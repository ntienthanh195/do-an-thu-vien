# Mục lục code — tra nhanh khi vấn đáp

## Cách tìm trong 10 giây

1. Thầy hỏi câu nào (a–j) thì mở file có chữ cái đó: `e_TimSach.cpp` là câu e.
2. Muốn nhảy thẳng tới đoạn thuật toán thì dùng **tìm trong toàn project**: VS Code `Ctrl+Shift+F`, Dev-C++ menu **Search → Find in Files**. Gõ:
   - `@TT [e` → mọi đoạn thuật toán câu e dùng (kể cả nằm ở file khác)
   - `@TT` → toàn bộ thuật toán của đồ án
3. Gặp lời gọi hàm muốn xem thân hàm: VS Code bấm `F12` (hoặc Ctrl + click), hoặc tra bảng dưới đây.

Quy ước tên file: **mỗi câu trong đề một file** (`a_` … `j_`), cộng 5 file nền `0x_` (tiện ích, giao diện, menu, lưu file) mà thầy ít hỏi.

Trong mỗi file câu, phần thuật toán và cấu trúc dữ liệu nằm dưới dòng `XU LY`, phần vẽ màn hình nằm dưới dòng `GIAO DIEN`. Các câu e, h, i, j chỉ có một hàm màn hình, nên bước thuật toán được gắn tag ngay trong hàm.

Hàm dùng chung đặt ở câu mà đề giới thiệu cấu trúc đó trước:

- **Cây độc giả AVL** (`tim_cay`, thêm, xóa, xoay): câu **a**
- **Duyệt cây ra mảng tạm** (`DemDocGia`, `LayDanhSachDocGia`): câu **b**
- **Mảng đầu sách, danh mục sách, mã `ISBN#N`, tìm cuốn theo mã**: câu **c**
- **Danh sách mượn trả** (thêm lượt, đếm đang mượn, quá hạn): câu **f**

Đầu mỗi file có mục `LAY HAM CUA CAU KHAC` và `CAU KHAC GOI HAM O DAY` để biết ngay hàm nằm ở đâu.

## Bảng tổng

| Câu | Chức năng | Mở file | Hàm chính | Cấu trúc dữ liệu | Thuật toán |
|---|---|---|---|---|---|
| a | Thêm / xóa / hiệu chỉnh thẻ | `a_QuanLyDocGia.cpp` | `them_cay` → `ThemDocGiaAVL`, `XoaDocGia` → `XoaNutAVL`, `HieuChinhDocGia`, `MaTheLonNhat` | Cây nhị phân tìm kiếm, cân bằng AVL | Chèn / xóa như BST, quay lui cập nhật `height`, xoay LL/LR/RR/RL — O(log n). Mã thẻ = mã lớn nhất + 1 |
| b | In danh sách độc giả | `b_InDanhSachDocGia.cpp` | `SapXepTheoTenHo`, `LayDanhSachDocGia` | Mảng con trỏ tạm lấy từ cây | Theo tên + họ: Quick Sort. Theo mã thẻ: duyệt LNR là có sẵn thứ tự |
| c | Nhập đầu sách, mã sách tự động | `c_NhapSach.cpp` | `ThemDauSach`, `TimViTriChenTheoTen`, `SinhMaSachTuDong` | Mảng con trỏ (tăng theo tên) + DSLK đơn danh mục sách | Tìm nhị phân vị trí chèn, dời con trỏ sang phải. Mã sách `ISBN#N` |
| d | In đầu sách theo thể loại | `d_InDauSachTheoTheLoai.cpp` | `SapXepTheoTheLoai` | Mảng con trỏ tạm | Insertion Sort (ổn định nên cùng thể loại vẫn tăng theo tên) |
| e | Tìm sách theo tên | `e_TimSach.cpp` (`ChuaChuoi` ở `01_`) | `ManHinhTimSach`, `ChuaChuoi` | Mảng con trỏ đầu sách | Duyệt tuyến tính, tên chứa từ khóa (không phân biệt hoa/thường) |
| f | Mượn sách | `f_MuonSach.cpp` (`TimCuonSachToanCuc` ở `c_`) | `MuonSach`, `them_lich_su`, `Dem_so_sach_dang_muon`, `CoSachQuaHan7Ngay`, `TimCuonSachToanCuc` | DSLK đơn mượn trả của từng độc giả | Kiểm tra điều kiện rồi thêm cuối DSLK |
| g | Trả sách, báo mất | `g_TraSach.cpp` | `TraSach`, `TimMuonDangMuonTheoMa`, `CapNhatLuotTra` | DSLK mượn trả | Duyệt tuyến tính tìm lượt đang mượn, đổi trạng thái (không xóa nút) |
| h | Sách đang mượn | `h_SachDangMuon.cpp` (`InSachDangMuon` ở `f_`) | `ManHinhSachDangMuon`, `InSachDangMuon` | DSLK mượn trả | Duyệt DSLK, lọc trạng thái 0 |
| i | Độc giả quá hạn | `i_DocGiaQuaHan.cpp` | `ManHinhDocGiaQuaHan` | Mảng tạm + 2 mảng song song `dg[]`, `luot[]` | Selection Sort giảm dần theo số ngày quá hạn |
| j | Top 10 sách | `j_Top10Sach.cpp` | `ManHinhTop10Sach` | Mảng đếm `luotMuon[]`, `thuTu[]` | Đếm lượt rồi Selection Sort chạy 10 vòng |

