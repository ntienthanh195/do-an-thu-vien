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

**Ưu tiên chung trước các khối chức năng:** Thành và Thái thống nhất định dạng rồi ưu tiên hoàn thành bộ dữ liệu mẫu cùng phần đọc tối thiểu để nạp dữ liệu vào cấu trúc. Thành làm độc giả/lịch sử, Thái làm sách/cuốn, Tấn hỗ trợ chuẩn bị mẫu. Kiểm tra bộ nhỏ trước rồi bổ sung bộ dài có liên kết mã và trạng thái nhất quán; chia sẻ ngay phần đã sẵn sàng qua nhánh riêng/PR. Nhờ đó, chức năng vừa viết xong có thể dùng bộ mẫu chung để thử ngay. Mốc dữ liệu nằm ở đầu khối A của Thành/Thái, không đợi xong quản lý độc giả, tìm kiếm, mượn–trả hoặc giao diện hoàn chỉnh. Không yêu cầu hoàn tất mọi khả năng ghi file hoặc mọi bộ dữ liệu lỗi trước khi viết nghiệp vụ; người viết vẫn tự chọn ca thử riêng cho chức năng mình.

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

**Push để nhóm xem và góp ý:** ai làm xong phần dữ liệu của mình thì cứ push lên nhánh riêng trước và gửi link nhánh/PR cho Thành, Thái và Tấn xem có ổn không; không cần đợi được duyệt mới push. Thành chuẩn bị xong thì Thái và Tấn xem; Thái chuẩn bị xong thì Thành và Tấn xem; Tấn chuẩn bị xong thì Thành và Thái xem. Cùng góp ý định dạng, nội dung, liên kết mã và mức phù hợp để thử chức năng; chưa có phần dữ liệu liên quan hoặc chưa chạy thử thì ghi rõ. Push là chia sẻ để xem xét, chưa phải ghép vào main hay xác nhận dữ liệu đã đúng.

**Dữ liệu mẫu chia sẻ sớm:** Thành, Thái hoặc Tấn chuẩn bị xong file theo định dạng chung thì đưa vào `DuLieu/`, push nhánh riêng và gửi PR ngay ở mốc đó; không cần đợi xong khối code hoặc đợi bộ dữ liệu của người khác hoàn chỉnh. PR có thể chỉ chứa dữ liệu và mô tả định dạng/phụ thuộc. Thành review độc giả/lịch sử, Thái review sách; ghi rõ đã thử đọc bằng chương trình hay mới kiểm tra nội dung. File chưa khớp các mã liên quan hoặc còn nháp phải được đánh dấu trong Draft PR, chưa coi là bộ mẫu hợp lệ chung. Quy định này nhằm chia sẻ dữ liệu sớm, không ép dừng để push sau từng hàm.

Mỗi người làm cả xử lý và màn hình phần mình. Có thể gom điều chỉnh giao diện liên quan vào PR của chức năng, hoặc gửi PR hoàn thiện giao diện riêng khi đủ ý nghĩa. Thành, Thái và Tấn cùng thống nhất bố cục/phím/thông báo; phần console dùng chung chia người thực hiện theo nhu cầu, không dồn riêng cho Thái.

Trước khi viết riêng, chốt những giao tiếp cần dùng ngay; không cần thiết kế xong toàn ứng dụng mới bắt đầu. Luồng ghép đầu có thể là đọc sách → menu → bảng sách cơ bản → quay lại. Bảng thử đó không tính là hoàn thành d và không bắt Tấn bỏ h để làm toàn bộ d trước.

Một PR dễ review cần có mục tiêu, phạm vi thực tế, phần phụ thuộc của Thành/Thái/Tấn, cách chạy, dữ liệu/kết quả kiểm tra và phần chưa xong. Người viết tự đề xuất ca thử; người review bổ sung thiếu sau. Không yêu cầu nhiều PR chỉ để chứng minh có làm việc.

Thành điều phối ghép; Thái review phần Thành, Thành review phần Thái; PR của Tấn được Thành review dữ liệu độc giả/lịch sử hoặc Thái review dữ liệu sách. Sau góp ý, tác giả sửa và push tiếp trên cùng nhánh. Sau khi ghép, cập nhật main trước khối mới. Giữ quy trình nhánh riêng → PR → review → ghép, không push thẳng main.

