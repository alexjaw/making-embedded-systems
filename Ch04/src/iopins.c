#include <stdio.h>
#include <stdbool.h>
#include "iopins.h"

enum {PIN_MIN = 0, PIN_MAX = 7};

uint8_t regs = 0x00;

static bool isWithinBounds(uint8_t pin)
{
    if((pin < PIN_MIN) || (pin > PIN_MAX)) {return false;}
    return true;
}

static uint8_t pin2hex(uint8_t pin)
{
    return (1 << pin);
}

void IOInit(volatile uint8_t * PORT)
{
    *PORT = regs;
}

void IOSet(volatile uint8_t * PORT, uint8_t PIN)
{
    //printf("initial port value: 0x%02x", *PORT);
    if(!isWithinBounds(PIN))
    {
        return;
    }
    *PORT |= pin2hex(PIN);
    //printf("final port value: 0x%02x", *PORT);
}

void IOClear(volatile uint8_t * PORT, uint8_t PIN)
{
    if(!isWithinBounds(PIN))
    {
        return;
    }
    *PORT &= ~pin2hex(PIN);
}
