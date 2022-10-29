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
#include <unordered_map>

#include "common/log/log.h"
#include "sql/parser/parse.h"
#include "sql/expr/tuple_cell.h"
#include "sql/expr/expression.h"
#include "storage/record/record.h"
#include "storage/common/table.h"

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

  virtual RC set_tuple(const char *table_name, Tuple *tuple){
    return RC::UNIMPLENMENT;
  };
  virtual RC append_table(const char *table_name){
    return RC::UNIMPLENMENT;
  }
  virtual RC close_table(const char *table_name){
    return RC::UNIMPLENMENT;
  }
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
    row_tuple->record_ = new Record();
    table_->copy_record(record_, row_tuple->record_);
    for (size_t i = 0; i < speces_.size(); i++) {
      row_tuple->speces_.push_back(speces_[i]);
    }
    return row_tuple;
  }

  void destroy() override{
    // delete record_->data();
    // delete record_;
    speces_.clear();
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
      proj_tuple->speces_.push_back(new TupleCellSpec(*spec));
    }
    return proj_tuple;
  }

  void destroy() override{
    // if(tuple_!=nullptr){
    //   tuple_->destroy();
    //   delete tuple_;
    // }
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
    for (auto&itr:composite_tuple.tuples_) {
      std::vector<Tuple *> tuples;
      for(auto tuple:itr.second){
        tuples.push_back(tuple->copy());
      }
      tuples_.insert({itr.first, tuples});
    }
  }

  void destroy() override{
    // for(auto &itr:tuples_){
    //   for(auto tuple:itr.second){
    //     tuple->destroy();
    //     delete tuple;
    //   }
    //   itr.second.clear();
    // }
    tuples_.clear();
  }

  Tuple* copy()const override {
    CompositeTuple *composite_tuple = new CompositeTuple();
    for(auto &itr:tuples_){
      std::vector<Tuple *> tuples;
      for (auto tuple : itr.second) {
        tuples.push_back(tuple->copy());
      }
      composite_tuple->tuples_[itr.first] = tuples;
    }
    return composite_tuple;
  }

  /* 用栈递归 */
  RC append_table(const char *table_name)override{
    tuples_[table_name].push_back(nullptr);
    return RC::SUCCESS;
  }

  RC set_tuple(const char *table_name,Tuple * tuple)override
  {
    auto itr = tuples_.find(table_name);
    if(itr==tuples_.end()){
      return RC::GENERIC_ERROR;
    }
    itr->second[itr->second.size() - 1] = tuple;
    return RC::SUCCESS;
  }
  
  RC close_table(const char *table_name)override{
    auto itr = tuples_.find(table_name);
    if(itr == tuples_.end()||itr->second.size()==0){
      return RC::GENERIC_ERROR;
    }
    itr->second.pop_back();
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
    // return tuples_.find(field.table_name())->second.back()->find_cell(field, cell);
    auto iter = tuples_.find(field.table_name());
    if (iter == tuples_.end()) {
      return RC::GENERIC_ERROR;
    }

    auto tuple = iter->second;
    if (tuple.size() == 0) {
      return RC::GENERIC_ERROR;
    }

    if (tuple.back() == nullptr) {
      return RC::GENERIC_ERROR;
    }
    return tuple.back()->find_cell(field, cell);
  }
  RC cell_spec_at(int index, const TupleCellSpec *&spec) const override
  {
    return RC::UNIMPLENMENT;
  }

private:
  std::unordered_map<std::string,std::vector<Tuple *>> tuples_;
};