#pragma once
#include "KhaiBao.h"

// Phụ trách: Thái
// Khung giao tiếp đề xuất. Xem docs/HUONG_DAN_KHUNG_CODE.md trước khi cài.

// Mục i. Thống kê quá hạn giảm dần. CHƯA CHỐT: một độc giả có nhiều cuốn quá hạn thì lấy mốc nào; chốt trước khi cài. Dùng phần tính ngày của Thành.
void manHinhDocGiaQuaHan(const ThuVien& thuVien, const NgayThang& ngayHienTai);

// Mục j. CHƯA CHỐT: theo đầu sách/cuốn, đồng hạng và cách tính lượt mất sách. Chốt trước khi cài; không tự thêm bộ đếm vào struct.
void manHinhTop10(const ThuVien& thuVien);
