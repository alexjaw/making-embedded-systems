#ifndef _LED_H
#define _LED_H
#include "ioMapping.h"

#if COMPILING_FOR_XPLAINED_XMEGA32E5       /******** XPLAINED_XMEGA32E5 ********/
#define LED_SET_DIRECTION  PORTA_DIR       //Reg defining if port is in or out
#define LED_REGISTER       PORTA_OUT       //Reg holding port data

#elif TEST                                 /************ TESTS *****************/  
volatile uint8_t LED_SET_DIRECTION;
volatile uint8_t LED_REGISTER;
#else
#error "No I/O map selected for the board. What is your target?"
#endif /* COMPILING_FOR_XPLAINED_XMEGA32E5 */

                                           /************* ALL ******************/
#define LED_PIN            4               //This is used
#define LED_BIT            (1 << LED_PIN)  //Not used, is included since it is in the book
#define ISOUT              1               //Defines port pin as output. If input, ISOUT 0

void LEDInit();
void LEDBlink();

#endif // _LED_H
