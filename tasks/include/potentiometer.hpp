#ifndef POTENTIOMETER_HPP
#define POTENTIOMETER_HPP

#include <Arduino.h>

class Potentiometer {
private:
  byte pin;
  byte state;
  unsigned long lastUpdatedAt;
  unsigned long debounceDelay;

public:
  Potentiometer(byte pin);

  void init();

  byte read();

  bool changed();
};

#endif
