#ifndef _IOPINS_H
#define _IOPINS_H
#include <stdint.h>
#include <stdbool.h>

void IOInit(volatile uint8_t * PORT);
void IOSetDir(volatile uint8_t * PORT, uint8_t PIN, bool isOutput);
void IOSet(volatile uint8_t * PORT, uint8_t PIN);
void IOClear(volatile uint8_t * PORT, uint8_t PIN);
void IOToogle(volatile uint8_t * PORT, uint8_t PIN);
#endif // _IOPINS_H
