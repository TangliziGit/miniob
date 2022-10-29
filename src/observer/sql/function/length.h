#pragma once

#include <limits>
#include "function.h"

namespace function {

class Length : public Function {
public:
  Length() = default;

protected:
  RC validate_fields(const ArgumentFields &fields) override {
    if (fields.size() != 1) return RC::INVALID_ARGUMENT;
    if (fields[0]->attr_type() != CHARS && fields[0]->attr_type() != TEXTS) return RC::INVALID_ARGUMENT;
    return RC::SUCCESS;
  }

  TupleCell calculate(const std::vector<TupleCell> &argument) override {
    char *data = argument[0].data();
    int count = 0;
    while (*data != '\0') count++, data++;
    return TupleCell{ count };
  }
};
}
