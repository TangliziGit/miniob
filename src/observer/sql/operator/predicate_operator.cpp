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
// Created by WangYunlai on 2022/6/27.
//

#include "common/log/log.h"
#include "sql/operator/predicate_operator.h"
#include "storage/record/record.h"
#include "sql/stmt/filter_stmt.h"
#include "storage/common/field.h"

RC PredicateOperator::open()
{
  if (children_.size() != 1) {
    LOG_WARN("predicate operator must has one child");
    return RC::INTERNAL;
  }

  return children_[0]->open();
}

RC PredicateOperator::next()
{
  RC rc = RC::SUCCESS;
  Operator *oper = children_[0];
  
  while (RC::SUCCESS == (rc = oper->next())) {
    Tuple *tuple = oper->current_tuple();
    if (nullptr == tuple) {
      rc = RC::INTERNAL;
      LOG_WARN("failed to get tuple from operator");
      break;
    }
    auto res = do_predicate(static_cast<RowTuple &>(*tuple));
    if(res.first== RC::SUCCESS && !res.second){
      continue;
    }else{
      return res.first;
    }
  }
  return rc;
}

RC PredicateOperator::close()
{
  children_[0]->close();
  return RC::SUCCESS;
}

Tuple * PredicateOperator::current_tuple()
{
  return children_[0]->current_tuple();
}

std::pair<RC,bool> PredicateOperator::do_predicate(Tuple &tuple)
{
  if (filter_stmt_ == nullptr || filter_stmt_->filter_units().empty()) {
    return {RC::SUCCESS,true};
  }
  RC rc = RC::SUCCESS;
  for (const FilterUnit *filter_unit : filter_stmt_->filter_units()) {
    Expression *left_expr = filter_unit->left();
    Expression *right_expr = filter_unit->right();
    CompOp comp = filter_unit->comp();
    if (comp == EXISTS) {
      return {rc, right_expr->exist()};
    }
    if(comp == NOT_EXISTS){
      return {rc, !right_expr->exist()};
    }
    TupleCell left_cell;
    TupleCell right_cell;
    if((rc = left_expr->get_value(tuple, left_cell))!= RC::SUCCESS){
      return {rc, false};
    }
    if(comp == IN){
      return {rc, !left_cell.is_null() && right_expr->in(left_cell)};
    }
    if(comp == NOT_IN){
      return {rc, !left_cell.is_null() && !right_expr->in(left_cell)};
    }
    if((rc = right_expr->get_value(tuple, right_cell))!= RC::SUCCESS){
      return {rc, false};
    }
    if(left_cell.attr_type()==NULLS||right_cell.attr_type()==NULLS){
      /* 如果是null,除is的任何比较都是false */
      if( comp==IS ){
        return {rc,left_cell.is(right_cell)};
      }
      if(comp == IS_NOT){
        return {rc,!left_cell.is(right_cell)};
      }
      return {rc, false};
    }
    if(comp == LIKE||comp == NOT_LIKE){
      bool is_like = left_cell.like(right_cell);
      if((comp == LIKE && !is_like)||(comp==NOT_LIKE&&is_like)){
        return {rc, false};
      }
      continue;
    }
    const int compare = left_cell.compare(right_cell);
    bool filter_result = false;
    switch (comp) {
    case EQUAL_TO: {
      filter_result = (0 == compare);
    } break;
    case LESS_EQUAL: {
      filter_result = (compare <= 0); 
    } break;
    case NOT_EQUAL: {
      filter_result = (compare != 0);
    } break;
    case LESS_THAN: {
      filter_result = (compare < 0);
    } break;
    case GREAT_EQUAL: {
      filter_result = (compare >= 0);
    } break;
    case GREAT_THAN: {
      filter_result = (compare > 0);
    } break;
    default: {
      LOG_WARN("invalid compare type: %d", comp);
    } break;
    }
    if (!filter_result) {
      return {rc, false};
    }
  }
  return {rc, true};
}
