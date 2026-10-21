# Demo C++11 và 325 câu vấn đáp đồng bộ

**Chạy demo mới:** mở [ThamKhao/README.md](ThamKhao/README.md), hoặc nhấp đúp ThamKhao/ChayDemo.bat trong gói ZIP.

> **Đồng bộ C++11 ngày 21/10/2026:** cả 325 câu đối chiếu mã nguồn demo tại commit `c6c48b3`. Liên kết tên file mở mã đi kèm; liên kết tên hàm/số dòng mở đúng snapshot C++11 trên GitHub. [Phạm vi đồng bộ và kiểm chứng](ThamKhao/DONG_BO_VAN_DAP_CPP11.md).



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

Code đi kèm là bản tham khảo AI chuyển sang C++11 ngày 21/10/2026. Nội dung 325 câu đã đồng bộ với snapshot C++11 `c6c48b3` ngày 21/10/2026: 35 câu chỉnh nội dung, toàn bộ nguồn đối chiếu cập nhật số dòng. Tên file mở mã cục bộ; tên hàm/số dòng mở snapshot cố định trên GitHub. Code này tách khỏi mã nguồn nhóm đang viết. Khi code nhóm thay đổi, phải đối chiếu lại đáp án; G01–G12 cần giảng viên xác nhận.

Bản gửi nhóm đã bỏ log, script và dữ liệu biên soạn. Hồ sơ đầy đủ vẫn được giữ riêng; không xem việc lược bỏ tệp là kiểm chứng mới. Các kiểm thử 17–18/10 thuộc phiên bản trước, không được tính là tái chạy 325 câu trên C++11. Đợt đồng bộ này kiểm nội dung theo diff, liên kết, bản xuất và gói ZIP; không sửa hay chạy lại toàn bộ ứng dụng. Chưa QA toàn bộ TUI, concurrency hoặc tải triệu. Lần thay thế C++11 có phạm vi kiểm chứng riêng tại [KIEM_CHUNG_CPP11.md](ThamKhao/KIEM_CHUNG_CPP11.md).
