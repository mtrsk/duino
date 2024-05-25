#include "events/button_pressed.hpp"

ButtonPressedEvent::ButtonPressedEvent(Led led, PushButton button) {
  this->led = led;
  this->button = button;
}

void ButtonPressedEvent::exec() {
  if (this->button.isPressed()) {
    this->led.reverse();
  };
};

uint32_t ButtonPressedEvent::timeOfNextCheck() {
  return DEFAULT_EVENT_WAITING_IN_MS;
};
