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
// Created by Meiyi & Longda on 2021/4/13.
//

#include <string>
#include <sstream>

#include "execute_stage.h"

#include "common/io/io.h"
#include "common/log/log.h"
#include "common/lang/defer.h"
#include "common/seda/timer_stage.h"
#include "common/lang/string.h"
#include "session/session.h"
#include "event/storage_event.h"
#include "event/sql_event.h"
#include "event/session_event.h"
#include "sql/expr/tuple.h"
#include "sql/operator/table_scan_operator.h"
#include "sql/operator/index_scan_operator.h"
#include "sql/operator/predicate_operator.h"
#include "sql/operator/delete_operator.h"
#include "sql/operator/update_operator.h"
#include "sql/operator/project_operator.h"
#include "sql/operator/order_by_operator.h"
#include "sql/operator/join_operator.h"
#include "sql/operator/aggregation_operator.h"
#include "sql/operator/expression_operator.h"
#include "sql/stmt/stmt.h"
#include "sql/stmt/select_stmt.h"
#include "sql/stmt/update_stmt.h"
#include "sql/stmt/delete_stmt.h"
#include "sql/stmt/insert_stmt.h"
#include "sql/stmt/filter_stmt.h"
#include "storage/common/table.h"
#include "storage/common/field.h"
#include "storage/index/index.h"
#include "storage/default/default_handler.h"
#include "storage/common/condition_filter.h"
#include "storage/trx/trx.h"
#include "storage/clog/clog.h"

using namespace common;

//RC create_selection_executor(
//   Trx *trx, const Selects &selects, const char *db, const char *table_name, SelectExeNode &select_node);

//! Constructor
ExecuteStage::ExecuteStage(const char *tag) : Stage(tag)
{}

//! Destructor
ExecuteStage::~ExecuteStage()
{}

//! Parse properties, instantiate a stage object
Stage *ExecuteStage::make_stage(const std::string &tag)
{
  ExecuteStage *stage = new (std::nothrow) ExecuteStage(tag.c_str());
  if (stage == nullptr) {
    LOG_ERROR("new ExecuteStage failed");
    return nullptr;
  }
  stage->set_properties();
  return stage;
}

//! Set properties for this object set in stage specific properties
bool ExecuteStage::set_properties()
{
  //  std::string stageNameStr(stageName);
  //  std::map<std::string, std::string> section = theGlobalProperties()->get(
  //    stageNameStr);
  //
  //  std::map<std::string, std::string>::iterator it;
  //
  //  std::string key;

  return true;
}

//! Initialize stage params and validate outputs
bool ExecuteStage::initialize()
{
  LOG_TRACE("Enter");

  std::list<Stage *>::iterator stgp = next_stage_list_.begin();
  default_storage_stage_ = *(stgp++);
  mem_storage_stage_ = *(stgp++);

  LOG_TRACE("Exit");
  return true;
}

//! Cleanup after disconnection
void ExecuteStage::cleanup()
{
  LOG_TRACE("Enter");

  LOG_TRACE("Exit");
}

void ExecuteStage::handle_event(StageEvent *event)
{
  LOG_TRACE("Enter\n");

  handle_request(event);

  LOG_TRACE("Exit\n");
  return;
}

void ExecuteStage::callback_event(StageEvent *event, CallbackContext *context)
{
  LOG_TRACE("Enter\n");

  // here finish read all data from disk or network, but do nothing here.

  LOG_TRACE("Exit\n");
  return;
}

