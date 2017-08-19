#include <stdio.h>
#include "iopins.h"

uint8_t dir_reg = 0x00;
uint8_t io_reg = 0x00;

static bool isWithinBounds(uint8_t pin)
{
    if((pin < PIN_MIN) || (pin > PIN_MAX)) {return false;}
    return true;
}

static uint8_t pin2hex(uint8_t pin)
{
    return (1 << pin);
}

void IOInit(volatile uint8_t * DIR, volatile uint8_t * IO)
{
    *DIR = dir_reg;
    *IO = io_reg;
}

void IOSetDir(volatile uint8_t * PORT, uint8_t PIN, bool isOutput)
{
    if(isOutput)
    {
        IOSet(PORT, PIN);
    }
    else
    {
        IOClear(PORT, PIN);
    }
}

void IOSet(volatile uint8_t * PORT, uint8_t PIN)
{
    if(!isWithinBounds(PIN))
    {
        return;
    }
    *PORT |= pin2hex(PIN);
}

void IOClear(volatile uint8_t * PORT, uint8_t PIN)
{
    if(!isWithinBounds(PIN))
    {
        return;
    }
    *PORT &= ~pin2hex(PIN);
}

void IOToggle(volatile uint8_t * PORT, uint8_t PIN)
{
    if(!isWithinBounds(PIN))
    {
        return;
    }
    *PORT ^= pin2hex(PIN);
}
