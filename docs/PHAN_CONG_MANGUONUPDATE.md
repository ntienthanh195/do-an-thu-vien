# Phân công code theo chức năng trong MaNguonUpdate/

> `MaNguon/` vẫn là nơi làm việc hiện tại, giữ nguyên 9 file cũ. `MaNguonUpdate/` nằm bên cạnh để nhóm xem phương án chia chức năng, chưa thay thế MaNguon. Hai file có code trong bản mới là bản sao tại mốc chuẩn bị; không duy trì sửa cả hai nơi.

Phương án tham khảo ngày 01/11/2026: mỗi chức năng a–j có một file riêng, dùng chung cấu trúc và dữ liệu của chương trình. Phân công Thành–Thái–Tấn giữ theo [hồ sơ phân công](PHAN_CONG_DO_AN_THU_VIEN.md). Các file chức năng và hỗ trợ mới chỉ giữ chỗ; việc sắp xếp file không xác nhận đã cài đặt, biên dịch hoặc kiểm thử chức năng.

## Thành — a, f, g

- [QuanLyDocGia.cpp](../MaNguonUpdate/QuanLyDocGia.cpp): **a**, thêm/xóa/hiệu chỉnh thẻ, cấp mã; các thao tác tìm/chèn/xóa BST độc giả dùng chung đặt tại đây.
- [MuonSach.cpp](../MaNguonUpdate/MuonSach.cpp): **f**, điều kiện và nghiệp vụ mượn; phối hợp lịch sử mượn với trạng thái cuốn sách. Dùng lại phần liệt kê sách đang mượn của Tấn.
- [TraSach.cpp](../MaNguonUpdate/TraSach.cpp): **g**, nghiệp vụ trả và cập nhật nhất quán lịch sử cùng cuốn sách. Các giả định chưa chốt với thầy vẫn cần được làm rõ.

Thành tự làm màn hình a, f, g; phụ trách ngày tháng dùng chung, lịch sử mượn–trả và điều phối nạp/lưu/thoát.

## Thái — c, e, i, j

- [NhapSach.cpp](../MaNguonUpdate/NhapSach.cpp): **c**, nhập đầu sách, phối hợp cấp mã/thêm cuốn. Thao tác nền trên mảng con trỏ đầu sách và tra cứu ISBN dùng chung đặt tại đây; giữ thứ tự theo tên.
- [TimSach.cpp](../MaNguonUpdate/TimSach.cpp): **e**, tìm theo tên và hiển thị đủ thông tin đầu sách, mã cuốn, trạng thái theo đề.
- [DocGiaQuaHan.cpp](../MaNguonUpdate/DocGiaQuaHan.cpp): **i**, tự lập và sắp kết quả quá hạn; dùng cách tính ngày chung do Thành phụ trách.
- [Top10Sach.cpp](../MaNguonUpdate/Top10Sach.cpp): **j**, tự tính thống kê từ dữ liệu mượn–trả. Cách đếm theo đầu sách/cuốn và xử lý đồng hạng phải theo quy tắc nhóm đã xác nhận với thầy.

Thái tự làm màn hình c, e, i, j; phụ trách thao tác cuốn sách và đọc/ghi đầu sách, cuốn sách.

## Tấn — b, d, h và menu

- [InDanhSachDocGia.cpp](../MaNguonUpdate/InDanhSachDocGia.cpp): **b**, in theo mã hoặc tên+họ; tự làm phần duyệt, chuẩn bị thứ tự và hiển thị.
- [InDauSachTheoTheLoai.cpp](../MaNguonUpdate/InDauSachTheoTheLoai.cpp): **d**, nhóm thể loại, tên tăng trong mỗi nhóm; giữ nguyên thứ tự lưu bắt buộc của dữ liệu gốc.
- [SachDangMuon.cpp](../MaNguonUpdate/SachDangMuon.cpp): **h**, liệt kê mã/tên sách đang mượn của độc giả; dùng tra cứu độc giả và sách đã thống nhất.
- [Menu.cpp](../MaNguonUpdate/Menu.cpp): menu và điều hướng tới các màn hình; phối hợp Thành khi ghép luồng chạy.

Tấn tự làm màn hình b, d, h; giữ thứ tự triển khai h → b theo mã → b theo tên+họ → d. Các chức năng xem không sửa dữ liệu nghiệp vụ.

## Phần dùng chung

