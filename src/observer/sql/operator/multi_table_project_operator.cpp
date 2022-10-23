
#include "common/log/log.h"
#include "sql/operator/multi_table_project_operator.h"
#include "storage/record/record.h"
#include "storage/common/table.h"

RC MultiTableProjectOperator::open()
{
  if (children_.size() != 1) {
    LOG_WARN("project operator must has 1 child");
    return RC::INTERNAL;
  }

  Operator *child = children_[0];
  RC rc = child->open();
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open child operator: %s", strrc(rc));
    return rc;
  }

  return RC::SUCCESS;
}

RC MultiTableProjectOperator::next()
{
  return children_[0]->next();
}

RC MultiTableProjectOperator::close()
{
  children_[0]->close();
  return RC::SUCCESS;
}
Tuple * MultiTableProjectOperator::current_tuple()
{
  tuple_.set_tuple(children_[0]->current_tuples());
  return &tuple_;
}

void MultiTableProjectOperator::add_projection(const Table *table, const FieldMeta *field_meta)
{
  TupleCellSpec *spec = new TupleCellSpec(new FieldExpr(table, field_meta));

  spec->set_alias(strdup(std::string(table->name()).append(".").append(field_meta->name()).c_str()));
  tuple_.add_cell_spec(spec);
}

RC MultiTableProjectOperator::tuple_cell_spec_at(int index, const TupleCellSpec *&spec) const
{
  return tuple_.cell_spec_at(index, spec);
}
