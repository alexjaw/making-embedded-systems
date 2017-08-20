#ifndef _BUTTON_H
#define _BUTTON_H
#include "ioMapping.h"
#include <stdbool.h>

#if COMPILING_FOR_XPLAINED_XMEGA32E5       /******** XPLAINED_XMEGA32E5 ********/
#define BTN_SET_DIRECTION  PORTD.DIR       //Reg defining if port is in or out
#define BTN_REGISTER       PORTD.IN        //Reg holding port data

#elif TEST                                 /************ TESTS *****************/  
volatile uint8_t BTN_SET_DIRECTION;
volatile uint8_t BTN_REGISTER;
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
