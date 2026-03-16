#include "logger.h"
#include <stdarg.h>
#include <time.h>
#include <string.h>

// 4. Sử dụng static để đóng gói trạng thái module
static log_level_t current_level = LOG_INFO;
static FILE* log_file = NULL;

static const char* level_strings[] = {
    "EMERGENCY", "ALERT", "CRITICAL", "ERROR", 
    "WARNING", "NOTICE", "INFO", "DEBUG"
};

int logger_init(log_level_t level, const char* filename) {
    current_level = level;
    if (filename != NULL) {
        log_file = fopen(filename, "a"); // Mở file ở chế độ append
        if (log_file == NULL) return -1;
    }
    return 0;
}

void logger_set_level(log_level_t level) {
    current_level = level;
}

void logger_log(log_level_t level, const char* file, int line, const char* fmt, ...) {
    // 2. Lọc theo cấp độ
    if (level > current_level) return;

    // 3. Lấy Timestamp [YYYY-MM-DD HH:MM:SS]
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char time_buf[25];
    strftime(time_buf, sizeof(time_buf), "%Y-%m-%d %H:%M:%S", t);

    // Chuẩn bị nội dung log
    char message_buf[1024];
    va_list args;
    va_start(args, fmt);
    vsnprintf(message_buf, sizeof(message_buf), fmt, args);
    va_end(args);

    // 3. Định dạng Log chuẩn
    // [Timestamp] [LEVEL] [FILE:LINE] - Message
    char final_buf[2048];
    snprintf(final_buf, sizeof(final_buf), "[%s] [%s] [%s:%d] - %s\n",
             time_buf, level_strings[level], file, line, message_buf);

    // 1. Logger đa đầu ra
    // Ghi ra Console
    if (level <= LOG_ERR) {
        fprintf(stderr, "%s", final_buf);
    } else {
        fprintf(stdout, "%s", final_buf);
    }

    // Ghi ra File nếu có cấu hình
    if (log_file) {
        fprintf(log_file, "%s", final_buf);
        fflush(log_file); // Đảm bảo log được ghi xuống đĩa ngay lập tức
    }
}

void logger_close(void) {
    if (log_file) {
        fclose(log_file);
        log_file = NULL;
    }
}