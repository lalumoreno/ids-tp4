#ifndef LOG_H
#define LOG_H

typedef enum
{
    ERROR,
    ALERTA,
    INFORMACION,
    DEPURACION
} log_level_t;

void myLog(log_level_t level, const char* fun, int line, const char* message);

#endif // ERRORES_H