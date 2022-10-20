/* Copyright (c) 2021 Xie Meiyi(xiemeiyi@hust.edu.cn) and OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by wangyunlai on 2021/6/11.
//

#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include "rc.h"
#include "sql/parser/parse_defs.h"

const double epsilon = 1E-6;
void *chars_to_number(const char *data, AttrType &type);

int compare_int(void *arg1, void *arg2)
{
  int v1 = *(int *)arg1;
  int v2 = *(int *)arg2;
  return v1 - v2;
}

int compare_float(void *arg1, void *arg2)
{
  float v1 = *(float *)arg1; 
  float v2 = *(float *)arg2; 
  float cmp = v1 - v2;
  if (cmp > epsilon) {
    return 1;
  }
  if (cmp < -epsilon) {
    return -1;
  }
  return 0;
}

int compare_string(void *arg1, int arg1_max_length, void *arg2, int arg2_max_length)
{
  const char *s1 = (const char *)arg1;
  const char *s2 = (const char *)arg2;
  int maxlen = std::min(arg1_max_length, arg2_max_length);
  int result =  strncmp(s1, s2, maxlen);
  if (0 != result) {
    return result;
  }

  if (arg1_max_length > maxlen) {
    return s1[maxlen] - 0;
  }

  if (arg2_max_length > maxlen) {
    return 0 - s2[maxlen];
  }
  return 0;
}

RC chars_to(Value *value, AttrType type) {
  if (type == CHARS) return RC::SUCCESS;

  AttrType new_type;
  void *casted = chars_to_number((const char *)value->data, new_type);

  if (new_type == type) {
    value->type = type;
    value->data = casted;
    return RC::SUCCESS;
  }

  switch (type) {
    case INTS: {
      int number = static_cast<int>(std::lroundf(*(float *)casted));
      value_init_integer(value, number);
      break;
    }
    case FLOATS: {
      auto number = static_cast<float>(*(int *)casted);
      value_init_float(value, number);
      break;
    }
    default:
      return RC::SCHEMA_FIELD_TYPE_MISMATCH;
  }
  return RC::SUCCESS;
}

RC ints_to(Value *value, AttrType type) {
  switch (type) {
    case INTS:
      break;
    case CHARS: {
      char string[4];
      sprintf(string, "%d", *(int *) value->data);
      value_init_string(value, string);
      break;
    }
    case FLOATS: {
      value_init_float(value, *(int *)value->data);
      break;
    }
    default:
      return RC::SCHEMA_FIELD_TYPE_MISMATCH;
  }
  return RC::SUCCESS;
}

RC floats_to(Value *value, AttrType type) {
  switch (type) {
    case FLOATS:
      break;
    case CHARS: {
      char string[100];
      sprintf(string, "%.2f", *(float *) value->data);
      size_t len = strlen(string);
      if (string[len-1] == '0') string[--len] = 0;
      value_init_string(value, string);
      break;
    }
    case INTS: {
      value_init_integer(value, std::round(*(float *) value->data));
      break;
    }
    default:
      return RC::SCHEMA_FIELD_TYPE_MISMATCH;
  }
  return RC::SUCCESS;
}

RC cast_to(Value *value, AttrType type) {
  switch (value->type) {
    case CHARS:
      return chars_to(value, type);
    case INTS:
      return ints_to(value, type);
    case FLOATS:
      return floats_to(value, type);
    default:
      return RC::SCHEMA_FIELD_TYPE_MISMATCH;
  }
}

int cast_to_int(void *data, AttrType type) {
  int res = 0;
  switch (type) {
    case CHARS:
      res = atoi((char *)data);
      break;
    case INTS:
      res = *(int *) data;
      break;
    case FLOATS:
      res = static_cast<int>(*(float *) data);
      break;
    default:
      break;
  }
  return res;
}

float cast_to_float(void *data, AttrType type) {
  float res = 0;
  switch (type) {
    case CHARS:
      res = atof((char *)data);
      break;
    case INTS:
      res = static_cast<float>(*(int *) data);
      break;
    case FLOATS:
      res = *(float *) data;
      break;
    default:
      break;
  }
  return res;
}

void *chars_to_number(const char *data, AttrType &type) {
  int x = 0;
  int idx = -1;
  int i = 0;
  for ( ; data[i] != 0; i++) {
    char ch = data[i];
    if ('0' <= ch && ch <= '9') {
      x = x*10 + (ch - '0');
    } else if (ch == '.' && idx < 0) {
      idx = i;
    } else {
      break;
    }
  }

  // now data[0:i] only contain numbers and one dot
  if (i == 0) {
    type = INTS;
    auto *res = new int{0};
    return res;
  }

  // the chars contain one dot, so make result to be a float
  // corner case: `.`, `1.`, and `.1`
  if (idx >= 0) {
    type = FLOATS;
    auto *res = new float{static_cast<float>(x * std::pow(0.1, i - idx - 1))};
    return res;
  }

  // chars only contain numbers, so the result is an int
  type = INTS;
  auto *res = new int{x};
  return res;
}

AttrType cast_target(void *data, AttrType type) {
  if (type != CHARS) return type;

  AttrType new_type;
  chars_to_number((const char *)data, new_type);
  return new_type;
}
