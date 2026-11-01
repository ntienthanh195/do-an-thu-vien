# MaNguonUpdate — phương án chia file để nhóm xem trước

**MaNguon vẫn giữ nguyên 9 file cũ và là nơi làm việc hiện tại.** Thư mục này đặt bên cạnh để đối chiếu, chưa thay thế bộ cũ. Chỉ chuyển sau khi cả nhóm thống nhất; không biên dịch gộp hai thư mục. Bộ này đã nhận phần code sách Thái đẩy ở commit `5c03ecf`, theo yêu cầu chuyển code của Thành. Không tự đồng bộ với MaNguon hoặc thư mục gốc của Thái.

- **Thành:** [a — Quản lý độc giả](QuanLyDocGia.cpp), [f — Mượn sách](MuonSach.cpp), [g — Trả sách](TraSach.cpp).
- **Thái:** [c — Nhập sách](NhapSach.cpp), [e — Tìm sách](TimSach.cpp), [i — Độc giả quá hạn](DocGiaQuaHan.cpp), [j — Top 10](Top10Sach.cpp).
- **Tấn:** [b — In độc giả](InDanhSachDocGia.cpp), [d — In đầu sách theo thể loại](InDauSachTheoTheLoai.cpp), [h — Sách đang mượn](SachDangMuon.cpp), [Menu](Menu.cpp).

[Phân công đầy đủ, phần dùng chung và cách chuyển từ tên file cũ](../docs/PHAN_CONG_MANGUONUPDATE.md) · [Hướng dẫn commit/push/PR](../docs/HUONG_DAN_DAY_CODE_CHO_NHOM.md).

Header, tiện ích, `NhapSach.cpp` và `CuonSach.cpp` đã có nội dung; 14 file .cpp còn lại vẫn trống. Chưa có chương trình hoàn chỉnh để chạy. Không sao chép các hàm dùng chung sang nhiều file; giữ một bộ struct và dữ liệu thống nhất. Màn hình riêng thuộc file chức năng tương ứng, hỗ trợ giao diện chung thuộc GiaoDien.cpp.


## Phần code Thái đã chuyển sang

Nguồn đối chiếu: commit `5c03ecf4137faf10ac8b17a0710b5fbda34ca542`, hai file `QuaTrinhTaoMotChucNang.cpp` và `01_HamTienIch.cpp` trong `TaiLieuThamKhao_AI/DEMO_DE_DOC_CPP11/MaNguon/`. Chỉ trích các hàm dưới đây và phụ thuộc cần thiết; không sao chép cả chương trình tham khảo.

- `NhapSach.cpp`: `HopLeTenSach`, `HopLeDauSach`, `TimDauSachTheoISBN`, `TimViTriChenTheoTen`, `ThemDauSach`.
- `CuonSach.cpp`: `HopLeCuonSach`.
- `01_HamTienIch.cpp`: giữ các hàm nhóm đã có, bổ sung `ChuanHoaChuoiSach`, `SoSanhChuoi`, `HopLeVanBan`, `ChuanHoaISBN`.
- `00_KhaiBaoChung.h`: giữ struct/hằng của nhóm, thêm khai báo hàm để các .cpp liên kết với nhau.

`ChuanHoaChuoiSach` là tên mới của hàm chuẩn hóa trong bản Thái: gộp khoảng trắng, giữ hoa/thường. `ChuanHoaChuoi` cũ của nhóm vẫn giữ cách cắt đầu/cuối và đổi sang chữ thường, để các lời gọi đã có không đổi hành vi. Các hàm chuyển từ bản Thái dùng tên mới; riêng `LaChuoiRong` dùng lại bản nhóm hiện có.

Đây là chuyển vị trí và nối khai báo, chưa sửa nghiệp vụ hoặc xác nhận hoàn thành chức năng c. `HopLeCuonSach` còn có các điều kiện kiểm tra mã/vị trí cần Thái sửa và thử lại; không coi việc biên dịch được là dữ liệu đầu vào đã được kiểm tra đúng. Các quy ước ISBN-13, mã cuốn và vị trí đang có trong bản Thái được giữ lại để nhóm đối chiếu với đề/thầy.

## Kiểm tra sau khi chuyển

Ngày 01/11/2026: đã biên dịch và liên kết riêng ba file tiện ích/đầu sách/cuốn sách với bộ chạy thử tạm ngoài mã sản phẩm bằng GCC C++11 (`-Wall -Wextra -pedantic`). Các ca đã chạy đạt: giữ hành vi hai hàm chuẩn hóa, thêm vào danh sách rỗng, chèn giữ thứ tự tên, chặn ISBN trùng, tìm thấy/không thấy ISBN, từ chối số trang không hợp lệ, cuốn hợp lệ và trạng thái không hợp lệ. Đây là kiểm tra tích hợp phần chuyển, chưa phải kiểm thử toàn chương trình hoặc đủ nghiệp vụ.

Đã tái hiện lỗi có sẵn: mã `9781234567890#x` và vị trí `1-xx-yy` vẫn được `HopLeCuonSach` chấp nhận. Giữ nguyên để Thái kiểm tra/sửa riêng; không coi các ca này là đạt yêu cầu. Compiler còn báo hai cảnh báo so sánh int với size_type ở các vòng lặp trong hàm này.
