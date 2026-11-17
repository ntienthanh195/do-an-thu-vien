# Bộ câu hỏi vấn đáp — bám code `BAN_VIET_LAI_GON`

**167 câu**, soạn ngày 15/11/2026 từ code trong `BAN_VIET_LAI_GON/MaNguon`. Bộ này thay cho bộ 325 câu cũ (bộ cũ bám bản demo ngày 21/10, không còn khớp code).

| Phần | Mã | Số câu | Ai ôn chính |
|---|---|---|---|
| A. Khai báo, biến thêm ngoài đề | C | 15 | Cả nhóm |
| B. Thẻ độc giả, cây AVL (a) | DG | 22 | Thành |
| C. Mượn, trả, ngày tháng (f, g) | MT | 22 | Thành |
| D. Đầu sách, cuốn sách, mã sách (c) | DS | 18 | Thái |
| E. Tìm sách, quá hạn, Top 10 (e, i, j) | TK, QH, TOP | 18 | Thái |
| F. In độc giả, thể loại, sách đang mượn, giao diện (b, d, h) | IN | 19 | Tấn |
| G. Lưu và đọc file | FL | 9 | Cả nhóm |
| H. Tình huống thực tế như làm sản phẩm thật | TT | 35 | Cả nhóm |
| I. Thầy bắt sửa code tại chỗ | SC | 9 | Cả nhóm |

**Bốn kiểu câu:**

- **Vì sao thêm:** thầy chỉ vào một chỗ trong code và hỏi vì sao em làm cách này mà không làm cách khác, làm vậy thì ảnh hưởng gì.
- **Thuật toán:** chỉ vào hàm, giải thích và chạy tay trên dữ liệu cụ thể.
- **Bẫy:** thao tác hợp lệ của người dùng nhưng code cho kết quả sai hoặc đáng ngờ.
- **Thực tế:** yêu cầu của thư viện thật mà code chưa có, hỏi sẽ làm thế nào.

**Cách dùng:** một người đọc câu hỏi, người kia trả lời và chỉ đúng dòng code, sau đó mới đọc phần "Gợi ý trả lời" ngay dưới câu hỏi. Tên file và số dòng theo bố cục file mới ngày 17/11 (bảng tra: [`MUC_LUC.md`](MUC_LUC.md)); nếu sửa code thì tìm theo tên hàm hoặc tag `@TT`. Dữ liệu ví dụ lấy từ `DuLieu/ThuVien.txt` mẫu, giả sử hôm nay là 15/11/2026.

**Mức độ kiểm chứng (rà soát ngày 16/11/2026):**

- Mọi số dòng trong bộ này đã được đối chiếu lại với code hiện tại bằng chương trình. Ngày 17/11 đổi sang bố cục file mới (`0.x_`, `1.x_`, `a_`–`j_`): cả 218 dẫn chiếu được chuyển theo đúng dòng code đã dời và kiểm tra lại bằng chương trình.
- Các gợi ý có kết quả cụ thể đã được chạy lại trên chính code của nhóm: các bước xoay AVL (DG01, DG11, DG12, DG19), cấp mã thẻ (DG10), mốc quá hạn và năm nhuận (MT06, MT19), lách ngày mượn (MT03, MT04), vị trí chèn và thứ tự tên (DS01, DS03, DS13), sinh trùng mã sách (DS07), tìm chuỗi (TK01, TK03, TT22), thứ tự Top 10 và đồng hạng (TOP01, TOP03), thứ tự in theo tên và thể loại (IN03, IN08), danh sách quá hạn (QH01), hình dạng cây sau khi đọc lại file (FL01), và 16 kiểu file sai (FL07, MT17, TT29).
- Chưa chạy được: các câu về tốc độ với dữ liệu rất lớn (QH02, TT03) là ước lượng; phần giao diện mới chỉ chạy trên lớp giả lập và một lần trên Windows Terminal.
- Câu nào ghi "giả định của nhóm" thì nên hỏi thầy trước buổi vấn đáp.

## Đã sửa trong code ngày 15/11/2026

| Lỗi | Sửa ở | Câu |
|---|---|---|
| Nhập ngày mượn lùi lại thì lách được kiểm tra quá hạn | `f_MuonSach.cpp` dòng 42 | MT03 |
| Nhận ngày mượn, ngày trả ở tương lai | `f_MuonSach.cpp` dòng 24–29, `g_TraSach.cpp` dòng 29–34 | MT04 |
| File hỏng thì chạy với thư viện rỗng rồi ghi đè mất dữ liệu | `main.cpp` dòng 12–26 | FL03 |
| Đồng hồ máy lùi năm làm file hợp lệ bị coi là hỏng | `1.2_DauSach_MangConTro.cpp` dòng 43–50 | FL04 |

Bản gốc của năm file đã sửa nằm trong `_BanTruocKhiSua_20261115`.

## 8 điểm yếu còn lại, nên sửa hoặc chuẩn bị sẵn câu trả lời

| # | Điểm yếu | Câu |
|---|---|---|
| 1 | Xóa thẻ lớn nhất rồi thêm mới thì cấp lại đúng mã cũ | DG10 |
| 2 | Mở khóa thẻ của người làm mất sách không cần điều kiện gì | DG15 |
| 3 | File đảo thứ tự cuốn làm sinh trùng mã sách | DS07 |
| 4 | Cuốn ghi "đang mượn" mà không ai giữ thì kẹt vĩnh viễn | MT17 |
| 5 | Top 10 đồng hạng không theo thứ tự tên | TOP03 |
| 6 | Sắp xếp quá hạn tính lại ngày quá nhiều lần, chậm khi dữ liệu lớn | QH02 |
| 7 | Không nhập được tiếng Việt có dấu, phái phải gõ "Nu" | TK04 |
| 8 | Không có sửa hay xóa đầu sách khi nhập sai | DS10 |

---

## A. Khai báo chung và biến thêm ngoài đề

### C01 · Vì sao thêm
`0.0_KhaiBaoChung.h` dòng 99, `NutDocGia::height`

**Hỏi:** Đề không có `height` trong thẻ độc giả. Em thêm để làm gì? Bỏ đi thì chương trình còn chạy đúng không, chậm ở đâu?

**Gợi ý trả lời:** Mã thẻ cấp tăng dần, nên với BST thường nút mới luôn nằm bên phải, cây thành danh sách liên kết và tìm thẻ mất O(n). `height` lưu chiều cao nút để tính hệ số cân bằng (cao trái trừ cao phải) trong O(1), lệch quá 1 thì xoay. Không có `height` vẫn làm AVL được nhưng mỗi lần phải đệ quy tính chiều cao O(n). AVL vẫn là cây nhị phân tìm kiếm nên không trái đề.

### C02 · Vì sao thêm
`0.0_KhaiBaoChung.h` dòng 99

**Hỏi:** Sao em lưu chiều cao mà không lưu hệ số cân bằng (−1, 0, 1) như trong giáo trình?

**Gợi ý trả lời:** Cả hai đều tốn một `int`. Chiều cao cập nhật bằng một công thức duy nhất: lớn hơn giữa hai con cộng 1. Hệ số cân bằng thì sau mỗi phép xoay phải xét từng trường hợp để gán lại, dễ sai hơn. Nhóm chọn cách dễ giải thích và dễ kiểm.

### C03 · Vì sao thêm
`0.0_KhaiBaoChung.h` dòng 69; `0.3_Menu_TongQuan.cpp` dòng 13–58

**Hỏi:** Số đầu sách thì em lưu sẵn trong `soLuong`, còn số độc giả, tổng số cuốn và số cuốn đang được mượn ở trang Tổng quan thì không lưu mà đếm lại mỗi lần. Vì sao hai cách khác nhau? Mỗi lần vẽ trang Tổng quan tốn gì?

**Gợi ý trả lời:** Mảng bắt buộc phải có số phần tử đang dùng, không có thì không biết mảng dừng ở đâu. Cây và danh sách liên kết tự kết thúc bằng con trỏ rỗng nên đếm được bằng cách duyệt; lưu thêm biến đếm là thêm biến ngoài đề và phải giữ cho khớp khi thêm, xóa, đọc file. Cái giá: mỗi lần vẽ trang Tổng quan duyệt mọi cuốn sách ba lần (tổng số, đang mượn, còn trên kệ) và mọi độc giả một lần, O(C + R).

### C04 · Vì sao thêm
`0.0_KhaiBaoChung.h` dòng 103, `typedef NutDocGia *CayDocGia`

**Hỏi:** `CayDocGia` là gì? Vì sao `them_cay` nhận `CayDocGia &` còn `MaTheLonNhat` chỉ nhận `CayDocGia`?

**Gợi ý trả lời:** Chỉ là tên khác của con trỏ tới nút gốc, không phải struct mới. Thêm và xóa có thể đổi gốc sau khi xoay nên phải nhận tham chiếu tới con trỏ gốc. `MaTheLonNhat` chỉ đọc, nhận bản sao con trỏ rồi đi dần sang phải cũng không ảnh hưởng gốc thật.

### C05 · Vì sao thêm
`j_Top10Sach.cpp` dòng 26–31

**Hỏi:** Sao không thêm trường "số lượt mượn" vào `DauSach` để Top 10 khỏi đếm lại?

**Gợi ý trả lời:** Vì đó là trường ngoài đề. Nhóm dùng mảng tạm `luotMuon[]` cấp phát trong hàm rồi giải phóng. Đánh đổi: mỗi lần xem phải duyệt toàn bộ lịch sử. Nếu thêm trường thì phải tăng khi mượn, dựng lại khi đọc file, và có nguy cơ lệch với lịch sử.

### C06 · Vì sao thêm
`0.0_KhaiBaoChung.h` dòng 12–13; `f_MuonSach.cpp` dòng 37

**Hỏi:** Thư viện đổi quy định thành mượn tối đa 5 cuốn. Em sửa mấy chỗ?

**Gợi ý trả lời:** Sửa hằng `MAX_SACH_MUON` là logic đổi theo. Nhưng thông báo lỗi ở f_MuonSach.cpp dòng 37 ghi cứng "đủ 3 cuốn", phải sửa chuỗi này. Tương tự tên hàm `CoSachQuaHan7Ngay` ghi cứng số 7 dù logic dùng `HAN_MUON`.

### C07 · Vì sao thêm
`f_MuonSach.cpp` dòng 19–74; `g_TraSach.cpp` dòng 20–58

**Hỏi:** `MuonSach` và `TraSach` không in gì ra màn hình, chỉ trả `bool` và ghi lý do vào `string &loi`. Việc in nằm ở `ManHinhMuonSach`. Sao em tách như vậy? Gộp lại thì mất gì?

**Gợi ý trả lời:** Hàm nghiệp vụ chỉ quyết định "được hay không và vì sao", hàm màn hình lo vị trí, màu, phím. Nhờ đó kiểm tra nghiệp vụ nằm một chỗ: đổi giao diện không đụng tới luật mượn, và thầy yêu cầu sửa luật (ví dụ cấm mượn hai cuốn cùng đầu sách) thì chỉ sửa một hàm. Gộp lại thì mỗi màn hình gọi mượn phải lặp lại các điều kiện, sót một chỗ là có lỗ hổng.

### C08 · Bẫy
`1.4_MuonTra_DSLKDon.cpp` dòng 90–103, `CapNhatLuotTra`

**Hỏi:** Hàm nhận `const NutDocGia &docgia` mà vẫn sửa ngày trả và trạng thái lượt mượn. Sao trình biên dịch không báo lỗi?

**Gợi ý trả lời:** `const` chỉ khóa các trường nằm ngay trong nút, tức là khóa con trỏ `dsMuonTra` không cho trỏ sang chỗ khác. Nó không khóa nút `MuonTra` mà con trỏ đó trỏ tới. Nên `const` ở đây gây hiểu nhầm; đúng ra nên bỏ `const` vì hàm có sửa dữ liệu của độc giả.

### C09 · Vì sao thêm
`0.1_HamTienIch.cpp` dòng 266–275; `0.2_GiaoDien.cpp` dòng 47–110

**Hỏi:** Liệt kê các hàm có sẵn em dùng mà không tự viết. Hàm nào bắt buộc, hàm nào tự viết được? Riêng `KhoiTaoManHinh` gọi ba hàm của Windows, mỗi hàm để làm gì?

**Gợi ý trả lời:** Bắt buộc: `time`, `localtime` (lấy ngày máy); `_getch` (đọc phím); `system("mode con")`; `setvbuf` (cho `cout` gom chữ vào vùng đệm); `ifstream`, `ofstream`, `getline`. Trong `KhoiTaoManHinh`: `SetConsoleOutputCP(65001)` chuyển console sang bảng mã UTF-8 để in tiếng Việt có dấu; `GetConsoleMode` và `SetConsoleMode` (cùng `GetStdHandle`) bật chế độ cho console hiểu mã ANSI. `gotoxy` và `SetColor` đều tự viết bằng cách in mã ANSI qua `cout`. Ba hàm này chỉ gọi một lần lúc mở chương trình. Còn lại nhóm tự viết: đổi số sang chuỗi và ngược lại, tách trường, so sánh chuỗi, tìm chuỗi con, các thuật toán sắp xếp, tính ngày, và toàn bộ thanh menu, ô số liệu, khung, ô nhập, bảng.

### C10 · Vì sao thêm
`0.0_KhaiBaoChung.h` dòng 37–99; `1.1_DocGia_CayAVL.cpp` dòng 154–156; `f_MuonSach.cpp` dòng 66–70

**Hỏi:** Trong các struct em viết sẵn giá trị ngay sau tên trường: `int height = 1`, `left = nullptr`, `trangThai = SACH_CHO_MUON`, ngày `0/0/0`. Sau lệnh `new NutDocGia` các trường của nút mang giá trị gì? Chỉ ba chỗ trong code đang dựa vào các giá trị mặc định đó mà không gán lại.

**Gợi ý trả lời:** Đây là giá trị khởi tạo mặc định của C++11: mỗi lần tạo biến hay `new` một struct, các trường tự nhận giá trị đó. Ba chỗ dựa vào nó: `ThemDocGiaAVL` tạo nút mới chỉ gán `thongTin`, còn `left`, `right` rỗng và `height = 1` là mặc định (nút lá cao 1, cây rỗng cao 0). `MuonSach` tạo lượt mới không gán `ngayTra`, nên nó là `0/0/0`, đúng quy ước "chưa trả" khi ghi file. `ThemCuonSachCoMa` không gán `next`, nên cuốn mới tự là cuối danh sách. Nếu thầy hỏi vì sao phải bật `-std=c++11`: cú pháp này là một lý do.

### C11 · Vì sao thêm
`1.1_DocGia_CayAVL.cpp` dòng 39, 94, 150, 249, 310, 334

**Hỏi:** Sáu hàm `XoayTrai`, `XoayPhai`, `ThemDocGiaAVL`, `CanBangLai`, `TachNutNhoNhat`, `XoaNutAVL` có chữ `static` đứng trước và không được khai báo trong file `.h`, còn `them_cay`, `XoaDocGia` thì có. Vì sao em chia như vậy? Nếu màn hình xóa thẻ gọi thẳng `XoaNutAVL` được thì nguy hiểm gì?

**Gợi ý trả lời:** `static` trước một hàm nghĩa là hàm chỉ dùng được trong chính file đó. Sáu hàm kia là các bước bên trong của cây AVL; bên ngoài chỉ được đi qua `them_cay` và `XoaDocGia`, là hai hàm có kiểm tra điều kiện. `XoaNutAVL` xóa nút mà không hủy danh sách mượn trả và không kiểm thẻ có lịch sử hay không; nếu gọi thẳng cho một thẻ đang giữ sách thì lịch sử bị rò bộ nhớ, cuốn sách kẹt ở trạng thái đang mượn và Top 10 giảm. Để `static` thì trình biên dịch chặn luôn khả năng đó.

### C12 · Vì sao thêm
`0.0_KhaiBaoChung.h` dòng 207–208, 266–267

**Hỏi:** Nhìn vào khai báo: `MuonSach(DanhSachDauSach &ds, NutDocGia &docgia, const string &maSach, NgayThang ngayMuon, string &loi)`. Năm tham số truyền theo ba kiểu khác nhau. Vì sao mỗi cái một kiểu? `HieuChinhDocGia` lại nhận `string Ho` không có `&`, tốn gì?

**Gợi ý trả lời:** `ds` và `docgia` truyền tham chiếu thường vì hàm sửa chúng (đổi trạng thái cuốn, thêm lượt). `maSach` là `const string &`: chỉ đọc và không chép chuỗi. `ngayMuon` truyền theo trị vì chỉ là ba số nguyên, chép còn rẻ hơn dùng tham chiếu. `loi` là tham chiếu thường vì đây là kết quả trả ra thứ hai, bên cạnh `bool`. `HieuChinhDocGia` nhận `string` theo trị là code gốc của nhóm: mỗi lời gọi chép ba chuỗi, vẫn đúng nhưng tốn hơn `const string &`; với họ tên vài chục ký tự thì không đáng kể.

### C13 · Thuật toán
`0.0_KhaiBaoChung.h` dòng 45–103

**Hỏi:** Vẽ sơ đồ bốn cấu trúc của đề và các mũi tên nối chúng. Từ một độc giả, đi đường nào để ra tên cuốn sách người đó đang giữ? Từ một cuốn sách, đi đường nào để biết ai đang giữ nó? Chiều nào có con trỏ, chiều nào không?

**Gợi ý trả lời:** Hai nhánh con trỏ: mảng đầu sách trỏ tới `DauSach`, từ đó `dms` trỏ tới danh sách `CuonSach`; cây trỏ tới `NutDocGia`, từ đó `dsMuonTra` trỏ tới danh sách `MuonTra`. Hai nhánh chỉ nối với nhau bằng một chuỗi: `MuonTra.maSach`. Độc giả ra tên sách: duyệt lịch sử, lấy mã sách, tách ISBN, tìm đầu sách trong mảng (tuyến tính), đọc `tenSach`. Cuốn sách ra người giữ: không có liên kết nào, phải duyệt mọi độc giả và mọi lượt mượn. Vì vậy câu hỏi "theo độc giả" rẻ, câu hỏi "theo sách" đắt; Top 10, kiểm kê, trả sách bằng mã sách đều gặp đúng chỗ này.

