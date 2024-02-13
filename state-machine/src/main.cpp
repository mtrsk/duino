#include <Arduino.h>
#include "constants.hpp"
#include "led.hpp"
#include "push_button.hpp"
#include "state.hpp"

// STATE -> EVENT -> STATE
const Command transitions[] = {
  {State::Init, Event::Started, State::Idle},
  {State::Idle, Event::ButtonPushed, State::LedOn},
  {State::LedOn, Event::LedChanged, State::LedOff},
  {State::LedOff, Event::LedChanged, State::LedOn},
};

// STATE x FUNCTION
static Update updates[] = {
  { State::Init, &state_init },
  { State::Idle, &state_idle },
  { State::LedOn, &state_led_on },
  { State::LedOff, &state_led_off },
};

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
  run(state, event, transitions, updates);
}

