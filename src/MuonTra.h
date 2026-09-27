#pragma once
#include "KhaiBao.h"

// Phụ trách: Thành
// Khung giao tiếp đề xuất. Xem docs/HUONG_DAN_KHUNG_CODE.md trước khi cài.

// Kiểm tra ngày lịch; 0/0/0 chỉ là ký hiệu chưa trả, không phải ngày lịch hợp lệ.
bool ngayHopLe(const NgayThang& ngay);

// Đầu vào phải là hai ngày hợp lệ. Trả số ngày denNgay trừ tuNgay; có thể âm. Không tự lấy ngày hiện tại bên trong.
int soNgayGiua(const NgayThang& tuNgay, const NgayThang& denNgay);

// Đếm các lần mượn đang hoạt động theo trạng thái; không lấy tổng số nút lịch sử làm số cuốn đang mượn.
int demSachDangMuon(const DocGia& docGia);

// Kiểm tra sách đang mượn quá hạn theo mốc 7 ngày của đề; nhóm chốt cách hiểu ngày biên và dùng chung ở f/i.
bool coSachQuaHan(const DocGia& docGia, const NgayThang& ngayHienTai);

// Mục f. Kiểm tra thẻ, cuốn, giới hạn 3 cuốn, quá hạn và ngày; thành công thì lịch sử/cuốn nhất quán, thất bại không đổi dữ liệu. Không in hoặc nhập trong hàm.
bool muonSach(ThuVien& thuVien, int maThe, const string& maSach, const NgayThang& ngayMuon, string& loi);

// Mục g. Tìm đúng lần đang mượn, kiểm tra ngày; trả lặp không ghi nhận lần nữa, giữ lịch sử. Trường hợp mất sách chưa được khung này quyết định thay nhóm.
bool traSach(ThuVien& thuVien, int maThe, const string& maSach, const NgayThang& ngayTra, string& loi);

// Giải phóng danh sách lịch sử và đưa con trỏ đầu về nullptr. Chỉ gọi khi hợp lệ theo quyền sở hữu dữ liệu.
void giaiPhongMuonTra(MuonTra*& dau);

// Màn hình f. Hiển thị sách đang mượn qua phần của Tấn, nhận dữ liệu và gọi muonSach; báo lý do thất bại.
void manHinhMuonSach(ThuVien& thuVien);

// Màn hình g. Chọn/nhập lần mượn cần trả, gọi traSach, hiển thị kết quả.
void manHinhTraSach(ThuVien& thuVien);
