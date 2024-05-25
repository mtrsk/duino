#include "events/potentiometer_updated.hpp"

PotentiometerUpdatedEvent::PotentiometerUpdatedEvent(
    Led led, Potentiometer potentiometer) {
  this->led = led;
  this->potentiometer = potentiometer;
}

void PotentiometerUpdatedEvent::exec() {
  if (this->potentiometer.changed()) {
    byte value = (this->potentiometer).read() / 4;
    (this->led).set(value);
  };
};

uint32_t PotentiometerUpdatedEvent::timeOfNextCheck() {
  return DEFAULT_EVENT_WAITING_IN_MS;
};
