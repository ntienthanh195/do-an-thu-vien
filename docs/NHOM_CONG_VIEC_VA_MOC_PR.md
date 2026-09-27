# Nhóm công việc và mốc gửi PR của Thành, Thái, Tấn

Đây là kế hoạch triển khai ngày 27/09/2026, chưa nhóm nào được đánh dấu hoàn thành. Phân công a–j giữ nguyên. Mỗi người tự thiết kế, tạo file, đặt hàm, viết code và đề xuất test; tài liệu không cung cấp khung hay thuật toán.

## Quy tắc dùng chung

- Mỗi nhóm công việc dưới đây hướng tới một PR có mục tiêu rõ và kết quả kiểm tra được. Không chờ làm xong toàn bộ phần của một người mới push.
- Commit và push lên nhánh riêng trong lúc làm để lưu công việc. Còn dở hoặc thiếu phụ thuộc thì mở Draft PR, ghi rõ giới hạn; push không có nghĩa đã hoàn thành hay được ghép.
- Khi đạt phạm vi nhóm việc, gửi PR để review: Thành điều phối, người viết tự sửa. PR của Thành được Thái review phần liên quan; PR của Thái được Thành review; PR của Tấn được Thành hoặc Thái review đúng dữ liệu phụ trách.
- Một nhóm việc quá lớn có thể tách thêm thành phần chạy/thử được; không tách theo từng dòng, biến hay vòng lặp. Không thêm chức năng ngoài đề để làm đầy mốc.
- Mỗi PR có xử lý và giao diện cơ bản cần thiết để dùng phần đó. Thử thao tác nền bằng chương trình thử riêng là hợp lệ khi màn hình chung chưa sẵn sàng; ghi rõ đã thử phần nào. Không đưa nhiều main vào bản build chung hoặc ghép code làm hỏng bản đang chạy.
- Sau khi PR được ghép, cập nhật main trước khi tạo nhánh nhiệm vụ mới. Không tạo tất cả nhánh từ một bản main cũ. Nhánh đang làm cần cập nhật phụ thuộc thì phối hợp Thành, không chép đè file.

## 0. Mốc chung trước khi viết riêng — C0

**Người tham gia:** Thành, Thái và Tấn; Thành điều phối.

**Kết quả cần chốt:** bản khai báo dùng chung từ code nhóm; ranh giới file do thành viên đề xuất; cách gọi các phần cần trao đổi; định dạng dữ liệu; quy ước phím/bố cục và cách build phần nhóm đang làm. Có thể chốt theo phần cần trước, không đợi thiết kế xong mọi màn hình.

**Bàn giao:** một PR tài liệu/cấu hình cần thiết do nhóm tự chuẩn bị, ghi ai cung cấp dữ liệu gì, cách thử bản ghép. Không tạo sẵn thân hàm cho các thành viên điền. Khi cần hỗ trợ console chung, cả ba chọn người thực hiện một phần nhỏ và gửi PR riêng; không mặc định giao tất cả cho Thái.

## 1. Thành — các nhóm công việc

### THANH-01 — Tạo và tìm độc giả (một phần a)

- **Phạm vi:** thêm thẻ, cấp mã và tìm độc giả; dữ liệu nhập đúng yêu cầu đề, giữ cấu trúc BST. Có cách nhập/thử phần này; chưa nhận là xong sửa và xóa.
- **Cần trước:** C0 cho phần độc giả. Thành tự đề xuất cách cấp mã để dùng tiếp với lưu/đọc.
- **Gửi PR khi:** thử được phần đã cài, nêu dữ liệu/kết quả mong đợi và thực tế, bàn giao cho Tấn cách truy cập độc giả. Thái review.

### THANH-02 — Hiệu chỉnh độc giả (tiếp a)

- **Phạm vi:** chỉnh thông tin được phép và trạng thái thẻ, cùng màn hình tương ứng; bảo toàn mã/liên kết/lịch sử theo yêu cầu đã chốt.
- **Cần trước:** THANH-01.
- **Gửi PR khi:** kiểm tra việc sửa và khả năng tìm/dùng độc giả sau sửa; ghi rõ phần a còn xóa. Thái review.

### THANH-03 — Đọc/ghi độc giả và lịch sử mẫu

- **Phạm vi:** lưu/đọc độc giả, lịch sử mượn–trả và thông tin cần bảo toàn quy tắc mã qua các lần chạy. Chuẩn bị bộ mẫu nhỏ có mô tả, chưa cần nghiệp vụ mượn–trả hoàn chỉnh.
- **Cần trước:** THANH-01, định dạng chung với Thái và dữ liệu sách/tra cứu từ THAI-01/02. Kiểm tra liên kết với sách trên bản tích hợp khi THAI-03 sẵn sàng.
- **Gửi PR khi:** thử lưu–đọc trong phạm vi đã cài, dữ liệu mẫu có thể dùng cho Tấn làm h và Thái làm thống kê. Không báo nạp toàn hệ thống đúng nếu chưa kiểm tra cùng phần sách. Thái review.

