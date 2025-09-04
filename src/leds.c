#include "leds.h"

static uint16_t* puerto;

void LedsInitDriver(uint16_t* puerto_virtual)
{
    puerto = puerto_virtual;
    *puerto = 0x0000; // Todos los bits en 0 (leds apagados)
}

void LedsTurnOn(int led_number)
{
    *puerto = 1 << 2;
}