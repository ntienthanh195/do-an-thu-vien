#pragma once
#include "KhaiBao.h"

// Phụ trách: Tấn
// Khung giao tiếp đề xuất. Xem docs/HUONG_DAN_KHUNG_CODE.md trước khi cài.

// Mục h — làm đầu tiên. Nhập mã thẻ, tự tra cứu/duyệt/lọc và in mã + tên các cuốn đang mượn; không sửa dữ liệu. Dùng timDocGia và timDauSachChuaCuon.
void manHinhSachDangMuon(const ThuVien& thuVien);

// Mục b, lựa chọn theo mã tăng dần. Tự viết phần duyệt BST và hiển thị. Có thể tự thêm hàm phụ trong LietKe.cpp.
void manHinhDocGiaTheoMa(const ThuVien& thuVien);

// Mục b, lựa chọn tên+họ tăng dần. Tự chuẩn bị thứ tự kết quả, không phá BST theo mã. Chốt cách so sánh chuỗi và đồng tên với nhóm.
void manHinhDocGiaTheoTenHo(const ThuVien& thuVien);

// Mục d. Tự nhóm thể loại và sắp tên trong nhóm khi hiển thị; giữ mảng đầu sách gốc tăng theo tên.
void manHinhDauSachTheoTheLoai(const ThuVien& thuVien);
