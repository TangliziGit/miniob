
#pragma once

#include "sql/operator/operator.h"
#include "storage/common/table.h"
#include "rc.h"

// TODO fixme
class BaseOperator : public Operator
{
public:
  BaseOperator()
  {}

  virtual ~BaseOperator() = default;

  RC open() override{

  }
  RC next() override{

  }
  RC close() override{
  }
  virtual Tuple * current_tuple(){
    return &tuple;
  }

private:
  CompositeTuple tuple_;
};
