# Yêu cầu, nguồn đối chiếu và giả định của bản tham khảo

Ngày lập: 16/10/2026. Đây là bản triển khai **do AI viết theo yêu cầu của Thành**, dùng để chạy, đọc, tự viết lại và luyện giải thích. Nó không phải bản nhóm đã tự cài, không ghi nhận hoàn thành môn học hoặc năng lực của bất kỳ thành viên nào. Các giả định dưới đây chỉ áp dụng cho bản tham khảo này; cần đối chiếu giảng viên trước khi dùng trong bản nộp.

## 1. Nguồn và phạm vi

Đã đọc trực tiếp đoạn **3. Thư viện** trong `DeTaiMonCTDL-CLC-HK1 26-27.doc` ở workspace. Bản trích đoạn được lưu tại [NGUYEN_VAN_DE_3_THU_VIEN.txt](NGUYEN_VAN_DE_3_THU_VIEN.txt). Các đoạn của đề khác không được dùng để tự cấp quyền thay cấu trúc cho đề Thư viện.

SHA-256 của file `.doc` đã đối chiếu: `9116E9A93C14582C0173341523EACF27F9C564321AB0D3CCFE0DD382CECA093D`. Mã này xác định bản tài liệu nguồn đã đọc, không phải chứng nhận của giảng viên về các giả định triển khai.

Đối chiếu repo `ntienthanh195/do-an-thu-vien`, nhánh `main`, commit `1e2450d73bc243172ff22afb02fd73f6b3172561`, cùng các file nhóm:

- `MaNguon/00_KhaiBaoChung.h`: tên kiểu, tên trường, hằng trạng thái và bốn cấu trúc bắt buộc.
- `docs/PHAN_CONG_THEO_FILE.md`: trách nhiệm của đúng chín file.
- `docs/THAI_BAT_DAU_TU_DAY.md` và `docs/PHAN_CONG_DO_AN_THU_VIEN.md`: Thái c/e/i/j; Thành a/f/g; Tấn b/d/h và menu.
- `TaiLieu/DinhDangDuLieu.md` và `DuLieu/DuLieuMau.txt`: định dạng văn bản v1 và bộ mẫu đã có của nhóm.

Tại phiên bản được đối chiếu, header có các cấu trúc; tám file `.cpp` còn trống. Vì vậy **cài đặt hàm trong bản này là code mới do AI viết**, không được mô tả là code của nhóm đã chạy từ trước. README cũ của repo có một số mô tả trạng thái chưa cập nhật; khai báo thật và tài liệu mới hơn được ưu tiên để đối chiếu.

Đây là thư mục tham khảo riêng trong workspace. Không sửa, ghép hay xuất bản code vào repo nhóm; không dùng mã nguồn đồ án tàu hỏa làm cơ sở.

## 2. Chức năng bắt buộc và vị trí thực hiện

**a — Thẻ độc giả:** thêm, xóa, hiệu chỉnh; mã nguyên tự động không trùng mã cũ; phái chỉ Nam/Nữ; thẻ 0 khóa hoặc 1 hoạt động. Xử lý và màn hình ở `04_XuLyDocGia.cpp`.

**b — Danh sách độc giả:** chọn tăng theo mã thẻ hoặc theo tên rồi họ. Duyệt BST và tạo thứ tự hiển thị ở `04_XuLyDocGia.cpp`; không đổi khóa hoặc cấu trúc BST để in theo tên.

**c — Đầu sách và cuốn:** nhập đủ thông tin đầu sách, tự cấp mã cuốn duy nhất; mảng đầu sách luôn tăng theo tên. `02_XuLyDauSach.cpp` xử lý đầu sách; `03_XuLyCuonSach.cpp` xử lý danh mục và mã cuốn. Câu “sao cho tìm thông tin sách theo mã sách nhanh nhất” cần được hiểu trong giới hạn bốn cấu trúc, như giải thích ở mục 4.

**d — Liệt kê đầu sách:** nhóm theo thể loại, trong từng nhóm tên tăng. Dùng thứ tự tạm trong `02_XuLyDauSach.cpp`; mảng đầu sách gốc vẫn tăng theo tên.

**e — Tìm theo tên:** xuất ISBN, tên, tác giả, năm xuất bản, thể loại, các mã cuốn và trạng thái. `02_XuLyDauSach.cpp` thực hiện; có thể hiển thị thêm số trang/vị trí đã có trong đề.

