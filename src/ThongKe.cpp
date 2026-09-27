#include "ThongKe.h"
#include "MuonTra.h"
#include "Sach.h"
#include <stdexcept>

// Phụ trách: Thái
// Các hàm chưa cài sẽ ném logic_error, không giả vờ xử lý thành công.

// Mục i. Thống kê quá hạn giảm dần. CHƯA CHỐT: một độc giả có nhiều cuốn quá hạn thì lấy mốc nào; chốt trước khi cài. Dùng phần tính ngày của Thành.
void manHinhDocGiaQuaHan(const ThuVien& thuVien, const NgayThang& ngayHienTai)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)thuVien;
    (void)ngayHienTai;
    // Biến cục bộ gợi ý (chưa khai báo): trang, ketQuaTam: tên gợi ý; kiểu/biểu diễn tạm do người viết đề xuất.
    // TODO(Thái): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: ThongKe::manHinhDocGiaQuaHan");
}

// Mục j. CHƯA CHỐT: theo đầu sách/cuốn, đồng hạng và cách tính lượt mất sách. Chốt trước khi cài; không tự thêm bộ đếm vào struct.
void manHinhTop10(const ThuVien& thuVien)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)thuVien;
    // Biến cục bộ gợi ý (chưa khai báo): soKetQua, ketQuaTam: tên gợi ý, chưa quy định cấu trúc tạm.
    // TODO(Thái): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: ThongKe::manHinhTop10");
}
