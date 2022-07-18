#include "stdio.h"
#include "check_average.h"
#include <gtest/gtest.h>

TEST(Total_Test_Ref, Total_True) {

    EXPECT_EQ(1, check_average(10));
}

TEST(Total_Test_Ref, Total_False) {

    EXPECT_EQ(0, check_average(20));
}