# Quản lý thư viện — bản viết lại gọn

Bản này viết lại từ `demo/` và `MaNguonUpdate/` với hai ràng buộc của thầy:

1. Chỉ dùng struct và trường dữ liệu có trong đề; thêm gì thì phải giải thích được (hiện chỉ thêm một trường `height`).
2. Giao diện tự viết từ `gotoxy`, `SetColor` và `_getch` (xem mục Giao diện).

## Cách chạy

- **Dev-C++ 5.11:** mở `ThuVien.dev`, nhấn F11. Project đã bật sẵn `-std=c++11`.
- **Dòng lệnh:** chạy `BienDich.bat` (cần `g++` của MinGW trong PATH).

Chương trình đọc và tự lưu vào `DuLieu/ThuVien.txt`. Muốn về lại dữ liệu ban đầu thì chép đè `DuLieuMau_SaoLuu.txt` lên file đó.

## Giao diện

Cửa sổ 120 cột × 30 dòng, chia hai vùng như một trang web quản trị, nền xanh đen và màu nhấn xanh bạc hà:

- **Thanh menu bên trái** (24 cột, nền sáng hơn) luôn hiện 12 mục: Tổng quan, mười chức năng a–j, Thoát. ↑/↓ để chọn, Enter để mở, Esc để quay về.
- **Vùng nội dung bên phải** (96 cột): tiêu đề và ngày ở trên, nội dung ở giữa, dòng thông báo và dòng hướng dẫn phím ở dưới.
- **Trang Tổng quan**: lời chào, bốn ô số liệu (đầu sách, cuốn sách, độc giả, đang được mượn) và bảng danh mục đầu sách có dòng xen kẽ màu.
- **Nhãn tiếng Việt có dấu**; dữ liệu nhập (tên sách, họ tên) vẫn không dấu.

Cách làm (xem chú thích đầu `0.2_GiaoDien.cpp`):

- `gotoxy(x, y)` tự viết: in mã ANSI `ESC[dòng;cộtH`.
- `cout` được gom vào vùng đệm (`setvbuf`) và chỉ đẩy ra màn hình trong `DocPhim`, ngay trước khi chờ phím; `VeManHinh` vẽ đè chứ không xóa trắng. Nhờ vậy chuyển màn hình không nhấp nháy.
- Con trỏ console được ẩn, chỉ hiện trong ô nhập (`HienConTro`).
- `SetColor(mauChu, mauNen)` tự viết: tra mã màu trong `BANG_MAU` rồi in mã màu ANSI `ESC[38;2;R;G;Bm`, vì 16 màu có sẵn của console không có các tông này.
- `KhoiTaoManHinh` gọi một lần lúc mở chương trình: `SetConsoleOutputCP(65001)` để in tiếng Việt, `GetConsoleMode`/`SetConsoleMode` để console hiểu mã màu.
- `InDuCot` căn cột theo số ký tự chứ không theo số byte, vì chữ có dấu chiếm 2–3 byte.
- Các hàm in nội dung tự cộng độ rộng thanh menu vào tọa độ x, nên từng màn hình không cần biết thanh menu.

Mã nguồn lưu ở bảng mã UTF-8. Dev-C++ 5.11 có thể hiện sai các chuỗi có dấu trong trình soạn thảo nhưng vẫn biên dịch đúng; nên sửa các chuỗi này bằng VS Code.

Hai bản giao diện trước nằm trong `_BanTruocKhiDoiGiaoDien_20261115` (menu a–j ở giữa màn hình) và `_BanGiaoDien16Mau_20261115` (thanh menu trái, 16 màu, không dấu).

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

File chia thành 3 nhóm. Tên đánh số như mục lục sách: số trước dấu chấm là nhóm, số sau là thứ tự trong nhóm (`1.2` = nhóm 1, file thứ 2) (bảng tra từng chức năng → file → hàm → thuật toán: [`MUC_LUC.md`](MUC_LUC.md)):

- **`0.x_`: phần nền** dùng chung.
- **`1.x_`: mỗi file một cấu trúc dữ liệu**, chứa các thao tác thêm/xóa/tìm trên cấu trúc đó.
- **`a_` … `j_`: mỗi file một câu trong đề**, chứa màn hình và thuật toán riêng của câu đó.

