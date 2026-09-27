#include "KhaiBao.h"
#include <iostream>

// Thành điều phối. Bộ khung chỉ kiểm tra khả năng build nhiều file.
int main()
{
    ThuVien thuVien;
    int maTheTiepTheo = 1; // Metadata hỗ trợ cấp mã; phải đọc/ghi cùng dữ liệu.
    (void)thuVien;
    (void)maTheTiepTheo;

    // TODO: nối nạp dữ liệu, menu, lưu/thoát và giải phóng khi các hàm đã cài.
    // Chưa gọi các hàm TODO vì chúng chủ động báo chưa cài bằng logic_error.
    std::cout << "KHUNG THU VIEN - CHUA CAI DAT CHUC NANG\n";
    return 0;
}
