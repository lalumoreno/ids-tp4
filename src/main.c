/**
 * @file main.c
 * @brief Ejemplo principal de uso del módulo GPIO con ADT.
 *
 * Este programa inicializa un GPIO configurado como salida
 * y lo hace parpadear en un bucle infinito.
 */

#include "gpio.h"
#include <stdio.h>
#include <unistd.h> // Para sleep()

/**
 * @brief Función principal.
 *
 * Inicializa un GPIO y hace parpadear el pin en un bucle.
 *
 * @return 0 en caso de éxito.
 */
int main(void)
{
    printf("Iniciando ejemplo GPIO con ADT...\n");

    // Crear un GPIO en el pin 13 como salida
    gpio_t* led = gpio_create(13, GPIO_OUTPUT);

    if (led == NULL)
    {
        printf("Error al inicializar el GPIO\n");
        return -1;
    }

    // Parpadeo
    while (1)
    {
        gpio_write(led, GPIO_HIGH);
        sleep(1);
        gpio_write(led, GPIO_LOW);
        sleep(1);
    }

    // Nunca llega aquí, pero se incluye para buenas prácticas
    gpio_destroy(led);
    return 0;
}