void ExecuteStage::handle_request(common::StageEvent *event)
{
  SQLStageEvent *sql_event = static_cast<SQLStageEvent *>(event);
  SessionEvent *session_event = sql_event->session_event();
  Stmt *stmt = sql_event->stmt();
  Session *session = session_event->session();
  Query *sql = sql_event->query();

  if (stmt != nullptr) {
    switch (stmt->type()) {
    case StmtType::SELECT: {
      do_select(sql_event);
    } break;
    case StmtType::INSERT: {
      do_insert(sql_event);
    } break;
    case StmtType::UPDATE: {
      do_update(sql_event);
    } break;
    case StmtType::DELETE: {
      do_delete(sql_event);
    } break;
    default: {
      LOG_WARN("should not happen. please implenment");
    } break;
    }
  } else {
    switch (sql->flag) {
    case SCF_HELP: {
      do_help(sql_event);
    } break;
    case SCF_CREATE_TABLE: {
      do_create_table(sql_event);
    } break;
    case SCF_CREATE_INDEX: {
      do_create_index(sql_event);
    } break;
    case SCF_DROP_TABLE:{
      do_remove_table(sql_event);
    } break;
    case SCF_SHOW_TABLES: {
      do_show_tables(sql_event);
    } break;
    case SCF_DESC_TABLE: {
      do_desc_table(sql_event);
    } break;
    case SCF_SHOW_INDEX: {
      do_show_index(sql_event);
    } break;

    case SCF_DROP_INDEX:
    case SCF_LOAD_DATA: {
      default_storage_stage_->handle_event(event);
    } break;
    case SCF_SYNC: {
      /*
      RC rc = DefaultHandler::get_default().sync();
      session_event->set_response(strrc(rc));
      */
    } break;
    case SCF_BEGIN: {
      do_begin(sql_event);
    } break;
    case SCF_COMMIT: {
      do_commit(sql_event);
    } break;
    case SCF_CLOG_SYNC: {
      do_clog_sync(sql_event);
    }
    case SCF_ROLLBACK: {
      Trx *trx = session_event->get_client()->session->current_trx();
      RC rc = trx->rollback();
      session->set_trx_multi_operation_mode(false);
      session_event->set_response(strrc(rc));
    } break;
    case SCF_EXIT: {
      // do nothing
      const char *response = "Unsupported\n";
      session_event->set_response(response);
    } break;
    default: {
      LOG_ERROR("Unsupported command=%d\n", sql->flag);
    }
    }
  }
}

void end_trx_if_need(Session *session, Trx *trx, bool all_right)
{
  if (!session->is_trx_multi_operation_mode()) {
    if (all_right) {
      trx->commit();
    } else {
      trx->rollback();
    }
  }
}

void print_tuple_header(std::ostream &os, const std::vector<AbstractField *> &fields,bool is_multi_table)
{
  const int cell_num = fields.size();
  for (int i = 0; i < cell_num; i++) {
    if (i != 0) {
      os << " | ";
    }

    if(is_multi_table && fields[i]->type() == FieldType::FIELD){
      /* ???????????????????????????????????????????????????????????????????????????????????? */
      auto field = dynamic_cast<Field *>(fields[i]);
      if (!field->has_alias()) {
        os << field->table_alias() << ".";
      }
    }
    os << fields[i]->alias();
  }

  if (cell_num > 0) {
    os << '\n';
  }
}

void tuple_to_string(std::ostream &os, const Tuple &tuple)
{
  TupleCell cell;
  RC rc = RC::SUCCESS;
  bool first_field = true;
  for (int i = 0; i < tuple.cell_num(); i++) {
    rc = tuple.cell_at(i, cell);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to fetch field of cell. index=%d, rc=%s", i, strrc(rc));
      break;
    }

    if (!first_field) {
      os << " | ";
    } else {
      first_field = false;
    }
    cell.to_string(os);
  }
}

