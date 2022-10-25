#pragma once

#include <utility>
#include <vector>
#include <queue>
#include "rc.h"
#include "sql/function/register.h"
#include "sql/operator/operator.h"

struct ORDER_DESC
{
    bool operator () (std::pair<std::vector<TupleCell*>, Tuple*> &a, std::pair<std::vector<TupleCell*>, Tuple*> &b)
    {
      for (int i = 0; i < a.first.size(); i++) {
        if (a.first[i]->is_null()) {
          return true;
        }
        if (a.first[i]->compare(*b.first[i]) == 0) {
          continue;
        }
        return a.first[i]->compare(*b.first[i]) < 0;
      }
      return false;
    }
};
struct ORDER_ASC
{
    bool operator () (std::pair<std::vector<TupleCell*>, Tuple*> &a, std::pair<std::vector<TupleCell*>, Tuple*> &b)
    {
        for (int i = 0; i < a.first.size(); i++) {
        if (a.first[i]->is_null()) {
          return true;
        }
        if (a.first[i]->compare(*b.first[i]) == 0) {
          continue;
        }
        return a.first[i]->compare(*b.first[i]) > 0;
      }
      return false;
    }
};
class OrderByOperator : public Operator
{
public:
  OrderByOperator(std::vector<Field*> fields, OrderFlag flag) : fields_(fields), flag_(flag) {
    
  }
  virtual RC open() {
    Operator *child = children_[0];
    RC rc = child->open();
    if (rc != SUCCESS) {
      return rc;
    }

    while ((rc = child->next()) == RC::SUCCESS) {
      Tuple * tuple = new CompositeTuple(static_cast<CompositeTuple &>(*child->current_tuple()));
      std::vector<TupleCell *> cells;
      for (int i = 0; i < this->fields_.size(); i++) {
        TupleCell *cell = new TupleCell();
        rc = tuple->find_cell(*fields_[i], *cell);
        if (RC::SUCCESS != rc) {
          return rc;
        }
        cells.push_back(cell);
      }
      
      if (flag_ == DESC_T) {
        desc_queue_.push(std::pair<std::vector<TupleCell*>, Tuple*>{cells, tuple});
      } else {
        asc_queue_.push(std::pair<std::vector<TupleCell*>, Tuple*>{cells, tuple});
      }
    }
    return RC::SUCCESS;
  }
  virtual RC next() {
    if ((flag_ == DESC_T && desc_queue_.empty()) || (flag_ == ASC_T && asc_queue_.empty())) {
      return RC::RECORD_EOF;
    }
    if (flag_ == DESC_T) {
      current_tuple_ = this->desc_queue_.top().second;
      this->desc_queue_.pop();
    } else {
      current_tuple_ = this->asc_queue_.top().second;
      this->asc_queue_.pop();
    }
    
    return RC::SUCCESS;
  }
  virtual RC close() {
    Operator *child = children_[0];
    while (!asc_queue_.empty()) {
      asc_queue_.pop();
    }
    while (!desc_queue_.empty()) {
      desc_queue_.pop();
    }
    RC rc = child->close();
    return rc;
  }

  virtual Tuple * current_tuple() {
    return current_tuple_;
  }

  void add_child(Operator *oper) {
    children_.push_back(oper);
  }


protected:
  std::priority_queue<std::pair<std::vector<TupleCell*>,Tuple*>, std::vector<std::pair<std::vector<TupleCell*>,Tuple*>>, ORDER_DESC> desc_queue_;
  std::priority_queue<std::pair<std::vector<TupleCell*>,Tuple*>, std::vector<std::pair<std::vector<TupleCell*>,Tuple*>>, ORDER_ASC> asc_queue_;
  std::vector<Operator *> children_;
  std::vector<Field*> fields_;
  Tuple* current_tuple_;
  OrderFlag flag_;
};