| File | Nội dung | Phụ trách |
|---|---|---|
| `0.0_KhaiBaoChung.h` | Hằng, struct theo đề, khai báo hàm (nhóm theo file) | Cả nhóm |
| `0.1_HamTienIch.cpp` | Chuỗi, số, ngày tháng | Thái (chuỗi), Thành (ngày) |
| `0.2_GiaoDien.cpp` | `gotoxy`, `SetColor`, khung, ô nhập | Cả nhóm |
| `0.3_Menu_TongQuan.cpp` | Thanh menu, trang Tổng quan | Tấn |
| `0.4_LuuDocFile.cpp` | Đọc / ghi `DuLieu/ThuVien.txt` | Cả nhóm |
| `1.1_DocGia_CayAVL.cpp` | Cây độc giả: tìm, thêm, xóa, xoay AVL, cấp mã thẻ, duyệt LNR ra mảng | Thành (duyệt cây: Thái) |
| `1.2_DauSach_MangConTro.cpp` | Mảng con trỏ đầu sách: tìm ISBN, tìm nhị phân vị trí chèn, thêm | Thái |
| `1.3_DanhMucSach_DSLKDon.cpp` | DSLK cuốn sách, mã sách tự động `ISBN#N` | Thái |
| `1.4_MuonTra_DSLKDon.cpp` | DSLK mượn trả, đếm đang mượn, quá hạn | Thành |
| `a_QuanLyDocGia.cpp` | a. Màn hình thêm / xóa / hiệu chỉnh thẻ | Thành |
| `b_InDanhSachDocGia.cpp` | b. In độc giả (Quick Sort theo tên + họ) | Tấn |
| `c_NhapSach.cpp` | c. Màn hình nhập đầu sách, thêm cuốn, thanh lý | Thái |
| `d_InDauSachTheoTheLoai.cpp` | d. In theo thể loại (Insertion Sort) | Tấn |
| `e_TimSach.cpp` | e. Tìm sách theo tên | Thái |
| `f_MuonSach.cpp` | f. Mượn sách | Thành |
| `g_TraSach.cpp` | g. Trả sách, báo mất | Thành |
| `h_SachDangMuon.cpp` | h. Sách đang mượn của một độc giả | Tấn |
| `i_DocGiaQuaHan.cpp` | i. Độc giả quá hạn (Selection Sort) | Thái |
| `j_Top10Sach.cpp` | j. Top 10 sách (Selection Sort 10 vòng) | Thái |
| `main.cpp` | Mở file, gọi menu, lưu và giải phóng | Cả nhóm |

Hàm có nhãn `[THANH]` / `[THAI]` là hàm nhóm đã viết trong `MaNguonUpdate/`, giữ tên và logic, chỉ đổi tham số vì không còn struct `ThuVien`.

### Code của nhóm được dùng lại

| Nguồn trong `MaNguonUpdate/` | Trong bản này | Mức thay đổi |
|---|---|---|
| `QuanLyDocGia.cpp`: `tim_cay`, `XoayTrai`, `XoayPhai`, `ThemDocGiaAVL`, `CanBangLai`, `TachNutNhoNhat`, `XoaNutAVL`, `HieuChinhDocGia`, `SinhMaTheTiepTheo`, `Huydocgia`, `HuyCayDocGia` | `1.1_DocGia_CayAVL.cpp` | Giữ nguyên thân hàm; `caydocgia.root` thành `caydocgia`; bỏ `cout` vì giao diện dùng `gotoxy` |
| `them_cay`, `XoaDocGia` | `1.1_DocGia_CayAVL.cpp` | Trả về `bool` (và chuỗi lỗi) thay cho `cout` |
| `LichSuMuonTra.cpp`: 6 hàm | `1.4_MuonTra_DSLKDon.cpp` | Giữ nguyên; `CapNhatLuotTra` thêm tham số trạng thái để dùng cho báo mất |
| `0.1_HamTienIch.cpp`: chuỗi (Thái), ngày tháng (Thành) | `0.1_HamTienIch.cpp` | Giữ nguyên logic; `SoSanhChuoi` gọi lại `ChuanHoaChuoi` |
| `NhapSach.cpp`: `HopLeDauSach`, `TimDauSachTheoISBN`, `TimViTriChenTheoTen`, `ThemDauSach` | `1.2_DauSach_MangConTro.cpp` | Giữ logic; tham số `ThuVien` thành `DanhSachDauSach` |
| `GiaoDien.cpp`: `ManHinhNhapDauSach` (kiểm tra từng ô ngay khi nhập) | `ManHinhThemDauSach` trong `c_NhapSach.cpp` | Giữ thứ tự và điều kiện kiểm tra từng ô; dùng ô nhập chung `NhapChuoi` |
| `CuonSach.cpp`: `TimCuonSachTrongDauSach`, `TimCuonSachToanCuc`, `DemCuonSach` | `1.3_DanhMucSach_DSLKDon.cpp` | Giữ logic; tách ISBN thành hàm riêng `TachISBNTuMaSach` |
| `CuonSach.cpp`: `SinhMaSachTuDong`, `HopLeCuonSach` | `1.3_DanhMucSach_DSLKDon.cpp` | Viết gọn lại: cộng 1 bằng số nguyên thay cho cộng chuỗi; `HopLeViTri` sửa lỗi điều kiện `&&` |
| `TimSach.cpp`: `ChuaChuoi` | `0.1_HamTienIch.cpp` | Giữ nguyên |
| `Top10Sach.cpp`: `DemDocGia`, `LayDanhSachDocGia` và hai hàm duyệt | `1.1_DocGia_CayAVL.cpp` | Giữ nguyên, bỏ `const` ở con trỏ nút |

