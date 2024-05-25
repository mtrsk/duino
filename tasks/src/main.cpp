#include "constants.hpp"
#include "led.hpp"
#include "potentiometer.hpp"
#include "push_button.hpp"
#include "state.hpp"
#include "events/button_pressed.hpp"
#include <Arduino.h>
#include <TaskManagerIO.h>

// Global variables
PushButton button(BUTTON_PIN);
Potentiometer potentiometer(POTENTIOMETER_PIN);
Led red(LED_RED_PIN);
Led yellow(LED_YELLOW_PIN);
Led green(LED_GREEN_PIN);

ButtonPressedEvent buttonPressed = ButtonPressedEvent(red, button);

// Arduino Program
void setup() {
  Serial.println("Starting Arduino...");
  state_init(red, yellow, green, button, potentiometer);

  taskManager.schedule(repeatSeconds(1), []() { state_update_led_digital(red); });
  taskManager.registerEvent(&buttonPressed);
}

void loop() { taskManager.runLoop(); }
