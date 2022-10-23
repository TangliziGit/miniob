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
    switch (fields_[0]->attr_type()) {
      case CHARS:
        return { new TupleCell{CHARS, strdup("")} };
      case INTS:
        return { new TupleCell{INT32_MIN} };
      case FLOATS:
        return { new TupleCell{std::numeric_limits<float>::min()} };
      case DATES: {
        auto data = new int{0};
        return { new TupleCell{DATES, (char *)data} };
      }
      default:
        LOG_ERROR("unsupported attribute type in min function: %d",
                  fields_[0]->attr_type());
    }
    return { new TupleCell{INT32_MIN} };
  }

  TupleCell settle(const State &state) override {
    return *state[0];
  }

protected:
  RC validate_fields(const ArgumentFields &fields) override {
    if (fields.size() != 1)
      return RC::INVALID_ARGUMENT;
    return RC::SUCCESS;
  }

  TupleCell calculate(const std::vector<TupleCell> &argument) override {
    // TODO(chunxu): check if null
    auto pair = state_[0]->max(argument[0]);
    if (pair.second != SUCCESS) {
      setRC(pair.second);
      return *state_[0];
    }
    *state_[0] = pair.first;
    return *state_[0];
  }

};
}
