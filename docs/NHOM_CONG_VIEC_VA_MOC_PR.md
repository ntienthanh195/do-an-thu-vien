# Khối công việc liền mạch và điểm bàn giao PR

Kế hoạch ngày 27/09/2026, điều chỉnh theo yêu cầu giữ nhịp làm việc của thành viên. Phân công a–j không đổi. Đây là hướng đi, chưa phải tiến độ hoàn thành; mỗi người tự thiết kế và viết code.

## 1. Không bắt dừng sau từng chức năng nhỏ

Các khối dưới đây là ranh giới để xem xét bàn giao, không phải số PR bắt buộc. Khi đang làm liền mạch những việc liên quan, thành viên có thể tiếp tục rồi kiểm thử chung ở điểm dừng tự nhiên. Không bắt push sau mỗi hàm hoặc mở một PR riêng cho thêm, tìm, sửa, xóa.

- **Commit:** lưu một thay đổi có ý nghĩa trên máy; người viết tự chọn thời điểm.
- **Push nhánh riêng:** lưu/chia sẻ công việc khi nghỉ, kết thúc buổi, cần trao đổi hoặc Thành/Thái/Tấn cần xem phần phụ thuộc. Không cần đợi code hoàn chỉnh, cũng không có hạn mức bắt buộc sau mỗi chức năng.
- **PR:** đề nghị review một khối có mục tiêu rõ và kết quả có thể kiểm tra. Có thể chứa nhiều commit và nhiều chức năng liên quan. Cần trao đổi sớm khi còn dở thì dùng Draft PR; không bắt mở Draft cho mọi lần push.
- **Ghép main:** sau review và kiểm tra phù hợp. Push hoặc mở PR không tự chứng minh đã hoàn thành.

Ưu tiên gửi ở điểm dừng tự nhiên: khép một luồng sử dụng, xong một buổi với khối đủ review, hoặc một phần đã sẵn sàng mà thành viên khác đang cần. Nếu phần phụ thuộc cần sớm, trao đổi để bàn giao phạm vi vừa đủ; không bắt cả nhóm chờ đến cuối đồ án.

## 2. Thành — ba khối chính

### Khối Thành A — quản lý độc giả và dữ liệu file

**Phạm vi liền mạch:** mục a gồm thêm/tìm/sửa/xóa thẻ, cấp mã, màn hình quản lý; đọc/ghi độc giả và lịch sử để có dữ liệu dùng chung. Thành có thể làm nối tiếp các thao tác rồi thử tổng hợp, không gửi riêng từng thao tác nhỏ.

**Phối hợp:** Thành chốt với Thái định dạng và quan hệ mã sách; cung cấp cho Tấn dữ liệu/cách tra cứu độc giả và lịch sử. Điều kiện xóa liên quan lịch sử phải được làm rõ trước khi cài hành vi tương ứng.

**Điểm bàn giao phù hợp:** một luồng quản lý độc giả và phần đọc/ghi đã dùng thử được, có dữ liệu/kết quả kiểm tra. Nếu xóa hoặc lưu trữ còn vướng mà Tấn cần tra cứu trước, Thành có thể tách phần nền đã ổn để bàn giao sớm, ghi rõ phần a chưa hoàn tất.

### Khối Thành B — ngày tháng, mượn và trả

**Phạm vi liền mạch:** xử lý ngày dùng chung, f và g, màn hình tương ứng, tính nhất quán sách/lịch sử và dữ liệu sau thao tác. Có thể làm mượn rồi trả, kiểm tra cả chuỗi trước khi gửi PR.

**Phối hợp:** dùng tra cứu sách từ Thái, phối hợp h của Tấn để hiển thị sách đang mượn trong f. Cung cấp phần ngày cho Thái làm i khi đã ổn; không bắt Thái chờ hoàn tất toàn bộ khối nếu chỉ cần phần ngày.

**Điểm bàn giao phù hợp:** luồng mượn–trả đã có thể thử và giải thích kết quả trên dữ liệu chung. Có thể tách mượn hoặc ngày thành PR sớm khi cần review/phụ thuộc; không bắt buộc tách theo từng chức năng. Quy tắc mất sách hoặc ngày chưa rõ phải ghi riêng, không tự suy thành yêu cầu thầy.