**f — Mượn:** nhập thẻ và hiện sách độc giả đang mượn trước khi chọn cuốn; tối đa ba cuốn đang mượn; chặn nếu có cuốn giữ quá bảy ngày. `06_NghiepVuTongHop.cpp` kiểm tra và đồng bộ sách/lịch sử, gọi lại phần h trong `05_XuLyMuonTra.cpp`.

**g — Trả:** tìm đúng lượt đang mượn, ghi ngày trả, chuyển lượt sang đã trả và cuốn sang cho mượn được. Giao dịch ở `06_NghiepVuTongHop.cpp`.

**h — Sách đang mượn của thẻ X:** hiện mã cuốn và tên đầu sách; duyệt lịch sử trạng thái 0 trong `05_XuLyMuonTra.cpp`.

**i — Độc giả quá hạn:** duyệt cây và lịch sử, tính số ngày bằng hàm ngày chung trong module01; sắp kết quả giảm dần. `06_NghiepVuTongHop.cpp` chỉ đọc dữ liệu cho chức năng này.

**j — Top10:** tính số lượt từ lịch sử rồi chọn/sắp tối đa mười kết quả. `06_NghiepVuTongHop.cpp` không thêm bộ đếm nghiệp vụ vào `DauSach`.

**Lưu/đọc và giao diện:** yêu cầu rõ của người dùng trong lượt triển khai. Module07 đọc/ghi v1; module08 có duy nhất một `main()`, điều hướng, phân trang, khởi động/nạp/lưu/thoát.

## 3. Cấu trúc và dữ liệu được giữ

- Mảng con trỏ `DanhSachDauSach.ds`, số phần tử `soLuong`; các con trỏ sở hữu đối tượng `DauSach`. Thứ tự bắt buộc là tên tăng.
- `DauSach.dms` trỏ danh sách liên kết đơn `CuonSach`; từng cuốn có mã, trạng thái, vị trí, `next`.
- `CayDocGia.root` trỏ BST các `NutDocGia`, khóa là `thongTin.maThe`; mỗi nút có `left/right`.
- `DocGia.dsMuonTra` trỏ danh sách liên kết đơn các lượt `MuonTra`; một mã cuốn có thể xuất hiện nhiều lần qua các lượt khác nhau.

Giữ nguyên các mã trạng thái: cuốn 0 cho mượn được/1 đang mượn/2 thanh lý; lượt 0 đang mượn/1 đã trả/2 làm mất; thẻ 0 khóa/1 hoạt động. Không đồng nhất ý nghĩa số 2 của cuốn với ý nghĩa số 2 của lượt.

Phần bổ sung có lý do cụ thể:

- `ThuVien.maTheLonNhatDaCap`: metadata đã được đề xuất trong v1 của nhóm, phục vụ yêu cầu không cấp lại mã cũ sau xóa và sau khởi động lại. Không lấy nó bằng mã lớn nhất còn trong BST.
- Destructor và cấm sao chép nông `ThuVien`: quy tắc quản lý bộ nhớ, không phải thông tin nghiệp vụ.
- Các mảng tạm giữ con trỏ hoặc kết quả đếm: chỉ dùng lúc duyệt/sắp/thống kê; không thay bốn kho dữ liệu gốc, không lưu thành trường nghiệp vụ.
- Giới hạn tài nguyên trong header: `MAX_DAU_SACH=10000` giữ đề xuất nhóm; `MAX_DOC_GIA` và `MAX_BAN_GHI` là giới hạn bảo vệ của bản tham khảo, không phải giới hạn được ghi trong đề.

Không thêm đặt trước, phí phạt, hạng thẻ, hàng đợi mượn, đa luồng hoặc thuộc tính tổng lượt mượn lưu sẵn.

## 4. Các giả định phải hỏi giảng viên

**G01 — Top theo đầu sách.** Mỗi lượt mượn thành công của mọi cuốn thuộc một ISBN đóng góp một lượt. Tính cả đang mượn, đã trả và làm mất: đó đều là lượt đã xảy ra. Không tính một yêu cầu mượn bị từ chối. Đầu sách có 0 lượt không hiện; kết quả tối đa mười dòng. Đây là cách hiểu triển khai của “10 sách”, chưa được thầy xác nhận.

