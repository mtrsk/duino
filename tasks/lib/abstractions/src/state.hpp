#include <constants.hpp>
#include <led.hpp>
#include <potentiometer.hpp>
#include <push_button.hpp>

// Third-Party deps
#include <Arduino.h>

// Initialization of the whole system
void state_init(Led &builtin, Led &red, Led &yellow, Led &green,
                PushButton &button, Potentiometer &potentiometer);

