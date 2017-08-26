#include "led_timer.h"
#include "timer.h"

void led_timer_set_frequency(float frq)
{
    timer_set_frequency(frq);
}
