#include <stdint.h>

#define ALL_LEDS_ON 0xFFFF
#define ALL_LEDS_OFF 0x0000

void LedsInitDriver(uint16_t* puerto_virtual);
void LedsTurnOn(int led_number);
void LedsTurnOff(int led_number);