/**
 * @file gpio.c
 * @brief Implementación del ADT GPIO.
 *
 * Esta implementación es genérica y sirve como template.
 * Dependiendo del hardware real, deben reemplazarse
 * las funciones de acceso por las correspondientes
 * a la plataforma.
 */

#include "gpio.h"
#include <stdio.h>
#include <stdlib.h>

/** @brief Estructura interna que representa un GPIO */
struct gpio
{
    uint8_t pin;        /**< Número de pin */
    gpio_mode_t mode;   /**< Modo de configuración */
    gpio_state_t state; /**< Último estado escrito */
};

gpio_t* gpio_create(uint8_t pin, gpio_mode_t mode)
{
    gpio_t* gpio = malloc(sizeof(gpio_t));
    if (!gpio)
        return NULL;

    gpio->pin = pin;
    gpio->mode = mode;
    gpio->state = GPIO_LOW;

    // Aquí iría la inicialización real del hardware
    printf("[GPIO] Pin %d inicializado como %s\n", pin,
           (mode == GPIO_OUTPUT) ? "OUTPUT" : "INPUT");

    return gpio;
}

void gpio_destroy(gpio_t* gpio)
{
    if (gpio)
    {
        printf("[GPIO] Liberando pin %d\n", gpio->pin);
        free(gpio);
    }
}

void gpio_write(gpio_t* gpio, gpio_state_t state)
{
    if (!gpio || gpio->mode != GPIO_OUTPUT)
        return;

    gpio->state = state;

    // Aquí se debería escribir al hardware real
    printf("[GPIO] Pin %d -> %s\n", gpio->pin,
           (state == GPIO_HIGH) ? "HIGH" : "LOW");
}

gpio_state_t gpio_read(gpio_t* gpio)
{
    if (!gpio || gpio->mode != GPIO_INPUT)
        return GPIO_LOW;

    // Aquí se debería leer del hardware real
    printf("[GPIO] Leyendo pin %d -> %s\n", gpio->pin,
           (gpio->state == GPIO_HIGH) ? "HIGH" : "LOW");

    return gpio->state;
}
