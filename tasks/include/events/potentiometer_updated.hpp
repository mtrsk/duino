#ifndef POTENTIOMETER_UPDATED_HPP
#define POTENTIOMETER_UPDATED_HPP

#include "constants.hpp"
#include "led.hpp"
#include "potentiometer.hpp"
#include "push_button.hpp"
#include <TaskManagerIO.h>

class PotentiometerUpdatedEvent : public BaseEvent {
private:
  Led &led;
  Potentiometer &potentiometer;

public:
  PotentiometerUpdatedEvent(Led led, Potentiometer potentiometer);
  void exec() override;
  uint32_t timeOfNextCheck() override;
};

#endif
