#pragma once

#include <utility>
#include <vector>
#include "rc.h"
#include "sql/function/register.h"
#include "sql/operator/operator.h"

using AggKey = std::vector<TupleCell *>;
using AggState = std::vector<TupleCell *>;
using AggStates = std::vector<AggState>;

class AggregationOperator : public Operator
{
public:
  AggregationOperator(
      std::vector<AbstractField *> select_fields,
      std::vector<FunctionField *> aggregation_fields,
      std::vector<Field *> group_by_fields,
      FilterStmt *having_fields)
      : select_field_to_index_(),
        select_fields_(std::move(select_fields)),
        group_by_fields_(std::move(group_by_fields)),
        aggregation_fields_(std::move(aggregation_fields)),
        predicate_oper_(having_fields) {}

  RC open() override {
    // build select_field_to_index for generating project tuple
    std::unordered_map<std::string, size_t> field_to_index;
    size_t group_by_size = group_by_fields_.size();
    for (size_t i=0; i<group_by_fields_.size(); i++) {
      field_to_index[group_by_fields_[i]->name()] = i;
    }

    for (size_t i=0; i<aggregation_fields_.size(); i++) {
      auto &field = aggregation_fields_[i];
      field_to_index[field->name()] = group_by_size + i;
    }

    select_field_to_index_.reserve(select_fields_.size());
    for (size_t i=0; i<select_fields_.size(); i++) {
      auto &field = select_fields_[i];
      if (field_to_index.count(field->name()) == 0) {
        return RC::MISMATCH;
      }
      select_field_to_index_.push_back(field_to_index[field->name()]);
    }

    // build aggregation functions
    for (auto & field : aggregation_fields_) {
      if (!FunctionRegister::is_aggregation(field->function_name())) {
        return RC::MISUSE;
      }

      auto result = FunctionRegister::create(field->function_name(), field->fields());
      if (result.second != RC::SUCCESS) {
        return result.second;
      }

      functions_.push_back(result.first);
    }

    // read all tuples to build aggregation hash map
    Operator *child = children_[0];
    RC rc = child->open();
    if (rc != SUCCESS) {
      return rc;
    }

    while ((rc = child->next()) == RC::SUCCESS) {
      Tuple *tuple = child->current_tuple();

      auto result = make_key(tuple);
      if (result.second != SUCCESS) {
        return result.second;
      }

      AggKey key = result.first;
      rc = insert(key, tuple);
      if (rc != SUCCESS) {
        return rc;
      }
    }
    if (rc != SUCCESS && rc != RECORD_EOF) {
      return rc;
    }

    next_iter_ = states_.begin();
    return RC::SUCCESS;
  };

  RC next() override {
    for (auto &iter = next_iter_; iter != states_.end(); iter++) {
      AggKey key = iter->first;
      AggStates states = iter->second;

      tuple_ = make_tuple(key, states);

      // if having clause not passed then continue next
      if (predicate_oper_.do_predicate(*tuple_)) {
        return SUCCESS;
      }
    }
    return RECORD_EOF;
  };

  RC close() override { return children_[0]->close(); };

  Tuple * current_tuple() override { return tuple_; };

private:
  std::pair<AggKey, RC> make_key(const Tuple *tuple) {
    std::vector<TupleCell *> key;
    for (const auto field: group_by_fields_) {
      TupleCell cell;
      RC rc = tuple->find_cell(*field, cell);
      if (rc != RC::SUCCESS) {
        return { {}, rc };
      }
    }
    return { key, SUCCESS };
  }

  RC insert(const AggKey &key, Tuple *tuple) {
    RC rc;
    if (states_.count(key) == 0) {
      states_[key] = {};
      for (auto & func : functions_) {
        states_[key].push_back(func->initialState());
      }
    }

    AggStates &states = states_[key];
    for (size_t i=0; i<functions_.size(); i++) {
      auto args = tuple->extract_cells(aggregation_fields_[i]->fields());
      if (args.second != SUCCESS) {
        return rc;
      }

      TupleCell result;
      rc = functions_[i]->execute(args.first, result, states[i]);
      if (rc != SUCCESS) {
        return rc;
      }
    }
    return SUCCESS;
  }

  ProjectTuple *make_tuple(const AggKey &key, const AggStates &states) {
    size_t key_size = key.size();
    auto *tuple = new ProjectTuple();

    for (const size_t index: select_field_to_index_) {
      ValueExpr *value = nullptr;
      if (index < key_size) {
        value = new ValueExpr(*key[index]);
      } else {
        const size_t i = index - key_size;
        const auto &func = functions_[i];
        const auto &state = states[i];

        value = new ValueExpr(func->settle(state));
      }

      tuple->add_cell_spec(new TupleCellSpec(value));
    }
    return tuple;
  }

private:
  std::map<AggKey, AggStates>::iterator next_iter_;

  ProjectTuple *tuple_{};
  std::map<AggKey, AggStates> states_;

  std::vector<size_t> select_field_to_index_;
  std::vector<AbstractField *> select_fields_;
  std::vector<Field *> group_by_fields_;
  std::vector<FunctionField *> aggregation_fields_;
  std::vector<Function *> functions_;

  PredicateOperator predicate_oper_;
};