### C14 · Thuật toán
Toàn bộ `MaNguon`

**Hỏi:** Nêu độ phức tạp của từng chức năng a đến j theo R (độc giả), D (đầu sách), c (số cuốn của một đầu sách), H (tổng lượt mượn), H₁ (lượt mượn của một người). Chức năng nào đắt nhất và vì sao?

**Gợi ý trả lời:** a: thêm, xóa, hiệu chỉnh thẻ O(log R). b: theo mã O(R); theo tên O(R log R) trung bình. c: thêm đầu sách O(D); thêm k cuốn O(k·(c + k)). d: sắp xếp chèn, O(D²) xấu nhất, gần O(D) khi thể loại đã gần đúng thứ tự. e: O(D) lần so chuỗi con, cộng phần in. f và g: O(log R + H₁ + D + c). h: O(log R + H₁ + D). i: O(R + H) để gom, cộng O(n²) để sắp n lượt quá hạn. j: O(R + H·D) để đếm, cộng 10·D để chọn. Đắt nhất là j vì mỗi lượt mượn phải tìm lại đầu sách trong mảng không sắp theo ISBN. Lưu ý thêm: mọi thao tác có thay đổi dữ liệu còn cộng một lần ghi lại cả file, O(D + C + R + H).

### C15 · Bẫy
`a_QuanLyDocGia.cpp` dòng 88; `0.4_LuuDocFile.cpp` dòng 51–72, 142

**Hỏi:** Em nói nhờ AVL nên thêm thẻ chỉ tốn O(log n). Nhưng ngay sau `them_cay`, em gọi `LuuSauThayDoi` ghi lại toàn bộ file, tốn O(n). Vậy AVL còn ý nghĩa gì?

**Gợi ý trả lời:** Với thao tác thêm và xóa thì đúng là phần ghi file lấn át, AVL không làm tổng thời gian nhỏ hơn O(n). AVL có ý nghĩa ở ba chỗ khác. Một: tìm thẻ, việc xảy ra ở đầu mọi giao dịch mượn, trả, xem sách, luôn O(log R). Hai: lúc mở chương trình, R thẻ được chèn lại từng cái; với BST thường và mã tăng dần thì tốn cỡ R²/2 bước, AVL chỉ R·log R; đã thử 100.000 thẻ, cây chỉ cao 17. Ba: BST lệch sâu R tầng thì các hàm đệ quy (duyệt, hủy cây) có thể tràn ngăn xếp. Trả lời thẳng như vậy tốt hơn là cãi rằng thêm thẻ vẫn O(log n).

---

## B. Thẻ độc giả và cây AVL (Thành)

### DG01 · Thuật toán
`1.1_DocGia_CayAVL.cpp` dòng 150–236, `ThemDocGiaAVL`

**Hỏi:** Thêm lần lượt 7 độc giả mới vào cây rỗng (mã 1 đến 7). Vẽ cây sau mỗi bước, bước nào xoay, xoay tại nút nào? So với BST thường.

**Gợi ý trả lời:** Xoay trái tại nút 1 khi thêm 3, tại nút 3 khi thêm 5, tại nút 2 khi thêm 6, tại nút 5 khi thêm 7. Kết quả là cây đầy đủ: gốc 4, con 2 và 6, lá 1, 3, 5, 7, cao 3. BST thường cho một chuỗi lệch phải cao 7.

### DG02 · Thuật toán
`1.1_DocGia_CayAVL.cpp` dòng 211–232

**Hỏi:** Code nhận biết bốn trường hợp mất cân bằng bằng cách so mã thẻ mới với mã của nút con (dòng 206, 218). Vì sao so mã là đủ? Lúc xóa có dùng cách này được không?

**Gợi ý trả lời:** Hệ số lớn hơn 1 nghĩa là nút mới vừa vào cây con trái. Nếu mã mới lớn hơn mã con trái thì nó nằm bên phải của con trái (trái–phải): xoay trái con rồi xoay phải; ngược lại là trái–trái: chỉ xoay phải. Khi xóa không có "mã vừa thêm", nên `CanBangLai` phải so chiều cao hai cháu (dòng 273, 291).

### DG03 · Thuật toán
`1.1_DocGia_CayAVL.cpp` dòng 39–91, 173–192

**Hỏi:** Trong `XoayTrai` em chỉ tính lại `height` cho đúng hai nút: gốc cũ rồi gốc mới. Vì sao hai nút là đủ, các nút con bên dưới không cần tính lại? Còn nút cha của chỗ vừa xoay thì ai cập nhật, ở dòng nào?

**Gợi ý trả lời:** Phép xoay chỉ đổi con của hai nút đó; ba cây con treo bên dưới giữ nguyên hình dạng nên chiều cao của chúng không đổi. Gốc cũ tính trước vì sau khi xoay nó là con của gốc mới, gốc mới cần chiều cao đã sửa của nó. Nút cha không được sửa trong `XoayTrai`: hàm trả gốc mới về cho lời gọi đệ quy của nút cha trong `ThemDocGiaAVL`, và nút cha tự tính lại chiều cao ở dòng 166–185. Cứ thế ngược lên tới gốc, nên mỗi lần thêm tốn O(log n).

### DG04 · Thuật toán
`1.1_DocGia_CayAVL.cpp` dòng 47–66, 69–88, 173–192 so với 254–266

**Hỏi:** Đoạn tính `height` gồm năm nhánh if lặp lại nhiều lần, trong khi `CanBangLai` viết gọn hơn. Em rút gọn giúp thầy.

**Gợi ý trả lời:** Cả hai làm cùng một việc: chiều cao bằng lớn hơn giữa cao trái và cao phải, cộng 1, với cây con rỗng coi là 0. Có thể tách một hàm `ChieuCao(p)` trả 0 khi `p` rỗng, rồi mỗi chỗ chỉ còn một dòng. Bản dài là code viết từ đầu của nhóm, giữ nguyên vì đã kiểm đúng.

### DG05 · Bẫy
`1.1_DocGia_CayAVL.cpp` dòng 41–44

**Hỏi:** `XoayTrai` đọc `root->right->left`. Có khi nào `root->right` rỗng làm chương trình sập không?

**Gợi ý trả lời:** Không, vì hàm chỉ được gọi trong ba tình huống đều bảo đảm con phải tồn tại: hệ số nhỏ hơn −1 (cây con phải cao ít nhất 2); trường hợp trái–phải lúc thêm (nút mới nằm bên phải con trái); và trong `CanBangLai` khi cháu phải cao hơn cháu trái.

### DG06 · Thuật toán
`1.1_DocGia_CayAVL.cpp` dòng 374–383

**Hỏi:** Xóa nút có hai con: em tách nút nhỏ nhất bên phải rồi nối lại con trỏ, chứ không chép `thongTin` sang. Vì sao?

**Gợi ý trả lời:** Gán cả struct `thongTin` sẽ chép luôn con trỏ `dsMuonTra`, làm hai nút cùng trỏ một danh sách lịch sử, rất dễ hủy trùng hoặc mất lịch sử. Nối lại con trỏ thì không chép chuỗi nào, và địa chỉ của nút thay thế không đổi. Chiều cao nút thay thế được tính lại ở `CanBangLai(root)` dòng 374.

### DG07 · Thuật toán
`1.1_DocGia_CayAVL.cpp` dòng 310–330, `TachNutNhoNhat`

**Hỏi:** Vì sao trên đường quay về hàm này cũng gọi `CanBangLai`?

**Gợi ý trả lời:** Rút nút nhỏ nhất làm nhánh đó thấp đi một bậc, các nút tổ tiên của nó trong cây con phải có thể bị lệch. Mỗi tầng đệ quy quay về phải tính lại chiều cao và xoay nếu cần.

### DG08 · Thuật toán
`1.1_DocGia_CayAVL.cpp` dòng 334–387

**Hỏi:** Xóa một nút lá thì hàm trả `nullptr` ngay (dòng 343). Vậy cân bằng lại xảy ra ở đâu? Thêm và xóa khác nhau thế nào về số lần xoay?

**Gợi ý trả lời:** Ở lời gọi của nút cha: sau khi gán lại con, nó rơi xuống `return CanBangLai(root)` dòng 374, và cứ thế lên đến gốc. Thêm chỉ cần xoay tại một nút là đủ; xóa có thể phải xoay ở nhiều tầng trên đường về gốc.

### DG09 · Thuật toán
`1.1_DocGia_CayAVL.cpp` dòng 392–409, `XoaDocGia`

**Hỏi:** Hàm tìm nút bằng `tim_cay` rồi `XoaNutAVL` lại tìm lần nữa. Có thừa không?

**Gợi ý trả lời:** Có tìm hai lần, mỗi lần O(log n). Lần đầu để kiểm tra "có tồn tại không, có lịch sử không" trước khi đụng vào cây. Gộp lại được nhưng phải đưa thông báo lỗi ra từ giữa hàm đệ quy, code rối hơn mà lợi không đáng kể.

### DG10 · Bẫy
`a_QuanLyDocGia.cpp` dòng 83–85; `1.1_DocGia_CayAVL.cpp` dòng 428–435

**Hỏi:** Đang có thẻ 1 đến 8. Thẻ 8 vừa cấp, chưa mượn gì, bị xóa. Thêm độc giả mới thì mã là bao nhiêu? Ngoài đời người cũ vẫn cầm thẻ giấy số 8 thì sao? Xóa thẻ 7 thay vì 8 thì mã mới là mấy?

**Gợi ý trả lời:** Mã mới bằng mã lớn nhất trong cây cộng 1, nên xóa thẻ 8 rồi thêm sẽ cấp lại 8. Đề ghi "không trùng với các mã thẻ độc giả cũ", có thể hiểu là kể cả mã đã xóa. Người cũ cầm thẻ giấy số 8 có thể mượn sách dưới tên người mới. Xóa thẻ 7 thì cấp 9, số 7 bỏ trống. Muốn không bao giờ cấp lại phải lưu "mã lớn nhất đã cấp" thành một giá trị trong file, tức là thêm một biến ngoài đề và phải giải thích.

### DG11 · Thuật toán
`1.1_DocGia_CayAVL.cpp` dòng 310–330, 374–386

**Hỏi:** Cây có thẻ 1 đến 7 (gốc 4, con 2 và 6, lá 1, 3, 5, 7), chưa ai mượn gì. Xóa thẻ 4. Chạy tay `TachNutNhoNhat` và vẽ cây sau khi xóa. Nút nào lên làm gốc, nút 6 thay đổi gì?

**Gợi ý trả lời:** Nút nhỏ nhất của cây con phải là 5. `TachNutNhoNhat` gỡ 5 ra, con trái của 6 thành rỗng, 6 còn chiều cao 2 và vẫn cân bằng. Nút 5 nhận con trái là 2, con phải là 6 rồi lên làm gốc. Cây mới: gốc 5; bên trái 2 (lá 1, 3); bên phải 6 (chỉ có con phải 7). `CanBangLai` ở dòng 374 tính lại chiều cao gốc là 3, không cần xoay.

### DG12 · Thuật toán
`1.1_DocGia_CayAVL.cpp` dòng 249–307, `CanBangLai`

**Hỏi:** Cây gốc 2, con trái 1, con phải 3, và 3 có con phải 4. Xóa thẻ 1 thì xoay gì? Nếu thay vào đó cây là gốc 2, con trái 1, con phải 4, và 4 có con trái 3, thì xóa 1 xoay khác thế nào?

**Gợi ý trả lời:** Trường hợp đầu: tại nút 2, cao trái 0, cao phải 2, hệ số −2. Con phải là 3 có cháu phải cao hơn cháu trái nên chỉ xoay trái tại 2: gốc mới là 3, con 2 và 4. Trường hợp sau: con phải là 4 có cháu trái cao hơn (dòng 291), nên xoay phải tại 4 trước rồi xoay trái tại 2; kết quả cũng là gốc 3, con 2 và 4. Lúc xóa không có "mã vừa thêm" để so nên phải so chiều cao hai cháu.

### DG13 · Thuật toán
`1.1_DocGia_CayAVL.cpp` dòng 239–245 và 167–171

**Hỏi:** `them_cay` gọi `tim_cay` kiểm trùng, trong khi `ThemDocGiaAVL` cũng đã có nhánh xử lý trùng mã. Thừa không?

**Gợi ý trả lời:** `ThemDocGiaAVL` trả về con trỏ gốc nên không báo được "bị trùng" cho nơi gọi. `them_cay` cần trả `false` khi trùng (đọc file dùng để phát hiện file có hai thẻ cùng mã), nên phải kiểm trước.

### DG14 · Vì sao thêm
`a_QuanLyDocGia.cpp` dòng 96, 109, 113

**Hỏi:** Ở màn hình hiệu chỉnh, em truyền thẳng kết quả `ChonMenu` vào `HieuChinhDocGia` làm trạng thái thẻ, không có `if` nào đổi "mục được chọn" thành `THE_BI_KHOA` hay `THE_HOAT_DONG`. Vì sao làm được vậy? Cách này ràng buộc gì về sau?

**Gợi ý trả lời:** `ChonMenu` trả chỉ số mục: 0 là "Khoa the", 1 là "Dang hoat dong", trùng đúng giá trị hai hằng `THE_BI_KHOA = 0` và `THE_HOAT_DONG = 1` mà đề quy định, nên không cần đổi. Ràng buộc: thứ tự hai chuỗi trong `mucTrangThai` phải luôn khớp giá trị hằng. Đây là chỗ phụ thuộc ngầm, nên nói rõ khi thầy chỉ vào dòng 550.

### DG15 · Bẫy
`1.1_DocGia_CayAVL.cpp` dòng 412–424; `a_QuanLyDocGia.cpp` dòng 94–117

**Hỏi:** Độc giả Cường (thẻ 1) bị khóa vì làm mất sách. Thủ thư vào hiệu chỉnh, chọn "Dang hoat dong". Chương trình có cho không? Có phân biệt được thẻ khóa do mất sách với thẻ khóa tay không?

**Gợi ý trả lời:** Cho, vì `HieuChinhDocGia` không kiểm điều kiện gì. Dữ liệu cũng không lưu lý do khóa, chỉ suy ra được từ lịch sử có lượt trạng thái 2. Đây là giả định của nhóm: thủ thư tự quyết sau khi độc giả đền sách. Nếu thầy muốn chặn thì phải có thêm quy ước "đã đền", mà đề không có trường nào cho việc đó.

### DG16 · Bẫy
`a_QuanLyDocGia.cpp` dòng 104–113

**Hỏi:** Đổi tên độc giả có phải sắp lại cây không? Đang ở bảng "in theo tên" thì sao? Có sửa mã thẻ được không?

**Gợi ý trả lời:** Không phải sắp lại, vì khóa của cây là mã thẻ. Bảng theo tên được sắp lại từ mảng tạm mỗi lần mở nên tự đúng. Mã thẻ không sửa được (màn hình không có ô đó); nếu cho sửa thì phải xóa nút rồi thêm lại để giữ đúng thứ tự cây.

### DG17 · Bẫy
`1.1_DocGia_CayAVL.cpp` dòng 401–405

**Hỏi:** Một độc giả đã trả hết sách từ lâu, xin hủy thẻ. Chương trình xử lý thế nào và vì sao? Hệ quả lâu dài?

**Gợi ý trả lời:** Không cho xóa vì thẻ đã có lịch sử, chỉ khóa được. Lý do: Top 10 đếm từ lịch sử của độc giả, xóa thẻ thì số lượt mượn của các sách giảm theo. Hệ quả: cây chỉ tăng chứ không giảm, và danh sách in luôn có cả thẻ đã ngừng dùng.

### DG18 · Thuật toán
`1.1_DocGia_CayAVL.cpp` dòng 446–456, `Huydocgia`

**Hỏi:** Vì sao hủy cây theo thứ tự sau (LRN)? Đệ quy sâu tối đa bao nhiêu? Lịch sử mượn được hủy ở đâu?

**Gợi ý trả lời:** Phải hủy hai cây con trước, vì xóa nút cha trước thì mất con trỏ tới các con. Độ sâu đệ quy bằng chiều cao cây, nhờ AVL chỉ khoảng log n. Lịch sử của từng nút được hủy bằng `HuyDanhSachMuonTra` ở dòng 437, ngay trước khi `delete` nút.

### DG19 · Thuật toán
`1.1_DocGia_CayAVL.cpp` dòng 270–286

**Hỏi:** Cây gốc 4, con trái 2 (có hai con 1 và 3), con phải 5. Xóa thẻ 5. Tại nút 4 hệ số cân bằng là bao nhiêu? Con trái là nút 2 có hai cháu cao bằng nhau: code xoay đơn hay xoay kép, do điều kiện nào? Vẽ cây kết quả.

**Gợi ý trả lời:** Sau khi xóa 5, tại nút 4 cao trái 2, cao phải 0, hệ số +2. Điều kiện ở dòng 273 là "cháu phải cao HƠN cháu trái" mới xoay trái con trước; ở đây hai cháu bằng nhau nên điều kiện sai, chỉ xoay phải một lần tại 4. Kết quả: gốc 2, con trái 1, con phải 4, và 4 có con trái 3. Quy tắc: xoay kép chỉ cần khi nhánh "trong" cao hơn hẳn; bằng nhau hoặc nhánh "ngoài" cao hơn thì xoay đơn là đủ. Trường hợp hai cháu bằng nhau chỉ xuất hiện khi xóa, không xuất hiện khi thêm.

### DG20 · Bẫy
`f_MuonSach.cpp` dòng 136–160; `a_QuanLyDocGia.cpp` dòng 128–137

**Hỏi:** Màn hình mượn sách giữ con trỏ `docgia` tới một nút của cây suốt lúc người dùng mượn liên tiếp nhiều cuốn. Nếu trong lúc đó cây bị xoay vì có thẻ mới được thêm, con trỏ này còn dùng được không? Trường hợp nào con trỏ tới nút thật sự hỏng, và màn hình xóa thẻ tránh nó thế nào?

