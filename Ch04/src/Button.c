#include "Button.h"
#include "iopins.h"

void ButtonInit()
{
    IOInit(&BTN_SET_DIRECTION, &BTN_REGISTER);
    IOSetDir(&BTN_SET_DIRECTION, BTN_PIN, ISOUT);
}

bool ButtonPressed()
{
    return IOGet(BTN_REGISTER, BTN_PIN);
}