### Khối Thành C — nối chương trình và hoàn thiện tích hợp

**Phạm vi:** nạp/lưu/thoát, ghép các màn hình và phần dữ liệu, quản lý giải phóng theo trách nhiệm sở hữu. Đây là công việc xuyên suốt khi các phần sẵn sàng, không phải đợi A/B và toàn nhóm xong mới ghép.

**Điểm bàn giao phù hợp:** một luồng chung hoạt động và đã thử với các phần liên quan. Thành điều phối; Thái và Tấn tự sửa phần mình. Không gom mọi lỗi thành việc Thành làm thay.

## 3. Thái — hai khối chính

### Khối Thái A — quản lý sách, tìm kiếm và dữ liệu file

**Phạm vi liền mạch:** c và e, đầu sách/cuốn sách, cấp mã, tra cứu, đọc/ghi sách và các màn hình tương ứng. Thái có thể làm từ nhập đầu sách đến cuốn, tìm kiếm và lưu/đọc rồi kiểm tra chung.

**Phối hợp:** chốt định dạng với Thành; cung cấp tra cứu cuốn cho Thành và tên/danh sách đầu sách cho Tấn. Bộ mẫu đọc file làm sớm trong khối để thử dữ liệu dài, không hoãn đến cuối đồ án.

**Điểm bàn giao phù hợp:** có luồng quản lý/tìm sách và dữ liệu thử rõ, giữ đúng cấu trúc/thứ tự theo đề. Nếu Thành hoặc Tấn đang cần tra cứu và mẫu, Thái bàn giao phần đó trước khi hoàn thiện toàn bộ màn hình. Không bắt tách riêng PR cho mỗi loại dữ liệu hay thao tác.

### Khối Thái B — thống kê và màn hình kết quả

**Phạm vi liền mạch:** i và j, lập kết quả thống kê và giao diện xem. Thái tự xử lý thống kê từ dữ liệu chung, không chờ Thành tính sẵn kết quả.

**Cần trước:** dữ liệu độc giả/lịch sử của Thành, phần ngày dùng chung cho i; xác nhận quy tắc xếp người có nhiều cuốn quá hạn, cách tính top 10 và đồng hạng. Dữ liệu mẫu hợp lệ có thể dùng trước khi f/g hoàn thiện.

**Điểm bàn giao phù hợp:** thống kê đã được đối chiếu với kết quả mong đợi, màn hình dùng được trong phạm vi công bố. i và j có thể cùng một PR nếu vẫn dễ review; nếu một mục vướng quy tắc hoặc khối quá lớn thì tách mục đã sẵn sàng. Không giữ cả hai đến cuối chỉ để đúng một PR.

## 4. Tấn — ba khối chính

### Khối Tấn A — xem sách đang mượn và menu cơ bản

**Phạm vi:** h với màn hình nhận mã thẻ/xem kết quả; menu cơ bản để vào màn hình đã có và quay lại. Tấn tự viết phần liệt kê và giao diện theo quy ước nhóm.

**Cần trước:** Thành cung cấp độc giả/lịch sử và cách truy cập; Thái cung cấp dữ liệu sách và cách lấy tên theo mã cuốn. Không cần chờ f/g hoàn chỉnh. Trong lúc chờ, Tấn tự phác yêu cầu, màn hình và dữ liệu thử; có thể làm menu khi cách điều hướng đã rõ.

**Điểm bàn giao phù hợp:** h và luồng vào/quay lại đã có thể kiểm tra. Nếu menu chung còn phụ thuộc thì Tấn có thể bàn giao h với cách thử riêng; không bắt giữ chức năng đã ổn chỉ để đợi menu. Mục chưa cài phải thể hiện đúng tình trạng.

### Khối Tấn B — toàn bộ hai cách xem độc giả

**Phạm vi:** mục b theo mã tăng dần và tên+họ tăng dần, cùng màn hình chọn cách xem. Tấn học/làm theo mã trước rồi theo tên, nhưng có thể làm liền mạch và gửi chung khi đủ kết quả.

**Cần trước:** dữ liệu cây và cách truy cập từ Thành, nền duyệt/sắp xếp cần dùng và quy tắc so sánh tên/họ. Việc xem không làm sai cây theo mã.

