#include "gtest/gtest.h"
#include "sql/parser/parse_defs.h"
#include "util/comparator.h"

TEST(test_util, test_chars_to_number) {
  char* str = "11.5";
  AttrType type;
  void* res = chars_to_number(str, type);
  
  printf("int: %d\n", *(int*)res);
  printf("float: %f\n", *(float *)res);
}

int main(int argc, char **argv)
{
  // 分析gtest程序的命令行参数
  testing::InitGoogleTest(&argc, argv);

  // 调用RUN_ALL_TESTS()运行所有测试用例
  // main函数返回RUN_ALL_TESTS()的运行结果
  return RUN_ALL_TESTS();
}