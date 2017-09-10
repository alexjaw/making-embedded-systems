#include "led_pwm.h"
#include "timer.h"

void led_pwm_set_brightness(uint8_t brightness)
{
    /* brightness: 0-100% */
    timer_set_simple_pwm(brightness);
}
