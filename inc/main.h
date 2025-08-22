/**
 * @file main.h
 * @brief Archivo de cabecera principal del programa.
 *
 * Este archivo contiene las definiciones y prototipos de funciones
 * utilizadas en el archivo `main.c`. Sirve como punto de entrada
 * para el sistema y permite la inclusión organizada de funciones
 * de inicialización y ejecución del programa.
 *
 * @author
 * @date    2025-08-21
 */

#ifndef MAIN_H
#define MAIN_H

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief Inicializa los recursos principales del programa.
     *
     * Configura las estructuras necesarias, incluyendo la cola de prioridad,
     * y prepara el entorno de ejecución del sistema.
     */
    void system_init(void);

    /**
     * @brief Ejecuta el flujo principal del programa.
     *
     * Esta función gestiona la inserción de elementos en la cola,
     * su procesamiento y visualización en consola.
     */
    void system_run(void);

#ifdef __cplusplus
}
#endif

#endif // MAIN_H
