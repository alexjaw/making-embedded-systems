#include "unity.h"
#include "led_pwm.h"
#include "mock_timer.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_set_brightness(void)
{
    timer_set_simple_pwm_Expect(42);
    led_pwm_set_brightness(42);
}

void test_led_pwm_NeedToImplement(void)
{
    TEST_IGNORE_MESSAGE("Need to Implement led_pwm");
}