## 6. Lịch triển khai và luyện vấn đáp đến kỳ thi tháng 12/2026

Lịch nhóm thống nhất ngày 27/09/2026, dựa trên dự kiến thi giữa tháng 12; chưa phải lịch thi chính thức của thầy. Các ngày dưới đây đều thuộc năm 2026. Đối chiếu lịch học/lịch thi thực tế để trao đổi điều chỉnh sớm, không tự kéo dài khi sát hạn. Đây là mục tiêu công việc, không xác nhận phần nào đã hoàn thành.

**Hai hạn chính: đủ chức năng vào 31/10; ổn định bản nộp chậm nhất 15/11.** Nửa đầu tháng 11 là khoảng đệm kiểm thử và sửa lỗi, không phải thời gian mặc định để bắt đầu các chức năng còn thiếu. Luyện giải thích khi review xuyên suốt; tháng 11 tập trung đọc code của nhau và vấn đáp.

### 27/09–04/10 — nền chung và dữ liệu dùng thử

- **Thành:** cùng Thái chốt định dạng và quan hệ mã; chuẩn bị mẫu độc giả/lịch sử và phần đọc tối thiểu vào đúng cấu trúc.
- **Thái:** cùng Thành chốt định dạng; chuẩn bị mẫu đầu sách/cuốn sách và phần đọc tối thiểu. Cung cấp cách tra cứu dữ liệu sách cho Thành/Tấn khi đã sẵn sàng.
- **Tấn:** tìm hiểu cấu trúc chung, chuẩn bị yêu cầu/màn hình và dữ liệu thử cho h; tự làm menu cơ bản sau khi thống nhất điều hướng. Hỗ trợ tạo mẫu theo định dạng đã chốt.
- **Cả ba:** thống nhất môi trường biên dịch, cách chạy, quy ước console và giao tiếp giữa các phần. Chuẩn C++ đang hoãn xác định cần được chốt ở mốc này sau khi kiểm tra môi trường; tài liệu này không tự ấn định một chuẩn.
- **Điểm kiểm tra:** có bộ nhỏ khớp mã và kết quả đối chiếu, đọc được vào cấu trúc; tiếp đó bổ sung bộ dài hợp lệ để thử chức năng. Ai có phần dữ liệu trước thì push nhánh trước, không đợi 04/10 hoặc đợi đủ mọi file mới chia sẻ; ghi rõ phần chưa thử/chưa khớp.

### 05–18/10 — hoàn thành khối nền và ghép chạy sớm

- **Thành:** khối A — quản lý độc giả, đọc/ghi dữ liệu liên quan và màn hình; cung cấp phần ngày dùng chung sớm cho Thái, không chờ xong toàn bộ mượn–trả.
- **Thái:** khối A — quản lý sách, tìm kiếm, đọc/ghi và màn hình; bàn giao tra cứu sách sớm nếu Thành/Tấn đang cần.
- **Tấn:** khối A — h và menu cơ bản; làm tiếp khối B khi đủ dữ liệu và nền kiến thức. Thành/Thái hỗ trợ giải thích phần phụ thuộc, Tấn tự cài phần mình.
- **Điểm kiểm tra:** các khối nền có thể chạy thử bằng dữ liệu chung và có luồng ghép ban đầu. Thành thực hiện khối C xuyên suốt; mỗi tác giả sửa lỗi phần mình. Không chờ cả ba xong mới ghép.

### 19–31/10 — đủ a–j và các màn hình tương ứng

- **Thành:** hoàn thành khối B — ngày tháng, mượn–trả và màn hình; tiếp tục khối C để nối nạp/lưu/thoát và các phần của nhóm.
- **Thái:** hoàn thành khối B — thống kê quá hạn, top 10 và màn hình; dùng quy tắc đã làm rõ và phần ngày chung.
- **Tấn:** hoàn thành khối B/C — cả hai cách xem độc giả, liệt kê đầu sách theo thể loại/tên, xem dữ liệu dài và nối menu.
- **Đích 31/10:** bản chung chạy được a–j với màn hình, dữ liệu mẫu và đọc/ghi; đã thử trong phạm vi từng chức năng. Có thể còn lỗi cần sửa nhưng không còn nguyên phân hệ chưa triển khai. Push hoặc mở PR chưa đủ để ghi đạt mốc.

