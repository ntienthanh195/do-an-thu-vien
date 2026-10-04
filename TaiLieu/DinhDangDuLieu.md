# Định dạng dữ liệu Thư viện — bản đề xuất v1

Ngày 05/10/2026. Thành chọn cách ghi dữ liệu con ngay dưới dữ liệu cha và yêu cầu chuẩn bị cả hai phần để nhóm xem trước. Tài liệu này đi cùng [DuLieuMau.txt](../DuLieu/DuLieuMau.txt). Đây là đề xuất cụ thể để Thành, Thái và Tấn review; chưa phải xác nhận của thầy hoặc bằng chứng chương trình C++ đã đọc/ghi thành công.

## 1. Một file chung, thứ tự cố định

File chứa lần lượt:
1. Mã thẻ lớn nhất đã từng cấp (đề xuất để giữ quy tắc không tái sử dụng mã).
2. Số lượng đầu sách.
3. Các khối đầu sách: một dòng đầu sách, tiếp theo đúng số dòng cuốn của nó.
4. Số lượng độc giả.
5. Các khối độc giả: một dòng độc giả, tiếp theo đúng số dòng lịch sử của người đó.
6. Kết thúc file; không còn bản ghi khác.

Số đầu sách không phải số cuốn. Đọc đủ các khối đầu sách, bao gồm cuốn đi kèm, mới chuyển sang số độc giả. Một khối có số con bằng 0 thì không có dòng con.

Định dạng không có nhãn SACH/DOCGIA, dòng tiêu đề, chú thích hoặc dòng trống giữa các bản ghi. Các nhãn bên dưới chỉ dùng để giải thích, không chép vào file dữ liệu. Dòng cuối có thể kết thúc bằng xuống dòng.

### Vì sao nhóm đề xuất bố trí này?

Đầu sách và các cuốn đặt cạnh nhau giúp đọc tuần tự, biết ngay cuốn thuộc đầu sách đang xử lý và dễ đối chiếu bộ mẫu. Độc giả/lịch sử dùng cùng nguyên tắc. Gộp một file giúp các phần đi cùng một bản dữ liệu. Đổi lại, số lượng và thứ tự phải chính xác; ghi kèm ISBN ở mỗi cuốn là phương án khác linh hoạt hơn về vị trí dòng nhưng cần liên kết lại theo ISBN. Đây là lý do thiết kế dự kiến, không khẳng định cách khác luôn khó bảo trì hoặc cách này an toàn hơn khi ghi lỗi. Nếu thầy quy định một định dạng bắt buộc, nhóm cần điều chỉnh theo yêu cầu đó.

## 2. Quy ước ký tự và trường

- File văn bản UTF-8 không BOM; bộ đọc cần xử lý được LF hoặc CRLF.
- Dấu | ngăn cách trường; không đặt | ở đầu/cuối dòng, không chèn khoảng trắng quanh dấu phân cách.
- Khoảng trắng trong họ, tên sách, tác giả và vị trí được giữ nguyên.
- Bản v1 chưa có cơ chế escape: dữ liệu trường không được chứa | hoặc xuống dòng. Khi nhập gặp các ký tự này phải báo không hợp lệ, không âm thầm làm biến dạng thông tin.
- Dòng đếm và mã thẻ dùng số nguyên thập phân. Số đếm không âm; mã thẻ của độc giả dương, không trùng nhau.
- ISBN và mã cuốn là chuỗi, không chuyển thành số làm mất số 0 đầu. ISBN trong bộ mẫu chỉ là mã giả lập, chưa được xác minh với danh mục xuất bản.
- Không trường văn bản nào trong bản mẫu bị bỏ trống. Dữ liệu rỗng biểu diễn bằng số lượng 0, không dùng một dòng trắng thay thế.

## 3. Các loại dòng

### Dòng đầu: thông tin cấp mã thẻ

Một số nguyên không âm: maTheLonNhatDaCap.

Đề xuất v1: cấp mã tăng dần, mã tiếp theo là giá trị này cộng 1; chỉ cập nhật mốc khi cấp thành công. Nếu vượt giới hạn kiểu int thì báo hết khả năng cấp, không quay vòng. Không giảm mốc khi xóa độc giả. Khi lưu, phải giữ mốc này cùng dữ liệu; không lấy lại đơn thuần từ mã lớn nhất còn trong BST.

