#include "function.h"

namespace function {

class Count : public Function {
public:
  Count() = default;

public:
  bool isAggregate() override { return true; }

  State initialState() override {
    return { new TupleCell{(int)0} };
  }

  TupleCell settle(const State &state) override {
    return *state[0];
  }

protected:
  RC validate(const std::vector<TupleCell> &argument) override {
    if (argument.size() != 1)
      return RC::INVALID_ARGUMENT;
    return RC::SUCCESS;
  }

  TupleCell calculate(const std::vector<TupleCell> &argument) override {
    // TODO(chunxu): check if null
    auto data = (int *)state_[0]->data();
    (*data)++;
    return *state_[0];
  }

};
}