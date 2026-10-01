# Phân công dữ liệu, kiểm thử và tài liệu

Cập nhật 02/10/2026 từ phân công của Thái. Các file đã được tạo trống, mỗi người tự bổ sung nội dung; chưa có dữ liệu hợp lệ hoặc kết quả kiểm thử từ việc tạo file. Xem [phân công code theo file](PHAN_CONG_THEO_FILE.md) và [lịch nhóm](NHOM_CONG_VIEC_VA_MOC_PR.md).

**Thứ tự bắt đầu:** hoàn thiện và chia sẻ sớm các kiểu dữ liệu/struct/hằng chung → review, ghép bản thống nhất vào `MaNguon/00_KhaiBaoChung.h` → chốt định dạng file → tạo bộ mẫu nhỏ và phần đọc tối thiểu → mở rộng bộ mẫu dài. Xem trách nhiệm và cách bàn giao ở mục đầu của [phân công code](PHAN_CONG_THEO_FILE.md). Kiểu dữ liệu trong code và dữ liệu mẫu trong file là hai đầu việc khác nhau; không cần chờ các hàm nghiệp vụ hoàn chỉnh mới gửi khai báo chung.

## DuLieu/DuLieuMau.txt

- Phân công:
  - Thái: Viết dữ liệu mẫu phần đầu sách và cuốn sách.
  - Thành: Viết dữ liệu mẫu phần độc giả và lịch sử mượn trả; khớp nối mã chéo giữa các phần.
  - Tấn: Hỗ trợ bổ sung thêm bộ dữ liệu dài đúng theo định dạng đã chốt.
- Ghi chú: Phải kèm theo văn bản mô tả chi tiết kết quả mong đợi khi nạp dữ liệu mẫu.
- Thành và Thái chốt định dạng file trước khi tạo mẫu: các trường, cách ghi ngày/trạng thái và quan hệ mã thẻ/mã cuốn/lịch sử. Cùng đối chiếu mã và trạng thái giữa phần sách với phần độc giả/lịch sử; Tấn tạo thêm mẫu theo định dạng đã thống nhất.
- Ưu tiên bộ nhỏ đã đối chiếu cùng phần đọc tối thiểu trước, rồi bổ sung bộ dài hợp lệ để thử chức năng. Ai chuẩn bị xong phần nào thì push nhánh riêng để hai thành viên còn lại xem, không đợi xong cả khối code; ghi rõ đã thử đọc bằng chương trình hay chưa và phần dữ liệu liên quan còn thiếu.
- Giữ bộ mẫu gốc để đối chiếu; chạy thử thêm/xóa/mượn/trả trên bản sao trong DuLieu/runtime/ (được Git bỏ qua). Mẫu lỗi có chủ đích được đánh dấu và tách khỏi bộ hợp lệ. Việc giữ bản mẫu không yêu cầu phải có chức năng backup tự động.

## DuLieu/DuLieuRong.txt

- Phân công:
  - Tấn: Hoàn thiện nội dung file đã tạo sẵn theo định dạng hệ thống rỗng mà Thành và Thái thống nhất; file 0 byte hiện tại chưa được coi là mẫu hợp lệ.

## TestKey/TestNhapDung.txt

- Phân công:
  - Cả ba: Mỗi người tự đóng góp các ca thử nghiệm (test case) chuẩn cho các chức năng do mình sở hữu.
  - Thành: Bổ sung thêm các ca thử tích hợp luồng nghiệp vụ (Mượn sách → Trả sách → Lưu file → Mở lại chương trình).
  - Tấn: Chịu trách nhiệm quản lý và duy trì cấu trúc của file tổng hợp.

## TestKey/TestNhapSai.txt

- Phân công:
  - Thái: Viết kịch bản nhập bậy / dữ liệu không hợp lệ cho đầu sách và cuốn sách.
  - Thành: Viết kịch bản nhập sai phái, ngày tháng sai quy cách, mượn vượt quá số lượng cho phép (quá 3 cuốn).
  - Tấn: Viết kịch bản chọn sai menu điều hướng, mã thẻ chứa ký tự không phải số.

## TaiLieu/SoDoLienKet.md

- Phân công:
  - Thái: Vẽ sơ đồ cấu trúc mảng con trỏ + danh sách liên kết đơn các cuốn sách.
  - Thành: Vẽ sơ đồ cấu trúc cây nhị phân tìm kiếm (BST) độc giả + danh sách liên kết đơn lịch sử mượn trả.
  - Tấn: Vẽ sơ đồ luồng hiển thị liệt kê và menu điều hướng.
  - Thành: Tổng hợp và ghép các sơ đồ thành bản hoàn chỉnh cuối cùng.

## TaiLieu/CauHoiHoiThay.md

- Phân công:
  - Cả ba: Mỗi người tự ghi lại các giả định và thắc mắc nghiệp vụ của mình (ví dụ: cách tính top-10 theo đầu sách hay cuốn sách, xử lý trường hợp đồng hạng, mốc thời gian tính quá hạn, ghi nhận ngày trả khi báo mất sách, xử lý ngày tháng 0/0/0, giới hạn MAX_DAU_SACH).
  - Thành: Chốt và duyệt lại danh sách câu hỏi tổng trước khi cả nhóm gặp thầy hướng dẫn.
