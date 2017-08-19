#ifndef _IOPINS_H
#define _IOPINS_H
#include <stdint.h>
#include <stdbool.h>

enum {PIN_MIN = 0, PIN_MAX = 7};

void IOInit(volatile uint8_t * REG_DIR, volatile uint8_t * REG_IO);
void IOSetDir(volatile uint8_t * PORT, uint8_t PIN, bool isOutput);
void IOSet(volatile uint8_t * PORT, uint8_t PIN);
void IOClear(volatile uint8_t * PORT, uint8_t PIN);
void IOToggle(volatile uint8_t * PORT, uint8_t PIN);
#endif // _IOPINS_H
