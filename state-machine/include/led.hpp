#ifndef LED_HPP
#define LED_HPP

#include <Arduino.h>

class Led {
private:
  byte pin;

public:
  Led(byte pin);

  void init();

  void on();

  void off();
};

#endif
