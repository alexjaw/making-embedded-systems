#include "unity.h"
#include "iopins.h"
#include <stdint.h>

volatile uint8_t REG_DIR, REG_IO, PIN; 

void setUp(void)
{
    IOInit(&REG_DIR, &REG_IO);
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
    IOSet(&REG_IO, PIN);
    IOInit(&REG_DIR, &REG_IO);
    TEST_ASSERT_EQUAL_HEX8(0, REG_DIR);
    TEST_ASSERT_EQUAL_HEX8(0, REG_IO);
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
    IOSet(&REG_IO, PIN_MIN);
    IOSet(&REG_IO, PIN_MAX);
    TEST_ASSERT_EQUAL_HEX8(expect, REG_IO);
}

void test_iopins_SetPinOutOfBounds(void)
{
    IOSet(&REG_IO, PIN_MIN-1);
    IOSet(&REG_IO, PIN_MAX+1);
    TEST_ASSERT_EQUAL_HEX8(0, REG_IO);
}

void test_iopins_SetCorrectPin(void)
{
    PIN = 5;
    IOSet(&REG_IO, PIN);
    TEST_ASSERT_EQUAL_HEX8(pin2hex(PIN), REG_IO);
}

void test_iopins_SetCorrectTwoPins(void)
{
    uint8_t pin1 = 0;
    uint8_t pin2 = 4;
    uint8_t expect = (pin2hex(pin1) | pin2hex(pin2));
    IOSet(&REG_IO, pin2);
    IOSet(&REG_IO, pin1);
    TEST_ASSERT_EQUAL_HEX8(expect, REG_IO);
}

void test_iopins_ClearCorrectPin(void)
{
    uint8_t pin2clear = 2;
    PIN = 4;
    IOSet(&REG_IO, PIN);
    IOSet(&REG_IO, pin2clear);
    IOClear(&REG_IO, pin2clear);
    TEST_ASSERT_EQUAL_HEX8(pin2hex(PIN), REG_IO);
}

void test_iopins_TogglePinFromClearState()
{
    PIN = 4;
    IOToggle(&REG_IO, PIN);
    TEST_ASSERT_EQUAL_HEX8((pin2hex(PIN)), REG_IO);
}

void test_iopins_TogglePinFromSetState()
{
    PIN = 4;
    IOSet(&REG_IO, PIN);
    IOToggle(&REG_IO, PIN);
    TEST_ASSERT_EQUAL_HEX8(0, REG_IO);
}

void test_iopins_GetInputOn()
{
    PIN = 4;
    REG_IO = 0x81;
    REG_IO |= pin2hex(PIN);
    bool result = IOGet(REG_IO, PIN);
    TEST_ASSERT_EQUAL(true, result);
}

void test_iopins_GetInputOff()
{
    PIN = 4;
    REG_IO = 0x81;
    REG_IO &= ~pin2hex(PIN);
    bool result = IOGet(REG_IO, PIN);
    TEST_ASSERT_EQUAL(false, result);
}

void test_iopins_NeedToImplement(void)
{
    TEST_IGNORE_MESSAGE("Need to implement test of reading a pin set to output");
}

/*
void test_iopins_NeedToImplement(void)
{
    TEST_IGNORE_MESSAGE("Need to Implement iopins");
}
*/
