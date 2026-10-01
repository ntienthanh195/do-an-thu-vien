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

- Mỗi người tự thiết kế và viết code trong các file đã tạo sẵn theo cách chia của nhóm; tự đề xuất tên hàm và cách gọi từ yêu cầu đề; tham khảo [hướng đi từng thành viên](docs/HUONG_DI_TU_LAM_CHO_TUNG_THANH_VIEN.md). Không dùng bộ khung hàm AI làm bài điền sẵn. Cùng thống nhất giao tiếp giữa các phần do người viết đề xuất.
- Không tự đổi tên/kiểu dữ liệu hoặc cách gọi hàm dùng chung mà chưa trao đổi.
- Một hàm dùng chung có một nơi cài đặt; các phần khác gọi lại.
- Mỗi người làm màn hình phần mình bằng bộ hỗ trợ giao diện chung.
- Mỗi thành viên tự viết, kiểm thử và giải thích phần mình phụ trách; review không đồng nghĩa làm thay.
- Không đưa bài tập cá nhân, đồ án tàu hỏa hoặc hồ sơ học cá nhân vào repo này.

## Dữ liệu mẫu

**Push để nhóm xem và góp ý:** ai làm xong phần dữ liệu của mình thì cứ push lên nhánh riêng trước và gửi link nhánh/PR cho Thành, Thái và Tấn xem có ổn không; không cần đợi được duyệt mới push. Thành chuẩn bị xong thì Thái và Tấn xem; Thái chuẩn bị xong thì Thành và Tấn xem; Tấn chuẩn bị xong thì Thành và Thái xem. Cùng góp ý định dạng, nội dung, liên kết mã và mức phù hợp để thử chức năng; chưa có phần dữ liệu liên quan hoặc chưa chạy thử thì ghi rõ. Push là chia sẻ để xem xét, chưa phải ghép vào main hay xác nhận dữ liệu đã đúng.

**Ưu tiên trước khi triển khai hàng loạt chức năng:** Thành và Thái chốt định dạng, chuẩn bị bộ dữ liệu mẫu chung và phần đọc tối thiểu để nạp vào đúng cấu trúc. Thành phụ trách độc giả/lịch sử; Thái phụ trách đầu sách/cuốn sách; Tấn hỗ trợ tạo dữ liệu theo định dạng đã chốt. Làm bộ nhỏ có kết quả đối chiếu trước, tiếp đến bộ dài hợp lệ. Mục tiêu là khi một chức năng vừa cài xong, người viết có ngay dữ liệu để chạy thử, không lúc đó mới bắt đầu chuẩn bị file. Không cần chờ hoàn chỉnh mọi chức năng ghi file hoặc mọi tình huống dữ liệu lỗi mới bắt đầu viết nghiệp vụ; phần ghi và lưu–mở lại vẫn phải hoàn thiện theo phân công.

**Có file dữ liệu mẫu trước thì đưa lên GitHub trước:** Thành, Thái hoặc Tấn chuẩn bị xong bộ mẫu theo định dạng đã thống nhất thì lưu vào `DuLieu/`, commit/push lên nhánh riêng và gửi PR để nhóm dùng sớm. Không chờ hoàn thành cả khối chức năng hoặc chờ tất cả bộ dữ liệu cùng xong; không push thẳng `main`. Có thể gửi PR chỉ chứa dữ liệu và mô tả. Nếu chưa có code đọc để thử thì ghi rõ “chưa kiểm thử bằng chương trình”, không coi file mẫu là bằng chứng phần đọc/ghi đã chạy đúng.

Kèm mô tả ngắn về định dạng, mục đích thử và những file cần dùng cùng để khớp mã. Thành kiểm tra phần độc giả/lịch sử, Thái kiểm tra phần sách, kể cả bộ mẫu do Tấn hỗ trợ chuẩn bị. Bộ mẫu mới không được âm thầm làm lệch dữ liệu liên quan đã có. Dữ liệu còn nháp hoặc chưa khớp được chia sẻ qua Draft PR và ghi rõ giới hạn trước khi ghép.

Thành phụ trách đọc/ghi độc giả và lịch sử mượn; Thái phụ trách đọc/ghi đầu sách và cuốn sách. Hai người chốt định dạng, quan hệ mã và cách báo lỗi trước; Tấn hỗ trợ chuẩn bị dữ liệu và kiểm thử.

Khi có định dạng, lưu dữ liệu mẫu giả lập dùng chung trong `DuLieu/`. Mỗi người sao chép dữ liệu cần chạy vào `DuLieu/runtime/` để thao tác thử không làm đổi bộ mẫu. Thư mục runtime được Git bỏ qua. Bộ mẫu có lỗi có chủ đích phải được ghi rõ và tách khỏi bộ hợp lệ.

Chưa tạo dữ liệu mẫu trước khi định dạng được chốt. Không đưa mật khẩu, token hoặc dữ liệu cá nhân thật vào repo.
