#include "unity.h"
#include "iopins.h"
#include <stdint.h>

volatile uint8_t REG_OUT, PIN; 

void setUp(void)
{
    IOInit(&REG_OUT);
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
    IOSet(&REG_OUT, PIN);
    IOInit(&REG_OUT);
    TEST_ASSERT_EQUAL_HEX8(0, REG_OUT);
}

void test_iopins_SetCorrectPin(void)
{
    PIN = 0;
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

void test_iopins_SetPinOutOfBounds(void)
{
    IOSet(&REG_OUT, -1);
    IOSet(&REG_OUT, 8);
    TEST_ASSERT_EQUAL_HEX8(0, REG_OUT);
}

void test_iopins_ClearCorrectPin(void)
{
    uint8_t pin2clear = 0;
    PIN = 4;
    IOSet(&REG_OUT, PIN);
    IOSet(&REG_OUT, pin2clear);
    IOClear(&REG_OUT, pin2clear);
    TEST_ASSERT_EQUAL_HEX8(pin2hex(PIN), REG_OUT);
}

/*
void test_iopins_NeedToImplement(void)
{
    TEST_IGNORE_MESSAGE("Need to Implement iopins");
}
*/
