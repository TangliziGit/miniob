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
// Created by wangyunlai on 2022/9/28
//

#include <string.h>
#include "util/util.h"

std::string double2string(double v)
{
  char buf[256];
  snprintf(buf, sizeof(buf), "%.2f", v);
  size_t len = strlen(buf);
  while (buf[len - 1] == '0') {
    len--;
      
  }
  if (buf[len - 1] == '.') {
    len--;
  }

  return std::string(buf, len);
}

int get_char_min(){
  return 0;
}
int get_char_max(){
  return std::numeric_limits<char>::max();
};
int get_int_min(){
  /* +1防溢出 */
  return std::numeric_limits<int>::min()/2;
}
int get_int_max(){
  return std::numeric_limits<int>::max()/2;
}
float get_float_min(){
  return std::numeric_limits<float>::min()/2;
}
float get_float_max(){
  return std::numeric_limits<float>::max()/2;
}

char *concat(const char *prefix, const char *suffix) {
  char *result = strdup(prefix);
  strcat(result, suffix);
  return result;
}
