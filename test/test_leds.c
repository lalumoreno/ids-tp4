#include "leds.h"
#include "unity.h"

void setUp(void)
{
    // This is run before EACH TEST
}

void tearDown(void)
{
    // This is run after EACH TEST
}

// Iniciar el driver y revisar que todos los LEDs están apagados
void test_iniciar_todos_los_leds_apagados(void)
{
    uint16_t puerto_virtual = 0x0000; // Todos los bits en 1 (leds apagados)

    LedsInitDriver(&puerto_virtual);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

// Prender un led y verificar que no cambió el estado de los demás
void test_prender_un_led(void)
{
    uint16_t puerto_virtual;

    LedsInitDriver(&puerto_virtual);
    LedsTurnOn(3);

    TEST_ASSERT_EQUAL_HEX16(
        1 << 2, puerto_virtual); // Solo el LED 3 debe estar encendido
}