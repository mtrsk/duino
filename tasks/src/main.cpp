#include "constants.hpp"
#include "events/button_pressed.hpp"
#include "events/potentiometer_updated.hpp"
#include "led.hpp"
#include "potentiometer.hpp"
#include "push_button.hpp"
#include "state.hpp"
#include <Arduino.h>
#include <TaskManagerIO.h>

// Global variables
static const char* names[] = {
  "BUILTIN",
  "RED",
  "YELLOW",
  "GREEN"
};

PushButton button(BUTTON_PIN);
Potentiometer potentiometer(POTENTIOMETER_PIN);
Led builtin(LED_BUILTIN, names[0]);
Led red(LED_RED_PIN, names[1]);
Led yellow(LED_YELLOW_PIN, names[2]);
Led green(LED_GREEN_PIN, names[3]);

ButtonPressedEvent buttonPressed = ButtonPressedEvent(yellow, button);
PotentiometerUpdatedEvent potentiometerUpdated =
    PotentiometerUpdatedEvent(green, potentiometer);

// Arduino Program
void setup() {
  Serial.println("Starting Arduino...");
  state_init(builtin, red, yellow, green, button, potentiometer);

  taskManager.schedule(repeatMillis(2500), []() { builtin.reverse(); });
  taskManager.schedule(repeatSeconds(1), []() { red.reverse(); });
  taskManager.registerEvent(&buttonPressed);
  taskManager.registerEvent(&potentiometerUpdated);
}

void loop() { taskManager.runLoop(); }
