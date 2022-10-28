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

class FilterTicker{
public:
  FilterTicker(const std::vector<int>&filter_col):filter_col_(filter_col){
    pass_map_.resize(filter_col.size(), false);
    size_t i = 0;
    while(i<filter_col_.size()){
      int num = 1;
      i++;
      while (i<filter_col_.size()&&filter_col_[i]==filter_col_[i-1]){
        i++;
        num++;
      }
      last_filters_.push_back(num);
    }
    pass_map_.resize(filter_col.size(), false);
    is_cold_.resize(last_filters_.size(), -1);
    last_col_ = is_cold_.size();
  }
  void reset(int id){
    int col = filter_col_[id];
    if(pass_map_[id]){
      last_filters_[col]++;
      pass_map_[id] = false;
    }
    /* 如果是因为当前filter导致的这个col冻住 */
    if(is_cold_[col]==id){
      last_col_++;
      is_cold_[col] = -1;
    }
  }
  bool pass(int id){
    pass_map_[id] = true;
    int col = filter_col_[id];
    last_filters_[col]--;
    if(last_filters_[col]==0){
      return true;
    }
    return false;
  }
  bool fail(int id){
    int col = filter_col_[id];
    is_cold_[col] = id;
    last_col_--;
    return last_col_ == 0;
  }
  bool is_cool(int id){
    int col = filter_col_[id];
    return is_cold_[col] == -1;
  }
  bool has_or(){
    return last_col_ != 1;
  }

private:
 std::vector<bool> pass_map_;
 std::vector<int> filter_col_;
 std::vector<int> last_filters_;
 std::vector<int> is_cold_;
 int last_col_;
};
class FilterUnit {
public:
  FilterUnit() = default;
  ~FilterUnit(){}
  
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

  void set_ticker(FilterTicker *ticker){
    ticker_ = ticker;
  }
  FilterTicker * get_ticker(){
    return ticker_;
  }
  void set_id(int id){
    id_ = id;
  }
  bool get_id(){
    return id_;
  }
  void reset(){
    ticker_->reset(id_);
  }
  bool pass(){
    return ticker_->pass(id_);
  }
  bool fail(){
    return ticker_->fail(id_);
  }
  bool is_cool(){
    return ticker_->is_cool(id_);
  }
  bool has_or(){
    return ticker_->has_or();
  }

private : 
  FilterTicker *ticker_;
  int id_;
  CompOp comp_ = NO_OP;
  Expression *left_ = nullptr;
  Expression *right_ = nullptr;
};

class FilterStmt 
{
public:

  FilterStmt() = default;
  virtual ~FilterStmt();
  FilterStmt(const std::vector<FilterUnit *> &filter_units) : filter_units_(filter_units){};

public:
  const std::vector<FilterUnit *> &filter_units() const
  {
    return filter_units_;
  }
  std::vector<FilterUnit *> filter_copy() const
  {
    return filter_units_;
  }
  void add_filter(FilterUnit * filter_unit){
    filter_units_.push_back(filter_unit);
  }
  void remove_filter(FilterUnit * filter_unit){
    for (size_t i = 0; i < filter_units_.size();i++){
      if(filter_unit == filter_units_[i]){
        filter_units_.erase(filter_units_.begin() + i);
        break;
      }
    }
  }
  bool has_or(){
    return filter_units_.size() != 0 ? filter_units_[0]->has_or() : false;
  }

public:
  static RC create(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
			const Condition *conditions, int condition_num,
			FilterStmt *&stmt);

  static RC create_filter_unit(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
			       const Condition &condition, FilterUnit *&filter_unit);

private:
  std::vector<FilterUnit *>  filter_units_;
};
