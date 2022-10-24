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
// Created by Meiyi & wangyunlai.wyl on 2021/5/19.
//

#include "storage/index/bplus_tree_index.h"
#include "common/log/log.h"

BplusTreeIndex::~BplusTreeIndex() noexcept
{
  close();
}

RC BplusTreeIndex::create(const char *file_name, const IndexMeta &index_meta, const std::vector<const FieldMeta*>&field_meta)
{
  if (inited_) {
    return RC::RECORD_OPENNED;
  }

  Index::init(index_meta, field_meta);
  std::vector<AttrType> attr_type;
  std::vector<int> attr_length;
  int total_length = 0;
  for(auto filed:field_meta){
    attr_type.emplace_back(filed->type());
    attr_length.emplace_back(filed->len());
    total_length += filed->len();
  }
  RC rc = index_handler_.create(file_name, attr_type, attr_length, total_length,index_meta.is_unique());
  if (RC::SUCCESS != rc) {
    return rc;
  }

  inited_ = true;
  return RC::SUCCESS;
}

RC BplusTreeIndex::open(const char *file_name, const IndexMeta &index_meta, const std::vector<const FieldMeta*>&field_meta)
{
  if (inited_) {
    return RC::RECORD_OPENNED;
  }

  Index::init(index_meta, field_meta);

  RC rc = index_handler_.open(file_name);
  if (RC::SUCCESS != rc) {
    return rc;
  }

  inited_ = true;
  return RC::SUCCESS;
}

RC BplusTreeIndex::close()
{
  if (inited_) {
    index_handler_.close();
    inited_ = false;
  }
  LOG_INFO("Successfully close index.");
  return RC::SUCCESS;
}

RC BplusTreeIndex::insert_entry(const char *record, const RID *rid)
{
  static const char *attr_ptr[MAX_NUM];
  bool has_null = false;
  for (size_t i = 0; i < field_meta_.size(); i++) {
    attr_ptr[i] = record + field_meta_[i].offset();
    has_null |= *(char *)(record + field_meta_[i].offset() + field_meta_[i].len()) == 1;
  }
  return index_handler_.insert_entry(attr_ptr, rid, has_null);
}

RC BplusTreeIndex::delete_entry(const char *record, const RID *rid)
{
  static const char *attr_ptr[MAX_NUM];
  for (size_t i = 0; i < field_meta_.size();i++){
    attr_ptr[i] = record + field_meta_[i].offset();
  }
  return index_handler_.delete_entry(attr_ptr, rid);
}

IndexScanner *BplusTreeIndex::create_scanner(const char *left_key, int left_len, bool left_inclusive,
					     const char *right_key, int right_len, bool right_inclusive)
{
  BplusTreeIndexScanner *index_scanner = new BplusTreeIndexScanner(index_handler_);
  RC rc = index_scanner->open(left_key, left_len, left_inclusive, right_key, right_len, right_inclusive);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open index scanner. rc=%d:%s", rc, strrc(rc));
    delete index_scanner;
    return nullptr;
  }
  return index_scanner;
}

RC BplusTreeIndex::sync()
{
  return index_handler_.sync();
}

////////////////////////////////////////////////////////////////////////////////
BplusTreeIndexScanner::BplusTreeIndexScanner(BplusTreeHandler &tree_handler) : tree_scanner_(tree_handler)
{}

BplusTreeIndexScanner::~BplusTreeIndexScanner() noexcept
{
  tree_scanner_.close();
}

RC BplusTreeIndexScanner::open(const char *left_key, int left_len, bool left_inclusive,
                               const char *right_key, int right_len, bool right_inclusive)
{
  return tree_scanner_.open(left_key, left_len, left_inclusive, right_key, right_len, right_inclusive);
}

RC BplusTreeIndexScanner::next_entry(RID *rid)
{
  return tree_scanner_.next_entry(rid);
}

RC BplusTreeIndexScanner::destroy()
{
  delete this;
  return RC::SUCCESS;
}
