#include "logging.h"

// log level from low to high
// 0: no log
// 1: error
// 2: error, warning
// 3: error, warning, info
// 4: error, warning, info, debug

int32_t g_log_level = 3;
FILE *g_log_file = NULL;

FILE* open_log_file()
{
    const char* log_dir = "/mnt/log/AI/";
    const char* file_prefix = "AI_";
    const char* file_suffix = ".log";
	
    if (access(log_dir, F_OK) != 0)
    {
        if (mkdir(log_dir, 0777) == -1)
        {
            printf("Failed to create log directory: %s\n", log_dir);
            return NULL;
        }
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char filename[256];

    strftime(filename, sizeof(filename), "%Y%m%d%H%M%S", t);
    strcat(filename, file_suffix);

    char filepath[256];
    sprintf(filepath, "%s%s%s", log_dir, file_prefix, filename);

    FILE *log_file = fopen(filepath, "w");
    if (!log_file)
    {
        printf("Failed to open log file: %s\n", filepath);
    }
    return log_file;
}

void log_to_file(const char *level_str, const char *format, ...)
{
    if (g_log_file)
    {
        va_list args;
        va_start(args, format);

        fprintf(g_log_file, "[%s] ", level_str);
        vfprintf(g_log_file, format, args);
        fprintf(g_log_file, "\n");
        fflush(g_log_file);

        va_end(args);
    }
}

