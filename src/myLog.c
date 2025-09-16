#include "myLog.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void myLog(log_level_t level, const char* fun, int line, const char* message)
{
    // Implementación simple de logging que podría ser expandida
    // para escribir en un archivo, enviar por red, etc.
    // Aquí solo se imprime en consola (stdout)
    const char* level_strings[] = {"ERROR", "ALERTA", "INFORMACION",
                                   "DEPURACION"};
    if (level < ERROR || level > DEPURACION)
    {
        level = ERROR; // Nivel por defecto si es inválido
    }
    printf("[%s] %s:%d: %s\n", level_strings[level], fun, line, message);
}