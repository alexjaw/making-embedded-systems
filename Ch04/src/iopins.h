#ifndef _IOPINS_H
#define _IOPINS_H
#include "ioMapping.h"
#include <stdbool.h>

#if COMPILING_FOR_XPLAINED_XMEGA32E5       /******** XPLAINED_XMEGA32E5 ********/
#define REG_DIR  PORTA_DIR                 //Reg defining if port is in or out
#define REG_IO   PORTA_OUT                 //Reg holding port data

#elif TEST                                 /************ TESTS *****************/  
volatile uint8_t REG_DIR;
volatile uint8_t REG_IO;
#else
#error "No I/O map selected for the board. What is your target?"
#endif /* COMPILING_FOR_XPLAINED_XMEGA32E5 */

                                           /************* ALL ******************/
//#define PIN                4               //This is used
//#define BIT                (1 << PIN)      //Not used, is included since it is in the book
//#define ISOUT              1               //Defines port pin as output. If input, ISOUT 0

enum {PIN_MIN = 0, PIN_MAX = 7};

void IOInit(volatile uint8_t * reg_dir, volatile uint8_t * reg_io);
void IOSetDir(volatile uint8_t * port, uint8_t pin, bool isOutput);
void IOSet(volatile uint8_t * port, uint8_t pin);
void IOClear(volatile uint8_t * port, uint8_t pin);
void IOToggle(volatile uint8_t * port, uint8_t pin);
bool IOGet(volatile uint8_t port, uint8_t pin);
#endif // _IOPINS_H
