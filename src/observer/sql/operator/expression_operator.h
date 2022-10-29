
#pragma once

#include "sql/operator/operator.h"
#include "storage/common/table.h"
#include "rc.h"
#include "sql/stmt/filter_stmt.h"
#include "storage/common/field.h"

// TODO fixme
class  ExprOperator : public ProjectOperator
{
public:
  ExprOperator();

  virtual ~ExprOperator() = default;
  explicit ExprOperator( std::vector<Expression*> exprs,std::vector<AbstractField *> query_fields):exprs_(exprs),query_fields_(query_fields){}
  RC open() override{
    if(children_.size()!=1){
      return RC::MISMATCH;
    }
    RC rc = RC::SUCCESS;
    for (auto field : query_fields_) {
      if((rc = add_projection(field))!= RC::SUCCESS){
        return rc;
      }
    }
    return children_[0]->open();
  }
  RC next() override{
    RC rc = children_[0]->next();
    if(rc !=RC::SUCCESS&&rc!=RC::SSSUCESS){
      return rc;
    }
    tuple_.set_tuple(children_[0]->current_tuple());
    return RC::SUCCESS;
  }
  RC close() override{
    if(children_.size()!=1){
      return RC::MISMATCH;
    }
    return children_[0]->close();
  }
  virtual Tuple * current_tuple(){
    return &tuple_;
  }
  RC add_projection(const AbstractField *abstract_field)override{
  // 对单表来说，展示的(alias) 字段总是字段名称，
  // 对多表查询来说，展示的alias 需要带表名字
  switch (abstract_field->type()) {
    case FieldType::FIELD: {
      auto field = dynamic_cast<const Field *>(abstract_field);
      auto *spec = new TupleCellSpec(new FieldExpr(field->table(), field->meta()));
      const char *alias = field->name();
      spec->set_alias(alias);
      tuple_.add_cell_spec(spec);
      break;
    }
    case FieldType::VALUE_FIELD: {
      auto field = dynamic_cast<const ValueField *>(abstract_field);
      auto *spec = new TupleCellSpec(new ValueExpr(*field->value()));
      spec->set_alias(field->name());
      tuple_.add_cell_spec(spec);
      break;
    }
    case FieldType::FUNCTION_FIELD: {
      auto field = dynamic_cast<const FunctionField *>(abstract_field);

      auto result = FunctionRegister::create(field->function_name(), field->fields());
      if (result.second != RC::SUCCESS) {
        return result.second;
      }
      Expression *expr;
      if (!FunctionRegister::is_aggregation(field->function_name())) {
        expr = new FunctionExpr(field->fields(), result.first);
      } else {
        expr = new AliasExpr(field->alias());
      }
      auto *spec = new TupleCellSpec(expr);
      spec->set_alias(field->name());
      tuple_.add_cell_spec(spec);
      break;
    }case FieldType::MATH_FIELD:{
      auto field = dynamic_cast<const MathField *>(abstract_field);
      int idx = field->expr_index();
      auto *spec = new TupleCellSpec(exprs_[idx]);
      spec->set_alias(field->name());
      tuple_.add_cell_spec(spec);
      break;
    }
    default:
      return RC::MISMATCH;
  }
  return RC::SUCCESS;
}
private:
  std::vector<Expression *> exprs_;
  std::vector<AbstractField *> query_fields_;
};
