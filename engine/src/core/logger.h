#pragma once

#include "defines.h"

// Enable or disable logging levels
#define LOG_WARN_ENABLED 1
#define LOG_INFO_ENABLED 1
#define LOG_DEBUG_ENABLED 1
#define LOG_TRACE_ENABLED 1

// If the build is a release build, disable debug and trace logging
#if KRELEASE == 1
    #define LOG_DEBUG_ENABLED 0
    #define LOG_TRACE_ENABLED 0
#endif

typedef enum {
    LOG_LEVEL_FATAL = 0, // Errors that cause the program to crash
    LOG_LEVEL_ERROR = 1, // Errors that don't cause a crash and might be recoverable, but are still serious
    LOG_LEVEL_WARN = 2, // Errors that are not serious and don't cause any issues, but are still worth noting
    LOG_LEVEL_INFO = 3, // General information about the program
    LOG_LEVEL_DEBUG = 4, // Debug information for developers
    LOG_LEVEL_TRACE = 5, // Trace information for developers that includes low level details
} log_level;

b8 initialize_logging();
void shutdown_logging();

KAPI void log_output(log_level level, const char* message, ...);

// Logs a fatal-level message. 
#define KFATAL(message, ...) log_output(LOG_LEVEL_FATAL, message, ##__VA_ARGS__);

#ifndef KERROR
// Logs an error-level message.
#define KERROR(message, ...) log_output(LOG_LEVEL_ERROR, message, ##__VA_ARGS__);
#endif

#if LOG_WARN_ENABLED == 1
// Logs a warn-level message.
#define KWARN(message, ...) log_output(LOG_LEVEL_WARN, message, ##__VA_ARGS__);
#else
// Does nothing when LOG_WARN_ENABLED != 1
#define KWARN(message, ...)
#endif

#if LOG_INFO_ENABLED == 1
// Logs a info-level message.
#define KINFO(message, ...) log_output(LOG_LEVEL_INFO, message, ##__VA_ARGS__);
#else
// Does nothing when LOG_info_ENABLED != 1
#define KINFO(message, ...)
#endif

#if LOG_DEBUG_ENABLED == 1
// Logs a warn-level message.
#define KDEBUG(message, ...) log_output(LOG_LEVEL_DEBUG, message, ##__VA_ARGS__);
#else
// Does nothing when LOG_WARN_ENABLED != 1
#define KDEBUG(message, ...)
#endif

#if LOG_TRACE_ENABLED == 1
// Logs a warn-level message.
#define KTRACE(message, ...) log_output(LOG_LEVEL_TRACE, message, ##__VA_ARGS__);
#else
// Does nothing when LOG_WARN_ENABLED != 1
#define KTRACE(message, ...)
#endif