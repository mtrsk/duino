#include <Arduino.h>
#include "constants.hpp"
#include "led.hpp"
#include "push_button.hpp"
#include "state.hpp"

// Global variables
PushButton button(BUTTON_PIN);
Led led(LED_BUILTIN);

State state = State::Init;

void setup() {
  state_init();
  button.init();
  led.init();
  state = State::Idle;
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(5000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(5000);
}

