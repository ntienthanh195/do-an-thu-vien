#include "GiaoDien.h"
#include <stdexcept>

// Phụ trách: Thái chính; Thành hỗ trợ
// Các hàm chưa cài sẽ ném logic_error, không giả vờ xử lý thành công.

// Xóa/chuẩn bị vùng hiển thị theo công cụ console nhóm chọn; chỉ gọi ở tầng giao diện.
void xoaManHinh()
{
    // Biến cục bộ gợi ý (chưa khai báo): Không cần biến bắt buộc.
    // TODO(Thái chính; Thành hỗ trợ): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: GiaoDien::xoaManHinh");
}

// Vẽ khung console tại tọa độ quy ước; kiểm tra kích thước phù hợp cửa sổ.
void veKhung(int x, int y, int rong, int cao, const string& tieuDe)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)x;
    (void)y;
    (void)rong;
    (void)cao;
    (void)tieuDe;
    // Biến cục bộ gợi ý (chưa khai báo): hang, cot: vị trí đang vẽ nếu cách cài cần.
    // TODO(Thái chính; Thành hỗ trợ): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: GiaoDien::veKhung");
}

// Các mục hợp lệ có soMuc > 0. Quy ước chỉ số trả về 0..soMuc-1, -1 là hủy/quay lại. Kết hợp phím số/Enter/mũi tên theo quy ước chung.
int chonMenu(const string* cacMuc, int soMuc)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)cacMuc;
    (void)soMuc;
    // Biến cục bộ gợi ý (chưa khai báo): viTriChon, phim: mục hiện tại và phím nhận.
    // TODO(Thái chính; Thành hỗ trợ): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: GiaoDien::chonMenu");
}

// Quy ước trang 1..tongSoTrang, trả 0 để quay lại; chỉ gọi khi tongSoTrang >= 1. Màn hình rỗng xử lý riêng.
int chonTrang(int trangHienTai, int tongSoTrang)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)trangHienTai;
    (void)tongSoTrang;
    // Biến cục bộ gợi ý (chưa khai báo): phim, trangMoi: dữ liệu điều hướng.
    // TODO(Thái chính; Thành hỗ trợ): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: GiaoDien::chonTrang");
}

// Hiển thị thông báo; thống nhất hành vi chờ phím với bên gọi để không chờ hai lần.
void thongBao(const string& noiDung, bool laLoi)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)noiDung;
    (void)laLoi;
    // Biến cục bộ gợi ý (chưa khai báo): Không cần biến bắt buộc.
    // TODO(Thái chính; Thành hỗ trợ): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: GiaoDien::thongBao");
}