**G02 — Đồng hạng top.** Lượt giảm dần; bằng lượt thì tên chuẩn hóa tăng, tiếp đến ISBN tăng. Chỉ lấy tối đa mười đầu sách, không mở rộng kết quả vượt mười khi đồng hạng ở ranh giới. Cần hỏi thầy muốn đúng mười hay bao gồm toàn bộ đồng hạng.

**G03 — Quá hạn.** Dùng hiệu số ngày lịch dân sự, không đếm thời điểm trong ngày. Giữ đúng bảy ngày chưa quá hạn; giữ tám ngày là quá hạn một ngày. Chỉ lượt trạng thái đang mượn được xét. Một độc giả có nhiều cuốn quá hạn lấy **số ngày quá hạn lớn nhất**; bằng nhau thì mã thẻ tăng. Không cộng ngày quá hạn các cuốn.

**G04 — Ngày thao tác.** Màn hình dùng ngày hiện tại của lần chạy; `--date` phục vụ bộ dữ liệu/kịch bản tái lập, không phải chức năng đặt trước. Không cho ngày tương lai so với ngày thực của máy trong các thao tác nghiệp vụ. Không cho mượn ngược trước lịch sử liên quan của độc giả/cuốn; được trả rồi mượn lại cùng ngày. File lịch sử vẫn phải hợp lệ về thời gian và không chồng lấn bất khả thi. Đề không yêu cầu nhập sự kiện theo giờ.

Bộ đọc còn kiểm giới hạn ba cuốn trong lịch sử bằng quét sự kiện theo độc giả/ngày. Trong một ngày, quy ước kiểm là kết thúc các lượt từ ngày trước → xét các lượt mượn và kết thúc cùng ngày nối tiếp nhau, mỗi lượt cần một chỗ trống → bắt đầu các lượt giữ sang ngày khác hoặc đang mở. Đây là kiểm tính khả thi theo dữ liệu ngày và quy ước đó; không khôi phục thứ tự giờ thực tế. V1 không có lịch sử khóa/mở thẻ, nên bộ đọc **không chứng minh toàn bộ điều kiện cấp quyền mượn của từng thời điểm quá khứ**, bao gồm trạng thái thẻ hoặc việc từng được mượn khi có cuốn quá hạn.

**G05 — Mất sách.** Báo mất kết thúc lượt: trạng thái lượt 2, ngày trả lưu ngày báo mất; cuốn chuyển 2 để rút khỏi lưu thông, thẻ bị khóa. Đây là ánh xạ tạm trong bộ trạng thái có sẵn, **không khẳng định “làm mất” chính là “thanh lý” theo nghiệp vụ thư viện**. Không có hoàn tác mất, phục hồi cuốn hay tính tiền. Cần hỏi thầy cách biểu diễn chính xác trước khi dùng cho bản nộp.

**G06 — Xóa độc giả.** Chỉ xóa người chưa có bất kỳ lịch sử nào; người có lịch sử dùng khóa thẻ. Cách này giữ được thống kê và lịch sử trong đúng cấu trúc đề cho phép. Cần hỏi thầy có cho xóa người đã trả hết và muốn bảo toàn lịch sử ra sao. Không tự thêm kho lịch sử độc lập để giải quyết câu hỏi này.

**G07 — Cấp mã.** Mã thẻ tăng từ mốc cao nhất đã từng cấp, chỉ tăng khi thêm thành công; không giảm khi xóa. Mã cuốn mới dạng `ISBN#số_thứ_tự`, còn mã cũ `S001…` vẫn được đọc/tra. Tách ISBN từ mã mới giúp chỉ duyệt danh mục tương ứng sau khi tìm đầu sách; với mảng gốc theo tên, tìm ISBN vẫn tuyến tính. Độ phức tạp đường mã mới là O(D + Cᵢ), không phải O(log D) hoặc O(1). Mã cũ có thể cần O(D + C). Nếu thầy đòi một cận nhanh hơn, phải xin rõ quyền thêm chỉ mục phụ; bản này không tự thay cấu trúc bắt buộc.

**G08 — Tên và tìm kiếm.** Chuẩn hóa khoảng trắng; hạ chữ ASCII A–Z khi tạo khóa so sánh. Byte UTF-8 của chữ có dấu được giữ, nên `AN` và `an` tương đương, còn mọi cặp chữ hoa/thường tiếng Việt có dấu không được bảo đảm tương đương. Tìm theo chuỗi con, giữ dấu. Đây không phải bộ đối chiếu từ điển tiếng Việt và không bỏ dấu. Hiển thị giữ văn bản gốc/đã chuẩn hóa khoảng trắng.

