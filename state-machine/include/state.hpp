#ifndef STATE_HPP
#define STATE_HPP

#include "led.hpp"
#include "push_button.hpp"
#include <Arduino.h>

// The states the system can be in
enum class State {
  Init,
  Idle,
  LedOn,
  LedOff,
};

// Events that can trigger state transitions
enum class Event {
  Started,
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
// STATE PROTOTYPES
void state_init(PushButton &button, Led &led);
void state_idle();
void state_led_turned_on();
void state_led_turned_off();

// The State Machine
void run(State &state, Event &event, const Command *transitions,
         size_t transitions_size, const Update *updates, size_t updates_size);

#endif
