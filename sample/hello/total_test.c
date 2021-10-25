#include "stdio.h"
#include <gtest/gtest.h>


TEST(Total_Test, Total_True) {
    int i, total;
    total = 0;

    for (i = 0; i < 10; i++)
    {
        total += i;
 
        if (total != 45)
            printf ("Failure\n");
        else
            printf ("Success\n");
    }


}