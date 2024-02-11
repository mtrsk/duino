enum class State {
    Init,
    Idle,
    LedOn,
    LedOff,
};

enum class Event {
    Any,
    None,
    ButtonPressed,
    LedChanged,
};

typedef struct {
    State curr;
    Event event;
    State next;
} Command;

typedef struct {
    State state;
    void (*func)(void);
} Decider;

void led_init();
