// fixture_c.c
#include <stdio.h>
#include "fixture_c.h"

// 전역변수.  Fixture를 C에서 써먹기 위해 일반적으로 상태값을 갖는 전역변수를 예를 든다.
State state;

void print_state(void) {
    printf("Current State = %d", state.current_state);
    printf("Prev State = %d", state.prev_state);
}

// 상태 전이 함수.  이 함수를 테스트 케이스에서 검증할 것이다.
void go_next_state(void) {
    state.prev_state = state.current_state;
    state.current_state++;
}