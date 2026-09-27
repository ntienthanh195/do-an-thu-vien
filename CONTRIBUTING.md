# Cách cộng tác của nhóm

Mới dùng GitHub: đọc [hướng dẫn từng bước dành cho nhóm](docs/HUONG_DAN_DAY_CODE_CHO_NHOM.md) trước. Tài liệu đó có cách đặt file đúng thư mục, lấy repo về máy và bàn giao chức năng đã viết.

## Một nhiệm vụ, một nhánh

1. Lấy bản `main` mới nhất trước khi bắt đầu.
2. Tạo nhánh cho một nhiệm vụ nhỏ, ví dụ `tan/liet-ke-dang-muon` hoặc `thai/doc-file-sach`.
3. Tự viết và thử phần được giao. Lưu các thay đổi thành commit có mô tả cụ thể.
4. Đẩy nhánh lên GitHub và mở pull request vào `main`.
5. Ghi chức năng đã làm, các phần phụ thuộc, cách thử/kết quả và phần còn thiếu trong pull request.
6. Một thành viên khác review; Thành điều phối ghép sau khi kiểm tra phù hợp. Người viết sửa phần mình khi cần.

Đây là quy ước nhóm; repo mới chưa được cấu hình quy tắc bảo vệ nhánh hoặc kiểm tra tự động.

## Phối hợp

- Mỗi người tự thiết kế, tự tạo file và tự đặt tên hàm từ đề; tham khảo [hướng đi từng thành viên](docs/HUONG_DI_TU_LAM_CHO_TUNG_THANH_VIEN.md). Không dùng bộ khung hàm AI làm bài điền sẵn. Cùng thống nhất giao tiếp giữa các phần do người viết đề xuất.
- Không tự đổi tên/kiểu dữ liệu hoặc cách gọi hàm dùng chung mà chưa trao đổi.
- Một hàm dùng chung có một nơi cài đặt; các phần khác gọi lại.
- Mỗi người làm màn hình phần mình bằng bộ hỗ trợ giao diện chung.
- Mỗi thành viên tự viết, kiểm thử và giải thích phần mình phụ trách; review không đồng nghĩa làm thay.
- Không đưa bài tập cá nhân, đồ án tàu hỏa hoặc hồ sơ học cá nhân vào repo này.

## Dữ liệu mẫu

Thành phụ trách đọc/ghi độc giả và lịch sử mượn; Thái phụ trách đọc/ghi đầu sách và cuốn sách. Hai người chốt định dạng, quan hệ mã và cách báo lỗi trước; Tấn hỗ trợ chuẩn bị dữ liệu và kiểm thử.

Khi có định dạng, lưu dữ liệu mẫu giả lập dùng chung trong `data/samples/`. Mỗi người sao chép dữ liệu cần chạy vào `data/runtime/` để thao tác thử không làm đổi bộ mẫu. Thư mục runtime được Git bỏ qua. Bộ mẫu có lỗi có chủ đích phải được ghi rõ và tách khỏi bộ hợp lệ.

Chưa tạo dữ liệu mẫu trước khi định dạng được chốt. Không đưa mật khẩu, token hoặc dữ liệu cá nhân thật vào repo.
