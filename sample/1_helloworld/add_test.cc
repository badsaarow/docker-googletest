#include "gtest/gtest.h"
#include "add.h"

namespace {
  TEST(EqualTest, Equal) {
    EXPECT_EQ(2, add(1, 1));
  }
}