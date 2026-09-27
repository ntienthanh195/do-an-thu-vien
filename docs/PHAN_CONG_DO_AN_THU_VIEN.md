# Phân công đồ án nhóm Thư viện

> Cập nhật 27/09/2026 — phân công triển khai đã thống nhất với Thành. Phần A dưới đây là nhiệm vụ hiện hành; phần B giữ nguyên hồ sơ phân công khai báo ngày 15/09 để tra cứu. Đây là kế hoạch công việc, chưa phải xác nhận chức năng đã hoàn thành.

## PHẦN A — PHÂN CÔNG TRIỂN KHAI HIỆN HÀNH

### 1. Sản phẩm chung của nhóm

Xây dựng ứng dụng quản lý Thư viện theo đề số 3, gồm đủ chức năng a–j, giao diện console hoàn chỉnh và khả năng đọc/ghi dữ liệu file.

- Giữ đúng bốn cấu trúc theo đề: mảng con trỏ đầu sách tăng theo tên; danh sách đơn cuốn sách; BST độc giả; danh sách đơn mượn–trả của mỗi độc giả.
- Có các màn hình sách, độc giả, mượn–trả, liệt kê và thống kê; có menu, bảng dữ liệu, nhập liệu, thông báo và đường quay lại.
- Đọc được dữ liệu chuẩn bị sẵn để thử chức năng ngay trong quá trình phát triển, gồm cả danh sách dài. Không chờ hoàn thành toàn bộ mới làm phần đọc file.
- Mỗi người trực tiếp viết, kiểm thử và giải thích phần mình phụ trách. Nhóm hỗ trợ nhau học nền và review; cả ba cùng tìm hiểu cách các phần kết nối.

### 2. Thành — độc giả, mượn–trả và điều phối tích hợp

**Chức năng chính:**

- **a — Quản lý thẻ độc giả:** thêm, xóa, hiệu chỉnh; cấp mã thẻ tự động không trùng mã thẻ cũ; quản lý thông tin và trạng thái thẻ đúng đề.
- **f — Mượn sách:** phối hợp dữ liệu độc giả, cuốn sách và lịch sử mượn; kiểm tra các điều kiện mượn theo đề.
- **g — Trả sách:** xử lý nghiệp vụ trả và bảo đảm thông tin cuốn sách, bản ghi mượn–trả nhất quán.
- Xử lý ngày tháng dùng chung: kiểm tra ngày và tính thời gian phục vụ mượn–trả, quá hạn. Thái sử dụng phần này cho mục i, không viết một cách tính khác.

**Giao diện và dữ liệu:**

- Làm màn hình nhập/sửa độc giả, mượn và trả sách bằng bộ hỗ trợ giao diện chung.
- Phụ trách đọc/ghi độc giả và lịch sử mượn–trả, bao gồm dữ liệu cần duy trì quy tắc cấp mã qua các lần chạy.
- Điều phối điểm chạy chung, nạp dữ liệu, lưu/thoát và ghép các chức năng với menu do Tấn làm.
- Cùng Thái hỗ trợ xây dựng và thống nhất cách sử dụng các thành phần giao diện chung.

**Cung cấp cho các bạn:** khả năng tìm độc giả theo mã, truy cập dữ liệu độc giả/lịch sử mượn để liệt kê, và các hàm ngày tháng đã thống nhất. Chức năng liệt kê phải chỉ đọc dữ liệu nghiệp vụ.

### 3. Thái — sách, thống kê và hỗ trợ giao diện chung

**Chức năng chính:**

- **c — Nhập thông tin đầu sách và cấp mã cuốn sách tự động:** quản lý mảng con trỏ đầu sách, danh mục cuốn sách và tra cứu theo mã; giữ thứ tự đầu sách theo đề.
- **e — Tìm thông tin sách theo tên:** xuất đủ các thông tin đề yêu cầu, gồm mã ISBN, thông tin đầu sách, các mã cuốn và trạng thái.
- **i — Liệt kê độc giả quá hạn:** theo thời gian quá hạn giảm dần, phối hợp dữ liệu mượn–trả và phần tính ngày của Thành.
- **j — Thống kê 10 sách có số lượt mượn nhiều nhất:** phối hợp lịch sử mượn do phần của Thành quản lý.

**Giao diện và dữ liệu:**

- Làm các màn hình nhập sách, tìm kiếm và thống kê thuộc phần mình.
- Phụ trách đọc/ghi đầu sách và cuốn sách.
- Phụ trách chính bộ hỗ trợ console dùng chung: khung, màu, tô sáng lựa chọn, nhận phím điều hướng, hỗ trợ bảng và phân trang. Thành cùng hỗ trợ; Thái không phải làm thay tất cả màn hình của hai bạn.
- Làm bản hỗ trợ tối thiểu đủ dùng trước, mở rộng theo nhu cầu thật của các màn hình.

