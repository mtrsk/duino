#include "constants.hpp"
#include "led.hpp"
#include "push_button.hpp"
#include "state.hpp"
#include <Arduino.h>

// STATE -> COMMAND -> STATE
const Transition transitions[] = {
    {State::Init, Command::Start, State::Idle},
    {State::Idle, Command::PushButton, State::LedOn},
    {State::LedOn, Command::AlterLed, State::LedOff},
    {State::LedOff, Command::AlterLed, State::LedOn},
};
constexpr size_t transitions_size = sizeof(transitions) / sizeof(transitions[0]);

// STATE x FUNCTION
const Update updates[] = {
    {State::Init, &state_init},
    {State::Idle, &state_idle},
    {State::LedOn, &state_led_turned_on},
    {State::LedOff, &state_led_turned_off},
};
constexpr size_t updates_size = sizeof(updates) / sizeof(updates[0]);

// Global variables
PushButton button(BUTTON_PIN);
Led led(LED_BUILTIN);

State state = State::Init;
Command command = Command::Start;

void setup() {
  state_init(button, led);
}

void loop() {
  run(state, command, transitions, transitions_size, updates, updates_size);
}
