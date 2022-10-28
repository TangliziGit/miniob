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

#include "sql/expr/tuple.h"
#include "expression.h"

RC FieldExpr::get_value(const Tuple &tuple, TupleCell &cell)
{
  return tuple.find_cell(field_, cell);
}

RC ValueExpr::get_value(const Tuple &tuple, TupleCell & cell) 
{
  cell = tuple_cell_;
  return RC::SUCCESS;
}
std::pair<bool,RC> SubSelectExpr::exist(){
  RC rc = RC::SUCCESS;
  if (need_execute()) {
    rc = execute();
    if(rc != RC::SUCCESS){
      return {false, rc};
    }
  }
    for (auto &tuple : tuples_){
      int cell_nul = tuple->cell_num();
      for (int i = 0; i < cell_nul;i++){
        TupleCell cell;
        tuple->cell_at(i, cell);
        if (!cell.is_null()) {
          return {true, rc};
        }
      }
    }
    return {false, rc};
}

SubSelectExpr::~SubSelectExpr(){
  // delete select_stmt_;
  // for (auto tuple : tuples_) {
  //   tuple->destroy();
  //   delete tuple;
  // }
  tuples_.clear();
}

RC SubSelectExpr::execute(){
    // for(auto tuple:tuples_){
      // tuple->destroy();
      // delete tuple;
    // }
    tuples_.clear();
    auto res = init_func_(select_stmt_);
    if(res.second != RC::SUCCESS){
      return res.second;
    }
    tuples_.swap(res.first);
    return res.second;
}

std::pair<bool,RC> SubSelectExpr::in(const TupleCell &cell)
{
  RC rc = RC::SUCCESS;
  if (need_execute()) {
    rc =execute();
    if(rc != RC::SUCCESS){
      return {false, rc};
    }
  }
  for (auto tuple : tuples_) {
    if (tuple->cell_num() != 1) {
      return {false, RC::MISMATCH};
    }
    TupleCell cur_cell;
    if (tuple->cell_at(0, cur_cell) != RC::SUCCESS) {
      return {false, RC::MISMATCH};
    }
    if (cur_cell.is_null()) {
      continue;
    }
    if (cur_cell.compare(cell) == 0) {
      return {true, rc};
    }
  }
  return {false, rc};
}

std::pair<bool,RC> SubSelectExpr::not_in(const TupleCell &cell)
{
  RC rc = RC::SUCCESS;
  if (need_execute()) {
   rc =  execute();
   if(rc != RC::SUCCESS){
     return {false, rc};
   }
  }
  bool not_in = true;
  for (auto tuple : tuples_) {
    if (tuple->cell_num() != 1) {
      return {false, RC::MISMATCH};
    }
    TupleCell cur_cell;
    if (tuple->cell_at(0, cur_cell) != RC::SUCCESS) {
      return {false, RC::MISMATCH};
    }
    if (cur_cell.is_null()) {
      /* not in,里面如果有null,返回false */
      return {false, rc};
    }
    if(cur_cell.compare(cell)==0){
      not_in = false;
    }
  }
  return {not_in, rc};
}

RC SubSelectExpr::get_value(const Tuple &tuple, TupleCell &cell){
  RC rc = RC::SUCCESS;
  if(need_execute()){
    rc = execute();
  }
  if (rc != RC::SUCCESS) {
    return rc;
  }
  if(tuples_.size() == 0){
    cell.set_type(AttrType::NULLS);
    return RC::SUCCESS;
  }
  if (tuples_.size() != 1 || tuples_[0]->cell_num() != 1) {
    return RC::MISMATCH;
  }
  rc = tuples_[0]->cell_at(0, cell);
  return rc;
}

RC MultiValueExpr::get_value(const Tuple &tuple, TupleCell &cell){
  RC rc = RC::SUCCESS;
  if(values_.size() == 0){
    cell.set_type(AttrType::NULLS);
    return RC::SUCCESS;
  }
  if (values_.size() != 1) {
    return RC::MISMATCH;
  }
  cell = values_[0];
  return rc;
}

std::pair<bool,RC> MultiValueExpr::in(const TupleCell &cell){
  for(auto &in_cell:values_){
    if(in_cell.is_null()){
      continue;
    }
    if(in_cell.compare(cell)==0){
      return {true, RC::SUCCESS};
    }
  }
  return {false, RC::SUCCESS};
}

std::pair<bool,RC> MultiValueExpr::not_in(const TupleCell &cell){
  bool not_in = true;
  for (auto &in_cell : values_) {
    if(in_cell.is_null()){
      return {false, RC::SUCCESS};
    }
    if(in_cell.compare(cell)==0){
      not_in = false;
    }
  }
  return {not_in,RC::SUCCESS};
}

RC FunctionExpr::get_value(const Tuple &tuple, TupleCell &result)
{
  auto args = tuple.extract_cells(fields_);
  if (args.second != SUCCESS) {
    return args.second;
  }

  return function_->execute(args.first, result);
}

RC AliasExpr::get_value(const Tuple &tuple, TupleCell &cell)
{
  return tuple.find_cell_by_alias(alias_, cell);
}
