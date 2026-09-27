#pragma once
#include "KhaiBao.h"

// Phụ trách: Tấn; Thành nối điều phối
// Khung giao tiếp đề xuất. Xem docs/HUONG_DAN_KHUNG_CODE.md trước khi cài.

// Điều khiển menu và gọi màn hình phụ trách a–j; không cài thuật toán nghiệp vụ ở đây. Thống nhất nạp/lưu/thoát với Thành; không tự quyết định cách bỏ thay đổi chưa lưu.
void chayMenuChinh(ThuVien& thuVien, int& maTheTiepTheo);
