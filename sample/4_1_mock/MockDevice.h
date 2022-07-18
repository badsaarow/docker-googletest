// MockDevice.h
#include "mock_device.h"

// header로 받을 함수들을 mock으로 테스트하기 위해 만든 wrapper class
class MockDevice {
    public:
        virtual ~MockDevice(){};
        virtual int connect()=0;
        virtual int send(char *str)=0;
};