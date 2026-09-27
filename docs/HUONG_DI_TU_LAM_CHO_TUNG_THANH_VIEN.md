# Hướng đi tự làm cho Thành, Thái và Tấn

## Cách dùng tài liệu

Theo lựa chọn của Thành ngày 27/09/2026, mỗi người đọc đề, tự thiết kế, tự tạo file, tự đặt tên hàm và tự viết code như đã làm ở mốc khai báo. Tài liệu chỉ nêu mục tiêu, yêu cầu, phần cần phối hợp và dấu hiệu có thể chuyển mốc; không cung cấp khung code, danh sách hàm bắt buộc, biến mẫu hoặc thuật toán để chép.

Phân công a–j giữ theo [phần A của hồ sơ phân công](PHAN_CONG_DO_AN_THU_VIEN.md). Các mốc dưới đây là hướng đi dự kiến, chưa phải tiến độ đã đạt. Có thể điều chỉnh nhịp theo phần đã tự làm được.

## 1. Thành — từ quản lý độc giả đến mượn–trả

**Đích cần làm được:** a, f, g; ngày tháng; đọc/ghi độc giả và lịch sử; màn hình tương ứng và điều phối ghép chương trình.

### Mốc đầu: dữ liệu độc giả và thao tác nền

Đọc lại yêu cầu a và bản khai báo nhóm đã viết. Tự xác định thông tin nào được nhập, được sửa, được cấp tự động; dữ liệu nào phải giữ nguyên. Tự tổ chức file và phần xử lý cần thiết cho việc quản lý độc giả theo BST.

Kết quả hướng tới là quản lý được dữ liệu độc giả trong phạm vi đã cài và giải thích được vì sao dữ liệu vẫn đúng sau thao tác. Trước khi cài xóa có liên quan lịch sử, làm rõ điều kiện được phép xóa. Không suy quy tắc chỉ từ việc một thao tác xóa cây có thể viết được.

### Mốc tiếp: đọc/ghi và ngày tháng

Trao đổi với Thái về định dạng dữ liệu và quan hệ mã giữa các phần. Tự thiết kế phần lưu/đọc độc giả cùng lịch sử, kể cả thông tin cần bảo đảm mã thẻ không trùng mã đã cấp khi mở lại chương trình. Chuẩn bị khả năng đọc dữ liệu sớm để Tấn có thể làm phần liệt kê.

Tự xác định các xử lý ngày cần cho mượn–trả và thống kê. Thống nhất ý nghĩa ngày, cách báo dữ liệu không hợp lệ và mốc quá hạn trước khi các phần khác dùng chung.

### Mốc nghiệp vụ: mượn và trả

Đọc f, g và các trạng thái trong đề; tự mô tả đầu vào, điều kiện chấp nhận/từ chối, dữ liệu bị thay đổi và kết quả cần có. Phần này phối hợp độc giả, cuốn sách và lịch sử mượn; dùng khả năng tra cứu do phần sách cung cấp.

Tự cài và tự đề xuất ca kiểm thử có kết quả mong đợi. Chỉ chuyển sang ghép đầy đủ khi đã kiểm tra phạm vi hiện tại; chưa có phần phụ thuộc thì ghi rõ giới hạn. Cách bảo đảm trạng thái nhất quán là phần Thành cần tự suy nghĩ và bảo vệ.

### Giao diện và phối hợp

Tự xây các màn hình thuộc a, f, g trên quy ước console chung. Phối hợp với Tấn khi cần hiển thị sách đang mượn, với Thái khi cần tra sách và tính thống kê. Điều phối nạp/lưu/thoát và ghép chương trình, không làm thay toàn bộ chức năng của hai bạn.

**Cần trao đổi trước khi viết riêng:** Tấn/Thái cần lấy thông tin độc giả/lịch sử gì; phần nào được sửa; kết quả khi không tìm thấy; phần ngày dùng chung; ai quản lý và giải phóng dữ liệu liên quan.

