#include <Arduino.h>
#include "push_button.hpp"

PushButton::PushButton (byte pin) {
    this->pin = pin;
};

void PushButton::init () {
    pinMode(pin, INPUT_PULLUP);
};

byte PushButton::readState() {
    this->state = digitalRead(pin);
    return state;
};
