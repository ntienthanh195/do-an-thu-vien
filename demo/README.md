# Demo đồ án Thư viện

Trên Windows, cài MinGW-w64 có lệnh `g++` trong PATH, rồi nhấp đúp **ChayDemo.cmd**. Lần đầu chương trình đọc 20 đầu sách, 60 cuốn và 20 độc giả từ [demo/DuLieu/DuLieuMau.txt](DuLieu/DuLieuMau.txt). Khi thao tác thành công, bản demo lưu vào `DuLieu/runtime/ThuVien.txt`. Lần mở sau sẽ tiếp tục từ đó.

Để xem cả 18 file trong Dev-C++ 5.11, tải toàn bộ repo, mở [demo.dev](../demo.dev) ở thư mục gốc rồi nhấn **F11**. Project dùng GCC trong `C:/msys64/ucrt64/bin`. Nếu máy cài MinGW-w64 ở nơi khác, chỉnh `CXXDIR` trong [demo.mk](../demo.mk) đến thư mục chứa `g++.exe`.

## Dữ liệu để trình thầy

Thư mục `demo/DuLieu` chứa dữ liệu giả lập để trình bày, đã mở rộng bằng Codex từ mẫu ban đầu của nhóm. Toàn bộ nội dung `DuLieuMau.txt` dùng chữ không dấu (ASCII) để xem trong Dev-C++ 5.11: **20 đầu sách, 60 cuốn, 20 độc giả và 50 lượt mượn** (38 đã trả, 10 đang mượn, 2 báo mất). Có 7 thể loại, 3 thẻ bị khóa và 1 độc giả đang giữ đủ 3 cuốn. Các tên và tác giả chỉ là dữ liệu minh họa.

Trong cây project Dev-C++, bấm `DuLieuMau.txt` cạnh 18 file mã nguồn để xem dữ liệu. Dòng đầu là mốc mã thẻ đã cấp (40), dòng thứ hai là số đầu sách. Mỗi đầu sách ghi `ISBN|ten|soTrang|tacGia|namXuatBan|theLoai|soCuon`, tiếp theo là các dòng `maCuon|trangThai|viTri`. Sau toàn bộ sách là số độc giả; mỗi độc giả ghi `maThe|ho|ten|phai|trangThaiThe|soLuot`, tiếp theo là các dòng `maCuon|ngayMuon|ngayTra|trangThaiMuon`.

Mã trạng thái cuốn: 0 còn cho mượn, 1 đang mượn, 2 thanh lý. Trạng thái thẻ: 0 khóa, 1 hoạt động. Trạng thái lượt mượn: 0 đang mượn, 1 đã trả, 2 báo mất; `0/0/0` là ngày trả chưa có. Đây là ba nhóm mã riêng biệt.

Ngày mẫu cố định đến 05/11/2026; kết quả quá hạn phụ thuộc ngày chạy. Khi trình ngày 07/11/2026, thẻ 7 và 12 quá hạn; thẻ 21 đang giữ 3 cuốn còn trong hạn; thẻ 18, 27, 28 bị khóa. Cuốn `S002` còn trên kệ để thử mượn. Mốc mã 40 khiến thẻ thêm tiếp theo là 41.

Tệp mẫu được giữ riêng; các thay đổi khi demo lưu vào `DuLieu/runtime/ThuVien.txt` ở thư mục gốc repo. Nếu đã chạy trước đó, chương trình tiếp tục phiên đã lưu thay vì nạp lại mẫu. Để trình bày lại từ mẫu, đóng chương trình, sao lưu rồi đổi tên tệp phiên này trước khi chạy lại.

## Một lượt trình bày

1. Chọn **e**, gõ `truc` để tìm *Cau truc du lieu*. Xem từng mã cuốn, vị trí và trạng thái.
2. Chọn **a** để thêm độc giả, ghi lại mã thẻ vừa cấp. Chọn **f** để mượn cuốn `S002` còn trên kệ trong dữ liệu mẫu.
3. Chọn **h** và nhập mã thẻ để xem cuốn đang giữ. Chọn **g** để trả, rồi mở lại **h**. Mở **j** để xem lượt mượn của đầu sách sau khi trả.
4. Chọn **i** để xem các độc giả còn giữ sách quá hạn. Mục này dùng cùng mốc với chức năng mượn của Thành. Ví dụ, mượn ngày 01, đến ngày 07 vẫn trong hạn, ngày 08 là ngày quá hạn đầu tiên.

Giao diện hỗ trợ chuột, phím mũi tên và Enter. Trong biểu mẫu, dùng Tab để chuyển ô, Ctrl+Enter để xác nhận hoặc Esc để hủy. Khi nhập đầu sách mới ở **c**, dùng ISBN 13 chữ số và vị trí dạng `A-01-01`. Mã cuốn mới có dạng `ISBN#1`.

## Đọc code theo chức năng

- **a–b · Độc giả** — `QuanLyDocGia.cpp` dùng cây AVL theo mã thẻ. `InDanhSachDocGia.cpp` duyệt theo mã hoặc tự sắp theo tên, họ.
- **c–e · Sách** — `NhapSach.cpp` chèn đầu sách vào mảng con trỏ, `CuonSach.cpp` quản lý danh sách cuốn. Phần in theo thể loại ở `InDauSachTheoTheLoai.cpp`, tìm theo tên ở `TimSach.cpp`.
- **f–h · Mượn trả** — `MuonSach.cpp`, `TraSach.cpp`, `SachDangMuon.cpp` dùng danh sách lịch sử trong `LichSuMuonTra.cpp`.
- **i–j · Thống kê** — `DocGiaQuaHan.cpp` xếp độc giả theo số ngày quá hạn. `Top10Sach.cpp` cộng các lượt mượn theo đầu sách rồi chọn tối đa 10 đầu sách.
- **Phần chung** — `00_KhaiBaoChung.h` chứa cấu trúc và khai báo hàm. `01_HamTienIch.cpp` xử lý chuỗi và ngày. `LuuDocFile.cpp` kiểm tra, đọc và ghi dữ liệu. Các mã trạng thái là hằng số trong `00_KhaiBaoChung.h`. Hàm `main` tạo thư viện và phiên giao diện. Hàm kiểm tra trạng thái sách nhận giá trị cần kiểm tra qua lời gọi `HopLeTrangThaiSach(s.trangThai)`. Phần chọn chức năng nằm ở `Menu.cpp`.

Các nhãn `[THANH]` và `[THAI]` đánh dấu code nhóm đã bàn giao. Nhãn `[DEMO - CODEX]` chỉ phần Codex viết, điều chỉnh hoặc tích hợp từ bản tham khảo thủ công. Các thao tác tìm, sắp xếp, tách trường, chuyển số và duyệt cấu trúc đều dùng hàm tự viết. Chương trình dùng chuỗi C++, luồng nhập/xuất và API Windows cho tệp, ngày hệ thống, Unicode, bàn phím và chuột.
