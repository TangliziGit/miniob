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

#ifndef __OBSERVER_SQL_PARSER_PARSE_DEFS_H__
#define __OBSERVER_SQL_PARSER_PARSE_DEFS_H__

#include <stddef.h>
#define MAX_NUM 20
#define MAX_REL_NAME 20
#define MAX_ATTR_NAME 20
#define MAX_ERROR_MESSAGE 20
#define MAX_DATA 50

//属性值类型
typedef enum
{
  UNDEFINED,
  CHARS,
  INTS,
  FLOATS,
  DATES,
  TEXTS,
  NULLS,
} AttrType;

typedef struct {
  // to avoid cycle dependence, declare Value and RelAttr as sub struct here
  struct Value {
    AttrType type;
    void *data;
  };
  struct RelAttr {
    char *relation_name;   // relation name (may be NULL) 表名
    char *attribute_name;  // attribute name              属性名
  };

  int is_value;
  struct Value *value;
  struct RelAttr *attribute;
} Parameter;

typedef struct {
  char *function_name;
  size_t parameter_num;
  Parameter parameters[MAX_NUM];
} FunctionAttr;

typedef enum {
  ADD=0,
  SUB,
  MUL,
  DIV,
  ADD_NEG,
} OP;

typedef struct _Expr{
  struct Attr{
  char *relation_name;   // relation name (may be NULL) 表名
  char *attribute_name;  // attribute name              属性名
  FunctionAttr *function;
  };
  
  struct Val {
    AttrType type;
    void *data;
  };

  char name[80];
  struct Val *value;
  struct Attr* attr;
  int is_attr;
  int expr_num;
  struct _Expr *expr[MAX_NUM*4];
  OP op[MAX_NUM*4];
}Expr;

//属性结构体
typedef struct {
  char *relation_name;   // relation name (may be NULL) 表名
  char *attribute_name;  // attribute name              属性名
  FunctionAttr *function;
  Expr *expr;
} RelAttr;

typedef enum {
  EQUAL_TO,     //"="     0
  LESS_EQUAL,   //"<="    1
  NOT_EQUAL,    //"<>"    2
  LESS_THAN,    //"<"     3
  GREAT_EQUAL,  //">="    4
  GREAT_THAN,   //">"     5
  NOT_LIKE,
  LIKE,
  IS,
  IS_NOT,
  IN,
  NOT_IN,
  EXISTS,
  NOT_EXISTS,
  NO_OP,
} CompOp;


typedef enum {
  NO_ORDER,
  ASC_T,
  DESC_T,
} OrderFlag;

//属性值
typedef struct _Value {
  AttrType type;  // type of value
  void *data;     // value
  int is_query;
  char name[20];
} Value;

typedef struct _Condition {
  int is_or;
  int left_is_attr;    // TRUE if left-hand side is an attribute
                       // 1时，操作符左边是属性名，0时，是属性值
  Value left_value;    // left-hand side value if left_is_attr = FALSE
  RelAttr left_attr;   // left-hand side attribute
  CompOp comp;         // comparison operator
  int right_is_attr;   // TRUE if right-hand side is an attribute
                       // 1时，操作符右边是属性名，0时，是属性值
  RelAttr right_attr;  // right-hand side attribute if right_is_attr = TRUE 右边的属性
  int right_value_num;    // value num for (NOT) IN comp
  Value right_value[MAX_NUM];  // right-hand side value if right_is_attr = FALSE
} Condition;

// struct of select
typedef struct {
  size_t attr_num;                        // Length of attrs in Select clause
  RelAttr attributes[MAX_NUM];            // attrs in Select clause
  const char *attribute_aliases[MAX_NUM]; // attrs alias in Select clause
  size_t relation_num;                    // Length of relations in From clause
  char *relations[MAX_NUM];               // relations in From clause
  char *relation_aliases[MAX_NUM];        // relation aliases in From clause
  size_t condition_num;                   // Length of conditions in Where clause
  Condition conditions[MAX_NUM];          // conditions in Where clause
  size_t group_by_attr_num;               // Length of attrs in Group By clause
  RelAttr group_by_attrs[MAX_NUM];        // attrs in Group By clause
  size_t having_condition_num;            // Length of conditions in Having clause
  Condition having_conditions[MAX_NUM];   // conditions in Having clause
  size_t order_num;                       // Length of attrs in order by
  RelAttr order_by[MAX_NUM];              // order by field
  OrderFlag order_flag[MAX_NUM];          // DESC or ASC(Default)
} Selects;

