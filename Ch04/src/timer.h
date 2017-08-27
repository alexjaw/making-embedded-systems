#ifndef _TIMER_H
#define _TIMER_H

/* TODO:
*  - How can this timer module be used for more than one timer?
*    Do I need to define my own timer struct that is provided to the module?
*    led_timer.c will then create its timer struct and pass it to the timer
*    so that it handles the correct timer registers used by led_timer.
*  
*  For ref see code examples in 
*  http://www.microchip.com//wwwAppNotes/AppNotes.aspx?appnote=en591816
*  There much of the examples are using TCC0. For XMEGAE that is instead
*  TCC4, TCC5 or TCD5.
*
*  The Period (PER) register sets the TOP value for the counter, 
*  i.e. how far it will count
*  TCC4.PER = 0x30;   //Could have used TCC5 or TCD5
*  
*  The CLKSEL bits in CTRLA is used to set the clock source for the counter
*  Use x_CLKSEL_gm where x is TC4, TC5 (TCD5 is a TC5 counter).
*  Use TC_CLKSEL_DIVx_gc, where x is the div that is appropriate for your
*  application.
*  TCC4.CTRLA = ( TCC4.CTRLA & ~TC4_CLKSEL_gm ) | TC_CLKSEL_DIV1_gc;  // Start Timer with no prescaling
*
*  Counter is finishhed when
*  TCC4.INTFLAGS & TC4_OVFIF_bm) != 0
*/

void timer_set_frequency(float frq);
void timer_start(void);
void timer_stop(void);
void timer_reset(void);
//void timer_init(void); //TODO:

#endif // _TIMER_H
