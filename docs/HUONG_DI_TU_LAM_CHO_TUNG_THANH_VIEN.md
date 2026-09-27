# Hướng đi tự làm cho Thành, Thái và Tấn

## Cách dùng tài liệu

Theo lựa chọn của Thành ngày 27/09/2026, mỗi người đọc đề, tự thiết kế, tự tạo file, tự đặt tên hàm và tự viết code như đã làm ở mốc khai báo. Tài liệu chỉ nêu mục tiêu, yêu cầu, phần cần phối hợp và dấu hiệu có thể chuyển mốc; không cung cấp khung code, danh sách hàm bắt buộc, biến mẫu hoặc thuật toán để chép.

Phân công a–j giữ theo [phần A của hồ sơ phân công](PHAN_CONG_DO_AN_THU_VIEN.md). Các mốc dưới đây là hướng đi dự kiến, chưa phải tiến độ đã đạt. Có thể điều chỉnh nhịp theo phần đã tự làm được.

## 1. Thành — từ quản lý độc giả đến mượn–trả

**Ưu tiên dữ liệu chung:** Thành và Thái chốt định dạng và làm bộ mẫu cùng khả năng đọc tối thiểu trước khi mở rộng các chức năng. Thành phụ trách độc giả/lịch sử; Thái phụ trách đầu sách/cuốn sách; Tấn hỗ trợ mẫu theo định dạng đã chốt. Cần nạp được bộ nhỏ đã đối chiếu, rồi có bộ dài hợp lệ để mỗi chức năng làm xong được thử ngay. Các mốc dưới đây mô tả nội dung học/làm, không có nghĩa phải xong hết thao tác quản lý mới chuẩn bị dữ liệu. Phần ghi file và kiểm tra lưu–mở lại được hoàn thiện tiếp theo phân công; không trì hoãn bộ mẫu chỉ vì phần ghi chưa xong.

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

Thành tự xây các màn hình thuộc a, f, g trên quy ước console chung. Phối hợp với Tấn khi cần hiển thị sách đang mượn, với Thái khi cần tra sách và tính thống kê. Thành điều phối nạp/lưu/thoát và ghép chương trình; Thái và Tấn tự thực hiện, tự sửa chức năng mình phụ trách.

**Cần trao đổi trước khi viết riêng:** Tấn/Thái cần lấy thông tin độc giả/lịch sử gì; phần nào được sửa; kết quả khi không tìm thấy; phần ngày dùng chung; ai quản lý và giải phóng dữ liệu liên quan.

## 2. Thái — từ đầu sách/cuốn sách đến thống kê

**Đích cần làm được:** c, e, i, j; đọc/ghi sách và tự làm các màn hình tương ứng. Các thành phần console dùng chung do cả ba thống nhất và chia việc theo nhu cầu, không mặc định Thái phụ trách chính.

### Bắt đầu buổi đầu tiên

Đọc mục c và khai báo đầu sách/cuốn sách của nhóm. Tự mô tả một đầu sách chứa thông tin gì, các cuốn thuộc đầu sách được phân biệt thế nào, thông tin nào nhập và thông tin nào chương trình cấp. Sau đó đề xuất phạm vi đầu tiên có thể cài và thử, tên file muốn tạo và thông tin cần cung cấp cho Thành/Tấn. Cả nhóm chốt chỗ dùng chung rồi Thái tự viết; không cần chờ phần độc giả hoàn thành.

### Mốc 1 — mục c: nhập đầu sách và cuốn sách

- **Cần đạt:** nhập được thông tin theo đề, cấp mã cuốn duy nhất và giữ danh sách đầu sách tăng theo tên. Thái tự làm màn hình nhập và thông báo kết quả.
- **Tự quyết định:** cách chia xử lý, cấp mã, tra cứu và tổ chức file; giải thích lựa chọn theo ràng buộc đề, không tự thay cấu trúc.
- **Phối hợp:** Thái cung cấp cho Thành cách tìm cuốn để mượn/trả; cung cấp cho Tấn cách lấy tên đầu sách theo mã cuốn và đọc danh sách đầu sách. Thành và Tấn dùng phần tra cứu này để tự viết chức năng mình phụ trách.
- **Bàn giao/chuyển mốc:** code đúng phạm vi đã nhận, dữ liệu thử do Thái chọn cùng kết quả mong đợi/thực tế; Thành và Tấn hiểu cách tra cứu do Thái cung cấp. Phần chưa cài phải ghi rõ, không coi xong một thao tác là xong toàn bộ c.