IndexScanOperator *try_to_create_index_scan_operator(FilterStmt *filter_stmt)
{
  const std::vector<FilterUnit *> &filter_units = filter_stmt->filter_units();
  if (filter_units.empty()||filter_stmt->has_or()) {
    return nullptr;
  }
  // ????????????????????????????????????????????????????????????????????????????????????????????????????????????
  // ?????????????????????????????????????????????????????????
  // ???????????????????????????????????????????????????????????????????????????????????????
  // ?????????????????????????????????????????????????????????????????????????????????. (???????????????????)
  const FilterUnit *better_filter = nullptr;
  for (const FilterUnit * filter_unit : filter_units) {
    if (filter_unit->comp() == NOT_EQUAL||filter_unit->comp()==LIKE||filter_unit->comp()==NOT_LIKE||filter_unit->comp()==IS||filter_unit->comp()==IS_NOT
    || filter_unit->comp() == IN||filter_unit->comp() == NOT_IN||filter_unit->comp()==EXISTS||filter_unit->comp()==NOT_EXISTS) {
      continue;
    }

    Expression *left = filter_unit->left();
    Expression *right = filter_unit->right();
    if (left->type() == ExprType::FIELD && right->type() == ExprType::VALUE) {
    } else if (left->type() == ExprType::VALUE && right->type() == ExprType::FIELD) {
      std::swap(left, right);
    }else{
      /* ??????????????????????????? */
      continue;
    }
    ValueExpr &right_value_expr = *(ValueExpr *)right;
    if(right_value_expr.value_type() == NULLS){
      /* nulls ??????????????? */
      continue;
    }
    FieldExpr &left_field_expr = *(FieldExpr *)left;
    const Field &field = left_field_expr.field();
    const Table *table = field.table();
    Index *index = table->find_index_by_field(field.field_name());
    if (index != nullptr) {
      if (better_filter == nullptr) {
        better_filter = filter_unit;
      } else if (filter_unit->comp() == EQUAL_TO) {
        better_filter = filter_unit;
    	break;
      }
    }
  }

  if (better_filter == nullptr) {
    return nullptr;
  }

  Expression *left = better_filter->left();
  Expression *right = better_filter->right();
  CompOp comp = better_filter->comp();
  if (left->type() == ExprType::VALUE && right->type() == ExprType::FIELD) {
    std::swap(left, right);
    switch (comp) {
    case EQUAL_TO:    { comp = EQUAL_TO; }    break;
    case LESS_EQUAL:  { comp = GREAT_THAN; }  break;
    case NOT_EQUAL:   { comp = NOT_EQUAL; }   break;
    case LESS_THAN:   { comp = GREAT_EQUAL; } break;
    case GREAT_EQUAL: { comp = LESS_THAN; }   break;
    case GREAT_THAN:  { comp = LESS_EQUAL; }  break;
    default: {
    	LOG_WARN("should not happen");
    }
    }
  }


  FieldExpr &left_field_expr = *(FieldExpr *)left;
  const Field &field = left_field_expr.field();
  const Table *table = field.table();
  Index *index = table->find_index_by_field(field.field_name());
  assert(index != nullptr);

  ValueExpr &right_value_expr = *(ValueExpr *)right;
  TupleCell value;
  right_value_expr.get_tuple_cell(value);

  const TupleCell *left_cell = nullptr;
  const TupleCell *right_cell = nullptr;
  bool left_inclusive = false;
  bool right_inclusive = false;

  switch (comp) {
  case EQUAL_TO: {
    left_cell = &value;
    right_cell = &value;
    left_inclusive = true;
    right_inclusive = true;
  } break;

  case LESS_EQUAL: {
    left_cell = nullptr;
    left_inclusive = false;
    right_cell = &value;
    right_inclusive = true;
  } break;

  case LESS_THAN: {
    left_cell = nullptr;
    left_inclusive = false;
    right_cell = &value;
    right_inclusive = false;
  } break;

  case GREAT_EQUAL: {
    left_cell = &value;
    left_inclusive = true;
    right_cell = nullptr;
    right_inclusive = false;
  } break;

  case GREAT_THAN: {
    left_cell = &value;
    left_inclusive = false;
    right_cell = nullptr;
    right_inclusive = false;
  } break;

  default: {
    LOG_WARN("should not happen. comp=%d", comp);
  } break;
  }

  IndexScanOperator *oper = new IndexScanOperator(table, index,
       left_cell, left_inclusive, right_cell, right_inclusive);

  LOG_INFO("use index for scan: %s in table %s", index->index_meta().name(), table->name());
  return oper;
}

static void find_filter(std::vector<FilterUnit *> &filter_units,const std::map<std::string,int>&name_idx,FilterStmt* out_filter_stmt){
  if (filter_units.empty() ) {
    return;
  }
  std::vector<FilterUnit *> remove_unit;
  for (auto filter_unit : filter_units) {
    Expression *left = filter_unit->left();
    Expression *right = filter_unit->right();
    FieldExpr *left_field = nullptr;
    FieldExpr *right_field = nullptr;
    if(left->type()==ExprType::MATH||right->type()==ExprType::MATH){
      continue;
    }
    if(left->type()==ExprType::FUNCTION||right->type()==ExprType::FUNCTION){
      continue;
    }
    if (left->type() == ExprType::FIELD) {
      left_field = reinterpret_cast<FieldExpr *>(left);
    }
    if(right->type() == ExprType::FIELD){
      right_field = reinterpret_cast<FieldExpr *>(right);
    }
    if((left_field==nullptr||name_idx.count(left_field->table_name()))&&(right_field==nullptr || name_idx.count(right_field->table_name()))){
      out_filter_stmt->add_filter(filter_unit);
      remove_unit.push_back(filter_unit);
    }
  }
  for(auto filter_unit:remove_unit){
    for (size_t i = 0; i < filter_units.size(); i++) {
      if(filter_units[i]==filter_unit){
        filter_units.erase(filter_units.begin() + i);
        break;
      }
    }
  }
}

