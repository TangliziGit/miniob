#pragma once

#include "function.h"
#include "count.h"
#include "max.h"
#include "min.h"
#include "avg.h"
#include "sum.h"

struct FunctionInfo {
  std::function<Function *()> constructor;
  bool aggregation = false;
};

using Functions = std::unordered_map<std::string, FunctionInfo>;
class FunctionRegister {
public:
  static Functions &functions() {
      static Functions fs;
      return fs;
  };

  static std::pair<Function *, RC> create(const std::string &name, const Function::ArgumentFields &fields) {
    Functions funcs = functions();
    if (funcs.count(name) == 0) {
      return { nullptr, RC::NOTFOUND };
    }
    Function *func = funcs[name].constructor();
    return { func, func->setArgumentFields(fields) };
  }

  static bool is_aggregation(const std::string &name) {
    Functions funcs = functions();
    if (funcs.count(name) == 0) {
      return false;
    }
    return funcs[name].aggregation;
  }

public:
  FunctionRegister(const std::string &name, std::function<Function *()> func, bool aggregation = false) {
    functions()[name] = { std::move(func), aggregation };
  }
};


#define Constructor(CLASS) [](){ return new CLASS(); }
static FunctionRegister count{ "count", Constructor(function::Count), true };
static FunctionRegister max{ "max", Constructor(function::Max), true };
static FunctionRegister min{ "min", Constructor(function::Min), true };
static FunctionRegister avg{ "avg", Constructor(function::Avg), true };
static FunctionRegister sum{ "sum", Constructor(function::Sum), true };
