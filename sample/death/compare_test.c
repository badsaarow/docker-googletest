#include "gtest/gtest.h"
// #include "../src/compare.h"

TEST(CompareTest, Compare) {
  ASSERT_GT(1, 0);
}

TEST(CompareTest, LT) {
  ASSERT_LT(3, 9);
}

TEST(CompareTest, String) {
  char *str = "hello";
  ASSERT_STREQ("hello", str);
}
