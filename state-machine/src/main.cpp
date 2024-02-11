#include <Arduino.h>
#include "constants.h"
#include "led.h"
#include "push_button.h"
#include "state.h"

PushButton button(BUTTON_PIN);
Led led(LED_BUILTIN);

void setup() {
  Serial.begin(SERIAL_BAUD_RATE);
  Serial.println("Starting Arduino...");
  Serial.setTimeout(10);
  pinMode(LED_BUILTIN, OUTPUT);
  led_init();
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(5000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(5000);
}

