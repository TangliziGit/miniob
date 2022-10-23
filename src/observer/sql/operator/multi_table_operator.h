#pragma once

#include "sql/operator/operator.h"


class MultiTableOperator : public Operator
{
public:
  MultiTableOperator(){}

  virtual ~MultiTableOperator() = default;
  void init(const std::map<std::string,int> &name_map){
    tuple_.init(name_map);
  }
  RC open() override;
  RC next() override;
  RC close() override;
  Tuple *current_tuple() override;

private:
  MulProjectTuple  tuple_;
};