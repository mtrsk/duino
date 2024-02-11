#include "constants.hpp"
#include "led.hpp"
#include "potentiometer.hpp"
#include "push_button.hpp"
#include "state.hpp"
#include <Arduino.h>
#include <TaskManagerIO.h>

// Global variables
PushButton button(BUTTON_PIN);
Potentiometer potentiometer(POTENTIOMETER_PIN);
Led red(LED_RED_PIN);
Led yellow(LED_YELLOW_PIN);
Led green(LED_GREEN_PIN);

State state = {.red = red,
               .green = green,
               .yellow = yellow,
               .button = button,
               .potentiometer = potentiometer};

// Arduino Program
void setup() {
  Serial.println("Starting Arduino...");
  state_init(state);
  taskManager.schedule(repeatSeconds(1), []() { state_update_red_led(state); });
}

void loop() { taskManager.runLoop(); }
