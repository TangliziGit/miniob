
#pragma once

#include "sql/operator/operator.h"
#include "storage/common/table.h"
#include "rc.h"
#include "sql/stmt/filter_stmt.h"
#include "storage/common/field.h"

// TODO fixme
class JoinOperator : public PredicateOperator
{
public:
  JoinOperator(Table *table,Operator * oper,FilterStmt * filter_stmt,Tuple* tuple):PredicateOperator(filter_stmt),
  table_(table),right_oper_(oper),tuple_(tuple)
  {
    tuple_->append_table(table_->name());
  }

  virtual ~JoinOperator() = default;
  bool is_base_oper(){
    return children_.size() == 0;
  }
  RC open() override{
    filter_clean_ = false;
    RC rc = right_oper_->open();
    if(rc != RC::SUCCESS){
      return rc;
    }

    if (!is_base_oper()) {
      rc = RC::SUCCESS;
      if((rc= children_[0]->open())!=RC::SUCCESS){
        return rc;
      }
      if ((rc = children_[0]->next()) != RC::SUCCESS&&(rc != RC::SSSUCESS)) {
        return rc;
      }
      if(rc==RC::SSSUCESS){
        filter_clean_ = true;
      }
    }
    return RC::SUCCESS;
  }
  RC next() override{
    RC rc = RC::SUCCESS;
    while (true) {
      rc = right_oper_->next();
      reset();
      if (rc != RC::SUCCESS) {
        if (rc != RC::RECORD_EOF) {
          return rc;
        }
        if (!is_base_oper()){
          rc = right_oper_->close();
          if(rc!= RC::SUCCESS){
            return rc;
          }
          rc = right_oper_->open();
          if (rc != RC::SUCCESS) {
            return rc;
          }
          rc = right_oper_->next();
          if (rc != RC::SUCCESS) {
            /* 空表 */
            return rc;
          }
          rc = children_[0]->next();
          if (rc != RC::SUCCESS&&rc!=RC::SSSUCESS) {
            return rc;
          }
          filter_clean_ = rc == RC::SSSUCESS;
        } else {
          return rc;
        }
      }
      rc = tuple_->set_tuple(table_->name(), right_oper_->current_tuple()->copy());
      if(rc != RC::SUCCESS){
        return rc;
      }
      if (!filter_clean_) {
        /* 条件还不够,需要做filter */
        auto res = do_predicate(*tuple_);
        if (res.first == RC::SUCCESS && !res.second) {
          continue;
        }
        return res.first;
      }else{
        return RC::SSSUCESS;
      }
    }
    return rc;
  }
  RC close() override{
    RC rc = right_oper_->close();
    if(rc !=RC::SUCCESS){
      return rc;
    }
    rc = tuple_->close_table(table_->name());
    if(rc != RC::SUCCESS){
      return rc;
    }
    if(is_base_oper()){
    }else{
      return children_[0]->close();
    }
    return RC::SUCCESS;
  }
  virtual Tuple * current_tuple(){
    return tuple_;
  }
  OperType type() override{
    return OperType::JOIN;
  }
private:
  bool filter_clean_;
  Table *table_;
  Operator *right_oper_;
  Tuple *tuple_;
};
