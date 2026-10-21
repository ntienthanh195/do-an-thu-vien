# Demo Thư viện — C++11, giữ giao diện console

Đây là bản chuyển đổi từ demo AI trong repo ntienthanh195/do-an-thu-vien, commit aec28f8489b15d332f210af1c991eef666476d9a. Không phải code nhóm tự viết. Bản C++17 cũ và mã nguồn nhóm được giữ nguyên.

## Chạy ngay

1. Giải nén toàn bộ thư mục.
2. Nhấp đúp **ChayDemo.bat**. Bản đóng gói có sẵn build/ThuVien.exe.
3. Mỗi lần chạy tạo một bản dữ liệu demo mới trong DuLieu/runtime; không ghi đè dữ liệu mẫu hoặc phiên cũ.

Giao diện vẫn có sidebar, màu, các nút, biểu mẫu, chuột, phím điều hướng và phân trang như bản AI cũ. Mở cửa sổ tối thiểu 80 cột × 24 dòng. Tab chuyển ô, Ctrl+Enter xác nhận, Esc hủy biểu mẫu; ở trang chính Esc/0 lưu và thoát, F5 lưu. Mỗi thao tác thêm/sửa/xóa, mượn/trả/báo mất thành công được tự lưu trước thông báo thành công. Mục “Thoát phiên” vẫn yêu cầu xác nhận và không hoàn tác dữ liệu đã tự lưu. Nếu báo CHƯA LƯU, giữ cửa sổ mở, xử lý lỗi ghi và nhấn F5; chương trình chặn sửa/nạp tiếp cho đến khi lưu được.

Chỉ một phiên của bản này được mở cùng đường dẫn dữ liệu để sửa. File phụ `.thuvien.lock` được hệ điều hành dọn khi đóng phiên, kể cả dừng tiến trình; không xóa file khóa khi đang chạy. Hai kho khác đường dẫn vẫn mở độc lập; `--check` chỉ đọc. Công cụ ngoài/bản cũ bỏ qua khóa hoặc hard link tên khác không được cơ chế này bảo vệ. Tự lưu không bảo đảm chống mất điện hoặc dừng ngay giữa cập nhật RAM và ghi file.

Demo dùng ngày mô phỏng 16/10/2026 như bản cũ để tái lập dữ liệu. Chạy trực tiếp chương trình không truyền --date sẽ lấy ngày máy bằng GetLocalTime.

## Biên dịch

Mã nguồn nằm trong **MaNguon/**: một header chung và tám file .cpp. Biên dịch cả tám file, không chỉ một file đang mở.

Trong PowerShell tại thư mục này:

    powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\Build.ps1

Hoặc chọn rõ compiler:

    powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\Build.ps1 -Compiler "C:\msys64\ucrt64\bin\g++.exe"

Có sẵn ThuVien.dev để mở dạng project trong Dev-C++. Cấu hình dùng -std=c++11; không còn liên kết shell32. Mã nguồn ứng dụng chỉ include bốn header thư viện:

- iostream
- string
- fstream
- windows.h

Các file .cpp include header chung của chính dự án. Đây không phải thư viện ngoài thứ năm. Không dùng bits/stdc++.h, container STL, std::sort, filesystem, unique_ptr, sstream, ctime, iomanip hoặc shellapi.h.

Đã kiểm chứng bằng GCC/MinGW 16.2.0 ở **chế độ C++11**, không có nghĩa chương trình cần chuẩn C++17. Compiler Dev-C++ GCC 4.9.2 có sẵn trên máy kiểm tra không khởi động được, kể cả với --version, báo Illegal System DLL Relocation; vì thế chưa xác nhận chạy/build bằng compiler cũ đó. Không thay compiler hay cấu hình Dev-C++ của người dùng.

## Những phần đã chuyển

Các thuật toán, bốn cấu trúc, quy tắc nghiệp vụ và mã vẽ giao diện được giữ. Chỉ thay lớp hỗ trợ bị ràng buộc thư viện/chuẩn:

- NgayThang có constructor C++11 để tiếp tục dùng các lời gọi với {ngay, thang, nam}.
- ConTroTam tự quản lý new/delete và new[]/delete[]; không cho sao chép để giữ quyền sở hữu duy nhất. Không thay kho dữ liệu gốc.
- BoDemChuoi/LuongChuoi dùng cơ chế stream của iostream để gom kết quả phân trang thay ostringstream.
- Ngày máy dùng Win32; định dạng ngày tự ghép chuỗi.
- Thư mục và thay file dùng Win32 thay filesystem. Vẫn ghi bản tạm, đóng file, đọc kiểm tra lại rồi mới thay bản đích.
- TepDoc/TepGhi ghép stream với CreateFileW/ReadFile/WriteFile để giữ đường dẫn tiếng Việt, không phụ thuộc overload fstream(wchar_t*) chỉ có ở một số phiên bản MinGW.
- Đối số chạy Unicode được tách từ GetCommandLineW; không cần CommandLineToArgvW/shellapi.h. Chỗ cần bộ đệm ghi dùng cách truy cập phù hợp C++11.
- Giữ chế độ vẽ RGB và chế độ console dự phòng; SDK cũ thiếu tên cờ VT được bổ sung đúng giá trị Win32.

Các mảng tạm, heap sort, tìm kiếm, BST, danh sách liên kết và thống kê vẫn tự cài như bản tham khảo. Các giả định về mất sách, xóa độc giả, đồng hạng và top 10 vẫn cần nhóm đối chiếu thầy; xem 01_YEU_CAU_VA_GIA_DINH.md.

## Dữ liệu và kiểm thử

Lưu theo định dạng v1 cũ. DuLieuMau.txt có 3 đầu sách, 6 cuốn và 3 độc giả; DuLieuRong.txt có ba dòng 0 hợp lệ.

    .\build\ThuVien.exe --check .\DuLieu\DuLieuMau.txt
    .\build\ThuVien.exe --data .\DuLieu\runtime\thu-vien-cua-toi.txt

--plain chỉ là chế độ nhập số dự phòng/kiểm thử. Launcher mặc định vẫn dùng giao diện console tương tác.

Kết quả đã kiểm chứng: 679 assertion nghiệp vụ, 30 kiểm tra CLI, 43 assertion giao diện Win32, 33 assertion lớp hỗ trợ, 26 assertion đối số và 29 assertion phiên thật — tổng 840. Thêm harness tiêm lỗi cấp phát sau nạp: bản sửa đạt, bản mutation bị bắt lỗi. Đây là kiểm tra tự động; chưa xác nhận chuột vật lý/IME trên mọi máy. Xem [phạm vi kiểm chứng](KIEM_CHUNG_CPP11.md).

Để chạy ngay, tải [gói demo C++11](../../DEMO_THU_VIEN_CPP11.zip), giải nén rồi mở ChayDemo.bat. Gói ZIP có sẵn file thực thi; khi clone repo, chạy Build.ps1 trước hoặc để launcher tự build.
