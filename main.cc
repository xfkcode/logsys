#include "logging.h"

int main() {
    // 打开日志文件
    g_log_file = open_log_file();
    if (!g_log_file) {
        fprintf(stderr, "Failed to open log file.\n");
        return 1;
    }

    // 记录不同级别的日志信息
    LOG_ERRO("This is an error message.");
    LOG_WARN("This is a warning message.");
    LOG_INFO("This is an information message.");
    LOG_DBUG("This is a debug message.");

    // 关闭日志文件
    fclose(g_log_file);
    g_log_file = nullptr;

    return 0;
}

