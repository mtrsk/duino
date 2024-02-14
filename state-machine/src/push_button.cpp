#include "push_button.hpp"
#include <Arduino.h>

PushButton::PushButton(byte pin) { this->pin = pin; };

void PushButton::init() {
  Serial.println("Initializing BUTTON");
  pinMode(pin, INPUT);
  this->state = digitalRead(pin);
};

void PushButton::read() {
  unsigned long now = millis();
  if ((now - lastUpdatedAt) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:
    byte reading = digitalRead(pin);

    // if the button state has changed:
    if (this->state != reading) {
      this->state = reading;
      this->lastUpdatedAt = now;
    }
  }
};

bool PushButton::isPressed() {
  PushButton::read();
  return (state == HIGH);
};
