#include "unity.h"
#include "iopins.h"
#include <stdint.h>

volatile uint8_t REG_DIR, REG_OUT, PIN; 

void setUp(void)
{
    IOInit(&REG_DIR, &REG_OUT);
}

void tearDown(void)
{
}

static uint8_t pin2hex(uint8_t pin)
{
    return (1 << pin);
}

void test_iopins_Init(void)
{
    PIN = 5;
    IOSetDir(&REG_DIR, PIN, true);
    IOSet(&REG_OUT, PIN);
    IOInit(&REG_DIR, &REG_OUT);
    TEST_ASSERT_EQUAL_HEX8(0, REG_DIR);
    TEST_ASSERT_EQUAL_HEX8(0, REG_OUT);
}

void test_iopins_IOSetDirAsOutput()
{
    PIN = PIN_MAX;
    IOSetDir(&REG_DIR, PIN, true);
    TEST_ASSERT_EQUAL_HEX8(pin2hex(PIN), REG_DIR);
}

void test_iopins_IOSetDirAsInput()
{
    PIN = PIN_MIN;
    IOSetDir(&REG_DIR, PIN, false);
    TEST_ASSERT_EQUAL_HEX8(0, REG_DIR);
}

void test_iopins_SetPinAtBounds(void)
{
    uint8_t expect = (pin2hex(PIN_MIN) | pin2hex(PIN_MAX)); 
    IOSet(&REG_OUT, PIN_MIN);
    IOSet(&REG_OUT, PIN_MAX);
    TEST_ASSERT_EQUAL_HEX8(expect, REG_OUT);
}

void test_iopins_SetPinOutOfBounds(void)
{
    IOSet(&REG_OUT, PIN_MIN-1);
    IOSet(&REG_OUT, PIN_MAX+1);
    TEST_ASSERT_EQUAL_HEX8(0, REG_OUT);
}

void test_iopins_SetCorrectPin(void)
{
    PIN = 5;
    IOSet(&REG_OUT, PIN);
    TEST_ASSERT_EQUAL_HEX8(pin2hex(PIN), REG_OUT);
}

void test_iopins_SetCorrectTwoPins(void)
{
    uint8_t pin1 = 0;
    uint8_t pin2 = 4;
    uint8_t expect = (pin2hex(pin1) | pin2hex(pin2));
    IOSet(&REG_OUT, pin2);
    IOSet(&REG_OUT, pin1);
    TEST_ASSERT_EQUAL_HEX8(expect, REG_OUT);
}

void test_iopins_ClearCorrectPin(void)
{
    uint8_t pin2clear = 2;
    PIN = 4;
    IOSet(&REG_OUT, PIN);
    IOSet(&REG_OUT, pin2clear);
    IOClear(&REG_OUT, pin2clear);
    TEST_ASSERT_EQUAL_HEX8(pin2hex(PIN), REG_OUT);
}

void test_iopins_TogglePinFromClearState()
{
    PIN = 4;
    IOToggle(&REG_OUT, PIN);
    TEST_ASSERT_EQUAL_HEX8((pin2hex(PIN)), REG_OUT);
}

void test_iopins_TogglePinFromSetState()
{
    PIN = 4;
    IOSet(&REG_OUT, PIN);
    IOToggle(&REG_OUT, PIN);
    TEST_ASSERT_EQUAL_HEX8(0, REG_OUT);
}

/*
void test_iopins_NeedToImplement(void)
{
    TEST_IGNORE_MESSAGE("Need to Implement iopins");
}
*/