### 01–15/11 — kiểm thử tổng hợp, sửa lỗi và luyện song song

- **Cả ba:** kiểm tra dữ liệu dài, nhập sai, chuỗi mượn–trả, trạng thái giữa sách/lịch sử và lưu–tắt–mở lại; kiểm tra toàn bộ điều hướng console.
- **Thành:** điều phối kiểm tra bản ghép; **Thái và Tấn:** cùng kiểm tra, tự sửa phần phụ trách. Không dồn mọi lỗi cho Thành.
- Bắt đầu các buổi đọc và truy vết code của nhau; mỗi người giải thích phần mình và học cách các phần khác kết nối.
- **Đích 15/11:** chốt bản ổn định đã đối chiếu yêu cầu, ghi rõ lỗi/giới hạn còn tồn tại nếu có; không gọi bản còn lỗi bắt buộc là đã hoàn tất. Hạn chế đổi thiết kế lớn sau mốc này; lỗi ảnh hưởng tính đúng hoặc yêu cầu vẫn phải sửa và kiểm thử lại.

### 16–30/11 — tập trung hiểu code và bảo vệ đồ án

- Thành, Thái và Tấn luân phiên vai chạy chương trình, đặt câu hỏi và theo dõi code; đổi vai qua các buổi.
- Luyện giải thích cấu trúc/thuật toán, truy vết ca khó có nhiều điều kiện, tìm lỗi và tự sửa phần ngắn rồi kiểm thử lại. Hỏi trên đúng phiên bản code của nhóm.
- Cả ba học phần kết nối và code của nhau, không chỉ thuộc phần mình viết. Người giải thích được code đồng đội không được ghi là tác giả phần đó.
- Ghi ngắn phần còn yếu để luyện lại; không xem việc tham gia buổi luyện là bằng chứng đã hiểu toàn bộ.

### 01/12 đến trước ngày thi — thi thử và kiểm tra bản nộp

- Thi thử theo hình thức thầy đã thông báo; luyện lại phần còn yếu, không tự giả định quy chế cho phép trả lời thay đồng đội.
- Chạy bản dự kiến nộp trên môi trường trình bày, kiểm tra dữ liệu đi kèm và hướng dẫn chạy.
- Tránh thêm tính năng ngoài đề sát ngày thi. Nếu sửa lỗi, kiểm thử lại luồng bị ảnh hưởng và cập nhật đúng bản dùng chung.

### Nhịp theo dõi để không trễ mốc

- Mỗi tuần cả ba có một buổi kiểm tra ngắn, tự thống nhất giờ phù hợp: phần đã chạy được, kết quả thử, điểm đang kẹt và người cần hỗ trợ. Ghi ngắn kết quả thực tế cùng link nhánh/PR để nhóm theo dõi.
- Báo ngay khi có nguy cơ trễ hoặc phần phụ thuộc chặn người khác; không đợi tới ngày hết hạn. Trao đổi cách hỗ trợ/điều chỉnh công việc và ghi lại nếu đổi mốc, không âm thầm lùi lịch.
- Mốc là hạn có kết quả để kiểm tra, không phải ngày duy nhất được push. Giữ điểm dừng tự nhiên, chia sẻ sớm phần đã sẵn sàng, không ép push sau từng hàm và không đặt số PR bắt buộc.
- Giữ quy trình nhánh riêng → PR → review → ghép main. Dữ liệu, code và kết quả kiểm thử phải được mô tả đúng trạng thái thực tế.

## 7. Điều chỉnh so với danh sách mốc cũ

Các mã THANH-01…08, THAI-01…06, TAN-01…05 trong phiên bản trước được thay bằng các khối A/B/C ở trên. Nội dung công việc vẫn giữ, chỉ đổi nhịp bàn giao để không ép dừng sau từng chức năng nhỏ. Không có tiến độ, điểm hay bằng chứng độc lập nào được tạo hoặc xóa do việc gộp mốc.
