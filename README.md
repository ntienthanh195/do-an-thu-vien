# Đồ án CTDL — Quản lý Thư viện

Đồ án nhóm đề số 3: quản lý sách, độc giả và mượn–trả bằng C++, với giao diện console tương tác và dữ liệu đọc/ghi file.

## Thành viên và nhiệm vụ

- **Thành:** a, f, g; độc giả, mượn–trả, ngày tháng, đọc/ghi độc giả và lịch sử; điều phối tích hợp.
- **Thái:** c, e, i, j; sách, thống kê, đọc/ghi sách và giao diện các chức năng tương ứng.
- **Tấn:** b, d, h; liệt kê dữ liệu và màn hình tương ứng; menu chính. Làm lần lượt h, b theo mã, b theo tên+họ, d.

Chi tiết ở [phân công nhóm](docs/PHAN_CONG_DO_AN_THU_VIEN.md), phần A. Phần B là lịch sử mốc khai báo, không thay phân công hiện hành.

**Giao diện console:** cả ba tự làm màn hình phần mình (Thành: a, f, g; Thái: c, e, i, j; Tấn: b, d, h và menu). Cùng thống nhất bố cục, phím và các phần dùng chung; chia người phụ trách từng phần dùng chung khi có nhu cầu, không mặc định dồn cho Thái.

## Yêu cầu cấu trúc

- Đầu sách: mảng con trỏ, luôn tăng theo tên sách.
- Cuốn sách: danh sách liên kết đơn.
- Độc giả: cây nhị phân tìm kiếm.
- Mượn–trả: danh sách liên kết đơn gắn với từng độc giả.

## Trạng thái ban đầu

`src/CODE-ĐỒ-ÁN-THƯ-VIỆN-DSA.cpp` là bản khai báo nhóm ngày 25/09/2026 được sao chép nguyên văn. Chưa có `main`, giao diện, chức năng a–j hoặc phần đọc/ghi dữ liệu; chưa phải chương trình hoàn chỉnh để chạy. Việc tạo repo không tạo thêm bằng chứng kiểm thử hoặc tiến độ triển khai.

Chưa chốt cấu hình build và định dạng dữ liệu. Nhóm sẽ bổ sung hướng dẫn chạy khi có bản thực thi đầu tiên.

## Cách làm việc

**Bắt đầu triển khai:** đọc [Hướng đi tự làm cho từng thành viên](docs/HUONG_DI_TU_LAM_CHO_TUNG_THANH_VIEN.md). Mỗi người tự thiết kế, tạo file, đặt tên hàm và viết code từ yêu cầu; repo không cung cấp bộ khung hàm để điền. Cả nhóm thống nhất cách gọi giữa các phần trước khi làm riêng.

**Thái và Tấn đọc trước:** [Hướng dẫn đặt file và đẩy code từng bước](docs/HUONG_DAN_DAY_CODE_CHO_NHOM.md) — vị trí file, GitHub Desktop, tạo nhánh, commit, push và gửi yêu cầu ghép.

Xem [hướng dẫn cộng tác](CONTRIBUTING.md). GitHub là nơi giữ bản code chung; Drive dành cho đề, tài liệu, ảnh/video và bản đóng gói khi cần. Ghi chú bàn giao Drive trong hồ sơ cũ được thay bằng quy trình GitHub đối với mã nguồn.

Mốc tích hợp đầu tiên: mở ứng dụng → đọc dữ liệu sách mẫu → menu → bảng sách xem được dữ liệu dài → quay lại → thoát. Đây là mục tiêu, chưa hoàn thành.
