#ifndef STATE_HPP
#define STATE_HPP

#include "led.hpp"
#include "potentiometer.hpp"
#include "push_button.hpp"
#include <Arduino.h>
#include <TaskManagerIO.h>

// Function prototypes
// LED PROTOTYPES
void state_init(Led &red, Led &yellow, Led &green, PushButton &button, Potentiometer &potentiometer);
void state_idle();

void state_update_led_digital(Led &led);
void state_update_led_analog(Led &led);

// BUTTON PROTOTYPES
void state_press_button(PushButton &button);

// POTENTIOMETER PROTOTYPES
void state_change_potentiometer(Potentiometer &potentiometer);

// Events
class ButtonPressedEvent : public BaseEvent {
private:
  Led &led;

public:
  ButtonPressedEvent(Led led);
  void exec() override;
  uint32_t timeOfNextCheck() override;
};

#endif
