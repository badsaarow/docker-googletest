// my_math_test.c
#include <stdio.h>
#include <gtest/gtest.h>
#include "my_math.h"

TEST(Math_Test, checkPrimeNumber) {
    EXPECT_FALSE(0 == checkPrimeNumber(3));
}