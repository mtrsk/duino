#ifndef PUSH_BUTTON_HPP
#define PUSH_BUTTON_HPP

#include <Arduino.h>

class PushButton {
private:
  byte pin;
  byte state;
  unsigned long lastUpdatedAt;
  unsigned long debounceDelay;

public:
  PushButton(byte pin);

  void init();

  void read();

  bool isPressed();
};

#endif
