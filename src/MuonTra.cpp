#include "MuonTra.h"
#include "DocGia.h"
#include "Sach.h"
#include <stdexcept>

// Phụ trách: Thành
// Các hàm chưa cài sẽ ném logic_error, không giả vờ xử lý thành công.

// Kiểm tra ngày lịch; 0/0/0 chỉ là ký hiệu chưa trả, không phải ngày lịch hợp lệ.
bool ngayHopLe(const NgayThang& ngay)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)ngay;
    // Biến cục bộ gợi ý (chưa khai báo): soNgayTrongThang: giới hạn cần kiểm tra; tự cài quy tắc năm nhuận.
    // TODO(Thành): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: MuonTra::ngayHopLe");
}

// Đầu vào phải là hai ngày hợp lệ. Trả số ngày denNgay trừ tuNgay; có thể âm. Không tự lấy ngày hiện tại bên trong.
int soNgayGiua(const NgayThang& tuNgay, const NgayThang& denNgay)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)tuNgay;
    (void)denNgay;
    // Biến cục bộ gợi ý (chưa khai báo): Các biến trung gian chuyển/tính ngày do người viết chọn.
    // TODO(Thành): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: MuonTra::soNgayGiua");
}

// Đếm các lần mượn đang hoạt động theo trạng thái; không lấy tổng số nút lịch sử làm số cuốn đang mượn.
int demSachDangMuon(const DocGia& docGia)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)docGia;
    // Biến cục bộ gợi ý (chưa khai báo): p: bản ghi đang xét; soLuong: kết quả đếm.
    // TODO(Thành): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: MuonTra::demSachDangMuon");
}

// Kiểm tra sách đang mượn quá hạn theo mốc 7 ngày của đề; nhóm chốt cách hiểu ngày biên và dùng chung ở f/i.
bool coSachQuaHan(const DocGia& docGia, const NgayThang& ngayHienTai)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)docGia;
    (void)ngayHienTai;
    // Biến cục bộ gợi ý (chưa khai báo): p: bản ghi; soNgay: khoảng thời gian. Không đổi dữ liệu.
    // TODO(Thành): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: MuonTra::coSachQuaHan");
}

// Mục f. Kiểm tra thẻ, cuốn, giới hạn 3 cuốn, quá hạn và ngày; thành công thì lịch sử/cuốn nhất quán, thất bại không đổi dữ liệu. Không in hoặc nhập trong hàm.
bool muonSach(ThuVien& thuVien, int maThe, const string& maSach, const NgayThang& ngayMuon, string& loi)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)thuVien;
    (void)maThe;
    (void)maSach;
    (void)ngayMuon;
    (void)loi;
    // Biến cục bộ gợi ý (chưa khai báo): docGia, cuonSach, banGhiMoi: các đối tượng liên quan; tự quyết định trình tự xử lý.
    // TODO(Thành): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: MuonTra::muonSach");
}

// Mục g. Tìm đúng lần đang mượn, kiểm tra ngày; trả lặp không ghi nhận lần nữa, giữ lịch sử. Trường hợp mất sách chưa được khung này quyết định thay nhóm.
bool traSach(ThuVien& thuVien, int maThe, const string& maSach, const NgayThang& ngayTra, string& loi)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)thuVien;
    (void)maThe;
    (void)maSach;
    (void)ngayTra;
    (void)loi;
    // Biến cục bộ gợi ý (chưa khai báo): docGia, cuonSach, lanMuon: thông tin cần tra cứu.
    // TODO(Thành): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: MuonTra::traSach");
}

// Giải phóng danh sách lịch sử và đưa con trỏ đầu về nullptr. Chỉ gọi khi hợp lệ theo quyền sở hữu dữ liệu.
void giaiPhongMuonTra(MuonTra*& dau)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)dau;
    // Biến cục bộ gợi ý (chưa khai báo): p: nút đang xử lý; con trỏ phụ do người viết chọn.
    // TODO(Thành): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: MuonTra::giaiPhongMuonTra");
}

// Màn hình f. Hiển thị sách đang mượn qua phần của Tấn, nhận dữ liệu và gọi muonSach; báo lý do thất bại.
void manHinhMuonSach(ThuVien& thuVien)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)thuVien;
    // Biến cục bộ gợi ý (chưa khai báo): maThe, maSach, ngayMuon, loi: dữ liệu nhập.
    // TODO(Thành): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: MuonTra::manHinhMuonSach");
}

// Màn hình g. Chọn/nhập lần mượn cần trả, gọi traSach, hiển thị kết quả.
void manHinhTraSach(ThuVien& thuVien)
{
    // Tạm đánh dấu tham số chưa dùng để khung build không có warning.
    (void)thuVien;
    // Biến cục bộ gợi ý (chưa khai báo): maThe, maSach, ngayTra, loi: dữ liệu nhập.
    // TODO(Thành): tự viết xử lý theo hợp đồng trên.
    // Khi cài xong: bỏ các (void) không còn cần và thay dòng throw dưới.
    throw std::logic_error("TODO: MuonTra::manHinhTraSach");
}
