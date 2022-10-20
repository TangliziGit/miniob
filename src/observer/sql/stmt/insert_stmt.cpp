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

#include "sql/stmt/insert_stmt.h"
#include "common/log/log.h"
#include "storage/common/db.h"
#include "storage/common/table.h"
#include "util/comparator.h"

InsertStmt::InsertStmt(Table *table, const Value values[MAX_NUM][MAX_NUM], const size_t value_amount[MAX_NUM],const size_t insert_num)
  : table_ (table),insert_num_(insert_num){
  for (int i = 0;i<insert_num_;i++){
    values_[i] = values[i];
    value_amount_[i] = value_amount[i];
  }
}

RC InsertStmt::create(Db *db, const Inserts &inserts, Stmt *&stmt)
{
  const char *table_name = inserts.relation_name;
  if (nullptr == db || nullptr == table_name || inserts.insert_num <= 0) {
    LOG_WARN("invalid argument. db=%p, table_name=%p, value_num=%d", 
             db, table_name, inserts.insert_num);
    return RC::INVALID_ARGUMENT;
  }

  // check whether the table exists
  Table *table = db->find_table(table_name);
  if (nullptr == table) {
    LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  // check the fields number and type cast
  auto values = new Value[MAX_NUM][MAX_NUM];
  memcpy(values, inserts.values, sizeof(inserts.values));

  int n = inserts.insert_num;
  for (int i = 0; i < n; i++) {
    Value *newVals = values[i];
    const Value *vals = inserts.values[i];
    const int value_num = inserts.value_num[i];
    const TableMeta &table_meta = table->table_meta();
    const int field_num = table_meta.field_num() - table_meta.sys_field_num();
    if (field_num != value_num) {
      LOG_WARN("schema mismatch. value num=%d, field num in schema=%d", value_num, field_num);
      return RC::SCHEMA_FIELD_MISSING;
    }

    // check fields type
    const int sys_field_num = table_meta.sys_field_num();
    for (int i = 0; i < value_num; i++) {
      const FieldMeta *field_meta = table_meta.field(i + sys_field_num);
      const AttrType field_type = field_meta->type();
      const AttrType value_type = vals[i].type;
      if (field_type != value_type) {
        // CHARS can not be converted into INTS, see 2.ERROR case in `primary-insert.result`
        if (field_type == CHARS && value_type == INTS) {
          return RC::SCHEMA_FIELD_TYPE_MISMATCH;
        }

        RC rc = cast_to(&newVals[i], field_type);
        if (rc != RC::SUCCESS) {
          return rc;
        }
      }
    }
  }

    // everything alright
  stmt = new InsertStmt(table, values, inserts.value_num, inserts.insert_num);
  return RC::SUCCESS;
}
