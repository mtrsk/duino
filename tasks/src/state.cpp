#include "state.hpp"
#include "constants.hpp"
#include "led.hpp"
#include "push_button.hpp"
#include <Arduino.h>

// STATE FUNCTIONS
// Initialization of the whole system
void state_init(State &state) {
  Serial.begin(SERIAL_BAUD_RATE);
  Serial.setTimeout(10);
  state.button.init();
  state.red.init();
  state.green.init();
  state.yellow.init();
};

// Doing nothing
void state_idle(State &state) { Serial.println("Idle..."); };

// RED LED
void state_update_red_led(State &state) {
  if (state.red.read() == HIGH) {
    Serial.println("Red LED is being turned off...");
    state.red.off();
  } else {
    Serial.println("Red LED is being turned on...");
    state.red.on();
  }
};

// GREEN LED
void state_update_green_led(State &state) {
  if (state.green.read() == HIGH) {
    Serial.println("Green LED is being turned off...");
    state.green.off();
  } else {
    Serial.println("Green LED is being turned on...");
    state.green.on();
  }
};

// YELLOW LED
void state_update_yellow_led(State &state) {
  // TODO: Implement this
  state.yellow.on();
  Serial.println("YELLOW LED is ON...");
};

// Events
void ButtonPressed::exec() {
  Serial.println("TODO...");
  state_update_red_led(*st);
};

uint32_t ButtonPressed::timeOfNextCheck() {
  Serial.println("TODO...");
  return millisToMicros(1000);
};

ButtonPressed::ButtonPressed(State st) { this->st = &st; }
