# Kiểm chứng bản C++11

Ngày 21/10/2026. Source: bản demo AI tại aec28f8489b15d332f210af1c991eef666476d9a; mã nguồn nhóm không được sửa.

- Build tám module với GCC/MinGW 16.2.0, -std=c++11, cảnh báo Wall/Wextra/Wpedantic/Wconversion/Wshadow và Werror: đạt.
- 679 assertion nghiệp vụ C++: đạt. Có ngày, chuỗi, mảng đầu sách, BST/xóa, mã không tái cấp, mượn–trả–mất, hạn mức, quá hạn, top10, dữ liệu sai/rollback, lưu/đọc Unicode và mẫu 100.000 độc giả.
- 30 kiểm tra CLI: đạt. Bao gồm a–j, Unicode, lưu/nạp lại, lỗi và EOF.
- 43 assertion giao diện Win32: đạt. Bơm phím/chuột vào console thật chạy ẩn; kiểm biểu mẫu, hủy, UTF-16, sidebar, phân trang, kích thước 80×24 / 70×20 / 120×32, màu và chế độ vẽ dự phòng.
- 33 assertion lớp hỗ trợ: đạt, biên dịch với -std=c++11 -pedantic-errors. Có giải phóng con trỏ khi thoát/throw, gom đầu ra, đối số có quote/backslash, Unicode/NUL/UTF-8 lỗi, tạo thư mục lồng và file vượt bộ đệm.
- Quét mã ứng dụng: đúng bốn header thư viện cho phép; không còn các API C++17 đã loại bỏ.
- 27 file nguồn gốc được đối chiếu SHA-256: giữ nguyên.

Tổng 785 kiểm tra tự động đã qua. Log và harness được giữ ở workspace kiểm chứng. Bản gửi nhóm chỉ kèm mã nguồn, cách chạy và bản tóm tắt này. Có thể xem diff trên lịch sử Git.

## Giới hạn

Ảnh trong hồ sơ kiểm chứng cục bộ được dựng từ dữ liệu đọc lại của bộ đệm console, không phải ảnh chụp desktop. Đã xem ảnh dashboard và form để kiểm bố cục. Chưa thử trực tiếp chuột vật lý, bộ gõ tiếng Việt/IME, font trên máy khác hoặc kéo resize liên tục. Không tuyên bố bao phủ mọi lỗi hay quy mô hàng triệu bản ghi.

GCC 4.9.2 đi kèm Dev-C++ trên máy không khởi động được, báo Illegal System DLL Relocation ngay khi --version; chưa kiểm chứng build bằng compiler này. Đã loại phụ thuộc wchar_t-fstream và bổ sung cờ VT mà SDK cũ thiếu, nhưng điều đó không thay một lần build thực tế bằng compiler cũ.

Đây là kiểm chứng kỹ thuật của bản AI; không phải bằng chứng nhóm tự viết, hiểu hay hoàn thành môn.

## Kiểm lại toàn bộ ngày 21/10/2026

Snapshot đợt rà soát trước: `b44964652043d8f4790a23952d4e3a8694ce1cdf`. Đã biên dịch lại với C++11; chạy mới 679 assertion nghiệp vụ, 43 Win32 và 33 lớp hỗ trợ. Phát hiện --check "" mở nhầm menu; đã thêm cổng từ chối --data/--check rỗng trước mọi thao tác tệp. Sau sửa, 30 kiểm tra CLI a–j và 26 assertion hồi quy đối số đều đạt (tổng 811, không cộng lặp các lần chạy cùng bộ). Mã nghiệp vụ/giao diện không đổi trong bản vá ba dòng này.

Rà soát đủ nội dung và mốc nguồn của 325 câu; chỉ TN238 cần bổ sung hành vi mới. Build và ZIP chứa cùng nguồn/file chạy đã kiểm. Không tăng số câu hoặc thêm tài liệu học mới. Giới hạn kiểm chứng ở trên vẫn áp dụng.

## Tự lưu, khóa phiên và sửa TN82 — 21/10/2026

Nguồn `1c4510c99e3ad6131b044f45f8c3ac192d1e9c1a` biên dịch C++11 với bộ cờ cảnh báo nghiêm ngặt trong Build.ps1; vẫn đúng bốn header và giao diện console. Chạy lại 679 assertion nghiệp vụ, 43 Win32, 33 lớp hỗ trợ, 30 CLI và 26 đối số. Thêm 29 assertion dùng tiến trình thật: mở trùng/khác kho, --check, đổi khóa khi NAP, tự lưu thêm/sửa/xóa/mượn/trả/mất, hủy giữa lô cuốn, dừng tiến trình sau tự lưu, lỗi ghi file chỉ đọc và thử lại không lặp giao dịch. Tổng 840 kiểm tra tự động.

Harness riêng chặn operator new ngay sau DocFile commit: NapPhien chuyển RAM/path/khóa thành công; mutation đổi swap thành phép gán đường dẫn thất bại đúng ca. Harness dùng static runtime để bắt cấp phát của string; ngoại lệ cảnh báo mismatched-new-delete chỉ tắt ở harness thay operator new bằng malloc, không thay cờ build ứng dụng. Đây là kiểm chứng TN82, không phải tiêm mọi lỗi bộ nhớ của cả chương trình.

Kiểm lại đủ 325 ID, nhóm 100/100/100/25, JSON–Markdown, symbol/dòng và liên kết; kiểm CRC, SHA-256 và byte từng thành viên hai ZIP, gồm exe mới. Giữ nguyên danh sách file gói gửi nhóm; harness/log ở workspace kiểm chứng.

Giới hạn: khóa phối hợp không ngăn công cụ ngoài/bản cũ bỏ qua khóa hoặc hard link tên khác. Tự lưu lỗi vẫn cần xử lý và F5; không cam kết chống mất điện/đóng cưỡng bức giữa commit RAM và ghi. Chưa kiểm tay IME/chuột vật lý trên máy thành viên; 840 kiểm tra không tương đương chạy riêng toàn bộ 325 câu và câu phụ.
