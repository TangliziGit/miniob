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
// Created by Wangyunlai on 2022/6/6.
//

#include "sql/stmt/select_stmt.h"
#include "sql/stmt/filter_stmt.h"
#include "common/log/log.h"
#include "common/lang/string.h"
#include "storage/common/db.h"
#include "storage/common/table.h"
#include "sql/function/register.h"

SelectStmt::~SelectStmt()
{
  // if (nullptr != filter_stmt_) {
  //   delete filter_stmt_;
  //   filter_stmt_ = nullptr;
  // }
}

static void wildcard_fields(Table *table, const char *table_alias, std::vector<Field *> &field_metas)
{
  const TableMeta &table_meta = table->table_meta();
  const int field_num = table_meta.field_num();
  for (int i = table_meta.sys_field_num(); i < field_num; i++) {
    field_metas.push_back(new Field(table, table_meta.field(i), table_alias, nullptr));
  }
}

static void wildcard_fields(Table *table, const char *table_alias, std::vector<AbstractField *> &field_metas)
{
  const TableMeta &table_meta = table->table_meta();
  const int field_num = table_meta.field_num();
  for (int i = table_meta.sys_field_num(); i < field_num; i++) {
    field_metas.push_back(new Field(table, table_meta.field(i), table_alias, nullptr));
  }
}

bool same_field_exists(const std::vector<FunctionField *> &fields, AbstractField &field) {
  for (const auto &f: fields) {
    if (f->name() == field.name()) return true;
  }
  return false;
}

