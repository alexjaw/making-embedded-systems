#include "led.h"
#include "iopins.h"

void LEDInit()
{
    IOInit(&LED_SET_DIRECTION, &LED_REGISTER);
    IOSetDir(&LED_SET_DIRECTION, LED_PIN, ISOUT);
}

void LEDBlink()
{
    IOToggle(&LED_REGISTER, LED_PIN);
}

