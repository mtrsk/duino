#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <Arduino.h>

#define LED_BUILTIN 13

#define LED_RED_PIN 12
#define LED_YELLOW_PIN 11
#define LED_GREEN_PIN 10

#define BUTTON_PIN 2

#define POTENTIOMETER_PIN A2

#define SERIAL_BAUD_RATE 115200

#define DEFAULT_EVENT_WAITING_IN_MS 1000L

static const char* names[] = {
  "BUILTIN",
  "RED",
  "YELLOW",
  "GREEN"
};

#endif
