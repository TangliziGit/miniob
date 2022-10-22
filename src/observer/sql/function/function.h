#pragma once

#include <utility>
#include <vector>
#include <functional>
#include "rc.h"
#include "storage/common/field.h"
#include "sql/expr/tuple_cell.h"

class Function {
public:
  using State = std::vector<TupleCell *>;
  using Arguments = std::vector<TupleCell>;

protected:
  virtual RC validate(const std::vector<TupleCell> &argument) { return RC::GENERIC_ERROR; }
  virtual TupleCell calculate(const std::vector<TupleCell> &argument) { return {AttrType::UNDEFINED, nullptr}; }
  RC setRC(RC rc) { return rc_ = rc; };

public:
  // only for stateful functions
  virtual bool isAggregate() { return false; }
  virtual State initialState() { return {}; }
  virtual TupleCell settle(const State &state) { return {}; }
  State getState() { return state_; }
  void setState(State state) { state_ = std::move(state); }

public:
  RC execute(const Arguments &arguments, TupleCell &result) {
    if (setRC(validate(arguments)) != RC::SUCCESS) {
      return rc_;
    }
    result = calculate(arguments);
    return rc_;
  }

  RC execute(const Arguments &arguments, TupleCell &result, State &state) {
    setState(state);
    RC rc = execute(arguments, result);
    state = getState();
    return rc;
  }

protected:
  RC rc_ = RC::SUCCESS;
  State state_{};
};
