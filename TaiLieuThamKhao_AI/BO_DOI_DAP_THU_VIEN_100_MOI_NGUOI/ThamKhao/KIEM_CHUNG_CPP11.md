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
