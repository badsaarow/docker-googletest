// mock_c.c
#include "mock_device.h"

// 실제 고객의 코드
int comm_test()
{
    if(connect() == 1)
    {
        send((char *)"hello mock test\n");
        return 1;
    }

    return 0;
}