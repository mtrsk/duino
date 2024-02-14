#include "push_button.hpp"
#include <Arduino.h>

PushButton::PushButton(byte pin) { this->pin = pin; };

void PushButton::init() { pinMode(pin, INPUT); };

byte PushButton::read() {
  this->state = digitalRead(pin);
  return state;
};

bool PushButton::isPressed() {
  return (state == HIGH);
};