## 2. Thái — từ đầu sách/cuốn sách đến thống kê

**Đích cần làm được:** c, e, i, j; đọc/ghi sách; màn hình tương ứng; phụ trách chính các thành phần console dùng chung, có Thành hỗ trợ.

### Mốc đầu: dữ liệu sách và tra cứu

Đọc c, e và phân biệt đầu sách với từng cuốn. Tự thiết kế cách nhập, cấp mã, tra cứu và giữ các cấu trúc đúng yêu cầu. Nhóm đã có khai báo; đọc và giải thích bản đó trước khi quyết định tổ chức file triển khai.

Kết quả hướng tới là phần khác có thể sử dụng thông tin sách một cách rõ ràng. Cách cấp mã duy nhất và giữ thứ tự đầu sách là phần Thái tự đề xuất, cài và kiểm chứng.

### Mốc dữ liệu file và giao diện dùng chung

Chốt định dạng sách/cuốn với Thành rồi tự viết đọc/ghi. Bộ dữ liệu đọc vào cần đủ nhất quán để dùng cùng độc giả và lịch sử, không chỉ đọc được số lượng lớn.

Trao đổi cùng nhóm về bố cục, phím điều khiển, thông báo và cách xem dữ liệu dài. Tự đề xuất phần giao diện nào có thể dùng lại giữa các màn hình, thử ở phạm vi nhỏ trước. Không cần hoàn thiện mọi hiệu ứng trước khi có một luồng chạy được; không nhận làm thay các màn hình thuộc Thành và Tấn.

### Mốc tìm kiếm và thống kê

Hoàn thiện màn hình e theo đủ thông tin đề yêu cầu. Khi dữ liệu mượn–trả và phần ngày đã sẵn sàng, triển khai i và j. Trước khi quyết định cách tính, làm rõ mốc xếp độc giả có nhiều cuốn quá hạn, top 10 tính theo đầu sách hay cuốn và xử lý đồng hạng.

Tự chọn cách tính, cách hiển thị và ca thử; giải thích được kết quả dựa trên dữ liệu nào. Dữ liệu ít hơn số kết quả dự kiến, dữ liệu dài và chi phí xử lý cần được xem xét khi review, không mặc định có giao diện đẹp là nghiệp vụ đã đúng.

**Cần trao đổi trước khi viết riêng:** Thành cần tra cứu/cập nhật thông tin cuốn gì; Tấn cần lấy tên và thông tin đầu sách thế nào; cách dùng bộ hỗ trợ console; định dạng file và quy tắc cấp mã.

## 3. Tấn — tự làm liệt kê dữ liệu rồi mở rộng giao diện

**Đích cần làm được:** h, b, d và màn hình tương ứng; menu chính. Tấn tự viết phần duyệt, lọc, chuẩn bị thứ tự và hiển thị, không chỉ in dữ liệu đã được hai bạn xử lý xong.

### Mốc đầu: mục h — sách một độc giả đang mượn

Đọc h cùng khai báo độc giả, lịch sử mượn và sách. Tự nói lại màn hình cần nhận thông tin gì và phải hiện kết quả gì. Xác định phần thông tin mình đã có và phần cần nhờ Thành/Thái cung cấp cách truy cập.

Sau khi nhóm thống nhất cách gọi giữa các phần, Tấn tự tạo file, chia công việc thành các hàm phù hợp và viết chức năng. Có thể học kiến thức còn thiếu qua ví dụ/truy vết, rồi quay lại tự cài. Không cần viết hết mục b, d cùng lúc.

Kết quả hướng tới: dùng được dữ liệu mẫu chung, trả kết quả đúng mục h và giải thích được dữ liệu đi từ đâu đến màn hình. Tấn tự chọn dữ liệu thử, ghi kết quả mong đợi và lý do chọn; hai bạn review sau.

### Mốc tiếp: mục b — hai cách xem độc giả