**Cung cấp cho các bạn:** khả năng tìm cuốn sách/đầu sách và lấy thông tin liên quan, quy ước sử dụng trạng thái cuốn sách, các thành phần giao diện dùng chung. Việc thay đổi trạng thái khi mượn–trả phải thống nhất với Thành, tránh hai phần cập nhật độc lập gây lệch dữ liệu.

### 4. Tấn — liệt kê dữ liệu và các màn hình tương ứng

**Chức năng chính:**

- **h — Liệt kê sách một độc giả đang mượn:** hiển thị mã sách và tên sách theo mã thẻ được chọn; sử dụng khả năng tìm độc giả của Thành và tra cứu sách của Thái.
- **b — In danh sách độc giả:** hỗ trợ thứ tự mã thẻ tăng dần và tên+họ tăng dần theo lựa chọn.
- **d — In danh sách đầu sách:** theo từng thể loại, trong mỗi thể loại tăng theo tên sách.
- Làm menu chính và nối đến các màn hình bằng bộ hỗ trợ chung; phối hợp với Thành khi ghép luồng chương trình.

**Phạm vi trực tiếp làm:** Tấn tự viết phần duyệt, lọc, chuẩn bị thứ tự kết quả và hiển thị của b, d, h; không chỉ nhận dữ liệu đã xử lý xong để in. Việc liệt kê không được làm sai cấu trúc hoặc thứ tự lưu bắt buộc của dữ liệu gốc.

**Thứ tự triển khai:** h → b theo mã → b theo tên+họ → d. Mỗi mốc là một chức năng có thể chạy thử. Khi cần kiến thức cây hoặc sắp xếp, nhóm hỗ trợ giải thích rồi Tấn tự cài và kiểm thử. Menu có thể làm song song khi bộ hỗ trợ đã đủ dùng.

**Hỗ trợ và dữ liệu thử:**

- Thành và Thái cung cấp các hàm tra cứu, hướng dẫn cách gọi và dữ liệu mẫu nhất quán.
- Tấn tự đề xuất dữ liệu và kết quả mong đợi cho phần mình; hai bạn review và bổ sung những ca còn thiếu.
- Tấn hỗ trợ chuẩn bị dữ liệu dài theo định dạng chung và ghi lỗi giao diện/chức năng gặp khi thử. Đây là việc hỗ trợ thêm, không thay phần code trực tiếp.

### 5. Quy ước chung để ghép code thuận tiện

**Khai báo và trách nhiệm:**

- Dùng một bộ cấu trúc và hằng trạng thái chung đã được cả nhóm đối chiếu đề. Thay đổi tên, kiểu hoặc ý nghĩa trường phải trao đổi trước khi sửa.
- Mỗi hàm dùng chung có một nơi cài đặt và một người phụ trách; các phần khác gọi lại, không sao chép rồi sửa thành nhiều phiên bản.
- Trước khi viết riêng, thống nhất tên hàm, đầu vào, đầu ra, cách báo không tìm thấy/thất bại và dữ liệu hàm được phép thay đổi. Người phụ trách tự đề xuất khai báo hàm, cả nhóm chốt cách gọi.
- Chương trình chung sử dụng cùng một bộ dữ liệu Thư viện. Không để mỗi phần tạo một bản độc giả hoặc sách riêng rồi xử lý lệch nhau.
- Chức năng mượn–trả do Thành chịu trách nhiệm tính nhất quán toàn nghiệp vụ; chức năng chỉ đọc của Tấn không cập nhật trạng thái hoặc lịch sử.

**Tổ chức file đề xuất để nhóm thống nhất:**

- `KhaiBao.h`: cấu trúc và hằng dùng chung; Thành điều phối thay đổi sau trao đổi nhóm.
- `DocGia.h/.cpp`, `MuonTra.h/.cpp`: phần Thành phụ trách; ngày tháng có thể tách file khi cần.
- `Sach.h/.cpp`, `ThongKe.h/.cpp`: phần Thái phụ trách.
- `LietKe.h/.cpp`, `Menu.h/.cpp`: phần Tấn phụ trách.
- `GiaoDien.h/.cpp`: bộ hỗ trợ chung, Thái phụ trách chính và Thành hỗ trợ.
- `main.cpp`: một điểm chạy duy nhất, Thành điều phối. Chương trình thử riêng của từng người giữ ngoài bản ghép.

Đây là cách chia file dự kiến, chưa phải các file đã được tạo. `.h` công bố cách gọi; `.cpp` chứa cài đặt. Chia file không thay đổi bốn cấu trúc dữ liệu theo đề.

**Giao diện console:**

