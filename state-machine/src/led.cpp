#include "led.hpp"
#include <Arduino.h>

Led::Led(byte pin) { this->pin = pin; }

void Led::init() { pinMode(pin, OUTPUT); }

void Led::on() { digitalWrite(pin, HIGH); }

void Led::off() { digitalWrite(pin, HIGH); }
