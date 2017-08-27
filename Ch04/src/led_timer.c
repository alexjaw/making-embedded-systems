#include "led_timer.h"
#include "timer.h"

void led_timer_set_frequency(float frq)
{
    timer_set_frequency(frq);
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

