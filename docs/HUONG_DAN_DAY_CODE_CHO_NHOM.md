# Hướng dẫn đặt file và đẩy code — dành cho Thành, Thái, Tấn

Repo chung: https://github.com/ntienthanh195/do-an-thu-vien

Hướng dẫn này dùng GitHub Desktop để thao tác bằng nút bấm. Code vẫn viết bằng IDE/editor của mỗi người. Không cần học lệnh Git để bắt đầu.

## 1. Code đặt ở đâu?

**Theo cách chia nhóm đã chốt, code mới đặt trong `MaNguon/`.** Các file đã tạo sẵn để Thành, Thái và Tấn mở đúng file rồi tự viết; không có thân hàm hoặc mẫu lời giải. Quy ước vị trí này thay các ví dụ `src/` và `data/samples/` trong hướng dẫn cũ; lịch làm việc và phân công chức năng a–j không đổi.

- `00_KhaiBaoChung.h`: khai báo chung, Thành điều phối; cả ba thống nhất thay đổi.
- `01_HamTienIch.cpp`: Thành làm ngày tháng/kiểm tra dữ liệu phần mình; Thái làm tiện ích chuỗi/trạng thái sách.
- `02_XuLyDauSach.cpp`: Thái quản lý/tìm đầu sách; Tấn liệt kê theo thể loại.
- `03_XuLyCuonSach.cpp`: Thái quản lý/tra cứu cuốn sách.
- `04_XuLyDocGia.cpp`: Thành quản lý độc giả; Tấn làm hai cách xem độc giả.
- `05_XuLyMuonTra.cpp`: Thành xử lý danh sách lịch sử; Tấn liệt kê sách đang mượn.
- `06_NghiepVuTongHop.cpp`: Thành làm nghiệp vụ mượn/trả; Thái làm thống kê quá hạn/top 10.
- `07_LuuDocFile.cpp`: Thành đọc/ghi độc giả và lịch sử, phối hợp lưu/nạp chung; Thái đọc/ghi sách. Backup tự động là tùy chọn làm sau.
- `08_ChuongTrinhChinh.cpp`: Tấn làm menu; Thành nối luồng chính, nạp/lưu/thoát. Helper giao diện dùng chung được cả ba chia việc cụ thể, không giao hết cho Tấn.

Mỗi người tự làm màn hình chức năng mình phụ trách. Báo nhau trước khi cùng sửa một file; làm trên nhánh riêng, gửi PR để review rồi mới ghép main. Ví dụ Tấn sửa phần liệt kê trong `MaNguon/05_XuLyMuonTra.cpp` trên nhánh `tan/liet-ke-dang-muon`; sau khi ghép, đường dẫn file không đổi. Không tạo ba bản chương trình theo tên người hoặc thêm hậu tố `final`, `v2`, `moi_nhat`; Git giữ lịch sử.

Header mới hiện trống để giữ chỗ. Bản khai báo cũ trong `src/CODE-ĐỒ-ÁN-THƯ-VIỆN-DSA.cpp` và bản Thái gửi PR #5 được giữ nguyên. Nhóm cần đưa bản khai báo đã duyệt vào header chung trước khi dùng để biên dịch; không duy trì nhiều bản struct sửa song song. Bộ file trống chưa phải chương trình chạy được.

Các thư mục còn lại:

- `DuLieu/DuLieuMau.txt`: nơi nhóm tự soạn mẫu sau khi chốt định dạng, kèm kết quả mong đợi.
- `DuLieu/DuLieuRong.txt`: mẫu hệ thống rỗng; file hiện trống chưa chứng minh đúng định dạng của bộ đọc sau này.
- `DuLieu/runtime/`: bản sao dữ liệu để chạy thử; Git bỏ qua để không ghi đè bộ mẫu chung.
- `TestKey/TestNhapDung.txt`, `TestKey/TestNhapSai.txt`: kịch bản thử do cả ba bổ sung cho phần mình; chưa có kịch bản hay kết quả kiểm thử.
- `TaiLieu/SoDoLienKet.md`, `TaiLieu/CauHoiHoiThay.md`: nơi nhóm tự viết sơ đồ và câu hỏi; hiện trống.
- `docs/`: giữ tài liệu phân công, lịch và hướng dẫn cộng tác đã có.

File `.exe`, `.o`, `.obj` và thư mục build không đưa lên làm mã nguồn. Đọc [hướng đi tự làm](HUONG_DI_TU_LAM_CHO_TUNG_THANH_VIEN.md) để hiểu trách nhiệm; vị trí file mới theo mục này.

## 2. Chuẩn bị lần đầu

