#ifndef STATE_HPP
#define STATE_HPP

// The states the system can be in
enum class State {
    Init,
    Idle,
    LedOn,
    LedOff,
};

// Events that can trigger state transitions
enum class Event {
    Start,
    ButtonPushed,
    PotentiometerChanged,
    LedChanged,
};

// Structure to represent a state transition,
// via commands.
// OLD STATE -> EVENT -> NEW STATE
typedef struct {
    State curr;
    Event event;
    State next;
} Command;

// Structure to map a state to a corresponding
// function that triggers a state update.
typedef struct {
    State state;
    void (*func)(void);
} Update;

// Function prototypes
void state_init();
void state_idle();
void state_led_on();
void state_led_off();

#endif
