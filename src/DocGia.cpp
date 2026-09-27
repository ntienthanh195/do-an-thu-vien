#include "DocGia.h"
#include <stdexcept>

// Phụ trách: Thành
// Các hàm chưa cài sẽ ném logic_error, không giả vờ xử lý thành công.

// Tìm độc giả theo mã; trả nullptr khi không thấy. Con trỏ mượn từ cây, bên gọi không delete. Không sửa dữ liệu.
DocGia* timDocGia(CayDocGia& cay, int maThe)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)cay;
    (void)maThe;
    // Biến cục bộ gợi ý (chưa khai báo): p: nút đang xét trong cây.
    // TODO(Thành): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: DocGia::timDocGia");
}

// Bản tra cứu chỉ đọc dành cho Tấn/Thái; không thay đổi cây hoặc lịch sử.
const DocGia* timDocGia(const CayDocGia& cay, int maThe)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)cay;
    (void)maThe;
    // Biến cục bộ gợi ý (chưa khai báo): p: nút đang xét.
    // TODO(Thành): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: DocGia::timDocGia");
}

// Mục a. Cấp mã và thêm độc giả hợp lệ; chỉ cập nhật bộ cấp mã khi thành công. Không tái dùng mã đã cấp, kể cả sau xóa/mở lại.
bool themDocGia(CayDocGia& cay, const string& ho, const string& ten, const string& phai, int& maTheTiepTheo, string& loi)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)cay;
    (void)ho;
    (void)ten;
    (void)phai;
    (void)maTheTiepTheo;
    (void)loi;
    // Biến cục bộ gợi ý (chưa khai báo): maMoi: mã dự kiến; nutMoi: nút được tạo. Tự xử lý giới hạn kiểu int.
    // TODO(Thành): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: DocGia::themDocGia");
}

// Mục a. Chỉ sửa thông tin được phép; giữ mã thẻ, liên kết cây và lịch sử. Sai dữ liệu thì không cập nhật dở dang.
bool suaDocGia(CayDocGia& cay, int maThe, const string& ho, const string& ten, const string& phai, int trangThaiThe, string& loi)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)cay;
    (void)maThe;
    (void)ho;
    (void)ten;
    (void)phai;
    (void)trangThaiThe;
    (void)loi;
    // Biến cục bộ gợi ý (chưa khai báo): docGia: độc giả cần sửa.
    // TODO(Thành): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: DocGia::suaDocGia");
}

// Mục a. CHƯA CHỐT: điều kiện xóa khi có lịch sử/đang mượn. Chốt quy tắc trước khi cài; không làm mất tham chiếu hoặc rò bộ nhớ.
bool xoaDocGia(CayDocGia& cay, int maThe, string& loi)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)cay;
    (void)maThe;
    (void)loi;
    // Biến cục bộ gợi ý (chưa khai báo): nutCanXoa: nút ứng với mã; các con trỏ phụ do người viết tự chọn.
    // TODO(Thành): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: DocGia::xoaDocGia");
}

// Giải phóng cây và lịch sử thuộc từng độc giả; kết thúc cây rỗng. Phối hợp giaiPhongMuonTra của Thành.
void giaiPhongDocGia(CayDocGia& cay)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)cay;
    // Biến cục bộ gợi ý (chưa khai báo): Các con trỏ duyệt do người viết tự chọn; không sao chép cây để giải phóng.
    // TODO(Thành): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: DocGia::giaiPhongDocGia");
}

// Màn hình a: nhập/hiệu chỉnh/xóa, gọi hàm nghiệp vụ, báo kết quả và quay lại. Mục b chuyển cho màn hình của Tấn.
void manHinhQuanLyDocGia(ThuVien& thuVien, int& maTheTiepTheo)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)thuVien;
    (void)maTheTiepTheo;
    // Biến cục bộ gợi ý (chưa khai báo): luaChon, maThe, ho, ten, phai, loi: dữ liệu nhập và thông báo.
    // TODO(Thành): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: DocGia::manHinhQuanLyDocGia");
}