- [00_KhaiBaoChung.h](../MaNguonUpdate/00_KhaiBaoChung.h): bộ struct/hằng chung hiện có, Thành điều phối. Các khai báo hàm được người viết đề xuất và bổ sung sau khi thống nhất cách gọi; không chép struct sang từng file chức năng.
- [01_HamTienIch.cpp](../MaNguonUpdate/01_HamTienIch.cpp): giữ nguyên code tiện ích hiện có. Thành phụ trách ngày tháng và kiểm tra độc giả/lịch sử; Thái phụ trách chuỗi và kiểm tra sách. Mỗi hàm có một người chịu trách nhiệm, trao đổi trước khi cùng sửa.
- [CuonSach.cpp](../MaNguonUpdate/CuonSach.cpp): Thái phụ trách danh sách cuốn, mã cuốn và tra cứu cuốn dùng chung cho c, f, g, h.
- [LichSuMuonTra.cpp](../MaNguonUpdate/LichSuMuonTra.cpp): Thành phụ trách thao tác nền trên danh sách lịch sử; không chứa chức năng h của Tấn. Mượn/trả chịu trách nhiệm phối hợp cập nhật toàn nghiệp vụ.
- [LuuDocFile.cpp](../MaNguonUpdate/LuuDocFile.cpp): Thành đọc/ghi độc giả và lịch sử, điều phối nạp/lưu chung; Thái đọc/ghi đầu sách và cuốn sách. Chốt ranh giới phần việc trước khi cùng sửa. Tấn hỗ trợ mẫu và thử dữ liệu, không bị chuyển sang phụ trách bộ đọc/ghi. Backup tự động vẫn là tùy chọn làm sau.
- [GiaoDien.cpp](../MaNguonUpdate/GiaoDien.cpp): hỗ trợ nhập, phím, bảng, phân trang và thông báo dùng chung. Cả ba chia người phụ trách từng phần; màn hình riêng vẫn thuộc file chức năng tương ứng.
- [main.cpp](../MaNguonUpdate/main.cpp): Thành điều phối điểm chạy duy nhất, tạo dữ liệu chung, nạp dữ liệu, nối menu và lưu/thoát. Hiện là file trống, chưa có hàm main.

Tổng cộng **17 file .cpp và 1 header**: 10 file chức năng a–j, 7 file hỗ trợ/điều phối. Header và file tiện ích là bản sao đối chiếu từ MaNguon tại mốc chuẩn bị, chưa tự đồng bộ khi MaNguon đổi; các file .cpp còn lại đều trống.

## Quy ước kết nối

1. Mỗi file chức năng chứa xử lý và màn hình riêng, nhưng tách trách nhiệm của hàm nhập/hiển thị với hàm xử lý nghiệp vụ.
2. Một hàm dùng chung có một nơi cài đặt. Thống nhất đầu vào, đầu ra, cách báo thất bại và dữ liệu được phép thay đổi trước khi gọi chéo; không sao chép hàm tìm kiếm/ngày tháng sang nhiều file.
3. Toàn chương trình dùng cùng dữ liệu Thư viện và giữ đúng bốn cấu trúc theo đề. Chia file không cấp quyền đổi cấu trúc hoặc mở rộng nghiệp vụ.
4. Khai báo cách gọi qua header; biên dịch và liên kết các file .cpp, không ghép bằng cách include các file .cpp. Nếu bổ sung header cho từng phần sau này, tránh khai báo trùng và thống nhất với nhóm.
5. Mỗi người tự thiết kế, tự viết và tự thử phần mình. File giữ chỗ không phải bộ khung hàm để điền hoặc bằng chứng hoàn thành.

## Đối chiếu file cũ → file mới (chỉ chuyển sau khi nhóm thống nhất)

- `00_KhaiBaoChung.h` → bản sao cùng tên trong `MaNguonUpdate/`; đối chiếu lại bản đang dùng trước khi chuyển.
- `01_HamTienIch.cpp` → bản sao cùng tên trong `MaNguonUpdate/`; không tự đồng bộ các sửa đổi sau mốc chuẩn bị.
- `02_XuLyDauSach.cpp`: phần c/thao tác đầu sách sang `NhapSach.cpp`; e sang `TimSach.cpp`; d sang `InDauSachTheoTheLoai.cpp`.
- `03_XuLyCuonSach.cpp` → `CuonSach.cpp`.
- `04_XuLyDocGia.cpp`: a/thao tác BST sang `QuanLyDocGia.cpp`; b sang `InDanhSachDocGia.cpp`.
- `05_XuLyMuonTra.cpp`: thao tác lịch sử sang `LichSuMuonTra.cpp`; h sang `SachDangMuon.cpp`.
- `06_NghiepVuTongHop.cpp`: f sang `MuonSach.cpp`; g sang `TraSach.cpp`; i sang `DocGiaQuaHan.cpp`; j sang `Top10Sach.cpp`.
- `07_LuuDocFile.cpp` → `LuuDocFile.cpp`.
- `08_ChuongTrinhChinh.cpp`: menu sang `Menu.cpp`, khởi động/nạp/lưu/thoát sang `main.cpp`, hỗ trợ giao diện chung sang `GiaoDien.cpp`.

Hiện tại nhóm tiếp tục làm việc trong `MaNguon/` theo tên file cũ. Không chuyển code đang dở chỉ vì thư mục mới xuất hiện. Khi cả ba thống nhất chuyển, commit công việc đang dở trên nhánh riêng, đối chiếu bản mới nhất trong MaNguon rồi chuyển từng phần và kiểm thử. Không chép đè code của người khác. Chỉ chọn một bộ nguồn để biên dịch; không gom cả MaNguon và MaNguonUpdate vào cùng project.

Repo nhóm chưa có cấu hình build chung ở gốc. Khi tạo project IDE/build, thêm các file .cpp thực sự tham gia chương trình và chỉ một main; bản thử riêng đặt ngoài bản ghép. Cấu hình build của các bản tham khảo trong TaiLieuThamKhao_AI không phải cấu hình của MaNguon nhóm.

Các bản mẫu AI, ZIP, dữ liệu, tài liệu ôn tập và bản khai báo lịch sử trong src được giữ nguyên. Xem thêm [hướng dẫn GitHub Desktop](HUONG_DAN_DAY_CODE_CHO_NHOM.md) và [phân công dữ liệu](PHAN_CONG_DU_LIEU.md).
