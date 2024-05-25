#ifndef STATE_HPP
#define STATE_HPP

#include "led.hpp"
#include "potentiometer.hpp"
#include "push_button.hpp"

void state_init(Led &builtin, Led &red, Led &yellow, Led &green,
                PushButton &button, Potentiometer &potentiometer);

#endif
