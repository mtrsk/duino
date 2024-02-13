#include "push_button.hpp"
#include <Arduino.h>

PushButton::PushButton(byte pin) { this->pin = pin; };

void PushButton::init() { pinMode(pin, INPUT_PULLUP); };

byte PushButton::readState() {
  this->state = digitalRead(pin);
  return state;
};
