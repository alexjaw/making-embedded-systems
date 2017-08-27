/*
* Functionality:
* Using the button to change the blinking speed was helpful, but marketing has
* found a problem in the uncertainty introduced into the blink rate. Instead of
* cutting the speed of the LED in half, they want to use the button to cycle
* through a series of precise blink rates: 6.5 times per second (Hz), 8.5 Hz, and
* 10 Hz.
*
* (reminder <math.h> will take some chip memory)
*
* Tests:
* - led_timer_set_frequency(float frq)...
* - led_timer_start()
* - led_timer_stop()
* - led_timer_reset()
* - led_timer_init()
*/

#include "unity.h"
#include "led_timer.h"
#include "mock_timer.h"

const float LOW_FRQ_HZ = 6.5; 

void setUp(void)
{
}

void tearDown(void)
{
}

void test_led_timer_set_frequency(void)
{
    timer_set_frequency_Expect(LOW_FRQ_HZ);
    led_timer_set_frequency(LOW_FRQ_HZ);
}

void test_led_timer_start(void)
{
    timer_start_Expect();
    led_timer_start();
}

void test_led_timer_stop(void)
{
    timer_stop_Expect();
    led_timer_stop();
}

void test_led_timer_reset(void)
{
    timer_reset_Expect();
    led_timer_reset();
}

void test_led_timer_NeedToImplement(void)
{
    TEST_IGNORE_MESSAGE("Need to Implement led_timer");
}
