#pragma once

#include "function.h"

namespace function {

class Avg : public Function {
public:
  Avg() = default;

public:
  bool isAggregate() override { return true; }

  State initialState() override {
    // sum, count, and non-null flag
    return { new TupleCell{(float)0}, new TupleCell{(int)0}, new TupleCell{(int)0} };
  }

  TupleCell settle(const State &state) override {
    if (*(int *)state_[2]->data() == 0) {
      // if no non-null value received, return NULL
      return TupleCell{NULLS, nullptr};
    }
    return state[0]->div(*state[1]).first;
  }

protected:
  RC validate_fields(const ArgumentFields &fields) override {
    if (fields.size() != 1)
      return RC::INVALID_ARGUMENT;
    return RC::SUCCESS;
  }

  TupleCell calculate(const std::vector<TupleCell> &argument) override {
    if (argument[0].is_null()) {
      return {NULLS, nullptr};
    }

    auto sum_cell = state_[0]->add(argument[0]);
    if (sum_cell.second != SUCCESS) {
      setRC(sum_cell.second);
      return sum_cell.first;
    }

    auto count = (int *)state_[1]->data();
    (*count)++;

    float sum = *(float *) sum_cell.first.data();
    state_[0]->set_data((char *)new float{sum});

    // set non-null flag true
    if (*(int *)state_[2]->data() == 0) {
      *(int *)state_[2]->data() = 1;
    }

    TupleCell cell{ sum / (float)(*count) };
    return cell;
  }

};
}
