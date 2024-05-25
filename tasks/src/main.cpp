#include "constants.hpp"
#include "led.hpp"
#include "potentiometer.hpp"
#include "push_button.hpp"
#include "state.hpp"
#include "events/button_pressed.hpp"
#include "events/potentiometer_updated.hpp"
#include <Arduino.h>
#include <TaskManagerIO.h>

// Global variables
PushButton button(BUTTON_PIN);
Potentiometer potentiometer(POTENTIOMETER_PIN);
Led red(LED_RED_PIN);
Led yellow(LED_YELLOW_PIN);
Led green(LED_GREEN_PIN);

ButtonPressedEvent buttonPressed = ButtonPressedEvent(yellow, button);
PotentiometerUpdatedEvent potentiometerUpdated = PotentiometerUpdatedEvent(green, potentiometer);

// Arduino Program
void setup() {
  Serial.println("Starting Arduino...");
  state_init(red, yellow, green, button, potentiometer);

  taskManager.schedule(repeatSeconds(1), []() { red.reverse(); });
  taskManager.registerEvent(&buttonPressed);
  taskManager.registerEvent(&potentiometerUpdated);
}

void loop() { taskManager.runLoop(); }
