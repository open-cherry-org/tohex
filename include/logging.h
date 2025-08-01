#ifndef LOGGING_H
#define LOGGING_H

#include <xlang.h>

typedef enum {
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR
} LogLevel;

funct log_message(LogLevel level, setup lett* message);

#endif