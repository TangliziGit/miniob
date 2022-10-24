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
// Created by WangYunlai on 2022/07/05.
//

#include <vector>
#include "sql/expr/tuple_cell.h"
#include "storage/common/field.h"
#include "common/log/log.h"
#include "util/comparator.h"
#include "util/util.h"

void TupleCell::to_string(std::ostream &os) const
{
  switch (attr_type_) {
  case INTS: {
    os << *(int *)data_;
  } break;
  case FLOATS: {
    float v = *(float *)data_;
    os << double2string(v);
  } break;
  case NULLS:{
    os << "null";
  }
  case TEXTS:
  case CHARS: {
    for (int i = 0; i < length_; i++) {
      if (data_[i] == '\0') {
        break;
      }
      os << data_[i];
    }
  } break;
  case DATES: {
    int val = *(int *)data_;
    char buf[16] = {0};
    snprintf(buf, sizeof(buf), "%04d-%02d-%02d", val / 10000, (val % 10000) / 100, val % 100);
    for (int i = 0; i < 16; i++) {
      if (buf[i] == '\0') {
        break;
      }
      os << buf[i];
    }
  }
  default: {
    LOG_WARN("unsupported attr type: %d", attr_type_);
  } break;
  }
}

int TupleCell::compare(const TupleCell &other) const
{
  if (this->attr_type_ == other.attr_type_) {
    switch (this->attr_type_) {
    case INTS: return compare_int(this->data_, other.data_);
    case FLOATS: return compare_float(this->data_, other.data_);
    case CHARS: return compare_string(this->data_, this->length_, other.data_, other.length_);
    case DATES:
      return compare_int(this->data_, other.data_);
    default: {
      LOG_WARN("unsupported type: %d", this->attr_type_);
      return -1;
    }
    }
  }

  auto lhs = this->cast_to(other);
  auto rhs = other.cast_to(*this);
  if (lhs.attr_type_ == rhs.attr_type_) {
    return lhs.compare(rhs);
  }
  return -1; // TODO return rc?
}

bool TupleCell::is(const TupleCell &other) const{
  return attr_type_ == NULLS && other.attr_type_ == NULLS;
}

bool TupleCell::like(const TupleCell &other) const
{
  if (this->attr_type_ == other.attr_type_ && this->attr_type() == CHARS) {
    /* 默认右侧为匹配串,动态规划 */
    const char *p1 = data_, *p2 = other.data();
    int len1 = strnlen(p1,length_), len2 = other.length();
    std::vector<std::vector<bool>> dp(len1+1, std::vector<bool>(len2+1, false));
    dp[0][0] = true;
    for (int i = 1; i <= len2; i++) {
      if(dp[0][i-1]&&(p2[i-1]=='%')){
        dp[0][i] = true;
      }else{
        break;
      }
    }
    for (int i = 1; i <= len1;i++){
      for (int j = 1; j <= len2;j++){
        if(p2[j-1]=='%'){
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - 1] || dp[i][j - 1];
          continue;
        }
        if(p2[j-1]=='_'||p2[j-1]==p1[i-1]||(p2[j-1]-32)==p1[i-1]||(p2[j-1]+32==p1[i-1])){
          dp[i][j] = dp[i - 1][j - 1];
        }
      }
    }
    return dp[len1][len2];
  }
  LOG_WARN("like not supported");
  return false; // TODO return rc?
}

TupleCell TupleCell::cast_to(const TupleCell &target) const {
  if (this->attr_type_ == target.attr_type_) return *this;

  AttrType this_type = cast_target(this->data_, this->attr_type_);
  AttrType target_type = cast_target(target.data_, target.attr_type_);
  AttrType new_type = std::max(this_type, target_type);
  switch (new_type) {
    case INTS: {
      int value = cast_to_int(this->data_, this->attr_type_);
      return TupleCell{value};
    }
    case FLOATS: {
      float value = cast_to_float(this->data_, this->attr_type_);
      return TupleCell{value};
    }
    default: {
      LOG_WARN("not supported");
      break;
    }
  }

  return *this;
}

