#include "led.h"

// Pin 4 on port D as output
#define LED_SET_DIRECTION  PORTA_DIR
#define LED_REGISTER       PORTA_OUT
#define LED_BIT            (1 << 4)

