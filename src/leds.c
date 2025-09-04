#include "leds.h"

void LedsInitDriver(uint16_t* puerto_virtual)
{
    // Inicializa el puerto virtual con todos los LEDs apagados (bits en 1)
    *puerto_virtual = 0xFFFF;
}