- Nhóm thống nhất kích thước bố cục, màu, cách nhận phím và ý nghĩa Enter/Esc/quay lại trước khi làm nhiều màn hình.
- Có thể kết hợp phím số với Enter, phím mũi tên và tô sáng lựa chọn. Đề xuất: ↑/↓ chọn menu, Enter mở, Esc quay lại; nhóm chốt quy ước cuối cùng và dùng nhất quán.
- Bảng dữ liệu dài phải xem được các phần tiếp theo bằng phân trang hoặc cách cuộn nhóm thống nhất; không chỉ hiển thị vừa một màn hình rồi bỏ phần còn lại.
- Mỗi màn hình có hướng dẫn thao tác, thông báo lỗi/thành công phù hợp và đường quay lại rõ ràng.
- Phân biệt hàm nhập/hiển thị với hàm xử lý nghiệp vụ; thống nhất nơi xóa màn hình, chờ phím và điều khiển chuyển màn hình để các hàm không gây gián đoạn nhau.

### 6. Dữ liệu file và kiểm thử

- Thành và Thái chốt định dạng file, quan hệ giữa mã thẻ/mã cuốn/lịch sử mượn, quy tắc đọc/ghi và cách báo lỗi. Tấn chuẩn bị dữ liệu theo định dạng đã chốt, không phải tự quyết định định dạng cho cả nhóm.
- Chuẩn bị bộ nhỏ có kết quả mong đợi rõ; bộ lớn hợp lệ, liên kết nhất quán để thử dữ liệu dài; và bộ lỗi có chủ đích được giữ riêng để thử xử lý dữ liệu sai.
- Dữ liệu dài giúp thử quy mô và giao diện, không tự chứng minh bao phủ lỗi nghiệp vụ. Mỗi người thiết kế thêm ca thử theo yêu cầu chức năng mình phụ trách, rồi nhóm review.
- Thử cả sau khi đọc dữ liệu và sau chuỗi thao tác trên chương trình; kiểm tra lưu rồi mở lại có bảo toàn dữ liệu cần thiết không.
- Không ghi trực tiếp địa chỉ con trỏ hoặc bê nguyên cách ghi nhị phân struct sinh viên sang các struct chứa `string` và con trỏ của Thư viện. Hai người phụ trách file thống nhất cách lưu dữ liệu và dựng lại liên kết.
- Ghi rõ phiên bản code, dữ liệu thử, kết quả mong đợi và kết quả thực tế. Biên dịch được, chạy đúng ca đã thử và tự giải thích được là các bằng chứng khác nhau.

### 7. Các mốc ghép và cách bàn giao

1. **Chốt nền chung:** bộ khai báo, cách gọi hàm giữa ba phần, định dạng file và quy ước giao diện; bản chung biên dịch được.
2. **Luồng đầu tiên:** mở chương trình → đọc file sách mẫu → menu → bảng sách xem được dữ liệu dài → quay lại → thoát. Thái làm đọc sách và hỗ trợ bảng, Tấn làm màn hình liệt kê ở mức phù hợp và menu, Thành nối khởi động. Màn hình tạm chưa đủ nhóm thể loại/thứ tự không được tính là hoàn thành mục d.
3. **Dữ liệu độc giả và liệt kê:** ghép phần độc giả, dữ liệu lịch sử mẫu và các màn hình b, h; mở rộng d theo đúng đề.
4. **Mượn–trả:** ghép f, g với độc giả, sách và lịch sử; kiểm tra các màn hình liệt kê phản ánh đúng thay đổi.
5. **Hoàn thiện:** c, e, i, j cùng các yêu cầu còn thiếu; kiểm thử lưu/đọc, dữ liệu dài, nhập sai và toàn bộ luồng giao diện. Một số phần có thể làm song song khi phụ thuộc đã sẵn sàng.

Mỗi lần giao code phải kèm: chức năng đã làm, cách gọi/phụ thuộc, ca thử và kết quả, phần còn thiếu. Người viết tự sửa phần mình sau review; Thành điều phối bản ghép, không nhận làm thay mọi phần.

