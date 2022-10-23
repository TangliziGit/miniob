

#include "sql/operator/multi_table_predicate_operator.h"
#include "common/log/log.h"
#include "storage/record/record.h"
#include "sql/stmt/filter_stmt.h"
#include "storage/common/field.h"

RC MultiTablePredicateOperator::open()
{
  if (children_.size() != 1) {
    LOG_WARN("predicate operator must has one child");
    return RC::INTERNAL;
  }

  return children_[0]->open();
}

RC MultiTablePredicateOperator::next()
{
  RC rc = RC::SUCCESS;
  Operator *oper = children_[0];
  
  while (RC::SUCCESS == (rc = oper->next())) {
    const std::vector<Tuple *>&tuple = oper->current_tuples();

    if (do_predicate(tuple)) {
      return rc;
    }
  }
  return rc;
}

RC MultiTablePredicateOperator::close()
{
  children_[0]->close();
  return RC::SUCCESS;
}

const std::vector<Tuple *> &MultiTablePredicateOperator::current_tuples()
{
  return children_[0]->current_tuples();
}

bool MultiTablePredicateOperator::do_predicate(const std::vector<Tuple*> &tuple)
{
  if (filter_stmt_ == nullptr || filter_stmt_->filter_units().empty()) {
    return true;
  }

  for (const FilterUnit *filter_unit : filter_stmt_->filter_units()) {
    Expression *left_expr = filter_unit->left();
    Expression *right_expr = filter_unit->right();
    CompOp comp = filter_unit->comp();
    Tuple *left_tuple = tuple[0];
    Tuple *right_tuple = tuple[0];
    if (left_expr->type() == ExprType::FIELD) {
      int idx = name_map_[reinterpret_cast<FieldExpr *>(left_expr)->table_name()];
      left_tuple = tuple[idx];
    }
    if(right_expr->type() == ExprType::FIELD){
      int idx = name_map_[reinterpret_cast<FieldExpr *>(right_expr)->table_name()];
      right_tuple = tuple[idx];
    }
    TupleCell left_cell;
    TupleCell right_cell;
    left_expr->get_value(*left_tuple, left_cell);
    right_expr->get_value(*right_tuple, right_cell);
    if(comp == LIKE||comp == NOT_LIKE){
      bool is_like = left_cell.like(right_cell);
      if((comp == LIKE && !is_like)||(comp==NOT_LIKE&&is_like)){
        return false;
      }
      continue;
    }
    const int compare = left_cell.compare(right_cell);
    bool filter_result = false;
    switch (comp) {
    case EQUAL_TO: {
      filter_result = (0 == compare); 
    } break;
    case LESS_EQUAL: {
      filter_result = (compare <= 0); 
    } break;
    case NOT_EQUAL: {
      filter_result = (compare != 0);
    } break;
    case LESS_THAN: {
      filter_result = (compare < 0);
    } break;
    case GREAT_EQUAL: {
      filter_result = (compare >= 0);
    } break;
    case GREAT_THAN: {
      filter_result = (compare > 0);
    } break;
    default: {
      LOG_WARN("invalid compare type: %d", comp);
    } break;
    }
    if (!filter_result) {
      return false;
    }
  }
  return true;
}