## Chi tiết từng câu (sinh từ các tag `@TT` trong code)

Số dòng tính theo bản ngày 17/11/2026. Sửa code thì số dòng có thể lệch, nhưng tìm theo tag `@TT` vẫn đúng.

### a. Quản lý thẻ độc giả (thêm / xóa / hiệu chỉnh)

Mở file: `a_QuanLyDocGia.cpp`

- `a_QuanLyDocGia.cpp` dòng 27 — `tim_cay`  
  Tim doc gia theo ma the: tim kiem tren cay nhi phan tim kiem bang vong lap - O(log n) vi cay AVL can bang
- `a_QuanLyDocGia.cpp` dòng 47 — `XoayTrai`  
  Xoay trai: con phai len lam goc, cap nhat height goc cu roi goc moi - O(1)
- `a_QuanLyDocGia.cpp` dòng 102 — `XoayPhai`  
  Xoay phai: con trai len lam goc, cap nhat height goc cu roi goc moi - O(1)
- `a_QuanLyDocGia.cpp` dòng 158 — `ThemDocGiaAVL`  
  Them doc gia: chen de quy nhu BST, tren duong quay lui cap nhat height, he so can bang > 1 / < -1 thi xoay (LL, LR, RR, RL) - O(log n)
- `a_QuanLyDocGia.cpp` dòng 257 — `CanBangLai`  
  Can bang lai mot nut sau khi xoa: tinh he so can bang, chon xoay don hay xoay kep theo chieu cao hai cay con cua nut con
- `a_QuanLyDocGia.cpp` dòng 318 — `TachNutNhoNhat`  
  Tach nut nho nhat (trai cung) cua cay con phai, dung khi xoa nut co 2 con
- `a_QuanLyDocGia.cpp` dòng 342 — `XoaNutAVL`  
  Xoa doc gia: xoa nut BST 3 truong hop (la / 1 con / 2 con -> thay bang nut nho nhat cua cay con phai), can bang lai tren duong quay lui - O(log n)
- `a_QuanLyDocGia.cpp` dòng 400 — `XoaDocGia`  
  Dieu kien xoa the: chi xoa the chua co lich su muon tra
- `a_QuanLyDocGia.cpp` dòng 436 — `MaTheLonNhat`  
  Cap ma the moi = ma lon nhat + 1; ma lon nhat la nut phai cung cua cay - O(log n)

### b. In danh sách độc giả

Mở file: `b_InDanhSachDocGia.cpp`

- `b_InDanhSachDocGia.cpp` dòng 21 — `DuyetGiuaDem`  
  Dem so doc gia: duyet giua LNR - O(n)
- `b_InDanhSachDocGia.cpp` dòng 32 — `DuyetGiuaThuThap`  
  Do con tro cac nut ra mang tam: duyet giua LNR nen mang tang dan theo ma the - O(n)
- `b_InDanhSachDocGia.cpp` dòng 73 — `SapXepTheoTenHo`  
  In theo ten + ho: Quick Sort tren mang con tro (chot la phan tu giua) - O(n log n) trung binh
