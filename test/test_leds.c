#include "leds.h"
#include "mock_myLog.h"
#include "unity.h"

static uint16_t puerto_virtual;

void setUp(void)
{
    // This is run before EACH TEST
    LedsInitDriver(&puerto_virtual);
}

void tearDown(void)
{
    // This is run after EACH TEST
}

// Iniciar el driver y revisar que todos los LEDs están apagados
void test_iniciar_todos_los_leds_apagados(void)
{
    uint16_t puerto_virtual =
        ALL_LEDS_ON; // Todos los bits en 1 (leds encendidos)
    LedsInitDriver(&puerto_virtual);
    TEST_ASSERT_EQUAL_HEX16(ALL_LEDS_OFF, puerto_virtual);
}

// Prender un led y verificar que no cambió el estado de los demás
void test_prender_un_led(void)
{
    LedsTurnOn(3);
    TEST_ASSERT_EQUAL_HEX16(
        (1 << 2), puerto_virtual); // Solo el LED 3 debe estar encendido
}

// Prender un led cualquiera y apagarlo
void test_prender_y_apagar_un_led(void)
{
    LedsTurnOn(5);
    LedsTurnOff(5);
    TEST_ASSERT_EQUAL_HEX16(
        ALL_LEDS_OFF, puerto_virtual); // Todos los LEDs deben estar apagados
}

// Prender mas de un led, apagar uno y verificar que los demás no cambiaron
void test_prender_varios_y_apagar_uno(void)
{
    LedsTurnOn(3);
    LedsTurnOn(5);
    LedsTurnOff(3);
    TEST_ASSERT_EQUAL_HEX16(
        1 << 4, puerto_virtual); // Solo el LED 5 debe estar encendido
}

// Prender leds fuera de rango y verificar que se recibe un error
void test_prender_led_fuera_de_rango(void)
{
    myLog_Expect(ERROR, "LedsTurnOn", 0,
                 "LED number out of range. Valid range is 1-16.");
    myLog_IgnoreArg_line();
    LedsTurnOn(0); // LED fuera de rango (menor que 1)
    TEST_ASSERT_EQUAL_HEX16(
        ALL_LEDS_OFF, puerto_virtual); // Todos los LEDs deben estar apagados

    myLog_ExpectAnyArgs();
    LedsTurnOn(17); // LED fuera de rango (mayor que 16)
    TEST_ASSERT_EQUAL_HEX16(
        ALL_LEDS_OFF, puerto_virtual); // Todos los LEDs deben estar apagados
}