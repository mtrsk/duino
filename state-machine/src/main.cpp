#include "constants.hpp"
#include "led.hpp"
#include "push_button.hpp"
#include "state.hpp"
#include <Arduino.h>

// STATE -> EVENT -> STATE
inline Command transitions[] = {
    {State::Init, Event::Started, State::Idle},
    {State::Idle, Event::ButtonPushed, State::LedOn},
    {State::LedOn, Event::LedChanged, State::LedOff},
    {State::LedOff, Event::LedChanged, State::LedOn},
};
const size_t transitions_size = sizeof(transitions) / sizeof(transitions[0]);

// STATE x FUNCTION
inline Update updates[] = {
    {State::Init, &state_init},
    {State::Idle, &state_idle},
    {State::LedOn, &state_led_turned_on},
    {State::LedOff, &state_led_turned_off},
};
const size_t updates_size = sizeof(updates) / sizeof(updates[0]);

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
  run(state, event, transitions, transitions_size, updates, updates_size);
}
