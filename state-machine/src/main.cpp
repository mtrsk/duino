#include <Arduino.h>
#include "constants.hpp"
#include "led.hpp"
#include "push_button.hpp"
#include "state.hpp"

// Global variables
PushButton button(BUTTON_PIN);
Led led(LED_BUILTIN);

State state = State::Init;
Event event = Event::Started;

void setup() {
  state_init();
  button.init();
  led.init();
}

void loop() {
}

