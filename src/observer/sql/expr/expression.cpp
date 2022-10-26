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
bool SubSelectExpr::exist(){
    /* todo(yin) check err here */
    init_if_not();
    for (auto &tuple : tuples_){
      int cell_nul = tuple->cell_num();
      for (int i = 0; i < cell_nul;i++){
        TupleCell cell;
        tuple->cell_at(i, cell);
        if (!cell.is_null()) {
          return true;
        }
      }
    }
    return false;
}

bool SubSelectExpr::in(const TupleCell &cell)
{
  init_if_not();
  for (auto tuple : tuples_) {
    if (tuple->cell_num() != 1) {
      /* todo(yin): err? */
      return false;
    }
    TupleCell cur_cell;
    if (tuple->cell_at(0, cur_cell) != RC::SUCCESS) {
      /*todo(yin):err? */
      return false;
    }
    if (cur_cell.is_null()) {
      continue;
    }
    if (cur_cell.compare(cell) == 0) {
      return true;
    }
  }
  return false;
}

RC SubSelectExpr::get_value(const Tuple &tuple, TupleCell &cell){
  RC rc = RC::SUCCESS;
  if ((rc = init_if_not()) != RC::SUCCESS) {
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
