# Demo C++11 và bộ câu hỏi đối chiếu C++17

**Chạy demo mới:** mở [ThamKhao/README.md](ThamKhao/README.md), hoặc nhấp đúp ThamKhao/ChayDemo.bat trong gói ZIP.

> **Lưu ý phiên bản:** bộ 325 câu/đáp án này được soạn trên snapshot AI C++17 trước chuyển đổi. Các liên kết code bên dưới được ghim về snapshot đó để giữ đúng số dòng và API được giải thích (cần Internet để mở). [Demo hiện hành đã chuyển sang C++11](ThamKhao/README.md), giữ giao diện và nghiệp vụ; các câu về filesystem/unique_ptr/shell32 không mô tả lớp hỗ trợ mới. Chưa tái kiểm định toàn bộ 325 đáp án cho bản C++11.



- **[Thái — 100 câu](01_CAU_HOI.md#thai)** · [Đáp án](02_DAP_AN.md#thai)
- **[Thành — 100 câu](01_CAU_HOI.md#thanh)** · [Đáp án](02_DAP_AN.md#thanh)
- **[Tấn — 100 câu](01_CAU_HOI.md#tan)** · [Đáp án](02_DAP_AN.md#tan)
- **[Cả nhóm — 25 câu](01_CAU_HOI.md#chung)** · [Đáp án](02_DAP_AN.md#chung)
- **[20 câu ôn trước](01_CAU_HOI.md#on-truoc)** — chọn từ bộ 325, không cộng thêm.

Tự dự đoán, chỉ vào code rồi mới xem đáp án. Mọi người cần hỏi chéo cả ba phần. Tìm câu bằng Ctrl+F với mã hoặc từ khóa. Đọc trên GitHub bằng Preview; trong VS Code nhấn Ctrl+Shift+V.

## Thư mục này có gì?

- `01_CAU_HOI.md`: toàn bộ câu hỏi và câu phụ.
- `02_DAP_AN.md`: đáp án giải thích, liên kết tới đúng câu và code.
- [ThamKhao/MaNguon](ThamKhao/MaNguon/): 9 file C++11 hiện hành, giữ giao diện console.
- [Yêu cầu và giả định](ThamKhao/01_YEU_CAU_VA_GIA_DINH.md): các quy tắc cần đối chiếu giảng viên.
- [Nguyên văn đề 3](ThamKhao/NGUYEN_VAN_DE_3_THU_VIEN.txt).

## Phạm vi

Code đi kèm là bản tham khảo AI chuyển sang C++11 ngày 21/10/2026. Nội dung câu hỏi biên tập ngày 18/10/2026 vẫn đối chiếu snapshot C++17 qua các liên kết lịch sử. Code này tách khỏi mã nguồn nhóm đang viết. Khi code nhóm thay đổi, phải đối chiếu lại đáp án; G01–G12 cần giảng viên xác nhận.

Bản gửi nhóm đã bỏ log, script và dữ liệu biên soạn. Hồ sơ đầy đủ vẫn được giữ riêng; không xem việc lược bỏ tệp là kiểm chứng mới. Trước đó có 25 ca CLI lịch sử và một đợt gồm 16 lượt assertion, 2 timeout chủ đích; không chứng nhận toàn bộ 325 câu. Chưa QA toàn bộ TUI, concurrency hoặc tải triệu. Lần thay thế C++11 có phạm vi kiểm chứng riêng tại [KIEM_CHUNG_CPP11.md](ThamKhao/KIEM_CHUNG_CPP11.md).
