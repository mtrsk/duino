#include "led.hpp"
#include <Arduino.h>

Led::Led(byte pin) { this->pin = pin; }

void Led::init() {
  Serial.println("Initializing LED");
  pinMode(pin, OUTPUT);
}

byte Led::read() {
  this->value = digitalRead(pin);
  return (this->value);
}

void Led::on() {
  digitalWrite(pin, HIGH);
  this->value = HIGH;
}

void Led::off() {
  digitalWrite(pin, HIGH);
  this->value = LOW;
}

void Led::reverse() {
  if (this->value == HIGH) {
    Serial.println("LED is being turned off...");
    off();
  } else {
    Serial.println("LED is being turned on...");
    on();
  }
}

void Led::set(byte value) {
  analogWrite(pin, value);
  this->value = value;
}