- `b_InDanhSachDocGia.cpp` dòng 111  
  Lay doc gia ra mang tam bang duyet LNR (da tang theo ma the), cay khong bi doi
- `01_HamTienIch.cpp` dòng 75 — `SoSanhChuoi`  
  So sanh 2 chuoi khong phan biet hoa/thuong, dung cho sap xep va tim nhi phan theo ten

### c. Nhập đầu sách, đánh mã sách tự động

Mở file: `c_NhapSach.cpp`

- `c_NhapSach.cpp` dòng 75 — `TimViTriDauSachTheoISBN`  
  Tim dau sach theo ISBN: tim tuyen tinh vi mang sap theo ten, khong theo ISBN - O(n)
- `c_NhapSach.cpp` dòng 96 — `TimViTriChenTheoTen`  
  Tim vi tri chen theo ten sach: tim kiem nhi phan (vi tri dau tien >= ten moi) - O(log n)
- `c_NhapSach.cpp` dòng 113 — `ThemDauSach`  
  Them dau sach giu mang tang theo ten: tim vi tri bang nhi phan, doi con tro sang phai 1 o - O(n)
- `c_NhapSach.cpp` dòng 217 — `SinhMaSachTuDong`  
  Danh ma sach tu dong ISBN#N: N = so thu tu cuon cuoi danh muc + 1
- `c_NhapSach.cpp` dòng 242 — `ThemCuonSachCoMa`  
  Them cuon vao cuoi DSLK don danh muc sach
- `01_HamTienIch.cpp` dòng 75 — `SoSanhChuoi`  
  So sanh 2 chuoi khong phan biet hoa/thuong, dung cho sap xep va tim nhi phan theo ten

### d. In đầu sách theo thể loại

Mở file: `d_InDauSachTheoTheLoai.cpp`

- `d_InDauSachTheoTheLoai.cpp` dòng 18 — `SapXepTheoTheLoai`  
  Sap mang tam theo the loai: Insertion Sort (on dinh nen cung the loai van tang theo ten) - O(n^2)
- `01_HamTienIch.cpp` dòng 75 — `SoSanhChuoi`  
  So sanh 2 chuoi khong phan biet hoa/thuong, dung cho sap xep va tim nhi phan theo ten

### e. Tìm sách theo tên

Mở file: `e_TimSach.cpp`

- `e_TimSach.cpp` dòng 78  
  Tim sach theo ten: duyet tuyen tinh ca mang dau sach, ten nao chua tu khoa (ChuaChuoi, khong phan biet hoa/thuong) thi luu chi so vao mang tam viTri[] - O(n*m)
- `c_NhapSach.cpp` dòng 75 — `TimViTriDauSachTheoISBN`  
  Tim dau sach theo ISBN: tim tuyen tinh vi mang sap theo ten, khong theo ISBN - O(n)
- `01_HamTienIch.cpp` dòng 91 — `ChuaChuoi`  
  Tim chuoi con khong phan biet hoa/thuong: thu tung vi tri bat dau, so tung ky tu - O(n*m)

### f. Mượn sách

Mở file: `f_MuonSach.cpp`

- `f_MuonSach.cpp` dòng 26 — `them_lich_su`  
  Them luot muon vao cuoi DSLK don muon tra
- `f_MuonSach.cpp` dòng 45 — `Dem_so_sach_dang_muon`  
  Dem so sach dang muon (de chan muon qua 3 cuon): duyet DSLK, dem trang thai 0
- `f_MuonSach.cpp` dòng 61 — `CoSachQuaHan7Ngay`  
  Kiem tra doc gia dang giu sach qua han: khoang cach ngay >= 7
- `f_MuonSach.cpp` dòng 80 — `SoNgayQuaHan`  
  So ngay qua han = khoang cach ngay - 7 + 1 (0 neu chua qua han)
- `f_MuonSach.cpp` dòng 106 — `MuonSach`  
  Muon sach: kiem tra lan luot ngay muon, the khoa, du 3 cuon, dang giu sach qua han, ma sach co ton tai, cuon dang muon/thanh ly; dat thi them cuoi DSLK muon tra
- `f_MuonSach.cpp` dòng 168 — `InSachDangMuon`  
  Liet ke sach dang muon: duyet DSLK muon tra, chi lay luot co trang thai 0 (dang muon)