**Gợi ý trả lời:** Còn dùng được. Phép xoay chỉ đổi các liên kết `left`, `right` và `height`; nút không bị cấp phát lại hay chép sang chỗ khác, nên mỗi độc giả nằm nguyên một địa chỉ từ lúc `new` đến lúc `delete`. Đã thử: giữ con trỏ tới thẻ 7, thêm ba thẻ làm cây xoay, con trỏ vẫn trỏ đúng thẻ 7. Con trỏ chỉ hỏng khi nút bị xóa. Màn hình xóa thẻ chép `maThe` ra biến riêng trước khi gọi `XoaDocGia` (dòng 565), các thông báo sau đó chỉ dùng biến này, không đụng tới `p` nữa.

### DG21 · Vì sao thêm
`1.1_DocGia_CayAVL.cpp` dòng 150–165, 446–456

**Hỏi:** `ThemDocGiaAVL` nhận `NutDocGia* root` và trả về con trỏ, nơi gọi viết `root->left = ThemDocGiaAVL(root->left, ...)`. Còn `Huydocgia` lại nhận `NutDocGia *&` và không trả gì. Hai cách này khác nhau thế nào, vì sao mỗi hàm một cách?

**Gợi ý trả lời:** Cả hai đều nhằm sửa được con trỏ của nút cha. Cách trả về con trỏ: hàm con trả gốc mới của cây con, nút cha tự gán lại; hợp với thêm và xóa AVL vì sau khi xoay, gốc của cây con đổi thành nút khác, và trên đường quay về mỗi tầng còn phải tính lại chiều cao. Cách tham chiếu tới con trỏ: hàm sửa thẳng vào ô con trỏ của cha; hợp với hủy cây vì chỉ cần gán ô đó thành rỗng sau khi `delete`, không có gì để trả về. Gán rỗng như vậy để sau khi hủy, cây ở trạng thái rỗng hợp lệ chứ không trỏ vào vùng nhớ đã trả.

### DG22 · Bẫy
`a_QuanLyDocGia.cpp` dòng 104–113; `1.1_DocGia_CayAVL.cpp` dòng 412–424

**Hỏi:** Ở màn hình hiệu chỉnh có dòng `DocGia dg = p->thongTin;`. Phép gán này chép những gì? `dg` và nút trong cây lúc đó cùng trỏ tới một danh sách mượn trả, có nguy hiểm không? Người dùng sửa họ xong rồi nhấn Esc ở ô tên thì thẻ trong cây đã bị đổi chưa?

**Gợi ý trả lời:** Phép gán chép từng trường: mã thẻ, ba chuỗi, trạng thái, và cả giá trị con trỏ `dsMuonTra` (không chép các lượt mượn). Hai nơi cùng trỏ một danh sách chỉ nguy hiểm nếu một bên đem `delete`; `DocGia` không có hàm hủy tự viết, nên khi `dg` hết phạm vi, danh sách không bị đụng tới. `dg` chỉ là chỗ nháp cho họ, tên, phái. Nhấn Esc thì gặp `continue` trước khi tới `HieuChinhDocGia`, nên thẻ trong cây chưa đổi gì; chỉ khi nhập đủ cả ba ô và chọn trạng thái thì bốn trường mới được ghi vào nút. `HieuChinhDocGia` không ghi `dsMuonTra` nên lịch sử không bao giờ bị thay.

---

## C. Mượn, trả, ngày tháng (Thành)

### MT01 · Thuật toán
`f_MuonSach.cpp` dòng 24–64

**Hỏi:** `MuonSach` kiểm theo thứ tự: ngày mượn, thẻ, đủ 3 cuốn, quá hạn, rồi mới tìm cuốn sách. Một độc giả bị khóa thẻ, đang giữ 3 cuốn, lại nhập sai mã sách thì báo lỗi nào? Vì sao em xếp thứ tự như vậy?

**Gợi ý trả lời:** Báo thẻ bị khóa. Ngày mượn kiểm đầu tiên vì đó là dữ liệu nhập, sai thì không cần xét gì thêm. Tiếp theo là các điều kiện về độc giả: không phụ thuộc cuốn nào và rẻ (xem một trường, duyệt lịch sử của một người). Tìm cuốn sách phải duyệt mảng đầu sách nên để sau cùng. Thứ tự này cũng quyết định người dùng thấy thông báo nào khi sai nhiều thứ cùng lúc.

### MT02 · Bẫy
`f_MuonSach.cpp` dòng 19–74

**Hỏi:** Độc giả đang giữ cuốn `9786040000001#1`, xin mượn thêm `9786040000001#2` cùng đầu sách. Có cho không? Nếu thầy bảo phải cấm thì sửa thế nào?

**Gợi ý trả lời:** Code hiện cho mượn, vì đề chỉ giới hạn 3 cuốn và mỗi cuốn có mã riêng. Thư viện thật thường cấm để một người không chiếm hai bản của cùng một sách. Muốn cấm: trước khi thêm lượt, duyệt lịch sử, nếu có lượt đang mượn mà `TachISBNTuMaSach` của nó bằng ISBN của cuốn mới thì từ chối. Đây là giả định cần chốt với thầy.

### MT03 · Vì sao thêm
`f_MuonSach.cpp` dòng 24, 42, 92

**Hỏi:** Hàm đã nhận tham số `ngayMuon`, vậy mà kiểm quá hạn ở dòng 33 em lại dùng `homNay` lấy từ máy chứ không dùng `ngayMuon`. Vì sao? Lấy Bình (thẻ 2, giữ `9786040000002#1` từ 01/11, hôm nay 15/11) để giải thích nếu dùng `ngayMuon` thì người dùng lách thế nào.

**Gợi ý trả lời:** Ngày mượn do thủ thư gõ nên có thể gõ lùi. Nếu xét quá hạn đến `ngayMuon`, thủ thư gõ 05/11 thì từ 01/11 đến 05/11 mới 4 ngày, Bình được mượn tiếp dù thực tế đã quá hạn 8 ngày. Xét đến ngày máy thì gõ ngày nào kết quả cũng như nhau, và khớp với bảng "sách đang mượn" vốn tô đỏ theo ngày máy (dòng 80). Bản trước 15/11 dùng `ngayMuon` và có đúng lỗ hổng này; đã chạy thử lại: mượn lùi ngày bị từ chối.

### MT04 · Vì sao thêm
`f_MuonSach.cpp` dòng 24–29; `g_TraSach.cpp` dòng 29–34

**Hỏi:** Em chặn ngày mượn và ngày trả ở tương lai, nhưng vẫn cho nhập ngày trong quá khứ. Vì sao chặn một chiều? Không chặn tương lai thì cuốn sách gặp chuyện gì?

**Gợi ý trả lời:** Cho nhập ngày quá khứ để thủ thư ghi bù giao dịch của hôm trước. Ngày tương lai thì chắc chắn là gõ nhầm, và hậu quả nặng: mượn ghi ngày 20/12 thì hôm nay độc giả mang trả sẽ bị từ chối vì ngày trả trước ngày mượn, cuốn sách kẹt đến 20/12. Ngày trả ở tương lai cũng làm cuốn sách "đã trả" trước khi về kệ. Cái giá: chương trình tin đồng hồ máy; đồng hồ sai thì các kiểm tra này sai theo.

### MT05 · Bẫy
`f_MuonSach.cpp` dòng 55–72

**Hỏi:** An trả cuốn X ngày 15/11. Ngay sau đó Bình mượn X nhưng nhập ngày mượn 10/11. Có được không? Vì sao chương trình không phát hiện hai người giữ cùng một cuốn trong cùng khoảng ngày?

**Gợi ý trả lời:** Được. Chương trình chỉ xem trạng thái hiện tại của cuốn. Lịch sử nằm theo từng độc giả, cuốn sách không biết ai đã mượn nó, nên muốn kiểm chồng ngày phải duyệt lịch sử của mọi độc giả. Hệ quả: lịch sử có thể vô lý dù từng thao tác đều "hợp lệ".

### MT06 · Thuật toán
`1.4_MuonTra_DSLKDon.cpp` dòng 60–85

**Hỏi:** Mượn ngày 01/11. Đến ngày 07/11 và ngày 08/11 (theo đồng hồ máy) xin mượn thêm thì sao? Ngày 08 quá hạn mấy ngày? Nếu thầy nói "ngày thứ 8 vẫn còn hạn" thì sửa đâu?

**Gợi ý trả lời:** Ngày 07: khoảng cách 6, được mượn. Ngày 08: khoảng cách 7, bị chặn và tính là quá hạn 1 ngày (công thức k − 7 + 1). Nếu thầy hiểu khác thì đổi `>=` thành `>` ở dòng 64, đồng thời sửa điều kiện và công thức ở dòng 77–79. Phải sửa cả hai chỗ cùng lúc.

### MT07 · Vì sao thêm
`1.4_MuonTra_DSLKDon.cpp` dòng 60–85

**Hỏi:** Em có hai hàm cùng liên quan quá hạn: `CoSachQuaHan7Ngay` trả có/không, `SoNgayQuaHan` trả số ngày. Vì sao cần cả hai, mỗi hàm dùng ở chức năng nào? Có hai hàm thì phải giữ điều gì cho khớp?

**Gợi ý trả lời:** Hàm thứ nhất dùng cho f: chỉ cần biết có cuốn nào quá hạn để chặn mượn, gặp cuốn đầu tiên là dừng. Hàm thứ hai dùng cho bảng h và danh sách i: cần con số để hiển thị và sắp xếp. Cả hai phải dùng chung một mốc `HAN_MUON` (dòng 64 và dòng 77); nếu hai mốc lệch nhau thì có người bị chặn mượn mà không nằm trong danh sách quá hạn. Hiện hai hàm đang khớp: khoảng cách từ 7 trở lên là quá hạn.

### MT08 · Thuật toán
`1.4_MuonTra_DSLKDon.cpp` dòng 11–26, `them_lich_su`

**Hỏi:** Thêm vào cuối danh sách phải duyệt hết lịch sử. Sao không thêm vào đầu cho O(1)?

**Gợi ý trả lời:** Thêm cuối giữ lịch sử theo thứ tự thời gian, in và ghi file không cần đảo. Nếu thêm đầu ở cả lúc mượn lẫn lúc đọc file thì mỗi lần lưu rồi mở lại thứ tự bị đảo ngược. Chi phí duyệt không đáng kể vì `MuonSach` vốn đã duyệt lịch sử để đếm và kiểm quá hạn.

### MT09 · Thuật toán
`f_MuonSach.cpp` dòng 35, 42, 70

**Hỏi:** Một độc giả lâu năm có 5000 lượt đã trả, đang giữ 1 cuốn. Một lần mượn duyệt lịch sử của người này mấy lần? Giới hạn 3 cuốn có giúp gì không?

**Gợi ý trả lời:** Ba lần trong `MuonSach` (đếm đang mượn, kiểm quá hạn, tìm đuôi để nối), cộng thêm các lần vẽ bảng. Mỗi lần 5000 bước, vẫn tức thì. Giới hạn 3 cuốn chỉ giới hạn số lượt đang mở, không giới hạn độ dài lịch sử.

### MT10 · Thuật toán
`1.4_MuonTra_DSLKDon.cpp` dòng 45–55

**Hỏi:** `TimMuonDangMuonTheoMa` so hai điều kiện: đúng mã sách và trạng thái đang mượn. Mã sách là duy nhất, sao còn phải so trạng thái? Lấy lịch sử của An (thẻ 4) trong file mẫu để giải thích.

**Gợi ý trả lời:** Mã sách duy nhất trong kho, nhưng trong lịch sử của một người thì không: cùng một cuốn có thể được mượn nhiều lần. An có hai lượt cùng mã `9786040000001#1`: lượt đã trả ngày 05/09 đứng trước, lượt đang mượn từ 20/10 đứng sau. Hàm duyệt từ đầu danh sách, nên phải có điều kiện trạng thái mới bỏ qua được lượt cũ và dừng đúng ở lượt đang mượn.

### MT11 · Thuật toán
`g_TraSach.cpp` dòng 23, 46, 53

**Hỏi:** `TraSach` đã tìm được con trỏ `luot` ở dòng 13, sao lại gọi `CapNhatLuotTra` để tìm lần nữa?

**Gợi ý trả lời:** Đúng là tìm hai lần. Có thể gán thẳng `luot->ngayTra` và `luot->trangThai`. Nhóm giữ `CapNhatLuotTra` vì đó là hàm đã viết và kiểm từ trước; lần tìm thứ hai chỉ tốn thêm một lượt duyệt lịch sử.

### MT12 · Bẫy
`f_MuonSach.cpp` dòng 35–46

**Hỏi:** Hôm nay 15/11. Độc giả giữ X từ 01/11, Y và Z từ 12/11. Người này trả Y rồi xin mượn W. Được không? Nếu trả X thay vì Y thì sao? Thẻ đang bị khóa có trả sách được không?

**Gợi ý trả lời:** Trả Y xong còn 2 cuốn, qua được điều kiện "đủ 3 cuốn", nhưng X vẫn quá hạn nên vẫn bị chặn ở dòng 33. Trả X thì còn 2 cuốn chưa quá hạn, mượn W được. Hai điều kiện độc lập: giảm số cuốn không làm hết quá hạn. Thẻ khóa vẫn trả được vì `TraSach` không kiểm trạng thái thẻ; khóa là cấm mượn thêm chứ không cấm trả.

### MT13 · Thuật toán
`g_TraSach.cpp` dòng 44–50

**Hỏi:** Độc giả giữ X và Y, báo mất X. Những gì thay đổi? Sau đó trả Y được không, mượn Z được không?

**Gợi ý trả lời:** Ba thay đổi: lượt mượn X chuyển trạng thái 2 và ghi ngày báo mất; cuốn X chuyển "đã thanh lý"; thẻ bị khóa. Y vẫn đang mượn và trả được bình thường. Mượn Z bị chặn vì thẻ khóa. Cả ba điều là giả định của nhóm, đề chỉ định nghĩa trạng thái 2.

### MT14 · Bẫy
`g_TraSach.cpp` dòng 44–50; `c_NhapSach.cpp` dòng 175–200

**Hỏi:** Hôm sau độc giả tìm lại được cuốn đã báo mất và mang đến. Chương trình xử lý được không?

**Gợi ý trả lời:** Không có chức năng khôi phục: cuốn đã "thanh lý" không quay lại "cho mượn được", lượt mượn vẫn ghi là mất. Cách làm hiện tại: nhập cuốn đó như cuốn mới (mã N+1) và mở khóa thẻ bằng hiệu chỉnh; lịch sử vẫn ghi mất. Muốn đúng phải thêm thao tác đổi cuốn 2 về 0 và lượt 2 về 1.

### MT15 · Bẫy
`g_TraSach.cpp` dòng 23–39; `f_MuonSach.cpp` dòng 66–72

**Hỏi:** Người dùng xác nhận báo mất nhưng nhập ngày báo mất trước ngày mượn. Thẻ có bị khóa không? Có khi nào dữ liệu bị đổi nửa chừng?

**Gợi ý trả lời:** Không. `TraSach` kiểm xong mọi điều kiện rồi mới sửa; trường hợp này trả `false` ở dòng 25–29 trước khi đổi bất cứ gì. `MuonSach` cũng vậy: sau các kiểm tra, hai bước "thêm lượt" và "đổi trạng thái cuốn" đi liền nhau, không có đường thoát ở giữa.

### MT16 · Thuật toán
`g_TraSach.cpp` dòng 63–78, 132

**Hỏi:** Người dùng chọn cuốn bằng phím mũi tên. Biến `chon` được đổi thành mã sách thế nào? Sau khi trả xong sao phải gán `chon = 0`?

**Gợi ý trả lời:** `MaSachDangMuonThu` duyệt lại lịch sử, đếm các lượt đang mượn đến lượt thứ `chon`. Không cần mảng tạm vì tối đa chỉ 3 lượt mở. Sau khi trả, số cuốn giảm; nếu giữ `chon` cũ thì có thể trỏ ra ngoài danh sách và nhận về mã rỗng.

### MT17 · Bẫy
`0.4_LuuDocFile.cpp` dòng 102–111, 146–155

**Hỏi:** File dữ liệu bị sửa tay: một cuốn ghi trạng thái 1 (đang mượn) nhưng không độc giả nào có lượt đang mượn cuốn đó. Chương trình có phát hiện không? Cuốn sách đó rồi sẽ ra sao?

**Gợi ý trả lời:** Không phát hiện: đọc file chỉ kiểm định dạng từng dòng, không đối chiếu sách với lịch sử. Cuốn đó kẹt vĩnh viễn: không mượn được (đã có người mượn), không trả được (không ai giữ), không thanh lý được (đang mượn). Cần kiểm chéo lúc đọc file.

### MT18 · Thuật toán
`0.1_HamTienIch.cpp` dòng 238–263, `Doirangay`

**Hỏi:** Hàm đổi ngày ra số ngày bằng cách cộng từng năm từ năm 1. Một lần gọi tốn bao nhiêu vòng lặp? Có công thức không cần vòng lặp không? Vì sao trả `long long`?

**Gợi ý trả lời:** Khoảng 2026 vòng cho phần năm, cộng tối đa 11 vòng cho tháng. Công thức thay thế: 365·(y−1) + (y−1)/4 − (y−1)/100 + (y−1)/400. Kết quả chỉ khoảng 740 nghìn nên `int` cũng đủ; `long long` là để an toàn, không bắt buộc. Cách cộng dần dễ hiểu và dễ kiểm hơn.

### MT19 · Thuật toán
`0.1_HamTienIch.cpp` dòng 204–227

**Hỏi:** Mượn ngày 25/02/2028. Ngày nào bắt đầu quá hạn? Năm 2100 có nhuận không, code xử lý đúng không?

**Gợi ý trả lời:** 2028 nhuận nên tháng 2 có 29 ngày. Khoảng cách 7 rơi vào 03/03/2028, đó là ngày quá hạn đầu tiên. Năm 2100 chia hết cho 100 nhưng không chia hết cho 400 nên không nhuận; `NamNhuan` (dòng 204) xử lý đúng.

### MT20 · Vì sao thêm
`f_MuonSach.cpp` dòng 143–153

**Hỏi:** Ô ngày mượn hiện sẵn ngày hôm nay và giữ lại ngày vừa nhập cho cuốn tiếp theo của cùng độc giả; đổi sang độc giả khác thì về lại hôm nay. Vì sao em cho nhập ngày mà không lấy thẳng ngày máy? Giữ lại ngày vừa nhập có rủi ro gì?

