#pragma once
#include "KhaiBao.h"

// Phụ trách: Thái
// Khung giao tiếp đề xuất. Xem docs/HUONG_DAN_KHUNG_CODE.md trước khi cài.

// Tra cứu đầu sách; nullptr nếu không thấy. Không sửa thứ tự mảng; bên gọi không delete con trỏ trả về.
DauSach* timDauSachTheoISBN(DanhSachDauSach& ds, const string& isbn);

// Tra cứu cuốn cho Thành dùng khi mượn/trả; nullptr nếu không thấy, con trỏ thuộc danh mục.
CuonSach* timCuonSach(DanhSachDauSach& ds, const string& maSach);

// Tra cứu chỉ đọc cho liệt kê/thống kê; không sửa trạng thái.
const CuonSach* timCuonSach(const DanhSachDauSach& ds, const string& maSach);

// Cho Tấn lấy tên sách ở mục h; trả đầu sách chứa mã cuốn hoặc nullptr.
const DauSach* timDauSachChuaCuon(const DanhSachDauSach& ds, const string& maSach);

// Mục c. Thêm đầu sách hợp lệ trong sức chứa, giữ thứ tự tên; thất bại không đổi danh sách. MAX_DAU_SACH là đề xuất nhóm, chưa phải giới hạn thầy xác nhận.
bool themDauSach(DanhSachDauSach& ds, const string& isbn, const string& tenSach, int soTrang, const string& tacGia, int namXuatBan, const string& theLoai, string& loi);

// Mục c. Cấp mã duy nhất, gắn cuốn vào đầu sách. Nhóm chốt quy tắc mã và lưu thông tin cấp mã nếu cần trước khi cài; chỉ xuất maSachDaCap khi thành công.
bool themCuonSach(DanhSachDauSach& ds, const string& isbn, const string& viTri, string& maSachDaCap, string& loi);

// Giải phóng các cuốn và đầu sách, đưa danh sách về rỗng; không giải phóng dữ liệu độc giả.
void giaiPhongSach(DanhSachDauSach& ds);

// Màn hình c. Nhập đầu sách/cuốn, gọi thao tác nền và thông báo.
void manHinhNhapSach(ThuVien& thuVien);

// Mục e. Nhập tên cần tìm và xuất đầy đủ thông tin đề yêu cầu, hỗ trợ danh sách dài. Chốt tìm chính xác/một phần với nhóm.
void manHinhTimSachTheoTen(const ThuVien& thuVien);