### THANH-04 — Ngày tháng và kiểm tra quá hạn dùng chung

- **Phạm vi:** phần ngày cần cho đề, ý nghĩa ngày hợp lệ và mốc quá hạn đã thống nhất; công bố cách Thái sử dụng.
- **Cần trước:** quy tắc ngày/biên quá hạn được làm rõ; có thể làm song song với file và sửa độc giả sau C0.
- **Gửi PR khi:** Thành tự chọn và giải thích ca thử ngày, đối chiếu kết quả, Thái hiểu cách dùng cho mục i. Không thêm nghiệp vụ thời gian ngoài đề. Thái review.

### THANH-05 — Mượn sách (f)

- **Phạm vi:** các điều kiện mượn, cập nhật sách/lịch sử nhất quán và màn hình mượn. Hiển thị sách đang mượn phối hợp dùng phần h của Tấn.
- **Cần trước:** dữ liệu/tra cứu độc giả và sách, THANH-04, TAN-01 để ghép đủ màn hình f. Có thể thử logic trước khi TAN-01 xong nhưng phải ghi giới hạn.
- **Gửi PR khi:** kiểm tra kết quả chấp nhận/từ chối theo dữ liệu Thành tự chọn, đối chiếu các phần bị tác động và hiển thị liên quan. Thái review phần sách và tích hợp.

### THANH-06 — Trả sách (g)

- **Phạm vi:** trả theo lần mượn phù hợp, ngày và trạng thái đúng yêu cầu, giữ lịch sử; màn hình trả.
- **Cần trước:** THANH-05 để kiểm chuỗi nghiệp vụ; các điểm mất sách/ngày trả chưa rõ phải được ghi và làm rõ trước khi triển khai hành vi tương ứng.
- **Gửi PR khi:** kiểm tra được phần trả và chuỗi liên quan mượn–trả; đối chiếu dữ liệu sách, lịch sử, kết quả h. Thái review.

### THANH-07 — Xóa độc giả (hoàn thiện a)

- **Phạm vi:** xóa theo quy tắc được phép, giữ BST và quản lý dữ liệu/lịch sử đúng. Không suy quyền xóa lịch sử từ thuật toán xóa nút.
- **Cần trước:** THANH-01 và quy tắc xóa đã rõ; có thể làm sớm hơn số thứ tự này khi dữ liệu cần thử đã sẵn sàng.
- **Gửi PR khi:** tự kiểm tra phần xóa cùng tra cứu và mã thẻ sau lưu/đọc; nêu phần liên quan lịch sử đã được kiểm chứng đến đâu. Thái review.

### THANH-08 — Nạp/lưu/thoát và kiểm tra bản tích hợp

- **Phạm vi:** nối các phần vào chương trình chung, nạp/lưu dữ liệu nhất quán, thoát và giải phóng theo trách nhiệm sở hữu. Thành điều phối; Thái tự sửa phần sách, Tấn tự sửa menu/màn hình khi có lỗi.
- **Cần trước:** các PR đọc/ghi và menu cần cho luồng đang ghép. Thực hiện từng phần ngay khi sẵn sàng, không đợi mọi chức năng a–j xong mới ghép.
- **Gửi PR khi:** mô tả luồng cụ thể vừa nối và bằng chứng chạy lại liên quan. Nếu nhiều luồng độc lập, chia PR nạp dữ liệu và PR lưu/thoát. Thái review cùng Tấn ở phần menu.

## 2. Thái — các nhóm công việc

### THAI-01 — Nhập đầu sách (một phần c)

- **Phạm vi:** thông tin đầu sách theo đề, quản lý mảng con trỏ và thứ tự tên; màn hình nhập cơ bản.
- **Cần trước:** C0 cho phần sách. Tự đề xuất các kiểm tra đầu vào theo đề.
- **Gửi PR khi:** tự kiểm tra việc nhập và thứ tự dữ liệu; ghi rõ cuốn sách/cấp mã chưa nằm trong phần này. Thành review.

### THAI-02 — Cuốn sách, cấp mã và tra cứu (hoàn thiện phần xử lý c)