**Gợi ý trả lời:** Cho nhập để ghi bù giao dịch hôm trước (thư viện ghi sổ tay rồi nhập sau). `ngayMuon` khai báo ngoài vòng mượn liên tiếp nên giữ giá trị, đỡ gõ lại khi một người mượn nhiều cuốn cùng ngày; vòng ngoài gán lại `HomNay()` khi đổi độc giả. Rủi ro: thủ thư ghi bù một cuốn ngày cũ rồi quên sửa, cuốn kế tiếp cũng mang ngày cũ. Ngày lùi không còn lách được quá hạn (MT03) nhưng vẫn làm sai lịch sử.

### MT21 · Thuật toán
`f_MuonSach.cpp` dòng 19–74, 131–167

**Hỏi:** Thủ thư vào "Mượn sách", gõ mã thẻ 6, gõ mã `9786040000004#1`, Enter hai lần và thấy thông báo thành công. Kể theo thứ tự các hàm được gọi từ lúc gõ mã thẻ tới lúc file được ghi, và mỗi hàm đụng vào cấu trúc dữ liệu nào.

**Gợi ý trả lời:** `NhapMaTheTimDocGia` gọi `tim_cay`: đi trên cây AVL. `InSachDangMuon`: duyệt danh sách mượn trả của thẻ 6, mỗi lượt đang mượn gọi `TimCuonSachToanCuc` để lấy tên sách. `MuonSach`: lấy ngày máy; `Dem_so_sach_dang_muon` và `CoSachQuaHan7Ngay` mỗi hàm duyệt danh sách mượn trả một lượt; `TimCuonSachToanCuc` tách ISBN, tìm tuyến tính trong mảng đầu sách, rồi duyệt danh sách cuốn của đầu sách đó; `them_lich_su` nối một nút vào cuối danh sách mượn trả; cuối cùng đổi trạng thái cuốn thành 1. `LuuSauThayDoi` gọi `LuuFile`: duyệt cả mảng, mọi danh sách cuốn, cả cây theo thứ tự trước và mọi danh sách mượn trả. Một lần mượn đi qua đủ bốn cấu trúc của đề.

### MT22 · Bẫy
`f_MuonSach.cpp` dòng 55–72; `j_Top10Sach.cpp` dòng 39–47

**Hỏi:** Một độc giả mượn một cuốn, trả ngay, rồi mượn lại và trả lại, làm năm lần trong cùng một ngày. Chương trình có chặn không? Lịch sử và Top 10 thay đổi thế nào? Có phân biệt được năm lượt đó với một lỗi ghi trùng không?

**Gợi ý trả lời:** Không chặn: sau mỗi lần trả cuốn sách về trạng thái "cho mượn được" và độc giả không vi phạm điều kiện nào. Lịch sử có năm nút giống hệt nhau (cùng mã sách, cùng ngày mượn, ngày trả, trạng thái), Top 10 của đầu sách đó tăng 5. Dữ liệu chỉ lưu ngày, không lưu giờ hay số thứ tự giao dịch, nên không phân biệt được năm lượt thật với năm dòng trùng. Nếu thầy hỏi cách hạn chế: quy ước mỗi cuốn một người chỉ tính một lượt mỗi ngày trong Top 10, hoặc không cho mượn lại cùng cuốn trong ngày đã trả.

---

## D. Đầu sách, cuốn sách, mã sách (Thái)

### DS01 · Thuật toán
`1.2_DauSach_MangConTro.cpp` dòng 100–124, `ThemDauSach`

**Hỏi:** Kho mẫu có 6 đầu sách theo tên: Cau truc du lieu va giai thuat, Co so du lieu, Giai tich 1, Lap trinh C++, Toan roi rac, Vat ly dai cuong. Thêm "Dai so". Nó vào vị trí nào, dịch mấy phần tử, dịch cái gì? Vì sao đề chọn mảng con trỏ?

**Gợi ý trả lời:** Vào vị trí 2 (sau "Co so du lieu"). Dịch 4 con trỏ ở vị trí 2 đến 5 sang phải một ô. Chỉ dịch con trỏ, mỗi cái vài byte, chứ không chép cả struct có bốn chuỗi. Địa chỉ của từng `DauSach` không đổi, nên con trỏ nào đang giữ một đầu sách vẫn dùng được sau khi chèn.

### DS02 · Vì sao thêm
`1.2_DauSach_MangConTro.cpp` dòng 119–121

**Hỏi:** Trong `ThemDauSach` em `new DauSach`, chép `d` vào rồi gán `dms = nullptr`. Vì sao không lưu luôn địa chỉ của `d` vào mảng? Vì sao phải ép `dms` về rỗng? Cách này ảnh hưởng gì tới nơi gọi?

**Gợi ý trả lời:** `d` là biến của nơi gọi (biến cục bộ ở màn hình nhập hoặc lúc đọc file), ra khỏi hàm đó là mất, nên kho phải giữ một bản riêng cấp phát động. Gán cả struct sẽ chép luôn con trỏ `dms`; ép về rỗng để đầu sách mới không dùng chung danh mục cuốn với bản gốc. Ảnh hưởng: nơi gọi không có địa chỉ của bản trong kho, muốn thêm cuốn phải gọi `TimDauSachTheoISBN` tìm lại (c_NhapSach.cpp dòng 136, 0.4_LuuDocFile.cpp dòng 101).

### DS03 · Thuật toán
`1.2_DauSach_MangConTro.cpp` dòng 83–96, `TimViTriChenTheoTen`

**Hỏi:** Chạy tay tìm vị trí chèn cho một sách mới cũng tên "Toan roi rac" (ISBN khác) vào kho 6 đầu sách. Nó đứng trước hay sau bản cũ? Có được trùng tên không? Vì sao `r` bắt đầu bằng `soLuong` chứ không phải `soLuong − 1`?

**Gợi ý trả lời:** l=0, r=6: m=3 nhỏ hơn nên l=4; m=5 không nhỏ hơn nên r=5; m=4 bằng nhau nên r=4. Kết quả 4, tức là chèn **trước** bản cũ. Trùng tên được phép, chỉ ISBN phải duy nhất. `r = soLuong` vì vị trí chèn có thể là ngay sau phần tử cuối; ô đó không bao giờ bị đọc vì `m` luôn nhỏ hơn `r`.

### DS04 · Thuật toán
`1.2_DauSach_MangConTro.cpp` dòng 109, 115–117

**Hỏi:** Tìm vị trí chèn bằng nhị phân là O(log D). Vậy thêm một đầu sách có phải O(log D) không?

**Gợi ý trả lời:** Không, vẫn O(D) vì hai việc: kiểm trùng ISBN phải tìm tuyến tính (mảng sắp theo tên, không theo ISBN), và dịch mảng. Nhị phân chỉ giảm số lần so sánh chuỗi tên.

### DS05 · Thuật toán
`1.3_DanhMucSach_DSLKDon.cpp` dòng 31–66; `1.2_DauSach_MangConTro.cpp` dòng 62–70

**Hỏi:** Đề yêu cầu đánh mã sách sao cho tìm theo mã nhanh nhất. Tìm `9786040000003#2` đi qua những bước nào, tốn bao nhiêu? Bước tìm ISBN vẫn tuyến tính, vậy đã nhanh nhất chưa?

**Gợi ý trả lời:** Ba bước: tách ISBN trước dấu `#`; tìm đầu sách theo ISBN, tuyến tính O(D); duyệt danh mục của riêng đầu sách đó O(c). Nếu mã không chứa ISBN (kiểu S001) thì phải duyệt toàn bộ cuốn của mọi đầu sách, O(C). Muốn nhanh hơn nữa cần một mảng phụ sắp theo ISBN để tìm nhị phân, tức là thêm cấu trúc ngoài đề. Trả lời trung thực: đây là cách nhanh nhất trong phạm vi bốn cấu trúc đề cho.

### DS06 · Thuật toán
`1.3_DanhMucSach_DSLKDon.cpp` dòng 71–92, `SinhMaSachTuDong`

**Hỏi:** Mã mới lấy số của nút cuối cộng 1, không lấy số nút cộng 1. Hai cách hiện có cho kết quả khác nhau không? Khi nào thì khác?

**Gợi ý trả lời:** Hiện giống nhau, vì thanh lý và báo mất chỉ đổi trạng thái, không xóa nút. Dòng thông báo ở c_NhapSach.cpp 170–171 còn dùng số nút làm "mã mới nhất", dựa vào đúng điều đó. Nếu sau này cho xóa nút thì đếm nút sẽ cấp trùng mã cũ, còn lấy số nút cuối vẫn đúng miễn là nút cuối mang số lớn nhất.

### DS07 · Bẫy
`1.3_DanhMucSach_DSLKDon.cpp` dòng 74–89; `0.4_LuuDocFile.cpp` dòng 102–111

**Hỏi:** File bị sửa tay, danh mục của một đầu sách ghi theo thứ tự `#3`, `#1`, `#2`. Mở chương trình, thêm một cuốn mới. Mã mới là gì?

**Gợi ý trả lời:** Nút cuối là `#2` nên mã mới là `#3`, trùng với cuốn đã có. Đọc file chỉ kiểm phần ISBN trước dấu `#` (dòng 108), không kiểm trùng mã trong danh mục. Sau đó tìm `#3` luôn trả cuốn đầu tiên, cuốn mới không bao giờ mượn được. Sửa: khi sinh mã, duyệt cả danh mục lấy số lớn nhất.

### DS08 · Thuật toán
`c_NhapSach.cpp` dòng 39–40; `1.3_DanhMucSach_DSLKDon.cpp` dòng 96–118

**Hỏi:** Nhập 500 cuốn cho một đầu sách đang có 500 cuốn. Mỗi cuốn mới phải duyệt danh mục mấy lần? Tổng chi phí? Giảm thế nào mà không thêm trường?

**Gợi ý trả lời:** Hai lần mỗi cuốn: một lần sinh mã (đi tới nút cuối), một lần nối đuôi. Tổng khoảng k·(c + k), ở đây vài trăm nghìn bước, vẫn nhanh. Giảm: giữ con trỏ đuôi và số cuối trong biến tạm của hàm nhập, không cần thêm trường vào struct.

### DS09 · Bẫy
`c_NhapSach.cpp` dòng 129–143

**Hỏi:** Thủ thư nhập xong sáu ô của đầu sách, đến ô "số cuốn" thì nhấn Esc. Đầu sách có được lưu không? So với nhấn Esc ở ô "thể loại".

**Gợi ý trả lời:** Có lưu: `ThemDauSach` đã chạy ở dòng 253, trước khi hỏi số cuốn. Kết quả là đầu sách không có cuốn nào và thông báo ghi rõ điều đó; có thể thêm cuốn sau ở mục 2. Esc ở ô thể loại thì chưa gọi `ThemDauSach` nên không có gì được thêm.

### DS10 · Bẫy
`c_NhapSach.cpp` dòng 202–218

**Hỏi:** Thủ thư gõ nhầm tên sách và đã lưu. Sửa thế nào? Nếu thầy yêu cầu thêm chức năng sửa tên thì có gán thẳng `tenSach` được không?

**Gợi ý trả lời:** Hiện không có sửa hay xóa đầu sách, đề chỉ yêu cầu nhập. Nếu thêm sửa tên thì không được gán thẳng, vì mảng phải luôn tăng theo tên. Phải rút con trỏ khỏi vị trí cũ, dồn mảng, tìm vị trí mới bằng nhị phân rồi chèn lại. ISBN, các cuốn và lịch sử không bị ảnh hưởng vì lịch sử tham chiếu mã sách chứ không tham chiếu tên.

### DS11 · Vì sao thêm
`c_NhapSach.cpp` dòng 175–200

**Hỏi:** Thanh lý sách sao chỉ đổi trạng thái mà không xóa nút khỏi danh sách liên kết? Sao không thanh lý được cuốn đang được mượn?

**Gợi ý trả lời:** Lịch sử mượn và Top 10 tham chiếu mã sách; xóa nút thì các màn hình h, i sẽ hiện "(không rõ đầu sách)" và việc sinh mã có thể cấp lại số cũ. Đề cũng đã cho sẵn trạng thái 2 cho việc này. Cuốn đang mượn phải được trả hoặc báo mất trước, nếu không lượt mượn sẽ tham chiếu một cuốn đã thanh lý mà vẫn "đang mượn".

### DS12 · Bẫy
`c_NhapSach.cpp` dòng 183–186; `f_MuonSach.cpp` dòng 157

**Hỏi:** Cùng gõ mã sách có một dấu cách thừa ở đầu. Màn hình mượn và màn hình thanh lý xử lý có giống nhau không?

**Gợi ý trả lời:** Không. Mượn có gọi `ChuanHoaChuoiSach` để bỏ khoảng trắng thừa, nên tìm thấy. Thanh lý dùng nguyên chuỗi vừa gõ nên báo không tìm thấy. Đây là điểm không nhất quán, sửa bằng một dòng chuẩn hóa.

### DS13 · Bẫy
`0.1_HamTienIch.cpp` dòng 75–87; `1.2_DauSach_MangConTro.cpp` dòng 83–96

**Hỏi:** Kho có "Toan 9", thủ thư thêm "Toan 10" và "Toan 11". Ba cuốn nằm theo thứ tự nào trong mảng và trên các bảng in? Sách tên "100 bai tap C" đứng ở đâu so với "An toan thong tin"?

**Gợi ý trả lời:** Thứ tự là "Toan 10", "Toan 11", "Toan 9". `SoSanhChuoi` so từng ký tự theo mã ASCII, ký tự '1' nhỏ hơn '9' nên "Toan 10" đứng trước "Toan 9". Chữ số có mã nhỏ hơn chữ cái nên "100 bai tap C" đứng trước mọi tên bắt đầu bằng chữ. Đây vẫn là "tăng dần theo tên" theo nghĩa so chuỗi, nhưng khác thứ tự người dùng mong đợi; muốn đúng kiểu người đọc phải so phần số như số.

### DS14 · Bẫy
`1.2_DauSach_MangConTro.cpp` dòng 15–28; `c_NhapSach.cpp` dòng 63–77

**Hỏi:** Thư viện có sách cũ dùng ISBN 10 số, luận văn không có ISBN, và có ISBN kết thúc bằng chữ X. Nhập được không? Gõ nhầm một chữ số ISBN thì chương trình có biết không?

**Gợi ý trả lời:** Không nhập được: bắt buộc đúng 13 chữ số. Phải tự đặt mã nội bộ 13 số cho các tài liệu đó. Chương trình bỏ dấu gạch và khoảng trắng nhưng không kiểm chữ số kiểm tra của ISBN, nên gõ nhầm một số vẫn được nhận như một ISBN khác.

### DS15 · Bẫy
`1.3_DanhMucSach_DSLKDon.cpp` dòng 13–28; `c_NhapSach.cpp` dòng 17–41

**Hỏi:** Nhập 20 cuốn một lần thì vị trí của chúng thế nào? Sau này chuyển một cuốn sang kệ khác thì sửa ở đâu?

**Gợi ý trả lời:** Cả 20 cuốn nhận cùng một vị trí vừa nhập. Không có chức năng sửa vị trí. Muốn các cuốn ở kệ khác nhau thì phải nhập thành nhiều lần. Sửa vị trí sau này thì dễ thêm: tìm cuốn theo mã rồi gán lại `viTri`, không ảnh hưởng thứ tự nào.

### DS16 · Thuật toán
`1.2_DauSach_MangConTro.cpp` dòng 127–141; `main.cpp` dòng 31–32

**Hỏi:** Khi thoát, chương trình hủy kho sách trước rồi mới hủy cây độc giả. Đổi thứ tự có sao không? Điều gì trong thiết kế khiến hai phần này độc lập?

**Gợi ý trả lời:** Đổi thứ tự không sao. Lượt mượn chỉ giữ mã sách dạng chuỗi, không giữ con trỏ tới cuốn sách, nên hủy lịch sử không cần đụng tới kho sách. Nếu `MuonTra` giữ con trỏ `CuonSach*` thì tra tên nhanh hơn, nhưng không ghi được vào file và phải cẩn thận thứ tự hủy.

### DS17 · Bẫy
`0.0_KhaiBaoChung.h` dòng 66–70; `1.2_DauSach_MangConTro.cpp` dòng 127–141

**Hỏi:** Struct `DanhSachDauSach` có mảng 10000 con trỏ, nhưng chỉ `soLuong = 0` được khởi tạo. 10000 ô con trỏ lúc đầu chứa gì? Vì sao chương trình không sập, và điều gì trong code bảo đảm không bao giờ đọc ô chưa dùng?

**Gợi ý trả lời:** Các ô chưa được gán chứa giá trị không xác định, không phải rỗng. Chương trình không bao giờ đọc chúng vì mọi vòng lặp trên mảng đều chạy từ 0 tới `soLuong − 1`: tìm ISBN, tìm vị trí chèn (cận phải là `soLuong`), in, lưu file, hủy. Khi chèn, ô `soLuong` chỉ được ghi vào rồi `soLuong` mới tăng. Vậy bất biến cần giữ là: các ô từ 0 tới `soLuong − 1` luôn hợp lệ, phần còn lại không ai đụng. Gán rỗng cho cả 10000 ô lúc tạo cũng được nhưng không cần.

### DS18 · Bẫy
`1.2_DauSach_MangConTro.cpp` dòng 83–96; `e_TimSach.cpp` dòng 79–83

**Hỏi:** Đề bắt mảng đầu sách luôn tăng dần theo tên, và em tốn công chèn đúng chỗ. Nhưng chức năng tìm theo tên của em vẫn duyệt từ đầu tới cuối. Vậy sắp theo tên được lợi gì trong chương trình này? Chức năng nào thật sự dựa vào thứ tự đó?

**Gợi ý trả lời:** Tìm kiểu "tên có chứa từ khóa" không dùng được thứ tự, nên phải duyệt hết. Thứ tự tên được dùng ở ba chỗ. Tìm vị trí chèn bằng nhị phân. Chức năng d: mảng tạm chép từ mảng gốc đã theo tên, sắp xếp chèn ổn định theo thể loại là xong, không phải so tên. Trang Tổng quan và mọi chỗ in danh mục đều ra thứ tự tên mà không phải sắp. Nếu thầy yêu cầu tìm đúng nguyên tên hoặc tên bắt đầu bằng một cụm thì dùng được nhị phân ngay trên mảng này. Trả lời thẳng: thứ tự tên phục vụ việc in và chèn, không phục vụ tìm chuỗi con.

