#pragma once

#include <utility>
#include <vector>
#include "rc.h"
#include "sql/function/register.h"
#include "sql/operator/operator.h"

using AggKey = std::vector<TupleCell *>;
using AggState = std::vector<TupleCell *>;
using AggStates = std::vector<AggState>;

namespace std {
template<>
struct hash<AggKey> {
  // better hash function implementation
  // ref: https://stackoverflow.com/questions/20511347/a-good-hash-function-for-a-vector
  std::size_t operator()(const AggKey &key) const {
    std::hash<TupleCell> hasher;
    std::size_t seed = key.size();
    for(auto& cell: key) {
      seed ^= hasher(*cell) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
  }
};

template<>
struct equal_to<AggKey> {
  bool operator()(const AggKey &lhs, const AggKey &rhs ) const {
    if (lhs.size() != rhs.size()) return false;

    size_t len = lhs.size();
    for (size_t i=0; i<len; i++) {
      if (!std::equal_to<TupleCell>{}(*lhs[i], *rhs[i])) return false;
    }
    return true;
  }
};
}

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

    for (auto &p: states_) {
      auto key = p.first;
      auto val = p.second;

      std::cout << "key hash: " << std::hash<AggKey>()(key);
      std::cout << "key: ";
      for (auto &cell: key) {
        cell->to_string(std::cout);
        std::cout << ", ";
      }
      std::cout << std::endl << "value: ";
      for (auto &cells: val) {
        std::cout << "[";
        for (auto &cell: cells) {
          cell->to_string(std::cout);
          std::cout << ", ";
        }
        std::cout << "], ";
      }
      std::cout << std::endl;
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
        iter++;
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
      auto cell = new TupleCell{};
      RC rc = tuple->find_cell(*field, *cell);
      if (rc != RC::SUCCESS) {
        return { {}, rc };
      }
      key.push_back(cell);
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

    for (size_t i = 0; i<select_field_to_index_.size(); i++) {
      size_t index = select_field_to_index_[i];
      ValueExpr *value = nullptr;
      if (index < key_size) {
        value = new ValueExpr(*key[index]);
      } else {
        const size_t i = index - key_size;
        const auto &func = functions_[i];
        const auto &state = states[i];

        value = new ValueExpr(func->settle(state));
      }

      auto spec = new TupleCellSpec(value);
      spec->set_alias(select_fields_[i]->name());
      tuple->add_cell_spec(spec);
    }
    return tuple;
  }

private:
  std::unordered_map<AggKey, AggStates>::iterator next_iter_;

  ProjectTuple *tuple_{};
  std::unordered_map<AggKey, AggStates> states_;

  std::vector<size_t> select_field_to_index_;
  std::vector<AbstractField *> select_fields_;
  std::vector<Field *> group_by_fields_;
  std::vector<FunctionField *> aggregation_fields_;
  std::vector<Function *> functions_;

  PredicateOperator predicate_oper_;
};