RC SelectStmt::create(Db *db, const Selects &select_sql, Stmt *&stmt,std::unordered_map<std::string, Table *>& out_table_map)
{
  if (nullptr == db) {
    LOG_WARN("invalid argument. db is null");
    return RC::INVALID_ARGUMENT;
  }

  // collect tables in `from` statement
  std::vector<Table *> tables;
  std::unordered_map<Table *, const char *> table_aliases;
  /* 默认为true,即每次遇到都重新计算一下,后面如果出现超时问题就优化这里 */
  bool contain_other_field = true;
  std::unordered_map<std::string, Table *> table_map;
  for (size_t i = 0; i < select_sql.relation_num; i++) {
    const char *table_name = select_sql.relations[i];
    const char *alias = select_sql.relation_aliases[i];
    if (nullptr == table_name) {
      LOG_WARN("invalid argument. relation name is null. index=%d", i);
      return RC::INVALID_ARGUMENT;
    }

    Table *table = db->find_table(table_name);
    if (nullptr == table) {
      LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
      return RC::SCHEMA_TABLE_NOT_EXIST;
    }

    tables.push_back(table);
    table_aliases[table] = alias;
    table_map.insert(std::pair<std::string, Table*>(table_name, table));
    if (alias != nullptr) {
      if (table_map.find(alias) != table_map.end()) {
        return RC::GENERIC_ERROR;
      }

      table_map.insert(std::pair<std::string, Table*>(alias, table));
    }
  }

  // collect query fields in `select` statement
  bool has_aggregation = false;
  std::vector<AbstractField *> query_fields;
  std::vector<FunctionField *> agg_fields;
  std::vector<Field *> order_by_fields;
  std::vector<OrderFlag> order_flag;
  for (int i = select_sql.attr_num - 1; i >= 0; i--) {
    const RelAttr &relation_attr = select_sql.attributes[i];
    const auto &alias = select_sql.attribute_aliases[i];

    // set function field
    if (relation_attr.function != nullptr) {
      auto result = FunctionField::make(tables[0], table_map, relation_attr.function, alias);
      if (result.second != RC::SUCCESS) {
        return result.second;
      }
      query_fields.push_back(result.first);

      bool is_agg = FunctionRegister::is_aggregation(relation_attr.function->function_name);
      has_aggregation |= is_agg;
      if (is_agg) {
        agg_fields.push_back(result.first);
      }
      continue;
    }

    // set wildcard '*' field
    if (common::is_blank(relation_attr.relation_name) && 0 == strcmp(relation_attr.attribute_name, "*")) {
      if (alias != nullptr) {
        return RC::GENERIC_ERROR;
      }

      for (Table *table : tables) {
        wildcard_fields(table, table_aliases[table], query_fields);
      }
      continue;
    }

    // set field with table name
    if (!common::is_blank(relation_attr.relation_name)) { // TODO
      const char *table_name = relation_attr.relation_name;
      const char *field_name = relation_attr.attribute_name;

      if (0 == strcmp(table_name, "*")) {
        if (0 != strcmp(field_name, "*")) {
          LOG_WARN("invalid field name while table is *. attr=%s", field_name);
          return RC::SCHEMA_FIELD_MISSING;
        }
        for (Table *table : tables) {
          wildcard_fields(table, table_aliases[table], query_fields);
        }
      } else {
        auto iter = table_map.find(table_name);
        if (iter == table_map.end()) {
          LOG_WARN("no such table in from list: %s", table_name);
          return RC::SCHEMA_FIELD_MISSING;
        }

        Table *table = iter->second;
        if (0 == strcmp(field_name, "*")) {
          if (alias != nullptr) {
            return RC::GENERIC_ERROR;
          }

          wildcard_fields(table, table_aliases[table], query_fields);
        } else {
          const FieldMeta *field_meta = table->table_meta().field(field_name);
          if (nullptr == field_meta) {
            LOG_WARN("no such field. field=%s.%s.%s", db->name(), table->name(), field_name);
            return RC::SCHEMA_FIELD_MISSING;
          }

        query_fields.push_back(new Field(table, field_meta, table_aliases[table], alias));
        }
      }
      continue;
    }

    // set normal field
    if (tables.size() != 1) {
      LOG_WARN("invalid. I do not know the attr's table. attr=%s", relation_attr.attribute_name);
      return RC::SCHEMA_FIELD_MISSING;
    }

    Table *table = tables[0];
    const FieldMeta *field_meta = table->table_meta().field(relation_attr.attribute_name);
    if (nullptr == field_meta) {
      LOG_WARN("no such field. field=%s.%s.%s", db->name(), table->name(), relation_attr.attribute_name);
      return RC::SCHEMA_FIELD_MISSING;
    }

    query_fields.push_back(new Field(table, field_meta, table_aliases[table], alias));
  }

  LOG_INFO("got %d tables in from stmt and %d fields in query stmt", tables.size(), query_fields.size());

  for (size_t i = 0; i < select_sql.order_num; i++) {
    const RelAttr  &relation_attr = select_sql.order_by[i];
    Table* table = tables[0];
    if (!common::is_blank(relation_attr.relation_name)) {
      auto iter = table_map.find(relation_attr.relation_name);
      table = iter->second;
    }
    const FieldMeta *field_meta = table->table_meta().field(relation_attr.attribute_name);
    if (nullptr == field_meta) {
      LOG_WARN("no such field. field=%s.%s.%s", db->name(), table->name(), relation_attr.attribute_name);
      return RC::SCHEMA_FIELD_MISSING;
    }
    order_flag.push_back(select_sql.order_flag[i]);
    order_by_fields.push_back(new Field(table, field_meta, table_aliases[table], nullptr));
  }
  Table *default_table = nullptr;
  if (tables.size() == 1) {
    default_table = tables[0];
  }

  for(auto &itr:table_map){
    out_table_map.insert({itr.first, itr.second});
  }
  // create filter statement in `where` statement
  FilterStmt *filter_stmt = nullptr;
  RC rc = FilterStmt::create(db, default_table, &out_table_map,
           select_sql.conditions, select_sql.condition_num, filter_stmt);
  if (rc != RC::SUCCESS) {
    LOG_WARN("cannot construct filter stmt");
    return rc;
  }

  // collect aggregation fields in group by clause
  std::vector<Field *> group_by_fields;
  for (size_t i=0; i<select_sql.group_by_attr_num; i++) {
    const auto relation_attr = select_sql.group_by_attrs[i];
    // NOTE: the code below is copied from initialize query fields

    // set field with table name
    if (!common::is_blank(relation_attr.relation_name)) {
      const char *table_name = relation_attr.relation_name;
      const char *field_name = relation_attr.attribute_name;

      if (0 == strcmp(table_name, "*")) {
        if (0 != strcmp(field_name, "*")) {
          LOG_WARN("invalid field name while table is *. attr=%s", field_name);
          return RC::SCHEMA_FIELD_MISSING;
        }
        for (Table *table : tables) {
          wildcard_fields(table, table_aliases[table], group_by_fields);
        }
      } else {
        auto iter = table_map.find(table_name);
        if (iter == table_map.end()) {
          LOG_WARN("no such table in from list: %s", table_name);
          return RC::SCHEMA_FIELD_MISSING;
        }

        Table *table = iter->second;
        if (0 == strcmp(field_name, "*")) {
          wildcard_fields(table, table_aliases[table], group_by_fields);
        } else {
          const FieldMeta *field_meta = table->table_meta().field(field_name);
          if (nullptr == field_meta) {
            LOG_WARN("no such field. field=%s.%s.%s", db->name(), table->name(), field_name);
            return RC::SCHEMA_FIELD_MISSING;
          }

          group_by_fields.push_back(new Field(table, field_meta, table_aliases[table], nullptr));
        }
      }
      continue;
    }

    // set normal field
    if (tables.size() != 1) {
      LOG_WARN("invalid. I do not know the attr's table. attr=%s", relation_attr.attribute_name);
      return RC::SCHEMA_FIELD_MISSING;
    }

    Table *table = tables[0];
    const FieldMeta *field_meta = table->table_meta().field(relation_attr.attribute_name);
    if (nullptr == field_meta) {
      LOG_WARN("no such field. field=%s.%s.%s", db->name(), table->name(), relation_attr.attribute_name);
      return RC::SCHEMA_FIELD_MISSING;
    }

    group_by_fields.push_back(new Field(table, field_meta, table_aliases[table], nullptr));
  }

  // collect aggregation conditions in having clause
  FilterStmt *having_filter_stmt = nullptr;
  rc = FilterStmt::create(db, default_table, &out_table_map,
      select_sql.having_conditions, select_sql.having_condition_num, having_filter_stmt);
  if (rc != RC::SUCCESS) {
    LOG_WARN("cannot construct having filter stmt");
    return rc;
  }

  std::vector<FunctionField *> hidden_agg_fields;
  for (size_t i = 0; i < select_sql.having_condition_num; i++) {
    auto condition = select_sql.having_conditions[i];

    if (condition.left_is_attr && condition.left_attr.function != nullptr) {
      auto func_attr = condition.left_attr.function;
      auto result = FunctionField::make(tables[0], table_map, func_attr, nullptr);
      if (result.second != RC::SUCCESS) {
        return result.second;
      }

      bool is_agg = FunctionRegister::is_aggregation(func_attr->function_name);
      has_aggregation |= is_agg;
      if (is_agg && !same_field_exists(agg_fields, *result.first)) {
        agg_fields.push_back(result.first);
        hidden_agg_fields.push_back(result.first);
      }
    }

    if (condition.right_is_attr && condition.right_attr.function != nullptr) {
      auto func_attr = condition.right_attr.function;
      auto result = FunctionField::make(tables[0], table_map, func_attr, nullptr);
      if (result.second != RC::SUCCESS) {
        return result.second;
      }

      bool is_agg = FunctionRegister::is_aggregation(func_attr->function_name);
      has_aggregation |= is_agg;
      if (is_agg && !same_field_exists(agg_fields, *result.first)) {
        agg_fields.push_back(result.first);
        hidden_agg_fields.push_back(result.first);
      }
    }
  }

  // everything alright
  SelectStmt *select_stmt = new SelectStmt();
  select_stmt->contain_other_field_ = contain_other_field;
  select_stmt->tables_.swap(tables);
  select_stmt->query_fields_.swap(query_fields);
  select_stmt->group_by_fields_.swap(group_by_fields);
  select_stmt->filter_stmt_ = filter_stmt;
  select_stmt->having_filter_stmt_ = having_filter_stmt;
  select_stmt->has_aggregation_ = has_aggregation;
  select_stmt->aggregation_fields_ = agg_fields;
  select_stmt->hidden_aggregation_fields_ = hidden_agg_fields;
  select_stmt->order_fields_.swap(order_by_fields);
  select_stmt->order_flag_.swap(order_flag);
  stmt = select_stmt;
  return RC::SUCCESS;
}
