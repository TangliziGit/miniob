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

#include "rc.h"
#include "common/log/log.h"
#include "common/lang/string.h"
#include "sql/stmt/filter_stmt.h"
#include "sql/function/register.h"
#include "storage/common/db.h"
#include "storage/common/table.h"

FilterStmt::~FilterStmt()
{
  // for (FilterUnit *unit : filter_units_) {
  //   delete unit;
  // }
  filter_units_.clear();
}

RC FilterStmt::create(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
		      const Condition *conditions, int condition_num,
		      FilterStmt *&stmt)
{
  RC rc = RC::SUCCESS;
  stmt = nullptr;

  FilterStmt *tmp_stmt = new FilterStmt();
  int cur_id = 0;
  std::vector<int> filter_col;
  for (int i = 0; i < condition_num; i++) {
    FilterUnit *filter_unit = nullptr;
    rc = create_filter_unit(db, default_table, tables, conditions[i], filter_unit);
    if (rc != RC::SUCCESS) {
      delete tmp_stmt;
      LOG_WARN("failed to create filter unit. condition index=%d", i);
      return rc;
    }
    if(!conditions[i].is_and){
      /* or */
      cur_id++;
    }
    filter_col.push_back(cur_id);
    filter_unit->set_id(i);
    tmp_stmt->filter_units_.push_back(filter_unit);
  }

  FilterTicker *ticker = new FilterTicker(filter_col);
  for (auto filter_unit:tmp_stmt->filter_units_) {
    filter_unit->set_ticker(ticker);
  }

  stmt = tmp_stmt;
  return rc;
}

RC get_table_and_field(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
		       const RelAttr &attr, Table *&table, const FieldMeta *&field)
{
  if (common::is_blank(attr.relation_name)) {
    table = default_table;
  } else if (nullptr != tables) {
    auto iter = tables->find(std::string(attr.relation_name));
    if (iter != tables->end()) {
      table = iter->second;
    }
  } else {
    table = db->find_table(attr.relation_name);
  }
  if (nullptr == table) {
    LOG_WARN("No such table: attr.relation_name: %s", attr.relation_name);
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  field = table->table_meta().field(attr.attribute_name);
  if (nullptr == field) {
    LOG_WARN("no such field in table: table %s, field %s", table->name(), attr.attribute_name);
    table = nullptr;
    return RC::SCHEMA_FIELD_NOT_EXIST;
  }

  return RC::SUCCESS;
}

std::pair<Expression *, RC> create_function_expr(
    FunctionAttr *func_attr,
    Table *default_table,
    const std::unordered_map<std::string, Table *> &tables) {
  auto func_field_result = FunctionField::make(default_table, tables, func_attr);
  if (func_field_result.second != RC::SUCCESS) {
    return { nullptr, func_field_result.second };
  }

  const auto &func_field = func_field_result.first;
  auto func_result = FunctionRegister::create(func_field->function_name(), func_field->fields());
  if (func_result.second != RC::SUCCESS) {
    return { nullptr, func_result.second };
  }

  const auto &func = func_result.first;
  if (FunctionRegister::is_aggregation(func_attr->function_name)) {
    return { new AliasExpr(func_field->name()), SUCCESS };
  }
  return { new FunctionExpr(func_field->fields(), func), SUCCESS };
}

RC FilterStmt::create_filter_unit(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
				  const Condition &condition, FilterUnit *&filter_unit)
{
  RC rc = RC::SUCCESS;
  
  CompOp comp = condition.comp;
  if (comp < EQUAL_TO || comp >= NO_OP) {
    LOG_WARN("invalid compare operator : %d", comp);
    return RC::INVALID_ARGUMENT;
  }

  Expression *left = nullptr;
  Expression *right = nullptr;
  if (condition.left_is_attr) {
    if (condition.left_attr.function != nullptr) {
      auto result = create_function_expr(condition.left_attr.function, default_table, *tables);
      if (result.second != SUCCESS) {
        return result.second;
      }

      left = result.first;
    } else {
      Table *table = nullptr;
      const FieldMeta *field = nullptr;
      rc = get_table_and_field(db, default_table, tables, condition.left_attr, table, field);
      if (rc != RC::SUCCESS) {
        LOG_WARN("cannot find attr");
        return rc;
      }
      left = new FieldExpr(table, field);
    }
  } else {
    if(condition.left_value.is_query){
      Query *query = (Query*)condition.left_value.data;
      Stmt *select_stmt = nullptr;
      if((rc = SelectStmt::create_stmt(db, *query, select_stmt,*tables))!= RC::SUCCESS){
        return rc;
      }
      size_t query_num = ((SelectStmt *)select_stmt)->query_fields().size();
      if(query_num>1 && (comp!=CompOp::EXISTS&&comp!=CompOp::NOT_EXISTS)){
        return RC::SCHEMA_FIELD_TYPE_MISMATCH;
      }
      left = new SubSelectExpr(select_stmt);
    } else {
      left = new ValueExpr(condition.left_value);
    }
  }

  if (condition.right_is_attr) {
    if (condition.right_attr.function != nullptr) {
      auto result = create_function_expr(condition.right_attr.function, default_table, *tables);
      if (result.second != SUCCESS) {
        return result.second;
      }

      right = result.first;
    } else {
      Table *table = nullptr;
      const FieldMeta *field = nullptr;
      rc = get_table_and_field(db, default_table, tables, condition.right_attr, table, field);
      if (rc != RC::SUCCESS) {
        LOG_WARN("cannot find attr");
        delete left;
        return rc;
      }
      right = new FieldExpr(table, field);
    }
  } else {
    if (condition.right_value[0].is_query) {
      Query *query = (Query*)condition.right_value[0].data;
      Stmt *select_stmt = nullptr;
      if((rc = SelectStmt::create_stmt(db, *query, select_stmt,*tables))!= RC::SUCCESS){
        return rc;
      }
      size_t query_num = ((SelectStmt *)select_stmt)->query_fields().size();
      if(query_num>1 && (comp!=CompOp::EXISTS&&comp!=CompOp::NOT_EXISTS)){
        return RC::SCHEMA_FIELD_TYPE_MISMATCH;
      }
      right = new SubSelectExpr(select_stmt);
    } else {
      if(condition.comp!=IN&&condition.comp!=NOT_IN){
        right = new ValueExpr(condition.right_value[0]);
      }else{
        right = new MultiValueExpr(condition.right_value_num, condition.right_value);
      }
    }
  }

  filter_unit = new FilterUnit;
  filter_unit->set_comp(comp);
  filter_unit->set_left(left);
  filter_unit->set_right(right);

  // 检查两个类型是否能够比较
  return rc;
}
