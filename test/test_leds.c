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

void test_al_iniciar_todos_los_leds_estan_apagados(void)
{
    uint16_t puerto_virtual = 0xFFFF; // Todos los bits en 1 (leds apagados)

    LedsInitDriver(&puerto_virtual);

    TEST_ASSERT_EQUAL_HEX16(0xFFFF, puerto_virtual);
}