### Mốc 2 — đọc/ghi sách và mục e

- **Cần đạt về file:** đọc được đầu sách và cuốn sách từ bộ mẫu đã thống nhất; lưu rồi đọc lại giữ thông tin cần thiết. Làm phần đọc sớm để nhóm có dữ liệu dài dùng thử, không đợi hoàn thành thống kê.
- **Cần đạt ở e:** người dùng tìm theo tên và xem đủ ISBN, tên sách, tác giả, năm xuất bản, thể loại, mã cuốn và trạng thái theo đề. Thái tự làm màn hình kết quả, xử lý việc xem dữ liệu dài.
- **Phối hợp:** chốt với Thành định dạng, quy tắc mã và cách báo file không đọc được/dữ liệu không hợp lệ; chốt cách hiểu tìm theo tên trước khi cài. Tấn có thể giúp chuẩn bị bộ mẫu sau khi định dạng rõ.
- **Bàn giao/chuyển mốc:** file mẫu có mô tả, cách đọc/ghi, cách chạy phần đã có và kết quả thử. Bộ mẫu liên quan lịch sử mượn phải khớp mã, không chỉ đủ số dòng.

### Mốc 3 — mục i: độc giả quá hạn

- **Cần đạt:** hiển thị độc giả quá hạn theo thời gian quá hạn giảm dần, có màn hình xem kết quả.
- **Cần có trước:** dữ liệu độc giả/lịch sử đọc được; ý nghĩa ngày và phần tính ngày do Thành cung cấp. Có thể dùng lịch sử mẫu hợp lệ trước khi mượn–trả chạy hoàn chỉnh.
- **Cần làm rõ:** chọn mốc so sánh thế nào nếu một độc giả có nhiều cuốn quá hạn; ngày dùng để lập danh sách. Không tự biến giả định thành quy tắc của thầy.
- **Bàn giao/chuyển mốc:** Thái tự chọn dữ liệu, tính kết quả mong đợi để đối chiếu, giải thích vì sao danh sách và thứ tự đúng; dữ liệu gốc vẫn đúng sau khi xem.

### Mốc 4 — mục j: top 10 sách được mượn nhiều nhất

- **Cần đạt:** thống kê và hiển thị theo cách hiểu yêu cầu đã được xác nhận.
- **Cần có trước:** thống nhất tính theo đầu sách hay cuốn, thế nào là một lượt được tính và cách xử lý đồng hạng; dữ liệu sách/lịch sử đủ để kiểm kết quả.
- **Tự quyết định:** cách tính và tổ chức kết quả, không tự thêm trường nghiệp vụ chỉ để tiện thống kê.
- **Bàn giao:** cách chạy, dữ liệu/kết quả thử và phần giải thích chi phí theo kích thước dữ liệu. Chưa có xác nhận nghiệp vụ thì giữ câu hỏi mở và làm phần độc lập khác.

Các mốc không phải hạn theo ngày. c/e và đọc file có thể xen kẽ theo phụ thuộc; mỗi lần làm một phần trọn vẹn. Giao diện thuộc chức năng nào thì Thái tự làm cùng chức năng đó, hoàn thiện dần theo quy ước chung. Phần console dùng chung do cả ba chia việc, không phải một dự án phụ Thái phải làm hết trước.

**Cần trao đổi trước khi viết riêng:** Thành cần tra cứu/cập nhật thông tin cuốn gì; Tấn cần lấy tên và thông tin đầu sách thế nào; cách dùng bộ hỗ trợ console; định dạng file và quy tắc cấp mã.

## 3. Tấn — tự làm liệt kê dữ liệu rồi mở rộng giao diện

**Đích cần làm được:** h, b, d và màn hình tương ứng; menu chính. Tấn tự viết phần duyệt, lọc, chuẩn bị thứ tự và hiển thị, không chỉ in dữ liệu đã được Thành và Thái xử lý xong.

### Bắt đầu buổi đầu tiên

Chỉ tập trung mục h. Đọc đề và khai báo liên quan, viết vài câu về thông tin người dùng nhập và kết quả muốn xem. Tự phác màn hình trên giấy hoặc bằng văn bản; nêu thông tin nào cần Thành/Thái cho biết cách truy cập. Chưa cần giải quyết toàn bộ b, d hay trang trí console ngay.