// struct of insert
typedef struct {
  char *relation_name;    // Relation to insert into
  size_t insert_num;
  size_t value_num[MAX_NUM];       // Length of values
  Value values[MAX_NUM][MAX_NUM];  // values to insert
} Inserts;

// struct of delete
typedef struct {
  char *relation_name;            // Relation to delete from
  size_t condition_num;           // Length of conditions in Where clause
  Condition conditions[MAX_NUM];  // conditions in Where clause
} Deletes;

// struct of update
typedef struct {
  char *relation_name;            // Relation to update
  size_t attr_num;
  char *attribute_name[MAX_NUM];           // Attribute to update
  Value value[MAX_NUM];                    // update value
  size_t condition_num;           // Length of conditions in Where clause
  Condition conditions[MAX_NUM];  // conditions in Where clause
} Updates;

typedef struct {
  char *name;     // Attribute name
  AttrType type;  // Type of attribute
  size_t length;  // Length of attribute
  int nullable;
} AttrInfo;

// struct of craete_table
typedef struct {
  char *relation_name;           // Relation name
  size_t attribute_count;        // Length of attribute
  AttrInfo attributes[MAX_NUM];  // attributes
} CreateTable;

// struct of drop_table
typedef struct {
  char *relation_name;  // Relation name
} DropTable;

// struct of create_index
typedef struct {
  int is_unique;         // unique
  char *index_name;      // Index name
  char *relation_name;   // Relation name
  size_t attribute_count;
  char *attribute_name[MAX_NUM];  // Attribute name
} CreateIndex;

// struct of  drop_index
typedef struct {
  const char *index_name;  // Index name
} DropIndex;

typedef struct {
  const char *relation_name;
} DescTable;

typedef struct {
  const char *relation_name;
  const char *file_name;
} LoadData;

typedef struct {
  const char *relation_name;
} ShowIndex;

union Queries {
  Selects selection;
  Inserts insertion;
  Deletes deletion;
  Updates update;
  CreateTable create_table;
  DropTable drop_table;
  CreateIndex create_index;
  DropIndex drop_index;
  DescTable desc_table;
  LoadData load_data;
  ShowIndex show_index;
  char *errors;
};

// 修改yacc中相关数字编码为宏定义
enum SqlCommandFlag {
  SCF_ERROR = 0,
  SCF_SELECT,
  SCF_INSERT,
  SCF_UPDATE,
  SCF_DELETE,
  SCF_CREATE_TABLE,
  SCF_DROP_TABLE,
  SCF_CREATE_INDEX,
  SCF_DROP_INDEX,
  SCF_SYNC,
  SCF_SHOW_TABLES,
  SCF_DESC_TABLE,
  SCF_BEGIN,
  SCF_COMMIT,
  SCF_CLOG_SYNC,
  SCF_ROLLBACK,
  SCF_LOAD_DATA,
  SCF_HELP,
  SCF_EXIT,
  SCF_SHOW_INDEX
};
// struct of flag and sql_struct
typedef struct Query {
  int date_parse_err;
  enum SqlCommandFlag flag;
  union Queries sstr;
} Query;

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

void parameter_init_attr(Parameter *parameter, RelAttr *attr);
void parameter_init_value(Parameter *parameter, Value *value);
void function_init(RelAttr *function, Parameter *parameters, size_t parameter_length, const char *function_name);
void function_destroy(FunctionAttr *function);

