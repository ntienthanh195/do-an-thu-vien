# Quản lý thư viện — bản viết lại gọn

Bản này viết lại từ `demo/` và `MaNguonUpdate/` với hai ràng buộc của thầy:

1. Chỉ dùng struct và trường dữ liệu có trong đề; thêm gì thì phải giải thích được (hiện chỉ thêm một trường `height`).
2. Giao diện tự viết từ `gotoxy`, `SetColor`, `system("cls")` và `_getch`.

## Cách chạy

- **Dev-C++ 5.11:** mở `ThuVien.dev`, nhấn F11. Project đã bật sẵn `-std=c++11`.
- **Dòng lệnh:** chạy `BienDich.bat` (cần `g++` của MinGW trong PATH).

Chương trình đọc và tự lưu vào `DuLieu/ThuVien.txt`. Muốn về lại dữ liệu ban đầu thì chép đè `DuLieuMau_SaoLuu.txt` lên file đó.

## Cấu trúc dữ liệu

| Đề yêu cầu | Trong code |
|---|---|
| Đầu sách: mảng con trỏ, tăng theo tên | `DanhSachDauSach { DauSach *ds[]; int soLuong; }` |
| Danh mục sách: DSLK đơn | `CuonSach { maSach, trangThai, viTri, next }` |
| Thẻ độc giả: cây nhị phân tìm kiếm | `NutDocGia { thongTin, left, right, height }` |
| Mượn trả: DSLK đơn | `MuonTra { maSach, ngayMuon, ngayTra, trangThai, next }` |

Ngoài bốn cấu trúc trên chỉ có `NgayThang` (kiểu của hai trường NgayMuon, NgayTra). `CayDocGia` là `typedef NutDocGia *`, không phải struct mới.

**Trường thêm duy nhất ngoài đề: `height` trong `NutDocGia`.** Lý do: mã thẻ cấp tăng dần nên BST thường sẽ lệch thành danh sách liên kết, tìm kiếm mất O(n). `height` lưu chiều cao của nút để tính hệ số cân bằng (cao trái − cao phải) trong O(1); khi hệ số vượt ±1 thì xoay trái/xoay phải (AVL). Nhờ đó tìm, thêm, xóa luôn là O(log n). AVL vẫn là cây nhị phân tìm kiếm nên không trái đề.

Đã bỏ so với bản cũ: `ThuVien`, `maTheLonNhatDaCap`, `Phim`, `MauGiaoDien`, `GiaoDien`, `KhoaTepPhien`, `PhienGiaoDien`, `KhungUI`, `SoLieu`, `ConsoleScope`, `LoiThuVien`, và không còn biến toàn cục.

Các thống kê dùng **mảng tạm cấp phát trong hàm rồi giải phóng**, không lưu thành trường:

| Chức năng | Mảng tạm | Thuật toán |
|---|---|---|
| b. In theo tên + họ | mảng con trỏ nút | Quick Sort |
| d. In theo thể loại | mảng con trỏ đầu sách | Insertion Sort (ổn định nên giữ thứ tự tên) |
| i. Quá hạn | hai mảng song song `dg[]`, `luot[]` | Selection Sort giảm dần |
| j. Top 10 | `luotMuon[]`, `thuTu[]` | Selection Sort chạy 10 vòng |

## File và người phụ trách

| File | Nội dung | Phụ trách |
|---|---|---|
| `QuanLyDocGia.cpp` | a. Thêm / xóa / hiệu chỉnh thẻ, cây AVL | Thành |
| `MuonSach.cpp`, `TraSach.cpp`, `LichSuMuonTra.cpp` | f, g và danh sách mượn trả | Thành |
| `NhapSach.cpp`, `CuonSach.cpp` | c. Đầu sách, cuốn sách, mã sách tự động | Thái |
| `TimSach.cpp`, `DocGiaQuaHan.cpp`, `Top10Sach.cpp` | e, i, j | Thái |
| `InDanhSachDocGia.cpp`, `InDauSachTheoTheLoai.cpp`, `SachDangMuon.cpp`, `Menu.cpp` | b, d, h, menu | Tấn |
| `01_HamTienIch.cpp`, `GiaoDien.cpp`, `LuuDocFile.cpp`, `main.cpp` | Phần chung | Cả nhóm |

Hàm có nhãn `[THANH]` / `[THAI]` là hàm nhóm đã viết trong `MaNguonUpdate/`, giữ tên và logic, chỉ đổi tham số vì không còn struct `ThuVien`.

### Code của nhóm được dùng lại

