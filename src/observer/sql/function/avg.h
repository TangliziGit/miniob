#pragma once

#include "function.h"

namespace function {

class Avg : public Function {
public:
  Avg() = default;

public:
  bool isAggregate() override { return true; }

  State initialState() override {
    // sum and count
    switch (fields_[0]->attr_type()) {
      case INTS:
        return { new TupleCell{(int)0}, new TupleCell{(int)0} };
      case FLOATS:
        return { new TupleCell{(float)0}, new TupleCell{(int)0} };
      default:
        LOG_ERROR("unsupported attribute type in avg function: %d",
            fields_[0]->attr_type());
    }
    return { new TupleCell{(int)0}, new TupleCell{(int)0} };
  }

  TupleCell settle(const State &state) override {
    return state[0]->div(*state[1]).first;
  }

protected:
  RC validate_fields(const ArgumentFields &fields) override {
    if (fields.size() != 1)
      return RC::INVALID_ARGUMENT;
    return RC::SUCCESS;
  }

  TupleCell calculate(const std::vector<TupleCell> &argument) override {
    // TODO(chunxu): check if null
    auto sum_cell = state_[0]->add(argument[0]);
    if (sum_cell.second != SUCCESS) {
      setRC(sum_cell.second);
      return sum_cell.first;
    }

    auto count = (int *)state_[1]->data();
    (*count)++;

    float sum;
    if (sum_cell.first.attr_type() == INTS) {
      sum = (float)*(int *) sum_cell.first.data();
    } else {
      sum = *(float *) sum_cell.first.data();
    }

    TupleCell cell{ sum / (float)(*count) };
    return cell;
  }

};
}
