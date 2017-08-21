#include <stdio.h>
#include "iopins.h"

static bool isWithinBounds(uint8_t pin)
{
    if((pin < PIN_MIN) || (pin > PIN_MAX)) {return false;}
    return true;
}

static uint8_t pin2hex(uint8_t pin)
{
    return (1 << pin);
}

void IOInit(volatile uint8_t * dir, volatile uint8_t * io)
{
    //IOSetDir() is left out since it is better for testing the module
    *dir = 0x00;
    *io = 0x00;
}

void IOSetDir(volatile uint8_t * port, uint8_t pin, bool isOutput)
{
    if(isOutput)
    {
        IOSet(port, pin);
    }
    else
    {
        IOClear(port, pin);
    }
}

void IOSet(volatile uint8_t * port, uint8_t pin)
{
    if(!isWithinBounds(pin))
    {
        return;
    }
    *port |= pin2hex(pin);
}

void IOClear(volatile uint8_t * port, uint8_t pin)
{
    if(!isWithinBounds(pin))
    {
        return;
    }
    *port &= ~pin2hex(pin);
}

void IOToggle(volatile uint8_t * port, uint8_t pin)
{
    if(!isWithinBounds(pin))
    {
        return;
    }
    *port ^= pin2hex(pin);
}

bool IOGet(volatile uint8_t port, uint8_t pin) 
{
    if(!isWithinBounds(pin))
    {
        return false;
    }

    bool result = pin2hex(pin) & port;
    if(result)
    {
        return true;
    }
    return false;
}

void IOInterruptEnable(volatile uint8_t * port, uint8_t pin)
{
    IOSet(port, pin);
}

void IOInterruptDisable(volatile uint8_t * port, uint8_t pin)
{
    IOClear(port, pin);
}
