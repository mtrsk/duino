#include <Arduino.h>
#include "constants.hpp"
#include "state.hpp"

// STATE FUNCTIONS
// Initialization of the whole system
void state_init() {
  Serial.begin(SERIAL_BAUD_RATE);
  Serial.println("Starting Arduino...");
  Serial.setTimeout(10);
};

// Doing nothing
void state_idle() {
  Serial.println("Idle...");
};

// Some LED is turned ON
void state_led_turned_on(){
  Serial.println("LED is on...");
  digitalWrite(LED_BUILTIN, HIGH);
};

// Some LED is turned OFF
void state_led_turned_off(){
  Serial.println("LED is off...");
  digitalWrite(LED_BUILTIN, LOW);
};

// State Machine
void run(State &state, Event &event, const Command transitions[], const Update updates[]){
  for (size_t i = 0; i < sizeof(transitions) / sizeof(transitions[0]); ++i) {
    if (transitions[i].curr == state && transitions[i].event == event) {
      // Transition to the next state
      state = transitions[i].next;
      break;
    }
  }

  // Execute the corresponding action for the current state
  for (size_t i = 0; i < sizeof(updates) / sizeof(updates[0]); ++i) {
    if (updates[i].state == state) {
      updates[i].func();
      break;
    }
  }
};

