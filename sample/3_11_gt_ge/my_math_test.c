// my_math_test.c
#include <stdio.h>
#include <gtest/gtest.h>
#include "my_math.h"

int arr[10] = {1,2,3,4,5,6,7,8,9,10};

TEST(Math_Test, sum_eq) {
    ASSERT_EQ(55, sum(arr, 10));
}

TEST(Math_Test, sum_lt) {
    ASSERT_LT(54, sum(arr, 10));
}

TEST(Math_Test, sum_le) {
    ASSERT_LE(55, sum(arr, 10));
}