#include "Menu.h"
#include "DocGia.h"
#include "MuonTra.h"
#include "Sach.h"
#include "ThongKe.h"
#include "LietKe.h"
#include "DuLieu.h"
#include "GiaoDien.h"
#include <stdexcept>

// Phụ trách: Tấn; Thành nối điều phối
// Các hàm chưa cài sẽ ném logic_error, không giả vờ xử lý thành công.

// Điều khiển menu và gọi màn hình phụ trách a–j; không cài thuật toán nghiệp vụ ở đây. Thống nhất nạp/lưu/thoát với Thành; không tự quyết định cách bỏ thay đổi chưa lưu.
void chayMenuChinh(ThuVien& thuVien, int& maTheTiepTheo)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)thuVien;
    (void)maTheTiepTheo;
    // Biến cục bộ gợi ý (chưa khai báo): luaChon: mục chọn; dangChay: điều khiển vòng menu; ngayHienTai: ngày dùng thống kê; loi: thông báo.
    // TODO(Tấn; Thành nối điều phối): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: Menu::chayMenuChinh");
}
