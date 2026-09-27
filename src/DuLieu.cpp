#include "DuLieu.h"
#include <stdexcept>

// Phụ trách: Thành: độc giả/lịch sử; Thái: sách
// Các hàm chưa cài sẽ ném logic_error, không giả vờ xử lý thành công.

// THÁI. Đọc cả đầu sách/cuốn và thông tin cấp mã nếu thiết kế cần. Chốt định dạng trước; dữ liệu không hợp lệ không được làm mất bản đang có.
bool docSach(const string& duongDan, DanhSachDauSach& ds, string& loi)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)duongDan;
    (void)ds;
    (void)loi;
    // Biến cục bộ gợi ý (chưa khai báo): tep: luồng đọc; duLieuTam: vùng dựng dữ liệu; tự chọn cách quản lý.
    // TODO(Thành: độc giả/lịch sử; Thái: sách): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: DuLieu::docSach");
}

// THÁI. Lưu dữ liệu sách theo định dạng chung, không ghi địa chỉ con trỏ/đối tượng string thô. Báo cả lỗi ghi.
bool ghiSach(const string& duongDan, const DanhSachDauSach& ds, string& loi)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)duongDan;
    (void)ds;
    (void)loi;
    // Biến cục bộ gợi ý (chưa khai báo): tep: luồng ghi.
    // TODO(Thành: độc giả/lịch sử; Thái: sách): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: DuLieu::ghiSach");
}

// THÀNH. Đọc độc giả+lịch sử và bộ cấp mã. Sách phải được nạp để kiểm tra tham chiếu; lỗi thì giữ dữ liệu hiện có. Chốt định dạng trước.
bool docDocGiaVaMuonTra(const string& duongDan, CayDocGia& cay, const DanhSachDauSach& dsSach, int& maTheTiepTheo, string& loi)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)duongDan;
    (void)cay;
    (void)dsSach;
    (void)maTheTiepTheo;
    (void)loi;
    // Biến cục bộ gợi ý (chưa khai báo): tep, duLieuTam, maTiepTheoTam: dữ liệu đọc tạm.
    // TODO(Thành: độc giả/lịch sử; Thái: sách): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: DuLieu::docDocGiaVaMuonTra");
}

// THÀNH. Lưu độc giả, toàn bộ lịch sử và bộ cấp mã; không chỉ lưu max mã hiện còn trong cây. Báo lỗi ghi.
bool ghiDocGiaVaMuonTra(const string& duongDan, const CayDocGia& cay, int maTheTiepTheo, string& loi)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)duongDan;
    (void)cay;
    (void)maTheTiepTheo;
    (void)loi;
    // Biến cục bộ gợi ý (chưa khai báo): tep: luồng ghi.
    // TODO(Thành: độc giả/lịch sử; Thái: sách): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: DuLieu::ghiDocGiaVaMuonTra");
}