**Điểm bàn giao phù hợp:** hai lựa chọn chạy được trên dữ liệu Tấn tự chọn, có kiểm tra lại dữ liệu gốc. Nếu đang mắc một lựa chọn thì có thể xin review sớm bằng Draft PR; không ép hoàn thành cả hai trước khi được giúp và không bắt push ngay sau lựa chọn đầu tiên.

### Khối Tấn C — xem đầu sách theo thể loại và tên

**Phạm vi:** d, cách tổ chức kết quả và màn hình xem được dữ liệu dài; nối vào menu theo quy ước chung.

**Cần trước:** danh sách đầu sách/cách truy cập từ Thái; cách trình bày giữa các thể loại được thống nhất. Tấn tự lựa chọn cách xử lý, giữ đúng dữ liệu gốc.

**Điểm bàn giao phù hợp:** liệt kê và giao diện đã được kiểm tra cùng nhau. Thái review thông tin/thứ tự sách, Thành phối hợp kiểm tra luồng chung.

B → C là nhịp học gợi ý, không phải lịch cứng. Nếu thiếu phụ thuộc, Thành, Thái và Tấn trao đổi để chọn khối đủ nền và dữ liệu. Không dồn nhiều việc mới cho Tấn chỉ để tránh chờ.

## 5. Giao diện và review không làm đứt mạch làm việc

**Dữ liệu mẫu chia sẻ sớm:** Thành, Thái hoặc Tấn chuẩn bị xong file theo định dạng chung thì đưa vào `data/samples/`, push nhánh riêng và gửi PR ngay ở mốc đó; không cần đợi xong khối code hoặc đợi bộ dữ liệu của người khác hoàn chỉnh. PR có thể chỉ chứa dữ liệu và mô tả định dạng/phụ thuộc. Thành review độc giả/lịch sử, Thái review sách; ghi rõ đã thử đọc bằng chương trình hay mới kiểm tra nội dung. File chưa khớp các mã liên quan hoặc còn nháp phải được đánh dấu trong Draft PR, chưa coi là bộ mẫu hợp lệ chung. Quy định này nhằm chia sẻ dữ liệu sớm, không ép dừng để push sau từng hàm.

Mỗi người làm cả xử lý và màn hình phần mình. Có thể gom điều chỉnh giao diện liên quan vào PR của chức năng, hoặc gửi PR hoàn thiện giao diện riêng khi đủ ý nghĩa. Thành, Thái và Tấn cùng thống nhất bố cục/phím/thông báo; phần console dùng chung chia người thực hiện theo nhu cầu, không dồn riêng cho Thái.

Trước khi viết riêng, chốt những giao tiếp cần dùng ngay; không cần thiết kế xong toàn ứng dụng mới bắt đầu. Luồng ghép đầu có thể là đọc sách → menu → bảng sách cơ bản → quay lại. Bảng thử đó không tính là hoàn thành d và không bắt Tấn bỏ h để làm toàn bộ d trước.

Một PR dễ review cần có mục tiêu, phạm vi thực tế, phần phụ thuộc của Thành/Thái/Tấn, cách chạy, dữ liệu/kết quả kiểm tra và phần chưa xong. Người viết tự đề xuất ca thử; người review bổ sung thiếu sau. Không yêu cầu nhiều PR chỉ để chứng minh có làm việc.

Thành điều phối ghép; Thái review phần Thành, Thành review phần Thái; PR của Tấn được Thành review dữ liệu độc giả/lịch sử hoặc Thái review dữ liệu sách. Sau góp ý, tác giả sửa và push tiếp trên cùng nhánh. Sau khi ghép, cập nhật main trước khối mới. Giữ quy trình nhánh riêng → PR → review → ghép, không push thẳng main.

## 6. Điều chỉnh so với danh sách mốc cũ

Các mã THANH-01…08, THAI-01…06, TAN-01…05 trong phiên bản trước được thay bằng các khối A/B/C ở trên. Nội dung công việc vẫn giữ, chỉ đổi nhịp bàn giao để không ép dừng sau từng chức năng nhỏ. Không có tiến độ, điểm hay bằng chứng độc lập nào được tạo hoặc xóa do việc gộp mốc.