---

## E. Tìm sách, quá hạn, Top 10 (Thái)

### TK01 · Thuật toán
`e_TimSach.cpp` dòng 78–83

**Hỏi:** Mảng đầu sách đã sắp theo tên. Sao tìm theo tên lại duyệt tuần tự mà không tìm nhị phân?

**Gợi ý trả lời:** Vì đây là tìm "tên có chứa từ khóa". Các tên chứa một từ khóa không nằm liền nhau trong thứ tự chữ cái: tìm "c" trên kho mẫu khớp cả sáu đầu sách, tìm "toan" chỉ khớp "Toan roi rac". Nhị phân chỉ dùng được khi tìm đúng nguyên tên hoặc theo phần đầu của tên.

### TK02 · Thuật toán
`0.1_HamTienIch.cpp` dòng 91–112, `ChuaChuoi`

**Hỏi:** Thuật toán tìm chuỗi con em dùng là gì, độ phức tạp bao nhiêu? Cho một ví dụ xấu nhất.

**Gợi ý trả lời:** Thử từng vị trí bắt đầu, so từng ký tự: O(n·m) với n là độ dài tên, m là độ dài từ khóa. Xấu nhất: tên "aaaaaaab", từ khóa "aaac", vị trí nào cũng so gần hết từ khóa rồi mới sai. Tên sách tối đa 100 ký tự nên không cần thuật toán phức tạp hơn.

### TK03 · Thuật toán
`0.1_HamTienIch.cpp` dòng 93–95

**Hỏi:** Trước vòng lặp, `ChuaChuoi` có hai dòng trả kết quả sớm: từ khóa rỗng thì trả `true`, tên ngắn hơn từ khóa thì trả `false`. Vì sao cần hai dòng này trong khi vòng lặp phía dưới cũng tự xử lý được? Cận trên của `i` là gì và vì sao?

**Gợi ý trả lời:** Cận trên là `s.size() − part.size()`, vị trí bắt đầu cuối cùng mà từ khóa còn nằm trọn trong tên. `size()` là số không dấu: nếu tên ngắn hơn từ khóa thì phép trừ không ra số âm mà ra số rất lớn, nên phải chặn trước ở dòng 92. Từ khóa rỗng coi như luôn khớp; màn hình tìm sách đã chặn từ khóa rỗng từ trước (e_TimSach.cpp dòng 70) nên nhánh này chỉ là phòng hờ.

### TK04 · Bẫy
`0.1_HamTienIch.cpp` dòng 115–133

**Hỏi:** Thủ thư muốn nhập tên sách "Lập trình C++" có dấu, và phái "Nữ" đúng như đề ghi. Được không? Vì sao?

**Gợi ý trả lời:** Không. `HopLeVanBan` từ chối mọi byte từ 127 trở lên, tức là mọi chữ có dấu. Phái phải gõ "Nu". Lý do: console Windows đọc phím có dấu qua `_getch` rất phức tạp, một chữ có dấu chiếm nhiều byte nên cắt cột và so sánh đều sai. Đây là giới hạn đã biết: toàn bộ dữ liệu nhập không dấu. Nên nói trước với thầy.

### TK05 · Bẫy
`e_TimSach.cpp` dòng 32–55, 79–83

**Hỏi:** Độc giả tìm "Cau truc", thấy đầu sách hiện ra với ba mã sách. Vậy có mượn được không? Kết quả tìm có lọc bỏ cuốn đã thanh lý hay đầu sách chưa có cuốn nào không?

**Gợi ý trả lời:** Chưa chắc mượn được. Với dữ liệu mẫu, đầu sách này có hai cuốn đang được mượn và một cuốn đã thanh lý, tức là không còn cuốn nào. Tìm kiếm khớp theo tên đầu sách và in mọi cuốn kèm trạng thái, đúng như đề yêu cầu ở mục e; nó không lọc theo khả năng mượn, đầu sách 0 cuốn vẫn hiện. Việc được mượn hay không chỉ `MuonSach` quyết định tại thời điểm mượn.

### QH01 · Thuật toán
`i_DocGiaQuaHan.cpp` dòng 18–73

**Hỏi:** Mô tả ba bước của chức năng i. Với dữ liệu mẫu, hôm nay 15/11/2026, danh sách in ra gồm những ai, theo thứ tự nào? Sao dùng hai mảng `dg[]` và `luot[]` chứ không dùng một mảng struct?

**Gợi ý trả lời:** Bước 1 lấy con trỏ các nút ra mảng; bước 2 gom các lượt đang mượn đã quá hạn; bước 3 sắp giảm dần bằng sắp xếp chọn. Kết quả: thẻ 4 (mượn 20/10, quá hạn 20 ngày) rồi thẻ 2 (mượn 01/11, quá hạn 8 ngày). Dùng hai mảng song song để không tạo struct mới ngoài đề; cái giá là mỗi lần đổi chỗ phải đổi cả hai mảng (dòng 59–64), quên một mảng thì tên người lệch với sách.

### QH02 · Bẫy
`i_DocGiaQuaHan.cpp` dòng 59–66; `0.1_HamTienIch.cpp` dòng 238–254

**Hỏi:** Giả sử có 1000 lượt quá hạn. Vòng sắp xếp gọi `SoNgayQuaHan` bao nhiêu lần, mỗi lần tốn gì? Cải thiện thế nào?

**Gợi ý trả lời:** Sắp xếp chọn so khoảng n²/2 = 500 nghìn lần, mỗi lần gọi `SoNgayQuaHan` hai lần, mỗi lần đó đổi hai ngày ra số, mỗi phép đổi lặp khoảng 2000 vòng. Tổng cỡ vài tỉ bước, chạy mất vài giây. Cải thiện: tính sẵn số ngày quá hạn vào một mảng tạm trước khi sắp, hoặc so thẳng ngày mượn (mượn sớm hơn là quá hạn lâu hơn).

### QH03 · Bẫy
`i_DocGiaQuaHan.cpp` dòng 59–73

**Hỏi:** Ba lượt cùng quá hạn 5 ngày của thẻ 3, thẻ 7, thẻ 9. Thứ tự in ra có theo mã thẻ không?

**Gợi ý trả lời:** Không bảo đảm. Sắp xếp chọn không ổn định: phép đổi chỗ có thể đẩy một phần tử ra sau các phần tử bằng nó. Kết quả vẫn cố định với cùng dữ liệu, nhưng không theo quy tắc nào giải thích được. Muốn rõ ràng thì thêm khóa phụ: cùng số ngày thì mã thẻ nhỏ đứng trước.

### QH04 · Bẫy
`i_DocGiaQuaHan.cpp` dòng 29–55

**Hỏi:** Đề ghi "in danh sách độc giả mượn sách quá hạn". Một người giữ hai cuốn quá hạn thì hiện mấy dòng? Có đúng đề không?

**Gợi ý trả lời:** Hai dòng, mỗi cuốn một dòng. Đây là giả định của nhóm: thủ thư cần biết đòi cuốn nào. Nếu thầy muốn mỗi độc giả một dòng thì lấy số ngày quá hạn lớn nhất của từng người rồi sắp theo số đó.

### QH05 · Bẫy
`i_DocGiaQuaHan.cpp` dòng 34, 48

**Hỏi:** Độc giả đang bị khóa thẻ mà còn giữ sách quá hạn có hiện trong danh sách không? Cuốn đã báo mất có hiện không?

**Gợi ý trả lời:** Người bị khóa vẫn hiện, vì danh sách không lọc theo trạng thái thẻ, và đúng là vẫn phải đòi sách. Cuốn đã báo mất không hiện, vì lượt đó có trạng thái 2, danh sách chỉ lấy lượt trạng thái "đang mượn".

### QH06 · Bẫy
`i_DocGiaQuaHan.cpp` dòng 20; `f_MuonSach.cpp` dòng 24

**Hỏi:** Chức năng i, bảng h và kiểm tra quá hạn khi mượn đều lấy ngày từ đồng hồ máy. Đồng hồ máy bị đặt lùi một tháng thì ba chỗ đó ra sao? Vì sao em vẫn chọn tin đồng hồ máy?

**Gợi ý trả lời:** Danh sách quá hạn trống hoặc thiếu, bảng h không tô đỏ, và người đang quá hạn mượn tiếp được. Thêm nữa, mọi giao dịch ghi đúng ngày thật sẽ bị từ chối vì "sau ngày hôm nay". Nhóm vẫn chọn đồng hồ máy vì nguồn còn lại là ngày người dùng gõ, dễ sai và dễ bị lợi dụng hơn nhiều. Tiêu đề mọi màn hình có in ngày máy để thủ thư nhận ra khi đồng hồ sai.

### TOP01 · Thuật toán
`j_Top10Sach.cpp` dòng 20–65

**Hỏi:** Mô tả ba bước của Top 10 và chi phí từng bước. Với dữ liệu mẫu, kết quả là gì?

**Gợi ý trả lời:** Bước 1 tạo mảng đếm theo chỉ số đầu sách. Bước 2 duyệt mọi lượt mượn của mọi độc giả, tách ISBN, tìm vị trí đầu sách (tuyến tính) rồi tăng đếm: chi phí số lượt nhân số đầu sách. Bước 3 chọn 10 lần phần tử lớn nhất: 10 nhân số đầu sách. Kết quả mẫu: Cau truc du lieu va giai thuat 5 lượt; Lap trinh C++ 3; Toan roi rac 3; Giai tich 1 có 1. Hai đầu sách còn lại 0 lượt nên không in.

### TOP02 · Thuật toán
`j_Top10Sach.cpp` dòng 27–31, 51–65

**Hỏi:** Sao sắp xếp chọn chỉ chạy 10 vòng? Mảng `thuTu[]` để làm gì, sao không đổi chỗ trực tiếp trên mảng đầu sách?

**Gợi ý trả lời:** Chỉ cần 10 phần tử lớn nhất, nên dừng sau 10 vòng thay vì sắp cả mảng. `thuTu[]` giữ chỉ số đầu sách để đổi chỗ; mảng đầu sách gốc phải giữ nguyên thứ tự tên theo yêu cầu của đề, và `luotMuon[]` phải giữ khớp với chỉ số gốc.

### TOP03 · Bẫy
`j_Top10Sach.cpp` dòng 54–65

**Hỏi:** Ba đầu sách theo thứ tự tên A, B, C có số lượt 1, 1, 5. Top in ra theo thứ tự nào? A và B đồng hạng, ai đứng trước?

**Gợi ý trả lời:** In ra C, B, A. Ở vòng đầu, C đổi chỗ với A, đẩy A xuống cuối, nên B đứng trước A dù tên A đứng trước. Với dữ liệu mẫu, đồng hạng tình cờ vẫn theo tên. Sửa: khi so, nếu bằng số lượt thì chọn phần tử có chỉ số gốc nhỏ hơn.

### TOP04 · Bẫy
`j_Top10Sach.cpp` dòng 51–53

**Hỏi:** Có 12 đầu sách cùng 5 lượt mượn và đó là số cao nhất. Top 10 in ai, bỏ ai?

**Gợi ý trả lời:** In đúng 10 dòng, cắt cứng, hai đầu sách bị bỏ tùy theo thứ tự đổi chỗ. Đây là giả định của nhóm. Nếu thầy muốn in cả các sách đồng hạng với hạng 10 thì phải chạy tiếp vòng chọn và in thêm khi số lượt còn bằng số lượt của dòng thứ 10.

### TOP05 · Bẫy
`j_Top10Sach.cpp` dòng 39–47

**Hỏi:** "Lượt mượn" đếm những trạng thái nào? Đếm theo đầu sách hay theo cuốn? Đề ghi "10 sách", nếu thầy hiểu là 10 cuốn thì sao?

**Gợi ý trả lời:** Đếm mọi lượt: đang mượn, đã trả, làm mất, vì đều là một lần mượn. Đếm theo đầu sách (gộp theo ISBN). Nếu thầy muốn theo cuốn thì khóa đếm phải là mã sách: cần mảng đếm theo từng cuốn và cách tra mã sách ra chỉ số, tốn hơn. Nên hỏi thầy trước.

### TOP06 · Thuật toán
`j_Top10Sach.cpp` dòng 78–83

**Hỏi:** Trong vòng in, gặp đầu sách 0 lượt thì `break`. Sao dùng `break` được mà không phải `continue`?

**Gợi ý trả lời:** Sau bước chọn, các ô đầu của `thuTu[]` đã giảm dần theo số lượt. Gặp một ô bằng 0 thì mọi ô sau cũng bằng 0, nên dừng luôn.

### TOP07 · Vì sao thêm
`b_InDanhSachDocGia.cpp` dòng 28–49; `d_InDauSachTheoTheLoai.cpp` dòng 18–31; `i_DocGiaQuaHan.cpp` dòng 59–73; `j_Top10Sach.cpp` dòng 54–65

**Hỏi:** Chương trình dùng ba thuật toán sắp xếp khác nhau: Quick Sort cho b, sắp xếp chèn cho d, sắp xếp chọn cho i và j. Vì sao không viết một hàm rồi dùng cho cả bốn chỗ? Mỗi chỗ chọn thuật toán đó dựa vào đặc điểm gì của dữ liệu?

**Gợi ý trả lời:** b: số độc giả có thể rất lớn và không có thứ tự sẵn theo tên, cần thuật toán O(n log n). d: dữ liệu đã có sẵn thứ tự tên và cần giữ thứ tự đó trong từng thể loại, nên cần thuật toán ổn định; sắp xếp chèn ổn định và chạy nhanh khi dữ liệu gần đúng thứ tự. j: chỉ cần 10 phần tử lớn nhất; sắp xếp chọn tự nhiên dừng được sau 10 vòng, tốn 10·D thay vì sắp cả mảng. i: số lượt quá hạn thường nhỏ nên chọn thuật toán đơn giản nhất; đây là chỗ yếu nếu dữ liệu lớn (QH02). Nói thật với thầy: dùng ba thuật toán cũng là để nhóm trình bày được chương Sắp xếp trên chính đồ án, nhưng mỗi lựa chọn đều có lý do từ dữ liệu.

---

## F. In danh sách, giao diện (Tấn)

### IN01 · Thuật toán
`1.1_DocGia_CayAVL.cpp` dòng 468–507; `b_InDanhSachDocGia.cpp` dòng 63–66

**Hỏi:** In độc giả theo mã thẻ tăng dần dùng phép duyệt nào, vì sao ra đúng thứ tự? Sao phải đếm số nút trước rồi mới lấy danh sách, tức là duyệt cây hai lần?

**Gợi ý trả lời:** Duyệt giữa (trái, nút, phải) trên cây tìm kiếm luôn cho khóa tăng dần. Phải đếm trước để biết cấp mảng tạm bao nhiêu ô, vì không lưu sẵn số độc giả thành một trường. Hai lần duyệt đều O(n).

### IN02 · Vì sao thêm
`b_InDanhSachDocGia.cpp` dòng 63–68, 117

**Hỏi:** Để in theo tên, em cấp một mảng tạm chứa con trỏ tới các nút rồi sắp mảng đó. Vì sao không sắp trực tiếp trên cây, và vì sao mảng chứa con trỏ chứ không chứa bản sao `DocGia`? Cách này tốn gì mỗi lần mở bảng?

**Gợi ý trả lời:** Cây được tổ chức theo mã thẻ, mọi chức năng tìm thẻ dựa vào thứ tự đó, nên không được xáo dữ liệu trong cây theo tên. Mảng chỉ chứa con trỏ nên đổi chỗ khi sắp chỉ là đổi địa chỉ, không chép chuỗi họ tên; và chép cả `DocGia` còn chép luôn con trỏ lịch sử. Cái giá: mỗi lần mở bảng duyệt cây hai lần (đếm, lấy danh sách), cấp mảng n con trỏ, sắp O(n log n), rồi giải phóng ở dòng 107. Không lưu lại vì tên có thể bị hiệu chỉnh giữa hai lần xem.

### IN03 · Thuật toán
`b_InDanhSachDocGia.cpp` dòng 18–49

**Hỏi:** Với sáu độc giả mẫu, bảng theo tên + họ in ra thứ tự nào? Hai người tên An, ai trước, vì sao?

**Gợi ý trả lời:** Hoang Minh An (thẻ 5), Nguyen Van An (thẻ 4), Tran Thi Binh (2), Le Van Cuong (1), Pham Thi Dung (3), Vo Thi Hoa (6). So tên trước; hai người cùng tên An thì so họ, "Hoang Minh" đứng trước "Nguyen Van".

### IN04 · Bẫy
`b_InDanhSachDocGia.cpp` dòng 18–24, 28–49

**Hỏi:** Hai độc giả trùng cả họ lẫn tên. Thứ tự giữa họ là gì? Quick Sort có trường hợp xấu không?

**Gợi ý trả lời:** Không xác định theo mã thẻ: hàm so sánh trả 0 và Quick Sort không ổn định. Nên thêm khóa phụ là mã thẻ. Quick Sort xấu nhất O(n²) khi chốt luôn rơi vào phần tử nhỏ nhất hoặc lớn nhất; chọn chốt ở giữa giúp mảng đã sắp sẵn không rơi vào trường hợp đó, nhưng không loại hẳn được.

### IN05 · Thuật toán
`b_InDanhSachDocGia.cpp` dòng 32–37

**Hỏi:** Hai vòng `while` tăng `i`, giảm `j` không kiểm biên mảng. Có chạy ra ngoài không? Sao `chot` giữ con trỏ phần tử chứ không giữ chỉ số?

**Gợi ý trả lời:** Không ra ngoài, vì phần tử chốt nằm trong đoạn đang xét nên `i` và `j` chắc chắn dừng khi gặp nó. Giữ giá trị chốt chứ không giữ chỉ số, vì trong lúc đổi chỗ phần tử ở vị trí giữa có thể đã bị thay bằng phần tử khác.

### IN06 · Bẫy
`b_InDanhSachDocGia.cpp` dòng 18–24