std::pair<std::vector<Tuple *>, RC> execute_select(Stmt *stmt);
RC init_subselect_if_have(FilterStmt *filter_stmt)
{
  RC rc = RC::SUCCESS;
  for (auto filter_unit : filter_stmt->filter_units()) {
    Expression *left = filter_unit->left();
    if(left->type() == ExprType::SUB_SELECT &&((rc = left->init(execute_select))!= RC::SUCCESS)){
      return rc;
    }
    Expression *right = filter_unit->right();
    if(right->type() == ExprType::SUB_SELECT &&((rc = right->init(execute_select))!= RC::SUCCESS)){
      return rc;
    }
  }
  return rc;
}

static CompositeTuple base_tuple;

std::pair<std::vector<Tuple*>, RC> execute_select(Stmt *stmt){
  SelectStmt *select_stmt = (SelectStmt *)(stmt);
  /* ?????????????????????do_select????????????,?????????lazy?????? */
  RC rc = RC::SUCCESS;
  std::vector<Tuple*> tuples;
  rc = init_subselect_if_have(select_stmt->filter_stmt());
  if(rc != RC::SUCCESS){
    return {tuples, rc};
  }

  auto tables = select_stmt->tables();
  std::map<std::string, int> name_idx;
  auto filter_units = select_stmt->filter_stmt()->filter_copy();
  std::vector<JoinOperator *> join_opers;
  for (size_t i = 0; i < tables.size(); i++) {
    Table *table = tables[i];
    name_idx[tables[i]->name()] = i;
    FilterStmt *cur_filter = new FilterStmt();
    find_filter(filter_units, name_idx, cur_filter);
    Operator *oper = try_to_create_index_scan_operator(cur_filter);
    if(oper == nullptr){
      oper = new TableScanOperator(table);
    }
    join_opers.push_back(new JoinOperator(table, oper, cur_filter,&base_tuple));
    if (i != 0) {
      join_opers[i]->add_child(join_opers[i - 1]);
    }
  }

  Operator *temp_oper = join_opers.back();
  PredicateOperator *pred_oper = new PredicateOperator(new FilterStmt(filter_units));
  pred_oper->add_child(temp_oper);

  Operator *oper = nullptr;
  if (select_stmt->has_aggregation()) {
    // TODO(chunxu): add group by and having fields
    oper = new AggregationOperator(
        select_stmt->query_fields(),
        select_stmt->aggregation_fields(),
        select_stmt->hidden_aggregation_fields(),
        select_stmt->group_by_fields(),
        select_stmt->having_filter_stmt()
    );
  } else {
    auto project_oper = new ProjectOperator();
    for (const auto *field : select_stmt->query_fields()) {
      project_oper->add_projection(field);
    }
    oper = project_oper;
  }
  oper->add_child(pred_oper);

  rc = oper->open();
  if (rc != RC::SUCCESS && rc!=RC::RECORD_EOF) {
    return {tuples, rc};
  }

  while (rc != RC::RECORD_EOF&&((rc = oper->next()) == RC::SUCCESS|| rc == RC::SSSUCESS)) {
    // get current record
    // write to response
    Tuple * tuple = oper->current_tuple();
    if (nullptr == tuple) {
      rc = RC::INTERNAL;
      LOG_WARN("failed to get current record. rc=%s", strrc(rc));
      break;
    }

    tuples.push_back(tuple->copy());
  }

  if (rc != RC::RECORD_EOF) {
    tuples.clear();
    oper->close();
  } else {
    rc = oper->close();
    if(rc != RC::SUCCESS){
      tuples.clear();
    }
  }
  return {tuples,rc};
};

