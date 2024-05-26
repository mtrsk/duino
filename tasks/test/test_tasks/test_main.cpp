#include <Arduino.h>
#include <unity.h>

void setUp(void)
{
  // set stuff up here
}

void tearDown(void)
{
}

void test_initialization_pins(void)
{
  //TEST_ASSERT_EQUAL(12, LED_RED_PIN);
  //TEST_ASSERT_EQUAL(11, LED_YELLOW_PIN);
  //TEST_ASSERT_EQUAL(10, LED_GREEN_PIN);
}

void setup()
{
  // NOTE!!! Wait for >2 secs
  // if board doesn't support software reset via Serial.DTR/RTS
  delay(2000);

  pinMode(LED_BUILTIN, OUTPUT);

  UNITY_BEGIN(); // IMPORTANT LINE!
  RUN_TEST(test_initialization_pins);
}

uint8_t i = 0;
uint8_t max_blinks = 5;

void loop()
{
  if (i < max_blinks)
  {
    //RUN_TEST(test_led_state_high);
    //delay(500);
    //RUN_TEST(test_led_state_low);
    //delay(500);
    i++;
  }
  else if (i == max_blinks)
  {
    UNITY_END(); // stop unit testing
  }
}
