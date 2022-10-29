#pragma once

#include <limits>
#include <cmath>
#include "function.h"

namespace function {

class Round : public Function {
public:
  Round() = default;

  RC validate(const std::vector<TupleCell> &argument) override {
    if (argument.size() == 2 && *(int*)argument[1].data() < 0) {
      return RC::INVALID_ARGUMENT;
    }
    return RC::SUCCESS;
  }

protected:
  RC validate_fields(const ArgumentFields &fields) override {
    if (fields.size() != 1 && fields.size() != 2) {
      return RC::INVALID_ARGUMENT;
    }

    if (fields[0]->attr_type() != FLOATS) return RC::INVALID_ARGUMENT;
    if (fields.size() == 2 && fields[1]->attr_type() != INTS) {
      return RC::INVALID_ARGUMENT;
    }

    return RC::SUCCESS;
  }

  TupleCell calculate(const std::vector<TupleCell> &argument) override {
    int pos = 0;
    if (argument.size() == 2) {
      pos = *(int*)argument[1].data();
    }

    float result = *(float *) argument[0].data();
    for (int i=0; i<pos; i++)
      result *= 10;
    result = std::round(result);
    for (int i=0; i<pos; i++)
      result /= 10;

    return TupleCell{ result };
  }
};
}
