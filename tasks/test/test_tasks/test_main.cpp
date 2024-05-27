// Local libs
#include <constants.hpp>
#include <led.hpp>
#include <potentiometer.hpp>
#include <push_button.hpp>
#include <state.hpp>

// Third-party
#include <Arduino.h>
#include <TaskManagerIO.h>
#include <unity.h>

Led *builtin;
Led *red;
Led *yellow;
Led *green;
PushButton *button;
Potentiometer *potentiometer;

void setUp(void) {
  // set stuff up here
  builtin = new Led(LED_BUILTIN, names[0]);
  red = new Led(LED_RED_PIN, names[1]);
  yellow = new Led(LED_YELLOW_PIN, names[2]);
  green = new Led(LED_GREEN_PIN, names[3]);
  button = new PushButton(BUTTON_PIN);
  potentiometer = new Potentiometer(POTENTIOMETER_PIN);

  Serial.begin(SERIAL_BAUD_RATE);
  Serial.setTimeout(10);
  builtin->init();
  red->init();
  green->init();
  yellow->init();
  button->init();
  potentiometer->init();
}

void tearDown(void) {
  delete builtin;
  delete red;
  delete yellow;
  delete green;
  delete button;
  delete potentiometer;
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

void test_button_toggles_green_led_if_it_is_off(void) {
  // Check the LED
  TEST_ASSERT_EQUAL(green->read(), LOW);
  delay(100);
  // Press the button
  digitalWrite(BUTTON_PIN, HIGH);
  delay(100);
  // Check the LED
  TEST_ASSERT_EQUAL(green->read(), HIGH);
}

void test_button_turns_green_led_off_if_it_is_on(void) {
  // Check the LED
  TEST_ASSERT_EQUAL(green->read(), HIGH);
  // Release the button
  digitalWrite(BUTTON_PIN, LOW);
  // Check the LED
  TEST_ASSERT_EQUAL(green->read(), LOW);
}

void test_potentiometer_changes_yellow_led(void) {
  digitalWrite(POTENTIOMETER_PIN, LOW);
  // Check the LED
  TEST_ASSERT_EQUAL(yellow->read(), LOW);
  // Change potentiometer
  analogWrite(POTENTIOMETER_PIN, 1023);
  delay(100);
  // Check the LED
  TEST_ASSERT_EQUAL(yellow->read(), HIGH);
  delay(100);
  digitalWrite(POTENTIOMETER_PIN, LOW);
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
    RUN_TEST(test_button_toggles_green_led_if_it_is_off);
    delay(100);
    RUN_TEST(test_button_turns_green_led_off_if_it_is_on);
    delay(100);
    //RUN_TEST(test_potentiometer_changes_yellow_led);
    i++;
  } else if (i == max_blinks) {
    UNITY_END(); // stop unit testing
  }
}