RC ExecuteStage::do_select(SQLStageEvent *sql_event)
{
  DEFER([&]() { base_tuple.destroy(); });
  SelectStmt *select_stmt = (SelectStmt *)(sql_event->stmt());
  SessionEvent *session_event = sql_event->session_event();
  
  /* ?????????????????????do_select????????????,?????????lazy?????? */
  RC rc = RC::SUCCESS;
  rc = init_subselect_if_have(select_stmt->filter_stmt());
  if (rc != RC::SUCCESS) {
    session_event->set_response("FAILURE\n");
    return rc;
  }
  auto tables = select_stmt->tables();
  std::map<std::string, int> name_idx;
  auto filter_units = select_stmt->filter_stmt()->filter_copy();
  std::vector<JoinOperator *> join_opers;
  for (size_t i = 0; i < tables.size(); i++) {
    Table *table = tables[i];
    if (table == nullptr && i == 0) continue;
    name_idx[tables[i]->name()] = i;
    FilterStmt *cur_filter = new FilterStmt();
    find_filter(filter_units, name_idx, cur_filter);
    Operator *oper=try_to_create_index_scan_operator(cur_filter);
    if(oper == nullptr){
      oper = new TableScanOperator(table);
    }
    join_opers.push_back(new JoinOperator(table, oper, cur_filter,&base_tuple));
    if (i != 0) {
      join_opers[i]->add_child(join_opers[i - 1]);
    }
  }

  PredicateOperator *pred_oper = new PredicateOperator(new FilterStmt(filter_units));
  Operator *temp_oper = nullptr;
  if (!tables.empty()) {
    temp_oper = join_opers.back();
    if (select_stmt->order_flag().size()!=0) {
      OrderByOperator *order_oper = new OrderByOperator(select_stmt->order_field(), select_stmt->order_flag());
      order_oper->add_child(temp_oper);
      temp_oper = order_oper;
    }
    pred_oper->add_child(temp_oper);
  } else {
    auto project_oper = new ProjectOperator(true);
    for (const auto *field : select_stmt->query_fields()) {
      rc = project_oper->add_projection(field);
      if (rc != SUCCESS) {
        session_event->set_response("FAILURE\n");
        return rc;
      }
    }
    pred_oper->add_child(project_oper);
  }

  if (select_stmt->has_aggregation()) {
    temp_oper = new AggregationOperator(
        select_stmt->query_fields(),
        select_stmt->aggregation_fields(),
        select_stmt->hidden_aggregation_fields(),
        select_stmt->group_by_fields(),
        select_stmt->having_filter_stmt()
    );
  } else {
    auto project_oper = new ProjectOperator();
    for (const auto *field : select_stmt->query_fields()) {
      rc = project_oper->add_projection(field);
      if (rc != SUCCESS) {
        session_event->set_response("FAILURE\n");
        return rc;
      }
    }
    temp_oper = project_oper;
  }
  temp_oper->add_child(pred_oper);

  Operator *oper = temp_oper;
  auto query_fields = select_stmt->query_fields();
  if (select_stmt->has_expression()) {
    query_fields = select_stmt->expr_query_fields();
    ExprOperator *expr_oper = new ExprOperator(select_stmt->exprs(), select_stmt->expr_query_fields());
    expr_oper->add_child(temp_oper);
    oper = expr_oper;
  }

  rc = oper->open();
  if (rc != RC::SUCCESS && rc!=RC::RECORD_EOF) {
    LOG_WARN("failed to open operator");
    session_event->set_response("FAILURE\n");
    return rc;
  }

  std::stringstream ss;
  print_tuple_header(ss, query_fields, tables.size() > 1);
  while (rc != RC::RECORD_EOF&&((rc = oper->next()) == RC::SUCCESS|| rc ==RC::SSSUCESS)) {
    // get current record
    // write to response
    Tuple * tuple = oper->current_tuple();
    if (nullptr == tuple) {
      rc = RC::INTERNAL;
      LOG_WARN("failed to get current record. rc=%s", strrc(rc));
      break;
    }

    tuple_to_string(ss, *tuple);
    ss << std::endl;
  }

  if (rc != RC::RECORD_EOF) {
    LOG_WARN("something wrong while iterate operator. rc=%s", strrc(rc));
    oper->close();
    session_event->set_response("FAILURE\n");
  } else {
    rc = oper->close();
    session_event->set_response(ss.str());
  }
  return rc;
}

RC ExecuteStage::do_help(SQLStageEvent *sql_event)
{
  SessionEvent *session_event = sql_event->session_event();
  const char *response = "show tables;\n"
                         "desc `table name`;\n"
                         "create table `table name` (`column name` `column type`, ...);\n"
                         "create index `index name` on `table` (`column`);\n"
                         "insert into `table` values(`value1`,`value2`);\n"
                         "update `table` set column=value [where `column`=`value`];\n"
                         "delete from `table` [where `column`=`value`];\n"
                         "select [ * | `columns` ] from `table`;\n";
  session_event->set_response(response);
  return RC::SUCCESS;
}