Đây là thông tin hỗ trợ lưu trữ được đề xuất, không phải trường nghiệp vụ mới theo đề. Header hiện tại chưa có nơi giữ mốc này; nhóm cần thống nhất nơi quản lý trước khi viết phần cấp mã/lưu file. Tài liệu không tự sửa struct hay quyết định thay cách cấp mã nếu thầy có quy định khác.

Trong mẫu, mốc là 20, dù mã lớn nhất còn hiện diện chỉ là 18: mô phỏng đã từng cấp tới 20, một số độc giả không còn trong dữ liệu. Mã mới dự kiến là 21.

### Phần sách

Dòng mở đầu: soLuongDauSach.

Mỗi đầu sách có đúng 7 trường:
ISBN|tenSach|soTrang|tacGia|namXuatBan|theLoai|soCuon

Ngay dưới đầu sách là soCuon dòng, mỗi dòng đúng 3 trường:
maSach|trangThai|viTri

Trạng thái cuốn theo header: 0 cho mượn được; 1 đang được mượn; 2 đã thanh lý.

Mỗi ISBN duy nhất; mã cuốn duy nhất toàn thư viện. Số đầu sách không vượt MAX_DAU_SACH hiện hành. Số trang dương; năm xuất bản hợp lệ theo quy tắc nhóm/thầy chốt.

Cuốn thuộc đầu sách ngay phía trên theo số lượng, nên không lặp ISBN trên từng cuốn. Khi nạp phải giữ mảng đầu sách tăng theo tên; không coi thứ tự file bất kỳ là đã đúng. Bộ mẫu dùng tên sách không dấu, khác nhau rõ ràng, đã xếp tăng theo tên; quy tắc so sánh tiếng Việt/hoa-thường vẫn cần nhóm thống nhất.

### Phần độc giả và lịch sử

Dòng mở đầu: soLuongDocGia.

Mỗi độc giả có đúng 6 trường:
maThe|ho|ten|phai|trangThaiThe|soBanGhiLichSu

Ngay dưới độc giả là soBanGhiLichSu dòng, mỗi dòng đúng 4 trường:
maSach|ngayMuon|ngayTra|trangThai

Phái: Nam hoặc Nữ. Trạng thái thẻ: 0 khóa; 1 hoạt động.
Trạng thái mượn–trả: 0 đang mượn; 1 đã trả; 2 làm mất.

Ngày thực dùng dd/mm/yyyy, ví dụ 03/10/2026. Ngày chưa trả dùng riêng 0/0/0. Ngày mượn phải là ngày thực hợp lệ; lượt đã trả có ngày trả hợp lệ không trước ngày mượn. Không dùng 0/0/0 làm ngày thực hoặc để tính khoảng cách ngày.

Số bản ghi là toàn bộ lịch sử, có thể lớn hơn 3. Một mã cuốn được xuất hiện nhiều lần ở các lượt khác nhau; không dùng riêng maSach làm định danh duy nhất của toàn bộ lịch sử.

Các độc giả trong file không nhất thiết tăng theo mã. Bộ đọc phải dựng BST theo maThe; không nối nút theo thứ tự dòng. Lịch sử trong mẫu ghi theo thứ tự thời gian từ cũ đến mới; giữ các bản ghi khi đọc/lưu lại.

## 4. Liên kết và đối chiếu

- Mã cuốn trong lịch sử phải tồn tại trong phần sách.
- Trong mẫu, mỗi cuốn trạng thái 1 có đúng một bản ghi đang mượn; không có hai độc giả cùng đang mượn một cuốn.
- Cuốn trạng thái 0 hoặc 2 không có bản ghi đang mượn.
- Bản ghi đã trả không có nghĩa cuốn hiện tại luôn trạng thái 0: cuốn đó có thể đã được mượn lại ở lượt sau.
- Các số đếm phục vụ xác định ranh giới trong file; không bắt buộc thêm trường đếm vào mọi struct.
- Không lưu địa chỉ con trỏ next, left, right, root, dms hoặc dsMuonTra. Phần đọc tạo đối tượng và dựng lại các liên kết.

## 5. Giải thích từng đoạn trong bộ mẫu

DuLieuMau.txt có 20 dòng dữ liệu:
- Dòng 1: mốc mã thẻ 20.
- Dòng 2: 3 đầu sách.
- Dòng 3–6: Cau truc du lieu và 3 cuốn S001–S003.
- Dòng 7–9: Lap trinh C++ và 2 cuốn S004–S005.
- Dòng 10–11: Toan roi rac và cuốn S006.
- Dòng 12: 3 độc giả.
- Dòng 13–17: độc giả 12, Nguyễn Văn An, 4 lượt lịch sử.
- Dòng 18–19: độc giả 7, Trần Thị Bình, 1 lượt lịch sử.
- Dòng 20: độc giả 18, Lê Văn Cường, thẻ khóa và không có lịch sử.

