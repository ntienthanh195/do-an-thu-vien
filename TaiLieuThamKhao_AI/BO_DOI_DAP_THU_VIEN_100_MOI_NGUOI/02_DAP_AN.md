# Đáp án — 325 câu đối đáp Thư viện

**Thái 100 · Thành 100 · Tấn 100 · Cả nhóm 25.** [Câu hỏi](01_CAU_HOI.md) · [Báo cáo kiểm tra](ThamKhao/BAO_CAO_KIEM_TRA.md).

Bản chỉnh nội dung 18/10/2026. “Truy vết/đề xuất” không phải kết quả đã chạy. [25 ca ngày17/10](ThamKhao/KIEM_CHUNG_RUNTIME.md) là bằng chứng lịch sử, không chạy lại trong đợt này. [18 lượt kiểm mới](ThamKhao/KIEM_DINH_20261018.md) gồm16 lượt assertion và2 timeout có chủ đích. Mỗi liên kết dưới chỉ xác nhận phạm vi ca, không chứng nhận toàn câu/câu phụ hay phương án chưa cài.

Quy ước D/C/R/H/h/L, giới hạn, cấu trúc bắt buộc và giả định G01–G12 nằm ở đầu file câu hỏi. Đáp án là căn cứ phản biện, không phải lời nói học thuộc hoặc bằng chứng người học đã tự làm.


<a id="thai"></a>
## Thái — 100 đáp án

<a id="TH01"></a>
### TH01 — Cùng ISBN nhưng ba trạng thái

**Thái · P1 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH01).

**Trả lời ngắn:** Tên, tác giả và ISBN thuộc đầu sách; mỗi cuốn giữ mã, trạng thái, vị trí riêng. Lịch sử phải ghi A#3.

**Giải thích và bảo vệ cách làm:**

Bình được mượn A#3 nếu thẻ hoạt động, còn hạn mức và không quá hạn; trạng thái A#1/A#2 không tự chặn A#3.

Một trạng thái chung không biểu diễn ba bản vật lý khác nhau và làm sai cấu trúc đề.

**Đáp câu phụ 1:** Tìm tên in trạng thái A#3 từ danh mục. Top đếm node lịch sử nên không tự cộng lượt và không kiểm mọi cặp trạng thái–lịch sử. KiemTraNoiBo khi lưu thấy cuốn đang mượn mà active bằng 0, từ chối. Ba đường đọc không có cùng trách nhiệm kiểm toàn vẹn.

**Sai lầm dễ mắc:** Dùng trạng thái một đầu để quyết định quyền mượn mọi cuốn của đầu đó.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Tạo ba cuốn đúng trạng thái kèm lịch sử hợp lệ; tìm tên trước/sau giao dịch, đối chiếu riêng từng mã.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — `DauSach`, dòng 15; [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `InMotDauSach`, dòng 14; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114.

<a id="TH02"></a>
### TH02 — Chèn giữa khi đang giữ con trỏ cuốn

**Thái · P1 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH02).

**Trả lời ngắn:** Vòng dịch chuyển các ô DauSach*, không di chuyển đối tượng đầu sách hoặc nút cuốn; con trỏ cuốn vẫn hợp lệ sau riêng thao tác thêm này.

**Giải thích và bảo vệ cách làm:**

Lap trinh chuyển sang chỉ số 2; dùng chỉ số 1 cũ sẽ trỏ sang đầu sách khác.

Tìm vị trí O(log D) phép so sánh; kiểm ISBN và dịch con trỏ khiến cả thao tác O(D), chưa tính độ dài chuỗi.

**Đáp câu phụ 1:** Không; NAP thay toàn bộ đối tượng nguồn và hủy bộ cũ. Bảo đảm con trỏ không đổi chỉ áp riêng chèn dịch ô.

**Sai lầm dễ mắc:** Suy con trỏ sống qua mọi thao tác từ việc nó sống qua chèn mảng.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Ghi địa chỉ cuốn và dãy ISBN trước/sau; thử chèn đầu, giữa, cuối và xác nhận dãy tên còn tăng.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `ThemDauSach`, dòng 64.

<a id="TH05"></a>
### TH05 — Mã có lỗ sau khi mở lại file

**Thái · P1 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH05).

**Trả lời ngắn:** Hai mã mới là A#4, A#5; lấy hậu tố chuẩn lớn nhất của ISBN A rồi tăng một, bỏ qua mã cũ S001.

**Giải thích và bảo vệ cách làm:**

Đếm nút cộng một không biểu diễn mã đã dùng; chỉ A#1/A#3 đã đủ tạo phản ví dụ trùng A#3.

Hàm quét toàn bộ danh mục, kể cả ngoài A, để tránh trùng khi bộ nhớ chứa mã sai chủ; chi phí O(D+C) ngoài xử lý chuỗi.

**Đáp câu phụ 1:** Không; bộ sinh không bỏ mã theo trạng thái và không lấp lỗ. Mã thanh lý vẫn thuộc danh tính được giữ.

**Sai lầm dễ mắc:** Số cuốn sẵn sàng hoặc số node thay được hậu tố lớn nhất.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Lặp sau nạp file; thử riêng A#1/A#3 không có S001 và kiểm không sinh A#3.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `SinhMaSachTuDong`, dòng 59.

<a id="TH06"></a>
### TH06 — Tên tăng không có nghĩa ISBN tăng

**Thái · P1 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH06).

**Trả lời ngắn:** Mã mới tách ISBN rồi quét đầu sách và danh mục tương ứng: O(D+Cᵢ). Mã cũ quét các danh mục: O(D+C).

**Giải thích và bảo vệ cách làm:**

Dãy Z/A/M không tăng theo ISBN; nhị phân tìm Z có thể loại bỏ nửa chứa Z dựa trên so sánh sai tiền điều kiện.

Yêu cầu tìm nhanh nhất cần được hỏi trong giới hạn cấu trúc; code hiện tại không chứng minh O(1) hoặc tối ưu tuyệt đối.

**Đáp câu phụ 1:** Không; index phải được dựng lại/cập nhật, nhất là nếu nó giữ chỉ số các ô bị dịch.

**Sai lầm dễ mắc:** Mảng tăng theo tên cũng tăng theo mọi trường khác.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Dựng đúng ba đầu sách này, tìm từng mã và một mã không có; đếm số lần so sánh trên bản sao.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `TimCuonSachToanCuc`, dòng 30, 51; [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `TimDauSachTheoISBN`, dòng 54.

<a id="TH13"></a>
### TH13 — Đếm chuỗi thành công và thất bại

**Thái · P1 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH13).

**Trả lời ngắn:** A có 2 lượt và 2 nút lịch sử; trả hoặc báo mất sửa chính phiếu đã tồn tại, không tạo lượt mới.

**Giải thích và bảo vệ cách làm:**

Yêu cầu của Cường thất bại không có phiếu; B có 0 lượt nên không hiện dù nhiều cuốn hơn.

G01 đếm mọi lượt thành công, kể cả đã mất; đây là cách hiểu top theo đầu sách cần xác nhận.

**Đáp câu phụ 1:** Không; đó là chỉ số mới cần ghi sự kiện thất bại, hiện không có trong lịch sử.

**Sai lầm dễ mắc:** Đồng nhất yêu cầu thử mượn, giao dịch thành công và số cuốn.

**Cách kiểm chứng:** Đề xuất kiểm chứng: In top sau từng sự kiện; kiểm A lần lượt 1, 1, 2, 2, 2 và B luôn không hiện.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InTop10SachDuocMuonNhieuNhat`, dòng 172; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KetThucMuon`, dòng 54.

<a id="TH14"></a>
### TH14 — Ranh giới thứ mười có ba đầu cùng tên

**Thái · P1 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH14).

**Trả lời ngắn:** Bản hiện in chín đầu lượt cao và A: lượt giảm, tên tăng, ISBN tăng; đầu 0 lượt bị bỏ. k là số ô top hợp lệ, luôn từ 0 đến 10, chỉ in các ô có chỉ số nhỏ hơn k.

**Giải thích và bảo vệ cách làm:**

Khi k=10, last=9 để dịch trong miền 0..9; phần tử đang đứng cuối bị loại nếu ứng viên mới vào top. Khởi tạo top bằng 0 không làm ô ngoài k trở thành kết quả hợp lệ.

Nếu yêu cầu lấy tất cả đồng lượt, bộ ví dụ phải có 12 dòng. Cần xác định ngưỡng lượt rồi chọn mọi đầu đạt ngưỡng và sắp theo khóa phụ; nới mảng nhưng vẫn chặn ở 10 không đổi nghĩa thuật toán.

Theo đầu hay cuốn và cách xử lý đồng hạng là giả định G01/G02 cần hỏi thầy. Đề xuất thuật toán mới trên bản sao, tính chi phí và thử cả dưới 10 đầu có lượt.

**Đáp câu phụ 1:** Tên không bắt buộc chuẩn hóa khoảng trắng khi nạp nhưng SoSanhChuoi chuẩn hóa và hạ ASCII để so; hai khóa tên bằng nhau. ISBN A đứng trước B. Phải dùng đúng khóa so, không so chuỗi hiển thị thô; đây vẫn là G02/G09.

**Sai lầm dễ mắc:** Dùng khóa phụ vượt qua khóa chính hoặc đọc ô top ngoài k.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Truy top/k khi có 0, 3, 10, 12 đầu dương; thêm ứng viên cao nhất lúc k=10; kiểm không đọc/ghi ngoài 0..9 và phân biệt hai đặc tả đồng hạng.

**Kiểm mới 18/10:** [original_top_ties](ThamKhao/KIEM_DINH_20261018.md#original_top_ties). Chỉ các assertion/quan sát nêu trong ca.

**Ca liên quan đã chạy 17/10 (không tái chạy đợt này):** [top_twelve_ties](ThamKhao/KIEM_CHUNG_RUNTIME.md#top_twelve_ties).

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InTop10SachDuocMuonNhieuNhat`, dòng 172; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `DauSachXepTruoc`, dòng 107.

<a id="TH37"></a>
### TH37 — Kho gần đầy, lỗi nào được báo và lúc nào dữ liệu đổi?

**Thái · P1 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH37).

**Trả lời ngắn:** Lần đầu dùng ô cuối hợp lệ; lần sau bị chặn ngay vì soLuong>= MAX_DAU_SACH, chưa kiểm ISBN. Đây là thứ tự báo lỗi hiện tại.

**Giải thích và bảo vệ cách làm:**

Đưa kiểm đầy sau dịch có thể ghi ds[ MAX_DAU_SACH ], vượt mảng trước khi kịp báo lỗi. Mọi kiểm và cấp phát phải xong trước commit dịch con trỏ.

Muốn gom lỗi phải có pha kiểm riêng, không dùng việc tiếp tục qua nhánh lỗi để chạy cả commit. Thứ tự thông báo thay đổi được nhưng cần thống nhất UI / test.

**Đáp câu phụ 1:** Không; thu thập lỗi phải ở pha đọc/kiểm không mutation, rồi không commit khi có lỗi.

**Sai lầm dễ mắc:** Tiếp tục qua lỗi để gom thông báo đồng nghĩa được chạy các bước ghi.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Dùng bản sao sát giới hạn; so mảng địa chỉ và soLuong trước/sau hai lệnh, rồi đọc cận vòng dịch.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `ThemDauSach`, dòng 64; [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `TimViTriChenTheoTen`, dòng 43.

<a id="TH41"></a>
### TH41 — Gộp ISBN nhìn giống nhau có thể đổi lịch sử của ai?

**Thái · P1 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH41).

**Trả lời ngắn:** ISBN so chính xác theo chuỗi sau chuẩn hóa khoảng trắng; các cặp trên là các đầu khác nhau. Mã cuốn tự sinh giữ nguyên tiền tố ISBN.

**Giải thích và bảo vệ cách làm:**

Đổi riêng phép so có thể làm nhiều định danh cũ rơi vào một khóa và trả sai chủ; không thể chỉ sửa tìm kiếm mà bỏ qua cuốn/lịch sử/thứ tự hòa.

Nếu thầy yêu cầu quy tắc mới, cần phát hiện va chạm, quy định ánh xạ danh tính và kiểm toàn bộ liên kết trên dữ liệu tạm; đây chưa là chức năng đang có.

**Đáp câu phụ 1:** Người dùng có thể không phân biệt 0012 và 12 khi chọn; phải giữ mã đầy đủ ở chỗ xác nhận, dù dữ liệu chưa bị gộp.

**Sai lầm dễ mắc:** Hình thức hiển thị giống nhau là căn cứ gộp danh tính.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Dựng bốn đầu với số lượt khác nhau; đối chiếu chủ từng cuốn và top trước khi thử quy tắc mới trên bản sao.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `TimDauSachTheoISBN`, dòng 54; [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `TachMaMoi`, dòng 8; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `TimChuSoHuu`, dòng 98.

<a id="TH46"></a>
### TH46 — Tem sách in thêm số 0: sửa dữ liệu hay sửa đầu vào?

**Thái · P1 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH46).

**Trả lời ngắn:** TachMaMoi từ chối hậu tố có 0 đầu; có # mà không hợp lệ không được dùng nhánh legacy. Trả A#01 không tự đóng phiếu A#1.

**Giải thích và bảo vệ cách làm:**

Cho fallback rộng che lỗi mã/quyền sở hữu. Bộ đọc cũng từ chối mã tự sinh không chuẩn; không có hai danh tính hợp lệ A#01/A#1 theo quy ước này.

Nếu hỗ trợ tem cũ cần quy tắc ánh xạ được xác nhận, kiểm va chạm và hiển thị mã đích trước giao dịch; sửa tem hoặc lớp chuyển đầu vào có kiểm soát, không tùy tiện đổi lịch sử.

**Đáp câu phụ 1:** Không; có# nhưng suffix không phải số dương chuẩn thì đường tìm trả thất bại, không fallback.

**Sai lầm dễ mắc:** Fallback càng rộng thì càng an toàn cho dữ liệu cũ.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Thử cùng độc giả trả bằng A#01 rồi A#1; kiểm lần đầu không đổi phiếu/cuốn và đọc nơi loader kiểm dạng mã.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `TachMaMoi`, dòng 8; [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `TimCuonSachToanCuc`, dòng 30, 51; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `MaSinhDungDauSach`, dòng 55; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KetThucMuon`, dòng 54.

<a id="TH61"></a>
### TH61 — Trả một phần làm người đứng đầu bảng chuyển vị trí thế nào?

**Thái · P1 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH61).

**Trả lời ngắn:** Ban đầu An vượt hạn 8 và 1 ngày, điểm max 8; Bình điểm 5 nên An đứng trước. Trả Y giữ điểm 8 và còn 1 cuốn quá hạn.

**Giải thích và bảo vệ cách làm:**

Trả X làm An còn điểm 1, xuống sau Bình. Ở cả hai nhánh vẫn còn một cuốn quá hạn nên xin W thất bại dù còn chỗ.

Báo cáo gom max và đếm số cuốn, còn quyền mượn dùng điều kiện tồn tại ít nhất một cuốn quá hạn; không dùng thay đổi thứ hạng để suy quyền.

**Đáp câu phụ 1:** Đúng, xét riêng quá hạn; quyền mượn vẫn còn kiểm thẻ, số giữ, ngày và cuốn.

**Sai lầm dễ mắc:** Hết một điều kiện cấm đồng nghĩa chắc chắn được mượn.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Kiểm hai bản dữ liệu riêng, so báo cáo i, h và kết quả mượn W sau mỗi lượt.

**Ca liên quan đã chạy 17/10 (không tái chạy đợt này):** [overdue_partial_return](ThamKhao/KIEM_CHUNG_RUNTIME.md#overdue_partial_return).

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InDocGiaQuaHan`, dòng 148; [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `CoSachQuaHan7Ngay`, dòng 9; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114.

<a id="TH15"></a>
### TH15 — Hủy khi mới thêm một phần danh mục

**Thái · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH15).

**Trả lời ngắn:** Cả hai luồng giữ đầu A và cuốn thứ nhất đã thêm; tìm thấy một cuốn, top chưa có lượt nên không hiện A.

**Giải thích và bảo vệ cách làm:**

Hủy form đầu trước khi gọi ThemDauSach thì thư viện vẫn trống. TUI chỉ tạo đầu khi xác nhận; cuốn được thêm qua thao tác riêng.

Không có giao dịch gộp cả đầu và mọi cuốn. Hủy bỏ giá trị tạm của form hiện tại, không hoàn tác các thao tác đã thành công.

Yêu cầu nguyên khối cần chuẩn bị và kiểm cả cụm trước khi đưa vào kho, hoặc cơ chế hoàn tác đầy đủ do người sửa thiết kế. Không xóa tùy tiện các cuốn đã commit vì thao tác hủy hiện chỉ áp form đang nhập.

**Đáp câu phụ 1:** Không; cuốn đầu vẫn trong kho và được bộ sinh mã xét. Hủy không reset lịch sử cấp mã từ danh mục hiện tại.

**Sai lầm dễ mắc:** Hủy một form là rollback toàn phiên nhập.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Chạy hai cách nhập trên bản sao, hủy rồi lưu; so số đầu/cuốn và mã sinh tiếp theo. TUI không có ô nhập số lượng cuốn.

**Ca liên quan đã chạy 17/10 (không tái chạy đợt này):** [partial_book_cancel](ThamKhao/KIEM_CHUNG_RUNTIME.md#partial_book_cancel).

**Nguồn đối chiếu:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `ManHinhNhapDauSach`, dòng 128; [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `ThemCuonSach`, dòng 74.

<a id="TH16"></a>
### TH16 — Mã chuẩn bị đặt nhầm đầu sách

**Thái · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH16).

**Trả lời ngắn:** Tra mã chuẩn chỉ vào đầu A nên không tìm thấy; kiểm toàn vẹn và lưu từ chối vì mã không thuộc đầu chứa nó.

**Giải thích và bảo vệ cách làm:**

Bộ sinh quét toàn cục vẫn thấy hậu tố 2 của A, nên có thể sinh A#3 nếu các điều kiện khác đạt.

Chống trùng không sửa dữ liệu sai chủ; bộ nhớ vẫn lỗi cho tới khi được khôi phục đúng.

**Đáp câu phụ 1:** Chưa; chỉ che sai cấu trúc, còn tiền tố/đầu chứa và liên kết vẫn vi phạm validator.

**Sai lầm dễ mắc:** Tìm thấy một con trỏ là bằng chứng đối tượng ở đúng chủ.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Gây lỗi trên bản sao rồi kiểm riêng tra cứu, thêm và lưu; không dùng riêng thông báo thêm thành công để kết luận toàn vẹn.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `TimCuonSachToanCuc`, dòng 30, 51; [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `SinhMaSachTuDong`, dòng 59; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `MaSinhDungDauSach`, dòng 55.

<a id="TH19"></a>
### TH19 — Đảo comparator khi vun đống

**Thái · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH19).

**Trả lời ngắn:** Comparator nghĩa là đứng trước, nên heap đưa phần tử đứng sau lên gốc; rút gốc ra cuối tạo thứ tự kết quả mong muốn.

**Giải thích và bảo vệ cách làm:**

Với dữ liệu này, dòng (30,6) là phần đứng cuối; hai dòng mức 7 phải ra theo mã 5 rồi 10.

Đảo một điều kiện phá quan hệ heap thống nhất; phải truy và kiểm cả sắp tăng lẫn giảm, không suy từ tên max/min heap.

Dựng từ i=1 đưa (30,6) lên trên (10,7); dựng i=0 cho mảng [(30,6),(10,7),(5,7),(20,11)]. Rút gốc về cuối và vun miền 3 cho [(10,7),(20,11),(5,7),(30,6)]. Cuối cùng ra [(20,11),(5,7),(10,7),(30,6)].

**Đáp câu phụ 1:** Có thể phát hiện qua mã tăng, nhưng chưa phủ chiều điểm chính; cần cả hòa và không hòa.

**Sai lầm dễ mắc:** Một bộ dữ liệu chỉ có khóa khác nhau ở một tầng đủ kiểm mọi nhánh comparator.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Truy mảng sau mỗi hoán đổi, chạy các hoán vị của bốn dòng và kiểm toàn thứ tự cùng số phần tử.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `VunDong`, dòng 79; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `SapXepHeap`, dòng 88; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InDocGiaQuaHan`, dòng 148.

<a id="TH20"></a>
### TH20 — Chỉ mục tạm với mã cũ và mã mới

**Thái · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH20).

**Trả lời ngắn:** Chỉ mục so chuỗi mã nên A#10 đứng trước A#2, rồi S001; mỗi dòng vẫn giữ chỉ số đầu sở hữu.

**Giải thích và bảo vệ cách làm:**

Ba tìm nhị phân cộng A=2, B=1; mã cũ cũng đi qua cùng chỉ mục, không phải quét lại thư viện.

Thứ tự dựng chỉ mục phải khớp phép so trong tìm kiếm; đổi sang thứ tự số riêng mà không đổi comparator sẽ phá tiền điều kiện.

**Đáp câu phụ 1:** Không; vị trí sau sort là hạng mã cuốn, không phải chỉ số đầu sách. Phải giữ mapping chủ theo từng ô.

**Sai lầm dễ mắc:** Thứ tự mới của index tự mang lại danh tính chủ.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Đối chiếu từng mã với chủ sở hữu, thêm mã không tồn tại và kiểm tìm trả -1.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InTop10SachDuocMuonNhieuNhat`, dòng 172; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `TimChuSoHuu`, dòng 98.

<a id="TH21"></a>
### TH21 — Có lịch sử nhưng mã cuốn biến mất

**Thái · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH21).

**Trả lời ngắn:** Top tìm không thấy chủ sở hữu, in lỗi toàn vẹn rồi return trước phần xuất bảng; không âm thầm bỏ lượt đó.

**Giải thích và bảo vệ cách làm:**

Lưu cũng bị chặn bởi lịch sử tham chiếu cuốn không tồn tại; dữ liệu RAM không được tự sửa.

Thông báo không thể khôi phục thông tin cuốn đã mất; bản hiện tại không có chức năng xóa cuốn đang được lịch sử tham chiếu.

Không đổi nhánh owner<0 thành owner=0 để tiếp tục: đó là tự gán một lượt không có chủ cho đầu đầu tiên. Tổng lượt có thể trông đúng nhưng phân bố và top sai; bộ kiểm vẫn không có chứng cứ cuốn thật thuộc đầu nào. InTop kiểm mapping trước khi xuất tiêu đề nên lỗi ở pha gom không tạo bảng top dở.

**Đáp câu phụ 1:** Có thể tổng vẫn bằng số node vì mọi lượt đều được cộng, nhưng đầu 0 nhận lượt không thuộc nó. So cặp mã cuốn→ISBN chủ và vector số lượt từng ISBN, không chỉ tổng; với mã không tồn tại phải báo lỗi, không tự gán chủ.

**Sai lầm dễ mắc:** Báo cáo hết lỗi sau thêm bản ghi giả là phục hồi đúng.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Chỉ tạo lỗi trên bản sao độc lập; kiểm không có tiêu đề top hoàn chỉnh và file đích cũ không bị thay.

**Kiểm mới 18/10:** [original_top_missing](ThamKhao/KIEM_DINH_20261018.md#original_top_missing). Chỉ các assertion/quan sát nêu trong ca.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InTop10SachDuocMuonNhieuNhat`, dòng 172; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102.

<a id="TH22"></a>
### TH22 — Vì sao một vòng lịch sử không phải O(H)

**Thái · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH22).

**Trả lời ngắn:** Dựng/sắp chỉ mục tốn O(D+C log(C+1)); xử lý lịch sử O(H log(C+1)); lấy độc giả O(R); chọn top O(10D). Không sắp toàn bộ D đầu theo lượt. Các cận so chuỗi còn phụ thuộc độ dài khóa.

**Giải thích và bảo vệ cách làm:**

Các mảng index, dem và view dùng O(C+D+R) ô, top có 10 ô. Ngoài ra helper duyệt BST cấp stack MAX_DOC_GIA con trỏ; phải phân biệt dung lượng thực cấp theo giới hạn cấu hình với số ô đang dùng theo chiều cao cây.

Với C cố định, phần xử lý lịch sử tăng theo H. Bỏ chỉ mục tiết kiệm mảng O(C), nhưng mỗi lượt legacy có thể quét O(D+C), cộng thêm tìm chỉ số đầu; tổng có thể thành O(H(D+C)) ngoài các bước còn lại.

Quy mô nhỏ có thể chưa đáng chi phí dựng chỉ mục, nhưng không được suy ít mảng hơn là nhanh hơn. So chi phí dựng, số lần tra và bộ nhớ trên cùng dữ liệu.

**Đáp câu phụ 1:** Không; lịch sử tích lũy không bị chặn ở 3 mỗi người, chỉ lượt mở có cận đó.

**Sai lầm dễ mắc:** R nhỏ hoặc mỗi người giữ tối đa 3 làm tổng lịch sử nhỏ.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Đánh dấu vòng lặp và lời gọi lồng nhau; dùng bộ đếm so sánh trên bản sao thay vì suy chỉ từ thời gian chạy.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InTop10SachDuocMuonNhieuNhat`, dòng 172; [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `TimCuonSachToanCuc`, dòng 30, 51; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `LayDanhSachDocGia`, dòng 18.

<a id="TH27"></a>
### TH27 — Đổi tên khi cuốn đã có lịch sử

**Thái · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH27).

**Trả lời ngắn:** Tiêu chí đạt: đầu đổi tên về đúng vị trí trước Binh; thêm Dau so sau đó vẫn giữ tên tăng.

**Giải thích và bảo vệ cách làm:**

Mã/cuốn/lịch sử giữ nguyên; tìm tên mới và top hiển thị tên mới, số lượt không đổi.

Tên không hợp lệ hoặc lỗi chuẩn bị phải giữ dữ liệu cũ; chức năng này là bài mở rộng trên bản sao, không mặc định yêu cầu đề.

Chuẩn bị và kiểm tên mới trước; xác định vị trí mới trên thứ tự không chứa chính đầu đang sửa. Khi không còn bước cấp phát, đổi tên đã chuẩn bị rồi dịch các ô con trỏ trong đoạn giữa vị trí cũ và mới, đặt lại đúng một con trỏ đầu sách. Không xóa/tạo lại node hay sửa ISBN. Nếu lỗi ở pha chuẩn bị, chưa thay tên hay mảng; phải kiểm cả hòa tên bằng ISBN. Đây là thiết kế đề xuất, chưa được cài hay đo.

**Đáp câu phụ 1:** Không theo hợp đồng hiện tại; tên được trùng, ISBN phân biệt và là khóa phụ. Vẫn phải đặt đúng vị trí.

**Sai lầm dễ mắc:** Tên sách là định danh duy nhất.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Tự kiểm đổi đầu→cuối, cuối→đầu, tên trùng đầu khác, dữ liệu sai và đối chiếu địa chỉ cuốn trước/sau.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `TimViTriChenTheoTen`, dòng 43; [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `ThemDauSach`, dòng 64; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InTop10SachDuocMuonNhieuNhat`, dòng 172.

<a id="TH28"></a>
### TH28 — Báo cáo hôm qua sau khi trả hôm nay

**Thái · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH28).

**Trả lời ngắn:** Không tái dựng: phiếu hiện đã trả nên bị bỏ trước phép tính ngày, dù tại 15/10 An thực tế còn giữ.

**Giải thích và bảo vệ cách làm:**

Ngày tham số chỉ dùng tính chênh lệch trên các phiếu đang mở trong trạng thái hiện tại.

Muốn báo cáo tại một thời điểm quá khứ cần hợp đồng khác dựa khoảng mượn–trả; không được gọi bản hiện tại là lịch sử tại ngày.

**Đáp câu phụ 1:** Có; phiếu trước trả còn mở nên được xét. Cùng tham số ngày không khóa snapshot dữ liệu quá khứ.

**Sai lầm dễ mắc:** Một tham số ngày đủ tái dựng trạng thái đã bị cập nhật.

**Cách kiểm chứng:** Đề xuất kiểm chứng: So sánh báo cáo 15/10 trước và sau thao tác trả 16/10 trên hai trạng thái; ghi rõ sự khác biệt.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InDocGiaQuaHan`, dòng 148.

<a id="TH38"></a>
### TH38 — Tìm chỗ chèn đúng khi tên hòa và ở cuối mảng

**Thái · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH38).

**Trả lời ngắn:** Lower bound tìm vị trí đầu tiên không đứng trước phần tử mới theo tên rồi ISBN; miền vị trí là [0, soLuong], miền phần tử đọc là [0, soLuong). Hai đầu được thêm cuối theo thứ tự đã nêu.

**Giải thích và bảo vệ cách làm:**

Khi left<right, mid luôn nhỏ hơn right và soLuong; kết thúc ở soLuong chỉ biểu diễn chèn cuối. Vòng dịch lúc đó không chạy.

Bỏ ISBN khỏi comparator chèn có thể đảo các tên hòa, trái comparator kiểm file/ top. Cần dùng cùng quan hệ thứ tự, không sửa riêng một helper.

**Đáp câu phụ 1:** Nếu mid đứng trước, mọi phần tử tới mid đều đứng trước theo thứ tự toàn phần nên vị trí chèn không thể ở đó. Nhánh còn lại phải giữ mid vì nó có thể là vị trí đầu tiên không đứng trước. Khi hòa tên vẫn so ISBN; giữ mid ở nhánh trái không làm mất vị trí đầu nhóm thích hợp.

**Sai lầm dễ mắc:** Lẫn miền vị trí chèn với miền chỉ số phần tử hiện có.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Thêm cả đầu có ISBN nhỏ hơn giữa nhóm tên hòa; kiểm tính tăng và thử lưu, không chỉ nhìn tên.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `TimViTriChenTheoTen`, dòng 43; [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `SoSanhDauSach`, dòng 9; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `SachTruoc`, dòng 31.

<a id="TH39"></a>
### TH39 — Dịch mảng sai chiều làm mất con trỏ

**Thái · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH39).

**Trả lời ngắn:** Dịch tiến ghi đè con trỏ nguồn chưa dùng, có thể tạo nhiều ô cùng trỏ C và làm mất E.

**Giải thích và bảo vệ cách làm:**

Mất quyền truy cập E gây rò rỉ; nhiều ô sở hữu một đối tượng có thể gây xóa lặp. Vòng dịch hiện tại đi lùi để giữ nguồn.

**Đáp câu phụ 1:** Các cận bị tính trên số lượng chưa hợp lệ, có thể đọc/ghi ngoài vùng hoặc để metadata sai khi lỗi; phải giữ pha kiểm trước commit.

**Sai lầm dễ mắc:** Sửa một chiều vòng lặp tự sửa mọi bất biến của chèn.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Vẽ các địa chỉ khác nhau trước và sau từng phép gán; không chạy destructor trên dữ liệu hỏng ngoài môi trường kiểm thử cô lập.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `ThemDauSach`, dòng 64; [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `HuyDanhSachDauSach`, dòng 120.

<a id="TH40"></a>
### TH40 — Nhập danh mục từ công cụ khác: ai sở hữu các cuốn?

**Thái · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH40).

**Trả lời ngắn:** Hợp đồng hiện tại chỉ thêm thông tin đầu; hai cuốn vẫn thuộc phía tạo đối tượng tạm. ThemDauSach không nhận hay tự giải phóng chúng.

**Giải thích và bảo vệ cách làm:**

Copy struct có con trỏ dms chỉ copy địa chỉ, tạo hai nơi tưởng cùng sở hữu. Khi một bên dọn, bên còn lại có con trỏ treo.

Nhập nguyên cụm là thay đổi API: chọn clone sâu hoặc chuyển quyền rõ ràng, kiểm mã/trạng thái/quyền sở hữu và chuẩn bị toàn cụm trước commit nếu yêu cầu nguyên khối.

**Đáp câu phụ 1:** Bên tạo/chủ sở hữu ban đầu theo hợp đồng của nó; hàm không nhận quyền sở hữu trên đường từ chối.

**Sai lầm dễ mắc:** Hàm nhận tham số const reference phải tự xóa dữ liệu truyền vào khi lỗi.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Vẽ đồ thị sở hữu trước/sau lời gọi thất bại; thử nhập trên bản sao với cuốn thứ hai trùng mã và kiểm không mất cuốn cũ.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `ThemDauSach`, dòng 64; [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `ThemCuonSach`, dòng 74; [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — `DauSach`, dòng 15.

<a id="TH43"></a>
### TH43 — Tái dùng số của sách thanh lý có thật sự tiết kiệm?

**Thái · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH43).

**Trả lời ngắn:** Bản hiện tại xét mọi mã có tiền tố A và cấp A#10, không lọc theo trạng thái cuốn.

**Giải thích và bảo vệ cách làm:**

Mua bản thay thế là thêm cuốn mới; gán lại #9 khiến một mã biểu diễn hai vật thể và phá quy tắc lượt mất kết thúc chuỗi cuốn. Đếm số nút cũng không bảo đảm không va chạm.

Lượt cũ vẫn thuộc đầu A nên top giữ được số lượt dù thêm A#10; không cần tái dùng định danh để nối thống kê.

**Đáp câu phụ 1:** Không; thêm cuốn chưa tạo lượt mượn. Chỉ giao dịch mượn thành công thêm lịch sử mới.

**Sai lầm dễ mắc:** Số bản mua mới là số lượt thống kê.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Lưu rồi nạp bộ có lượt mất, thêm cuốn và xác nhận A#9/lịch sử cũ còn nguyên, A#10 có trạng thái sẵn sàng.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `SinhMaSachTuDong`, dòng 59; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InTop10SachDuocMuonNhieuNhat`, dòng 172; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102.

<a id="TH48"></a>
### TH48 — Mã xem trước đã hiện nhưng đầu sách chưa được tạo

**Thái · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH48).

**Trả lời ngắn:** Helper tính ứng viên từ ISBN truyền vào và các mã đang có; không chứng minh đối tượng tạm đã thuộc kho, không giữ chỗ và không tạo cuốn.

**Giải thích và bảo vệ cách làm:**

Nếu đầu chưa được commit, việc hiển thị ứng viên không phải thành công nhập sách. ThemCuonSach tìm đầu thật, kiểm hạn mức, cấp phát rồi mới nối nút.

Giao diện xem trước cần nhãn dự kiến và kiểm lại khi thêm; không dùng preview làm nguồn cấp mã độc lập với nghiệp vụ.

**Đáp câu phụ 1:** Có; helper không giữ chỗ hoặc tăng bộ đếm bền. Chỉ thêm thành công mới thay tập mã được xét.

**Sai lầm dễ mắc:** Mỗi lần nhìn thấy mã là đã tiêu thụ một mã.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Trên bản sao tạo đầu tạm chưa nối, gọi helper rồi kiểm soLuong/cuốn không tăng; sau đó gọi thêm với đầu thật.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `SinhMaSachTuDong`, dòng 59; [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `ThemCuonSach`, dòng 74; [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `ThemDauSach`, dòng 64.

<a id="TH53"></a>
### TH53 — Tìm chuỗi con có dùng được khoảng nhị phân của tên?

**Thái · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH53).

**Trả lời ngắn:** Tìm 'an toan' phải nhận An toan và Lap trinh an toan; điểm không khớp giữa chúng không kết thúc tập kết quả.

**Giải thích và bảo vệ cách làm:**

Thứ tự tên không gom mọi vị trí chứa chuỗi con thành một khoảng. Lower bound của đầu sách không trực tiếp tăng tốc truy vấn chứa ở bất kỳ vị trí.

Tên chính xác hoặc tiền tố theo cùng khóa chuẩn hóa có thể tìm vùng ứng viên phù hợp; vẫn cần kiểm biên và không tự thay nghĩa truy vấn hiện tại.

**Đáp câu phụ 1:** Không; ChuaChuoi là predicate và caller tăng một lần cho đầu khớp, không đếm vị trí khớp.

**Sai lầm dễ mắc:** Tìm substring là liệt kê mọi vị trí khớp hoặc cho phép dừng ở khoảng trống.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Dùng kết quả quét đầy đủ làm đối chiếu độc lập cho đề xuất; kiểm từ khóa xuất hiện đầu, giữa, cuối tên.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `TimDauSachTheoTen`, dòng 84; [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `TimViTriChenTheoTen`, dòng 43; [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `ChuaChuoi`, dòng 31.

<a id="TH54"></a>
### TH54 — Một kết quả tìm kiếm đại diện đầu sách hay bản vật lý?

**Thái · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH54).

**Trả lời ngắn:** n tăng một lần cho mỗi đầu khớp: hai đầu, không phụ thuộc số lần từ khóa xuất hiện hay số cuốn.

**Giải thích và bảo vệ cách làm:**

Muốn số cuốn sẵn sàng cần bộ đếm tạm riêng khi duyệt dms; đầu không có cuốn vẫn là một kết quả tên. Số khả dụng danh mục chưa chứng minh độc giả cụ thể đủ quyền mượn.

Không dùng số dòng văn bản hoặc số lần khớp ký tự làm tổng nghiệp vụ; lớp mượn vẫn phải kiểm lại đầy đủ.

**Đáp câu phụ 1:** Không; số sẵn sàng là thuộc tính danh mục, còn quyền phụ thuộc thẻ/hạn mức/quá hạn/timeline của người.

**Sai lầm dễ mắc:** Đếm khả dụng vật lý bằng số giao dịch có thể được phép.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Tạo hai đầu như đề, đối chiếu ba số: đầu khớp, tổng bản vật lý và bản sẵn sàng; không suy chúng từ nhau.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `TimDauSachTheoTen`, dòng 84; [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `InMotDauSach`, dòng 14; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114.

<a id="TH55"></a>
### TH55 — Dán tên từ tài liệu: tìm thấy không có nghĩa dữ liệu được nhận

**Thái · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH55).

**Trả lời ngắn:** Tìm kiếm chuẩn hóa khoảng trắng của khóa nên tab có thể thành dấu cách. Thêm dữ liệu gọi validator gốc trước chuẩn hóa, tab là ký tự điều khiển bị cấm.

**Giải thích và bảo vệ cách làm:**

Khóa truy vấn tạm và văn bản sẽ lưu có hợp đồng khác nhau; không phải mọi chuỗi tìm được đều là đầu vào hợp lệ để ghi.

Bỏ kiểm gốc thay đổi chính sách chấp nhận dữ liệu, có thể che newline/tab trong dữ liệu nhập. Muốn thống nhất cần quyết định quy tắc và kiểm cả API /file/ UI, không vá riêng tìm kiếm.

**Đáp câu phụ 1:** Không theo validator hiện tại; cần kiểm raw trước, nếu đổi chính sách phải thay nhất quán và xác nhận phạm vi.

**Sai lầm dễ mắc:** Chuẩn hóa xóa được dấu hiệu sai thì đầu vào ban đầu hợp lệ.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Dùng cùng chuỗi chứa tab gọi tìm và thêm trên bản sao; xác nhận tìm không đổi kho, thêm lỗi không tăng soLuong.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `ChuaChuoi`, dòng 31; [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `HopLeVanBan`, dòng 42; [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `ThemDauSach`, dòng 64.

<a id="TH57"></a>
### TH57 — Sửa một cận tìm kiếm làm mất cả nhóm tài liệu

**Thái · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH57).

**Trả lời ngắn:** Vị trí cuối hợp lệ là a.size()−b.size(); dùng < bỏ nó. Khi hai độ dài bằng nhau, vị trí 0 duy nhất cũng bị bỏ.

**Giải thích và bảo vệ cách làm:**

Cận <= chỉ an toàn sau khi đã chặn từ khóa dài hơn tên; bỏ chặn lại gây trừ size_t âm theo nghĩa toán học thành số rất lớn.

Tối ưu phải giữ tập vị trí ứng viên hoặc chứng minh bước nhảy hợp lệ; không lấy bớt vị trí để tuyên bố nhanh hơn.

**Đáp câu phụ 1:** Trước; tránh phép trừ unsigned cuộn thành số lớn. Sau đó mới dùng cận vị trí cuối.

**Sai lầm dễ mắc:** Có kiểm vòng lặp thì phép trừ size_t luôn an toàn.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Đối chiếu cuối tên, nguyên tên, giữa tên, dài hơn tên và rỗng; tự viết expected từ chuỗi, không gọi lại helper làm oracle.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `ChuaChuoi`, dòng 31.

<a id="TH62"></a>
### TH62 — Đồng mức quá hạn nhưng số cuốn khác: công bằng theo quy tắc nào?

**Thái · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH62).

**Trả lời ngắn:** Code xếp max ngày giảm rồi mã tăng, nên B trước A cả trước/sau khi A trả hai cuốn nếu vẫn còn một cuốn điểm 2.

**Giải thích và bảo vệ cách làm:**

Thêm số cuốn làm khóa phụ chỉ ảnh hưởng khi max hòa; đổi sang tổng có thể đổi thứ tự cả khi max khác. Ví dụ max 5 với một cuốn so với ba cuốn mỗi cuốn 2: max ưu tiên 5, tổng ưu tiên 6.

Đây là thay đổi quy tắc cần xác nhận, không kết luận code sai từ cảm giác công bằng; phải đổi comparator /nhãn/ test tương ứng.

Khi đổi sang tổng, chỉ cộng ngày vượt bảy dương của lượt đang mở; thử người có một cuốn nặng và nhiều cuốn nhẹ để phân biệt với max. Chặn mượn vẫn là tồn tại ít nhất một cuốn quá hạn, không dựa thứ hạng hoặc điểm thống kê.

**Đáp câu phụ 1:** Người đọc có thể tưởng mã vẫn phá hòa ngay sau max. Thuật toán, nhãn, đặc tả và test phải phản ánh cùng quy tắc.

**Sai lầm dễ mắc:** Đổi comparator chỉ ảnh hưởng nội bộ, không đổi ý nghĩa kết quả.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Lập bảng expected cho hai bộ quy tắc bằng tay, giữ nguyên phép chặn mượn để thấy nó không phụ thuộc xếp hạng.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InDocGiaQuaHan`, dòng 148; [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `CoSachQuaHan7Ngay`, dòng 9.

<a id="TH63"></a>
### TH63 — Ẩn thẻ khóa có che nghĩa vụ trả sách còn lại?

**Thái · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH63).

**Trả lời ngắn:** i vẫn cần A vì Y còn quá hạn; h hiện Y, Z; X là lượt mất không còn đang mượn. Khóa thẻ không xóa các khoản đang giữ.

**Giải thích và bảo vệ cách làm:**

A được trả Y/Z nếu ngày/liên kết hợp lệ, nhưng mượn mới vẫn bị khóa chặn. View chỉ thẻ hoạt động đã loại mất dữ liệu cần báo cáo.

Muốn dùng chung helper nên tách tập đầy đủ và điều kiện lọc của từng chức năng; không coi một view phục vụ UI là toàn bộ kho độc giả.

**Đáp câu phụ 1:** Không; kiểm phải thấy mọi người/lịch sử, kể cả thẻ khóa. View lọc theo mục đích không là tập nguồn đầy đủ.

**Sai lầm dễ mắc:** View dùng tốt cho một màn hình dùng được cho mọi nghiệp vụ.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Chạy báo mất, i, h, trả Y rồi i lần nữa; so trạng thái thẻ vẫn khóa và nghĩa vụ Z còn nguyên.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InDocGiaQuaHan`, dòng 148; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KetThucMuon`, dòng 54; [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `LietKeSachDangMuon`, dòng 21.

<a id="TH72"></a>
### TH72 — Dọn độc giả cũ có thể làm thống kê giảm mà kho không đổi

**Thái · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH72).

**Trả lời ngắn:** Xóa A được, xóa B bị chặn vì có lịch sử bất kỳ. Theo đường hiện tại top không giảm do hai yêu cầu này.

**Giải thích và bảo vệ cách làm:**

Lịch sử nằm trong độc giả và là nguồn đếm top; xóa người có lượt trả sẽ xóa hoặc làm mất nguồn thống kê dù cuốn vẫn còn.

Có thể khóa thẻ để ngừng cho mượn, giữ hồ sơ và lịch sử. Xóa/ẩn lưu trữ là yêu cầu khác cần chốt, không tự chuyển sang kho ngoài cấu trúc đề.

**Đáp câu phụ 1:** Không; khóa giữ nguyên lịch sử. Chỉ đổi quyền mượn mới, không xóa nguồn thống kê.

**Sai lầm dễ mắc:** Khóa, ẩn và xóa hồ sơ là cùng một thao tác.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Đối chiếu tổng lịch sử và top khi xóa A; trên bản sao thiết kế phản ví dụ cho chính sách xóa B mà chưa thực hiện trên dữ liệu thật.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `XoaDocGia`, dòng 85; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `HieuChinhDocGia`, dòng 73; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InTop10SachDuocMuonNhieuNhat`, dòng 172.

<a id="TH74"></a>
### TH74 — Đổi kiểu so ISBN chỉ ở top phá hợp đồng hòa thế nào?

**Thái · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH74).

**Trả lời ngắn:** Bản hiện tại so chuỗi chính xác nên '10' trước '2'; với tên hòa, '02' có thứ tự riêng. Mã 'AB' hợp lệ nhưng không chuyển số được.

**Giải thích và bảo vệ cách làm:**

So số làm '02' và '2' hòa dù là hai đầu khác nhau; cần quy tắc tổng thể và khóa phụ duy nhất nếu thay đặc tả. Không sửa một comparator tùy dữ liệu.

Với bộ khóa lượt–tên– ISBN hiện tại và ISBN duy nhất, thứ tự xác định không dựa vào stable sort; lưu–nạp không đổi kết quả.

**Đáp câu phụ 1:** Có, vì các đầu hòa đã có thứ tự ISBN từ đầu vào và sort ổn định bảo toàn thứ tự đó; loader cũng dựng lại mảng chuẩn. Không được nói mọi cách bỏ ISBN đều làm kết quả bất định. Nếu đổi sang view đầu vào khác thứ tự hoặc thuật toán không ổn định, bảo đảm này mất; giữ khóa ISBN tường minh giảm phụ thuộc vào tiền điều kiện ẩn.

**Sai lầm dễ mắc:** Stable sort tự tạo khóa phá hòa còn thiếu.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Lập expected cho cả mã chữ/số/0 đầu; kiểm cặp comparator hai chiều và top ở ngưỡng 10.

**Ca liên quan đã chạy 17/10 (không tái chạy đợt này):** [top_twelve_ties](ThamKhao/KIEM_CHUNG_RUNTIME.md#top_twelve_ties).

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `DauSachXepTruoc`, dòng 107; [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `SoSanhDauSach`, dòng 9; [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `HopLeDauSach`, dòng 27.

<a id="TH93"></a>
### TH93 — Nạp file đầu sách lộn thứ tự

**Thái · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH93).

**Trả lời ngắn:** DocNoiBo sắp mảng tạm bằng SachTruoc trước kiểm toàn vẹn, nên file lộn thứ tự có thể nạp thành A,M,Z.

**Giải thích và bảo vệ cách làm:**

KiemTraToanVen trên RAM lộn thứ tự thì từ chối; nó kiểm chứ không tự sắp đối tượng đầu vào.

--check nạp vào đối tượng cục bộ và in kết quả kiểm, không gọi LuuFile. Sắp biểu diễn tạm không đồng nghĩa sửa file trên đĩa; có thể so byte/hash file trước và sau.

**Đáp câu phụ 1:** Không; --check không ghi lại file, chỉ bộ tạm trong RAM được sắp và kiểm.

**Sai lầm dễ mắc:** Kiểm file hợp lệ đồng nghĩa canonical hóa và ghi lại file.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Nạp bản file lộn thứ tự rồi in; so kiểm RAM bị đổi thứ tự trên bản sao.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `DocNoiBo`, dòng 222; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507.

<a id="TH97"></a>
### TH97 — Tìm thấy tên nhưng cả hai người đều chưa chắc mượn được

**Thái · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH97).

**Trả lời ngắn:** Tìm tên hiện đủ trạng thái ba cuốn. An bị quá hạn chặn và không giữ chỗ A#2; Bình mượn được nếu ngày hợp lệ.

**Giải thích và bảo vệ cách làm:**

Kết quả danh mục trả lời tồn tại/trạng thái, nghiệp vụ kiểm độc giả và liên kết tại thời điểm gọi. Không dùng việc được hiển thị làm bằng chứng cho phép.

Ẩn cuốn bận/thanh lý có thể hợp một bộ lọc, nhưng làm mất thông tin kiểm kê/tra cứu nếu thay luôn chế độ đầy đủ; nên nêu rõ mục đích lọc.

**Đáp câu phụ 1:** Không; chưa có node mới hay thay trạng thái; Bình có thể mượn theo lượt xử lý kế tiếp.

**Sai lầm dễ mắc:** Bị từ chối nhưng đã xem kết quả tìm vẫn tạo quyền ưu tiên.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Theo dõi phiếu An/Bình và trạng thái A#2 sau từng lệnh, kiểm tìm không tạo giao dịch.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `TimDauSachTheoTen`, dòng 84; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114.

<a id="TH202"></a>
### TH202 — Hai sách khác nội dung nhưng cùng tên

**Thái · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH202).

**Trả lời ngắn:** Tên trùng được phép; ISBN mới là định danh duy nhất của đầu sách.

**Giải thích và bảo vệ cách làm:**

Kiểm trùng dùng TimDauSachTheoISBN. Bộ so phá hòa bằng ISBN nên mảng vẫn có thứ tự. Tìm tên in riêng thông tin và danh mục từng đầu; chọn mã cuốn cụ thể để nối lịch sử.

**Đáp câu phụ 1:** Không. Code không có quy tắc suy đồng nhất theo các trường mô tả. Gộp phải có xác nhận danh tính và chuyển mọi tham chiếu, hiện chưa có chức năng đó.

**Sai lầm dễ mắc:** Tương đương khóa tên bị coi là trùng bản ghi.

**Cách kiểm chứng:** Đề xuất: thêm A/B cùng tên, tìm tên phải ra 2 đầu; mượn B#1 rồi top chỉ cộng B.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `ThemDauSach`, dòng 64; [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `TimDauSachTheoTen`, dòng 84.

<a id="TH203"></a>
### TH203 — Chèn đầu mới khi mã sách đang được tra theo chỉ số phụ

**Thái · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH203).

**Trả lời ngắn:** Chỉ số gốc của nhiều đầu đổi; con trỏ đến các đầu còn sống không đổi do riêng phép chèn.

**Giải thích và bảo vệ cách làm:**

Cả hai vẫn phải thêm mục phụ đúng thứ tự và giữ đồng bộ khi nạp. Bản con trỏ tránh cập nhật hàng loạt chỉ số gốc nhưng phát sinh vòng đời và bộ nhớ O(D); cần giảng viên cho phép chỉ mục hỗ trợ.

**Đáp câu phụ 1:** Không. Mảng gốc và mảng chỉ mục vẫn có thể dịch O(D) phần tử. Tối ưu đường đọc không xóa chi phí cập nhật.

**Sai lầm dễ mắc:** Chỉ mục phụ được trình bày như đã tồn tại trong sản phẩm.

**Cách kiểm chứng:** Đề xuất: thêm đầu đầu/giữa/cuối rồi tra mọi ISBN; nạp thư viện khác phải bỏ toàn bộ chỉ mục cũ.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `TimDauSachTheoISBN`, dòng 54; [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `ThemDauSach`, dòng 64.

<a id="TH204"></a>
### TH204 — So sánh sau khi đã chuẩn bị có thể vẫn cấp phát

**Thái · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH204).

**Trả lời ngắn:** Ở code hiện tại chưa dịch mảng, node tạm còn được unique_ptr quản lý nên dữ liệu gốc giữ nguyên.

**Giải thích và bảo vệ cách làm:**

SoSanhChuoi tạo hai string khóa, có thể cấp phát. TimViTriChenTheoTen hoàn thành trước vòng dịch. Nếu trộn phép so có thể ném vào pha đã ghi con trỏ thì cần cơ chế hoàn tác khác.

**Đáp câu phụ 1:** Không; nó mô tả đoạn commit trong hàm. Caller vẫn có thể cấp phát khi dựng thông báo sau khi thêm đã thành công.

**Sai lầm dễ mắc:** So chuỗi được mặc định là phép toán không ném ngoại lệ.

**Cách kiểm chứng:** Truy vết: đánh dấu mọi lời gọi tạo string trước dòng 78; nếu tiêm lỗi thì thử tại comparator, kiểm soLuong và dãy địa chỉ không đổi.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `ThemDauSach`, dòng 64; [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `TimViTriChenTheoTen`, dòng 43; [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `SoSanhChuoi`, dòng 27.

<a id="TH205"></a>
### TH205 — Chuẩn hóa từ khóa một lần hay một lần mỗi đầu

**Thái · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH205).

**Trả lời ngắn:** Có thể tạo khóa truy vấn một lần cho cả lần tìm; hiện ChuaChuoi chuẩn hóa lại nó D lần.

**Giải thích và bảo vệ cách làm:**

Tách helper so các khóa đã chuẩn hóa giúp tránh O(DM) công việc lặp, nhưng vòng khớp vẫn có cận O(DLM). Cache khóa tên còn cần đồng bộ khi thêm/nạp và bộ nhớ O(DL), không tự được phép thêm vào cấu trúc.

**Đáp câu phụ 1:** Không; phần tiết kiệm nhỏ và chi phí xuất có thể chiếm ưu thế. Cần so dữ liệu nhiều đầu và truy vấn dài trên cùng ngữ nghĩa.

**Sai lầm dễ mắc:** Chuẩn hóa một lần được gọi là biến tìm kiếm thành tuyến tính.

**Cách kiểm chứng:** Đề xuất: đếm số lần KhoaSoSanh cho part trước/sau, đối chiếu tập ISBN với quét cũ cho dấu cách/ASCII và khớp cuối tên.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `TimDauSachTheoTen`, dòng 84; [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `ChuaChuoi`, dòng 31.

<a id="TH206"></a>
### TH206 — In lại báo cáo khi stream đã báo lỗi

**Thái · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH206).

**Trả lời ngắn:** Hàm trả void và không kiểm trạng thái stream; n chỉ đếm đầu khớp, không xác nhận dữ liệu đã tới người nhận.

**Giải thích và bảo vệ cách làm:**

Stream mặc định có thể giữ lỗi mà không ném. Caller phải kiểm stream hoặc dùng hợp đồng xuất có kết quả rõ; việc đọc kho vẫn không sửa nghiệp vụ.

**Đáp câu phụ 1:** Không. Nó báo lỗi sớm hơn nhưng phần đã xuất trước lỗi vẫn có thể tồn tại; muốn nguyên khối cần chuẩn bị kết quả và giao nhận theo hợp đồng riêng.

**Sai lầm dễ mắc:** Không có exception nghĩa là báo cáo đã xuất thành công.

**Cách kiểm chứng:** Đề xuất: ostream lỗi sẵn và stream lỗi giữa chừng trên harness, kiểm trạng thái stream và kho; không coi đây là lỗi console đã xảy ra.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `TimDauSachTheoTen`, dòng 84; [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `InMotDauSach`, dòng 14.

<a id="TH207"></a>
### TH207 — Tìm tên trên kho lớn với rất ít kết quả

**Thái · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH207).

**Trả lời ngắn:** Một đầu khớp vẫn có thể tạo 150.000 dòng cuốn; số đầu kết quả không đo kích thước báo cáo.

**Giải thích và bảo vệ cách làm:**

Hàm quét D tên rồi InMotDauSach duyệt toàn dms của từng đầu khớp. Gọi từ màn hình còn dựng ostringstream trước phân trang; độ dài mã/vị trí góp vào số byte đầu ra.

**Đáp câu phụ 1:** Không. Muốn trang đầu sớm phải đổi cách cung cấp dữ liệu chi tiết và giữ thứ tự/snapshot; hiện vẫn dựng toàn văn.

**Sai lầm dễ mắc:** Đánh giá tìm kiếm chỉ bằng số đầu khớp.

**Cách kiểm chứng:** Phân tích theo C_khớp và số byte B; thử tải giới hạn nhỏ hơn để kiểm số dòng, không gọi số liệu giả định là benchmark.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `TimDauSachTheoTen`, dòng 84; [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `InMotDauSach`, dòng 14.

<a id="TH208"></a>
### TH208 — Danh mục không được sắp theo mã nhưng tìm trong đầu vẫn đúng

**Thái · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH208).

**Trả lời ngắn:** Tra tuyến tính vẫn đúng; cuốn mới A#11 được nối cuối, không cần danh sách tăng mã.

**Giải thích và bảo vệ cách làm:**

Loader giữ thứ tự cuốn từ file. Dừng theo lớn/nhỏ chỉ đúng khi đã bảo đảm cùng thứ tự so; danh sách hiện tại không có bất biến đó. Max hậu tố được tìm bằng quét, không lấy nút cuối.

**Đáp câu phụ 1:** Không có truy cập giữa O(1); việc đi tới các nút giữa vẫn tốn duyệt. Chỉ đếm số phép so không đủ tính thời gian.

**Sai lầm dễ mắc:** Mọi cấu trúc đã sắp đều hỗ trợ nhị phân nhanh như mảng.

**Cách kiểm chứng:** Đề xuất: nạp thứ tự trên, tra đủ ba mã và thêm; kiểm thứ tự cũ được giữ, mã mới đúng.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `TimCuonSachTrongDauSach`, dòng 21, 25; [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `ThemCuonSach`, dòng 74; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `DocNoiBo`, dòng 222.

<a id="TH209"></a>
### TH209 — Số cuốn trong dòng đầu sách lệch một đơn vị

**Thái · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH209).

**Trả lời ngắn:** Loader đang chờ bản ghi cuốn 3 trường nên từ chối dòng 7 trường; chưa swap dữ liệu.

**Giải thích và bảo vệ cách làm:**

Số đếm điều khiển ranh giới bản ghi. Tự đoán lại sẽ khiến cú pháp và quan hệ các phần mất đáng tin, đặc biệt nếu dòng sai tình cờ có đúng số trường. Cần sửa file theo nguồn xác nhận.

**Đáp câu phụ 1:** Chưa; phải qua kiểm trạng thái, mã, chủ sở hữu và liên kết sau đọc. Đúng số trường chỉ là một tầng kiểm.

**Sai lầm dễ mắc:** Chỉ cần mọi dòng parse được là toàn bộ file đúng cấu trúc.

**Cách kiểm chứng:** Đề xuất: nạp file sai số cuốn vào phiên có dữ liệu A0, kiểm lỗi và nội dung A0 giữ nguyên; đối chiếu file đếm đúng.

**Ca liên quan đã chạy 17/10 (không tái chạy đợt này):** [load_failure_keeps_ram](ThamKhao/KIEM_CHUNG_RUNTIME.md#load_failure_keeps_ram).

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `DocNoiBo`, dòng 222; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `BoDoc`, dòng 63.

<a id="TH210"></a>
### TH210 — Bỏ một cuốn không có lịch sử khi ghi vẫn đọc lại được

**Thái · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH210).

**Trả lời ngắn:** Không nhất thiết; file bị mất cuốn vẫn có thể tự nhất quán và đọc hợp lệ.

**Giải thích và bảo vệ cách làm:**

Đọc lại kiểm cú pháp/bất biến của bản đã ghi, không so toàn bộ nội dung với RAM nguồn. Cần phép so round-trip theo ISBN, mã cuốn, vị trí, trạng thái và lịch sử, không chỉ kiểm return true.

**Đáp câu phụ 1:** Khi lịch sử vẫn được ghi, kiểm tham chiếu sẽ bắt mã cuốn thiếu. Độ phủ này không chứng minh bắt được cuốn không tham chiếu.

**Sai lầm dễ mắc:** Đọc lại thành công được coi là chứng minh serialization không mất trường/bản ghi.

**Cách kiểm chứng:** Đề xuất: fixture có một cuốn rảnh không lịch sử ở cuối; mutation bỏ cuốn phải bị phép so nội dung bắt dù --check có thể chấp nhận.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `Ghi`, dòng 273; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `LuuNoiBo`, dòng 290.

<a id="TH211"></a>
### TH211 — Bỏ một lượt cũ: top giảm nhưng kiểm liên kết vẫn xanh

**Thái · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH211).

**Trả lời ngắn:** Top đang phản ánh đúng số node còn trong file; validator không biết lượt đã biến mất nếu dữ liệu còn lại vẫn nhất quán.

**Giải thích và bảo vệ cách làm:**

Cần đối chiếu với bản nguồn/backup hoặc nhật ký được thiết kế riêng. Code hiện không có tổng kiểm độc lập hoặc audit để chứng minh đủ lịch sử; không bịa thêm lượt chỉ từ kỳ vọng.

**Đáp câu phụ 1:** Không; checksum chỉ xác định nội dung đó. So với hash bản gốc đáng tin có thể phát hiện đổi byte nhưng không tự giải thích lượt nào mất.

**Sai lầm dễ mắc:** Mọi khác biệt thống kê đều quy cho thuật toán đếm.

**Cách kiểm chứng:** Đề xuất: so hai fixture 5/4 lượt hợp lệ, top tương ứng; dùng so bản ghi để chỉ đúng lượt thiếu.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InTop10SachDuocMuonNhieuNhat`, dòng 172; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102.

<a id="TH212"></a>
### TH212 — Top của hai nửa kho có ghép được không

**Thái · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH212).

**Trả lời ngắn:** Đúng khi mỗi đầu thuộc đúng một nửa, điểm đã là tổng đầy đủ và mọi bước dùng cùng thứ tự lượt–tên–ISBN.

**Giải thích và bảo vệ cách làm:**

Một đầu bị loại khỏi top 10 nửa mình đã có ít nhất 10 đầu đứng trước nó trong toàn bộ tập, nên không thể lọt top 10 toàn cục. Đây là tối ưu pha chọn, không giảm quét lịch sử.

**Đáp câu phụ 1:** Không: điểm của cùng một đầu bị chia nhỏ. Một đầu đứng thứ 11 ở cả hai nửa có thể có tổng lớn nhất sau cộng; phải hợp nhất điểm theo ISBN trước chọn.

**Sai lầm dễ mắc:** Ghép top cục bộ luôn đúng dù chia dữ liệu theo chiều nào.

**Cách kiểm chứng:** Đề xuất: tạo phản ví dụ một đầu có điểm vừa ở hai nhóm độc giả, các đầu cạnh tranh chỉ xuất hiện một nhóm; so tổng tay.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InTop10SachDuocMuonNhieuNhat`, dòng 172; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `DauSachXepTruoc`, dòng 107.

<a id="TH213"></a>
### TH213 — Tìm hai từ độc lập khác tìm cả cụm

**Thái · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH213).

**Trả lời ngắn:** AND hai phép chứa cho hai tên đầu; tìm cả cụm chỉ khớp tên đầu; OR còn nhận lap rap.

**Giải thích và bảo vệ cách làm:**

Phải chốt query là cụm hay các token. Tách token rồi chuẩn hóa/kiểm rỗng, AND có thể dừng khi một token không khớp; OR dừng khi một token khớp. Không thêm một đầu nhiều lần chỉ vì khớp nhiều token. Chi phí theo số token, D và độ dài; có thể chuẩn hóa tên một lần trên mỗi đầu.

**Đáp câu phụ 1:** Không; kết quả vẫn là tập đầu khớp. Có thể loại token trùng để giảm kiểm nhưng không đổi thứ tự kết quả.

**Sai lầm dễ mắc:** Nối các từ bằng dấu cách luôn tương đương yêu cầu chứa tất cả từ.

**Cách kiểm chứng:** Đề xuất ba tên trên và query token rỗng/trùng; so tập ISBN theo từng đặc tả, chưa cài tìm nhiều từ.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `ChuaChuoi`, dòng 31; [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `TimDauSachTheoTen`, dòng 84.

<a id="TH214"></a>
### TH214 — Một đầu cực nhiều cuốn và nhiều đầu ít cuốn

**Thái · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH214).

**Trả lời ngắn:** Không; đường mã chuẩn phụ thuộc Cᵢ của đầu được tra và vị trí cuốn trong danh sách.

**Giải thích và bảo vệ cách làm:**

Tìm ISBN vẫn quét tối đa D, sau đó tìm trong riêng dms. Phân bố truy vấn và số cuốn mỗi đầu quyết định chi phí thực; cận xấu nhất dùng đầu lớn nhất. Đây là phân tích, chưa đo.

**Đáp câu phụ 1:** Mã legacy không cho biết chủ, có thể quét qua nhiều đầu và cuốn; vị trí đầu/cuốn trong kho lại ảnh hưởng số bước.

**Sai lầm dễ mắc:** Một con số C tổng được dùng cho mọi phân bố và tỉ lệ truy vấn.

**Cách kiểm chứng:** Đề xuất: bộ đếm node trên hai kho tổng hợp nhỏ cùng D/C, thay tỉ lệ truy vấn và chọn cuốn đầu/cuối.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `TimCuonSachToanCuc`, dòng 30, 51.

<a id="TH215"></a>
### TH215 — Mã chuẩn không làm lịch sử cũ tự đổi mã

**Thái · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH215).

**Trả lời ngắn:** Sửa riêng danh mục làm lịch sử mồ côi; đây phải là di trú định danh có phát hiện va chạm.

**Giải thích và bảo vệ cách làm:**

Bản hiện không có đổi mã. Thiết kế khả thi dùng bộ tạm, ánh xạ một-một mã cũ→mới, cập nhật tất cả tham chiếu rồi kiểm toàn vẹn và đối chiếu tổng lượt trước khi thay. Mã đích trùng phải từ chối hoặc chọn quy tắc mới được duyệt.

**Đáp câu phụ 1:** Không: tên có thể trùng và không xác định cuốn vật lý. Ánh xạ phải dựa danh tính đáng tin, không đoán từ tên.

**Sai lầm dễ mắc:** Đổi tem được coi là thay văn bản hiển thị thuần túy.

**Cách kiểm chứng:** Đề xuất: một mã cũ nhiều người từng mượn, một đích trùng; thử chuyển thành công/thất bại trên bản sao và so top/h.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `TimCuonSachToanCuc`, dòng 30, 51; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102.

<a id="TH216"></a>
### TH216 — Dòng quá hạn của người trước lọt sang người sau

**Thái · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH216).

**Trả lời ngắn:** row.soNgay và row.soCuon của mã 10 có thể bị mang sang mã 20, làm người chưa quá hạn xuất hiện với số liệu cũ.

**Giải thích và bảo vệ cách làm:**

Trong code đúng, mỗi độc giả nhận DongQuaHan mới với hai số bằng 0. Mảng đích chỉ nhận bản sao row, không tự biết số nào cần reset. Tối ưu tuổi thọ biến phải giữ phạm vi của phép tích lũy.

**Đáp câu phụ 1:** Duyệt ngược có thể đổi người bị nhận dữ liệu dư; đó là đổi thuật toán duyệt, không sửa lỗi reset. Thay hình BST vẫn giữ inorder mã tăng nên không tự đảo 10 và 20. Phải khởi tạo tích lũy riêng cho từng người và kiểm bằng dãy người có số liệu đối lập.

**Sai lầm dễ mắc:** Khởi tạo mảng kết quả được coi là đủ cho mọi bộ tích lũy trung gian.

**Cách kiểm chứng:** Đề xuất: người quá hạn→không quá hạn→quá hạn nhẹ; đổi hình BST và kiểm đúng tập mã cùng max/count.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InDocGiaQuaHan`, dòng 148.

<a id="TH217"></a>
### TH217 — Báo cáo ngày tương lai và giao dịch ngày tương lai

**Thái · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH217).

**Trả lời ngắn:** API báo cáo chỉ kiểm ngày hợp lệ nên có thể tính quá hạn 1 ngày; giao dịch và --date đều chặn tương lai.

**Giải thích và bảo vệ cách làm:**

Kết quả báo cáo trực tiếp là phép tính trên các lượt hiện đang mở, giả sử chưa trả đến ngày xét. Nó không dự báo chắc ai còn giữ vào ngày mai và không cấp quyền nhập giao dịch tương lai.

**Đáp câu phụ 1:** Không, nhánh NgayHopLe trả thông báo rồi dừng trước khi tạo view và quét lịch sử.

**Sai lầm dễ mắc:** Mọi hàm nhận NgayThang được giả định có cùng chính sách thời gian.

**Cách kiểm chứng:** Đề xuất: gọi API báo cáo/nghiệp vụ trên cùng fixture và ngày máy xác định; ghi rõ CLI không cho nhập ngày tương lai.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InDocGiaQuaHan`, dòng 148; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KiemTraNgayGiaoDich`, dòng 17; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507.

<a id="TH218"></a>
### TH218 — Tên khóa so sánh dài chung một tiền tố

**Thái · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH218).

**Trả lời ngắn:** O(10D) là số lần so khóa ở pha chọn, không phải số thao tác ký tự hay cấp phát.

**Giải thích và bảo vệ cách làm:**

Khi lượt hòa, SoSanhChuoi chuẩn hóa và tạo khóa cho cả hai tên; so tiền tố chung phải đọc nhiều byte, rồi có thể so ISBN. Cận phải thêm L, cùng chi phí dựng chỉ mục và quét lịch sử.

**Đáp câu phụ 1:** Nó giảm tạo khóa lặp nhưng so hai chuỗi có tiền tố dài vẫn phụ thuộc L; đổi cấu trúc khóa cần cân đối bộ nhớ và quyền sở hữu.

**Sai lầm dễ mắc:** Mỗi phép so string được tính như một lệnh O(1) ở mọi phân tích.

**Cách kiểm chứng:** Đề xuất: đếm số lần chuẩn hóa và byte so trên dữ liệu tiền tố dài/ngắn cùng D/H; chưa có số đo thời gian.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `DauSachXepTruoc`, dòng 107; [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `SoSanhChuoi`, dòng 27.

<a id="TH219"></a>
### TH219 — Tên có nhiều khoảng trắng qua hai đường nhập

**Thái · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH219).

**Trả lời ngắn:** API thêm chuẩn hóa khoảng trắng tên; loader gán nguyên tên từ trường file và validator không bắt tên phải ở dạng chuẩn.

**Giải thích và bảo vệ cách làm:**

Cả hai tạo cùng khóa so nên có thể cùng khớp và phá hòa theo ISBN, dù văn bản hiển thị/lưu lại khác. Quy tắc bắt dạng chuẩn trong file áp cho mã định danh, không phải mọi tên.

**Đáp câu phụ 1:** Đó là thay đổi chính sách bảo toàn dữ liệu, phải quyết định rõ. Test nghiệp vụ nên tách nội dung lưu và tương đương khóa tìm, không sửa dữ liệu chỉ để làm test xanh.

**Sai lầm dễ mắc:** Hợp lệ file đồng nghĩa mọi trường đã được chuẩn hóa như form.

**Cách kiểm chứng:** Đề xuất: nạp tên ba dấu cách, thêm tên tương tự, so byte và tìm; ISBN giữ chuẩn trong cả hai đầu.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `ThemDauSach`, dòng 64; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `DocNoiBo`, dòng 222; [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `KhoaSoSanh`, dòng 22.

<a id="TH220"></a>
### TH220 — Output mã bị alias với ISBN nguồn

**Thái · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH220).

**Trả lời ngắn:** Gán output có thể đổi chính ISBN của đầu A thành A#1, trước khi nối cuốn; chữ ký tham chiếu không ngăn alias này.

**Giải thích và bảo vệ cách làm:**

Hàm dùng d đã tìm được nên vẫn có thể nối cuốn, nhưng ISBN có # vi phạm quy tắc đầu sách. UI dùng biến ma cục bộ riêng. Cần nêu tiền điều kiện output độc lập hoặc thiết kế kiểu kết quả không cho ghi ngược vào cấu trúc.

**Đáp câu phụ 1:** Không; ma vẫn tham chiếu trực tiếp trường đó. Bản sao đầu vào chỉ giữ được giá trị đọc, không bảo vệ nơi nhận output.

**Sai lầm dễ mắc:** const ở một tham số được xem là cấm mọi tham số khác sửa cùng dữ liệu.

**Cách kiểm chứng:** Đề xuất: harness biệt lập gọi alias rồi kiểm toàn vẹn; phục hồi ISBN trước hủy nếu cần. Không khẳng định UI hiện tại tạo lỗi này.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `ThemCuonSach`, dòng 74.

<a id="TH221"></a>
### TH221 — Hai đầu cùng sở hữu một đuôi danh sách

**Thái · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH221).

**Trả lời ngắn:** Đây là chia sẻ node sở hữu, không phải vòng; cùng cuốn sẽ được thu vào chỉ mục hai lần và trùng mã bị phát hiện.

**Giải thích và bảo vệ cách làm:**

Hai danh mục đều tưởng sở hữu S001 nên hủy lần hai có thể dùng/xóa vùng đã giải phóng. Validator báo lỗi không sửa đồ thị sở hữu và không làm destructor trên RAM hỏng thành an toàn.

**Đáp câu phụ 1:** Không nhất thiết double-delete; đó là trùng định danh hai đối tượng. Cần phân biệt đồng địa chỉ với bằng giá trị mã dù validator đều có thể báo trùng mã.

**Sai lầm dễ mắc:** Danh sách không vòng được coi là đủ bảo đảm quyền sở hữu duy nhất.

**Cách kiểm chứng:** Truy vết bằng sơ đồ; nếu harness tạo chia sẻ thì tháo alias trước dọn. Không chạy destructor mù trên dữ liệu lỗi.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `HuyDanhMucCuonSach`, dòng 99; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102.

<a id="TH222"></a>
### TH222 — Top có tổng lượt đúng nhưng gán sai chủ đầu

**Thái · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH222).

**Trả lời ngắn:** Phần tử chỉ mục là cặp cuốn–chỉ số chủ, phải hoán đổi cả cặp; tách cặp sẽ cộng vào chủ cũ của vị trí.

**Giải thích và bảo vệ cách làm:**

TimChuSoHuu tìm đúng mã nhưng trả sai dauSach nên tổng toàn kho vẫn bằng H. Cần kiểm từng ánh xạ mã→ISBN và bộ đếm từng đầu, không chỉ tổng.

**Đáp câu phụ 1:** Có thể bị che. Dùng số lượt bất đối xứng và tên/mã có thứ tự chéo để ép phép hoán đổi có ý nghĩa.

**Sai lầm dễ mắc:** Tổng lượt bằng H được coi là chứng minh thống kê từng đầu đúng.

**Cách kiểm chứng:** Đề xuất: 3 lượt A, 1 lượt B; kiểm cả chỉ mục sau sắp và top A3/B1, rồi đổi thứ tự nhập.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `ChiMucCuon`, dòng 96; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InTop10SachDuocMuonNhieuNhat`, dòng 172.

<a id="TH223"></a>
### TH223 — Con trỏ cuốn bị xóa trong lúc xây chỉ mục tạm

**Thái · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH223).

**Trả lời ngắn:** Hiện không có worker; báo cáo chạy xong trong cùng luồng trước khi nhận NAP. Mở rộng song song làm vòng đời con trỏ trở thành vấn đề mới.

**Giải thích và bảo vệ cách làm:**

Nạp có thể hủy toàn bộ cuốn cũ; khóa chỉ khi in là quá muộn. Phải giữ khóa đọc qua toàn vòng đời view hoặc dùng snapshot sở hữu riêng có phiên bản; đổi lại chặn ghi lâu hoặc tăng RAM/copy.

**Đáp câu phụ 1:** Tránh một số con trỏ treo nhưng chưa tạo snapshot nhất quán; từng lần tra có thể gặp phiên khác. Cần định nghĩa kết quả thuộc một phiên cụ thể.

**Sai lầm dễ mắc:** Khóa output được nhầm là khóa nguồn dữ liệu của báo cáo.

**Cách kiểm chứng:** Đề xuất: dùng barrier trong bản thử dừng worker sau dựng index rồi nạp; kiểm thiết kế mới không dùng vùng cũ và không trộn phiên. Chưa chạy.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InTop10SachDuocMuonNhieuNhat`, dòng 172; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `HoanDoiThuVien`, dòng 338.

<a id="TH224"></a>
### TH224 — Một triệu lượt mượn không đồng nghĩa một triệu độc giả

**Thái · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH224).

**Trả lời ngắn:** Không nạp đủ H=1.000.000 ở MAX_BAN_GHI=200.000; số lịch sử được kiểm theo ngân sách còn lại khi đọc.

**Giải thích và bảo vệ cách làm:**

Sau giả định nâng giới hạn, phải tính chỉ mục cuốn, view độc giả, lịch sử nguồn, mảng kiểm Luot và tối đa 2H sự kiện, cùng bản dữ liệu cũ/tạm lúc nạp. Top vẫn xử lý cả lượt đã trả, khoảng O(C log C+H log C+R+10D), cộng độ dài mã.

**Đáp câu phụ 1:** Không: còn 50.000 lượt mở của một người, vượt 3. Với bản hiện trần H=200.000 đã chặn trước khi nhận đủ một triệu. Chỉ khi đổi thêm các lượt thành đã đóng, ngày không chồng quá hạn mức và mọi liên kết/trạng thái khớp thì đây mới là một giả định khác có thể hợp lệ sau nâng trần; không lấy trường hợp khác đó làm đáp án cho dữ liệu giữ nguyên.

**Sai lầm dễ mắc:** Dùng số người dùng để thay H hoặc lấy hạn mức 3 giới hạn toàn lịch sử.

**Cách kiểm chứng:** Chỉ phân tích quy mô; test hiện tại phải kiểm từ chối vượt H trước, không tuyên bố benchmark triệu lượt.

**Kiểm mới 18/10:** [original_four_open](ThamKhao/KIEM_DINH_20261018.md#original_four_open). Chỉ các assertion/quan sát nêu trong ca.

**Nguồn đối chiếu:** [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — `MAX_BAN_GHI`, dòng 9; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `DocNoiBo`, dòng 222; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InTop10SachDuocMuonNhieuNhat`, dòng 172.

<a id="TH225"></a>
### TH225 — Ngày sai làm thống kê ngừng trước tiêu đề

**Thái · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH225).

**Trả lời ngắn:** Không có bảng một phần theo đường này: lỗi tính ngày xảy ra trong pha gom, trước khi sắp và xuất tiêu đề.

**Giải thích và bảo vệ cách làm:**

SoThuTuNgay ném invalid_argument; mảng tạm được dọn khi unwinding và dữ liệu nghiệp vụ không đổi. Caller cần báo lỗi, không lấy việc row của 10 đã tính làm báo cáo thành công.

**Đáp câu phụ 1:** Có thể đã xuất người 10 trước khi lỗi ở 20; cần quyết định cho phép báo cáo từng phần hay đệm kết quả, ngoài chuyện không đổi RAM.

**Sai lầm dễ mắc:** Không sửa dữ liệu bị nhầm với không bao giờ có đầu ra từng phần.

**Cách kiểm chứng:** Truy vết hoặc harness ostringstream: xác nhận exception và chuỗi rỗng; khác với lỗi stream xảy ra trong pha xuất.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InDocGiaQuaHan`, dòng 148; [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `SoThuTuNgay`, dòng 112.

<a id="TH226"></a>
### TH226 — Hai lần nhập cùng ISBN sau timeout ở lớp điều phối

**Thái · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH226).

**Trả lời ngắn:** Lặp thêm đầu A bị ISBN trùng chặn; mỗi lần thêm cuốn là yêu cầu tạo một bản vật lý mới và có thể cấp hai mã khác nhau.

**Giải thích và bảo vệ cách làm:**

Vị trí kệ không là định danh yêu cầu hay cuốn. Hai API có ý nghĩa lặp khác nhau; cần kiểm kho sau thông báo thất bại. Bản hiện không có mã yêu cầu để nhận ra retry cùng ý định.

**Đáp câu phụ 1:** Tên không duy nhất giữa đầu và không phân biệt các cuốn cùng đầu. Nó vừa chặn thao tác hợp lệ vừa không mô tả được ý định retry.

**Sai lầm dễ mắc:** Mọi lệnh thêm đều an toàn khi gửi lại vì đều có mã tự động.

**Cách kiểm chứng:** Đề xuất: thêm A hai lần rồi thêm cuốn hai lần; mong 1 đầu, 2 cuốn, không có lịch sử mượn.

**Ca liên quan đã chạy 17/10 (không tái chạy đợt này):** [book_and_copies_retry](ThamKhao/KIEM_CHUNG_RUNTIME.md#book_and_copies_retry).

**Nguồn đối chiếu:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `ThemDauSach`, dòng 64; [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `ThemCuonSach`, dòng 74.

<a id="TH227"></a>
### TH227 — Các danh mục có sắp riêng đủ để bỏ sort index top không

**Thái · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH227).

**Trả lời ngắn:** Mỗi danh mục phải tăng theo đúng phép so mã toàn cục và phép trộn phải giữ mapping chủ; danh mục hiện không bảo đảm thứ tự đó.

**Giải thích và bảo vệ cách làm:**

A#10 đứng trước A#2 theo so chuỗi, nhưng được thêm sau; legacy làm miền mã không còn chỉ một khoảng prefix. Muốn k-way merge phải sắp từng view trước hoặc duy trì thứ tự mới có chi phí cập nhật. Nối các danh mục không tương đương merge theo mã.

**Đáp câu phụ 1:** Không; đảo ở giữa vẫn có thể tồn tại. Cần invariant được duy trì hoặc kiểm các cặp kề trên toàn danh sách.

**Sai lầm dễ mắc:** Các cuốn cùng ISBN được thêm tăng số nên tăng theo comparator chuỗi của index.

**Cách kiểm chứng:** Đề xuất phản ví dụ 1,2,10 cùng legacy, so lookup mọi mã với index chuẩn; chưa thay thuật toán.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `ThemCuonSach`, dòng 74; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InTop10SachDuocMuonNhieuNhat`, dòng 172.

<a id="TH228"></a>
### TH228 — Giảm MAX_DAU_SACH khi kho cũ đang vượt ngưỡng mới

**Thái · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH228).

**Trả lời ngắn:** Số đầu ở đầu file vượt miền r.So nên nạp thất bại; chương trình không tự cắt danh mục.

**Giải thích và bảo vệ cách làm:**

Cắt đầu còn có thể bỏ cuốn được lịch sử tham chiếu và làm lệch thống kê. Thay giới hạn là thay khả năng tương thích dữ liệu, cần kế hoạch chuyển dữ liệu/khôi phục hoặc giữ cấu hình đủ trước khi triển khai.

**Đáp câu phụ 1:** Không; tăng khả năng chứa không đổi insertion sort thể loại, chi phí quét hay bộ nhớ tạm. Phải đánh giá riêng.

**Sai lầm dễ mắc:** Thay hằng giới hạn được coi là thay UI không ảnh hưởng dữ liệu lưu.

**Cách kiểm chứng:** Đề xuất: trên build bản sao hạ ngưỡng nhỏ, nạp file ngay dưới/trên ngưỡng; kiểm dữ liệu đích không bị cắt hoặc ghi đè.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — `MAX_DAU_SACH`, dòng 7; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `DocNoiBo`, dòng 222; [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `ThemDauSach`, dòng 64.

<a id="TH229"></a>
### TH229 — Hủy phần sách trước lịch sử có luôn dereference mã cuốn

**Thái · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH229).

**Trả lời ngắn:** Đường hủy lịch sử hiện chỉ đi next và delete node; không tra maSach, nên riêng quan hệ mã không bắt buộc sách còn sống khi hủy.

**Giải thích và bảo vệ cách làm:**

Thứ tự hiện rõ ràng nhưng không nên bịa phụ thuộc con trỏ không có. Nếu thêm callback/log khi hủy phải tra tên sách, hoặc thêm con trỏ mượn, thứ tự và vòng đời sẽ cần xét lại. Không tự thêm các phần đó.

**Đáp câu phụ 1:** Không; những view chứa con trỏ sách đã hết hiệu lực. Kết luận chỉ áp destructor lịch sử đã đọc, không áp mọi caller.

**Sai lầm dễ mắc:** Mọi liên kết bằng mã được coi như con trỏ sở hữu trực tiếp.

**Cách kiểm chứng:** Truy các hàm hủy và loại trường; nếu thử đảo thứ tự thì chỉ trên fixture riêng, kiểm giải phóng đầy đủ bằng công cụ phù hợp.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `HuyThuVien`, dòng 335; [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `HuyDanhSachDauSach`, dòng 120; [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `HuyDanhSachMuonTra`, dòng 18.

<a id="TH230"></a>
### TH230 — Mã rỗng trong kết quả của một API tự viết

**Thái · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH230).

**Trả lời ngắn:** Node mặc định có trạng thái cho mượn và next=null nhưng mã/vị trí rỗng; một số trường hợp lệ không tạo thành một cuốn hợp lệ.

**Giải thích và bảo vệ cách làm:**

ThemCuonSach hiện chuẩn bị các chuỗi trước nối. Nối sớm đưa đối tượng chưa hoàn chỉnh vào kho; kiểm file sẽ từ chối văn bản rỗng nhưng không tự rollback helper mới.

**Đáp câu phụ 1:** Delete ngay để lại liên kết treo; không delete giữ một node chưa hoàn chỉnh trong kho, cũng không giữ nguyên trạng thái. Rollback phải tháo đúng ô liên kết và khôi phục mọi trường đã đổi, đồng thời tránh hai chủ cùng hủy. Cách hiện tại chuẩn bị node dưới unique_ptr rồi mới bàn giao giúp tránh đường dọn phức tạp đó.

**Sai lầm dễ mắc:** Constructor mặc định được xem là tạo sẵn một bản ghi nghiệp vụ hợp lệ.

**Cách kiểm chứng:** Đề xuất: mutation bỏ gán vị trí, kiểm toàn vẹn phải từ chối; đối chiếu số node trước/sau lỗi chuẩn bị ở API chuẩn.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — `CuonSach`, dòng 14; [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `ThemCuonSach`, dòng 74; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102.

<a id="TH231"></a>
### TH231 — Ghi danh mục phải duyệt hai lượt hay lưu sẵn số cuốn

**Thái · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH231).

**Trả lời ngắn:** Hai lượt vẫn O(c); count lâu dài chỉ giảm hằng số ở đường ghi nhưng thêm bất biến đồng bộ.

**Giải thích và bảo vệ cách làm:**

File cần count trước danh sách nên không đơn giản in rồi mới biết count. Có thể đệm phần cuốn để tính trước nhưng trả thêm bộ nhớ/chuỗi. Trường hỗ trợ mới phải có mục đích và được phép, không tự coi ít vòng là tối ưu đáng giá.

**Đáp câu phụ 1:** Không, loader dùng count làm ranh giới; dòng dư có thể bị hiểu là phần sau hoặc bị từ chối. Count sai làm hỏng framing.

**Sai lầm dễ mắc:** Giảm từ hai lần quét xuống một lần được gọi là giảm O(c) xuống O(1) cho cả ghi.

**Cách kiểm chứng:** Đề xuất: đếm số bước ghi c và 2c cuốn; mutation count lệch phải bị kiểm round-trip phát hiện.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `Ghi`, dòng 273; [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `DemCuonSach`, dòng 102.

<a id="TH232"></a>
### TH232 — Nhập hai danh mục riêng bằng NAP có phải hợp nhất

**Thái · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH232).

**Trả lời ngắn:** NAP thay toàn bộ thư viện bằng file B hợp lệ; nó không hợp nhất hai file.

**Giải thích và bảo vệ cách làm:**

Nhập bổ sung cần quy tắc trùng ISBN, trùng mã cuốn, mã thẻ và lịch sử; giữ bản tạm để báo xung đột, không tự chọn thông tin đúng. Đây là yêu cầu mới, có thể phải ánh xạ mã và được giảng viên đồng ý.

**Đáp câu phụ 1:** Không; các cuốn hoặc lịch sử B có thể tham chiếu bản bị bỏ. Phải xét toàn bộ quan hệ trước quyết định bỏ/ghép.

**Sai lầm dễ mắc:** Hai lần nạp thành công được hiểu là cộng dồn dữ liệu.

**Cách kiểm chứng:** Đề xuất: A và B có tổng riêng, cùng ISBN khác cuốn; đối chiếu bản hiện sau NAP chỉ bằng B, rồi lập bảng xung đột cho thiết kế merge.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `DocNoiBo`, dòng 222; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `HoanDoiThuVien`, dòng 338.

<a id="TH233"></a>
### TH233 — Thống kê mức luân chuyển khác số lượt tuyệt đối

**Thái · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH233).

**Trả lời ngắn:** Top hiện xếp A trước vì 100>20; không tính tỉ lệ sử dụng.

**Giải thích và bảo vệ cách làm:**

Tỉ lệ theo số cuốn hiện tại cho A=1, B=10 nhưng là chỉ số mới. Mẫu số 0 cần quy ước; cuốn mua cuối kỳ không có lịch sử số lượng theo thời gian nên không suy ra mức sử dụng công bằng cả kỳ chỉ từ snapshot.

**Đáp câu phụ 1:** Không: chia nguyên mất phần lẻ và chia 0 nguy hiểm; quan trọng hơn là chưa chốt nghĩa mẫu số và thời kỳ. Có thể so phân số sau kiểm miền, nhưng cần đúng đặc tả trước.

**Sai lầm dễ mắc:** Top nhiều lượt được trình bày như chứng minh sử dụng hiệu quả nhất.

**Cách kiểm chứng:** Đề xuất: A/B, một đầu 0 cuốn và một đầu nhiều cuốn thanh lý; lập expected cho từng định nghĩa được chọn.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InTop10SachDuocMuonNhieuNhat`, dòng 172; [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `DemCuonSach`, dòng 102.

<a id="TH235"></a>
### TH235 — Kiểm số cuốn dùng >= và ngân sách trước thêm

**Thái · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH235).

**Trả lời ngắn:** M−1 node cũ không đạt ngưỡng M nên được thêm thành M; M node cũ bị chặn khi đếm tới node M.

**Giải thích và bảo vệ cách làm:**

Điều kiện hiện kiểm kho trước cấp node. Sửa tăng hậu tố và > có thể bỏ qua kho đã đầy, cho trạng thái vượt giới hạn mà loader sau đó không nhận. Cần chứng minh theo số node thực, không đoán từ ký hiệu.

**Đáp câu phụ 1:** Không; cuốn phải thuộc danh mục của đầu. Test sát ngưỡng phải có cấu trúc và liên kết hợp lệ, hoặc hạ hằng trên bản thử và nói rõ.

**Sai lầm dễ mắc:** Đọc biểu thức ++tong mà không xét vòng chỉ chạy trên các node đã có.

**Cách kiểm chứng:** Truy vết M=3 trên bản sao cấu hình nhỏ: 2→3 được, 3→4 bị chặn; file sau thành công vẫn đọc lại được.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `ThemCuonSach`, dòng 74; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `DocNoiBo`, dòng 222.

<a id="TH236"></a>
### TH236 — Gộp báo cáo quá hạn từ hai nhóm độc giả

**Thái · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH236).

**Trả lời ngắn:** Cùng A phải ghép max=max(8,3)=8 và count=1+2=3; không cộng max thành 11.

**Giải thích và bảo vệ cách làm:**

Max và count có phép kết hợp khác nhau. Đoạn không có lượt quá hạn dùng max 0/count 0; mọi đoạn phải cùng ngày đối chiếu, cùng snapshot và không đếm chồng node. Chia theo người rời nhau có thể nối dòng rồi sort theo khóa báo cáo, không gộp hai người trùng tên.

**Đáp câu phụ 1:** Count bị tăng dư; max đúng không chứng minh phân hoạch đúng. Cần kiểm mỗi node thuộc đúng một phần.

**Sai lầm dễ mắc:** Mọi số tổng hợp đều ghép bằng phép cộng hoặc max đúng là đủ.

**Cách kiểm chứng:** Đề xuất so xử lý toàn bộ với mọi điểm chia trên lịch sử nhỏ; đây là thiết kế chưa triển khai.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `DongQuaHan`, dòng 95; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InDocGiaQuaHan`, dòng 148.

<a id="TH237"></a>
### TH237 — Dùng bucket số lượt thay bảng top mười ô

**Thái · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH237).

**Trả lời ngắn:** Bucket có thể tốn O(H+D) bộ nhớ/thời gian khởi tạo/quét, trong khi bảng 10 ô chọn O(10D), O(10) ô ngoài dem/index.

**Giải thích và bảo vệ cách làm:**

Số lượt phân bucket chưa giải quyết tên–ISBN trong bucket ngưỡng; cần chọn/sắp theo khóa phụ cho đủ 10. D nhỏ/H lớn có thể làm bucket tệ hơn. H là tổng lượt chứ không phải số bucket có dữ liệu; không gọi bucket tự động O(D) nếu vẫn cấp H+1.

**Đáp câu phụ 1:** Không; còn quy tắc tên tăng/ISBN tăng. Phải bảo vệ thứ tự ở ngưỡng, kể cả không xuất toàn bucket.

**Sai lầm dễ mắc:** Khóa chính là số nguyên nên counting/bucket luôn nhanh và bỏ được comparator phụ.

**Cách kiểm chứng:** Đề xuất so với top hiện tại trên D nhỏ/H lớn, nhiều hòa và H=0; chưa đo hay cài bucket.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InTop10SachDuocMuonNhieuNhat`, dòng 172; [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — `MAX_BAN_GHI`, dòng 9.

<a id="TH238"></a>
### TH238 — Hậu tố mã số không phải chỉ số truy cập mảng

**Thái · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH238).

**Trả lời ngắn:** Hậu tố không phải số lượng hay chỉ số liên tục; mảng trực tiếp theo max có thể cấp rất nhiều ô cho hai cuốn.

**Giải thích và bảo vệ cách làm:**

Hiện tra theo chuỗi trong danh sách, số node phụ thuộc Cᵢ. Chỉ mục phụ cần chọn theo độ thưa và hỗ trợ legacy; không tự thay danh sách bắt buộc bằng mảng. Giới hạn tổng cuốn không giới hạn max hậu tố cùng giá trị.

**Đáp câu phụ 1:** Cần thêm ánh xạ tìm từ hậu tố sang vị trí, phát sinh chi phí và đồng bộ; đã không còn phép đánh chỉ số trực tiếp ban đầu.

**Sai lầm dễ mắc:** Mã lớn được coi là bằng số node hoặc bị MAX_BAN_GHI chặn vì chính giá trị mã.

**Cách kiểm chứng:** Đề xuất: fixture hai cuốn hậu tố cách xa, kiểm tra cứu và sinh mã tiếp; chỉ phân tích bộ nhớ phương án mảng thưa.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `TachMaMoi`, dòng 8; [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `TimCuonSachTrongDauSach`, dòng 21, 25.

<a id="TH239"></a>
### TH239 — Gửi báo cáo cho người đọc không có quyền sửa

**Thái · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH239).

**Trả lời ngắn:** Bản console hiện không có xác thực/phân quyền; người sử dụng phiên có thể chọn các mục menu.

**Giải thích và bảo vệ cách làm:**

Dịch vụ mới cần kiểm quyền ở ranh giới yêu cầu trước gọi báo cáo và giới hạn trường trả về; ẩn nút không chặn caller khác. Phải chốt vai trò, phạm vi dữ liệu và kiểm truy cập bằng danh tính đáng tin, không tin tên do request tự khai.

**Đáp câu phụ 1:** Không; đó là dữ liệu khác, cần quyết định quyền riêng. Bản e hiện chỉ in trạng thái cuốn, không tự xuất danh tính người giữ.

**Sai lầm dễ mắc:** Menu console được nhầm là hệ thống đã kiểm soát quyền người dùng.

**Cách kiểm chứng:** Đề xuất cho hệ thống mở rộng: người không đăng nhập, sinh viên và thủ thư gọi trực tiếp từng báo cáo; kiểm cả dữ liệu bị từ chối. Chưa triển khai.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InDocGiaQuaHan`, dòng 148.

<a id="TH240"></a>
### TH240 — Heap mười phần tử và bảng chèn mười ô

**Thái · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH240).

**Trả lời ngắn:** Root nên là đầu tệ nhất đang giữ để so ứng viên mới; kết thúc cần sắp 10 phần tử theo thứ tự xuất.

**Giải thích và bảo vệ cách làm:**

Heap cho O(D log 10) so chọn và O(10 log 10) chốt; chèn hiện tại O(10D), nhưng k nhỏ nên hằng số/độ đơn giản có thể quan trọng. Hai cách đều không bỏ được chi phí dựng index và đếm H. Phải giữ toàn comparator, loại đầu 0 trước chọn.

**Đáp câu phụ 1:** Loại người thắng hiện tại thay vì ứng viên yếu nhất, có thể mất đầu đáng thuộc top.

**Sai lầm dễ mắc:** Có heap là toàn báo cáo chắc nhanh hơn dù chi phí chính nằm ở xử lý lịch sử.

**Cách kiểm chứng:** Đề xuất so dãy ISBN chính xác với bảng 10 ô trên mọi vị trí ứng viên và nhiều khóa hòa; chưa benchmark.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InTop10SachDuocMuonNhieuNhat`, dòng 172; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `DauSachXepTruoc`, dòng 107.

<a id="TH241"></a>
### TH241 — Mượn trả cùng ngày tạo hai node giống hệt trên giấy

**Thái · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH241).

**Trả lời ngắn:** Code có thể tạo hai lượt thật với các trường bằng nhau; top phải đếm 2. Loại một node sẽ làm mất một lượt.

**Giải thích và bảo vệ cách làm:**

V1 không có thời điểm giờ hay ID giao dịch để phân biệt hai ý định ngoài những trường đó. Không tự khử trùng lịch sử chỉ bằng equality; cần nguồn xác minh hoặc thiết kế định danh lượt mới nếu yêu cầu.

**Đáp câu phụ 1:** Không; nó kiểm tính khả thi theo ngày, không chứng thực sự kiện ngoài đời. Chấp nhận khác xác nhận nguồn gốc.

**Sai lầm dễ mắc:** Bản ghi giống mọi trường được coi chắc chắn là trùng lỗi.

**Cách kiểm chứng:** Đề xuất: chạy hai chu kỳ trong ngày, lưu–nạp và top=2; giữ hai node, so với file cố ý mất một node.

**Ca liên quan đã chạy 17/10 (không tái chạy đợt này):** [two_identical_day_loans](ThamKhao/KIEM_CHUNG_RUNTIME.md#two_identical_day_loans).

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KetThucMuon`, dòng 54; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InTop10SachDuocMuonNhieuNhat`, dòng 172.

<a id="TH242"></a>
### TH242 — Giới hạn byte của vị trí kệ ảnh hưởng kích thước báo cáo

**Thái · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH242).

**Trả lời ngắn:** sizeof chỉ chứa đối tượng string, không bao gồm toàn bộ vùng ký tự cấp phát của từng chuỗi; báo cáo text còn tạo bản sao nội dung.

**Giải thích và bảo vệ cách làm:**

Cần tính các chuỗi mã/vị trí trong dữ liệu và dung lượng ostringstream/string, ngoài overhead node/allocator. SSO hay capacity là chi tiết triển khai nên không tự bịa byte chính xác nếu chưa đo.

**Đáp câu phụ 1:** Không; 512 là byte UTF-8 tối đa, số code unit UTF-16 và ô hiển thị khác nhau. Đo trên dữ liệu cụ thể hoặc đưa cận có giả định.

**Sai lầm dễ mắc:** sizeof struct được dùng như tổng dung lượng sở hữu của cấu trúc chứa string.

**Cách kiểm chứng:** Phân tích tài nguyên theo tổng byte chuỗi B; thử fixture giới hạn nhỏ, không tuyên bố đã đo 200.000 chuỗi tối đa.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `HopLeVanBan`, dòng 42; [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `InMotDauSach`, dòng 14.

<a id="TH243"></a>
### TH243 — Khóa báo cáo gộp theo tên làm mất hai ISBN

**Thái · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH243).

**Trả lời ngắn:** Đặc tả hiện gom theo đầu định danh ISBN, nên cần hai kết quả A7/B4; tên giống không cho phép gộp đầu.

**Giải thích và bảo vệ cách làm:**

Các cuốn cùng ISBN có chung chủ nên cộng đúng vào dem[owner]. Tên là khóa hiển thị và phá hòa, không là khóa định danh. Cần giữ ánh xạ cuốn→đầu trong chỉ mục.

**Đáp câu phụ 1:** Chưa chắc: tên trùng có thể là tác phẩm khác, nhiều tên có thể là cùng tác phẩm. Cần mô hình và quy tắc xác định tác phẩm được duyệt; hiện không có trường đó.

**Sai lầm dễ mắc:** Gom nhóm theo chuỗi hiển thị được coi là tương đương gom theo danh tính.

**Cách kiểm chứng:** Đề xuất: hai ISBN cùng tên với số lượt lệch; top phải giữ hai dòng và tổng 11, không một dòng.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InTop10SachDuocMuonNhieuNhat`, dòng 172; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `TimChuSoHuu`, dòng 98.

<a id="TH244"></a>
### TH244 — Nhị phân thấy mã nhưng không thấy đủ mọi bản ghi trùng

**Thái · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH244).

**Trả lời ngắn:** Khi mã không duy nhất, tìm nhị phân có thể trả một mục trùng; không có căn cứ chọn chủ thật.

**Giải thích và bảo vệ cách làm:**

KiemTraNoiBo kiểm mã cuốn trùng, còn top giả định nguồn đã hợp lệ và chỉ chặn không tìm thấy. Thành công của một phép join không chứng minh ràng buộc duy nhất.

**Đáp câu phụ 1:** Chỉ làm lựa chọn xác định hơn; vẫn không giải quyết hai danh tính cùng mã. Cần từ chối và đối soát nguồn trùng.

**Sai lầm dễ mắc:** Có một kết quả tìm được được xem là có đúng một kết quả hợp lệ.

**Cách kiểm chứng:** Đề xuất: kiểm validator trên hai node trùng; chỉ phân tích top trên RAM lỗi và không khẳng định top có cơ chế tự sửa.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `TimChuSoHuu`, dòng 98; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102.

<a id="TH245"></a>
### TH245 — Ưu tiên quá hạn theo cuốn thay vì theo người

**Thái · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH245).

**Trả lời ngắn:** rows hiện giữ một dòng mỗi độc giả với max và count, không giữ danh sách mã/ngày từng cuốn.

**Giải thích và bảo vệ cách làm:**

Báo cáo theo cuốn cần gom từng lượt mở quá hạn kèm mã thẻ/mã cuốn/số ngày rồi sắp theo đặc tả mới. Thay vòng in không khôi phục được chi tiết đã bỏ trong phép tổng hợp.

**Đáp câu phụ 1:** Có: cuốn thứ hai bị ghi 9 thay vì 8. Tổng hợp theo người không thể thay số đo từng cuốn.

**Sai lầm dễ mắc:** Một dòng đã tổng hợp được xem là đủ tái dựng mọi chi tiết gốc.

**Cách kiểm chứng:** Đề xuất: expected ba dòng 9/8/7, so báo cáo người hai dòng max 9/max 7; giữ cả hai chức năng riêng nếu được chấp thuận.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `DongQuaHan`, dòng 95; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InDocGiaQuaHan`, dòng 148.

<a id="TH246"></a>
### TH246 — Chỉ mục cuốn dựng lại mỗi lần có lợi trong phiên ít đọc

**Thái · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH246).

**Trả lời ngắn:** Chỉ mục mã cuốn có thể tái dùng khi danh mục không đổi; bộ đếm top còn phụ thuộc lịch sử mới. Hai cache có điều kiện làm mới khác nhau.

**Giải thích và bảo vệ cách làm:**

Phiên ít đọc có thể không đáng giữ bộ nhớ/đồng bộ. Phiên đọc nhiều cần đo chi phí dựng/sắp index so với quét H; thêm cuốn/nạp bắt làm mới index, mượn mới đổi điểm dù danh mục không đổi.

**Đáp câu phụ 1:** Riêng trả không đổi mã/chủ và không tạo lượt, nên không bắt buộc vì sự kiện đó; vẫn phải xét các sự kiện khác cùng phiên và vòng đời snapshot.

**Sai lầm dễ mắc:** Cache chỉ mục tra cứu được gọi chung là cache top nên vô hiệu hóa sai phạm vi.

**Cách kiểm chứng:** Đề xuất: bộ đếm số lần dựng index trên hai workload; đối chiếu với hàm tính lại sau thêm cuốn, mượn, trả và NAP. Chưa cài cache.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InTop10SachDuocMuonNhieuNhat`, dòng 172; [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `ThemCuonSach`, dòng 74.

<a id="TH247"></a>
### TH247 — Hiện “đã thanh lý” có biết lý do là mất không

**Thái · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH247).

**Trả lời ngắn:** InMotDauSach hiện cả hai là “Da thanh ly”; trạng thái cuốn không tự ghi lý do.

**Giải thích và bảo vệ cách làm:**

Lượt mất có thể giúp nhận biết X trong mô hình G05; Y trạng thái 2 không bắt buộc có lịch sử mất. V1 không có sự kiện thanh lý hay người thực hiện, nên không được tự gán trách nhiệm.

**Đáp câu phụ 1:** Không. Đề quy định trạng thái cuốn 2 là thanh lý; ánh xạ báo mất chỉ là giả định của bản này, cần hỏi thầy.

**Sai lầm dễ mắc:** Hai enum cùng giá trị 2 bị coi là cùng một sự kiện nghiệp vụ.

**Cách kiểm chứng:** Đề xuất: fixture X mất/Y thanh lý không lịch sử, tìm cả hai; kiểm nhãn và giới hạn khả năng giải thích nguyên nhân.

**Ca liên quan đã chạy 17/10 (không tái chạy đợt này):** [lost_then_return_other](ThamKhao/KIEM_CHUNG_RUNTIME.md#lost_then_return_other).

**Nguồn đối chiếu:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `InMotDauSach`, dòng 14; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `DanhDauMatSach`, dòng 142; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102.

<a id="TH248"></a>
### TH248 — Vị trí kệ mới phải đổi số liệu nào

**Thái · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH248).

**Trả lời ngắn:** Code chỉ lưu một chuỗi viTri và in nó; chưa có nghiệp vụ chuyển vị trí hay lịch sử di chuyển để xác định hai nghĩa này.

**Giải thích và bảo vệ cách làm:**

Nếu là kệ cất mặc định, có thể đổi mà không đổi mã/lượt/top sau kiểm văn bản. Nếu là vị trí vật lý, cuốn đang do độc giả giữ không thật ở kệ; cần quy tắc và dữ liệu bổ sung được duyệt. Không suy chuỗi kệ chứng minh sách ở đó.

**Đáp câu phụ 1:** Không có cơ sở: mã đại diện bản vật lý, vị trí là thuộc tính. Chỉ đổi kệ không tạo bản sách mới hay lượt mượn.

**Sai lầm dễ mắc:** Thông tin vị trí được trình bày như theo dõi vật lý thời gian thực.

**Cách kiểm chứng:** Đề xuất thiết kế: kiểm mã/lịch sử/top giữ nguyên sau đổi hợp lệ; test lỗi văn bản giữ vị trí cũ. Chưa triển khai.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — `CuonSach`, dòng 14; [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `InMotDauSach`, dòng 14; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InTop10SachDuocMuonNhieuNhat`, dòng 172.

<a id="TH249"></a>
### TH249 — Đếm lượt top dùng int trong miền đã chặn

**Thái · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH249).

**Trả lời ngắn:** Với H≤200.000, mỗi dem≤H nên nằm trong miền int; thời gian hoạt động không vượt qua được giới hạn nạp/thêm lịch sử của bản này.

**Giải thích và bảo vệ cách làm:**

Nâng quy mô phải xét cả bộ đếm tổng, chỉ số, kích thước cấp phát, 2H sự kiện và kiểu metadata liên quan. Đổi một mảng số đếm không làm cả chương trình hỗ trợ hàng tỷ node.

**Đáp câu phụ 1:** Phải chứng minh đi qua cổng giới hạn trước; file hợp lệ theo bản hiện sẽ bị từ chối sớm. RAM tự sửa vượt cổng là ca chẩn đoán khác.

**Sai lầm dễ mắc:** Phân tích tràn bỏ qua miền dữ liệu đã được kiểm ở đầu vào.

**Cách kiểm chứng:** Truy cận H và nơi tăng dem; thử sát giới hạn bằng cấu hình nhỏ nếu cần, không tạo tải nhiều tỷ.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — `MAX_BAN_GHI`, dòng 9; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InTop10SachDuocMuonNhieuNhat`, dòng 172.

<a id="TH250"></a>
### TH250 — Trình tự chuẩn hóa mã và xuất lỗi chứa mã

**Thái · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH250).

**Trả lời ngắn:** Mã lưu phải bằng ChuanHoaChuoi của chính nó; khớp giữa hai phía chưa đủ nếu vi phạm dạng chuẩn định danh.

**Giải thích và bảo vệ cách làm:**

UI chuẩn hóa trước tra nên mã không chuẩn có thể không truy cập đúng. Trim hàng loạt có thể gộp hai mã khác thành một, vì vậy loader từ chối chứ không tự đổi mã và tham chiếu.

**Đáp câu phụ 1:** Không; validator áp so dạng chuẩn riêng ISBN/maSach trong danh mục/lịch sử. Tên có quy tắc văn bản và khóa so khác.

**Sai lầm dễ mắc:** Tính nhất quán tham chiếu bị coi là đủ thay mọi bất biến định danh.

**Cách kiểm chứng:** Đề xuất: file có hai mã “A#1” và “ A#1 ”; loader phải từ chối, không tự gộp. So file chỉ có tên thừa khoảng trắng.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102; [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `TimCuonSachToanCuc`, dòng 30, 51.

<a id="TH251"></a>
### TH251 — Chỉ tìm sách có sẵn là truy vấn mới

**Thái · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH251).

**Trả lời ngắn:** Theo đặc tả mới chỉ B là đầu kết quả; n phải đếm các đầu thỏa đồng thời tên và khả dụng.

**Giải thích và bảo vệ cách làm:**

Phải chốt in mọi cuốn của B hay chỉ cuốn rảnh; hai lựa chọn đều khác bộ tìm hiện tại luôn in đủ trạng thái. Có thể dừng kiểm tồn tại ở cuốn rảnh đầu tiên, nhưng phần xuất đầy đủ vẫn cần duyệt danh mục.

**Đáp câu phụ 1:** Không; đây là bộ lọc kho. MuonSach vẫn kiểm thẻ, hạn mức, ngày và quan hệ khi xác nhận.

**Sai lầm dễ mắc:** Dừng sớm phép tồn tại được dùng luôn để bỏ các cuốn cần hiển thị.

**Cách kiểm chứng:** Đề xuất: A/B/C như trên, thêm đầu khớp không có cuốn; expected tập ISBN riêng và nội dung cuốn theo chế độ đã chọn.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `TimDauSachTheoTen`, dòng 84; [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `InMotDauSach`, dòng 14.

<a id="TH252"></a>
### TH252 — Một đầu có cuốn legacy và chuẩn cùng hậu tố nhìn giống

**Thái · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH252).

**Trả lời ngắn:** S001 và A#1 là hai mã khác nhau; cấp tiếp A#2 và top A cộng lượt của cả hai.

**Giải thích và bảo vệ cách làm:**

Legacy được tra bằng toàn chuỗi, không suy ISBN/hậu tố số. Bộ sinh chỉ lấy hậu tố từ mã chuẩn. Loại một cuốn mà giữ lịch sử tạo tham chiếu thiếu; gộp hai bản có thể làm các khoảng mượn đồng thời trở thành xung đột giả.

**Đáp câu phụ 1:** Chưa; không chồng thời gian không chứng minh cùng vật thể. Cần đối soát danh mục/tem thật trước di trú.

**Sai lầm dễ mắc:** Phần số giống nhau được coi là định danh thống nhất qua hai định dạng.

**Cách kiểm chứng:** Đề xuất: hai cuốn được mượn cùng thời gian bởi hai người vẫn hợp lệ; top cộng 2 và mã mới #2.

**Ca liên quan đã chạy 17/10 (không tái chạy đợt này):** [new_legacy_distinct](ThamKhao/KIEM_CHUNG_RUNTIME.md#new_legacy_distinct).

**Nguồn đối chiếu:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `TachMaMoi`, dòng 8; [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `SinhMaSachTuDong`, dòng 59; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `TimChuSoHuu`, dòng 98.

<a id="TH253"></a>
### TH253 — Dừng ngay sau đủ mười đầu có lượt

**Thái · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH253).

**Trả lời ngắn:** Hai đầu cuối phải lên hạng đầu nhưng sẽ không được xét; đủ 10 ứng viên chưa có nghĩa đã biết top của toàn kho.

**Giải thích và bảo vệ cách làm:**

Sau mỗi tiền tố, top chứa tối đa 10 đầu tốt nhất trong các đầu đã xét. Vì kho theo tên, không có cận đảm bảo đầu chưa xét có lượt thấp hơn; phải xét tất cả đầu có điểm.

**Đáp câu phụ 1:** Không: ứng viên đến sau không đứng trước ứng viên trước theo cùng tên–ISBN, nên top là 10 đầu đầu. Ca mọi điểm bằng nhau làm break tình cờ đúng. Muốn dừng tổng quát phải có cận chứng minh mọi đầu chưa xét không thể tốt hơn ngưỡng; thứ tự tên không cung cấp cận số lượt. Ca 100/50 lượt ở câu chính vẫn bác bỏ break.

**Sai lầm dễ mắc:** Kích thước kết quả đã đủ được nhầm là điều kiện hoàn thành lựa chọn.

**Cách kiểm chứng:** Đề xuất: 10 đầu ít lượt trước 2 đầu nhiều lượt; kiểm cả top và số ứng viên đã xét; thêm ca ứng viên bị loại khi j>=10.

**Kiểm mới 18/10:** [original_top_late](ThamKhao/KIEM_DINH_20261018.md#original_top_late), [original_top_ties](ThamKhao/KIEM_DINH_20261018.md#original_top_ties). Chỉ các assertion/quan sát nêu trong ca.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InTop10SachDuocMuonNhieuNhat`, dòng 172; [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `SoSanhDauSach`, dòng 9.

<a id="TH301"></a>
### TH301 — ISBN hợp lệ nhưng mã cuốn kế tiếp vượt 512 byte

**Thái · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH301).

**Trả lời ngắn:** 510 byte ISBN cộng # và số 10 tạo mã 513 byte, vượt HopLeVanBan≤512; SinhMaSachTuDong thất bại trước cấp phát/nối cuốn mới. Với ISBN 509 byte, mã #10 dài 512 nên qua cổng độ dài nếu các điều kiện khác hợp lệ.

**Giải thích và bảo vệ cách làm:**

Một đầu có ISBN hợp lệ không bảo đảm mọi mã ghép sau này hợp lệ. Cuốn #9 dài 512 vẫn hợp lệ; đây là giới hạn biểu diễn chuỗi, khác đầy MAX_BAN_GHI hoặc suffix INT_MAX. ThemCuonSach dùng maMoi cục bộ và chỉ gán output sau sinh mã, nên ở lỗi này output caller và danh sách giữ nguyên.

**Đáp câu phụ 1:** Không: prefix phải đúng ISBN chủ, còn lịch sử và tem dùng mã cũ. Có thể đề xuất giới hạn ISBN chặt hơn để dành chỗ cho suffix tối đa, nhưng đó là đổi điều kiện nhận dữ liệu cần xác nhận và tương thích file cũ; không tự cắt hoặc đổi mã đang dùng.

**Sai lầm dễ mắc:** Mỗi trường riêng hợp lệ suy ra chuỗi ghép mã luôn hợp lệ.

**Cách kiểm chứng:** Dựng hai fixture 509/510 byte với #9, gọi thêm, so bool/output/count và kiểm toàn vẹn trước–sau; không tạo tải lớn.

**Kiểm mới 18/10:** [original_code509](ThamKhao/KIEM_DINH_20261018.md#original_code509), [original_code510](ThamKhao/KIEM_DINH_20261018.md#original_code510). Chỉ các assertion/quan sát nêu trong ca.

**Nguồn đối chiếu:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `SinhMaSachTuDong`, dòng 59; [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `ThemCuonSach`, dòng 74; [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `HopLeVanBan`, dòng 42.

<a id="TH302"></a>
### TH302 — Năm xuất bản và ngày mượn được kiểm độc lập

**Thái · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH302).

**Trả lời ngắn:** Không có điều kiện so ngày mượn với namXuatBan. Đầu 2025 qua kiểm năm theo HomNay() trong năm 2026; ngày 2020 hợp lệ và không tương lai. Với lịch sử rỗng/các điều kiện khác hợp lệ, MuonSach có thể nhận và bộ kiểm không đối chiếu hai trường này.

**Giải thích và bảo vệ cách làm:**

Đây là khoảng trống kiểm quan hệ dữ liệu, chưa đủ gọi là vi phạm đề vì đề không quy định ràng buộc đó. --date không thay đồng hồ kiểm năm xuất bản. Không kể hành vi này thành tính năng nhập lịch sử tùy ý: các mốc độc giả/cuốn vẫn chặn ghi lùi khi đã có lịch sử.

**Đáp câu phụ 1:** Không có tháng/ngày phát hành. Có thể chọn quy tắc so năm tối thiểu sau khi thầy xác nhận, nhưng không suy ngày phát hành chính xác hoặc tự thêm trường. Dữ liệu cũ vi phạm quy tắc mới cũng cần chính sách, không sửa lịch sử âm thầm.

**Sai lầm dễ mắc:** Mọi liên hệ thực tế giữa các trường đều đã được code hoặc đề quy định.

**Cách kiểm chứng:** Fixture đầu 2025 và mượn 2020 trên máy 2026; kiểm API và KiemTraToanVen. Không thay đồng hồ hệ thống.

**Kiểm mới 18/10:** [original_publication_date](ThamKhao/KIEM_DINH_20261018.md#original_publication_date). Chỉ các assertion/quan sát nêu trong ca.

**Nguồn đối chiếu:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `HopLeDauSach`, dòng 27; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KiemTraNgayGiaoDich`, dòng 17; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102.

<a id="TH29"></a>
### TH29 — Thống kê số độc giả khác nhau

**Thái · P3 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH29).

**Trả lời ngắn:** Báo cáo mới phải cho A=2, B=1; top lượt cũ vẫn A=5, B=2.

**Giải thích và bảo vệ cách làm:**

Một độc giả mượn nhiều cuốn hoặc nhiều lượt cùng đầu chỉ đóng góp một cho đầu đó; trạng thái kết thúc không xóa việc từng mượn.

Tự chọn dữ liệu tạm, giải thích loại bỏ trùng theo đúng cặp độc giả–đầu sách và chi phí; đây là yêu cầu mở rộng.

Một phương án: dựng chỉ mục cuốn→chỉ số đầu như top; mảng unique[D] khởi tạo 0 và stamp[D] khởi tạo 0. Duyệt từng độc giả với mã dương duy nhất; với mỗi lượt tra owner, chỉ tăng unique[owner] khi stamp[owner] khác mã người rồi gán stamp đó. Mọi trạng thái đều tính nếu yêu cầu là từng mượn. Không cần xóa stamp D ô mỗi người. Chi phí O(D+C log C+R+H log C) cộng chuỗi, bộ nhớ O(C+D+R+MAX_DOC_GIA) với cách tạo view hiện tại; lỗi mã không có chủ phải từ chối, không tự gán.

**Đáp câu phụ 1:** Đúng về đếm nhưng reset thêm O(RD) kể cả người không lịch sử. Mã thẻ dương duy nhất trong snapshot dùng được làm dấu người, 0 là chưa gặp; duyệt mỗi người một lần nên không cần tự tăng generation. Stamp chỉ sống trong báo cáo, không tái dùng qua NAP hoặc giữa các snapshot.

**Sai lầm dễ mắc:** Distinct theo mã cuốn thay cho distinct người mượn.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Tự kiểm một người qua nhiều cuốn, nhiều người chung cuốn ở các thời điểm hợp lệ, đầu 0 lượt và hai báo cáo cùng chạy.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InTop10SachDuocMuonNhieuNhat`, dòng 172.

<a id="TH31"></a>
### TH31 — UTF-8 đúng chưa phải so tiếng Việt đầy đủ

**Thái · P3 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH31).

**Trả lời ngắn:** lap   trinh khớp hai tên không dấu; Lập trình khớp tên có dấu; LẬP TRÌNH không khớp tên có dấu chữ thường trong ví dụ. Helper chỉ hạ A..Z ASCII và gom một số whitespace ASCII.

**Giải thích và bảo vệ cách làm:**

UTF-8 của á dựng sẵn và a cộng dấu sắc khác nhau; NBSP không phải dấu cách mà KhoangTrang nhận. Bản hiện không tự chuẩn hóa các cặp này thành cùng khóa tìm.

GhepDauHienThi chỉ phục vụ bản vẽ, không thay byte dữ liệu gốc. tolower từng byte không thực hiện Unicode case folding hoặc chuẩn hóa tổ hợp.

Nếu đổi quy tắc tìm/so sánh, phải chốt phạm vi Unicode và kiểm nhất quán tìm, sắp, nhóm; không tự gộp định danh ISBN hay sửa lịch sử chỉ vì nhìn giống nhau.

**Đáp câu phụ 1:** Không; quy tắc tìm tên và định danh ISBN là hai hợp đồng. Gộp mã cần migration và xử lý va chạm riêng.

**Sai lầm dễ mắc:** Chuẩn hóa tìm kiếm tự cấp quyền hợp nhất định danh.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Lập expected độc lập cho ba truy vấn và hai cặp Unicode; kiểm cả byte dữ liệu sau hiển thị vẫn nguyên. Đây không phải bằng chứng đã thử mọi bộ gõ/terminal.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `KhoaSoSanh`, dòng 22; [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `ChuaChuoi`, dòng 31; [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `TimDauSachTheoTen`, dòng 84; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `GhepDauHienThi`, dòng 56.

<a id="TH34"></a>
### TH34 — Tham số owner còn giữ kết quả lần trước

**Thái · P3 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH34).

**Trả lời ngắn:** Mỗi lần tìm đặt owner về nullptr trước; mã không có và A#01 trả nullptr, owner cũng nullptr.

**Giải thích và bảo vệ cách làm:**

A#1 hợp lệ nếu tồn tại sẽ trả cuốn và owner A; mã có # sai chuẩn không rơi sang tìm mã cũ.

Wrapper nhận ThuVien thực sự mutable rồi dùng bản const để tra; không được dùng lập luận này để sửa một đối tượng vốn const.

**Đáp câu phụ 1:** Không; owner là output tùy chọn. Kết quả cuốn vẫn trả riêng nếu tìm được.

**Sai lầm dễ mắc:** Có output tùy chọn nghĩa caller luôn phải cung cấp vùng ghi.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Khởi tạo owner bằng con trỏ hợp lệ khác, gọi chuỗi tìm thất bại/thành công và kiểm cả hai kết quả.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `TimCuonSachToanCuc`, dòng 30, 51.

<a id="TH35"></a>
### TH35 — Lỗi trước khi gắn nút vào danh sách

**Thái · P3 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH35).

**Trả lời ngắn:** Nếu nối nút trước rồi gán ma thất bại, catch có thể báo dữ liệu không đổi trong khi cuốn đã được thêm.

**Giải thích và bảo vệ cách làm:**

Bản hiện tại chuẩn bị mã, vị trí, nút và output trước; commit là gắn con trỏ bằng release, không còn gán chuỗi.

unique_ptr giữ nút tạm trước commit; thoát sớm sẽ hủy nó. Không suy ra đã chạy kiểm lỗi cấp phát nếu chưa có công cụ gây lỗi.

**Đáp câu phụ 1:** Không; danh sách thư viện nhận sở hữu. Xóa thêm bằng con trỏ tạm sẽ phá nguồn hoặc double-free.

**Sai lầm dễ mắc:** release tương đương get và vẫn tự dọn đối tượng.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Truy quyền sở hữu từng bước; nếu làm fault injection thì chỉ trên bản sao, kiểm số nút và báo cáo bộ nhớ.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `ThemCuonSach`, dòng 74.

<a id="TH51"></a>
### TH51 — Danh sách cuốn có chu trình

**Thái · P3 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH51).

**Trả lời ngắn:** Các helper duyệt đến null giả định danh sách không vòng; có thể lặp vô hạn hoặc truy cập bộ nhớ đã giải phóng khi hủy.

**Giải thích và bảo vệ cách làm:**

Kiểm toàn vẹn có cận số bản ghi để phát hiện một số vòng, nhưng không sửa liên kết hay bảo đảm destructor an toàn. File bình thường không chứa địa chỉ để tạo vòng.

**Đáp câu phụ 1:** Không; việc thay bộ dữ liệu sẽ hủy bộ cũ bằng destructor vốn giả định cấu trúc hợp lệ. Cần cô lập/tháo vòng an toàn trong harness.

**Sai lầm dễ mắc:** Nạp file tốt tự chữa được mọi đồ thị con trỏ RAM hỏng.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Dùng sơ đồ hoặc harness cô lập có giới hạn thời gian; không tạo vòng trên phiên dữ liệu đang học.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `DemCuonSach`, dòng 102; [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `HuyDanhMucCuonSach`, dòng 99; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102.

<a id="TH52"></a>
### TH52 — Tối ưu nhập lô: tail, tổng cuốn, max mã và phạm vi commit

**Thái · P3 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH52).

**Trả lời ngắn:** Chưa. Mỗi lời gọi còn tìm đầu O(D), quét D đầu và C+j cuốn để kiểm tổng/sinh max, rồi tìm tail của c+j cuốn. Tổng cấu trúc O(kD+kC+k²), chưa tính độ dài chuỗi, kiểm đầu vào và cấp phát.

**Giải thích và bảo vệ cách làm:**

Thiết kế lô có thể tra đầu, kiểm tổng C, quét max hậu tố và xác định tail một lần; giữ tổng/max/tail cục bộ đúng phiên và cập nhật sau mỗi lần thêm thành công. Khi đó phần quét ban đầu O(D+C), phần còn lại O(k) thao tác cấu trúc cộng kiểm văn bản/sinh mã/cấp phát. Không được bỏ kiểm suffix INT_MAX, độ dài mã hay giới hạn tổng.

Cần chọn commit từng cuốn như đường gọi hiện tại hay nguyên lô. Nếu nguyên lô, chuẩn bị danh sách riêng có một chủ sở hữu, kiểm đủ k và tài nguyên trước nối; lỗi hủy vùng tạm. Nếu từng cuốn, lần thứ hai sai không được hoàn tác cuốn thứ nhất. Tail/max không sống qua NAP. Đây là thiết kế, chưa sửa sản phẩm.

**Đáp câu phụ 1:** Commit từng cuốn giữ cuốn thứ nhất, không thêm cuốn thứ hai. Nguyên lô giữ toàn bộ kho như trước lô. Muốn gọi tối ưu là giữ hành vi hiện tại phải chọn nhánh từng cuốn hoặc công bố đổi đặc tả; không chỉ so tốc độ và mã ở ca toàn thành công.

**Sai lầm dễ mắc:** Cache con trỏ đuôi có thể giữ vô hạn mà không quản lý lifetime.

**Cách kiểm chứng:** Đề xuất kiểm chứng: So khớp mã và dữ liệu khi lô bị lỗi ở giữa, đo riêng số lần duyệt đuôi/cấp mã.

**Kiểm mới 18/10:** [original_partial_batch](ThamKhao/KIEM_DINH_20261018.md#original_partial_batch). Chỉ các assertion/quan sát nêu trong ca.

**Nguồn đối chiếu:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `ThemCuonSach`, dòng 74; [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `SinhMaSachTuDong`, dòng 59.

<a id="TH58"></a>
### TH58 — Dữ liệu lặp làm tìm chuỗi con chậm

**Thái · P3 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH58).

**Trả lời ngắn:** Các tiền tố lặp khiến nhiều vị trí so gần hết từ khóa; thuật toán vét từng vị trí có cận O(L·M).

**Giải thích và bảo vệ cách làm:**

Chuẩn hóa không loại việc so lặp. Một thuật toán chuỗi khác là đề xuất tối ưu cần tự cài và kiểm giữ đúng ngữ nghĩa tìm.

**Đáp câu phụ 1:** Các vị trí bắt đầu có thể chồng nhau; nhảy cả mẫu bỏ những tiền tố còn phù hợp. KMP giữ độ dài tiền tố đúng dài nhất đồng thời là hậu tố phần đã khớp, dựng bảng O(M) rồi quét O(L+M), bộ nhớ O(M), trên chuỗi khóa đã chuẩn hóa. Đây là phương án chưa cài; với trường ≤512 byte còn phải tính chi phí chuẩn hóa và mức lặp truy vấn trước khi chọn.

**Sai lầm dễ mắc:** Độ phức tạp xấu nhất mô tả thời gian mọi bộ dữ liệu.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Đếm so sánh trên chuỗi lặp dài trong harness; không suy độ phức tạp từ một truy vấn nhanh.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `ChuaChuoi`, dòng 31.

<a id="TH79"></a>
### TH79 — Top tháng: lọc ngày mượn hay ngày trả sẽ kể câu chuyện khác

**Thái · P3 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH79).

**Trả lời ngắn:** Theo ngày mượn thuộc tháng 10: A không tính, B và C tính mỗi lượt 1. Đếm kết thúc trong tháng lại tính A/B, không tính C; đó là chỉ số khác.

**Giải thích và bảo vệ cách làm:**

Đặt bộ lọc trên lịch sử trước tăng dem sau khi đã xác định chủ; kiểm ngày đầu/cuối tháng và khoảng lọc hợp lệ. Top toàn thời gian nên giữ lựa chọn cũ.

Báo cáo cuối kỳ về trạng thái cần tái dựng khoảng giữ, không chỉ dùng trạng thái hiện tại; phải chốt yêu cầu trước sửa.

**Đáp câu phụ 1:** Không; phải trả lỗi hoặc tập rỗng theo đặc tả rõ, không âm thầm mở rộng phạm vi báo cáo.

**Sai lầm dễ mắc:** Bộ lọc sai được phép bỏ qua mà vẫn ghi nhãn top tháng.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Lập fixture với mốc máy phù hợp hoặc truy vết trên giấy; thêm lượt ở 30/09, 01/10, 31/10, 01/11 và so ba định nghĩa.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InTop10SachDuocMuonNhieuNhat`, dòng 172; [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `SoThuTuNgay`, dòng 112.

<a id="TH80"></a>
### TH80 — Top cuốn và top đầu không thể dùng chung khóa đếm

**Thái · P3 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH80).

**Trả lời ngắn:** Top đầu xếp A7 trước B6; top cuốn xếp B#1=6, A#2=4, A#1=3. Tổng lượt toàn kho vẫn 13.

**Giải thích và bảo vệ cách làm:**

Phải đếm theo danh tính cuốn, không cộng mọi cuốn vào chỉ số đầu; giữ liên kết để hiển thị tên nhưng không dùng tên làm khóa.

Có thể dùng chỉ mục cuốn tạm đang có và bộ đếm theo C, chọn top 10 trên C; chi phí chọn đổi 10D thành 10C, cần quy tắc hòa mã cuốn và báo cáo riêng.

**Đáp câu phụ 1:** Không; danh tính mới là mã cuốn, cần khóa phá hòa rõ. Tên chỉ phục vụ hiển thị, không thay đơn vị thống kê.

**Sai lầm dễ mắc:** Chỉ đổi tiêu đề hoặc lấy cuốn đầu của mỗi ISBN là đã có top theo cuốn.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Kiểm cả hai báo cáo đồng thời, mỗi lượt đóng góp đúng một cuốn và một đầu, kể cả cuốn thanh lý.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `ChiMucCuon`, dòng 96; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `TimChuSoHuu`, dòng 98; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InTop10SachDuocMuonNhieuNhat`, dòng 172.

<a id="TH81"></a>
### TH81 — Muốn giữ cache top giữa các giao dịch

**Thái · P3 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH81).

**Trả lời ngắn:** Chèn trước A đổi chỉ số nhưng không di chuyển đối tượng A; dùng vị trí 2 cũ có thể gán lượt sai đầu. Mượn thành công tăng lượt, trả/mất không tạo lượt mới; đổi tên còn có thể đổi thứ tự hòa.

**Giải thích và bảo vệ cách làm:**

Nạp thay toàn bộ nguồn, kể cả danh mục và lịch sử. Nếu phiên mới không có lượt, giữ các ô top cũ sẽ lộ dữ liệu phiên trước; không được chỉ cập nhật khi gặp số đếm dương.

Code hiện dựng index, dem được zero-initialize và k=0 cho mỗi lần gọi. Bỏ {} làm phép ++ đọc int chưa khởi tạo: hành vi không xác định trong C++17, khác lỗi logic cache chưa reset.

Cache lâu dài phải có quy tắc làm mới cho chèn, giao dịch, đổi khóa hiển thị và nạp; xem xét cả con trỏ, chỉ số và điểm đếm. Đo lợi ích trước, không tự thêm trường nghiệp vụ vào cấu trúc đề.

**Đáp câu phụ 1:** Có; cùng path không đồng nghĩa cùng version dữ liệu, các pointer/chỉ số/counters cũ có thể sai.

**Sai lầm dễ mắc:** Đường dẫn không đổi nên cache luôn còn đúng.

**Cách kiểm chứng:** Đề xuất kiểm chứng: So với kết quả tính lại từ đầu sau từng sự kiện; đặc biệt nạp phiên không có lượt phải ra rỗng. Biến thể bỏ khởi tạo chỉ phân tích hoặc dùng công cụ phù hợp, không coi một lần chạy ra 0 là bằng chứng.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InTop10SachDuocMuonNhieuNhat`, dòng 172; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `DocFile`, dòng 349; [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `ThemDauSach`, dòng 64.

<a id="TH90"></a>
### TH90 — Lấy đúng k người quá hạn thay vì tất cả

**Thái · P3 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH90).

**Trả lời ngắn:** Đúng 5 người phải là mã 80..84: mức quá hạn giảm, mã thẻ tăng khi hòa. Inorder theo mã chọn 1..5 trước sẽ bỏ cả nhóm nặng hơn; sắp sau khi cắt không cứu được ứng viên đã mất.

**Giải thích và bảo vệ cách làm:**

Với K người quá hạn, cách hiện tại quét R+H rồi sắp K, tốn O(R+H+K log(K+1)) phép xử lý/so sánh ngoài độ dài chuỗi. rows cấp theo R và stack duyệt theo MAX_DOC_GIA, không chỉ theo 5 dòng in.

Giữ top 5 có thể giảm khâu chọn xuống O(5R) và mảng xếp hạng còn 5 ô, nhưng vẫn phải quét lịch sử để tính mức của mọi ứng viên; các mảng view/helper còn lại không tự mất. Nếu lấy tất cả đồng mức ngưỡng thứ năm, phải in cả 20 người 80..99 theo đặc tả mới.

**Đáp câu phụ 1:** Không; miền ứng viên là người thật sự quá hạn. Cần ghi ba kết quả, không điền bằng người có điểm 0.

**Sai lầm dễ mắc:** Cắt 5 người theo mã rồi sort sẽ tìm được 5 người quá hạn nặng nhất.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Truy cùng bộ dữ liệu bằng comparator hiện tại; đổi hình BST không đổi kết quả. Thử K<5, K=0 và khóa hòa; tách yêu cầu đúng 5 khỏi tất cả đồng hạng.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InDocGiaQuaHan`, dòng 148; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `SapXepHeap`, dòng 88.

<a id="TH94"></a>
### TH94 — Đối soát kho theo ba trạng thái không được lấy phép trừ thiếu

**Thái · P3 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH94).

**Trả lời ngắn:** A tổng 6 nhưng tổng trừ đang mượn=5 gồm 2 sẵn+3 thanh lý; B phải có các số 0. Cần đếm từng trạng thái cuốn riêng.

**Giải thích và bảo vệ cách làm:**

Đối chiếu phiếu mở là phép nối theo mã, không chỉ so tổng: hai mã lệch nhau có thể vẫn cho tổng bằng nhau.

Báo cáo chỉ đọc có thể ghi cảnh báo; KiemTraToanVen kiểm tương đương từng cuốn với số lượt mở. Không chữa bằng cách cộng trừ để làm tổng đẹp.

**Đáp câu phụ 1:** Không; sai lệch có thể bù nhau. Phải đối chiếu theo từng mã cuốn và điều kiện đúng một lượt mở.

**Sai lầm dễ mắc:** Đối soát tổng thay được đối soát danh tính.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Dựng thêm RAM lỗi có một cuốn thiếu phiếu và cuốn khác dư phiếu để tổng vẫn bằng; kiểm cảnh báo theo mã.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `DemCuonSach`, dòng 102; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `TongQuan`, dòng 263.

<a id="TH99"></a>
### TH99 — Tối ưu tìm kiếm nhưng expected dùng chính hàm đang sửa

**Thái · P3 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH99).

**Trả lời ngắn:** Nếu actual và expected dùng cùng lỗi, test chỉ so một hàm với chính nó. Cần expected tính tay cho ví dụ nhỏ hoặc thuật toán tham chiếu độc lập trong harness, ghi rõ phạm vi được phép.

**Giải thích và bảo vệ cách làm:**

Các quan hệ hữu ích: thêm đầu không khớp không đổi tập kết quả cũ; đổi ASCII hoa/thường giữ kết quả theo hợp đồng; đặt từ khóa ở cuối vẫn phải khớp.

Quy định DSA cần tuân trong mã đồ án; công cụ kiểm thử bên ngoài phải phân biệt và hỏi thầy nếu có yêu cầu chung. Không dùng test harness để lách thuật toán sản phẩm.

**Đáp câu phụ 1:** Không; cùng cấu trúc lỗi có thể cho cùng kết quả sai. Cần expected tay hoặc cách xây oracle khác được kiểm.

**Sai lầm dễ mắc:** Hai hàm khác tên tự động là hai nguồn kiểm độc lập.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Thiết kế ít nhất một test giết được lỗi bỏ vị trí cuối và một test Unicode không được giả định case-fold đầy đủ.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `ChuaChuoi`, dòng 31; [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `TimDauSachTheoTen`, dòng 84.

<a id="TH100"></a>
### TH100 — Đề nghị xóa lịch sử trả cũ để nhẹ file

**Thái · P3 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TH100).

**Trả lời ngắn:** Top đếm từ từng lịch sử nên giảm nếu xóa; kiểm mốc gần nhất/chuỗi giao dịch mất các sự kiện đã xóa, khả năng chứng minh quá khứ cũng giảm.

**Giải thích và bảo vệ cách làm:**

Một tổng số lượt không giữ ngày, độc giả và quan hệ trước–sau; nó không thay được lịch sử để kiểm chuỗi hoặc giải thích giao dịch.

Hiện không có chức năng purge; phải chốt chính sách lưu giữ và báo cáo trước khi mở rộng, giữ đúng cấu trúc đề. Có thể giảm chi phí serialization/đọc mà chưa xóa bằng chứng nghiệp vụ.

**Đáp câu phụ 1:** Không; phép gom đã mất người/ngày/thứ tự. Muốn trả lời phải giữ dữ liệu chi tiết hoặc kho lịch sử được thiết kế riêng.

**Sai lầm dễ mắc:** Một số tổng là bản nén không mất thông tin của toàn bộ lịch sử.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Lấy một cuốn đã trải qua nhiều người, vẽ những câu hỏi còn trả lời được và không trả lời được sau xóa; đối chiếu top trước/sau trên bản sao.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KiemTraDongThoiGian`, dòng 25; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InTop10SachDuocMuonNhieuNhat`, dòng 172; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102.


<a id="thanh"></a>
## Thành — 100 đáp án

<a id="TV01"></a>
### TV01 — Ai được mượn khi hai người cùng chọn một cuốn?

**Thành · P1 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV01).

**Trả lời ngắn:** Khi cả hai hợp lệ, A thành công: thêm một lượt trạng thái 0, X#1 chuyển 0→1. B bị từ chối vì cuốn đang mượn; lịch sử B vẫn rỗng.

**Giải thích và bảo vệ cách làm:**

Khi A bị khóa, A bị chặn trước bước tìm cuốn, không thay đổi dữ liệu. B sau đó mượn thành công; chỉ B có lượt mới.

Đây là xử lý tuần tự trong một tiến trình. Đề không có đặt trước/hàng chờ; không tự thêm. Hai chương trình cùng mở file là bài toán khác, chưa được bảo đảm.

**Đáp câu phụ 1:** Không; commit RAM và lưu file là hai mốc. Mở lại có thể thấy snapshot cũ, cần đối soát thực tế.

**Sai lầm dễ mắc:** Xử lý tuần tự đúng trong RAM tự bảo đảm bền vững trên đĩa.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Chạy hai kịch bản từ cùng dữ liệu ban đầu; sau mỗi yêu cầu kiểm trạng thái cuốn, số lượt từng người và chủ của lượt đang mở.

**Ca liên quan đã chạy 17/10 (không tái chạy đợt này):** [sequential_same_copy](ThamKhao/KIEM_CHUNG_RUNTIME.md#sequential_same_copy).

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114.

<a id="TV02"></a>
### TV02 — Đang giữ một cuốn, mượn thêm hai cuốn có được không?

**Thành · P1 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV02).

**Trả lời ngắn:** Kịch bản đầu chấp nhận cả hai: số cuốn đang mượn 1→2→3, thêm hai lượt riêng. Quy tắc hiện tại giới hạn cuốn, không cấm nhiều cuốn cùng ISBN.

**Giải thích và bảo vệ cách làm:**

Nếu X#3 do B giữ, X#2 vẫn thành công; yêu cầu X#3 thất bại. A giữ hai cuốn, giao dịch thành công trước đó không bị hoàn tác.

Nếu X#1 mượn từ 01/10, A đang quá hạn tại 16/10 nên cả hai yêu cầu mới bị chặn; cuốn sẵn sàng không đủ để được mượn.

**Đáp câu phụ 1:** Không; hạn mức đếm cuốn/lượt mở, không đếm số ISBN khác nhau.

**Sai lầm dễ mắc:** Ba đầu sách khác nhau mới là miền áp dụng giới hạn 3.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Đối chiếu riêng từng mã cuốn, số lượt mới và số trạng thái đang mượn; không lấy số ISBN hoặc tổng chiều dài lịch sử làm số cuốn đang giữ.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114; [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `DemSoSachDangMuon`, dòng 5.

<a id="TV03"></a>
### TV03 — Đã giữ ba cuốn: đổi thứ tự thao tác có đổi kết quả?

**Thành · P1 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV03).

**Trả lời ngắn:** Mượn trước bị chặn ở giới hạn ba cuốn; trả X#1 sau đó thành công. Kết thúc A giữ hai cuốn, W#1 vẫn sẵn sàng, không có lượt W#1 mới.

**Giải thích và bảo vệ cách làm:**

Trả trước làm số đang giữ 3→2; mượn W#1 sau đó thành công, 2→3. Lịch sử tăng một nút; lượt X#1 cũ được cập nhật thành đã trả.

Chương trình không lưu yêu cầu mượn thất bại để tự chạy lại. Không có hàng chờ hoặc giao dịch gộp hai thao tác.

**Đáp câu phụ 1:** Gửi yêu cầu mượn mới và kiểm lại điều kiện; không có retry tự động hay giữ chỗ cho yêu cầu cũ.

**Sai lầm dễ mắc:** Một yêu cầu thất bại tự được xếp chờ khi điều kiện về sau thay đổi.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Khôi phục dữ liệu trước khi đổi thứ tự; kiểm cả nội dung lịch sử thay vì chỉ nhìn số cuốn cuối cùng.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `TraSach`, dòng 139.

<a id="TV04"></a>
### TV04 — Quá hạn, khóa thẻ và quyền trả sách tương tác thế nào?

**Thành · P1 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV04).

**Trả lời ngắn:** 08→15/10 bằng bảy ngày, chưa quá hạn; mượn Y#1 được nếu các điều kiện khác hợp lệ. 08→16/10 bằng tám ngày, yêu cầu mượn mới bị chặn.

**Giải thích và bảo vệ cách làm:**

Thẻ khóa vẫn được trả X#1: lượt đổi 0→1, ngày trả 16/10, cuốn đổi 1→0. Việc trả không tự mở khóa thẻ.

Xin mượn Y#1 sau trả vẫn bị chặn do thẻ khóa. Phân biệt quyền mượn mới với quyền kết thúc một lượt đã có.

**Đáp câu phụ 1:** Chưa; predicate chỉ cần còn một lượt mở quá 7 ngày để chặn, chưa kể thẻ và hạn mức.

**Sai lầm dễ mắc:** Trả một cuốn quá hạn sẽ xóa trạng thái quá hạn của cả người.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Hai phép thử ngày phải bắt đầu từ bản sao riêng. Kiểm đúng hiệu ngày lịch, không dùng phép trừ số ngày trong tháng.

**Ca liên quan đã chạy 17/10 (không tái chạy đợt này):** [seven_eight_15](ThamKhao/KIEM_CHUNG_RUNTIME.md#seven_eight_15), [seven_eight_16](ThamKhao/KIEM_CHUNG_RUNTIME.md#seven_eight_16), [leap_seven](ThamKhao/KIEM_CHUNG_RUNTIME.md#leap_seven), [leap_eight](ThamKhao/KIEM_CHUNG_RUNTIME.md#leap_eight).

**Nguồn đối chiếu:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `QuaHan7Ngay`, dòng 124; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KetThucMuon`, dòng 54.

<a id="TV05"></a>
### TV05 — Trả, bấm trả lại rồi người khác mượn lại cùng ngày

**Thành · P1 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV05).

**Trả lời ngắn:** Lần trả đầu chỉ cập nhật lượt thứ ba của A; hai lượt cũ giữ nguyên. Lần trả thứ hai thất bại vì A không còn lượt đang mở.

**Giải thích và bảo vệ cách làm:**

B mượn cùng ngày được: cuốn 0→1 và lịch sử B thêm một lượt. A trả tiếp bị từ chối, không đóng lượt của B hoặc đổi cuốn về 0.

Tìm theo mã phải kèm trạng thái đang mượn và đúng độc giả. Lệnh lặp bị từ chối, nhưng trạng thái sau thất bại không đổi; không gọi đó là thành công lần hai.

**Đáp câu phụ 1:** Không; mượn thành công tạo lượt mới, còn node cũ giữ sự kiện cũ.

**Sai lầm dễ mắc:** Cùng mã cuốn thì chỉ cần một node lịch sử được bật/tắt qua mọi lần.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Lưu dấu nhận diện từng nút trước chuỗi; kiểm đúng một nút cũ đổi và đúng một nút mới thuộc B được thêm.

**Ca liên quan đã chạy 17/10 (không tái chạy đợt này):** [return_then_other_borrow_old_return](ThamKhao/KIEM_CHUNG_RUNTIME.md#return_then_other_borrow_old_return).

**Nguồn đối chiếu:** [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `TimMuonDangMuonTheoMa`, dòng 14; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KetThucMuon`, dòng 54.

<a id="TV06"></a>
### TV06 — Báo mất có kết thúc mọi khoản mượn không?

**Thành · P1 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV06).

**Trả lời ngắn:** Báo mất X#1: lượt 0→2, ngày trả ghi ngày báo mất, cuốn 1→2, thẻ 1→0. Y#1 vẫn đang mượn; số đang mượn giảm 2→1.

**Giải thích và bảo vệ cách làm:**

Mượn Z#1 bị chặn; trả Y#1 vẫn thành công và số đang mượn về 0. Báo mất lặp thất bại; mở thẻ bị chặn vì còn lịch sử mất.

Dùng ngày trả làm ngày báo mất, chuyển cuốn sang thanh lý và chưa hỗ trợ xử lý xong mất là giả định G05, không phải quy tắc giảng viên đã xác nhận.

**Đáp câu phụ 1:** Không; chỉ X bị đổi cùng phiếu mất. Khóa thẻ không đổi trạng thái các cuốn khác A đang giữ.

**Sai lầm dễ mắc:** Báo mất một cuốn kết thúc toàn bộ khoản mượn của người đó.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Kiểm cả hai lượt riêng, Z#1 không đổi, thẻ còn khóa sau khi trả hết; không xóa lịch sử mất để ép mở thẻ.

**Ca liên quan đã chạy 17/10 (không tái chạy đợt này):** [lost_then_return_other](ThamKhao/KIEM_CHUNG_RUNTIME.md#lost_then_return_other).

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `DanhDauMatSach`, dòng 142; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KetThucMuon`, dòng 54; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `HieuChinhDocGia`, dòng 73.

<a id="TV07"></a>
### TV07 — Nút kế tiếp có lịch sử riêng: xóa gốc thế nào?

**Thành · P1 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV07).

**Trả lời ngắn:** 50 trở thành gốc; trái 20, phải 70; trái của 70 thành 60. Mọi khóa vẫn thỏa cận BST, 40 bị loại và mốc mã đã cấp không giảm.

**Giải thích và bảo vệ cách làm:**

Code di chuyển nguyên nút 50, giữ thông tin và danh sách lịch sử của chính độc giả 50. Chỉ nút 40 cũ bị delete.

Chỉ chép maThe sẽ gán định danh 50 cho hồ sơ khác, làm mất liên kết thông tin/lịch sử. Sao chép nông cả DocGia rồi hủy sai cũng có thể gây con trỏ treo.

**Đáp câu phụ 1:** Không; bất kỳ lịch sử nào cũng chặn xóa trước xử lý cấu trúc.

**Sai lầm dễ mắc:** Trả hết là đủ điều kiện xóa người và mọi lịch sử của họ.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Kiểm inorder 20,50,60,70; tìm lại 50 với đúng hai lượt; kiểm 40 không còn và mọi nút còn lại chỉ được hủy một lần.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `XoaDocGia`, dòng 85.

<a id="TV08"></a>
### TV08 — Xóa mã lớn nhất rồi lưu lại có được cấp lại mã?

**Thành · P1 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV08).

**Trả lời ngắn:** Thêm đầu cấp 21, mốc thành 21. Xóa và lưu–nạp vẫn giữ mốc 21; tên rỗng thất bại không tiêu thụ mã; thêm hợp lệ tiếp theo cấp 22.

**Giải thích và bảo vệ cách làm:**

Mốc INT_MAX làm yêu cầu thất bại trước phép cộng, không quay vòng về âm/0 hoặc lấy khoảng trống trong cây để cấp lại.

Mã lớn nhất còn trong BST và số độc giả không thể thay thế mốc từng cấp: hai giá trị đó có thể giảm sau xóa.

**Đáp câu phụ 1:** 21; mốc thuộc lịch sử cấp mã, không tính lại từ số node hoặc max hiện có.

**Sai lầm dễ mắc:** Cây rỗng đồng nghĩa chưa từng cấp thẻ.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Kiểm metadata file sau xóa và sau nhập thất bại; bảo đảm đầu ra mã của lần thành công được dùng, không đọc biến mã cũ sau thất bại.

**Ca liên quan đã chạy 17/10 (không tái chạy đợt này):** [delete_keep_highwater](ThamKhao/KIEM_CHUNG_RUNTIME.md#delete_keep_highwater).

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `ThemDocGia`, dòng 64; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `XoaDocGia`, dòng 85; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `Ghi`, dòng 273.

<a id="TV09"></a>
### TV09 — Thiếu bộ nhớ ở giữa thao tác mượn

**Thành · P1 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV09).

**Trả lời ngắn:** Thất bại trước commit giữ nguyên danh sách lịch sử, số đang mượn, cuốn Y#1 và thẻ. unique_ptr hủy nút tạm nếu việc gán chuỗi ném ngoại lệ.

**Giải thích và bảo vệ cách làm:**

Code chỉ nối lượt vào tail sau mọi kiểm tra/cấp phát; ngay sau đó đổi cuốn sang đang mượn. Hai bước này không cấp phát hoặc sao chép chuỗi.

Đổi cuốn trước khi có lượt hoàn chỉnh có thể để cuốn trạng thái 1 nhưng không có lượt mở. Bảo đảm này dành cho thực thi tuần tự, không chống mọi sự cố tiến trình.

**Đáp câu phụ 1:** Không; chỉ hai bước không cấp phát trong mô hình tuần tự. Đồng thời cần bảo vệ toàn pha kiểm–commit và dữ liệu liên quan.

**Sai lầm dễ mắc:** Exception safety trong một luồng là thread safety.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Đọc vị trí release và phép gán trạng thái; nếu mô phỏng lỗi, dùng bộ kiểm riêng, so trạng thái trước/sau và không gọi mô phỏng là lỗi đã gặp thực tế.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114.

<a id="TV10"></a>
### TV10 — Cuốn rảnh nhưng ngày giao dịch vẫn bị chặn

**Thành · P1 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV10).

**Trả lời ngắn:** A/X ngày 15 bị mốc của A ngày 16 chặn. C/X ngày 14 bị mốc của chính cuốn X ngày 15 chặn dù C chưa có lịch sử. C/Z ngày 15 được nhận: giao dịch ngày 16 của A/Y không liên quan.

**Giải thích và bảo vệ cách làm:**

A/X ngày 16 được nhận nếu các điều kiện còn lại hợp lệ; ngày bằng mốc được phép. Mỗi ca chạy từ bản dữ liệu ban đầu riêng, chỉ ca thành công mới thêm phiếu và đổi cuốn.

Helper quét max trên các lượt thuộc độc giả HOẶC có cùng mã cuốn, không lấy node cuối hay giao của hai điều kiện. Đảo liên kết không đổi max; dùng mốc toàn thư viện sẽ chặn cả giao dịch không liên quan theo một chính sách khác.

**Đáp câu phụ 1:** Không theo điều kiện OR liên quan hiện tại; vẫn quét để đếm nhưng không dùng ngày đó làm mốc A/X.

**Sai lầm dễ mắc:** Ngày mới nhất bất kỳ là mốc hợp lệ của mọi giao dịch.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Chuẩn bị bốn bản dữ liệu độc lập; đối chiếu số phiếu, trạng thái X/Z và lỗi từng lần. Đảo thứ tự lịch sử hợp lệ rồi so lại mốc/kết quả.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KiemTraDongThoiGian`, dòng 25; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114.

<a id="TV11"></a>
### TV11 — Hiện không giữ cuốn nào nhưng lịch sử vẫn vô lý

**Thành · P1 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV11).

**Trả lời ngắn:** Bốn khoảng 01–10/10 chồng lấn làm số giữ từng vượt ba, nên bị từ chối dù hiện tại đều đã trả.

**Giải thích và bảo vệ cách làm:**

Bốn lượt mượn–trả cùng 10/10 có thể diễn ra nối tiếp, được chấp nhận nếu dữ liệu khác hợp lệ. Ba cuốn giữ xuyên ngày cộng lượt trong ngày bị từ chối.

Bộ đọc quét sự kiện theo độc giả/ngày: kết thúc lượt cũ, lượt mượn–trả cùng ngày, rồi lượt bắt đầu giữ qua ngày; kiểm tính khả thi theo độ chính xác ngày.

Khi chỉ hai chỗ bị giữ xuyên ngày, các lượt mượn–trả cùng ngày có thể dùng nối tiếp chỗ thứ ba. V1 kiểm tồn tại thứ tự hợp lệ theo ngày, không có giờ để xác nhận đúng thứ tự thực tế ngoài đời.

**Đáp câu phụ 1:** Không; chỉ chứng minh tồn tại thứ tự khả thi theo độ chính xác ngày. Không có giờ hoặc audit để xác minh ngoài đời.

**Sai lầm dễ mắc:** Chấp nhận dữ liệu nghĩa đã chứng minh trình tự lịch sử thực.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Tạo ba file bản sao với các mã cuốn khác nhau, cuốn đều trạng thái 0; kiểm lỗi giới hạn lịch sử thay vì lỗi liên kết khác.

**Ca liên quan đã chạy 17/10 (không tái chạy đợt này):** [four_overlap](ThamKhao/KIEM_CHUNG_RUNTIME.md#four_overlap), [four_same_day](ThamKhao/KIEM_CHUNG_RUNTIME.md#four_same_day).

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `MocMuon`, dòng 91.

<a id="TV12"></a>
### TV12 — Cây cân bằng có làm ThemDocGia thành O(log R)?

**Thành · P1 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV12).

**Trả lời ngắn:** ThemDocGia gọi DemDocGia duyệt toàn cây O(R), rồi chèn O(h); tổng O(R+h), tức O(R) trong giới hạn cây hợp lệ, chưa tính độ dài chuỗi.

**Giải thích và bảo vệ cách làm:**

Cân bằng lúc nạp chỉ giảm h ban đầu. Thêm mã tăng liên tiếp kéo dài nhánh phải; code không có phép cân bằng sau chèn như AVL.

Bộ duyệt cấp phát mảng MAX_DOC_GIA con trỏ, không phải chỉ h ô. Phân biệt số ô thực dùng với dung lượng mảng thực cấp phát.

Lấp chỗ trống tái dùng mã đã xóa, trái quy tắc mốc tăng; cấp ngẫu nhiên đổi quy tắc cấp mã và không bảo đảm cây cân bằng. Phải phân biệt đổi hợp đồng với tối ưu thuật toán trong đúng ràng buộc BST thường, không tự chuyển sang AVL.

Từ rỗng, N lần thêm phải đếm 0+1+…+(N−1)=N(N−1)/2 node, nên O(N²) ngay cả giả định cây luôn cân bằng. Với cây thường mã tăng, đường chèn cũng suy biến. Loader sort rồi dựng cân bằng là đường khác, không phải N lần ThemDocGia; bypass bằng ChenDocGiaCoMa còn mất kiểm giới hạn/mốc.

**Đáp câu phụ 1:** Tăng chỉ sau chèn thành công; giảm chỉ sau xóa thành công; nạp phải nhận số của bộ mới, hủy/reset và swap phải xử lý cùng phiên. Lỗi/hủy không đổi count. Chèn qua helper thấp cũng phải có hợp đồng rõ. Nếu count lệch, cổng MAX sai dù cây tìm được; cải thiện O(h) mỗi thêm chỉ có khi metadata được duy trì đúng và được phép.

**Sai lầm dễ mắc:** Một helper logarithmic làm toàn đường gọi logarithmic.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Lần theo chuỗi lời gọi DemDocGia→LayDanhSachDocGia và ChenDocGiaCoMa; không kết luận độ phức tạp toàn hàm chỉ từ vòng tìm trên BST.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `ThemDocGia`, dòng 64; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `DemDocGia`, dòng 33; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `ChenDocGiaCoMa`, dòng 51.

<a id="TV29"></a>
### TV29 — Hai người trùng họ tên, sửa nhầm hồ sơ sẽ tác động ai?

**Thành · P1 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV29).

**Trả lời ngắn:** HieuChinhDocGia chỉ thay thông tin được phép và trạng thái thẻ, giữ mã/cây/lịch sử; X vẫn thuộc 10. Trùng tên không chứng minh cùng người.

**Giải thích và bảo vệ cách làm:**

Đổi maThe trực tiếp có thể phá BST; gộp theo tên có thể chuyển nghĩa vụ giữa hai người thật. Cần định danh và đối chiếu giấy tờ ngoài mô hình trước đề xuất sửa.

Hiện chưa có chức năng chuyển lượt mượn. Một mở rộng phải kiểm hạn mức, quá hạn, thời gian, trạng thái cuốn và nguồn dấu vết, không chỉ chuyển con trỏ lịch sử.

**Đáp câu phụ 1:** Không; dữ liệu mô tả không đủ chứng minh nhân thân, cần xác minh ngoài mô hình trước chính sách hợp nhất.

**Sai lầm dễ mắc:** Mã khác nhưng trường giống là lỗi trùng cần tự gộp.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Sau sửa 20, tìm cả hai mã và xem h; lập trạng thái mong đợi cho phương án điều chỉnh trên bản sao trước khi code.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `ThemDocGia`, dòng 64; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `HieuChinhDocGia`, dòng 73; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114.

<a id="TV13"></a>
### TV13 — Một trường đúng không đủ để cho mượn hoặc trả

**Thành · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV13).

**Trả lời ngắn:** B bị chặn vì quét thấy lượt đang mở dù cuốn ghi sẵn sàng. A trả bị chặn ngay vì cuốn không ở trạng thái đang mượn.

**Giải thích và bảo vệ cách làm:**

Khi cuốn trạng thái 1 nhưng có hai lượt mở, trả của một người bị chặn bởi dangMuon!=1; không tùy chọn một lượt rồi tiếp tục.

Các hàm báo lỗi và giữ nguyên dữ liệu, không tự suy bên nào đúng. Đây là ca lỗi giả lập trên bản sao, không khẳng định dữ liệu sản phẩm đang hỏng.

**Đáp câu phụ 1:** Không; kiểm phải trên đúng cuốn và chủ. Tổng bằng nhau không bảo vệ mapping.

**Sai lầm dễ mắc:** Đối soát tổng thay được đối soát từng khóa.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Chụp cả hai lịch sử và cuốn trước/sau từng lệnh; phân biệt nhánh kiểm trạng thái cuốn với nhánh kiểm số lượt mở toàn thư viện.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KetThucMuon`, dòng 54; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KiemTraDongThoiGian`, dòng 25.

<a id="TV14"></a>
### TV14 — Đổi tên hoặc khóa thẻ có cần chuyển nút BST?

**Thành · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV14).

**Trả lời ngắn:** Tên/họ/trạng thái thẻ đổi; mã 20, vị trí nút và con trỏ lịch sử giữ nguyên. Khóa thẻ không tự trả X#1 hoặc xóa lượt mở.

**Giải thích và bảo vệ cách làm:**

Hàm hiệu chỉnh không cung cấp đổi maThe. Sửa 20→70 ở cây con trái của 40 phá bất biến; tìm 70 đi sang phải nên có thể không gặp nút.

Bộ kiểm truyền khoảng khóa hợp lệ xuống cây, phát hiện vi phạm với tổ tiên; so mỗi nút với hai con trực tiếp chưa đủ cho mọi cây.

**Đáp câu phụ 1:** Không; phải giữ cận từ mọi tổ tiên. Một cạnh cục bộ đúng vẫn có thể vi phạm miền toàn nhánh.

**Sai lầm dễ mắc:** BST chỉ cần so với hai con trực tiếp.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Kiểm mã định danh và địa chỉ nút trước/sau chỉnh thông tin; ví dụ lỗi đổi khóa chỉ thực hiện trong fixture độc lập.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `HieuChinhDocGia`, dòng 73; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `TimDocGia`, dòng 8, 13; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102.

<a id="TV17"></a>
### TV17 — 100.000 nút lệch có làm tràn call stack?

**Thành · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV17).

**Trả lời ngắn:** Duyệt inorder dùng vòng lặp và stack trên heap cấp MAX_DOC_GIA con trỏ; cây lệch trái có thể dùng đủ số ô đó, tránh chiều sâu đệ quy 100.000.

**Giải thích và bảo vệ cách làm:**

Hủy cây quay liên kết để lần lượt đưa nút không có con trái ra hủy; hủy lịch sử của nút trước delete. Chi phí O(R+H), bộ nhớ phụ O(1).

Cuối cùng root=nullptr, toàn bộ node lịch sử được giải phóng. Không cần giữ hình dạng BST trong quá trình hủy; con trỏ view cũ không còn dùng được.

**Đáp câu phụ 1:** Không; HuyCayDocGia chỉ quản cây/lịch sử. HuyThuVien mới đặt metadata toàn thư viện về 0.

**Sai lầm dễ mắc:** Hủy một cấu trúc con tự đồng bộ mọi metadata của đối tượng bao.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Truy vết trước trên cây 3→2→1 có một nhánh phải; nếu kiểm cây lớn phải dùng fixture riêng và công cụ bộ nhớ phù hợp.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `LayDanhSachDocGia`, dòng 18; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `HuyCayDocGia`, dòng 103; [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `HuyDanhSachMuonTra`, dòng 18.

<a id="TV19"></a>
### TV19 — File hợp lệ có chứng minh từng lần mượn đúng quyền?

**Thành · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV19).

**Trả lời ngắn:** Với dữ liệu đã nêu và các trường còn lại hợp lệ, bộ đọc không loại riêng vì điều kiện quá hạn lúc cấp lượt ngày 10; hai lượt không vi phạm giới hạn ba cuốn.

**Giải thích và bảo vệ cách làm:**

MuonSach ở thời điểm 10/10 sẽ chặn khi còn X#1 quá hạn. Bộ kiểm file hiện tại không tái hiện toàn bộ quyết định cấp quyền trong quá khứ.

V1 chỉ lưu trạng thái thẻ hiện tại, không có lịch sử khóa/mở, nên không xác nhận được thẻ hoạt động vào ngày 10. Hợp lệ cấu trúc không đồng nghĩa chứng minh mọi nghiệp vụ quá khứ.

**Đáp câu phụ 1:** Không; cần lịch sử thay trạng thái nếu đặc tả yêu cầu xác minh quá khứ. Giá trị hiện tại không đủ.

**Sai lầm dễ mắc:** Một snapshot trạng thái đại diện cho trạng thái ở mọi ngày.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Đối chiếu các điều kiện thật trong KiemTraNoiBo với MuonSach; không gán cho validator kiểm tra không có trong code.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114.

<a id="TV20"></a>
### TV20 — Trả và mượn lại cùng ngày khác với lịch sử chồng lấn

**Thành · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV20).

**Trả lời ngắn:** B mượn 09/10 chồng lấn với lượt A đến 10/10 nên file bị từ chối. B bắt đầu 10/10 có thể là sau lúc A trả, được phép theo độ chính xác ngày.

**Giải thích và bảo vệ cách làm:**

Nếu lượt trước kết thúc bằng mất, bộ kiểm không cho lượt mượn kế tiếp của cùng cuốn, kể cả không chồng ngày và các trạng thái hiện tại đã sửa phù hợp.

Bộ kiểm sắp view theo cuốn, ngày bắt đầu/kết thúc rồi xét các lượt kề nhau; không phụ thuộc các độc giả xuất hiện trước sau trong file.

**Đáp câu phụ 1:** Không; validator dựng/sắp view các lượt theo cuốn và ngày rồi kiểm, không tin thứ tự vật lý dòng người.

**Sai lầm dễ mắc:** Thứ tự xuất hiện trong file quyết định thời gian giao dịch.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Dùng ba file riêng, giữ các trường không liên quan giống nhau; kiểm rằng đổi thứ tự dòng độc giả không thay kết luận.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102.

<a id="TV21"></a>
### TV21 — Giới hạn lịch sử đạt đúng M vẫn trả được

**Thành · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV21).

**Trả lời ngắn:** Node thứ M vào với tong=M−1 nên được đếm lên M; không có node thứ M+1. Trả không cần tăng H.

**Giải thích và bảo vệ cách làm:**

MuonSach còn kiểm tong>=M để chặn tạo node mới; KetThucMuon chỉ dùng kết quả kiểm và cập nhật node đang có. Nếu H vượt M thì cả việc quét cũng bị từ chối.

**Đáp câu phụ 1:** Có, nó sẽ từ chối ngay tại node thứ M dù nguồn vẫn trong giới hạn. Cận validator và cận tạo thêm phải khác mục đích.

**Sai lầm dễ mắc:** Dùng cùng dấu kiểm cho trạng thái hiện có và trạng thái sau thêm.

**Cách kiểm chứng:** Truy M=3 trên bản sao hạ ngưỡng; H3 trả được, mượn mới không; H4 là RAM lỗi riêng.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KiemTraDongThoiGian`, dòng 25; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KetThucMuon`, dòng 54.

<a id="TV22"></a>
### TV22 — Sửa thông tin đồng thời mở thẻ có thể đổi nửa chừng?

**Thành · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV22).

**Trả lời ngắn:** Yêu cầu mở thẻ bị chặn bởi lịch sử mất trước khi swap, nên cả họ/tên mới cũng chưa được áp dụng; không cập nhật một phần.

**Giải thích và bảo vệ cách làm:**

Giữ khóa và đổi thông tin hợp lệ được phép; lịch sử không đổi. Tên chứa | bị từ chối và toàn bộ hồ sơ giữ trạng thái trước lời gọi đó.

Chuỗi mới được chuẩn bị trước commit; lỗi cấp phát trước swap không sửa bản gốc. Hàm này không tự bắt mọi ngoại lệ để trả false, nên cần phân biệt bảo toàn dữ liệu với cách báo lỗi.

**Đáp câu phụ 1:** Không; cả yêu cầu chưa commit, phải giữ thông tin cũ và thông báo đúng phạm vi thất bại.

**Sai lầm dễ mắc:** Một phần đầu vào hợp lệ sẽ được áp dụng dù API trả lỗi toàn lời gọi.

**Cách kiểm chứng:** Đề xuất kiểm chứng: So cả ho, ten, phai, trangThaiThe, maThe và con trỏ lịch sử trước/sau; đọc vị trí kiểm mất, tạo chuỗi tạm và swap.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `HieuChinhDocGia`, dòng 73.

<a id="TV30"></a>
### TV30 — Cấp mã trước hay sau khi dữ liệu đã được chấp nhận?

**Thành · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV30).

**Trả lời ngắn:** Lần nhập sai chưa tới cấp mã; lỗi trước khi nối nút không cập nhật mốc; lần thành công nhận 21. Đây là giả lập lỗi cấp phát cần harness riêng.

**Giải thích và bảo vệ cách làm:**

ChenDocGiaCoMa chuẩn bị nút qua unique_ptr rồi mới nối. ThemDocGia không tự bắt mọi ngoại lệ; UI có catch ngoài, không được nói mọi lỗi đều trả false.

Trì hoãn cập nhật mốc tránh phải rollback qua nhiều nhánh. Tăng rồi giảm đòi bao phủ mọi đường thoát và có thể sai nếu phạm vi mở rộng; không giúp tính đúng hiện tại.

**Đáp câu phụ 1:** Không; output caller và metadata nguồn là hai biến. Caller phải dựa vào kết quả, không dùng ma cũ như mã vừa cấp.

**Sai lầm dễ mắc:** Biến output có số dương chứng minh lần thêm hiện tại thành công.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Kiểm mốc, cây và output ở ba lần; với thiếu bộ nhớ chỉ ghi đã chạy khi thật có tiêm lỗi, không suy từ CLI.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `ThemDocGia`, dòng 64; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `ChenDocGiaCoMa`, dòng 51; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507.

<a id="TV32"></a>
### TV32 — Mở khóa thẻ có đồng nghĩa được mượn ngay?

**Thành · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV32).

**Trả lời ngắn:** A mở được rồi có thể mượn nếu ngày/các liên kết hợp lệ. B mở bị từ chối do lịch sử mất theo giả định hiện tại.

**Giải thích và bảo vệ cách làm:**

C có thể mở khóa nhưng mượn vẫn bị quá hạn chặn; mở khóa không xóa lịch sử hay cập nhật ngày.

HieuChinhDocGia kiểm khả năng đặt trạng thái thẻ, MuonSach còn hạn mức/quá hạn/cuốn/thời gian; hai quyết định khác phạm vi.

**Đáp câu phụ 1:** Bị hạn mức chặn; mở khóa chỉ vượt một điều kiện riêng, không đặt số đang giữ về 0.

**Sai lầm dễ mắc:** Mở khóa là đặt lại toàn quyền và nghĩa vụ của người.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Dùng ba hồ sơ riêng, so trạng thái sau mở và số lịch sử sau mượn; ghi rõ quy tắc xử lý mất cần hỏi thầy.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `HieuChinhDocGia`, dòng 73; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114.

<a id="TV35"></a>
### TV35 — Successor chính là con phải

**Thành · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV35).

**Trả lời ngắn:** succLink trỏ vào old->right; gán *succLink=succ->right trước làm old->right thành cây con phải cũ của 20.

**Giải thích và bảo vệ cách làm:**

Sau đó succ->right=old->right không trỏ chính succ. Đổi thứ tự nối có thể tạo vòng, nên phải giải thích bằng địa chỉ.

**Đáp câu phụ 1:** Nằm bên phải 20 mới; phép tháo successor trước nối giữ cây con đó, không xóa nó cùng 10.

**Sai lầm dễ mắc:** Successor được chuyển thì cây con phải của nó có thể bỏ qua.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Vẽ ba node và con phải 25 của 20, kiểm inorder sau xóa là 5,20,25.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `XoaDocGia`, dòng 85.

<a id="TV37"></a>
### TV37 — Một hàm xóa xử lý gốc lẫn con mà không trả gốc mới

**Thành · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV37).

**Trả lời ngắn:** Xóa 25 đi đến ô con rỗng của 30 và không đổi cây. Xóa 10 nối ô trái của 20 sang 15; xóa 20 di chuyển successor 30 lên, giữ 15 bên trái.

**Giải thích và bảo vệ cách làm:**

link là địa chỉ ô giữ con trỏ, có thể là & root hoặc &parent->left/right; *link là node hiện có hoặc null.

Gán biến node cục bộ không tự thay ô sở hữu của caller. Cách con trỏ kép gom các trường hợp nhưng vẫn cần kiểm lịch sử và xử lý hai con đúng.

**Đáp câu phụ 1:** Không; phải lấy bản sao thông tin cần dùng trước khi xóa hoặc dùng dữ liệu còn sống khác.

**Sai lầm dễ mắc:** Con trỏ cục bộ vẫn có giá trị địa chỉ nên được dereference sau delete.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Vẽ từng ô liên kết sau ba lệnh, kiểm inorder 15, 30 và mốc cấp mã không giảm; không dereference con trỏ của node đã xóa.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `XoaDocGia`, dòng 85; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `TimDocGia`, dòng 8, 13.

<a id="TV39"></a>
### TV39 — Xóa hết hồ sơ bằng hàm hủy không phải nghiệp vụ

**Thành · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV39).

**Trả lời ngắn:** Hàm hủy giải phóng cây/lịch sử không áp quy tắc xóa nghiệp vụ; cuốn có thể còn trạng thái 1 nhưng mất phiếu mở.

**Giải thích và bảo vệ cách làm:**

HuyCayDocGia chỉ nhận cây nên không đổi kho sách hay metadata của ThuVien. Nó phục vụ giải phóng, không API cho phép xóa dữ liệu đang dùng. HuyThuVien hủy cả kho và đặt mốc 0 ở vòng đời kết thúc/reset.

**Đáp câu phụ 1:** Không; lịch sử/top và danh tính đã cấp đã mất. Đây là xóa dữ liệu, không sửa nhất quán bằng đổi cờ.

**Sai lầm dễ mắc:** Hàm quản lý bộ nhớ được sử dụng như chức năng quản trị hợp lệ.

**Cách kiểm chứng:** Truy caller và hậu điều kiện trên sơ đồ; nếu thử dùng fixture riêng, đối chiếu validator sau hủy cây.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `HuyCayDocGia`, dòng 103; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `XoaDocGia`, dòng 85; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `HuyThuVien`, dòng 335.

<a id="TV46"></a>
### TV46 — Yêu cầu gửi lại có phải cùng giao dịch hay một lượt mới?

**Thành · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV46).

**Trả lời ngắn:** Gọi lại ngay bị trạng thái cuốn chặn, không thêm phiếu. Sau trả, nếu quyền/ngày hợp lệ, lời gọi mượn cùng tham số là một lượt mới vì X đã rảnh.

**Giải thích và bảo vệ cách làm:**

Code không có mã giao dịch để nhận ra cùng một ý định được gửi lại; bảo vệ theo trạng thái khác cơ chế xử lý yêu cầu lặp theo danh tính.

Muốn hỗ trợ retry từ mạng phải chốt request ID/phạm vi/lưu kết quả; đó là mở rộng ngoài console tuần tự và cấu trúc hiện tại.

**Đáp câu phụ 1:** Không; trả rồi mượn lại cùng ngày có cùng bộ đó. Request ID phải đại diện ý định riêng, có quy tắc cấp/lưu/đối chiếu payload.

**Sai lầm dễ mắc:** Trùng tham số tự chứng minh đó là cùng một yêu cầu gửi lại.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Truy ba lời gọi mượn quanh một lần trả, đối chiếu H tăng 2 chứ không 1 và top tăng tương ứng.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KetThucMuon`, dòng 54; [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `TimMuonDangMuonTheoMa`, dòng 14.

<a id="TV48"></a>
### TV48 — Tìm lại cuốn đã báo mất: khôi phục cần quy tắc gì?

**Thành · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV48).

**Trả lời ngắn:** Lượt X đã kết thúc trạng thái mất nên không có phiếu mở để TraSach đóng; code chưa hỗ trợ tìm lại/giải quyết mất. Y vẫn là nghĩa vụ riêng.

**Giải thích và bảo vệ cách làm:**

Chỉ đổi X sẵn sàng/thẻ hoạt động mâu thuẫn kiểm lượt mất yêu cầu cuốn thanh lý và thẻ khóa, lịch sử cũng không cho mượn sau mất.

Cần chốt quy tắc bảo tồn dấu vết, khả năng mượn lại, xử lý mọi lượt mất còn lại trước mở thẻ; không sửa một vài trạng thái để che lỗi hay giả vờ đã triển khai.

**Đáp câu phụ 1:** Chưa thể khẳng định; cần đặc tả đối với mọi nghĩa vụ còn lại và dấu vết xử lý, không dựa một cờ mới đơn lẻ.

**Sai lầm dễ mắc:** Tìm lại một cuốn tự xóa mọi lý do khóa của người.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Vẽ trạng thái hiện tại và các invariant bị từng đề xuất phá; thực nghiệm trên bản sao, giữ nguyên dữ liệu thật.

**Ca liên quan đã chạy 17/10 (không tái chạy đợt này):** [lost_no_reopen](ThamKhao/KIEM_CHUNG_RUNTIME.md#lost_no_reopen).

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KetThucMuon`, dòng 54; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `HieuChinhDocGia`, dòng 73; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102.

<a id="TV51"></a>
### TV51 — Gộp các lần quét lịch sử có làm đổi lỗi đầu tiên?

**Thành · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV51).

**Trả lời ngắn:** Bản hiện tại báo đủ 3 trước quá hạn. Gộp quét có thể thu thông tin một lần nhưng phải ra quyết định theo thứ tự hợp đồng cũ nếu yêu cầu giữ hành vi.

**Giải thích và bảo vệ cách làm:**

Boolean tồn tại quá hạn cho phép dừng sớm; tổng số và max cần xử lý phần còn lại hoặc cận chứng minh phù hợp. Không lấy nút quá hạn đầu làm nặng nhất.

Một kết quả tạm gồm count /hasOverdue/ max giúp tránh vòng lặp lặp lại, không phải trường lưu lâu dài; chi phí toàn giao dịch vẫn còn quét toàn thư viện.

**Đáp câu phụ 1:** Không; timeline vẫn quét R/H toàn thư viện và còn tìm cuốn/người, nối đuôi. Phải tính toàn đường gọi.

**Sai lầm dễ mắc:** Giảm số vòng ở một helper là đã loại nút thắt toàn giao dịch.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Dùng ca đủ 3+quá hạn, chỉ quá hạn, max ở cuối và lịch sử trả xen kẽ; so thông báo và dữ liệu trước/sau refactor.

**Ca liên quan đã chạy 17/10 (không tái chạy đợt này):** [locked_full_overdue_precedence](ThamKhao/KIEM_CHUNG_RUNTIME.md#locked_full_overdue_precedence), [full_before_overdue](ThamKhao/KIEM_CHUNG_RUNTIME.md#full_before_overdue).

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114; [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `DemSoSachDangMuon`, dòng 5; [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `CoSachQuaHan7Ngay`, dòng 9.

<a id="TV57"></a>
### TV57 — Kho vật lý đầy nhưng lịch sử còn chỗ: giao dịch cần tài nguyên nào?

**Thành · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV57).

**Trả lời ngắn:** Mượn đầu thêm một MuonTra đưa H=M, không thêm CuonSach nên được phép. Thêm cuốn bị giới hạn C=M chặn.

**Giải thích và bảo vệ cách làm:**

Trả sửa lượt hiện có nên được; mượn lại cần lượt mới nên H=M chặn dù cuốn đã rảnh. Trả không xóa lịch sử để giải phóng hạn mức.

C và H là hai giới hạn độc lập trong bản này. Gộp chúng thay chính sách tài nguyên và có thể chặn yêu cầu đang hợp lệ.

**Đáp câu phụ 1:** Không; cập nhật lượt có sẵn, nên riêng cận H không chặn kết thúc lượt hợp lệ.

**Sai lầm dễ mắc:** Mọi thay đổi nghiệp vụ đều cần tăng số bản ghi lịch sử.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Kiểm count của từng loại và số cấp phát logic; dùng harness sát giới hạn hoặc truy vết, không suy mọi thao tác tạo node.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `ThemCuonSach`, dòng 74; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KetThucMuon`, dòng 54.

<a id="TV62"></a>
### TV62 — Một lỗi lịch sử của người khác có chặn giao dịch không

**Thành · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV62).

**Trả lời ngắn:** Nó vẫn đếm tổng lịch sử nhưng bỏ kiểm ngày chi tiết khi cả độc giả lẫn mã cuốn không liên quan; giao dịch A/X có thể qua.

**Giải thích và bảo vệ cách làm:**

KiemTraNoiBo kiểm mọi lịch sử nên lưu sẽ từ chối. Kiểm giao dịch cục bộ không phải chứng nhận toàn bộ RAM sạch; nguồn chuẩn phải qua loader và API hợp lệ.

**Đáp câu phụ 1:** Lượt trở thành liên quan theo mã cuốn nên helper kiểm ngày/trạng thái và từ chối trước commit.

**Sai lầm dễ mắc:** Có một giao dịch thành công được xem như toàn bộ dữ liệu hợp lệ.

**Cách kiểm chứng:** Đề xuất: hai fixture RAM lỗi chỉ thay mã Y/X; đọc nhánh continue và so kết quả validator toàn cục.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KiemTraDongThoiGian`, dòng 25; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102.

<a id="TV66"></a>
### TV66 — Ngày trả được ghi trước trạng thái không có cửa sổ UI chen vào

**Thành · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV66).

**Trả lời ngắn:** Trong luồng console đồng bộ hiện tại, không có vòng nhận menu xen giữa các phép gán đó.

**Giải thích và bảo vệ cách làm:**

Đoạn commit không cấp phát/string, nhưng tính tuần tự không bảo đảm chống dừng tiến trình hay người đọc từ thread khác nếu mở rộng. Gọi nó là một cụm cập nhật phối hợp trong mô hình hiện tại, không tuyên bố atomic với mọi môi trường.

**Đáp câu phụ 1:** Không; atomic từng trường không gộp toàn bộ thành một giao dịch. Người đọc vẫn có thể thấy các thời điểm khác nhau nếu thiếu đồng bộ cụm.

**Sai lầm dễ mắc:** Không có chen UI hiện tại được suy thành hỗ trợ đa luồng an toàn.

**Cách kiểm chứng:** Truy call stack không yield/callback giữa commit; bài đa luồng chỉ phân tích, chưa triển khai atomic/lock.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KetThucMuon`, dòng 54; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507.

<a id="TV71"></a>
### TV71 — Parser nhận ngày nhưng cả bản ghi vẫn phải bị loại

**Thành · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV71).

**Trả lời ngắn:** Parser chỉ chuyển cú pháp/sentinel; phiếu đang mở cần sentinel, phiếu kết thúc cần ngày thật hợp lệ và không trước ngày mượn.

**Giải thích và bảo vệ cách làm:**

Cấm sentinel ở parser làm file đang mượn hợp lệ không đọc được; chấp nhận ở mọi trạng thái bỏ mất kiểm chéo trạng thái–ngày.

KiemTraNoiBo từ chối hai phiếu mâu thuẫn trước swap RAM. Việc parser trả true không cấp quyền thực hiện giao dịch với ngày rỗng.

**Đáp câu phụ 1:** Không; ngày mượn luôn phải là ngày thật hợp lệ, sentinel chỉ dành trường ngày kết thúc chưa có ở lượt mở.

**Sai lầm dễ mắc:** Parser nhận sentinel nghĩa mọi trường ngày đều nhận sentinel.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Dùng ba file riêng với danh mục/trạng thái cuốn khớp phần còn lại; kiểm lỗi không thay dữ liệu phiên đang mở.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `DocNgay`, dòng 95; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KiemTraNgayGiaoDich`, dòng 17.

<a id="TV73"></a>
### TV73 — Vì sao tính ngày bằng số thứ tự thay vì vòng lặp từng ngày?

**Thành · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV73).

**Trả lời ngắn:** Công thức cộng số ngày của các năm hoàn tất rồi số ngày trước tháng và ngày hiện tại; hiệu hai số tránh vòng lặp phụ thuộc khoảng thời gian.

**Giải thích và bảo vệ cách làm:**

Năm 1900 không nhuận, 2000 nhuận; phần cộng sau tháng 2 chỉ áp năm hiện tại nhuận. Chỉ chia 4 sai tại thế kỷ không chia 400.

Vòng tăng ngày có thể đúng nếu xử lý đầy đủ lịch nhưng mỗi phép hiệu tốn số ngày cách nhau; khi quét H lượt tăng chi phí đáng kể. Ít dòng hoặc dễ nhìn không là tiêu chí duy nhất.

**Đáp câu phụ 1:** Từ chối qua NgayHopLe; phép ordinal không phải công cụ tự sửa ngày ngoài lịch.

**Sai lầm dễ mắc:** Công thức số ngày biến mọi bộ ba số thành ngày hợp lệ.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Tính tay qua 28/02 và 01/03 của 1900/2000, qua 31/12; so số bước theo khoảng năm mà không cần đo thời gian máy.

**Ca liên quan đã chạy 17/10 (không tái chạy đợt này):** [leap_seven](ThamKhao/KIEM_CHUNG_RUNTIME.md#leap_seven), [leap_eight](ThamKhao/KIEM_CHUNG_RUNTIME.md#leap_eight).

**Nguồn đối chiếu:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `SoThuTuNgay`, dòng 112; [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `NamNhuan`, dòng 87; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InDocGiaQuaHan`, dòng 148.

<a id="TV74"></a>
### TV74 — Dùng abs cho khoảng cách ngày có che giao dịch ghi lùi?

**Thành · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV74).

**Trả lời ngắn:** KhoangCachNgay (a, b)=b−a giữ thông tin trước/sau. Các kiểm tương lai, ngày trả trước mượn và giao nhau lịch sử dựa vào dấu.

**Giải thích và bảo vệ cách làm:**

abs biến quan hệ đảo ngày thành số dương, làm mất hướng; không phải sửa lỗi hiển thị. KiemTraDongThoiGian còn so số thứ tự trực tiếp nên cần đọc từng caller, không kết luận mọi nhánh đổi giống nhau.

Nếu một báo cáo muốn độ dài không hướng phải là yêu cầu riêng và gọi sau kiểm ngày; giữ hợp đồng helper chung.

**Đáp câu phụ 1:** Không; đổi chiều đảo dấu có chủ ý, abs mất hướng ở cả hai chiều. Mỗi caller phải có quy ước rõ.

**Sai lầm dễ mắc:** Dấu âm là lỗi tính toán cần loại bỏ ở helper chung.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Liệt kê callers và chiều tham số, chọn một ca cho mỗi nhánh trước/sau/cùng ngày; so expected trước khi thử sửa.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `KhoangCachNgay`, dòng 118; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KiemTraNgayGiaoDich`, dòng 17; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KiemTraDongThoiGian`, dòng 25.

<a id="TV85"></a>
### TV85 — Lưu–nạp: so cái gì để biết lịch sử vẫn thuộc đúng người?

**Thành · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV85).

**Trả lời ngắn:** Địa chỉ/hình dạng cây không cần giữ; mã, trường hồ sơ, lịch sử từng mã, liên kết cuốn và mốc cấp mã mới là nội dung cần bảo toàn.

**Giải thích và bảo vệ cách làm:**

Inorder theo mã chỉ chứng minh tập/thứ tự khóa, tổng H chỉ chứng minh số lượng; cả hai có thể đúng dù lịch sử đổi chủ.

Cần đối chiếu bản ghi lịch sử theo từng độc giả và trạng thái cuốn, đồng thời kiểm bất biến; không yêu cầu địa chỉ bộ nhớ bằng nhau sau nạp.

**Đáp câu phụ 1:** Không nếu vẫn thỏa invariant; round-trip cần so dữ liệu trường, không chỉ xác nhận snapshot hợp lệ.

**Sai lầm dễ mắc:** Hợp lệ sau nạp là bằng chứng không mất hoặc đổi dữ liệu.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Tạo hai người tên giống nhưng mượn hai mã khác, so nội dung trước/sau và thử mutation hoán đổi lịch sử để test phải bắt được.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `Ghi`, dòng 273; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `DocNoiBo`, dòng 222; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `DungBST`, dòng 97; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `LayDanhSachDocGia`, dòng 18.

<a id="TV88"></a>
### TV88 — Lượt mất cũ bị mở thẻ bằng cách sửa RAM

**Thành · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV88).

**Trả lời ngắn:** MuonSach kiểm trạng thái thẻ hiện tại và các điều kiện mượn, không có nhánh riêng cấm mọi lịch sử mất; có thể nhận Y trong RAM sai này.

**Giải thích và bảo vệ cách làm:**

HieuChinhDocGia chặn mở thẻ có lượt mất; loader/validator yêu cầu thẻ khóa khi có mất. Bỏ qua cổng đó phá tiền điều kiện của luồng chuẩn. Không nói MuonSach tự phục hồi chính sách.

**Đáp câu phụ 1:** File bị kiểm mất–thẻ khóa từ chối. Đường file hợp lệ khác tiêm lỗi trực tiếp vào RAM.

**Sai lầm dễ mắc:** Bất biến được bảo vệ ở một cổng được tưởng là lặp lại ở mọi hàm.

**Cách kiểm chứng:** Đề xuất: hai đường fixture file và RAM sửa tay; kiểm khác biệt, không sửa nguồn sản phẩm.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `HieuChinhDocGia`, dòng 73; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102.

<a id="TV94"></a>
### TV94 — Nhập một giao dịch nguyên khối nhiều cuốn

**Thành · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV94).

**Trả lời ngắn:** Y có thể thành công rồi Z thất bại; API hiện commit từng cuốn, không tự rollback cả lô.

**Giải thích và bảo vệ cách làm:**

Thiết kế lô phải kiểm tập mã không trùng, hạn mức sau cả lô, quyền/ngày/trạng thái và cấp phát đủ các node trước commit. Phải chốt thứ tự lỗi, chi phí, và cơ chế đồng bộ nếu có concurrent; không dùng trả sách giả để rollback vì tạo lịch sử khác.

**Đáp câu phụ 1:** Không; đã tạo một lượt Y rồi đóng, top vẫn tăng. Đó là nghiệp vụ khác chứ không rollback.

**Sai lầm dễ mắc:** Gọi API ngược được coi là hoàn tác mọi dấu vết của giao dịch.

**Cách kiểm chứng:** Đề xuất: lô có Z bận, trùngY/Y, thiếu 1 slot và lỗi cấp phát trước commit; chưa cài API lô.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114.

<a id="TV99"></a>
### TV99 — Ẩn hồ sơ đã ngừng dùng không xóa nghĩa vụ

**Thành · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV99).

**Trả lời ngắn:** Khóa hiện chỉ nói không được mượn mới; không đủ phân biệt lưu trữ với khóa tạm hoặc mất sách.

**Giải thích và bảo vệ cách làm:**

Có thể có bộ lọc hiển thị thẻ khóa với nhãn rõ nhưng không coi đó là trạng thái lưu trữ mới. Nếu cần vòng đời riêng phải hỏi quyền thêm dữ liệu; mọi báo cáo nghĩa vụ vẫn phải đọc người còn giữ sách.

**Đáp câu phụ 1:** Không; view là phép đọc. Bỏ khỏi serialization sẽ mất lịch sử và thay dữ liệu, khác ẩn màn hình.

**Sai lầm dễ mắc:** Một cờ sẵn có được dùng cho nhiều nghĩa không phân biệt được.

**Cách kiểm chứng:** Đề xuất thiết kế: khóa thủ công, khóa do mất còn sách và người không lịch sử; kiểm lọc không đổi nguồn/top/h.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `XoaDocGia`, dòng 85; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `HieuChinhDocGia`, dòng 73; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `Ghi`, dòng 273.

<a id="TV201"></a>
### TV201 — Xóa một khoảng mã khi đang duyệt view

**Thành · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV201).

**Trả lời ngắn:** Chụp các mã mục tiêu vào mảng giá trị trước, rồi gọi XoaDocGia theo từng mã và ghi thành công/thất bại riêng.

**Giải thích và bảo vệ cách làm:**

View con trỏ có lifetime phụ thuộc node; bản sao mã không bị delete làm treo. Xóa một người có lịch sử bị chặn không nên làm chương trình nói cả lô thành công. Nếu yêu cầu all-or-nothing phải thêm pha kiểm/transaction, bản hiện chỉ atomic từng lời gọi.

**Đáp câu phụ 1:** Không; di chuyển nguyên successor giữ mã. Danh sách mã mục tiêu tránh phụ thuộc vị trí/root mới.

**Sai lầm dễ mắc:** Một iterator/con trỏ từ trước mutation luôn dùng được tới hết vòng for.

**Cách kiểm chứng:** Đề xuất cây có gốc hai con, một người bị chặn lịch sử và các mục không tồn tại; kiểm từng kết quả.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `XoaDocGia`, dòng 85; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `LayDanhSachDocGia`, dòng 18.

<a id="TV202"></a>
### TV202 — Thẻ INT_MAX vẫn hợp lệ khi đọc

**Thành · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV202).

**Trả lời ngắn:** Mã INT_MAX có thể hợp lệ trong cây, nhưng không thể cấp mã mới sau mốc đó.

**Giải thích và bảo vệ cách làm:**

Cận trên mở cần lớn hơn khóa int lớn nhất; tính INT_MAX+1 ngay trong int sẽ tràn trước khi chuyển kiểu. ThemDocGia kiểm hết miền trước phép cộng mốc.

**Đáp câu phụ 1:** Không, phép kiểm maThe>=hi sẽ loại chính mã INT_MAX; phải giữ miền cận rộng hơn miền khóa.

**Sai lầm dễ mắc:** Khóa không còn cấp tiếp được bị coi là khóa hiện có không hợp lệ.

**Cách kiểm chứng:** Đề xuất: file một mã max và file metadata max−1/mã max; ca đầu nạp được nhưng thêm thất bại, ca sau bị metadata chặn.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `ThemDocGia`, dòng 64.

<a id="TV203"></a>
### TV203 — Dựng BST cân bằng không được nối nhánh cũ còn sót

**Thành · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV203).

**Trả lời ngắn:** Phải gán cả kết quả nullptr ở cận rỗng; liên kết tạm cũ không được tồn tại sau dựng lại.

**Giải thích và bảo vệ cách làm:**

Hàm hiện đặt left/right bằng kết quả đệ quy cho mọi node. Bỏ phép gán khi rỗng có thể để node trỏ vào node đã nằm ở nhánh khác, tạo sai thứ tự, chia sẻ hoặc vòng.

**Đáp câu phụ 1:** Không, nó chỉ đổi thứ tự con trỏ trong mảng phụ; DungBST mới dựng lại các cạnh thật.

**Sai lầm dễ mắc:** Mảng con trỏ đã sắp được xem như cây đã được sắp.

**Cách kiểm chứng:** Đề xuất: vẽ nhánh phải tạm với thứ tự đầu vào đảo, dựng 4 node; kiểm mọi node xuất hiện đúng một lần và lá có hai con null.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `DungBST`, dòng 97; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `DocNoiBo`, dòng 222.

<a id="TV205"></a>
### TV205 — Nhập lô hồ sơ mới khác nạp thay thư viện

**Thành · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV205).

**Trả lời ngắn:** DocFile thay cả thư viện, không merge; file thiếu kho/lịch sử cũ có thể làm mất phiên hiện tại khi nạp thành công.

**Giải thích và bảo vệ cách làm:**

Bulk thêm phải cấp mã từ mốc hiện tại, giữ toàn bộ người/kho/lịch sử cũ, kiểm tổng R và dữ liệu đầu vào, chốt commit từng hồ sơ hay cả lô. Có thể chuẩn bị mảng nút mới, nhưng xây lại cây cần quản ownership và pointer đang được mượn. Không dùng loader như shortcut bỏ hợp đồng.

**Đáp câu phụ 1:** Không; phải chốt ánh xạ, collision và mốc, không coi mã bên ngoài có cùng namespace.

**Sai lầm dễ mắc:** Hai đường đều tạo BST nên có thể thay nhau mà không xét semantics thay/ghép.

**Cách kiểm chứng:** Đề xuất fixture cũ có phiếu mở, bulk có lỗi giữa lô; so dữ liệu cũ và mốc theo đặc tả.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `ThemDocGia`, dòng 64; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `DocNoiBo`, dòng 222; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `DungBST`, dòng 97.

<a id="TV206"></a>
### TV206 — Người bị xóa có thể còn được hiển thị trong view

**Thành · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV206).

**Trả lời ngắn:** View không tự cập nhật; con trỏ tới node đã xóa bị treo, dù vùng mảng view vẫn còn.

**Giải thích và bảo vệ cách làm:**

Hiệu chỉnh tên giữ node sống nhưng thứ tự view đã sắp có thể cũ. Xóa và sửa có hai loại vô hiệu khác nhau: vòng đời đối tượng và tính đúng thứ tự. Bản hiện dựng view trong một lần báo cáo tuần tự.

**Đáp câu phụ 1:** Không biết ô nào phải loại và có thể vẫn dereference ô treo; phải tái dựng hoặc cập nhật view đúng theo mã/đối tượng.

**Sai lầm dễ mắc:** View sở hữu mảng được tưởng là snapshot sở hữu cả node.

**Cách kiểm chứng:** Đề xuất: trên harness không dereference con trỏ đã xóa; kiểm thiết kế màn hình mới tái dựng sau mutation.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `XoaDocGia`, dòng 85; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InDocGiaTheoTenHo`, dòng 119.

<a id="TV209"></a>
### TV209 — Có phiếu mở nhưng ngày trả không rỗng trong RAM

**Thành · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV209).

**Trả lời ngắn:** KetThucMuon và helper timeline không kiểm riêng ngayTra rỗng của phiếu mở; có thể ghi ngày 17 rồi đóng lượt nếu các điều kiện khác đạt.

**Giải thích và bảo vệ cách làm:**

KiemTraNoiBo có kiểm rõ lượt mở phải ngayTra=0/0/0 và sẽ từ chối trước thao tác. API giao dịch dựa vào nguồn hợp lệ, không phải bộ kiểm đầy đủ mọi corruption.

**Đáp câu phụ 1:** Không; nó chỉ tình cờ ghi đè trường trong ca cụ thể, không xác minh nguồn hay sửa mọi bất nhất. Cần đối soát dữ liệu trước.

**Sai lầm dễ mắc:** Một vài kiểm phòng thủ trong API được hiểu là kiểm toàn vẹn tuyệt đối.

**Cách kiểm chứng:** Đề xuất: harness tách biệt kiểm validator trước, gọi trả rồi kiểm sau; ghi rõ corruption không sinh từ loader hợp lệ.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KiemTraDongThoiGian`, dòng 25; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KetThucMuon`, dòng 54; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102.

<a id="TV212"></a>
### TV212 — Tham số sửa tên alias với trường trong node

**Thành · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV212).

**Trả lời ngắn:** h,t,f được chuẩn bị từ giá trị đầu vào cũ trước commit; sau đó swap từng trường không làm mất dữ liệu mà bước chuẩn bị sau còn cần.

**Giải thích và bảo vệ cách làm:**

Nếu gán trực tiếp ho trước rồi mới đọc tham chiếu ten đang alias ho cũ, có thể nhận giá trị đã đổi thay vì giá trị ban đầu. Cần giữ validate và khả năng từ chối mở thẻ trước commit. Đây là phân tích alias API, không phải yêu cầu UI cho tráo họ/tên.

**Đáp câu phụ 1:** Bản hiện đã tạo f trước swap nên giữ giá trị đầu vào; vẫn phải qua validation phai đúng miền.

**Sai lầm dễ mắc:** Các tham số const string& không thể alias dữ liệu mà hàm sẽ cập nhật.

**Cách kiểm chứng:** Đề xuất harness tham chiếu chéo, so kết quả với bản sao input độc lập và ca từ chối toàn bộ.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `HieuChinhDocGia`, dòng 73.

<a id="TV214"></a>
### TV214 — Hai thẻ khóa không cho biết ai đã khóa

**Thành · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV214).

**Trả lời ngắn:** V1 chỉ có trạng thái hiện tại và lịch sử mượn; không có người thao tác/thời điểm khóa hay log thay đổi thẻ.

**Giải thích và bảo vệ cách làm:**

Thiết kế mở rộng cần danh tính người vận hành đáng tin, thẻ đích, trạng thái trước/sau, thời điểm và kết quả; sự kiện thành công phải gắn với commit. Cần xử lý thống nhất khi ghi log thất bại, không chỉ in thêm dòng console.

**Đáp câu phụ 1:** Không; có thể có thao tác khóa lại hoặc nguồn dữ liệu khác. Lịch sử mất cho biết sự kiện mượn, không đầy đủ chuỗi chỉnh thẻ.

**Sai lầm dễ mắc:** Trạng thái cuối được coi như nhật ký thao tác đầy đủ.

**Cách kiểm chứng:** Đề xuất hệ thống mới: chỉnh thành công, bị từ chối mở thẻ mất, retry và lưu lỗi; kiểm log không bịa thành công. Chưa triển khai.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `HieuChinhDocGia`, dòng 73; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `DanhDauMatSach`, dòng 142; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `Ghi`, dòng 273.

<a id="TV215"></a>
### TV215 — Chuyển phiếu mở giữa hai độc giả không chỉ là nối danh sách

**Thành · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV215).

**Trả lời ngắn:** B sẽ giữ 4 cuốn, vi phạm hạn mức dù trạng thái X không đổi; còn phải xét ngày, quá hạn, thẻ và định danh người thực sự mượn.

**Giải thích và bảo vệ cách làm:**

Bản hiện không có chuyển phiếu. Điều chỉnh cần quy tắc có xác minh nguồn, bảo toàn dấu vết và kiểm toàn bộ trạng thái trước commit; v1 thiếu lịch sử thẻ/giờ nên không tự chứng minh mọi quyền quá khứ.

**Đáp câu phụ 1:** Chưa; có thể xung đột mốc thời gian, quyền lúc mượn hoặc nguồn xác nhận. Hạn mức là một điều kiện, không phải toàn hợp đồng.

**Sai lầm dễ mắc:** Cuốn không đổi trạng thái được coi là không có giao dịch liên module.

**Cách kiểm chứng:** Đề xuất: B có 3/2 cuốn và có/không quá hạn; ghi rõ ca nào bị điều kiện nào chặn trong thiết kế, chưa có API hiện tại.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — `DocGia`, dòng 24; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KiemTraDongThoiGian`, dòng 25; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102.

<a id="TV216"></a>
### TV216 — Không thể chỉ khóa cuốn khi mở dịch vụ mượn

**Thành · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV216).

**Trả lời ngắn:** Có nếu hai kiểm cùng dùng trạng thái trước cập nhật. Khóa cuốn tránh mượn trùng một cuốn nhưng không bảo vệ hạn mức theo độc giả.

**Giải thích và bảo vệ cách làm:**

Giao dịch cần phối hợp trạng thái độc giả/lịch sử và cuốn, kiểm lại trong cùng miền đồng bộ. Nếu dùng khóa, phải có thứ tự lấy khóa nhất quán để tránh chờ vòng; nếu dùng DB, cần ràng buộc/giao dịch tương ứng. Code console hiện tuần tự, chưa có các cơ chế đó.

**Đáp câu phụ 1:** Không; mutex nội bộ không phối hợp hai tiến trình độc lập, và file snapshot còn có nguy cơ mất cập nhật.

**Sai lầm dễ mắc:** Khóa tài nguyên vật lý được coi là bảo vệ mọi bất biến nghiệp vụ.

**Cách kiểm chứng:** Đề xuất: barrier cho hai request đọc cùng số 2 rồi commit trên mô hình thử; thiết kế đúng chỉ nhận tối đa một yêu cầu. Chưa chạy đồng thời.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114; [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `DemSoSachDangMuon`, dòng 5.

<a id="TV217"></a>
### TV217 — Trả và báo mất cùng một phiếu trong dịch vụ

**Thành · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV217).

**Trả lời ngắn:** Có thể phiếu/cuốn/thẻ phản ánh hai quyết định khác nhau nếu các phép ghi xen kẽ; chỉ bảo vệ một trường không đủ.

**Giải thích và bảo vệ cách làm:**

Phải kiểm phiếu còn mở và cập nhật phiếu, cuốn, trạng thái thẻ liên quan trong một giao dịch hoặc khóa chung. Request đến sau phải nhận kết quả xung đột/đã xử lý theo chính sách rõ. Bản hiện một luồng thực hiện trọn lời gọi.

**Đáp câu phụ 1:** Đó là chính sách nghiệp vụ mới cần xử lý hậu quả thẻ và dấu vết, không vá một cờ sau khi hai commit đã xảy ra.

**Sai lầm dễ mắc:** Các phép gán int riêng lẻ nhanh được xem là giao dịch nguyên tử.

**Cách kiểm chứng:** Đề xuất: lịch xen kẽ đọc–ghi trên giấy và test hai request có barrier nếu triển khai; kiểm cả ba đối tượng.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KetThucMuon`, dòng 54.

<a id="TV218"></a>
### TV218 — Khóa có thứ tự để tránh hai yêu cầu chờ nhau

**Thành · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV218).

**Trả lời ngắn:** Có vòng chờ: mượn giữ A chờ X, trả giữ X chờ A; cả hai không tiến tiếp.

**Giải thích và bảo vệ cách làm:**

Cần thứ tự khóa chung cho mọi API, hoặc cơ chế giao dịch có phát hiện/hủy xung đột và retry an toàn. Phải tính cả khóa liên quan mốc toàn lịch sử; thêm khóa cục bộ không tự biến helper quét toàn kho thành snapshot nhất quán.

**Đáp câu phụ 1:** Không; phải biết ranh giới commit và hoàn tác phần chưa hoàn tất. Timeout không được để trạng thái nửa giao dịch.

**Sai lầm dễ mắc:** Chỉ cần có lock, không cần hợp đồng thứ tự và phạm vi.

**Cách kiểm chứng:** Đề xuất: test lịch hai khóa trên mô hình nhỏ, chứng minh thứ tự dùng chung loại chu trình; chưa thêm lock vào sản phẩm.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KetThucMuon`, dòng 54.

<a id="TV219"></a>
### TV219 — Một triệu hồ sơ và giới hạn stack duyệt

**Thành · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV219).

**Trả lời ngắn:** Bản hiện MAX_DOC_GIA=100.000: loader chặn số độc giả, API thêm chặn số hiện có; không có benchmark một triệu hồ sơ.

**Giải thích và bảo vệ cách làm:**

Sau nâng giới hạn, cần tính mảng stack cấp theo MAX_DOC_GIA, nodes/view, bản cũ+tạm và string. Tìm mã O(h); nạp dựng h nhỏ nhưng các lần thêm sau có thể làm lệch, còn ThemDocGia đếm O(R). Tỷ lệ đọc nhiều chưa xóa chi phí nhập và lưu.

**Đáp câu phụ 1:** Không; R có hằng riêng, C/H dùng giới hạn khác. Phải kiểm đúng đại lượng chứ không đổi một số toàn cục.

**Sai lầm dễ mắc:** Một triệu người dùng trực tuyến được đồng nhất với một triệu hồ sơ lưu trữ.

**Cách kiểm chứng:** Chỉ phân tích; thử số đếm R vượt ngưỡng bằng file nhỏ khai báo lớn để kiểm từ chối sớm, không giả vờ đã nạp triệu node.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — `MAX_DOC_GIA`, dòng 8; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `LayDanhSachDocGia`, dòng 18; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `DocNoiBo`, dòng 222.

<a id="TV221"></a>
### TV221 — Sentinel ngày có chuỗi chuẩn riêng

**Thành · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV221).

**Trả lời ngắn:** Ngày thật hai cách viết được parse cùng giá trị và ghi chuẩn 01/02/2024; sentinel chỉ chấp nhận đúng chuỗi 0/0/0.

**Giải thích và bảo vệ cách làm:**

DocNgay cho ngoại lệ ngày không hợp lệ dựa chuỗi chính xác s=="0/0/0". ChuoiNgay định dạng lại ngày thật. Test cần tách tương đương giá trị và bảo toàn byte; định dạng v1 không hứa giữ kiểu viết ban đầu.

**Đáp câu phụ 1:** Không; parser yêu cầu sentinel chính xác và các ngày khác phải qua NgayHopLe. 00/00/0000 bị từ chối.

**Sai lầm dễ mắc:** Hàm parse/print được xem là hai phép nghịch đảo trên mọi chuỗi đầu vào.

**Cách kiểm chứng:** Đề xuất: bốn chuỗi trên; kiểm bool và ChuoiNgay sau thành công, không dùng output cũ khi parse thất bại.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `DocNgay`, dòng 95; [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `ChuoiNgay`, dòng 106; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `Ghi`, dòng 273.

<a id="TV222"></a>
### TV222 — Thêm lịch sử vào đầu để bỏ quét tail

**Thành · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV222).

**Trả lời ngắn:** Các phép đếm/max/top quét theo nội dung nên không cần thứ tự node; nhưng h và Ghi đi theo next nên thứ tự hiển thị/lưu lịch sử thay đổi.

**Giải thích và bảo vệ cách làm:**

Đây có thể giảm một quét O(H_A), không bỏ quét timeline O(R+H). Phải chốt thứ tự lịch sử có là hợp đồng cần giữ không và cập nhật test; không gọi refactor giữ mọi byte đầu ra.

**Đáp câu phụ 1:** Nó lọc cả trạng thái 0; tối đa một phiếu mở của cuốn nên thứ tự không đổi phiếu cần chọn. RAM trùng phiếu là tiền điều kiện khác.

**Sai lầm dễ mắc:** Giữ cùng số node được coi là giữ mọi hành vi và thứ tự quan sát.

**Cách kiểm chứng:** Đề xuất: lịch sử hai lượt đóng và một mở, mượn thêm; so nghiệp vụ và thứ tự h/file riêng. Chưa sửa sản phẩm.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114; [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `LietKeSachDangMuon`, dòng 21; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `Ghi`, dòng 273.

<a id="TV224"></a>
### TV224 — Mốc đã cấp không phải số người còn hoạt động

**Thành · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV224).

**Trả lời ngắn:** Không; số hiện có là đếm node 20, số hoạt động là đếm trạng thái 1 bằng 5, mốc 9000 chỉ phục vụ không cấp lại mã cũ.

**Giải thích và bảo vệ cách làm:**

Xóa làm số node giảm nhưng không giảm mốc; khóa chỉ đổi trạng thái. Ba đại lượng cần nguồn và phạm vi khác nhau, không suy tỷ lệ hoạt động từ mốc mã.

**Đáp câu phụ 1:** Không chắc: file cho mốc cao hơn mã còn có, code không lưu chứng cứ từng mã được cấp. Nó là high-water metadata được nguồn file cung cấp.

**Sai lầm dễ mắc:** Mã tự tăng được dùng như số lượng người dùng thực tế.

**Cách kiểm chứng:** Đề xuất: fixture mốc lớn, ít node, nhiều khóa; kiểm ba số và một lần thêm cấp 9001, không “sửa” mốc xuống 20.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `ThemDocGia`, dòng 64; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `XoaDocGia`, dòng 85; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `DemDocGia`, dòng 33.

<a id="TV225"></a>
### TV225 — Họ tên hợp lệ nhưng phái sai ở khoảng trắng

**Thành · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV225).

**Trả lời ngắn:** Phái phải đúng Nam hoặc Nữ ngay ở HopLePhai; “ Nam ” bị từ chối trước chuẩn hóa họ/tên và trước cấp mã.

**Giải thích và bảo vệ cách làm:**

Họ/tên là văn bản mô tả, phái là miền giá trị đóng. Nếu muốn UI chấp nhận các cách viết khác phải chốt adapter chuẩn hóa rõ ràng, vẫn giữ dữ liệu lưu ở giá trị quy định.

**Đáp câu phụ 1:** Không; helper phái không gọi KhoaSoSanh và giá trị nam không thuộc hai chuỗi quy định.

**Sai lầm dễ mắc:** Tính dung sai của tìm kiếm được áp sang mọi trường nhập nghiệp vụ.

**Cách kiểm chứng:** Đề xuất: phái Nam, Nam có dấu cách, nam, Nữ; so kết quả, mốc và số node sau mỗi lần độc lập.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `HopLeDocGia`, dòng 35; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `ThemDocGia`, dòng 64; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `HieuChinhDocGia`, dòng 73.

<a id="TV226"></a>
### TV226 — Chu trình lịch sử chặn đường chạy trước điểm commit giả lập

**Thành · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV226).

**Trả lời ngắn:** Không tới. DemSoSachDangMuon duyệt lịch sử A trước kiểm quá hạn, tra cuốn, kiểm timeline, cấp phát và tìm tail. Hai node đều đã trả nên bộ đếm không tăng nhưng vòng duyệt không kết thúc.

**Giải thích và bảo vệ cách làm:**

Trong ca này cuốn X vẫn rảnh và chưa cấp/nối phiếu mới; không được dùng nó làm bằng chứng mutation tạo cuốn đang mượn thiếu phiếu. Đây là RAM hỏng giả lập, không phải đầu vào hợp lệ từ loader. Chỉ dịch phép gán trước tail vẫn nằm sau mọi kiểm có thể ném/lỗi; hai thao tác commit cuối đều là gán con trỏ/số trong luồng tuần tự. Muốn chứng minh rủi ro khác phải chỉ đúng điểm có thể thất bại sau phép gán, không tự thêm luồng chạy chen.

**Đáp câu phụ 1:** Đếm/quá hạn của A kết thúc. KiemTraDongThoiGian duyệt toàn thư viện và có cận MAX_BAN_GHI, kể cả node không liên quan A/X. Vòng ở B làm chạm cận rồi trả false trước cấp phát/commit; khác với vòng trong A bị mắc ngay tại helper đếm không có cận.

**Sai lầm dễ mắc:** Dùng trạng thái cuối tưởng tượng mà chưa chứng minh lời gọi tới được dòng gây lỗi.

**Cách kiểm chứng:** Truy call graph trước; kiểm vòng của A bằng timeout riêng và kiểm vòng của B bằng harness có tháo vòng khi dọn. Timeout chỉ xác nhận lời gọi không kết thúc trong thời hạn, lý do vòng vô hạn dựa mã nguồn.

**Kiểm mới 18/10:** [original_foreign_cycle](ThamKhao/KIEM_DINH_20261018.md#original_foreign_cycle), [commit_before_tail_foreign_cycle](ThamKhao/KIEM_DINH_20261018.md#commit_before_tail_foreign_cycle), [original_own_cycle](ThamKhao/KIEM_DINH_20261018.md#original_own_cycle), [commit_before_tail_own_cycle](ThamKhao/KIEM_DINH_20261018.md#commit_before_tail_own_cycle). Chỉ các assertion/quan sát nêu trong ca.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114; [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `DemSoSachDangMuon`, dòng 5; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KiemTraDongThoiGian`, dòng 25.

<a id="TV227"></a>
### TV227 — ThuVien không copy nhưng DocGia vẫn copy được

**Thành · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV227).

**Trả lời ngắn:** Cấm copy ThuVien không tự cấm copy từng DocGia; phép copy mặc định có thể sao chép con trỏ lịch sử.

**Giải thích và bảo vệ cách làm:**

Hai hồ sơ sau copy có thể cùng trỏ một danh sách, gây đổi dữ liệu chéo và hủy lặp. Helper chèn chỉ nhận hồ sơ rỗng lịch sử để không vô tình nhận quyền sở hữu qua copy nông; clone sâu cần API riêng.

**Đáp câu phụ 1:** Không có alias lịch sử khi con trỏ null; vẫn phải bảo đảm khóa, mốc và các trường hợp lệ trước chèn.

**Sai lầm dễ mắc:** Một lớp chủ cấm copy được tưởng là mọi kiểu con đều cấm copy.

**Cách kiểm chứng:** Truy sơ đồ alias; thử compile copy DocGia rỗng riêng để thấy khác ThuVien, không chạy double-delete.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — `ThuVien`, dòng 30; [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — `DocGia`, dòng 24; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `ChenDocGiaCoMa`, dòng 51.

<a id="TV228"></a>
### TV228 — Qua nửa đêm: ngày lịch khác thời lượng tính bằng giờ

**Thành · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV228).

**Trả lời ngắn:** Hiệu ngày là 1; chương trình không lưu giờ nên không đo được 10 phút hay thời lượng theo giây.

**Giải thích và bảo vệ cách làm:**

Công thức ngày dân sự không chịu thay đổi độ dài ngày do DST, nhưng HomNay lấy ngày theo máy chạy. Dịch vụ nhiều nơi cần múi giờ nghiệp vụ và nguồn thời gian nhất quán; đổi sang timestamp là thay mô hình, không sửa một phép trừ.

**Đáp câu phụ 1:** Không; đã mất giờ bắt đầu/kết thúc, và ngày địa phương có thể không dài đúng 24 giờ ở hệ thống có DST.

**Sai lầm dễ mắc:** Ngày lịch được diễn giải như thời lượng chính xác theo giờ.

**Cách kiểm chứng:** Phân tích trên hai sự kiện qua nửa đêm; không thay đồng hồ máy. Test tương lai cần clock/múi giờ giả lập nếu mở rộng.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `KhoangCachNgay`, dòng 118; [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `HomNay`, dòng 119; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KiemTraNgayGiaoDich`, dòng 17.

<a id="TV229"></a>
### TV229 — Ngày máy lùi làm file cũ bị xem là tương lai

**Thành · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV229).

**Trả lời ngắn:** Validator dùng HomNay của máy để chặn ngày mượn/trả tương lai;16/10 lớn hơn 15/10 nên file có thể bị từ chối.

**Giải thích và bảo vệ cách làm:**

--date điều khiển ngày giao dịch của phiên, không thay nguồn HomNay trong kiểm file. Cần chẩn đoán đồng hồ/môi trường trước khi sửa lịch sử đã có; không ghi lùi dữ liệu để ép nạp.

**Đáp câu phụ 1:** Không khi validator phụ thuộc môi trường thời gian. Cần ghi ngày máy/giả định bên cạnh phiên bản code và dữ liệu.

**Sai lầm dễ mắc:** Kiểm toàn vẹn được coi là hàm chỉ phụ thuộc byte file.

**Cách kiểm chứng:** Đề xuất với clock giả lập trên bản sao; không chỉnh giờ máy thật. So cùng fixture ở hai ngày và giữ nguyên file.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102; [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `HomNay`, dòng 119; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507.

<a id="TV230"></a>
### TV230 — Hủy trước parse và parse sai không cùng dấu hiệu

**Thành · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV230).

**Trả lời ngắn:** abc làm NhapSo báo lỗi rồi hỏi lại, nên 12 vẫn là mã thẻ. /huy làm màn hình xóa return, nên 12 tiếp theo có thể là lựa chọn lưu ở menu chính.

**Giải thích và bảo vệ cách làm:**

Hủy thay đổi trạng thái điều khiển, sai số giữ cùng trạng thái nhập. Script không thể cứ gửi tiếp một dãy field sau hủy và kỳ vọng chúng được hiểu như trước.

**Đáp câu phụ 1:** Không; các token vẫn có thể hợp lệ ở menu khác. Cần kiểm thông báo/đường đi và trạng thái file cuối.

**Sai lầm dễ mắc:** Hủy và validation thất bại được coi là cùng một kiểu thử lại.

**Cách kiểm chứng:** Đề xuất: hai transcript riêng, đối chiếu node 12 và thông báo lưu; không dùng chung phần đuôi input mà không xét ngữ cảnh.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `ManHinhDocGia`, dòng 138; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `NhapSo`, dòng 412; [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `DocSoNguyen`, dòng 65.

<a id="TV231"></a>
### TV231 — Đệ quy lúc dựng cây khác đệ quy trên cây nhập tăng

**Thành · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV231).

**Trả lời ngắn:** DungBST chia gần đôi khoảng [lo,hi) mỗi mức nên độ sâu O(log R), không đi theo nhánh của cây cũ.

**Giải thích và bảo vệ cách làm:**

Đệ quy duyệt/hủy cây lệch có thể sâu O(R), vì thế code hủy dùng lặp. Tính an toàn phụ thuộc cấu trúc lời gọi, không chỉ từ khóa đệ quy; vẫn phải tính tổng O(R) lời gọi dựng.

**Đáp câu phụ 1:** Một nhánh chỉ giảm 1, tạo cây lệch và độ sâu O(R); cùng tên hàm nhưng mất lập luận chia đôi.

**Sai lầm dễ mắc:** Số node bằng số frame đang tồn tại đồng thời cho mọi đệ quy.

**Cách kiểm chứng:** Truy R=7 với mid và với lo; đếm độ sâu cực đại riêng tổng lời gọi. Chưa dựng tải 100.000 để đo stack.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `DungBST`, dòng 97; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `HuyCayDocGia`, dòng 103.

<a id="TV232"></a>
### TV232 — Kiểm khoảng mượn kề nhau có bỏ sót khoảng xa

**Thành · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV232).

**Trả lời ngắn:** Nếu mọi lượt trước phải đã trả và kết thúc không sau lượt kế tiếp bắt đầu, các khoảng nối thành chuỗi không chồng.

**Giải thích và bảo vệ cách làm:**

Tính bắc cầu của thứ tự ngày bảo đảm lượt 1 kết thúc trước hoặc bằng bắt đầu lượt 2, vốn không sau bắt đầu lượt 3. Lượt đang mở/mất không được có lượt kế tiếp nên cũng không bị bỏ qua. Phải nhóm đúng mã cuốn trước.

**Đáp câu phụ 1:** Khóa mới đặt B trước A vì 10<20; kiểm kề thấy B kết thúc 10 sau A bắt đầu 01 nên từ chối dù thứ tự A rồi B khả thi. Sort theo start/end và quy tắc cùng ngày của bản hiện đặt A trước B. Một thứ tự mới phải có chứng minh tương thích phép kiểm, không chỉ làm các khoảng trông đã tăng.

**Sai lầm dễ mắc:** Kiểm ít cặp hơn được mặc định là bỏ kiểm mà không xét thứ tự đã tạo.

**Cách kiểm chứng:** Đề xuất: ba khoảng với khoảng đầu ôm hai khoảng sau, ba khoảng tiếp giáp, một lượt mở ở giữa; validator phải phát hiện ca sai.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102.

<a id="TV233"></a>
### TV233 — Reset số đang giữ mỗi ngày làm mất sách qua đêm

**Thành · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV233).

**Trả lời ngắn:** Bản đúng mang held=3 qua ngày 05, cộng lượt thứ 4 thành 4 và từ chối tại đó. Bản reset theo ngày bỏ mất 3 nghĩa vụ: ngày 05 thành 1 nên chưa thấy vượt 3.

**Giải thích và bảo vệ cách làm:**

Nhưng ngày 06 reset về 0 rồi xử lý trả làm held=-1; điều kiện held<0 vẫn từ chối. Vì vậy fixture này không chứng minh file lọt qua, chỉ chỉ ra sai vị trí/lý do kiểm. Một lượt duy nhất mượn 01 trả 10 là dữ liệu hợp lệ mà mutation cũng từ chối tại 10 vì held âm: đó là phản ví dụ phân biệt đầu ra boolean.

Bản hiện reset khi đổi mã thẻ; nghĩa vụ của cùng người phải truyền xuyên ngày. Kiểm từng tiền tố và cả giới hạn dưới 0/trên 3, không chỉ tổng cuối.

**Đáp câu phụ 1:** Không, cả hai cùng trả false dù đường kiểm khác. Thêm một lượt hợp lệ kéo dài qua ngày, expected true ở bản gốc và false ở mutation. Dùng cả ca được nhận lẫn bị chặn để tránh mutation sai bị cổng khác che.

**Sai lầm dễ mắc:** Giới hạn đồng thời được kiểm bằng trạng thái cuối kỳ hoặc từng ngày độc lập.

**Cách kiểm chứng:** Truy sự kiện 01:+3,05:+1,06:-1,10:-3; kiểm bản gốc và bản sao chỉ đổi điều kiện reset, gồm một khoảng hợp lệ qua ngày. Không suy PASS của ca từ chối là thuật toán đúng.

**Kiểm mới 18/10:** [original_sweep_valid](ThamKhao/KIEM_DINH_20261018.md#original_sweep_valid), [original_sweep_four](ThamKhao/KIEM_DINH_20261018.md#original_sweep_four), [reset_by_day_sweep_valid](ThamKhao/KIEM_DINH_20261018.md#reset_by_day_sweep_valid), [reset_by_day_sweep_four](ThamKhao/KIEM_DINH_20261018.md#reset_by_day_sweep_four). Chỉ các assertion/quan sát nêu trong ca.

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `MocMuon`, dòng 91; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102.

<a id="TV234"></a>
### TV234 — Sắp sự kiện theo ngày trước mã thẻ

**Thành · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV234).

**Trả lời ngắn:** Khi quay lại A ngày 03, code reset held về 0 rồi trừ 1 nên báo âm dù lịch sử hợp lệ.

**Giải thích và bảo vệ cách làm:**

Bản hiện gom toàn bộ sự kiện mỗi người liên tiếp, cho phép một bộ tích lũy. Nếu muốn quét toàn cục theo ngày phải giữ trạng thái riêng cho từng người hoặc đổi thuật toán, trả thêm bộ nhớ/tra cứu.

**Đáp câu phụ 1:** Không; số đang giữ đã sai và kiểm hạn mức có thể bỏ sót. Cần sửa mô hình trạng thái theo thứ tự dữ liệu.

**Sai lầm dễ mắc:** Đổi comparator được coi là không ảnh hưởng phần quét phía sau.

**Cách kiểm chứng:** Đề xuất: hai người xen ngày như trên, cộng ca A đủ 3 trong lúc B trả; so validator cũ và mutation.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `MocMuon`, dòng 91; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102.

<a id="TV235"></a>
### TV235 — Dữ liệu lịch sử tương lai dù --date là quá khứ

**Thành · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV235).

**Trả lời ngắn:** Nạp có thể thành công vì ngày 16 không sau ngày máy; ngày mô phỏng không là mốc kiểm file.

**Giải thích và bảo vệ cách làm:**

Khi trả ngày 10, kiểm timeline thấy ngày mượn 16 là mốc liên quan nên từ chối ghi lùi. Đây là hai chính sách khác nhau: nguồn dữ liệu hợp lệ và thao tác tại ngày phiên.

**Đáp câu phụ 1:** Không; nó tính trên phiếu hiện mở, có thể cho hiệu âm/không quá hạn với lượt bắt đầu sau ngày xét. Nó không là truy vấn lịch sử snapshot.

**Sai lầm dễ mắc:** --date được coi là đổi đồng hồ và mọi cổng kiểm toàn ứng dụng.

**Cách kiểm chứng:** Đề xuất: file ngày 16 và phiên ngày 10, kiểm nạp được nhưng trả bị timeline chặn, dữ liệu giữ nguyên.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102.

<a id="TV236"></a>
### TV236 — Khoảng trắng trong số của file khác menu

**Thành · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV236).

**Trả lời ngắn:** NhapSo gọi ChuanHoaChuoi trước DocSoNguyen; BoDoc.So truyền nguyên dòng, nên hợp đồng cú pháp khác nhau.

**Giải thích và bảo vệ cách làm:**

Menu dung sai phục vụ nhập tay; file v1 hiện yêu cầu số thuần. Mở rộng parser cần chốt cả dấu cộng, khoảng trắng trong trường, leading zeros và số đếm, không âm thầm đổi tất cả cú pháp để “giống UI”.

**Đáp câu phụ 1:** ChuanHoaChuoi giữ một dấu cách giữa hai cụm, parser vẫn từ chối. Không được xóa mọi khoảng trắng vì sẽ đổi giá trị.

**Sai lầm dễ mắc:** Cùng helper số được coi là cùng hợp đồng ở mọi caller.

**Cách kiểm chứng:** Đề xuất: 12, dấu cách bao quanh, 1 2 và +12 qua menu/loader; ghi đúng kỳ vọng từng cổng.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `DocSoNguyen`, dòng 65; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `BoDoc`, dòng 63; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `NhapSo`, dòng 412.

<a id="TV237"></a>
### TV237 — Dòng cuối không newline và dòng rỗng dư

**Thành · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV237).

**Trả lời ngắn:** Dòng cuối có nội dung dù không newline vẫn được nhận; dòng rỗng dư còn byte sau các bản ghi nên bị kiểm dữ liệu dư từ chối.

**Giải thích và bảo vệ cách làm:**

BoDoc.Dong phân biệt đã đọc ít nhất một ký tự với file kết thúc trước dòng cần có. Sau đủ cấu trúc, peek yêu cầu EOF; không có quy tắc bỏ qua các dòng trắng cuối.

**Đáp câu phụ 1:** Không thể dùng nó thay bản ghi bắt buộc; parser trường/số sẽ từ chối hoặc báo kết thúc sớm tùy byte thực.

**Sai lầm dễ mắc:** Mọi thay đổi newline được xem là tương đương vì không thấy ký tự trên màn hình.

**Cách kiểm chứng:** Đề xuất: ba bản byte cùng dữ liệu: LF cuối, không LF cuối, thêm LF dư; dùng --check và hash xác nhận không ghi lại.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `BoDoc`, dòng 63; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `DocNoiBo`, dòng 222.

<a id="TV238"></a>
### TV238 — BOM chỉ được bỏ ở đầu file

**Thành · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV238).

**Trả lời ngắn:** BoDoc chỉ bỏ BOM UTF-8 ở dòng 1; U+FEFF trong trường giữa file bị HopLeVanBan từ chối.

**Giải thích và bảo vệ cách làm:**

UTF-8 đúng cú pháp không có nghĩa mọi code point được phép trong dữ liệu. Cần xem byte/điểm mã và vị trí ghép, sửa nguồn nhập có kiểm soát; không xóa mọi byte không ASCII làm mất tiếng Việt.

**Đáp câu phụ 1:** Không; đó là xử lý chuỗi đọc tạm. Chỉ lưu lại mới có thể xuất định dạng mới không BOM theo Ghi.

**Sai lầm dễ mắc:** Ký tự không nhìn thấy được coi là không có dữ liệu.

**Cách kiểm chứng:** Đề xuất: BOM ở đầu và trong họ, so nhận/từ chối; kiểm file gốc không đổi sau --check.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `BoDoc`, dòng 63; [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `HopLeVanBan`, dòng 42.

<a id="TV239"></a>
### TV239 — Giới hạn dòng và giới hạn trường bảo vệ hai thứ khác

**Thành · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV239).

**Trả lời ngắn:** Dòng 100.000 bị BoDoc chặn khi đọc vượt 65536 byte; trường 600 byte bị kiểm văn bản sau tách trường.

**Giải thích và bảo vệ cách làm:**

Cận dòng giới hạn bộ nhớ trước khi parse/validate field; nếu chỉ kiểm sau đọc, input cực dài đã gây chi phí cấp phát và duyệt. Cận field bảo vệ dữ liệu hợp lệ, không thay cận framing.

**Đáp câu phụ 1:** Không; tổng số bản ghi có giới hạn riêng R/H/C. Phải bảo vệ cả kích thước bản ghi và số bản ghi.

**Sai lầm dễ mắc:** Một hạn mức byte được coi là đủ cho mọi chiều tài nguyên.

**Cách kiểm chứng:** Đề xuất: fixture vượt dòng và vượt trường riêng, kiểm thông báo/từ chối trước swap; không cần file khổng lồ thực.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `BoDoc`, dòng 63; [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `HopLeVanBan`, dòng 42.

<a id="TV240"></a>
### TV240 — Count lịch sử của từng người không phải quota riêng 200.000

**Thành · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV240).

**Trả lời ngắn:** Không; count của B bị kiểm với MAX_BAN_GHI−nh, chỉ còn 50.000 sau A.

**Giải thích và bảo vệ cách làm:**

Ngân sách lịch sử là tổng thư viện, khác hạn mức đang giữ của từng người. Cách trừ ngân sách trước cấp phát còn tránh cộng hai count lớn rồi mới phát hiện tràn hoặc vượt ngưỡng.

**Đáp câu phụ 1:** Vẫn vượt tổng nên từ chối; dòng báo lỗi có thể khác vì người đọc sau hết ngân sách. Không có nạp một phần khi người đầu hợp lệ.

**Sai lầm dễ mắc:** Giới hạn tổng bị áp độc lập cho từng danh sách con.

**Cách kiểm chứng:** Phân tích số count hoặc thử cấu hình nhỏ tương ứng 15/10 trên M20; không tuyên bố đã tạo 250.000 lượt.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `DocNoiBo`, dòng 222.

<a id="TV241"></a>
### TV241 — Đếm lịch sử toàn thư viện trong validator với bộ nhớ theo cấu hình

**Thành · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV241).

**Trả lời ngắn:** Có các mảng cuốn MAX_BAN_GHI, stack MAX_DOC_GIA và lượt MAX_BAN_GHI; bộ đếm theo số cuốn và mốc sự kiện theo số lượt thực sau gom.

**Giải thích và bảo vệ cách làm:**

KiemTraNoiBo dành trước dung lượng trần để bảo vệ việc gom/duyệt. Với cấu hình cố định, bộ nhớ nền đáng kể ngay khi H nhỏ; muốn tối ưu cấp theo dữ liệu phải đếm an toàn trước hoặc quản buffer tăng có cận và giữ exception/ownership đúng. Không lấy O(h) ô đang dùng để báo lượng đã cấp.

Ngoài các buffer theo trần còn dau[nd] (D con trỏ), active[nc] (C bộ đếm) và moc[2*nh] (tối đa hai mốc mỗi lượt). Phân tích peak phải xét cả các mảng còn sống đồng thời trong validator và bộ dữ liệu nguồn; không bỏ D chỉ vì ví dụ ít đầu.

**Đáp câu phụ 1:** Không; các mảng cấp theo MAX tăng ngay trong lần kiểm dữ liệu nhỏ. Phải tính lại sizeof từng record và peak của đọc/lưu.

**Sai lầm dễ mắc:** Ký hiệu big-O theo số node đang có mô tả chính xác cấp phát của buffer dùng cận cấu hình.

**Cách kiểm chứng:** Truy biểu thức new[]; chưa đo byte peak và chưa tăng giới hạn sản phẩm.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `Luot`, dòng 90; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `MocMuon`, dòng 91.

<a id="TV242"></a>
### TV242 — Kiểm RAM tùy ý không phải bộ cứu mọi con trỏ

**Thành · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV242).

**Trả lời ngắn:** Không. Dereference con trỏ không hợp lệ là hành vi không xác định, không được bảo đảm biến thành std::exception.

**Giải thích và bảo vệ cách làm:**

Validator kiểm cấu trúc/giá trị trong miền đối tượng có thể truy cập; cận số node không chứng minh địa chỉ hợp lệ. Chẩn đoán lỗi bộ nhớ cần debugger/sanitizer và nguồn gây lỗi trên bản sao, không dùng validator như sandbox.

**Đáp câu phụ 1:** Không; nó có thể dangling hoặc địa chỉ rác. Null-check chỉ xử lý một giá trị đặc biệt.

**Sai lầm dễ mắc:** catch bao quanh hàm được coi là bắt mọi lỗi của ngôn ngữ/hệ điều hành.

**Cách kiểm chứng:** Chỉ phân tích/sanitizer trên harness an toàn; không tạo địa chỉ rác rồi chạy trong phiên dữ liệu thật.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraToanVen`, dòng 345; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102.

<a id="TV243"></a>
### TV243 — Gộp hai người bằng cách nối lịch sử

**Thành · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV243).

**Trả lời ngắn:** Sau ghép người 10 có 4 cuốn mở; lịch sử kết hợp cũng có thể vượt 3 ở các thời điểm cũ.

**Giải thích và bảo vệ cách làm:**

Cần quy tắc xử lý danh tính, nghĩa vụ, mốc mã và audit; API xóa 20 hiện cấm khi có lịch sử. Hợp nhất phải kiểm trên bản tạm, xử lý xung đột và giữ dấu vết theo yêu cầu được duyệt, không nối mù.

**Đáp câu phụ 1:** Chưa; các lượt đã trả của hai hồ sơ có thể từng chồng quá 3 sau khi hợp nhất. Phải xét sweep theo danh tính mới.

**Sai lầm dễ mắc:** Hai hồ sơ hợp lệ riêng được coi là hợp lệ khi hợp nhất.

**Cách kiểm chứng:** Đề xuất: ca 4 mở và ca hiện 2 nhưng quá khứ 4 chồng; thiết kế phải từ chối/đòi xử lý rõ, chưa có chức năng merge.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — `DocGia`, dòng 24; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `XoaDocGia`, dòng 85.

<a id="TV246"></a>
### TV246 — Sửa ngày trả trong file có thể phá hai phía

**Thành · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV246).

**Trả lời ngắn:** Khoảng A tới 12 chồng lượt B bắt đầu 10 nên validator phải từ chối, dù ngày trả không trước ngày mượn của A.

**Giải thích và bảo vệ cách làm:**

Sửa thời gian một lượt còn kéo dài số cuốn A giữ trong sweep độc giả; có thể tạo vượt 3 với các cuốn khác. Cần xác minh sự kiện nào thực sự sai, không sửa tất cả để ép file hợp lệ.

**Đáp câu phụ 1:** Không; A có thể giữ 4 trong 11–12. Hai quan hệ theo cuốn và theo độc giả độc lập đều cần kiểm.

**Sai lầm dễ mắc:** Mỗi bản ghi hợp lệ riêng được xem là lịch sử hợp lệ toàn cục.

**Cách kiểm chứng:** Đề xuất: hai fixture phân biệt lỗi chồng cuốn và vượt 3 của người; kiểm mỗi ca báo từ chối trước swap.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KiemTraDongThoiGian`, dòng 25.

<a id="TV247"></a>
### TV247 — Đổi mọi ngày cùng một độ lệch có giữ toàn vẹn không

**Thành · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV247).

**Trả lời ngắn:** Nếu dịch đúng theo lịch, khoảng cách/thứ tự sự kiện giữ; nhưng ngày mới có thể vượt ngày máy hoặc miền 1..9999.

**Giải thích và bảo vệ cách làm:**

Không cộng trực tiếp trường ngay vì cuối tháng/năm. Sentinel không phải ngày để dịch. Quan hệ thời gian tương đối được giữ chưa đủ bảo đảm mọi validation tuyệt đối, gồm ngày không tương lai và năm xuất bản so ngày máy nếu dữ liệu đó cũng đổi. Test cần chốt miền trước phép biến đổi.

**Đáp câu phụ 1:** Không; thay độ dài khoảng, có thể làm trả trước mượn, giảm/tăng overlap và quá hạn.

**Sai lầm dễ mắc:** Một phép đổi dữ liệu giữ thứ tự luôn giữ mọi luật tuyệt đối về lịch.

**Cách kiểm chứng:** Đề xuất fixture qua tháng/năm và gần HomNay; tính expected bằng lịch độc lập, chưa chạy biến đổi này.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `SoThuTuNgay`, dòng 112; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KiemTraDongThoiGian`, dòng 25.

<a id="TV248"></a>
### TV248 — Mượn chưa lưu rồi thoát: mở lại có thể cho người khác mượn

**Thành · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV248).

**Trả lời ngắn:** Không có log bền riêng nên bản mở lại chỉ biết file cũ; có thể cho B mượn theo dữ liệu đó dù vật lý không còn sách.

**Giải thích và bảo vệ cách làm:**

Phân biệt trạng thái chương trình và thực tế quầy. Cần kiểm kệ/phiếu nguồn, khôi phục dữ liệu đúng theo quy trình; muốn giảm cửa sổ mất sự kiện cần thiết kế lưu sau giao dịch hoặc nhật ký bền có xử lý lỗi, hiện chưa có.

**Đáp câu phụ 1:** Không; phải gắn lưu bền với commit thành công và định nghĩa kết quả nếu lưu thất bại. Tần suất lưu không thay hợp đồng độ bền.

**Sai lầm dễ mắc:** Trạng thái file hợp lệ được coi là luôn khớp sách ngoài đời.

**Cách kiểm chứng:** Đề xuất: hai tiến trình nối tiếp trên fixture, lần đầu thoát không lưu; kiểm file không có lượt A. Không dùng dữ liệu nhóm.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `LuuFile`, dòng 353; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507.

<a id="TV249"></a>
### TV249 — Đổi hạn mức 3 thành tham số cấu hình

**Thành · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV249).

**Trả lời ngắn:** Validator kiểm số phiếu hiện mở và sweep lịch sử vẫn dùng 3, nên dữ liệu mới có thể không lưu/nạp được.

**Giải thích và bảo vệ cách làm:**

Cần thống nhất tham số/ràng buộc tại API, kiểm toàn vẹn và nhãn/test, đồng thời xét file cũ theo chính sách nào. Bản nộp vẫn phải giữ 3 theo đề; đây chỉ là bài sửa có yêu cầu trên bản sao.

**Đáp câu phụ 1:** Không; số dòng hiển thị và giới hạn nghiệp vụ là hai yêu cầu khác nhau. Không suy từ bố cục sang chính sách.

**Sai lầm dễ mắc:** Một điều kiện tại form/API được coi là toàn bộ nguồn quy tắc.

**Cách kiểm chứng:** Đề xuất: ca 4 mở và ca 4 chồng trong quá khứ qua cả API/lưu/nạp; so bản gốc vẫn chặn 3→4.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `DemSoSachDangMuon`, dòng 5; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102.

<a id="TV250"></a>
### TV250 — Giảm hạn mức không thể sửa bằng xóa phiếu

**Thành · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV250).

**Trả lời ngắn:** Không xóa nghĩa vụ để vừa ngưỡng. Cần chính sách chuyển tiếp giữ dữ liệu cũ, cho kết thúc lượt và chặn cấp thêm cho tới đạt mức mới.

**Giải thích và bảo vệ cách làm:**

Validator lịch sử cần biết phiên bản/quãng hiệu lực chính sách hoặc quy tắc grandfather đã được duyệt; áp ngưỡng 2 cho mọi quá khứ sẽ loại dữ liệu từng hợp lệ. Bản hiện không có cơ chế phiên bản đó.

**Đáp câu phụ 1:** Không khi chính sách thay theo thời gian; phải tách kiểm quyền mới và khả năng chấp nhận lịch sử cũ.

**Sai lầm dễ mắc:** Di trú chính sách được làm bằng sửa dữ liệu để khớp luật mới.

**Cách kiểm chứng:** Đề xuất: A3 trả dần, B2 thử mượn; file lịch sử 3 dưới luật cũ. Chỉ phân tích, không đổi hạn mức đề.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KetThucMuon`, dòng 54.

<a id="TV251"></a>
### TV251 — Tìm thẻ lặp trong một thao tác UI có đáng loại

**Thành · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV251).

**Trả lời ngắn:** Có thể giảm một số lần O(h) trong một caller kiểm soát, nhưng phải giữ kiểm nghiệp vụ ở điểm commit và không giữ node qua nạp/xóa.

**Giải thích và bảo vệ cách làm:**

Bản hiện các bước chạy tuần tự nên pointer còn sống trong màn hình đó; API theo mã dễ giữ hợp đồng độc lập. Tối ưu nội bộ phải không mở lối bỏ kiểm, còn quét lịch sử toàn kho vẫn có thể chiếm phần lớn.

**Đáp câu phụ 1:** Không; phải lấy lại theo mã hoặc giữ snapshot/khóa. Đổi điều hướng làm tiền điều kiện tối ưu cũ hết hiệu lực.

**Sai lầm dễ mắc:** Loại mọi lần tìm lặp được xem là an toàn dù vòng đời UI thay đổi.

**Cách kiểm chứng:** Đề xuất: đếm calls tìm và tổng node quét trước/sau trên bản sao, giữ kết quả thất bại/thành công và thử sau nạp.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `ManHinhMuonTra`, dòng 206; [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `LietKeSachDangMuon`, dòng 21; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114.

<a id="TV252"></a>
### TV252 — Nạp lại thay đổi hình cây nhưng không là cân bằng liên tục

**Thành · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV252).

**Trả lời ngắn:** Nạp thành công dựng lại cây cân bằng theo mã và giữ nội dung nghiệp vụ theo file, nhưng phải serialize, kiểm toàn vẹn, cấp dữ liệu tạm và hủy bản cũ.

**Giải thích và bảo vệ cách làm:**

Mọi con trỏ/view cũ bị vô hiệu. Chi phí theo toàn thư viện D/C/R/H và I/O có thể lớn hơn lợi ích một lần tìm; cũng không được nạp file cũ nếu lưu trước đó thất bại. Đây không phải AVL tự cân bằng.

**Đáp câu phụ 1:** Có thể mất các thay đổi chưa lưu. Phải kiểm đúng kết quả lưu và cân nhắc cách tái cân bằng trong RAM được phép, không dùng I/O mù.

**Sai lầm dễ mắc:** Cải thiện h được đo mà bỏ mọi chi phí/lỗi của đường lưu–nạp.

**Cách kiểm chứng:** Phân tích call graph; thử ít node trên bản sao với lưu thành công/thất bại, không coi đây là tối ưu được khuyến nghị mặc định.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `DungBST`, dòng 97; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `DocNoiBo`, dòng 222; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `ThemDocGia`, dòng 64.

<a id="TV253"></a>
### TV253 — Ghi hồ sơ theo tên cần giữ lịch sử đi cùng mã

**Thành · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV253).

**Trả lời ngắn:** Hồ sơ mã A có thể bị gắn lịch sử của mã B vì hai mảng có thứ tự khác; chỉ số dòng không là danh tính.

**Giải thích và bảo vệ cách làm:**

Phải xuất hồ sơ và danh sách lịch sử từ cùng node được chọn. Loader có thể bắt một số mâu thuẫn nhưng không chứng minh mọi lịch sử đổi chủ đều bị loại nếu quan hệ còn khả thi.

**Đáp câu phụ 1:** Có thể; cần so nội dung mã cuốn/ngày/trạng thái dưới đúng maThe, không chỉ count.

**Sai lầm dễ mắc:** Hai view cùng số phần tử được ghép bằng chỉ số mà không kiểm khóa.

**Cách kiểm chứng:** Đề xuất: hai người đảo thứ tự tên/mã, mỗi người một lượt khác cuốn và ngày; so round-trip theo mã thẻ.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `Ghi`, dòng 273; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InDocGiaTheoTenHo`, dòng 119.

<a id="TV254"></a>
### TV254 — Định dạng không có số phiên bản: phát hiện nhầm schema

**Thành · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV254).

**Trả lời ngắn:** Không; loader cũ đòi hai dòng số và đúng 6 trường độc giả. Schema mới có thể bị từ chối hoặc đọc lệch, không tự migration.

**Giải thích và bảo vệ cách làm:**

Đặt magic/version rõ, dispatch parser theo phiên bản được hỗ trợ; đọc vào bộ tạm, chuyển đổi theo quy tắc có dữ liệu mặc định được phép rồi kiểm toàn vẹn. Giữ file gốc, không dùng số 0 làm phiên bản vì có thể trùng mốc hợp lệ. Điện thoại là trường ngoài đề, cần chấp thuận trước.

**Đáp câu phụ 1:** Không; cần marker không nhập nhằng hoặc định dạng envelope rõ. Không suy schema từ việc parse một số được.

**Sai lầm dễ mắc:** Thêm một cột vào file là tương thích ngược vì tất cả trường đều là text.

**Cách kiểm chứng:** Đề xuất test file cũ, mới, version lạ, thiếu trường và rollback migration; chưa thêm format.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `DocNoiBo`, dòng 222; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `Ghi`, dòng 273; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `BoDoc`, dòng 63.

<a id="TV255"></a>
### TV255 — Hồ sơ mới mang trạng thái hoạt động ở đâu

**Thành · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV255).

**Trả lời ngắn:** DocGia mặc định THE_HOAT_DONG; ThemDocGia tạo DocGia d rồi không gán lại trạng thái, nên kế thừa default đó.

**Giải thích và bảo vệ cách làm:**

Việc HopLeDocGia được gọi với THE_HOAT_DONG để kiểm đầu vào không tự gán trường d. Đổi default làm người mới bị khóa dù validator vẫn kiểm giá trị 1; phải kiểm toàn đường khởi tạo, không chỉ form.

**Đáp câu phụ 1:** Không; form thêm dùng 3 trường và ThemDocGia không nhận tham số trạng thái. Trường không truyền tới API không quyết định dữ liệu.

**Sai lầm dễ mắc:** Giá trị được kiểm được tưởng là đã gán cho đối tượng tạo mới.

**Cách kiểm chứng:** Đề xuất: tạo người qua API và UI rồi đọc trangThaiThe; mutation default phải làm test phát hiện khác hành vi.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — `DocGia`, dòng 24; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `ThemDocGia`, dòng 64; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `ManHinhDocGia`, dòng 138.

<a id="TV257"></a>
### TV257 — Trùng mã ở xa nhau trong file được phát hiện sau bước nào

**Thành · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV257).

**Trả lời ngắn:** Hai mã 10 không kề trong file nhưng trở thành kề sau sort nodes theo mã; vòng kiểm kề sau sort phát hiện trùng trước DungBST.

**Giải thích và bảo vệ cách làm:**

Tính duy nhất cần xét toàn tập. Dựng cây chứa khóa trùng phá bất biến khoảng; tự ghi đè một người làm mất hồ sơ/lịch sử chứ không giải quyết sự nhập nhằng. Bộ tạm vẫn sở hữu các node khi từ chối, RAM đang dùng chưa swap. Không tự hợp nhất hai người theo tên hoặc mã trùng.

**Đáp câu phụ 1:** Chèn thường có thể tạo cây lệch và tổng O(R²); sort rồi dựng cân bằng có O(R log R) cho phần mã, ngoài đọc/kiểm lịch sử. Vẫn cần đúng ownership khi lỗi.

**Sai lầm dễ mắc:** Kiểm hai dòng cạnh nhau trước sort đủ chứng minh duy nhất toàn file.

**Cách kiểm chứng:** Đề xuất trùng ở đầu/cuối và tên khác, so lỗi giữ RAM; không dùng bỏ bản ghi trùng làm cách nhận file.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `DocNoiBo`, dòng 222; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `DungBST`, dòng 97.

<a id="TV258"></a>
### TV258 — Hai file cùng mã người nhưng lịch sử xung đột khi hợp nhất

**Thành · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV258).

**Trả lời ngắn:** Chưa đủ; còn va chạm đầu/ISBN/cuốn và lịch sử tham chiếu mã cuốn, cùng mốc đã cấp và chính sách hồ sơ.

**Giải thích và bảo vệ cách làm:**

Phải xác minh danh tính nào là cùng đối tượng thật, ánh xạ riêng người/đầu/cuốn cho nguồnB, cập nhật mọi tham chiếu tương ứng và kiểm timeline/hạn mức sau ghép. Trong v1 lịch sử gắn bằng ownership dưới người, nên chuyển đúng node người lẫn mã cuốn trong từng lượt. NAP hiện là thay, chưa merge.

**Đáp câu phụ 1:** Không; namespace cuốn được cấp độc lập. Cần đối soát vật lý, không ghép tự động chỉ theo chuỗi trùng.

**Sai lầm dễ mắc:** Đổi duy nhất mã độc giả là giải quyết mọi va chạm khi ghép thư viện.

**Cách kiểm chứng:** Đề xuất hai fixture có va chạm chéo và một dữ liệu không va; kiểm mapping không làm đổi chủ lượt.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `DocNoiBo`, dòng 222; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `ChenDocGiaCoMa`, dòng 51; [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — `DocGia`, dòng 24.

<a id="TV259"></a>
### TV259 — Chọn predecessor thay successor khi xóa hai con

**Thành · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV259).

**Trả lời ngắn:** Predecessor là 30; tháo 30 khỏi phải của 20 bằng cách nối ô đó sang 25, rồi chuyển nguyên node 30 lên chỗ 40.

**Giải thích và bảo vệ cách làm:**

30 nhận cây trái đã tháo nó và cây phải 70; lịch sử của 30 đi theo node, không tráo danh tính. Tìm predecessor tốn đường xuống phải ở nhánh trái O(h), successor tương tự phía kia. Chọn nhánh có vẻ ngắn hơn không làm BST thành cây tự cân bằng.

**Đáp câu phụ 1:** Tháo 20 trước để old->left thành 10, rồi gắn 20.left=old->left; tránh tự nối 20 với chính nó, đối xứng nhánh successor trực tiếp.

**Sai lầm dễ mắc:** Đổi successor sang predecessor chỉ là đổi tên biến mà không đổi phía tìm và cây con cần giữ.

**Cách kiểm chứng:** Đề xuất kiểm inorder/tập mã/ownership lịch sử trên hai biến thể và trường hợp trực tiếp; chưa sửa sản phẩm.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `XoaDocGia`, dòng 85.

<a id="TV260"></a>
### TV260 — Xóa một phần lịch sử để sửa số đang giữ

**Thành · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV260).

**Trả lời ngắn:** Cuốn vẫn 1 mà không có phiếu mở; người khác bị trạng thái cuốn chặn, lưu bị kiểm toàn vẹn từ chối.

**Giải thích và bảo vệ cách làm:**

Trả phải kết thúc phiếu và đổi cuốn, giữ lịch sử để top/đối soát. Xóa node không chỉ là cách khác để đạt count 0, nó mất sự kiện và phá quan hệ.

**Đáp câu phụ 1:** Không; lịch sử và top vẫn mất lượt, không có ngày trả. Cùng trạng thái hiện tại không chứng minh cùng lịch sử.

**Sai lầm dễ mắc:** Chỉ số tổng đang giữ đúng được coi là toàn bộ nghiệp vụ đã đúng.

**Cách kiểm chứng:** Đề xuất: so thao tác trả chuẩn với mutation xóa node trên hai fixture; kiểm count, cuốn, H, top và ngày trả.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `DemSoSachDangMuon`, dòng 5; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KetThucMuon`, dòng 54; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102.

<a id="TV301"></a>
### TV301 — Đúng với cha nhưng sai khoảng khóa của tổ tiên

**Thành · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV301).

**Trả lời ngắn:** TimDocGia đi phải ở 40 và không tìm được 50; inorder cho 20,50,40 nên không tăng. 50 ở trong toàn cây con trái 40 phải nhỏ hơn 40, dù nó lớn hơn cha 20.

**Giải thích và bảo vệ cách làm:**

KiemTraNoiBo truyền khoảng mở (lo,hi) theo tổ tiên: gốc(0,INT_MAX+1), nhánh trái 40 có hi 40, nhánh phải 20 có (20,40). Khóa 50 bị từ chối. Cận long long biểu diễn được INT_MAX+1; kiểm cục bộ với cha bỏ mất ràng buộc từ ông. Không tự dựng cân bằng rồi coi dữ liệu RAM hỏng đã được chữa đúng ownership.

**Đáp câu phụ 1:** 30 hợp lệ vì 20<30<40. 40 trùng khóa gốc và vi phạm cận hi, phải từ chối; đổi sang khoảng đóng che khóa trùng. Mỗi node hợp lệ phải thỏa đồng thời mọi cận tổ tiên, không chỉ một nhánh gần nhất.

**Sai lầm dễ mắc:** Kiểm trái<cha<phải ở từng cạnh là đã chứng minh BST toàn cục.

**Cách kiểm chứng:** Dựng cây debug không chu trình, gọi tìm/inorder/validator rồi hủy bình thường; đổi 50→30→40 để kiểm cả ca nhận và từ chối.

**Kiểm mới 18/10:** [original_bst_bounds](ThamKhao/KIEM_DINH_20261018.md#original_bst_bounds). Chỉ các assertion/quan sát nêu trong ca.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `TimDocGia`, dòng 8, 13; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `LayDanhSachDocGia`, dòng 18; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102.

<a id="TV23"></a>
### TV23 — Độc giả chỉ giữ một cuốn nhưng mượn vẫn chậm

**Thành · P3 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV23).

**Trả lời ngắn:** Đếm đang mượn và kiểm quá hạn duyệt lịch sử A; nối cuối cũng có thể duyệt toàn bộ lịch sử A. Giới hạn ba chỉ áp dụng lượt đang mở.

**Giải thích và bảo vệ cách làm:**

Kiểm dòng thời gian tạo view độc giả rồi duyệt toàn bộ H lượt để đếm lượt mở của cuốn và tìm mốc liên quan. Chi phí này không mất đi khi A có ít sách đang giữ.

Cận gộp gồm O(h+chi phí tìm cuốn+R+H+H_A), chưa tính chuỗi; với dữ liệu hợp lệ H_A≤H. Không được gọi toàn hàm O(log R).

**Đáp câu phụ 1:** Không; đó là công việc kiểm khác và còn phải tìm max liên quan/count toàn cục.

**Sai lầm dễ mắc:** Tối ưu vị trí vài node giải quyết mọi lần quét H.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Đánh dấu từng vòng lặp trong call graph; nếu đo, giữ nguyên số đang mượn rồi tăng riêng lịch sử để quan sát đúng yếu tố.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KiemTraDongThoiGian`, dòng 25; [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `DemSoSachDangMuon`, dòng 5.

<a id="TV24"></a>
### TV24 — Gọi helper chèn trực tiếp có bỏ qua mốc mã?

**Thành · P3 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV24).

**Trả lời ngắn:** Helper có thể chèn 99 vào BST nhưng không cập nhật mốc của ThuVien; bộ kiểm thấy mã vượt mốc 12 nên không chấp nhận lưu. Tìm kiếm thành công chưa đủ.

**Giải thích và bảo vệ cách làm:**

Helper từ chối đối tượng đã có dsMuonTra nhằm tránh nhập quyền sở hữu lịch sử bằng sao chép nông; nó chỉ nhận hồ sơ rỗng lịch sử.

Luồng cấp mã chuẩn là ThemDocGia: kiểm điều kiện, chọn mốc+1, chèn thành công rồi cập nhật mốc. Loader hiện tại có luồng dựng và kiểm riêng.

**Đáp câu phụ 1:** Chưa; caller còn phải bảo vệ hạn mức, quy tắc cấp và hợp đồng đầu vào. Không dùng helper thấp làm thay API đầy đủ.

**Sai lầm dễ mắc:** Sửa một metadata là đã tái hiện tất cả tiền điều kiện API cấp cao.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Trên fixture độc lập, đối chiếu TimDocGia với KiemTraToanVen trước khi thử lưu; không đưa lời gọi helper trực tiếp vào luồng người dùng.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `ChenDocGiaCoMa`, dòng 51; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `ThemDocGia`, dòng 64; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102.

<a id="TV27"></a>
### TV27 — Xem lịch sử mới nhất trước nhưng giữ danh sách gốc

**Thành · P3 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV27).

**Trả lời ngắn:** Kết quả phải Y,Z,X; đây là xem toàn lịch sử nên hiển thị trạng thái và không bỏ lượt đã trả/mất. Danh sách gốc vẫn X→Y→Z.

**Giải thích và bảo vệ cách làm:**

Có thể dùng mảng view kèm vị trí gốc và thuật toán tự cài; tiêu chí chấp nhận là giữ thứ tự gốc khi ngày bằng nhau. Không dùng std::sort hoặc container thay danh sách.

Người sửa phải tự giải thích độ phức tạp của cách chọn; test rỗng, một lượt, ngày bằng nhau, cùng mã xuất hiện nhiều lần và mã thẻ không tồn tại.

Cụ thể, gom (con trỏ lượt, vị trí gốc, số thứ tự ngày) vào view H_A ô, heap sort theo ngày giảm rồi vị trí gốc tăng. Có O(H_A log H_A) phép so khóa số và O(H_A) bộ nhớ view, cộng tìm người O(h), tính ngày/gom O(H_A), nối tên nếu hiển thị và độ dài output. Tính ordinal trước sort để lỗi ngày xảy ra trước xuất; không đổi next. Đây là thuật toán đề xuất chứ chưa có chức năng mới.

**Đáp câu phụ 1:** Mang vị trí gốc làm khóa phụ trong view; khi ngày hòa so vị trí, rồi sort theo toàn khóa.

**Sai lầm dễ mắc:** Muốn ổn định kết quả bắt buộc phải sửa liên kết nguồn hoặc dùng stable sort có sẵn.

**Cách kiểm chứng:** Đề xuất kiểm chứng: So chuỗi next và file lưu trước–sau báo cáo; kiểm kết quả đồng ngày bằng thứ tự gốc, không tình cờ dựa vào mã cuốn.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `LietKeSachDangMuon`, dòng 21; [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — `MuonTra`, dòng 20.

<a id="TV67"></a>
### TV67 — Gia hạn bảy ngày bằng sửa ngày mượn

**Thành · P3 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV67).

**Trả lời ngắn:** Sửa ngày mượn làm mất thời điểm bắt đầu thật, thay đổi kiểm chồng lấn và báo cáo quá hạn; không còn là lịch sử ban đầu.

**Giải thích và bảo vệ cách làm:**

Bản hiện tại không có gia hạn. Cần hỏi đặc tả và quyền bổ sung biểu diễn trước, không tự thêm hoặc dùng ngày mượn làm ngày hạn trả.

**Đáp câu phụ 1:** Không; nếu cần audit phải có sự kiện tương ứng và quy tắc được cho phép, không suy từ deadline hiện tại.

**Sai lầm dễ mắc:** Thêm một ngày mới tự cung cấp đầy đủ lịch sử gia hạn.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Lấy lượt đã tồn tại trước giao dịch khác, truy vết kiểm toàn vẹn và báo cáo sau đổi ngày trên giấy.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — `MuonTra`, dòng 20; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KiemTraDongThoiGian`, dòng 25; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102.

<a id="TV68"></a>
### TV68 — Hoàn tác lần trả gần nhất

**Thành · P3 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV68).

**Trả lời ngắn:** Sẽ có hai lượt mở trên cùng cuốn và có thể chồng khoảng thời gian; hạn mức của A cũng có thể đã dùng cho cuốn khác.

**Giải thích và bảo vệ cách làm:**

Không có undo hiện tại. Mở rộng cần kiểm chuỗi phụ thuộc và quy tắc lịch sử, không chỉ đổi trạng thái cũ về 0.

**Đáp câu phụ 1:** Không; có thể thành 4 lượt mở. Undo phải kiểm cả chuỗi phụ thuộc ở độc giả lẫn cuốn.

**Sai lầm dễ mắc:** Không xung đột ở cuốn thì undo chắc chắn hợp lệ.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Vẽ chuỗi A trả, B mượn, A mượn cuốn khác rồi đề xuất undo; chỉ các cấu trúc bị ảnh hưởng.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KetThucMuon`, dòng 54; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102.

<a id="TV75"></a>
### TV75 — Không quá hạn hay dữ liệu không tính được?

**Thành · P3 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV75).

**Trả lời ngắn:** QuaHan7Ngay kiểm ngày và trả false khi không hợp lệ; điều đó không chứng minh dữ liệu tốt. MuonSach còn kiểm timeline liên quan và từ chối ngày sai trước commit.

**Giải thích và bảo vệ cách làm:**

Báo cáo dùng KhoangCachNgay / SoThuTuNgay có thể ném lỗi trên ngày sai; đó là hành vi khác bool helper. RAM hỏng là ca chẩn đoán, không đầu vào hợp lệ thông thường.

Nếu cần báo đủ nguyên nhân, thiết kế kết quả valid/overdue hoặc lỗi riêng; không cho 'không tính được' tự trở thành quyền mượn.

**Đáp câu phụ 1:** Không; chỉ biểu diễn lỗi rõ hơn. Cần nguồn dữ liệu đúng và quy trình phục hồi riêng.

**Sai lầm dễ mắc:** Báo lỗi rõ đồng nghĩa tự sửa được nguyên nhân dữ liệu.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Tiêm lỗi ngày trên bản sao có kiểm soát, đọc nhánh từ chối và chắc chắn không thêm phiếu; không lưu bộ lỗi như dữ liệu thật.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `CoSachQuaHan7Ngay`, dòng 9; [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `QuaHan7Ngay`, dòng 124; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KiemTraDongThoiGian`, dòng 25; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InDocGiaQuaHan`, dòng 148.

<a id="TV76"></a>
### TV76 — Phiên mở qua nửa đêm

**Thành · P3 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV76).

**Trả lời ngắn:** ChayUngDung lấy ngay một lần khi khởi động hoặc từ --date; vòng menu tiếp tục dùng giá trị đó.

**Giải thích và bảo vệ cách làm:**

HomNay trong kiểm không tương lai được gọi lại, nhưng không tự thay ngày giao dịch đã lưu của phiên. Đây là giới hạn cần nói rõ nếu muốn cập nhật ngày tự động.

**Đáp câu phụ 1:** Không; lưu không gán lại ngày phiên. Cần thay hành vi điều phối nếu yêu cầu tự cập nhật.

**Sai lầm dễ mắc:** Mọi thao tác quay về menu đều khởi tạo lại ngày.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Chỉ biến ngay ngoài vòng lặp và các lời gọi MuonTra; dùng clock giả lập nếu kiểm thực nghiệm.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KiemTraNgayGiaoDich`, dòng 17.

<a id="TV89"></a>
### TV89 — Ghi file bằng sizeof(DocGia)

**Thành · P3 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV89).

**Trả lời ngắn:** std::string và con trỏ chứa chi tiết bộ nhớ của tiến trình; ghi struct thô không lưu nội dung chuỗi/lịch sử thành định dạng độc lập.

**Giải thích và bảo vệ cách làm:**

Phải tuần tự hóa từng trường và node rồi dựng lại liên kết. File v1 không lưu địa chỉ heap.

**Đáp câu phụ 1:** Không; phải ghi node theo thứ tự/trường logic và dựng lại liên kết, địa chỉ next vẫn vô nghĩa ở tiến trình mới.

**Sai lầm dễ mắc:** Thêm nội dung string là đủ để raw struct chứa pointer có thể phục hồi.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Mô tả dữ liệu cần phục hồi cho một độc giả có hai lượt, đối chiếu Ghi/DocNoiBo.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — `DocGia`, dòng 24; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `Ghi`, dòng 273; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `DocNoiBo`, dòng 222.

<a id="TV93"></a>
### TV93 — Một màn hình cần nhiều số liệu độc giả: quét hay lưu bộ đếm?

**Thành · P3 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV93).

**Trả lời ngắn:** Hai nhóm hoạt động/khóa phân hoạch trạng thái thẻ hợp lệ; nhóm đang giữ/quá hạn chồng lên chúng, không cộng cả bốn thành R.

**Giải thích và bảo vệ cách làm:**

Một lượt qua độc giả/lịch sử có thể tích lũy tạm O(R+H), giữ BST duy nhất theo mã. Chia cây thay cấu trúc sở hữu và kéo theo đồng bộ.

Cache lâu dài phải cập nhật mọi thao tác kể cả chỉ qua ngày làm phát sinh quá hạn dù không có giao dịch; lợi ích cần đo và được phép theo đề.

**Đáp câu phụ 1:** Có; cache phụ thuộc ngày đối chiếu, không chỉ version mutation. Cần khóa cache bao gồm thời điểm hoặc lịch làm mới.

**Sai lầm dễ mắc:** Chỉ cập nhật cache khi có ghi dữ liệu là đủ cho mọi thống kê.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Dùng người khóa+quá hạn, hoạt động+không giữ và mất+vẫn giữ; kiểm số liệu trước/sau qua mốc 8 ngày.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `LayDanhSachDocGia`, dòng 18; [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `DemSoSachDangMuon`, dòng 5; [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `CoSachQuaHan7Ngay`, dòng 9; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `TongQuan`, dòng 263.

<a id="TV96"></a>
### TV96 — Dừng sau khi thấy ba lượt mở có còn đúng với mọi caller?

**Thành · P3 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV96).

**Trả lời ngắn:** Trong dữ liệu hợp lệ chỉ tối đa 3 mở, nhưng vẫn có thể quét gần hết 80.003 node để gặp chúng; không có cận 3 vòng.

**Giải thích và bảo vệ cách làm:**

Dừng ở 3 đủ cho predicate đã đủ hạn mức, nhưng không trả tổng chính xác nếu dữ liệu sai 4. Thay helper chung có thể ảnh hưởng chẩn đoán/ caller đếm.

Có thể tách predicate hoặc tham số giới hạn với tên/hợp đồng rõ; kiểm toàn vẹn vẫn phải phát hiện vượt 3, không dùng số đã cắt để xác nhận hợp lệ.

**Đáp câu phụ 1:** Không nếu phần sau chưa biết; có thể còn lượt mở. Chỉ true ở ngưỡng có căn cứ dừng, false cần hết dữ liệu hoặc bằng chứng khác.

**Sai lầm dễ mắc:** Dừng sớm được theo cả hai hướng vì kết quả là bool.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Chọn mở ở đầu/cuối và RAM giả lập 4 mở; so số bước lẫn ý nghĩa kết quả cho từng caller.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `DemSoSachDangMuon`, dòng 5; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102.

<a id="TV98"></a>
### TV98 — Nhập lịch sử cũ thay cho giao dịch hiện tại

**Thành · P3 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV98).

**Trả lời ngắn:** API hiện tại chặn ghi lùi qua mốc độc giả/cuốn; không là công cụ chèn sự kiện quá khứ.

**Giải thích và bảo vệ cách làm:**

Nhập lịch sử cần kiểm chồng cuốn, hạn mức từng thời điểm và giới hạn thông tin thẻ/giờ trong v1; phải giữ riêng với giao dịch hiện tại và hỏi quy tắc.

**Đáp câu phụ 1:** Không; còn chồng cuốn, số giữ từng thời điểm và liên kết trạng thái. Thứ tự next không thay kiểm nghiệp vụ toàn cục.

**Sai lầm dễ mắc:** Đặt đúng vị trí lịch sử là đủ hợp lệ về thời gian.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Lấy một cuốn đã có hai lượt nối tiếp, đề xuất lượt chen giữa và kiểm tính khả thi trên giấy.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KiemTraDongThoiGian`, dòng 25; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102.

<a id="TV100"></a>
### TV100 — Một ca ở quầy có bốn yêu cầu liên tiếp và hai lần thất bại

**Thành · P3 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TV100).

**Trả lời ngắn:** Trả Z bị từ chối vì không có phiếu mở của A; B/Z giữ nguyên. Trả X được dù A khóa và X quá hạn.

**Giải thích và bảo vệ cách làm:**

Xin W bị khóa chặn, W vẫn rảnh; trả Y được. Cuối ca A giữ 0 cuốn nhưng thẻ vẫn khóa; X, Y rảnh và lịch sử trả được giữ.

Mỗi lời gọi là thao tác riêng, thất bại của một bước không hoàn tác thành công trước đó. Thông báo phải theo từng bước và lưu file là bước khác.

**Đáp câu phụ 1:** Không; cần kết quả từng lời gọi và phiếu/cuốn liên quan. Nhiều chuỗi khác nhau có cùng số cuối.

**Sai lầm dễ mắc:** Hậu trạng thái tổng hợp duy nhất đủ mô tả mọi giao dịch trong ca.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Lập bảng 4 bước với trạng thái 3 cuốn của người đọc và W; đối chiếu h, i, top và thử lưu–nạp trên dữ liệu riêng.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KetThucMuon`, dòng 54; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114; [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `LietKeSachDangMuon`, dòng 21; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `HieuChinhDocGia`, dòng 73.


<a id="tan"></a>
## Tấn — 100 đáp án

<a id="TN01"></a>
### TN01 — Đổi tên xong, hai kiểu liệt kê có còn đúng?

**Tấn · P1 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN01).

**Trả lời ngắn:** Theo tên: 30, 20, 10; theo mã: 10, 20, 30. Đổi tên hợp lệ không đổi khóa BST.

**Giải thích và bảo vệ cách làm:**

Bản hiện tại heap sort mảng con trỏ tạm theo tên–họ–mã; không hoán đổi thông tin nằm tại các nút.

Nếu đổi cả bản ghi giữa vị trí cây, mã có thể nằm sai nhánh; TimDocGia đi theo mã sẽ bỏ qua nút tồn tại.

**Đáp câu phụ 1:** Kiểm cặp mã→họ/tên trước–sau và lịch sử thuộc người thật. BST có thể vẫn đúng khóa, nhưng hồ sơ bị tráo danh tính mô tả; kiểm mỗi tập mã hoặc thứ tự tên riêng không đủ.

**Sai lầm dễ mắc:** Sắp con trỏ tạm và tráo dữ liệu node là một việc.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Tạo ba độc giả trong bản sao; kiểm hai thứ tự và tra đủ ba mã sau khi in theo tên.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InDocGiaTheoTenHo`, dòng 119; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `TimDocGia`, dòng 8, 13.

<a id="TN02"></a>
### TN02 — In theo thể loại rồi thêm đầu sách

**Tấn · P1 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN02).

**Trả lời ngắn:** Báo cáo thể loại có nhóm LichSu chứa A,C rồi Toan chứa B; mảng gốc trước khi chèn vẫn A,B,C.

**Giải thích và bảo vệ cách làm:**

Sau chèn BB, thứ tự gốc phải A,B,BB,C. Thuộc tính thể loại của BB quyết định nhóm hiển thị tiếp theo.

Lower bound chỉ đúng khi mảng đã tăng theo cùng bộ so tên–ISBN; sắp gốc theo thể loại làm mất tiền điều kiện.

**Đáp câu phụ 1:** Có; một màn hình d trông đúng không kiểm invariant nguồn. Cần kiểm trực tiếp thứ tự gốc và thao tác phụ thuộc sau đó.

**Sai lầm dễ mắc:** Báo cáo đẹp đủ chứng minh việc sort không gây tác dụng phụ.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Chụp dãy ISBN trước/sau in d; thêm BB và kiểm toàn vẹn. Không chỉ nhìn báo cáo thể loại.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `InDauSachTheoTheLoai`, dòng 98; [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `TimViTriChenTheoTen`, dòng 43.

<a id="TN03"></a>
### TN03 — Có tám lượt lịch sử nhưng chỉ giữ hai cuốn

**Tấn · P1 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN03).

**Trả lời ngắn:** In đúng hai lượt trạng thái MUON_DANG_MUON của S1,S2 cùng tên đầu sách; sáu lượt đã trả vẫn được lưu.

**Giải thích và bảo vệ cách làm:**

Giới hạn ba áp dụng số cuốn đang giữ, không giới hạn tổng số nút lịch sử hay số nút cần duyệt.

Một mã cuốn có nhiều lần mượn; trạng thái lượt mới quyết định h, không phải vị trí xuất hiện đầu tiên.

**Đáp câu phụ 1:** Không; khử trùng trình bày che dữ liệu hỏng. h hiện lọc từng node nên có thể in hai dòng; validator toàn cục mới từ chối hai lượt mở. Cần đối soát phiếu gốc, không tự chọn một lượt để giữ.

**Sai lầm dễ mắc:** Mọi lịch sử chưa xóa đều là sách đang mượn.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Đặt hai lượt mở sau hơn ba lượt đóng; đối chiếu h và số lượt lịch sử trước/sau báo cáo.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `LietKeSachDangMuon`, dòng 21; [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `DemSoSachDangMuon`, dòng 5.

<a id="TN05"></a>
### TN05 — Tên bằng nhau, heap sort có đảo kết quả ngẫu nhiên?

**Tấn · P1 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN05).

**Trả lời ngắn:** Ba tên có khóa ASCII bằng nhau; Le trước Tran, sau đó mã tăng: 20,10,30.

**Giải thích và bảo vệ cách làm:**

Tên–họ–mã là bộ khóa đầy đủ với mã duy nhất; không cần dựa vào tính ổn định của heap sort để phá hòa.

SoSanhChuoi không đối chiếu từ điển tiếng Việt đầy đủ; dữ liệu có dấu cần hiểu đúng giả định so sánh hiện tại.

**Đáp câu phụ 1:** Heap không ổn định không bảo đảm giữ mã tăng khi khóa bằng. Stable sort trên inorder mã tăng có thể giữ đúng mã phụ ngầm; nhưng đó là bảo đảm từ đầu vào và thuật toán, không từ comparator. Khóa mã tường minh tránh phụ thuộc hai điều kiện ấy.

**Sai lầm dễ mắc:** Heap sort không ổn định nghĩa kết quả luôn ngẫu nhiên.

**Cách kiểm chứng:** Đề xuất kiểm chứng: So dãy mã ở ba lần in; bổ sung tên có dấu để phân biệt quy tắc hiện tại với kỳ vọng ngôn ngữ tự nhiên.

**Ca liên quan đã chạy 17/10 (không tái chạy đợt này):** [reader_ties_and_readonly](ThamKhao/KIEM_CHUNG_RUNTIME.md#reader_ties_and_readonly).

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `TenHoTruoc`, dòng 44; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InDocGiaTheoTenHo`, dòng 119; [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `SoSanhChuoi`, dòng 27.

<a id="TN201"></a>
### TN201 — Một nút được đưa vào view đúng một lần

**Tấn · P1 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN201).

**Trả lời ngắn:** Thứ tự đầu là 20,25,30; sau xuất một nút phải chuyển sang cây con phải của nó.

**Giải thích và bảo vệ cách làm:**

Stack giữ các tổ tiên còn chờ xuất sau nhánh trái. Sau xuất 20, đi phải 30 rồi đẩy 30,25; pop 25 rồi 30. Đi lại trái sẽ lặp phần đã duyệt, có thể lặp vô hạn hoặc bỏ nhánh phải. Mỗi nút được đẩy và pop một lần trong cây hợp lệ: O(R), bộ nhớ hoạt động O(h), dù code cấp stack theo MAX_DOC_GIA.

**Đáp câu phụ 1:** Không: tối đa một nút chờ ở đường đó; cây lệch trái mới làm stack chứa R nút. Cả hai vẫn xuất R nút.

**Sai lầm dễ mắc:** Đồng nhất chiều cao cây với số phần tử stack luôn thực sự dùng trên mọi hình cây.

**Cách kiểm chứng:** Truy vết bằng giấy các lần push/pop trên cây đã nêu; chưa chạy mutation vòng duyệt.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `LayDanhSachDocGia`, dòng 18.

<a id="TN09"></a>
### TN09 — Bản xuất có dòng quá dài nhưng xem chi tiết không phải sửa dữ liệu

**Tấn · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN09).

**Trả lời ngắn:** Phải giữ dòng đầy đủ từ text/all; phần cắt để vẽ không là dữ liệu gốc cho chi tiết hoặc bản xuất.

**Giải thích và bảo vệ cách làm:**

HienThiPhanTrang lấy lát dòng đầy đủ rồi DongBang chỉ trình bày theo chiều rộng; Enter dùng nội dung dòng. Nếu ghi lại từ khung CHAR_INFO, dấu rút gọn và bố cục thay tên thật. Không dùng độ rộng màn hình để kết luận dữ liệu bị lưu ngắn.

**Đáp câu phụ 1:** Bản xuất mất hậu tố phân biệt, có thể gán nhầm tên khi người đọc ghép bằng chữ. Đối soát bằng mã/ISBN và chuỗi đầy đủ, kiểm cặp trường từng dòng. Cùng số dòng không chứng minh giữ thông tin.

**Sai lầm dễ mắc:** Những gì terminal vẽ chính là toàn bộ chuỗi đang lưu trong báo cáo.

**Cách kiểm chứng:** Truy nguồn text đến dòng chi tiết; đề xuất TUI với hai tên dài, chưa kiểm bằng mắt trên terminal.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `DongBang`, dòng 230; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `XemChiTiet`, dòng 242; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `HienThiPhanTrang`, dòng 450.

<a id="TN19"></a>
### TN19 — In mã tăng bằng duyệt trực tiếp hay phải tạo view?

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN19).

**Trả lời ngắn:** Inorder xuất 10, 15, 20, 30; in khi đẩy sẽ đưa cha ra trước một số con trái nên không bảo đảm mã tăng.

**Giải thích và bảo vệ cách làm:**

Có thể thiết kế duyệt xuất trực tiếp để bỏ mảng view và một lần đếm, nhưng vẫn cần stack duyệt hoặc cơ chế duyệt hợp lệ. Không tự sửa BST.

Nếu tiếp tục ghi ostringstream thì vẫn giữ toàn báo cáo; tối ưu cấu trúc tạm chưa biến UI thành đọc lười. Cần đo cả tạo báo cáo và xuất.

**Đáp câu phụ 1:** Có; phần đã ghi ra file không tự bị xóa. Cần quy định xuất nguyên khối hoặc chấp nhận file chưa hoàn tất.

**Sai lầm dễ mắc:** Bỏ view không ảnh hưởng hợp đồng lỗi của toàn pipeline.

**Cách kiểm chứng:** Đề xuất kiểm chứng: So nội dung/thứ tự hai cách trên cây lệch và cân bằng, rồi tính bộ nhớ riêng stack / view /text.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InDocGiaTheoMa`, dòng 111; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `LayDanhSachDocGia`, dòng 18; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `HienThiPhanTrang`, dòng 450.

<a id="TN21"></a>
### TN21 — Kết quả mới chỉ ghi một phần khi mảng view thiếu chỗ

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN21).

**Trả lời ngắn:** Helper kiểm cận trước ghi nên không ghi ô thứ 3; hai ô trước có thể đã được điền, cây không bị sửa bởi việc lấy view.

**Giải thích và bảo vệ cách làm:**

Không dùng kết quả từng phần như danh sách đầy đủ sau exception; caller cần bỏ kết quả hoặc nêu rõ lỗi.

Code hiện tại gọi liên tiếp trong cùng luồng, không tự có giao dịch chen giữa; đây là lỗi caller giả lập. Nếu mở rộng đồng thời cần snapshot /khóa theo đặc tả, không chỉ tăng capacity tùy ý.

out=nullptr là chế độ chỉ đếm: kiểm capacity chỉ áp khi out khác null; giới hạn tổng MAX_DOC_GIA vẫn áp. Gom hai kiểm này thành một kiểm capacity vô điều kiện sẽ làm mọi cây không rỗng thất bại khi đếm.

**Đáp câu phụ 1:** Không; chỉ n ô đầu được helper điền, phần dư không là dữ liệu hợp lệ.

**Sai lầm dễ mắc:** Miền bộ nhớ được cấp là miền kết quả hợp lệ.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Dựng caller lỗi trên bản sao và kiểm cây vẫn có 3 người; đọc vị trí kiểm trước out [n].

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `LayDanhSachDocGia`, dòng 18; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InDocGiaTheoTenHo`, dòng 119.

<a id="TN29"></a>
### TN29 — Một thể loại bị in thành nhiều nhóm dù sort đúng

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN29).

**Trả lời ngắn:** Comparator hạ ASCII nên ba thể loại cùng nhóm; so byte gốc để phát hiện đổi nhóm có thể tách chúng tùy thứ tự tên.

**Giải thích và bảo vệ cách làm:**

Dùng cùng quan hệ tương đương khi sắp và phân nhóm; nhãn có thể lấy từ đầu đầu tiên, không cần sửa mọi chuỗi gốc.

Chuẩn hóa hiện tại không case-fold tiếng Việt đầy đủ; không mở rộng kết luận sang mọi chữ có dấu. Muốn quy tắc khác cần đổi nhất quán và kiểm dữ liệu.

**Đáp câu phụ 1:** Không; có thể format nhãn riêng, giữ khóa tương đương và dữ liệu nguồn.

**Sai lầm dễ mắc:** Nhóm hiển thị thống nhất buộc phải ghi đè toàn bộ chuỗi nguồn.

**Cách kiểm chứng:** Đề xuất kiểm chứng: So số nhóm, tập ISBN mỗi nhóm và nhãn; thêm một cặp có dấu để ghi đúng giới hạn.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `InDauSachTheoTheLoai`, dòng 98; [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `SoSanhChuoi`, dòng 27.

<a id="TN30"></a>
### TN30 — Vì sao phải sắp view thể loại khi kho đã sắp tên?

**Tấn · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN30).

**Trả lời ngắn:** In khi loại thay đổi trên kho gốc tạo L2, L1, L2 nên tách nhóm. Cần một thứ tự theo thể loại hoặc cơ chế thu nhóm khác.

**Giải thích và bảo vệ cách làm:**

Quét mỗi loại có thể đúng nếu liệt kê loại duy nhất và thứ tự loại đúng, nhưng tốn nhiều lượt quét tới O(D²) và cần tránh lặp loại; không miễn phí chỉ vì bỏ view.

View hiện tại sort thể loại–tên– ISBN bằng insertion sort O(D²), bộ nhớ O(D), không phá thứ tự tên của kho phục vụ chèn.

**Đáp câu phụ 1:** Có thể D²; còn phải xác định thứ tự và tránh loại trùng. Bỏ view không tự giảm thời gian.

**Sai lầm dễ mắc:** Không có mảng phụ nghĩa thuật toán luôn rẻ hơn.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Lập kết quả expected L1: B, L2: A, C, rồi so số so sánh/dịch trên dữ liệu nhiều loại xen kẽ.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `InDauSachTheoTheLoai`, dòng 98; [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `TimViTriChenTheoTen`, dòng 43.

<a id="TN38"></a>
### TN38 — Gộp hai cuốn cùng tên trên bảng rồi trả một cuốn

**Tấn · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN38).

**Trả lời ngắn:** Bản hiện tại in hai lượt với hai mã khác nhau; tên không đủ chọn bản. Không được tự suy bản người dùng đưa từ tên.

**Giải thích và bảo vệ cách làm:**

Màn hình gộp có thể có danh sách con mã/địa điểm/ngày mượn, chọn rõ bản trước gọi TraSach; vẫn kiểm người sở hữu và trạng thái.

Sau trả một, số đang giữ giảm 1, top không tăng hay giảm; lịch sử đã trả vẫn có. Gộp trình bày không gộp hai danh tính cuốn.

**Đáp câu phụ 1:** Không; phải kiểm theo mã. Nhóm giảm số lượng chỉ là số tổng, không bảo vệ trả đúng bản.

**Sai lầm dễ mắc:** Hai cuốn cùng tên thay thế cho nhau trong mọi thao tác.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Trả riêng X#2 trên bản sao, kiểm X#1 vẫn mở và không đổi nhầm phiếu đầu tiên có cùng tên.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `LietKeSachDangMuon`, dòng 21; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `TraSach`, dòng 139; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InTop10SachDuocMuonNhieuNhat`, dòng 172.

<a id="TN43"></a>
### TN43 — Xem sách đang giữ rồi hủy: giao dịch bắt đầu từ lúc nào?

**Tấn · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN43).

**Trả lời ngắn:** Đóng báo cáo chỉ kết thúc xem, hủy form trước gọi nghiệp vụ không thêm phiếu/giữ chỗ. B có thể mượn X sau đó trong phiên tuần tự.

**Giải thích và bảo vệ cách làm:**

A khi thử lại bị trạng thái X chặn; bản hiện tại không lưu lời hẹn từ màn hình xem. MuonSach là nơi kiểm quyền/trạng thái và commit.

Preview chỉ giúp UI, không thay kiểm tại lời gọi chính; nếu mở rộng nhiều phiên càng phải nêu rõ tính nhất quán, không suy có hàng chờ.

**Đáp câu phụ 1:** A đã đủ 3 nên cổng DemSoSachDangMuon chặn trước tra X, dù X cũng đang bận. Preview không bảo lưu quyền hay thứ tự thông báo; phải lấy trạng thái tại lần gọi mới.

**Sai lầm dễ mắc:** Đóng preview tương đương xác nhận giao dịch.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Theo dõi số phiếu tại từng lần mở/đóng/xác nhận; dùng log caller trên bản sao để thấy hủy không gọi MuonSach.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `ManHinhMuonTra`, dòng 206; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `BieuMau`, dòng 334; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114.

<a id="TN48"></a>
### TN48 — Đầu ra báo cáo có được dùng làm đầu vào loader

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN48).

**Trả lời ngắn:** Báo cáo có tiêu đề/format đọc, không có cấu trúc mốc–sách–cuốn–người–lịch sử mà DocNoiBo yêu cầu.

**Giải thích và bảo vệ cách làm:**

Thiếu metadata và dữ liệu không hiển thị; đổi một nhãn không tạo lại lịch sử/kho. Cần LuuFile để tạo snapshot toàn hệ thống, báo cáo chỉ là tài liệu đọc. NAP báo cáo lỗi phải giữ RAM cũ, không coi lỗi là cần xóa dữ liệu rồi thử lại.

**Đáp câu phụ 1:** Vẫn thiếu mốc và danh mục sách/cuốn; nhiều snapshot khác nhau có cùng báo cáo b.

**Sai lầm dễ mắc:** Text nhìn đủ thông tin trên màn hình là file phục hồi đầy đủ.

**Cách kiểm chứng:** Đề xuất lưu báo cáo riêng ở đường thử rồi DocFile trên RAM có dấu nhận diện; kiểm giữ RAM khi lỗi.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InDocGiaTheoMa`, dòng 111; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `Ghi`, dòng 273; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `DocNoiBo`, dòng 222.

<a id="TN49"></a>
### TN49 — Một phím mang nhiều ý nghĩa: lỗi nếu xử lý toàn cục

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN49).

**Trả lời ngắn:** 0 trong field là dữ liệu của mã 10; 0 ở menu con quay lại, còn menu chính 0 thử lưu và thoát. Esc form hủy đầu vào, không đồng nghĩa bỏ toàn phiên.

**Giải thích và bảo vệ cách làm:**

Lớp đọc trả sự kiện; màn hình/ngữ cảnh quyết định điều hướng. Bắt toàn cục làm mất khả năng nhập và có thể lưu/thoát ngoài ý định.

Dữ liệu form cục bộ chưa commit trước xác nhận; giao dịch đã thành công trước đó vẫn ở RAM. Phải truy ranh giới gọi nghiệp vụ cho từng ngữ cảnh.

**Đáp câu phụ 1:** Không; caller nhận lựa chọn quay lại trong ngữ cảnh submenu. Menu chính mới diễn giải 0 thành thử lưu–thoát.

**Sai lầm dễ mắc:** Lớp đọc phím nên gán ý nghĩa nghiệp vụ chung cho mọi màn hình.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Thiết kế chuỗi phím cho từng màn hình trên dữ liệu thử, kiểm không gọi LuuFile / Thoat khi chỉ sửa mã trong ô.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `DocPhimConsole`, dòng 124; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `BieuMau`, dòng 334; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChonMenu`, dòng 419; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507.

<a id="TN53"></a>
### TN53 — Xóa nội dung trên form rồi hủy có xóa hồ sơ thật không?

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN53).

**Trả lời ngắn:** Ctrl+A hiện xóa field cục bộ, không chọn văn bản như editor đầy đủ. Esc bỏ form nên caller chưa gọi hiệu chỉnh; hồ sơ/lịch sử giữ nguyên.

**Giải thích và bảo vệ cách làm:**

fields là bản nhập tạm, values chỉ được trả khi xác nhận; hiệu chỉnh còn có validator / commit riêng.

Bind trực tiếp sẽ sửa dữ liệu trước quyết định và cần rollback /transaction đúng cả nhiều trường/ngoại lệ; không chỉ thêm nút Hủy là đủ.

**Đáp câu phụ 1:** Không; API còn kiểm trước swap. Form xác nhận chỉ chuyển dữ liệu tạm cho bước nghiệp vụ.

**Sai lầm dễ mắc:** Xác nhận form đồng nghĩa mọi field đã ghi vào node.

**Cách kiểm chứng:** Đề xuất kiểm chứng: So họ/tên/thẻ và địa chỉ lịch sử trước/sau hủy; trên bản sao mới thử thiết kế bind và chỉ ra đường phải hoàn tác.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `BieuMau`, dòng 334; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `ManHinhDocGia`, dòng 138; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `HieuChinhDocGia`, dòng 73.

<a id="TN54"></a>
### TN54 — Ba mốc 'xác nhận', 'đã thêm', 'đã lưu' có cùng nghĩa không?

**Tấn · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN54).

**Trả lời ngắn:** Form true chỉ là người dùng xác nhận trường nhập; số trang abc vẫn bị parse chặn, chưa thêm đầu.

**Giải thích và bảo vệ cách làm:**

Sau sửa 100 và ThemDauSach thành công, đầu có trong RAM; chưa chắc nằm trên đĩa. Đóng tiến trình trước lưu có thể mất thay đổi đó.

Thông báo nên phân biệt nhận biểu mẫu, cập nhật RAM và LuuFile thành công. Không lấy một bool ở tầng nhập làm bằng chứng tất cả tầng đã hoàn tất.

**Đáp câu phụ 1:** Không; đã thêm RAM nhưng chưa lưu đĩa. Thông báo gộp có thể dẫn người dùng thêm lặp.

**Sai lầm dễ mắc:** Thành công/thất bại của cả luồng chỉ cần một nhãn không phân mốc.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Truy lời gọi từ BieuMau đến ThemDauSach đến LuuFile; so số đầu RAM và file tại từng mốc trên bản dữ liệu thử.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `BieuMau`, dòng 334; [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `ManHinhNhapDauSach`, dòng 128; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `LuuFile`, dòng 353.

<a id="TN56"></a>
### TN56 — Chạy kịch bản nhập liệu bị hết stdin giữa hồ sơ

**Tấn · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN56).

**Trả lời ngắn:** Chuỗi nhập dừng trước ThemDocGia cho B, nên không tạo B hay tiêu thụ mã. A đã commit vẫn chỉ ở RAM nếu chưa lưu.

**Giải thích và bảo vệ cách làm:**

Vòng chính gặp cin lỗi sẽ thoát không tự lưu, trả 0 trong đường hiện tại; exit code 0 không tự chứng minh mọi lệnh dự kiến đã được xử lý/lưu.

Script kiểm thử cần quan sát thông báo lưu và đọc/kiểm file đích, đối chiếu dữ liệu mong đợi; không chỉ nhìn process exitcode.

**Đáp câu phụ 1:** Không; EOF chỉ không tự ghi thêm. Snapshot đã lưu vẫn tồn tại.

**Sai lầm dễ mắc:** Thoát không tự lưu nghĩa mất cả những dữ liệu đã lưu trước đó.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Tạo input cố ý cắt giữa B trên file tạm, so file trước sau; thêm một kịch bản đầy đủ có lưu để đối chiếu.

**Ca liên quan đã chạy 17/10 (không tái chạy đợt này):** [eof_unsaved](ThamKhao/KIEM_CHUNG_RUNTIME.md#eof_unsaved).

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `ManHinhDocGia`, dòng 138; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `NhapDong`, dòng 403; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507.

<a id="TN57"></a>
### TN57 — Tên vừa ô nhập nhưng vượt giới hạn lưu theo byte

**Tấn · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN57).

**Trả lời ngắn:** Form đếm đơn vị UTF-16, validator đếm byte UTF-8; số ký tự, byte và ô terminal khác nhau. Hiển thị vừa ô không chứng minh dữ liệu vừa 512 byte.

**Giải thích và bảo vệ cách làm:**

Cắt chỉ bản vẽ không làm chuỗi gốc ngắn; cắt dữ liệu tùy ý có thể đổi tên hoặc tạo UTF-8 sai. Cần báo đúng giới hạn trước commit và cho người dùng sửa.

Đếm byte chuỗi sau chuyển mã đúng; nếu muốn hiển thị bộ đếm thêm thì đặt rõ đơn vị, không hứa số ký tự tiếng Việt cố định.

**Đáp câu phụ 1:** Không. Dùng hai tên cùng tiền tố dài nhưng hậu tố khác: màn hình hẹp có thể rút gọn, song chi tiết và dữ liệu lưu phải giữ đúng chuỗi đã được nhận. Đầu vào vượt 512 byte phải báo từ chối theo hợp đồng hiện tại, không tự bỏ hậu tố.

**Sai lầm dễ mắc:** Đếm chiều rộng terminal là kiểm đúng giới hạn lưu trữ.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Dùng chuỗi ASCII và chuỗi Việt cùng số ký tự nhưng khác byte, kiểm vẫn giữ hồ sơ cũ khi từ chối.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `BieuMau`, dòng 334; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `TuUTF16`, dòng 41; [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `HopLeVanBan`, dòng 42.

<a id="TN64"></a>
### TN64 — Thêm nút trả trên bảng h: dòng được chọn phải mang dữ liệu gì?

**Tấn · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN64).

**Trả lời ngắn:** selected hiện là chỉ số dòng text, có thể chỉ tiêu đề/thông báo; renderer không giữ một CuonSach hay phiếu giao dịch. Cắt chuỗi/format không là nguồn danh tính.

**Giải thích và bảo vệ cách làm:**

Cần ánh xạ dòng dữ liệu→mã thẻ, mã cuốn riêng và vô hiệu hành động trên hàng trang trí. Xác nhận rõ rồi gọi TraSach để kiểm nghiệp vụ lại.

Đây là mở rộng UI, chưa có trong bản hiện tại; sau trả thành công tạo lại view, tái đặt lựa chọn hợp lệ.

**Đáp câu phụ 1:** Không; tập lượt mở thay đổi. Cần đặt lại hoặc tìm lại theo định danh còn tồn tại, không dựa chỉ số cũ.

**Sai lầm dễ mắc:** Số hàng là một khóa nghiệp vụ bền qua cập nhật.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Thiết kế test chọn tiêu đề, hai cuốn cùng tên, dòng cuối bị xóa khỏi view sau trả; không thay nguồn code chính khi ôn.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `HienThiPhanTrang`, dòng 450; [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `LietKeSachDangMuon`, dòng 21; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `TraSach`, dòng 139.

<a id="TN67"></a>
### TN67 — Đổi kích thước ở trang cuối: giữ bản ghi hay giữ số trang?

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN67).

**Trả lời ngắn:** rows =h−11 nên step đổi 13→21; page = selected / step, selected 24 vẫn chỉ dòng cũ và PgDn được chặn về n−1=24.

**Giải thích và bảo vệ cách làm:**

Bản hiện text không đổi trong vòng xem, nên resize không làm selected vượt n. Nếu thêm lọc giảm n phải chặn/reset selected và xây lại starts.

Giữ số trang cứng có thể nhảy đến nhóm dòng khác khi step đổi; cần chốt UX giữ bản ghi đang xem hay trang.

**Đáp câu phụ 1:** Có trong mô hình bản ghi mới; không sao chép máy móc giả thiết text hiện tại luôn có ít nhất một dòng.

**Sai lầm dễ mắc:** Một guard đúng cho text tự đúng cho mọi mô hình dữ liệu mới.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Truy selected / page / step tại ba mốc; test 0 kết quả theo đặc tả mới riêng vì renderer hiện nhận dòng text.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `HienThiPhanTrang`, dòng 450.

<a id="TN73"></a>
### TN73 — Xác nhận NAP bị hủy: đường dẫn mới có được giữ làm đích lưu?

**Tấn · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN73).

**Trả lời ngắn:** Sai từ khóa hoặc hủy chưa gọi DocFile, RAM/path vẫn của A; F5 lưu vào A. next chỉ là đường dẫn ứng viên, không được đổi đích lưu trước khi chấp nhận phiên mới.

**Giải thích và bảo vệ cách làm:**

NAP đúng và DocFile thành công thay RAM bằng B rồi đặt path=B. Không có bước tự lưu các thay đổi A trước đó, nên phải lưu A nếu muốn giữ; file A trên đĩa không bị viết bởi việc nạp B.

Gán path quá sớm khiến hủy nạp vẫn có thể ghi RAM của A lên B chưa được nạp. Nếu chính DocFile thất bại trước swap, phiên A vẫn giữ nguyên.

Phân biệt thành công nạp với toàn thao tác UI: trường hợp hiếm gán path ném ngoại lệ sau khi RAM đã swap được xét tại TN82; không hứa mọi lỗi đều rollback cả hai.

**Đáp câu phụ 1:** DocFile lỗi trước swap giữ RAM/path A, nên F5 lưu cả giao dịch chưa ghi của A vào A; B không bị ghi. So nội dung/hash hai file và dữ liệu A vừa thêm, không chỉ kiểm một chữ lỗi.

**Sai lầm dễ mắc:** Nhập đường dẫn mới là đã chuyển đích lưu.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Trên hai cặp file tạm, kiểm từng nhánh bằng nội dung/hash A và B; báo cáo chạy v2 chỉ kiểm nhánh sai từ khóa, không tự xác nhận nhánh mới.

**Ca liên quan đã chạy 17/10 (không tái chạy đợt này):** [load_success_switches_destination](ThamKhao/KIEM_CHUNG_RUNTIME.md#load_success_switches_destination).

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `DocFile`, dòng 349; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `LuuFile`, dòng 353.

<a id="TN75"></a>
### TN75 — Gõ sai đường dẫn lúc mở ứng dụng và lúc NAP khác nhau

**Tấn · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN75).

**Trả lời ngắn:** Khởi động đường dẫn chưa có cho RAM rỗng và tạo thư mục cha; file mới chỉ được ghi khi lưu. File cũ ở đường dẫn khác vẫn còn.

**Giải thích và bảo vệ cách làm:**

NAP gọi DocFile phải mở được file, thất bại giữ phiên hiện tại. Tự rỗng hóa lúc NAP sẽ làm mất thay đổi chưa lưu.

Cần xem đường dẫn tuyệt đối, thư mục làm việc và thông báo khởi động, không vội kết luận loader xóa dữ liệu.

Nếu file --data tồn tại nhưng DocFile thất bại, ChayUngDung báo lỗi và trả mã 2 trước menu, không cho ghi đè bằng dữ liệu rỗng. Cần phân biệt đường dẫn mới, file không mở được và file đang có nhưng không hợp lệ.

**Đáp câu phụ 1:** Chưa; xác minh đích tuyệt đối/cwd trước, tránh tạo thêm kho thứ hai và nhầm nguồn.

**Sai lầm dễ mắc:** Thấy kho rỗng là bằng chứng loader đã xóa file cũ.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Dùng hai đường dẫn tạm kiểm tồn tại trước sau, đối chiếu RAM /file khi chưa lưu và sau F5.

**Ca liên quan đã chạy 17/10 (không tái chạy đợt này):** [startup_invalid_no_overwrite](ThamKhao/KIEM_CHUNG_RUNTIME.md#startup_invalid_no_overwrite).

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `DocFile`, dòng 349.

<a id="TN79"></a>
### TN79 — Cùng exe, mỗi thành viên thấy một thư viện khác

**Tấn · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN79).

**Trả lời ngắn:** Mặc định DuLieu/runtime/ThuVien.txt được tính từ thư mục làm việc, nên cùng exe có thể trỏ hai đích. Nếu đích chưa có tạo phiên rỗng, kho khác vẫn còn.

**Giải thích và bảo vệ cách làm:**

Launcher chốt thư mục làm việc hoặc truyền --data tuyệt đối giúp tái lập; hiện đường dẫn đang dùng để người vận hành xác minh.

Không ghi lại/xóa file để'chữa' trước khi tìm đúng đích. Sau bàn giao cần kiểm cùng phiên bản code và cùng input nếu so kết quả.

Khoảng trắng không được quote có thể tách thành nhiều đối số; bản này gặp đối số dư không nhận biết thì in hướng dẫn và trả 2 trước khi nạp. CommandLineToArgvW xử lý mã hóa và quy tắc tách đối số, không tự đoán ghép lại đường dẫn người dùng muốn.

**Đáp câu phụ 1:** Không; đích phụ thuộc cwd, không nhất thiết thư mục chứa exe. Launcher phải chốt một cách rõ ràng.

**Sai lầm dễ mắc:** Đường dẫn tương đối luôn tính từ chỗ đặt exe.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Chạy bằng hai thư mục làm việc tại vùng thử riêng, so đường dẫn và file tạo ra; không đụng dữ liệu nhóm.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `LuuNoiBo`, dòng 290.

<a id="TN84"></a>
### TN84 — Ghi log console làm đổi đường UI nhưng không được đổi nghiệp vụ

**Tấn · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN84).

**Trả lời ngắn:** giaoDienPhim chỉ bật khi không --plain và stdin / stdout đều là TTY; redirect chọn nhánh dòng. Đây là fallback hiện tại.

**Giải thích và bảo vệ cách làm:**

Các API giao dịch/ validator chung phải giữ quy tắc ở mọi caller. Chặn 3 chỉ ở form có thể bị bỏ qua bằng --plain/ API.

CLI test chứng minh luồng dòng và phần nghiệp vụ nó thực đi qua, không chứng minh chuột, IME, resize hoặc event Win32.

**Đáp câu phụ 1:** Không; API chung đúng chưa bảo đảm mapping sự kiện, focus và xác nhận TUI đúng. Hai lớp cần bằng chứng riêng.

**Sai lầm dễ mắc:** Dùng chung nghiệp vụ đồng nghĩa mọi giao diện đã được kiểm.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Chạy ca đã giữ 3 xin thêm qua API và --plain, kiểm thêm UI riêng nếu có; so trạng thái chứ không chỉ layout.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `NhapBieuMau`, dòng 397.

<a id="TN88"></a>
### TN88 — Parse sai nhưng thao tác nhầm độc giả của lần trước

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN88).

**Trả lời ngắn:** Output giữ nguyên khi lỗi nên ma có thể vẫn 12; nếu 12 tồn tại và không lịch sử, API xóa đúng theo tham số nó nhận nhưng sai ý định UI.

**Giải thích và bảo vệ cách làm:**

API không biết văn bản đầu vào đã bị bỏ qua; reset 0 giảm khả năng xóa nhầm nhưng không thay được nhánh không gọi nghiệp vụ khi lỗi/hủy.

Tách biến đầu vào tạm và kết quả parse, nêu đúng người trước xác nhận; kiểm callback thành công thay vì chỉ kiểm ma ở miền.

**Đáp câu phụ 1:** Chưa; chỉ tình cờ bị điều kiện khác chặn. Với mã khác không lịch sử vẫn có thể xóa nhầm.

**Sai lầm dễ mắc:** Một lần không gây thiệt hại chứng minh đường gọi sai an toàn.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Trên bản sao cho 12 không lịch sử, nhập đúng rồi sai, kiểm 0 lời gọi XoaDocGia trong lần sai.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `DocSoNguyen`, dòng 65; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `ManHinhDocGia`, dòng 138; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `XoaDocGia`, dòng 85.

<a id="TN202"></a>
### TN202 — Mảng đã tăng nhưng bị mất một người

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN202).

**Trả lời ngắn:** Kết quả đúng là 30,20,10. Dãy lỗi 30,20,20 vẫn tăng không giảm theo tên–họ–mã nhưng không phải hoán vị đầu vào.

**Giải thích và bảo vệ cách làm:**

Kiểm số lượng, tần suất mỗi mã trước/sau và quan hệ từng mã với họ/tên; sau đó kiểm comparator trên mọi cặp kề. Một phép gán thiếu biến tạm có thể nhân đôi con trỏ mà không vượt bộ nhớ. Dữ liệu BST không đổi là hậu điều kiện riêng.

**Đáp câu phụ 1:** Cùng 3 phần tử và tổng 60 nhưng mất 20,30, lặp 10 và thêm 40. Cần kiểm đúng đa tập định danh, không chỉ một checksum số học; sau đó vẫn kiểm thứ tự và mapping trường.

**Sai lầm dễ mắc:** Báo cáo được sắp đúng đồng nghĩa chứa đủ dữ liệu.

**Cách kiểm chứng:** Đề xuất: dùng ba tên đảo và hai hồ sơ trùng tên; chèn lỗi gán trên bản sao rồi kiểm permutation lẫn thứ tự.

**Kiểm mới 18/10:** [original_sort_permutation](ThamKhao/KIEM_DINH_20261018.md#original_sort_permutation). Chỉ các assertion/quan sát nêu trong ca.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InDocGiaTheoTenHo`, dòng 119.

<a id="TN203"></a>
### TN203 — Vì sao dựng heap từ nửa sau trở về đầu

**Tấn · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN203).

**Trả lời ngắn:** Vun các root 2,1,0; lá 3..6 đã là heap một phần tử. Dựng từ dưới lên có O(R) phép xử lý nút theo tổng độ cao.

**Giải thích và bảo vệ cách làm:**

Khi vun root 2 rồi 1, các cây con đã là heap; root 0 dựa vào điều đó. Chèn từng phần tử rồi nổi lên có cận O(R log R). Giai đoạn lấy max R lần vẫn O(R log R); giảm phần dựng không làm cả sort tuyến tính. Chi phí so chuỗi còn phụ thuộc L.

**Đáp câu phụ 1:** Con có thể đưa phần tử lớn hơn lên sau lần vun cha; cha không còn bảo đảm lớn nhất theo comparator.

**Sai lầm dễ mắc:** Thấy một vòng for từ n/2 nên kết luận toàn bộ heap sort O(R).

**Cách kiểm chứng:** Truy các cây con trên bảy tên theo thứ tự bất lợi; muốn đo phải đếm so sánh riêng dựng/rút heap.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InDocGiaTheoTenHo`, dòng 119.

<a id="TN204"></a>
### TN204 — Duyệt Morris có thật sự là báo cáo chỉ đọc

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN204).

**Trả lời ngắn:** Các liên kết tạm còn sót có thể tạo chu trình và phá giả định cây; báo cáo không còn thuần chỉ đọc trong lúc chạy.

**Giải thích và bảo vệ cách làm:**

Morris có thể dùng O(1) bộ nhớ phụ nếu hoàn tất và phục hồi mọi nối. Với callback có thể ném lỗi cần cơ chế bảo đảm tháo đủ nối khi rời sớm; việc đó phức tạp hơn stack/view hiện tại. Không đưa trực tiếp vào bản nộp chỉ vì tiết kiệm mảng.

**Đáp câu phụ 1:** Không; const nông không thay nghĩa vụ bảo toàn liên kết. Cần thiết kế kiểu và đường phục hồi đúng.

**Sai lầm dễ mắc:** Thuật toán O(1) bộ nhớ luôn an toàn hơn thuật toán dùng stack.

**Cách kiểm chứng:** Đề xuất trên bản sao: dừng ở nhiều lần thăm; sau mỗi lần kiểm toàn bộ cạnh, tìm mã và hủy không lặp.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `LayDanhSachDocGia`, dòng 18; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InDocGiaTheoMa`, dòng 111.

<a id="TN205"></a>
### TN205 — Bảng mã giảm dần không cần sắp lại

**Tấn · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN205).

**Trả lời ngắn:** Kết quả 30,20,15,10; duyệt ngược hoặc đảo view tăng đều đúng, không cần heap sort.

**Giải thích và bảo vệ cách làm:**

Duyệt ngược O(R), stack hoạt động O(h); đảo view O(R) sau khi dựng view và cần O(R) ô. Heap thêm O(R log R) không khai thác thứ tự BST. Không đổi trái/phải vật lý chỉ để đổi thứ tự trình bày.

**Đáp câu phụ 1:** Duyệt ngược và dừng sau 5 nút đã xuất; chi phí O(h+5) trên cây hợp lệ, h có thể R. Không dừng sau 5 lần push.

**Sai lầm dễ mắc:** Đảo thứ tự báo cáo đồng nghĩa đảo cấu trúc cây.

**Cách kiểm chứng:** Đề xuất: so dãy mã với reverse của inorder, gồm cây lệch và k lớn hơn số người.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `LayDanhSachDocGia`, dòng 18; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InDocGiaTheoMa`, dòng 111.

<a id="TN206"></a>
### TN206 — Lọc một khoảng mã có cần xem cả cây

**Tấn · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN206).

**Trả lời ngắn:** Chỉ xuất 40,50,60; tại 30 bỏ cây con trái, tại 70 bỏ cây con phải.

**Giải thích và bảo vệ cách làm:**

Bất biến BST cho phép cắt nhánh ngoài khoảng. Duyệt có cắt nhánh có cận O(h+k) với k kết quả; cây lệch vẫn có trường hợp O(R). Lọc toàn view O(R) và tốn view. Cận gồm hai đầu phải thống nhất với điều kiện rẽ nhánh.

**Đáp câu phụ 1:** Khóa duy nhất nên chỉ 40 thuộc khoảng, hai cây con bị loại bởi cận chặt của BST. L>U cần từ chối đầu vào hoặc trả tập rỗng được công bố; không tự đổi hai cận vì sẽ đổi ý nghĩa yêu cầu.

**Sai lầm dễ mắc:** Có BST nên mọi truy vấn khoảng đều O(log R) bất kể số dòng kết quả.

**Cách kiểm chứng:** Đề xuất: đối chiếu với quét đầy đủ trên đoạn rỗng, hai biên, toàn miền và cây lệch.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `TimDocGia`, dòng 8, 13; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `LayDanhSachDocGia`, dòng 18.

<a id="TN207"></a>
### TN207 — Nhảy tới người thứ k không phải tìm mã k

**Tấn · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN207).

**Trả lời ngắn:** Người thứ 2 là mã 30; TimDocGia với 2 tìm danh tính 2 nên không giải bài toán thứ hạng.

**Giải thích và bảo vệ cách làm:**

Có thể duyệt inorder đếm tới k với O(h+k), hoặc bổ sung kích thước cây con để chọn theo hạng O(h). Phương án sau cần được phép thêm metadata và cập nhật khi chèn/xóa/dựng lại cây; chỉ thêm trường không đủ. Không tự khẳng định O(log R) với cây lệch.

**Đáp câu phụ 1:** Không; đường tháo successor và đường vị trí xóa đều có thể đổi kích thước cây con, node mới lên gốc cần size mới. Phải cập nhật các tổ tiên bị ảnh hưởng và kiểm từng size bằng số node thực, không chỉ tổng R.

**Sai lầm dễ mắc:** Dùng mã thẻ hoặc high-water mark làm vị trí liên tục trong danh sách.

**Cách kiểm chứng:** Đề xuất: test mã khuyết, xóa đầu, k=0 và k vượt R; so truy vấn hạng với view inorder.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `TimDocGia`, dòng 8, 13; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `LayDanhSachDocGia`, dòng 18; [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — `NutDocGia`, dòng 28.

<a id="TN208"></a>
### TN208 — Chọn mười tên đầu khi R lớn

**Tấn · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN208).

**Trả lời ngắn:** Giữ heap có root là người lớn nhất trong 10 ứng viên đang giữ; chỉ thay khi ứng viên mới đứng trước root.

**Giải thích và bảo vệ cách làm:**

Sau duyệt phải sắp 10 phần tử để xuất tăng. Chi phí O(R log 10+10 log 10), bộ nhớ chọn O(10) cộng stack duyệt; full sort O(R log R) và view O(R). Chỉ lấy 10 node đầu inorder là chọn mã nhỏ, không phải tên nhỏ.

**Đáp câu phụ 1:** Không; mã là khóa cuối nên 10 mã nhỏ nhất thắng. Phải dùng trọn comparator.

**Sai lầm dễ mắc:** Dừng duyệt BST sau đủ 10 người vì báo cáo chỉ cần 10 dòng.

**Cách kiểm chứng:** Đề xuất: đặt 10 tên nhỏ nhất ở mã lớn, so kết quả với full sort; đếm phép so, chưa benchmark.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InDocGiaTheoTenHo`, dòng 119; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `TenHoTruoc`, dòng 44.

<a id="TN209"></a>
### TN209 — Tìm tiền tố trên view tên đã sắp

**Tấn · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN209).

**Trả lời ngắn:** Tiền tố khớp an và an binh nằm trong một đoạn; tìm chứa còn có lan, thanh nên không có bảo đảm một đoạn như vậy.

**Giải thích và bảo vệ cách làm:**

Có thể lower_bound theo khóa tên chuẩn hóa rồi quét đến khi hết tiền tố, giữ mọi họ/mã trong đoạn. Một vị trí đầu không đại diện tất cả tên trùng. Cần nêu quy tắc prefix đúng byte khóa hiện tại, không hứa không dấu hoặc case-fold tiếng Việt.

**Đáp câu phụ 1:** Phải quy định rỗng là từ chối hay tất cả; không lặng lẽ dùng tiền tố rỗng để trả toàn R khi UI đang mong tìm cụ thể.

**Sai lầm dễ mắc:** Mọi tìm kiếm chuỗi trên dữ liệu đã sắp đều nhị phân được.

**Cách kiểm chứng:** Đề xuất: đối chiếu quét prefix trên toàn view, có tên trùng và khóa chuẩn hóa bằng nhau.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `TenHoTruoc`, dòng 44; [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `KhoaSoSanh`, dòng 22; [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `ChuaChuoi`, dòng 31.

<a id="TN210"></a>
### TN210 — Độ sâu duyệt cây và độ sâu sort không cùng cận

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN210).

**Trả lời ngắn:** Merge sort chia mảng theo đôi có độ sâu O(log R), khác DFS cây lệch O(h)=O(R). Heap sort hiện tại dùng vòng lặp và không cần mảng merge R phần tử.

**Giải thích và bảo vệ cách làm:**

Merge cần buffer O(R) con trỏ để trộn và có thể giữ tính ổn định nếu chọn trái khi hòa. Cả hai O(R log R) phép so, chi phí chuỗi vẫn có. Có thể cấp buffer một lần trước sort để tránh cấp phát ở mỗi mức; không sửa BST hoặc thay container bắt buộc.

**Đáp câu phụ 1:** Không; mất cân bằng chia nhỏ làm độ sâu tuyến tính và tổng chi phí có thể bậc hai. Lập luận phải theo phép chia thật.

**Sai lầm dễ mắc:** Mọi đệ quy trên R phần tử đều có độ sâu R hoặc đều có độ sâu logR.

**Cách kiểm chứng:** Đề xuất so output với heap trên dữ liệu đảo/hòa và đếm depth/cấp buffer; chưa cài merge sort.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InDocGiaTheoTenHo`, dòng 119; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `LayDanhSachDocGia`, dòng 18; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `DungBST`, dòng 97.

<a id="TN211"></a>
### TN211 — Sao chép dữ liệu để sắp thay vì sao chép con trỏ

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN211).

**Trả lời ngắn:** Copy DocGia sao chép các string nhưng chỉ copy địa chỉ dsMuonTra; không nhân bản các node lịch sử.

**Giải thích và bảo vệ cách làm:**

Tốn thêm bộ nhớ/cấp phát chuỗi O(RL) so với O(R) con trỏ. Nếu coi mỗi bản tạm sở hữu lịch sử rồi gọi HuyDanhSachMuonTra, sẽ xóa dữ liệu thật hoặc giải phóng lặp. View hiện tại đủ cho đọc/sort khi đời sống nguồn bao trùm báo cáo.

**Đáp câu phụ 1:** Có: DTO chỉ chứa các trường cần in được copy rõ ràng, không mang pointer sở hữu lịch sử; trả giá bộ nhớ để có snapshot độc lập.

**Sai lầm dễ mắc:** Copy một struct có string và con trỏ tạo bản sao sâu toàn bộ đồ thị dữ liệu.

**Cách kiểm chứng:** Đề xuất: kiểm lịch sử còn nguyên sau hủy view và đo cấp phát chuỗi; không thực hiện free dữ liệu thật.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InDocGiaTheoTenHo`, dòng 119; [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — `DocGia`, dòng 24.

<a id="TN212"></a>
### TN212 — Sắp tên bằng so bản ghi đã định dạng

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN212).

**Trả lời ngắn:** Không; chuỗi bắt đầu bằng mã nên đang sắp theo phần trình bày của mã, không theo tên–họ–mã.

**Giải thích và bảo vệ cách làm:**

Padding có thể sửa một sai khác số và chữ nhưng vẫn dùng nhầm khóa ưu tiên. Comparator phải lấy các trường dữ liệu đúng thứ tự; format chỉ thực hiện sau chọn thứ tự. Nếu đổi vị trí cột, kết quả sort không nên đổi theo.

**Đáp câu phụ 1:** Có thể chia theo trạng thái trước rồi mới các cột khác; đó là thay chức năng ngoài ý định.

**Sai lầm dễ mắc:** Chuỗi nhìn giống một hàng đầy đủ có thể thay comparator cấu trúc.

**Cách kiểm chứng:** Đề xuất: đổi bố cục cột nhưng giữ cùng dữ liệu, yêu cầu dãy mã của báo cáo không đổi.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `TenHoTruoc`, dòng 44; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InMotDocGia`, dòng 41.

<a id="TN213"></a>
### TN213 — Bỏ điều kiện count vì tin caller luôn đúng

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN213).

**Trả lời ngắn:** Hàm không phải bộ phát hiện chu trình; cận stack/số lượt bảo vệ giới hạn duyệt nhưng không chứng nhận cấu trúc là BST hợp lệ.

**Giải thích và bảo vệ cách làm:**

Liên kết vòng có thể làm push liên tục tới cận rồi ném lỗi hoặc thăm lặp đến cận tùy hình vòng. Không coi thông báo vượt giới hạn là đã có hơn MAX độc giả thật. Chỉ dùng fixture hỏng trên bản sao, tránh destructor cây thường với vòng chưa tháo.

**Đáp câu phụ 1:** Không; chưa biết cạnh nào đúng theo nguồn. Cần chẩn đoán địa chỉ/cạnh và phục hồi từ nguồn hợp lệ, không đoán xóa node.

**Sai lầm dễ mắc:** Kiểm n<=MAX đồng nghĩa đã kiểm không chu trình và không chia sẻ node.

**Cách kiểm chứng:** Chỉ phân tích; fault fixture cần teardown riêng tháo vòng trước hủy, chưa chạy.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `LayDanhSachDocGia`, dòng 18; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `DemDocGia`, dòng 33.

<a id="TN214"></a>
### TN214 — Chèn đầu sách đã tăng có làm view thể loại luôn rẻ

**Tấn · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN214).

**Trả lời ngắn:** Insertion sort phụ thuộc độ đảo theo khóa thể loại–tên–ISBN, không chỉ việc tên gốc đã tăng.

**Giải thích và bảo vệ cách làm:**

Kho A gần đúng thứ tự báo cáo nên ít dịch, gần O(D) so; kho B có thể O(D²) dịch. Mỗi dịch là con trỏ, nhưng mỗi so có chuẩn hóa chuỗi. Cùng D chưa đủ mô tả tải; cần phân bố thể loại, độ dài khóa và hòa tên.

**Đáp câu phụ 1:** View đã đúng thứ tự phụ tên–ISBN, nên không phải worst case chỉ vì một nhóm rất lớn.

**Sai lầm dễ mắc:** Dữ liệu đã sắp theo bất kỳ khóa nào đều là best case cho insertion sort.

**Cách kiểm chứng:** Đề xuất đếm so/dịch trên hai kho cùng D, không suy mili giây từ phân tích.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `InDauSachTheoTheLoai`, dòng 98.

<a id="TN215"></a>
### TN215 — Bảo toàn thứ tự đầu vào khi bỏ khóa mã khỏi yêu cầu

**Tấn · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN215).

**Trả lời ngắn:** Không; mã vẫn phá hòa trước khi tính ổn định có tác dụng, nên thứ tự chọn bị thay bằng mã.

**Giải thích và bảo vệ cách làm:**

Phải chốt tập đầu vào và ordinal lựa chọn, rồi dùng khóa tên–họ–ordinal hoặc comparator chỉ tên–họ cùng sort ổn định trên thứ tự đã chọn. Bản hiện không có danh sách chọn; inorder đầu vào cũng là mã tăng nên không đại diện thứ tự chọn của người.

**Đáp câu phụ 1:** Không; phải quy định danh sách chọn cho phép lặp hay là tập, xử lý danh tính trước sort.

**Sai lầm dễ mắc:** Chỉ đổi thuật toán thành stable là đạt mọi quy tắc giữ thứ tự ưu tiên bên ngoài.

**Cách kiểm chứng:** Đề xuất cùng tên/họ với thứ tự chọn 30,10,20; expected giữ 30,10,20 theo đặc tả mới.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InDocGiaTheoTenHo`, dòng 119; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `TenHoTruoc`, dòng 44.

<a id="TN216"></a>
### TN216 — Chỉ xem một thể loại mà vẫn sắp toàn kho

**Tấn · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN216).

**Trả lời ngắn:** Có thể quét kho gốc, lọc thể loại bằng SoSanhChuoi==0 và xuất theo thứ tự gặp; các đầu được chọn đã tăng tên–ISBN.

**Giải thích và bảo vệ cách làm:**

Chi phí O(D) phép kiểm khóa cộng chi phí chuỗi/đầu ra, không cần O(D²) sort thể loại. Đây chỉ áp khi chọn một nhóm và yêu cầu trong nhóm đúng thứ tự gốc. Không dùng so byte để lọc khác quan hệ d.

**Đáp câu phụ 1:** Không; tên có thể xen hai loại. Có thể quét riêng theo từng loại đã xếp đúng hoặc sắp view lọc, nêu chi phí theo số nhóm.

**Sai lầm dễ mắc:** Mọi bộ lọc của báo cáo d đều phải chạy lại toàn thuật toán nhóm.

**Cách kiểm chứng:** Đề xuất: đối chiếu danh sách ISBN với nhóm tương ứng của d, dùng biến thể hoa/thường ASCII.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `InDauSachTheoTheLoai`, dòng 98; [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `SoSanhChuoi`, dòng 27.

<a id="TN217"></a>
### TN217 — Gộp hai danh sách thể loại đã sắp

**Tấn · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN217).

**Trả lời ngắn:** Trộn hai dãy theo trọn comparator có O(D) phép so và giữ đủ mọi ISBN; tên trùng không phải bản trùng.

**Giải thích và bảo vệ cách làm:**

Hai view phải thuộc cùng snapshot nguồn và có tập ISBN rời nhau theo giả thiết. Nối rồi insertion sort có thể O(D²). Nếu đầu vào thực ra có ISBN giao nhau, cần báo vi phạm tiền điều kiện hoặc quy định loại trùng theo danh tính, không lặng gộp tên.

**Đáp câu phụ 1:** Không; cả hai dãy phải tăng theo chính comparator dùng khi trộn.

**Sai lầm dễ mắc:** Bất kỳ hai danh sách đã sắp nào cũng trộn đúng bằng một comparator tùy chọn.

**Cách kiểm chứng:** Đề xuất: so merge với full sort chuẩn trên phân hoạch xen kẽ, trùng tên và phần rỗng.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `InDauSachTheoTheLoai`, dòng 98; [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `TimDauSachTheoISBN`, dòng 54.

<a id="TN218"></a>
### TN218 — Tên nhóm đầu trang không phải nhóm mới

**Tấn · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN218).

**Trả lời ngắn:** Nhãn lặp là ngữ cảnh trình bày, không mở nhóm nghiệp vụ mới và không tăng tổng.

**Giải thích và bảo vệ cách làm:**

Hiện d sinh text trước, phân trang không hiểu nhóm. Thiết kế mới cần dòng dữ liệu có group key cùng metadata tiêu đề; bộ phân trang có thể thêm nhãn nhưng bộ tính tổng chỉ nhận bản ghi gốc. Resize có thể đổi số nhãn lặp mà tổng vẫn giữ.

**Đáp câu phụ 1:** Không; phân biệt tiêu đề gốc và nhãn tiếp nối để chỉ hiển thị một lần, không đổi group key.

**Sai lầm dễ mắc:** Mỗi lần thấy dòng tên thể loại trên màn hình đều là một nhóm dữ liệu mới.

**Cách kiểm chứng:** Đề xuất: một nhóm dài qua 3 trang, nhóm kế bắt đầu đúng biên, thay chiều cao và so tổng.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `InDauSachTheoTheLoai`, dòng 98; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `HienThiPhanTrang`, dòng 450.

<a id="TN219"></a>
### TN219 — Liệt kê h khi độc giả còn nhưng không giữ sách

**Tấn · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN219).

**Trả lời ngắn:** Không tồn tại độc giả khác độc giả tồn tại nhưng không có lượt mở; không nên suy trạng thái định danh từ một đoạn text.

**Giải thích và bảo vệ cách làm:**

LietKeSachDangMuon kiểm người trước rồi mới quét lịch sử và thông báo không giữ sách. Caller hiện dùng để hiển thị; nếu muốn máy xử lý nên trả trạng thái cấu trúc cùng dữ liệu, renderer chuyển thành chữ. Không tự tạo hồ sơ khi không tìm thấy.

**Đáp câu phụ 1:** Ở tích hợp dùng thông điệp làm API; kiểm trạng thái có kiểu ổn định thay vì so câu tiếng Việt/không dấu.

**Sai lầm dễ mắc:** Báo cáo không có dòng sách chứng minh mã người dùng nhập là hợp lệ.

**Cách kiểm chứng:** Truy nhánh nguồn; đề xuất test hai trường hợp và đổi text giả lập, chưa có API cấu trúc mới.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `LietKeSachDangMuon`, dòng 21; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `TimDocGia`, dòng 8, 13.

<a id="TN220"></a>
### TN220 — Có đủ ba mã nhưng chọn đúng lượt bằng cặp nào

**Tấn · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN220).

**Trả lời ngắn:** Cặp đó không định danh mọi lượt lịch sử; nhưng với nguồn hợp lệ, đúng người/cuốn chỉ có tối đa một lượt mở để API trả tìm.

**Giải thích và bảo vệ cách làm:**

Nếu thêm thao tác trên lượt đóng, cần danh tính lượt hoặc ordinal snapshot kèm version và kiểm lại; ngày cũng có thể trùng nên không tự là ID. Không biến mã cuốn thành ID giao dịch. Chỉ xem chi tiết trong snapshot có thể dùng vị trí nội bộ, nhưng phải vô hiệu khi nguồn đổi.

**Đáp câu phụ 1:** Không; hai node hợp lệ có thể cùng mọi trường đó. Cần hợp đồng định danh rõ, không loại một node như trùng rác.

**Sai lầm dễ mắc:** Mã cuốn duy nhất suy ra mỗi lượt giao dịch của cuốn cũng duy nhất.

**Cách kiểm chứng:** Đề xuất fixture hai lượt giống trường, chọn từng dòng và kiểm định danh snapshot; chưa thêm sửa lượt.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — `MuonTra`, dòng 20; [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `LietKeSachDangMuon`, dòng 21; [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `TimMuonDangMuonTheoMa`, dòng 14.

<a id="TN221"></a>
### TN221 — Khi h gặp lỗi ở lượt mở thứ hai

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN221).

**Trả lời ngắn:** ChuoiNgay định dạng trường số; nó không gọi NgayHopLe để xác minh ngày 32/01. Báo cáo có thể in dữ liệu ngày sai.

**Giải thích và bảo vệ cách làm:**

Hàm hiển thị dựa vào dữ liệu đã được nghiệp vụ/loader bảo đảm, không là validator toàn bộ. Phân biệt bộ định dạng với phép SoThuTu có kiểm hợp lệ và ném lỗi. Cần chạy KiemTraToanVen cho fixture trước khi coi báo cáo là đáng tin.

**Đáp câu phụ 1:** Phép tính gọi SoThuTu có thể ném; phải xử lý việc dựng báo cáo thất bại và không hiển thị phần dở như đầy đủ.

**Sai lầm dễ mắc:** Ngày xuất được thành chuỗi đẹp tức là lịch hợp lệ.

**Cách kiểm chứng:** Truy hai helper theo code; đề xuất fixture 32/01 qua API hiển thị và bộ kiểm riêng, không nạp vào phiên thật.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `LietKeSachDangMuon`, dòng 21; [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `ChuoiNgay`, dòng 106; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507.

<a id="TN222"></a>
### TN222 — Một người có ba cuốn mới nhưng danh mục rất lớn

**Tấn · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN222).

**Trả lời ngắn:** Tìm độc giả O(h), duyệt H_A lịch sử; chỉ các lượt mở mới tra cuốn, mỗi mã mới tốn tìm ISBN O(D) rồi danh sách chủ O(C_i).

**Giải thích và bảo vệ cách làm:**

Tổng O(h+H_A+3D+sum C_i) bỏ qua chuỗi, với 3 là cận lượt mở hợp lệ. Lượt đóng không chạy phép nối. Mã legacy có đường quét toàn kho khác. Các giới hạn C,H hiện tại vẫn áp; đây là phân tích trong giới hạn, không benchmark.

**Đáp câu phụ 1:** Không; hàm vẫn duyệt đến null, không dừng sau 3. Có thể bàn dừng sớm chỉ khi tin invariant và không cần phát hiện dữ liệu hỏng.

**Sai lầm dễ mắc:** Nhân toàn H_A với chi phí tìm cuốn dù code chỉ tra trong nhánh đang mượn.

**Cách kiểm chứng:** Truy điều kiện trước lời gọi tra; đề xuất đếm số lần TimCuonSachToanCuc đúng 3.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `LietKeSachDangMuon`, dòng 21; [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `TimCuonSachToanCuc`, dòng 30, 51.

<a id="TN223"></a>
### TN223 — Duyệt theo tầng có bảo đảm mã tăng không

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN223).

**Trả lời ngắn:** Duyệt tầng cho 40,20,60,10,30,50,70, không tăng theo mã. Inorder mới khai thác bất biến BST để cho 10..70 tăng.

**Giải thích và bảo vệ cách làm:**

Hàng đợi cần theo bề rộng tối đa, có thể O(R) ở cây cân bằng; stack hoạt động theo h. Chia trang theo tầng là đặc tả xem cấu trúc cây khác báo cáo danh sách mã. Nếu sort lại BFS thì thêm chi phí không cần cho b; không thay cấu trúc sản phẩm chỉ để tạo queue.

**Đáp câu phụ 1:** Có, nhưng một cây đặc biệt không chứng minh đúng cho mọi BST. Bộ test phải có hai nhánh và nhiều tầng.

**Sai lầm dễ mắc:** Mọi duyệt BST đều cho mã tăng hoặc chia trang nên dùng duyệt tầng.

**Cách kiểm chứng:** Truy dãy trên cây 7 node, so với inorder và cây lệch; chỉ thay thuật toán trên bản sao nếu luyện.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `LayDanhSachDocGia`, dòng 18; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InDocGiaTheoMa`, dòng 111.

<a id="TN224"></a>
### TN224 — Màn hình báo cáo dùng tổng giữ sách để chia nhóm độc giả

**Tấn · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN224).

**Trả lời ngắn:** Duyệt inorder theo mã, tính số mở từng người rồi append vào bucket tương ứng sẽ giữ mã tăng trong mỗi bucket.

**Giải thích và bảo vệ cách làm:**

Đếm phải quét lịch sử nên tổng O(R+H), không O(R) chỉ vì bốn nhãn. Bucket là view tạm mượn node, không bốn cây sở hữu mới; bộ nhớ tổng O(R) ô nếu giữ mọi dòng. Trường hợp count>3 là dữ liệu sai phải báo, không index ngoài 4 hoặc clamp về 3.

**Đáp câu phụ 1:** Không; phải sort từng bucket hoặc đổi nguồn duyệt đúng thứ tự.

**Sai lầm dễ mắc:** Miền khóa 0..3 nhỏ nghĩa mọi chi phí của báo cáo đều hằng số.

**Cách kiểm chứng:** Đề xuất người 0/1/2/3, lịch sử đóng dài và fixture 4 mở; kiểm mỗi người đúng một nhóm.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `DemSoSachDangMuon`, dòng 5; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `LayDanhSachDocGia`, dòng 18.

<a id="TN225"></a>
### TN225 — Bản ghi đã trả không được tái xuất chỉ vì tên khớp

**Tấn · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN225).

**Trả lời ngắn:** Kết quả chỉ gồm Y: yêu cầu là đang mượn AND tên khớp, không phải hai nhóm độc lập.

**Giải thích và bảo vệ cách làm:**

Lọc trạng thái trước để không nối tên cho lượt đóng. Cùng một cuốn có lịch sử cũ đóng và mới mở càng dễ lộ lỗi OR. Mã/phiếu phải giữ riêng sau lọc; không gộp theo tên.

**Đáp câu phụ 1:** Không; bỏ điều kiện đang mượn khỏi hợp đồng rồi chỉ lọc tên, hiển thị trạng thái/ngày phù hợp. OR vẫn trả mọi lượt mở kể cả tên không khớp.

**Sai lầm dễ mắc:** Ghép thêm điều kiện tìm bằng OR sẽ chỉ làm tìm kiếm linh hoạt hơn mà không đổi nghĩa bảng.

**Cách kiểm chứng:** Đề xuất: bốn tổ hợp mở/đóng × khớp/không khớp và một mã xuất hiện hai lượt.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `LietKeSachDangMuon`, dòng 21; [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `ChuaChuoi`, dòng 31.

<a id="TN226"></a>
### TN226 — Báo cáo quá hạn và h cùng phiên nhưng ngày khác

**Tấn · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN226).

**Trả lời ngắn:** h liệt kê lượt mở và ngày mượn, không tính số ngày quá hạn; i dùng ngày phiên 10/09 nên quá hạn 2 ngày.

**Giải thích và bảo vệ cách làm:**

ChayUngDung truyền ngày phiên cho i; h không nhận ngày đối chiếu. Không thêm diễn giải của renderer từ HomNay rồi đặt cạnh số của i mà không gắn nhãn, sẽ tạo hai mốc trên cùng màn hình. QuaHan dùng >7 ngày, không >=7.

**Đáp câu phụ 1:** Truyền cùng ngày đối chiếu rõ ràng từ điều phối, không đọc đồng hồ riêng trong mỗi dòng.

**Sai lầm dễ mắc:** Mọi báo cáo trong chương trình tự dùng ngày thực của máy ở lúc vẽ.

**Cách kiểm chứng:** Truy signature và tham số caller; biên 7/8 có test CLI riêng, cột mới chưa cài.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `LietKeSachDangMuon`, dòng 21; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `InDocGiaQuaHan`, dòng 148; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507.

<a id="TN227"></a>
### TN227 — Nhập dữ liệu batch qua stdin có transaction toàn file không

**Tấn · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN227).

**Trả lời ngắn:** Không có transaction cho toàn stdin. NhapSo báo lỗi abc và đọc lại;12 sau đó có thể trở thành lựa chọn lưu ở chính lần đọc menu đang chờ.

**Giải thích và bảo vệ cách làm:**

Các lệnh trước đã commit RAM độc lập. Kịch bản cần đồng bộ ngữ pháp prompt/lệnh, kiểm thông báo lưu và dữ liệu đích, không cho rằng một dòng input luôn là một giao dịch cố định bất kể retry. Đây là CLI tương tác, không phải định dạng import có schema.

**Đáp câu phụ 1:** Không; cần chế độ batch/hợp đồng lỗi riêng, giữ parser từ chối đúng. Đổi abc thành 0 có thể kích hoạt lưu–thoát ngoài ý định.

**Sai lầm dễ mắc:** Tệp stdin là một gói giao dịch nguyên tử hoặc mọi dòng luôn khớp prompt dự tính.

**Cách kiểm chứng:** Đề xuất fixture script retry có đích tạm, kiểm thứ tự lệnh thực nhận và trạng thái file; chưa chạy chuỗi này.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `NhapSo`, dòng 412; [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `ManHinhNhapDauSach`, dòng 128.

<a id="TN228"></a>
### TN228 — Thông báo thất bại nhưng stream không ném

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN228).

**Trả lời ngắn:** Không; nhánh plain ghi rồi flush nhưng không kiểm trạng thái cout, cũng không có rollback nghiệp vụ.

**Giải thích và bảo vệ cách làm:**

iostream mặc định có thể giữ cờ lỗi mà không throw. Catch chỉ xử lý exception thật; thông báo không đến người dùng không chứng minh RAM chưa đổi. Cần quyết định lỗi output có làm dừng phiên, đánh dấu trạng thái chưa rõ hay cho kiểm lại, tách khỏi commit.

**Đáp câu phụ 1:** Không; lỗi vẫn có thể xảy ra sau commit, chỉ đổi cách báo lỗi. Cần kiểm trạng thái nghiệp vụ trước retry.

**Sai lầm dễ mắc:** Mọi lỗi ghi stream đều đi qua catch(std::exception).

**Cách kiểm chứng:** Chỉ truy code; muốn thử cần streambuf lỗi/redirect có kiểm soát, chưa chạy fault injection.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ThongBao`, dòng 444; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507.

<a id="TN229"></a>
### TN229 — Một báo cáo lỗi không được nối vào báo cáo lần trước

**Tấn · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN229).

**Trả lời ngắn:** clear() chỉ xóa cờ trạng thái; không xóa chuỗi bên trong. Tái dùng sai sẽ nối báo cáo mới vào báo cáo cũ.

**Giải thích và bảo vệ cách làm:**

Stream mới giới hạn dữ liệu và lỗi vào một thao tác. Nếu chủ động tái dùng cần reset cả buffer, trạng thái và vị trí theo hợp đồng, không để thông tin người cũ lẫn vào h mới. Đây là lỗi trình bày có thể gây đối đáp sai về ai đang giữ sách.

**Đáp câu phụ 1:** Không; nội dung và cờ lỗi là hai trạng thái riêng cần quản lý.

**Sai lầm dễ mắc:** clear() của stream tương đương clear() của string.

**Cách kiểm chứng:** Đề xuất: ba báo cáo có dấu nhận diện riêng, kiểm báo cáo 2 không chứa dữ liệu 1; không cần đổi sản phẩm.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507; [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `LietKeSachDangMuon`, dòng 21.

<a id="TN230"></a>
### TN230 — Báo cáo đang xem có cho phép sửa nguồn đồng thời không

**Tấn · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN230).

**Trả lời ngắn:** Vòng xem là lời gọi chặn trong cùng luồng; phải trở về menu để chạy nghiệp vụ khác. Text đã dựng không có cập nhật nền.

**Giải thích và bảo vệ cách làm:**

Sự kiện phím trong HienThiPhanTrang được xử lý tại màn hình đó, không tự dispatch các lựa chọn menu chính. Thêm nền/live view cần mô hình đồng bộ dữ liệu, vòng đời và thông báo thay đổi; không dùng lập luận race giữa hai màn hình để mô tả lỗi hiện tại.

**Đáp câu phụ 1:** Không; không có watcher hay tự nạp. A chỉ biết thay đổi khi chủ động đọc lại, với các rủi ro phiên cũ.

**Sai lầm dễ mắc:** Có giao diện tương tác thì mặc nhiên có nhiều luồng cập nhật dữ liệu.

**Cách kiểm chứng:** Truy lời gọi đồng bộ và vòng nhận sự kiện; chưa thử concurrency vì code không có tính năng đó.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `HienThiPhanTrang`, dòng 450; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507.

<a id="TN231"></a>
### TN231 — Một báo cáo chạy nền trả kết quả sau khi đã NAP

**Tấn · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN231).

**Trả lời ngắn:** Kết quả có thể hợp lệ cho A nhưng bị gắn nhầm ngữ cảnh B; an toàn bộ nhớ không đủ cho đúng phiên.

**Giải thích và bảo vệ cách làm:**

Gắn generation/version phiên vào yêu cầu và kết quả, chỉ hiển thị khi vẫn khớp hoặc ghi rõ đó là báo cáo A. Hủy worker là tối ưu, kiểm version khi nhận mới là bảo vệ kết quả đến muộn. Bản hiện không có worker; snapshot sâu có chi phí O(D+C+R+H) và chuỗi.

**Đáp câu phụ 1:** Không; cần mã yêu cầu/thứ tự hoặc version dữ liệu, vì cùng file có thể có nhiều thế hệ và bộ lọc khác nhau.

**Sai lầm dễ mắc:** Không có dangling pointer là báo cáo bất đồng bộ chắc chắn thuộc đúng dữ liệu đang xem.

**Cách kiểm chứng:** Đề xuất giả lập hoàn thành đảo thứ tự và nạp lại cùng path; chưa triển khai worker.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `HienThiPhanTrang`, dòng 450; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `HoanDoiThuVien`, dòng 338.

<a id="TN232"></a>
### TN232 — Trang theo offset khi có người chen vào trước

**Tấn · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN232).

**Trả lời ngắn:** Offset trên tập thay đổi có thể lặp người cuối trang 1 ở trang 2; xóa trước offset có thể làm bỏ người.

**Giải thích và bảo vệ cách làm:**

Snapshot giữ tập/thứ tự cho toàn phiên đọc, tốn bộ nhớ hoặc phiên bản lưu trữ. Cursor theo trọn khóa cuối tránh dịch vị trí do thêm phía trước nhưng cần quy định khi người đổi tên, và không cho ngẫu nhiên tới trang xa miễn phí. Hiện chương trình đã giữ text nên không có lỗi offset động này.

**Đáp câu phụ 1:** Không; cần họ và mã theo comparator để không bỏ các bản ghi cùng tên.

**Sai lầm dễ mắc:** Chia dữ liệu thành trang tự động bảo đảm không lặp/mất khi nguồn đổi.

**Cách kiểm chứng:** Đề xuất: xen thêm/xóa/đổi tên giữa hai lần lấy trang; kiểm đúng theo đặc tả snapshot hoặc cursor.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InDocGiaTheoTenHo`, dòng 119; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `HienThiPhanTrang`, dòng 450.

<a id="TN233"></a>
### TN233 — Bộ chỉ mục starts phải giữ dòng cuối không có newline

**Tấn · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN233).

**Trả lời ngắn:** Hai text đầu có 2 dòng nội dung; text thứ ba có 3 dòng với dòng giữa rỗng. Dòng cuối không cần kết thúc LF để tồn tại.

**Giải thích và bảo vệ cách làm:**

Code chỉ thêm đầu dòng sau LF nếu còn ký tự phía sau, rồi thêm sentinel kích thước toàn chuỗi. Cặp starts[i],starts[i+1] xác định lát; bước bỏ CR/LF khi lấy dòng không đồng nghĩa bỏ dòng trống nội bộ. Đây là chỉ mục text, không đếm độc giả.

**Đáp câu phụ 1:** Không; mảng đầu dòng bắt đầu tại 0 nên có một dòng rỗng để xem, không được hiểu thành một bản ghi thư viện.

**Sai lầm dễ mắc:** Số ký tự LF luôn bằng số dòng nội dung hoặc số bản ghi.

**Cách kiểm chứng:** Truy ba chuỗi bằng chỉ số; đề xuất test renderer riêng, chưa chạy TUI.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `HienThiPhanTrang`, dòng 450.

<a id="TN234"></a>
### TN234 — Tính trang từ con trỏ dòng mà không nhân tràn

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN234).

**Trả lời ngắn:** API nhận toàn chuỗi nên phải xét khả năng biểu diễn số dòng/chỉ số, cả cộng làm tròn và nhân trước khi clamp.

**Giải thích và bảo vệ cách làm:**

Chọn kiểu đủ chứa size, kiểm chuyển về int, dùng phép tính tránh cộng tràn và chặn trước tăng/nhân. clamp sau biểu thức tràn không cứu phép toán đã sai. Không khẳng định bản hiện chịu chuỗi vô hạn; bộ nhớ có thể thất bại trước.

**Đáp câu phụ 1:** Chia cho 0; code hiện ép số dòng tối thiểu 1. Phải giữ tiền điều kiện đó khi sửa layout.

**Sai lầm dễ mắc:** Có min/max ở cuối biểu thức thì mọi tràn số ở giữa đều an toàn.

**Cách kiểm chứng:** Đề xuất kiểm bằng giá trị biên số học và stub số dòng, không cấp chuỗi hàng tỷ dòng.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `HienThiPhanTrang`, dòng 450.

<a id="TN236"></a>
### TN236 — Ngày phiên hợp lệ lúc mở nhưng đồng hồ đổi trước giao dịch

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN236).

**Trả lời ngắn:** Không; nghiệp vụ kiểm lại ngày giao dịch so với HomNay ở lúc gọi, nên 10/09 trở thành tương lai và bị từ chối.

**Giải thích và bảo vệ cách làm:**

Ngày phiên là giá trị lưu từ đầu, còn kiểm tương lai đọc đồng hồ mới. Đây là thay đổi môi trường trên bản thử; không cần sửa đồng hồ thật để chứng minh, có thể dùng clock stub. Muốn hỗ trợ ngày nghiệp vụ độc lập đồng hồ phải chốt đặc tả, không bỏ kiểm tùy tiện.

**Đáp câu phụ 1:** Không; i chỉ kiểm ngày hợp lệ. UI và nghiệp vụ khác hợp đồng, phải ghi rõ mốc được dùng.

**Sai lầm dễ mắc:** Một điều kiện đã đúng ở lúc vào chương trình thì đúng suốt phiên.

**Cách kiểm chứng:** Truy vị trí HomNay; đề xuất clock stub trên bản sao, chưa đổi ngày hệ thống.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KiemTraNgayGiaoDich`, dòng 17.

<a id="TN237"></a>
### TN237 — Mẫu form tối đa 12 trường nhưng caller muốn 13

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN237).

**Trả lời ngắn:** BieuMau ném std::runtime_error khi count ngoài 1..12, không trả false như thao tác hủy; plain có đường lặp riêng nên hợp đồng khả dụng UI không tự giống nhau cho 13 trường.

**Giải thích và bảo vệ cách làm:**

Caller phải dùng count được hỗ trợ và mảng labels/values đủ kích thước, hoặc chia form theo ý nghĩa và chốt commit cả nhóm. Không tăng count mà không xem fields/cursors/nút/scroll và đường hủy. Luật nghiệp vụ chung không giải quyết giới hạn renderer.

**Đáp câu phụ 1:** Không; phải giữ dữ liệu tạm đến cuối nếu đặc tả cần nguyên khối. Chia màn hình không tự chia/gộp giao dịch.

**Sai lầm dễ mắc:** Nhánh plain nhận đầu vào chứng minh mọi form TUI cùng API đều hỗ trợ được.

**Cách kiểm chứng:** Truy guard count và caller; đề xuất stub count 12/13 cùng hủy bước 2, chưa chạy TUI mới.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `BieuMau`, dòng 334; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `NhapBieuMau`, dòng 397.

<a id="TN238"></a>
### TN238 — Hai đích --data và --check trong cùng lệnh

**Tấn · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN238).

**Trả lời ngắn:** Nhánh check chạy trước nhánh khởi động data; nó chỉ thử B rồi trả 2 nếu B hỏng, không nạp hoặc tạo cha A qua nhánh data.

**Giải thích và bảo vệ cách làm:**

Các biến path và check được parse riêng; check không rỗng chi phối chế độ sau parse. Lặp --data dùng giá trị sau cùng, nhưng --help có thể return ngay khi gặp. Chỉ nhìn tên exe hay một phần command không đủ tái lập.

**Đáp câu phụ 1:** Không; parse ngày sai trả 2 trước DocFile. Cần phân biệt lỗi đối số với lỗi dữ liệu B qua stderr.

**Sai lầm dễ mắc:** Mã thoát 2 luôn có nghĩa file mà người dùng muốn kiểm đã được đọc và phát hiện hỏng.

**Cách kiểm chứng:** Đề xuất ba argv có dấu nhận diện file, đối chiếu thông báo và không có file A mới.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507.

<a id="TN239"></a>
### TN239 — --check xanh nhưng người đọc vẫn không được mượn

**Tấn · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN239).

**Trả lời ngắn:** File hợp lệ có thể chứa thẻ khóa; check toàn vẹn không cấp quyền mượn cho mọi người.

**Giải thích và bảo vệ cách làm:**

Loader kiểm trạng thái thẻ thuộc miền 0/1 và các quan hệ; MuonSach yêu cầu thẻ hoạt động cùng điều kiện hạn mức/quá hạn/cuốn. Một trạng thái bị chặn nghiệp vụ vẫn là trạng thái hợp lệ của hệ thống.

**Đáp câu phụ 1:** Không; xóa quyết định khóa và có thể vi phạm lịch sử mất. Kiểm tra phải chỉ đọc, không sửa quyền.

**Sai lầm dễ mắc:** PASS toàn vẹn là PASS mọi chức năng với mọi đầu vào nghiệp vụ.

**Cách kiểm chứng:** Đã có ca CLI thẻ khóa bị từ chối; mở rộng kiểm --check trên cùng fixture là test đề xuất.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114.

<a id="TN240"></a>
### TN240 — Thư mục mới có nhưng file chưa có sau hủy phiên

**Tấn · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN240).

**Trả lời ngắn:** Không nhất thiết có lần lưu nào; ChayUngDung tạo thư mục cha khi đích chưa có, trước menu.

**Giải thích và bảo vệ cách làm:**

File chỉ được ghi qua LuuFile. Thoát không lưu không hoàn tác thư mục đã tạo; tác dụng phụ filesystem và dữ liệu thư viện là hai phạm vi. Test phải quan sát đúng file, nội dung và lời gọi lưu, không dùng sự tồn tại thư mục làm chứng cứ commit.

**Đáp câu phụ 1:** Chưa đi vào menu/lưu; lỗi ra catch ngoài. Có thể có phần đường dẫn đã tạo, không đồng nghĩa có snapshot dữ liệu.

**Sai lầm dễ mắc:** Không có file dữ liệu thì chương trình chưa hề tạo tác dụng phụ filesystem nào.

**Cách kiểm chứng:** Đề xuất chạy trong đường tạm mới, ghi nhận thư mục/file trước–sau; không thử quyền trên dữ liệu nhóm.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `LuuFile`, dòng 353.

<a id="TN241"></a>
### TN241 — Con trỏ ngữ cảnh UI được gán cho một phiên cục bộ

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN241).

**Trả lời ngắn:** Sau ChayUngDung trả, tv và path cục bộ đã hết đời sống; các con trỏ UI toàn cục không được reset thành null nên không được dùng tiếp.

**Giải thích và bảo vệ cách làm:**

Mô hình chạy hiện tại kết thúc chương trình sau một ChayUngDung nên không có màn hình kế tiếp dùng chúng. Khi nhúng/tái khởi động UI trong cùng tiến trình cần quản lý context bằng lifetime rõ ràng hoặc reset/RAII, không giữ địa chỉ stack cũ.

**Đáp câu phụ 1:** Không; phải gắn callback với phiên mới rõ ràng, không dựa vào bộ nhớ tình cờ tái sử dụng.

**Sai lầm dễ mắc:** Biến con trỏ toàn cục làm đối tượng mà nó trỏ tới sống toàn chương trình.

**Cách kiểm chứng:** Chỉ chẩn đoán lifetime; không gọi con trỏ hết hạn để tạo bằng chứng giả.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `TongQuan`, dòng 263.

<a id="TN242"></a>
### TN242 — Báo lỗi lại cần cấp phát và ghi màn hình

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN242).

**Trả lời ngắn:** Không; exception ném từ phần thân catch không được chính catch đó xử lý lại, có thể đi ra main.

**Giải thích và bảo vệ cách làm:**

Đường báo lỗi cũng có cấp phát/I/O. Vì thế không hứa mọi lỗi thao tác đều giữ ứng dụng mở; cần phương án thông báo tối thiểu ít phụ thuộc tài nguyên khi thiết kế lại. Trạng thái RAM có thể đã đổi hoặc chưa, tùy vị trí lỗi ban đầu.

**Đáp câu phụ 1:** Không; không có autosave ở catch ngoài. Phân biệt giao dịch đang lỗi với dữ liệu cũ còn trong RAM.

**Sai lầm dễ mắc:** Đã có catch trong vòng lặp thì mọi lỗi phát sinh trong cả handler đều được phục hồi.

**Cách kiểm chứng:** Truy phạm vi try; fault injection hai lần lỗi liên tiếp mới kiểm được runtime, chưa chạy.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ThongBao`, dòng 444; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `main`, dòng 585.

<a id="TN243"></a>
### TN243 — Mượn bị từ chối nhưng tiến trình vẫn trả 0

**Tấn · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN243).

**Trả lời ngắn:** Exitcode 0 cho biết đường thoát bình thường, không cho biết mọi thao tác nghiệp vụ thành công.

**Giải thích và bảo vệ cách làm:**

Ca từ chối mong đúng thông báo, số lượt và cuốn không đổi; ca thành công mong node mới và trạng thái cuốn đổi. Nên đọc snapshot được lưu ở test riêng hoặc API state, tránh coi chuỗi OK bất kỳ trong cả log là bằng chứng cho lệnh đang xét.

**Đáp câu phụ 1:** Không; cần gắn đoạn output/hậu điều kiện với đúng thao tác, tránh thành công của lệnh trước che lệnh sau.

**Sai lầm dễ mắc:** Mã thoát 0 hoặc một chữ OK đủ làm oracle cho toàn kịch bản tương tác.

**Cách kiểm chứng:** Các test CLI mới kiểm thông báo và hậu điều kiện cụ thể; không chỉ dùng exitcode.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `ManHinhMuonTra`, dòng 206; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507.

<a id="TN244"></a>
### TN244 — Xuất CSV từ bảng ký tự phân cột

**Tấn · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN244).

**Trả lời ngắn:** Quy tắc của định dạng đích khác quy tắc bảng hiện tại; dấu phẩy/nháy trong trường cần escape CSV đúng.

**Giải thích và bảo vệ cách làm:**

Nên xuất từ các trường dữ liệu, bao/nhân đôi nháy khi cần, tách tiêu đề và thông báo khỏi bản ghi. Không tự cấm thêm dấu phẩy trong tên để chữa renderer. Đây là bản xuất đọc, không phải schema DocFile hiện tại.

**Đáp câu phụ 1:** Không; phải định nghĩa tab/newline/encoding và cách round-trip của định dạng đó, dù validator hiện tại đã chặn nhiều ký tự điều khiển.

**Sai lầm dễ mắc:** Thay ký tự phân cột trong text là chuyển đổi định dạng dữ liệu hoàn chỉnh.

**Cách kiểm chứng:** Đề xuất round-trip CSV bằng parser độc lập với tên chứa dấu phẩy/nháy; chưa cài exporter.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InMotDocGia`, dòng 41; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `DongBang`, dòng 230; [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `HopLeVanBan`, dòng 42.

<a id="TN245"></a>
### TN245 — Thêm lựa chọn menu làm lệch nghiệp vụ

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN245).

**Trả lời ngắn:** Chỉ số vị trí đang đóng vai trò mã hành động; chèn một nhãn mà không sửa dispatcher và menu TUI sẽ lệch.

**Giải thích và bảo vệ cách làm:**

Cần đối chiếu nhãn plain, nhãn/đường tắt TUI, giá trị ChonMenu trả và nhánh nghiệp vụ. Thiết kế mã hành động ổn định tách khỏi vị trí giúp giảm rủi ro, nhưng phải kiểm mọi đường trả. Không đổi count chỉ để làm hiện thêm chữ rồi coi đã tích hợp.

**Đáp câu phụ 1:** Không; lỗi ở mapping UI→API. Cần test lựa chọn thật và quan sát API/hậu điều kiện của từng mục.

**Sai lầm dễ mắc:** Thêm dòng vào mảng nhãn là đã thêm chức năng menu hoàn chỉnh.

**Cách kiểm chứng:** Đề xuất bảng expected action cho mọi mục sau chèn, test plain và TUI riêng; chưa sửa menu.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChonMenu`, dòng 419; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `TrangChinh`, dòng 270.

<a id="TN246"></a>
### TN246 — Một triệu độc giả: không thể chỉ tăng số dòng màn hình

**Tấn · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN246).

**Trả lời ngắn:** MAX_DOC_GIA=100000 chặn nạp/thêm/duyệt; không có benchmark 1 triệu ở bản hiện.

**Giải thích và bảo vệ cách làm:**

Sau khi giả sử sửa giới hạn và duyệt an toàn, vẫn có node/chuỗi nguồn, stack theoMAX, viewR con trỏ, O(R log R) so tên với L, rồi text UTF-8, bản UTF-16 và starts. Cần tính bộ nhớ đỉnh khi buffer chồng sống và lượng xuất; phân trang 13 dòng không xóa các khoản này. Đây là 1 triệu hồ sơ, không 1 triệu phiên.

**Đáp câu phụ 1:** Không; cần đổi truy vấn/materialization hoặc chỉ lấy tập cần, kèm đặc tả truy cập trang và version.

**Sai lầm dễ mắc:** Tăng MAX và giảm chiều cao bảng đủ biến console thành hệ thống phục vụ triệu người đồng thời.

**Cách kiểm chứng:** Chỉ phân tích cận; đề xuất đo tăng dần trên dữ liệu tổng hợp trong giới hạn an toàn, chưa đo tải triệu.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — `MAX_DOC_GIA`, dòng 8; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `LayDanhSachDocGia`, dòng 18; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InDocGiaTheoTenHo`, dòng 119; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `HienThiPhanTrang`, dòng 450.

<a id="TN247"></a>
### TN247 — So hai bản báo cáo sau sửa code bằng tiêu chí nào

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN247).

**Trả lời ngắn:** Tách kiểm ngữ nghĩa các bản ghi, thứ tự, trường khóa và trạng thái khỏi kiểm định dạng được phép đổi.

**Giải thích và bảo vệ cách làm:**

Báo cáo b so dãy mã với trường tương ứng; d so nhóm thể loại và dãy ISBN; h so đúng lượt mở/mã/tên. Không bỏ qua ngày hay mã như "nhiễu". Vẫn có một lớp test riêng cho tiêu đề/phân cột để phát hiện mất khả năng đọc.

**Đáp câu phụ 1:** Đối chiếu cặp trường trên từng bản ghi theo danh tính, không chỉ tập mã hoặc tập tên rời nhau.

**Sai lầm dễ mắc:** Giảm độ nhạy của snapshot bằng cách bỏ toàn nội dung cần bảo vệ.

**Cách kiểm chứng:** Đề xuất oracle độc lập từ fixture nhỏ, kiểm cả mutation đổi mapping và thay whitespace hợp lệ.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InDocGiaTheoTenHo`, dòng 119; [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `InDauSachTheoTheLoai`, dòng 98; [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `LietKeSachDangMuon`, dòng 21.

<a id="TN248"></a>
### TN248 — Cho phép sửa tiếp sau khi lưu báo dữ liệu không toàn vẹn

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN248).

**Trả lời ngắn:** Không; nghiệp vụ cục bộ không phải công cụ sửa toàn bộ RAM hỏng, và thao tác mới có thể che dấu nguồn lỗi.

**Giải thích và bảo vệ cách làm:**

Ghi lỗi cụ thể, phiên bản, danh tính liên quan và đường tái hiện trên bản sao; so snapshot hợp lệ gần nhất. Một số báo cáo có thể hiển thị liên kết lỗi hoặc ném, không chứng nhận trạng thái an toàn để tiếp tục. Bản hiện giữ RAM để không mất ngay dữ liệu, chưa có chế độ repair.

**Đáp câu phụ 1:** Không; chỉ phục hồi snapshot file, những thay đổi chưa ghi có thể mất và cần đối soát riêng.

**Sai lầm dễ mắc:** Còn hiện menu thì mọi thao tác tiếp theo đều là cách chữa dữ liệu an toàn.

**Cách kiểm chứng:** Chỉ đề xuất quy trình fixture; không tự làm hỏng RAM/dữ liệu nhóm.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `LuuFile`, dòng 353; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102.

<a id="TN249"></a>
### TN249 — Định dạng số của stream có thể làm lệch dữ liệu thử

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN249).

**Trả lời ngắn:** Có thể hiện 10 và 1a theo trạng thái hex kế thừa; hàm hiện không reset base số của stream.

**Giải thích và bảo vệ cách làm:**

Caller menu tạo ostringstream mới nên mặc định thập phân, nhưng API ostream& có trạng thái do caller điều khiển. Cần chốt tiền điều kiện stream hoặc thiết kế guard định dạng/serializer rõ ràng. Đây là lỗi tích hợp giả lập, không khẳng định menu đang in hex.

**Đáp câu phụ 1:** Caller muốn tiếp tục in hex sau báo cáo; hợp đồng cần nói ai sở hữu trạng thái format hoặc dùng guard khôi phục.

**Sai lầm dễ mắc:** Một ostream mới hay cũ đều in số như nhau bất kể manipulator trước đó.

**Cách kiểm chứng:** Đề xuất harness hex/dec và so mã dữ liệu thật; chưa chạy ca stream state.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InDocGiaTheoMa`, dòng 111; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InMotDocGia`, dòng 41.

<a id="TN250"></a>
### TN250 — In theo mã rồi mới sắp view dùng chung

**Tấn · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN250).

**Trả lời ngắn:** Có thể tái sử dụng nếu hoàn tất xuất thứ tự mã trước khi sắp; sau sort view không còn theo mã.

**Giải thích và bảo vệ cách làm:**

Tiết kiệm một lần đếm/duyệt/cấp view trong cùng snapshot, không đổi BST. Nếu cần hai view cùng lúc hoặc quay lại thứ tự mã phải giữ bản sao con trỏ hoặc dựng lại/in theo cây. Phải quản lý rõ trạng thái thứ tự của buffer, không gọi nó là view mã suốt đời.

**Đáp câu phụ 1:** Không; chuỗi đã chứa bản sao ký tự, không phải view con trỏ sống.

**Sai lầm dễ mắc:** View lấy từ inorder luôn giữ thứ tự mã dù đã được một hàm khác sort.

**Cách kiểm chứng:** Đề xuất so hai báo cáo với hai lời gọi chuẩn; kiểm nguồn không đổi và không lẫn thứ tự.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InDocGiaTheoMa`, dòng 111; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InDocGiaTheoTenHo`, dòng 119.

<a id="TN251"></a>
### TN251 — Dòng form đã trả một phần khi bước sau bị hủy

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN251).

**Trả lời ngắn:** Không có bảo đảm rollback toàn mảng values ở fallback đọc tuần tự; các ô trước có thể đã được gán.

**Giải thích và bảo vệ cách làm:**

values phải là vùng tạm của caller, không bind trực tiếp vào node. false nghĩa không có bộ form hoàn chỉnh để commit, không có nghĩa mọi byte output chưa từng đổi. TUI dùng fields tạm nhưng cũng không nên suy hợp đồng mạnh hơn cho mọi mode từ một nhánh.

**Đáp câu phụ 1:** Trường mới đầu form có thể ghép với trường cũ lần trước, tạo hồ sơ hợp lệ cú pháp nhưng sai ý định.

**Sai lầm dễ mắc:** Một API nhập trảfalse luôn giữ nguyên mọi output, bất kể nó đọc bao nhiêu trường.

**Cách kiểm chứng:** Đề xuất values có dấu riêng từng ô, hủy ở trường 2, assert không gọi nghiệp vụ và inspect vùng tạm.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `NhapBieuMau`, dòng 397; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `NhapDong`, dòng 403.

<a id="TN253"></a>
### TN253 — Một thay đổi chỉ đọc có thể vẫn rất tốn cấp phát

**Tấn · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN253).

**Trả lời ngắn:** Có thể chồng buffer ostringstream, string từ str(), wstring all và starts; view sort đã hết đời sống khi hàm in trả.

**Giải thích và bảo vệ cách làm:**

Báo cáo không đổi dữ liệu nhưng vẫn cấp phát. Cần phân biệt lifetime giữa bước sort/in và bước phân trang để không cộng mọi khoản vô điều kiện hoặc bỏ sót bản copy. Đo peak theo giai đoạn, L và số dòng; bộ cấp phát có thể giữ vùng đã free nên RSS cũng không bằng số object sống.

**Đáp câu phụ 1:** Chỉ có thể bỏ lần tạo lại/copy tùy cách truyền, nhưng giữ thêm bộ nhớ nền; cần đo lifetime thực, không suy từ số biến.

**Sai lầm dễ mắc:** Read-only nghĩa là không tốn tài nguyên hoặc bộ nhớ cuối phiên bằng đỉnh.

**Cách kiểm chứng:** Phân tích lifetime theo scope; chưa đo RSS/peak hay benchmark.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InDocGiaTheoTenHo`, dòng 119; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `HienThiPhanTrang`, dòng 450.

<a id="TN254"></a>
### TN254 — Sắp báo cáo báo lỗi thì có được hiển thị view đang dở

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN254).

**Trả lời ngắn:** BST không bị sửa; view có thể chưa sắp xong và không được gắn nhãn đã sắp. Mọi swap đã hoàn tất vẫn giữ tập con trỏ.

**Giải thích và bảo vệ cách làm:**

So sánh ném trước swap kế tiếp, các lần swap trước chỉ hoán vị. Hàm hiện không catch để in view dở, và tiêu đề được viết sau sort. Nếu thêm fallback phải ghi rõ thứ tự khác hoặc chạy một đường đọc có hợp đồng rõ; thiếu bộ nhớ có thể khiến fallback cũng lỗi.

**Đáp câu phụ 1:** Thứ tự view đã đúng nhưng output có thể thiếu phần cuối; vấn đề chuyển từ kết quả thuật toán sang hoàn tất xuất.

**Sai lầm dễ mắc:** Báo cáo chỉ đọc không có trạng thái trung gian cần phân biệt khi lỗi.

**Cách kiểm chứng:** Truy vị trí sort/tiêu đề; fault injection comparator và stream là hai test riêng chưa chạy.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InDocGiaTheoTenHo`, dòng 119; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `TenHoTruoc`, dòng 44; [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `SoSanhChuoi`, dòng 27.

<a id="TN255"></a>
### TN255 — Tối ưu so tên bằng địa chỉ string

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN255).

**Trả lời ngắn:** Địa chỉ không mã hóa thứ tự chữ; quan hệ địa chỉ đối tượng không phải hợp đồng sắp tên.

**Giải thích và bảo vệ cách làm:**

Sau nạp/cấp phát mới địa chỉ có thể khác dù dữ liệu y hệt. Muốn giảm chuẩn hóa phải lưu khóa nội dung tạm gắn đúng từng record và giữ comparator đầy đủ. Không dùng pointer ordering hoặc hash đơn lẻ để thay thứ tự từ vựng.

**Đáp câu phụ 1:** Không; hash không bảo toàn thứ tự và có thể va chạm. Nó chỉ hỗ trợ tác vụ phù hợp khi vẫn xử lý bằng nội dung.

**Sai lầm dễ mắc:** So nhanh một số đại diện của chuỗi là tương đương so chuỗi.

**Cách kiểm chứng:** Đề xuất tạo cùng dữ liệu theo nhiều thứ tự cấp phát, so output với comparator chuẩn.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `TenHoTruoc`, dòng 44; [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `SoSanhChuoi`, dòng 27.

<a id="TN256"></a>
### TN256 — Chọn tên từ từng trang rồi ghép có thành toàn cục

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN256).

**Trả lời ngắn:** Các khối đã sắp vẫn có thể giao nhau về khoảng khóa; nối không tạo thứ tự toàn cục.

**Giải thích và bảo vệ cách làm:**

Cần merge các run theo cùng comparator hoặc thiết kế chọn trang từ toàn tập có bảo đảm. External sort còn cần nơi lưu run, quản lý lỗi/temp và snapshot; hiện chương trình sort toàn view trong RAM. Không thay bằng local sort chỉ vì màn hình hiển thị từng khối.

**Đáp câu phụ 1:** Được, nhưng phải có bảo đảm đó theo dữ liệu/thuật toán, không suy từ thứ tự mã ban đầu.

**Sai lầm dễ mắc:** Mỗi trang đã đúng thứ tự thì báo cáo nhiều trang cũng đúng thứ tự.

**Cách kiểm chứng:** Đề xuất dữ liệu tên đảo theo nhóm mã và so ranh giới giữa hai trang.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InDocGiaTheoTenHo`, dòng 119; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `HienThiPhanTrang`, dòng 450.

<a id="TN257"></a>
### TN257 — Đổi giới hạn trang có làm kết quả lọc khác nhau

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN257).

**Trả lời ngắn:** Ghép các dòng dữ liệu được phân trang đúng một lần phải khớp chuỗi báo cáo đầy đủ trước phân trang, với cùng thứ tự.

**Giải thích và bảo vệ cách làm:**

Đổi step không được đổi tập/thứ tự dữ liệu; chỉ đổi điểm ngắt. Kiểm bắt đầu 0, mỗi lát nửa mở không chồng/khuyết, cuối đúngn; tiêu đề lặp phải loại theo metadata nếu thiết kế mới có. Không so số trang vì số trang được phép đổi.

**Đáp câu phụ 1:** Không; cần tách dòng trang trí và dòng dữ liệu để kiểm coverage, đồng thời kiểm tiêu đề ở lớp bố cục.

**Sai lầm dễ mắc:** Đếm đúng số trang đủ chứng minh không bỏ/lặp dòng ở ranh giới.

**Cách kiểm chứng:** Đề xuất test mọi step nhỏ trên cùng danh sách, nhất là n=step±1,2step±1; chưa chạy TUI.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `HienThiPhanTrang`, dòng 450; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InDocGiaTheoTenHo`, dòng 119; [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `LietKeSachDangMuon`, dòng 21.

<a id="TN258"></a>
### TN258 — Hiển thị trạng thái bằng điều kiện chân trị che miền sai

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN258).

**Trả lời ngắn:** Có thể hiện Hoat dong vì 2 khác 0, nhưng trạng thái 2 sai miền; validator từ chối.

**Giải thích và bảo vệ cách làm:**

Định dạng ternary không tự kiểm enum. MuonSach kiểm khác THE_HOAT_DONG nên 2 bị từ chối, làm lộ chênh lệch giữa nhãn và rule. Bản dữ liệu hợp lệ qua loader không có 2; câu này là chẩn đoán RAM hỏng, không cáo buộc luồng nhập bình thường.

**Đáp câu phụ 1:** Giá trị 2 là true nên vượt cổng thẻ sau sửa; nếu mọi kiểm khác hợp lệ có thể mượn dù thẻ sai miền. Làm renderer và nghiệp vụ cùng hiểu sai không sửa dữ liệu. Phải giữ kiểm miền/giá trị 1 và hiển thị rõ giá trị lỗi.

**Sai lầm dễ mắc:** Một nhãn Hoạt động trên báo cáo là chứng cứ mọi predicate thẻ đều nhận hợp lệ.

**Cách kiểm chứng:** Truy ternary và so enum; đề xuất harness giá trị 2, không sửa file runtime thật.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InMotDocGia`, dòng 41; [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `HopLeTrangThaiThe`, dòng 128; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102.

<a id="TN259"></a>
### TN259 — Phép tìm đầu sách trong báo cáo nên mượn hay sở hữu dữ liệu

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN259).

**Trả lời ngắn:** string_view chỉ mượn vùng ký tự; NAP hủy đầu cũ có thể làm view treo. string copy sở hữu ký tự riêng nhưng là snapshot cũ.

**Giải thích và bảo vệ cách làm:**

Trong h hiện tại, tên được ghi ngay vào stream khi nguồn còn sống. Trả view ra ngoài mở rộng lifetime contract; const chỉ cấm sửa qua view, không kéo dài đời sống. Nếu copy thì tốn O(L) nhưng vẫn phải gắn đúng phiên nếu dùng muộn.

**Đáp câu phụ 1:** Không; gán string có thể cấp phát lại hoặc đổi nội dung. Node còn sống không đủ bảo đảm buffer cũ.

**Sai lầm dễ mắc:** Tham chiếu/view const là bản sao an toàn, độc lập với nguồn.

**Cách kiểm chứng:** Chỉ phân tích hợp đồng API mới; không dereference vùng đã hết hạn.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `TimCuonSachToanCuc`, dòng 30, 51; [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `LietKeSachDangMuon`, dòng 21.

<a id="TN260"></a>
### TN260 — Nhập form theo mảng trường làm lệch dữ liệu có kiểu giống nhau

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN260).

**Trả lời ngắn:** Validator thấy hai chuỗi hợp lệ nên có thể chấp nhận, nhưng ý nghĩa trường bị tráo; thứ tự sort tên cũng thay vì lấy nhầm phần họ.

**Giải thích và bảo vệ cách làm:**

Đây là hợp đồng vị trí giữa labels, values và tham số API. Cần test trường có giá trị phân biệt, không dùng họ/tên giống nhau; giữ mô hình dữ liệu có tên trường rõ hoặc ánh xạ được kiểm. Thành công kỹ thuật không đồng nghĩa đúng ý định người nhập.

**Đáp câu phụ 1:** Không; phải kiểm đúng họ và tên sau commit, rồi thứ tự báo cáo dự kiến.

**Sai lầm dễ mắc:** Hai tham số cùng kiểu string nên đổi vị trí không làm sai nghiệp vụ.

**Cách kiểm chứng:** Đề xuất họNguyen tênAn và họLe tênBinh, kiểm form→API→b theo tên trên bản sao.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `NhapBieuMau`, dòng 397; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `ManHinhDocGia`, dòng 138; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `HieuChinhDocGia`, dòng 73.

<a id="TN261"></a>
### TN261 — Hủy trả sách sau khi đã chọn loại báo mất

**Tấn · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN261).

**Trả lời ngắn:** Không có cờ báo mất lưu toàn phiên ở đường này; lựa chọn loại thuộc lời gọi màn hình, hủy trước API không đổi X,Y/thẻ.

**Giải thích và bảo vệ cách làm:**

Lần sau đọc lựa chọn mới và gọi TraSach choY; báo mất chỉ commit khi DanhDauMatSach thành công. Cần kiểm cả trạng thái điều khiển lẫn RAM, tránh refactor dùng biến toàn cục nhớ loại mà không reset khi hủy.

**Đáp câu phụ 1:** Không; khóa từ mấtX đã commit, trảY được phép nhưng không xóa lịch sử mất hay tự mở thẻ.

**Sai lầm dễ mắc:** Chọn mục báo mất đã tự khóa thẻ, hoặc hủy màn hình sau commit sẽ hoàn tác mất.

**Cách kiểm chứng:** Truy scope biến và lời gọi; ca mất rồi trả có test CLI, ca hủy form TUI chưa chạy.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `ManHinhMuonTra`, dòng 206; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `DanhDauMatSach`, dòng 142; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `NhapBieuMau`, dòng 397.

<a id="TN262"></a>
### TN262 — Danh sách độc giả là danh sách hiện tại, không phải người từng tồn tại

**Tấn · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN262).

**Trả lời ngắn:** Không; high-water mark giữ việc không cấp lùi, không lưu tên hay sự kiện cấp/xóa của hồ sơ đã xóa.

**Giải thích và bảo vệ cách làm:**

b duyệt node hiện tồn tại. XoaDocGia cho xóa người không lịch sử, nên thông tin cá nhân đó không còn trong mô hình. Nếu cần audit ai tạo/xóa và thời điểm phải có dữ liệu/yêu cầu bổ sung, không suy từ số mốc.

**Đáp câu phụ 1:** Không; file có thể có mốc lớn hơn mã lớn nhất và các khoảng khuyết, nhưng không chứa nguyên nhân từng khoảng.

**Sai lầm dễ mắc:** Mã không tái dùng đồng nghĩa có đầy đủ lịch sử chủ sở hữu của mọi mã đã cấp.

**Cách kiểm chứng:** Truy delete và schema mốc; test CLI đã giữ mốc sau xóa, việc truy lại tên cũ không được hỗ trợ.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `XoaDocGia`, dòng 85; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InDocGiaTheoMa`, dòng 111; [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — `ThuVien`, dòng 30.

<a id="TN263"></a>
### TN263 — Đặt giới hạn kết quả báo cáo mà không giấu việc cắt

**Tấn · P2 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN263).

**Trả lời ngắn:** Phải nêu tổng phù hợp hoặc trạng thái còn dữ liệu, số đã hiển thị, điều kiện lọc/thứ tự và dấu bị giới hạn.

**Giải thích và bảo vệ cách làm:**

Cắt 1000 node inorder trước sort tên là 1000 mã nhỏ được sắp tên, không 1000 tên nhỏ nhất toàn bộ. Muốn tập đầu theo tên phải chọn theo toàn bộ thứ tự hoặc định nghĩa lại báo cáo rõ ràng. Metadata phải lấy từ cùng snapshot.

**Đáp câu phụ 1:** Không; có thể ghi "đang hiển thị 1000, còn dữ liệu" hoặc chưa biết tổng theo hợp đồng, không giả số chính xác.

**Sai lầm dễ mắc:** Giới hạn tài nguyên chỉ là chi tiết UI nên không cần thông báo thay đổi phạm vi kết quả.

**Cách kiểm chứng:** Đề xuất đặt người tênA ở mã lớn ngoài 1000 đầu, kiểm nhãn cắt và tập kết quả.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InDocGiaTheoTenHo`, dòng 119; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `HienThiPhanTrang`, dòng 450.

<a id="TN264"></a>
### TN264 — Khi mỗi bước đều tuyến tính nhưng lặp ở trong vòng

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN264).

**Trả lời ngắn:** Đếm lại mỗi điều kiện vòng lặp làm khoảng R+1 lần duyệt O(R), thành O(R²) cộng nhiều cấp phát stack.

**Giải thích và bảo vệ cách làm:**

n lấy một lần đủ trong mô hình tuần tự nguồn không đổi. Nếu có đồng thời, đếm mới mỗi vòng vẫn không làm view cũ hợp lệ hoặc đủ capacity; cần khóa/snapshot, không phải polling count. Đây là công việc dư có thể chứng minh bằng số lần gọi.

**Đáp câu phụ 1:** Không nên dựa vào tối ưu để sửa thiết kế; hàm có cấp phát/ngoại lệ và đọc cấu trúc nên không mặc nhiên là biểu thức hằng có thể nhấc ra.

**Sai lầm dễ mắc:** Một hàm O(R) vẫn rẻ khi dùng trong điều kiện của một vòng O(R).

**Cách kiểm chứng:** Đề xuất instrument số lần DemDocGia trên bản sao, không đo bằng mắt thời gian bảng xuất.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `DemDocGia`, dòng 33; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `LayDanhSachDocGia`, dòng 18.

<a id="TN265"></a>
### TN265 — Một bản báo cáo thất bại có được đánh dấu đã kiểm dữ liệu

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN265).

**Trả lời ngắn:** Ví dụ phiếu trỏ mã cuốn không tồn tại vẫn không được b theo tên kiểm; b chỉ dùng trường độc giả để sắp/in.

**Giải thích và bảo vệ cách làm:**

Không có exception của một báo cáo chỉ chứng minh đường đó không báo lỗi trong lần chạy. Cờ toàn vẹn chỉ hợp lệ nếu bộ kiểm đủ phạm vi đã chạy trên đúng version và không có mutation chưa kiểm sau đó. Tối ưu bỏ kiểm lưu cần luận chứng riêng.

**Đáp câu phụ 1:** Không; mutation mới phải giữ mọi invariant được chứng minh hoặc hủy hiệu lực cờ.

**Sai lầm dễ mắc:** Chạy được một màn hình là đã xác nhận toàn dữ liệu thư viện hợp lệ.

**Cách kiểm chứng:** Đề xuất fixture lỗi chỉ ở lịch sử, so b với bộ kiểm; không bỏ validator sản phẩm.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraToanVen`, dòng 345; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InDocGiaTheoTenHo`, dòng 119.

<a id="TN266"></a>
### TN266 — Bằng chứng read-only bằng hash file có đủ không

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN266).

**Trả lời ngắn:** Hash file chỉ quan sát đĩa, không thấy mutation RAM chưa lưu. Cần snapshot ngữ nghĩa RAM trước/sau hoặc serialize vào vùng thử để so đúng dữ liệu.

**Giải thích và bảo vệ cách làm:**

Đối chiếu node, trường, liên kết theo hợp đồng; nếu dùng serializer làm oracle phải biết nó phủ các trường cần bảo vệ và không tự làm mất dữ liệu. Không lưu vào file thật để kiểm một hàm chỉ đọc. Pointer/order cần xét khác nhau giữa chỉ xem và round-trip.

**Đáp câu phụ 1:** Không; so byte và so ngữ nghĩa là hai mức khác nhau. Với chỉ xem không ghi, file phải không đổi; với round-trip cần định nghĩa canonical.

**Sai lầm dễ mắc:** Hash đĩa không đổi chứng minh toàn bộ trạng thái trong RAM bất biến.

**Cách kiểm chứng:** Đề xuất mutation tráo tên trên bản sao phải bị snapshot RAM bắt dù hash file cũ vẫn giữ.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InDocGiaTheoTenHo`, dòng 119; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `LuuFile`, dòng 353; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507.

<a id="TN267"></a>
### TN267 — Mã hóa chuỗi ngày dùng để sort có làm lệch năm

**Tấn · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN267).

**Trả lời ngắn:** Sort dd/mm/yyyy đặt 01/12 trước 02/01 dù tháng 12 muộn hơn; cần khóa ngày có nghĩa lịch như SoThuTuNgay.

**Giải thích và bảo vệ cách làm:**

ISO với năm/tháng/ngày đủ độ rộng và ngày đã hợp lệ có thứ tự từ vựng khớp thời gian, nhưng sentinel và ngày sai phải xử lý riêng. Ordinal hiện có kiểm hợp lệ và tránh lệ thuộc format UI. Không đổi format hiển thị để chữa khóa sort mà không nêu đặc tả.

**Đáp câu phụ 1:** Không; sentinel là chưa có ngày kết thúc, không một mốc thời gian. Cần định nghĩa vị trí/loại khỏi sort theo mục đích.

**Sai lầm dễ mắc:** Ngày đã zero-pad là so chuỗi đúng bất kể thứ tự các thành phần.

**Cách kiểm chứng:** Đề xuất cặp qua tháng/năm, ngày hòa và sentinel; so expected theo lịch độc lập, chưa cài sort mới.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `ChuoiNgay`, dòng 106; [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `SoThuTuNgay`, dòng 112; [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `LietKeSachDangMuon`, dòng 21.

<a id="TN24"></a>
### TN24 — Vùng heap thu nhỏ khác với độ dài mảng đã cấp

**Tấn · P3 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN24).

**Trả lời ngắn:** Vùng heap là[0, size ), ngoài đó là đoạn đã được chốt. Cận n chỉ bảo vệ vùng cấp phát, không bảo vệ invariant thuật toán.

**Giải thích và bảo vệ cách làm:**

Nút cuối có thể chỉ có con trái; phải kiểm child+1< size trước đọc con phải. Dùng n cho phép đọc và hoán đổi phần tử đã chốt.

Lỗi này có thể không gây crash hay báo vượt bộ nhớ; cần kiểm thứ tự và tính cố định của đoạn cuối sau từng bước.

**Đáp câu phụ 1:** Có nhưng thuộc vùng đã chốt; lỗi logic không nhất thiết vượt vùng cấp phát.

**Sai lầm dễ mắc:** Không crash hoặc sanitizer im lặng chứng minh heap đúng.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Truy heap kích thước chẵn 6 trong mảng 10, đánh dấu đoạn đã chốt; thử tên/họ hòa để tránh test chỉ theo một ký tự.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InDocGiaTheoTenHo`, dòng 119.

<a id="TN27"></a>
### TN27 — Tìm người theo họ tên trên bảng đã sắp tên

**Tấn · P3 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN27).

**Trả lời ngắn:** Bảng tăng theo tên rồi họ không tăng theo chuỗi họ+tên; nhị phân bằng khóa khác có thể bỏ sót. Tìm chứa còn không bảo đảm tập khớp liên tiếp.

**Giải thích và bảo vệ cách làm:**

Có thể quét view và lọc theo hợp đồng truy vấn, hoặc tạo chỉ mục tạm có đúng khóa cho tìm chính xác; vẫn giữ maThe để định danh người trùng tên.

Chi phí phụ thuộc số người/độ dài chuỗi; không đổi khóa BST hoặc danh tính chỉ để tiện tìm từ UI.

**Đáp câu phụ 1:** Không; contains không bảo đảm đoạn liên tiếp theo khóa hiện có. Phải giữ đúng nghĩa query.

**Sai lầm dễ mắc:** Mọi tìm tên là tìm exact key có thể nhị phân.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Dùng phản ví dụ ba người và hai người trùng họ tên; kiểm cả tìm đúng nguyên chuỗi và phần tên.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `TenHoTruoc`, dòng 44; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `LayDanhSachDocGia`, dòng 18; [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `ChuaChuoi`, dòng 31.

<a id="TN28"></a>
### TN28 — Danh sách thẻ khóa: lọc trước hay sắp trước?

**Tấn · P3 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN28).

**Trả lời ngắn:** Lọc trước rồi sắp k cần duyệt R và O(k log k) phép so, thay vì sắp R; bộ nhớ thực cấp phụ thuộc cách dựng view, không tự thành O(k) nếu vẫn cấp R.

**Giải thích và bảo vệ cách làm:**

Thẻ khóa có thể còn nghĩa vụ, không xóa node hay lịch sử khi lọc. Tổng là k người thỏa điều kiện, không số dòng văn bản.

Giữ comparator tên–họ–mã; test k=0, k=R và khóa do mất/thủ công để thấy cùng trạng thái nhưng lịch sử khác.

**Đáp câu phụ 1:** Không; vẫn sort R, còn chi phí lọc. Lợi ích phụ thuộc độ chọn lọc, không phải mọi dữ liệu.

**Sai lầm dễ mắc:** Một tối ưu thắng với 200/100000 sẽ thắng tuyệt đối.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Thiết kế view trên bản sao, đối chiếu tập mã và thứ tự với quét lọc tham chiếu; đo số phép so.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InDocGiaTheoTenHo`, dòng 119; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `LayDanhSachDocGia`, dòng 18; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `TenHoTruoc`, dòng 44.

<a id="TN33"></a>
### TN33 — Đổi thuật toán báo cáo thể loại khi gần 10.000 đầu

**Tấn · P3 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN33).

**Trả lời ngắn:** Giữ thể loại rồi tên chuẩn hóa rồi ISBN; hoán đổi con trỏ view, không kho gốc. Heap giảm cận phép so từ O(D²) xuống O(D log D).

**Giải thích và bảo vệ cách làm:**

Tạo khóa chuẩn hóa tạm có thể giảm chi phí lặp theo độ dài chuỗi, đổi lại bộ nhớ/cấp phát bổ sung; nếu lỗi trước báo cáo, dữ liệu gốc vẫn phải nguyên.

Cần đo tạo view /khóa/ sort /xuất riêng; không tuyên bố toàn màn hình nhanh tương ứng chỉ từ cận sort.

**Đáp câu phụ 1:** Không; cần đo toàn pipeline và từng pha để biết phần nào chi phối.

**Sai lầm dễ mắc:** Cải thiện cận một pha đồng nghĩa tốc độ toàn luồng tăng cùng tỷ lệ.

**Cách kiểm chứng:** Đề xuất kiểm chứng: So kết quả đầy đủ trên loại đảo, đã tăng, nhiều hòa, 0/1 đầu; kiểm thêm đầu mới sau báo cáo vẫn đúng thứ tự kho.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `InDauSachTheoTheLoai`, dòng 98; [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `KhoaSoSanh`, dòng 22; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `SapXepHeap`, dòng 88.

<a id="TN36"></a>
### TN36 — Tổng theo thể loại không được lấy từ số dòng UI

**Tấn · P3 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN36).

**Trả lời ngắn:** Tổng đầu đếm phần tử view, tổng bản duyệt dms, sẵn sàng lọc trạng thái 0; ba số không suy trực tiếp từ số dòng text.

**Giải thích và bảo vệ cách làm:**

Chốt nhóm khi khóa thể loại đổi và sau vòng lặp cho nhóm cuối; dùng cùng SoSanhChuoi để nhận nhóm, không theo byte nhãn.

Phân trang là trình bày, không chia lại phạm vi thống kê; tổng phải độc lập chiều cao terminal và tiêu đề lặp.

**Đáp câu phụ 1:** Nhóm cuối không gặp lần chuyển loại tiếp nên không được chốt, cần flush sau vòng. Tổng toàn kho không đủ tái dựng từng nhóm nếu nhiều nhóm hoặc lọc; kiểm riêng đầu 0 cuốn và số bản sẵn sàng từ trạng thái 0.

**Sai lầm dễ mắc:** Đầu sách và cuốn là cùng đơn vị đếm.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Kiểm một nhóm, nhiều nhóm, nhóm cuối 0 cuốn; resize và đổi trang không làm tổng khác.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `InDauSachTheoTheLoai`, dòng 98; [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `DemCuonSach`, dòng 102; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `HienThiPhanTrang`, dòng 450.

<a id="TN46"></a>
### TN46 — Đổi tên sách có làm 'phiếu cũ' đổi chữ không?

**Tấn · P3 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN46).

**Trả lời ngắn:** h tra chủ cuốn hiện tại rồi lấy tenSach, nên sau mở rộng đổi tên sẽ hiện tên mới; MuonTra không có snapshot tên.

**Giải thích và bảo vệ cách làm:**

Không thể tái dựng tên cũ từ mã/ngày/trạng thái nếu đã ghi đè tên và không lưu lịch sử đổi. Renderer không tạo lại thông tin đã mất.

Bản hiện chưa có đổi tên hay phiếu snapshot. Muốn lưu tên tại giao dịch phải chốt mục đích và trường/hồ sơ bổ sung được phép, không tự thêm vào đề.

**Đáp câu phụ 1:** Có thể vì tên là khóa phụ phá hòa. Cần tách bất biến số lượt theo ISBN với thứ tự hiển thị; test chỉ tổng top sẽ bỏ sót một thay đổi thứ hạng hợp lệ theo tên mới.

**Sai lầm dễ mắc:** Thông tin hiển thị thay là số giao dịch thay.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Vẽ đường dữ liệu maSach→cuốn→đầu→tên, nêu hai đặc tả 'thông tin hiện tại'/'bản in lúc mượn' và test khác nhau.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — `MuonTra`, dòng 20; [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `LietKeSachDangMuon`, dòng 21; [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `TimCuonSachToanCuc`, dòng 30, 51.

<a id="TN71"></a>
### TN71 — Phân trang không phải đọc lười

**Tấn · P3 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN71).

**Trả lời ngắn:** Caller đã tạo toàn báo cáo bằng ostringstream, truyền chuỗi kết quả; hàm đổi sang wstring all và lập chỉ mục starts cho mọi dòng. Chỉ vẽ 13 dòng giảm chi phí vẽ mỗi khung, không xóa bộ đệm và công việc đã làm trước đó.

**Giải thích và bảo vệ cách làm:**

Chỉ giữ 13 dòng đầu làm mất dữ liệu cho trang sau/End; cắt trước khi lọc hoặc sắp toàn tập còn có thể chọn sai kết quả. Cần tính bộ nhớ theo tổng ký tự và số dòng, không theo chiều cao màn hình.

Muốn đọc theo trang cần giao diện cung cấp bản ghi/trang, định nghĩa thứ tự và giữ phiên dữ liệu nhất quán giữa các trang. Đánh đổi truy cập ngẫu nhiên, tính lại, cache hoặc chỉ mục; không thể đạt chỉ bằng đổi vòng vẽ.

**Đáp câu phụ 1:** Không từ giao diện string hiện tại. Cần index/nguồn truy vấn có thứ tự và cơ chế lấy cuối, hoặc duyệt/sắp đủ để biết kết quả. Đọc lười tiết kiệm buffer nhưng không tự xóa chi phí xác định thứ tự hay khả năng nhảy ngẫu nhiên.

**Sai lầm dễ mắc:** Phân trang hiện tại là query từng trang từ cấu trúc nguồn.

**Cách kiểm chứng:** Đề xuất kiểm chứng: So dữ liệu ít/nhiều dòng cùng chiều cao; kiểm PgDn, End và thứ tự toàn bộ kết quả trên thiết kế mới. Đây là đề xuất trên bản sao, chưa triển khai đọc lười.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `HienThiPhanTrang`, dòng 450; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `ManHinhMuonTra`, dòng 206.

<a id="TN82"></a>
### TN82 — RAM nạp xong nhưng gán path ném ngoại lệ

**Tấn · P3 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN82).

**Trả lời ngắn:** Không có rollback UI cho trường hợp đó: DocFile đã đổi RAM, còn path có thể vẫn cũ khi phép gán ném lỗi.

**Giải thích và bảo vệ cách làm:**

Đây là giới hạn ngoại lệ ở lớp điều phối, khác bảo đảm DocFile khi chính nó thất bại. Không nói mọi lỗi nạp đều giữ cả phiên cũ nếu lỗi xảy ra sau commit.

**Đáp câu phụ 1:** Giảm điểm cấp phát sau commit; cần thiết kế chuyển cả context bằng các thao tác không ném và kiểm các thành phần khác. Đây là đề xuất sửa trên bản sao.

**Sai lầm dễ mắc:** Bảo đảm mạnh của một hàm tự bao trùm mọi thao tác caller sau nó.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Truy vết ranh giới commit; muốn thử cần fault injection có kiểm soát, chưa coi là ca đã chạy.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `DocFile`, dòng 349.

<a id="TN94"></a>
### TN94 — Cảnh báo có thay đổi chưa lưu

**Tấn · P3 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN94).

**Trả lời ngắn:** Mở form rồi hủy không đổi dữ liệu nên không nên báo bẩn vì riêng việc mở. F5 có thể lưu thất bại, không được xóa cờ sớm.

**Giải thích và bảo vệ cách làm:**

Cờ phải đổi theo giao dịch thành công/lưu hoặc nạp thành công; báo cáo chỉ đọc không làm bẩn. Đây là trạng thái UI hỗ trợ, cần quản lý nhất quán.

**Đáp câu phụ 1:** Cờ có thay đổi từ lần lưu là bảo thủ và có thể vẫn true dù dữ liệu trở lại như cũ. Nếu đặc tả muốn đúng chênh lệch snapshot thì phải so dữ liệu/version có cơ chế hoàn tác tương ứng, trả thêm chi phí. Hai định nghĩa dirty khác nhau cần được chốt.

**Sai lầm dễ mắc:** Nhấn nút hoặc xem được báo cáo là đã ghi dữ liệu.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Test hủy, nhập sai, thêm thành công, lưu lỗi, lưu được và nạp file mới.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `BieuMau`, dòng 334; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `LuuFile`, dòng 353.

<a id="TN95"></a>
### TN95 — Đọc phím lỗi nằm ngoài try của thao tác

**Tấn · P3 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN95).

**Trả lời ngắn:** Lời gọi ChonMenu nằm trước try của từng thao tác; ngoại lệ đi tới catch ngoài ở main và có thể kết thúc chương trình với mã 1.

**Giải thích và bảo vệ cách làm:**

Không có tự lưu trong đường lỗi đó, nên thay đổi chưa ghi có thể mất. RAII dọn bộ nhớ/console không đồng nghĩa lưu dữ liệu nghiệp vụ.

**Đáp câu phụ 1:** Chưa; có thể tạo vòng báo lỗi hoặc lỗi tiếp trong ThongBao. Phải chốt khả năng tái tạo input, chuyển chế độ hoặc thoát có thông tin; vị trí catch chỉ đổi nơi bắt, không sửa tài nguyên hay tự lưu RAM.

**Sai lầm dễ mắc:** Dọn tài nguyên thành công là đã bảo toàn mọi thay đổi nghiệp vụ.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Truy stack gọi và phạm vi hai try; nếu thử cần giả lập lỗi input, không nhận là ca runtime đã chạy.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `DocPhimConsole`, dòng 124; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `main`, dòng 585.

<a id="TN100"></a>
### TN100 — Thầy hỏi phần mượn dù mình phụ trách menu

**Tấn · P3 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#TN100).

**Trả lời ngắn:** Luồng đi ChayUngDung→ManHinhMuonTra→MuonSach, có thay lịch sử và trạng thái cuốn trong RAM; LuuFile là bước khác.

**Giải thích và bảo vệ cách làm:**

Lưu thất bại không tự hoàn tác mượn đã thành công trong RAM, nhưng đĩa chưa phản ánh giao dịch mới. Cần giải thích cả quyền mượn, commit RAM, lưu đĩa và lựa chọn tiếp của người dùng.

Nhánh choice=0 chỉ return sau khi LuuFile thành công; khi lưu thất bại vẫn quay vòng menu và còn xem được dữ liệu RAM. Đóng cửa sổ hoặc xác nhận thoát không lưu sau đó có thể bỏ các thay đổi chưa ghi.

**Đáp câu phụ 1:** Không nếu chưa có lần lưu thành công; đó là bỏ thay đổi RAM. File cũ không tự nhận lượt mới.

**Sai lầm dễ mắc:** Mượn thành công trước đó luôn xuất hiện sau lần khởi động kế.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Truy vết một mã thẻ/cuốn xuyên module, phân biệt 'mượn thành công' với 'đã lưu bền vào file'.

**Ca liên quan đã chạy 17/10 (không tái chạy đợt này):** [save_locked_keeps_ram_file](ThamKhao/KIEM_CHUNG_RUNTIME.md#save_locked_keeps_ram_file).

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `ManHinhMuonTra`, dòng 206; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `LuuFile`, dòng 353.


<a id="chung"></a>
## Cả nhóm — 25 đáp án

<a id="CH01"></a>
### CH01 — Sao chép thư viện để chạy thử

**Cả nhóm · P1 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#CH01).

**Trả lời ngắn:** Copy constructor và phép gán copy đã bị xóa nên thao tác copy không biên dịch.

**Giải thích và bảo vệ cách làm:**

Copy mặc định các con trỏ chỉ tạo hai chủ sở hữu cùng vùng nhớ; thay đổi qua một bản ảnh hưởng bản kia, hủy dễ giải phóng hai lần.

Muốn bản thử độc lập phải dựng bản dữ liệu sâu có sở hữu riêng; không bỏ cấm copy để chữa triệu chứng.

**Đáp câu phụ 1:** Không; swap trao đổi ownership, không clone. Muốn hai bản độc lập phải sao chép sâu qua cơ chế có kiểm.

**Sai lầm dễ mắc:** Swap tạo bản sao hoặc nhân đôi quyền sở hữu.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Thử lỗi biên dịch trên bản sao; vẽ hai đường con trỏ cùng trỏ một node, không chạy cố tình double-delete.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — `ThuVien`, dòng 30; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `HuyThuVien`, dòng 335.

<a id="GH01"></a>
### GH01 — Ghép ba module: ai được quyền thay trạng thái cuốn?

**Cả nhóm · P1 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#GH01).

**Trả lời ngắn:** Tra cứu chỉ tìm đối tượng, không được đổi trạng thái. Nếu đổi trước kiểm quyền, giao dịch bị từ chối nhưng cuốn đã bị giữ mà không có phiếu.

**Giải thích và bảo vệ cách làm:**

MuonSach là nơi phối hợp các điều kiện và commit phiếu–cuốn sau chuẩn bị; UI chỉ thông báo theo kết quả, không tự đặt lại trạng thái để che lỗi.

Hợp đồng giữa module phải nêu tác dụng phụ, sở hữu con trỏ và thời điểm thành công; kiểm tích hợp cần so cả cuốn/lịch sử sau lệnh thất bại.

Ở biến thể chỉ gọi tìm bên trong MuonSach, kiểm thẻ khóa diễn ra trước tra cuốn nên không tới mutation. Ca làm hỏng trạng thái trong câu chính phụ thuộc lời gọi tìm sớm của caller đã nêu rõ, không phải hành vi sản phẩm hiện tại.

**Đáp câu phụ 1:** Không; sẽ xóa trạng thái của giao dịch hợp lệ khác. Chỉ API đúng mới quản mutation, UI không rollback bằng phỏng đoán.

**Sai lầm dễ mắc:** Caller cứ reset dữ liệu về mặc định khi API báo lỗi.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Dùng thẻ khóa xin cuốn rảnh rồi người hợp lệ xin cùng cuốn; sau lần lỗi cuốn phải vẫn rảnh và không có phiếu mới.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `TimCuonSachToanCuc`, dòng 30, 51; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `ManHinhMuonTra`, dòng 206.

<a id="CH02"></a>
### CH02 — Con trỏ cũ sau khi nạp file

**Cả nhóm · P1 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#CH02).

**Trả lời ngắn:** Nạp thành công hoán đổi bộ dữ liệu; biến tạm nhận dữ liệu cũ và destructor hủy nó. p cũ trở thành con trỏ treo dù mã 12 vẫn tồn tại trong bộ mới.

**Giải thích và bảo vệ cách làm:**

Cần tìm lại theo mã sau nạp thành công; cùng giá trị khóa không có nghĩa cùng địa chỉ hay cùng đối tượng.

Nạp thất bại trước hoán đổi giữ bộ dữ liệu cũ, nên p vẫn còn hiệu lực nếu không có thao tác xóa khác.

**Đáp câu phụ 1:** Không nếu hai kho độc lập; chỉ cùng giá trị mã trong phiên mới. Context nguồn cần được giữ rõ.

**Sai lầm dễ mắc:** Cùng mã xuyên hai file luôn là cùng danh tính ngoài đời.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Đối chiếu địa chỉ và tra lại theo mã; không dereference con trỏ cũ sau nạp thành công.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `DocNoiBo`, dòng 222; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `HoanDoiThuVien`, dòng 338.

<a id="GH02"></a>
### GH02 — File thay an toàn có ngăn hai người mượn trùng?

**Cả nhóm · P1 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#GH02).

**Trả lời ngắn:** Có thể cả hai thành công vì mỗi tiến trình kiểm RAM riêng; lần lưu sau ghi ảnh chụp của Q và làm mất cập nhật của P.

**Giải thích và bảo vệ cách làm:**

Thư mục tạm riêng tránh va tên và bước thay tránh ghi dở trực tiếp; chúng không cung cấp khóa nghiệp vụ hay kiểm phiên bản.

Bản hiện tại chỉ hỗ trợ một phiên sửa theo thứ tự. Nếu cần đa tiến trình phải xác định chính sách phối hợp mới và kiểm riêng.

**Đáp câu phụ 1:** Không; cần cơ chế phối hợp có phạm vi xuyên tiến trình và kiểm version cùng quyền sở hữu ghi. Khóa phải phủ đọc trạng thái mới–kiểm–ghi hoặc giao dịch thích hợp.

**Sai lầm dễ mắc:** Khóa trong bộ nhớ một tiến trình bảo vệ được mọi chương trình dùng cùng file.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Chạy hai phiên với bản sao cùng file; nạp trước, lưu P rồi Q, mở lại và đối chiếu. Đây là kịch bản đề xuất, chưa tự coi đã chạy.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `LuuNoiBo`, dòng 290; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114.

<a id="CH03"></a>
### CH03 — Hàm chỉ xem vẫn sửa được sách?

**Cả nhóm · P1 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#CH03).

**Trả lời ngắn:** Const trên đối tượng chứa con trỏ không tự làm đối tượng được trỏ tới thành const; đây là const nông.

**Giải thích và bảo vệ cách làm:**

Đổi tên tại chỗ có thể phá thứ tự mảng, làm quyết định tìm vị trí chèn bằng tìm nhị phân sai; tìm ISBN tuyến tính vẫn có thể thấy mã.

Dùng con trỏ const khi đọc và giữ hợp đồng không sửa; cần review/test trạng thái trước–sau chứ không chỉ nhìn chữ const.

**Đáp câu phụ 1:** Không; tên/type bề ngoài không thay tác dụng phụ. Sửa đối tượng thực sự const còn có thể là hành vi không xác định.

**Sai lầm dễ mắc:** Cast bỏ const là cách hợp lệ để mọi hàm đọc được tối ưu bằng mutation.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Trên bản sao, chụp dữ liệu trước/sau các hàm b/d/e/h/i/j; kiểm thứ tự tên sau mỗi lần.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — `DanhSachDauSach`, dòng 19; [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `TimViTriChenTheoTen`, dòng 43.

<a id="GH03"></a>
### GH03 — File đứt giữa lịch sử độc giả thứ hai

**Cả nhóm · P1 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#GH03).

**Trả lời ngắn:** DocNoiBo dựng ThuVien tmp; nút đọc xong được gắn quyền sở hữu ngay, độc giả tạm nối nhánh phải trước khi dựng BST.

**Giải thích và bảo vệ cách làm:**

Return lỗi hủy tmp cùng danh sách con; unique_ptr giữ đối tượng đang chuẩn bị nhưng chưa chuyển sở hữu.

A chỉ thay sau kiểm toàn vẹn và HoanDoiThuVien. Thiếu dòng hoặc trùng mã đều không đến bước swap; không suy thành đã kiểm leak bằng công cụ.

**Đáp câu phụ 1:** Chưa; swap chỉ sau toàn bộ kiểm. Bộ tạm được hủy theo ownership, còn A giữ nguyên.

**Sai lầm dễ mắc:** Đọc hết/sắp xong nghĩa đã commit nạp.

**Cách kiểm chứng:** Đề xuất kiểm chứng: So ảnh chụp A trước/sau hai file lỗi; dùng công cụ phát hiện bộ nhớ nếu kiểm rò, không kết luận chỉ từ việc RAM còn đúng.

**Ca liên quan đã chạy 17/10 (không tái chạy đợt này):** [load_failure_keeps_ram](ThamKhao/KIEM_CHUNG_RUNTIME.md#load_failure_keeps_ram).

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `DocNoiBo`, dòng 222; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `ThuVien::~ThuVien`, dòng 334; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `HuyCayDocGia`, dòng 103.

<a id="CH04"></a>
### CH04 — Con trỏ kép ở danh sách rỗng

**Cả nhóm · P1 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#CH04).

**Trả lời ngắn:** Con trỏ kép đang trỏ vào ô chứa head hoặc next cần sửa; gán qua ô đó mới nối node vào cấu trúc.

**Giải thích và bảo vệ cách làm:**

Chỉ gán bản sao con trỏ cục bộ không cập nhật dms/next của thư viện; node có thể bị mất đường sở hữu.

Trường hợp rỗng và không rỗng dùng cùng cơ chế; đổi sang một con trỏ vẫn làm được nhưng phải xử lý đúng nơi ghi liên kết.

**Đáp câu phụ 1:** Không; tail là địa chỉ ô bên trong node cũ đã bị hủy, không một định danh bền. Cần tìm lại đầu và ô cuối trong bộ mới. Hợp đồng địa chỉ ô cũng phụ thuộc lifetime như con trỏ node.

**Sai lầm dễ mắc:** Địa chỉ ô và giá trị con trỏ chứa trong ô là một.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Truy vết địa chỉ dms, tail và *tail cho 0,1,2 node; đếm lại từ head sau thêm.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `ThemCuonSach`, dòng 74.

<a id="GH04"></a>
### GH04 — Từng module nhìn đúng nhưng ghép lại mâu thuẫn

**Cả nhóm · P1 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#GH04).

**Trả lời ngắn:** Với từng cuốn, trạng thái đang mượn phải tương ứng đúng một lượt mở; mâu thuẫn trạng thái–số lượt hoặc hai lượt mở đều bị từ chối.

**Giải thích và bảo vệ cách làm:**

Giới hạn hiện tại đếm lượt đang mượn của từng độc giả; tổng lịch sử đã đóng không bị giới hạn bằng ba.

Không tự chọn người đang giữ thật bằng cách sửa một cờ; dữ liệu không đủ để quyết định. Nạp lỗi giữ toàn bộ RAM cũ.

**Đáp câu phụ 1:** Không; dữ liệu mâu thuẫn không chỉ ra phiếu nào đúng. Cần nguồn đối soát, không chữa bằng cách làm count đẹp.

**Sai lầm dễ mắc:** Validator phát hiện được lỗi thì cũng có đủ dữ liệu tự quyết định cách sửa.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Dùng hai file lỗi chỉ khác quan hệ X; kiểm báo lỗi và ảnh chụp RAM trước/sau, rồi kiểm file hợp lệ có một lượt mở.

**Ca liên quan đã chạy 17/10 (không tái chạy đợt này):** [startup_invalid_no_overwrite](ThamKhao/KIEM_CHUNG_RUNTIME.md#startup_invalid_no_overwrite).

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114.

<a id="CH05"></a>
### CH05 — Ngoại lệ sau commit có nghĩa giao dịch đã thất bại không?

**Cả nhóm · P1 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#CH05).

**Trả lời ngắn:** Sau commit nghiệp vụ, phiếu/cuốn đã đổi dù thông báo thất bại; không được suy mọi exception trong cả thao tác nghĩa dữ liệu giữ nguyên.

**Giải thích và bảo vệ cách làm:**

Gọi lại ngay cùng cuốn bị trạng thái đang mượn chặn, nhưng không có requestID để chứng minh đó là cùng yêu cầu. Cần đọc trạng thái thật và báo đúng mốc đã hoàn tất.

Lưu file là bước khác; commit RAM không chứng minh bền vững trên đĩa. Bảo đảm mạnh trước commit của MuonSach không bao trùm mọi xử lý sau hàm.

**Đáp câu phụ 1:** Không; phải xác nhận LuuFile thành công riêng. Kiểm RAM chỉ giải đáp commit nghiệp vụ.

**Sai lầm dễ mắc:** Phục hồi thông báo thành công đồng nghĩa phục hồi độ bền trên đĩa.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Truy điểm lỗi giả lập trước cấp phát, sau commit và khi lưu; ghi rõ chỉ truy vết nếu chưa có harness tiêm lỗi.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `ManHinhMuonTra`, dòng 206; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ThongBao`, dòng 444; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507.

<a id="GH05"></a>
### GH05 — Thất bại sau khi đã ghi file tạm

**Cả nhóm · P1 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#GH05).

**Trả lời ngắn:** Các lỗi trước thay đích giữ file cũ; LuuFile không sửa RAM. Đối tượng quản lý phạm vi thử dọn vùng tạm; lỗi dọn bị bỏ qua nên không bảo đảm mọi môi trường đều xóa sạch tạm.

**Giải thích và bảo vệ cách làm:**

Sau ghi, flush, đóng và đọc lại thành công, Windows dùng MoveFileExW thay đích; ngoài Windows dùng filesystem::rename.

Không có cam kết chịu mọi mất điện hoặc khóa nhiều tiến trình. Một ca lỗi thay file đã kiểm chỉ chứng minh đúng ca đó.

**Đáp câu phụ 1:** Không; tính hợp lệ không tương đương bằng dữ liệu nguồn. Cần kiểm round-trip ngữ nghĩa nếu muốn phát hiện mất nội dung.

**Sai lầm dễ mắc:** Kiểm file mới hợp lệ là đã chứng minh sao lưu không mất dữ liệu.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Đối chiếu byte file đích và dữ liệu RAM khi cố ý làm bước thay thất bại; tách lỗi đã thực thi với lỗi mới chỉ phân tích.

**Ca liên quan đã chạy 17/10 (không tái chạy đợt này):** [save_locked_keeps_ram_file](ThamKhao/KIEM_CHUNG_RUNTIME.md#save_locked_keeps_ram_file).

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `LuuNoiBo`, dòng 290; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `LuuFile`, dòng 353.

<a id="CH07"></a>
### CH07 — Quên hoặc dùng sai release

**Cả nhóm · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#CH07).

**Trả lời ngắn:** get không chuyển sở hữu; khi unique_ptr hủy, danh sách giữ con trỏ treo.

**Giải thích và bảo vệ cách làm:**

release sớm bỏ người quản lý node; nếu chưa có cấu trúc nhận và quay về vì lỗi, node có thể rò bộ nhớ.

Chuẩn bị thành công rồi nối bằng release để luôn có đúng một bên chịu trách nhiệm hủy; các view chỉ mượn con trỏ.

**Đáp câu phụ 1:** Chỉ an toàn khi ngay sau nối chắc chắn chuyển ownership mà không thoát/throw và chưa có hai bên dọn cùng node. Một phép tạo thông báo có thể ném giữa hai dòng làm unique_ptr hủy node trong khi nguồn đã giữ địa chỉ. Nối bằng release ở bước commit làm ranh giới rõ hơn.

**Sai lầm dễ mắc:** Mọi raw pointer do release trả đều cần caller delete ngay.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Vẽ chủ sở hữu node ở từng dòng và mọi đường return; không chạy truy cập con trỏ treo.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `ThemCuonSach`, dòng 74; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114.

<a id="CH08"></a>
### CH08 — Xóa bảng kết quả làm hỏng thư viện

**Cả nhóm · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#CH08).

**Trả lời ngắn:** Các phần tử view mượn node BST; delete từng node phá cấu trúc và có thể dẫn đến dùng vùng đã hủy hoặc hủy hai lần.

**Giải thích và bảo vệ cách làm:**

Chỉ vùng chứa danh sách con trỏ tạm được giải phóng khi hết hàm; node và lịch sử vẫn thuộc thư viện.

HuyCayDocGia hủy danh sách lịch sử của mỗi node rồi hủy node; phân biệt delete đối tượng với delete[] mảng.

**Đáp câu phụ 1:** Không; cả hai vẫn mượn node nguồn. Chỉ mỗi vùng mảng có ownership riêng.

**Sai lầm dễ mắc:** Số lượng view tương ứng số lần cần delete node.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Sơ đồ sở hữu trước/sau in; thử tìm và lưu sau nhiều lần liệt kê trên bản gốc đúng.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InDocGiaTheoTenHo`, dòng 119; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `HuyCayDocGia`, dòng 103.

<a id="GH08"></a>
### GH08 — Dữ liệu ngày không đủ để khẳng định thứ tự thật

**Cả nhóm · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#GH08).

**Trả lời ngắn:** Cùng ngày có thể xếp lượt đã trả trước lượt mất, nên có thứ tự khả thi; cuốn và thẻ phải khớp quy tắc mất.

**Giải thích và bảo vệ cách làm:**

Mượn ngày sau khi đã báo mất bị từ chối: lượt đứng trước cùng cuốn phải là đã trả và kết thúc không sau lượt kế tiếp.

Loader sắp theo ngày, thời điểm kết thúc và khóa phụ; v1 không lưu giờ nên không chứng minh thứ tự thật từ vị trí dòng.

**Đáp câu phụ 1:** Không; thứ tự dòng chỉ là serialization, không phải bằng chứng timestamp thực.

**Sai lầm dễ mắc:** Vị trí trong file là thời điểm thật của sự kiện.

**Cách kiểm chứng:** Đề xuất kiểm chứng: So file cùng ngày, file sau ngày mất và file đổi vị trí các bản ghi; nêu rõ kết luận khả thi khác lịch sử thực tế.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `KiemTraNoiBo`, dòng 102; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `KiemTraDongThoiGian`, dòng 25.

<a id="CH09"></a>
### CH09 — Kiểm tràn sau khi đã tràn

**Cả nhóm · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#CH09).

**Trả lời ngắn:** Tràn số nguyên có dấu xảy ra trước phép so thì không có bảo đảm kết quả; không được dựa vào chuyện quay về số âm.

**Giải thích và bảo vệ cách làm:**

Hiện tại kiểm khả năng nhân/cộng trong giới hạn trước khi làm; value chỉ gán sau khi toàn chuỗi hợp lệ.

Số âm, khoảng trắng nội dung, ký tự dư không hợp lệ cho parser này; caller quyết định có chuẩn hóa khoảng trắng bên ngoài không.

**Đáp câu phụ 1:** Không theo phép tích lũy giá trị, nhưng vẫn phải quét toàn chuỗi và kiểm miền/độ dài ở tầng thích hợp. Độ dài input khác giá trị số.

**Sai lầm dễ mắc:** Mọi chuỗi dài đều overflow hoặc overflow được phát hiện bằng kết quả âm.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Thử max int, max+1, chuỗi rất dài và output mang giá trị cũ để xác nhận thất bại không gán output.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `DocSoNguyen`, dòng 65.

<a id="GH09"></a>
### GH09 — Chạy riêng file main rồi gặp lỗi linker

**Cả nhóm · P2 · Hiện tại**. [Đọc lại câu hỏi](01_CAU_HOI.md#GH09).

**Trả lời ngắn:** Biên dịch và liên kết cả tám .cpp, dùng chung header; project chỉ giữ một main sản phẩm. Khai báo hàm không thay định nghĩa ở module khác.

**Giải thích và bảo vệ cách làm:**

Compiler và thư viện cần hỗ trợ C++17 với filesystem; Windows liên kết shell32 cho CommandLineToArgvW.

Chạy Console Application bằng Dev-C++ hoặc exe trực tiếp; không có web server. Build.ps1 là cấu hình đối chiếu, chưa chứng minh mọi bản Dev-C++ đều tương thích.

**Đáp câu phụ 1:** Không; cần link đơn vị dịch chứa định nghĩa, và kiểm signature khớp. Prototype không sinh thân hàm.

**Sai lầm dễ mắc:** Lỗi linker thiếu định nghĩa được sửa bằng thêm khai báo.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Clean build cả project trên máy nhóm; chạy --help, nạp dữ liệu và lưu lại. Ghi phiên bản compiler cùng lỗi thật nếu còn.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `main`, dòng 585; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `LuuNoiBo`, dòng 290; [00_KhaiBaoChung.h](ThamKhao/MaNguon/00_KhaiBaoChung.h) — `MuonSach`, dòng 108.

<a id="CH10"></a>
### CH10 — Chuẩn hóa giúp dữ liệu sai đi qua

**Cả nhóm · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#CH10).

**Trả lời ngắn:** Chuẩn hóa gom tab/newline thành dấu cách, có thể làm dữ liệu cấm bị âm thầm chấp nhận dưới nội dung khác.

**Giải thích và bảo vệ cách làm:**

API hiện kiểm raw trước rồi mới chuẩn hóa khoảng trắng thường; validator file kiểm theo định dạng v1.

Hàm tiện ích có thể phục vụ nhiều ngữ cảnh; hợp đồng của điểm nhận dữ liệu quyết định khi nào được dùng.

**Đáp câu phụ 1:** Không; query tạm và dữ liệu bền có chính sách khác nhau. Chốt hợp đồng từng điểm vào.

**Sai lầm dễ mắc:** Helper chuẩn hóa quyết định chính sách chấp nhận của mọi caller.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Gọi API với LF/tab/pipe và tên có khoảng trắng thường; chụp số node và dữ liệu trước–sau.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `ChuanHoaChuoi`, dòng 14; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `ThemDocGia`, dòng 64.

<a id="CH11"></a>
### CH11 — Bool, output và exception: hợp đồng có thể bị hiểu sai khi ghép

**Cả nhóm · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#CH11).

**Trả lời ngắn:** Không ném không đồng nghĩa true: validation có thể trả false và output cũ còn nguyên. Ngược lại caller phải xử lý ngoại lệ ở hàm có đường cấp phát không bắt tại chỗ.

**Giải thích và bảo vệ cách làm:**

Có thể chuẩn hóa result thành công/mã/lỗi ở adapter hoặc API và quy định output chỉ dùng khi thành công; cập nhật mọi caller và test cả false /throw.

Thông báo lỗi cũng có thể cấp phát; bảo đảm exception tuyệt đối cần phạm vi thực tế rõ ràng. Không nhận mọi ngoại lệ là thiếu bộ nhớ hoặc mọi catch là rollback.

**Đáp câu phụ 1:** Không; giá trị đó có thể là kết quả cũ. Chỉ công bố mã mới khi thành công đã xác nhận.

**Sai lầm dễ mắc:** Không exception là đủ để dùng mọi output như dữ liệu mới.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Lập bảng các đường success, false, throw từ code thật; kiểm trạng thái và output, không chỉ kiểm chuỗi thông báo.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `ThemCuonSach`, dòng 74; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `ThemDocGia`, dòng 64; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507.

<a id="CH12"></a>
### CH12 — Comparator có chu trình: sort có thể sửa giúp không?

**Cả nhóm · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#CH12).

**Trả lời ngắn:** A<B<C nhưng C<A tạo chu trình, trái tính bắc cầu cần cho quan hệ thứ tự. Thuật toán sắp không tự giải quyết một đặc tả không nhất quán.

**Giải thích và bảo vệ cách làm:**

Khóa nhiều tầng hiện tại so tiêu chí đầu khác nhau rồi phá hòa bằng định danh, cho quan hệ xác định trên dữ liệu hợp lệ.

Comparator phụ thuộc số lần gọi hoặc sửa dữ liệu làm kết quả không ổn định theo đầu vào/thuật toán. Cần tách lịch luân phiên khỏi sort, kiểm tính bất phản xạ, bất đối xứng và bắc cầu bằng bộ ba.

**Đáp câu phụ 1:** Không; khóa của cùng record có thể đổi giữa các phép so, nên không còn một quan hệ cố định cho lần sắp. Chốt ngày đối chiếu một lần, tính khóa trước rồi kiểm quan hệ; test so x với chính nó chưa kiểm tính nhất quán qua thời gian.

**Sai lầm dễ mắc:** Comparator chỉ cần trả một bool cho mọi cặp là đủ.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Dùng bộ ba cụ thể và mọi cặp so, sau đó kiểm comparator hiện tại với dữ liệu hòa tên; không cần chạy sort để thấy chu trình vô nghiệm.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `TenHoTruoc`, dòng 44; [02_XuLyDauSach.cpp](ThamKhao/MaNguon/02_XuLyDauSach.cpp) — `SoSanhDauSach`, dòng 9; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `DauSachXepTruoc`, dòng 107; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `SapXepHeap`, dòng 88.

<a id="GH12"></a>
### GH12 — Nạp đúng các node nhưng quên metadata: lỗi nằm ngoài BST

**Cả nhóm · P2 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#GH12).

**Trả lời ngắn:** Mốc đã cấp giữ lịch sử định danh đã xóa, không bằng max còn trong cây. Phiên nguồn cần cấp 101, không phải 81.

**Giải thích và bảo vệ cách làm:**

Nạp thay cả bộ dữ liệu phải nhận metadata của bộ mới cùng các cấu trúc; lấy max với RAM cũ tùy tiện trộn hai phiên độc lập và đổi hành vi cấp mã của file mới.

HoanDoiThuVien đổi mốc cùng root /mảng/số lượng. Test chỉ tập node hoặc inorder không đủ kiểm trạng thái toàn ứng dụng.

**Đáp câu phụ 1:** Không; NAP là thay phiên, không merge hai kho. Chuyển metadataB cùng dữ liệuB.

**Sai lầm dễ mắc:** Metadata lớn hơn luôn an toàn và được phép trộn giữa hai nguồn.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Dùng hai file độc lập có mốc khác và cây nhỏ hơn mốc; nạp lần lượt rồi thêm một người để xác nhận nguồn mốc.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `DocNoiBo`, dòng 222; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `HoanDoiThuVien`, dòng 338; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `ThemDocGia`, dòng 64.

<a id="GH13"></a>
### GH13 — Đổi b sang họ–tên–mã trên bản sao

**Cả nhóm · P3 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#GH13).

**Trả lời ngắn:** Tiêu chí đạt: nhánh b mới cho 20,10,30; khi họ và tên bằng nhau, mã tăng quyết định thứ tự.

**Giải thích và bảo vệ cách làm:**

Không đổi khóa hay vị trí nút BST để đạt hiển thị; b theo mã và tra cứu vẫn đúng.

Nhãn phản ánh quy tắc mới; dữ liệu trước/sau báo cáo giữ nguyên. Người luyện tự cài và giải thích thay đổi, không chép đáp án code.

Chỉ sửa trên bản sao khi yêu cầu thay quy tắc sắp. Nếu chỉ đổi cột hiển thị, ghép chuỗi ở renderer và giữ comparator tên–họ–mã cũ; kiểm nhãn, thứ tự và dữ liệu riêng để tránh đổi nghiệp vụ ngoài ý muốn.

**Đáp câu phụ 1:** Không; phải lấy expected theo đặc tả được chọn. Đổi bố cục giữ comparator cũ, không áp test của một yêu cầu khác.

**Sai lầm dễ mắc:** Mọi chỉnh UI đều bao gồm quyền đổi thứ tự nghiệp vụ.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Chạy ca phân biệt họ/tên, đồng họ+tên, rỗng; kiểm tìm mã và lưu–nạp sau sửa. Chỉ đánh dấu đạt khi đã thực thi.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `TenHoTruoc`, dòng 44; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InDocGiaTheoTenHo`, dòng 119; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507.

<a id="CH14"></a>
### CH14 — Đổi chỉ số sang size_t để hết warning có an toàn không?

**Cả nhóm · P3 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#CH14).

**Trả lời ngắn:** size_t không biểu diễn số âm; giảm 0 hoặc lấy độ dài nhỏ trừ lớn sẽ wrap theo số unsigned, không tạo điều kiện âm để dừng.

**Giải thích và bảo vệ cách làm:**

Vòng heap hiện dùng i>0 rồi gọi i−1, tránh cần đi qua−1. ChuaChuoi chặn b.size()>a.size() trước hiệu cận.

Đổi kiểu để hết warning không chứng minh thuật toán; chọn miền chỉ số, kiểm trước phép trừ và phân biệt cận rỗng. Không đổi sang int tùy tiện nếu kích thước có thể vượt miền.

**Đáp câu phụ 1:** Không; kích thước lớn có thể không biểu diễn được. Chọn kiểu/cận theo miền và kiểm chuyển kiểu, không đổi hàng loạt.

**Sai lầm dễ mắc:** Một kiểu chỉ số duy nhất luôn đúng cho mọi cấu trúc.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Truy n=0, 1, 2 và tên ngắn hơn từ khóa; chỉ ra lần truy cập ngoài miền bằng giấy trước khi chạy bản lỗi.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [01_HamTienIch.cpp](ThamKhao/MaNguon/01_HamTienIch.cpp) — `ChuaChuoi`, dòng 31; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `SapXepHeap`, dòng 88; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `InDocGiaTheoTenHo`, dòng 119.

<a id="GH14"></a>
### GH14 — Báo cáo đang giữ của mọi người: nối dữ liệu theo đường nào?

**Cả nhóm · P3 · Mở rộng giả định**. [Đọc lại câu hỏi](01_CAU_HOI.md#GH14).

**Trả lời ngắn:** Mỗi h tự tìm người, quét lịch sử và tra từng cuốn; mã legacy có thể quét toàn kho. Tối đa 3 lượt mở mỗi người không giới hạn H đã kết thúc.

**Giải thích và bảo vệ cách làm:**

Một view người theo mã và chỉ mục cuốn tạm có thể giảm tra lặp, đổi lại chi phí dựng/sắp chỉ mục và bộ nhớ O(C+R); phải tính thêm H và số dòng xuất.

Nếu dữ liệu nhỏ, dựng chỉ mục có thể chưa đáng; chọn dựa quy mô và số tra, không thay bốn cấu trúc lưu trữ hay thêm cache thiếu vòng đời.

Gọi h cho từng người có chi phí cấu trúc O(Rh+H+A(D+C)) trong cận xấu có mã legacy, A≤min(3R,C,H) với dữ liệu hợp lệ. Một lần inorder, dựng index cuốn có owner rồi tra nhị phân cho lượt mở đạt O(D+C log C+R+H+A log C), cộng chuỗi/đầu ra. D không tự biến mất khi nhiều đầu rỗng; buffer hiện dùng stack theo MAX_DOC_GIA, khác số ô hoạt động h.

**Đáp câu phụ 1:** Không; phải duyệt mới biết không có. Chỉ mục/cache được duy trì đúng mới có thể thay việc đó, kèm chi phí cập nhật.

**Sai lầm dễ mắc:** Không có output thì truy vấn không phải làm công việc.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Lập cận theo số lượt mở A, H, C và chiều cao cây; so output hai phương án trên mã mới/legacy và người bị khóa.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [05_XuLyMuonTra.cpp](ThamKhao/MaNguon/05_XuLyMuonTra.cpp) — `LietKeSachDangMuon`, dòng 21; [04_XuLyDocGia.cpp](ThamKhao/MaNguon/04_XuLyDocGia.cpp) — `LayDanhSachDocGia`, dòng 18; [03_XuLyCuonSach.cpp](ThamKhao/MaNguon/03_XuLyCuonSach.cpp) — `TimCuonSachToanCuc`, dòng 30, 51; [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `ChiMucCuon`, dòng 96.

<a id="CH15"></a>
### CH15 — Mọi exception đều thiếu bộ nhớ?

**Cả nhóm · P3 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#CH15).

**Trả lời ngắn:** Bắt lớp gốc rồi gán một nguyên nhân cụ thể có thể làm chẩn đoán sai; không suy mọi std::exception là bad_alloc.

**Giải thích và bảo vệ cách làm:**

Có thể phân biệt bad_alloc và lỗi khác, giữ thông điệp phù hợp; phải bảo toàn nguyên tắc chưa commit khi thao tác thất bại.

Đây là hạn chế chẩn đoán cần nhận diện, không tự khẳng định một lỗi không có repro đã xảy ra trong phiên thực.

**Đáp câu phụ 1:** Không; loại lỗi và thời điểm commit là hai điều kiện riêng. Phải chuẩn bị trước commit hoặc có rollback đúng các liên kết/trạng thái. Thông điệp thiếu bộ nhớ không cho phép khẳng định dữ liệu nguyên vẹn khi đã mutate.

**Sai lầm dễ mắc:** Thông báo nguyên nhân tự cung cấp bảo đảm rollback.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Thiết kế điểm giả lập exception trên bản sao và expected trạng thái; không chỉ kiểm nội dung thông báo.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [06_NghiepVuTongHop.cpp](ThamKhao/MaNguon/06_NghiepVuTongHop.cpp) — `MuonSach`, dòng 114; [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507.

<a id="GH15"></a>
### GH15 — Xem số liệu file trước khi thay RAM

**Cả nhóm · P3 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#GH15).

**Trả lời ngắn:** Tiêu chí đạt: chỉ hiển thị số liệu sau khi file qua kiểm toàn vẹn; chưa xác nhận thì trạng thái đang dùng không thay.

**Giải thích và bảo vệ cách làm:**

Hủy hoặc lỗi giữ nội dung RAM, path và khả năng thao tác dữ liệu cũ; xác nhận thành công mới chuyển phiên làm việc.

Không giữ con trỏ từ bộ tạm đã hủy hoặc từ dữ liệu cũ sau thay; bộ nhớ phải có chủ sở hữu rõ ở mọi nhánh.

Chỉ sửa bản sao để luyện thay đổi yêu cầu; không tự áp luồng mới vào bản nộp.

**Đáp câu phụ 1:** Phải chốt hợp đồng: commit đúng snapshot đã preview, hoặc đọc lại và yêu cầu xác nhận phiên mới. Không lặng đổi nội dung giữa preview và xác nhận.

**Sai lầm dễ mắc:** Preview một file bảo đảm đường dẫn đó không bao giờ đổi nội dung.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Kiểm file đúng rồi hủy, file thiếu dòng, file đúng rồi NAP; sau mỗi ca lưu và xác nhận đúng đường dẫn, dữ liệu dự kiến.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `DocFile`, dòng 349; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `HoanDoiThuVien`, dòng 338.

<a id="GH16"></a>
### GH16 — Lưu thành file khác nhưng chỉ đổi phiên khi thành công

**Cả nhóm · P3 · Chẩn đoán trên bản sao**. [Đọc lại câu hỏi](01_CAU_HOI.md#GH16).

**Trả lời ngắn:** Tiêu chí đạt: hủy không tạo file; lỗi không đổi path hoặc RAM; thành công tạo bản đọc lại hợp lệ và chuyển path hiện hành.

**Giải thích và bảo vệ cách làm:**

File gốc được giữ nguyên; lần lưu tiếp theo phải vào file mới chỉ khi lần lưu thành công trước đó đã chuyển path.

Nhập Unicode và khoảng trắng được xử lý như đường dẫn hiện có; thông báo không được nói thành công trước kết quả LuuFile.

Chỉ sửa bản sao để luyện thay đổi yêu cầu; không tự áp chức năng mới vào bản nộp.

**Đáp câu phụ 1:** Chưa; cần chuẩn bị đường dẫn trước và commit context không cấp phát hoặc xử lý trạng thái rõ. Tệp mới thành công chưa đủ chuyển phiên nguyên khối.

**Sai lầm dễ mắc:** LuuFile true tự bảo đảm mọi metadata UI sau nó cũng cập nhật.

**Cách kiểm chứng:** Đề xuất kiểm chứng: Kiểm hủy, đường dẫn không ghi được, đường dẫn có dấu và lần lưu tiếp theo; so byte file gốc, file mới và nạp lại dữ liệu.

**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.

**Nguồn đối chiếu:** [08_ChuongTrinhChinh.cpp](ThamKhao/MaNguon/08_ChuongTrinhChinh.cpp) — `ChayUngDung`, dòng 507; [07_LuuDocFile.cpp](ThamKhao/MaNguon/07_LuuDocFile.cpp) — `LuuFile`, dòng 353.


## Mốc ID đã gộp

Các mục sau chỉ điều hướng, không phải câu riêng.

<a id="TH201"></a>
TH201 đã gộp vào [TH52](#TH52); vị trí bổ sung dùng ID mới [TH301](#TH301).

<a id="TH234"></a>
TH234 đã gộp vào [TH21](#TH21); vị trí bổ sung dùng ID mới [TH302](#TH302).

<a id="TV204"></a>
TV204 đã gộp vào [TV12](#TV12); vị trí bổ sung dùng ID mới [TV301](#TV301).

