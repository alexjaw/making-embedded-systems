#include "unity.h"
#include "Button.h"
#include "iopins.h"

void setUp(void)
{
    ButtonInit();
}

void tearDown(void)
{
}

static uint8_t pin2hex(uint8_t pin)
{
    return (1 << pin);
}

void test_Button_ButtonInit(void)
{
    BTN_SET_DIRECTION = 0x01;
    BTN_REGISTER = 0xff;
    ButtonInit();
    TEST_ASSERT_EQUAL_HEX8(0, BTN_SET_DIRECTION);
    TEST_ASSERT_EQUAL_HEX8(0, BTN_REGISTER);
}

void test_Button_ButtonPressed(void)
{
    BTN_REGISTER = pin2hex(BTN_PIN);
    bool result = ButtonPressed();
    TEST_ASSERT_EQUAL_HEX8(BTN_REGISTER, result);
    BTN_REGISTER = 0;
    result = ButtonPressed();
    TEST_ASSERT_EQUAL_HEX8(BTN_REGISTER, result);
}

/*void test_Button_NeedToImplement(void)
{
    TEST_IGNORE_MESSAGE("Need to Implement Button");
}*/
