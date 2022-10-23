#pragma once

#include "sql/operator/operator.h"


class MultiTableOperator : public Operator
{
public:
  MultiTableOperator() = default;

  virtual ~MultiTableOperator() = default;

  RC open() override;
  RC next() override;
  RC close() override;
  Tuple * current_tuple() override{
    return nullptr;
  }
  const std::vector<Tuple *> &current_tuples();
private:
  std::vector<Tuple *> tuples_;
};