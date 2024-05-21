#ifndef STATE_HPP
#define STATE_HPP

#include "led.hpp"
#include "potentiometer.hpp"
#include "push_button.hpp"
#include <Arduino.h>
#include <TaskManagerIO.h>

typedef struct {
  Led &red;
  Led &green;
  Led &yellow;
  PushButton &button;
  Potentiometer &potentiometer;
} State;

// Function prototypes
// LED PROTOTYPES
void state_init(State &state);
void state_idle(State &state);

void state_update_red_led(State &state);
void state_update_green_led(State &state);
void state_update_yellow_led(State &state);

// BUTTON PROTOTYPES
void state_press_button(State &state);

// POTENTIOMETER PROTOTYPES
void state_change_potentiometer(State &state);

// Events
class ButtonPressed : public BaseEvent {
private:
  State *st;

public:
  ButtonPressed(State st);
  void exec() override;
  uint32_t timeOfNextCheck() override;
};

#endif