| Nguồn trong `MaNguonUpdate/` | Trong bản này | Mức thay đổi |
|---|---|---|
| `QuanLyDocGia.cpp`: `tim_cay`, `XoayTrai`, `XoayPhai`, `ThemDocGiaAVL`, `CanBangLai`, `TachNutNhoNhat`, `XoaNutAVL`, `HieuChinhDocGia`, `SinhMaTheTiepTheo`, `Huydocgia`, `HuyCayDocGia` | `QuanLyDocGia.cpp` | Giữ nguyên thân hàm; `caydocgia.root` thành `caydocgia`; bỏ `cout` vì giao diện dùng `gotoxy` |
| `them_cay`, `XoaDocGia` | `QuanLyDocGia.cpp` | Trả về `bool` (và chuỗi lỗi) thay cho `cout` |
| `LichSuMuonTra.cpp`: 6 hàm | `LichSuMuonTra.cpp` | Giữ nguyên; `CapNhatLuotTra` thêm tham số trạng thái để dùng cho báo mất |
| `01_HamTienIch.cpp`: chuỗi (Thái), ngày tháng (Thành) | `01_HamTienIch.cpp` | Giữ nguyên logic; `SoSanhChuoi` gọi lại `ChuanHoaChuoi` |
| `NhapSach.cpp`: `HopLeDauSach`, `TimDauSachTheoISBN`, `TimViTriChenTheoTen`, `ThemDauSach` | `NhapSach.cpp` | Giữ logic; tham số `ThuVien` thành `DanhSachDauSach` |
| `GiaoDien.cpp`: `ManHinhNhapDauSach` (kiểm tra từng ô ngay khi nhập) | `ManHinhThemDauSach` trong `NhapSach.cpp` | Giữ thứ tự và điều kiện kiểm tra từng ô; dùng ô nhập chung `NhapChuoi` |
| `CuonSach.cpp`: `TimCuonSachTrongDauSach`, `TimCuonSachToanCuc`, `DemCuonSach` | `CuonSach.cpp` | Giữ logic; tách ISBN thành hàm riêng `TachISBNTuMaSach` |
| `CuonSach.cpp`: `SinhMaSachTuDong`, `HopLeCuonSach` | `CuonSach.cpp` | Viết gọn lại: cộng 1 bằng số nguyên thay cho cộng chuỗi; `HopLeViTri` sửa lỗi điều kiện `&&` |
| `TimSach.cpp`: `ChuaChuoi` | `01_HamTienIch.cpp` | Giữ nguyên |
| `Top10Sach.cpp`: `DemDocGia`, `LayDanhSachDocGia` và hai hàm duyệt | `Top10Sach.cpp` | Giữ nguyên, bỏ `const` ở con trỏ nút |

Phần viết mới hoàn toàn: `GiaoDien.cpp`, `LuuDocFile.cpp`, `Menu.cpp`, `main.cpp`, các màn hình b, d, f, g, h, i và phần xếp hạng của j (trong `MaNguonUpdate/` các file này còn trống).

## Các quy ước cần giải thích được với thầy

- **Mã thẻ tăng dần**: mã mới = mã lớn nhất trong cây (nút ngoài cùng bên phải) + 1, nên không trùng mã nào đang có. Mã của thẻ đã xóa có thể được cấp lại nếu đó là mã lớn nhất; chấp nhận được vì chỉ xóa được thẻ chưa từng mượn sách.
- **Cây AVL**: xem mục "Trường thêm duy nhất ngoài đề" ở trên. Bốn trường hợp xoay: lệch trái–trái xoay phải; lệch phải–phải xoay trái; trái–phải xoay trái con rồi xoay phải; phải–trái xoay phải con rồi xoay trái.
- **Mã sách `ISBN#N`**: tách ISBN từ mã để tìm đúng đầu sách rồi chỉ duyệt danh mục của đầu sách đó. Đây là cách hiểu câu "tìm theo mã sách nhanh nhất".
- **Quá hạn**: giữ mốc `>= 7` của nhóm (mượn ngày 01 thì ngày 08 là quá hạn 1 ngày).
- **Xóa thẻ**: chỉ xóa thẻ chưa có lịch sử mượn; thẻ có lịch sử thì khóa.
- **Báo mất**: lượt mượn = 2, cuốn sách chuyển "đã thanh lý", khóa thẻ.
- **Ghi file**: độc giả ghi theo thứ tự duyệt trước (NLR); khi đọc lại, từng thẻ được thêm bằng `them_cay` nên cây tự cân bằng, không cần lưu `height`.
- **Top 10**: tính theo đầu sách, đếm cả lượt đang mượn, đã trả và làm mất.

Ba mục quá hạn, báo mất và top 10 là giả định của nhóm, nên hỏi lại thầy.

## Đã kiểm tra

- Biên dịch C++11 `-Wall -Wextra -pedantic` không cảnh báo, cho cả Windows (MinGW-w64) và Linux.
- Chạy thử đủ a–j bằng phím giả lập trên Linux, thay 4 lời gọi console bằng lớp giả lập; chạy với AddressSanitizer không có lỗi bộ nhớ hay rò rỉ.
- Cây AVL: chèn 2.000 mã tăng dần cho chiều cao 11; sau 5.000 thao tác thêm/xóa ngẫu nhiên, mọi nút vẫn đúng thứ tự BST, đúng `height` và lệch không quá 1.
- **Chưa chạy trên console Windows thật.** Cần mở bằng Dev-C++ và thao tác thử trên máy trình diễn.
