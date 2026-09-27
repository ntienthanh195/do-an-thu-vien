# Đọc và sử dụng bộ khung code

Bộ khung được AI soạn theo yêu cầu rõ của Thành ngày 27/09/2026 để ba thành viên hình dung công việc. Đây là giao tiếp hàm đề xuất và hỗ trợ thiết kế, không phải thuật toán nhóm đã tự viết, chức năng hoàn thành hoặc bằng chứng tự chủ.

## 1. Bắt đầu từ đâu?

- **Thành:** `src/DocGia.h/.cpp`, `src/MuonTra.h/.cpp`, hai hàm độc giả/lịch sử trong `src/DuLieu.cpp` và `src/main.cpp`.
- **Thái:** `src/Sach.h/.cpp`, `src/ThongKe.h/.cpp`, `src/GiaoDien.h/.cpp`, hai hàm sách trong `src/DuLieu.cpp`.
- **Tấn:** `src/LietKe.h/.cpp` và `src/Menu.h/.cpp`. Bắt đầu từ `manHinhSachDangMuon`; các hàm tra cứu liên quan cần được cài trước khi chạy trọn chức năng.
- **Chung:** `src/KhaiBao.h` giữ nguyên trường và giá trị từ bản khai báo nhóm 25/09. Bản `CODE-ĐỒ-ÁN-THƯ-VIỆN-DSA.cpp` cũ vẫn giữ nguyên để đối chiếu, không nằm trong lệnh build và không được include cùng header mới.

`DuLieu.cpp` là file hai người cùng phụ trách các hàm khác nhau. Thông báo nhau trước khi sửa; PR giữ đúng phần mình. Nếu file lớn, nhóm có thể thống nhất tách thành hai file sau, cập nhật danh sách build tương ứng.

## 2. Một hàm trong khung có gì?

Mở file `.h` trước để xem tên hàm, tham số và kết quả. Mở `.cpp` để viết phần xử lý bên trong cặp ngoặc nhọn. Comment phía trên nêu yêu cầu, phía trong gợi ý tên/vai trò biến cục bộ; không ép dùng đủ mọi biến nếu cách cài không cần.

- `const string& maSach`: nhận mã cuốn sách, không sửa chuỗi bên gọi.
- `int maThe`: nhận mã thẻ cần xử lý.
- `ThuVien& thuVien`: dùng dữ liệu chung và có thể thay đổi khi hợp đồng hàm cho phép.
- `const ThuVien& thuVien`: chức năng chỉ đọc theo quy ước. Vì struct chứa con trỏ, const ở ngoài không tự bảo vệ toàn bộ dữ liệu bên trong; người viết vẫn phải giữ đúng cam kết không sửa cây, liên kết, trạng thái.
- `int& maTheTiepTheo`: tham chiếu bộ cấp mã dùng chung; không tạo lại thành 1 mỗi lần gọi hàm.
- `string& loi`: nơi trả lý do thất bại.
- `string& maSachDaCap`: nơi xuất mã vừa cấp khi thêm cuốn thành công.

Quy ước cho các hàm nghiệp vụ/đọc ghi trả `bool`: thành công trả true và xóa nội dung lỗi cũ; thất bại trả false, gán lý do vào `loi` và không để dữ liệu bị cập nhật một phần. Chỉ kết quả xuất khi thành công mới có giá trị; không dùng `maSachDaCap` sau lần thất bại.

Hàm tìm trả con trỏ mượn từ dữ liệu chung: nullptr nghĩa là không tìm thấy. Người gọi kiểm tra trước khi truy cập; không delete con trỏ trả về, không giữ nó qua thao tác xóa/thay toàn bộ dữ liệu. Hai bản `timDocGia`/`timCuonSach` là overload: bản dùng dữ liệu const trả con trỏ chỉ đọc.

Các hàm màn hình `void` do người phụ trách tự cài nhập, gọi nghiệp vụ, hiển thị và quay lại. Hàm nghiệp vụ không tự xóa màn hình hoặc chờ phím. Phần chuẩn bị/sắp xếp dữ liệu liệt kê vẫn do Tấn tự viết; có thể thêm hàm phụ để tách việc, không nhất thiết nhét tất cả vào một hàm màn hình.

## 3. Biến bên trong hàm hình dung thế nào?

Tham số đã có tên và kiểu cụ thể trong từng chữ ký. Biến cục bộ để phục vụ cách cài của mỗi người; comment trong từng thân hàm nêu gợi ý, chưa phải danh sách bắt buộc hoặc thuật toán.

Ví dụ trong màn hình h của Tấn:

- `maThe` kiểu `int`: mã người dùng nhập.
- `docGia` kiểu `const DocGia*`: kết quả tra cứu độc giả.
- `p` kiểu `const MuonTra*`: bản ghi lịch sử đang xem.
- `dauSach` kiểu `const DauSach*`: nơi lấy tên sách ứng với mã cuốn.
- `trang` kiểu `int`: trang đang hiển thị nếu màn hình đã có phân trang.

