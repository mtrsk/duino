#include "state.hpp"
#include "constants.hpp"
#include "led.hpp"
#include "push_button.hpp"
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

void state_idle() {
  Serial.println("Idle..."); 
};

// LED
void state_update_led_digital(Led &led) {
  if (led.read() == HIGH) {
    Serial.println("LED is being turned off...");
    led.off();
  } else {
    Serial.println("LED is being turned on...");
    led.on();
  }
};

// YELLOW LED
void state_update_led_analog(Led &led) {
  // TODO: Implement this
  Serial.println("LED is ON...");
};
