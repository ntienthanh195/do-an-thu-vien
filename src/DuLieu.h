#pragma once
#include "KhaiBao.h"

// Phụ trách: Thành: độc giả/lịch sử; Thái: sách
// Khung giao tiếp đề xuất. Xem docs/HUONG_DAN_KHUNG_CODE.md trước khi cài.

// THÁI. Đọc cả đầu sách/cuốn và thông tin cấp mã nếu thiết kế cần. Chốt định dạng trước; dữ liệu không hợp lệ không được làm mất bản đang có.
bool docSach(const string& duongDan, DanhSachDauSach& ds, string& loi);

// THÁI. Lưu dữ liệu sách theo định dạng chung, không ghi địa chỉ con trỏ/đối tượng string thô. Báo cả lỗi ghi.
bool ghiSach(const string& duongDan, const DanhSachDauSach& ds, string& loi);

// THÀNH. Đọc độc giả+lịch sử và bộ cấp mã. Sách phải được nạp để kiểm tra tham chiếu; lỗi thì giữ dữ liệu hiện có. Chốt định dạng trước.
bool docDocGiaVaMuonTra(const string& duongDan, CayDocGia& cay, const DanhSachDauSach& dsSach, int& maTheTiepTheo, string& loi);

// THÀNH. Lưu độc giả, toàn bộ lịch sử và bộ cấp mã; không chỉ lưu max mã hiện còn trong cây. Báo lỗi ghi.
bool ghiDocGiaVaMuonTra(const string& duongDan, const CayDocGia& cay, int maTheTiepTheo, string& loi);