RC ExecuteStage::do_create_table(SQLStageEvent *sql_event)
{
  const CreateTable &create_table = sql_event->query()->sstr.create_table;
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();
  RC rc = db->create_table(create_table.relation_name,
			create_table.attribute_count, create_table.attributes);
  if (rc == RC::SUCCESS) {
    session_event->set_response("SUCCESS\n");
  } else {
    session_event->set_response("FAILURE\n");
  }
  return rc;
}

RC ExecuteStage::do_remove_table(SQLStageEvent *sql_event)
{
  const DropTable &drop_table = sql_event->query()->sstr.drop_table;
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();
  RC rc = db->remove_table(drop_table.relation_name);
  if (rc == RC::SUCCESS) {
    session_event->set_response("SUCCESS\n");
  } else {
    session_event->set_response("FAILURE\n");
  }
  return rc;
}

RC ExecuteStage::do_create_index(SQLStageEvent *sql_event)
{
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();
  CreateIndex &create_index = sql_event->query()->sstr.create_index;
  Table *table = db->find_table(create_index.relation_name);
  if (nullptr == table) {
    session_event->set_response("FAILURE\n");
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  RC rc = table->create_index(nullptr,
      create_index.index_name,
      create_index.attribute_count,
      create_index.attribute_name,
      create_index.is_unique);
  sql_event->session_event()->set_response(rc == RC::SUCCESS ? "SUCCESS\n" : "FAILURE\n");
  return rc;
}

RC ExecuteStage::do_show_tables(SQLStageEvent *sql_event)
{
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();
  std::vector<std::string> all_tables;
  db->all_tables(all_tables);
  if (all_tables.empty()) {
    session_event->set_response("No table\n");
  } else {
    std::stringstream ss;
    for (const auto &table : all_tables) {
      ss << table << std::endl;
    }
    session_event->set_response(ss.str().c_str());
  }
  return RC::SUCCESS;
}

RC ExecuteStage::do_show_index(SQLStageEvent *sql_event)
{
  SessionEvent *session_event = sql_event->session_event();
  Table *tb = session_event->session()->get_current_db()->find_table(sql_event->query()->sstr.show_index.relation_name);
  if (tb == nullptr) {
    session_event->set_response("FAILURE\n");
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }
  const TableMeta tb_meta = tb->table_meta();
  std::stringstream ss;
  ss << "Table | Non_unique | Key_name | Seq_in_index | Column_name" << std::endl;
  for (int i = 0; i < tb_meta.index_num(); i++) {
    const IndexMeta *index_meta = tb_meta.index(i);
    for (int j = 0; j < index_meta->filed_length(); j++) {
      ss << tb->name() << " | ";
      ss << (index_meta->is_unique() ? 0 : 1) << " | ";
      ss << index_meta->name() << " | ";
      ss << (j + 1) << " | ";
      ss << index_meta->field(j) << "\n";
    }
  }
  session_event->set_response(ss.str().c_str());
  return RC::SUCCESS;
}

RC ExecuteStage::do_desc_table(SQLStageEvent *sql_event)
{
  Query *query = sql_event->query();
  Db *db = sql_event->session_event()->session()->get_current_db();
  const char *table_name = query->sstr.desc_table.relation_name;
  Table *table = db->find_table(table_name);
  std::stringstream ss;
  if (table != nullptr) {
    table->table_meta().desc(ss);
  } else {
    ss << "No such table: " << table_name << std::endl;
  }
  sql_event->session_event()->set_response(ss.str().c_str());
  return RC::SUCCESS;
}

RC ExecuteStage::do_insert(SQLStageEvent *sql_event)
{
  Stmt *stmt = sql_event->stmt();
  SessionEvent *session_event = sql_event->session_event();
  Session *session = session_event->session();
  Db *db = session->get_current_db();
  Trx *trx = session->current_trx();
  CLogManager *clog_manager = db->get_clog_manager();

  if (stmt == nullptr) {
    LOG_WARN("cannot find statement");
    return RC::GENERIC_ERROR;
  }

  InsertStmt *insert_stmt = (InsertStmt *)stmt;
  Table *table = insert_stmt->table();
  int n = insert_stmt->insert_num();
  RC rc = RC::SUCCESS;
  for (int i = 0; i < n; i++) {
    rc = table->insert_record(trx, insert_stmt->value_amount(i), insert_stmt->values(i));
    if (rc != RC::SUCCESS) {
      if(trx!=nullptr){
        /* ????????????????????? */
        trx->rollback();
      }
      session_event->set_response("FAILURE\n");
      return rc;
    }
  }
  /* ???????????????,???????????????????????????,?????????????????? */
  if (!session->is_trx_multi_operation_mode()) {
    CLogRecord *clog_record = nullptr;
    rc = clog_manager->clog_gen_record(CLogType::REDO_MTR_COMMIT, trx->get_current_id(), clog_record);
    if (rc != RC::SUCCESS || clog_record == nullptr) {
      session_event->set_response("FAILURE\n");
      return rc;
    }

    rc = clog_manager->clog_append_record(clog_record);
    if (rc != RC::SUCCESS) {
      session_event->set_response("FAILURE\n");
      return rc;
    }

    trx->next_current_id();
  }
  session_event->set_response("SUCCESS\n");
  return rc;
}

RC ExecuteStage::do_update(SQLStageEvent *sql_event)
{
  DEFER([&]() { base_tuple.destroy(); });
  Stmt *stmt = sql_event->stmt();
  SessionEvent *session_event = sql_event->session_event();
  Session *session = session_event->session();
  Db *db = session->get_current_db();
  Trx *trx = session->current_trx();
  CLogManager *clog_manager = db->get_clog_manager();

  if (stmt == nullptr) {
    LOG_WARN("cannot find statement");
    session_event->set_response("FAILURE\n");
    return RC::GENERIC_ERROR;
  }

  UpdateStmt *update_stmt = (UpdateStmt *)stmt;

  RC rc = RC::SUCCESS;
  std::vector<Tuple*> tuples;
  rc = init_subselect_if_have(update_stmt->filter());
  if(rc != RC::SUCCESS){
    session_event->set_response("FAILURE\n");
    return rc;
  }
  std::vector<Value> &values = update_stmt->value();
  for (size_t i = 0; i < values.size(); i++) {
    if (values[i].is_query) {
      Query *query = (Query *)values[i].data;
      Stmt *select_stmt = nullptr;
      if ((rc = SelectStmt::create_stmt(db, *query, select_stmt)) != RC::SUCCESS) {
        session_event->set_response("FAILURE\n");
        return rc;
      }
      size_t query_num = ((SelectStmt *)select_stmt)->query_fields().size();
      if (query_num > 1) {
        session_event->set_response("FAILURE\n");
        return RC::SCHEMA_FIELD_TYPE_MISMATCH;
      }
      SubSelectExpr *right = new SubSelectExpr(select_stmt);
      right->init(execute_select);
      TupleCell cell;
      RowTuple tmp;
      if ((rc = right->get_value(tmp, cell)) != RC::SUCCESS) {
        session_event->set_response("FAILURE\n");
        return rc;
      }
      Value new_value;
      new_value.data = cell.data();
      new_value.type = cell.attr_type();
      new_value.is_query = 0;
      Table *table = update_stmt->table();
      const char *field_name = update_stmt->attribute_name().at(i);
      const FieldMeta *field_meta = table->table_meta().field(field_name);
      if (field_meta->type() != new_value.type && new_value.type != NULLS) {
        if ((rc = cast_to(&new_value, field_meta->type())) != RC::SUCCESS) {
          session_event->set_response("FAILURE\n");
          return rc;
        }
      }
      values[i] = new_value;
    }
  }
  TableScanOperator scan_oper(update_stmt->table());
  PredicateOperator pred_oper(update_stmt->filter());
  pred_oper.add_child(&scan_oper);
  UpdateOperator update_oper{update_stmt, trx};
  update_oper.add_child(&pred_oper);

  rc = update_oper.open();
  if (rc != RC::SUCCESS) {
    if(trx!=nullptr){
      trx->rollback();
    }
    session_event->set_response("FAILURE\n");
  } else {
    session_event->set_response("SUCCESS\n");
    if (!session->is_trx_multi_operation_mode()) {
      CLogRecord *clog_record = nullptr;
      rc = clog_manager->clog_gen_record(CLogType::REDO_MTR_COMMIT, trx->get_current_id(), clog_record);
      if (rc != RC::SUCCESS || clog_record == nullptr) {
        session_event->set_response("FAILURE\n");
        return rc;
      }

      rc = clog_manager->clog_append_record(clog_record);
      if (rc != RC::SUCCESS) {
        session_event->set_response("FAILURE\n");
        return rc;
      }

      trx->next_current_id();
      session_event->set_response("SUCCESS\n");
    }
  }
  return rc;
}

RC ExecuteStage::do_delete(SQLStageEvent *sql_event)
{
  Stmt *stmt = sql_event->stmt();
  SessionEvent *session_event = sql_event->session_event();
  Session *session = session_event->session();
  Db *db = session->get_current_db();
  Trx *trx = session->current_trx();
  CLogManager *clog_manager = db->get_clog_manager();

  if (stmt == nullptr) {
    LOG_WARN("cannot find statement");
    return RC::GENERIC_ERROR;
  }

  DeleteStmt *delete_stmt = (DeleteStmt *)stmt;
  
  RC rc = RC::SUCCESS;
  std::vector<Tuple*> tuples;
  rc = init_subselect_if_have(delete_stmt->filter_stmt());
  if(rc != RC::SUCCESS){
      session_event->set_response("FAILURE\n");
      return rc;
  }

  TableScanOperator scan_oper(delete_stmt->table());
  PredicateOperator pred_oper(delete_stmt->filter_stmt());
  pred_oper.add_child(&scan_oper);
  DeleteOperator delete_oper(delete_stmt, trx);
  delete_oper.add_child(&pred_oper);

  rc = delete_oper.open();
  if (rc != RC::SUCCESS) {
    session_event->set_response("FAILURE\n");
  } else {
    session_event->set_response("SUCCESS\n");
    if (!session->is_trx_multi_operation_mode()) {
      CLogRecord *clog_record = nullptr;
      rc = clog_manager->clog_gen_record(CLogType::REDO_MTR_COMMIT, trx->get_current_id(), clog_record);
      if (rc != RC::SUCCESS || clog_record == nullptr) {
        session_event->set_response("FAILURE\n");
        return rc;
      }

      rc = clog_manager->clog_append_record(clog_record);
      if (rc != RC::SUCCESS) {
        session_event->set_response("FAILURE\n");
        return rc;
      } 

      trx->next_current_id();
      session_event->set_response("SUCCESS\n");
    }
  }
  return rc;
}

RC ExecuteStage::do_begin(SQLStageEvent *sql_event)
{
  RC rc = RC::SUCCESS;
  SessionEvent *session_event = sql_event->session_event();
  Session *session = session_event->session();
  Db *db = session->get_current_db();
  Trx *trx = session->current_trx();
  CLogManager *clog_manager = db->get_clog_manager();

  session->set_trx_multi_operation_mode(true);

  CLogRecord *clog_record = nullptr;
  rc = clog_manager->clog_gen_record(CLogType::REDO_MTR_BEGIN, trx->get_current_id(), clog_record);
  if (rc != RC::SUCCESS || clog_record == nullptr) {
    session_event->set_response("FAILURE\n");
    return rc;
  }

  rc = clog_manager->clog_append_record(clog_record);
  if (rc != RC::SUCCESS) {
    session_event->set_response("FAILURE\n");
  } else {
    session_event->set_response("SUCCESS\n");
  }

  return rc;
}

RC ExecuteStage::do_commit(SQLStageEvent *sql_event)
{
  RC rc = RC::SUCCESS;
  SessionEvent *session_event = sql_event->session_event();
  Session *session = session_event->session();
  Db *db = session->get_current_db();
  Trx *trx = session->current_trx();
  CLogManager *clog_manager = db->get_clog_manager();

  session->set_trx_multi_operation_mode(false);

  CLogRecord *clog_record = nullptr;
  rc = clog_manager->clog_gen_record(CLogType::REDO_MTR_COMMIT, trx->get_current_id(), clog_record);
  if (rc != RC::SUCCESS || clog_record == nullptr) {
    session_event->set_response("FAILURE\n");
    return rc;
  }

  rc = clog_manager->clog_append_record(clog_record);
  if (rc != RC::SUCCESS) {
    session_event->set_response("FAILURE\n");
  } else {
    session_event->set_response("SUCCESS\n");
  }

  trx->next_current_id();

  return rc;
}

RC ExecuteStage::do_clog_sync(SQLStageEvent *sql_event)
{
  RC rc = RC::SUCCESS;
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();
  CLogManager *clog_manager = db->get_clog_manager();

  rc = clog_manager->clog_sync();
  if (rc != RC::SUCCESS) {
    session_event->set_response("FAILURE\n");
  } else {
    session_event->set_response("SUCCESS\n");
  }

  return rc;
}
