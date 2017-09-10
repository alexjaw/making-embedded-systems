#ifndef _TIMER_H
#define _TIMER_H

void timer_init(void);
void timer_set_frequency_1_hz(void);
void timer_start(void);
void timer_stop(void);
void timer_reset(void);
void timer_pwm_init(void);
void timer_set_simple_pwm(uint8_t duty);
void timer_pwm_start(void);
void timer_pwm_stop(void);

#endif // _TIMER_H
