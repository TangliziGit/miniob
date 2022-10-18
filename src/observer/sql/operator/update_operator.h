#pragma once

#include "sql/operator/operator.h"
#include "rc.h"

class Trx;
class UpdateStmt;

class UpdateOperator : public Operator
{
public:
  UpdateOperator(UpdateStmt *stmt, Trx *trx)
      : stmt_(stmt), trx_(trx)
  {}

  virtual ~UpdateOperator() = default;

  RC open() override;
  RC next() override;
  RC close() override;

  Tuple * current_tuple() override {
    return nullptr;
  }
private:
  UpdateStmt *stmt_ = nullptr;
  Trx *trx_ = nullptr;
};