1. Gửi username GitHub cho Thành để được mời vào repo và chấp nhận lời mời. Repo riêng tư nên có link thôi chưa đủ quyền truy cập.
2. Cài [GitHub Desktop từ trang chính thức](https://desktop.github.com/) và đăng nhập đúng tài khoản được mời.
3. Trong Desktop chọn **File → Clone repository**, mở phần **URL**, nhập link repo chung ở đầu tài liệu.
4. Chọn thư mục trên máy để lưu rồi bấm **Clone**. Ghi nhớ vị trí thư mục `do-an-thu-vien` vừa được tạo.
5. Mở đúng thư mục đó trong editor. Có thể dùng **Repository → Show in Explorer** để tìm thư mục trên Windows.

Clone là lấy repo cùng lịch sử Git về để làm việc. Download ZIP phù hợp để đọc/lưu tài liệu, nhưng bản giải nén không tự có kết nối Git để commit/push như bản clone.

Không bấm tạo repo mới hoặc Publish repository thành repo riêng của mình. Cả nhóm dùng chung repo `ntienthanh195/do-an-thu-vien`.

## 3. Trước mỗi nhiệm vụ: cập nhật và tạo nhánh

1. Mở GitHub Desktop, kiểm tra **Current repository** là `do-an-thu-vien`.
2. Nếu còn thay đổi chưa lưu thành commit của nhiệm vụ trước, xử lý trên nhánh đang làm trước khi đổi nhánh. Không chọn Discard chỉ để hết cảnh báo.
3. Chọn **Current branch → main**. Bấm **Fetch origin** để kiểm tra thay đổi; nếu có **Pull origin**, bấm để lấy bản mới về.
4. Từ `main` mới nhất, chọn **Current branch → New branch** và đặt tên theo nhiệm vụ, ví dụ:
   - Tấn: `tan/liet-ke-dang-muon`.
   - Thái: `thai/doc-file-sach`.
   - Thành: `thanh/them-doc-gia`.
5. Kiểm tra nhánh vừa tạo đang được chọn rồi bắt đầu sửa code.

Mỗi chức năng/mốc nhỏ dùng một nhánh. Nếu đang sửa tiếp cùng nhiệm vụ đã có PR, dùng lại nhánh đó; không tạo nhánh mới sau mỗi lần sửa.

## 4. Nếu đã code xong ở thư mục khác

Sau khi clone, cập nhật `main` và tạo nhánh như trên, sao chép có chọn lọc phần file của mình vào đúng `src` trong repo.

- Đọc bản chung hiện tại trước khi thay file để không làm mất phần bạn khác vừa sửa.
- Không chép cả thư mục project cũ đè lên repo, không mang theo `.git`, file chạy hay cấu hình máy cá nhân.
- Nếu bản thử có `main` riêng hoặc chứa lại toàn bộ khai báo chung, trao đổi với Thành để tách phần chức năng trước khi ghép. Chương trình chung chỉ có một điểm chạy.
- Kiểm tra cách gọi hàm và kiểu dữ liệu khớp bản chung. Nếu thiếu hàm phụ thuộc, ghi rõ phần chưa chạy được; không báo đã kiểm thử cả chương trình.

## 5. Code xong: commit và push

1. Lưu file trong editor, biên dịch/chạy thử phạm vi có thể kiểm tra.
2. Quay lại Desktop, mở **Changes**. Phải nhìn thấy đường dẫn dự kiến như `src/LietKe.cpp` hoặc `src/Sach.cpp`.
3. Bấm từng file để xem các dòng thêm/xóa. Chỉ chọn những file thuộc nhiệm vụ; nếu có file lạ, cả project hoặc thay đổi của người khác, kiểm tra lại trước khi commit.
4. Nhập **Summary** cụ thể, ví dụ `Thêm liệt kê sách độc giả đang mượn`. Ghi mô tả bổ sung nếu cần.
5. Kiểm tra nút **Commit to ...** đang ghi đúng nhánh nhiệm vụ, rồi commit.
6. Nếu nhánh chưa có trên GitHub, bấm **Publish branch**. Những lần tiếp theo dùng **Push origin** để gửi commit mới lên.

**Commit lưu thay đổi trong repo trên máy. Push mới đưa commit lên GitHub. Push nhánh riêng chưa ghép code vào `main`.**

Không chọn trực tiếp `main` để gửi phần đang làm theo quy ước nhóm. Đây là quy ước cộng tác; repo chưa có bảo vệ nhánh tự động để ngăn mọi thao tác nhầm.

## 6. Gửi yêu cầu ghép code

Sau khi push nhánh, dùng **Preview Pull Request/Create Pull Request** nếu Desktop hiển thị, hoặc mở tab **Pull requests → New pull request** trên GitHub.

- **Base:** `main` — nơi muốn ghép vào.
- **Compare:** nhánh vừa push — nơi chứa thay đổi của mình.
- Xem lại các file thay đổi trước khi tạo PR.

Ghi nội dung ngắn theo mẫu:

```text
Chức năng: ...
File đã thay đổi: ...
Hàm/phần của bạn khác đang sử dụng: ...
Đã thử với dữ liệu nào, mong đợi gì, kết quả thực tế: ...
Phần chưa làm hoặc chưa kiểm tra: ...
```

Nhắn link PR trong nhóm để Thành điều phối review. Không tự bấm Merge khi chưa thống nhất. Còn đang làm hoặc thiếu phụ thuộc thì ghi rõ, có thể mở Draft PR để trao đổi; chưa tính là hoàn thành.

Nếu được góp ý, sửa trên chính nhánh đó → commit → push. PR đang mở sẽ nhận các commit mới, không cần tạo lại PR cho cùng lượt sửa.

## 7. Sau khi đã ghép

1. Kiểm tra PR đã có trạng thái **Merged**.
2. Khi không còn thay đổi chưa commit, chuyển về `main` trên Desktop.
3. Fetch rồi Pull nếu có cập nhật. Kiểm tra chức năng của mình trong bản chung đã ghép.
4. Tạo nhánh mới từ `main` mới nhất cho nhiệm vụ tiếp theo.

Nếu đang làm dở một nhánh khác và cần thay đổi mới của đồng đội, không chép file từ website đè vào. Trao đổi với Thành để cập nhật nhánh từ `main` và xử lý xung đột nếu có.

## 8. Những tình huống dễ nhầm

- **Push xong nhưng trên website không thấy code:** kiểm tra ô chọn nhánh; website có thể đang xem `main`, còn code mới ở nhánh nhiệm vụ. Chỉ sau khi PR được ghép thì `main` mới có thay đổi.
- **Không thấy Changes:** kiểm tra đã lưu file và đang sửa đúng thư mục clone; file ngoài repo hoặc bị `.gitignore` bỏ qua sẽ không hiện như mong đợi.
- **Không mở được repo hoặc push bị từ chối:** kiểm tra đúng tài khoản, đã nhận lời mời và quyền truy cập. Không gửi mật khẩu/token cho nhóm.
- **Desktop báo conflict/xung đột:** giữ nguyên công việc, báo Thành cùng xem phần trùng. Không chọn đại phiên bản, không force push để vượt lỗi.
- **Sửa nhầm trên main nhưng chưa commit:** giữ thay đổi, nhờ Thành hỗ trợ chuyển sang nhánh phù hợp; không xóa code để làm lại. Nếu đã commit/push nhầm thì báo rõ trước khi sửa lịch sử.
- **Có dữ liệu test dài:** đưa bộ mẫu đã thống nhất vào `data/samples`, không đưa dữ liệu cá nhân thật hoặc kết quả chạy thay đổi liên tục vào đó.

## 9. Ví dụ bàn giao của Tấn

Tấn nhận mục h → lấy `main` mới nhất → tạo `tan/liet-ke-dang-muon` → tự viết phần phụ trách ở `src/LietKe.h/.cpp` theo cách gọi đã thống nhất → thử dữ liệu và ghi kết quả → commit → Publish branch/Push origin → PR vào `main` → sửa theo review → Thành điều phối ghép → cả nhóm Pull bản mới.

Thái làm tương tự với nhánh và file phần sách/thống kê của mình. Không gửi một file `Thai_final.cpp` hoặc `Tan_final.cpp` lên thư mục gốc rồi chờ người khác tự tìm cách ghép.

## Tài liệu GitHub chính thức

- [Clone repo](https://docs.github.com/en/desktop/adding-and-cloning-repositories).
- [Tạo nhánh và lưu thay đổi](https://docs.github.com/en/get-started/start-your-journey/writing-and-storing-your-code).
- [Xem thay đổi và commit](https://docs.github.com/en/desktop/making-changes-in-a-branch/committing-and-reviewing-changes-to-your-project-in-github-desktop).
- [Đồng bộ nhánh](https://docs.github.com/en/desktop/contributing-and-collaborating-using-github-desktop/syncing-your-branch).
- [Tạo pull request](https://docs.github.com/en/desktop/working-with-your-remote-repository-on-github-or-github-enterprise/creating-an-issue-or-pull-request-from-github-desktop).

Hướng dẫn nhóm cập nhật 27/09/2026. Tên/vị trí nút có thể khác nhẹ theo phiên bản Desktop; luôn kiểm tra tên repo, nhánh và danh sách file trước khi gửi thay đổi.
