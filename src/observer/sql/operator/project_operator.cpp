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
// Created by WangYunlai on 2022/07/01.
//

#include "common/log/log.h"
#include "sql/operator/project_operator.h"
#include "storage/record/record.h"
#include "storage/common/table.h"
#include "sql/function/register.h"

RC ProjectOperator::open()
{
  if (children_.size() != 1) {
    LOG_WARN("project operator must has 1 child");
    return RC::INTERNAL;
  }

  Operator *child = children_[0];
  RC rc = child->open();
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open child operator: %s", strrc(rc));
    return rc;
  }

  return RC::SUCCESS;
}

RC ProjectOperator::next()
{
  return children_[0]->next();
}

RC ProjectOperator::close()
{
  children_[0]->close();
  return RC::SUCCESS;
}
Tuple *ProjectOperator::current_tuple()
{
  tuple_.set_tuple(children_[0]->current_tuple());
  return &tuple_;
}

RC ProjectOperator::add_projection(const AbstractField *abstract_field)
{
  // 对单表来说，展示的(alias) 字段总是字段名称，
  // 对多表查询来说，展示的alias 需要带表名字
  switch (abstract_field->type()) {
    case FieldType::FIELD: {
      auto field = dynamic_cast<const Field *>(abstract_field);
      auto *spec = new TupleCellSpec(new FieldExpr(field->table(), field->meta()));
      spec->set_alias(field->name());
      tuple_.add_cell_spec(spec);
      break;
    }
    case FieldType::VALUE_FIELD: {
      auto field = dynamic_cast<const ValueField *>(abstract_field);
      auto *spec = new TupleCellSpec(new ValueExpr(*field->value()));
      spec->set_alias(field->name());
      tuple_.add_cell_spec(spec);
      break;
    }
    case FieldType::FUNCTION_FIELD: {
      auto field = dynamic_cast<const FunctionField *>(abstract_field);
      if (FunctionRegister::is_aggregation(field->function_name())) {
        // you should not apply aggregation in project operator
        return RC::MISUSE;
      }

      auto result = FunctionRegister::create(field->function_name());
      if (result.second != RC::SUCCESS) {
        return result.second;
      }

      auto *spec = new TupleCellSpec(new FunctionExpr(field->fields(), result.first));
      spec->set_alias(field->name());
      tuple_.add_cell_spec(spec);
      break;
    }
    default:
      return RC::MISMATCH;
  }
  return RC::SUCCESS;
}

RC ProjectOperator::tuple_cell_spec_at(int index, const TupleCellSpec *&spec) const
{
  return tuple_.cell_spec_at(index, spec);
}
