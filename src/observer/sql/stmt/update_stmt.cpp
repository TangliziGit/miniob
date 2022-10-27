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

#include "common/log/log.h"
#include "sql/stmt/update_stmt.h"
#include "sql/stmt/filter_stmt.h"
#include "storage/common/db.h"
#include "util/comparator.h"

UpdateStmt::UpdateStmt(Table *table, FilterStmt *filter,std::vector<const char *>&attr_name,std::vector<Value>&value)
  :table_ (table), filter_(filter),attr_name_(std::move(attr_name)),value_(std::move(value))
{}

RC UpdateStmt::create(Db *db, const Updates &update, Stmt *&stmt)
{
  const char *table_name = update.relation_name;
  if (nullptr == db || nullptr == table_name) {
    LOG_WARN("invalid argument. db=%p, table_name=%p", db, table_name);
    return RC::INVALID_ARGUMENT;
  }

  // check whether the table exists
  Table *table = db->find_table(table_name);
  if (nullptr == table) {
    LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }
  std::vector<const char *> attr_name;
  std::vector<Value> value;
  int num = update.attr_num;
  RC rc = RC::SUCCESS;
  for (int i = 0; i < num; i++) {
    const FieldMeta *attr_meta = table->table_meta().field(update.attribute_name[i]);
    if (attr_meta == nullptr) {
      LOG_WARN("no such attribute name field. db=%s, table_name=%s, attribute_name=%s",
          db->name(),
          table_name,
          update.attribute_name);
      return RC::SCHEMA_FIELD_NOT_EXIST;
    }
    Value new_value = update.value[i];
    if (attr_meta->type() != update.value[i].type&&update.value[i].type!=NULLS&&!update.value[i].is_query) {
      RC rc = cast_to(&new_value, attr_meta->type());
      if (rc != RC::SUCCESS) {
        return rc;
      }
    }
    if(update.value[i].type == NULLS && !attr_meta->nullable()){
      return RC::SCHEMA_FIELD_TYPE_MISMATCH;
    }
    
    attr_name.emplace_back(update.attribute_name[i]);
    value.emplace_back(new_value);
  }

    std::unordered_map<std::string, Table *> table_map;
  table_map.insert(std::pair<std::string, Table *>(std::string(table_name), table));

  FilterStmt *filter_stmt = nullptr;
  rc = FilterStmt::create(db, table, &table_map,
                             update.conditions, update.condition_num, filter_stmt);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to create filter statement. rc=%d:%s", rc, strrc(rc));
    return rc;
  }

  stmt = new UpdateStmt(table, filter_stmt, attr_name, value);
  return rc;
}