- **Phạm vi:** cuốn thuộc đầu sách, mã cuốn duy nhất, trạng thái/vị trí và tra cứu; hoàn thiện màn hình c tương ứng.
- **Cần trước:** THAI-01; quy tắc mã và phần cần lưu phải thống nhất với Thành.
- **Gửi PR khi:** Thành dùng được tra cứu cuốn cho mượn–trả, Tấn dùng được dữ liệu đầu sách/tên theo mã cuốn. Có dữ liệu và kết quả thử do Thái chọn. Thành review.

### THAI-03 — Đọc/ghi sách và bộ mẫu

- **Phạm vi:** lưu/đọc đầu sách, cuốn sách theo định dạng chung; bộ mẫu nhỏ và bộ dài có mô tả, dữ liệu lỗi có chủ đích để riêng.
- **Cần trước:** THAI-01/02 và định dạng đã chốt với Thành. Làm sớm để cả nhóm dùng dữ liệu, không chờ thống kê.
- **Gửi PR khi:** đối chiếu lưu–đọc, cung cấp cách nạp dữ liệu để Thành ghép và Tấn dùng. Thái chịu trách nhiệm dữ liệu sách nhất quán; Tấn hỗ trợ chuẩn bị mẫu theo định dạng. Thành review.

### THAI-04 — Tìm sách theo tên (e)

- **Phạm vi:** tìm theo cách hiểu đã thống nhất, xuất đủ thông tin đề; tự làm màn hình tìm và xem kết quả.
- **Cần trước:** THAI-01/02; dùng bộ mẫu khi THAI-03 sẵn sàng, không bắt buộc chờ file để bắt đầu thiết kế.
- **Gửi PR khi:** kết quả và thông tin hiển thị được kiểm trên dữ liệu tự chọn; xem được kết quả dài theo phạm vi màn hình đã nhận. Thành review.

### THAI-05 — Danh sách độc giả quá hạn (i)

- **Phạm vi:** xác định kết quả quá hạn và thứ tự giảm dần, màn hình thống kê.
- **Cần trước:** lịch sử/độc giả mẫu từ THANH-03, phần ngày THANH-04 và quy tắc chọn mốc khi một độc giả có nhiều cuốn quá hạn. Không phải chờ toàn bộ mượn–trả nếu dữ liệu mẫu đã hợp lệ.
- **Gửi PR khi:** có kết quả mong đợi tự tính để so sánh, giải thích nguồn dữ liệu và dùng thống nhất cách tính ngày của Thành. Thành review.

### THAI-06 — Top 10 sách mượn nhiều nhất (j)

- **Phạm vi:** thống kê và màn hình top 10 theo quy tắc đã xác nhận, không tự thêm bộ đếm nghiệp vụ vào cấu trúc chỉ vì tiện.
- **Cần trước:** dữ liệu sách/lịch sử dùng chung; đã rõ tính theo đầu sách hay cuốn, cách tính lượt và đồng hạng. Có thể làm song song THAI-05 khi đủ điều kiện.
- **Gửi PR khi:** đối chiếu với kết quả mong đợi, giải thích lựa chọn và chi phí; ghi mọi giới hạn chưa kiểm tra. Thành review.

## 3. Tấn — các nhóm công việc

### TAN-01 — Sách độc giả đang mượn (h)

- **Phạm vi:** tự viết xử lý liệt kê mã/tên sách đang mượn và màn hình nhận mã thẻ/xem kết quả.
- **Cần trước:** Thành cung cấp dữ liệu độc giả/lịch sử và cách tra cứu; Thái cung cấp dữ liệu sách và cách tra tên theo mã cuốn. Dùng mẫu hợp lệ từ THANH-03 và THAI-02/03; không chờ f/g hoàn chỉnh.
- **Gửi PR khi:** Tấn tự chọn dữ liệu và kết quả mong đợi, chạy đối chiếu, giải thích dữ liệu liên quan; chỉ xem không làm thay đổi nghiệp vụ. Thành review lịch sử, Thái review thông tin sách.

### TAN-02 — Độc giả theo mã (một phần b)

- **Phạm vi:** liệt kê độc giả theo mã tăng dần và màn hình tương ứng; tự chọn cách duyệt cây.
- **Cần trước:** dữ liệu cây và cách truy cập từ Thành; học đúng nền cây còn thiếu. Nếu TAN-01 đang chờ phụ thuộc, có thể trao đổi để làm nhóm này trước khi đủ nền.
- **Gửi PR khi:** thứ tự/nội dung được kiểm trên dữ liệu Tấn chọn, không phá cây; ghi rõ chưa có lựa chọn theo tên+họ. Thành review.

### TAN-03 — Độc giả theo tên+họ (hoàn thiện b)

