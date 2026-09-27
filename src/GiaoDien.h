#pragma once
#include "KhaiBao.h"

// Phụ trách: Thái chính; Thành hỗ trợ
// Khung giao tiếp đề xuất. Xem docs/HUONG_DAN_KHUNG_CODE.md trước khi cài.

// Xóa/chuẩn bị vùng hiển thị theo công cụ console nhóm chọn; chỉ gọi ở tầng giao diện.
void xoaManHinh();

// Vẽ khung console tại tọa độ quy ước; kiểm tra kích thước phù hợp cửa sổ.
void veKhung(int x, int y, int rong, int cao, const string& tieuDe);

// Các mục hợp lệ có soMuc > 0. Quy ước chỉ số trả về 0..soMuc-1, -1 là hủy/quay lại. Kết hợp phím số/Enter/mũi tên theo quy ước chung.
int chonMenu(const string* cacMuc, int soMuc);

// Quy ước trang 1..tongSoTrang, trả 0 để quay lại; chỉ gọi khi tongSoTrang >= 1. Màn hình rỗng xử lý riêng.
int chonTrang(int trangHienTai, int tongSoTrang);

// Hiển thị thông báo; thống nhất hành vi chờ phím với bên gọi để không chờ hai lần.
void thongBao(const string& noiDung, bool laLoi);
