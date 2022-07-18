// mock_c_test.cpp
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "mock_c.h"
#include "MockDevice.h"

using namespace std;
using ::testing::Return;
using ::testing::_;

// mock을 쓰기 위해서는 꼭 해야 하는 gTest 선언.  함수의 파라미터와 리턴값만 정의한다.
class DeviceMock:MockDevice {
  public:
    MOCK_METHOD0(connect, int ());
    MOCK_METHOD1(send, int (char *str));
};

// device mock을 pointer로 정의해서 테스트시 할당한 후 없앨 거다.
DeviceMock *deviceMock;

// C 코드에서 linking시 symbol을 찾을 수 있어야 하므로 class 멤버함수가 아닌 일반 함수로 뺀다.
int connect(){
    return deviceMock->connect();
}

int send(char *str){
    return deviceMock->send(str);
}

// 항상 성공하는 함수
TEST(MockTest, Always_True) {
    EXPECT_EQ(1, 1);
};

// mock connect test 함수
TEST(MockTest, Comm_Test_True) {
    deviceMock = new DeviceMock();
    // mock의 행위를 정의.  connect()가 한번은 불려야 하고, 그 때 1을 리턴하도록 gTest mock에게 알린다.
    EXPECT_CALL(*deviceMock, connect())
    .WillOnce(Return(1));
    // send의 행위의 정의.  인자가 뭐가 오는간에 한번은 불려야 하고, 1을 리턴한다.
    EXPECT_CALL(*deviceMock, send(_))
    .WillOnce(Return(1));

    // connect와 send다 성공시 1을 리턴하는게 comm_test 함수이므로 1이 되면 성공.
    int ret_value = comm_test();
    EXPECT_EQ(1, ret_value);
    delete deviceMock;
};

TEST(MockTest, Comm_Test_False) {
    deviceMock = new DeviceMock();
    // connect()가 되지 않는 경우를 테스트하기 위해 불리면 0을 리턴하도록 gTest에게 알린다.
    EXPECT_CALL(*deviceMock, connect())
    .WillOnce(Return(0));

    // comm_test가 connect()를 부를 꺼고, 그 때 connect는 0을 리턴할 것으므로 0이 되면 맞다.
    int ret_value = comm_test();
    EXPECT_EQ(0, ret_value);
    delete deviceMock;
};