### Mốc 1 — mục h: sách một độc giả đang mượn

- **Nền cần hiểu:** vai trò mã thẻ, mã cuốn, đầu sách và một bản ghi mượn; ý nghĩa các trạng thái. Chỗ nào chưa hiểu thì hỏi đúng chỗ đó trước khi viết.
- **Tấn tự làm:** thiết kế và cài phần liệt kê theo yêu cầu, gồm xử lý dữ liệu cần hiển thị và màn hình nhận mã thẻ/xem kết quả. Tự tạo file và đặt tên hàm sau khi chốt cách dùng chung.
- **Thành cung cấp cho Tấn:** cách tìm độc giả và đọc lịch sử mượn–trả, cùng dữ liệu độc giả/lịch sử mẫu hợp lệ.
- **Thái cung cấp cho Tấn:** cách tra tên đầu sách theo mã cuốn, cùng dữ liệu sách mẫu khớp với lịch sử. Tấn không phải chờ nghiệp vụ mượn–trả hoàn chỉnh. Thành và Thái cung cấp phần tra cứu nền; Tấn tự xử lý yêu cầu h.
- **Bàn giao/chuyển mốc:** Tấn tự đề xuất dữ liệu, kết quả mong đợi và lý do thử; chạy đối chiếu khi đủ phụ thuộc, giải thích dữ liệu nào quyết định kết quả. Không làm thay đổi dữ liệu khi chỉ xem danh sách. Nếu thiếu phụ thuộc, ghi rõ đã làm đến đâu.

### Mốc 2 — phần b: xem độc giả theo mã

- **Nền cần hiểu:** cây của nhóm tổ chức theo khóa gì và cách truy cập các nút; học đúng nền còn thiếu trước khi cài.
- **Cần đạt:** hiển thị đầy đủ danh sách độc giả theo mã tăng dần, có cách quay lại; Tấn tự chọn cách duyệt và cách tổ chức màn hình.
- **Phối hợp:** Thành cung cấp dữ liệu cây dùng thử và giải thích cách truy cập; không cần chờ mọi chức năng sửa/xóa độc giả hoàn chỉnh.
- **Bàn giao/chuyển mốc:** có dữ liệu/kết quả thử tự đề xuất và giải thích được thứ tự. Ghi đúng là hoàn thành lựa chọn theo mã, chưa phải toàn bộ b.

### Mốc 3 — hoàn thiện b: xem theo tên+họ

- **Cần đạt:** cùng dữ liệu độc giả, người dùng chọn xem theo tên+họ tăng dần hoặc theo mã. Thống nhất cách so sánh tên/họ và trường hợp bằng nhau trước khi cài.
- **Tấn tự quyết định:** cách tạo thứ tự hiển thị; không làm sai cấu trúc BST theo mã khi đổi lựa chọn xem. Không được chỉ đổi nhãn cột rồi coi thứ tự đã đúng.
- **Phối hợp:** Tấn trao đổi với Thành về dữ liệu cây và ràng buộc độc giả; có thể nhờ Thành hoặc Thái giải thích nền sắp xếp/cách dùng dữ liệu tạm, rồi Tấn tự đề xuất cách làm. Không sao chép một lời giải hoàn chỉnh để coi là tự thiết kế.
- **Bàn giao/chuyển mốc:** hai lựa chọn cho kết quả đúng trên dữ liệu do Tấn chọn và phần quản lý độc giả vẫn dùng được; nêu rõ mức hỗ trợ đã nhận.

### Mốc 4 — mục d: đầu sách theo thể loại và tên

- **Cần đạt:** xem đầu sách theo từng thể loại; tên sách tăng dần trong từng thể loại. Màn hình phải xem được dữ liệu dài.
- **Phối hợp:** Thái cung cấp dữ liệu đầu sách và cách truy cập. Nhóm làm rõ cách trình bày/thứ tự giữa các thể loại nếu đề chưa quy định.
- **Tấn tự quyết định:** cách tổ chức kết quả hiển thị, giữ nguyên tính đúng và thứ tự lưu bắt buộc của dữ liệu gốc; không đổi cấu trúc đề để tiện in.
- **Bàn giao:** Tấn gửi code, màn hình, dữ liệu/kết quả thử và giải thích lựa chọn; Thái review phần dữ liệu sách, Thành cùng kiểm tra cách ghép sau khi Tấn đã đề xuất ca thử.

