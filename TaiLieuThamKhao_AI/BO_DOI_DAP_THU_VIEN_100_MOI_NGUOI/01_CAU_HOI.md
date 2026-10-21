# 325 câu đối đáp đồ án Thư viện

> **Đồng bộ C++11 ngày 21/10/2026:** cả 325 câu đối chiếu mã nguồn demo tại commit `b449646`. Liên kết tên file mở mã đi kèm; liên kết tên hàm/số dòng mở đúng snapshot C++11 trên GitHub. [Phạm vi đồng bộ và kiểm chứng](ThamKhao/DONG_BO_VAN_DAP_CPP11.md).


**Thái 100 · Thành 100 · Tấn 100 · Cả nhóm 25.** Mỗi ID là một câu chính; câu phụ và danh sách ôn trước không cộng thêm vào số lượng.

Giải nén toàn bộ ZIP, mở thư mục bằng VS Code rồi mở file này và nhấn **Ctrl+Shift+V**. Dòng `<a id=...>` chỉ là mốc liên kết, không phải nội dung cần học. Bấm liên kết mã để đến câu; mở đáp án sau khi tự dự đoán.

**Đi nhanh:** [20 câu ôn trước](#on-truoc) · [Thái — 100](#thai) · [Thành — 100](#thanh) · [Tấn — 100](#tan) · [Chung — 25](#chung) · [Đáp án](02_DAP_AN.md) · [Hướng dẫn đọc](README.md).

Bộ này bám đúng chín file **demo AI C++11 trên Windows** trong `ThamKhao/MaNguon`, snapshot `b449646` ngày 21/10/2026. Giữ bốn cấu trúc nghiệp vụ và bốn header iostream, string, fstream, windows.h. Đây là mã tham khảo AI, không phải bằng chứng nhóm tự viết; khi mã nguồn đổi tiếp phải đối chiếu lại đáp án. [nguyên văn đề 3](ThamKhao/NGUYEN_VAN_DE_3_THU_VIEN.txt), [yêu cầu và giả định G01–G12](ThamKhao/01_YEU_CAU_VA_GIA_DINH.md).

**Cách dùng:** một người hỏi câu chính, người được hỏi dự đoán và chỉ code, rồi dùng câu phụ để đổi điều kiện. Đáp án là căn cứ phản biện, không phải lời nói cần học thuộc. P1/P2/P3 chỉ là thứ tự ôn theo tác động và phụ thuộc; không phải xác suất thầy hỏi hoặc cam kết điểm.

**Ba phạm vi:** “Hiện tại” mô tả mô hình có sẵn; “Chẩn đoán trên bản sao” giả lập lỗi hoặc refactor để phân tích; “Mở rộng giả định” là yêu cầu chưa triển khai. Nhãn chính áp cho tình huống trung tâm; một câu phụ có thể đổi sang giả định và sẽ nói rõ. Không thực hiện mutation thử trên bản nộp.

**Điều kiện chung:** nếu không nói khác, cấu trúc/liên kết, thẻ, ngày và các điều kiện không được thay đổi đều hợp lệ. Ngày ví dụ không vượt ngày máy; khi thử sau này hãy dùng dữ liệu và ngày máy phù hợp. Mặc định một người thao tác tuần tự trong một tiến trình; chỉ câu nêu rõ nhiều tiến trình/dịch vụ mới xét đồng thời. Không có đặt trước, hàng chờ, phân quyền hay audit đầy đủ trong bản hiện tại.

**Quy ước phân tích:** D = số đầu sách; C = số cuốn vật lý; R = số độc giả; H = tổng lượt lịch sử (kể cả đã trả/mất); H_A = lịch sử của một người; h = chiều cao BST; L = độ dài chuỗi. MAX_DAU_SACH=10.000, MAX_DOC_GIA=100.000; MAX_BAN_GHI=200.000 áp riêng cho C và H. Giới hạn 3 chỉ áp lượt đang mở. Phân tích có 1 triệu hồ sơ/lượt là giả định vượt cận: bản hiện từ chối tại các cổng giới hạn; không phải benchmark đã chạy. Khi không ghi L, cận đếm thao tác cấu trúc còn phải cộng chi phí chuỗi/cấp phát/đầu ra.

**Bốn cấu trúc giữ nguyên:** mảng con trỏ đầu sách theo tên; danh sách đơn cuốn; BST độc giả theo mã; danh sách đơn lịch sử từng người. View là mảng tham chiếu tạm để đọc/sắp, không nhận quyền xóa node nguồn. Snapshot là ảnh dữ liệu tại một mốc. Commit là thời điểm đưa thay đổi vào nguồn; commit RAM khác lưu bền. Invariant là điều kiện phải giữ đúng. Các phương án thay cấu trúc/trường/luật chỉ để so sánh, cần giảng viên cho phép trước khi đưa vào bản nộp; không mặc định STL thay phần tự cài.

Cuốn:0 sẵn sàng/1 đang mượn/2 thanh lý; lượt:0 mở/1 đã trả/2 mất; thẻ:0 khóa/1 hoạt động. G01–G12 là giả định triển khai cần xác nhận, đặc biệt top theo đầu, đồng hạng, max quá hạn, ánh xạ mất, xóa người có lịch sử và quy tắc cấp mã.

**Lịch sử nội dung:** bản 18/10 đã sửa truy vết, phản ví dụ và gộp ba cặp trùng; bản 21/10 đồng bộ API, hợp đồng bộ đệm/ngoại lệ và toàn bộ mốc nguồn sang C++11. Bản gửi nhóm chỉ giữ nội dung học và code đi kèm; hồ sơ biên soạn/kiểm thử đầy đủ được lưu riêng. Các ID gộp được dẫn tới câu giữ lại, không tính thêm câu.


<a id="on-truoc"></a>
## 20 câu ôn trước

- [TV01 — Ai được mượn khi hai người cùng chọn một cuốn?](#TV01)
- [TV03 — Đã giữ ba cuốn: đổi thứ tự thao tác có đổi kết quả?](#TV03)
- [TV04 — Quá hạn, khóa thẻ và quyền trả sách tương tác thế nào?](#TV04)
- [TV05 — Trả, bấm trả lại rồi người khác mượn lại cùng ngày](#TV05)
- [TV06 — Báo mất có kết thúc mọi khoản mượn không?](#TV06)
- [TV07 — Nút kế tiếp có lịch sử riêng: xóa gốc thế nào?](#TV07)
- [TV10 — Cuốn rảnh nhưng ngày giao dịch vẫn bị chặn](#TV10)
- [TV11 — Hiện không giữ cuốn nào nhưng lịch sử vẫn vô lý](#TV11)
- [TH02 — Chèn giữa khi đang giữ con trỏ cuốn](#TH02)
- [TH06 — Tên tăng không có nghĩa ISBN tăng](#TH06)
- [TH14 — Ranh giới thứ mười có ba đầu cùng tên](#TH14)
- [TH61 — Trả một phần làm người đứng đầu bảng chuyển vị trí thế nào?](#TH61)
- [TN01 — Đổi tên xong, hai kiểu liệt kê có còn đúng?](#TN01)
- [TN03 — Có tám lượt lịch sử nhưng chỉ giữ hai cuốn](#TN03)
- [TN71 — Phân trang không phải đọc lười](#TN71)
- [TN100 — Thầy hỏi phần mượn dù mình phụ trách menu](#TN100)
- [GH02 — File thay an toàn có ngăn hai người mượn trùng?](#GH02)
- [GH03 — File đứt giữa lịch sử độc giả thứ hai](#GH03)
- [GH05 — Thất bại sau khi đã ghi file tạm](#GH05)
- [CH05 — Ngoại lệ sau commit có nghĩa giao dịch đã thất bại không?](#CH05)

<a id="thai"></a>
## Thái — 100 câu

<a id="TH01"></a>
### 001. TH01 — Cùng ISBN nhưng ba trạng thái

**Phụ trách:** Thái · **Ưu tiên:** P1 · **Phạm vi:** Hiện tại.

**Trọng tâm:** c — Đầu sách và cuốn.

**Chỉ vào code:** [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [DauSach, dòng 274](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L274); [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [InMotDauSach, dòng 10](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L10); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110).

**Câu chính:** ISBN A có A#1 đang được An mượn, A#2 đã thanh lý, A#3 còn trên kệ. Bình tìm tên rồi xin mượn A#3. Hãy chỉ các trường và liên kết code dùng để hiện đúng ba trạng thái, định danh cuốn của Bình và giải thích hậu quả nếu thay chúng bằng một trạng thái ở đầu sách.

**Câu phụ 1:** Trên bản sao RAM, đổi riêng A#3 thành đang mượn nhưng không tạo lượt cho Bình. Tìm tên và top có cùng phát hiện lỗi này không? Lưu có được chấp nhận không?

[Mở đáp án TH01](02_DAP_AN.md#TH01) · [Về đầu phần](#thai)

<a id="TH02"></a>
### 002. TH02 — Chèn giữa khi đang giữ con trỏ cuốn

**Phụ trách:** Thái · **Ưu tiên:** P1 · **Phạm vi:** Hiện tại.

**Trọng tâm:** c — Đầu sách và cuốn.

**Chỉ vào code:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [ThemDauSach, dòng 60](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L60).

**Câu chính:** Mảng tên tăng đang là Cau truc, Lap trinh, Toan. Một hàm đang giữ con trỏ tới cuốn của Lap trinh và chỉ số đầu sách là 1. Thêm Dai so thành công. Con trỏ và chỉ số cũ còn dùng được thế nào? Chỉ vòng dịch và phân tích việc gì thực sự tốn tuyến tính.

**Câu phụ 1:** Nếu sau chèn là một lần NAP thành công, còn được dùng con trỏ cũ không?

[Mở đáp án TH02](02_DAP_AN.md#TH02) · [Về đầu phần](#thai)

<a id="TH05"></a>
### 003. TH05 — Mã có lỗ sau khi mở lại file

**Phụ trách:** Thái · **Ưu tiên:** P1 · **Phạm vi:** Hiện tại.

**Trọng tâm:** c — Mã và tra cứu.

**Chỉ vào code:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [SinhMaSachTuDong, dòng 56](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L56).

**Câu chính:** Đầu A có đúng A#1, A#3 và mã cũ S001; các liên kết đều hợp lệ. Lưu rồi mở lại, thêm hai cuốn liên tiếp. Dự đoán hai mã mới và nêu vì sao chỉ đếm nút có thể tình cờ đúng ở lượt đầu nhưng không phải quy tắc đúng. Hàm hiện tại có quét ngoài A không?

**Câu phụ 1:** Nếu A#3 đang thanh lý thì mã mới có hạ về A#2 không?

[Mở đáp án TH05](02_DAP_AN.md#TH05) · [Về đầu phần](#thai)

<a id="TH06"></a>
### 004. TH06 — Tên tăng không có nghĩa ISBN tăng

**Phụ trách:** Thái · **Ưu tiên:** P1 · **Phạm vi:** Hiện tại.

**Trọng tâm:** c — Mã và tra cứu.

**Chỉ vào code:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [TimCuonSachToanCuc, dòng 27](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L27), [TimCuonSachToanCuc, dòng 48](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L48); [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [TimDauSachTheoISBN, dòng 50](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L50).

**Câu chính:** Mảng tên tăng chứa ISBN Z ở tên An, ISBN A ở tên Binh, ISBN M ở tên Cuong. Cần tìm A#2 và mã cũ S005 thuộc M. Hãy truy nhánh tìm thực tế; nếu thay tìm ISBN bằng nhị phân ngay trên mảng này, ví dụ nào bị bỏ sót và chi phí đúng hiện tại là gì?

**Câu phụ 1:** Thêm chỉ mục ISBN tạm có cho phép bỏ kiểm tương ứng giữa index và kho sau chèn không?

[Mở đáp án TH06](02_DAP_AN.md#TH06) · [Về đầu phần](#thai)

<a id="TH13"></a>
### 005. TH13 — Đếm chuỗi thành công và thất bại

**Phụ trách:** Thái · **Ưu tiên:** P1 · **Phạm vi:** Hiện tại.

**Trọng tâm:** j — Top10.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InTop10SachDuocMuonNhieuNhat, dòng 168](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L168); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KetThucMuon, dòng 50](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L50).

**Câu chính:** ISBN A có một cuốn: An mượn 01/10, trả 03/10; Bình mượn 03/10, báo mất 05/10; Cường xin mượn cuốn đó 06/10 bị từ chối. ISBN B có bốn cuốn chưa mượn. Dự đoán top và số nút lịch sử; tại sao trả, mất và yêu cầu bị từ chối không làm tăng giống nhau?

**Câu phụ 1:** Một yêu cầu mượn thất bại có được cộng vào báo cáo nhu cầu nếu vẫn gọi nó là top hiện tại không?

[Mở đáp án TH13](02_DAP_AN.md#TH13) · [Về đầu phần](#thai)

<a id="TH14"></a>
### 006. TH14 — Ranh giới thứ mười có ba đầu cùng tên

**Phụ trách:** Thái · **Ưu tiên:** P1 · **Phạm vi:** Hiện tại.

**Trọng tâm:** j — Top10.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InTop10SachDuocMuonNhieuNhat, dòng 168](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L168); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [DauSachXepTruoc, dòng 103](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L103).

**Câu chính:** Chín đầu có số lượt lớn hơn 1; A/B/C cùng tên Lap trinh và cùng 1 lượt, còn một đầu 0 lượt. Truy vòng chọn top: ai ở vị trí thứ mười, k biểu diễn gì và vì sao last không được bằng 10 khi mảng đã đủ? Nếu thầy đổi yêu cầu thành in mọi đầu đồng lượt ở ngưỡng thứ mười, phải đổi tiêu chí chọn thế nào; chỉ tăng kích thước mảng có đủ không?

**Câu phụ 1:** Hai đầu A và B đều 1 lượt, tên lưu lần lượt "  LAP   TRINH " và "lap trinh" trong file hợp lệ. Vì sao nhìn tên gốc có thể đoán sai đầu ở ngưỡng, và comparator thực chọn ai?

[Mở đáp án TH14](02_DAP_AN.md#TH14) · [Về đầu phần](#thai)

<a id="TH37"></a>
### 007. TH37 — Kho gần đầy, lỗi nào được báo và lúc nào dữ liệu đổi?

**Phụ trách:** Thái · **Ưu tiên:** P1 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Kho gần đầy, lỗi nào được báo và lúc nào dữ liệu đổi?.

**Chỉ vào code:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [ThemDauSach, dòng 60](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L60); [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [TimViTriChenTheoTen, dòng 39](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L39).

**Câu chính:** Kho còn một ô đầu sách. Thủ thư thêm Z hợp lệ, rồi thêm một đầu có ISBN trùng nhưng tên khác. Thầy chỉ vào ba nhánh đầy, trùng và vòng dịch: vì sao lần sau báo đầy trước trùng; chuyển kiểm đầy xuống sau vòng dịch có thể gây gì? Thiết kế hợp đồng nếu muốn báo đủ các lỗi mà vẫn không ghi quá mảng.

**Câu phụ 1:** Hết chỗ nhưng dữ liệu nhập cũng sai: có cần chạy vòng dịch để tìm đủ lỗi không?

[Mở đáp án TH37](02_DAP_AN.md#TH37) · [Về đầu phần](#thai)

<a id="TH41"></a>
### 008. TH41 — Gộp ISBN nhìn giống nhau có thể đổi lịch sử của ai?

**Phụ trách:** Thái · **Ưu tiên:** P1 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** Gộp ISBN nhìn giống nhau có thể đổi lịch sử của ai?.

**Chỉ vào code:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [TimDauSachTheoISBN, dòng 50](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L50); [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [TachMaMoi, dòng 5](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L5); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [TimChuSoHuu, dòng 94](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L94).

**Câu chính:** Kho đang có ISBN 0012 và 12, ab và AB; mỗi đầu có cuốn và lịch sử riêng. Một bạn muốn chuyển ISBN sang số hoặc hạ chữ để tránh trùng khi nhập. Theo code hiện tại các cặp có trùng không? Nếu áp quy tắc mới chỉ lúc tìm cuốn mà không chuyển dữ liệu, tên tìm thấy, chủ cuốn và top có thể lệch thế nào? Nêu việc phải chốt trước khi gộp.

**Câu phụ 1:** Nếu chỉ đổi nhãn ISBN trên màn hình thành số nhưng API vẫn nhận chuỗi gốc thì nguy cơ còn lại là gì?

[Mở đáp án TH41](02_DAP_AN.md#TH41) · [Về đầu phần](#thai)

<a id="TH46"></a>
### 009. TH46 — Tem sách in thêm số 0: sửa dữ liệu hay sửa đầu vào?

**Phụ trách:** Thái · **Ưu tiên:** P1 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Tem sách in thêm số 0: sửa dữ liệu hay sửa đầu vào?.

**Chỉ vào code:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [TachMaMoi, dòng 5](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L5); [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [TimCuonSachToanCuc, dòng 27](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L27), [TimCuonSachToanCuc, dòng 48](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L48); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [MaSinhDungDauSach, dòng 43](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L43); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KetThucMuon, dòng 50](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L50).

**Câu chính:** Tem ngoài đời ghi A#01 nhưng kho/lịch sử có A#1. Thủ thư quét tem để trả, bị không tìm thấy. Thầy hỏi có nên cho mọi mã có # sai định dạng rơi sang tìm legacy hoặc tự bỏ số 0 không; nếu file lại có A#01 thật thì sao? Phân tích ranh giới chấp nhận đầu vào và định danh đã lưu.

**Câu phụ 1:** Quét A#0 thay vì A#01 có được nhận như mã legacy không?

[Mở đáp án TH46](02_DAP_AN.md#TH46) · [Về đầu phần](#thai)

<a id="TH61"></a>
### 010. TH61 — Trả một phần làm người đứng đầu bảng chuyển vị trí thế nào?

**Phụ trách:** Thái · **Ưu tiên:** P1 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Trả một phần làm người đứng đầu bảng chuyển vị trí thế nào?.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InDocGiaQuaHan, dòng 144](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L144); [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [CoSachQuaHan7Ngay, dòng 8](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L8); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110).

**Câu chính:** Ngày 16/10/2026, An mã 20 giữ X từ 01/10 và Y từ 08/10; Bình mã 10 giữ Z từ 04/10. So sánh hai lượt chạy độc lập: An trả Y trước hoặc trả X trước, rồi xin W đang rảnh. Dự đoán thứ hạng, số cuốn quá hạn và quyền mượn; chỉ vì sao giảm số cuốn không đồng nghĩa hết quá hạn.

**Câu phụ 1:** Nếu chỉ còn một cuốn đúng 7 ngày thì A đã hết điều kiện quá hạn chưa?

[Mở đáp án TH61](02_DAP_AN.md#TH61) · [Về đầu phần](#thai)

<a id="TH15"></a>
### 011. TH15 — Hủy khi mới thêm một phần danh mục

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** c — Đầu sách và cuốn.

**Chỉ vào code:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [ManHinhNhapDauSach, dòng 124](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L124); [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [ThemCuonSach, dòng 71](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L71).

**Câu chính:** Từ thư viện trống, trong --plain thêm đầu A, yêu cầu ba cuốn, thêm xong cuốn thứ nhất rồi /huy ở vị trí cuốn thứ hai. Sau đó tìm A và gọi top. TUI mới tạo đầu và từng cuốn qua các form riêng: hủy form cuốn thứ hai có cùng kết quả không? So với hủy form đầu sách trước khi xác nhận. Nếu muốn cả đầu và ba cuốn cùng thành công hoặc cùng hủy, phạm vi chuẩn bị/commit phải thay đổi ở đâu?

**Câu phụ 1:** Sau hủy cuốn thứ hai rồi thêm cuốn nữa, có được bỏ qua cuốn đầu đã commit khi tính mã không?

[Mở đáp án TH15](02_DAP_AN.md#TH15) · [Về đầu phần](#thai)

<a id="TH16"></a>
### 012. TH16 — Mã chuẩn bị đặt nhầm đầu sách

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** c — Mã và tra cứu.

**Chỉ vào code:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [TimCuonSachToanCuc, dòng 27](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L27), [TimCuonSachToanCuc, dòng 48](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L48); [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [SinhMaSachTuDong, dòng 56](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L56); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [MaSinhDungDauSach, dòng 43](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L43).

**Câu chính:** Bản sao RAM đặt A#2 dưới đầu B, còn đầu A không chứa mã đó. Tra A#2, rồi kiểm toàn vẹn và thử lưu. Kết quả từng bước là gì? Nếu thêm cuốn mới vào A trước khi sửa lỗi, bộ sinh mã chọn hậu tố nào? Phân biệt chống trùng với sửa quyền sở hữu.

**Câu phụ 1:** Nếu cho tra A#2 fallback sang mọi đầu và tìm được dưới B, lỗi quyền sở hữu đã được giải quyết chưa?

[Mở đáp án TH16](02_DAP_AN.md#TH16) · [Về đầu phần](#thai)

<a id="TH19"></a>
### 013. TH19 — Đảo comparator khi vun đống

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** i — Quá hạn.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [VunDong, dòng 75](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L75); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [SapXepHeap, dòng 84](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L84); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InDocGiaQuaHan, dòng 144](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L144).

**Câu chính:** Bốn dòng quá hạn có cặp (mã thẻ, ngày): (20,11), (10,7), (5,7), (30,6). Thầy chỉ vào VunDong và hỏi vì sao phần tử ở gốc lại là phần cần đứng cuối. Hãy truy lần dựng/rút đầu tiên; nếu đảo riêng điều kiện chọn con nhưng giữ phần còn lại, kết quả có còn được bảo đảm không?

**Câu phụ 1:** Nếu mọi dòng có cùng mức quá hạn, test có còn phát hiện sai comparator không?

[Mở đáp án TH19](02_DAP_AN.md#TH19) · [Về đầu phần](#thai)

<a id="TH20"></a>
### 014. TH20 — Chỉ mục tạm với mã cũ và mã mới

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** j — Top10.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InTop10SachDuocMuonNhieuNhat, dòng 168](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L168); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [TimChuSoHuu, dòng 94](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L94).

**Câu chính:** Đầu A chứa A#2/A#10; đầu B chứa S001. Lịch sử có ba mã này, mỗi mã một lượt. Hãy chỉ thứ tự chỉ mục sau heap sort, đường tìm của từng lịch sử và tổng mỗi đầu. Sắp mã theo hậu tố số riêng rồi dùng TimChuSoHuu nguyên trạng có còn hợp lệ không?

**Câu phụ 1:** Bỏ chỉ số chủ trong mỗi ô index rồi suy từ vị trí sau sort có đúng không?

[Mở đáp án TH20](02_DAP_AN.md#TH20) · [Về đầu phần](#thai)

<a id="TH21"></a>
### 015. TH21 — Có lịch sử nhưng mã cuốn biến mất

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** j — Top10.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InTop10SachDuocMuonNhieuNhat, dòng 168](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L168); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90).

**Câu chính:** Trên bản sao RAM, lịch sử An giữ mã S001 nhưng danh mục đã bị xóa mất cuốn S001; một đầu khác có nhiều lượt hợp lệ. Gọi top 10 rồi lưu. Hàm có xuất bảng top thiếu S001 không? Chỉ nơi phát hiện, ảnh hưởng dữ liệu và phân biệt báo lỗi với khả năng tự khôi phục.

**Câu phụ 1:** Nếu thay owner<0 bằng owner=0 để luôn in được top, tổng số lượt có thể vẫn đúng không và oracle nào bắt sai?

[Mở đáp án TH21](02_DAP_AN.md#TH21) · [Về đầu phần](#thai)

<a id="TH22"></a>
### 016. TH22 — Vì sao một vòng lịch sử không phải O(H)

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** j — Top10.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InTop10SachDuocMuonNhieuNhat, dòng 168](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L168); [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [TimCuonSachToanCuc, dòng 27](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L27), [TimCuonSachToanCuc, dòng 48](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L48); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [LayDanhSachDocGia, dòng 13](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L13).

**Câu chính:** Thầy đưa dữ liệu gồm D đầu, C cuốn, R độc giả và H lượt, trong đó hầu hết dùng mã cũ. Hãy đi từng khối của InTop10SachDuocMuonNhieuNhat để tính thời gian/bộ nhớ. Nếu H tăng gấp đôi nhưng C giữ nguyên, phần nào tăng và phần nào không? Có sắp toàn bộ D đầu theo lượt không? So với bỏ chỉ mục và gọi TimCuonSachToanCuc cho từng lượt legacy, tiết kiệm được bộ nhớ nào nhưng phải trả thêm thời gian nào?

**Câu phụ 1:** R nhỏ nhưng H lớn có cho bỏ hạng H log C khỏi phân tích không?

[Mở đáp án TH22](02_DAP_AN.md#TH22) · [Về đầu phần](#thai)

<a id="TH27"></a>
### 017. TH27 — Đổi tên khi cuốn đã có lịch sử

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** Sửa trên bản sao — c.

**Chỉ vào code:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [TimViTriChenTheoTen, dòng 39](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L39); [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [ThemDauSach, dòng 60](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L60); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InTop10SachDuocMuonNhieuNhat, dòng 168](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L168).

**Câu chính:** Trên bản sao, thêm thao tác đổi tên đầu sách theo ISBN; được đổi tên nhưng không đổi ISBN, địa chỉ các cuốn hay lịch sử. Đổi Toan thành An trong mảng đang có Binh, Cuong, Toan; sau đó thêm Dau so và chạy tìm/top. Hãy tự thiết kế cài đặt và test để mọi bất biến còn đúng.

**Câu phụ 1:** Nếu đổi tên làm khóa so sánh bằng đầu khác nhưng ISBN khác thì có phải từ chối trùng tên không?

[Mở đáp án TH27](02_DAP_AN.md#TH27) · [Về đầu phần](#thai)

<a id="TH28"></a>
### 018. TH28 — Báo cáo hôm qua sau khi trả hôm nay

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Ghép báo cáo với trạng thái.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InDocGiaQuaHan, dòng 144](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L144).

**Câu chính:** An mượn A#1 ngày 01/10/2026 và trả ngày 16/10. Sau khi đã trả, gọi InDocGiaQuaHan với ngày 15/10. Bản hiện tại có tái dựng việc An từng giữ quá hạn hôm qua không? Hãy chỉ điều kiện lọc, phân biệt tham số ngày đối chiếu với báo cáo lịch sử và đề xuất test để tránh mô tả quá khả năng.

**Câu phụ 1:** Gọi cùng ngày 15/10 trên bản sao trước thao tác trả có ra khác sau trả không?

[Mở đáp án TH28](02_DAP_AN.md#TH28) · [Về đầu phần](#thai)

<a id="TH38"></a>
### 019. TH38 — Tìm chỗ chèn đúng khi tên hòa và ở cuối mảng

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Tìm chỗ chèn đúng khi tên hòa và ở cuối mảng.

**Chỉ vào code:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [TimViTriChenTheoTen, dòng 39](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L39); [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [SoSanhDauSach, dòng 5](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L5); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [SachTruoc, dòng 19](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L19).

**Câu chính:** Kho có A/ ISBN 1, M/ ISBN 2, Z/ ISBN 3. Cần thêm Z/ ISBN 9 rồi Zz/ ISBN 4. Thầy chỉ left=0, right=soLuong: hãy nêu khoảng chỉ số còn có thể chứa vị trí chèn sau mỗi nhánh, giải thích vì sao kết quả có thể bằng soLuong mà không đọc ô đó. Nếu đổi comparator chỉ so tên nhưng giữ các phần khác, lưu/kiểm toàn vẹn có còn nhất quán?

**Câu phụ 1:** Ở một vòng, phần tử mid đứng trước đầu mới. Vì sao phải đặt left=mid+1, còn khi không đứng trước lại đặt right=mid? Dùng nhóm cùng tên nhưng ISBN khác để giải thích.

[Mở đáp án TH38](02_DAP_AN.md#TH38) · [Về đầu phần](#thai)

<a id="TH39"></a>
### 020. TH39 — Dịch mảng sai chiều làm mất con trỏ

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** c · Đầu sách, mã cuốn và quyền sở hữu.

**Chỉ vào code:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [ThemDauSach, dòng 60](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L60); [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [HuyDanhSachDauSach, dòng 116](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L116).

**Câu chính:** Trên bản sao, đổi vòng dịch khi chèn B vào A,C,E thành duyệt từ pos lên cuối. Ba con trỏ sau dịch có thể thế nào? Liên hệ việc hủy thư viện sau đó.

**Câu phụ 1:** Dịch ngược đúng nhưng soLuong tăng trước kiểm capacity thì rủi ro nào còn?

[Mở đáp án TH39](02_DAP_AN.md#TH39) · [Về đầu phần](#thai)

<a id="TH40"></a>
### 021. TH40 — Nhập danh mục từ công cụ khác: ai sở hữu các cuốn?

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** Nhập danh mục từ công cụ khác: ai sở hữu các cuốn?.

**Chỉ vào code:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [ThemDauSach, dòng 60](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L60); [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [ThemCuonSach, dòng 71](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L71); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [DauSach, dòng 274](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L274).

**Câu chính:** Một công cụ nhập liệu dựng DauSach tạm với hai cuốn và muốn gọi ThemDauSach để chuyển cả cụm vào thư viện. Hàm từ chối vì dms khác null. Thầy hỏi vì sao không bỏ điều kiện đó rồi dùng phép gán struct; nếu muốn hỗ trợ nhập nguyên cụm, phải chốt copy hay chuyển quyền sở hữu và xử lý cuốn thứ hai sai ra sao?

**Câu phụ 1:** Khi ThemDauSach từ chối dms khác null, ai phải dọn hai cuốn tạm?

[Mở đáp án TH40](02_DAP_AN.md#TH40) · [Về đầu phần](#thai)

<a id="TH43"></a>
### 022. TH43 — Tái dùng số của sách thanh lý có thật sự tiết kiệm?

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Tái dùng số của sách thanh lý có thật sự tiết kiệm?.

**Chỉ vào code:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [SinhMaSachTuDong, dòng 56](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L56); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InTop10SachDuocMuonNhieuNhat, dòng 168](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L168); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90).

**Câu chính:** A có A#1 sẵn sàng, A#9 thanh lý sau báo mất và lịch sử vẫn tham chiếu A#9. Thầy đề nghị lấy số cuốn đang dùng+1 hoặc tái dùng #9 cho sách mua thay thế. So với SinhMaSachTuDong, hai cách đó đổi ý nghĩa lịch sử/ top thế nào? Có thể mua bản thay thế mà giữ dấu vết cuốn mất không?

**Câu phụ 1:** Thêm A#10 có tự tăng top của đầu A không?

[Mở đáp án TH43](02_DAP_AN.md#TH43) · [Về đầu phần](#thai)

<a id="TH48"></a>
### 023. TH48 — Mã xem trước đã hiện nhưng đầu sách chưa được tạo

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** Mã xem trước đã hiện nhưng đầu sách chưa được tạo.

**Chỉ vào code:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [SinhMaSachTuDong, dòng 56](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L56); [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [ThemCuonSach, dòng 71](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L71); [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [ThemDauSach, dòng 60](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L60).

**Câu chính:** Một form mới dựng DauSach ISBN X trong biến tạm, kho chưa có X hoặc mã X#n nhưng mảng đầu sách đã đầy. Form gọi SinhMaSachTuDong và hiện X#1 trước khi thêm đầu. Sau đó ThemDauSach thất bại vì kho đầy. Helper bảo đảm điều gì; UI có được coi X#1 là mã đã cấp không? So với ThemCuonSach thành công và chỉ điểm thiếu trong hợp đồng preview.

**Câu phụ 1:** Hai lần gọi helper preview mà không thêm cuốn có thể trả cùng mã không?

[Mở đáp án TH48](02_DAP_AN.md#TH48) · [Về đầu phần](#thai)

<a id="TH53"></a>
### 024. TH53 — Tìm chuỗi con có dùng được khoảng nhị phân của tên?

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Tìm chuỗi con có dùng được khoảng nhị phân của tên?.

**Chỉ vào code:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [TimDauSachTheoTen, dòng 80](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L80); [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [TimViTriChenTheoTen, dòng 39](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L39); [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [ChuaChuoi, dòng 27](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L27).

**Câu chính:** Kho theo tên gồm An toan, Cau truc, Lap trinh an toan, Toan roi rac. Thầy đề nghị gặp An toan rồi dừng khi Cau truc không khớp để tăng tốc. Hãy chỉ kết quả mất, giải thích tập tên chứa từ khóa có liên tiếp trong thứ tự hiện tại không. So sánh điều kiện để dùng lower bound cho tên chính xác hoặc tiền tố.

**Câu phụ 1:** Nếu từ khóa xuất hiện nhiều lần trong cùng tên, đầu đó có xuất hiện nhiều lần trong kết quả không?

[Mở đáp án TH53](02_DAP_AN.md#TH53) · [Về đầu phần](#thai)

<a id="TH54"></a>
### 025. TH54 — Một kết quả tìm kiếm đại diện đầu sách hay bản vật lý?

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** Một kết quả tìm kiếm đại diện đầu sách hay bản vật lý?.

**Chỉ vào code:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [TimDauSachTheoTen, dòng 80](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L80); [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [InMotDauSach, dòng 10](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L10); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110).

**Câu chính:** Tên 'C C C' có bốn cuốn, chỉ một sẵn sàng; một đầu khác khớp C chưa có cuốn. Thầy muốn màn hình ghi '2 kết quả, 1 cuốn có thể mượn'. Số n hiện tại trả lời đại lượng nào? Nếu gộp vòng khớp tên, in cuốn và đếm khả dụng vào một bộ đếm, lỗi nào xuất hiện; thiết kế tính số liệu mà không đổi quyền mượn.

**Câu phụ 1:** Một cuốn trạng thái 0 có chắc được mọi độc giả mượn không?

[Mở đáp án TH54](02_DAP_AN.md#TH54) · [Về đầu phần](#thai)

<a id="TH55"></a>
### 026. TH55 — Dán tên từ tài liệu: tìm thấy không có nghĩa dữ liệu được nhận

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Dán tên từ tài liệu: tìm thấy không có nghĩa dữ liệu được nhận.

**Chỉ vào code:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [ChuaChuoi, dòng 27](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L27); [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [HopLeVanBan, dòng 38](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L38); [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [ThemDauSach, dòng 60](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L60).

**Câu chính:** Kho có 'Lap trinh C'. Người dùng dán truy vấn có tab giữa Lap và trinh rồi tìm thấy; nhưng thêm đầu sách mới với tên chứa đúng tab đó lại bị từ chối. Thầy chỉ ChuaChuoi, HopLeDauSach và hỏi hai hành vi có mâu thuẫn không; nếu thống nhất bằng cách bỏ kiểm dữ liệu gốc thì ảnh hưởng lưu file và quy ước nhập thế nào?

**Câu phụ 1:** Dữ liệu raw chứa newline nhưng sau chuẩn hóa trông đẹp có nên mặc nhiên nhận không?

[Mở đáp án TH55](02_DAP_AN.md#TH55) · [Về đầu phần](#thai)

<a id="TH57"></a>
### 027. TH57 — Sửa một cận tìm kiếm làm mất cả nhóm tài liệu

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Sửa một cận tìm kiếm làm mất cả nhóm tài liệu.

**Chỉ vào code:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [ChuaChuoi, dòng 27](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L27).

**Câu chính:** Sau refactor, người dùng tìm 'DEF' trong 'ABCDEF' không thấy, tìm nguyên tên cũng không thấy, nhưng từ khóa ở giữa vẫn thấy. Thầy chỉ vòng ngoài ChuaChuoi và yêu cầu khoanh vùng bằng ba ví dụ trước khi sửa. Vì sao đổi <= thành < gây mẫu lỗi đó; muốn giảm so sánh có được bỏ vị trí cuối không?

**Câu phụ 1:** Một từ khóa dài hơn tên nên kết thúc trước hay sau phép trừ size?

[Mở đáp án TH57](02_DAP_AN.md#TH57) · [Về đầu phần](#thai)

<a id="TH62"></a>
### 028. TH62 — Đồng mức quá hạn nhưng số cuốn khác: công bằng theo quy tắc nào?

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** Đồng mức quá hạn nhưng số cuốn khác: công bằng theo quy tắc nào?.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InDocGiaQuaHan, dòng 144](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L144); [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [CoSachQuaHan7Ngay, dòng 8](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L8).

**Câu chính:** A mã 20 giữ ba cuốn đều quá hạn 2 ngày; B mã 10 giữ một cuốn quá hạn 2 ngày. Thầy đề nghị ưu tiên A vì tổng ảnh hưởng lớn hơn. Code hiện dùng khóa nào, sau A trả hai cuốn thứ tự có đổi không? Nếu chấp nhận đề xuất, so sánh thêm số cuốn làm khóa phụ với đổi điểm sang tổng ngày; dùng phản ví dụ cho thấy hai cách khác nhau. Nếu thầy chốt tính tổng, hãy xác định phần gom, comparator, nhãn và test phải đổi trên bản sao, đồng thời giữ nguyên điều kiện cấm mượn.

**Câu phụ 1:** Thêm số cuốn làm khóa phụ mà quên cập nhật nhãn báo cáo gây hiểu nhầm gì?

[Mở đáp án TH62](02_DAP_AN.md#TH62) · [Về đầu phần](#thai)

<a id="TH63"></a>
### 029. TH63 — Ẩn thẻ khóa có che nghĩa vụ trả sách còn lại?

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** Ẩn thẻ khóa có che nghĩa vụ trả sách còn lại?.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InDocGiaQuaHan, dòng 144](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L144); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KetThucMuon, dòng 50](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L50); [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [LietKeSachDangMuon, dòng 20](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L20).

**Câu chính:** A báo mất X nên thẻ khóa; Y của A còn quá hạn, Z chưa quá hạn. Thủ thư bật đề xuất 'chỉ hiện thẻ hoạt động' cho danh sách độc giả rồi muốn tái dùng danh sách đó để in quá hạn. Theo code hiện tại i/h và trả Y/Z hoạt động thế nào? Vì sao tối ưu tái dùng view lọc này sai nghiệp vụ?

**Câu phụ 1:** Ẩn A khỏi danh sách liên hệ có thể dùng làm đầu vào duy nhất cho kiểm toàn vẹn không?

[Mở đáp án TH63](02_DAP_AN.md#TH63) · [Về đầu phần](#thai)

<a id="TH72"></a>
### 030. TH72 — Dọn độc giả cũ có thể làm thống kê giảm mà kho không đổi

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** Dọn độc giả cũ có thể làm thống kê giảm mà kho không đổi.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [XoaDocGia, dòng 80](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L80); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [HieuChinhDocGia, dòng 68](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L68); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InTop10SachDuocMuonNhieuNhat, dòng 168](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L168).

**Câu chính:** A chưa có lịch sử, B đã trả hết 10 lượt. Quản trị muốn xóa cả hai để danh sách gọn, rồi so top trước/sau. Code cho phép ai; nếu đổi điều kiện xóa thành 'không giữ cuốn nào', vì sao danh mục cuốn không đổi nhưng top vẫn giảm? Đề xuất cách quản lý ngừng hoạt động phù hợp cấu trúc hiện tại.

**Câu phụ 1:** Khóa thẻ B có làm top giảm 10 lượt không?

[Mở đáp án TH72](02_DAP_AN.md#TH72) · [Về đầu phần](#thai)

<a id="TH74"></a>
### 031. TH74 — Đổi kiểu so ISBN chỉ ở top phá hợp đồng hòa thế nào?

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Đổi kiểu so ISBN chỉ ở top phá hợp đồng hòa thế nào?.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [DauSachXepTruoc, dòng 103](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L103); [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [SoSanhDauSach, dòng 5](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L5); [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [HopLeDauSach, dòng 23](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L23).

**Câu chính:** Hai đầu cùng tên chuẩn hóa và 5 lượt, ISBN '10' và '2'. Thành viên sửa top để so số còn tìm ISBN /file giữ chuỗi; thêm ISBN '02' và 'AB'. Thầy yêu cầu quy tắc phá hòa áp dụng cho toàn miền mã và kết quả xác định sau lưu–nạp. Vì sao chỉ dùng chuyển sang int không đủ, và có cần stable sort không?

**Câu phụ 1:** Nếu bỏ ISBN khỏi comparator nhưng dùng sort ổn định trên đúng mảng gốc đang tăng tên–ISBN, các đầu cùng số lượt và cùng khóa tên có giữ ISBN tăng không? Sau NAP còn đúng không?

[Mở đáp án TH74](02_DAP_AN.md#TH74) · [Về đầu phần](#thai)

<a id="TH93"></a>
### 032. TH93 — Nạp file đầu sách lộn thứ tự

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** c · Đầu sách, mã cuốn và quyền sở hữu.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [DocNoiBo, dòng 210](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L210); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490).

**Câu chính:** File có thứ tự tên Z,A,M nhưng mã và lịch sử đều hợp lệ. Bộ đọc từ chối ngay vì thứ tự sai, hay sắp trước rồi kiểm? Vì sao điều này khác sửa trực tiếp mảng RAM thành Z,A,M? Nếu chạy --check, thứ tự trong file gốc có bị ghi lại không?

**Câu phụ 1:** Sau --check thành công rồi mở file bằng editor, thứ tự Z,A,M còn đó có phải --check sai không?

[Mở đáp án TH93](02_DAP_AN.md#TH93) · [Về đầu phần](#thai)

<a id="TH97"></a>
### 033. TH97 — Tìm thấy tên nhưng cả hai người đều chưa chắc mượn được

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Tìm thấy tên nhưng cả hai người đều chưa chắc mượn được.

**Chỉ vào code:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [TimDauSachTheoTen, dòng 80](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L80); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110).

**Câu chính:** Đầu A có A#1 thanh lý, A#2 rảnh, A#3 đang do C giữ. An đang quá hạn ở đầu khác, Bình đủ điều kiện; cả hai tìm A rồi lần lượt xin A#2. Thầy hỏi kết quả tìm có phải danh sách 'được phép mượn' không, ai được A#2, và nếu UI giấu mọi cuốn không rảnh thì mất thông tin nào?

**Câu phụ 1:** An bị chặn trước khi tìm mã cuốn thì cuốn rảnh có bị giữ chỗ cho An không?

[Mở đáp án TH97](02_DAP_AN.md#TH97) · [Về đầu phần](#thai)

<a id="TH202"></a>
### 034. TH202 — Hai sách khác nội dung nhưng cùng tên

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** c — Danh tính.

**Chỉ vào code:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [ThemDauSach, dòng 60](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L60); [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [TimDauSachTheoTen, dòng 80](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L80).

**Câu chính:** Hai đầu ISBN A/B đều tên Cấu trúc dữ liệu nhưng khác tác giả và số trang, mỗi đầu có cuốn riêng. Thủ thư định chặn tên trùng ngay khi nhập vì tìm tên trả hai dòng. Bản hiện cho thêm cả hai không, và phải dùng thông tin nào khi chọn cuốn để mượn?

**Câu phụ 1:** Nếu cả tác giả và số trang cũng giống nhau, có đủ bằng chứng để tự gộp A/B không?

[Mở đáp án TH202](02_DAP_AN.md#TH202) · [Về đầu phần](#thai)

<a id="TH203"></a>
### 035. TH203 — Chèn đầu mới khi mã sách đang được tra theo chỉ số phụ

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** c — Chỉ mục ISBN.

**Chỉ vào code:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [TimDauSachTheoISBN, dòng 50](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L50); [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [ThemDauSach, dòng 60](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L60).

**Câu chính:** Để tra ISBN nhanh trong giới hạn mảng tên, đề xuất mảng phụ sắp ISBN, mỗi phần tử giữ vị trí trong mảng gốc. Khi chèn một đầu ở đầu mảng, phần nào phải cập nhật? So với mảng phụ giữ con trỏ DauSach; nêu điều kiện để dùng cho bản nộp.

**Câu phụ 1:** Tìm ISBN còn O(log D) có làm thêm đầu thành O(log D) không?

[Mở đáp án TH203](02_DAP_AN.md#TH203) · [Về đầu phần](#thai)

<a id="TH204"></a>
### 036. TH204 — So sánh sau khi đã chuẩn bị có thể vẫn cấp phát

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** c — Ngoại lệ comparator.

**Chỉ vào code:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [ThemDauSach, dòng 60](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L60); [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [TimViTriChenTheoTen, dòng 39](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L39); [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [SoSanhChuoi, dòng 23](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L23); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [ConTroTam, dòng 29](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L29), [ConTroTam, dòng 42](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L42).

**Câu chính:** Trong ThemDauSach, các chuỗi của node mới đã gán xong nhưng TimViTriChenTheoTen gọi SoSanhChuoi. Giả lập tạo khóa so sánh thất bại đúng lúc tìm vị trí. Mảng có bị dịch một phần không? Đưa tìm vị trí vào giữa vòng dịch làm thay đổi bảo đảm nào?

**Câu phụ 1:** Ghi chú “mọi cấp phát đã xong” tại dòng commit có bao gồm việc in thông báo sau hàm không?

[Mở đáp án TH204](02_DAP_AN.md#TH204) · [Về đầu phần](#thai)

<a id="TH205"></a>
### 037. TH205 — Chuẩn hóa từ khóa một lần hay một lần mỗi đầu

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** e — Công việc lặp.

**Chỉ vào code:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [TimDauSachTheoTen, dòng 80](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L80); [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [ChuaChuoi, dòng 27](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L27).

**Câu chính:** Một truy vấn dài M byte tìm trên D đầu, mỗi tên tối đa L byte. TimDauSachTheoTen đã chuẩn hóa ten nhưng ChuaChuoi lại tạo khóa của part mỗi lần gọi. Muốn bỏ công việc dư nào mà vẫn giữ đúng tìm chuỗi con? So với lưu khóa tên lâu dài.

**Câu phụ 1:** Truy vấn chỉ có một ký tự có chứng minh tối ưu này đáng làm không?

[Mở đáp án TH205](02_DAP_AN.md#TH205) · [Về đầu phần](#thai)

<a id="TH206"></a>
### 038. TH206 — In lại báo cáo khi stream đã báo lỗi

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** e — Xuất kết quả.

**Chỉ vào code:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [TimDauSachTheoTen, dòng 80](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L80); [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [InMotDauSach, dòng 10](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L10); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [LuongChuoi, dòng 70](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L70).

**Câu chính:** Một caller truyền ostream đã có failbit vào TimDauSachTheoTen cho truy vấn khớp hai đầu. Hàm có trả trạng thái thất bại không? Số n đếm được có chứng minh người nhận đã thấy đủ dữ liệu, và API báo cáo cần đổi gì nếu phải bảo đảm xuất đầy đủ?

**Câu phụ 1:** Bật exceptions cho stream rồi bắt bên ngoài có làm báo cáo nguyên khối không?

[Mở đáp án TH206](02_DAP_AN.md#TH206) · [Về đầu phần](#thai)

<a id="TH207"></a>
### 039. TH207 — Tìm tên trên kho lớn với rất ít kết quả

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** e — Chi phí đầu ra.

**Chỉ vào code:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [TimDauSachTheoTen, dòng 80](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L80); [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [InMotDauSach, dòng 10](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L10); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [LuongChuoi, dòng 70](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L70).

**Câu chính:** D=10.000 đầu, C=200.000 cuốn, chỉ một tên khớp nhưng đầu đó chứa 150.000 cuốn. Một người nói tìm chỉ ra một đầu nên báo cáo nhỏ. Hãy tách chi phí khớp tên và xuất danh mục; so với một truy vấn khớp 100 đầu mỗi đầu không có cuốn.

**Câu phụ 1:** Chỉ giảm số dòng vẽ mỗi trang có giảm thời gian quét 150.000 cuốn trước trang đầu không?

[Mở đáp án TH207](02_DAP_AN.md#TH207) · [Về đầu phần](#thai)

<a id="TH208"></a>
### 040. TH208 — Danh mục không được sắp theo mã nhưng tìm trong đầu vẫn đúng

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** c — Thứ tự danh sách.

**Chỉ vào code:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [TimCuonSachTrongDauSach, dòng 18](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L18), [TimCuonSachTrongDauSach, dòng 22](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L22); [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [ThemCuonSach, dòng 71](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L71); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [DocNoiBo, dòng 210](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L210).

**Câu chính:** File hợp lệ cho đầu A chứa A#10, A#2, S7 theo thứ tự đó. Sau nạp, tìm A#2 và thêm một cuốn. Có cần sắp danh sách mã để tra đúng không? So việc duyệt hiện tại với đề xuất dừng ngay khi gặp mã lớn hơn mã cần tìm.

**Câu phụ 1:** Sắp danh sách rồi tìm nhị phân trên danh sách đơn có đạt O(log Cᵢ) thời gian không?

[Mở đáp án TH208](02_DAP_AN.md#TH208) · [Về đầu phần](#thai)

<a id="TH209"></a>
### 041. TH209 — Số cuốn trong dòng đầu sách lệch một đơn vị

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** c — Đọc file sách.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [DocNoiBo, dòng 210](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L210); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [BoDoc, dòng 51](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L51).

**Câu chính:** File khai báo đầu A có 2 cuốn nhưng thực tế chỉ có 1 dòng cuốn; dòng kế tiếp là bản ghi đầu B gồm 7 trường. Loader sẽ đọc dòng B như gì? Vì sao không thể tự giảm số cuốn rồi đọc tiếp để cứu dữ liệu?

**Câu phụ 1:** Nếu số đếm dư gặp một dòng có đúng 3 trường thì đã đủ để nhận là cuốn không?

[Mở đáp án TH209](02_DAP_AN.md#TH209) · [Về đầu phần](#thai)

<a id="TH210"></a>
### 042. TH210 — Bỏ một cuốn không có lịch sử khi ghi vẫn đọc lại được

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** c — Kiểm serialization.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [Ghi, dòng 261](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L261); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [LuuNoiBo, dòng 278](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L278).

**Câu chính:** Trên bản sao, Ghi vô tình bỏ cuốn cuối đang rảnh và đồng thời ghi số cuốn giảm một; cuốn đó chưa có lịch sử. File tạm vẫn qua DocNoiBo. Cơ chế đọc lại có phát hiện mất dữ liệu này không? Test phải so điều gì?

**Câu phụ 1:** Nếu cuốn bị bỏ đang có một phiếu mở thì khác thế nào?

[Mở đáp án TH210](02_DAP_AN.md#TH210) · [Về đầu phần](#thai)

<a id="TH211"></a>
### 043. TH211 — Bỏ một lượt cũ: top giảm nhưng kiểm liên kết vẫn xanh

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** j — Nguồn thống kê.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InTop10SachDuocMuonNhieuNhat, dòng 168](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L168); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90).

**Câu chính:** Một công cụ xuất file quên một lượt đã trả của A#1 nhưng giữ các lượt sau, cuốn hiện rảnh; các khoảng còn lại hợp lệ. Top A giảm từ 5 xuống 4, --check vẫn chấp nhận. Đây có nhất thiết là lỗi hàm top không và cần nguồn nào để phát hiện mất lượt?

**Câu phụ 1:** Một checksum của chính file thiếu có chứng minh đủ 5 lượt không?

[Mở đáp án TH211](02_DAP_AN.md#TH211) · [Về đầu phần](#thai)

<a id="TH212"></a>
### 044. TH212 — Top của hai nửa kho có ghép được không

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** j — Chọn ứng viên.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InTop10SachDuocMuonNhieuNhat, dòng 168](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L168); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [DauSachXepTruoc, dòng 103](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L103).

**Câu chính:** Để giảm bộ nhớ xếp hạng, chia tập đầu sách thành hai nửa không trùng ISBN; đã có đúng tổng lượt toàn cục của từng đầu. Chỉ giữ top 10 mỗi nửa rồi chọn top 10 trong 20 ứng viên có đúng không? Hãy nêu lập luận theo comparator hiện tại.

**Câu phụ 1:** Nếu chia theo độc giả rồi lấy top riêng của từng nửa lịch sử, lập luận còn đúng không?

[Mở đáp án TH212](02_DAP_AN.md#TH212) · [Về đầu phần](#thai)

<a id="TH213"></a>
### 045. TH213 — Tìm hai từ độc lập khác tìm cả cụm

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** e — Ngữ nghĩa truy vấn.

**Chỉ vào code:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [ChuaChuoi, dòng 27](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L27); [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [TimDauSachTheoTen, dòng 80](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L80).

**Câu chính:** Muốn tìm tên chứa cả "lap" và "trinh" ở bất kỳ vị trí, không cần liền nhau. Kho có "lap trinh", "trinh do lap", "lap rap". Gọi ChuaChuoi với chuỗi "lap trinh" có đủ không? Thiết kế hai predicate và phân biệt với OR.

**Câu phụ 1:** Hai token giống nhau sau chuẩn hóa có cần làm đầu xuất hiện hai lần không?

[Mở đáp án TH213](02_DAP_AN.md#TH213) · [Về đầu phần](#thai)

<a id="TH214"></a>
### 046. TH214 — Một đầu cực nhiều cuốn và nhiều đầu ít cuốn

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** c — Phân bố dữ liệu.

**Chỉ vào code:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [TimCuonSachToanCuc, dòng 27](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L27), [TimCuonSachToanCuc, dòng 48](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L48).

**Câu chính:** Hai kho đều D=1.000, C=100.000. Kho A có một đầu chứa 90.000 cuốn; kho B chia đều. Mỗi lần tra mã chuẩn, 90% yêu cầu hướng vào đầu lớn của A. Cùng D/C có đủ dự đoán chi phí tra trung bình bằng nhau không?

**Câu phụ 1:** Nếu toàn bộ truy vấn chuyển sang mã legacy thì lợi thế phân nhánh theo ISBN còn không?

[Mở đáp án TH214](02_DAP_AN.md#TH214) · [Về đầu phần](#thai)

<a id="TH215"></a>
### 047. TH215 — Mã chuẩn không làm lịch sử cũ tự đổi mã

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** c — Di trú mã.

**Chỉ vào code:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [TimCuonSachToanCuc, dòng 27](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L27), [TimCuonSachToanCuc, dòng 48](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L48); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90).

**Câu chính:** Kho có S001 thuộc A và 20 lượt lịch sử tham chiếu S001. Muốn đổi tem sang A#1 để tra nhanh, một người chỉ sửa CuonSach.maSach. Những quan hệ nào cần chuyển cùng nhau, và xử lý nếu A#1 đã tồn tại?

**Câu phụ 1:** Có thể chỉ fallback tìm S001 theo tên đầu sách để khỏi sửa lịch sử không?

[Mở đáp án TH215](02_DAP_AN.md#TH215) · [Về đầu phần](#thai)

<a id="TH216"></a>
### 048. TH216 — Dòng quá hạn của người trước lọt sang người sau

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** i — Khởi tạo kết quả.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InDocGiaQuaHan, dòng 144](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L144).

**Câu chính:** Refactor đưa DongQuaHan row ra ngoài vòng duyệt độc giả để giảm tạo biến, nhưng chỉ thay row.dg. Mã 10 có một cuốn quá hạn 8 ngày; mã 20 chỉ giữ cuốn 2 ngày. Báo cáo sai thế nào và vì sao mảng rows khởi tạo đủ vẫn không cứu được?

**Câu phụ 1:** Nếu đổi riêng nguồn duyệt báo cáo sang phải–gốc–trái, người 20 ra trước 10, có thể làm lỗi biến tích lũy bộc lộ khác không? Chỉ đổi hình BST hợp lệ có đảo inorder 10,20 không?

[Mở đáp án TH216](02_DAP_AN.md#TH216) · [Về đầu phần](#thai)

<a id="TH217"></a>
### 049. TH217 — Báo cáo ngày tương lai và giao dịch ngày tương lai

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** i — Hợp đồng ngày.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InDocGiaQuaHan, dòng 144](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L144); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KiemTraNgayGiaoDich, dòng 13](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L13); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490).

**Câu chính:** Ngày máy 17/10/2026, có lượt mở từ 10/10. Harness gọi trực tiếp InDocGiaQuaHan ngày 18/10 rồi MuonSach ngày 18/10; CLI chạy --date 18/10. Ba đường có cùng kiểm ngày không? Báo cáo đó được phép kết luận gì?

**Câu phụ 1:** Nếu ngày báo cáo là 31/02 thì có còn đi vào tính hiệu ngày không?

[Mở đáp án TH217](02_DAP_AN.md#TH217) · [Về đầu phần](#thai)

<a id="TH218"></a>
### 050. TH218 — Tên khóa so sánh dài chung một tiền tố

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** j — Chi phí ký tự.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [DauSachXepTruoc, dòng 103](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L103); [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [SoSanhChuoi, dòng 23](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L23).

**Câu chính:** D=10.000 đầu đều có một lượt; tên dài gần 512 byte, chung tiền tố rất dài. So với tên ngắn khác ký tự đầu, vì sao cùng O(10D) lượt xét ứng viên vẫn có thể tốn khác nhiều? Phải tính chi phí nào trong comparator?

**Câu phụ 1:** Cache khóa tên tạm có loại hết chi phí L khỏi so sánh không?

[Mở đáp án TH218](02_DAP_AN.md#TH218) · [Về đầu phần](#thai)

<a id="TH219"></a>
### 051. TH219 — Tên có nhiều khoảng trắng qua hai đường nhập

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** c/e — Bảo toàn văn bản.

**Chỉ vào code:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [ThemDauSach, dòng 60](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L60); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [DocNoiBo, dòng 210](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L210); [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [KhoaSoSanh, dòng 18](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L18).

**Câu chính:** File hợp lệ lưu tenSach là “Lap   trinh”; nhập form mới dùng cùng chuỗi cho đầu ISBN khác. So byte tên lưu trong RAM của hai đầu, kết quả tìm “lap trinh” và thứ tự hòa. Loader có chuẩn hóa mọi trường văn bản giống API thêm không?

**Câu phụ 1:** Có nên sửa loader âm thầm chuẩn hóa mọi tên để test byte bằng nhau?

[Mở đáp án TH219](02_DAP_AN.md#TH219) · [Về đầu phần](#thai)

<a id="TH220"></a>
### 052. TH220 — Output mã bị alias với ISBN nguồn

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** c — Hợp đồng tham chiếu.

**Chỉ vào code:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [ThemCuonSach, dòng 71](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L71).

**Câu chính:** Một caller thử nghiệm lấy d là đầu A rồi truyền d->ISBN làm cả tham số isbn lẫn biến nhận output ma của ThemCuonSach. Vị trí hợp lệ, kho còn chỗ. Truy tới ma=maMoi: đối tượng nguồn nào bị sửa và vì sao đường UI thông thường không gặp tình huống này?

**Câu phụ 1:** Đổi const string& isbn thành truyền giá trị có đủ ngăn sửa d->ISBN qua output không?

[Mở đáp án TH220](02_DAP_AN.md#TH220) · [Về đầu phần](#thai)

<a id="TH221"></a>
### 053. TH221 — Hai đầu cùng sở hữu một đuôi danh sách

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** c — Sở hữu cuốn.

**Chỉ vào code:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [HuyDanhMucCuonSach, dòng 96](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L96); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90).

**Câu chính:** Trên sơ đồ RAM lỗi, A.dms và B.dms đều dẫn đến cùng node legacy S001, không có chu trình. Đếm từng đầu đều kết thúc. Vì sao kiểm chỉ tìm vòng chưa đủ, kiểm toàn vẹn có thể phát hiện gì và hủy hai danh mục nguy hiểm ở đâu?

**Câu phụ 1:** Cho hai node khác địa chỉ nhưng cùng mã S001 có cùng lỗi bộ nhớ không?

[Mở đáp án TH221](02_DAP_AN.md#TH221) · [Về đầu phần](#thai)

<a id="TH222"></a>
### 054. TH222 — Top có tổng lượt đúng nhưng gán sai chủ đầu

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** j — Bảo toàn ánh xạ.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [ChiMucCuon, dòng 92](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L92); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InTop10SachDuocMuonNhieuNhat, dòng 168](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L168).

**Câu chính:** Trên bản sao, lúc heapsort index chỉ đổi trường cuon, quên đổi dauSach. A#1 thuộc A có 3 lượt, B#1 thuộc B có 1 lượt; thứ tự đầu theo tên ngược thứ tự mã. Vì sao tổng 4 vẫn đúng mà top từng đầu sai?

**Câu phụ 1:** Nếu hai đầu có cùng số lượt thì test có chắc phát hiện lỗi không?

[Mở đáp án TH222](02_DAP_AN.md#TH222) · [Về đầu phần](#thai)

<a id="TH223"></a>
### 055. TH223 — Con trỏ cuốn bị xóa trong lúc xây chỉ mục tạm

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** j — Snapshot sống.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InTop10SachDuocMuonNhieuNhat, dòng 168](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L168); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [HoanDoiThuVien, dòng 324](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L324).

**Câu chính:** Giả định chuyển báo cáo top sang worker nền, UI được nạp file trong khi worker đang dùng index chứa CuonSach*. Bản tuần tự hiện tại tránh tình huống này thế nào? Khóa riêng dòng in kết quả có đủ không, và cần bảo vệ khoảng nào?

**Câu phụ 1:** Chỉ lưu ISBN thay con trỏ có giải quyết số liệu pha trộn hai phiên không?

[Mở đáp án TH223](02_DAP_AN.md#TH223) · [Về đầu phần](#thai)

<a id="TH224"></a>
### 056. TH224 — Một triệu lượt mượn không đồng nghĩa một triệu độc giả

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** j — Quy mô có giới hạn.

**Chỉ vào code:** [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [MAX_BAN_GHI, dòng 265](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L265); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [DocNoiBo, dòng 210](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L210); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InTop10SachDuocMuonNhieuNhat, dòng 168](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L168).

**Câu chính:** Đề xuất đánh giá top với D=5.000, C=80.000, R=20.000, H=1.000.000, L≤64; một người thao tác tuần tự và 95% lượt đã trả. Bản hiện nạp được không? Nếu được phép nâng giới hạn H, cần tính lại những gì trước khi đo?

**Câu phụ 1:** Giữ nguyên một triệu lượt với 95% đã trả, chuyển tất cả sang một người: sau khi giả sử đã nâng trần H, dữ liệu có hợp lệ chỉ vì đa số là lịch sử cũ không?

[Mở đáp án TH224](02_DAP_AN.md#TH224) · [Về đầu phần](#thai)

<a id="TH225"></a>
### 057. TH225 — Ngày sai làm thống kê ngừng trước tiêu đề

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** i — Thất bại báo cáo.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InDocGiaQuaHan, dòng 144](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L144); [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [SoThuTuNgay, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L110); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [LuongChuoi, dòng 70](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L70); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [LoiThuVien, dòng 20](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L20).

**Câu chính:** RAM thử có mã 10 quá hạn hợp lệ; mã 20 có lượt mở ngày 31/02. Dùng LuongChuoi rỗng gọi InDocGiaQuaHan với ngày hợp lệ. Đã thu row của 10 trước khi gặp lỗi thì có bảng một người được xuất không? Chỉ nơi xuất tiêu đề so với nơi tính ngày.

**Câu phụ 1:** Nếu refactor vừa gom vừa xuất từng người, bảo đảm đầu ra thay đổi thế nào?

[Mở đáp án TH225](02_DAP_AN.md#TH225) · [Về đầu phần](#thai)

<a id="TH226"></a>
### 058. TH226 — Hai lần nhập cùng ISBN sau timeout ở lớp điều phối

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** c — Retry thêm đầu.

**Chỉ vào code:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [ThemDauSach, dòng 60](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L60); [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [ThemCuonSach, dòng 71](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L71).

**Câu chính:** ThemDauSach A đã thành công nhưng caller không đọc được thông báo; gửi lại nguyên yêu cầu A, rồi chuyển sang ThemCuonSach A hai lần với cùng vị trí. Kho còn chỗ. Những thao tác nào bị trùng chặn, những thao tác nào tạo thêm dữ liệu và vì sao không dùng một chính sách retry chung?

**Câu phụ 1:** Nếu đặt cùng tenSach làm khóa chống lặp cho cả hai API thì sai gì?

[Mở đáp án TH226](02_DAP_AN.md#TH226) · [Về đầu phần](#thai)

<a id="TH227"></a>
### 059. TH227 — Các danh mục có sắp riêng đủ để bỏ sort index top không

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** j — Hợp nhất chỉ mục.

**Chỉ vào code:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [ThemCuonSach, dòng 71](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L71); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InTop10SachDuocMuonNhieuNhat, dòng 168](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L168).

**Câu chính:** A có danh sách theo thứ tự thêm A#1,A#2,A#10; B có mã legacyS001,B#1. Bạn muốn trộn các danh mục như các dãy đã sắp để bỏ heap sort index toàn kho. Hai tiền điều kiện nào phải chứng minh trước, và dữ liệu hiện tại có thỏa không?

**Câu phụ 1:** Chỉ kiểm cuốn đầu và cuối mỗi danh sách có chứng minh cả danh sách tăng không?

[Mở đáp án TH227](02_DAP_AN.md#TH227) · [Về đầu phần](#thai)

<a id="TH228"></a>
### 060. TH228 — Giảm MAX_DAU_SACH khi kho cũ đang vượt ngưỡng mới

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** c — Thay cấu hình.

**Chỉ vào code:** [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [MAX_DAU_SACH, dòng 263](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L263); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [DocNoiBo, dòng 210](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L210); [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [ThemDauSach, dòng 60](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L60).

**Câu chính:** Bản cũ lưu 8.000 đầu hợp lệ. Nhóm muốn build bản nhẹ với MAX_DAU_SACH=5.000 nhưng giữ nguyên file v1. Bản mới mở file sẽ xử lý ở đâu; có được tự lấy 5.000 đầu đầu tiên để chạy không?

**Câu phụ 1:** Nếu chỉ nâng giới hạn lại, có chắc mọi hiệu năng đều chấp nhận được không?

[Mở đáp án TH228](02_DAP_AN.md#TH228) · [Về đầu phần](#thai)

<a id="TH229"></a>
### 061. TH229 — Hủy phần sách trước lịch sử có luôn dereference mã cuốn

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** c — Thứ tự giải phóng.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [HuyThuVien, dòng 321](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L321); [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [HuyDanhSachDauSach, dòng 116](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L116); [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [HuyDanhSachMuonTra, dòng 17](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L17).

**Câu chính:** HuyThuVien hiện hủy độc giả rồi sách. Trên bản sao đổi thứ tự hủy sách trước. MuonTra chứa maSach dạng string, không chứa CuonSach*. Destructor danh sách lịch sử hiện có cần truy cuốn để hủy không? Nêu điều kiện khiến kết luận này thay đổi.

**Câu phụ 1:** Vậy có được dùng các view báo cáo sau khi đã hủy riêng sách không?

[Mở đáp án TH229](02_DAP_AN.md#TH229) · [Về đầu phần](#thai)

<a id="TH230"></a>
### 062. TH230 — Mã rỗng trong kết quả của một API tự viết

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** c — Khởi tạo node.

**Chỉ vào code:** [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [CuonSach, dòng 273](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L273); [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [ThemCuonSach, dòng 71](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L71); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [ConTroTam, dòng 29](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L29), [ConTroTam, dòng 42](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L42).

**Câu chính:** Một helper mới cấp CuonSach bằng new CuonSach rồi nối ngay, sau đó mới gán maSach và viTri. Giả sử người viết quên một phép gán hoặc nó ném lỗi. Giá trị mặc định nào vẫn có vẻ hợp lệ, và vì sao chỉ kiểm trạng thái 0 không đủ để nhận node?

**Câu phụ 1:** Helper lỗi đã nối node, gán xong maSach rồi gán viTri ném. Nếu catch delete node nhưng không tháo liên kết thì sao; nếu không delete thì đã đạt hợp đồng false giữ nguyên kho chưa?

[Mở đáp án TH230](02_DAP_AN.md#TH230) · [Về đầu phần](#thai)

<a id="TH231"></a>
### 063. TH231 — Ghi danh mục phải duyệt hai lượt hay lưu sẵn số cuốn

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** c — Serialization và đếm.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [Ghi, dòng 261](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L261); [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [DemCuonSach, dòng 99](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L99).

**Câu chính:** Đầu A có c cuốn. Ghi gọi DemCuonSach để ghi count rồi duyệt lại để xuất từng cuốn. Một bạn muốn lưu thêm count trong DauSach. So chi phí hai lượt quét với rủi ro duy trì count qua thêm/nạp; có thật giảm bậc thời gian không?

**Câu phụ 1:** Nếu count lưu sẵn nhỏ hơn danh sách một thì file có tự phục hồi nhờ đọc hết không?

[Mở đáp án TH231](02_DAP_AN.md#TH231) · [Về đầu phần](#thai)

<a id="TH232"></a>
### 064. TH232 — Nhập hai danh mục riêng bằng NAP có phải hợp nhất

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** c — Nhập dữ liệu ngoài.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [DocNoiBo, dòng 210](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L210); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [HoanDoiThuVien, dòng 324](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L324).

**Câu chính:** Thái có file A với ISBN X, Thành gửi file B có ISBN Y và một ISBN X khác thông tin. Thủ thư muốn gom kho bằng cách NAP A rồi NAP B. Bản hiện làm gì? Thiết kế một lần nhập bổ sung phải giải quyết những xung đột nào trước commit?

**Câu phụ 1:** Chỉ bỏ các đầu trùng ISBN trong B có đủ giữ lịch sử B không?

[Mở đáp án TH232](02_DAP_AN.md#TH232) · [Về đầu phần](#thai)

<a id="TH233"></a>
### 065. TH233 — Thống kê mức luân chuyển khác số lượt tuyệt đối

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** j — Chỉ số mới.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InTop10SachDuocMuonNhieuNhat, dòng 168](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L168); [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [DemCuonSach, dòng 99](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L99).

**Câu chính:** Quản lý muốn so hiệu quả sử dụng: A có 100 lượt và 100 cuốn, B có 20 lượt và 2 cuốn. Code top xếp ai trước? Nếu đề xuất lượt trên cuốn, phải chốt mẫu số gồm thanh lý hay chỉ lưu thông, xử lý đầu chưa có cuốn và thời gian bổ sung cuốn ra sao?

**Câu phụ 1:** Đổi comparator sang chia nguyên dem/count có đủ không?

[Mở đáp án TH233](02_DAP_AN.md#TH233) · [Về đầu phần](#thai)

<a id="TH235"></a>
### 066. TH235 — Kiểm số cuốn dùng >= và ngân sách trước thêm

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** c — Cận tài nguyên.

**Chỉ vào code:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [ThemCuonSach, dòng 71](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L71); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [DocNoiBo, dòng 210](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L210).

**Câu chính:** M=MAX_BAN_GHI. Lúc đang có M−1 cuốn, vòng kiểm ++tong>=M có chặn thêm không; lúc có M thì sao? Một bạn sửa thành tong++>M vì cho rằng kiểm trước nối bị lệch một. Hãy phân biệt số node cũ và số node sau thêm.

**Câu phụ 1:** Kho không có đầu nào nhưng tổng cuốn khai báo M có là fixture hợp lệ để thử không?

[Mở đáp án TH235](02_DAP_AN.md#TH235) · [Về đầu phần](#thai)

<a id="TH236"></a>
### 067. TH236 — Gộp báo cáo quá hạn từ hai nhóm độc giả

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** i — Phép gom có thể kết hợp.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [DongQuaHan, dòng 91](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L91); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InDocGiaQuaHan, dòng 144](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L144).

**Câu chính:** Chia lịch sử của mỗi người thành hai đoạn để tính tạm, không chạy đồng thời trên nguồn đang đổi. Đoạn 1 của A có max quá hạn 8,count 1; đoạn 2 có max 3,count 2. Ghép kết quả đúng thế nào? Nếu chia theo người thay vì lịch sử thì khóa ghép khác ra sao?

**Câu phụ 1:** Nếu hai đoạn cùng chứa một lượt do cắt sai ranh giới thì max có thể vẫn đúng còn count thế nào?

[Mở đáp án TH236](02_DAP_AN.md#TH236) · [Về đầu phần](#thai)

<a id="TH237"></a>
### 068. TH237 — Dùng bucket số lượt thay bảng top mười ô

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** j — Đánh đổi chọn theo số nguyên.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InTop10SachDuocMuonNhieuNhat, dòng 168](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L168); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [MAX_BAN_GHI, dòng 265](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L265).

**Câu chính:** Vì số lượt mỗi đầu là số nguyên≤H≤200000, đề xuất bucket theo số lượt để tìm top 10 thay vòng chèn 10 ô. Khi D nhỏ,H lớn và khi nhiều đầu đồng lượt, chi phí và quy tắc hòa có gì cần giải quyết?

**Câu phụ 1:** Chỉ quét từ H xuống rồi lấy tùy 10 đầu đầu tiên ở bucket hòa có giữ kết quả hiện tại không?

[Mở đáp án TH237](02_DAP_AN.md#TH237) · [Về đầu phần](#thai)

<a id="TH238"></a>
### 069. TH238 — Hậu tố mã số không phải chỉ số truy cập mảng

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** c — Miền định danh.

**Chỉ vào code:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [TachMaMoi, dòng 5](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L5); [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [TimCuonSachTrongDauSach, dòng 18](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L18), [TimCuonSachTrongDauSach, dòng 22](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L22).

**Câu chính:** Một đầu chỉ có A#1 và A#1000000, đều đúng miền int; kho vẫn chỉ có 2 cuốn. Đề xuất chuyển sang mảng tạm đánh địa chỉ bằng hậu tố để tra O(1). Hãy so dung lượng và ý nghĩa khoảng trống với danh sách hiện tại.

**Câu phụ 1:** Nén hậu tố thành vị trí 0,1 có còn truy cập trực tiếp chỉ bằng hậu tố không?

[Mở đáp án TH238](02_DAP_AN.md#TH238) · [Về đầu phần](#thai)

<a id="TH239"></a>
### 070. TH239 — Gửi báo cáo cho người đọc không có quyền sửa

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** e/i/j — Quyền truy cập.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InDocGiaQuaHan, dòng 144](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L144).

**Câu chính:** Giả định biến chương trình thành dịch vụ dùng chung: sinh viên được tìm sách nhưng không được xem họ tên độc giả quá hạn. Hiện menu có kiểm người đăng nhập hay vai trò không? Chỉ ẩn mục i ở giao diện có bảo vệ dữ liệu khi còn endpoint gọi trực tiếp không?

**Câu phụ 1:** Cho phép tìm tên sách có tự cấp quyền xem ai đang mượn từng cuốn không?

[Mở đáp án TH239](02_DAP_AN.md#TH239) · [Về đầu phần](#thai)

<a id="TH240"></a>
### 071. TH240 — Heap mười phần tử và bảng chèn mười ô

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** j — Chọn k nhỏ.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InTop10SachDuocMuonNhieuNhat, dòng 168](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L168); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [DauSachXepTruoc, dòng 103](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L103).

**Câu chính:** Thầy đề nghị thay top[10] chèn có thứ tự bằng heap kích thước 10 để chọn từ D đầu đã có dem. Root heap nên là đầu tốt nhất hay tệ nhất trong 10? So số phép so, thứ tự xuất và tính đơn giản khi k cố định 10.

**Câu phụ 1:** Nếu root là đầu tốt nhất rồi loại root khi có ứng viên tốt hơn thì lỗi gì?

[Mở đáp án TH240](02_DAP_AN.md#TH240) · [Về đầu phần](#thai)

<a id="TH241"></a>
### 072. TH241 — Mượn trả cùng ngày tạo hai node giống hệt trên giấy

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** j — Lượt và loại trùng.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KetThucMuon, dòng 50](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L50); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InTop10SachDuocMuonNhieuNhat, dòng 168](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L168).

**Câu chính:** A mượn X#1 rồi trả, sau đó lại mượn rồi trả cùng ngày 16/10. Hai node cuối có cùng mã, ngày mượn, ngày trả và trạng thái. Một công cụ deduplicate bỏ một node vì tất cả trường bằng nhau. Nó có bảo toàn top không, và v1 có đủ biết đây là bản sao lỗi hay hai lượt thật không?

**Câu phụ 1:** Validator chấp nhận hai lượt cùng ngày có chứng minh chúng chắc chắn đã xảy ra không?

[Mở đáp án TH241](02_DAP_AN.md#TH241) · [Về đầu phần](#thai)

<a id="TH242"></a>
### 073. TH242 — Giới hạn byte của vị trí kệ ảnh hưởng kích thước báo cáo

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** e — Tài nguyên văn bản.

**Chỉ vào code:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [HopLeVanBan, dòng 38](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L38); [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [InMotDauSach, dòng 10](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L10); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [LuongChuoi, dòng 70](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L70).

**Câu chính:** C=200.000 cuốn cùng khớp truy vấn, mỗi viTri gần 512 byte. Một báo cáo dự toán RAM chỉ lấy C*sizeof(CuonSach). Thiếu phần nào ngay cả trước khi UI đổi sang UTF-16?

**Câu phụ 1:** Có thể lấy 512 ký tự nhân 2 cho mọi vị trí tiếng Việt không?

[Mở đáp án TH242](02_DAP_AN.md#TH242) · [Về đầu phần](#thai)

<a id="TH243"></a>
### 074. TH243 — Khóa báo cáo gộp theo tên làm mất hai ISBN

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** j — Khóa gom nhóm.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InTop10SachDuocMuonNhieuNhat, dòng 168](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L168); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [TimChuSoHuu, dòng 94](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L94).

**Câu chính:** Đầu A và B cùng tên nhưng lần lượt có 7 và 4 lượt. Một refactor dùng tên chuẩn hóa làm khóa bộ đếm để tiết kiệm mục trùng, xuất một dòng 11 lượt. Vì sao tổng H vẫn đúng nhưng trái đặc tả hiện tại; so với gộp các cuốn cùng ISBN?

**Câu phụ 1:** Nếu muốn thêm báo cáo theo tác phẩm, có đủ dùng tên hiện tại không?

[Mở đáp án TH243](02_DAP_AN.md#TH243) · [Về đầu phần](#thai)

<a id="TH244"></a>
### 075. TH244 — Nhị phân thấy mã nhưng không thấy đủ mọi bản ghi trùng

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** j — Tiền điều kiện dữ liệu.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [TimChuSoHuu, dòng 94](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L94); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90).

**Câu chính:** RAM thử có hai CuonSach khác nhau cùng mã legacy S1 dưới hai đầu; lịch sử có một S1. Index đã sắp nên TimChuSoHuu tìm được S1. Có thể lấy kết quả đó làm chủ chắc chắn không? Tại sao top không thay kiểm toàn vẹn toàn hệ thống?

**Câu phụ 1:** Dùng lower_bound để luôn lấy mục đầu có sửa tính đúng nghiệp vụ không?

[Mở đáp án TH244](02_DAP_AN.md#TH244) · [Về đầu phần](#thai)

<a id="TH245"></a>
### 076. TH245 — Ưu tiên quá hạn theo cuốn thay vì theo người

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** i — Đơn vị xếp hạng.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [DongQuaHan, dòng 91](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L91); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InDocGiaQuaHan, dòng 144](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L144).

**Câu chính:** An giữ hai cuốn quá hạn 9 và 8 ngày; Bình giữ một cuốn quá hạn 7 ngày. Quản lý muốn danh sách thu hồi từng cuốn. Đổi vòng in rows hiện tại có đủ tạo 3 dòng chính xác với mã cuốn không, hay đã mất thông tin ở pha gom?

**Câu phụ 1:** Nếu vẫn dùng max của An cho cả hai mã, có sai ngay khi thứ hạng người vẫn đúng không?

[Mở đáp án TH245](02_DAP_AN.md#TH245) · [Về đầu phần](#thai)

<a id="TH246"></a>
### 077. TH246 — Chỉ mục cuốn dựng lại mỗi lần có lợi trong phiên ít đọc

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** j — Tỷ lệ đọc ghi.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InTop10SachDuocMuonNhieuNhat, dòng 168](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L168); [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [ThemCuonSach, dòng 71](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L71).

**Câu chính:** Hai workload cùng D/C/H: phiên A chỉ gọi top một lần sau 1.000 thao tác; phiên B gọi top sau mỗi thao tác. Có nên quyết định giữ chỉ mục cuốn lâu dài giống nhau? Phân tích phần nào có thể tái dùng mà không đồng nhất với cache kết quả top.

**Câu phụ 1:** Trả một lượt có bắt buộc dựng lại index và cộng lại điểm theo G01 không?

[Mở đáp án TH246](02_DAP_AN.md#TH246) · [Về đầu phần](#thai)

<a id="TH247"></a>
### 078. TH247 — Hiện “đã thanh lý” có biết lý do là mất không

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** e — Thông tin suy ra.

**Chỉ vào code:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [InMotDauSach, dòng 10](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L10); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [DanhDauMatSach, dòng 138](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L138); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90).

**Câu chính:** Hai cuốn trạng thái 2: X có lịch sử mất, Y không có lịch sử. Tìm tên sẽ hiện cùng nhãn gì? Có được suy cả hai đều do độc giả làm mất để quy trách nhiệm không; muốn phân biệt phải đọc dữ liệu nào và giới hạn nào còn lại?

**Câu phụ 1:** Đổi nhãn tất cả cuốn 2 thành “Mất” có giữ đúng nghĩa trường theo đề không?

[Mở đáp án TH247](02_DAP_AN.md#TH247) · [Về đầu phần](#thai)

<a id="TH248"></a>
### 079. TH248 — Vị trí kệ mới phải đổi số liệu nào

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** c — Sửa thuộc tính không định danh.

**Chỉ vào code:** [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [CuonSach, dòng 273](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L273); [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [InMotDauSach, dòng 10](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L10); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InTop10SachDuocMuonNhieuNhat, dòng 168](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L168).

**Câu chính:** Nếu bổ sung chuyển vị trí A#1 từ Kệ 1 sang Kệ 2 trong khi đang được mượn, cần chốt viTri nghĩa là vị trí cất mặc định hay vị trí vật lý hiện tại. Hai cách hiểu ảnh hưởng thao tác được phép và lời giải thích tìm kiếm ra sao?

**Câu phụ 1:** Đổi riêng vị trí có cần cấp mã cuốn mới theo bản hiện không?

[Mở đáp án TH248](02_DAP_AN.md#TH248) · [Về đầu phần](#thai)

<a id="TH249"></a>
### 080. TH249 — Đếm lượt top dùng int trong miền đã chặn

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** j — Miền số đếm.

**Chỉ vào code:** [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [MAX_BAN_GHI, dòng 265](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L265); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InTop10SachDuocMuonNhieuNhat, dòng 168](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L168).

**Câu chính:** Trong dữ liệu hợp lệ hiện tại, dem của một đầu có thể tràn int vì thư viện hoạt động lâu dài không? Nếu nâng H lên nhiều tỷ lượt ở thiết kế mới, chỉ đổi dem sang long long có đủ không?

**Câu phụ 1:** Có thể kiểm tràn bằng cách nạp H lớn hơn giới hạn rồi nói bản hiện lỗi dem không?

[Mở đáp án TH249](02_DAP_AN.md#TH249) · [Về đầu phần](#thai)

<a id="TH250"></a>
### 081. TH250 — Trình tự chuẩn hóa mã và xuất lỗi chứa mã

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** c/e — Chẩn đoán định danh.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90); [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [TimCuonSachToanCuc, dòng 27](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L27), [TimCuonSachToanCuc, dòng 48](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L48).

**Câu chính:** File dùng mã cuốn “ A#1 ” và lịch sử cũng dùng đúng chuỗi có dấu cách ấy. Một người nói hai phía bằng nhau nên hợp lệ. Vì sao loader vẫn từ chối, và nếu tự trim cả hai phía thì cần xét va chạm nào với mã A#1 đã có?

**Câu phụ 1:** Quy tắc này có buộc tên sách nhiều khoảng trắng phải bị từ chối giống mã không?

[Mở đáp án TH250](02_DAP_AN.md#TH250) · [Về đầu phần](#thai)

<a id="TH251"></a>
### 082. TH251 — Chỉ tìm sách có sẵn là truy vấn mới

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** e — Kết hợp điều kiện.

**Chỉ vào code:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [TimDauSachTheoTen, dòng 80](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L80); [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [InMotDauSach, dòng 10](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L10).

**Câu chính:** Muốn thêm lựa chọn “tên chứa An và còn ít nhất một cuốn rảnh”. Đầu A khớp tên có 2 cuốn bận; đầu B khớp tên có 1 rảnh và 2 bận; đầu C không khớp tên có 3 rảnh. Bộ kết quả nên chứa đầu nào, và n nên đếm trước hay sau cả hai điều kiện?

**Câu phụ 1:** B đang có cuốn rảnh có chứng minh độc giả đang khóa được mượn không?

[Mở đáp án TH251](02_DAP_AN.md#TH251) · [Về đầu phần](#thai)

<a id="TH252"></a>
### 083. TH252 — Một đầu có cuốn legacy và chuẩn cùng hậu tố nhìn giống

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** c — Không suy danh tính từ số.

**Chỉ vào code:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [TachMaMoi, dòng 5](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L5); [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [SinhMaSachTuDong, dòng 56](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L56); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [TimChuSoHuu, dòng 94](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L94).

**Câu chính:** Đầu A có cuốn legacy S001 và A#1; mỗi cuốn từng được một người khác mượn. Một bộ chuyển dữ liệu suy rằng phần số đều là 1 nên đây là cùng bản sách. Bản hiện tra, cấp mã tiếp và top ra sao; vì sao loại một cuốn sẽ phá liên kết?

**Câu phụ 1:** Nếu lịch sử hai mã không chồng ngày thì đã đủ để gộp chưa?

[Mở đáp án TH252](02_DAP_AN.md#TH252) · [Về đầu phần](#thai)

<a id="TH253"></a>
### 084. TH253 — Dừng ngay sau đủ mười đầu có lượt

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** j — Bất biến chọn top.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InTop10SachDuocMuonNhieuNhat, dòng 168](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L168); [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [SoSanhDauSach, dòng 5](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L5).

**Câu chính:** Kho theo tên có 12 đầu: 10 đầu đầu tiên mỗi đầu 1 lượt, hai đầu cuối lần lượt 100 và 50 lượt. Bạn thêm break ngay khi k==10 để tăng tốc. Hãy nêu hai kết quả bị bỏ, và bất biến đúng của top sau khi xét i đầu là gì.

**Câu phụ 1:** Nếu cả 12 đầu đều 1 lượt và mảng gốc vẫn tăng tên–ISBN, đầu thứ 12 có thể đẩy đầu thứ 10 ra chỉ nhờ khóa hòa không? Ca này có đủ chứng minh break khi đủ 10 là đúng tổng quát không?

[Mở đáp án TH253](02_DAP_AN.md#TH253) · [Về đầu phần](#thai)

<a id="TH301"></a>
### 085. TH301 — ISBN hợp lệ nhưng mã cuốn kế tiếp vượt 512 byte

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** c — Giới hạn kết hợp trường và hậu tố.

**Chỉ vào code:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [SinhMaSachTuDong, dòng 56](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L56); [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [ThemCuonSach, dòng 71](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L71); [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [HopLeVanBan, dòng 38](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L38).

**Câu chính:** Đầu sách có ISBN gồm đúng 510 byte ASCII, đã có một cuốn ISBN#9 và chưa đầy kho. Thêm cuốn mới ở vị trí hợp lệ: mã tiếp theo là gì và lời gọi có thành công không? So với ISBN dài 509 byte. Truy thời điểm kiểm để kết luận số node, output mã và tài nguyên nào thực sự hết.

**Câu phụ 1:** Cắt bớt một byte ISBN để cấp #10 có phải tối ưu giữ nguyên định danh không? Nếu muốn tránh ngõ cụt từ lúc tạo đầu thì cần chốt gì?

[Mở đáp án TH301](02_DAP_AN.md#TH301) · [Về đầu phần](#thai)

<a id="TH302"></a>
### 086. TH302 — Năm xuất bản và ngày mượn được kiểm độc lập

**Phụ trách:** Thái · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** c/f — Quan hệ năm xuất bản và lịch sử.

**Chỉ vào code:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [HopLeDauSach, dòng 23](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L23); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KiemTraNgayGiaoDich, dòng 13](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L13); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90).

**Câu chính:** Ngày máy năm 2026, phiên thử --date 01/10/2020. Tạo đầu xuất bản 2025, cuốn rảnh, A hoạt động chưa có lịch sử. Bản hiện có tự chặn mượn ngày 2020 vì sách chưa xuất bản không? Truy validator đầu sách, ngày giao dịch và kiểm toàn vẹn; phân biệt hành vi với yêu cầu cần hỏi thầy.

**Câu phụ 1:** Nếu bổ sung quy tắc không mượn trước xuất bản, chỉ có năm xuất bản có đủ quyết định lượt 01/01/2025 trước hay sau ngày phát hành thật không?

[Mở đáp án TH302](02_DAP_AN.md#TH302) · [Về đầu phần](#thai)

<a id="TH29"></a>
### 087. TH29 — Thống kê số độc giả khác nhau

**Phụ trách:** Thái · **Ưu tiên:** P3 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** Sửa trên bản sao — j.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InTop10SachDuocMuonNhieuNhat, dòng 168](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L168).

**Câu chính:** Trên bản sao, thêm báo cáo riêng đếm số độc giả khác nhau từng mượn mỗi đầu sách; giữ nguyên top lượt cũ. An mượn A#1 ba lần và A#2 một lần, Bình mượn A#1 một lần; Cường mượn B#1 hai lần. Tự cài đếm không dùng set/map, không thêm trường lâu dài và tự kiểm tra.

**Câu phụ 1:** Dùng bool seen[D] rồi xóa hết trước mỗi người có đúng nhưng chậm ở đâu? Vì sao dùng mã thẻ làm stamp không cần tạo thêm số thế hệ dễ tràn?

[Mở đáp án TH29](02_DAP_AN.md#TH29) · [Về đầu phần](#thai)

<a id="TH31"></a>
### 088. TH31 — UTF-8 đúng chưa phải so tiếng Việt đầy đủ

**Phụ trách:** Thái · **Ưu tiên:** P3 · **Phạm vi:** Hiện tại.

**Trọng tâm:** e — Chuỗi và UTF-8.

**Chỉ vào code:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [KhoaSoSanh, dòng 18](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L18); [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [ChuaChuoi, dòng 27](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L27); [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [TimDauSachTheoTen, dòng 80](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L80); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [GhepDauHienThi, dòng 39](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L39).

**Câu chính:** Kho có Lap trinh C++, LAP TRINH Python và Lập trình cơ bản. Tìm lap   trinh, Lập trình, LẬP TRÌNH rồi giải thích kết quả bằng KhoaSoSanh. So thêm hai cặp nhìn giống nhau: á dựng sẵn với a + dấu sắc tổ hợp; dấu cách ASCII với NBSP U+00A0 giữa hai từ. Giao diện ghép dấu đẹp hoặc gọi tolower từng byte có đủ làm các cặp tương đương trong tìm kiếm không?

**Câu phụ 1:** Đổi quy tắc tìm không dấu có cho gộp ISBN khác byte không?

[Mở đáp án TH31](02_DAP_AN.md#TH31) · [Về đầu phần](#thai)

<a id="TH34"></a>
### 089. TH34 — Tham số owner còn giữ kết quả lần trước

**Phụ trách:** Thái · **Ưu tiên:** P3 · **Phạm vi:** Hiện tại.

**Trọng tâm:** c — Hợp đồng tra cứu.

**Chỉ vào code:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [TimCuonSachToanCuc, dòng 27](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L27), [TimCuonSachToanCuc, dòng 48](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L48).

**Câu chính:** Biến owner đang trỏ đầu A từ lần tìm A#1 thành công. Dùng lại biến đó để tìm KHONG_CO, rồi A#01 và A#1. Hãy chỉ giá trị trả về và owner sau mỗi lần; tại sao không được đọc owner cũ khi tìm thất bại, và wrapper mutable được phép cast trong điều kiện nào?

**Câu phụ 1:** Caller không yêu cầu owner, chỉ truyền nullptr, có được coi đó là tìm thất bại không?

[Mở đáp án TH34](02_DAP_AN.md#TH34) · [Về đầu phần](#thai)

<a id="TH35"></a>
### 090. TH35 — Lỗi trước khi gắn nút vào danh sách

**Phụ trách:** Thái · **Ưu tiên:** P3 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** c — Commit và lỗi chuẩn bị.

**Chỉ vào code:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [ThemCuonSach, dòng 71](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L71); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [ConTroTam, dòng 29](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L29), [ConTroTam, dòng 42](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L42).

**Câu chính:** Trong ThemCuonSach, thầy chuyển phép gán chuỗi output ma xuống sau khi nối nút mới, rồi giả sử phép gán đó ném ngoại lệ. Thông báo catch có còn phản ánh đúng dữ liệu không? Chỉ ranh giới commit hiện tại và nêu cách kiểm không rò rỉ, không tăng cuốn khi lỗi xảy ra trước commit.

**Câu phụ 1:** Sau release, ConTroTam còn chịu trách nhiệm xóa node đã nối không?

[Mở đáp án TH35](02_DAP_AN.md#TH35) · [Về đầu phần](#thai)

<a id="TH51"></a>
### 091. TH51 — Danh sách cuốn có chu trình

**Phụ trách:** Thái · **Ưu tiên:** P3 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** c · Đầu sách, mã cuốn và quyền sở hữu.

**Chỉ vào code:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [DemCuonSach, dòng 99](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L99); [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [HuyDanhMucCuonSach, dòng 96](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L96); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90).

**Câu chính:** Một sửa đổi sai nối cuốn cuối về cuốn đầu. DemCuonSach, tìm mã không tồn tại và hủy danh mục có còn an toàn? Kiểm file có chữa được cấu trúc RAM này không?

**Câu phụ 1:** Gọi lại loader trên cùng biến có chắc giải phóng an toàn đồ thị RAM có vòng không?

[Mở đáp án TH51](02_DAP_AN.md#TH51) · [Về đầu phần](#thai)

<a id="TH52"></a>
### 092. TH52 — Tối ưu nhập lô: tail, tổng cuốn, max mã và phạm vi commit

**Phụ trách:** Thái · **Ưu tiên:** P3 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** c · Đầu sách, mã cuốn và quyền sở hữu.

**Chỉ vào code:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [ThemCuonSach, dòng 71](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L71); [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [SinhMaSachTuDong, dòng 56](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L56).

**Câu chính:** Kho có D đầu, C cuốn, đầu đang nhập có c cuốn. Nhập k cuốn hợp lệ liên tiếp dưới các giới hạn. Trên bản sao vẫn giữ danh sách đơn và không thêm trường nghiệp vụ: chỉ giữ tail tạm có làm cả lô O(C+k) không? Tính chi phí đầy đủ rồi đề xuất cách giảm các lần quét mà giữ mã và hợp đồng lỗi.

**Câu phụ 1:** Cuốn thứ hai có vị trí kệ chứa ký tự cấm, cuốn thứ nhất đã hợp lệ. Hai hợp đồng commit cho trạng thái nào, và test so phiên cũ phải chọn expected nào?

[Mở đáp án TH52](02_DAP_AN.md#TH52) · [Về đầu phần](#thai)

<a id="TH58"></a>
### 093. TH58 — Dữ liệu lặp làm tìm chuỗi con chậm

**Phụ trách:** Thái · **Ưu tiên:** P3 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** e · Tìm tên, so sánh và Unicode.

**Chỉ vào code:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [ChuaChuoi, dòng 27](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L27).

**Câu chính:** Tên có nhiều chữ a rồi kết thúc bằng b; từ khóa nhiều chữ a rồi c. Mỗi vị trí bắt đầu phải so bao nhiêu ký tự trước khi thất bại? Hạ chữ một lần có đủ làm thuật toán tuyến tính không?

**Câu phụ 1:** Tên có nhiều a, mẫu là aaaaab. Sau khi khớp dài rồi sai ở ký tự cuối, vì sao nhảy nguyên độ dài mẫu có thể bỏ kết quả? Nếu đề xuất KMP thì phải giữ thông tin gì và trả thêm bộ nhớ nào?

[Mở đáp án TH58](02_DAP_AN.md#TH58) · [Về đầu phần](#thai)

<a id="TH79"></a>
### 094. TH79 — Top tháng: lọc ngày mượn hay ngày trả sẽ kể câu chuyện khác

**Phụ trách:** Thái · **Ưu tiên:** P3 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** Top tháng: lọc ngày mượn hay ngày trả sẽ kể câu chuyện khác.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InTop10SachDuocMuonNhieuNhat, dòng 168](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L168); [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [SoThuTuNgay, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L110).

**Câu chính:** Thầy yêu cầu top tháng 10. A có lượt 30/09–02/10, B có lượt 05/10–06/10 báo mất, C mượn 31/10 chưa trả; ngày máy được giả định sau 31/10 cho bộ dữ liệu này. Chốt nếu tính lượt bắt đầu trong tháng thì ai được tính; so với đếm hoàn tất hay đang giữ cuối tháng. Đề xuất vị trí lọc và cách tránh thay đổi top toàn thời gian.

**Câu phụ 1:** Khoảng lọc rỗng hoặc ngày đầu sau ngày cuối nên được hiểu tự động là toàn thời gian không?

[Mở đáp án TH79](02_DAP_AN.md#TH79) · [Về đầu phần](#thai)

<a id="TH80"></a>
### 095. TH80 — Top cuốn và top đầu không thể dùng chung khóa đếm

**Phụ trách:** Thái · **Ưu tiên:** P3 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** Top cuốn và top đầu không thể dùng chung khóa đếm.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [ChiMucCuon, dòng 92](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L92); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [TimChuSoHuu, dòng 94](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L94); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InTop10SachDuocMuonNhieuNhat, dòng 168](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L168).

**Câu chính:** A#1 có 3 lượt, A#2 có 4 lượt, B#1 có 6 lượt; hai đầu A/B khác nhau. Muốn thêm top từng cuốn để xem bản nào hao mòn. Thầy chỉ ChiMucCuon.dauSach và dem[owner]: cần đổi đại lượng/khóa nào, thứ hạng mới ra sao và chi phí có thay đổi? Vì sao đổi tiêu đề hoặc chọn cuốn đầu tiên của mỗi đầu là sai?

**Câu phụ 1:** Nếu hai cuốn khác đầu cùng tên sách và cùng lượt, có được gộp thành một dòng top cuốn không?

[Mở đáp án TH80](02_DAP_AN.md#TH80) · [Về đầu phần](#thai)

<a id="TH81"></a>
### 096. TH81 — Muốn giữ cache top giữa các giao dịch

**Phụ trách:** Thái · **Ưu tiên:** P3 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** j · Đếm lượt và top 10.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InTop10SachDuocMuonNhieuNhat, dòng 168](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L168); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [DocFile, dòng 336](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L336); [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [ThemDauSach, dòng 60](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L60).

**Câu chính:** Top đang giữ chỉ số đầu A=2 và các bộ đếm. So các biến thể độc lập: chèn một đầu trước A; mượn rồi trả một cuốn A; nạp thư viện khác chưa có lượt nào. Nếu cache chỉ cập nhật các đầu có lượt dương thì lỗi gì xảy ra? Chỉ vòng đời dữ liệu tạm hiện tại, phân biệt cache cũ với việc bỏ {} ở new int[d]{}, rồi đề xuất điều kiện vô hiệu hóa nếu muốn cache lâu dài.

**Câu phụ 1:** NAP cùng đường dẫn nhưng nội dung mới có bắt buộc bỏ cache không?

[Mở đáp án TH81](02_DAP_AN.md#TH81) · [Về đầu phần](#thai)

<a id="TH90"></a>
### 097. TH90 — Lấy đúng k người quá hạn thay vì tất cả

**Phụ trách:** Thái · **Ưu tiên:** P3 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** i · Quá hạn và cách xếp hạng.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InDocGiaQuaHan, dòng 144](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L144); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [SapXepHeap, dòng 84](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L84).

**Câu chính:** Trong báo cáo quá hạn, mã 1..5 chỉ quá hạn 1 ngày, mã 80..99 đều quá hạn 8 ngày; không có người quá hạn khác. Thầy yêu cầu đúng 5 người theo comparator hiện tại. Một bạn lấy 5 người gặp đầu khi inorder rồi mới sắp: sai cụ thể ở đâu? So sắp toàn bộ với giữ top 5 tạm; tính cả quét H lịch sử, R độc giả và bộ nhớ thực cấp. Nếu yêu cầu lấy cả đồng hạng thì kết quả thay đổi thế nào?

**Câu phụ 1:** Nếu chỉ có ba người quá hạn nhưng yêu cầu top 5, có cần thêm hai người chưa quá hạn cho đủ không?

[Mở đáp án TH90](02_DAP_AN.md#TH90) · [Về đầu phần](#thai)

<a id="TH94"></a>
### 098. TH94 — Đối soát kho theo ba trạng thái không được lấy phép trừ thiếu

**Phụ trách:** Thái · **Ưu tiên:** P3 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Đối soát kho theo ba trạng thái không được lấy phép trừ thiếu.

**Chỉ vào code:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [DemCuonSach, dòng 99](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L99); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [TongQuan, dòng 246](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L246).

**Câu chính:** A có 2 sẵn sàng, 1 đang mượn, 3 thanh lý. B không có cuốn. Thầy yêu cầu bảng tồn kho từng đầu và tổng cuối bảng, đồng thời báo nếu số cuốn đang mượn không khớp số phiếu mở. Vì sao DemCuonSach −số đang mượn không là số sẵn sàng; thiết kế hai lớp đếm và đối chiếu mà không tự sửa dữ liệu.

**Câu phụ 1:** Hai tổng bằng nhau có loại được lỗi một mã thiếu phiếu và một mã thừa phiếu không?

[Mở đáp án TH94](02_DAP_AN.md#TH94) · [Về đầu phần](#thai)

<a id="TH99"></a>
### 099. TH99 — Tối ưu tìm kiếm nhưng expected dùng chính hàm đang sửa

**Phụ trách:** Thái · **Ưu tiên:** P3 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Tối ưu tìm kiếm nhưng expected dùng chính hàm đang sửa.

**Chỉ vào code:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [ChuaChuoi, dòng 27](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L27); [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [TimDauSachTheoTen, dòng 80](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L80).

**Câu chính:** Nhóm sửa ChuaChuoi để giảm so sánh. Bộ test tạo expected bằng cách gọi ChuaChuoi cũ được sửa chung trong cùng file nên tất cả đều xanh, nhưng người dùng vẫn mất kết quả cuối tên. Thầy yêu cầu thiết kế oracle độc lập và phép biến đổi dữ liệu phải giữ kết quả; giới hạn không dùng sort /find trong mã nộp có được dùng làm lý do bỏ kiểm thử không?

**Câu phụ 1:** Test tham chiếu được copy nguyên vòng lặp lỗi nhưng đổi tên hàm có độc lập không?

[Mở đáp án TH99](02_DAP_AN.md#TH99) · [Về đầu phần](#thai)

<a id="TH100"></a>
### 100. TH100 — Đề nghị xóa lịch sử trả cũ để nhẹ file

**Phụ trách:** Thái · **Ưu tiên:** P3 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** Đề nghị xóa lịch sử trả cũ để nhẹ file.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KiemTraDongThoiGian, dòng 21](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L21); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InTop10SachDuocMuonNhieuNhat, dòng 168](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L168); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90).

**Câu chính:** Thủ thư muốn xóa mọi lượt đã trả quá một năm, giữ lượt mở và mất. Thầy yêu cầu chỉ những kết quả có thể đổi ngoài dung lượng file: top, mốc giao dịch liên quan, đối chiếu chuỗi cùng cuốn và khả năng truy vết. Nếu giữ bộ đếm top tổng thay cho lịch sử, có khôi phục được mọi thông tin đã mất không?

**Câu phụ 1:** Giữ tổng lượt theo đầu có trả lời ai mượn một cuốn ở ngày cụ thể không?

[Mở đáp án TH100](02_DAP_AN.md#TH100) · [Về đầu phần](#thai)


<a id="thanh"></a>
## Thành — 100 câu

<a id="TV01"></a>
### 001. TV01 — Ai được mượn khi hai người cùng chọn một cuốn?

**Phụ trách:** Thành · **Ưu tiên:** P1 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Hai độc giả cùng một cuốn.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110).

**Câu chính:** Ngày 16/10/2026, A và B chưa mượn gì; X#1 đang cho mượn được. Chương trình xử lý A rồi B. So sánh hai lượt chạy độc lập: cả hai thẻ hoạt động; hoặc chỉ thẻ A bị khóa. Sau từng yêu cầu, ai giữ X#1, lịch sử tăng bao nhiêu? Chỉ ra nhánh quyết định; có cần hàng chờ không?

**Câu phụ 1:** Nếu A được mượn rồi đóng chương trình chưa lưu, file có tự ghi nhận A đã nhận cuốn không?

[Mở đáp án TV01](02_DAP_AN.md#TV01) · [Về đầu phần](#thanh)

<a id="TV02"></a>
### 002. TV02 — Đang giữ một cuốn, mượn thêm hai cuốn có được không?

**Phụ trách:** Thành · **Ưu tiên:** P1 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Giới hạn ba cuốn và cùng ISBN.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110); [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [DemSoSachDangMuon, dòng 4](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L4).

**Câu chính:** Ngày 16/10/2026, A hoạt động, đang giữ X#1 mượn ngày 14/10; X#2 và X#3 cùng ISBN X đều sẵn sàng. A lần lượt mượn X#2 rồi X#3. Kết quả từng bước? Chạy lại khi X#3 đang do B giữ, hoặc X#1 được mượn từ 01/10. Cùng ISBN có tự làm yêu cầu sai không?

**Câu phụ 1:** Đổi X#3 thành một cuốn thuộc ISBN khác có thay hạn mức còn một chỗ không?

[Mở đáp án TV02](02_DAP_AN.md#TV02) · [Về đầu phần](#thanh)

<a id="TV03"></a>
### 003. TV03 — Đã giữ ba cuốn: đổi thứ tự thao tác có đổi kết quả?

**Phụ trách:** Thành · **Ưu tiên:** P1 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Thứ tự trả và mượn.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [TraSach, dòng 135](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L135).

**Câu chính:** A hoạt động, giữ X#1, Y#1, Z#1 từ 14/10; W#1 sẵn sàng, mọi lịch sử hợp lệ. Ngày 16/10, so sánh: mượn W#1 rồi trả X#1; và trả X#1 rồi mượn W#1. Xác định số lượt, số cuốn đang giữ và trạng thái bốn cuốn sau mỗi bước. Yêu cầu thất bại có tự chạy lại không?

**Câu phụ 1:** Sau nhánh mượn W thất bại rồi trả X, phải làm gì nếu vẫn muốn W?

[Mở đáp án TV03](02_DAP_AN.md#TV03) · [Về đầu phần](#thanh)

<a id="TV04"></a>
### 004. TV04 — Quá hạn, khóa thẻ và quyền trả sách tương tác thế nào?

**Phụ trách:** Thành · **Ưu tiên:** P1 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Bảy ngày và thẻ khóa.

**Chỉ vào code:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [QuaHan7Ngay, dòng 121](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L121); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KetThucMuon, dòng 50](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L50).

**Câu chính:** A giữ X#1 từ 08/10/2026; Y#1 sẵn sàng. Từ cùng trạng thái thẻ hoạt động, thử mượn Y#1 lần lượt ở ngày 15/10 và 16/10. Sau đó dùng bản dữ liệu A đã bị khóa, trả X#1 ngày 16/10 rồi xin mượn Y#1. Mỗi bước được xử lý thế nào?

**Câu phụ 1:** Nếu đã trả cuốn quá hạn nhưng còn một cuốn quá hạn khác, quyền mượn đã mở chưa?

[Mở đáp án TV04](02_DAP_AN.md#TV04) · [Về đầu phần](#thanh)

<a id="TV05"></a>
### 005. TV05 — Trả, bấm trả lại rồi người khác mượn lại cùng ngày

**Phụ trách:** Thành · **Ưu tiên:** P1 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Trả đúng lượt đang mở.

**Chỉ vào code:** [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [TimMuonDangMuonTheoMa, dòng 13](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L13); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KetThucMuon, dòng 50](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L50).

**Câu chính:** A có hai lượt X#1 đã trả và một lượt đang mượn từ 14/10. Ngày 16/10: A trả X#1, gọi trả lần nữa; B hợp lệ mượn X#1; A tiếp tục gọi trả X#1. Theo dõi từng lượt lịch sử, ngày trả và cuốn sách. Nếu chỉ tìm lần xuất hiện đầu tiên của mã cuốn thì sai ở đâu?

**Câu phụ 1:** Nếu B cũng đã trả rồi A mượn lại, helper có được dùng lại node cũ đã trả của A không?

[Mở đáp án TV05](02_DAP_AN.md#TV05) · [Về đầu phần](#thanh)

<a id="TV06"></a>
### 006. TV06 — Báo mất có kết thúc mọi khoản mượn không?

**Phụ trách:** Thành · **Ưu tiên:** P1 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Mất một cuốn khi còn cuốn khác.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [DanhDauMatSach, dòng 138](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L138); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KetThucMuon, dòng 50](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L50); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [HieuChinhDocGia, dòng 68](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L68).

**Câu chính:** A hoạt động, giữ X#1 và Y#1 từ 14/10. Ngày 16/10 A báo mất X#1, xin mượn Z#1 đang sẵn sàng, rồi trả Y#1; sau đó thử báo mất X#1 lần nữa và mở lại thẻ. Dự đoán từng kết quả, các trạng thái và số đang mượn. Phần nào là giả định phải hỏi thầy?

**Câu phụ 1:** Cuốn Y chưa quá hạn nhưng A mất X thì Y có tự chuyển thanh lý không?

[Mở đáp án TV06](02_DAP_AN.md#TV06) · [Về đầu phần](#thanh)

<a id="TV07"></a>
### 007. TV07 — Nút kế tiếp có lịch sử riêng: xóa gốc thế nào?

**Phụ trách:** Thành · **Ưu tiên:** P1 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Xóa BST hai con và sở hữu lịch sử.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [XoaDocGia, dòng 80](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L80).

**Câu chính:** BST có gốc 40, trái 20, phải 70; 70 có trái 50, 50 có phải 60. Nút 40 không có lịch sử; nút 50 có hai lượt đã trả. Xóa 40 bằng hàm hiện tại. Vẽ cây và quyền sở hữu lịch sử sau xóa. Điều gì xảy ra nếu chỉ chép maThe từ 50 sang 40?

**Câu phụ 1:** Nếu nút cần xóa 40 có một lượt đã trả thì có đến nhánh successor không?

[Mở đáp án TV07](02_DAP_AN.md#TV07) · [Về đầu phần](#thanh)

<a id="TV08"></a>
### 008. TV08 — Xóa mã lớn nhất rồi lưu lại có được cấp lại mã?

**Phụ trách:** Thành · **Ưu tiên:** P1 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Mốc mã thẻ và tràn số.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [ThemDocGia, dòng 59](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L59); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [XoaDocGia, dòng 80](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L80); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [Ghi, dòng 261](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L261).

**Câu chính:** Mốc đã cấp 20, BST còn 7/12/18. Thêm hợp lệ, xóa người vừa thêm chưa có lịch sử, lưu–nạp, thử thêm tên rỗng rồi thêm hợp lệ. Liệt kê mã và mốc sau từng bước. Ở bản sao khác mốc là SO_NGUYEN_LON_NHAT nhưng cây rỗng: thêm người mới phải thế nào?

**Câu phụ 1:** Một file hợp lệ có cây rỗng và mốc 20 thì mã tiếp theo là gì?

[Mở đáp án TV08](02_DAP_AN.md#TV08) · [Về đầu phần](#thanh)

<a id="TV09"></a>
### 009. TV09 — Thiếu bộ nhớ ở giữa thao tác mượn

**Phụ trách:** Thành · **Ưu tiên:** P1 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Điểm cập nhật giao dịch mượn.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [ConTroTam, dòng 29](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L29), [ConTroTam, dòng 42](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L42).

**Câu chính:** A hoạt động, giữ một cuốn chưa quá hạn; Y#1 sẵn sàng và mọi lịch sử hợp lệ. MuonSach gặp lỗi cấp phát khi tạo lượt mới hoặc khi gán maSach vào lượt tạm. Trạng thái nào phải giữ nguyên? Chỉ ra thời điểm dữ liệu thật bắt đầu thay đổi và giải thích vì sao đổi cuốn trước cấp phát là nguy hiểm.

**Câu phụ 1:** Đổi trạng thái cuốn sau nối phiếu có chứng minh an toàn khi hai thread cùng gọi không?

[Mở đáp án TV09](02_DAP_AN.md#TV09) · [Về đầu phần](#thanh)

<a id="TV10"></a>
### 010. TV10 — Cuốn rảnh nhưng ngày giao dịch vẫn bị chặn

**Phụ trách:** Thành · **Ưu tiên:** P1 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Mốc thời gian theo độc giả hoặc cuốn.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KiemTraDongThoiGian, dòng 21](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L21); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110).

**Câu chính:** A đã trả Y ngày 16/10/2026, B đã trả X ngày 15/10; C chưa có lịch sử, Z chưa từng mượn. Các thẻ hoạt động, X/Z rảnh. Trên các bản dữ liệu độc lập, xét A mượn X ngày 15; C mượn X ngày 14; C mượn Z ngày 15; A mượn X ngày 16. Mỗi lần bị chặn bởi mốc nào hoặc được nhận? Nếu đảo thứ tự các node lịch sử hợp lệ thì mốc có đổi không; vì sao không lấy ngày lớn nhất toàn thư viện?

**Câu phụ 1:** Thêm một lượt rất mới ở người khác và cuốn khác có đổi mốc giao dịch A/X không?

[Mở đáp án TV10](02_DAP_AN.md#TV10) · [Về đầu phần](#thanh)

<a id="TV11"></a>
### 011. TV11 — Hiện không giữ cuốn nào nhưng lịch sử vẫn vô lý

**Phụ trách:** Thành · **Ưu tiên:** P1 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Giới hạn ba cuốn trong lịch sử.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [MocMuon, dòng 79](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L79).

**Câu chính:** File có A đã trả hết. So sánh: bốn cuốn cùng mượn 01/10, trả 10/10; bốn lượt nối tiếp đều mượn–trả 10/10; hoặc ba cuốn giữ 01–12/10 và thêm lượt mượn–trả 10/10. Bộ đọc chấp nhận trường hợp nào? Vì sao chỉ đếm trạng thái đang mượn hiện tại không đủ? Nếu giữ hai cuốn xuyên ngày và có hai lượt mượn–trả cùng ngày, vì sao không nhất thiết là giữ đồng thời bốn cuốn?

**Câu phụ 1:** File chỉ có ngày có chứng minh bốn lượt cùng ngày đã diễn ra đúng thứ tự thực tế không?

[Mở đáp án TV11](02_DAP_AN.md#TV11) · [Về đầu phần](#thanh)

<a id="TV12"></a>
### 012. TV12 — Cây cân bằng có làm ThemDocGia thành O(log R)?

**Phụ trách:** Thành · **Ưu tiên:** P1 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Chi phí đầy đủ của thêm độc giả.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [ThemDocGia, dòng 59](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L59); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [DemDocGia, dòng 28](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L28); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [ChenDocGiaCoMa, dòng 46](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L46).

**Câu chính:** Sau nạp file có R=50.000 độc giả, BST cân bằng. Gọi ThemDocGia thêm một người hợp lệ rồi lặp nhiều lần với mã tự tăng. Hãy tính chi phí cả hàm, chỉ ra công việc ngoài đường tìm vị trí chèn, và giải thích độ cao cây có được bảo đảm về sau hay không. Đề xuất cấp mã nhỏ nhất còn trống hoặc ngẫu nhiên để bớt lệch có phải tối ưu giữ nguyên hợp đồng cấp mã hiện tại không?

**Câu phụ 1:** Giả định được phép thêm bộ đếm R để bỏ DemDocGia: tăng/giảm ở những mốc nào, và vì sao chỉ sửa hàm thêm vẫn chưa giảm đúng chi phí mà giữ dữ liệu?

[Mở đáp án TV12](02_DAP_AN.md#TV12) · [Về đầu phần](#thanh)

<a id="TV29"></a>
### 013. TV29 — Hai người trùng họ tên, sửa nhầm hồ sơ sẽ tác động ai?

**Phụ trách:** Thành · **Ưu tiên:** P1 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Hai người trùng họ tên, sửa nhầm hồ sơ sẽ tác động ai?.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [ThemDocGia, dòng 59](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L59); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [HieuChinhDocGia, dòng 68](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L68); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110).

**Câu chính:** Hai độc giả cùng Nguyen An, mã 10 và 20; 10 đang giữ X, 20 chưa mượn. Thủ thư sửa tên 20 rồi muốn chuyển X sang 20 vì tưởng lúc trước nhập nhầm. Theo API hiện tại sửa tên có chuyển lịch sử không? Vì sao không dùng tên để gộp người hoặc sửa maThe trực tiếp; nếu cần điều chỉnh giao dịch nhầm phải xác minh những gì?

**Câu phụ 1:** Hai hồ sơ giống toàn bộ họ/tên/phái có được coi chắc chắn cùng một người không?

[Mở đáp án TV29](02_DAP_AN.md#TV29) · [Về đầu phần](#thanh)

<a id="TV13"></a>
### 014. TV13 — Một trường đúng không đủ để cho mượn hoặc trả

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Dữ liệu cuốn và lịch sử mâu thuẫn.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KetThucMuon, dòng 50](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L50); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KiemTraDongThoiGian, dòng 21](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L21).

**Câu chính:** Ngày hợp lệ, không tương lai/không lùi. B hoạt động, chưa giữ sách. Trên bản sao, X#1 trạng thái 0 nhưng A có lượt đang mở: B xin X#1, rồi A thử trả. Bản khác, X#1 trạng thái 1 nhưng A/B đều có lượt mở: A thử trả. Từng yêu cầu bị chặn ở đâu, có tự chữa dữ liệu không?

**Câu phụ 1:** Nếu tổng phiếu mở toàn kho bằng tổng cuốn 1 nhưng khác mã thì có được cho trả tiếp không?

[Mở đáp án TV13](02_DAP_AN.md#TV13) · [Về đầu phần](#thanh)

<a id="TV14"></a>
### 015. TV14 — Đổi tên hoặc khóa thẻ có cần chuyển nút BST?

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Khóa BST và hiệu chỉnh thông tin.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [HieuChinhDocGia, dòng 68](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L68); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [TimDocGia, dòng 3](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L3), [TimDocGia, dòng 8](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L8); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90).

**Câu chính:** BST gốc 40 có con 20 và 60; độc giả 20 đang mượn X#1. Hiệu chỉnh tên, họ và khóa thẻ 20. Cây, mã thẻ và lịch sử phải thế nào? Nếu ai đó sửa trực tiếp mã 20 thành 70 nhưng giữ liên kết, TimDocGia(70) và kiểm tra BST có thể phát hiện điều gì?

**Câu phụ 1:** Nút 70 nằm sâu trong trái của 40 nhưng lớn hơn cha trực tiếp của nó thì kiểm cha–con có đủ không?

[Mở đáp án TV14](02_DAP_AN.md#TV14) · [Về đầu phần](#thanh)

<a id="TV17"></a>
### 016. TV17 — 100.000 nút lệch có làm tràn call stack?

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Cây lệch, duyệt và hủy.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [LayDanhSachDocGia, dòng 13](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L13); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [HuyCayDocGia, dòng 98](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L98); [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [HuyDanhSachMuonTra, dòng 17](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L17).

**Câu chính:** Cây hợp lệ có 100.000 nút lệch trái; mỗi độc giả có một lượt đã trả. Chạy DemDocGia rồi HuyCayDocGia. Hai hàm sử dụng bộ nhớ phụ khác nhau thế nào, lịch sử được hủy ở đâu? Giải thích vì sao thay bằng đệ quy một dòng chưa chắc an toàn và sau hủy phải còn trạng thái gì.

**Câu phụ 1:** Hủy riêng cây có tự đặt lại mốc cấp mã của ThuVien không?

[Mở đáp án TV17](02_DAP_AN.md#TV17) · [Về đầu phần](#thanh)

<a id="TV19"></a>
### 017. TV19 — File hợp lệ có chứng minh từng lần mượn đúng quyền?

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Giới hạn chứng minh của file lịch sử.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110).

**Câu chính:** A hiện hoạt động. Lịch sử X#1 mượn 01/10, trả 12/10; Y#1 mượn 10/10, trả 11/10; hai cuốn hiện trạng thái 0. Không có dữ liệu khác. Bộ đọc có loại chỉ vì A giữ X#1 quá bảy ngày khi mượn Y#1 không? Nó biết trạng thái thẻ A tại 10/10 không?

**Câu phụ 1:** Thêm trường trạng thái thẻ hiện tại có truy được ngày thẻ từng khóa không?

[Mở đáp án TV19](02_DAP_AN.md#TV19) · [Về đầu phần](#thanh)

<a id="TV20"></a>
### 018. TV20 — Trả và mượn lại cùng ngày khác với lịch sử chồng lấn

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Khoảng thời gian của cùng một cuốn.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90).

**Câu chính:** X#1 có lượt A mượn 01/10, trả 10/10; lượt B mượn 09/10, trả 12/10; hiện cuốn trạng thái 0. So sánh khi đổi ngày mượn của B thành 10/10. Nếu thay lượt A thành báo mất ngày 10/10, sửa cuốn/thẻ đúng quy ước, B còn được có lượt sau đó không?

**Câu phụ 1:** Đổi thứ tự các độc giả trong file có làm lượt chồng lấn trở nên hợp lệ không?

[Mở đáp án TV20](02_DAP_AN.md#TV20) · [Về đầu phần](#thanh)

<a id="TV21"></a>
### 019. TV21 — Giới hạn lịch sử đạt đúng M vẫn trả được

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** g — Tài nguyên khi đóng lượt.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KiemTraDongThoiGian, dòng 21](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L21); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KetThucMuon, dòng 50](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L50).

**Câu chính:** H đúng MAX_BAN_GHI, có một phiếu mở hợp lệ cần trả. Helper kiểm if(tongLichSu>=MAX_BAN_GHI) trước ++ ở mỗi node. Vì sao quét đủ M node không tự thất bại, trong khi mượn mới bị chặn sau quét?

**Câu phụ 1:** Sửa helper thành kiểm sau tăng với >= có ảnh hưởng quyền trả ở sát giới hạn không?

[Mở đáp án TV21](02_DAP_AN.md#TV21) · [Về đầu phần](#thanh)

<a id="TV22"></a>
### 020. TV22 — Sửa thông tin đồng thời mở thẻ có thể đổi nửa chừng?

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Hiệu chỉnh an toàn và mở lại thẻ.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [HieuChinhDocGia, dòng 68](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L68).

**Câu chính:** A bị khóa, có một lượt mất và một lượt đang mượn. Gửi HieuChinhDocGia với họ/tên mới hợp lệ và trạng thái hoạt động; sau thất bại thử đổi tên nhưng giữ khóa. Tiếp tục thử tên chứa |. Mỗi lần dữ liệu nào được đổi? Nếu cấp phát chuỗi tạm thất bại trước swap, bản gốc ra sao?

**Câu phụ 1:** Sau yêu cầu mở thẻ thất bại, UI có được báo tên đã đổi thành công không?

[Mở đáp án TV22](02_DAP_AN.md#TV22) · [Về đầu phần](#thanh)

<a id="TV30"></a>
### 021. TV30 — Cấp mã trước hay sau khi dữ liệu đã được chấp nhận?

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Cấp mã trước hay sau khi dữ liệu đã được chấp nhận?.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [ThemDocGia, dòng 59](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L59); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [ChenDocGiaCoMa, dòng 46](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L46); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [ConTroTam, dòng 29](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L29), [ConTroTam, dòng 42](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L42).

**Câu chính:** Mốc 20. Lần đầu thêm phái 'nam' bị từ chối; lần sau dữ liệu đúng nhưng giả lập cấp phát nút thất bại; lần thứ ba thành công. Thầy chỉ maTheLonNhatDaCap và hỏi vì sao cập nhật sau ChenDocGiaCoMa, nếu tăng mốc ngay đầu hàm rồi cố giảm trong mọi catch thì những đường lỗi nào phải quản lý? Phân biệt lỗi trả false và ngoại lệ.

**Câu phụ 1:** Output ma còn giá trị cũ sau false có làm mốc đã cấp thay đổi không?

[Mở đáp án TV30](02_DAP_AN.md#TV30) · [Về đầu phần](#thanh)

<a id="TV32"></a>
### 022. TV32 — Mở khóa thẻ có đồng nghĩa được mượn ngay?

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Mở khóa thẻ có đồng nghĩa được mượn ngay?.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [HieuChinhDocGia, dòng 68](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L68); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110).

**Câu chính:** A bị khóa thủ công, còn hai cuốn chưa quá hạn và không có lượt mất. B cũng bị khóa nhưng có lượt mất cũ; C bị khóa thủ công và giữ cuốn quá hạn. Lần lượt mở khóa rồi xin cuốn rảnh cho từng người. Truy nhánh HieuChinhDocGia và MuonSach; vì sao không thể dùng một bool 'mở khóa được' làm toàn bộ quyền mượn?

**Câu phụ 1:** A được mở khóa nhưng đã giữ đủ 3 thì yêu cầu mượn mới ra sao?

[Mở đáp án TV32](02_DAP_AN.md#TV32) · [Về đầu phần](#thanh)

<a id="TV35"></a>
### 023. TV35 — Successor chính là con phải

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** a · BST, mã thẻ và hiệu chỉnh.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [XoaDocGia, dòng 80](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L80).

**Câu chính:** Xóa gốc 10 không lịch sử, trái 5, phải 20 và 20 không có con trái. Hãy truy vết succLink, old->right và succ->right để chứng minh không tạo vòng 20 trỏ chính nó.

**Câu phụ 1:** Nếu successor 20 có phải 25 thì sau xóa 10 node 25 thuộc đâu?

[Mở đáp án TV35](02_DAP_AN.md#TV35) · [Về đầu phần](#thanh)

<a id="TV37"></a>
### 024. TV37 — Một hàm xóa xử lý gốc lẫn con mà không trả gốc mới

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Một hàm xóa xử lý gốc lẫn con mà không trả gốc mới.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [XoaDocGia, dòng 80](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L80); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [TimDocGia, dòng 3](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L3), [TimDocGia, dòng 8](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L8).

**Câu chính:** Cây 20 có 10 và 30, 10 có phải 15; không ai có lịch sử. Gọi xóa 25 thất bại, xóa 10 rồi xóa 20. Thầy chỉ NutDocGia ** link: ô nào được sửa ở mỗi lần, vì sao link khác null vẫn có thể chứa *link=null, và thay link bằng NutDocGia * khiến cập nhật root /ô con bị mất thế nào?

**Câu phụ 1:** Sau delete old có được dùng old để ghi thông báo tên không?

[Mở đáp án TV37](02_DAP_AN.md#TV37) · [Về đầu phần](#thanh)

<a id="TV39"></a>
### 025. TV39 — Xóa hết hồ sơ bằng hàm hủy không phải nghiệp vụ

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** a — Cổng thao tác.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [HuyCayDocGia, dòng 98](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L98); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [XoaDocGia, dòng 80](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L80); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [HuyThuVien, dòng 321](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L321).

**Câu chính:** Một nút UI thử “dọn độc giả” gọi HuyCayDocGia trực tiếp khi có người đang mượn. Hàm có hỏi điều kiện lịch sử như XoaDocGia không? Sau đó danh mục cuốn và mốc mã trong ThuVien ra sao?

**Câu phụ 1:** Chỉ đặt mọi cuốn 1 về 0 sau hủy có bảo toàn hệ thống không?

[Mở đáp án TV39](02_DAP_AN.md#TV39) · [Về đầu phần](#thanh)

<a id="TV46"></a>
### 026. TV46 — Yêu cầu gửi lại có phải cùng giao dịch hay một lượt mới?

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** Yêu cầu gửi lại có phải cùng giao dịch hay một lượt mới?.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KetThucMuon, dòng 50](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L50); [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [TimMuonDangMuonTheoMa, dòng 13](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L13).

**Câu chính:** A mượn X thành công, gọi lại ngay cùng mã; rồi trả X và một adapter gửi lại yêu cầu mượn cũ cùng ngày. Thầy hỏi tại sao lần lặp đầu bị chặn nhưng lần sau có thể tạo lượt mới; có thể gọi code là xử lý đúng một lần cho mỗi yêu cầu không? Cần dữ liệu nào để nhận biết lần gửi lại độc lập với trạng thái cuốn? Giả sử ban đầu A không giữ cuốn nào và các điều kiện khác hợp lệ.

**Câu phụ 1:** Dùng ngày+mã thẻ+mã cuốn làm request ID có phân biệt hai lần mượn hợp lệ cùng ngày không?

[Mở đáp án TV46](02_DAP_AN.md#TV46) · [Về đầu phần](#thanh)

<a id="TV48"></a>
### 027. TV48 — Tìm lại cuốn đã báo mất: khôi phục cần quy tắc gì?

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** Tìm lại cuốn đã báo mất: khôi phục cần quy tắc gì?.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KetThucMuon, dòng 50](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L50); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [HieuChinhDocGia, dòng 68](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L68); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90).

**Câu chính:** A đã báo mất X ngày 15/10, ngày 16/10 mang X đến; thẻ A đang khóa và còn Y đang mượn. Bản hiện tại gọi TraSach (X) sẽ ra sao? Thầy đề nghị đổi X về sẵn sàng rồi mở thẻ: kiểm file nào phản đối, và một tính năng 'tìm lại' cần phân biệt khôi phục cuốn, xử lý lịch sử mất và trạng thái thẻ thế nào?

**Câu phụ 1:** A có hai lượt mất khác cuốn; giải quyết một cuốn có đủ mở thẻ theo thiết kế mới không?

[Mở đáp án TV48](02_DAP_AN.md#TV48) · [Về đầu phần](#thanh)

<a id="TV51"></a>
### 028. TV51 — Gộp các lần quét lịch sử có làm đổi lỗi đầu tiên?

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Gộp các lần quét lịch sử có làm đổi lỗi đầu tiên?.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110); [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [DemSoSachDangMuon, dòng 4](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L4); [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [CoSachQuaHan7Ngay, dòng 8](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L8).

**Câu chính:** A hoạt động, giữ ba cuốn trong đó một quá hạn. MuonSach gọi DemSoSachDangMuon rồi CoSachQuaHan7Ngay. Thầy muốn gộp một vòng để giảm quét và trả thêm cuốn quá hạn nặng nhất. Phải giữ thứ tự thông báo nào; khi đã gặp một cuốn quá hạn có được dừng nếu còn cần đếm chính xác hoặc tìm max không?

**Câu phụ 1:** Chỉ gộp hai lượt quét lịch sử A có làm MuonSach thành O(H_A) không?

[Mở đáp án TV51](02_DAP_AN.md#TV51) · [Về đầu phần](#thanh)

<a id="TV57"></a>
### 029. TV57 — Kho vật lý đầy nhưng lịch sử còn chỗ: giao dịch cần tài nguyên nào?

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Kho vật lý đầy nhưng lịch sử còn chỗ: giao dịch cần tài nguyên nào?.

**Chỉ vào code:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [ThemCuonSach, dòng 71](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L71); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KetThucMuon, dòng 50](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L50).

**Câu chính:** Có đúng M cuốn và M−1 lượt lịch sử, A đủ quyền mượn một cuốn rảnh. Sau mượn, thử thêm cuốn mới, trả cuốn vừa mượn rồi mượn lại. Với M= MAX_BAN_GHI, hãy nêu kết quả từng bước và loại node cấp phát; tại sao cộng C+H để kiểm một hạn mức chung sẽ đổi hợp đồng?

**Câu phụ 1:** Khi H=M, báo mất lượt đang mở có cần node lịch sử mới không?

[Mở đáp án TV57](02_DAP_AN.md#TV57) · [Về đầu phần](#thanh)

<a id="TV62"></a>
### 030. TV62 — Một lỗi lịch sử của người khác có chặn giao dịch không

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** f — Phạm vi kiểm.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KiemTraDongThoiGian, dòng 21](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L21); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90).

**Câu chính:** RAM thử: A xin X hợp lệ, còn B có lượt Y đã trả nhưng ngày sai; B khác A, Y khác X. H chưa vượt ngưỡng. Helper timeline có kiểm ngày của lượt B/Y không? So với lần lưu toàn thư viện.

**Câu phụ 1:** Nếu đổi Y thành X trong lượt lỗi của B, kết luận thế nào?

[Mở đáp án TV62](02_DAP_AN.md#TV62) · [Về đầu phần](#thanh)

<a id="TV66"></a>
### 031. TV66 — Ngày trả được ghi trước trạng thái không có cửa sổ UI chen vào

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** g — Mô hình thực thi.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KetThucMuon, dòng 50](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L50); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490).

**Câu chính:** Trong KetThucMuon có vài phép gán liên tiếp: ngày trả, trạng thái phiếu, trạng thái cuốn, có thể khóa thẻ. Thầy hỏi giữa hai dòng thủ thư khác có bấm menu xem trạng thái nửa chừng trong cùng tiến trình hiện tại được không? Phân biệt với crash và mô hình đa luồng.

**Câu phụ 1:** Đặt từng phép gán thành atomic<int> có tự cho snapshot ba trường nhất quán không?

[Mở đáp án TV66](02_DAP_AN.md#TV66) · [Về đầu phần](#thanh)

<a id="TV71"></a>
### 032. TV71 — Parser nhận ngày nhưng cả bản ghi vẫn phải bị loại

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Parser nhận ngày nhưng cả bản ghi vẫn phải bị loại.

**Chỉ vào code:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [DocNgay, dòng 91](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L91); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KiemTraNgayGiaoDich, dòng 13](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L13).

**Câu chính:** File có ba phiếu: đang mượn với ngayTra=0/0/0; đã trả với ngayTra=0/0/0; đang mượn với ngayTra=16/10/2026. Thầy chỉ DocNgay và hỏi tại sao không để parser quyết định toàn bộ hợp lệ. Nếu sửa DocNgay để cấm 0/0/0 mọi nơi hoặc chấp nhận nó ở mọi trạng thái, trường hợp nào hỏng?

**Câu phụ 1:** 0/0/0 có dùng làm ngayMuon của một phiếu hợp lệ được không?

[Mở đáp án TV71](02_DAP_AN.md#TV71) · [Về đầu phần](#thanh)

<a id="TV73"></a>
### 033. TV73 — Vì sao tính ngày bằng số thứ tự thay vì vòng lặp từng ngày?

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Vì sao tính ngày bằng số thứ tự thay vì vòng lặp từng ngày?.

**Chỉ vào code:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [SoThuTuNgay, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L110); [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [NamNhuan, dòng 83](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L83); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InDocGiaQuaHan, dòng 144](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L144).

**Câu chính:** Thầy chỉ SoThuTuNgay và đề nghị đếm bằng tăng ngày từng bước từ ngày mượn tới ngày xét vì dễ hiểu. Với lịch sử dài qua nhiều năm và H nhiều, so tính đúng/chi phí hai cách; giải thích vai trò y/4−y/100+y/400 và vị trí cộng ngày nhuận. Chọn ví dụ khiến chỉ dùng chia 4 sai.

**Câu phụ 1:** Ngày 29/02/1900 nên được công thức âm thầm chuyển thành 01/03 hay từ chối?

[Mở đáp án TV73](02_DAP_AN.md#TV73) · [Về đầu phần](#thanh)

<a id="TV74"></a>
### 034. TV74 — Dùng abs cho khoảng cách ngày có che giao dịch ghi lùi?

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Dùng abs cho khoảng cách ngày có che giao dịch ghi lùi?.

**Chỉ vào code:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [KhoangCachNgay, dòng 116](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L116); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KiemTraNgayGiaoDich, dòng 13](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L13); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KiemTraDongThoiGian, dòng 21](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L21).

**Câu chính:** Một bạn thấy hiệu ngày âm trong test nên thêm abs vào KhoangCachNgay. Thầy yêu cầu xét A đã có giao dịch 16/10 nhưng nhập 15/10, lượt trả trước ngày mượn và kiểm ngày tương lai. Những nơi nào dựa vào dấu của hiệu; vì sao sửa helper chung có thể làm báo cáo đẹp số nhưng validator chấp nhận sai?

**Câu phụ 1:** Đổi chiều tham số KhoangCachNgay có tương đương thêm abs không?

[Mở đáp án TV74](02_DAP_AN.md#TV74) · [Về đầu phần](#thanh)

<a id="TV85"></a>
### 035. TV85 — Lưu–nạp: so cái gì để biết lịch sử vẫn thuộc đúng người?

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Lưu–nạp: so cái gì để biết lịch sử vẫn thuộc đúng người?.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [Ghi, dòng 261](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L261); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [DocNoiBo, dòng 210](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L210); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [DungBST, dòng 85](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L85); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [LayDanhSachDocGia, dòng 13](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L13).

**Câu chính:** Lưu cây lệch có nhiều độc giả trùng tên nhưng mã khác, mỗi người có lịch sử riêng; nạp lại cây cân bằng. Một test so địa chỉ root và preorder báo thất bại. Thầy yêu cầu chọn tiêu chí đồng nhất nghiệp vụ, đồng thời phát hiện lỗi vô tình gán danh sách người 10 sang 20 dù tổng H không đổi. Chỉ cần so inorder hay tổng lượt đã đủ chưa?

**Câu phụ 1:** Tổng H và mọi mã cuốn đúng nhưng ngày trả bị đổi sang ngày hợp lệ khác thì bộ kiểm có chắc phát hiện không?

[Mở đáp án TV85](02_DAP_AN.md#TV85) · [Về đầu phần](#thanh)

<a id="TV88"></a>
### 036. TV88 — Lượt mất cũ bị mở thẻ bằng cách sửa RAM

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** a/f — Chính sách và nguồn tin.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [HieuChinhDocGia, dòng 68](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L68); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90).

**Câu chính:** RAM thử có A đã mất X nhưng bị sửa trực tiếp trangThaiThe=1; không giữ sách khác. Xin cuốn Y rảnh với ngày hợp lệ. MuonSach có quét lịch sử mất để tự khóa A lại không, và vì sao UI chuẩn không tạo trạng thái này?

**Câu phụ 1:** Nếu đưa cùng trạng thái vào file rồi mở ứng dụng thì có đi tới menu không?

[Mở đáp án TV88](02_DAP_AN.md#TV88) · [Về đầu phần](#thanh)

<a id="TV94"></a>
### 037. TV94 — Nhập một giao dịch nguyên khối nhiều cuốn

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** f — Phạm vi transaction.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110).

**Câu chính:** A giữ 1 cuốn; muốn mượn cùng lúc Y/Z theo yêu cầu tất cả hoặc không cuốn nào. Y rảnh, Z bận. Gọi MuonSach(Y) rồi MuonSach(Z) hiện cho trạng thái gì? Muốn nguyên khối cần chuẩn bị và kiểm những gì trước khi nối node đầu?

**Câu phụ 1:** Nếu “hoàn tác” Y bằng TraSach khi Z lỗi, top và lịch sử có như chưa mượn không?

[Mở đáp án TV94](02_DAP_AN.md#TV94) · [Về đầu phần](#thanh)

<a id="TV99"></a>
### 038. TV99 — Ẩn hồ sơ đã ngừng dùng không xóa nghĩa vụ

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** a — Vòng đời hồ sơ.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [XoaDocGia, dòng 80](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L80); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [HieuChinhDocGia, dòng 68](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L68); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [Ghi, dòng 261](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L261).

**Câu chính:** Muốn màn hình mặc định không hiện người ngừng dùng nhưng vẫn giữ lịch sử và mã không tái cấp. Có thể dùng trangThaiThe=0 làm “đã lưu trữ” mà không đổi ý nghĩa khóa hiện có không? Xét người khóa do mất vẫn đang giữ sách.

**Câu phụ 1:** Xóa khỏi view mặc định có cho phép bỏ họ khỏi file khi lưu không?

[Mở đáp án TV99](02_DAP_AN.md#TV99) · [Về đầu phần](#thanh)

<a id="TV201"></a>
### 039. TV201 — Xóa một khoảng mã khi đang duyệt view

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** a — Mutation trong vòng duyệt.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [XoaDocGia, dòng 80](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L80); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [LayDanhSachDocGia, dòng 13](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L13).

**Câu chính:** Yêu cầu mới xóa các hồ sơ chưa có lịch sử trong khoảng[10,30]. Một view con trỏ đã lấy trước chứa 10,20,30; sau xóa 10, vòng lặp vẫn dùng pointer 10 để đọc lại mã hoặc nhánh cây cho bước sau. Thiết kế cách giữ danh sách mục tiêu và báo kết quả từng người mà không dùng vùng đã hủy.

**Câu phụ 1:** Sau xóa gốc hai con, các mã của node được chuyển có đổi không?

[Mở đáp án TV201](02_DAP_AN.md#TV201) · [Về đầu phần](#thanh)

<a id="TV202"></a>
### 040. TV202 — Thẻ SO_NGUYEN_LON_NHAT vẫn hợp lệ khi đọc

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** a — Miền biên khóa.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [ThemDocGia, dòng 59](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L59).

**Câu chính:** File có đúng một độc giả mã SO_NGUYEN_LON_NHAT, metadata cũng SO_NGUYEN_LON_NHAT, không lịch sử. Bộ kiểm khởi tạo hi bằng long long(SO_NGUYEN_LON_NHAT)+1 vì sao? Nạp được rồi có thêm độc giả mới được không?

**Câu phụ 1:** Dùng hi=SO_NGUYEN_LON_NHAT để tránh phép cộng có giữ được mọi khóa hợp lệ không?

[Mở đáp án TV202](02_DAP_AN.md#TV202) · [Về đầu phần](#thanh)

<a id="TV203"></a>
### 041. TV203 — Dựng BST cân bằng không được nối nhánh cũ còn sót

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** a — Nạp cây.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [DungBST, dòng 85](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L85); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [DocNoiBo, dòng 210](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L210).

**Câu chính:** Loader tạm nối các node thành nhánh phải rồi sắp nodes theo mã. Với các mã 10,20,30,40, DungBST phải ghi lại cả left và right cho từng node thế nào? Nếu chỉ ghi liên kết khi cây con không rỗng, nhánh phải tạm cũ có thể gây gì?

**Câu phụ 1:** Sắp mảng nodes có tự thay liên kết trong các node không?

[Mở đáp án TV203](02_DAP_AN.md#TV203) · [Về đầu phần](#thanh)

<a id="TV205"></a>
### 042. TV205 — Nhập lô hồ sơ mới khác nạp thay thư viện

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** a — Hai loại bulk.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [ThemDocGia, dòng 59](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L59); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [DocNoiBo, dòng 210](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L210); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [DungBST, dòng 85](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L85).

**Câu chính:** Có 100 hồ sơ mới chưa có mã, muốn thêm vào thư viện đang có lịch sử. Một bạn tạo file chỉ 100 người rồi gọi DocFile để tận dụng DungBST nhanh. Vì sao không tương đương 100 lần ThemDocGia, và hợp đồng bulk thêm cần giữ gì?

**Câu phụ 1:** Nếu 100 hồ sơ đã có mã từ hệ thống khác thì có được dùng nguyên mã mà không kiểm va chạm không?

[Mở đáp án TV205](02_DAP_AN.md#TV205) · [Về đầu phần](#thanh)

<a id="TV206"></a>
### 043. TV206 — Người bị xóa có thể còn được hiển thị trong view

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** a — Vòng đời sau xóa.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [XoaDocGia, dòng 80](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L80); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InDocGiaTheoTenHo, dòng 114](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L114).

**Câu chính:** Một màn hình thử giữ view ba con trỏ độc giả. Trong cùng caller, xóa người chưa có lịch sử ở giữa view rồi tiếp tục in view cũ. Xóa thành công có làm các phần tử view tự co lại không? So với hiệu chỉnh tên của cùng người.

**Câu phụ 1:** Chỉ giảm số lượng view một đơn vị có đủ không?

[Mở đáp án TV206](02_DAP_AN.md#TV206) · [Về đầu phần](#thanh)

<a id="TV209"></a>
### 044. TV209 — Có phiếu mở nhưng ngày trả không rỗng trong RAM

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** f/g — Tiền điều kiện toàn vẹn.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KiemTraDongThoiGian, dòng 21](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L21); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KetThucMuon, dòng 50](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L50); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90).

**Câu chính:** RAM chẩn đoán có một phiếu trạng thái 0, ngày mượn hợp lệ nhưng ngayTra đã là 16/10; cuốn trạng thái 1, không phiếu trùng, ngày gọi 17 hợp lệ. TraSach có nhất thiết từ chối riêng lỗi sentinel này không? So với KiemTraToanVen.

**Câu phụ 1:** Có được quảng bá TraSach như công cụ sửa dữ liệu hỏng này không?

[Mở đáp án TV209](02_DAP_AN.md#TV209) · [Về đầu phần](#thanh)

<a id="TV212"></a>
### 045. TV212 — Tham số sửa tên alias với trường trong node

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** a — Chuẩn bị trước swap.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [HieuChinhDocGia, dòng 68](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L68).

**Câu chính:** Caller API truyền ho tham chiếu p->thongTin.ten và ten tham chiếu p->thongTin.ho để đổi hai trường trên bản sao. Vì sao HieuChinhDocGia chép các chuỗi tạm trước mọi swap giúp tránh đọc trường đã bị sửa giữa chừng?

**Câu phụ 1:** Một tham số phai alias ho vốn chứa "Nam" có được giữ đọc an toàn nếu các trường khác swap trước không?

[Mở đáp án TV212](02_DAP_AN.md#TV212) · [Về đầu phần](#thanh)

<a id="TV214"></a>
### 046. TV214 — Hai thẻ khóa không cho biết ai đã khóa

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** a — Dấu vết thao tác.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [HieuChinhDocGia, dòng 68](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L68); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [DanhDauMatSach, dòng 138](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L138); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [Ghi, dòng 261](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L261).

**Câu chính:** Một thẻ bị khóa thủ công, một thẻ khóa do mất. Người vận hành hỏi ai bấm khóa và lúc nào. File hiện lưu đủ để trả lời không? Nếu thêm audit, cần ghi sự kiện gì và khi nào để tránh ghi “đã khóa” cho yêu cầu thất bại?

**Câu phụ 1:** Có lượt mất có đủ suy ra lần khóa cuối cùng luôn do báo mất không?

[Mở đáp án TV214](02_DAP_AN.md#TV214) · [Về đầu phần](#thanh)

<a id="TV215"></a>
### 047. TV215 — Chuyển phiếu mở giữa hai độc giả không chỉ là nối danh sách

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** f — Điều chỉnh chủ lượt.

**Chỉ vào code:** [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [DocGia, dòng 283](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L283); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KiemTraDongThoiGian, dòng 21](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L21); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90).

**Câu chính:** Nhập nhầm A mượn X, muốn chuyển phiếu mở sang B; B đang giữ 3 cuốn, thẻ hoạt động. Cuốn X vẫn trạng thái 1 nên một bạn chỉ tháo/nối node và nói không ảnh hưởng kho. Các điều kiện nào bị bỏ qua, và dữ liệu nào đủ/thiếu để sửa giao dịch quá khứ?

**Câu phụ 1:** Nếu B chỉ giữ 2 cuốn thì nối node đã luôn đúng chưa?

[Mở đáp án TV215](02_DAP_AN.md#TV215) · [Về đầu phần](#thanh)

<a id="TV216"></a>
### 048. TV216 — Không thể chỉ khóa cuốn khi mở dịch vụ mượn

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** f — Đồng thời.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110); [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [DemSoSachDangMuon, dòng 4](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L4).

**Câu chính:** Giả định dịch vụ đồng thời: A đang giữ 2 cuốn, hai request chọn Y và Z đều rảnh. Mỗi request khóa riêng cuốn mình rồi đọc số đang giữ=2 trước khi commit. Có thể A giữ 4 không; cần bảo vệ thêm dữ liệu nào?

**Câu phụ 1:** Một mutex trong mỗi exe có đủ cho hai exe cùng ghi file không?

[Mở đáp án TV216](02_DAP_AN.md#TV216) · [Về đầu phần](#thanh)

<a id="TV217"></a>
### 049. TV217 — Trả và báo mất cùng một phiếu trong dịch vụ

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** g — Xung đột kết thúc.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KetThucMuon, dòng 50](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L50).

**Câu chính:** Giả định hai request đồng thời cùng đọc phiếu X đang mở: một trả thường, một báo mất. Nếu mỗi request dùng con trỏ đã tìm và ghi thẳng ba trường, những trạng thái hỗn hợp nào có thể xảy ra; phạm vi giao dịch cần bao gồm gì?

**Câu phụ 1:** Cho lệnh trả luôn thắng báo mất có phải chỉ thêm một if cuối không?

[Mở đáp án TV217](02_DAP_AN.md#TV217) · [Về đầu phần](#thanh)

<a id="TV218"></a>
### 050. TV218 — Khóa có thứ tự để tránh hai yêu cầu chờ nhau

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** f/g — Thiết kế khóa.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KetThucMuon, dòng 50](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L50).

**Câu chính:** Trong bản dịch vụ giả định, mượn khóa độc giả A rồi cuốn X; trả khóa X rồi A. Hai request chạy đồng thời, mỗi bên đã giữ khóa đầu. Truy trạng thái chờ và đề xuất quy ước lấy khóa có thể kiểm thử.

**Câu phụ 1:** Đặt timeout rồi tự báo thất bại có đủ khi một bên đã cập nhật phiếu chưa?

[Mở đáp án TV218](02_DAP_AN.md#TV218) · [Về đầu phần](#thanh)

<a id="TV219"></a>
### 051. TV219 — Một triệu hồ sơ và giới hạn stack duyệt

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** a — Quy mô độc giả.

**Chỉ vào code:** [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [MAX_DOC_GIA, dòng 264](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L264); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [LayDanhSachDocGia, dòng 13](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L13); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [DocNoiBo, dòng 210](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L210).

**Câu chính:** Yêu cầu R=1.000.000 hồ sơ, D=1.000, C=10.000, H=100.000, một người thao tác tuần tự; 90% chỉ tìm mã. Bản hiện từ chối ở đâu? Giả sử được tăng giới hạn, so cây dựng cân bằng khi nạp với cây sau nhiều lần thêm mã tăng.

**Câu phụ 1:** Tăng MAX_BAN_GHI có giải quyết giới hạn R không?

[Mở đáp án TV219](02_DAP_AN.md#TV219) · [Về đầu phần](#thanh)

<a id="TV221"></a>
### 052. TV221 — Sentinel ngày có chuỗi chuẩn riêng

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** f/g — Parse và serialize.

**Chỉ vào code:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [DocNgay, dòng 91](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L91); [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [ChuoiNgay, dòng 102](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L102); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [Ghi, dòng 261](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L261).

**Câu chính:** Hai chuỗi “1/2/2024” và “01/02/2024” được đọc thành ngày thật rồi ghi lại. So với “0/0/0” và “00/00/0000”, kết quả có giống nhau không? Vì sao test round-trip từng byte có thể báo lỗi dù ngày thật giữ nguyên?

**Câu phụ 1:** Ngày thật có số 0 ở đầu được chấp nhận có nghĩa mọi chuỗi toàn số 0 đều là ngày rỗng không?

[Mở đáp án TV221](02_DAP_AN.md#TV221) · [Về đầu phần](#thanh)

<a id="TV222"></a>
### 053. TV222 — Thêm lịch sử vào đầu để bỏ quét tail

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** f — Hợp đồng thứ tự.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110); [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [LietKeSachDangMuon, dòng 20](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L20); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [Ghi, dòng 261](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L261).

**Câu chính:** Muốn bỏ vòng quét tail của MuonSach bằng cách nối phiếu mới vào đầu danh sách. Các kiểm count/quá hạn/max và top còn phụ thuộc thứ tự node không? Những đầu ra nào có thể đổi dù tổng lượt vẫn đúng?

**Câu phụ 1:** Phiếu cùng mã xuất hiện nhiều lần có làm TimMuonDangMuonTheoMa chọn nhầm nếu dữ liệu hợp lệ không?

[Mở đáp án TV222](02_DAP_AN.md#TV222) · [Về đầu phần](#thanh)

<a id="TV224"></a>
### 054. TV224 — Mốc đã cấp không phải số người còn hoạt động

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** a — Metadata báo cáo.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [ThemDocGia, dòng 59](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L59); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [XoaDocGia, dòng 80](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L80); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [DemDocGia, dòng 28](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L28).

**Câu chính:** Mốc maTheLonNhatDaCap=9000, BST còn 20 người trong đó 15 bị khóa. Dashboard muốn báo số độc giả đăng ký hiện có và số thẻ hoạt động. Có dùng mốc 9000 hoặc mã max trong cây cho một trong hai số này không?

**Câu phụ 1:** Mốc 9000 có chứng minh đã có đúng 9000 người thật từng đăng ký không?

[Mở đáp án TV224](02_DAP_AN.md#TV224) · [Về đầu phần](#thanh)

<a id="TV225"></a>
### 055. TV225 — Họ tên hợp lệ nhưng phái sai ở khoảng trắng

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** a — Lớp chuẩn hóa.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [HopLeDocGia, dòng 30](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L30); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [ThemDocGia, dòng 59](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L59); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [HieuChinhDocGia, dòng 68](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L68).

**Câu chính:** Qua API thêm, ho=" Nguyen ", ten=" An ", phai=" Nam " đều có khoảng trắng bao quanh. Họ/tên có thể được chuẩn hóa nhưng phái đi nhánh nào? Vì sao không suy mọi field cùng một chính sách trim, và khi từ chối mốc mã có đổi không?

**Câu phụ 1:** Hạ chữ phái thành nam trong KhoaSoSanh có giúp HopLePhai chấp nhận không?

[Mở đáp án TV225](02_DAP_AN.md#TV225) · [Về đầu phần](#thanh)

<a id="TV226"></a>
### 056. TV226 — Chu trình lịch sử chặn đường chạy trước điểm commit giả lập

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** f — Thứ tự commit.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110); [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [DemSoSachDangMuon, dòng 4](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L4); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KiemTraDongThoiGian, dòng 21](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L21).

**Câu chính:** Trên bản sao, chỉ chuyển phép gán cuon->trangThai=1 lên ngay trước vòng tìm tail cuối MuonSach; giữ nguyên mọi kiểm trước đó. A hoạt động, có hai node lịch sử đã trả nối vòng với nhau; ngày hợp lệ, cuốn X rảnh. Lời gọi có tới phép gán vừa chuyển không? Truy đúng thứ tự helper và trạng thái trước khi kết luận lỗi nửa commit.

**Câu phụ 1:** Nếu lịch sử A rỗng, vòng hai node đã trả thuộc B và dùng cuốn khác X thì đường chạy thay đổi thế nào?

[Mở đáp án TV226](02_DAP_AN.md#TV226) · [Về đầu phần](#thanh)

<a id="TV227"></a>
### 057. TV227 — ThuVien không copy nhưng DocGia vẫn copy được

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** a — Bảo vệ kiểu dữ liệu.

**Chỉ vào code:** [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [ThuVien, dòng 289](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L289); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [DocGia, dòng 283](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L283); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [ChenDocGiaCoMa, dòng 46](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L46).

**Câu chính:** Một hàm thử làm DocGia b=a với a đã có lịch sử, rồi chuyển b vào một node khác. ThuVien đã delete copy constructor có ngăn được phép copy này không? Vì sao ChenDocGiaCoMa chặn d.dsMuonTra khác null?

**Câu phụ 1:** Copy DocGia không lịch sử để chuẩn bị node mới có cùng rủi ro danh sách không?

[Mở đáp án TV227](02_DAP_AN.md#TV227) · [Về đầu phần](#thanh)

<a id="TV228"></a>
### 058. TV228 — Qua nửa đêm: ngày lịch khác thời lượng tính bằng giờ

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** f/g — Mô hình thời gian.

**Chỉ vào code:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [KhoangCachNgay, dòng 116](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L116); [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [HomNay, dòng 117](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L117); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KiemTraNgayGiaoDich, dòng 13](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L13).

**Câu chính:** Một người mượn lúc 23:55 ngày 10, trả 00:05 ngày 11; v1 chỉ lưu ngày. KhoangCachNgay trả bao nhiêu, có đo 10 phút không? Nếu dịch vụ sau này phục vụ nhiều múi giờ, phải chốt thời điểm nào quyết định ngày nghiệp vụ.

**Câu phụ 1:** Có nên nhân hiệu ngày với 24 để khẳng định số giờ thực giữ sách không?

[Mở đáp án TV228](02_DAP_AN.md#TV228) · [Về đầu phần](#thanh)

<a id="TV229"></a>
### 059. TV229 — Ngày máy lùi làm file cũ bị xem là tương lai

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** f/g — Phụ thuộc môi trường.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90); [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [HomNay, dòng 117](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L117); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490).

**Câu chính:** File đã lưu lượt mượn 16/10/2026 hợp lệ khi máy ở 17/10. Sau đó máy bị đặt lại 15/10; mở cùng byte file. Vì sao loader có thể từ chối, và --date 14/10 có sửa được kiểm file này không?

**Câu phụ 1:** Hash file không đổi có chứng minh mọi kết quả kiểm cũng phải không đổi không?

[Mở đáp án TV229](02_DAP_AN.md#TV229) · [Về đầu phần](#thanh)

<a id="TV230"></a>
### 060. TV230 — Hủy trước parse và parse sai không cùng dấu hiệu

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** a — Hợp đồng API nhập.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [ManHinhDocGia, dòng 133](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L133); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [NhapSo, dòng 395](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L395); [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [DocSoNguyen, dòng 61](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L61).

**Câu chính:** Trong --plain chọn xóa độc giả: nhập abc rồi 12, so với nhập /huy rồi 12. Người 12 không lịch sử. Vì sao case đầu có thể xóa còn case sau 12 được đọc ở ngữ cảnh khác; script kiểm thử phải đồng bộ theo giao thức thế nào?

**Câu phụ 1:** Chỉ kiểm không có exception có phát hiện script đi nhầm nhánh không?

[Mở đáp án TV230](02_DAP_AN.md#TV230) · [Về đầu phần](#thanh)

<a id="TV231"></a>
### 061. TV231 — Đệ quy lúc dựng cây khác đệ quy trên cây nhập tăng

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** a — Độ sâu thuật toán.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [DungBST, dòng 85](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L85); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [HuyCayDocGia, dòng 98](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L98).

**Câu chính:** Nhóm cấm mọi đệ quy vì sợ cây 100.000 nút lệch. Vì sao DungBST vẫn dùng đệ quy mà độ sâu không bằng 100.000 khi nhận mảng đã sắp? So lời gọi trên khoảng chỉ số với duyệt cây đã tồn tại.

**Câu phụ 1:** Nếu chọn phần tử đầu thay mid trong DungBST thì hai cận đổi ra sao?

[Mở đáp án TV231](02_DAP_AN.md#TV231) · [Về đầu phần](#thanh)

<a id="TV232"></a>
### 062. TV232 — Kiểm khoảng mượn kề nhau có bỏ sót khoảng xa

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** f/g — Chứng minh validator.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90).

**Câu chính:** Sau sort các lượt cùng cuốn theo ngày bắt đầu, validator chỉ so từng cặp kề nhau. Một người đòi so mọi cặp O(H²) vì sợ lượt 1 chồng lượt 3. Hãy lập luận vì sao mọi cặp kề hợp lệ đã loại chồng lấn xa, xét cả lượt đang mở.

**Câu phụ 1:** Nếu sort theo ngày kết thúc rồi mã thẻ, hai lượt cùng cuốn: A mã 20 mượn 01 trả 10; B mã 10 mượn 10 trả 10, đều tháng 10/2026. Điều gì xảy ra khi end bằng nhau và so kề?

[Mở đáp án TV232](02_DAP_AN.md#TV232) · [Về đầu phần](#thanh)

<a id="TV233"></a>
### 063. TV233 — Reset số đang giữ mỗi ngày làm mất sách qua đêm

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** f — Quét sự kiện.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [MocMuon, dòng 79](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L79); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90).

**Câu chính:** Sửa sweep để held=0 mỗi khi đổi ngày thay vì đổi độc giả. A giữ 3 cuốn từ 01 đến 10/10/2026, mượn cuốn thứ 4 ngày 05 và trả 06. Truy đến lần từ chối đầu của bản đúng và bản sửa. Có được kết luận bản sửa chắc chắn chấp nhận file này không?

**Câu phụ 1:** Nếu bộ test chỉ assert bốn khoảng trên phải bị từ chối thì có bắt được mutation reset theo ngày không? Thiết kế ca bổ sung tối thiểu.

[Mở đáp án TV233](02_DAP_AN.md#TV233) · [Về đầu phần](#thanh)

<a id="TV234"></a>
### 064. TV234 — Sắp sự kiện theo ngày trước mã thẻ

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** f — Nhóm sự kiện.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [MocMuon, dòng 79](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L79); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90).

**Câu chính:** Đổi comparator MocMuon từ mã→ngày→loại sang ngày→mã→loại nhưng giữ reader/held hiện tại. A mượn ngày 01, B mượn 02, A trả 03. Theo dõi held khi đổi người và nêu vì sao một biến held không đủ cho thứ tự mới.

**Câu phụ 1:** Chỉ bỏ nhánh kiểm held<0 để hết lỗi có đúng không?

[Mở đáp án TV234](02_DAP_AN.md#TV234) · [Về đầu phần](#thanh)

<a id="TV235"></a>
### 065. TV235 — Dữ liệu lịch sử tương lai dù --date là quá khứ

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** f/g — Đường nhập file.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90).

**Câu chính:** Ngày máy 17/10, file có lượt mở 16/10. Chạy --date 10/10 rồi chọn trả lượt đó. Nạp file có bị từ chối vì sau ngày mô phỏng không, và giao dịch trả ngày 10 bị chặn ở đâu?

**Câu phụ 1:** Báo cáo i ngày 10 có tự dựng lại thư viện như nó tồn tại ngày 10 không?

[Mở đáp án TV235](02_DAP_AN.md#TV235) · [Về đầu phần](#thanh)

<a id="TV236"></a>
### 066. TV236 — Khoảng trắng trong số của file khác menu

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** a/f — Cú pháp dữ liệu.

**Chỉ vào code:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [DocSoNguyen, dòng 61](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L61); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [BoDoc, dòng 51](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L51); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [NhapSo, dòng 395](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L395).

**Câu chính:** Nhập “ 12 ” ở menu mã thẻ được nhận sau chuẩn hóa, nhưng dòng count độc giả “ 12 ” trong file bị từ chối. Một người muốn thêm trim ở mọi số trong loader. Phải đánh giá điều gì về định dạng và test, thay vì gọi hai đường là mâu thuẫn?

**Câu phụ 1:** Cho trim đầu/cuối có làm “1 2” thành 12 không?

[Mở đáp án TV236](02_DAP_AN.md#TV236) · [Về đầu phần](#thanh)

<a id="TV237"></a>
### 067. TV237 — Dòng cuối không newline và dòng rỗng dư

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** a/f — Kết thúc file.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [BoDoc, dòng 51](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L51); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [DocNoiBo, dòng 210](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L210).

**Câu chính:** File v1 hợp lệ bỏ newline ở cuối bản ghi cuối; bản khác thêm một dòng rỗng sau newline kết thúc chuẩn. Bộ đọc có xem hai trường hợp giống nhau không? Truy any, EOF và peek sau khi đọc đủ số bản ghi.

**Câu phụ 1:** Nếu dòng cuối cần đọc hoàn toàn rỗng rồi EOF thì sao?

[Mở đáp án TV237](02_DAP_AN.md#TV237) · [Về đầu phần](#thanh)

<a id="TV238"></a>
### 068. TV238 — BOM chỉ được bỏ ở đầu file

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** a/f — Mã hóa file.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [BoDoc, dòng 51](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L51); [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [HopLeVanBan, dòng 38](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L38).

**Câu chính:** Ghép hai đoạn file UTF-8 bằng công cụ làm BOM thứ hai nằm trước họ độc giả giữa file. Dòng vẫn hiển thị giống bình thường. Vì sao bộ đọc không coi BOM đó như BOM đầu, và cách chẩn đoán cần nhìn gì?

**Câu phụ 1:** BOM đầu file bị bỏ có làm file nguồn trên đĩa mất BOM khi chỉ --check không?

[Mở đáp án TV238](02_DAP_AN.md#TV238) · [Về đầu phần](#thanh)

<a id="TV239"></a>
### 069. TV239 — Giới hạn dòng và giới hạn trường bảo vệ hai thứ khác

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** a/f — Tài nguyên parser.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [BoDoc, dòng 51](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L51); [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [HopLeVanBan, dòng 38](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L38).

**Câu chính:** Một file có dòng độc giả dài 100.000 byte; file khác có dòng 2000 byte nhưng một trường họ dài 600 byte. Chúng bị chặn ở cùng tầng không? Vì sao không thể bỏ cận dòng với lý do mỗi field đã có 512 byte?

**Câu phụ 1:** Một triệu dòng ngắn có được cận 65536 tự ngăn tổng tài nguyên không?

[Mở đáp án TV239](02_DAP_AN.md#TV239) · [Về đầu phần](#thanh)

<a id="TV240"></a>
### 070. TV240 — Count lịch sử của từng người không phải quota riêng 200.000

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** f/g — Ngân sách tổng.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [DocNoiBo, dòng 210](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L210).

**Câu chính:** File khai báo A có 150.000 lượt, B có 100.000 lượt, mỗi người không quá 3 lượt mở; tổng cuốn/độc giả hợp lệ. Với MAX_BAN_GHI=200.000, loader có chấp nhận vì mỗi count đều nhỏ hơn 200.000 không?

**Câu phụ 1:** Đảo A/B trong file có thay việc cả file bị từ chối không?

[Mở đáp án TV240](02_DAP_AN.md#TV240) · [Về đầu phần](#thanh)

<a id="TV241"></a>
### 071. TV241 — Đếm lịch sử toàn thư viện trong validator với bộ nhớ theo cấu hình

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** f/g — Dung lượng tạm.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [Luot, dòng 78](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L78); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [MocMuon, dòng 79](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L79).

**Câu chính:** Một file chỉ có R=2,H=3,C=2. Bộ kiểm cấp những mảng nào theo MAX và mảng nào theo dữ liệu thực? Vì sao công thức bộ nhớ O(R+H+C) không đủ mô tả số byte thực cấp của bản hiện tại khi dữ liệu nhỏ?

**Câu phụ 1:** Nâng MAX để nhận 1 triệu lượt có chỉ tăng bộ nhớ khi thật có 1 triệu node không?

[Mở đáp án TV241](02_DAP_AN.md#TV241) · [Về đầu phần](#thanh)

<a id="TV242"></a>
### 072. TV242 — Kiểm RAM tùy ý không phải bộ cứu mọi con trỏ

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** a/f — Giới hạn validator.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraToanVen, dòng 331](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L331); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90).

**Câu chính:** Một bug ghi root bằng địa chỉ không thuộc node sống. Có thể gọi KiemTraToanVen rồi tin catch(...) sẽ trả false an toàn cho mọi con trỏ lỗi không? Phân biệt dữ liệu nghiệp vụ sai với vi phạm bộ nhớ C++.

**Câu phụ 1:** Một pointer không null có đủ vượt qua tiền điều kiện sống không?

[Mở đáp án TV242](02_DAP_AN.md#TV242) · [Về đầu phần](#thanh)

<a id="TV243"></a>
### 073. TV243 — Gộp hai người bằng cách nối lịch sử

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** a — Hợp nhất hồ sơ.

**Chỉ vào code:** [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [DocGia, dòng 283](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L283); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [XoaDocGia, dòng 80](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L80).

**Câu chính:** Xác minh ngoài chương trình rằng thẻ 10 và 20 là cùng một người, mỗi thẻ đang giữ 2 cuốn khác nhau. Muốn giữ thẻ 10 và ghép lịch sử 20 vào 10. Những quy tắc nào khiến không thể chỉ nối hai danh sách rồi xóa 20?

**Câu phụ 1:** Nếu hiện tại mỗi thẻ giữ 1 cuốn thì đã chắc hợp lệ toàn lịch sử chưa?

[Mở đáp án TV243](02_DAP_AN.md#TV243) · [Về đầu phần](#thanh)

<a id="TV246"></a>
### 074. TV246 — Sửa ngày trả trong file có thể phá hai phía

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** g — Chỉnh lịch sử.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KiemTraDongThoiGian, dòng 21](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L21).

**Câu chính:** A trả X ngày 10, B mượn X ngày 10. Người vận hành sửa ngày trả của A thành 12 vì nhầm giấy tờ, giữ các trường khác. Độ đúng “ngày trả sau ngày mượn” có đủ; cần đối soát thêm chuỗi cuốn và hạn mức người thế nào?

**Câu phụ 1:** Nếu B bắt đầu 13 nhưng A đã mượn thêm 3 cuốn ngày 11 thì có chắc sửa thành 12 hợp lệ không?

[Mở đáp án TV246](02_DAP_AN.md#TV246) · [Về đầu phần](#thanh)

<a id="TV247"></a>
### 075. TV247 — Đổi mọi ngày cùng một độ lệch có giữ toàn vẹn không

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** f/g — Kiểm theo phép biến đổi.

**Chỉ vào code:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [SoThuTuNgay, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L110); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KiemTraDongThoiGian, dòng 21](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L21).

**Câu chính:** Muốn tạo fixture hồi quy bằng dịch tất cả ngày thật tiến 1 ngày và giữ sentinel 0/0/0. Các khoảng cách/chồng lấn có giữ không, và điều kiện biên nào có thể làm file mới bị từ chối dù file cũ hợp lệ?

**Câu phụ 1:** Dịch chỉ ngày mượn mà không ngày trả có còn là phép bảo toàn không?

[Mở đáp án TV247](02_DAP_AN.md#TV247) · [Về đầu phần](#thanh)

<a id="TV248"></a>
### 076. TV248 — Mượn chưa lưu rồi thoát: mở lại có thể cho người khác mượn

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** f — Độ bền sự kiện.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [LuuFile, dòng 341](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L341); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490).

**Câu chính:** A mượn X thành công trong RAM nhưng chưa lưu, đóng tiến trình; mở lại file cũ X rảnh rồi B mượn X. Trong thực tế A đã mang sách đi. Code có thể phát hiện sự kiện bị mất trên đĩa không và cần quy trình đối soát nào?

**Câu phụ 1:** Tự lưu sau mỗi lần gọi MuonSach trả false có giải quyết sự kiện thành công trước crash không?

[Mở đáp án TV248](02_DAP_AN.md#TV248) · [Về đầu phần](#thanh)

<a id="TV249"></a>
### 077. TV249 — Đổi hạn mức 3 thành tham số cấu hình

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** f — Ràng buộc dùng chung.

**Chỉ vào code:** [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [DemSoSachDangMuon, dòng 4](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L4); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90).

**Câu chính:** Trên bản sao thầy cho thử hạn mức 4 để so thiết kế, nhưng chỉ sửa điều kiện trong MuonSach. A mượn cuốn thứ 4 thành công rồi bấm lưu. Những cổng nào còn dùng 3, và vì sao thay một literal không đủ thực hiện yêu cầu?

**Câu phụ 1:** Nếu thầy chỉ muốn hiển thị 4 dòng sách đang mượn có phải đổi hạn mức không?

[Mở đáp án TV249](02_DAP_AN.md#TV249) · [Về đầu phần](#thanh)

<a id="TV250"></a>
### 078. TV250 — Giảm hạn mức không thể sửa bằng xóa phiếu

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** f — Di trú chính sách.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KetThucMuon, dòng 50](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L50).

**Câu chính:** Giả định đổi chính sách từ 3 xuống 2 trong một hệ thống thực; file đang có A giữ 3 cuốn hợp lệ theo quy tắc cũ. Có nên xóa bớt phiếu để file qua validator mới không? Nêu cách cho trả dần nhưng chặn mượn thêm và vấn đề kiểm lịch sử cũ.

**Câu phụ 1:** Chỉ dùng cùng một biến MAX cho hiện tại lẫn mọi lịch sử có đủ không?

[Mở đáp án TV250](02_DAP_AN.md#TV250) · [Về đầu phần](#thanh)

<a id="TV251"></a>
### 079. TV251 — Tìm thẻ lặp trong một thao tác UI có đáng loại

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** a/f — Chi phí toàn đường gọi.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [ManHinhMuonTra, dòng 202](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L202); [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [LietKeSachDangMuon, dòng 20](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L20); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110).

**Câu chính:** Màn hình f tìm thẻ để xác nhận, h tìm lại để in, MuonSach lại tìm khi commit. Với cây lệch h lớn, có thể truyền node đã tìm cho mọi bước để giảm quét không? Phân tích lợi ích và tiền điều kiện vòng đời khi API còn công khai nhận mã.

**Câu phụ 1:** Nếu sau này cho mở NAP ngay trong bảng h, con trỏ ban đầu còn chắc dùng được không?

[Mở đáp án TV251](02_DAP_AN.md#TV251) · [Về đầu phần](#thanh)

<a id="TV252"></a>
### 080. TV252 — Nạp lại thay đổi hình cây nhưng không là cân bằng liên tục

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** a — Tối ưu vận hành.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [DungBST, dòng 85](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L85); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [DocNoiBo, dòng 210](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L210); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [ThemDocGia, dòng 59](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L59).

**Câu chính:** Sau nhiều lần thêm mã tăng, nhóm đề xuất lưu rồi nạp lại sau mỗi lần thêm để luôn có cây cân bằng. Cách này giữ tập dữ liệu ra sao và phải trả chi phí/giới hạn gì ngoài O(log R) tìm kiếm?

**Câu phụ 1:** Nếu lưu thất bại mà vẫn NAP file cũ để “cân bằng” thì sao?

[Mở đáp án TV252](02_DAP_AN.md#TV252) · [Về đầu phần](#thanh)

<a id="TV253"></a>
### 081. TV253 — Ghi hồ sơ theo tên cần giữ lịch sử đi cùng mã

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** a — Serialization thứ tự.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [Ghi, dòng 261](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L261); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InDocGiaTheoTenHo, dòng 114](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L114).

**Câu chính:** Một refactor muốn file dễ đọc nên ghi độc giả theo tên từ view, nhưng vòng ghi lịch sử vẫn dùng mảng inorder cũ cùng chỉ số i. Người tên trùng/khác làm lỗi gì mà tổng R/H vẫn có thể đúng?

**Câu phụ 1:** Giữ tổng số lượt mỗi người bằng nhau có che lỗi không?

[Mở đáp án TV253](02_DAP_AN.md#TV253) · [Về đầu phần](#thanh)

<a id="TV254"></a>
### 082. TV254 — Định dạng không có số phiên bản: phát hiện nhầm schema

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** f/g — Tiến hóa file.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [DocNoiBo, dòng 210](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L210); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [Ghi, dòng 261](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L261); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [BoDoc, dòng 51](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L51).

**Câu chính:** Bản hiện bắt đầu bằng mốc mã rồi số đầu. Nhóm muốn thêm trường điện thoại vào dòng độc giả và số phiên bản ở đầu file. Nếu ghi mới nhưng dùng loader cũ, parser có tự hiểu được không? Thiết kế nhận diện và chuyển đổi mà không ghi đè file cũ khi thất bại.

**Câu phụ 1:** Nếu số phiên bản mới tình cờ là số nguyên hợp lệ cho mốc, có đủ phân biệt hai schema không?

[Mở đáp án TV254](02_DAP_AN.md#TV254) · [Về đầu phần](#thanh)

<a id="TV255"></a>
### 083. TV255 — Hồ sơ mới mang trạng thái hoạt động ở đâu

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** a — Khởi tạo nghiệp vụ.

**Chỉ vào code:** [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [DocGia, dòng 283](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L283); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [ThemDocGia, dòng 59](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L59); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [ManHinhDocGia, dòng 133](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L133).

**Câu chính:** Form thêm độc giả chỉ hỏi họ, tên, phái; form sửa mới hỏi trạng thái. Vì sao hồ sơ thêm có trạng thái 1 mà không cần đọc ô thứ 4? Nếu đổi default DocGia thành khóa, đâu là hành vi đổi âm thầm?

**Câu phụ 1:** Chỉ sửa giá trị values[3] trong form thêm có bảo đảm đổi trạng thái node không?

[Mở đáp án TV255](02_DAP_AN.md#TV255) · [Về đầu phần](#thanh)

<a id="TV257"></a>
### 084. TV257 — Trùng mã ở xa nhau trong file được phát hiện sau bước nào

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** a — Kiểm duy nhất khi nạp.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [DocNoiBo, dòng 210](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L210); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [DungBST, dòng 85](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L85).

**Câu chính:** File có độc giả theo mã 30,10,40,10, hai hồ sơ 10 có tên và lịch sử khác nhau. Nếu kiểm trùng chỉ với dòng người vừa đọc trước đó rồi bỏ vòng kiểm sau sort, lỗi nào lọt? Vì sao không dựng BST trước rồi mặc định tìm thấy một 10 là đủ?

**Câu phụ 1:** Nếu dùng chèn BST từng người để bắt trùng thay sort rồi dựng, chi phí với file mã tăng có thể khác thế nào?

[Mở đáp án TV257](02_DAP_AN.md#TV257) · [Về đầu phần](#thanh)

<a id="TV258"></a>
### 085. TV258 — Hai file cùng mã người nhưng lịch sử xung đột khi hợp nhất

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** a/f — Namespace dữ liệu.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [DocNoiBo, dòng 210](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L210); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [ChenDocGiaCoMa, dòng 46](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L46); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [DocGia, dòng 283](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L283).

**Câu chính:** KhoA và khoB độc lập đều có thẻ 10 nhưng khác người, mỗi người có lịch sử riêng và có thể cùng mã cuốnX#1. Nếu muốn hợp nhất, đổi mã ngườiB thành 11 có đủ không? Nêu các namespace và ánh xạ cần giữ trong vùng tạm.

**Câu phụ 1:** Cùng tên sách và ISBN có bảo đảm X#1 của hai kho là cùng bản vật lý không?

[Mở đáp án TV258](02_DAP_AN.md#TV258) · [Về đầu phần](#thanh)

<a id="TV259"></a>
### 086. TV259 — Chọn predecessor thay successor khi xóa hai con

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** a — So thuật toán xóa.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [XoaDocGia, dòng 80](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L80).

**Câu chính:** Gốc 40 không lịch sử, trái 20 có phải 30 (30 có trái 25), phải 70 có trái 50. Thầy cho thử thay successor bằng predecessor trên bản sao. Phải tháo node nào, giữ cây con nào và có được đổi chỉ mã giữa hai node không?

**Câu phụ 1:** Nếu predecessor chính là con trái 20 và 20 có trái 10 thì thứ tự tháo/nối nào cần giữ?

[Mở đáp án TV259](02_DAP_AN.md#TV259) · [Về đầu phần](#thanh)

<a id="TV260"></a>
### 087. TV260 — Xóa một phần lịch sử để sửa số đang giữ

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** f/g — Nguồn sự thật.

**Chỉ vào code:** [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [DemSoSachDangMuon, dòng 4](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L4); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KetThucMuon, dòng 50](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L50); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90).

**Câu chính:** A có phiếu X đang mở, cuốnX trạng thái 1. Một màn hình thử xóa node đó để giảm số đang giữ thay vì gọi TraSach. Số hiển thị A về 0 nhưng quan hệ cuốn và khả năng người khác mượn thay đổi thế nào?

**Câu phụ 1:** Nếu đồng thời đặt cuốn 0 thì đã tương đương trả đúng chưa?

[Mở đáp án TV260](02_DAP_AN.md#TV260) · [Về đầu phần](#thanh)

<a id="TV301"></a>
### 088. TV301 — Đúng với cha nhưng sai khoảng khóa của tổ tiên

**Phụ trách:** Thành · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** a — Bất biến BST toàn cây.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [TimDocGia, dòng 3](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L3), [TimDocGia, dòng 8](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L8); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [LayDanhSachDocGia, dòng 13](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L13); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90).

**Câu chính:** RAM debug có gốc 40, con trái 20, con phải của 20 là 50; các hồ sơ không lịch sử, mốc đã cấp 50. Mỗi cạnh đều có con trái nhỏ hơn cha hoặc con phải lớn hơn cha. TimDocGia(50), inorder và validator toàn vẹn trả gì? Vì sao kiểm riêng quan hệ cha–con không đủ?

**Câu phụ 1:** Thay 50 bằng 40 hoặc 30, trường hợp nào hợp lệ? Có nên đổi so sánh khoảng mở thành đóng để nhận khóa bằng tổ tiên?

[Mở đáp án TV301](02_DAP_AN.md#TV301) · [Về đầu phần](#thanh)

<a id="TV23"></a>
### 089. TV23 — Độc giả chỉ giữ một cuốn nhưng mượn vẫn chậm

**Phụ trách:** Thành · **Ưu tiên:** P3 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Chi phí kiểm tra toàn thư viện.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KiemTraDongThoiGian, dòng 21](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L21); [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [DemSoSachDangMuon, dòng 4](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L4).

**Câu chính:** A có 10.000 lượt đã trả và một lượt đang mượn; toàn thư viện có R độc giả, H lượt, C cuốn. A xin cuốn Y#1 hợp lệ. Vì sao chi phí không chỉ là tìm A và Y#1? Chỉ ra các lần duyệt lặp và nơi nối cuối lịch sử; việc giữ tối đa ba cuốn có giới hạn độ dài lịch sử không?

**Câu phụ 1:** Chuyển các lượt mở lên đầu có loại được quét timeline toàn thư viện không?

[Mở đáp án TV23](02_DAP_AN.md#TV23) · [Về đầu phần](#thanh)

<a id="TV24"></a>
### 090. TV24 — Gọi helper chèn trực tiếp có bỏ qua mốc mã?

**Phụ trách:** Thành · **Ưu tiên:** P3 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Hợp đồng helper và mã định danh.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [ChenDocGiaCoMa, dòng 46](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L46); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [ThemDocGia, dòng 59](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L59); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90).

**Câu chính:** Thư viện có mốc mã 12. Một lập trình viên gọi ChenDocGiaCoMa để chèn độc giả 99 không lịch sử, thay vì ThemDocGia, rồi lưu. Cây tìm được 99 có đủ chứng minh trạng thái hợp lệ không? Nếu DocGia truyền vào đã có dsMuonTra, helper làm gì? Ai chịu trách nhiệm cập nhật mốc?

**Câu phụ 1:** Tự đặt mốc 99 sau helper thành công có đủ chứng minh caller đúng mọi điều kiện ThemDocGia không?

[Mở đáp án TV24](02_DAP_AN.md#TV24) · [Về đầu phần](#thanh)

<a id="TV27"></a>
### 091. TV27 — Xem lịch sử mới nhất trước nhưng giữ danh sách gốc

**Phụ trách:** Thành · **Ưu tiên:** P3 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** Bài sửa trên bản sao: xem lịch sử.

**Chỉ vào code:** [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [LietKeSachDangMuon, dòng 20](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L20); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [MuonTra, dòng 279](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L279).

**Câu chính:** Trên bản sao, thêm màn hình lịch sử một thẻ theo ngày mượn giảm; cùng ngày giữ thứ tự gốc trong danh sách. A có lượt X ngày 14/10, Y ngày 16/10, Z ngày 16/10 theo thứ tự lưu. Không đảo liên kết thật. Nêu thuật toán, bộ nhớ, tiêu chí đồng hạng và test rồi tự cài.

**Câu phụ 1:** Heap không ổn định có thể giữ thứ tự ngày hòa bằng cách nào mà không đảo next?

[Mở đáp án TV27](02_DAP_AN.md#TV27) · [Về đầu phần](#thanh)

<a id="TV67"></a>
### 092. TV67 — Gia hạn bảy ngày bằng sửa ngày mượn

**Phụ trách:** Thành · **Ưu tiên:** P3 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** f/g · Mượn, trả, mất và ngày giao dịch.

**Chỉ vào code:** [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [MuonTra, dòng 279](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L279); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KiemTraDongThoiGian, dòng 21](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L21); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90).

**Câu chính:** Thầy hỏi nếu muốn gia hạn, có thể đổi ngayMuon của lượt đang mở thành hôm nay để tránh quá hạn không? Những dữ liệu và ý nghĩa nào bị mất?

**Câu phụ 1:** Chỉ lưu hạn trả mới nhưng không giữ ngày gia hạn có trả lời ai gia hạn lúc nào không?

[Mở đáp án TV67](02_DAP_AN.md#TV67) · [Về đầu phần](#thanh)

<a id="TV68"></a>
### 093. TV68 — Hoàn tác lần trả gần nhất

**Phụ trách:** Thành · **Ưu tiên:** P3 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** f/g · Mượn, trả, mất và ngày giao dịch.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KetThucMuon, dòng 50](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L50); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90).

**Câu chính:** Người dùng trả X nhầm, sau đó B đã mượn X. Muốn đặt lượt cũ của A về đang mượn để undo, bất biến nào sẽ vỡ? Vì sao chỉ phục hồi một node không đủ?

**Câu phụ 1:** Nếu B chưa mượn X nhưng A đã dùng đủ 3 chỗ sau trả nhầm, bật lại lượt X có an toàn không?

[Mở đáp án TV68](02_DAP_AN.md#TV68) · [Về đầu phần](#thanh)

<a id="TV75"></a>
### 094. TV75 — Không quá hạn hay dữ liệu không tính được?

**Phụ trách:** Thành · **Ưu tiên:** P3 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Không quá hạn hay dữ liệu không tính được?.

**Chỉ vào code:** [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [CoSachQuaHan7Ngay, dòng 8](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L8); [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [QuaHan7Ngay, dòng 121](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L121); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KiemTraDongThoiGian, dòng 21](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L21); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InDocGiaQuaHan, dòng 144](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L144).

**Câu chính:** Trên RAM debug, A hoạt động có một lượt mở với ngày 31/02; xin cuốn rảnh. CoSachQuaHan7Ngay có thể trả false vì ngày sai; thầy hỏi có phải được quyền mượn không. Truy tiếp KiemTraDongThoiGian và so với báo cáo dùng SoThuTuNgay: vì sao bool không đủ diễn đạt cả 'không quá hạn' và 'không xác định'?

**Câu phụ 1:** Đổi bool sang ba trạng thái có tự sửa RAM ngày sai không?

[Mở đáp án TV75](02_DAP_AN.md#TV75) · [Về đầu phần](#thanh)

<a id="TV76"></a>
### 095. TV76 — Phiên mở qua nửa đêm

**Phụ trách:** Thành · **Ưu tiên:** P3 · **Phạm vi:** Hiện tại.

**Trọng tâm:** f/g · Mượn, trả, mất và ngày giao dịch.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KiemTraNgayGiaoDich, dòng 13](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L13).

**Câu chính:** Chương trình mở lúc 23:59 ngày 16/10, không thoát, trả sách lúc 00:05 ngày 17/10. Ngày truyền cho nghiệp vụ tự đổi theo đồng hồ không? Nhãn ngày có thể cũ vì đâu?

**Câu phụ 1:** Bật F5 lưu có tự làm biến ngay nhận HomNay mới không?

[Mở đáp án TV76](02_DAP_AN.md#TV76) · [Về đầu phần](#thanh)

<a id="TV89"></a>
### 096. TV89 — Ghi file bằng sizeof(DocGia)

**Phụ trách:** Thành · **Ưu tiên:** P3 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Tích hợp · Lưu, nạp và vòng đời dữ liệu.

**Chỉ vào code:** [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [DocGia, dòng 283](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L283); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [Ghi, dòng 261](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L261); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [DocNoiBo, dòng 210](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L210).

**Câu chính:** Thầy chỉ con trỏ dsMuonTra và hỏi vì sao không ghi nguyên sizeof(DocGia) cho nhanh. Sau khởi động lại, chuỗi và địa chỉ node trong dữ liệu thô có ý nghĩa gì?

**Câu phụ 1:** Dùng sizeof cộng chiều dài chuỗi nhưng vẫn ghi pointer next có thành định dạng bền không?

[Mở đáp án TV89](02_DAP_AN.md#TV89) · [Về đầu phần](#thanh)

<a id="TV93"></a>
### 097. TV93 — Một màn hình cần nhiều số liệu độc giả: quét hay lưu bộ đếm?

**Phụ trách:** Thành · **Ưu tiên:** P3 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** Một màn hình cần nhiều số liệu độc giả: quét hay lưu bộ đếm?.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [LayDanhSachDocGia, dòng 13](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L13); [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [DemSoSachDangMuon, dòng 4](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L4); [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [CoSachQuaHan7Ngay, dòng 8](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L8); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [TongQuan, dòng 246](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L246).

**Câu chính:** Dashboard mới muốn số thẻ hoạt động, khóa, đang giữ sách và có quá hạn; một người có thể vừa khóa vừa quá hạn. Thầy đề nghị chia độc giả thành các cây riêng cho mỗi nhóm hoặc lưu bốn bộ đếm lâu dài. So với một lượt duyệt tạo số liệu tạm, rủi ro cập nhật sau mất/trả/sửa thẻ/nạp file là gì và các nhóm có cộng thành tổng R không?

**Câu phụ 1:** Không giao dịch nhưng ngày qua mốc 8 có làm cache số quá hạn cũ sai không?

[Mở đáp án TV93](02_DAP_AN.md#TV93) · [Về đầu phần](#thanh)

<a id="TV96"></a>
### 098. TV96 — Dừng sau khi thấy ba lượt mở có còn đúng với mọi caller?

**Phụ trách:** Thành · **Ưu tiên:** P3 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Dừng sau khi thấy ba lượt mở có còn đúng với mọi caller?.

**Chỉ vào code:** [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [DemSoSachDangMuon, dòng 4](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L4); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90).

**Câu chính:** A có 80.000 lượt trả và ba lượt mở xen kẽ. Muốn DemSoSachDangMuon trả ngay khi đủ 3 để tăng tốc; thầy hỏi hàm dùng để quyết định >=3 hay để báo số chính xác. Với RAM hỏng có 4 lượt mở, cách tối ưu có che lỗi không; một helper đếm chính xác và một predicate đủ hạn mức nên có hợp đồng khác thế nào?

**Câu phụ 1:** Predicate đủ 3 có thể trả false trước khi duyệt hết nếu mới thấy 2 không?

[Mở đáp án TV96](02_DAP_AN.md#TV96) · [Về đầu phần](#thanh)

<a id="TV98"></a>
### 099. TV98 — Nhập lịch sử cũ thay cho giao dịch hiện tại

**Phụ trách:** Thành · **Ưu tiên:** P3 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** Tích hợp · Lưu, nạp và vòng đời dữ liệu.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KiemTraDongThoiGian, dòng 21](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L21); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90).

**Câu chính:** Thầy muốn nhập một lượt quá khứ vào giữa lịch sử. Có thể gọi MuonSach rồi TraSach với ngày cũ là xong không? Đặc tả mới phải xét những xung đột nào?

**Câu phụ 1:** Chèn một node vào đúng thứ tự ngày trong danh sách có giải quyết hết xung đột không?

[Mở đáp án TV98](02_DAP_AN.md#TV98) · [Về đầu phần](#thanh)

<a id="TV100"></a>
### 100. TV100 — Một ca ở quầy có bốn yêu cầu liên tiếp và hai lần thất bại

**Phụ trách:** Thành · **Ưu tiên:** P3 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Một ca ở quầy có bốn yêu cầu liên tiếp và hai lần thất bại.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KetThucMuon, dòng 50](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L50); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110); [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [LietKeSachDangMuon, dòng 20](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L20); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [HieuChinhDocGia, dòng 68](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L68).

**Câu chính:** Ngày 16/10/2026, A khóa thủ công, giữ X từ 08/10 và Y từ 14/10; B giữ Z từ 14/10; W rảnh. A trả Z, trả X, xin W, rồi trả Y. Giả sử mọi mốc liên quan không muộn hơn 16/10. Nêu kết quả, các phiếu/cuốn/thẻ sau từng bước; thầy yêu cầu chỉ nhánh kiểm và giải thích vì sao không gom cả ca thành thành công hoặc thất bại.

**Câu phụ 1:** Tổng cuối ca A giữ 0 có cho biết từng bước nào đã thất bại không?

[Mở đáp án TV100](02_DAP_AN.md#TV100) · [Về đầu phần](#thanh)


<a id="tan"></a>
## Tấn — 100 câu

<a id="TN01"></a>
### 001. TN01 — Đổi tên xong, hai kiểu liệt kê có còn đúng?

**Phụ trách:** Tấn · **Ưu tiên:** P1 · **Phạm vi:** Hiện tại.

**Trọng tâm:** b · BST và thứ tự tên.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InDocGiaTheoTenHo, dòng 114](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L114); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [TimDocGia, dòng 3](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L3), [TimDocGia, dòng 8](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L8).

**Câu chính:** Cây có mã 10 tên Dung, 20 tên An, 30 tên Binh. Đổi tên mã 30 thành A, rồi lần lượt in theo tên, tìm mã 30 và in theo mã. Dự đoán thứ tự hai báo cáo; chỉ ra vì sao sắp trực tiếp thông tin các nút theo tên có thể phá tìm kiếm.

**Câu phụ 1:** Nếu tráo riêng họ/tên giữa hai node nhưng giữ mã và lịch sử, tìm mã vẫn thành công. Test nào phát hiện lỗi còn lại?

[Mở đáp án TN01](02_DAP_AN.md#TN01) · [Về đầu phần](#tan)

<a id="TN02"></a>
### 002. TN02 — In theo thể loại rồi thêm đầu sách

**Phụ trách:** Tấn · **Ưu tiên:** P1 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** d · Bất biến mảng đầu sách.

**Chỉ vào code:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [InDauSachTheoTheLoai, dòng 94](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L94); [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [TimViTriChenTheoTen, dòng 39](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L39).

**Câu chính:** Mảng gốc theo tên là A/LichSu, B/Toan, C/LichSu. Sau khi in theo thể loại, thêm đầu tên BB. Dự đoán mảng gốc và kết quả nhóm thể loại. Nếu lập trình viên sắp ngay mảng gốc thành A,C,B để in, bước chèn nhị phân còn cơ sở nào đúng?

**Câu phụ 1:** Nếu chỉ xem d mà chưa chèn thêm thì mảng gốc bị sắp sai có thể bị bỏ sót trong demo không?

[Mở đáp án TN02](02_DAP_AN.md#TN02) · [Về đầu phần](#tan)

<a id="TN03"></a>
### 003. TN03 — Có tám lượt lịch sử nhưng chỉ giữ hai cuốn

**Phụ trách:** Tấn · **Ưu tiên:** P1 · **Phạm vi:** Hiện tại.

**Trọng tâm:** h · Lịch sử và lượt đang mở.

**Chỉ vào code:** [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [LietKeSachDangMuon, dòng 20](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L20); [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [DemSoSachDangMuon, dòng 4](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L4).

**Câu chính:** Độc giả có tám nút lịch sử: sáu lượt đã trả, sau đó S1 và S2 đang mượn; S1 cũng xuất hiện trong lượt đã trả đầu tiên. Chức năng h phải in gì? Vì sao chỉ duyệt ba nút đầu hoặc lấy lần gặp mã S1 đầu tiên đều sai?

**Câu phụ 1:** Hai lượt S1 đều mang trạng thái mở trong RAM debug. Có nên in một dòng theo mã duy nhất để làm h trông đúng không?

[Mở đáp án TN03](02_DAP_AN.md#TN03) · [Về đầu phần](#tan)

<a id="TN05"></a>
### 004. TN05 — Tên bằng nhau, heap sort có đảo kết quả ngẫu nhiên?

**Phụ trách:** Tấn · **Ưu tiên:** P1 · **Phạm vi:** Hiện tại.

**Trọng tâm:** b · Đồng tên và khóa phụ.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [TenHoTruoc, dòng 39](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L39); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InDocGiaTheoTenHo, dòng 114](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L114); [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [SoSanhChuoi, dòng 23](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L23).

**Câu chính:** Ba độc giả có (mã,họ,tên): (30,Tran,AN), (10,Tran,an), (20,Le,An). In theo tên hai lần rồi lưu–nạp và in lại. Thứ tự nào phải giữ? Heap sort không ổn định có làm mất tính xác định không, và quy tắc này có bảo đảm thứ tự từ điển tiếng Việt?

**Câu phụ 1:** Nếu bỏ mã khỏi comparator và giữ heap hiện tại, hai người cùng họ/tên còn có thứ tự xác định theo yêu cầu không? Nếu thay bằng stable sort trên inorder thì sao?

[Mở đáp án TN05](02_DAP_AN.md#TN05) · [Về đầu phần](#tan)

<a id="TN201"></a>
### 005. TN201 — Một nút được đưa vào view đúng một lần

**Phụ trách:** Tấn · **Ưu tiên:** P1 · **Phạm vi:** Hiện tại.

**Trọng tâm:** b — Duyệt cây.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [LayDanhSachDocGia, dòng 13](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L13).

**Câu chính:** Cây gốc 40, trái 20, phải 60; 20 có phải 30, 30 có trái 25. Truy vết stack đến khi xuất 30. Nếu sau pop lại đi sang trái của nút vừa xuất thay vì sang phải, báo cáo sai ở đâu?

**Câu phụ 1:** Nếu cây chỉ có chuỗi con phải, stack hoạt động có đạt R không?

[Mở đáp án TN201](02_DAP_AN.md#TN201) · [Về đầu phần](#tan)

<a id="TN09"></a>
### 006. TN09 — Bản xuất có dòng quá dài nhưng xem chi tiết không phải sửa dữ liệu

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Phân trang — Ranh giới biểu diễn.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [DongBang, dòng 213](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L213); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [XemChiTiet, dòng 225](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L225); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [HienThiPhanTrang, dòng 433](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L433).

**Câu chính:** Một dòng bảng chứa nhiều trường dài bị rút gọn ở cột. Enter mở chi tiết để xem lại. Nêu chuỗi nào phải được giữ nguyên để phân biệt hai đầu có tiền tố tên giống nhau; nếu dùng chữ đã vẽ để tạo bản xuất thì mất gì?

**Câu phụ 1:** Nếu chi tiết giữ đúng chuỗi UTF-8 nhưng xuất từ ô CHAR_INFO đã cắt, hai đầu tên chung tiền tố có thể gây sai gì khi đối soát, dù số dòng vẫn đúng?

[Mở đáp án TN09](02_DAP_AN.md#TN09) · [Về đầu phần](#tan)

<a id="TN19"></a>
### 007. TN19 — In mã tăng bằng duyệt trực tiếp hay phải tạo view?

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** In mã tăng bằng duyệt trực tiếp hay phải tạo view?.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InDocGiaTheoMa, dòng 106](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L106); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [LayDanhSachDocGia, dòng 13](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L13); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [HienThiPhanTrang, dòng 433](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L433); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [LuongChuoi, dòng 70](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L70).

**Câu chính:** BST lớn, người dùng chỉ muốn b theo mã. Thầy chỉ InDocGiaTheoMa đang đếm, cấp mảng rồi duyệt lại; đề nghị in ngay khi inorder pop để tránh mảng kết quả. Nêu thứ tự xuất trên cây 20–10–30 với 10 phải 15, chi phí/bộ nhớ được giảm và phần nào còn cần khi UI vẫn gom text để phân trang. In lúc đẩy node có đúng không?

**Câu phụ 1:** Truyền stream trực tiếp ra file thay vì LuongChuoi có thay điểm nhìn thấy output dở khi lỗi không?

[Mở đáp án TN19](02_DAP_AN.md#TN19) · [Về đầu phần](#tan)

<a id="TN21"></a>
### 008. TN21 — Kết quả mới chỉ ghi một phần khi mảng view thiếu chỗ

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Kết quả mới chỉ ghi một phần khi mảng view thiếu chỗ.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [LayDanhSachDocGia, dòng 13](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L13); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InDocGiaTheoTenHo, dòng 114](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L114).

**Câu chính:** Một caller đếm cây có 2 người để cấp view rồi tự chèn người thứ 3 trước LayDanhSachDocGia; hàm ném lỗi ở phần tử thứ 3. Thầy hỏi hai ô đầu và cây đang ở trạng thái nào, có được bắt lỗi rồi vẫn in 2 ô như 'toàn bộ' không? Trong chương trình tuần tự hiện tại cặp đếm–duyệt có tự bị chen giao dịch không? Tại sao DemDocGia lại gọi LayDanhSachDocGia với out=nullptr, capacity=0 mà vẫn đếm được cây không rỗng?

**Câu phụ 1:** Nếu capacity lớn hơn R thì các ô sau n có được in vì đã cấp phát đủ không?

[Mở đáp án TN21](02_DAP_AN.md#TN21) · [Về đầu phần](#tan)

<a id="TN29"></a>
### 009. TN29 — Một thể loại bị in thành nhiều nhóm dù sort đúng

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Một thể loại bị in thành nhiều nhóm dù sort đúng.

**Chỉ vào code:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [InDauSachTheoTheLoai, dòng 94](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L94); [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [SoSanhChuoi, dòng 23](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L23).

**Câu chính:** Kho có thể loại 'Cong nghe','CONG NGHE','Cong nghe' và tên A, B, C. Sau refactor, sort vẫn dùng SoSanhChuoi nhưng đổi nhãn nhóm dùng string!=; người dùng thấy ba nhóm. Thầy yêu cầu chỉ mâu thuẫn giữa quan hệ sắp và quan hệ bằng, cách giữ nhãn hiển thị gốc mà nhóm vẫn thống nhất; xử lý chữ có dấu có tự tương đương không?

**Câu phụ 1:** Đổi nhãn nhóm sang viết hoa có cần sửa mọi theLoai trong kho không?

[Mở đáp án TN29](02_DAP_AN.md#TN29) · [Về đầu phần](#tan)

<a id="TN30"></a>
### 010. TN30 — Vì sao phải sắp view thể loại khi kho đã sắp tên?

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Vì sao phải sắp view thể loại khi kho đã sắp tên?.

**Chỉ vào code:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [InDauSachTheoTheLoai, dòng 94](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L94); [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [TimViTriChenTheoTen, dòng 39](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L39).

**Câu chính:** Tên A loại L2, B loại L1, C loại L2. Thầy muốn tiết kiệm mảng tạm bằng quét kho gốc và in mỗi nhóm một lần. So ba cách: in khi loại thay đổi; quét lại toàn kho cho từng loại; sort view. Cách nào giữ nhóm liền, thứ tự trong nhóm và mảng gốc, với chi phí nào?

**Câu phụ 1:** Nếu có D thể loại khác nhau thì quét toàn kho cho từng loại tốn bao nhiêu lần xét đầu?

[Mở đáp án TN30](02_DAP_AN.md#TN30) · [Về đầu phần](#tan)

<a id="TN38"></a>
### 011. TN38 — Gộp hai cuốn cùng tên trên bảng rồi trả một cuốn

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** Gộp hai cuốn cùng tên trên bảng rồi trả một cuốn.

**Chỉ vào code:** [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [LietKeSachDangMuon, dòng 20](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L20); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [TraSach, dòng 135](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L135); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InTop10SachDuocMuonNhieuNhat, dòng 168](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L168).

**Câu chính:** A giữ X#1 và X#2 cùng tên. UI mới gộp thành 'TênX × 2', người dùng muốn trả một bản nhưng không chỉ mã. Thầy hỏi bản hiện tại h giữ thông tin nào, có được tùy tiện chọn X#1 để trả không, và một màn hình gộp cần cho xác định bản vật lý thế nào để kiểm kê khớp?

**Câu phụ 1:** Sau trảX#2, nhóm tên còn 1 có cho biết X#1 đã được đổi trạng thái không?

[Mở đáp án TN38](02_DAP_AN.md#TN38) · [Về đầu phần](#tan)

<a id="TN43"></a>
### 012. TN43 — Xem sách đang giữ rồi hủy: giao dịch bắt đầu từ lúc nào?

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Xem sách đang giữ rồi hủy: giao dịch bắt đầu từ lúc nào?.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [ManHinhMuonTra, dòng 202](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L202); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [BieuMau, dòng 317](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L317); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110).

**Câu chính:** A đang giữ 2 cuốn; vào f, đóng bảng h, nhập mã X rảnh rồi hủy trước xác nhận. Sau đó B mượn X và A thử lại. Thầy yêu cầu chỉ ranh giới từ hành động UI sang MuonSach, giải thích vì sao từng thấy X rảnh không tạo quyền ưu tiên; nếu thêm xem trước quyền mượn cần kiểm lại lúc nào?

**Câu phụ 1:** Preview xong A đã giữ 2 cuốn; trước lần thử lại, A mượn một cuốn khác và B cũng mượn X. Lời gọi A xin X bị chặn ở đâu trước?

[Mở đáp án TN43](02_DAP_AN.md#TN43) · [Về đầu phần](#tan)

<a id="TN48"></a>
### 013. TN48 — Đầu ra báo cáo có được dùng làm đầu vào loader

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Menu — Hai schema khác nhau.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InDocGiaTheoMa, dòng 106](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L106); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [Ghi, dòng 261](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L261); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [DocNoiBo, dòng 210](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L210).

**Câu chính:** Người dùng redirect báo cáo b ra file rồi NAP file đó vì có đủ tên/mã đang nhìn thấy. So dòng đầu, số trường, nhãn trạng thái và dữ liệu thiếu với schema Ghi. Vì sao đổi Hoat dong thành 1 vẫn chưa biến nó thành backup?

**Câu phụ 1:** Nếu bảng chỉ gồm người không lịch sử thì có đủ tự dựng một file cùng thư viện không?

[Mở đáp án TN48](02_DAP_AN.md#TN48) · [Về đầu phần](#tan)

<a id="TN49"></a>
### 014. TN49 — Một phím mang nhiều ý nghĩa: lỗi nếu xử lý toàn cục

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Một phím mang nhiều ý nghĩa: lỗi nếu xử lý toàn cục.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [DocPhimConsole, dòng 107](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L107); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [BieuMau, dòng 317](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L317); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChonMenu, dòng 402](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L402); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490).

**Câu chính:** Người dùng nhập mã 10, nhấn 0 để quay lại menu con rồi nhấn Esc ở form đang sửa hồ sơ. Một refactor bắt mọi ký tự 0 hoặc Esc ở lớp đọc phím và trả 'thoát chương trình'. Thầy yêu cầu giải thích vì sao parser phím không nên quyết định nghiệp vụ chung, mỗi màn hình phải dịch sự kiện ra hành động ở đâu và dữ liệu nào đã commit.

**Câu phụ 1:** Esc ở menu con độc giả có cần lưu–thoát toàn chương trình không?

[Mở đáp án TN49](02_DAP_AN.md#TN49) · [Về đầu phần](#tan)

<a id="TN53"></a>
### 015. TN53 — Xóa nội dung trên form rồi hủy có xóa hồ sơ thật không?

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Xóa nội dung trên form rồi hủy có xóa hồ sơ thật không?.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [BieuMau, dòng 317](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L317); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [ManHinhDocGia, dòng 133](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L133); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [HieuChinhDocGia, dòng 68](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L68).

**Câu chính:** A đang giữ sách; mở sửa tên, Ctrl+A để xóa field, gõ tên khác, chuyển trạng thái thẻ rồi Esc. Thầy chỉ fields, cursors và values: vùng nào bị đổi, khi nào mới gọi HieuChinhDocGia? Nếu tối ưu bằng bind field trực tiếp vào chuỗi trong node, việc hủy và lỗi validation phải được thiết kế lại ra sao?

**Câu phụ 1:** Form trả true nhưng HieuChinhDocGia từ chối mở thẻ có làm tên mới được áp một phần không?

[Mở đáp án TN53](02_DAP_AN.md#TN53) · [Về đầu phần](#tan)

<a id="TN54"></a>
### 016. TN54 — Ba mốc 'xác nhận', 'đã thêm', 'đã lưu' có cùng nghĩa không?

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Ba mốc 'xác nhận', 'đã thêm', 'đã lưu' có cùng nghĩa không?.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [BieuMau, dòng 317](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L317); [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [ManHinhNhapDauSach, dòng 124](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L124); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [LuuFile, dòng 341](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L341).

**Câu chính:** Form thêm đầu sách có số trang abc, người dùng Ctrl+Enter; sửa thành 100, xác nhận thành công rồi đóng cửa sổ trước khi lưu. Thầy yêu cầu chỉ ba tầng và dữ liệu ở mỗi mốc. Nếu UI hiện 'đã lưu' ngay khi NhapBieuMau trả true, thông báo gây hiểu nhầm gì; nên dùng thông báo nào theo kết quả thật?

**Câu phụ 1:** ThemDauSach true rồi LuuFile false nên thông báo gộp "thêm thất bại" có chính xác không?

[Mở đáp án TN54](02_DAP_AN.md#TN54) · [Về đầu phần](#tan)

<a id="TN56"></a>
### 017. TN56 — Chạy kịch bản nhập liệu bị hết stdin giữa hồ sơ

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Chạy kịch bản nhập liệu bị hết stdin giữa hồ sơ.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [ManHinhDocGia, dòng 133](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L133); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [NhapDong, dòng 386](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L386); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490).

**Câu chính:** Kịch bản --plain đã thêm người A đầy đủ vào RAM, đang nhập họ của B thì EOF trước tên. Thầy hỏi B có node nửa chừng không, A có tự được lưu không, và mã thoát 0 có chứng minh kịch bản thành công toàn bộ không? Đề xuất cách kiểm hậu điều kiện cho script demo mà không sửa nghiệp vụ.

**Câu phụ 1:** EOF ngay sau F5 đã lưu thành công có làm file vừa lưu bị hoàn tác không?

[Mở đáp án TN56](02_DAP_AN.md#TN56) · [Về đầu phần](#tan)

<a id="TN57"></a>
### 018. TN57 — Tên vừa ô nhập nhưng vượt giới hạn lưu theo byte

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Tên vừa ô nhập nhưng vượt giới hạn lưu theo byte.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [BieuMau, dòng 317](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L317); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [TuUTF16, dòng 24](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L24); [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [HopLeVanBan, dòng 38](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L38).

**Câu chính:** Người dùng dán tên gồm nhiều ký tự Việt, ô nhập vẫn nhận nhưng nghiệp vụ từ chối vì vượt 512 byte. Thầy chỉ wstring 4096 và HopLeVanBan 512: hai cận đo gì, cắt field cho vừa cột có giải quyết không? Thiết kế báo lỗi/tính độ dài mà không cắt giữa UTF-8 hoặc âm thầm sửa tên.

**Câu phụ 1:** Có thể đếm byte sau khi tự cắt tên rồi vẫn báo tên đã lưu nguyên vẹn không? Thiết kế một test phân biệt cắt hiển thị với cắt dữ liệu.

[Mở đáp án TN57](02_DAP_AN.md#TN57) · [Về đầu phần](#tan)

<a id="TN64"></a>
### 019. TN64 — Thêm nút trả trên bảng h: dòng được chọn phải mang dữ liệu gì?

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** Thêm nút trả trên bảng h: dòng được chọn phải mang dữ liệu gì?.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [HienThiPhanTrang, dòng 433](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L433); [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [LietKeSachDangMuon, dòng 20](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L20); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [TraSach, dòng 135](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L135).

**Câu chính:** Hiện Enter trong bảng chỉ mở dòng đầy đủ. Thầy muốn thêm 'Trả cuốn đang chọn'; bảng có tiêu đề, dòng trống, tên bị cắt và hai cuốn cùng tên. Nếu lấy selected rồi tách chuỗi hiển thị để gọi TraSach, có thể sai những gì? Thiết kế kết quả có bản ghi và xác nhận đúng mã/người/ngày.

**Câu phụ 1:** Sau trả thành công, giữ selected cũ có chắc trỏ cùng cuốn trong view mới không?

[Mở đáp án TN64](02_DAP_AN.md#TN64) · [Về đầu phần](#tan)

<a id="TN67"></a>
### 020. TN67 — Đổi kích thước ở trang cuối: giữ bản ghi hay giữ số trang?

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Đổi kích thước ở trang cuối: giữ bản ghi hay giữ số trang?.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [HienThiPhanTrang, dòng 433](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L433).

**Câu chính:** Báo cáo 25 dòng, selected =24; terminal từ 80 × 24 đổi 120 × 32 rồi PgDn. Thầy hỏi page được tính lại từ selected hay giữ cứng, vì sao cận n−1 phải áp dù số dòng mỗi trang đổi. Nếu sau đó nhúng bộ lọc còn 3 dòng, cơ chế resize hiện tại có tự đủ không?

**Câu phụ 1:** Nếu nhúng bộ lọc trả 0 bản ghi thì dùng n-1 có cần xử lý miền rỗng riêng không?

[Mở đáp án TN67](02_DAP_AN.md#TN67) · [Về đầu phần](#tan)

<a id="TN73"></a>
### 021. TN73 — Xác nhận NAP bị hủy: đường dẫn mới có được giữ làm đích lưu?

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Xác nhận NAP bị hủy: đường dẫn mới có được giữ làm đích lưu?.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [DocFile, dòng 336](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L336); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [LuuFile, dòng 341](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L341).

**Câu chính:** RAM có thay đổi chưa lưu, path=A. So hai nhánh độc lập: chọn B nhưng nhập nap khác từ khóa rồi F5; hoặc xác nhận đúng NAP và nạp B hợp lệ. RAM, file A và đích lưu sau đó là gì? Vì sao gán path=next ngay khi chọn file có thể ghi đè nhầm B khi hủy; nạp thành công có tự lưu A trước không?

**Câu phụ 1:** Trong phiên A đã có giao dịch chưa lưu, thử NAP B hỏng rồi F5: F5 phải ghi dữ liệu nào vào đâu, và cần quan sát gì để tránh kết luận sai từ thông báo?

[Mở đáp án TN73](02_DAP_AN.md#TN73) · [Về đầu phần](#tan)

<a id="TN75"></a>
### 022. TN75 — Gõ sai đường dẫn lúc mở ứng dụng và lúc NAP khác nhau

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Gõ sai đường dẫn lúc mở ứng dụng và lúc NAP khác nhau.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [DocFile, dòng 336](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L336).

**Câu chính:** Thủ thư gõ thiếu một ký tự trong --data và thấy thư viện rỗng; ở phiên đang chạy lại NAP đường dẫn không có thì nhận lỗi. Thầy hỏi vì sao hai đường không cùng tạo phiên rỗng, file cũ có biến mất không và cần thông tin nào để chẩn đoán 'mất dữ liệu' trước khi lưu? So thêm đường dẫn --data đã tồn tại nhưng file bị cắt giữa lịch sử: có được vào menu với thư viện rỗng rồi cho lưu đè không?

**Câu phụ 1:** Nếu file cũ vẫn ở đường đúng nhưng chạy từ cwd khác, có nên tạo lại dữ liệu để sửa không?

[Mở đáp án TN75](02_DAP_AN.md#TN75) · [Về đầu phần](#tan)

<a id="TN79"></a>
### 023. TN79 — Cùng exe, mỗi thành viên thấy một thư viện khác

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Cùng exe, mỗi thành viên thấy một thư viện khác.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [LuuNoiBo, dòng 278](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L278); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [DocDoiSoWindows, dòng 139](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L139).

**Câu chính:** A chạy exe từ thư mục gốc, B chạy từ build, cả hai không truyền --data. Thầy yêu cầu tìm vì sao một người thấy rỗng mà không kết luận file đã hỏng. Hãy giải thích đường dẫn tương đối được giải theo ngữ cảnh nào; đề xuất launcher /hiển thị đường dẫn tuyệt đối và cách bàn giao để tránh hai bộ dữ liệu tách biệt. Thành viên C truyền --data Dữ liệu/Thư viện.txt mà không đặt đường dẫn trong dấu nháy: vì sao đọc argv UTF-16 đúng vẫn chưa giải quyết được lỗi này?

**Câu phụ 1:** Đưa exe sang thư mục khác nhưng giữ cwd cũ có tự đổi đích tương đối không?

[Mở đáp án TN79](02_DAP_AN.md#TN79) · [Về đầu phần](#tan)

<a id="TN84"></a>
### 024. TN84 — Ghi log console làm đổi đường UI nhưng không được đổi nghiệp vụ

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Ghi log console làm đổi đường UI nhưng không được đổi nghiệp vụ.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [NhapBieuMau, dòng 380](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L380).

**Câu chính:** Chạy exe đúng trên Windows nhưng redirect stdout vào file log, form phím biến thành menu dòng. Thầy chỉ điều kiện GetConsoleMode trên hai handle chuẩn và hỏi CLI test đang kiểm đường nào, các validator nào vẫn dùng chung; nếu đặt hạn mức 3 cuốn chỉ trong form, thử nghiệm nào sẽ lộ lỗ hổng?

**Câu phụ 1:** CLI đủ test mượn có thay kiểm điều hướng TUI gọi đúng hàm không?

[Mở đáp án TN84](02_DAP_AN.md#TN84) · [Về đầu phần](#tan)

<a id="TN88"></a>
### 025. TN88 — Parse sai nhưng thao tác nhầm độc giả của lần trước

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Parse sai nhưng thao tác nhầm độc giả của lần trước.

**Chỉ vào code:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [DocSoNguyen, dòng 61](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L61); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [ManHinhDocGia, dòng 133](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L133); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [XoaDocGia, dòng 80](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L80).

**Câu chính:** Form giữ ma=12 từ lần tra trước; lần mới gõ abc, DocSoNguyen trả false. Một refactor vẫn gọi XoaDocGia (ma). Thầy hỏi có thể xóa nhầm người 12 khi nào và vì sao API xóa không biết người dùng vừa nhập sai? So việc reset ma=0 với thật sự chặn hành động bằng kết quả parse.

**Câu phụ 1:** Nếu mã 12 có lịch sử nên xóa bị chặn thì lỗi caller parse sai đã hết nguy hiểm chưa?

[Mở đáp án TN88](02_DAP_AN.md#TN88) · [Về đầu phần](#tan)

<a id="TN202"></a>
### 026. TN202 — Mảng đã tăng nhưng bị mất một người

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** b — Hoán vị khi sắp.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InDocGiaTheoTenHo, dòng 114](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L114).

**Câu chính:** View ban đầu trỏ các mã 10,20,30 có tên C,B,A, cùng họ. Bản sửa heap cho ra 30,20,20, tương ứng A,B,B: thứ tự đã tăng nhưng thiếu người 10. Vì sao test chỉ kiểm thứ tự không đủ? Nêu kết quả đúng và hậu điều kiện phát hiện cả mất người lẫn in trùng.

**Câu phụ 1:** Chỉ so số phần tử và tổng mã có đủ thay bảng tần suất không? Cho đầu vào 10,20,30 và đầu ra 10,10,40.

[Mở đáp án TN202](02_DAP_AN.md#TN202) · [Về đầu phần](#tan)

<a id="TN203"></a>
### 027. TN203 — Vì sao dựng heap từ nửa sau trở về đầu

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** b — Dựng heap.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InDocGiaTheoTenHo, dòng 114](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L114).

**Câu chính:** Có bảy con trỏ độc giả. Đọc vòng dựng heap và chỉ thứ tự các root được vun. So với chèn từng người vào heap mới: vì sao hai cách đều có thể đúng nhưng cận dựng heap khác nhau?

**Câu phụ 1:** Nếu vun root 0 trước rồi không quay lại sau khi vun con thì bảo đảm nào mất?

[Mở đáp án TN203](02_DAP_AN.md#TN203) · [Về đầu phần](#tan)

<a id="TN204"></a>
### 028. TN204 — Duyệt Morris có thật sự là báo cáo chỉ đọc

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** b — So phương án duyệt.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [LayDanhSachDocGia, dòng 13](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L13); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InDocGiaTheoMa, dòng 106](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L106).

**Câu chính:** Thầy đề nghị bỏ stack bằng Morris inorder: tạm nối phải của tiền nhiệm về tổ tiên. Nếu đang in thì stream ném lỗi trước khi gỡ các nối tạm, chuyện gì xảy ra khi người dùng tìm/xóa hoặc hủy cây?

**Câu phụ 1:** Đánh dấu hàm const có tự ngăn nối qua con trỏ thành viên không?

[Mở đáp án TN204](02_DAP_AN.md#TN204) · [Về đầu phần](#tan)

<a id="TN205"></a>
### 029. TN205 — Bảng mã giảm dần không cần sắp lại

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** b — Thứ tự duyệt.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [LayDanhSachDocGia, dòng 13](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L13); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InDocGiaTheoMa, dòng 106](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L106).

**Câu chính:** Yêu cầu mới: xem mã giảm dần, vẫn giữ BST theo mã tăng ở trái→gốc→phải. Với gốc 20, trái 10 có phải 15, phải 30, hãy so duyệt phải–gốc–trái với tạo view tăng rồi đảo, và với heap sort theo mã.

**Câu phụ 1:** Nếu chỉ cần 5 mã lớn nhất thì cách nào cho dừng sớm có căn cứ?

[Mở đáp án TN205](02_DAP_AN.md#TN205) · [Về đầu phần](#tan)

<a id="TN206"></a>
### 030. TN206 — Lọc một khoảng mã có cần xem cả cây

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** b — Cắt nhánh.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [TimDocGia, dòng 3](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L3), [TimDocGia, dòng 8](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L8); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [LayDanhSachDocGia, dòng 13](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L13).

**Câu chính:** Bảng mới chỉ lấy mã trong[35,65], tăng theo mã. Cây gốc 50, trái 30 có phải 40, phải 70 có trái 60. Nhánh nào có thể bỏ chắc chắn? So với lọc toàn view rồi in.

**Câu phụ 1:** Đổi khoảng[35,65] thành[40,40] rồi gặp đúng node 40: có cần tiếp tục vào cả hai cây con không, và nếu L>U cần hợp đồng gì?

[Mở đáp án TN206](02_DAP_AN.md#TN206) · [Về đầu phần](#tan)

<a id="TN207"></a>
### 031. TN207 — Nhảy tới người thứ k không phải tìm mã k

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** b — Thứ hạng.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [TimDocGia, dòng 3](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L3), [TimDocGia, dòng 8](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L8); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [LayDanhSachDocGia, dòng 13](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L13); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [NutDocGia, dòng 287](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L287).

**Câu chính:** Mã hiện có 10,30,100. UI mới muốn đến người thứ 2 trong thứ tự mã. Một người gọi TimDocGia(root,2). Hãy nêu kết quả đúng và hai hướng hỗ trợ truy vấn thứ hạng, kể cả chi phí duy trì.

**Câu phụ 1:** Giả định có size cây con: xóa 40 có hai con bằng chuyển nguyên successor 50 từ sâu lên. Chỉ giảm size ở node 40 có đủ không?

[Mở đáp án TN207](02_DAP_AN.md#TN207) · [Về đầu phần](#tan)

<a id="TN208"></a>
### 032. TN208 — Chọn mười tên đầu khi R lớn

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** b — Chọn tập nhỏ.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InDocGiaTheoTenHo, dòng 114](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L114); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [TenHoTruoc, dòng 39](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L39).

**Câu chính:** Yêu cầu mới chỉ xuất 10 người nhỏ nhất theo tên–họ–mã trong R=100000, đọc nhiều và không lưu cache. So heap sort toàn view với heap tạm tối đa 10 phần tử trong lúc inorder; điều kiện thay root là gì?

**Câu phụ 1:** Nếu mọi tên và họ giống nhau, người mã lớn vừa đến có được thay root nhỏ hơn không?

[Mở đáp án TN208](02_DAP_AN.md#TN208) · [Về đầu phần](#tan)

<a id="TN209"></a>
### 033. TN209 — Tìm tiền tố trên view tên đã sắp

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** b — Hợp đồng truy vấn.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [TenHoTruoc, dòng 39](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L39); [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [KhoaSoSanh, dòng 18](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L18); [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [ChuaChuoi, dòng 27](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L27).

**Câu chính:** View sắp tên–họ–mã, yêu cầu mới tìm tên có tiền tố ASCII "an" theo cùng KhoaSoSanh. Với tên an, an binh, lan, thanh, hãy phân biệt đoạn tiền tố liên tiếp và tìm chứa; một lower_bound có đủ trả mọi người không?

**Câu phụ 1:** Nếu người dùng chỉ nhập khoảng trắng thì query có còn hợp đồng rõ không?

[Mở đáp án TN209](02_DAP_AN.md#TN209) · [Về đầu phần](#tan)

<a id="TN210"></a>
### 034. TN210 — Độ sâu duyệt cây và độ sâu sort không cùng cận

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** b — So lời gọi đệ quy.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InDocGiaTheoTenHo, dòng 114](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L114); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [LayDanhSachDocGia, dòng 13](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L13); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [DungBST, dòng 85](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L85).

**Câu chính:** Thầy muốn thay heap sort view tên bằng merge sort tự cài và sợ nó tràn stack như DFS đệ quy trên BST100000 node lệch. Hai độ sâu có cùng phụ thuộc h không? So bộ nhớ phụ và điểm cấp phát của hai cách sort.

**Câu phụ 1:** Nếu chia merge ở vị trí cố định 1 vàR−1 thay vì giữa thì độ sâu còn log không?

[Mở đáp án TN210](02_DAP_AN.md#TN210) · [Về đầu phần](#tan)

<a id="TN211"></a>
### 035. TN211 — Sao chép dữ liệu để sắp thay vì sao chép con trỏ

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** b — Chi phí view.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InDocGiaTheoTenHo, dòng 114](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L114); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [DocGia, dòng 283](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L283).

**Câu chính:** Bản sửa tạo mảng DocGia bằng copy mỗi thongTin để sort, thay view const NutDocGia*. Mỗi người có lịch sử dài. Hãy phân biệt chi phí chuỗi, con trỏ lịch sử được copy và rủi ro nếu thêm bước dọn lịch sử cho từng phần tử tạm.

**Câu phụ 1:** Nếu chỉ cần mã, họ, tên độc lập với nguồn thì có phương án giữa hai cách không?

[Mở đáp án TN211](02_DAP_AN.md#TN211) · [Về đầu phần](#tan)

<a id="TN212"></a>
### 036. TN212 — Sắp tên bằng so bản ghi đã định dạng

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** b — Khóa và trình bày.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [TenHoTruoc, dòng 39](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L39); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InMotDocGia, dòng 36](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L36).

**Câu chính:** Một refactor tạo chuỗi "ma | ho | ten | phai | the" rồi dùng so chuỗi đó để sort báo cáo b theo tên. Với mã 2 tênZ và mã 10 tênA, thêm zero padding có cứu hợp đồng không?

**Câu phụ 1:** Thêm cột trạng thái ở đầu chuỗi có thể âm thầm thay ý nghĩa báo cáo thế nào?

[Mở đáp án TN212](02_DAP_AN.md#TN212) · [Về đầu phần](#tan)

<a id="TN213"></a>
### 037. TN213 — Bỏ điều kiện count vì tin caller luôn đúng

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** b — Tiền điều kiện API.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [LayDanhSachDocGia, dòng 13](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L13); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [DemDocGia, dòng 28](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L28).

**Câu chính:** Một test harness nối nhầm một node trái trở về tổ tiên, sau đó gọi b. Hàm LayDanhSachDocGia có xác minh cấu trúc cây trước khi duyệt không? Các cận MAX_DOC_GIA giúp gì và không chứng minh được gì?

**Câu phụ 1:** Đếm số mã khác nhau sau khi lỗi có đủ để sửa tự động liên kết không?

[Mở đáp án TN213](02_DAP_AN.md#TN213) · [Về đầu phần](#tan)

<a id="TN214"></a>
### 038. TN214 — Chèn đầu sách đã tăng có làm view thể loại luôn rẻ

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** d — Phân bố dữ liệu.

**Chỉ vào code:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [InDauSachTheoTheLoai, dòng 94](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L94).

**Câu chính:** Hai kho có cùng D và tên tăng. Kho A các thể loại cũng tăng theo thứ tự tên; kho B thể loại giảm. Vì sao insertion sort của d có số dịch rất khác dù cả hai mảng gốc đều hợp lệ? Nêu tập dữ liệu đo phân biệt.

**Câu phụ 1:** Nếu tất cả đầu thuộc một thể loại thì dữ liệu gốc theo tên có lợi thế gì?

[Mở đáp án TN214](02_DAP_AN.md#TN214) · [Về đầu phần](#tan)

<a id="TN215"></a>
### 039. TN215 — Bảo toàn thứ tự đầu vào khi bỏ khóa mã khỏi yêu cầu

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** b — Tính ổn định theo đặc tả.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InDocGiaTheoTenHo, dòng 114](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L114); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [TenHoTruoc, dòng 39](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L39).

**Câu chính:** Yêu cầu mới: tên–họ tăng, khi hòa giữ thứ tự người dùng đánh dấu trong danh sách chọn 20 mã, không phải mã tăng. Nếu giữ comparator tên–họ–mã hiện tại rồi dùng stable merge sort, kết quả có đạt không?

**Câu phụ 1:** Nếu một mã được chọn hai lần thì thứ tự ổn định có tự loại trùng không?

[Mở đáp án TN215](02_DAP_AN.md#TN215) · [Về đầu phần](#tan)

<a id="TN216"></a>
### 040. TN216 — Chỉ xem một thể loại mà vẫn sắp toàn kho

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** d — Lọc theo khóa đầu.

**Chỉ vào code:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [InDauSachTheoTheLoai, dòng 94](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L94); [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [SoSanhChuoi, dòng 23](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L23).

**Câu chính:** Yêu cầu mới chỉ xem thể loại Toan; kho gốc vẫn tăng tên–ISBN. Có cần tạo và sắp toàn view d rồi lấy nhóm Toan không? Hãy tận dụng thứ tự gốc và định nghĩa tương đương thể loại hiện có.

**Câu phụ 1:** Nếu chọn hai thể loại và muốn từng nhóm liền nhau thì một lần lọc như trên còn đủ không?

[Mở đáp án TN216](02_DAP_AN.md#TN216) · [Về đầu phần](#tan)

<a id="TN217"></a>
### 041. TN217 — Gộp hai danh sách thể loại đã sắp

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** d — Hợp nhất view.

**Chỉ vào code:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [InDauSachTheoTheLoai, dòng 94](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L94); [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [TimDauSachTheoISBN, dòng 50](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L50).

**Câu chính:** Một thiết kế tách kho hiện tại thành hai phần không giao nhau theo ISBN, mỗi phần đã sắp thể loại–tên–ISBN. Muốn dựng d toàn kho, so trộn hai dãy với nối rồi insertion sort. Có được loại một dòng khi chỉ cùng tên không?

**Câu phụ 1:** Một view sắp tên trước thể loại có dùng chung vòng merge này được không?

[Mở đáp án TN217](02_DAP_AN.md#TN217) · [Về đầu phần](#tan)

<a id="TN218"></a>
### 042. TN218 — Tên nhóm đầu trang không phải nhóm mới

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** d — Ngữ cảnh phân trang.

**Chỉ vào code:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [InDauSachTheoTheLoai, dòng 94](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L94); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [HienThiPhanTrang, dòng 433](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L433).

**Câu chính:** Muốn bản in nhiều trang lặp tên thể loại ở đầu trang khi một nhóm dài sang trang kế. Nếu đưa dòng lặp đó trở lại thuật toán tính tổng nhóm, số nhóm và tổng đầu có thể sai ra sao? Đặt trách nhiệm dữ liệu và trang ở đâu?

**Câu phụ 1:** Nếu trang bắt đầu đúng ở thể loại mới thì có cần hai tiêu đề giống nhau không?

[Mở đáp án TN218](02_DAP_AN.md#TN218) · [Về đầu phần](#tan)

<a id="TN219"></a>
### 043. TN219 — Liệt kê h khi độc giả còn nhưng không giữ sách

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** h — Hợp đồng kết quả.

**Chỉ vào code:** [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [LietKeSachDangMuon, dòng 20](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L20); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [TimDocGia, dòng 3](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L3), [TimDocGia, dòng 8](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L8).

**Câu chính:** Hai thao tác: tra mã 999 không tồn tại; tra mã 10 tồn tại với toàn lịch sử đã trả. Hệ thống giám sát chỉ tìm chuỗi "khong co sach dang muon" để quyết định mã hợp lệ. Vì sao hợp đồng text dễ dùng sai, và caller mới nên phân biệt những trạng thái nào?

**Câu phụ 1:** Nếu đổi ngôn ngữ thông báo mà giám sát hỏng thì lỗi nằm ở dữ liệu hay tích hợp?

[Mở đáp án TN219](02_DAP_AN.md#TN219) · [Về đầu phần](#tan)

<a id="TN220"></a>
### 044. TN220 — Có đủ ba mã nhưng chọn đúng lượt bằng cặp nào

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** h — Khóa của dòng lịch sử.

**Chỉ vào code:** [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [MuonTra, dòng 279](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L279); [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [LietKeSachDangMuon, dòng 20](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L20); [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [TimMuonDangMuonTheoMa, dòng 13](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L13).

**Câu chính:** Màn hình mới xem cả lịch sử và cho mở chi tiết một lượt. Cùng người 10 có hai lượt X#1 đã trả cùng ngày và một lượt X#1 mở. Cặp(maThe,maSach) có đủ chỉ đúng lượt đã chọn không? Vì sao API trả hiện tại vẫn dùng được cặp đó cho lượt mở hợp lệ?

**Câu phụ 1:** Dùng(ngày mượn,ngày trả,trạng thái) bổ sung có bảo đảm duy nhất với hai lần mượn–trả cùng ngày không?

[Mở đáp án TN220](02_DAP_AN.md#TN220) · [Về đầu phần](#tan)

<a id="TN221"></a>
### 045. TN221 — Khi h gặp lỗi ở lượt mở thứ hai

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** h — Xuất từng phần.

**Chỉ vào code:** [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [LietKeSachDangMuon, dòng 20](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L20); [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [ChuoiNgay, dòng 102](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L102); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [LuongChuoi, dòng 70](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L70).

**Câu chính:** Trong fixture RAM hỏng, lượt mở đầu có ngày hợp lệ, lượt thứ hai có ngày 32/01. Gọi h vào LuongChuoi rồi mới hiển thị như menu. Dự đoán có ngoại lệ từ ChuoiNgay không và vì sao in được ngày không chứng minh ngày hợp lệ?

**Câu phụ 1:** Nếu thay ChuoiNgay bằng phép tính số ngày để thêm cột mới thì đường lỗi có thể đổi thế nào?

[Mở đáp án TN221](02_DAP_AN.md#TN221) · [Về đầu phần](#tan)

<a id="TN222"></a>
### 046. TN222 — Một người có ba cuốn mới nhưng danh mục rất lớn

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** h — Chi phí phép nối.

**Chỉ vào code:** [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [LietKeSachDangMuon, dòng 20](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L20); [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [TimCuonSachToanCuc, dòng 27](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L27), [TimCuonSachToanCuc, dòng 48](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L48).

**Câu chính:** A có H_A=50000 lượt, chỉ 3 lượt cuối đang mở, cả 3 dùng mã mới ISBN#n; D=10000 và mỗi đầu liên quan có C_i cuốn. Phân rã chi phí h, tránh nói "chỉ 3 lượt nên O(1)" hoặc "mỗi lượt đều tìm toàn kho".

**Câu phụ 1:** Nếu chuyển ba lượt mở lên đầu lịch sử thì cận duyệt hiện tại có tự giảm không?

[Mở đáp án TN222](02_DAP_AN.md#TN222) · [Về đầu phần](#tan)

<a id="TN223"></a>
### 047. TN223 — Duyệt theo tầng có bảo đảm mã tăng không

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** b — So thứ tự duyệt.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [LayDanhSachDocGia, dòng 13](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L13); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InDocGiaTheoMa, dòng 106](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L106).

**Câu chính:** Cây gốc 40, trái 20 có 10/30, phải 60 có 50/70. Một refactor dùng hàng đợi duyệt tầng vì dễ làm phân trang. Nêu dãy nhận được, vì sao không đạt b theo mã và các khoản bộ nhớ khác stack inorder.

**Câu phụ 1:** Cây chỉ có nhánh phải có làm BFS tình cờ tăng mã không?

[Mở đáp án TN223](02_DAP_AN.md#TN223) · [Về đầu phần](#tan)

<a id="TN224"></a>
### 048. TN224 — Màn hình báo cáo dùng tổng giữ sách để chia nhóm độc giả

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** h — Tần suất nhỏ.

**Chỉ vào code:** [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [DemSoSachDangMuon, dòng 4](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L4); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [LayDanhSachDocGia, dòng 13](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L13).

**Câu chính:** Yêu cầu mới chia người thành 0/1/2/3 cuốn đang giữ, trong mỗi nhóm mã tăng. Có thể tránh sort toàn R bằng bốn bucket tạm không? Cách duyệt và ghép nào giữ thứ tự trong nhóm; H ảnh hưởng ở đâu?

**Câu phụ 1:** Nếu dựng bucket từ preorder thì trong nhóm có chắc mã tăng không?

[Mở đáp án TN224](02_DAP_AN.md#TN224) · [Về đầu phần](#tan)

<a id="TN225"></a>
### 049. TN225 — Bản ghi đã trả không được tái xuất chỉ vì tên khớp

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** h — Kết hợp bộ lọc.

**Chỉ vào code:** [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [LietKeSachDangMuon, dòng 20](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L20); [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [ChuaChuoi, dòng 27](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L27).

**Câu chính:** Thêm ô tìm tên trong h. A có lượt X đã trả và Y đang mở, cả hai cùng tên khớp. Bản sửa dùng điều kiện "đang mượn OR tên khớp". Nêu tập kết quả đúng, phản ví dụ cho OR và vị trí tiết kiệm tra tên.

**Câu phụ 1:** Nếu yêu cầu đổi thành tìm trong toàn lịch sử thì có thể chỉ đổi AND thành OR không?

[Mở đáp án TN225](02_DAP_AN.md#TN225) · [Về đầu phần](#tan)

<a id="TN226"></a>
### 050. TN226 — Báo cáo quá hạn và h cùng phiên nhưng ngày khác

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** h/i — Hợp đồng ngày báo cáo.

**Chỉ vào code:** [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [LietKeSachDangMuon, dòng 20](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L20); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [InDocGiaQuaHan, dòng 144](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L144); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490).

**Câu chính:** Khởi động --date 10/09 với dữ liệu hợp lệ có A đang giữ cuốn mượn 01/09; hôm máy 15/09. h và i có thể hiện các con số nào, và h có đang tự quyết định theo ngày máy rằng A quá hạn không?

**Câu phụ 1:** Nếu bổ sung cột quá hạn cho h thì ngày đó nên lấy từ đâu để nhất quán phiên?

[Mở đáp án TN226](02_DAP_AN.md#TN226) · [Về đầu phần](#tan)

<a id="TN227"></a>
### 051. TN227 — Nhập dữ liệu batch qua stdin có transaction toàn file không

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Menu — Hợp đồng batch.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [NhapSo, dòng 395](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L395); [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [ManHinhNhapDauSach, dòng 124](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L124).

**Câu chính:** Script --plain thêm đầu A hợp lệ, tiếp theo gửi mục menu abc rồi dòng 12 rồi 13 rồiTHOAT. Có thể coi lỗi abc khiến tất cả lệnh trước rollback không? Dòng 12 được hiểu theo lần đọc nào và cần kiểm gì để script không báo thành công giả?

**Câu phụ 1:** Nếu muốn dừng batch ngay lỗi đầu thì có nên sửa validator thành chấp nhận abc như 0 không?

[Mở đáp án TN227](02_DAP_AN.md#TN227) · [Về đầu phần](#tan)

<a id="TN228"></a>
### 052. TN228 — Thông báo thất bại nhưng stream không ném

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Menu — Trạng thái đầu ra.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ThongBao, dòng 427](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L427); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [LuongChuoi, dòng 70](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L70).

**Câu chính:** Chạy --plain, một phép ghi cout thất bại và chỉ đặt failbit vì không bật exceptions. ThongBao có tự phát hiện để hoàn tác nghiệp vụ vừa thành công không? Phân biệt nhánh failbit và ngoại lệ khi đánh giá catch.

**Câu phụ 1:** Bật exceptions cho cout có tự biến việc mượn thành nguyên tử với màn hình không?

[Mở đáp án TN228](02_DAP_AN.md#TN228) · [Về đầu phần](#tan)

<a id="TN229"></a>
### 053. TN229 — Một báo cáo lỗi không được nối vào báo cáo lần trước

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Menu — Vòng đời bộ đệm.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490); [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [LietKeSachDangMuon, dòng 20](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L20); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [LuongChuoi, dòng 70](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L70); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [BoDemChuoi, dòng 56](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L56).

**Câu chính:** Người dùng xem b rồi h rồi i. Vì sao ChayUngDung tạo LuongChuoi mới cho mỗi vòng thao tác? Nếu tái sử dụng một stream và chỉ gọi clear(), nội dung cũ có biến mất không?

**Câu phụ 1:** Một bạn chép cách reset bằng out.str("") vào LuongChuoi rồi gọi clear(). Code có biên dịch không; vì sao clear() riêng vẫn chưa đủ?

[Mở đáp án TN229](02_DAP_AN.md#TN229) · [Về đầu phần](#tan)

<a id="TN230"></a>
### 054. TN230 — Báo cáo đang xem có cho phép sửa nguồn đồng thời không

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Menu — Mô hình thực thi.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [HienThiPhanTrang, dòng 433](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L433); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490).

**Câu chính:** Trong TUI hiện tại, người dùng đang ở trang 2 của b rồi muốn bấm lệnh mượn ở menu chính. Có hai luồng UI cùng chạy không? Nếu giả định báo cáo cũ tự thay đổi khi mượn trong nền, đã thêm điều gì ngoài code?

**Câu phụ 1:** Hai exe riêng có làm text của exe A tự cập nhật khi B lưu file không?

[Mở đáp án TN230](02_DAP_AN.md#TN230) · [Về đầu phần](#tan)

<a id="TN231"></a>
### 055. TN231 — Một báo cáo chạy nền trả kết quả sau khi đã NAP

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** Menu — Kết quả bất đồng bộ.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [HienThiPhanTrang, dòng 433](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L433); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [HoanDoiThuVien, dòng 324](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L324).

**Câu chính:** Giả sử thêm worker tạo báo cáo b từ bản sao phiênA. Trong lúc đó UI nạp phiênB; workerA xong sau. Không còn con trỏ treo vì worker giữ bản sao sâu, nhưng đưa kết quả lên màn hình B vẫn sai ở đâu?

**Câu phụ 1:** Worker cũ hoàn thành sau worker mới của cùng phiên thì chỉ kiểm tên file có đủ không?

[Mở đáp án TN231](02_DAP_AN.md#TN231) · [Về đầu phần](#tan)

<a id="TN232"></a>
### 056. TN232 — Trang theo offset khi có người chen vào trước

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** b — Phân trang dữ liệu.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InDocGiaTheoTenHo, dòng 114](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L114); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [HienThiPhanTrang, dòng 433](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L433).

**Câu chính:** Thiết kế dịch vụ giả định đọc theo trang 10 người sắp tên–họ–mã, không còn snapshot text cố định. Sau trang 1, một người mới được thêm vào đầu thứ tự. Trang 2 lấy offset 10 có thể lặp/bỏ ai? So snapshot với cursor theo khóa cuối.

**Câu phụ 1:** Chỉ dùng tên làm cursor có đủ với hai người trùng tên không?

[Mở đáp án TN232](02_DAP_AN.md#TN232) · [Về đầu phần](#tan)

<a id="TN233"></a>
### 057. TN233 — Bộ chỉ mục starts phải giữ dòng cuối không có newline

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Phân trang — Phân tách dòng.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [HienThiPhanTrang, dòng 433](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L433).

**Câu chính:** So ba text: "A\nB", "A\nB\n", "A\n\nB". Truy cách dựng starts và sentinel cuối. Vì sao bỏ dòng cuối khi không có LF hoặc tạo một dòng dữ liệu giả sau LF cuối đều làm kiểm kết quả sai?

**Câu phụ 1:** Text rỗng có phải làm n=0 trong code hiện tại không?

[Mở đáp án TN233](02_DAP_AN.md#TN233) · [Về đầu phần](#tan)

<a id="TN234"></a>
### 058. TN234 — Tính trang từ con trỏ dòng mà không nhân tràn

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Phân trang — Cận số học.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [HienThiPhanTrang, dòng 433](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L433).

**Câu chính:** Một refactor tính totalPages=(n+step-1)/step và next=(page+1)*step bằng int cho báo cáo sinh ngoài chương trình rất lớn. Vì sao dữ liệu thư viện hợp lệ có giới hạn không đủ bảo vệ API nhận string tùy ý? Nêu cận và phép tính cần kiểm trước.

**Câu phụ 1:** Nếu n nhỏ nhưng step=0 do công thức chiều cao mới thì vấn đề nào xuất hiện trước?

[Mở đáp án TN234](02_DAP_AN.md#TN234) · [Về đầu phần](#tan)

<a id="TN236"></a>
### 059. TN236 — Ngày phiên hợp lệ lúc mở nhưng đồng hồ đổi trước giao dịch

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Menu — Thời điểm kiểm.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KiemTraNgayGiaoDich, dòng 13](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L13).

**Câu chính:** Mở phiên ngày 10/09 khi ngày máy 10/09; trước khi bấm mượn, môi trường thử đổi ngày máy thành 09/09. Màn hình vẫn ghi 10/09. Lời gọi mượn có còn được chấp nhận chỉ vì đối số --date đã qua kiểm lúc khởi động?

**Câu phụ 1:** Nếu chỉ mở báo cáo i với ngày 10/09 sau khi đồng hồ đổi thì API i có cùng chặn tương lai không?

[Mở đáp án TN236](02_DAP_AN.md#TN236) · [Về đầu phần](#tan)

<a id="TN237"></a>
### 060. TN237 — Mẫu form tối đa 12 trường nhưng caller muốn 13

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Menu — Hợp đồng kích thước.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [BieuMau, dòng 317](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L317); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [NhapBieuMau, dòng 380](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L380); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [LoiThuVien, dòng 20](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L20).

**Câu chính:** Một màn hình mới ghép nhiều bước thành 13 trường rồi gọi NhapBieuMau. BieuMau TUI có giới hạn count, trong khi fallback plain lặp theo count. Nếu chỉ thử plain rồi công bố dùng được cho cả hai, thiếu chứng cứ và nguy cơ gì?

**Câu phụ 1:** Chia 13 trường thành hai form mà form 1 đã commit thì hủy form 2 có còn all-or-nothing không?

[Mở đáp án TN237](02_DAP_AN.md#TN237) · [Về đầu phần](#tan)

<a id="TN238"></a>
### 061. TN238 — Hai đích --data và --check trong cùng lệnh

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Menu — Hợp đồng đối số.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490).

**Câu chính:** Lệnh có --data A --check B --plain, A chứa dữ liệu đang dùng còn B là file thử hỏng. Chương trình có nạp A trước để phục hồi khi B lỗi không, có tạo thư mục cha của A không? Vì sao tester phải ghi chính xác argv? Thử thêm --check "" hoặc --data "": chương trình có được mở menu hoặc tạo thư mục không?

**Câu phụ 1:** Đặt --date sai trước --check B thì có chắc B được kiểm không?

[Mở đáp án TN238](02_DAP_AN.md#TN238) · [Về đầu phần](#tan)

<a id="TN239"></a>
### 062. TN239 — --check xanh nhưng người đọc vẫn không được mượn

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Menu — Ý nghĩa thành công.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110).

**Câu chính:** File có A bị khóa thủ công, không giữ sách; --check báo hợp lệ. Người dùng cho rằng lỗi phần f vì A không mượn được X rảnh. Giải thích hai loại điều kiện và test nào phân biệt file hợp lệ với giao dịch được phép.

**Câu phụ 1:** Tự mở mọi thẻ khi --check thành công có bảo toàn ý nghĩa dữ liệu không?

[Mở đáp án TN239](02_DAP_AN.md#TN239) · [Về đầu phần](#tan)

<a id="TN240"></a>
### 063. TN240 — Thư mục mới có nhưng file chưa có sau hủy phiên

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Menu — Tác dụng phụ khởi động.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [LuuFile, dòng 341](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L341); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [TaoThuMuc, dòng 119](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L119).

**Câu chính:** --data trỏ thư mục cha chưa tồn tại; khởi động vào kho rỗng rồi chọn 13 xác nhận THOAT. Kiểm đĩa thấy thư mục cha đã tạo nhưng không có file. Có phải lưu đã chạy nửa chừng không và test chỉ đếm thư mục sai ở đâu?

**Câu phụ 1:** Nếu TaoThuMuc gặp lỗi khi gọi CreateDirectoryW và ném LoiThuVien thì đã có thư viện mới lưu được hay chưa?

[Mở đáp án TN240](02_DAP_AN.md#TN240) · [Về đầu phần](#tan)

<a id="TN241"></a>
### 064. TN241 — Con trỏ ngữ cảnh UI được gán cho một phiên cục bộ

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Menu — Vòng đời ngữ cảnh.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [TongQuan, dòng 246](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L246).

**Câu chính:** Bản test gọi ChayUngDung hai lần trong cùng tiến trình, rồi gọi TrangChinh sau khi lần hai đã trả. duLieuUI và duongDanUI trỏ tới đâu? Vì sao gọi được main một lần không chứng minh kiểu tái sử dụng này an toàn?

**Câu phụ 1:** Gọi ChayUngDung lần mới có tự làm địa chỉ cũ hợp lệ trở lại cho callback còn treo không?

[Mở đáp án TN241](02_DAP_AN.md#TN241) · [Về đầu phần](#tan)

<a id="TN242"></a>
### 065. TN242 — Báo lỗi lại cần cấp phát và ghi màn hình

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Menu — Lỗi trong xử lý lỗi.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ThongBao, dòng 427](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L427); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [main, dòng 573](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L573).

**Câu chính:** Một thao tác ném bad_alloc; catch trong vòng menu nối chuỗi thông báo rồi gọi ThongBao. Nếu việc tạo chuỗi hoặc màn hình lỗi tiếp, có bắt lại bằng chính catch đó để tiếp tục vòng lặp không?

**Câu phụ 1:** Nếu lỗi ban đầu xảy ra trước commit thì việc kết thúc tiến trình có tự lưu các giao dịch cũ chưa lưu không?

[Mở đáp án TN242](02_DAP_AN.md#TN242) · [Về đầu phần](#tan)

<a id="TN243"></a>
### 066. TN243 — Mượn bị từ chối nhưng tiến trình vẫn trả 0

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Menu — Oracle kiểm thử.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [ManHinhMuonTra, dòng 202](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L202); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490).

**Câu chính:** Một script gửi mượn lần 4 khi người đó đã giữ 3 rồi chọn 13/THOAT. Exe trả 0. Test chỉ assert exitcode==0 sẽ bỏ sót điều gì? Thiết kế oracle cho ca từ chối có kiểm cả dữ liệu trước–sau.

**Câu phụ 1:** Một log có OK thêm người trước khi mượn thất bại có làm assert "OK" đáng tin không?

[Mở đáp án TN243](02_DAP_AN.md#TN243) · [Về đầu phần](#tan)

<a id="TN244"></a>
### 067. TN244 — Xuất CSV từ bảng ký tự phân cột

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** Menu — Định dạng xuất mới.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InMotDocGia, dòng 36](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L36); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [DongBang, dòng 213](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L213); [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [HopLeVanBan, dòng 38](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L38).

**Câu chính:** Muốn xuất CSV cho nhóm: tên có dấu phẩy và dấu nháy kép đều hợp lệ, còn | bị cấm. Một người thay mọi | trong chuỗi báo cáo bằng dấu phẩy. Tại sao file có thể sai cột dù đầu vào hợp lệ?

**Câu phụ 1:** Đổi sang TSV có loại mọi trách nhiệm escape không?

[Mở đáp án TN244](02_DAP_AN.md#TN244) · [Về đầu phần](#tan)

<a id="TN245"></a>
### 068. TN245 — Thêm lựa chọn menu làm lệch nghiệp vụ

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Menu — Ánh xạ hành động.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChonMenu, dòng 402](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L402); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [TrangChinh, dòng 253](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L253).

**Câu chính:** Trên bản sao, thêm "Sao lưu" vào giữa labels trước mục mượn nhưng giữ nguyên chuỗi if choice==6/7 và điềuHuong TUI. Nêu cách người dùng có thể bấm đúng chữ nhưng gọi sai chức năng; cần đối chiếu những ánh xạ nào?

**Câu phụ 1:** Test chỉ gọi trực tiếp MuonSach đúng có bắt lỗi này không?

[Mở đáp án TN245](02_DAP_AN.md#TN245) · [Về đầu phần](#tan)

<a id="TN246"></a>
### 069. TN246 — Một triệu độc giả: không thể chỉ tăng số dòng màn hình

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** b — Quy mô giả định.

**Chỉ vào code:** [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [MAX_DOC_GIA, dòng 264](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L264); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [LayDanhSachDocGia, dòng 13](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L13); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InDocGiaTheoTenHo, dòng 114](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L114); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [HienThiPhanTrang, dòng 433](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L433).

**Câu chính:** Giả định 1 triệu hồ sơ R, D=10000,C=200000,H=200000, L≤512 byte mỗi trường, một người đọc báo cáo b nhiều lần. Bản hiện dừng ở đâu? Nếu được nâng giới hạn, phân tích bộ nhớ tăng thêm cho b theo tên trước khi nói đến số người dùng đồng thời.

**Câu phụ 1:** Giảm số dòng vẽ từ 13 xuống 5 có giảm chi phí sắp R tên không?

[Mở đáp án TN246](02_DAP_AN.md#TN246) · [Về đầu phần](#tan)

<a id="TN247"></a>
### 070. TN247 — So hai bản báo cáo sau sửa code bằng tiêu chí nào

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** b/d/h — Kiểm hồi quy.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InDocGiaTheoTenHo, dòng 114](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L114); [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [InDauSachTheoTheLoai, dòng 94](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L94); [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [LietKeSachDangMuon, dòng 20](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L20).

**Câu chính:** Một refactor chỉ đổi khoảng trắng tiêu đề nhưng test snapshot toàn text đỏ. Người sửa muốn bỏ qua mọi chữ và chỉ so số dòng. Hãy thiết kế đối chiếu giữ được lỗi sai người/thứ tự/quan hệ mà không khóa cứng toàn bố cục.

**Câu phụ 1:** Nếu hai báo cáo cùng số dòng nhưng hoán đổi mã gắn với tên thì test nào bắt?

[Mở đáp án TN247](02_DAP_AN.md#TN247) · [Về đầu phần](#tan)

<a id="TN248"></a>
### 071. TN248 — Cho phép sửa tiếp sau khi lưu báo dữ liệu không toàn vẹn

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Menu — Chẩn đoán trạng thái.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [LuuFile, dòng 341](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L341); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90).

**Câu chính:** Một fixture RAM hỏng làm LuuFile báo phiếu trỏ cuốn không có; menu giữ phiên mở. Có nên hướng dẫn bấm mượn/trả ngẫu nhiên cho đến khi lưu được không? Nêu dữ liệu cần chụp để chẩn đoán và giới hạn của việc xem báo cáo.

**Câu phụ 1:** Nạp lại bản file cũ hợp lệ có đồng nghĩa đã phục hồi các giao dịch RAM chưa lưu không?

[Mở đáp án TN248](02_DAP_AN.md#TN248) · [Về đầu phần](#tan)

<a id="TN249"></a>
### 072. TN249 — Định dạng số của stream có thể làm lệch dữ liệu thử

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** b — Trạng thái stream.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InDocGiaTheoMa, dòng 106](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L106); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InMotDocGia, dòng 36](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L36); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [LuongChuoi, dòng 70](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L70).

**Câu chính:** Harness đặt out<<std::hex rồi truyền stream đó vào InDocGiaTheoMa với mã 16 và 26. Báo cáo nhận dạng có thể hiện gì? Hàm hiện có đặt lại std::dec không, và vì sao không nên parse text đó như mã thập phân chuẩn?

**Câu phụ 1:** Nếu một helper tự đặt dec rồi không phục hồi thì có thể ảnh hưởng caller nào?

[Mở đáp án TN249](02_DAP_AN.md#TN249) · [Về đầu phần](#tan)

<a id="TN250"></a>
### 073. TN250 — In theo mã rồi mới sắp view dùng chung

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** b — Tái sử dụng view trong một lệnh.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InDocGiaTheoMa, dòng 106](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L106); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InDocGiaTheoTenHo, dòng 114](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L114).

**Câu chính:** Muốn một lệnh in b theo mã và b theo tên. Có thể dựng view inorder một lần, in theo mã, sắp view theo tên rồi in tiếp không? Đổi thứ tự hai bước in hoặc giữ view để in mã lại có nguy cơ gì?

**Câu phụ 1:** Nếu chỉ dựng hai chuỗi kết quả rồi mới mở UI thì sort sau có làm chuỗi đầu đổi không?

[Mở đáp án TN250](02_DAP_AN.md#TN250) · [Về đầu phần](#tan)

<a id="TN251"></a>
### 074. TN251 — Dòng form đã trả một phần khi bước sau bị hủy

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Menu — Kết quả nhiều trường.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [NhapBieuMau, dòng 380](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L380); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [NhapDong, dòng 386](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L386).

**Câu chính:** Trong fallback plain, NhapBieuMau đọc ba trường; trường 1 đã gán, trường 2 nhận/hủy bằng /huy và hàm trảfalse. Có bảo đảm mảng values của caller hoàn toàn giữ giá trị cũ như trước lời gọi không? Vì sao caller phải chặn commit dù một số ô đã có nội dung hợp lệ?

**Câu phụ 1:** Nếu bỏ qua false và dùng các ô cũ ở phần chưa đọc thì dữ liệu nào bị trộn?

[Mở đáp án TN251](02_DAP_AN.md#TN251) · [Về đầu phần](#tan)

<a id="TN253"></a>
### 075. TN253 — Một thay đổi chỉ đọc có thể vẫn rất tốn cấp phát

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Menu — Bộ nhớ đỉnh.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InDocGiaTheoTenHo, dòng 114](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L114); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [HienThiPhanTrang, dòng 433](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L433); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [LuongChuoi, dòng 70](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L70); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [BoDemChuoi, dòng 56](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L56).

**Câu chính:** R=100000, lịch sử không đổi. Bật b theo tên lặp lại rồi đóng. Tại lúc chuyển out.str() vào HienThiPhanTrang, những bộ đệm nào có thể cùng sống? Vì sao xem bộ nhớ sau khi đóng không cho biết đỉnh lúc mở?

**Câu phụ 1:** Giữ một string report lâu dài để mở lại có nhất thiết giảm peak không?

[Mở đáp án TN253](02_DAP_AN.md#TN253) · [Về đầu phần](#tan)

<a id="TN254"></a>
### 076. TN254 — Sắp báo cáo báo lỗi thì có được hiển thị view đang dở

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** b — Exception khi so chuỗi.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InDocGiaTheoTenHo, dòng 114](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L114); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [TenHoTruoc, dòng 39](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L39); [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [SoSanhChuoi, dòng 23](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L23).

**Câu chính:** Comparator cấp phát khóa chuỗi và ném bad_alloc ở giữa heap sort tên. BST có bị đổi không, view còn là hoán vị không, và có được bắt lỗi rồi in view như "đã sắp" để người dùng tiếp tục không?

**Câu phụ 1:** Nếu lỗi trong khi ghi từng dòng sau sort thì khác điểm nào?

[Mở đáp án TN254](02_DAP_AN.md#TN254) · [Về đầu phần](#tan)

<a id="TN255"></a>
### 077. TN255 — Tối ưu so tên bằng địa chỉ string

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** b — Lỗi tối ưu comparator.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [TenHoTruoc, dòng 39](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L39); [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [SoSanhChuoi, dòng 23](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L23).

**Câu chính:** Một người thấy chuẩn hóa chuỗi nhiều lần nên sửa comparator so địa chỉ c_str() thay vì nội dung. Trên một lần chạy kết quả tình cờ giống mong đợi. Vì sao lưu–nạp hoặc đổi thứ tự cấp phát có thể lộ sai?

**Câu phụ 1:** Dùng hash tên thay địa chỉ có làm đúng thứ tự tên không?

[Mở đáp án TN255](02_DAP_AN.md#TN255) · [Về đầu phần](#tan)

<a id="TN256"></a>
### 078. TN256 — Chọn tên từ từng trang rồi ghép có thành toàn cục

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** b — Sắp cục bộ và toàn cục.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InDocGiaTheoTenHo, dòng 114](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L114); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [HienThiPhanTrang, dòng 433](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L433).

**Câu chính:** Bản tối ưu lấy inorder thành từng khối 13 người, sort tên trong mỗi khối rồi nối để xem. Khối 1 có tên Z,M, khối 2 có A,B. Vì sao mỗi trang tăng mà toàn báo cáo sai? Nếu muốn sort ngoài bộ nhớ, bước nào còn thiếu?

**Câu phụ 1:** Nếu tình cờ max khối trước≤min khối sau cho mọi cặp thì nối được không?

[Mở đáp án TN256](02_DAP_AN.md#TN256) · [Về đầu phần](#tan)

<a id="TN257"></a>
### 079. TN257 — Đổi giới hạn trang có làm kết quả lọc khác nhau

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** b/d/h — Kiểm tính độc lập.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [HienThiPhanTrang, dòng 433](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L433); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InDocGiaTheoTenHo, dòng 114](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L114); [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [LietKeSachDangMuon, dòng 20](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L20).

**Câu chính:** Sau refactor, người kiểm thấy thay chiều cao terminal làm mất một độc giả ở cuối báo cáo. Hãy nêu phép kiểm không cần biết trước mọi tên nhưng vẫn chứng minh lỗi do phân trang: so chuỗi các dòng dữ liệu đi qua mọi trang với gì?

**Câu phụ 1:** Nếu mỗi trang có dòng tiêu đề lặp, so số dòng thô có còn là oracle phù hợp không?

[Mở đáp án TN257](02_DAP_AN.md#TN257) · [Về đầu phần](#tan)

<a id="TN258"></a>
### 080. TN258 — Hiển thị trạng thái bằng điều kiện chân trị che miền sai

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** b — Miền enum.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InMotDocGia, dòng 36](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L36); [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [HopLeTrangThaiThe, dòng 125](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L125); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90).

**Câu chính:** Fixture RAM có trangThaiThe=2. InMotDocGia dùng điều kiện chân trị, còn validator chỉ nhận 0/1. Bảng có thể hiện "Hoat dong" không, và từ đó có kết luận nghiệp vụ sẽ coi thẻ hợp lệ không?

**Câu phụ 1:** Nếu sửa điều kiện mượn từ !=THE_HOAT_DONG thành !trangThaiThe để khớp nhãn, fixture trạng thái 2 sẽ đổi kết quả thế nào?

[Mở đáp án TN258](02_DAP_AN.md#TN258) · [Về đầu phần](#tan)

<a id="TN259"></a>
### 081. TN259 — Phép tìm đầu sách trong báo cáo nên mượn hay sở hữu dữ liệu

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** h — Đời sống kết quả join.

**Chỉ vào code:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [TimCuonSachToanCuc, dòng 27](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L27), [TimCuonSachToanCuc, dòng 48](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L48); [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [LietKeSachDangMuon, dòng 20](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L20).

**Câu chính:** Một helper UI mới trong C++11 trả view tự cài gồm const char* trỏ vào tên đầu sách và độ dài; caller giữ để in sau NAP. Sao chép một string tên có khác gì về đời sống và chi phí? Vì sao view chỉ đọc không tự giữ đối tượng nguồn?

**Câu phụ 1:** Nếu chỉ sửa tên trong cùng node mà không xóa node, view mượn vùng ký tự có chắc còn dùng được không?

[Mở đáp án TN259](02_DAP_AN.md#TN259) · [Về đầu phần](#tan)

<a id="TN260"></a>
### 082. TN260 — Nhập form theo mảng trường làm lệch dữ liệu có kiểu giống nhau

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Menu — Ánh xạ trường.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [NhapBieuMau, dòng 380](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L380); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [ManHinhDocGia, dòng 133](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L133); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [HieuChinhDocGia, dòng 68](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L68).

**Câu chính:** Trên bản sao, đổi vị trí nhãn Họ và Tên nhưng quên đổi values[0]/values[1] lúc gọi HieuChinhDocGia. Cả hai chuỗi đều hợp lệ. Vì sao validator không phát hiện và báo cáo tên–họ sẽ bị ảnh hưởng thế nào?

**Câu phụ 1:** Test chỉ kiểm mã thẻ/lịch sử không đổi có bắt lỗi này không?

[Mở đáp án TN260](02_DAP_AN.md#TN260) · [Về đầu phần](#tan)

<a id="TN261"></a>
### 083. TN261 — Hủy trả sách sau khi đã chọn loại báo mất

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Menu — Trạng thái điều khiển.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [ManHinhMuonTra, dòng 202](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L202); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [DanhDauMatSach, dòng 138](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L138); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [NhapBieuMau, dòng 380](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L380).

**Câu chính:** A giữ X,Y. Vào g, chọn báo mất rồi hủy ở form mã sách. Lần sau vào g chọn trả bình thường choY. Có cờ báo mất nào lưu qua hai lần để khóa nhầm A không? Truy biến chọn loại và điểm gọi API.

**Câu phụ 1:** Nếu lần đầu đã báo mấtX thành công rồi mới đóng thông báo thì lần sau trảY có mở thẻ không?

[Mở đáp án TN261](02_DAP_AN.md#TN261) · [Về đầu phần](#tan)

<a id="TN262"></a>
### 084. TN262 — Danh sách độc giả là danh sách hiện tại, không phải người từng tồn tại

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** b — Giới hạn lịch sử hồ sơ.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [XoaDocGia, dòng 80](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L80); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InDocGiaTheoMa, dòng 106](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L106); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [ThuVien, dòng 289](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L289).

**Câu chính:** Thêm A mã 10 chưa có lịch sử rồi xóa thành công; high-water mark vẫn 10. Báo cáo b và file có đủ để in lại tên A khi thầy hỏi ai từng được cấp 10 không? Phân biệt mốc mã với nhật ký cấp thẻ.

**Câu phụ 1:** Suy mã bị khuyết là người đã bị xóa có luôn đúng với dữ liệu nhập hợp lệ không?

[Mở đáp án TN262](02_DAP_AN.md#TN262) · [Về đầu phần](#tan)

<a id="TN263"></a>
### 085. TN263 — Đặt giới hạn kết quả báo cáo mà không giấu việc cắt

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** b/d — Hợp đồng kết quả giới hạn.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InDocGiaTheoTenHo, dòng 114](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L114); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [HienThiPhanTrang, dòng 433](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L433).

**Câu chính:** Muốn bảo vệ UI bằng giới hạn xuất 1000 người dù R=100000. Một người break sau 1000 và vẫn ghi "Danh sách độc giả" cùng tổng 1000. Cần trả metadata nào để người dùng không hiểu đây là toàn thư viện, và cắt trước/sau sort khác nhau thế nào?

**Câu phụ 1:** Nếu việc đếm tổng quá tốn thì có được bịa tổng bằng limit không?

[Mở đáp án TN263](02_DAP_AN.md#TN263) · [Về đầu phần](#tan)

<a id="TN264"></a>
### 086. TN264 — Khi mỗi bước đều tuyến tính nhưng lặp ở trong vòng

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** b — Đếm lặp khi dựng view.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [DemDocGia, dòng 28](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L28); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [LayDanhSachDocGia, dòng 13](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L13).

**Câu chính:** Refactor vòng in từ i<n thành i<DemDocGia(tree) để "luôn cập nhật số người". Cây không đổi, R lớn. Chi phí thay đổi thế nào kể cả cấp phát stack, và vì sao tính lại không cung cấp snapshot nhất quán nếu sau này có ghi nền?

**Câu phụ 1:** Nếu compiler không tối ưu bỏ lời gọi thì có phải compiler kém không?

[Mở đáp án TN264](02_DAP_AN.md#TN264) · [Về đầu phần](#tan)

<a id="TN265"></a>
### 087. TN265 — Một bản báo cáo thất bại có được đánh dấu đã kiểm dữ liệu

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** b/d/h — Báo cáo và toàn vẹn.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraToanVen, dòng 331](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L331); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InDocGiaTheoTenHo, dòng 114](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L114).

**Câu chính:** Thêm cờ validated=true sau khi b theo tên chạy không ném lỗi để bỏ KiemTraToanVen khi lưu. File có thể chứa lỗi ở cuốn/lịch sử mà b không đọc. Hãy dựng phản ví dụ và phân biệt kiểm đường đọc với kiểm toàn hệ thống.

**Câu phụ 1:** Sau một lần KiemTraToanVen thành công, thêm cuốn qua API thử chưa bảo vệ có làm cờ còn đáng tin không?

[Mở đáp án TN265](02_DAP_AN.md#TN265) · [Về đầu phần](#tan)

<a id="TN266"></a>
### 088. TN266 — Bằng chứng read-only bằng hash file có đủ không

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** b/d/h — Kiểm tác dụng phụ.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InDocGiaTheoTenHo, dòng 114](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L114); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [LuuFile, dòng 341](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L341); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490).

**Câu chính:** Test chụp SHA-256 file trước/sau xem b, hash không đổi nên kết luận b không sửa RAM. Bản lỗi có thể tráo hai tên trong RAM nhưng chưa lưu. Thiết kế phép kiểm nào bắt được, và vì sao lưu để lấy hash cũng cần kiểm bảo toàn serialization?

**Câu phụ 1:** Nếu hash file đổi chỉ vì serializer canonical hóa thứ tự thì có chứng minh nghiệp vụ đổi không?

[Mở đáp án TN266](02_DAP_AN.md#TN266) · [Về đầu phần](#tan)

<a id="TN267"></a>
### 089. TN267 — Mã hóa chuỗi ngày dùng để sort có làm lệch năm

**Phụ trách:** Tấn · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** h — Khóa thời gian trình bày.

**Chỉ vào code:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [ChuoiNgay, dòng 102](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L102); [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [SoThuTuNgay, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L110); [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [LietKeSachDangMuon, dòng 20](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L20).

**Câu chính:** Báo cáo lịch sử mới sort bằng chuỗi ChuoiNgay(dd/mm/yyyy) tăng. Hai lượt 01/12/2025 và 02/01/2025 bị xếp thế nào, vì sao sai lịch? Có thể dùng chuỗi ISO yyyy-mm-dd thay ordinal trong mọi trường hợp không?

**Câu phụ 1:** Chuỗi 01/01/0001 và sentinel 0/0/0 có cùng vai trò ngày nhỏ nhất được không?

[Mở đáp án TN267](02_DAP_AN.md#TN267) · [Về đầu phần](#tan)

<a id="TN24"></a>
### 090. TN24 — Vùng heap thu nhỏ khác với độ dài mảng đã cấp

**Phụ trách:** Tấn · **Ưu tiên:** P3 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Vùng heap thu nhỏ khác với độ dài mảng đã cấp.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InDocGiaTheoTenHo, dòng 114](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L114).

**Câu chính:** Mảng view 10 người đang heap sort; sau vài lần rút, size còn 6 nhưng các ô 6..9 đã chứa kết quả cuối. Thầy hỏi vì sao đọc con phải phải so với size hiện tại, không so với n=10; nếu lỡ kéo một ô đã chốt vào heap, cận bộ nhớ có thể vẫn đúng mà kết quả sai thế nào?

**Câu phụ 1:** Nút chỉ có con trái trong heap size 6 thì đọc con phải dựa n=10 có thể vẫn trong bộ nhớ không?

[Mở đáp án TN24](02_DAP_AN.md#TN24) · [Về đầu phần](#tan)

<a id="TN27"></a>
### 091. TN27 — Tìm người theo họ tên trên bảng đã sắp tên

**Phụ trách:** Tấn · **Ưu tiên:** P3 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** Tìm người theo họ tên trên bảng đã sắp tên.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [TenHoTruoc, dòng 39](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L39); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [LayDanhSachDocGia, dòng 13](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L13); [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [ChuaChuoi, dòng 27](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L27).

**Câu chính:** Bảng b sắp tên–họ–mã. Thầy muốn thêm tìm theo chuỗi họ tên đầy đủ, ví dụ 'Nguyen An', rồi gợi ý dùng nhị phân vì bảng đã sắp. Với Tran An, Nguyen Binh, Le An, tiền điều kiện nào thiếu? Thiết kế tìm chính xác và tìm chứa khác nhau mà giữ kết quả đúng người, không đổi BST.

**Câu phụ 1:** Truy vấn chứa "An" có thể dùng cùng lower_bound của nguyên họ+tên không?

[Mở đáp án TN27](02_DAP_AN.md#TN27) · [Về đầu phần](#tan)

<a id="TN28"></a>
### 092. TN28 — Danh sách thẻ khóa: lọc trước hay sắp trước?

**Phụ trách:** Tấn · **Ưu tiên:** P3 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** Danh sách thẻ khóa: lọc trước hay sắp trước?.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InDocGiaTheoTenHo, dòng 114](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L114); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [LayDanhSachDocGia, dòng 13](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L13); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [TenHoTruoc, dòng 39](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L39).

**Câu chính:** R=100.000 người, chỉ k=200 thẻ khóa, vài người khóa vẫn giữ sách. Thầy yêu cầu bảng riêng theo tên và đề nghị lọc trước khi heap sort. So thời gian/bộ nhớ với sắp toàn R rồi lọc; có được bỏ người khóa còn lịch sử để 'danh sách nhẹ' không, và tổng số kết quả phải lấy từ đâu?

**Câu phụ 1:** k=R thì lọc trước có giảm bậc sort không?

[Mở đáp án TN28](02_DAP_AN.md#TN28) · [Về đầu phần](#tan)

<a id="TN33"></a>
### 093. TN33 — Đổi thuật toán báo cáo thể loại khi gần 10.000 đầu

**Phụ trách:** Tấn · **Ưu tiên:** P3 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Đổi thuật toán báo cáo thể loại khi gần 10.000 đầu.

**Chỉ vào code:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [InDauSachTheoTheLoai, dòng 94](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L94); [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [KhoaSoSanh, dòng 18](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L18); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [SapXepHeap, dòng 84](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L84).

**Câu chính:** Kho tăng theo tên nhưng thể loại gần giảm dần nên insertion sort báo cáo chậm. Thầy cho đổi sang heap tự viết trên bản sao: chọn comparator, đối tượng được hoán đổi và chứng minh kết quả trước/sau không đổi. Nếu muốn chuẩn hóa khóa một lần để giảm cấp phát, bộ nhớ và xử lý lỗi có thay đổi không?

**Câu phụ 1:** Chỉ đo sort mà bỏ tạo khóa và dựng báo cáo có chứng minh cả màn hình nhanh hơn không?

[Mở đáp án TN33](02_DAP_AN.md#TN33) · [Về đầu phần](#tan)

<a id="TN36"></a>
### 094. TN36 — Tổng theo thể loại không được lấy từ số dòng UI

**Phụ trách:** Tấn · **Ưu tiên:** P3 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** Tổng theo thể loại không được lấy từ số dòng UI.

**Chỉ vào code:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [InDauSachTheoTheLoai, dòng 94](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L94); [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [DemCuonSach, dòng 99](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L99); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [HienThiPhanTrang, dòng 433](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L433).

**Câu chính:** Thầy muốn mỗi nhóm ghi số đầu, số bản và số bản sẵn sàng; nhóm cuối chỉ có một đầu 0 cuốn. Bảng có tiêu đề và dòng trống, phân trang cắt giữa nhóm. Thiết kế chỗ tính/chốt tổng trước khi render, cách giữ định nghĩa cùng nhóm và vì sao không cộng số dòng từng trang.

**Câu phụ 1:** Nhóm cuối có đầu không cuốn, nhóm trước có cuốn 0/1/2. Nếu chỉ chốt tổng khi gặp loại mới, phần nào mất và có thể dùng tổng toàn kho để suy lại không?

[Mở đáp án TN36](02_DAP_AN.md#TN36) · [Về đầu phần](#tan)

<a id="TN46"></a>
### 095. TN46 — Đổi tên sách có làm 'phiếu cũ' đổi chữ không?

**Phụ trách:** Tấn · **Ưu tiên:** P3 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** Đổi tên sách có làm 'phiếu cũ' đổi chữ không?.

**Chỉ vào code:** [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [MuonTra, dòng 279](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L279); [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [LietKeSachDangMuon, dòng 20](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L20); [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [TimCuonSachToanCuc, dòng 27](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L27), [TimCuonSachToanCuc, dòng 48](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L48).

**Câu chính:** Giả sử bổ sung đổi tên đầu sách đúng cách, giữ ISBN /cuốn/lịch sử. Thầy yêu cầu in lại lịch sử mượn như lúc giao sách và hỏi tại sao h hiện tên mới. Mô hình MuonTra đang lưu gì, tên được tra lúc nào; nếu phải giữ tên tại thời điểm mượn thì đó là đổi yêu cầu/dữ liệu hay chỉ đổi renderer?

**Câu phụ 1:** Sau khi giả định đổi tên đầu X từ Z thành A, số lượt không đổi; thứ hạng top có thể đổi không khi hòa lượt với đầu khác?

[Mở đáp án TN46](02_DAP_AN.md#TN46) · [Về đầu phần](#tan)

<a id="TN71"></a>
### 096. TN71 — Phân trang không phải đọc lười

**Phụ trách:** Tấn · **Ưu tiên:** P3 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** Menu · Tương tác, nhập và hiển thị.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [HienThiPhanTrang, dòng 433](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L433); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [ManHinhMuonTra, dòng 202](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L202); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [LuongChuoi, dòng 70](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L70); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [BoDemChuoi, dòng 56](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L56).

**Câu chính:** Báo cáo có hàng chục nghìn dòng nhưng terminal chỉ vẽ 13 dòng; thầy muốn giảm bộ nhớ bằng cách giữ đúng 13 dòng đầu trong HienThiPhanTrang. Hãy lần theo LuongChuoi, text, wstring all và starts: chi phí nào đã xảy ra trước lúc vẽ? Phương án đó sẽ làm PgDn/End và báo cáo đã sắp có vấn đề gì; muốn đọc từng trang phải đổi hợp đồng dữ liệu và vòng đời snapshot ra sao?

**Câu phụ 1:** Muốn End đến trang cuối mà chỉ giữ 13 dòng, có thể vừa không đọc hết vừa biết ngay nội dung cuối theo tên toàn cục không?

[Mở đáp án TN71](02_DAP_AN.md#TN71) · [Về đầu phần](#tan)

<a id="TN82"></a>
### 097. TN82 — RAM nạp xong nhưng gán path ném ngoại lệ

**Phụ trách:** Tấn · **Ưu tiên:** P3 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Tích hợp · Lưu, nạp và vòng đời dữ liệu.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [DocFile, dòng 336](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L336).

**Câu chính:** Sau DocFile(tv,next) thành công, dòng path=next có thể cần cấp phát. Nếu cấp phát thất bại ở đúng đây, có chắc cả RAM lẫn path cùng quay về phiên cũ không?

**Câu phụ 1:** Chuẩn bị chuỗi path mới trước DocFile rồi swap sau thành công có giúp gì?

[Mở đáp án TN82](02_DAP_AN.md#TN82) · [Về đầu phần](#tan)

<a id="TN94"></a>
### 098. TN94 — Cảnh báo có thay đổi chưa lưu

**Phụ trách:** Tấn · **Ưu tiên:** P3 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** Tích hợp · Lưu, nạp và vòng đời dữ liệu.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [BieuMau, dòng 317](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L317); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [LuuFile, dòng 341](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L341).

**Câu chính:** Muốn thêm nhãn 'chưa lưu'. Nếu đặt cờ ngay khi mở form rồi xóa cờ ngay khi bấm F5, hai sai lệch nào xảy ra?

**Câu phụ 1:** Người dùng đổi tên A→B rồi B→A trước lưu. Cờ dirty=true từ mỗi commit có nhất thiết sai không; muốn biểu thị đúng khác biệt với file cần gì?

[Mở đáp án TN94](02_DAP_AN.md#TN94) · [Về đầu phần](#tan)

<a id="TN95"></a>
### 099. TN95 — Đọc phím lỗi nằm ngoài try của thao tác

**Phụ trách:** Tấn · **Ưu tiên:** P3 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Tích hợp · Lưu, nạp và vòng đời dữ liệu.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [DocPhimConsole, dòng 107](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L107); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [main, dòng 573](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L573).

**Câu chính:** Đã có thay đổi RAM chưa lưu; ChonMenu ném lỗi vì ReadConsoleInputW thất bại. catch bên trong vòng menu có giữ phiên để thử lại không? Đọc vị trí try thay vì suy mọi lỗi đều được phục hồi.

**Câu phụ 1:** Nếu đưa ChonMenu vào try nhưng handler chỉ báo lỗi rồi lặp khi handle console vẫn hỏng, có đủ gọi là phục hồi không?

[Mở đáp án TN95](02_DAP_AN.md#TN95) · [Về đầu phần](#tan)

<a id="TN100"></a>
### 100. TN100 — Thầy hỏi phần mượn dù mình phụ trách menu

**Phụ trách:** Tấn · **Ưu tiên:** P3 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Tích hợp · Lưu, nạp và vòng đời dữ liệu.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [ManHinhMuonTra, dòng 202](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L202); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [LuuFile, dòng 341](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L341).

**Câu chính:** Người dùng chọn mượn, xem bảng đang giữ, xác nhận cuốn rồi bấm lưu. Thầy yêu cầu chỉ toàn bộ đường gọi và trạng thái nếu lưu thất bại sau mượn thành công. Em phải trả lời vượt phần giao diện thế nào? Nếu thao tác lưu đó là chọn 0 để lưu và thoát nhưng thất bại, vòng chính có cho mở b/h để xem lại RAM không?

**Câu phụ 1:** Sau lỗi lưu, chọn 13 rồi xác nhậnTHOAT có giữ lượt mượn mới trong file không?

[Mở đáp án TN100](02_DAP_AN.md#TN100) · [Về đầu phần](#tan)


<a id="chung"></a>
## Cả nhóm — 25 câu

<a id="CH01"></a>
### 001. CH01 — Sao chép thư viện để chạy thử

**Phụ trách:** Cả nhóm · **Ưu tiên:** P1 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Sở hữu bộ nhớ.

**Chỉ vào code:** [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [ThuVien, dòng 289](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L289); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [HuyThuVien, dòng 321](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L321).

**Câu chính:** Một bạn tạo bản sao toàn bộ `ThuVien` rồi mượn sách trên bản sao để xem kết quả. Với khai báo hiện tại, điều gì xảy ra khi biên dịch? Nếu bỏ hai khai báo cấm copy, bản sao có thật sự độc lập không; chuyện gì có thể xảy ra khi hai đối tượng kết thúc?

**Câu phụ 1:** Dùng HoanDoiThuVien để có hai bản cùng dữ liệu độc lập được không?

[Mở đáp án CH01](02_DAP_AN.md#CH01) · [Về đầu phần](#chung)

<a id="GH01"></a>
### 002. GH01 — Ghép ba module: ai được quyền thay trạng thái cuốn?

**Phụ trách:** Cả nhóm · **Ưu tiên:** P1 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Ghép ba module: ai được quyền thay trạng thái cuốn?.

**Chỉ vào code:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [TimCuonSachToanCuc, dòng 27](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L27), [TimCuonSachToanCuc, dòng 48](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L48); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [ManHinhMuonTra, dòng 202](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L202).

**Câu chính:** Thái trả con trỏ cuốn cho Thành, Tấn hiển thị kết quả mượn. Trên bản ghép giả lập, UI gọi hàm tìm trước MuonSach; hàm tìm bị sửa để đặt cuốn đang mượn ngay khi tìm thấy. Sau đó MuonSach nhận A có thẻ khóa và trả lỗi. Truy trạng thái cuốn và lịch sử; nếu chỉ đổi hàm tìm được gọi bên trong MuonSach mà bỏ lời gọi sớm của UI, ca thẻ khóa còn tới mutation không?

**Câu phụ 1:** UI tự đặt cuốn về 0 khi MuonSach false có an toàn với lỗi do cuốn đang do người khác giữ không?

[Mở đáp án GH01](02_DAP_AN.md#GH01) · [Về đầu phần](#chung)

<a id="CH02"></a>
### 003. CH02 — Con trỏ cũ sau khi nạp file

**Phụ trách:** Cả nhóm · **Ưu tiên:** P1 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Sở hữu bộ nhớ.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [DocNoiBo, dòng 210](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L210); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [HoanDoiThuVien, dòng 324](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L324).

**Câu chính:** Bạn lưu `NutDocGia* p` của thẻ 12 để dùng cuối màn hình. Trong lúc đó người dùng nạp thành công một file khác, cũng có thẻ 12. Dùng tiếp `p` có hợp lệ không? Nếu lần nạp thất bại thì kết luận có đổi không? Chỉ ra vòng đời bộ dữ liệu cũ.

**Câu phụ 1:** Tìm lại mã 12 ởB có chứng minh đó là cùng người nhưA không?

[Mở đáp án CH02](02_DAP_AN.md#CH02) · [Về đầu phần](#chung)

<a id="GH02"></a>
### 004. GH02 — File thay an toàn có ngăn hai người mượn trùng?

**Phụ trách:** Cả nhóm · **Ưu tiên:** P1 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** Ghép · Hai tiến trình.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [LuuNoiBo, dòng 278](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L278); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110).

**Câu chính:** Mở hai exe P,Q cùng nạp file chứa X đang rảnh. P cho A mượn rồi lưu; Q vẫn giữ RAM cũ, cho B mượn rồi lưu cùng đường dẫn. Có thể cả hai báo thành công không? File cuối chứa gì, và ghi file tạm rồi thay đích có tự khóa dữ liệu hoặc hợp nhất hai giao dịch không?

**Câu phụ 1:** Một mutex chỉ trong exeP có chặn exeQ ghi đè không?

[Mở đáp án GH02](02_DAP_AN.md#GH02) · [Về đầu phần](#chung)

<a id="CH03"></a>
### 005. CH03 — Hàm chỉ xem vẫn sửa được sách?

**Phụ trách:** Cả nhóm · **Ưu tiên:** P1 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** const và giao tiếp.

**Chỉ vào code:** [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [DanhSachDauSach, dòng 278](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L278); [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [TimViTriChenTheoTen, dòng 39](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L39).

**Câu chính:** Một hàm nhận `const ThuVien&`, lấy con trỏ từ mảng đầu sách rồi sửa tên sách qua con trỏ đó. Compiler có nhất thiết chặn không? Nếu sửa thành tên đứng trước đầu mảng, các hàm chèn và tìm nào bị ảnh hưởng? Hợp đồng chỉ xem phải được bảo vệ ra sao?

**Câu phụ 1:** Một hàm const nhưng dùng const_cast để sửa nguồn có làm hợp đồng chỉ đọc đúng không?

[Mở đáp án CH03](02_DAP_AN.md#CH03) · [Về đầu phần](#chung)

<a id="GH03"></a>
### 006. GH03 — File đứt giữa lịch sử độc giả thứ hai

**Phụ trách:** Cả nhóm · **Ưu tiên:** P1 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Ghép · Nạp file và dọn bộ tạm.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [DocNoiBo, dòng 210](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L210); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [ThuVien::~ThuVien, dòng 320](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L320); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [HuyCayDocGia, dòng 98](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L98); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [ConTroTam, dòng 29](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L29), [ConTroTam, dòng 42](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L42); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [TepDoc, dòng 203](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L203); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [BoDemDocTep, dòng 176](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L176).

**Câu chính:** RAM đang có dữ liệu A. File B đã đọc xong đầu sách, cuốn và độc giả đầu; đến lịch sử người thứ hai thì thiếu dòng. Những đối tượng vừa cấp phát do ai sở hữu, có rò nếu return sớm không, và A có bị xóa một phần? Nếu B đọc hết nhưng trùng mã thẻ thì khác gì?

**Câu phụ 1:** Bộ tạm đã dựng cây cân bằng nhưng validator cuối thất bại thì RAMA đã bị thay chưa?

[Mở đáp án GH03](02_DAP_AN.md#GH03) · [Về đầu phần](#chung)

<a id="CH04"></a>
### 007. CH04 — Con trỏ kép ở danh sách rỗng

**Phụ trách:** Cả nhóm · **Ưu tiên:** P1 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Danh sách và liên kết.

**Chỉ vào code:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [ThemCuonSach, dòng 71](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L71).

**Câu chính:** Khi thêm cuốn đầu tiên, một bạn đổi biến `CuonSach** tail` thành con trỏ `CuonSach*` rồi chỉ gán biến cục bộ ở cuối hàm. Cuốn mới có đến được từ `dms` không? Với danh sách đã có hai cuốn, cần phân biệt địa chỉ ô liên kết và địa chỉ node thế nào?

**Câu phụ 1:** Tail trỏ vào ô next của node cuối; sau NAP thành công, còn có thể gán qua tail để thêm vào bộ mới có cùng mã không?

[Mở đáp án CH04](02_DAP_AN.md#CH04) · [Về đầu phần](#chung)

<a id="GH04"></a>
### 008. GH04 — Từng module nhìn đúng nhưng ghép lại mâu thuẫn

**Phụ trách:** Cả nhóm · **Ưu tiên:** P1 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Ghép · Bất biến trạng thái.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110).

**Câu chính:** File ghi cuốn X sẵn sàng (0) nhưng có một lịch sử X đang mở; biến thể X đang mượn (1) nhưng hai người cùng có lượt X đang mở. Có nên tự sửa trạng thái cuốn không? Chỉ ra kiểm nào phải từ chối mỗi biến thể và giới hạn ba cuốn được đếm ở đâu.

**Câu phụ 1:** Xóa một trong hai phiếu mở tùy ý có chắc giữ đúng người mượn thật không?

[Mở đáp án GH04](02_DAP_AN.md#GH04) · [Về đầu phần](#chung)

<a id="CH05"></a>
### 009. CH05 — Ngoại lệ sau commit có nghĩa giao dịch đã thất bại không?

**Phụ trách:** Cả nhóm · **Ưu tiên:** P1 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Ngoại lệ sau commit có nghĩa giao dịch đã thất bại không?.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [ManHinhMuonTra, dòng 202](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L202); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ThongBao, dòng 427](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L427); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490).

**Câu chính:** MuonSach đã nối phiếu và đổi cuốn, trả true; ngay sau đó việc tạo chuỗi thông báo UI ném ngoại lệ. Thầy hỏi có được báo 'dữ liệu không đổi' như lỗi trước cấp phát phiếu không, và người dùng thử lại có tạo lượt thứ hai ngay không? Phân biệt phạm vi bảo đảm của nghiệp vụ và toàn luồng UI /lưu file.

**Câu phụ 1:** Đọc lại RAM thấy lượt đã có thì có thể báo đã lưu file không?

[Mở đáp án CH05](02_DAP_AN.md#CH05) · [Về đầu phần](#chung)

<a id="GH05"></a>
### 010. GH05 — Thất bại sau khi đã ghi file tạm

**Phụ trách:** Cả nhóm · **Ưu tiên:** P1 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Ghép · Ghi file.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [LuuNoiBo, dòng 278](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L278); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [LuuFile, dòng 341](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L341); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [TepGhi, dòng 251](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L251); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [BoDemGhiTep, dòng 211](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L211).

**Câu chính:** File cũ hợp lệ, RAM có một lượt mượn mới. Xét lỗi khi ghi/flush file tạm, lỗi đọc kiểm lại, và Windows từ chối thay file đích. Ở mỗi mốc, file cũ và RAM ra sao? Nếu mọi bước thành công, cơ chế này có chứng minh chịu mọi mất điện hoặc ngăn cập nhật thất lạc giữa hai exe không?

**Câu phụ 1:** Đọc lại file tạm hợp lệ có chứng minh serializer không bỏ một bản ghi độc lập hợp lệ không?

[Mở đáp án GH05](02_DAP_AN.md#GH05) · [Về đầu phần](#chung)

<a id="CH07"></a>
### 011. CH07 — Quên hoặc dùng sai release

**Phụ trách:** Cả nhóm · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** RAII và giải phóng.

**Chỉ vào code:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [ThemCuonSach, dòng 71](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L71); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [ConTroTam, dòng 29](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L29), [ConTroTam, dòng 42](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L42).

**Câu chính:** Node mới đang được `ConTroTam` giữ. Một bạn nối con trỏ lấy từ `get()` vào danh sách rồi để biến tạm hết phạm vi; người khác gọi `release()` trước mọi kiểm tra và sau đó trả false. Hai cách sửa này tạo rủi ro gì? Vì sao vị trí chuyển quyền sở hữu phải gắn với bước commit?

**Câu phụ 1:** Giả định nối get() rồi gọi release ở dòng kế: điều kiện nào làm hai dòng đó an toàn, và chèn một thao tác có thể ném vào giữa tạo lỗi gì?

[Mở đáp án CH07](02_DAP_AN.md#CH07) · [Về đầu phần](#chung)

<a id="CH08"></a>
### 012. CH08 — Xóa bảng kết quả làm hỏng thư viện

**Phụ trách:** Cả nhóm · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Bộ nhớ tạm.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InDocGiaTheoTenHo, dòng 114](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L114); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [HuyCayDocGia, dòng 98](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L98).

**Câu chính:** Bảng in theo tên chứa các con trỏ tới độc giả trong BST. Sau khi in, một bạn lặp delete từng phần tử rồi delete mảng cho chắc không rò. Lần tìm độc giả hoặc thoát chương trình tiếp theo có thể gặp gì? Nếu chỉ giải phóng mảng view thì lịch sử của độc giả do ai hủy?

**Câu phụ 1:** Copy mảng con trỏ view thành mảng thứ hai có tạo thêm chủ sở hữu node không?

[Mở đáp án CH08](02_DAP_AN.md#CH08) · [Về đầu phần](#chung)

<a id="GH08"></a>
### 013. GH08 — Dữ liệu ngày không đủ để khẳng định thứ tự thật

**Phụ trách:** Cả nhóm · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Ghép · Cùng ngày và báo mất.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [KiemTraNoiBo, dòng 90](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L90); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [KiemTraDongThoiGian, dòng 21](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L21).

**Câu chính:** Cùng cuốn X có hai lượt cùng ngày 01: A mượn–trả, B mượn–báo mất; X đã thanh lý, B bị khóa. Loader có thể chấp nhận không? Đổi lượt của A thành ngày 02 sau ngày B báo mất 01 thì sao? Việc đảo dòng trong file có thể dùng làm bằng chứng giờ thao tác thực tế không?

**Câu phụ 1:** Đổi vị trí hai dòng cùng ngày có bổ sung được thông tin giờ đã mất không?

[Mở đáp án GH08](02_DAP_AN.md#GH08) · [Về đầu phần](#chung)

<a id="CH09"></a>
### 014. CH09 — Kiểm tràn sau khi đã tràn

**Phụ trách:** Cả nhóm · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Số nguyên và cận.

**Chỉ vào code:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [DocSoNguyen, dòng 61](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L61).

**Câu chính:** Đầu vào số là `2147483648` trên cấu hình int của bản này. Một bạn bỏ phép so `hi/10` và `hi%10`, tính `n*10+d` trước rồi kiểm n có lớn hơn hi không. Cách đó có an toàn không? Đối số output phải ra sao khi đọc thất bại?

**Câu phụ 1:** Chuỗi số rất dài toàn 0 có tràn chỉ vì dài không?

[Mở đáp án CH09](02_DAP_AN.md#CH09) · [Về đầu phần](#chung)

<a id="GH09"></a>
### 015. GH09 — Chạy riêng file main rồi gặp lỗi linker

**Phụ trách:** Cả nhóm · **Ưu tiên:** P2 · **Phạm vi:** Hiện tại.

**Trọng tâm:** Ghép · Dev-C++ và liên kết.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [main, dòng 573](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L573); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [LuuNoiBo, dòng 278](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L278); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [MuonSach, dòng 367](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L367); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [DocDoiSoWindows, dòng 139](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L139).

**Câu chính:** Bạn mở riêng 08 trong Dev-C++ rồi Compile & Run, linker báo thiếu MuonSach; thêm cả main mặc định của project lại báo trùng main. Một máy khác báo thiếu windows.h; một bản tải về vẫn đòi filesystem hoặc CommandLineToArgvW. Hãy phân loại từng lỗi, kiểm đúng phiên bản và nêu cấu hình build của demo C++11 này.

**Câu phụ 1:** Thêm prototype MuonSach lần nữa có sửa lỗi undefined reference khi thiếu 06 không?

[Mở đáp án GH09](02_DAP_AN.md#GH09) · [Về đầu phần](#chung)

<a id="CH10"></a>
### 016. CH10 — Chuẩn hóa giúp dữ liệu sai đi qua

**Phụ trách:** Cả nhóm · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** UTF-8 và hợp đồng.

**Chỉ vào code:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [ChuanHoaChuoi, dòng 10](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L10); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [ThemDocGia, dòng 59](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L59).

**Câu chính:** API nhận tên có newline hoặc tab từ file/bộ kiểm thử, không phải người gõ từng dòng console. Một bạn bỏ kiểm dữ liệu gốc và chỉ kiểm chuỗi sau `ChuanHoaChuoi`. Điều gì thay đổi so với quy ước v1? Tại sao chức năng chuẩn hóa tự nó xử lý whitespace vẫn chưa đủ làm hàm nhập an toàn?

**Câu phụ 1:** Một query tìm kiếm chứa tab được chuẩn hóa có chứng minh API lưu tên cũng nên nhận tab không?

[Mở đáp án CH10](02_DAP_AN.md#CH10) · [Về đầu phần](#chung)

<a id="CH11"></a>
### 017. CH11 — Bool, output và exception: hợp đồng có thể bị hiểu sai khi ghép

**Phụ trách:** Cả nhóm · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Bool, output và exception: hợp đồng có thể bị hiểu sai khi ghép.

**Chỉ vào code:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [ThemCuonSach, dòng 71](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L71); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [ThemDocGia, dòng 59](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L59); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490).

**Câu chính:** Thầy so ThemCuonSach có catch trả false với ThemDocGia có thể ném ngoại lệ; hai hàm đều có output mã. Adapter chung chỉ kiểm 'không có exception' rồi báo thành công. Hãy chỉ hai kiểu kết luận sai có thể xảy ra, thiết kế một hợp đồng kết quả thống nhất và nêu phần nào không thể hứa khi lỗi ở chính bước tạo thông báo.

**Câu phụ 1:** Adapter có thể gán mã output vào thông báo trước khi kiểm bool không?

[Mở đáp án CH11](02_DAP_AN.md#CH11) · [Về đầu phần](#chung)

<a id="CH12"></a>
### 018. CH12 — Comparator có chu trình: sort có thể sửa giúp không?

**Phụ trách:** Cả nhóm · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Comparator có chu trình: sort có thể sửa giúp không?.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [TenHoTruoc, dòng 39](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L39); [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — [SoSanhDauSach, dòng 5](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/02_XuLyDauSach.cpp#L5); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [DauSachXepTruoc, dòng 103](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L103); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [SapXepHeap, dòng 84](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L84).

**Câu chính:** Một đề xuất ưu tiên thể loại theo vòng A trước B, B trước C, C trước A để 'luân phiên công bằng', rồi dùng cùng heap sort. Thầy yêu cầu chỉ vì sao không thể có dãy thỏa mọi cặp; khác gì quy tắc khóa phụ tên– ISBN hiện tại. Nếu comparator còn đổi theo số lần được gọi, có thể dùng kết quả một lần chạy đúng làm bằng chứng không?

**Câu phụ 1:** Comparator ưu tiên quá hạn theo ngày máy đọc lại ở mỗi phép so; nếu đồng hồ đổi giữa sort thì test bất phản xạ đơn lẻ có đủ không?

[Mở đáp án CH12](02_DAP_AN.md#CH12) · [Về đầu phần](#chung)

<a id="GH12"></a>
### 019. GH12 — Nạp đúng các node nhưng quên metadata: lỗi nằm ngoài BST

**Phụ trách:** Cả nhóm · **Ưu tiên:** P2 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Nạp đúng các node nhưng quên metadata: lỗi nằm ngoài BST.

**Chỉ vào code:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [DocNoiBo, dòng 210](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L210); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [HoanDoiThuVien, dòng 324](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L324); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [ThemDocGia, dòng 59](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L59).

**Câu chính:** File có mốc 100 nhưng mã lớn nhất còn lại 80; một refactor loader bỏ dòng mốc rồi tính lại từ cây để đơn giản định dạng. Thầy hỏi vì sao cây tìm/in vẫn đúng nhưng lần cấp thẻ tiếp theo sai; nếu lấy max giữa RAM cũ và file mới thì có luôn đúng khi NAP một thư viện độc lập không?

**Câu phụ 1:** Nạp thư việnB có mốc thấp hơnA nhưng hợp lệ độc lập có phải tự nâng mốcB theoA không?

[Mở đáp án GH12](02_DAP_AN.md#GH12) · [Về đầu phần](#chung)

<a id="GH13"></a>
### 020. GH13 — Đổi b sang họ–tên–mã trên bản sao

**Phụ trách:** Cả nhóm · **Ưu tiên:** P3 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Sửa trực tiếp · 20 phút.

**Chỉ vào code:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [TenHoTruoc, dòng 39](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L39); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InDocGiaTheoTenHo, dòng 114](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L114); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490).

**Câu chính:** Trong 20 phút, trên bản sao, đổi riêng lựa chọn b theo tên thành họ–tên–mã tăng; sửa nhãn tương ứng. Với (30,Tran,An), (10,Le,Z), (20,Le,A), kết quả phải 20,10,30. Giữ b theo mã, khóa BST, dữ liệu file và lịch sử. Tự chọn thêm ca đồng khóa và nêu kiểm thử hồi quy cần chạy. Nếu thầy chỉ yêu cầu ghép cột Họ tên cho gọn mà không đổi quy tắc sắp, có được nhân tiện sửa comparator như trên không?

**Câu phụ 1:** Nếu thầy đổi lại chỉ nhãn cột mà không đổi sort, ca 20,10,30 còn là expected bắt buộc không?

[Mở đáp án GH13](02_DAP_AN.md#GH13) · [Về đầu phần](#chung)

<a id="CH14"></a>
### 021. CH14 — Đổi chỉ số sang size_t để hết warning có an toàn không?

**Phụ trách:** Cả nhóm · **Ưu tiên:** P3 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Đổi chỉ số sang size_t để hết warning có an toàn không?.

**Chỉ vào code:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — [ChuaChuoi, dòng 27](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/01_HamTienIch.cpp#L27); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [SapXepHeap, dòng 84](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L84); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [InDocGiaTheoTenHo, dòng 114](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L114).

**Câu chính:** Thầy chỉ ChuaChuoi dùng size_t và heap sort dùng int. Một bạn đổi mọi chỉ số heap sang size_t rồi giữ vòng for(i=n/2; i>=0;--i), đồng thời bỏ kiểm từ khóa dài hơn tên vì ' size không âm'. Hai chỗ trừ có gì chung, cần thiết kế cận/vòng lặp thế nào để không dựa vào giá trị âm không tồn tại?

**Câu phụ 1:** Thay size_t bằng int cho mọi độ dài có tự hết lỗi không?

[Mở đáp án CH14](02_DAP_AN.md#CH14) · [Về đầu phần](#chung)

<a id="GH14"></a>
### 022. GH14 — Báo cáo đang giữ của mọi người: nối dữ liệu theo đường nào?

**Phụ trách:** Cả nhóm · **Ưu tiên:** P3 · **Phạm vi:** Mở rộng giả định.

**Trọng tâm:** Báo cáo đang giữ của mọi người: nối dữ liệu theo đường nào?.

**Chỉ vào code:** [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — [LietKeSachDangMuon, dòng 20](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/05_XuLyMuonTra.cpp#L20); [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — [LayDanhSachDocGia, dòng 13](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/04_XuLyDocGia.cpp#L13); [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — [TimCuonSachToanCuc, dòng 27](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L27), [TimCuonSachToanCuc, dòng 48](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/03_XuLyCuonSach.cpp#L48); [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [ChiMucCuon, dòng 92](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L92).

**Câu chính:** Thầy muốn bảng mã thẻ–họ tên–mã cuốn–tên sách cho mọi lượt đang mở, mã thẻ tăng. Có R người, H lịch sử, C cuốn và nhiều mã legacy. So cách gọi h cho từng người với một lần duyệt và chỉ mục cuốn tạm; điểm nào bị quét lặp, bộ nhớ nào phải trả thêm và vì sao giới hạn 3 không làm chi phí toàn báo cáo thành O(R)?

**Câu phụ 1:** K=0 lượt mở có cho kết luận không cần duyệt H ở thiết kế quét hiện tại không?

[Mở đáp án GH14](02_DAP_AN.md#GH14) · [Về đầu phần](#chung)

<a id="CH15"></a>
### 023. CH15 — Mọi exception đều thiếu bộ nhớ?

**Phụ trách:** Cả nhóm · **Ưu tiên:** P3 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Ngoại lệ và ý nghĩa lỗi.

**Chỉ vào code:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — [MuonSach, dòng 110](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/06_NghiepVuTongHop.cpp#L110); [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490); [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — [LoiThuVien, dòng 20](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/00_KhaiBaoChung.h#L20).

**Câu chính:** Các hàm sách/nghiệp vụ như ThemCuonSach và MuonSach dùng catch(...) rồi báo thiếu bộ nhớ. Các wrapper file và main lại bắt LoiThuVien trước catch(...). Nếu lỗi khác phát sinh, thông báo có luôn đúng nguyên nhân không? Đề xuất cải thiện chẩn đoán trên bản sao mà vẫn giữ C++11 và bốn header được phép.

**Câu phụ 1:** Bắt LoiThuVien riêng rồi trả false có đủ chứng minh dữ liệu không đổi nếu lỗi xảy ra sau phép nối node của một refactor không?

[Mở đáp án CH15](02_DAP_AN.md#CH15) · [Về đầu phần](#chung)

<a id="GH15"></a>
### 024. GH15 — Xem số liệu file trước khi thay RAM

**Phụ trách:** Cả nhóm · **Ưu tiên:** P3 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Sửa trực tiếp · 20 phút.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [DocFile, dòng 336](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L336); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [HoanDoiThuVien, dòng 324](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L324).

**Câu chính:** Trong 20 phút, trên bản sao, đổi luồng nạp: file hợp lệ hiện số đầu/cuốn/độc giả trước khi xác nhận NAP. Hủy phải giữ RAM và đường dẫn hiện hành; file lỗi không được thay dữ liệu. NAP thành công thay cả dữ liệu lẫn đường dẫn. Không thêm trường nghiệp vụ; tránh tồn tại view trỏ vào bộ dữ liệu đã hủy.

**Câu phụ 1:** Sau previewB hợp lệ rồi fileB bên ngoài đổi trước xác nhận, nên dùng bộ nào để commit?

[Mở đáp án GH15](02_DAP_AN.md#GH15) · [Về đầu phần](#chung)

<a id="GH16"></a>
### 025. GH16 — Lưu thành file khác nhưng chỉ đổi phiên khi thành công

**Phụ trách:** Cả nhóm · **Ưu tiên:** P3 · **Phạm vi:** Chẩn đoán trên bản sao.

**Trọng tâm:** Sửa trực tiếp · 20 phút.

**Chỉ vào code:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — [ChayUngDung, dòng 490](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp#L490); [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — [LuuFile, dòng 341](https://github.com/ntienthanh195/do-an-thu-vien/blob/b44964652043d8f4790a23952d4e3a8694ce1cdf/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/MaNguon/07_LuuDocFile.cpp#L341).

**Câu chính:** Trong 20 phút, trên bản sao, thêm lựa chọn lưu thành file khác. Nhập đường dẫn và xác nhận trước khi ghi; hủy hoặc ghi lỗi giữ đường dẫn hiện hành và RAM. Lưu thành công mới dùng đường dẫn mới cho lần lưu sau. Không đổi định dạng v1, thuật toán nghiệp vụ hoặc xóa file gốc.

**Câu phụ 1:** Sau lưu file mới thành công nhưng gán path mới ném lỗi, tiêu chí đã đạt trọn chưa?

[Mở đáp án GH16](02_DAP_AN.md#GH16) · [Về đầu phần](#chung)


## Mốc ID đã gộp

Các mục sau chỉ điều hướng, không phải câu riêng.

<a id="TH201"></a>
TH201 đã gộp vào [TH52](#TH52); vị trí bổ sung dùng ID mới [TH301](#TH301).

<a id="TH234"></a>
TH234 đã gộp vào [TH21](#TH21); vị trí bổ sung dùng ID mới [TH302](#TH302).

<a id="TV204"></a>
TV204 đã gộp vào [TV12](#TV12); vị trí bổ sung dùng ID mới [TV301](#TV301).

