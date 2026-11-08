# Demo đồ án Thư viện

Trên Windows, cài MinGW-w64 có lệnh `g++` trong PATH, rồi nhấp đúp **ChayDemo.cmd**. Bản hiện tại đọc và tự lưu trực tiếp vào [demo/DuLieu/DuLieuMau.txt](DuLieu/DuLieuMau.txt), gồm 3 đầu sách, 9 cuốn và 4 độc giả. Mỗi thao tác thành công được lưu trước khi cho làm tiếp. Nên sao lưu file này trước khi trình diễn để có thể bắt đầu lại.

Để xem cả 18 file trong Dev-C++ 5.11, tải toàn bộ repo, mở [demo.dev](../demo.dev) ở thư mục gốc rồi nhấn **F11**. Project dùng GCC trong `C:/msys64/ucrt64/bin`. Nếu máy cài MinGW-w64 ở nơi khác, chỉnh `CXXDIR` trong [demo.mk](../demo.mk) đến thư mục chứa `g++.exe`.

## Dữ liệu để trình thầy

Bộ mẫu hiện tại được rút gọn để thao tác demo, có 3 đầu sách, 9 cuốn, 4 độc giả và 7 lượt mượn (4 đã trả, 3 đang mượn). Nội dung dùng chữ không dấu để đọc trong Dev-C++.

Trong cây project Dev-C++, bấm `DuLieuMau.txt` cạnh 18 file mã nguồn để xem dữ liệu. Dòng đầu là mốc mã thẻ đã cấp (41), dòng thứ hai là số đầu sách. Mỗi đầu sách ghi `ISBN|ten|soTrang|tacGia|namXuatBan|theLoai|soCuon`, tiếp theo là các dòng `maCuon|trangThai|viTri`. Sau toàn bộ sách là số độc giả; mỗi độc giả ghi `maThe|ho|ten|phai|trangThaiThe|soLuot`, tiếp theo là các dòng `maCuon|ngayMuon|ngayTra|trangThaiMuon`.

Mã trạng thái cuốn: 0 còn cho mượn, 1 đang mượn, 2 thanh lý. Trạng thái thẻ: 0 khóa, 1 hoạt động. Trạng thái lượt mượn: 0 đang mượn, 1 đã trả, 2 báo mất; `0/0/0` là ngày trả chưa có. Đây là ba nhóm mã riêng biệt.

Dữ liệu có lịch sử đến 07/11/2026. Ngày này, thẻ 7 và 12 đang giữ sách quá hạn; thẻ 18 bị khóa; thẻ 41 đang giữ S002. Các cuốn S005, S007, S006, S008 và S009 còn cho mượn. Mốc mã 41 khiến thẻ thêm tiếp theo là 42.

Để thử trên bản sao, sao chép file mẫu ra một đường dẫn riêng rồi chạy `demo.exe --data "duong-dan-ban-sao.txt"` từ thư mục gốc repo.

## Một lượt trình bày

1. Chọn **e**, gõ `truc` để tìm *Cau truc du lieu*. Xem từng mã cuốn, vị trí và trạng thái.
2. Chọn **a** để thêm độc giả, ghi lại mã thẻ vừa cấp. Chọn **f**, tìm độc giả theo mã hoặc tên, nhập mã cuốn còn cho mượn rồi Enter. Bảng đang giữ cập nhật tại chỗ; tiếp tục cùng thẻ đến tối đa 3 cuốn hoặc chọn Kết thúc.
3. Chọn **h** và nhập mã thẻ để xem cuốn đang giữ. Chọn **g**, tìm độc giả rồi chọn cuốn ngay trong bảng đang giữ để trả liên tiếp. Báo mất có bước xác nhận khóa thẻ. Mở **j** để xem lượt mượn của đầu sách sau khi trả.
4. Chọn **i** để xem các độc giả còn giữ sách quá hạn. Mục này dùng cùng mốc với chức năng mượn của Thành. Ví dụ, mượn ngày 01, đến ngày 07 vẫn trong hạn, ngày 08 là ngày quá hạn đầu tiên.

Giao diện hỗ trợ chuột, phím mũi tên và Enter. Trong biểu mẫu, dùng Tab/Enter để đến nút lưu hoặc bấm nút bằng chuột. Các form thêm độc giả, đầu sách và cuốn hỗ trợ Lưu và nhập tiếp; Esc/Kết thúc để dừng. Mượn/trả cập nhật ngay trên màn hình sau khi lưu; Enter trên ô trống sau giao dịch không tạo thêm giao dịch. Khi nhập đầu sách mới ở **c**, dùng ISBN 13 chữ số và vị trí dạng `A-01-01`. Mã cuốn mới có dạng `ISBN#1`.

## Đọc code theo chức năng

- **a–b · Độc giả** — `QuanLyDocGia.cpp` dùng cây AVL theo mã thẻ. `InDanhSachDocGia.cpp` duyệt theo mã hoặc tự sắp theo tên, họ.
- **c–e · Sách** — `NhapSach.cpp` chèn đầu sách vào mảng con trỏ, `CuonSach.cpp` quản lý danh sách cuốn. Phần in theo thể loại ở `InDauSachTheoTheLoai.cpp`, tìm theo tên ở `TimSach.cpp`.
- **f–h · Mượn trả** — `MuonSach.cpp`, `TraSach.cpp`, `SachDangMuon.cpp` dùng danh sách lịch sử trong `LichSuMuonTra.cpp`.
- **i–j · Thống kê** — `DocGiaQuaHan.cpp` xếp độc giả theo số ngày quá hạn. `Top10Sach.cpp` cộng các lượt mượn theo đầu sách rồi chọn tối đa 10 đầu sách.
- **Phần chung** — `00_KhaiBaoChung.h` chứa cấu trúc và khai báo hàm. `01_HamTienIch.cpp` xử lý chuỗi và ngày. `LuuDocFile.cpp` kiểm tra, đọc và ghi dữ liệu. Các mã trạng thái là hằng số trong `00_KhaiBaoChung.h`. Hàm `main` tạo thư viện và phiên giao diện. Hàm kiểm tra trạng thái sách nhận giá trị cần kiểm tra qua lời gọi `HopLeTrangThaiSach(s.trangThai)`. Phần chọn chức năng nằm ở `Menu.cpp`.

Các nhãn `[THANH]` và `[THAI]` đánh dấu code nhóm đã bàn giao. Nhãn `[DEMO - CODEX]` chỉ phần Codex viết, điều chỉnh hoặc tích hợp từ bản tham khảo thủ công. Các thao tác tìm, sắp xếp, tách trường, chuyển số và duyệt cấu trúc đều dùng hàm tự viết. Chương trình dùng chuỗi C++, luồng nhập/xuất và API Windows cho tệp, ngày hệ thống, Unicode, bàn phím và chuột.

## Kiểm tra bản cập nhật 07/11/2026

Đã biên dịch C++11 với `-Wall -Wextra -Wpedantic -Werror`, chạy 30 ca CLI và kiểm thử sự kiện console Windows ở 80×24/120×32 cho chọn theo tên/mã, mượn/trả liên tục, giới hạn 3 cuốn, báo mất, lưu/đọc lại và lỗi lưu. Các kiểm thử console dùng bàn phím/chuột giả lập; cần thao tác thử trên máy trình diễn.

Mục còn theo dõi riêng: chặn một độc giả giữ đồng thời hai cuốn khác mã của cùng đầu sách. Bản này chưa bổ sung điều kiện đó.
