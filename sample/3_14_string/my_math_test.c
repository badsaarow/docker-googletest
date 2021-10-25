// my_math_test.c
#include <stdio.h>
#include <gtest/gtest.h>
#include "my_math.h"

TEST(Math_Test, num_name_streq) {
    ASSERT_STREQ("zero", num_name(0));
}

TEST(Math_Test, num_name_strne) {
    ASSERT_STRNE("zero", num_name(1));
}

TEST(Math_Test, num_name_strne2) {
    ASSERT_STRNE("Zero", num_name(0));
}

TEST(Math_Test, num_name_strcaseeq) {
    ASSERT_STRCASEEQ("Zero", num_name(0));
}

TEST(Math_Test, num_name_strcasene) {
    ASSERT_STRCASENE("Zero", num_name(1));
}