#include "events/button_pressed.hpp"

ButtonPressedEvent::ButtonPressedEvent(Led led, PushButton button) {
  this->led = led;
  this->button = button;
}

void ButtonPressedEvent::exec() {
  if (this->button.isPressed()) {
    state_update_led_digital(this->led);
  };
};

uint32_t ButtonPressedEvent::timeOfNextCheck() {
  return 1000L;
};