**G09 — Các khóa phụ.** Đầu sách trùng tên dùng ISBN làm khóa phụ để kết quả xác định; độc giả tên+họ trùng dùng mã thẻ. Thể loại so bằng cùng quy tắc chuỗi. Cần hỏi thầy quy ước alphabet tiếng Việt hoặc tính ổn định khi khóa bằng nhau.

**G10 — Dữ liệu nhập.** Các trường văn bản bắt buộc không rỗng, UTF-8 hợp lệ và tối đa 512 byte; không chứa `|`, CR/LF và ký tự điều khiển làm hỏng định dạng. ISBN là mã văn bản, giữ số 0 đầu; không chứa `#` vì ký tự này dùng phân tách mã cuốn mới. Không kiểm checksum ISBN-10/13 vì mẫu nhóm dùng mã giả lập và đề chưa đòi. Số trang dương; năm xuất bản từ 1 đến năm hiện tại. Phái dùng đúng `Nam` hoặc `Nữ`. Trường 512 byte không có nghĩa 512 ký tự tiếng Việt.

**G11 — Lưu trữ.** Giữ định dạng v1 đã đề xuất: metadata, đầu sách/cuốn, độc giả/lịch sử; UTF-8; phân trường `|`; không dump struct và không lưu địa chỉ. Đọc vào bộ tạm, kiểm tra liên kết rồi thay dữ liệu. Ghi qua file tạm trước khi thay bản đích. Đây là chương trình một người dùng theo thứ tự, không có giao dịch đa tiến trình hoặc cam kết chịu mọi sự cố mất điện.

**Bổ sung kiểm định mã sau rà soát 16/10:** ISBN và mã cuốn trong danh mục/lịch sử phải bằng kết quả `ChuanHoaChuoi` của chính mã đó: không dư dấu cách đầu/cuối hoặc nhiều dấu cách liên tiếp. Một dấu cách ở giữa vẫn hợp lệ. Bộ đọc **từ chối** mã không chuẩn, không tự đổi mã vì có thể làm trùng hoặc lệch tham chiếu. Điều này giữ mã nạp từ file truy cập được qua menu vốn chuẩn hóa đầu vào; không áp thêm quy tắc này cho tên, tác giả hoặc vị trí.

**G12 — Chỉ thực hiện các thao tác được công bố.** Đề bắt buộc thêm/xóa/sửa đối với thẻ; không tự suy thành yêu cầu CRUD đầy đủ cho đầu sách/cuốn. Bản tham khảo có nhập đầu sách và thêm cuốn; không cung cấp xóa đầu sách đang bị lịch sử tham chiếu hoặc đổi mã đã phát sinh lịch sử.

## 5. Hàm thư viện và phần tự cài

Không dùng `vector`, `map`, `list`, các container STL thay cấu trúc đề; không dùng `std::sort`, `std::find`, `std::count` hoặc `string::find` để thực hiện các bài toán tìm/sắp/đếm phải tự cài.

Cho phép `std::string` làm kiểu văn bản; `std::unique_ptr` để giữ quyền sở hữu tạm, không thay danh sách/cây/mảng của đề; stream/file/ngày/hệ điều hành phục vụ nhập xuất. Giả định này cần xác nhận nếu lớp có quy định cấm rộng hơn.

Kiểm kê thư viện được sử dụng trong bản triển khai:

