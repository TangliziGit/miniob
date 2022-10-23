
#pragma once

#include "sql/operator/operator.h"
#include <map>

class FilterStmt;

class MultiTablePredicateOperator : public Operator
{
public:
  MultiTablePredicateOperator(FilterStmt *filter_stmt,std::map<std::string, int>&name_map)
    : filter_stmt_(filter_stmt),name_map_(name_map)
  {}

  virtual ~MultiTablePredicateOperator() = default;

  RC open() override;
  RC next() override;
  RC close() override;

  Tuple * current_tuple() override{
    return nullptr;
  }
  const std::vector<Tuple *> &current_tuples();

private:
  bool do_predicate(const std::vector<Tuple*> &tuple);
private:
  FilterStmt *filter_stmt_ = nullptr;
  std::map<std::string, int> name_map_;
};
