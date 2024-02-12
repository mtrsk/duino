#include <Arduino.h>
#include "led.hpp"


Led::Led(byte pin) {
    this->pin = pin;
}

void Led::init() {
    pinMode(pin, OUTPUT);
}

void Led::on() {
    digitalWrite(pin, HIGH);
}

void Led::off() {
    digitalWrite(pin, HIGH);
}