**Hỏi:** Sao không ghép tên với họ thành một chuỗi rồi so một lần cho gọn?

**Gợi ý trả lời:** Sai với tên này là phần đầu của tên kia. Ví dụ "An" họ "Vu" và "Anh" họ "Le": đúng ra An đứng trước Anh. Ghép lại thành "anvu" và "anhle", ký tự thứ ba là 'v' so với 'h', nên Anh lại đứng trước. Phải so tên xong mới so họ.

### IN07 · Thuật toán
`d_InDauSachTheoTheLoai.cpp` dòng 18–31

**Hỏi:** Chức năng b em dùng Quick Sort, chức năng d em lại dùng sắp xếp chèn và chỉ so thể loại, không so tên. Vậy "trong từng thể loại in theo tên tăng dần" được bảo đảm ở đâu? Chọn sắp xếp chèn thì tốn gì?

**Gợi ý trả lời:** Mảng gốc vốn đã tăng theo tên. Sắp xếp chèn là ổn định: điều kiện ở dòng 18 chỉ dời phần tử khi thể loại lớn hơn hẳn, nên hai sách cùng thể loại giữ nguyên thứ tự cũ, tức là vẫn tăng theo tên. Quick Sort không ổn định, dùng ở đây thì phải so cả thể loại lẫn tên. Cái giá: sắp xếp chèn xấu nhất O(D²), khi thứ tự thể loại ngược với thứ tự tên; với vài nghìn đầu sách vẫn chấp nhận được.

### IN08 · Thuật toán
`d_InDauSachTheoTheLoai.cpp` dòng 35–42

**Hỏi:** Với kho mẫu, chức năng d in ra thế nào? "Tin hoc" và "tin  HOC" có vào cùng nhóm không? Khi nào sắp xếp chèn chậm nhất?

**Gợi ý trả lời:** Tin hoc: Cau truc du lieu va giai thuat, Co so du lieu, Lap trinh C++. Toan hoc: Giai tich 1, Toan roi rac. Vat ly: Vat ly dai cuong. Hai cách viết kia cùng nhóm, vì `SoSanhChuoi` bỏ khoảng trắng thừa và không phân biệt hoa thường. Chậm nhất O(D²) khi thứ tự thể loại ngược hẳn với thứ tự tên.

### IN09 · Thuật toán
`d_InDauSachTheoTheLoai.cpp` dòng 62

**Hỏi:** Tên thể loại chỉ được in ở một số dòng, theo điều kiện "là dòng đầu của trang, hoặc khác thể loại với dòng liền trước". Vì sao cần vế "dòng đầu của trang"? Vì sao em viết vế đó trước?

**Gợi ý trả lời:** Một thể loại có thể dài hơn 15 dòng và kéo sang trang sau; không có vế "đầu trang" thì trang sau không có tên thể loại, người xem không biết đang ở nhóm nào. Viết vế đó trước vì ở dòng đầu tiên của cả bảng (i = 0) không có dòng liền trước để so; khi vế đầu đã đúng thì C++ không tính vế sau, nên không đọc phần tử trước đầu mảng.

### IN10 · Thuật toán
`f_MuonSach.cpp` dòng 94–124; `h_SachDangMuon.cpp`

**Hỏi:** Lượt mượn chỉ lưu mã sách. Chức năng h lấy tên sách ở đâu, tốn bao nhiêu? Khi nào hiện "(không rõ đầu sách)"?

**Gợi ý trả lời:** Với mỗi lượt đang mượn, tách ISBN từ mã rồi tìm đầu sách trong mảng (tuyến tính). Tối đa 3 lượt mở nên tối đa 3 lần tìm, cộng một lượt duyệt cả lịch sử để lọc. Dòng "(không rõ đầu sách)" hiện khi mã sách trong lịch sử không khớp ISBN nào trong kho, chỉ xảy ra khi file bị sửa tay.

### IN11 · Vì sao thêm
`0.2_GiaoDien.cpp` dòng 104–110; `0.0_KhaiBaoChung.h` dòng 110–116

**Hỏi:** `DocPhim` trả mã phím mũi tên là 256 cộng mã phím, nên các hằng `PHIM_LEN`, `PHIM_PHAI` đều lớn hơn 256. Vì sao em làm vậy thay vì trả thẳng mã phím? Chỉ một màn hình trong chương trình mà nếu không làm vậy sẽ lẫn phím.

**Gợi ý trả lời:** `_getch` trả phím mũi tên thành hai lần đọc: 0 hoặc 224, rồi mã phím. Mã thứ hai trùng với chữ cái thường: mũi tên phải là 77, bằng chữ 'M'; mũi tên lên là 72, bằng 'H'. Cộng 256 đưa phím mũi tên ra ngoài khoảng mã ký tự nên không bao giờ lẫn. Ở màn hình trả sách (g_TraSach.cpp dòng 109), phím 'M' là báo mất; không cộng 256 thì mũi tên phải cũng thành báo mất.

### IN12 · Vì sao thêm
`0.2_GiaoDien.cpp` dòng 113–158, 186–243; `0.0_KhaiBaoChung.h` dòng 132–138

**Hỏi:** Màn hình chia hai vùng: thanh menu bên trái và vùng nội dung bên phải. Các màn hình chức năng vẫn gọi `InTai(4, 5, ...)` như thể bắt đầu từ cột 0. Vậy ai dời nội dung sang phải, ở dòng nào? Vì sao em làm ở đó mà không sửa tọa độ trong từng màn hình?

**Gợi ý trả lời:** Bốn hàm in nội dung `InTai`, `InCot`, `XoaVung`, `VeKhung` (và vị trí con trỏ trong `NhapChuoi`) cộng thêm `RONG_MENU` vào x trước khi gọi `gotoxy`. Chỉ `VeMenuTrai` gọi `gotoxy` trực tiếp vì nó vẽ ngoài vùng nội dung. Nhờ vậy muốn đổi độ rộng thanh menu chỉ sửa một hằng, và mười màn hình chức năng không cần biết thanh menu tồn tại. Cái giá: vùng nội dung chỉ còn 96 cột trong cửa sổ 120 cột, nên các bảng phải thu hẹp cột và tên dài bị cắt.

### IN13 · Vì sao thêm
`0.3_Menu_TongQuan.cpp` dòng 95–150; `0.2_GiaoDien.cpp` dòng 188–200

**Hỏi:** Tên các mục menu nằm trong mảng ở `VeMucMenu`, còn việc gọi chức năng nằm trong `switch (chon)` ở `MenuChinh`. Hai chỗ này liên hệ với nhau bằng gì? Thêm một chức năng mới vào giữa thì phải sửa những đâu?

**Gợi ý trả lời:** Liên hệ bằng số thứ tự: mục thứ i trong mảng ứng với `case i`, và số đầu tiên truyền cho `VeManHinh` ở từng màn hình cũng là số đó (để tô sáng đúng mục khi đang ở trong chức năng). Thêm một mục ở giữa phải sửa bốn nơi: mảng tên, hằng `SO_MUC_MENU`, các `case` phía sau, và tham số `VeManHinh` của các màn hình phía sau. Đây là ràng buộc ngầm của cách làm đơn giản này; gọn hơn là đặt hằng tên cho từng mục.

### IN14 · Thuật toán
`0.3_Menu_TongQuan.cpp` dòng 104–127; `0.2_GiaoDien.cpp` dòng 186–243

**Hỏi:** Thanh menu tô sáng mục đang chọn bằng hai màu khác nhau. Khi nào dùng màu nào? Nhấn mũi tên lên khi đang ở mục đầu tiên thì sao, công thức nào làm việc đó? Mỗi lần nhấn phím chương trình vẽ lại những gì, và vì sao em tách `VeMucMenu` khỏi `VeMenuTrai`? Con trỏ nhấp nháy của console hiện ở đâu, ẩn ở đâu?

**Gợi ý trả lời:** Khi người dùng đang di chuyển trên thanh menu (`dangDieuKhien = true`) mục được tô nền và có thêm vạch sáng ở đầu dòng; khi đang làm việc trong vùng nội dung, mục hiện tại chỉ còn tô nền, không có vạch, để biết mình đang ở đâu. Lên từ mục đầu thì vòng xuống mục cuối nhờ `(chon + SO_MUC_MENU - 1) % SO_MUC_MENU`; xuống từ mục cuối về đầu nhờ `(chon + 1) % SO_MUC_MENU`. Mỗi lần nhấn phím chỉ vẽ lại đúng hai dòng bằng `VeMucMenu`: mục vừa rời đi và mục vừa tới. Bản đầu vẽ lại cả thanh menu (30 dòng nền và 12 mục) sau mỗi phím nên màn hình nhấp nháy. `VeMenuTrai` chỉ còn được gọi khi vẽ lại cả màn hình. Con trỏ được ẩn ngay lúc mở chương trình (`HienConTro(false)` trong `KhoiTaoManHinh`) và chỉ hiện trong lúc chờ phím ở ô nhập (`NhapChuoi`); nếu để hiện suốt, mắt sẽ thấy nó nhảy theo từng lệnh `gotoxy`.

### IN15 · Vì sao thêm
`0.2_GiaoDien.cpp` dòng 27–100

**Hỏi:** `SetColor` của em không gọi `SetConsoleTextAttribute` như cách quen thuộc mà in ra một chuỗi bắt đầu bằng ký tự ESC. Chuỗi đó là gì, vì sao em làm vậy? Vì sao `XoaManHinh` không dùng `system("cls")`, và nó được gọi khi nào?

**Gợi ý trả lời:** `SetConsoleTextAttribute` chỉ chọn được 16 màu có sẵn của console, không có nền xanh đen và màu xanh bạc hà của giao diện. Chuỗi `ESC[38;2;R;G;Bm` là mã màu ANSI: console đọc nó như một lệnh "đổi màu chữ thành (R, G, B)" chứ không in ra; `48;2;...` là màu nền. Mỗi mã màu 0–15 của chương trình tra ra một bộ ba RGB trong `BANG_MAU`. Console chỉ hiểu mã này sau khi `KhoiTaoManHinh` bật chế độ tương ứng. `system("cls")` xóa bằng màu đen mặc định của console, nên em in `ESC[2J` để xóa bằng đúng màu nền đang chọn; hàm này chỉ gọi lúc mở và lúc thoát chương trình. Cái giá: trên Windows quá cũ không hỗ trợ mã ANSI thì màn hình hiện ký tự lạ.

### IN16 · Thuật toán
`0.2_GiaoDien.cpp` dòng 121–148, `InDuCot`

**Hỏi:** Nhãn "Mã thẻ" có 6 ký tự nhưng `size()` của nó là 10. Vì sao? `InDuCot` làm thế nào để các cột của bảng vẫn thẳng hàng khi tiêu đề có dấu? Điều kiện `(s[i] & 0xC0) == 0x80` nghĩa là gì?

**Gợi ý trả lời:** Chuỗi được lưu theo UTF-8: chữ không dấu chiếm 1 byte, chữ có dấu tiếng Việt chiếm 2 hoặc 3 byte, và `size()` đếm byte. Trên màn hình mỗi chữ vẫn chỉ chiếm 1 ô. Nếu căn cột theo `size()` thì cột có dấu bị thiếu khoảng trắng và lệch. `InDuCot` đếm số ô: in byte đầu của một ký tự, rồi in tiếp mọi byte nối tiếp của nó mà không tăng số ô. Byte nối tiếp trong UTF-8 luôn có hai bit cao là `10`, tức là `byte & 0xC0 == 0x80`. Khi cắt chuỗi dài, hàm chỉ cắt ở ranh giới ký tự nên không bao giờ in nửa chữ. Dữ liệu người dùng nhập vẫn là không dấu nên các hàm so sánh, tìm kiếm không bị ảnh hưởng.

### IN17 · Vì sao thêm
`0.2_GiaoDien.cpp` dòng 47–110, 246–265

**Hỏi:** `gotoxy` của em in ra `ESC[dòng;cộtH` chứ không gọi `SetConsoleCursorPosition`, và `KhoiTaoManHinh` có lệnh `setvbuf`. Hai việc này liên quan gì tới chuyện màn hình không nhấp nháy khi chuyển chức năng? Vì sao `DocPhim` lại gọi `cout.flush()`? Vì sao `VeManHinh` không xóa trắng cả màn hình?

**Gợi ý trả lời:** Nhấp nháy xảy ra khi người dùng kịp nhìn thấy màn hình ở trạng thái dở dang: vừa bị xóa trắng, hoặc mới vẽ được một nửa. `setvbuf` cho `cout` gom mọi thứ vào một vùng đệm lớn; cả màn hình mới được vẽ xong trong vùng đệm rồi mới đẩy ra một lần, lúc `DocPhim` gọi `flush` ngay trước khi chờ phím. Muốn vậy thì lệnh đổi vị trí con trỏ cũng phải nằm trong cùng dòng chảy với chữ và màu, nên `gotoxy` in mã ANSI; nếu gọi `SetConsoleCursorPosition` thì phải đẩy vùng đệm ra trước mỗi lần đổi vị trí, tức là lại vẽ từng mẩu. `VeManHinh` không xóa trắng mà vẽ đè: thanh menu vẽ lại y như cũ nên mắt không thấy đổi, vùng nội dung được lấp bằng màu nền rồi vẽ nội dung mới. Cái giá: nếu quên `flush` trước khi chờ phím thì người dùng không thấy gì; vì vậy mọi chỗ chờ phím đều đi qua `DocPhim`.

### IN18 · Vì sao thêm
`0.2_GiaoDien.cpp` dòng 335–369

**Hỏi:** Mọi ô nhập trong chương trình đều đi qua `NhapChuoi`, đọc từng phím bằng `_getch`, không có chỗ nào dùng `cin` hay `getline`. Vì sao? Điều kiện `phim >= 32 && phim <= 126` ở dòng 363 lọc những gì? Người dùng nhấn mũi tên trái, hoặc gõ chữ có dấu trong ô nhập thì sao? Nhấn Esc thì biến `s` của nơi gọi ra sao?

**Gợi ý trả lời:** `cin` chỉ trả dữ liệu sau khi người dùng nhấn Enter, không bắt được Esc, không giới hạn được số ký tự và không chặn được ký tự sai ngay lúc gõ; nó cũng tự in chữ ra và xuống dòng, phá bố cục vẽ bằng `gotoxy`. Tự đọc từng phím thì kiểm soát được hết. Khoảng 32 đến 126 là các ký tự in được của bảng ASCII: chữ không dấu, số, dấu câu. Phím mũi tên có mã từ 256 trở lên (`DocPhim` đã cộng 256) nên bị bỏ qua. Chữ có dấu cũng bị bỏ qua, khớp với quy ước dữ liệu không dấu. Hàm sửa trên bản sao `tam`; chỉ khi nhấn Enter mới gán `s = tam`, nên Esc giữ nguyên `s`.

### IN19 · Bẫy
`0.1_HamTienIch.cpp` dòng 161–173; `0.2_GiaoDien.cpp` dòng 372–385

**Hỏi:** `ChuoiThanhSo` từ chối chuỗi dài hơn 9 chữ số. Vì sao là 9 mà không phải 10? Hàm có nhận số âm không, ở đâu trong chương trình cần số âm? Người dùng gõ "007" vào ô số trang thì được số nào?

**Gợi ý trả lời:** Số `int` lớn nhất là 2.147.483.647, có 10 chữ số, nhưng không phải số 10 chữ số nào cũng vừa (ví dụ 3.000.000.000 thì tràn). Số 9 chữ số bất kỳ thì chắc chắn vừa, nên chặn ở 9 là khỏi phải viết đoạn kiểm tràn. Hàm chỉ nhận ký tự 0 đến 9 nên không có số âm; chương trình không cần số âm ở đâu cả, và nhờ vậy file có "-1" bị từ chối ngay. "007" cho ra 7 vì hàm nhân 10 rồi cộng dần từng chữ số.

---

## G. Lưu và đọc file (cả nhóm)

### FL01 · Thuật toán
`0.4_LuuDocFile.cpp` dòng 33–49, 142

**Hỏi:** Cây độc giả được ghi theo thứ tự nào? Đọc lại thì cây có giống hệt cây cũ không? Có cần ghi `height` vào file không? Cho ví dụ với cây gốc 3, con trái 2 (có con trái 1), con phải 4.

**Gợi ý trả lời:** Ghi theo duyệt trước (nút, trái, phải). Đọc lại bằng `them_cay` nên cây tự cân bằng, `height` tự tính lại, không cần ghi. Hình dạng có thể khác: ví dụ trên ghi ra 3, 2, 1, 4; đọc lại, sau 3, 2, 1 cây xoay phải thành gốc 2, rồi 4 vào bên phải của 3. Khác hình cũ nhưng vẫn là AVL hợp lệ với cùng dữ liệu. Với BST thường thì thứ tự ghi mới quan trọng: ghi theo duyệt giữa sẽ đọc lại thành cây lệch.

### FL02 · Bẫy
`0.4_LuuDocFile.cpp` dòng 181–185; `main.cpp` dòng 28–33

**Hỏi:** Người dùng không chọn "Thoát" mà bấm nút X của cửa sổ console ngay sau khi cho mượn một cuốn. Lượt mượn đó có mất không? Các lệnh hủy bộ nhớ ở cuối `main` có chạy không? Cái giá của cách làm này là gì?

**Gợi ý trả lời:** Không mất, vì mọi thao tác thành công đều gọi `LuuSauThayDoi` ghi file ngay. Phần cuối `main` (lưu lần cuối và giải phóng bộ nhớ) không chạy; hệ điều hành thu hồi bộ nhớ khi tiến trình kết thúc. Cái giá: mỗi thao tác ghi lại toàn bộ file, tốn thời gian tỉ lệ với toàn bộ dữ liệu, vì file văn bản không sửa giữa được.

### FL03 · Vì sao thêm
`main.cpp` dòng 12–26; `0.4_LuuDocFile.cpp` dòng 53

**Hỏi:** Khi đọc file thất bại, `main` báo lỗi rồi thoát luôn bằng `return 1`, không vào menu. Vì sao không cho chạy tiếp với thư viện rỗng để người dùng nhập lại? Dòng 25–26 ghi file `ThuVien_BanTruoc.txt` để làm gì, và vì sao chỉ ghi khi thư viện không rỗng? Mất điện đúng lúc đang ghi file thì cứu được tới đâu?

