#pragma once
#include "KhaiBao.h"

// Phụ trách: Thành
// Khung giao tiếp đề xuất. Xem docs/HUONG_DAN_KHUNG_CODE.md trước khi cài.

// Tìm độc giả theo mã; trả nullptr khi không thấy. Con trỏ mượn từ cây, bên gọi không delete. Không sửa dữ liệu.
DocGia* timDocGia(CayDocGia& cay, int maThe);

// Bản tra cứu chỉ đọc dành cho Tấn/Thái; không thay đổi cây hoặc lịch sử.
const DocGia* timDocGia(const CayDocGia& cay, int maThe);

// Mục a. Cấp mã và thêm độc giả hợp lệ; chỉ cập nhật bộ cấp mã khi thành công. Không tái dùng mã đã cấp, kể cả sau xóa/mở lại.
bool themDocGia(CayDocGia& cay, const string& ho, const string& ten, const string& phai, int& maTheTiepTheo, string& loi);

// Mục a. Chỉ sửa thông tin được phép; giữ mã thẻ, liên kết cây và lịch sử. Sai dữ liệu thì không cập nhật dở dang.
bool suaDocGia(CayDocGia& cay, int maThe, const string& ho, const string& ten, const string& phai, int trangThaiThe, string& loi);

// Mục a. CHƯA CHỐT: điều kiện xóa khi có lịch sử/đang mượn. Chốt quy tắc trước khi cài; không làm mất tham chiếu hoặc rò bộ nhớ.
bool xoaDocGia(CayDocGia& cay, int maThe, string& loi);

// Giải phóng cây và lịch sử thuộc từng độc giả; kết thúc cây rỗng. Phối hợp giaiPhongMuonTra của Thành.
void giaiPhongDocGia(CayDocGia& cay);

// Màn hình a: nhập/hiệu chỉnh/xóa, gọi hàm nghiệp vụ, báo kết quả và quay lại. Mục b chuyển cho màn hình của Tấn.
void manHinhQuanLyDocGia(ThuVien& thuVien, int& maTheTiepTheo);
