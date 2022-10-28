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
// Created by Wangyunlai on 2022/5/22.
//

#pragma once

#include <vector>
#include <unordered_map>
#include "rc.h"
#include "sql/parser/parse_defs.h"
#include "sql/stmt/stmt.h"
#include "sql/stmt/select_stmt.h"
#include "sql/expr/expression.h"

class Db;
class Table;
class FieldMeta;
class FilterUnit {
public:
  FilterUnit() = default;
  ~FilterUnit()
  {
    // if (left_) {
    //   delete left_;
    //   left_ = nullptr;
    // }
    // if (right_) {
    //   delete right_;
    //   right_ = nullptr;
    // }
  }
  
  void set_comp(CompOp comp) {
    comp_ = comp;
  }

  CompOp comp() const {
    return comp_;
  }

  void set_left(Expression *expr)
  {
    left_ = expr;
  }
  void set_right(Expression *expr)
  {
    right_ = expr;
  }
  Expression *left() const
  {
    return left_;
  }
  Expression *right() const
  {
    return right_;
  }
  void set_or_and(bool or_and){
    or_and_ = or_and;
  }
  bool get_or_and(){
    return or_and_;
  }

private:
  bool or_and_;
  CompOp comp_ = NO_OP;
  Expression *left_ = nullptr;
  Expression *right_ = nullptr;
};

class FilterStmt 
{
public:

  FilterStmt() = default;
  virtual ~FilterStmt();
  FilterStmt(std::set<FilterUnit *> filter_units) : filter_units_(filter_units){};

public:
  const std::set<FilterUnit *> &filter_units() const
  {
    return filter_units_;
  }
  std::set<FilterUnit *> filter_copy() const
  {
    return filter_units_;
  }
  void add_filter(FilterUnit * filter_unit){
    filter_units_.insert(filter_unit);
  }
  void remove_filter(FilterUnit * filter_unit){
    filter_units_.erase(filter_unit);
  }
  bool is_or(){
    return is_or_;
  }

public:
  static RC create(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
			const Condition *conditions, int condition_num,
			FilterStmt *&stmt);

  static RC create_filter_unit(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
			       const Condition &condition, FilterUnit *&filter_unit);

private:
  std::set<FilterUnit *>  filter_units_;
  bool is_or_;
};
