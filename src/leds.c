#include "leds.h"
#include "myLog.h"

static uint16_t* puerto;

void LedsInitDriver(uint16_t* puerto_virtual)
{
    puerto = puerto_virtual;
    *puerto = ALL_LEDS_OFF; // Todos los bits en 0 (leds apagados)
}

void LedsTurnOn(int led_number)
{
    if (led_number < 1 || led_number > 16)
    {
        myLog(ERROR, "LedsTurnOn", 0,
              "LED number out of range. Valid range is 1-16.");
        return;
    }

    *puerto = (1 << (led_number - 1)); // Prender solo el led especificado
}

void LedsTurnOff(int led_number)
{
    *puerto =
        (*puerto & ~(1 << (led_number - 1))); // Apagar solo el led especificado
}