#include "state.hpp"
#include "constants.hpp"
#include "led.hpp"
#include "potentiometer.hpp"
#include "push_button.hpp"
#include <Arduino.h>

// STATE FUNCTIONS
// Initialization of the whole system
void state_init(Led &builtin, Led &red, Led &yellow, Led &green,
                PushButton &button, Potentiometer &potentiometer) {
  Serial.begin(SERIAL_BAUD_RATE);
  Serial.setTimeout(10);
  builtin.init();
  red.init();
  green.init();
  yellow.init();
  button.init();
  potentiometer.init();
};