Phần viết mới hoàn toàn: `0.2_GiaoDien.cpp`, `0.4_LuuDocFile.cpp`, `0.3_Menu_TongQuan.cpp`, `main.cpp`, các màn hình b, d, f, g, h, i và phần xếp hạng của j (trong `MaNguonUpdate/` các file này còn trống).

## Các quy ước cần giải thích được với thầy

- **Mã thẻ tăng dần**: mã mới = mã lớn nhất trong cây (nút ngoài cùng bên phải) + 1, nên không trùng mã nào đang có. Mã của thẻ đã xóa có thể được cấp lại nếu đó là mã lớn nhất; chấp nhận được vì chỉ xóa được thẻ chưa từng mượn sách.
- **Cây AVL**: xem mục "Trường thêm duy nhất ngoài đề" ở trên. Bốn trường hợp xoay: lệch trái–trái xoay phải; lệch phải–phải xoay trái; trái–phải xoay trái con rồi xoay phải; phải–trái xoay phải con rồi xoay trái.
- **Mã sách `ISBN#N`**: tách ISBN từ mã để tìm đúng đầu sách rồi chỉ duyệt danh mục của đầu sách đó. Đây là cách hiểu câu "tìm theo mã sách nhanh nhất".
- **Quá hạn**: giữ mốc `>= 7` của nhóm (mượn ngày 01 thì ngày 08 là quá hạn 1 ngày).
- **Xóa thẻ**: chỉ xóa thẻ chưa có lịch sử mượn; thẻ có lịch sử thì khóa.
- **Báo mất**: lượt mượn = 2, cuốn sách chuyển "đã thanh lý", khóa thẻ.
- **Ghi file**: độc giả ghi theo thứ tự duyệt trước (NLR); khi đọc lại, từng thẻ được thêm bằng `them_cay` nên cây tự cân bằng, không cần lưu `height`.
- **Top 10**: tính theo đầu sách, đếm cả lượt đang mượn, đã trả và làm mất.

- **Ngày mượn, ngày trả**: không nhận ngày sau ngày của máy; kiểm tra quá hạn khi mượn tính đến ngày của máy, không tính đến ngày mượn vừa nhập (sửa 15/11).
- **File hỏng**: chương trình báo lỗi rồi thoát, không lưu đè. Mỗi lần mở và đọc file thành công sẽ ghi bản sao `DuLieu/ThuVien_BanTruoc.txt`; file chính hỏng thì chép bản sao này đè lên (sửa 15/11).
- **Năm xuất bản**: "không vượt quá năm hiện tại" chỉ kiểm ở màn hình nhập, không kiểm khi đọc file (sửa 15/11).

Ba mục quá hạn, báo mất và top 10 là giả định của nhóm, nên hỏi lại thầy.

## Đã kiểm tra

- Biên dịch C++11 `-Wall -Wextra -pedantic` không cảnh báo, cho cả Windows (MinGW-w64) và Linux.
- Chạy thử đủ a–j bằng phím giả lập trên Linux, thay 4 lời gọi console bằng lớp giả lập; chạy với AddressSanitizer không có lỗi bộ nhớ hay rò rỉ.
- Cây AVL: chèn 2.000 mã tăng dần cho chiều cao 11; sau 5.000 thao tác thêm/xóa ngẫu nhiên, mọi nút vẫn đúng thứ tự BST, đúng `height` và lệch không quá 1.
- **Chưa chạy trên console Windows thật.** Cần mở bằng Dev-C++ và thao tác thử trên máy trình diễn.