**Gợi ý trả lời:** Chạy tiếp với thư viện rỗng thì lần lưu đầu tiên (sau một thao tác, hoặc lúc thoát) sẽ ghi đè file hỏng bằng dữ liệu rỗng, mất cả phần còn cứu được. Dừng lại thì file hỏng còn nguyên để sửa tay. Mở file để ghi là xóa nội dung cũ ngay (0.4_LuuDocFile.cpp dòng 53), nên mất điện giữa chừng làm file cụt. Vì vậy mỗi lần mở chương trình và đọc file thành công, dòng 25–26 ghi một bản sao; file chính hỏng thì chép bản sao đè lên, chỉ mất các thao tác của phiên làm việc cuối. Thư viện rỗng thì không ghi, để lần chạy nhầm thư mục hoặc chưa có file không đè một bản sao rỗng lên bản sao đang có dữ liệu. Bản trước 15/11 chạy tiếp với thư viện rỗng và mất hết khi thoát.

### FL04 · Vì sao thêm
`1.2_DauSach_MangConTro.cpp` dòng 43–50; `c_NhapSach.cpp` dòng 109–116

**Hỏi:** Điều kiện "năm xuất bản không vượt quá năm hiện tại" chỉ nằm ở màn hình nhập, còn `HopLeDauSach` chỉ kiểm năm lớn hơn 0. Vì sao em tách hai mức kiểm như vậy?

**Gợi ý trả lời:** `HopLeDauSach` được `ThemDauSach` gọi cả khi đọc file. Nếu nó so với năm của máy thì khi đồng hồ máy bị đặt lùi (ví dụ về 2025 trong khi kho có sách xuất bản 2026), một file hoàn toàn hợp lệ bị coi là hỏng và chương trình không mở được. Điều kiện phụ thuộc thời điểm chỉ nên áp cho dữ liệu người dùng đang gõ; dữ liệu đã lưu chỉ kiểm những gì luôn đúng. Cái giá: sửa tay file thành năm 2090 thì chương trình vẫn nhận.

### FL05 · Vì sao thêm
`0.4_LuuDocFile.cpp` dòng 57–67, 84–112

**Hỏi:** File ghi số đầu sách, số cuốn của từng đầu sách, số lượt của từng độc giả trước dữ liệu. Để làm gì? Nếu ghi "3 cuốn" mà thực tế chỉ có 2 dòng cuốn thì sao?

**Gợi ý trả lời:** Các loại dòng nằm chung một file, nên phải biết trước bao nhiêu dòng tiếp theo thuộc về bản ghi đang đọc. Nếu thiếu một dòng cuốn, dòng đầu sách kế tiếp (7 trường) bị đọc như một dòng cuốn (cần 3 trường), số trường không khớp nên đọc thất bại. Chương trình không tự đoán để sửa.

### FL06 · Thuật toán
`0.4_LuuDocFile.cpp` dòng 97–101

**Hỏi:** Sau khi `ThemDauSach`, sao phải `TimDauSachTheoISBN` lại mới thêm cuốn? Đọc file có D đầu sách tốn bao nhiêu?

**Gợi ý trả lời:** `d` là biến cục bộ; `ThemDauSach` tạo một bản sao bằng `new` và đặt vào mảng theo tên, nên phải tìm lại địa chỉ bản trong kho. Mỗi đầu sách tốn một lần kiểm trùng và một lần tìm lại, đều tuyến tính, nên đọc cả file là O(D²). File đã ghi theo thứ tự tên nên phần dịch mảng không tốn gì.

### FL07 · Bẫy
`0.4_LuuDocFile.cpp` dòng 107–110, 140–143, 152–154

**Hỏi:** Người ta sửa file bằng Notepad. Những lỗi nào chương trình phát hiện khi đọc, những lỗi nào lọt?

**Gợi ý trả lời:** Phát hiện: sai số trường, số không phải chữ số, trạng thái ngoài miền, ngày không tồn tại, phái khác Nam/Nu, trùng mã thẻ, trùng ISBN, mã sách không mang ISBN của đầu sách chứa nó. Lọt: trùng mã sách trong một đầu sách (DS07), cuốn "đang mượn" mà không ai giữ (MT17), lượt mượn trỏ tới mã sách không tồn tại, độc giả có hơn 3 lượt đang mượn, ngày trả trước ngày mượn.

### FL08 · Thuật toán
`0.4_LuuDocFile.cpp` dòng 163–178

**Hỏi:** File hỏng ở dòng lịch sử của độc giả thứ hai. Lúc đó đã cấp phát những gì? Ai giải phóng?

**Gợi ý trả lời:** Đã có toàn bộ đầu sách, các cuốn, độc giả thứ nhất cùng lịch sử, và nút độc giả thứ hai. `DocFile` gọi `HuyDanhSachDauSach` và `HuyCayDocGia` (dòng 170–174) để giải phóng hết, đưa về thư viện rỗng, không rò bộ nhớ.

### FL09 · Vì sao thêm
`main.cpp` dòng 22–30

**Hỏi:** Mọi thao tác đã tự lưu file ngay khi xong. Vậy vì sao khi thoát `main` còn gọi `LuuFile` thêm lần nữa ở dòng 30? Còn bản sao `ThuVien_BanTruoc.txt` thì vì sao được ghi lúc mở chương trình mà không ghi lúc thoát?

**Gợi ý trả lời:** Lần lưu lúc thoát là phòng hờ: nếu một lần tự lưu trước đó thất bại (ổ đĩa bận, thư mục vừa được tạo lại) thì đây là cơ hội ghi lại; ở lần chạy đầu tiên nó cũng tạo ra file dù chưa có thao tác nào. Bản sao được ghi lúc mở vì đó là thời điểm duy nhất chắc chắn dữ liệu hợp lệ: vừa đọc xong và qua được mọi kiểm tra. Nếu ghi bản sao lúc thoát thì người dùng tắt bằng nút X sẽ không bao giờ có bản sao, và dữ liệu bị nhập sai trong phiên cũng bị chép luôn vào bản sao.

---

## H. Tình huống thực tế, như làm sản phẩm cho người dùng thật

Các câu này không có "đáp án đúng trong code". Thầy muốn nghe: hiện tại code làm gì, thiếu gì, và nếu phải làm thì đụng vào cấu trúc nào.

### TT01 · Thực tế
**Hỏi:** Độc giả đến quầy, quên mã thẻ, chỉ nhớ họ tên. Thủ thư làm thế nào? Nếu thêm tìm theo tên thì tốn bao nhiêu?

**Gợi ý trả lời:** Mọi màn hình chỉ nhận mã thẻ (`NhapMaTheTimDocGia`). Cách tạm: mở chức năng b in theo tên rồi dò lấy mã. Thêm tìm theo tên thì phải duyệt cả cây, O(R), vì cây sắp theo mã chứ không theo tên; và phải xử lý trường hợp nhiều người trùng tên bằng cách cho chọn trong danh sách.

### TT02 · Thực tế
**Hỏi:** Thư viện có hai quầy, hai máy cùng mở chương trình trên một file đặt ở ổ mạng. Chuyện gì xảy ra? Hệ thống web thật giải quyết thế nào?

**Gợi ý trả lời:** Mỗi máy giữ một bản dữ liệu riêng trong bộ nhớ và mỗi lần lưu là ghi đè cả file. Máy lưu sau xóa mất thay đổi của máy lưu trước; hai quầy có thể cùng cho mượn một cuốn. Chương trình này chỉ dành cho một người dùng. Hệ thống thật để dữ liệu ở một máy chủ có cơ sở dữ liệu, mỗi thao tác là một giao dịch có khóa.

### TT03 · Thực tế
**Hỏi:** Thư viện lớn dần: 50.000 độc giả, 10.000 đầu sách, 500.000 lượt mượn. Thao tác nào chậm trước tiên? Thao tác nào vẫn nhanh?

**Gợi ý trả lời:** Chậm trước: lưu file sau mỗi thao tác (ghi lại hàng chục MB mỗi lần mượn); Top 10 (số lượt nhân số đầu sách, cỡ vài tỉ phép so chuỗi); khởi động (đọc đầu sách O(D²)); danh sách quá hạn (QH02). Vẫn nhanh: tìm thẻ độc giả O(log R) nhờ AVL, chèn đầu sách.

### TT04 · Thực tế
**Hỏi:** Độc giả xin gia hạn thêm 7 ngày cho cuốn đang mượn. Làm được không? Cách "trả rồi mượn lại" có hậu quả gì?

**Gợi ý trả lời:** Không có chức năng gia hạn. Trả rồi mượn lại tạo thêm một lượt, làm Top 10 tăng ảo, và nếu đã quá hạn thì việc trả xóa luôn dấu vết quá hạn. Sửa ngày mượn thì mất ngày mượn thật. Muốn làm đúng cần thêm thông tin "số lần gia hạn" hoặc "hạn trả", là trường ngoài đề.

### TT05 · Thực tế
**Hỏi:** Thư viện phạt 1.000 đồng mỗi ngày quá hạn cho mỗi cuốn. Dữ liệu hiện có đủ để tính không, kể cả cuốn đã trả trễ?

**Gợi ý trả lời:** Tính được mà không cần trường mới. Cuốn đang giữ: dùng `SoNgayQuaHan` đến hôm nay. Cuốn đã trả trễ: lượt mượn có cả ngày mượn và ngày trả, lấy khoảng cách trừ 7. Nhưng "đã nộp phạt hay chưa" thì dữ liệu không lưu được, cần thêm trường.

### TT06 · Thực tế
**Hỏi:** Độc giả muốn xem lại tất cả sách mình từng mượn. Có dữ liệu không? Thêm chức năng này khó không?

**Gợi ý trả lời:** Có: danh sách mượn trả giữ cả lượt đã trả và đã mất, vì trả sách chỉ đổi trạng thái chứ không xóa nút. Chức năng h hiện chỉ lọc lượt đang mượn. Thêm màn hình lịch sử là bỏ điều kiện lọc và thêm phân trang, không đụng tới cấu trúc.

### TT07 · Thực tế
**Hỏi:** Độc giả làm mất thẻ, xin cấp lại. Nếu thủ thư tạo thẻ mới thì chuyện gì xảy ra với sách người đó đang giữ?

**Gợi ý trả lời:** Thẻ mới là một nút mới với mã mới, lịch sử trống. Sách đang giữ và lịch sử vẫn nằm ở thẻ cũ, nên người này có thể mượn thêm 3 cuốn bằng thẻ mới, vượt giới hạn. Cách đúng: mã thẻ là định danh của người, không phải của tấm thẻ; in lại thẻ với mã cũ chứ không tạo nút mới.

### TT08 · Thực tế
**Hỏi:** Sách hot luôn có người mượn. Độc giả muốn đặt trước, khi sách về thì mình được ưu tiên. Cần cấu trúc dữ liệu gì?

**Gợi ý trả lời:** Hiện không có. Cần một hàng đợi (vào trước ra trước) gắn với từng đầu sách, chứa mã thẻ của người chờ; khi có cuốn được trả thì chỉ người đầu hàng được mượn. Đó là cấu trúc ngoài bốn cấu trúc của đề, phải được thầy cho phép.

### TT09 · Thực tế
**Hỏi:** Thủ thư bấm nhầm, ghi trả sai cuốn, hoặc ghi mượn cho nhầm người. Có hoàn tác được không?

**Gợi ý trả lời:** Không có hoàn tác. Trả nhầm thì chỉ còn cách mượn lại, tạo một lượt mới: lịch sử sai và Top 10 tăng thêm 1. Mượn nhầm người thì phải trả rồi mượn lại cho đúng người, để lại một lượt thừa. Muốn hoàn tác cần nhớ thao tác gần nhất (một ngăn xếp), hoặc ít nhất một chức năng "hủy lượt mượn vừa tạo".

### TT10 · Thực tế
**Hỏi:** Cuối năm kiểm kê: thư viện cần số cuốn trên kệ, đang cho mượn, đã thanh lý, và muốn biết sổ sách có khớp không. Chương trình cho biết được gì?

**Gợi ý trả lời:** Trang Tổng quan hiện tổng số cuốn, số cuốn đang được mượn và số cuốn còn trên kệ của 10 đầu sách đầu (0.3_Menu_TongQuan.cpp dòng 13–90), nhưng chưa có số cuốn đã thanh lý và chưa đối chiếu với lịch sử. Viết thêm thì đơn giản: một lượt duyệt mọi danh mục, đếm theo ba trạng thái; một lượt duyệt mọi lịch sử, đếm lượt đang mượn; hai con số "đang mượn" phải bằng nhau, lệch là dữ liệu hỏng (xem MT17).

### TT11 · Thực tế
**Hỏi:** Một cuốn bị rách, đem đi đóng lại hai tuần. Chưa thanh lý nhưng tạm không cho mượn. Ghi nhận thế nào?

**Gợi ý trả lời:** Đề chỉ có ba trạng thái. Thanh lý thì không quay lại được. Không có cách ghi nhận đúng; cách tạm duy nhất là để nguyên "cho mượn được" và nhớ ngoài sổ. Thêm trạng thái thứ tư là sửa quy định của đề, phải hỏi thầy.

### TT12 · Thực tế
**Hỏi:** Giảng viên được mượn 10 cuốn trong 30 ngày, sinh viên 3 cuốn trong 7 ngày. Sửa thế nào?

**Gợi ý trả lời:** Hiện hai giới hạn là hằng số dùng chung cho mọi người. Cần thêm trường "loại độc giả" vào thẻ (ngoài đề), và `MuonSach`, `CoSachQuaHan7Ngay`, `SoNgayQuaHan` phải nhận giới hạn theo loại thay vì dùng hằng. File cũng phải thêm một trường.

### TT13 · Thực tế
**Hỏi:** Người đến trả sách hộ bạn, chỉ cầm cuốn sách có dán mã, không biết mã thẻ của bạn. Trả được không? Sao chương trình không tra được "cuốn này ai đang giữ"?

**Gợi ý trả lời:** Không trả được: chức năng g bắt buộc nhập mã thẻ trước. Cuốn sách chỉ lưu trạng thái, không lưu ai đang giữ; thông tin đó nằm trong lịch sử của từng độc giả. Muốn tra theo mã sách phải duyệt mọi độc giả và mọi lượt mượn, O(R + H). Làm được, không cần trường mới, chỉ chậm hơn.

### TT14 · Thực tế
**Hỏi:** Sinh viên dùng máy tra cứu ở sảnh thư viện. Họ có vào được chức năng xóa thẻ, mượn trả không? Cần gì để ngăn?

**Gợi ý trả lời:** Vào được hết: chương trình không có đăng nhập hay phân quyền. Cần ít nhất hai vai trò (thủ thư và người tra cứu) và kiểm vai trò trước khi vào từng mục menu. Chỉ ẩn mục trên menu là chưa đủ nếu các hàm vẫn gọi được từ chỗ khác.

### TT15 · Thực tế
**Hỏi:** Thủ thư lỡ thanh lý nhầm, hoặc nhập sai hàng loạt, muốn quay lại dữ liệu sáng nay. Được không?

**Gợi ý trả lời:** Chỉ được một phần. File chính bị ghi đè sau mỗi thao tác và không có nhật ký thao tác; chỉ có `ThuVien_BanTruoc.txt` là bản chụp lúc mở chương trình (main.cpp dòng 25–26), nên quay lại được trạng thái đầu phiên làm việc, không chọn được mốc khác. Muốn hơn thì đặt tên bản sao theo ngày.

### TT16 · Thực tế
**Hỏi:** Ban giám đốc muốn Top 10 của riêng tháng 11, không phải từ trước đến nay. Dữ liệu có đủ không? Lượt mượn 30/10 trả 02/11 tính vào tháng nào?

**Gợi ý trả lời:** Đủ, vì mỗi lượt có ngày mượn. Chỉ cần thêm điều kiện lọc tháng và năm ở bước đếm (j_Top10Sach.cpp dòng 41–46). Lượt vắt qua hai tháng phải có quy ước; hợp lý nhất là tính theo ngày mượn, vì "lượt mượn" là sự kiện xảy ra lúc mượn.

### TT17 · Thực tế
**Hỏi:** Hạn trả rơi vào chủ nhật hoặc ngày lễ, thư viện đóng cửa. Độc giả trả vào thứ hai có bị tính quá hạn không?

**Gợi ý trả lời:** Có. Chương trình đếm ngày lịch liên tục, không biết thứ trong tuần hay ngày nghỉ. Muốn xử lý cần hàm tính thứ từ ngày (lấy số ngày từ `Doirangay` chia dư cho 7) và một danh sách ngày lễ; hạn trả dời sang ngày làm việc kế tiếp.

### TT18 · Thực tế
**Hỏi:** Nếu chuyển chương trình này thành trang web cho độc giả tự tra cứu và thủ thư thao tác, phần nào của code giữ lại được, phần nào phải viết lại?

**Gợi ý trả lời:** Giữ được: các hàm nghiệp vụ không dính màn hình, như `MuonSach`, `TraSach`, `them_cay`, `ThemDauSach`, các hàm ngày tháng; chúng nhận dữ liệu và trả kết quả kèm chuỗi lỗi. Viết lại: toàn bộ phần `ManHinh...` và `0.2_GiaoDien.cpp`; phần lưu file phải thay bằng cơ sở dữ liệu để nhiều người dùng cùng lúc (TT02); thêm đăng nhập (TT14). Việc tách hàm nghiệp vụ khỏi hàm màn hình là lý do thiết kế đáng nêu với thầy.

### TT19 · Thực tế
**Hỏi:** Thư viện mua bản tái bản lần 2 của "Lap trinh C++": cùng tên, khác năm xuất bản, số trang và ISBN. Nhập vào thì chương trình coi đây là gì? Tìm theo tên, in theo thể loại và Top 10 hiển thị hai bản này thế nào?

**Gợi ý trả lời:** Là một đầu sách mới, vì đầu sách được định danh bằng ISBN; trùng tên được phép và bản mới được chèn ngay trước bản cũ trong mảng. Tìm theo tên ra hai kết quả, bảng thể loại có hai dòng liền nhau, Top 10 đếm riêng từng ISBN nên lượt mượn bị chia đôi. Chương trình không có khái niệm "cùng một tác phẩm"; muốn gộp phải có thêm một khóa chung, là thông tin ngoài đề.

