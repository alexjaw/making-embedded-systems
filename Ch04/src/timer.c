#include "timer.h"
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

/* 2Mhz default xmega freq with prescaler set at 1024*/
static uint8_t PRESCALER_1024 = TC_CLKSEL_DIV1024_gc;
static const PER_1HZ = 0x03d1;

void timer_init(void)
{
    TCC4.CTRLA = ( TCC4.CTRLA & ~TC4_CLKSEL_gm ) | PRESCALER_1024;
}

void timer_set_frequency_1_hz(void)
{
    /* The Period (PER) register (32bit) sets the TOP value for the counter, 
	* i.e. how far it will count
	* 1MHz clock with prescaler 1024 ticks 1E6/1024 = 977 (976.56...) times per
	* second (1 tick every 1024ms). For 1 Hz this means that we change state
	* when PER counter has reached half the value, i.e 488 = 0x01E8.
	* 2MHz clock with prescaler 1024 ticks 2E6/1024 = 1953 times per second.
	* PER counter = 977 = 0x03d1.
	* 32Mhz: PER = 0x3d09
	*/
	TCC4.PER = PER_1HZ;
}
