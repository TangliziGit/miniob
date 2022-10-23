#include "sql/operator/multi_table_operator.h"
#include "storage/common/table.h"
#include "rc.h"

RC MultiTableOperator::open()
{
  RC rc = RC::SUCCESS;
  for (auto &child : children_) {
    rc = child->open();
    if(rc !=RC::SUCCESS){
      return rc;
    }
  }
  /* 打开剩下最后一个scanner不next */
  for (size_t i = 0; i < children_.size()-1;i++){
    rc = children_[i]->next();
    /* 如果有一个为空呢? */
    if(rc !=RC::SUCCESS){
      return rc;
    }
    tuple_.set_tuple(i, children_[i]->current_tuple());
  }
  return rc;
}

RC MultiTableOperator::next()
{
  size_t size = children_.size();
  RC rc = RC::SUCCESS;
  for (size_t i = size - 1; i >= 0; i--) {
    if ((rc = children_[i]->next()) != RC::SUCCESS) {
      if (rc!=RC::RECORD_EOF || i == 0) {
        return rc;
      }
      /* todo, check rc */
      children_[i]->close();
      children_[i]->open();
      children_[i]->next();
      tuple_.set_tuple(i, children_[i]->current_tuple());
    }else{
      tuple_.set_tuple(i, children_[i]->current_tuple());
      break;
    }
  }
  return rc;
}

RC MultiTableOperator::close()
{
  RC rc = RC::SUCCESS;
  for (auto &child : children_) {
    rc = child->close();
    if(rc !=RC::SUCCESS){
      return rc;
    }
  }
  return rc;
}

Tuple * MultiTableOperator::current_tuple()
{
  return &tuple_;
}
