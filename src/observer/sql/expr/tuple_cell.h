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
// Created by WangYunlai on 2022/6/7.
//

#pragma once

#include <cstring>
#include <iostream>
#include "storage/common/table.h"
#include "storage/common/field_meta.h"
#include "util/comparator.h"

class TupleCell
{
public: 
  TupleCell() = default;
  
  TupleCell(FieldMeta *meta, char *data)
    : TupleCell(meta->type(), data)
  {}
  TupleCell(AttrType attr_type, char *data)
    : attr_type_(attr_type), data_(data)
  {}

  explicit TupleCell(int number)
      : attr_type_(INTS), data_((char *)new int{number}) {}
  explicit TupleCell(float number)
      : attr_type_(FLOATS), data_((char *)new float{number}) {}

  void set_type(AttrType type) { this->attr_type_ = type; }
  void set_length(int length) { this->length_ = length; }
  void set_data(char *data) { this->data_ = data; }
  void set_data(const char *data) { this->set_data(const_cast<char *>(data)); }

  void to_string(std::ostream &os) const;

  int compare(const TupleCell &other) const;

  bool like(const TupleCell &other) const;
  bool is(const TupleCell &other) const;

  TupleCell cast_to(const TupleCell &target) const;
  std::pair<TupleCell, RC> add(const TupleCell &rhs) const;
  std::pair<TupleCell, RC> div(const TupleCell &rhs) const;
  std::pair<TupleCell, RC> min(const TupleCell &rhs) const;
  std::pair<TupleCell, RC> max(const TupleCell &rhs) const;

  char *data() const
  {
    return data_;
  }

  int length() const { return length_; }
  bool is_null()const {
    return attr_type_ == NULLS;
  }

  AttrType attr_type() const
  {
    return attr_type_;
  }

private:
  AttrType attr_type_ = UNDEFINED;
  int length_ = -1;
  char *data_ = nullptr; // real data. no need to move to field_meta.offset
};

namespace std {
template<>
struct hash<TupleCell> {
  // naive hasher implement
  std::size_t operator()(const TupleCell &cell) const {
    auto type = cell.attr_type();
    if (type == NULLS) return 0;
    auto h = type + cell.length();

    if (type == CHARS || type == TEXTS) {
      for (int i=0; cell.data()[i] != 0; i++)
        h += cell.data()[i];
    } else {
      for (int i = 0; i < cell.length(); i++)
        h += cell.data()[i];
    }
    return h;
  }
};

template<>
struct equal_to<TupleCell> {
  bool operator()(const TupleCell &lhs, const TupleCell &rhs ) const {
    if (lhs.attr_type() == NULLS && rhs.attr_type() == NULLS) return true;
    if (lhs.attr_type() == NULLS || rhs.attr_type() == NULLS) return false;

    if (lhs.attr_type() != rhs.attr_type()) return false;

    auto type = lhs.attr_type();
    if (type == CHARS || type == TEXTS) {
      size_t i = 0;
      char *ldata = lhs.data();
      char *rdata = rhs.data();

      for (; ldata[i] != 0 && rdata[i] != 0; i++) {
        if (ldata[i] != rdata[i]) return false;
      }
      if (ldata[i] != rdata[i]) return false;
    } else {
      if (lhs.length() != rhs.length()) return false;

      size_t length = lhs.length();
      for (size_t i=0; i<length; i++) {
        if (lhs.data()[i] != rhs.data()[i]) return false;
      }
    }
    return true;
  }
};
}