std::pair<TupleCell, RC> TupleCell::add(const TupleCell &other) const {
  auto lhs = this->cast_to(other);
  auto rhs = other.cast_to(*this);
  if (lhs.attr_type_ != rhs.attr_type_) {
    return { *this, MISMATCH };
  }

  switch (lhs.attr_type_) {
    case INTS: {
      int value = *(int *)lhs.data_ + *(int *)rhs.data_;
      memcpy(lhs.data_, &value, sizeof(value));
      return { lhs, SUCCESS };
    }
    case FLOATS: {
      float value = *(float *)lhs.data_ + *(float *)rhs.data_;
      memcpy(lhs.data_, &value, sizeof(value));
      return { lhs, SUCCESS };
    }
    default:
      LOG_WARN("not supported");
  }

  return { lhs, UNIMPLENMENT };
}

std::pair<TupleCell, RC> TupleCell::div(const TupleCell &other) const {
  auto lhs = this->cast_to(other);
  auto rhs = other.cast_to(*this);
  if (lhs.attr_type_ != rhs.attr_type_) {
    return { *this, MISMATCH };
  }

  switch (lhs.attr_type_) {
    case INTS: {
      int value = *(int *)lhs.data_ / *(int *)rhs.data_;
      memcpy(lhs.data_, &value, sizeof(value));
      return { lhs, SUCCESS };
    }
    case FLOATS: {
      float value = *(float *)lhs.data_ / *(float *)rhs.data_;
      memcpy(lhs.data_, &value, sizeof(value));
      return { lhs, SUCCESS };
    }
    default:
      LOG_WARN("not supported");
  }

  return { lhs, UNIMPLENMENT };
}

std::pair<TupleCell, RC> TupleCell::min(const TupleCell &other) const {
  auto lhs = this->cast_to(other);
  auto rhs = other.cast_to(*this);
  if (lhs.attr_type_ != rhs.attr_type_) {
    return { *this, MISMATCH };
  }

  switch (lhs.attr_type_) {
    case CHARS: {
      int result = lhs.compare(rhs);
      if (result < 0) {
        return { lhs, SUCCESS };
      }
      return { rhs, SUCCESS };
    }
    case DATES:
    case INTS: {
      int value = std::min(*(int *)lhs.data_, *(int *)rhs.data_);
      memcpy(lhs.data_, &value, sizeof(value));
      return { lhs, SUCCESS };
    }
    case FLOATS: {
      float value = std::min(*(float *)lhs.data_, *(float *)rhs.data_);
      memcpy(lhs.data_, &value, sizeof(value));
      return { lhs, SUCCESS };
    }
    default:
      LOG_WARN("not supported");
  }

  return { lhs, UNIMPLENMENT };
}

std::pair<TupleCell, RC> TupleCell::max(const TupleCell &other) const {
  auto lhs = this->cast_to(other);
  auto rhs = other.cast_to(*this);
  if (lhs.attr_type_ != rhs.attr_type_) {
    return { *this, MISMATCH };
  }

  switch (lhs.attr_type_) {
    case CHARS: {
      int result = lhs.compare(rhs);
      if (result < 0) {
        return { rhs, SUCCESS };
      }
      return { lhs, SUCCESS };
    }
    case DATES:
    case INTS: {
      int value = std::max(*(int *)lhs.data_, *(int *)rhs.data_);
      memcpy(lhs.data_, &value, sizeof(value));
      return { lhs, SUCCESS };
    }
    case FLOATS: {
      float value = std::max(*(float *)lhs.data_, *(float *)rhs.data_);
      memcpy(lhs.data_, &value, sizeof(value));
      return { lhs, SUCCESS };
    }
    default:
      LOG_WARN("not supported");
  }

  return { lhs, UNIMPLENMENT };
}
