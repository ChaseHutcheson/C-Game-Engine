#include "logger.h"
#include "asserts.h"

// TODO: temporary
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

b8 initialize_logging()
{
    // TODO: create log file
    return TRUE;
}

void shutdown_logging()
{
    // TODO: clean up logging/write queued entries
}

void log_output(log_level level, const char *message, ...)
{
    // Defined an array of strings for each log level
    const char *level_strings[6] = {"[FATAL]: ", "[ERROR]: ", "[WARN]: ", "[INFO]: ", "[DEBUG]: ", "[TRACE]: "};

    // Check if the log level is less than 2 (FATAL or ERROR)
    // b8 is_error = level < 2;

    // Create a buffer to store the formatted message
    char out_message[32000];

    // Clear the buffer
    memset(out_message, 0, sizeof(out_message));

    // Format the message
    __builtin_va_list arg_ptr;
    // Start the va_list after the message parameter
    va_start(arg_ptr, message);
    // output the message to the out_message buffer
    vsnprintf(out_message, 32000, message, arg_ptr);
    // Clean up memmory used by arg_ptr
    va_end(arg_ptr);

    // Prepend the log level to the message
    char out_message2[32000];
    sprintf(out_message2, "%s%s\n", level_strings[level], out_message);

    // Print the message to the console
    // TODO: platform specific logging
    printf("%s", out_message2);
}

void report_assertion_failure(const char *expression, const char *message, const char *file, i32 line)
{
    log_output(LOG_LEVEL_FATAL, "Assertion failed: %s\nMessage: %s\nFile: %s\nLine: %d", expression, message, file, line);
}
