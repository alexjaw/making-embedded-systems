#ifndef _IOPINS_H
#define _IOPINS_H
#include <stdbool.h>
#include "ioMapping.h"

enum {PIN_MIN = 0, PIN_MAX = 7}; 

void IOInit(volatile uint8_t * reg_dir, volatile uint8_t * reg_io);
void IOSetDir(volatile uint8_t * port, uint8_t pin, bool isOutput);
/* What should be configured in the header and what should be configured in IO-functions?:*/
//void IOConfigureInterrupt(volatile uint8_t * port, uint8_t pin, uint8_t trigger_type, uint8_t trigger_state);
void IOInterruptEnable(volatile uint8_t * port, uint8_t pin);
void IOInterruptDisable(volatile uint8_t * port, uint8_t pin);
//
void IOSet(volatile uint8_t * port, uint8_t pin);
void IOClear(volatile uint8_t * port, uint8_t pin);
void IOToggle(volatile uint8_t * port, uint8_t pin);
bool IOGet(volatile uint8_t port, uint8_t pin);
#endif // _IOPINS_H
