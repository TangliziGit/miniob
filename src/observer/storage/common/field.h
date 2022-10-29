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

#pragma once

#include <utility>
#include <unordered_map>
#include <sstream>
#include "common/log/log.h"
#include "storage/common/table.h"
#include "storage/common/field_meta.h"
#include "sql/expr/tuple_cell.h"
#include "common/lang/string.h"
#include "util/util.h"

enum class FieldType {
  NONE,
  FIELD,
  VALUE_FIELD,
  FUNCTION_FIELD,
};

class AbstractField {
public:
  virtual FieldType type() const { return FieldType::NONE; }
  virtual const char *name() const { return "NONE"; }
  virtual const char *alias() const { return name(); }
  virtual AttrType attr_type() const { return UNDEFINED; }
};

class Field : public AbstractField {
public:
  Field() = default;
  Field(const Table *table, const FieldMeta *field, const char *table_alias, const char *field_alias)
      : table_(table), field_(field), table_alias_(table_alias), field_alias_(field_alias) {}

  FieldType type() const override     { return FieldType::FIELD; }
  const char *name() const override   { return field_name(); }
  const char *alias() const override  { return field_alias_? field_alias(): concat(table_alias(), field_alias()); }
  AttrType attr_type() const override { return field_->type(); }

public:
  const Table *table() const              { return table_; }
  const FieldMeta *meta() const           { return field_; }
  const char *table_name() const          { return table_->name(); }
  const char *field_name() const          { return field_->name(); }
  const char *table_alias() const         { return table_alias_? table_alias_: table_->name(); }
  const char *field_alias() const         { return field_alias_? field_alias_: field_->name(); }
  bool has_alias() const                  { return field_alias_ != nullptr; }

  void set_table(const Table *table)      { this->table_ = table; }
  void set_field(const FieldMeta *field)  { this->field_ = field; }

private:
  const Table *table_ = nullptr;
  const FieldMeta *field_ = nullptr;
  const char *table_alias_ = nullptr;
  const char *field_alias_ = nullptr;
};

class ValueField : public AbstractField {
public:
  ValueField(Value *value, const char *name, const char *alias)
      : value_(value), name_(name), alias_(alias) {}

  FieldType type() const override     { return FieldType::VALUE_FIELD; }
  const char *name() const override   { return name_; }
  const char *alias() const override  { return alias_? alias_: name(); }
  AttrType attr_type() const override { return value_->type; }

  Value *value() const { return value_; }

private:
  Value *value_;
  const char *name_;
  const char *alias_;
};

class FunctionField : public AbstractField {
public:
  FunctionField(std::vector<AbstractField *> fields, const char *name, const char *function_name, const char *alias)
      : fields_(std::move(fields)), name_(name), function_name_(function_name), alias_(alias) {}

  FieldType type() const override     { return FieldType::FUNCTION_FIELD; }
  const char *name() const override   { return name_; }
  const char *alias() const override  { return alias_? alias_: name(); }
  AttrType attr_type() const override { return UNDEFINED; }

  const char *function_name() const { return function_name_; }
  std::vector<AbstractField *> fields() const { return fields_; }

public:
  static std::pair<FunctionField *, RC> make(
      Table *default_table,
      std::unordered_map<std::string, Table *> table_map,
      FunctionAttr *function_attr,
      const char *alias) {
    std::vector<AbstractField*> fields;
    std::stringstream name;
    std::stringstream value_name;

    name << function_attr->function_name << '(';
    for (size_t i=0; i<function_attr->parameter_num; i++) {
      const auto &param = function_attr->parameters[i];

      if (param.is_value) {
        auto value = reinterpret_cast<Value *>(param.value);
        TupleCell cell(value->type, (char *) value->data);

        value_name.clear();
        cell.to_string(value_name);
        auto field = new ValueField{value, value_name.str().c_str(), nullptr};
        fields.push_back(field);

        name << field->name();
      } else {
        const auto &attr = param.attribute;
        const auto &table_name = attr->relation_name;
        const auto &field_name = attr->attribute_name;

        if (common::is_blank(table_name) && 0 == strcmp(field_name, "*")) {
          if (0 != strcmp(function_attr->function_name, "count")) {
            return { nullptr, RC::INVALID_ARGUMENT };
          }

          auto value = new Value{ INTS, new int(1) };
          auto field = new ValueField{value, "*", nullptr};
          fields.push_back(field);
          name << field->name();
          continue;
        }

        Table *table = nullptr;
        if (table_name == nullptr) {
          table = default_table;
        } else {
          auto iter = table_map.find(table_name);
          if (iter == table_map.end()) {
            LOG_WARN("no such table in from list: %s", table_name);
            return { nullptr, RC::SCHEMA_FIELD_MISSING };
          }
          table = iter->second;
        }

        const FieldMeta *field_meta = table->table_meta().field(field_name);
        if (nullptr == field_meta) {
          LOG_WARN("no such field. field=%s.%s", table->name(), field_name);
          return { nullptr, RC::SCHEMA_FIELD_MISSING };
        }

        auto field = new Field{table, field_meta, nullptr, nullptr};
        fields.push_back(field);
        if(table_map.size()>1){
          /* 多表查询,需要带上表名 */
          name << table->name() << ".";
        }
        name << field->name();
      }

      if (i != function_attr->parameter_num - 1) {
        name << ", ";
      }
    }
    name << ')';

    // TODO(chunxu): what if this name duplicates?
    auto field = new FunctionField{ fields, strdup(name.str().c_str()), function_attr->function_name, alias };
    return { field, RC::SUCCESS };
  }

private:
  const std::vector<AbstractField *> fields_;
  const char *name_;
  const char *function_name_;
  const char *alias_;
};