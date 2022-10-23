

#pragma once

#include "sql/operator/operator.h"
#include "rc.h"

class MultiTableProjectOperator : public Operator
{
public:
  MultiTableProjectOperator()
  {}

  virtual ~MultiTableProjectOperator() = default;

  void add_projection(const Table *table, const FieldMeta *field);

  RC open() override;
  RC next() override;
  RC close() override;

  int tuple_cell_num() const
  {
    return tuple_.cell_num();
  }

  RC tuple_cell_spec_at(int index, const TupleCellSpec *&spec) const;

  Tuple *current_tuple() override;
  void set_name_map(const std::map<std::string,int> &name_map){
    tuple_.set_name_map(name_map);
  }

private:
  MulProjectTuple tuple_;
};