### TT20 · Thực tế
**Hỏi:** Cuối năm học, phòng đào tạo yêu cầu khóa toàn bộ thẻ có mã từ 2000 đến 3500 (khóa sinh viên vừa tốt nghiệp). Chương trình làm được không? Viết thêm thì tận dụng cây tìm kiếm thế nào để không phải duyệt cả cây?

**Gợi ý trả lời:** Hiện chỉ khóa từng thẻ ở màn hình hiệu chỉnh. Viết thêm: duyệt cây có cắt nhánh theo khoảng: nếu mã nút lớn hơn 2000 mới đi sang trái, nếu nhỏ hơn 3500 mới đi sang phải, nút nằm trong khoảng thì đổi trạng thái. Chi phí O(log n + k) với k là số thẻ trong khoảng, nhờ cây cân bằng. Đổi trạng thái không phải khóa của cây nên không cần xoay; lưu file một lần sau cùng chứ không lưu sau mỗi thẻ.

### TT21 · Thực tế
**Hỏi:** Thư viện đang quản lý 3000 đầu sách bằng Excel và muốn chuyển sang chương trình này. Phải gõ tay từng đầu sách à? Nếu soạn sẵn file `ThuVien.txt` thì cần đúng những gì, có phải sắp theo tên trước không?

**Gợi ý trả lời:** Không cần gõ tay: soạn file đúng định dạng là chương trình đọc được. Không cần sắp theo tên, vì đọc file gọi `ThemDauSach`, hàm này tự chèn đúng vị trí; file chưa sắp thì tốn thêm phần dịch mảng, vẫn chạy được. Cần đúng: dòng đầu là số đầu sách; mỗi đầu sách 7 trường, trường cuối là số cuốn; mã cuốn phải dạng ISBN#N của chính đầu sách đó và nên tăng dần; không có dấu, không có ký tự `|` trong nội dung. Sai một dòng là cả file bị từ chối và chương trình thoát.

### TT22 · Thực tế
**Hỏi:** Độc giả nhớ mang máng tên sách và gõ "du lieu cau truc", hoặc gõ dính "cautruc". Có tìm ra "Cau truc du lieu va giai thuat" không? Muốn tìm được khi các từ đảo thứ tự thì sửa thế nào?

**Gợi ý trả lời:** Không ra. `ChuaChuoi` tìm nguyên cụm liên tiếp, chỉ bỏ qua hoa thường và khoảng trắng thừa. Muốn tìm theo từng từ: tách từ khóa thành các từ (đã có `TachTruong` với dấu cách), tên sách khớp khi chứa đủ mọi từ, tức là gọi `ChuaChuoi` cho từng từ và lấy điều kiện VÀ. Chi phí nhân thêm số từ. Tìm gần đúng khi gõ sai chính tả là bài toán khác hẳn, không nằm trong phạm vi.

### TT23 · Thực tế
**Hỏi:** Độc giả hỏi: "Cuốn `9786040000001#1` đang ai giữ, bao giờ trả?" Rồi thư viện phát hiện cuốn này bị xé trang và muốn biết những ai từng mượn nó. Chương trình trả lời được không, tốn bao nhiêu?

**Gợi ý trả lời:** Dữ liệu có đủ nhưng chưa có màn hình. Cuốn sách chỉ lưu trạng thái, nên cả hai câu đều phải duyệt mọi độc giả và mọi lượt mượn, lọc theo mã sách: O(R + H). Lượt đang mượn cho biết người giữ; các lượt đã trả cho danh sách người từng mượn. Riêng "bao giờ trả" còn thiếu một hàm cộng 7 ngày vào ngày mượn: hiện chỉ có `Doirangay` đổi ngày ra số, chưa có hàm đổi ngược số ra ngày.

### TT24 · Thực tế
**Hỏi:** Trường muốn khen thưởng 10 độc giả mượn nhiều sách nhất năm. So với Top 10 sách thì bài này dễ hơn hay khó hơn với cấu trúc dữ liệu hiện tại? Vì sao?

**Gợi ý trả lời:** Dễ hơn. Lịch sử mượn nằm ngay trong từng độc giả, nên số lượt của một người chỉ là độ dài danh sách của người đó (lọc theo năm của ngày mượn): một lượt duyệt cây O(R + H), không phải tra ISBN. Top 10 sách khó hơn vì từ mỗi lượt phải tìm ngược ra đầu sách. Cấu trúc đề cho thuận cho câu hỏi "theo độc giả" và tốn kém cho câu hỏi "theo sách".

### TT25 · Thực tế
**Hỏi:** Thủ thư muốn danh sách các đầu sách chưa từng được ai mượn để cân nhắc thanh lý. Tận dụng được phần nào của chức năng j? Nếu hỏi "cuốn nào chưa từng được mượn" thì khác gì?

**Gợi ý trả lời:** Bước 1 và 2 của Top 10 đã tính `luotMuon[]` cho mọi đầu sách; chỉ cần in các đầu sách có giá trị 0 thay vì chọn 10 cái lớn nhất. Hỏi theo cuốn thì mảng đếm phải theo từng cuốn: cần đánh số mọi cuốn và tra từ mã sách ra số thứ tự, tức là tìm đầu sách rồi duyệt danh mục cho mỗi lượt mượn, tốn hơn nhiều.

### TT26 · Thực tế
**Hỏi:** Một người đăng ký thẻ hai lần ở hai quầy, hoặc mượn thẻ của bạn. Chương trình có phát hiện không? Giới hạn 3 cuốn còn ý nghĩa không?

**Gợi ý trả lời:** Không phát hiện. Thẻ chỉ có họ, tên, phái; trùng họ tên là hợp lệ vì người khác nhau có thể trùng tên, nên không có gì để nhận ra một người có hai thẻ. Mỗi thẻ được 3 cuốn, vậy người đó mượn được 6. Giới hạn 3 cuốn là theo thẻ chứ không theo người. Muốn theo người cần một định danh thật như mã sinh viên, là trường ngoài đề.

### TT27 · Thực tế
**Hỏi:** Thư viện muốn thẻ tự bị khóa khi giữ sách quá hạn hơn 30 ngày, và tự mở lại khi trả. Hiện thẻ bị khóa trong những trường hợp nào? Tự khóa thì nên chạy lúc nào, và vướng gì khi tự mở?

**Gợi ý trả lời:** Hiện chỉ khóa khi thủ thư khóa tay hoặc khi báo mất sách. Người quá hạn không bị khóa thẻ, chỉ bị chặn mượn bởi kiểm tra quá hạn. Tự khóa có thể chạy lúc khởi động: duyệt cả cây và lịch sử, O(R + H). Tự mở thì vướng: trạng thái thẻ chỉ có 0 và 1, không lưu lý do khóa, nên không phân biệt được thẻ khóa do quá hạn với thẻ khóa do mất sách hay khóa tay. Thực ra kiểm tra quá hạn sẵn có đã cho đúng tác dụng "tự khóa, tự mở" mà không cần đổi trạng thái.

### TT28 · Thực tế
**Hỏi:** Thủ thư tạo lối tắt ngoài màn hình rồi mở chương trình từ đó, thấy thư viện trống trơn và hoảng vì tưởng mất dữ liệu. Chuyện gì đã xảy ra? Nếu họ nhập tiếp thì dữ liệu đi đâu?

**Gợi ý trả lời:** Tên file là đường dẫn tương đối `DuLieu/ThuVien.txt`, tính từ thư mục mà chương trình được chạy, không phải thư mục chứa file exe. Chạy từ chỗ khác thì không thấy file; `DocFile` coi "chưa có file" là thư viện rỗng hợp lệ (0.4_LuuDocFile.cpp dòng 166–167). File thật vẫn nguyên. Nhập tiếp thì hoặc báo không ghi được (chỗ đó không có thư mục `DuLieu`), hoặc tạo ra một bộ dữ liệu thứ hai tách biệt. Nên in đường dẫn file đang dùng lên màn hình, hoặc báo rõ "chưa có file dữ liệu" thay vì im lặng.

### TT29 · Thực tế
**Hỏi:** File dữ liệu là văn bản thường. Một sinh viên có quyền dùng máy mở `ThuVien.txt` bằng Notepad, đổi trạng thái thẻ của mình từ 0 thành 1 và xóa dòng lượt mượn quá hạn. Chương trình có phát hiện không?

**Gợi ý trả lời:** Đổi trạng thái thẻ thì không thể phát hiện, vì đó là giá trị hợp lệ. Xóa một dòng lượt mượn mà không sửa số lượt ở dòng độc giả thì file lệch số dòng, bị từ chối và chương trình thoát; nếu sửa cả số lượt thì lọt, và cuốn sách tương ứng kẹt ở trạng thái "đang mượn" (MT17). File không có mã kiểm tra hay mã hóa. Đây là giới hạn của việc lưu văn bản thường; hệ thống thật để dữ liệu ở máy chủ, người dùng không chạm được vào file.

### TT30 · Thực tế
**Hỏi:** Độc giả đến quầy nói "cho em mượn cuốn Toan roi rac". Thủ thư phải thao tác những bước nào? Chỗ nào dễ sai nhất? Cải thiện thế nào mà không đổi cấu trúc dữ liệu?

**Gợi ý trả lời:** Vào e tìm tên, đọc danh sách mã để chọn một cuốn đang "cho mượn được", nhớ hoặc chép mã dài 15 ký tự, thoát ra, vào f, nhập mã thẻ rồi gõ lại nguyên mã sách. Gõ lại mã là chỗ dễ sai nhất. Cải thiện: ở f cho nhập ISBN hoặc chọn từ kết quả tìm tên, rồi chương trình tự duyệt danh mục lấy cuốn đầu tiên có trạng thái 0. Chỉ thêm một vòng duyệt, không thêm trường nào.

### TT31 · Thực tế
**Hỏi:** Sau nhiều năm, mã thẻ tăng tới 1.000.000. Chương trình còn dùng được không? Chỗ nào hỏng đầu tiên?

**Gợi ý trả lời:** Kiểu `int` chứa được tới khoảng 2 tỉ và cây AVL 1 triệu nút chỉ cao khoảng 20–28, nên phần dữ liệu không sao. Hỏng đầu tiên là giao diện: ô nhập mã thẻ chỉ cho 6 chữ số (`NhapMaTheTimDocGia`, a_QuanLyDocGia.cpp dòng 40), nên thẻ 1.000.000 được cấp nhưng không gõ được mã để mượn, trả hay hiệu chỉnh. Tiếp theo là cột mã thẻ trên các bảng và thời gian lưu file sau mỗi thao tác.

### TT32 · Thực tế
**Hỏi:** File dữ liệu ngày càng nặng. Thủ thư đề nghị xóa các lượt mượn đã trả từ hơn hai năm trước. Việc này kéo theo những thay đổi nào ngoài chuyện file nhẹ đi?

**Gợi ý trả lời:** Top 10 giảm, vì nó đếm từ lịch sử. Độc giả nào bị xóa sạch lịch sử thì `XoaDocGia` sẽ cho xóa thẻ (điều kiện chỉ là danh sách mượn trả rỗng), và nếu đó là thẻ mã lớn nhất thì mã bị cấp lại cho người mới (DG10). Mất luôn khả năng truy vết ai từng mượn một cuốn và tính tiền phạt cũ. Lượt đang mượn và lượt làm mất phải giữ, nếu không cuốn sách và thẻ mất căn cứ cho trạng thái hiện tại.

### TT33 · Thực tế
**Hỏi:** Một cuốn thuộc hai thể loại, thủ thư nhập "Tin hoc, Toan hoc". Một người khác gõ nhầm "Tin hok". Bảng in theo thể loại ra sao? Sửa lại được không?

**Gợi ý trả lời:** Thể loại là một chuỗi và được so nguyên chuỗi, nên "Tin hoc, Toan hoc" thành một nhóm riêng, không nằm trong nhóm Tin hoc lẫn Toan hoc; "Tin hok" cũng thành một nhóm riêng. Chương trình chỉ gộp khác biệt hoa thường và khoảng trắng. Không có danh mục thể loại chuẩn để chọn, và không có chức năng sửa đầu sách (DS10), nên nhập sai là phải sửa tay trong file. Cải thiện rẻ nhất: khi nhập, liệt kê các thể loại đã có để chọn.

### TT34 · Thực tế
**Hỏi:** Ban giám hiệu yêu cầu nộp danh sách độc giả quá hạn bằng giấy hoặc file Excel. Chương trình xuất được không? Mở thẳng `ThuVien.txt` bằng Excel có dùng được không?

**Gợi ý trả lời:** Chưa: mọi báo cáo chỉ vẽ lên màn hình bằng `gotoxy`. Mở file dữ liệu bằng Excel với dấu ngăn `|` thì đọc được từng dòng, nhưng dòng đầu sách, dòng cuốn, dòng độc giả, dòng lượt mượn nằm xen nhau với số cột khác nhau, và không có cột "số ngày quá hạn" vì số đó được tính lúc xem. Thêm xuất file thì dễ: sau bước sắp xếp ở chức năng i, ghi hai mảng `dg[]`, `luot[]` ra một file văn bản, mỗi dòng một lượt, các cột ngăn bằng dấu phẩy.

### TT35 · Thực tế
**Hỏi:** Một sinh viên nghỉ học và không bao giờ trả 2 cuốn đang giữ. Sau một năm, hai cuốn đó và thẻ này ở trạng thái gì? Thủ thư dọn dẹp thế nào, có hệ quả gì?

**Gợi ý trả lời:** Hai cuốn vẫn "đã có người mượn", không ai mượn được và không thanh lý được; thẻ vẫn hoạt động; hai dòng này đứng đầu danh sách quá hạn mãi. Cách duy nhất là vào g báo mất từng cuốn: lượt chuyển trạng thái 2, cuốn chuyển thanh lý, thẻ bị khóa. Hệ quả: hai cuốn vẫn nằm trong danh mục và vẫn được đếm trong tổng số cuốn ở menu chính, thẻ không xóa được vì có lịch sử. Số liệu "làm mất" lúc này gộp cả mất thật lẫn không thu hồi được.

---

## I. Thầy bắt sửa code tại chỗ

Mỗi câu nên tự làm thử trên một bản sao, bấm giờ 10–15 phút.

### SC01 · Sửa tại chỗ
**Hỏi:** Đổi giới hạn mượn từ 3 thành 5 cuốn.

**Gợi ý trả lời:** Sửa `MAX_SACH_MUON` trong `0.0_KhaiBaoChung.h` dòng 12 và chuỗi thông báo ở `f_MuonSach.cpp` dòng 37. Bảng sách đang mượn tự cao thêm vì dùng hằng (dòng 78), nhưng phải kiểm lại các nhãn bên dưới bảng (dòng 136–137 đặt ở y = 18, 20) có bị đè không.

### SC02 · Sửa tại chỗ
**Hỏi:** Đổi Top 10 thành Top 5.

**Gợi ý trả lời:** Số 10 ghi cứng ở `j_Top10Sach.cpp` dòng 52–53, cùng tiêu đề màn hình và tên mục menu. Nên tách thành một hằng.

### SC03 · Sửa tại chỗ
**Hỏi:** In danh sách độc giả theo mã thẻ giảm dần.

**Gợi ý trả lời:** Cách nhanh: giữ mảng tạm như cũ, in từ phần tử cuối về đầu. Cách theo cây: duyệt phải, nút, trái.

### SC04 · Sửa tại chỗ
**Hỏi:** Cấm một độc giả giữ hai cuốn của cùng một đầu sách.

**Gợi ý trả lời:** Trong `MuonSach`, sau khi tìm được cuốn: duyệt lịch sử, nếu có lượt đang mượn mà `TachISBNTuMaSach(p->maSach)` bằng `dauSach->ISBN` thì gán lỗi và trả `false`. Đặt trước dòng 57.

### SC05 · Sửa tại chỗ
**Hỏi:** Danh sách quá hạn: mỗi độc giả chỉ một dòng, lấy số ngày quá hạn lớn nhất.

**Gợi ý trả lời:** Ở bước 2 của `ManHinhDocGiaQuaHan`, với mỗi độc giả chỉ giữ lượt có ngày mượn sớm nhất trong các lượt quá hạn, rồi mới đưa vào `dg[]`, `luot[]`. Phần sắp xếp và in giữ nguyên.

### SC06 · Sửa tại chỗ
**Hỏi:** Cho tìm sách theo tên tác giả.

**Gợi ý trả lời:** Trong `ManHinhTimSach` dòng 76, đổi điều kiện thành khớp tên sách hoặc khớp `tacGia`, hoặc thêm một lựa chọn kiểu tìm. Phần hiển thị không đổi.

### SC07 · Sửa tại chỗ
**Hỏi:** Quá hạn cùng số ngày thì mã thẻ nhỏ in trước. Top 10 cùng số lượt thì tên sách đứng trước in trước.

**Gợi ý trả lời:** Quá hạn (dòng 56): thêm nhánh "bằng số ngày và mã thẻ của `dg[j]` nhỏ hơn". Top 10 (dòng 92): thêm nhánh "bằng số lượt và `thuTu[j] < thuTu[lonNhat]`".

### SC08 · Sửa tại chỗ
**Hỏi:** Chặn ngày mượn nằm trước ngày trả gần nhất của chính cuốn sách đó (xem MT05).

**Gợi ý:** Cuốn sách không lưu ai đã mượn, nên phải duyệt mọi độc giả (`LayDanhSachDocGia`) và mọi lượt có cùng mã sách, lấy ngày trả lớn nhất; nếu `ngayMuon` nhỏ hơn ngày đó thì từ chối. Chi phí O(R + H) cho mỗi lần mượn.

### SC09 · Sửa tại chỗ
**Hỏi:** Trả sách chỉ bằng mã sách, không cần nhập mã thẻ.

**Gợi ý trả lời:** Lấy mảng con trỏ nút bằng `LayDanhSachDocGia`, với từng độc giả gọi `TimMuonDangMuonTheoMa`; gặp người đầu tiên có lượt đang mượn mã đó thì gọi `TraSach`. Nhớ giải phóng mảng tạm.
