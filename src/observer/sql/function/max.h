#pragma once

#include <limits>
#include "function.h"
#include "util/comparator.h"

namespace function {

class Max : public Function {
public:
  Max() = default;

public:
  bool isAggregate() override { return true; }

  State initialState() override {
    State result;
    switch (fields_[0]->attr_type()) {
      case CHARS:
        result.push_back(new TupleCell{CHARS, strdup("")});
        break;
      case INTS:
        result.push_back(new TupleCell{INT32_MIN});
        break;
      case FLOATS:
        result.push_back(new TupleCell{std::numeric_limits<float>::min()});
        break;
      case DATES: {
        auto data = new int{0};
        result.push_back(new TupleCell{DATES, (char *)data});
        break;
      }
      default: {
        LOG_ERROR("unsupported attribute type in min function: %d", fields_[0]->attr_type());
        result.push_back(new TupleCell{INT32_MIN});
      }
    }
    // non-null flag state
    result.push_back(new TupleCell{(int)0});
    return result;
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

    auto pair = state_[0]->max(argument[0]);
    if (pair.second != SUCCESS) {
      setRC(pair.second);
      return *state_[0];
    }
    *state_[0] = pair.first;

    // set non-null flag true
    if (*(int *)state_[2]->data() == 0) {
      *(int *)state_[2]->data() = 1;
    }

    return *state_[0];
  }
};
}
