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
// Created by Meiyi 
//

#include <mutex>
#include "sql/parser/parse.h"
#include "rc.h"
#include "common/log/log.h"

RC parse(char *st, Query *sqln);

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus
void parameter_init_attr(Parameter *parameter, RelAttr *attr) {
  parameter->is_value = 0;
  parameter->value = nullptr;
  parameter->attribute = new Parameter::RelAttr {
      .relation_name = attr->relation_name,
      .attribute_name = attr->attribute_name,
  };
}

void parameter_init_value(Parameter *parameter, Value *value) {
  parameter->is_value = 1;
  parameter->attribute = nullptr;
  parameter->value = new Parameter::Value {
      .type = value->type,
      .data = value->data,
  };
}

void function_init(RelAttr *function, Parameter *parameters, size_t parameter_length, const char *function_name) {
  *function = {
      .relation_name = nullptr,
      .attribute_name = nullptr,
      .function = new FunctionAttr{
          .function_name = strdup(function_name),
          .parameter_num = parameter_length,
          .parameters = {},
      }
  };

  for (size_t i=0; i<parameter_length; i++) {
    function->function->parameters[i] = parameters[i];
  }
}

void function_destroy(FunctionAttr *function) {
  if (function == nullptr) return;

  free(function->function_name);
  function->function_name = nullptr;
  for (size_t i = 0; i < function->parameter_num; i++) {
    // free(function->parameters[i].value->data);
    // function->parameters[i].value->data = nullptr;

    // free(function->parameters[i].attribute->attribute_name);
    // function->parameters[i].attribute->attribute_name = nullptr;
    // free(function->parameters[i].attribute->relation_name);
    // function->parameters[i].attribute->relation_name = nullptr;
  }
}

void expresion_destroy(Expr *expr) {
  if (expr == nullptr) return;

}

void relation_attr_init(RelAttr *relation_attr, const char *relation_name, const char *attribute_name)
{
  if (relation_name != nullptr) {
    relation_attr->relation_name = strdup(relation_name);
  } else {
    relation_attr->relation_name = nullptr;
  }
  relation_attr->attribute_name = strdup(attribute_name);
  relation_attr->function = nullptr;
}

void relation_attr_destroy(RelAttr *relation_attr)
{
  if(relation_attr->relation_name!=nullptr){
    free(relation_attr->relation_name);
  }
  free(relation_attr->attribute_name);
  function_destroy(relation_attr->function);
  expresion_destroy(relation_attr->expr);
  free(relation_attr->function);
  relation_attr->relation_name = nullptr;
  relation_attr->attribute_name = nullptr;
  relation_attr->function = nullptr;
  relation_attr->expr = nullptr;
}