- `<string>`: `std::string`, `std::wstring`, phép gán/nối/so sánh/truy cập ký tự, `size`, `empty`, `substr`, `compare`, `clear`, `insert`, `erase`, `back`, `pop_back`, `swap`, `data`, `c_str`, `std::to_string`, `std::to_wstring`. Cắt chuỗi hoặc so chuỗi chỉ là thao tác văn bản; thuật toán tìm chuỗi con vẫn tự viết. `insert`/`erase` trong ô nhập chỉnh văn bản, không thay thuật toán chèn/xóa cấu trúc DSA.
- `<iosfwd>`, `<iostream>`, `<ostream>`, `<fstream>`, `<sstream>`: `cin/cout/cerr`, stream đọc/ghi chuỗi và file, `std::getline`, `get`, `peek`, `bad`, `fail`, `flush`, `close`, `str`, các toán tử nhập/xuất và `std::char_traits<char>::eof`.
- `<iomanip>`: `std::setw`, `std::setfill` để định dạng ngày. `<ctime>`: `std::time`, `std::localtime` lấy ngày hiện tại; thuật toán tính ngày nhuận và khoảng cách ngày tự cài.
- `<memory>`: `std::unique_ptr`, `get`, `release`, `reset` và destructor để quản lý node/mảng tạm khi thoát sớm. Bốn cấu trúc nghiệp vụ vẫn dùng con trỏ và thuật toán tự cài.
- `<limits>`, `<climits>`: `std::numeric_limits<int>::max`, `INT_MAX` để kiểm tràn. `<exception>`, `<stdexcept>`: `std::exception::what`, `std::runtime_error`, `std::invalid_argument` để báo lỗi.
- `<filesystem>`: `u8path`, `path`, `exists`, `create_directory`, `create_directories`, `remove`, `rename`; các phép ghép đường dẫn, `parent_path`, `filename`, `empty`, `u8string`, `c_str`. `<chrono>`: `high_resolution_clock::now`, `time_since_epoch`, `count` để đặt tên vùng ghi tạm. Đây là `duration::count` đo thời gian, không phải thuật toán `std::count` đếm tập dữ liệu.
- `<system_error>`: `std::error_code`, `std::errc::file_exists`, `message` để báo lỗi file. `<cstdio>` cung cấp các luồng chuẩn cho kiểm terminal.
- Trên Windows, `<windows.h>`, `<shellapi.h>`, `<io.h>`: `MoveFileExW`, `GetLastError`; `GetStdHandle`, `GetConsoleScreenBufferInfo`, `SetConsoleTextAttribute`, `GetConsoleCursorInfo`, `SetConsoleCursorInfo`, `SetConsoleCursorPosition`, `WriteConsoleOutputW`; `GetConsoleMode`, `SetConsoleMode`, `ReadConsoleInputW`, `WideCharToMultiByte`, `MultiByteToWideChar`; `GetConsoleCP`, `GetConsoleOutputCP`, `SetConsoleCP`, `SetConsoleOutputCP`; `GetCommandLineW`, `CommandLineToArgvW`, `LocalFree`; `_isatty`, `_fileno`. Đây là file/console/đối số chạy, không thay thuật toán DSA. Build Windows liên kết `shell32` để dùng `CommandLineToArgvW`. Nhánh ngoài Windows dùng giao diện dòng số; `<unistd.h>` là include tương thích nền tảng.
- Lớp giao diện màu hiện tại dùng thêm `WriteConsoleW`, `GetConsoleScreenBufferInfoEx`, `SetConsoleScreenBufferInfoEx`, `SetConsoleWindowInfo`, `GetCurrentConsoleFontEx`, `SetCurrentConsoleFontEx`, `GetEnvironmentVariableW` và `FoldStringW(MAP_PRECOMPOSED)`. Chúng phục vụ màu, font, tọa độ và ghép dấu trên bản hiển thị; không thay thuật toán tìm/sắp xếp và không sửa byte dữ liệu nghiệp vụ. Bảng màu dùng macro `RGB`, `GetRValue`, `GetGValue`, `GetBValue`.

Không dùng `system("cls")` hoặc thực thi lệnh shell từ dữ liệu nhập. Danh sách `#include` và lời gọi trong chín file là căn cứ đối chiếu khi thay phiên bản.

Tự cài chuẩn hóa và tìm chuỗi con; tìm đầu sách/ISBN/cuốn; chèn mảng có thứ tự; tìm/chèn/xóa BST; duyệt danh sách; đếm lịch sử; sắp các bảng kết quả; tính ngày; thống kê top và quá hạn. Không nói một phép sắp nhanh hơn nếu chưa tính cả khâu tạo dữ liệu kết quả.

## 6. Cách dùng tài liệu để học

Đọc yêu cầu và giả định trong file này, rồi trả lời [câu hỏi](../01_CAU_HOI.md) trước khi mở [đáp án](../02_DAP_AN.md). Đáp án mô tả bản AI và giả định của nó, không phải đáp án thầy đã duyệt.

Che code rồi viết lại là luyện có hỗ trợ vì đã xem giải pháp. Để tự kiểm chứng, tự thiết kế thêm dữ liệu, giải thích một ca chưa xem và sửa một yêu cầu có thay đổi ý nghĩa. Không cập nhật nhật ký học hoặc điểm tự chủ chỉ vì tài liệu/bản build này tồn tại.
