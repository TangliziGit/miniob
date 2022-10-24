#pragma once

#include "function.h"

namespace function {

class Sum : public Function {
public:
  Sum() = default;

public:
  bool isAggregate() override { return true; }

  State initialState() override {
    switch (fields_[0]->attr_type()) {
      case INTS:
        return { new TupleCell{0}, new TupleCell{0} };
      case FLOATS:
        return { new TupleCell{(float)0.0}, new TupleCell{0} };
      default:
        LOG_ERROR("unsupported attribute type in min function: %d",
                  fields_[0]->attr_type());
    }
    return { new TupleCell{0}, new TupleCell{0} };
  }

  TupleCell settle(const State &state) override {
    if (*(int *)state_[1]->data() == 0) {
      // if no non-null value received, return NULL
      return TupleCell{NULLS, nullptr};
    }
    return *state[0];
  }

protected:
  RC validate_fields(const ArgumentFields &fields) override {
    if (fields.size() != 1)
      return RC::INVALID_ARGUMENT;
    return RC::SUCCESS;
  }

  TupleCell calculate(const std::vector<TupleCell> &argument) override {
    if (argument[0].is_null()) return *state_[0];

    auto pair = state_[0]->add(argument[0]);
    if (pair.second != SUCCESS) {
      setRC(pair.second);
      return *state_[0];
    }
    *state_[0] = pair.first;

    // set non-null flag true
    if (*(int *)state_[1]->data() == 0) {
      *(int *)state_[1]->data() = 1;
    }

    return *state_[0];
  }

};
}