Làm lựa chọn theo mã trước, rồi lựa chọn theo tên+họ. Đọc lại đặc điểm cây mà nhóm dùng và yêu cầu thứ tự hiển thị. Tự đề xuất cách tổ chức phần liệt kê, bảo đảm xem danh sách không làm sai dữ liệu gốc.

Nếu còn thiếu nền cây hoặc sắp xếp, học đúng phần đang cần rồi tự viết tiếp. Nhờ hỗ trợ không có nghĩa phải chuyển hẳn chức năng cho bạn khác; ghi rõ phần nào đã được hướng dẫn và phần nào tự thực hiện.

### Mốc tiếp: mục d — đầu sách theo thể loại và tên

Đọc yêu cầu d, trao đổi với Thái về dữ liệu đầu sách. Tự mô tả thứ tự kết quả cần thấy trước khi chọn cách cài. Giữ đúng cấu trúc và thứ tự lưu bắt buộc của danh sách gốc; cách tạo kết quả hiển thị do Tấn tự đề xuất.

### Menu và màn hình

Dùng các thành phần console mà nhóm thống nhất để làm menu chính và màn hình b, d, h. Chốt với Thành cách chuyển màn hình, quay lại và thoát. Dữ liệu dài phải xem được đầy đủ; phạm vi nào chưa có điều hướng/phân trang thì ghi rõ.

**Cần trao đổi trước khi viết riêng:** cách tìm độc giả; cách truy cập lịch sử và tìm tên sách; cách đọc dữ liệu mà không sửa trạng thái; cách sử dụng phím, bảng và thông báo của nhóm.

## 4. Cả nhóm thống nhất gì trước khi code riêng?

- Đọc đúng bản khai báo chung và đề; mỗi người tự đề xuất cách tổ chức file, tên hàm, dữ liệu vào/ra cho phần mình.
- Những chỗ gọi nhau phải thống nhất tên, tham số, kết quả và trách nhiệm thay đổi dữ liệu trước. Đây là việc do người viết thiết kế và nhóm trao đổi, không lấy bộ hàm AI cũ làm mẫu bắt buộc.
- Giữ bốn cấu trúc theo đề. Dữ liệu hỗ trợ bổ sung phải có mục đích rõ; điểm chưa được thầy xác nhận thì ghi câu hỏi.
- Quy ước giao diện nhất quán, định dạng file thống nhất, có dữ liệu nhỏ để kiểm kết quả và dữ liệu dài để thử quy mô. Tấn hỗ trợ chuẩn bị dữ liệu sau khi Thành/Thái chốt định dạng.
- Mỗi người ghi phạm vi đã làm, các ca tự nghĩ/các ca được gợi ý và kết quả thực tế. Khi review, dùng chính phiên bản mới nhất để truy vết hoặc luyện giải thích; không công nhận độc lập chỉ vì code chạy được.

## 5. Bàn giao một phần như thế nào?

Người viết tự tạo file trong `src` với tên nhóm đã thống nhất. Một phần bàn giao gồm: code của mình, mục đích, cách phần khác sử dụng, dữ liệu/kết quả thử, điểm chưa hoàn thành hoặc cần hỏi thầy. Không cần đợi xong toàn bộ phân công mới gửi.

Làm trên nhánh riêng, mở PR và cùng review theo [hướng dẫn GitHub](HUONG_DAN_DAY_CODE_CHO_NHOM.md). Hướng dẫn vị trí thư mục chỉ giúp tổ chức dự án; không yêu cầu tạo sẵn tất cả file hoặc làm theo tên hàm/biến do AI đặt.

Bước bắt đầu cho mỗi người: chọn mốc đầu thuộc phần mình, đọc yêu cầu và khai báo có liên quan, trình bày ngắn dự định cùng điểm cần phối hợp, rồi tự tạo file và cài phạm vi đã thống nhất. Khi mắc, hỏi đúng điểm để nhận gợi ý tăng dần; không cần chờ hoàn thành cả phân hệ mới trao đổi.
