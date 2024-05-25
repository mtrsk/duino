#ifndef BUTTON_PRESSED_HPP
#define BUTTON_PRESSED_HPP

#include "led.hpp"
#include "push_button.hpp"
#include "state.hpp"
#include <TaskManagerIO.h>

class ButtonPressedEvent : public BaseEvent {
private:
  Led &led;
  PushButton &button;

public:
  ButtonPressedEvent(Led led, PushButton button);
  void exec() override;
  uint32_t timeOfNextCheck() override;
};

#endif
