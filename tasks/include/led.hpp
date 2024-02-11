#ifndef LED_HPP
#define LED_HPP

#include <Arduino.h>

class Led {
private:
  byte pin;

public:
  Led(byte pin);

  void init();

  byte read();

  void on();

  void off();
};

#endif
