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
  Serial.println("LED is being turned on...");
  digitalWrite(pin, HIGH);
  this->value = HIGH;
}

void Led::off() {
  Serial.println("LED is being turned off...");
  digitalWrite(pin, HIGH);
  this->value = LOW;
}

void Led::reverse() {
  Serial.println("SWITCHING LED...");
  if (this->value == HIGH) {
    off();
  } else {
    on();
  }
}

void Led::set(byte value) {
  analogWrite(pin, value);
  this->value = value;
}
