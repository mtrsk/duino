#ifndef STATE_HPP
#define STATE_HPP

#include "led.hpp"
#include "potentiometer.hpp"
#include "push_button.hpp"

// State PROTOTYPES
void state_init(Led &red, Led &yellow, Led &green, PushButton &button, Potentiometer &potentiometer);
void state_idle();

// LED PROTOTYPES
void state_update_led_digital(Led &led);
void state_update_led_analog(Led &led);

// BUTTON PROTOTYPES
void state_press_button(PushButton &button);

// POTENTIOMETER PROTOTYPES
void state_change_potentiometer(Potentiometer &potentiometer);

#endif
