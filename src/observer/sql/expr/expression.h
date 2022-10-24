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

class Tuple;

enum class ExprType {
  NONE,
  FIELD,
  VALUE,
  FUNCTION,
  ALIAS,
};

class Expression
{
public: 
  Expression() = default;
  virtual ~Expression() = default;
  
  virtual RC get_value(const Tuple &tuple, TupleCell &cell) const = 0;
  virtual ExprType type() const = 0;
};

class FieldExpr : public Expression
{
public:
  FieldExpr() = default;
  FieldExpr(const Table *table, const FieldMeta *field) : field_(table, field)
  {}

  virtual ~FieldExpr() = default;

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

  RC get_value(const Tuple &tuple, TupleCell &cell) const override;
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

  virtual ~ValueExpr() = default;

  RC get_value(const Tuple &tuple, TupleCell & cell) const override;
  AttrType value_type(){
    return tuple_cell_.attr_type();
  }
  ExprType type() const override
  {
    return ExprType::VALUE;
  }

  void get_tuple_cell(TupleCell &cell) const {
    cell = tuple_cell_;
  }

private:
  TupleCell tuple_cell_;
};

class FunctionExpr : public Expression {
public:
  explicit FunctionExpr(std::vector<AbstractField *> fields, Function *function)
      : fields_(std::move(fields)), function_(function) {}
  ~FunctionExpr() override = default;

  ExprType type() const override { return ExprType::FUNCTION; }
  RC get_value(const Tuple &tuple, TupleCell &cell) const override;

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
  RC get_value(const Tuple &tuple, TupleCell &cell) const override;
private:
  const char *alias_;
};