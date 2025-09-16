/**
 * @file gpio.h
 * @brief Interfaz ADT para el manejo de GPIO.
 *
 * Define una abstracción de tipo de dato (ADT) para manipular
 * pines GPIO de forma independiente al hardware.
 */

#ifndef GPIO_H
#define GPIO_H

#include <stdbool.h>
#include <stdint.h>

/** @brief Estados posibles de un pin GPIO */
typedef enum
{
    GPIO_LOW = 0, /**< Estado bajo */
    GPIO_HIGH     /**< Estado alto */
} gpio_state_t;

/** @brief Modos de configuración de un GPIO */
typedef enum
{
    GPIO_INPUT = 0, /**< Configurado como entrada */
    GPIO_OUTPUT     /**< Configurado como salida */
} gpio_mode_t;

/** @brief Tipo opaco que representa un GPIO */
typedef struct gpio gpio_t;

/**
 * @brief Crea e inicializa un nuevo GPIO.
 *
 * @param pin Número de pin a configurar.
 * @param mode Modo de funcionamiento (entrada/salida).
 * @return Puntero a la estructura gpio_t o NULL si falla.
 */
gpio_t* gpio_create(uint8_t pin, gpio_mode_t mode);

/**
 * @brief Libera un GPIO previamente creado.
 *
 * @param gpio Puntero al GPIO.
 */
void gpio_destroy(gpio_t* gpio);

/**
 * @brief Escribe un valor en un GPIO configurado como salida.
 *
 * @param gpio Puntero al GPIO.
 * @param state Estado a escribir (GPIO_LOW o GPIO_HIGH).
 */
void gpio_write(gpio_t* gpio, gpio_state_t state);

/**
 * @brief Lee el estado de un GPIO configurado como entrada.
 *
 * @param gpio Puntero al GPIO.
 * @return Estado actual del pin (GPIO_LOW o GPIO_HIGH).
 */
gpio_state_t gpio_read(gpio_t* gpio);

#endif // GPIO_H
