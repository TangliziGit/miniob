#pragma once

#include <limits>
#include <algorithm>
#include "function.h"

static const char *months[] = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December",
};

static const char *days[] = {
    "1st", "2nd", "3rd", "4th", "5th", "6th", "7th", "8th", "9th",
    "10th", "11th", "12th", "13th", "14th", "15th", "16th", "17th", "18th", "19th",
    "20th", "21st", "22nd", "23rd", "24th", "25th", "26th", "27th", "28th", "29th",
    "30th", "31st"
};

static void replace(std::string &result, const char *pattern, const char *target) {
  std::string p = pattern;
  std::string t = target;

  size_t pos = result.find(p);
  while (pos != std::string::npos) {
    result.replace(pos, p.length(), t);
    pos = result.find(p);
  }
}

namespace function {

class DateFormat : public Function {
public:
  DateFormat() = default;

protected:
  RC validate_fields(const ArgumentFields &fields) override {
    if (fields.size() != 2)
      return RC::INVALID_ARGUMENT;
    if (fields[0]->attr_type() != DATES)
      return RC::INVALID_ARGUMENT;
    if (fields[1]->attr_type() != CHARS && fields[1]->attr_type() != TEXTS)
      return RC::INVALID_ARGUMENT;
    return RC::SUCCESS;
  }

  TupleCell calculate(const std::vector<TupleCell> &argument) override {
    int date = *(int *)argument[0].data();
    std::string result = argument[1].data();

    int year = date / 10000;
    int month = (date / 100) % 100;
    int day = date % 100;

    char Y[10];
    const char *M = months[month - 1];
    const char *D = days[day - 1];
    char y[10];
    char m[10];
    char d[10];

    sprintf(Y, "%04d", year);
    sprintf(y, "%02d", year % 100);
    sprintf(m, "%02d", month);
    sprintf(d, "%02d", day);

    replace(result, "%Y", Y);
    replace(result, "%y", y);
    replace(result, "%M", M);
    replace(result, "%m", m);
    replace(result, "%D", D);
    replace(result, "%d", d);

    char *newDate = strdup(result.c_str());
    return TupleCell{ TEXTS, newDate };
  }
};
}