Nếu còn mắc ở một mốc, thu hẹp đúng điểm mắc để học và sửa, không đồng loạt mở thêm các mục. Những lần được giải thích vẫn là học có hỗ trợ; chuyển mốc không tự chứng minh đã tự chủ toàn bộ kiến thức.

### Menu và màn hình

Tấn tự thiết kế và cài giao diện menu chính, màn hình b, d, h theo quy ước nhóm; cùng tham gia xây dựng phần console dùng chung phù hợp khả năng. Chốt với Thành cách chuyển màn hình, quay lại và thoát. Dữ liệu dài phải xem được đầy đủ; phạm vi nào chưa có điều hướng/phân trang thì ghi rõ. Không cần chờ Thái làm sẵn toàn bộ giao diện mới bắt đầu.

Menu làm song song ở phạm vi nhỏ sau khi thống nhất điều hướng. Mục chưa cài phải được thể hiện là chưa có chức năng, không báo thao tác thành công giả. Trong mốc ghép đầu tiên của nhóm, Tấn có thể làm màn hình bảng sách đơn giản để thử kết nối; đó là bản thử giao diện, không đổi thứ tự học h → b → d và không tính là đã hoàn thành d.

**Cần trao đổi trước khi viết riêng:** cách tìm độc giả; cách truy cập lịch sử và tìm tên sách; cách đọc dữ liệu mà không sửa trạng thái; cách sử dụng phím, bảng và thông báo của nhóm.

## 4. Cả nhóm thống nhất gì trước khi code riêng?

- Đọc đúng bản khai báo chung và đề; mỗi người tự đề xuất cách tổ chức file, tên hàm, dữ liệu vào/ra cho phần mình.
- Những chỗ gọi nhau phải thống nhất tên, tham số, kết quả và trách nhiệm thay đổi dữ liệu trước. Đây là việc do người viết thiết kế và nhóm trao đổi, không lấy bộ hàm AI cũ làm mẫu bắt buộc.
- Giữ bốn cấu trúc theo đề. Dữ liệu hỗ trợ bổ sung phải có mục đích rõ; điểm chưa được thầy xác nhận thì ghi câu hỏi.
- Quy ước giao diện nhất quán, định dạng file thống nhất, có dữ liệu nhỏ để kiểm kết quả và dữ liệu dài để thử quy mô. Tấn hỗ trợ chuẩn bị dữ liệu sau khi Thành/Thái chốt định dạng.
- Mỗi người ghi phạm vi đã làm, các ca tự nghĩ/các ca được gợi ý và kết quả thực tế. Khi review, dùng chính phiên bản mới nhất để truy vết hoặc luyện giải thích; không công nhận độc lập chỉ vì code chạy được.

## 5. Bàn giao một phần như thế nào?

Thực hiện theo [khối công việc liền mạch và điểm bàn giao PR](NHOM_CONG_VIEC_VA_MOC_PR.md): Thành có ba khối, Thái hai khối, Tấn ba khối. Các mốc học phía trên giúp hiểu trình tự học, không bắt dừng để push hay mở PR sau mỗi mốc. Thành viên tự chọn điểm dừng tự nhiên để commit/push và gửi khối đủ review; có thể gộp việc liên quan hoặc tách phần phụ thuộc cần bàn giao sớm. Không có quota PR và không chờ dồn toàn bộ đồ án mới gửi.

Người viết tự tạo file trong `src` với tên nhóm đã thống nhất. Một phần bàn giao gồm: code của mình, mục đích, cách phần khác sử dụng, dữ liệu/kết quả thử, điểm chưa hoàn thành hoặc cần hỏi thầy. Không cần đợi xong toàn bộ phân công mới gửi.

Làm trên nhánh riêng, mở PR và cùng review theo [hướng dẫn GitHub](HUONG_DAN_DAY_CODE_CHO_NHOM.md). Hướng dẫn vị trí thư mục chỉ giúp tổ chức dự án; không yêu cầu tạo sẵn tất cả file hoặc làm theo tên hàm/biến do AI đặt.

Bước bắt đầu cho mỗi người: chọn mốc đầu thuộc phần mình, đọc yêu cầu và khai báo có liên quan, trình bày ngắn dự định cùng điểm cần phối hợp, rồi tự tạo file và cài phạm vi đã thống nhất. Khi mắc, hỏi đúng điểm để nhận gợi ý tăng dần; không cần chờ hoàn thành cả phân hệ mới trao đổi.
