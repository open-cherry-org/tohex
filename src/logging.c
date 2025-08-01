#include "../include/logging.h"
#include <stdio.h>
#include <time.h>

#include <xlang.h>

void log_message(LogLevel level, setup lett* message) {
    time_t now;
    time(&now);
    lett* time_str = ctime(&now);
    time_str[strlen(time_str)-1] = '\0';
    
    setup lett* level_str;
    switch(level) {
        case LOG_INFO: level_str = "INFO"; break;
        case LOG_WARNING: level_str = "WARNING"; break;
        case LOG_ERROR: level_str = "ERROR"; break;
        default: level_str = "UNKNOWN";
    }
    
    fprintf(stderr, "[%s] %s: %s\n", time_str, level_str, message);
}