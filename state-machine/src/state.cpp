#include <Arduino.h>
#include "constants.h"
#include "state.h"

// INIT FUNCTIONS
void led_init() {
  digitalWrite(LED_BUILTIN, HIGH);
};

// STATE -> EVENT -> STATE
static Command commands[] = {
    { State::Init, Event::Any, State::Idle }
};

// STATE -> FUNCTION
static Decider decisions[] = {
    { State::Init, &led_init },
};
