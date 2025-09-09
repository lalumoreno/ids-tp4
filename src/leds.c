#include "leds.h"
#include "myLog.h"
#include <stdbool.h>

static uint16_t* puerto;

bool isValidLedNumber(int led_number)
{
    return (led_number >= MIN_LED_NUMBER && led_number <= MAX_LED_NUMBER);
}

void LedsInitDriver(uint16_t* puerto_virtual)
{
    puerto = puerto_virtual;
    LedsTurnAllOff(); // Todos los bits en 0 (leds apagados)
}

// Prender un led sin afectar el estado de los demás
void LedsTurnOn(int led_number)
{
    if (!isValidLedNumber(led_number))
    {
        myLog(ERROR, "LedsTurnOn", 0,
              "LED number out of range. Valid range is 1-16.");
        return;
    }

    *puerto |= (1 << (led_number - 1)); // Prender solo el led especificado
}

void LedsTurnOff(int led_number)
{
    if (!isValidLedNumber(led_number))
    {
        myLog(ERROR, "LedsTurnOff", 0,
              "LED number out of range. Valid range is 1-16.");
        return;
    }

    *puerto =
        (*puerto & ~(1 << (led_number - 1))); // Apagar solo el led especificado
}

void LedsTurnAllOff(void)
{
    *puerto = ALL_LEDS_OFF;
}

void LedsTurnAllOn(void)
{
    *puerto = ALL_LEDS_ON;
}