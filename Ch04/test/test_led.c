#include "unity.h"
#include "led.h"
#include "iopins.h"

void setUp(void)
{
    LEDInit();
}

void tearDown(void)
{
}

static uint8_t pin2hex(uint8_t pin)
{
    return (1 << pin);
}

void test_led_LEDInit()
{
    LED_SET_DIRECTION = 0x00;
    LED_REGISTER = 0xff;
    LEDInit();
    TEST_ASSERT_EQUAL_HEX8(pin2hex(LED_PIN), LED_SET_DIRECTION);
    TEST_ASSERT_EQUAL_HEX8(0, LED_REGISTER);
}

void test_led_LEDBlink()
{
    LEDBlink();
    TEST_ASSERT_EQUAL_HEX8(pin2hex(LED_PIN), LED_REGISTER);
    LEDBlink();
    TEST_ASSERT_EQUAL_HEX8(0, LED_REGISTER);
}

/*void test_led_NeedToImplement(void)
{
    TEST_IGNORE_MESSAGE("Need to Implement led");
}*/
