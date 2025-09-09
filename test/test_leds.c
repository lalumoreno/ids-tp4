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

// Prender varios leds y verificar que todos queden encendidos
void test_prender_varios_leds(void)
{
    LedsTurnOn(2);
    LedsTurnOn(4);
    LedsTurnOn(6);
    TEST_ASSERT_EQUAL_HEX16(
        1 << 1 | 1 << 3 | 1 << 5,
        puerto_virtual); // el led 2, 4 y 6 deben estar encendidos
}

// Prender mas de un led, apagar uno y verificar que los demás no cambiaron
void test_prender_varios_y_apagar_uno(void)
{
    LedsTurnOn(5);
    LedsTurnOn(3);
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

// Apagar leds fuera de rango y verificar que se recibe un error
void test_apagar_led_fuera_de_rango(void)
{
    LedsTurnOn(5); // Prender un LED válido primero

    myLog_Expect(ERROR, "LedsTurnOff", 0,
                 "LED number out of range. Valid range is 1-16.");
    myLog_IgnoreArg_line();
    LedsTurnOff(0); // LED fuera de rango (menor que 1)
    TEST_ASSERT_EQUAL_HEX16(1 << 4,
                            puerto_virtual); // El LED 5 debe seguir encendido

    myLog_ExpectAnyArgs();
    LedsTurnOff(17); // LED fuera de rango (mayor que 16)
    TEST_ASSERT_EQUAL_HEX16(1 << 4,
                            puerto_virtual); // El LED 5 debe seguir encendido
}

// Prender todos los leds
void test_prender_todos_los_leds(void)
{
    LedsTurnAllOn();
    TEST_ASSERT_EQUAL_HEX16(ALL_LEDS_ON, puerto_virtual);
}

// Apagar todos los leds
void test_apagar_todos_los_leds(void)
{
    LedsTurnAllOn(); // Primero prender todos los LEDs
    LedsTurnAllOff();
    TEST_ASSERT_EQUAL_HEX16(ALL_LEDS_OFF, puerto_virtual);
}

// Consultar el estado de un led encendido y verificar que es correcto
void test_consultar_estado_led_encendido(void)
{
    LedsTurnOn(7);
    TEST_ASSERT_TRUE(LedsIsOn(7));
}

// Consultar el estado de un led apagado y verificar que es correcto
void test_consultar_estado_led_apagado(void)
{
    LedsTurnOn(8);
    LedsTurnOff(8);
    TEST_ASSERT_FALSE(LedsIsOn(8));
}