Từ 27/09/2026, mã nguồn và tài liệu triển khai chung được quản lý tại repo riêng tư [do-an-thu-vien](https://github.com/ntienthanh195/do-an-thu-vien). Mỗi nhiệm vụ làm trên một nhánh, gửi pull request để review và ghép vào main; Thành điều phối ghép sau kiểm tra. Drive ở phần B dùng cho đề, tài liệu, ảnh/video hoặc bản đóng gói, không giữ một bản code chính thức song song. Ghép theo mốc nhỏ, không đợi cả ba hoàn thành toàn bộ mới ghép. Thái và Tấn cần được mời vào repo bằng tài khoản GitHub của từng người; chưa coi việc tạo repo là đã cấp quyền cho hai bạn.

### 8. Những điểm phải làm rõ trước khi chốt hành vi liên quan

- Top 10 tính theo đầu sách hay cuốn sách, xử lý đồng hạng thế nào.
- Cách xác định thời gian quá hạn của một độc giả khi có nhiều cuốn quá hạn; mốc ngày dùng để tính.
- Điều kiện xóa độc giả/sách khi còn liên quan tới mượn–trả hoặc lịch sử; cách bảo toàn yêu cầu mã thẻ không trùng mã cũ.
- Cách xử lý trường hợp làm mất sách và ý nghĩa ngày trả tương ứng.

Đây là các điểm cần đối chiếu đề hoặc hỏi thầy; nhóm không tự coi một giả định là quy tắc thầy đã xác nhận. Không tự thêm nghiệp vụ hoặc thay cấu trúc bắt buộc.

---

## PHẦN B — LỊCH SỬ PHÂN CÔNG MỐC KHAI BÁO 15/09/2026

Phần bên dưới được giữ nguyên để tra cứu. Các câu như “chưa cần làm menu/chức năng” và phân công cũ cho Tấn chỉ áp dụng mốc khai báo trước 19/09; nhiệm vụ triển khai hiện tại theo phần A.

### Phân công chuẩn bị đồ án Thư viện — bản cũ

> Cập nhật 15/09/2026 — chuẩn bị cho thứ bảy 19/09/2026. Đây là phân công cho mốc khai báo, chưa phải chia cố định mọi chức năng trong cả tháng.

## 1. Mục tiêu trước thứ bảy

Từ bây giờ đến buổi thầy đọc phần khai báo, nhóm cần hoàn thành một bản khai báo đầu tiên có thể biên dịch được. Nhóm **chưa cần làm menu, chức năng thêm/xóa/sửa, mượn/trả hoàn chỉnh hoặc giao diện**.

Bản khai báo phải thể hiện rõ bốn cấu trúc mà đề yêu cầu:

1. Đầu sách: danh sách tuyến tính dạng mảng con trỏ, tăng theo tên sách.
2. Danh mục sách: danh sách liên kết đơn chứa từng cuốn sách cụ thể.
3. Thẻ độc giả: cây nhị phân tìm kiếm.
4. Mượn trả: danh sách liên kết đơn, được liên kết với thẻ độc giả.

Điều quan trọng là cả ba người đều hiểu toàn bộ thiết kế. Mỗi người có một phần viết chính, nhưng không được chỉ biết phần của mình.

## 2. Nguyên tắc làm việc chung

### Yêu cầu quan trọng của thầy: làm đúng đề

Người học bổ sung ngày 15/09/2026: thầy yêu cầu giữ đúng cấu trúc và thông tin của đề, tự ý thay đổi sẽ bị trừ điểm nặng. Cả ba áp dụng ngay khi khai báo:

- Giữ đủ các trường, kiểu dữ liệu và giá trị trạng thái được đề quy định; giữ đúng bốn cấu trúc ở mục 1.
- Chỉ thêm phần hỗ trợ cần thiết cho yêu cầu đã có và phải giải thích được mục đích. Ví dụ: con trỏ nối nút, gốc cây, số đầu sách đang dùng, kiểu ngày tháng. Không coi đây là quyền tự do thêm thông tin.
- Không tự thêm phí phạt, hạng độc giả, đặt trước hoặc đổi cấu trúc chỉ vì thấy tiện/nhanh hơn.
- Nếu muốn lưu thêm tổng lượt mượn hoặc số sách đang mượn, phải nêu vì sao không tính từ dữ liệu sẵn có, cách cập nhật và tránh lệch. Khi chưa rõ thầy có cho phép, ghi câu hỏi để hỏi thầy trước khi đưa vào bản nộp.
- Mỗi người ghi rõ trong bảng giải thích: **trường theo đề / phần hỗ trợ cài đặt / mục đích / cách duy trì đúng / điểm cần hỏi thầy**. Thống nhất nội bộ nhóm không thay thế được yêu cầu của thầy.

### Cách dùng các gợi ý code bên dưới

Các đoạn C++ chỉ minh họa một vài cách khai báo, **không phải bộ khai báo hoàn chỉnh để nộp**. Tên như `NutDocGia`, `DauSach`, `Ngay` là tên minh họa; nhóm tự thống nhất tên, cách tổ chức `struct`/`class`, vị trí khai báo và khởi tạo phù hợp với quy định của thầy. Phần đề đã quy định thì phải giữ đúng. Không cần làm giống hệt cách viết trong gợi ý.

Các kiểu và hằng dùng trong ví dụ phải được khai báo phù hợp trước khi sử dụng. Không ghép nguyên các mẩu ví dụ rồi coi là chương trình hoàn chỉnh. Dấu `*` trong khai báo là con trỏ; `nullptr` là chưa trỏ đến đối tượng, không tạo đối tượng mới.

### Bảng phân công

| Thành viên | Phần trực tiếp viết |
|---|---|
| Thành viên 1 — Thành | Thẻ độc giả, nút cây tìm kiếm theo mã thẻ và cách quản lý gốc cây |
| Thành viên 2 — Thái | Đầu sách, mảng con trỏ quản lý đầu sách và danh sách liên kết các cuốn sách |
| Thành viên 3 — Tấn | Ngày tháng, bản ghi mượn trả và danh sách liên kết mượn trả |

**Ghép code và kiểm tra là việc chung; thành viên 1 điều phối buổi ghép.** Mỗi người tự sửa phần mình phụ trách sau khi cả nhóm trao đổi.

Trước khi viết riêng, phải chốt ba điểm kết nối:

- Thành viên 1 và 3: kiểu danh sách mượn trả mà mỗi độc giả liên kết đến. Thành viên 3 khai báo kiểu này; thành viên 1 sử dụng, không khai báo lại.
- Thành viên 2 và 3: kiểu và ý nghĩa mã cuốn sách trong danh mục phải khớp với mã sách ở bản ghi mượn.
- Cả ba: tên kiểu, tên trường, ý nghĩa trạng thái, cách biểu diễn dữ liệu rỗng và nơi khai báo từng kiểu để tránh trùng.

Sơ đồ chung:

```text
Mảng con trỏ đầu sách
  └─ Mỗi đầu sách → danh sách các cuốn thuộc đầu sách đó

Cây thẻ độc giả
  └─ Mỗi độc giả → danh sách các lần mượn trả
                    └─ Mã sách tham chiếu đến một cuốn trong danh mục
```

Liên hệ qua mã sách không bắt buộc phải thêm con trỏ trực tiếp tới cuốn sách. Nhóm cần giải thích cách tra cứu dự kiến, chưa cần viết chức năng tra cứu.

- Cả nhóm thống nhất sơ đồ, tên kiểu dữ liệu, tên trường và ý nghĩa trạng thái trước khi viết.
- Không tự ý đổi tên trường hoặc thay đổi kiểu dữ liệu trong phần của người khác mà chưa trao đổi.
- Mỗi người trực tiếp viết code phần mình được giao.
- Sau khi ghép code, cả ba cùng biên dịch và đọc lại toàn bộ file.
- Chưa làm chức năng để tránh thiết kế vội và khó sửa.
- Không lưu trùng một thông tin nếu chỉ cần một nơi quản lý.

## 3. Phần việc của thành viên 1 — Thành

### Người phụ trách

Thành viên 1: **Thành**

### Phần code chính

- Thiết kế và viết khai báo **thẻ độc giả dạng cây nhị phân tìm kiếm**.
- Khai báo thông tin độc giả: mã thẻ, họ, tên, phái, trạng thái thẻ; thể hiện nhánh trái, nhánh phải của nút cây.
- Khai báo cách quản lý gốc cây và nêu cách biểu diễn cây chưa có độc giả.
- Thống nhất với thành viên 3 cách một thẻ độc giả liên kết đến danh sách mượn trả. Thành viên 1 không viết lại nút mượn trả.
- Điều phối buổi ghép code và giữ bản chung sau khi cả nhóm kiểm tra.

Theo đề: mã thẻ là số nguyên tự cấp, không trùng mã thẻ cũ; phái nhận Nam/Nữ; trạng thái thẻ 0 là khóa, 1 là hoạt động. Chỉ cần nêu quy ước cấp mã dự kiến ở mốc này, chưa phải hoàn thành hàm cấp mã.

### Gợi ý code cho thành viên 1 — chỉ để bắt đầu

Hãy tự phác thảo hai phần: **một nút cây có gì** và **cả cây được truy cập từ đâu**. Trong nút cần phân biệt dữ liệu độc giả, liên kết sang các nút cây khác và liên kết sang danh sách mượn trả.

Ví dụ cú pháp khai báo một con trỏ quản lý gốc:

```cpp
// Giả sử nhóm đã khai báo kiểu NutDocGia.
NutDocGia* goc = nullptr;
```

Dòng này chỉ biểu diễn một cây đang rỗng; chưa tạo độc giả và chưa tạo nút. Nhóm tự chọn nơi đặt biến gốc để quản lý cả cây, không mặc định mỗi nút giữ thêm một gốc riêng.

Với liên kết bên trong nút, dạng khai báo cần hiểu là:

```cpp
KieuNut* lienKet;  // Mẫu cú pháp; thay bằng kiểu và tên đúng vai trò.
```

Tự xác định liên kết trái/phải cần kiểu gì, còn liên kết tới lịch sử mượn dùng kiểu nào do thành viên 3 cung cấp. Đừng thay liên kết bằng một đối tượng cùng kiểu nằm trực tiếp trong chính nó: cần hiểu sự khác nhau giữa chứa địa chỉ và chứa toàn bộ đối tượng.

**Phần tự hoàn thiện:** các trường theo đề, khai báo nút, hai nhánh, liên kết mượn trả và cách khởi tạo chúng. Chưa viết thuật toán thêm/tìm/xóa cây. Khai báo mã thẻ kiểu số nguyên không tự sinh ra mã duy nhất; việc cấp mã là thao tác phải làm sau.

### Việc kiểm tra cùng cả nhóm

- Kiểm tra tên kiểu dữ liệu, con trỏ và quan hệ giữa bốn cấu trúc.
- Kiểm tra các trạng thái có bị dùng lẫn không:
  - trạng thái thẻ độc giả;
  - trạng thái cuốn sách;
  - trạng thái một lần mượn/trả.
- Biên dịch bản chung sau mỗi lần ghép.
- Ghi lại các lỗi hoặc điểm chưa thống nhất để cả nhóm cùng quyết định.

### Thành viên 1 phải giải thích được

- Vì sao thẻ độc giả dùng cây nhị phân tìm kiếm.
- Khóa tìm kiếm của cây là trường nào.
- Đâu là thông tin độc giả, đâu là liên kết của cây?
- Gốc cây khác một nút cây ở vai trò nào? Cây rỗng được biểu diễn ra sao?
- Tìm theo mã thẻ khác in theo tên + họ thế nào?
- Hình dạng cây ảnh hưởng đến tốc độ tìm kiếm ra sao?
- Một độc giả chưa mượn sách liên kết đến danh sách mượn trả thế nào?

### Sản phẩm phải nộp

- Phần khai báo do thành viên 1 tự viết.
- Bảng giải thích tên trường, kiểu dữ liệu dự kiến, ý nghĩa và lý do cần từng trường.
- Sơ đồ cây nhỏ và liên kết từ một độc giả đến danh sách mượn trả.
- Một danh sách ngắn các điểm cần cả nhóm thống nhất.

## 4. Phần việc của thành viên 2 — Thái

### Người phụ trách

Thành viên 2: **Thái**

### Phần code chính

- Thiết kế và viết khai báo **đầu sách**.
- Khai báo **mảng con trỏ quản lý đầu sách**, phân biệt số đầu sách đang có với sức chứa mảng.
- Thiết kế và viết khai báo **danh mục các cuốn sách**.
- Thể hiện quan hệ: một đầu sách có thể có nhiều cuốn sách cụ thể.

### Các trường cần làm rõ

- ISBN của đầu sách.
- Tên sách.
- Số trang.
- Tác giả.
- Năm xuất bản.
- Thể loại.
- Mã riêng của từng cuốn sách.
- Vị trí của cuốn sách.
- Trạng thái cuốn sách: cho mượn được, đang được mượn, đã thanh lý.

Theo đề, ba trạng thái cuốn sách lần lượt là 0, 1, 2. Nếu đề chưa ghi sức chứa mảng, con số nhóm chọn phải được ghi là đề xuất, không lấy giới hạn từ đề tài khác. Thống nhất kiểu mã cuốn sách với thành viên 3.

### Gợi ý code cho thành viên 2 — phân biệt mảng và đối tượng

Bắt đầu bằng việc viết riêng bảng trường của **đầu sách** và **cuốn sách**, rồi tự khai báo các kiểu tương ứng. Khi nghĩ đến danh sách đầu sách, phân biệt hai cách viết:

```cpp
// Giả sử đã có kiểu DauSach và hằng nguyên dương MAX_DAU_SACH.
DauSach* ds[MAX_DAU_SACH];  // Mỗi ô chứa một con trỏ tới đầu sách.
```

```cpp
// Chỉ để đối chiếu: đây là mảng chứa trực tiếp các đối tượng.
DauSach ds[MAX_DAU_SACH];
```

**Đề yêu cầu dạng mảng con trỏ ở ví dụ thứ nhất.** Hai đoạn là hai ví dụ riêng, không khai báo đồng thời cùng tên `ds`. Tự xác định nơi quản lý số phần tử đang dùng và sức chứa. Tên `MAX_DAU_SACH` là minh họa, chưa ấn định một giới hạn mới của đề.

Khai báo mảng con trỏ không tạo ra các đối tượng đầu sách. Nếu mảng là biến cục bộ không có khởi tạo, các ô con trỏ chưa có giá trị dùng được; nhóm phải tự chọn và giải thích cách khởi tạo trước khi sử dụng.

Ở danh mục cuốn sách, dùng mẫu con trỏ `KieuNut* lienKet;` để tự khai báo liên kết đến nút kế tiếp. Tự xác định con trỏ trong đầu sách sẽ dẫn đến danh mục như thế nào. Không sao chép tên sách, tác giả và toàn bộ thông tin đầu sách vào mỗi cuốn.

**Phần tự hoàn thiện:** đủ trường của hai loại dữ liệu, nút cuốn sách, mảng con trỏ và cách biểu diễn danh sách rỗng. Chưa viết hàm sinh mã, sắp xếp hoặc thêm/xóa sách. Viết mảng không tự làm các đầu sách tăng theo tên.

### Việc kiểm tra

- Đảm bảo danh sách đầu sách có thể duy trì thứ tự tăng theo tên sách.
- Đảm bảo mỗi cuốn sách có mã riêng.
- Đảm bảo có thể đi từ một đầu sách đến các cuốn sách thuộc đầu sách đó.
- Kiểm tra không trộn thông tin của đầu sách với thông tin riêng của từng cuốn.

### Thành viên 2 phải giải thích được

- Đầu sách khác cuốn sách cụ thể ở điểm nào.
- Vì sao đầu sách dùng mảng con trỏ.
- Vì sao các cuốn sách cụ thể dùng danh sách liên kết đơn.
- Nếu một đầu sách có 5 cuốn thì dữ liệu nào chỉ lưu một lần và dữ liệu nào lưu 5 lần.
- Tìm sách theo tên và tìm cuốn sách theo mã khác nhau như thế nào.
- Mảng con trỏ khác mảng chứa trực tiếp các đối tượng đầu sách thế nào?
- Số đầu sách đang có khác sức chứa mảng thế nào?
- Khai báo mảng có tự làm dữ liệu tăng theo tên không, hay cần thao tác duy trì thứ tự về sau?

### Sản phẩm phải nộp

- Phần khai báo đầu sách, mảng con trỏ quản lý và danh mục sách do thành viên tự viết.
- Bảng giải thích tên trường, kiểu dữ liệu dự kiến, ý nghĩa và lý do cần từng trường.
- Sơ đồ liên kết giữa đầu sách và các cuốn sách.
- Danh sách các trạng thái cuốn sách và ý nghĩa từng trạng thái.

## 5. Phần việc của thành viên 3 — Tấn

### Người phụ trách

Thành viên 3: **Tấn**

### Phần code chính

- Thiết kế và viết **kiểu ngày tháng** dùng cho ngày mượn và ngày trả.
- Khai báo **bản ghi mượn trả**: mã sách, ngày mượn, ngày trả và trạng thái.
- Khai báo **nút liên kết đơn và cách quản lý danh sách mượn trả** của một độc giả.
- Đề xuất cách biểu diễn ngày trả khi chưa trả, ghi rõ đây là quy ước nhóm lựa chọn.
- Chốt với thành viên 1 cách gắn danh sách vào độc giả; chốt với thành viên 2 kiểu mã cuốn sách.

Thành viên 3 phụ trách một cấu trúc dữ liệu chính, không chỉ làm kiểu hỗ trợ. Không tự thêm lớp quản lý tất cả danh sách trùng với phần của hai thành viên còn lại. Chưa cần viết thuật toán tính quá hạn hoặc lưu file trước thứ bảy.

### Gợi ý code cho thành viên 3 — ngày tháng và một lần mượn

Trước tiên tự đề xuất cách biểu diễn một ngày. Nếu nhóm chọn tạo kiểu riêng tên `Ngay`, có thể dùng kiểu đó cho hai trường khác vai trò:

```cpp
// Mẩu khai báo bên trong bản ghi, sau khi kiểu Ngay đã được định nghĩa.
Ngay ngayMuon;
Ngay ngayTra;
```

Đây là hai giá trị ngày thuộc một bản ghi, không phải hai con trỏ. Nhóm tự hoàn thiện kiểu `Ngay` và quy ước ngày trả chưa có; không tự coi ngày toàn số 0 là một ngày hợp lệ hoặc một quy ước thầy đã yêu cầu.

Để nối các lần mượn, cú pháp con trỏ có dạng:

```cpp
KieuNutMuonTra* lienKetTiep;  // Thay bằng tên kiểu nút đã thống nhất.
```

Tự xác định dữ liệu theo đề đặt ở đâu trong nút và danh sách bắt đầu từ đâu. Mỗi lần mượn là một bản ghi; khi một cuốn được mượn lại ở thời điểm khác, không vì trùng mã sách mà mặc định đó là cùng một bản ghi lịch sử.

**Phần tự hoàn thiện:** kiểu ngày, bản ghi, nút và cách quản lý danh sách của một độc giả. Mã sách phải khớp kiểu với thành viên 2; kiểu danh sách/nút phải dùng được ở phần thành viên 1. Không thêm trường số sách đang mượn chỉ để cho đủ việc; chưa cần viết thuật toán ngày tháng hoặc tính quá hạn.

### Các quy tắc cần ghi rõ

- Mỗi độc giả được mượn tối đa 3 cuốn cùng lúc; danh sách lịch sử mượn trả không bị giới hạn ở 3 nút.
- Không cho mượn khi độc giả đang giữ sách quá hạn 7 ngày.
- Thẻ độc giả có trạng thái bị khóa hoặc đang hoạt động.
- Cuốn sách có trạng thái cho mượn được, đã có độc giả mượn hoặc đã thanh lý.
- Lần mượn trả có trạng thái 0 là đang mượn, 1 là đã trả, 2 là làm mất.
- Mã thẻ không trùng mã thẻ cũ; mỗi cuốn sách có mã riêng duy nhất. Mã sách có thể xuất hiện trong nhiều lần mượn ở các thời điểm khác nhau.

### Việc kiểm tra

- Kiểm tra các trạng thái có giá trị hợp lệ.
- Kiểm tra các kiểu dữ liệu có dùng chung được giữa các phần không.
- Kiểm tra file chung có biên dịch được sau khi ghép.
- Ghi ra những thông tin chưa nên quyết định sớm để cả nhóm thảo luận.

### Thành viên 3 phải giải thích được

- Vì sao trạng thái cuốn sách và trạng thái lần mượn là hai thứ khác nhau.
- Vì sao giới hạn mượn 3 cuốn phải được kiểm tra ở nghiệp vụ mượn.
- Dữ liệu ngày tháng cần dùng để kiểm tra quá hạn như thế nào.
- Kiểu dữ liệu hoặc hằng số dùng chung giúp giảm lỗi gì.
- Một nút biểu diễn một cuốn sách hay một lần mượn một cuốn sách?
- Vì sao danh sách lịch sử có thể dài hơn 3 nút?
- Khi chưa trả, chương trình dự kiến nhận biết ngày trả chưa có ra sao?

### Sản phẩm phải nộp

- Phần khai báo ngày tháng, bản ghi và danh sách mượn trả do thành viên tự viết.
- Bảng giải thích từng trường, trạng thái và quy ước ngày trả chưa có.
- Sơ đồ một độc giả có cả lần đã trả và lần đang mượn.
- Danh sách điểm chưa rõ cần hỏi nhóm hoặc thầy; ví dụ ý nghĩa ngày trả khi làm mất sách. Không tự coi giả định là yêu cầu đã được thầy xác nhận.

## 6. Độ khó và cách cân bằng công việc

Ba phần không khó bằng nhau tuyệt đối. Với phân công mới ở mốc khai báo:

- **Thành viên 1:** khó ở tư duy cây, khóa tìm kiếm và liên kết con trỏ.
- **Thành viên 2:** nhiều thành phần hơn, phối hợp mảng con trỏ với danh sách liên kết và phân biệt đầu sách/cuốn sách.
- **Thành viên 3:** khai báo gọn hơn, cần làm rõ lịch sử mượn, trạng thái và ngày tháng.

Sau khi khai báo xong, thành viên 2 đọc và giải thích phần 1, thành viên 3 giải thích phần 2, thành viên 1 giải thích phần 3. Người viết nghe và bổ sung chỗ hiểu sai. Sau đó mỗi người trình bày toàn bộ sơ đồ. Phần chức năng về sau sẽ được chia tiếp theo khối lượng thực tế.

Các cấu trúc chính đã được thầy chỉ định trong đề. Khi trình bày, nói rõ điều đó, rồi phân tích cách sử dụng, ưu/nhược điểm; không mặc định cấu trúc theo đề luôn nhanh nhất.

## 7. Nộp và ghép code

**Nơi mỗi thành viên tải code lên:** [Thư mục Google Drive của nhóm](https://drive.google.com/drive/folders/1RLC-9c10PC0VKdBr4IZSUy7iEqNFaDl1?usp=sharing).

1. Thành, Thái và Tấn tải phần code của mình cùng bảng giải thích/câu hỏi còn vướng lên thư mục Drive ở trên. Đặt tên file có tên người viết và phiên bản để dễ nhận biết, ví dụ `Thanh_khai_bao_v1.cpp`, `Thai_khai_bao_v1.cpp`, `Tan_khai_bao_v1.cpp`; đây chỉ là ví dụ tên file.
2. Cả ba cùng ghép vào một bản chung; Thành điều phối buổi ghép. Khi gửi bản sửa, đánh dấu rõ phiên bản mới; không ghi đè phần của người khác.
3. Cả nhóm xác định lỗi tên kiểu dữ liệu, dấu chấm phẩy, con trỏ, khai báo trùng và thứ tự khai báo; người phụ trách tự sửa phần của mình.
4. Cả ba cùng biên dịch bản chung.
5. Không thêm chức năng mới trước khi khai báo đã thống nhất.
6. Lưu một bản cuối cùng để mang đi trình bày với thầy.

## 8. Tiêu chí hoàn thành trước khi gặp thầy

Đây là checklist mục tiêu, chưa phải kết quả nhóm đã đạt. Chỉ ghi hoàn thành khi đã thực sự làm và kiểm tra.

- File khai báo biên dịch được.
- Bốn cấu trúc đúng với đề.
- Các mối liên kết giữa chúng được giải thích bằng lời và bằng sơ đồ.
- Không có trường bị trùng hoặc không rõ mục đích.
- Cả ba người đều giải thích được toàn bộ bản khai báo.
- Cả ba biết phần mình trực tiếp viết và biết cách phối hợp khi cần sửa.
- Có bảng giải thích trường dữ liệu và danh sách giả định cần hỏi thầy.
- Đã đối chiếu từng trường và từng cấu trúc với đề; mọi phần bổ sung đều có mục đích phục vụ yêu cầu đã có, không có thay đổi nghiệp vụ/cấu trúc chưa được phép.
- Phân biệt rõ biên dịch thành công với thiết kế đúng và với kiểm thử chức năng. Các chức năng chưa viết thì chưa thể ghi đã kiểm thử.