- `a_QuanLyDocGia.cpp` dòng 27 — `tim_cay`  
  Tim doc gia theo ma the: tim kiem tren cay nhi phan tim kiem bang vong lap - O(log n) vi cay AVL can bang
- `c_NhapSach.cpp` dòng 75 — `TimViTriDauSachTheoISBN`  
  Tim dau sach theo ISBN: tim tuyen tinh vi mang sap theo ten, khong theo ISBN - O(n)
- `c_NhapSach.cpp` dòng 206 — `TimCuonSachToanCuc`  
  Tim cuon theo ma sach: tach ISBN truoc dau #, tim dau sach, roi chi duyet DSLK danh muc cua dau sach do (khong duyet danh muc cua moi dau sach)
- `01_HamTienIch.cpp` dòng 258 — `KhoangCachNgay`  
  Khoang cach 2 ngay = Doirangay(ngay 2) - Doirangay(ngay 1)

### g. Trả sách

Mở file: `g_TraSach.cpp`

- `g_TraSach.cpp` dòng 19 — `TimMuonDangMuonTheoMa`  
  Tim luot dang muon cua mot ma sach: duyet tuyen tinh DSLK muon tra
- `g_TraSach.cpp` dòng 34 — `CapNhatLuotTra`  
  Tra sach: khong xoa nut, chi doi trang thai + ghi ngay tra (giu lich su cho top 10)
- `g_TraSach.cpp` dòng 51 — `TraSach`  
  Tra sach / bao mat: tim luot dang muon, kiem tra ngay tra, doi trang thai luot + cuon; bao mat thi cuon -> thanh ly va khoa the
- `a_QuanLyDocGia.cpp` dòng 27 — `tim_cay`  
  Tim doc gia theo ma the: tim kiem tren cay nhi phan tim kiem bang vong lap - O(log n) vi cay AVL can bang
- `c_NhapSach.cpp` dòng 75 — `TimViTriDauSachTheoISBN`  
  Tim dau sach theo ISBN: tim tuyen tinh vi mang sap theo ten, khong theo ISBN - O(n)
- `c_NhapSach.cpp` dòng 206 — `TimCuonSachToanCuc`  
  Tim cuon theo ma sach: tach ISBN truoc dau #, tim dau sach, roi chi duyet DSLK danh muc cua dau sach do (khong duyet danh muc cua moi dau sach)
- `f_MuonSach.cpp` dòng 80 — `SoNgayQuaHan`  
  So ngay qua han = khoang cach ngay - 7 + 1 (0 neu chua qua han)
- `f_MuonSach.cpp` dòng 168 — `InSachDangMuon`  
  Liet ke sach dang muon: duyet DSLK muon tra, chi lay luot co trang thai 0 (dang muon)
- `01_HamTienIch.cpp` dòng 258 — `KhoangCachNgay`  
  Khoang cach 2 ngay = Doirangay(ngay 2) - Doirangay(ngay 1)

### h. Sách một độc giả đang mượn

Mở file: `h_SachDangMuon.cpp`

- `h_SachDangMuon.cpp` dòng 14 — `ManHinhSachDangMuon`  
  Tim doc gia bang tim_cay (a_QuanLyDocGia.cpp), liet ke bang InSachDangMuon (f_MuonSach.cpp)
- `a_QuanLyDocGia.cpp` dòng 27 — `tim_cay`  
  Tim doc gia theo ma the: tim kiem tren cay nhi phan tim kiem bang vong lap - O(log n) vi cay AVL can bang
- `c_NhapSach.cpp` dòng 75 — `TimViTriDauSachTheoISBN`  
  Tim dau sach theo ISBN: tim tuyen tinh vi mang sap theo ten, khong theo ISBN - O(n)
- `c_NhapSach.cpp` dòng 206 — `TimCuonSachToanCuc`  
  Tim cuon theo ma sach: tach ISBN truoc dau #, tim dau sach, roi chi duyet DSLK danh muc cua dau sach do (khong duyet danh muc cua moi dau sach)
- `f_MuonSach.cpp` dòng 80 — `SoNgayQuaHan`  
  So ngay qua han = khoang cach ngay - 7 + 1 (0 neu chua qua han)
