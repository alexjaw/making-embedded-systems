#include "led_timer.h"
#include "timer.h"

void led_timer_set_frequency_1_hz()
{
    timer_set_frequency_1_hz();
}

void led_timer_start(void)
{
    timer_start();
}

void led_timer_stop(void)
{
    timer_stop();
}

void led_timer_reset(void)
{
    timer_reset();
}

