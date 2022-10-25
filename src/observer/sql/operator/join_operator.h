
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
  JoinOperator(Table *table,Operator * oper,FilterStmt * filter_stmt):PredicateOperator(filter_stmt),
  table_(table),right_oper_(oper)
  {}

  virtual ~JoinOperator() = default;
  void init(std::map<std::string,int>name_idx){
    if(is_base_oper()){
      tuple_ = new CompositeTuple();
      tuple_->init(name_idx);
    }
  }
  bool is_base_oper(){
    return children_.size() == 0;
  }
  RC open() override{
    right_oper_->open();

    if (!is_base_oper()) {
      children_[0]->open();
      RC rc = RC::SUCCESS;
      if ((rc = children_[0]->next()) != RC::SUCCESS) {
        return rc;
      }
      tuple_ = children_[0]->current_tuple();
    }
    return RC::SUCCESS;
  }
  RC next() override{
    RC rc = RC::SUCCESS;
    while (1) {
      rc = right_oper_->next();
      if (rc != RC::SUCCESS) {
        if (rc != RC::RECORD_EOF) {
          return rc;
        }
        if (!is_base_oper()){
          rc = children_[0]->next();
          if (rc != RC::SUCCESS) {
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
        }else{
          return rc;
        }
      }
      tuple_->set_tuple(table_->name(), right_oper_->current_tuple());
      if(do_predicate(*tuple_)){
        return rc;
      }
    }
  }
  RC close() override{
    right_oper_->close();
    if(is_base_oper()){
      delete tuple_;
    }else{
      children_[0]->close();
    }
    delete right_oper_;
    return RC::SUCCESS;
  }
  virtual Tuple * current_tuple(){
    return tuple_;
  }
  OperType type() override{
    return OperType::JOIN;
  }
private:
  Table *table_;
  Operator *right_oper_;
  Tuple *tuple_;
};
