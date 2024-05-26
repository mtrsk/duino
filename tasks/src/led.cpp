#include "led.hpp"
#include <Arduino.h>

Led::Led(byte pin, const char* name) {
  this->pin = pin;
  this->name = name;
}

void Led::init() {
  Serial.print(this->name);
  Serial.println(" LED is being setup...");
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
}

byte Led::read() {
  this->value = digitalRead(pin);
  return (this->value);
}

void Led::on() {
  Serial.print(this->name);
  Serial.println(" LED is being turned on...");
  digitalWrite(pin, HIGH);
  this->value = HIGH;
}

void Led::off() {
  Serial.print(this->name);
  Serial.println(" LED is being turned off...");
  digitalWrite(pin, HIGH);
  this->value = LOW;
}

void Led::reverse() {
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
