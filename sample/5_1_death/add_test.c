#include "gtest/gtest.h"
#include "../src/add.h"

TEST(AddTest, Add) {
  ASSERT_TRUE(1);
}

TEST(AddTest, AddOnetoOne) {
  EXPECT_EQ(2, add(1,1));
}