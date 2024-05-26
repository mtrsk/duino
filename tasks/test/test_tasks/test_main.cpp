// Local libs
#include <constants.hpp>
#include <led.hpp>

// Third-party
#include <Arduino.h>
#include <unity.h>

Led *red;
Led *yellow;
Led *green;

void setUp(void) {
  // set stuff up here
  red = new Led(LED_RED_PIN, names[1]);
  yellow = new Led(LED_YELLOW_PIN, names[2]);
  green = new Led(LED_GREEN_PIN, names[3]);
}

void tearDown(void) {
  delete red;
  delete yellow;
  delete green;
}

void test_initialization_pins(void) {
  TEST_ASSERT_EQUAL(12, LED_RED_PIN);
  TEST_ASSERT_EQUAL(11, LED_YELLOW_PIN);
  TEST_ASSERT_EQUAL(10, LED_GREEN_PIN);
  TEST_ASSERT_EQUAL(2, BUTTON_PIN);
  TEST_ASSERT_EQUAL(A2, POTENTIOMETER_PIN);
}

void test_initialization_leds_start_as_zero(void) {
  TEST_ASSERT_EQUAL(red->read(), LOW);
  TEST_ASSERT_EQUAL(yellow->read(), LOW);
  TEST_ASSERT_EQUAL(green->read(), LOW);
}

void setup() {
  // NOTE!!! Wait for >2 secs
  // if board doesn't support software reset via Serial.DTR/RTS
  delay(2000);

  pinMode(LED_BUILTIN, OUTPUT);

  UNITY_BEGIN(); // IMPORTANT LINE!
  RUN_TEST(test_initialization_pins);
  RUN_TEST(test_initialization_leds_start_as_zero);
}

uint8_t i = 0;
uint8_t max_blinks = 5;

void loop() {
  if (i < max_blinks) {
    // RUN_TEST(test_led_state_high);
    // delay(500);
    // RUN_TEST(test_led_state_low);
    // delay(500);
    i++;
  } else if (i == max_blinks) {
    UNITY_END(); // stop unit testing
  }
}
