#include "state.hpp"
#include "constants.hpp"
#include "led.hpp"
#include "push_button.hpp"
#include "potentiometer.hpp"
#include <Arduino.h>

// STATE FUNCTIONS
// Initialization of the whole system
void state_init(Led &red, Led &yellow, Led &green, PushButton &button, Potentiometer &potentiometer) {
  Serial.begin(SERIAL_BAUD_RATE);
  Serial.setTimeout(10);
  red.init();
  green.init();
  yellow.init();
  button.init();
  potentiometer.init();
};
