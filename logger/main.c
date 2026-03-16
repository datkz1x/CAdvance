#include "logger.h"
#include <string.h>

int main() {
    // Khởi tạo logger mức DEBUG, ghi ra file "system.log"
    if (logger_init(LOG_DEBUG, "system.log") != 0) {
        printf("Khởi tạo Logger thất bại!\n");
        return 1;
    }
    char long_str[2000];
    memset(long_str, 'A', 1999);
    long_str[1999] = '\0';
    log_message(LOG_INFO, "Test %s", long_str);
    log_message(LOG_INFO, "Hệ thống bắt đầu khởi động...");
    
    int sensor_val = 42;
    log_message(LOG_DEBUG, "Giá trị cảm biến đọc được: %d", sensor_val);

    // Giả lập lỗi
    log_message(LOG_ERR, "Không thể kết nối đến cơ sở dữ liệu.");

    // Thay đổi mức lọc log sang WARNING (bỏ qua INFO và DEBUG)
    logger_set_level(LOG_WARNING);
    log_message(LOG_INFO, "Thông báo này sẽ KHÔNG được hiển thị.");
    log_message(LOG_CRIT, "Thiết bị quá nhiệt! Cần xử lý ngay.");
    
    logger_close();
    return 0;
}