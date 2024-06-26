
#ifndef LOGGING_H
#define LOGGING_H

#include <stdio.h>
#include <time.h>
#include <stdarg.h>
#include <cstdint>
#include <cstring>
#include <sys/stat.h>
#include <unistd.h>
// log level from low to high
// 0: no log
// 1: error
// 2: error, warning
// 3: error, warning, info
// 4: error, warning, info, debug
extern int32_t g_log_level;
extern FILE *g_log_file;

FILE* open_log_file();
void log_to_file(const char *level_str, const char *format, ...);

#define NN_LOG(level, level_str, ...)              \
    do                                             \
    {                                              \
        if (g_log_level >= level)                  \
        {                                          \
            log_to_file(level_str, __VA_ARGS__);   \
        }                                          \
    } while (0)

#define LOG_ERRO(...)   NN_LOG(1, "ERRO", __VA_ARGS__)
#define LOG_WARN(...)   NN_LOG(2, "WARN", __VA_ARGS__)
#define LOG_INFO(...)   NN_LOG(3, "INFO", __VA_ARGS__)
#define LOG_DBUG(...)   NN_LOG(4, "DBUG", __VA_ARGS__)

#endif // LOGGING_H
