#ifndef _IOPINS_H
#define _IOPINS_H
#include <stdint.h>
#include <stdbool.h>

enum {PIN_MIN = 0, PIN_MAX = 7};

void IOInit(volatile uint8_t * reg_dir, volatile uint8_t * reg_io);
void IOSetDir(volatile uint8_t * port, uint8_t pin, bool isOutput);
void IOSet(volatile uint8_t * port, uint8_t pin);
void IOClear(volatile uint8_t * port, uint8_t pin);
void IOToggle(volatile uint8_t * port, uint8_t pin);
bool IOGet(volatile uint8_t port, uint8_t pin);
#endif // _IOPINS_H
