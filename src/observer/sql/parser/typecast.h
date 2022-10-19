#include <cstdlib>
#include <cstdio>
#include <cmath>
#include "rc.h"
#include "parse_defs.h"

RC chars_to(Value *value, AttrType type) {
  switch (type) {
    case CHARS:
      break;
    case INTS: {
      int number = atoi((char *)value->data);
      value_init_integer(value, number);
      break;
    }
    case FLOATS: {
      float number = atof((char *)value->data);
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
    }
    case FLOATS: {
      value_init_float(value, *(int*)value->data);
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
      char string[9];
      sprintf(string, "%f", *(float *) value->data);
      value_init_string(value, string);
    }
    case INTS: {
      value_init_integer(value, std::round(*(int *) value->data));
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