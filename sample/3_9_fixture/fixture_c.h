// fixture_c.h
typedef struct _State {
    int current_state;
    int prev_state;
} State;

extern State state;

void go_next_state(void);