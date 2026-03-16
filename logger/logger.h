#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>

// 2. Các mức Log theo tiêu chuẩn Syslog
typedef enum {
    LOG_EMERG = 0,   // Nhật ký khẩn cấp
    LOG_ALERT,
    LOG_CRIT,
    LOG_ERR,
    LOG_WARNING,
    LOG_NOTICE,
    LOG_INFO,
    LOG_DEBUG
} log_level_t;

// Khởi tạo logger (tùy chọn ghi file)
int logger_init(log_level_t level, const char* filename);

// Thay đổi mức lọc log tại thời điểm chạy
void logger_set_level(log_level_t level);

// Hàm ghi log chính (không gọi trực tiếp, dùng qua macro)
void logger_log(log_level_t level, const char* file, int line, const char* fmt, ...);

// Giải phóng tài nguyên
void logger_close(void);

// 4. Giao diện tiện lợi: Macro để tự động lấy __FILE__ và __LINE__
#define log_message(level, fmt, ...) \
    logger_log(level, __FILE__, __LINE__, fmt, ##__VA_ARGS__)

#endif