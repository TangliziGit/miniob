#pragma once

#include <utility>
#include <vector>
#include <queue>
#include "rc.h"
#include "sql/function/register.h"
#include "sql/operator/operator.h"

struct ORDER
{
    bool operator () (std::pair<std::vector<std::pair<OrderFlag, TupleCell*>>,Tuple*> &a, std::pair<std::vector<std::pair<OrderFlag, TupleCell*>>,Tuple*> &b)
    {
      for (size_t i = 0; i < a.first.size(); i++) {
        if (a.first[i].second->is_null() && b.first[i].second->is_null()) {
          continue;
        }
        if (a.first[i].second->is_null()) {
          return a.first[i].first == DESC_T;
        }
        if (b.first[i].second->is_null()) {
          return b.first[i].first == ASC_T;
        }
        if (a.first[i].second->compare(*b.first[i].second) == 0) {
          continue;
        }
        if (a.first[i].first == ASC_T) {
          return a.first[i].second->compare(*b.first[i].second) > 0;
        }
        return a.first[i].second->compare(*b.first[i].second) < 0;
      }
      return false;
    }
};
class OrderByOperator : public Operator
{
public:
  OrderByOperator(std::vector<Field*> fields, std::vector<OrderFlag> flag) : fields_(fields), flag_(flag) {
    
  }
  virtual RC open() {
    Operator *child = children_[0];
    RC rc = child->open();
    if (rc != SUCCESS) {
      return rc;
    }

    while ((rc = child->next()) == RC::SUCCESS) {
      Tuple * tuple = new CompositeTuple(static_cast<CompositeTuple &>(*child->current_tuple()));
     std::vector<std::pair<OrderFlag, TupleCell*>> cells;
      for (size_t i = 0; i < this->fields_.size(); i++) {
        TupleCell *cell = new TupleCell();
        rc = tuple->find_cell(*fields_[i], *cell);
        if (RC::SUCCESS != rc) {
          return rc;
        }
        cells.push_back({flag_[i], cell});
      }
      
      order_queue_.push(std::pair<std::vector<std::pair<OrderFlag, TupleCell*>>, Tuple*>{cells, tuple});
    }
    return RC::SUCCESS;
  }
  virtual RC next() {
    if (order_queue_.empty()) {
      return RC::RECORD_EOF;
    }
    current_tuple_ = this->order_queue_.top().second;
    this->order_queue_.pop();
    return RC::SUCCESS;
  }
  virtual RC close() {
    Operator *child = children_[0];
    while (!order_queue_.empty()) {
      order_queue_.pop();
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
  std::priority_queue<std::pair<std::vector<std::pair<OrderFlag, TupleCell*>>,Tuple*>, std::vector<std::pair<std::vector<std::pair<OrderFlag, TupleCell*>>,Tuple*>>, ORDER> order_queue_;
  std::vector<Operator *> children_;
  std::vector<Field*> fields_;
  Tuple* current_tuple_;
  std::vector<OrderFlag> flag_;
};