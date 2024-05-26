#ifndef LED_HPP
#define LED_HPP

#include <Arduino.h>

class Led {
private:
  byte pin;
  byte value;
  const char* name;

public:
  Led(byte pin, const char* name);

  void init();

  byte read();

  void on();

  void off();

  void reverse();

  // Only use this with Analog pins
  void set(byte value);
};

#endif
