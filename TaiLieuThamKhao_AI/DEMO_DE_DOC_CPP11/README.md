# Bản code dễ đọc — giữ giao diện console

Đây là bản bổ sung theo phong cách hàm, struct và con trỏ trong ví dụ của thầy. Giữ giao diện chuột/phím, biểu mẫu, màu, phân trang, tự lưu và khóa phiên của demo hiện tại. Code tham khảo do AI sửa; không phải bằng chứng nhóm tự viết.

**Chạy:** giải nén toàn bộ, nhấn `ChayDemo.bat`. **Build:** mở `ThuVien.dev` với compiler hỗ trợ C++11, hoặc chạy `powershell -ExecutionPolicy Bypass -File Build.ps1`. Chỉ dùng bốn header thư viện: `iostream`, `string`, `fstream`, `windows.h`; không cần cài thư viện khác. `HoTroHeThong.h` là file mã nguồn đi kèm, không phải thư viện ngoài.

## Đọc code từ đâu?

1. `MaNguon/00_KhaiBaoChung.h`: `using namespace std;`, hằng số, các struct và khai báo hàm. Bốn cấu trúc lưu dữ liệu giữ nguyên đề.
2. `02_XuLyDauSach.cpp` và `03_XuLyCuonSach.cpp`: mảng con trỏ, tìm, chèn, danh sách cuốn, cấp mã.
3. `04_XuLyDocGia.cpp`: BST; chèn/xóa dùng con trỏ `cha`, `p`, `keTiep` để thấy rõ liên kết thay đổi. Không sao chép nhầm lịch sử khi xóa nút hai con.
4. `05_XuLyMuonTra.cpp` và `06_NghiepVuTongHop.cpp`: danh sách lượt mượn, kiểm điều kiện, cập nhật trạng thái, quá hạn và top 10. Hàm vun đống/sắp xếp có tên riêng, không dùng template/lambda.
5. `01_HamTienIch.cpp`: tra khi cần xử lý chuỗi, số và ngày.

Các file 01–06 dùng con trỏ thường, `new/delete`, mảng tạm và hàm có tên; không còn `ConTroTam`, template, lambda hoặc tiền tố `std::`. Mỗi khối được xuống dòng để dễ đặt breakpoint và truy vết. Các mảng tạm được `delete[]` cả khi in/kiểm tra phát sinh lỗi; `try/catch` còn lại phục vụ việc dọn bộ nhớ, không thay thuật toán. Giữ cách sắp xếp hiệu quả hiện có, không đổi tất cả sang hai vòng lặp chỉ để ít cú pháp hơn.

Mã nguồn chỉ còn chỉ thị `#include`: đã bỏ `#ifndef`, `#ifdef`, `#else`, `#endif`, `#define`, `#error` và `#pragma once`. Hằng cấu hình dùng `const`. File `09_Main.cpp` chứa `main()` ngắn; phần khởi động và giao diện vẫn ở file 08. Bản này dành cho Windows. Mỗi file `.cpp` chỉ include khai báo chung một lần; không include các file `.cpp` vào nhau. Build cả chín file `.cpp` như Build.ps1 hoặc project Dev-C++ đã cấu hình.

## Phần kỹ thuật vẫn giữ

`HoTroHeThong.h` gom các lớp đệm, Unicode/đường dẫn Windows và hỗ trợ giao diện trước đây nằm ngay đầu khai báo chung. `07_LuuDocFile.cpp` vẫn kiểm dữ liệu trước khi thay kho; `08_ChuongTrinhChinh.cpp` vẫn điều khiển giao diện. Các phần này còn cú pháp nâng cao, gồm lớp/template trong hỗ trợ và sắp xếp nội bộ của bộ đọc. Đây **không phải** bản đã loại bỏ mọi class/template khỏi toàn chương trình. Tách chúng giúp phần CTDL nhóm cần đọc không bị lẫn với kỹ thuật console; không tuyên bố chỉ thêm `using namespace std` là đã đơn giản hóa toàn bộ hệ thống.

Giữ xử lý chữ đang hoạt động để không làm hỏng giao diện hoặc dữ liệu có dấu; nhóm không cần sửa cấu hình tiếng Việt để chạy exe kèm theo. Không sao chép `gets`, `fflush(stdin)` hay các đoạn chưa hoàn chỉnh trong ví dụ thầy vào bản này.

## Dữ liệu và tài liệu ôn

Mỗi lần mở `ChayDemo.bat` tạo bản sao dữ liệu mẫu riêng. Muốn tiếp tục một kho đã làm, chọn **Mở dữ liệu** trong giao diện hoặc chạy `build/ThuVien.exe --data DuLieu/runtime/ten-file.txt`. Không chọn lại một phiên demo mới rồi tưởng dữ liệu cũ đã bị mất.

Bản này bổ sung riêng; bộ 325 câu và các liên kết số dòng hiện tại vẫn ghim vào bản demo trước. Nghiệp vụ giữ nguyên nhưng các câu về `ConTroTam`, lambda, tên helper hoặc số dòng không được coi là đã đồng bộ với bản dễ đọc. Khi ôn code của bản này, đối chiếu hàm thật trong thư mục này.

Đã build C++11 với cảnh báo nghiêm ngặt và chạy 840 kiểm tra tự động: 679 nghiệp vụ, 43 giao diện Win32, 33 hỗ trợ, 30 CLI, 26 đối số, 29 phiên/tự lưu/khóa. Đã xem ảnh buffer console sau kiểm thử; chưa kiểm tay chuột/IME trên máy từng thành viên. Tự lưu lỗi vẫn cần xử lý và F5; không cam kết chống mất điện giữa cập nhật RAM và ghi file. Khóa phối hợp không ngăn phần mềm ngoài bỏ qua khóa.