Trong nghiệp vụ mượn của Thành, `docGia` có thể là `DocGia*`, `cuonSach` là `CuonSach*`, `banGhiMoi` là `MuonTra*`; đây là các đối tượng có thể cần thay đổi. Cách kiểm tra, cấp phát và giữ dữ liệu nhất quán do Thành tự viết.

Trong phần thêm đầu sách của Thái, `dauSachMoi` có thể là `DauSach*`, `viTriChen` là `int`. Các biến nhập như tên, tác giả thuộc màn hình; thuật toán duy trì thứ tự mảng do Thái tự cài.

`ketQuaTam` chỉ là tên gợi ý cho liệt kê/thống kê. Khung không thêm vector/map hay cấu trúc lưu nghiệp vụ mới. Người phụ trách đề xuất dữ liệu tạm, giải thích mục đích và đối chiếu giới hạn thầy trước khi dùng.

## 4. Vì sao có (void) và throw?

`(void)maThe;` chỉ đánh dấu tham số chưa dùng để tránh warning trong khung. Nó không thực hiện nghiệp vụ. Khi đã dùng tham số, có thể bỏ dòng đánh dấu tương ứng.

`throw std::logic_error("TODO: ...");` báo hàm chưa được cài. Nếu gọi lúc chưa thay dòng đó, chương trình sẽ báo lỗi (và có thể kết thúc nếu chưa có xử lý exception). Nhờ vậy khung không giả vờ tìm thấy dữ liệu, đọc file thành công hay mượn sách được.

Khi tự cài một hàm, thay phần TODO và dòng throw bằng xử lý thật; giữ cách gọi đã thống nhất hoặc trao đổi trước khi đổi chữ ký. Nhóm không bắt buộc dùng exception cho nghiệp vụ; dòng throw này chỉ là dấu chặn của bộ khung.

## 5. Những quyết định còn mở

- Định dạng file và quy tắc cấp mã cuốn chưa được cài. Không tự tạo dữ liệu mẫu theo một định dạng riêng rồi coi cả nhóm đã đồng ý.
- `maTheTiepTheo` là metadata hỗ trợ cấp mã, truyền riêng để không thay struct theo đề. Giữ giá trị qua lưu/đọc, không chỉ tính lại từ các mã còn trong cây; nhóm cần xử lý giới hạn int và thống nhất quy tắc cấp mã.
- Ngày biên quá hạn, xóa khi còn lịch sử, trường hợp mất sách, mốc xếp hạng độc giả quá hạn và top 10 còn cần làm rõ theo hồ sơ phân công.
- Không có hàm xử lý mất sách riêng trong khung: trạng thái theo đề vẫn giữ đầy đủ, nhưng chưa tự gán quy tắc nghiệp vụ/ngày trả cho tình huống chưa chốt.
- `docSach` và `docDocGiaVaMuonTra` mô tả không thay dữ liệu đang có khi đọc lỗi. Khi nối khởi động/nạp lại, Thành cần kiểm tra cả bộ dữ liệu cùng nhau trước khi dùng; hai lần đọc riêng thành công chưa tự bảo đảm mọi trạng thái sách và lịch sử khớp nhau.
- Giải phóng đúng chủ sở hữu: phần sách giải phóng đầu sách/cuốn; phần độc giả giải phóng cây và lịch sử. Không sao chép nông các struct chứa con trỏ để tạo một bộ dữ liệu sở hữu thứ hai.

## 6. Build bộ khung trên Windows

Cần PowerShell và compiler g++ hỗ trợ C++17. Mở terminal ở thư mục repo, chạy:

```powershell
.\build.ps1
.\build\thu-vien.exe
```

Nếu g++ không có trong PATH, chỉ định đường dẫn thực tế của máy:

```powershell
.\build.ps1 -Compiler 'C:\duong-dan-compiler\g++.exe'
```

Script build liệt kê đúng các `.cpp` tham gia chương trình; nếu nhóm thêm file triển khai mới, cập nhật danh sách đó. Không include file `.cpp` vào file `.cpp` khác; include header tương ứng.

Hiện `main` chỉ khởi tạo dữ liệu rỗng và in `KHUNG THU VIEN - CHUA CAI DAT CHUC NANG`. Chưa gọi menu, đọc file hay nghiệp vụ. Chạy ra dòng này chứng minh bộ khung build/link và khởi động được, không chứng minh a–j, giao diện hoặc file dữ liệu đã hoạt động.

## 7. Khi bắt tay vào làm

Mỗi người chọn một chức năng trong phần mình, thống nhất các hàm phụ thuộc và tự chuẩn bị test. Đọc comment trong header và thân hàm trước khi cài. Những hàm chưa có thì ghi rõ phụ thuộc, không thay bằng kết quả giả trong bản chung.

Đẩy thay đổi lên nhánh nhiệm vụ và gửi PR theo [hướng dẫn đẩy code](HUONG_DAN_DAY_CODE_CHO_NHOM.md). Code khung AI có sẵn là phần hỗ trợ; chỉ ghi nhận phần người viết thực sự tự cài và kiểm thử, không tính toàn bộ file là tự viết độc lập.
