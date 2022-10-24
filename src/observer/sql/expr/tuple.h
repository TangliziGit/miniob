/* Copyright (c) 2021 Xie Meiyi(xiemeiyi@hust.edu.cn) and OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Wangyunlai on 2021/5/14.
//

#pragma once

#include <memory>
#include <vector>

#include "common/log/log.h"
#include "sql/parser/parse.h"
#include "sql/expr/tuple_cell.h"
#include "sql/expr/expression.h"
#include "storage/record/record.h"

class Table;

class TupleCellSpec
{
public:
  TupleCellSpec() = default;
  TupleCellSpec(Expression *expr) : expression_(expr)
  {}

  ~TupleCellSpec()
  {
    if (expression_) {
      delete expression_;
      expression_ = nullptr;
    }
  }

  void set_alias(const char *alias)
  {
    this->alias_ = alias;
  }
  const char *alias() const
  {
    return alias_;
  }

  Expression *expression() const
  {
    return expression_;
  }

private:
  const char *alias_ = nullptr;
  Expression *expression_ = nullptr;
};

class Tuple
{
public:
  Tuple() = default;
  virtual ~Tuple() = default;

  virtual int cell_num() const = 0; 
  virtual RC  cell_at(int index, TupleCell &cell) const = 0;
  virtual RC  find_cell(const Field &field, TupleCell &cell) const = 0;
  virtual RC  find_cell_by_alias(const char *alias, TupleCell &cell) const = 0;
  virtual RC  cell_spec_at(int index, const TupleCellSpec *&spec) const = 0;

  // extract_cells just for function arguments extracting
  std::pair<Function::Arguments, RC> extract_cells(const std::vector<AbstractField *>& fields) const {
    Function::Arguments args;
    for (const auto field: fields) {
      TupleCell cell;
      switch (field->type()) {
        case FieldType::FIELD:
          this->find_cell(*dynamic_cast<Field *>(field), cell);
          break;
        case FieldType::VALUE_FIELD: {
          auto value = dynamic_cast<ValueField *>(field)->value();
          cell.set_type(value->type);
          cell.set_data((char *)value->data);
          break;
        }
        default:
          // recursive function call is not necessary
          return { {}, RC::MISMATCH };
      }
      args.push_back(cell);
    }
    return { args, RC::SUCCESS };
  }
};

class RowTuple : public Tuple
{
public:
  RowTuple() = default;
  virtual ~RowTuple()
  {
    for (TupleCellSpec *spec : speces_) {
      delete spec;
    }
    speces_.clear();
  }
  
  void set_record(Record *record)
  {
    this->record_ = record;
  }

  void set_schema(const Table *table, const std::vector<FieldMeta> *fields)
  {
    table_ = table;
    this->speces_.reserve(fields->size());
    for (const FieldMeta &field : *fields) {
      speces_.push_back(new TupleCellSpec(new FieldExpr(table, &field)));
    }
  }

  int cell_num() const override
  {
    return speces_.size();
  }

  RC cell_at(int index, TupleCell &cell) const override
  {
    if (index < 0 || index >= static_cast<int>(speces_.size())) {
      LOG_WARN("invalid argument. index=%d", index);
      return RC::INVALID_ARGUMENT;
    }

    const TupleCellSpec *spec = speces_[index];
    FieldExpr *field_expr = (FieldExpr *)spec->expression();
    const FieldMeta *field_meta = field_expr->field().meta();
    bool is_null = *(char *)(this->record_->data() + field_meta->offset() + field_meta->len()) == 1;
    cell.set_type(is_null ? NULLS : field_meta->type());
    cell.set_data(this->record_->data() + field_meta->offset());
    cell.set_length(field_meta->len());
    return RC::SUCCESS;
  }

  RC find_cell_by_alias(const char *alias, TupleCell &cell) const override {
    for (size_t i = 0; i < speces_.size(); ++i) {
      if (0 == strcmp(alias, speces_[i]->alias())) {
        return cell_at(i, cell);
      }
    }
    return RC::NOTFOUND;
  }

  RC find_cell(const Field &field, TupleCell &cell) const override
  {
    const char *table_name = field.table_name();
    if (0 != strcmp(table_name, table_->name())) {
      return RC::NOTFOUND;
    }

    const char *field_name = field.field_name();
    for (size_t i = 0; i < speces_.size(); ++i) {
      const FieldExpr * field_expr = (const FieldExpr *)speces_[i]->expression();
      const Field &field = field_expr->field();
      if (0 == strcmp(field_name, field.field_name())) {
	return cell_at(i, cell);
      }
    }
    return RC::NOTFOUND;
  }

  RC cell_spec_at(int index, const TupleCellSpec *&spec) const override
  {
    if (index < 0 || index >= static_cast<int>(speces_.size())) {
      LOG_WARN("invalid argument. index=%d", index);
      return RC::INVALID_ARGUMENT;
    }
    spec = speces_[index];
    return RC::SUCCESS;
  }

  Record &record()
  {
    return *record_;
  }

  const Record &record() const
  {
    return *record_;
  }
private:
  Record *record_ = nullptr;
  const Table *table_ = nullptr;
  std::vector<TupleCellSpec *> speces_;
};



class ProjectTuple : public Tuple
{
public:
  ProjectTuple() = default;
  virtual ~ProjectTuple()
  {
    for (TupleCellSpec *spec : speces_) {
      delete spec;
    }
    speces_.clear();
  }

  void set_tuple(Tuple *tuple)
  {
    this->tuple_ = tuple;
  }

  void add_cell_spec(TupleCellSpec *spec)
  {
    speces_.push_back(spec);
  }
  void resize_cell_spec(size_t spec_num) {
    speces_.resize(spec_num);
  }

  int cell_num() const override
  {
    return speces_.size();
  }

  RC cell_at(int index, TupleCell &cell) const override
  {
    if (index < 0 || index >= static_cast<int>(speces_.size())) {
      return RC::GENERIC_ERROR;
    }

    const TupleCellSpec *spec = speces_[index];
    if (spec->expression()->type() == ExprType::VALUE) {
      RowTuple tmp;
      return spec->expression()->get_value(tmp, cell);
    }

    if (tuple_ == nullptr) {
      return RC::GENERIC_ERROR;
    }

    return spec->expression()->get_value(*tuple_, cell);
  }

  RC find_cell_by_alias(const char *alias, TupleCell &cell) const override {
    for (size_t i = 0; i < speces_.size(); ++i) {
      if (0 == strcmp(alias, speces_[i]->alias())) {
        return cell_at(i, cell);
      }
    }
    return RC::NOTFOUND;
  }

  RC find_cell(const Field &field, TupleCell &cell) const override
  {
    return tuple_->find_cell(field, cell);
  }
  RC cell_spec_at(int index, const TupleCellSpec *&spec) const override
  {
    if (index < 0 || index >= static_cast<int>(speces_.size())) {
      return RC::NOTFOUND;
    }
    spec = speces_[index];
    return RC::SUCCESS;
  }
private:
  std::vector<TupleCellSpec *> speces_;
  Tuple *tuple_ = nullptr;
};

class MulProjectTuple: public Tuple
{
public:
  MulProjectTuple() = default;
  virtual ~MulProjectTuple(){}

  void init(const std::map<std::string,int> &name_map){
    this->tuples_.resize(name_map.size());
    this->name_map_ = name_map;
  }

  void set_tuple(int idx,Tuple * tuple)
  {
    this->tuples_[idx] = tuple;
  }

  int cell_num() const override{
    return 0;
  }

  RC cell_at(int index, TupleCell &cell) const override
  {
    return RC::UNIMPLENMENT;
  }

  RC find_cell_by_alias(const char *alias, TupleCell &cell) const override {
    // TODO(chunxu): it seems not necessary to implement
    return RC::NOTFOUND;
  }

  RC find_cell(const Field &field, TupleCell &cell) const override
  {
    int idx = name_map_.find(field.table_name())->second;
    return tuples_.at(idx)->find_cell(field, cell);
  }
  RC cell_spec_at(int index, const TupleCellSpec *&spec) const override
  {
    return RC::UNIMPLENMENT;
  }

private:
  std::vector<Tuple *> tuples_;
  std::map<std::string, int> name_map_;
};