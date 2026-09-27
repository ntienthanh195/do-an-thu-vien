#include "LietKe.h"
#include "DocGia.h"
#include "Sach.h"
#include "GiaoDien.h"
#include <stdexcept>

// Phụ trách: Tấn
// Các hàm chưa cài sẽ ném logic_error, không giả vờ xử lý thành công.

// Mục h — làm đầu tiên. Nhập mã thẻ, tự tra cứu/duyệt/lọc và in mã + tên các cuốn đang mượn; không sửa dữ liệu. Dùng timDocGia và timDauSachChuaCuon.
void manHinhSachDangMuon(const ThuVien& thuVien)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)thuVien;
    // Biến cục bộ gợi ý (chưa khai báo): maThe: mã nhập; docGia: người tìm được; p: lần mượn đang xét; dauSach: nơi lấy tên; trang: trang hiển thị.
    // TODO(Tấn): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: LietKe::manHinhSachDangMuon");
}

// Mục b, lựa chọn theo mã tăng dần. Tự viết phần duyệt BST và hiển thị. Có thể tự thêm hàm phụ trong LietKe.cpp.
void manHinhDocGiaTheoMa(const ThuVien& thuVien)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)thuVien;
    // Biến cục bộ gợi ý (chưa khai báo): trang: trang hiển thị; các biến duyệt cây do Tấn tự chọn.
    // TODO(Tấn): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: LietKe::manHinhDocGiaTheoMa");
}

// Mục b, lựa chọn tên+họ tăng dần. Tự chuẩn bị thứ tự kết quả, không phá BST theo mã. Chốt cách so sánh chuỗi và đồng tên với nhóm.
void manHinhDocGiaTheoTenHo(const ThuVien& thuVien)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)thuVien;
    // Biến cục bộ gợi ý (chưa khai báo): trang, ketQuaTam: tên gợi ý; tự đề xuất cách lưu kết quả tạm.
    // TODO(Tấn): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: LietKe::manHinhDocGiaTheoTenHo");
}

// Mục d. Tự nhóm thể loại và sắp tên trong nhóm khi hiển thị; giữ mảng đầu sách gốc tăng theo tên.
void manHinhDauSachTheoTheLoai(const ThuVien& thuVien)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)thuVien;
    // Biến cục bộ gợi ý (chưa khai báo): trang, theLoaiDangIn, ketQuaTam: tên gợi ý, không bắt buộc dùng tất cả.
    // TODO(Tấn): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: LietKe::manHinhDauSachTheoTheLoai");
}
