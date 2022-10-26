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
    /* todo :mem leak */
    // if (expression_) {
    //   delete expression_;
    //   expression_ = nullptr;
    // }
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
  virtual Tuple* copy() const = 0;
  virtual void destroy() = 0;
  virtual RC init(const std::map<std::string, int> &name_map)
  {
    return RC::UNIMPLENMENT;
  };

  virtual RC set_tuple(const char *table_name, Tuple *tuple){
    return RC::UNIMPLENMENT;
  };


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
  RowTuple(RowTuple& row_tuple) {
    this->table_ = row_tuple.table_;
    this->record_ = new Record(*row_tuple.record_);
    for (size_t i = 0; i < row_tuple.speces_.size(); i++) {
      this->speces_.push_back(row_tuple.speces_[i]);
    }
  }
  virtual ~RowTuple()
  {
    // for (TupleCellSpec *spec : speces_) {
    //   delete spec;
    // }
    speces_.clear();
  }
  Tuple* copy()const override{
    RowTuple *row_tuple = new RowTuple();
    row_tuple->table_ = table_;
    /* todo(yin):mem leak */
    row_tuple->record_ = new Record(*record_);
    for (size_t i = 0; i < speces_.size(); i++) {
      row_tuple->speces_.push_back(speces_[i]);
    }
    return row_tuple;
  }

  void destroy() override{
    delete record_;
    record_ = nullptr;
    table_ = nullptr;
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
    // for (TupleCellSpec *spec : speces_) {
    //   delete spec;
    // }
    speces_.clear();
  }

  Tuple* copy()const override{
    /* 不复制speces,没用 */
    ProjectTuple *proj_tuple = new ProjectTuple();
    if(tuple_!=nullptr){
      proj_tuple->tuple_ = tuple_->copy();
    }
    for(TupleCellSpec*spec:speces_){
      proj_tuple->speces_.push_back(spec);
    }
    return proj_tuple;
  }

  void destroy() override{
    if(tuple_!=nullptr){
      tuple_->destroy();
      delete tuple_;
    }
    tuple_ = nullptr;
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

class CompositeTuple: public Tuple
{
public:
  CompositeTuple() = default;
  virtual ~CompositeTuple(){}
  CompositeTuple(CompositeTuple &composite_tuple) {
    for (size_t i = 0; i < composite_tuple.tuples_.size(); i++) {
      this->tuples_.push_back(new RowTuple(static_cast<RowTuple&>(*composite_tuple.tuples_[i])));
    }
    this->name_map_ = composite_tuple.name_map_;
  }

  void destroy() override{
    for(auto tuple:tuples_){
      tuple->destroy();
      delete tuple;
    }
    tuples_.clear();
  }

  Tuple* copy()const override {
    CompositeTuple *composite_tuple = new CompositeTuple();
    for(auto tuple:tuples_){
      composite_tuple->tuples_.push_back(tuple->copy());
    }
    composite_tuple->name_map_ = name_map_;
    return composite_tuple;
  }

  RC init(const std::map<std::string,int> &name_map)override {
    this->tuples_.resize(name_map.size());
    this->name_map_ = name_map;
    return RC::SUCCESS;
  }

  RC set_tuple(const char *table_name,Tuple * tuple)override
  {
    auto itr = name_map_.find(table_name);
    if(itr == name_map_.end())
      return RC::SCHEMA_TABLE_EXIST;
    int idx = itr->second;
    this->tuples_[idx] = tuple;
    return RC::SUCCESS;
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