- `f_MuonSach.cpp` dòng 168 — `InSachDangMuon`  
  Liet ke sach dang muon: duyet DSLK muon tra, chi lay luot co trang thai 0 (dang muon)
- `01_HamTienIch.cpp` dòng 258 — `KhoangCachNgay`  
  Khoang cach 2 ngay = Doirangay(ngay 2) - Doirangay(ngay 1)

### i. Độc giả mượn quá hạn

Mở file: `i_DocGiaQuaHan.cpp`

- `i_DocGiaQuaHan.cpp` dòng 24  
  Buoc 1: duyet LNR do con tro doc gia ra mang tam
- `i_DocGiaQuaHan.cpp` dòng 41  
  Buoc 2: loc luot dang muon da qua han vao 2 mang song song dg[], luot[]
- `i_DocGiaQuaHan.cpp` dòng 59  
  Buoc 3: Selection Sort giam dan theo so ngay qua han - O(k^2), k = so luot qua han
- `b_InDanhSachDocGia.cpp` dòng 21 — `DuyetGiuaDem`  
  Dem so doc gia: duyet giua LNR - O(n)
- `b_InDanhSachDocGia.cpp` dòng 32 — `DuyetGiuaThuThap`  
  Do con tro cac nut ra mang tam: duyet giua LNR nen mang tang dan theo ma the - O(n)
- `c_NhapSach.cpp` dòng 75 — `TimViTriDauSachTheoISBN`  
  Tim dau sach theo ISBN: tim tuyen tinh vi mang sap theo ten, khong theo ISBN - O(n)
- `c_NhapSach.cpp` dòng 206 — `TimCuonSachToanCuc`  
  Tim cuon theo ma sach: tach ISBN truoc dau #, tim dau sach, roi chi duyet DSLK danh muc cua dau sach do (khong duyet danh muc cua moi dau sach)
- `f_MuonSach.cpp` dòng 80 — `SoNgayQuaHan`  
  So ngay qua han = khoang cach ngay - 7 + 1 (0 neu chua qua han)
- `01_HamTienIch.cpp` dòng 258 — `KhoangCachNgay`  
  Khoang cach 2 ngay = Doirangay(ngay 2) - Doirangay(ngay 1)

### j. 10 sách mượn nhiều nhất

Mở file: `j_Top10Sach.cpp`

- `j_Top10Sach.cpp` dòng 25  
  Buoc 1: mang tam luotMuon[] = 0, thuTu[] = chi so dau sach
- `j_Top10Sach.cpp` dòng 35  
  Buoc 2: duyet moi doc gia, moi luot muon -> tach ISBN -> tim dau sach -> tang luotMuon
- `j_Top10Sach.cpp` dòng 50  
  Buoc 3: Selection Sort chi chay 10 vong (moi vong dua dau sach nhieu luot nhat len) - O(10*n)
- `b_InDanhSachDocGia.cpp` dòng 21 — `DuyetGiuaDem`  
  Dem so doc gia: duyet giua LNR - O(n)
- `b_InDanhSachDocGia.cpp` dòng 32 — `DuyetGiuaThuThap`  
  Do con tro cac nut ra mang tam: duyet giua LNR nen mang tang dan theo ma the - O(n)
- `c_NhapSach.cpp` dòng 75 — `TimViTriDauSachTheoISBN`  
  Tim dau sach theo ISBN: tim tuyen tinh vi mang sap theo ten, khong theo ISBN - O(n)

### Dùng chung (không gắn câu nào)

- `01_HamTienIch.cpp` dòng 238 — `Doirangay`  
  Doi ngay ra so ngay tinh tu 01/01/0001 (cong 365/366 tung nam, so ngay tung thang)
- `04_LuuDocFile.cpp` dòng 33 — `GhiDocGia`  
  Luu file: ghi cay doc gia theo duyet truoc NLR
- `04_LuuDocFile.cpp` dòng 119 — `DocPhanDocGia`  
  Doc file: them lai tung doc gia bang them_cay, cay tu can bang AVL nen khong luu height
- `a_QuanLyDocGia.cpp` dòng 454 — `Huydocgia`  
  Huy cay doc gia: duyet sau (LRN), huy ca DSLK muon tra cua tung nut
