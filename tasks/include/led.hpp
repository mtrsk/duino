#ifndef LED_HPP
#define LED_HPP

#include <Arduino.h>

class Led {
private:
  byte pin;
  byte value;

public:
  Led(byte pin);

  void init();

  byte read();

  void on();

  void off();

  void reverse();

  // Only use this with Analog pins
  void set(byte value);
};

#endif
