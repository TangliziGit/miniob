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
// Created by Wangyunlai on 2022/6/5.
//

#pragma once

#include <vector>

#include "rc.h"
#include "sql/stmt/stmt.h"
#include "storage/common/field.h"

class FieldMeta;
class FilterStmt;
class Db;
class Table;

class SelectStmt : public Stmt
{
public:

  SelectStmt() = default;
  ~SelectStmt() override;

  StmtType type() const override { return StmtType::SELECT; }
public:
  static RC create(Db *db, const Selects &select_sql, Stmt *&stmt);

public:
  const std::vector<Table *> &tables() const { return tables_; }
  const std::vector<AbstractField *> &query_fields() const { return query_fields_; }
  const std::vector<Field *> &group_by_fields() const { return group_by_fields_; }
  FilterStmt *filter_stmt() const { return filter_stmt_; }
  FilterStmt *having_filter_stmt() const { return having_filter_stmt_; }
  bool has_aggregation() const { return has_aggregation_; }
  const std::vector<FunctionField *> &aggregation_fields() const { return aggregation_fields_; }
  const std::vector<FunctionField *> &hidden_aggregation_fields() const { return hidden_aggregation_fields_; }

  std::vector<OrderFlag> order_flag() { return order_flag_; };
  std::vector<Field*> order_field() {return order_fields_; };
private:
  std::vector<AbstractField *> query_fields_;
  std::vector<Table *> tables_;
  FilterStmt *filter_stmt_ = nullptr;
  std::vector<Field *> order_fields_;
  std::vector<OrderFlag> order_flag_;
  FilterStmt *having_filter_stmt_ = nullptr;
  bool has_aggregation_ = false;
  std::vector<FunctionField *> aggregation_fields_;
  std::vector<FunctionField *> hidden_aggregation_fields_;
  std::vector<Field *> group_by_fields_;
};

