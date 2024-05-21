#include "led.hpp"
#include <Arduino.h>

Led::Led(byte pin) { this->pin = pin; }

void Led::init() {
  Serial.println("Initializing LED");
  pinMode(pin, OUTPUT);
}

byte Led::read() { return digitalRead(pin); }

void Led::on() { digitalWrite(pin, HIGH); }

void Led::off() { digitalWrite(pin, HIGH); }