Kết quả mong đợi sau khi đọc:
- 3 đầu sách, tổng 6 cuốn: 3 cho mượn được, 2 đang mượn, 1 thanh lý.
- 3 độc giả: 2 thẻ hoạt động, 1 thẻ khóa.
- Tổng 5 lượt lịch sử: 3 đã trả, 2 đang mượn; chưa có lượt làm mất.
- Nguyễn Văn An đang mượn S001 (Cau truc du lieu); Trần Thị Bình đang mượn S004 (Lap trinh C++).
- S001 xuất hiện hai lần trong lịch sử của An: lượt tháng 9 đã trả, lượt tháng 10 đang mượn. Không được bỏ một lượt vì trùng mã cuốn.
- Liệt kê độc giả theo mã phải ra 7, 12, 18, dù thứ tự file là 12, 7, 18.
- Nếu ngày đối chiếu là 05/10/2026, hai lượt đang mượn có khoảng cách ngày lần lượt 2 và 1; không hard-code ngày này trong chương trình.
- Lưu rồi đọc lại phải bảo toàn thông tin và quan hệ, không yêu cầu cây có hình dạng hoặc địa chỉ bộ nhớ giống trước.

Đây là dữ liệu giả lập để kiểm tra nạp và liên kết, không phải dữ liệu người dùng thật, bộ thử đầy đủ, hoặc bằng chứng hoàn thành a–j.

## 6. Dữ liệu thiếu/sai và giới hạn bản v1

Phần đọc cần phát hiện thiếu/thừa trường, số đếm sai, kết thúc sớm, dữ liệu dư cuối file, ngày/trạng thái sai, mã trùng hoặc liên kết không tồn tại. Báo vị trí và lý do; không báo nạp thành công một bộ đã thiếu khối. Khi nạp thay dữ liệu đang dùng, cần giữ được bản đang có nếu dữ liệu mới không hợp lệ; cơ chế cụ thể do người viết thiết kế.

Một file giúp bộ mẫu đi cùng nhau, không tự bảo đảm an toàn khi ghi lỗi giữa chừng. Cách lưu tránh mất bản cũ cần được thiết kế và kiểm thử riêng.

Các điểm chưa chốt, không tự suy thành yêu cầu của thầy:
- Quy tắc ngày trả và trạng thái cuốn/thẻ khi báo mất: mẫu chưa dùng trạng thái lịch sử 2.
- Điều kiện xóa và giữ lịch sử; cách cấp mã cụ thể cần xác nhận với nhóm.
- Cách so sánh tên tiếng Việt/đồng tên; quy tắc tìm theo tên.
- Quy tắc top 10, đồng hạng và thời gian quá hạn của độc giả có nhiều cuốn.
- Mẫu này chưa có dữ liệu dài, đầu sách không cuốn, quá hạn, mất sách hoặc dữ liệu lỗi có chủ đích.
- DuLieuRong.txt còn trống, chưa được coi là dữ liệu rỗng hợp lệ theo v1. Nếu dùng v1, dữ liệu thư viện hoàn toàn mới/rỗng là ba dòng 0: mốc mã, số đầu sách, số độc giả. Với thư viện đã từng dùng, giữ mốc mã cũ dù số đầu sách/độc giả đều là 0.

## 7. Cách phối hợp

Thành chuẩn bị bản đề xuất và mẫu cả hai phần để chia sẻ sớm. Thái review sách/cuốn và tự viết đọc/ghi phần đó; Thành review độc giả/lịch sử, mốc mã và tự viết phần tương ứng; Tấn đọc quy ước để chuẩn bị dữ liệu và chức năng liệt kê/menu. Không thay phân công chức năng.

Đọc/ghi file theo thứ tự đã mô tả; hai người thống nhất cách bàn giao vị trí đọc và cách báo lỗi khi nối hai phần. Làm thử trên bản sao trong DuLieu/runtime/, giữ nguyên bộ mẫu để đối chiếu.

Đã đối chiếu bộ mẫu bằng kiểm tra độc lập về số trường, số lượng, mã, trạng thái, ngày và liên kết. Chưa kiểm thử bằng chương trình C++ của nhóm. AI hỗ trợ soạn tài liệu/dữ liệu theo yêu cầu; không ghi nhận đây là bằng chứng người học tự cài hoặc tự kiểm thử.
