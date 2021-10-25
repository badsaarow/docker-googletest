#include <gtest/gtest.h>
void swap(int& x, int& y){}

TEST(Swap_Test, Swap_True) {

    int x = 30;
    int y = 15;
    swap(x, y);
    ASSERT_EQ(15, x) << "x must be 15";
    ASSERT_EQ(30, y) << "y must be 30";

}