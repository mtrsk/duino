#include "potentiometer.hpp"
#include <Arduino.h>

Potentiometer::Potentiometer(byte pin) { this->pin = pin; };

void Potentiometer::init() {
  Serial.println("Initializing POTENTIOMETER");
  pinMode(pin, INPUT);
  this->state = analogRead(pin);
};

byte Potentiometer::read() {
  unsigned long now = millis();
  if ((now - lastUpdatedAt) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:
    byte reading = analogRead(pin);

    // if the button state has changed:
    if (this->state != reading) {
      this->state = reading;
      this->lastUpdatedAt = now;
    }
  }
  return this->state;
};

bool Potentiometer::changed() {
  byte oldState = this->state;
  Potentiometer::read();
  return (state != oldState);
};
