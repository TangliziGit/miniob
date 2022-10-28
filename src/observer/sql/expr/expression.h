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
// Created by Wangyunlai on 2022/07/05.
//

#pragma once

#include <string.h>
#include <utility>
#include "storage/common/field.h"
#include "sql/expr/tuple_cell.h"
#include "sql/function/function.h"
#include "sql/stmt/select_stmt.h"

class Tuple;

enum class ExprType {
  NONE,
  FIELD,
  VALUE,
  FUNCTION,
  ALIAS,
  SUB_SELECT,
  MULTI_VALUE,
};

class Expression
{
public: 
  Expression() = default;
  virtual ~Expression() = default;
  
  virtual RC get_value(const Tuple &tuple, TupleCell &cell)= 0;
  virtual ExprType type() const = 0;
  virtual Expression *copy()const {
    return nullptr;
  }
  virtual std::pair<bool,RC> exist(){
    return {false, RC::UNIMPLENMENT};
  }
  virtual std::pair<bool,RC> in(const TupleCell&cell){
    return {false, RC::UNIMPLENMENT};
  }
  virtual std::pair<bool,RC> not_in(const TupleCell&cell){
    return {false, RC::UNIMPLENMENT};
  }
  virtual RC init(std::function<std::pair<std::vector<Tuple*>,RC>(Stmt *)> init_func){
    return RC::UNIMPLENMENT;
  }
};

class FieldExpr : public Expression
{
public:
  FieldExpr() = default;
  FieldExpr(const Table *table, const FieldMeta *field) : field_(table, field)
  {}

  virtual ~FieldExpr() = default;

  Expression*copy()const override{
    FieldExpr *field_expr = new FieldExpr(field_.table(), field_.meta());
    return field_expr;
  }
  ExprType type() const override
  {
    return ExprType::FIELD;
  }

  Field &field()
  {
    return field_;
  }

  const Field &field() const
  {
    return field_;
  }

  const char *table_name() const
  {
    return field_.table_name();
  }

  const char *field_name() const
  {
    return field_.field_name();
  }

  RC get_value(const Tuple &tuple, TupleCell &cell)override;
private:
  Field field_;
};

class ValueExpr : public Expression
{
public:
  ValueExpr() = default;
  explicit ValueExpr(const TupleCell &cell) : tuple_cell_(cell) {}
  ValueExpr(const Value &value) : tuple_cell_(value.type, (char *)value.data)
  {
    if (value.type == CHARS) {
      tuple_cell_.set_length(strlen((const char *)value.data));
    }
  }

  Expression*copy()const override{
    ValueExpr *field_expr = new ValueExpr(tuple_cell_);
    return field_expr;
  }

  virtual ~ValueExpr() = default;

  RC get_value(const Tuple &tuple, TupleCell & cell) override;
  AttrType value_type(){
    return tuple_cell_.attr_type();
  }
  ExprType type() const override
  {
    return ExprType::VALUE;
  }

  std::pair<bool,RC> in(const TupleCell &cell)override{
     if(tuple_cell_.is_null()&&cell.is_null()){
       return {false,RC::SUCCESS};
     }
     return {tuple_cell_.compare(cell) == 0, RC::SUCCESS};
  }

  std::pair<bool,RC> not_in(const TupleCell &cell)override{

    return {tuple_cell_.is_null(), RC::SUCCESS};
  }

  void get_tuple_cell(TupleCell &cell) const {
    cell = tuple_cell_;
  }

private:
  TupleCell tuple_cell_;
};


class SubSelectExpr : public Expression
{
public:
  SubSelectExpr() = default;
  explicit SubSelectExpr(Stmt *select_stmt) : select_stmt_(select_stmt) {}

  virtual ~SubSelectExpr();
  RC init(std::function<std::pair<std::vector<Tuple *>, RC>(Stmt *)> init_func) override
  {
    init_func_ = init_func;
    return RC::SUCCESS;
  }

  RC execute();

  RC get_value(const Tuple &tuple, TupleCell &cell) override;

  std::pair<bool,RC> exist() override;
  bool need_execute(){
    return ((SelectStmt *)(select_stmt_))->contain_other_field();
  }
  std::pair<bool,RC> in(const TupleCell &cell) override;
  std::pair<bool,RC> not_in(const TupleCell &cell) override;
  ExprType type() const override
  {
    return ExprType::SUB_SELECT;
  }
private:
  std::function<std::pair<std::vector<Tuple*>, RC>(Stmt *)> init_func_;
  Stmt *select_stmt_;
  std::vector<Tuple *> tuples_;
};

class MultiValueExpr : public Expression {
  public:
  MultiValueExpr() = default;
  explicit MultiValueExpr(const std::vector<TupleCell> &values):values_(values) {}
  MultiValueExpr(int value_num, const Value *value){
    for (int i = 0; i < value_num;i++){
      values_.push_back(TupleCell(value[i].type, (char *)value[i].data));
    }
  }

  virtual ~MultiValueExpr() = default;
  RC get_value(const Tuple &tuple, TupleCell &cell) override;

  std::pair<bool,RC> in(const TupleCell &cell) override;
  std::pair<bool,RC> not_in(const TupleCell &cell) override;
  ExprType type() const override
  {
    return ExprType::MULTI_VALUE;
  }

private:
  std::vector<TupleCell> values_;
};
class FunctionExpr : public Expression {
public:
  explicit FunctionExpr(std::vector<AbstractField *> fields, Function *function)
      : fields_(std::move(fields)), function_(function) {}
  ~FunctionExpr() override = default;

  ExprType type() const override { return ExprType::FUNCTION; }
  RC get_value(const Tuple &tuple, TupleCell &cell) override;

private:
  std::vector<AbstractField *> fields_;
  Function *function_;
};

class CompositeExpression : public Expression {
  
};

class AliasExpr : public Expression
{
public:
  explicit AliasExpr(const char *alias) : alias_(alias) {}
  ~AliasExpr() override = default;

  ExprType type() const override { return ExprType::ALIAS; }
  RC get_value(const Tuple &tuple, TupleCell &cell) override;
private:
  const char *alias_;
};