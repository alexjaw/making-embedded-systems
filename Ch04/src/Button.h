#ifndef _BUTTON_H
#define _BUTTON_H
#include "ioMapping.h"
#include <stdbool.h>

#if COMPILING_FOR_XPLAINED_XMEGA32E5       /******** XPLAINED_XMEGA32E5 ********/
#define BTN_SET_DIRECTION  PORTD.DIR       //Reg defining if port is in or out
#define BTN_REGISTER       PORTD.IN        //Reg holding port data
                                           //for xmega interrupts see http://www.atmel.com/images/doc8043.pdf
BTNPORT.PIN2CTRL = PORT_ISC_RISING_gc;     //1.Set type
#define BTN_INTERRUPT      PORTD.INTMASK   //2.Used with IO handler to enable/disable pin interrupts
//BTNPORT.INTMASK |= BTNMASK;              //  In practice, this enables pin interrupt
BTNPORT.INTCTRL = PORT_INTLVL_LO_gc;       //3.Set prio
PMIC.CTRL = PMIC_LOLVLEN_bm;               //4.Enable interrupt controller
                                           //5.Enable interrupts globally with sei()

#elif TEST                                 /************ TESTS *****************/  
volatile uint8_t BTN_SET_DIRECTION;
volatile uint8_t BTN_REGISTER;
volatile uint8_t BTN_INTERRUPT;
#else
#error "No I/O map selected for the board. What is your target?"
#endif /* COMPILING_FOR_XPLAINED_XMEGA32E5 */

                                           /************* ALL ******************/
#define BTN_PIN            0               //This is used
#define LED_BIT            (1 << BTN_PIN)  //Not used, is included since it is in the book
#define ISOUT              0               //Defines port pin as output. If input, ISOUT 0

void ButtonInit();
bool ButtonPressed();
#endif // _BUTTON_H
