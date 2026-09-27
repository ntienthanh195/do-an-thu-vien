#include "Sach.h"
#include <stdexcept>

// Phụ trách: Thái
// Các hàm chưa cài sẽ ném logic_error, không giả vờ xử lý thành công.

// Tra cứu đầu sách; nullptr nếu không thấy. Không sửa thứ tự mảng; bên gọi không delete con trỏ trả về.
DauSach* timDauSachTheoISBN(DanhSachDauSach& ds, const string& isbn)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)ds;
    (void)isbn;
    // Biến cục bộ gợi ý (chưa khai báo): i: vị trí đang xét.
    // TODO(Thái): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: Sach::timDauSachTheoISBN");
}

// Tra cứu cuốn cho Thành dùng khi mượn/trả; nullptr nếu không thấy, con trỏ thuộc danh mục.
CuonSach* timCuonSach(DanhSachDauSach& ds, const string& maSach)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)ds;
    (void)maSach;
    // Biến cục bộ gợi ý (chưa khai báo): i, p: vị trí đầu sách và nút cuốn.
    // TODO(Thái): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: Sach::timCuonSach");
}

// Tra cứu chỉ đọc cho liệt kê/thống kê; không sửa trạng thái.
const CuonSach* timCuonSach(const DanhSachDauSach& ds, const string& maSach)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)ds;
    (void)maSach;
    // Biến cục bộ gợi ý (chưa khai báo): i, p: dữ liệu duyệt.
    // TODO(Thái): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: Sach::timCuonSach");
}

// Cho Tấn lấy tên sách ở mục h; trả đầu sách chứa mã cuốn hoặc nullptr.
const DauSach* timDauSachChuaCuon(const DanhSachDauSach& ds, const string& maSach)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)ds;
    (void)maSach;
    // Biến cục bộ gợi ý (chưa khai báo): i, p: dữ liệu duyệt.
    // TODO(Thái): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: Sach::timDauSachChuaCuon");
}

// Mục c. Thêm đầu sách hợp lệ trong sức chứa, giữ thứ tự tên; thất bại không đổi danh sách. MAX_DAU_SACH là đề xuất nhóm, chưa phải giới hạn thầy xác nhận.
bool themDauSach(DanhSachDauSach& ds, const string& isbn, const string& tenSach, int soTrang, const string& tacGia, int namXuatBan, const string& theLoai, string& loi)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)ds;
    (void)isbn;
    (void)tenSach;
    (void)soTrang;
    (void)tacGia;
    (void)namXuatBan;
    (void)theLoai;
    (void)loi;
    // Biến cục bộ gợi ý (chưa khai báo): dauSachMoi, viTriChen: biến hỗ trợ dự kiến.
    // TODO(Thái): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: Sach::themDauSach");
}

// Mục c. Cấp mã duy nhất, gắn cuốn vào đầu sách. Nhóm chốt quy tắc mã và lưu thông tin cấp mã nếu cần trước khi cài; chỉ xuất maSachDaCap khi thành công.
bool themCuonSach(DanhSachDauSach& ds, const string& isbn, const string& viTri, string& maSachDaCap, string& loi)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)ds;
    (void)isbn;
    (void)viTri;
    (void)maSachDaCap;
    (void)loi;
    // Biến cục bộ gợi ý (chưa khai báo): dauSach, cuonMoi: đối tượng cần dùng.
    // TODO(Thái): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: Sach::themCuonSach");
}

// Giải phóng các cuốn và đầu sách, đưa danh sách về rỗng; không giải phóng dữ liệu độc giả.
void giaiPhongSach(DanhSachDauSach& ds)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)ds;
    // Biến cục bộ gợi ý (chưa khai báo): i, p: vị trí và nút cần xử lý.
    // TODO(Thái): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: Sach::giaiPhongSach");
}

// Màn hình c. Nhập đầu sách/cuốn, gọi thao tác nền và thông báo.
void manHinhNhapSach(ThuVien& thuVien)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)thuVien;
    // Biến cục bộ gợi ý (chưa khai báo): luaChon, isbn, tenSach, viTri, loi: dữ liệu biểu mẫu.
    // TODO(Thái): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: Sach::manHinhNhapSach");
}

// Mục e. Nhập tên cần tìm và xuất đầy đủ thông tin đề yêu cầu, hỗ trợ danh sách dài. Chốt tìm chính xác/một phần với nhóm.
void manHinhTimSachTheoTen(const ThuVien& thuVien)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)thuVien;
    // Biến cục bộ gợi ý (chưa khai báo): tuKhoa, trang: từ tìm kiếm và trang đang xem.
    // TODO(Thái): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: Sach::manHinhTimSachTheoTen");
}