void value_init_integer(Value *value, int v)
{
  value->type = INTS;
  value->data = malloc(sizeof(v));
  memcpy(value->data, &v, sizeof(v));
}
void value_init_float(Value *value, float v)
{
  value->type = FLOATS;
  value->data = malloc(sizeof(v));
  memcpy(value->data, &v, sizeof(v));
}
void value_init_string(Value *value, const char *v)
{
  value->type = CHARS;
  value->data = strdup(v);
}
bool check_date(int y,int m,int d){
   static int mon[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool leap = (y%400==0 || (y%100 && y%4==0));
    return (m > 0)&&(m <= 12)
        && (d > 0)&&(d <= ((m==2 && leap)?1:0) + mon[m]);
}
int value_init_date(Value* value, const char* v) {
    value->type = DATES;
    int y,m,d;
    sscanf(v, "%d-%d-%d", &y, &m, &d);
    bool b = check_date(y,m,d);
    if(!b) return -1;
    int dv = y*10000+m*100+d;
    value->data = malloc(sizeof(dv));
    memcpy(value->data, &dv, sizeof(dv));
    return 1;
}

void value_init_select(Value* value, Query *sub_query) {
  value->is_query = 1;
  value->data = sub_query;
}

void value_init_null(Value* value) {
  value->type = NULLS;
}

void expression_init(RelAttr *attr, RelAttr *expr_attr){
  attr->expr = expr_attr->expr;
}

void value_destroy(Value *value)
{
  value->type = UNDEFINED;
  if(value->data!=nullptr){
    if(value->is_query){
      query_destroy((Query *)value->data);
    }else free(value->data);
  }
  value->is_query = 0;
  value->data = nullptr;
}

void condition_in_init(Condition *condition, CompOp comp,int left_is_attr, RelAttr *left_attr, Value *left_value, int value_num, Value *right_value){
  condition->comp = comp;
  condition->left_is_attr = left_is_attr;
  if (left_is_attr) {
    condition->left_attr = *left_attr;
  } else {
    condition->left_value = *left_value;
  }
  condition->right_value_num = value_num;
  condition->right_is_attr = 0;
  for (int i = 0; i < value_num; i++) {
    condition->right_value[i] = right_value[i];
  }
}
void condition_init(Condition *condition, CompOp comp, int left_is_attr, RelAttr *left_attr, Value *left_value,
    int right_is_attr, RelAttr *right_attr, Value *right_value)
{
  condition->comp = comp;
  if (comp != CompOp::EXISTS && comp != CompOp::NOT_EXISTS) {
    condition->left_is_attr = left_is_attr;
    if (left_is_attr) {
      condition->left_attr = *left_attr;
    } else {
      condition->left_value = *left_value;
    }
  }

  condition->right_is_attr = right_is_attr;
  if (right_is_attr) {
    condition->right_attr = *right_attr;
  } else {
    condition->right_value[0] = *right_value;
    condition->right_value_num = 1;
  }
}
void condition_destroy(Condition *condition)
{
  if (condition->left_is_attr) {
    relation_attr_destroy(&condition->left_attr);
  } else {
    value_destroy(&condition->left_value);
  }
  if (condition->right_is_attr) {
    relation_attr_destroy(&condition->right_attr);
  } else {
    for (int i = 0; i < condition->right_value_num;i++){
      value_destroy(&condition->right_value[i]);
    }
    condition->right_value_num = 0;
  }
}

void attr_info_init(AttrInfo *attr_info, const char *name, AttrType type, size_t length,int nullable)
{
  attr_info->nullable = nullable;
  attr_info->name = strdup(name);
  attr_info->type = type;
  attr_info->length = length;
}
void attr_info_init_no_length(AttrInfo *attr_info, const char *name, AttrType type,int nullable)
{
  attr_info->nullable = nullable;
  attr_info->name = strdup(name);
  attr_info->type = type;
  int len = 4;
  switch (attr_info->type)
  {
  case TEXTS:
    len = 4096;
    break;
  
  default:
    break;
  }
  attr_info->length = len;
}
void attr_info_destroy(AttrInfo *attr_info)
{
  free(attr_info->name);
  attr_info->name = nullptr;
}

void append_expression(RelAttr*left_attr,OP op,RelAttr*right_attr){
  static char op_name[4][2] = {"+", "-", "*", "/"};
  Expr *left_expr = left_attr->expr;
  Expr *right_expr = right_attr->expr;
  left_expr->op[left_expr->expr_num] = op;
  left_expr->expr[left_expr->expr_num++] = right_expr;
  strcat(left_expr->name, op_name[(int)op]);
  strcat(left_expr->name, right_expr->name);
  right_attr->expr = nullptr;
}

void append_brace(RelAttr *attr){
  Expr *expr = attr->expr;
  char tmp[40] = {0};
  strcat(tmp, "(");
  strcat(tmp, expr->name);
  strcat(tmp, ")");
  strcpy(expr->name, tmp);
}

void init_expression(RelAttr*init_attr,int is_attr,RelAttr*attr,Value *value){
  init_attr->expr = (Expr *)(malloc(sizeof(Expr)));
  Expr *expr = init_attr->expr;
  expr->name[0] = 0;
  expr->is_attr = is_attr;
  if(expr->is_attr){
    const char *rel_name;
    const char *attr_name;
    if (attr->function != nullptr) {
      strcat(expr->name, attr->function->function_name);
      strcat(expr->name, "(");
      rel_name = attr->function->parameters[0].attribute->relation_name;
      attr_name = attr->function->parameters[0].attribute->attribute_name;
      if (rel_name != nullptr) {
        strcat(expr->name, rel_name);
        strcat(expr->name, ".");
      }
      strcat(expr->name, attr_name);
      strcat(expr->name, ")");
    }else{
      rel_name = attr->relation_name;
      attr_name = attr->attribute_name;
      if (rel_name != nullptr) {
        strcat(expr->name, rel_name);
        strcat(expr->name, ".");
      }
      strcat(expr->name, attr_name);
    }
    expr->attr = new Expr::Attr{
        .relation_name = attr->relation_name,
        .attribute_name = attr->attribute_name,
        .function = attr->function,
    };
  }else{
    /* todo,如果需要的话,请加上name */
    expr->value = new Expr::Val{
        .type = value->type,
        .data = value->data,
    };
  }
}

void selects_init(Selects *selects, ...);
void selects_append_attribute(Selects *selects, RelAttr *rel_attr, const char *alias)
{
  selects->attributes[selects->attr_num++] = *rel_attr;
  if (alias != nullptr) {
    selects->attribute_aliases[selects->attr_num-1] = strdup(alias);
  }
}
void selects_append_relation(Selects *selects, const char *relation_name, const char *alias)
{
  selects->relations[selects->relation_num++] = strdup(relation_name);
  if (alias != nullptr) {
    selects->relation_aliases[selects->relation_num-1] = strdup(alias);
  }
}
void selects_append_order(Selects *selects, RelAttr rel_attrs[], size_t order_num, OrderFlag flag[]) {
  for (size_t i = 0; i < order_num; i++) {
    selects->order_by[i] = rel_attrs[i];
    selects->order_flag[i] = flag[i];
  }
  selects->order_num = order_num;
  
}
void selects_append_conditions(Selects *selects, Condition conditions[], size_t condition_num)
{
  assert(condition_num <= sizeof(selects->conditions) / sizeof(selects->conditions[0]));
  for (size_t i = 0; i < condition_num; i++) {
    selects->conditions[i] = conditions[i];
  }
  selects->condition_num = condition_num;
}

void selects_append_group_by(Selects *selects, RelAttr rel_attr[], size_t attr_num) {
  for (size_t i = 0; i < attr_num; i++) {
    selects->group_by_attrs[i] = rel_attr[i];
  }
  selects->group_by_attr_num = attr_num;
}

void selects_append_having(Selects *selects, Condition conditions[], size_t condition_num) {
  for (size_t i = 0; i < condition_num; i++) {
    selects->having_conditions[i] = conditions[i];
  }
  selects->having_condition_num = condition_num;
}

void selects_destroy(Selects *selects)
{
  for (size_t i = 0; i < selects->attr_num; i++) {
    relation_attr_destroy(&selects->attributes[i]);
  }
  selects->attr_num = 0;

  for (size_t i = 0; i < selects->relation_num; i++) {
    free(selects->relations[i]);
    selects->relations[i] = NULL;
  }
  selects->relation_num = 0;

  for (size_t i = 0; i < selects->condition_num; i++) {
    condition_destroy(&selects->conditions[i]);
  }
  selects->condition_num = 0;
}

void inserts_init(Inserts *inserts, const char *relation_name, Value values[MAX_NUM][MAX_NUM], size_t value_num[MAX_NUM],size_t insert_num)
{
  inserts->relation_name = strdup(relation_name);
  for (size_t i = 0; i < insert_num; i++) {
    for (size_t j = 0; j < value_num[i];j++){
      inserts->values[i][j] = values[i][j];
    }
    inserts->value_num[i] = value_num[i];
  }
  inserts->insert_num = insert_num;
}
void inserts_destroy(Inserts *inserts)
{
  free(inserts->relation_name);
  inserts->relation_name = nullptr;
  int n = inserts->insert_num;
  for (int i = 0; i < n;i++){
    for (size_t j = 0; j < inserts->value_num[i]; j++) {
      value_destroy(&inserts->values[i][j]);
    }
    inserts->value_num[i] = 0;
  }
  inserts->insert_num = 0;
}

void deletes_init_relation(Deletes *deletes, const char *relation_name)
{
  deletes->relation_name = strdup(relation_name);
}

void deletes_set_conditions(Deletes *deletes, Condition conditions[], size_t condition_num)
{
  assert(condition_num <= sizeof(deletes->conditions) / sizeof(deletes->conditions[0]));
  for (size_t i = 0; i < condition_num; i++) {
    deletes->conditions[i] = conditions[i];
  }
  deletes->condition_num = condition_num;
}
void deletes_destroy(Deletes *deletes)
{
  for (size_t i = 0; i < deletes->condition_num; i++) {
    condition_destroy(&deletes->conditions[i]);
  }
  deletes->condition_num = 0;
  free(deletes->relation_name);
  deletes->relation_name = nullptr;
}

void updates_init(Updates *updates, const char *relation_name,size_t attr_num,const char attribute_name[MAX_NUM][MAX_NUM], Value value[MAX_NUM],
    Condition conditions[], size_t condition_num)
{
  updates->attr_num = attr_num;
  for (size_t i = 0; i < attr_num;i++){
    updates->value[i] = value[i];
    updates->attribute_name[i] = strdup(attribute_name[i]);
  }
  updates->relation_name = strdup(relation_name);
  for (size_t i = 0; i < condition_num; i++) {
    updates->conditions[i] = conditions[i];
  }
  updates->condition_num = condition_num;
}

void updates_destroy(Updates *updates)
{
  free(updates->relation_name);
  updates->relation_name = nullptr;
  for (size_t i = 0; i < updates->attr_num;i++){
    free(updates->attribute_name[i]);
    updates->attribute_name[i] = nullptr;
    value_destroy(&updates->value[i]);
  }
  updates->attr_num = 0;

  for (size_t i = 0; i < updates->condition_num; i++) {
    condition_destroy(&updates->conditions[i]);
  }
  updates->condition_num = 0;
}

void create_table_append_attribute(CreateTable *create_table, AttrInfo *attr_info)
{
  create_table->attributes[create_table->attribute_count++] = *attr_info;
}

void create_table_init_name(CreateTable *create_table, const char *relation_name)
{
  create_table->relation_name = strdup(relation_name);
}

void create_table_destroy(CreateTable *create_table)
{
  for (size_t i = 0; i < create_table->attribute_count; i++) {
    attr_info_destroy(&create_table->attributes[i]);
  }
  create_table->attribute_count = 0;
  free(create_table->relation_name);
  create_table->relation_name = nullptr;
}

void drop_table_init(DropTable *drop_table, const char *relation_name)
{
  drop_table->relation_name = strdup(relation_name);
}

void drop_table_destroy(DropTable *drop_table)
{
  free(drop_table->relation_name);
  drop_table->relation_name = nullptr;
}

void show_index_init(ShowIndex *show_index, const char *relation_name)
{
  show_index->relation_name = strdup(relation_name);
}

void show_index_destroy(ShowIndex *show_index)
{
  free((char *)show_index->relation_name);
  show_index->relation_name = nullptr;
}

void create_index_init(
    CreateIndex *create_index, const char *index_name, const char *relation_name, size_t atr_num, 
     const char attr_name[MAX_NUM][MAX_NUM],int is_unique)
{
  create_index->index_name = strdup(index_name);
  create_index->relation_name = strdup(relation_name);
  create_index->attribute_count = atr_num;
  for (size_t i = 0; i < atr_num;i++){
    create_index->attribute_name[i] = strdup(attr_name[i]);
  }
  create_index->is_unique = is_unique;
}

void create_index_destroy(CreateIndex *create_index)
{
  free(create_index->index_name);
  free(create_index->relation_name);
  for (size_t i = 0; i < create_index->attribute_count;i++){
     free(create_index->attribute_name[i]);
  }

  create_index->index_name = nullptr;
  create_index->relation_name = nullptr;
  for (size_t i = 0; i < create_index->attribute_count;i++){
    create_index->attribute_name[i] = nullptr;
  }
  create_index->attribute_count = 0;
}

void drop_index_init(DropIndex *drop_index, const char *index_name)
{
  drop_index->index_name = strdup(index_name);
}

void drop_index_destroy(DropIndex *drop_index)
{
  free((char *)drop_index->index_name);
  drop_index->index_name = nullptr;
}

void desc_table_init(DescTable *desc_table, const char *relation_name)
{
  desc_table->relation_name = strdup(relation_name);
}

void desc_table_destroy(DescTable *desc_table)
{
  free((char *)desc_table->relation_name);
  desc_table->relation_name = nullptr;
}

void load_data_init(LoadData *load_data, const char *relation_name, const char *file_name)
{
  load_data->relation_name = strdup(relation_name);

  if (file_name[0] == '\'' || file_name[0] == '\"') {
    file_name++;
  }
  char *dup_file_name = strdup(file_name);
  int len = strlen(dup_file_name);
  if (dup_file_name[len - 1] == '\'' || dup_file_name[len - 1] == '\"') {
    dup_file_name[len - 1] = 0;
  }
  load_data->file_name = dup_file_name;
}

void load_data_destroy(LoadData *load_data)
{
  free((char *)load_data->relation_name);
  free((char *)load_data->file_name);
  load_data->relation_name = nullptr;
  load_data->file_name = nullptr;
}

void query_init(Query *query)
{
  query->flag = SCF_ERROR;
  memset(&query->sstr, 0, sizeof(query->sstr));
}

Query *query_create()
{
  Query *query = (Query *)malloc(sizeof(Query));
  if (nullptr == query) {
    LOG_ERROR("Failed to alloc memroy for query. size=%ld", sizeof(Query));
    return nullptr;
  }

  query_init(query);
  return query;
}

void query_reset(Query *query)
{
  switch (query->flag) {
    case SCF_SELECT: {
      selects_destroy(&query->sstr.selection);
    } break;
    case SCF_INSERT: {
      inserts_destroy(&query->sstr.insertion);
    } break;
    case SCF_DELETE: {
      deletes_destroy(&query->sstr.deletion);
    } break;
    case SCF_UPDATE: {
      updates_destroy(&query->sstr.update);
    } break;
    case SCF_CREATE_TABLE: {
      create_table_destroy(&query->sstr.create_table);
    } break;
    case SCF_DROP_TABLE: {
      drop_table_destroy(&query->sstr.drop_table);
    } break;
    case SCF_CREATE_INDEX: {
      create_index_destroy(&query->sstr.create_index);
    } break;
    case SCF_DROP_INDEX: {
      drop_index_destroy(&query->sstr.drop_index);
    } break;
    case SCF_SYNC: {

    } break;
    case SCF_SHOW_TABLES:
      break;

    case SCF_DESC_TABLE: {
      desc_table_destroy(&query->sstr.desc_table);
    } break;

    case SCF_LOAD_DATA: {
      load_data_destroy(&query->sstr.load_data);
    } break;

    case SCF_SHOW_INDEX: {
      show_index_destroy(&query->sstr.show_index);
    } break;
    
    case SCF_CLOG_SYNC:
    case SCF_BEGIN:
    case SCF_COMMIT:
    case SCF_ROLLBACK:
    case SCF_HELP:
    case SCF_EXIT:
    case SCF_ERROR:
      break;
  }
}

void query_destroy(Query *query)
{
  query_reset(query);
  free(query);
}
#ifdef __cplusplus
}  // extern "C"
#endif  // __cplusplus

////////////////////////////////////////////////////////////////////////////////

extern "C" int sql_parse(const char *st, Query *sqls);

RC parse(const char *st, Query *sqln)
{
  sqln->date_parse_err = 1;
  sql_parse(st, sqln);

  if (sqln->flag == SCF_ERROR)
    return SQL_SYNTAX;
  else if(sqln->date_parse_err<0){
    return RC::DATE_ILLEGAL;
  }
  return SUCCESS;
}