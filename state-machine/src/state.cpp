#include "state.hpp"
#include "constants.hpp"
#include "led.hpp"
#include "push_button.hpp"
#include <Arduino.h>

// STATE FUNCTIONS
// Initialization of the whole system
void state_init(PushButton &button, Led &led) {
  Serial.begin(SERIAL_BAUD_RATE);
  Serial.println("Starting Arduino...");
  Serial.setTimeout(10);
  button.init();
  led.init();
};

// Doing nothing
void state_idle() { Serial.println("Idle..."); };

// Some LED is turned ON
void state_led_turned_on() {
  Serial.println("LED is on...");
  digitalWrite(LED_BUILTIN, HIGH);
};

// Some LED is turned OFF
void state_led_turned_off() {
  Serial.println("LED is off...");
  digitalWrite(LED_BUILTIN, LOW);
};

// State Machine
void run(State &state, Event &event, const Command *transitions,
         size_t transitions_size, const Update *updates, size_t updates_size) {
  for (size_t i = 0; i < transitions_size; ++i) {
    if (transitions[i].curr == state && transitions[i].event == event) {
      // Transition to the next state
      state = transitions[i].next;
      break;
    }
  }

  // Execute the corresponding action for the current state
  for (size_t i = 0; i < updates_size; ++i) {
    if (updates[i].state == state) {
      updates[i].func();
      break;
    }
  }
};