void relation_attr_init(RelAttr *relation_attr, const char *relation_name, const char *attribute_name);
void relation_attr_destroy(RelAttr *relation_attr);

void value_init_integer(Value *value, int v);
void value_init_float(Value *value, float v);
void value_init_string(Value *value, const char *v);
int  value_init_date(Value *value, const char *v);
void value_init_select(Value *value, Query *sub_query);
void value_init_null(Value *value);

void value_destroy(Value *value);

void condition_init(Condition *condition, CompOp comp, int left_is_attr, RelAttr *left_attr, Value *left_value,
    int right_is_attr, RelAttr *right_attr, Value *right_value);
void condition_in_init(Condition *condition, CompOp comp,int left_is_attr, RelAttr *left_attr, Value *left_value,
    int value_num, Value *right_value);
void condition_destroy(Condition *condition);

void attr_info_init(AttrInfo *attr_info, const char *name, AttrType type, size_t length,int nullable);
void attr_info_init_no_length(AttrInfo *attr_info, const char *name, AttrType type,int nullable);
void attr_info_destroy(AttrInfo *attr_info);

void append_expression(RelAttr *left_expr, OP op, RelAttr *right_expr);
void append_brace(RelAttr *expr);
void append_neg(RelAttr *expr);
void init_expression(RelAttr *expr, int is_attr, RelAttr *attr, Value *value);

void selects_init(Selects *selects, ...);
void selects_append_attribute(Selects *selects, RelAttr *rel_attr, const char *alias);
void selects_append_relation(Selects *selects, const char *relation_name, const char *alias);
void selects_append_order(Selects *selects, RelAttr rel_attrs[], size_t order_num, OrderFlag flag[]);
void selects_append_conditions(Selects *selects, Condition conditions[], size_t condition_num);
void selects_append_group_by(Selects *selects, RelAttr rel_attr[], size_t attr_num);
void selects_append_having(Selects *selects, Condition conditions[], size_t condition_num);
void selects_destroy(Selects *selects);

void inserts_init(Inserts *inserts, const char *relation_name, Value values[MAX_NUM][MAX_NUM], size_t value_num[MAX_NUM], size_t insert_num);
void inserts_destroy(Inserts *inserts);

void deletes_init_relation(Deletes *deletes, const char *relation_name);
void deletes_set_conditions(Deletes *deletes, Condition conditions[], size_t condition_num);
void deletes_destroy(Deletes *deletes);

void updates_init(Updates *updates, const char *relation_name,size_t attr_num,const char attribute_name[MAX_NUM][MAX_NUM], Value value[MAX_NUM],
    Condition conditions[], size_t condition_num);
void updates_destroy(Updates *updates);

void create_table_append_attribute(CreateTable *create_table, AttrInfo *attr_info);
void create_table_init_name(CreateTable *create_table, const char *relation_name);
void create_table_destroy(CreateTable *create_table);

void drop_table_init(DropTable *drop_table, const char *relation_name);
void drop_table_destroy(DropTable *drop_table);

void create_index_init(
    CreateIndex *create_index, const char *index_name, const char *relation_name, size_t atr_num, const char attr_name[MAX_NUM][MAX_NUM],int is_unique);
void create_index_destroy(CreateIndex *create_index);

void drop_index_init(DropIndex *drop_index, const char *index_name);
void drop_index_destroy(DropIndex *drop_index);

void desc_table_init(DescTable *desc_table, const char *relation_name);
void desc_table_destroy(DescTable *desc_table);

void load_data_init(LoadData *load_data, const char *relation_name, const char *file_name);
void load_data_destroy(LoadData *load_data);

void show_index_init(ShowIndex *show_index, const char *relation_name);
void relation_attr_destroy(RelAttr *relation_attr);

void query_init(Query *query);
Query *query_create();  // create and init
void query_reset(Query *query);
void query_destroy(Query *query);  // reset and delete

#ifdef __cplusplus
}
#endif  // __cplusplus

#endif  // __OBSERVER_SQL_PARSER_PARSE_DEFS_H__
