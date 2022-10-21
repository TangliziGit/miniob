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
// Created by Meiyi & Wangyunlai.wyl on 2021/5/18.
//

#include "storage/common/index_meta.h"
#include "storage/common/field_meta.h"
#include "storage/common/table_meta.h"
#include "common/lang/string.h"
#include "common/log/log.h"
#include "rc.h"
#include "json/json.h"

const static Json::StaticString FIELD_UNIQUE("unique");
const static Json::StaticString FIELD_NAME("name");
const static Json::StaticString FIELD_FIELD_NAME("field_name");

RC IndexMeta::init(const char *name, const std::vector<const FieldMeta*> &field,bool is_unique)
{
  if (common::is_blank(name)) {
    LOG_ERROR("Failed to init index, name is empty.");
    return RC::INVALID_ARGUMENT;
  }

  name_ = name;
  is_unique_ = is_unique;
  for (auto the_field : field) {
    fields_.emplace_back(the_field->name());
  }
  return RC::SUCCESS;
}

void IndexMeta::to_json(Json::Value &json_value) const
{
  json_value[FIELD_UNIQUE] = is_unique_;
  json_value[FIELD_NAME] = name_;
  Json::Value value;
  for (auto &filed : fields_) {
    value.append(filed);
  }
  json_value[FIELD_FIELD_NAME] = value;
}

RC IndexMeta::from_json(const TableMeta &table, const Json::Value &json_value, IndexMeta &index)
{
  const Json::Value &is_unique = json_value[FIELD_UNIQUE];
  const Json::Value &name_value = json_value[FIELD_NAME];
  const Json::Value &field_value = json_value[FIELD_FIELD_NAME];
  if(!is_unique.isBool()){
    return RC::GENERIC_ERROR;
  }
  if (!name_value.isString()) {
    LOG_ERROR("Index name is not a string. json value=%s", name_value.toStyledString().c_str());
    return RC::GENERIC_ERROR;
  }

  if (!field_value.isArray()) {
    return RC::GENERIC_ERROR;
  }
  int size = field_value.size();
  std::vector<const FieldMeta*> fileds;
  for (int i = 0; i < size; i++) {
    const FieldMeta *field = table.field(field_value[i].asCString());
    if (nullptr == field) {
      return RC::SCHEMA_FIELD_MISSING;
    }
    fileds.push_back(field);
  }

  return index.init(name_value.asCString(), fileds, is_unique.asBool());
}

const char *IndexMeta::name() const
{
  return name_.c_str();
}

const char *IndexMeta::field(int idx) const
{
  return fields_[idx].c_str();
}
bool IndexMeta::is_unique() const
{
  return is_unique_;
}

void IndexMeta::desc(std::ostream &os) const
{
  os << "index name=" << name_ << ", field=" << fields_[0];
  for (auto i = 1; i < fields_.size();i++){
    os << "," << fields_[i];
  }
}