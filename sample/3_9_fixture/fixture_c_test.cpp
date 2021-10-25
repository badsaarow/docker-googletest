// fixture_c_test
#include "stdio.h"
#include <gtest/gtest.h>
#include "fixture_c.h"

// Fixture를 C에서 사용하기 위해 Setup을 하는 클래스 정의
class StateTestSmpl : public testing::Test {
 protected:  // You should make the members protected s.t. they can be
             // accessed from sub-classes.

  //TEST_F 를 통해 이 SetUp() 불려 매 함수마다 전역변수를 초기화하도록 한다.
  virtual void SetUp() {
    state.current_state = 0;
    state.prev_state = 0;
  }

  //
  // virtual void TearDown() {
  // }
};

// 항상 성공하는 테스트케이스.  TEST_F 자체가 제대로 되는지 확인 용
TEST_F(StateTestSmpl, Always_True) {
    EXPECT_EQ(0, 0);
}

// go_next_state() 함수가 제대로 동작하는지 확인
TEST_F(StateTestSmpl, Next_State) {
    // 전역변수 초기화가 제대로 되었는지 확인
    EXPECT_EQ(0, state.current_state);
    EXPECT_EQ(0, state.prev_state);

    go_next_state(); // 함수가 실행되면 전역변수 상태값이 바뀐다.

    // 함수 실행 전역변수가 제대로 바뀌었는지 확인
    EXPECT_EQ(1, state.current_state);
    EXPECT_EQ(0, state.prev_state);
}

// 이전 테스트 케이스와 영향이 없을 체크하기 위함
TEST_F(StateTestSmpl, Next_Next_State) {
    // 상태를 두번 바꿈.
    go_next_state();
    go_next_state();

    // 호출전 전역변수가 초기화되었으므로 2,1이 됨을 확인
    EXPECT_EQ(2, state.current_state);
    EXPECT_EQ(1, state.prev_state);
}