- **Phạm vi:** bổ sung lựa chọn xem theo tên+họ, giữ lựa chọn mã; tự chuẩn bị thứ tự kết quả và giao diện chuyển lựa chọn.
- **Cần trước:** TAN-02, quy tắc so sánh tên/họ đã thống nhất và nền sắp xếp cần dùng.
- **Gửi PR khi:** kiểm cả hai lựa chọn, dữ liệu gốc vẫn đúng; nêu phần được hướng dẫn và phần tự làm. Thành review.

### TAN-04 — Đầu sách theo thể loại và tên (d)

- **Phạm vi:** tự tổ chức liệt kê theo thể loại, tên tăng trong nhóm, màn hình xem danh sách.
- **Cần trước:** dữ liệu đầu sách từ Thái, quy ước hiển thị thể loại đã rõ; không cần chờ i/j.
- **Gửi PR khi:** kiểm kết quả hiển thị và thứ tự lưu gốc trên dữ liệu Tấn chọn, xem được dữ liệu dài. Thái review dữ liệu sách, Thành kiểm phần ghép.

### TAN-05 — Menu và điều hướng đến chức năng đã có

- **Phạm vi:** menu chính và đường vào/quay lại màn hình đã cài; mục chưa cài thể hiện đúng tình trạng. Tấn tự làm giao diện theo quy ước cả nhóm.
- **Cần trước:** C0 về phím/luồng, ít nhất một màn hình có thể gọi. Có thể làm song song các nhóm trên; không phải đợi TAN-04.
- **Gửi PR khi:** chỉ rõ màn hình nào đã nối, kiểm thao tác điều hướng tương ứng; Thành review và phối hợp nạp/lưu/thoát. Nối thêm màn hình về sau có thể thành PR nhỏ theo từng nhóm liên quan.

## 4. Giao diện và các mốc ghép chung

Mỗi người tự làm màn hình chức năng mình phụ trách. Không cần trang trí hoàn chỉnh mới push; bản cơ bản phải dùng/thử được trong phạm vi công bố. Nếu phân trang/điều hướng/hoàn thiện trình bày là thay đổi độc lập đủ ý nghĩa thì mở PR riêng theo tên người và màn hình; chức năng còn thiếu yêu cầu hiển thị không được đánh dấu hoàn tất chỉ vì PR xử lý đã ghép.

Gợi ý thứ tự phối hợp để không chờ nhau:

1. **Sau C0:** Thành bắt đầu THANH-01, Thái bắt đầu THAI-01; Tấn đọc h, tự phác yêu cầu màn hình và dữ liệu thử, trao đổi phần tra cứu cần có. Tấn có thể chuẩn bị menu sau khi quy ước rõ.
2. **Khi sách và đọc file sẵn sàng:** ghép luồng đọc sách → menu → xem bảng cơ bản → quay lại. Bảng thử không tính là hoàn thành d; không bắt Tấn bỏ h để làm toàn bộ d trước.
3. **Khi có độc giả/lịch sử mẫu và tra cứu sách:** Tấn triển khai/hoàn thiện TAN-01; Thành tiếp tục phần ngày và chuẩn bị mượn. Thái làm e, chuẩn bị thống kê theo dữ liệu sẵn có.
4. **Sau mỗi nhóm nghiệp vụ:** ghép sớm và thử phần liệt kê/thống kê liên quan. Thành, Thái và Tấn tự sửa phần mình sau khi cùng xác định nguyên nhân.
5. **Trước kết thúc đồ án:** cả ba rà đủ a–j, giao diện, dữ liệu dài, lưu–mở lại và phần còn thiếu; luyện giải thích trên phiên bản thực tế. Không lấy số PR làm số chức năng hoàn thành hoặc bằng chứng tự chủ.

## 5. Nội dung một PR để người nhận dễ review

- Mã nhóm việc và phạm vi thật đã làm (ví dụ TAN-02), file do người viết tự tạo/sửa.
- Chức năng người dùng có thể thử; cách chạy theo cấu hình build hiện tại của nhóm.
- Phụ thuộc PR/phần nào của Thành, Thái hoặc Tấn; phần đó đã ghép chưa.
- Dữ liệu thử, kết quả mong đợi, kết quả thực tế; phân biệt tự nghĩ và được gợi ý.
- Việc còn thiếu hoặc quy tắc chưa xác nhận; Draft nếu chưa sẵn sàng ghép.

Sau review, tác giả tự sửa trên cùng nhánh và push tiếp vào PR đó. Thành chỉ ghép khi các kiểm tra phù hợp đạt; không bỏ qua lỗi build hoặc phụ thuộc còn thiếu để kịp số lượng PR. Nếu bị chặn ở một phần, làm phần độc lập đã đủ điều kiện hoặc ghi câu hỏi cần giải quyết, không viết kết quả giả để lấp chỗ trống.
