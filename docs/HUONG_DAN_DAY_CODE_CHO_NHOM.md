# Hướng dẫn đặt file và đẩy code — dành cho Thành, Thái, Tấn

Repo chung: https://github.com/ntienthanh195/do-an-thu-vien

Hướng dẫn này dùng GitHub Desktop để thao tác bằng nút bấm. Code vẫn viết bằng IDE/editor của mỗi người. Không cần học lệnh Git để bắt đầu.

## 1. Code đặt ở đâu?

**Mọi file mã nguồn `.cpp` và khai báo `.h` của chương trình đặt trong thư mục `src` của repo đã clone về máy.** Push sẽ đưa các thay đổi lên đúng đường dẫn đó trên GitHub; không có bước chọn “thư mục nhận” mỗi lần push.

Phân biệt ba việc:

- **Thư mục:** vị trí file, ví dụ `src/LietKe.cpp`.
- **Nhánh:** phiên bản đang làm việc, ví dụ `tan/liet-ke-dang-muon`.
- **Pull request (PR):** yêu cầu xem xét và ghép thay đổi từ nhánh đó vào `main`.

File của Tấn trên nhánh riêng vẫn nằm ở `src/LietKe.cpp`; sau khi ghép vào `main`, đường dẫn vẫn như vậy. Không tạo ba thư mục tên người để chứa ba bản chương trình riêng.

Các tên file dưới đây chỉ là ví dụ để hiểu vị trí đặt code theo phân công, không phải bộ khung bắt buộc:

- **Thành:** `src/DocGia.h`, `src/DocGia.cpp`, `src/MuonTra.h`, `src/MuonTra.cpp`; điều phối `src/main.cpp`.
- **Thái:** `src/Sach.h`, `src/Sach.cpp`, `src/ThongKe.h`, `src/ThongKe.cpp`; phụ trách chính `src/GiaoDien.h`, `src/GiaoDien.cpp`.
- **Tấn:** `src/LietKe.h`, `src/LietKe.cpp`, `src/Menu.h`, `src/Menu.cpp`.
- **Dùng chung:** `src/KhaiBao.h`, do cả nhóm thống nhất và Thành điều phối thay đổi.

**Mỗi người tự thiết kế và tạo file khi cần; nhóm tự thống nhất tên và cách chia.** Đọc [hướng đi tự làm](HUONG_DI_TU_LAM_CHO_TUNG_THANH_VIEN.md) trước khi bắt đầu. Repo giữ bản khai báo nhóm tự viết `src/CODE-ĐỒ-ÁN-THƯ-VIỆN-DSA.cpp`; không có bộ hàm AI để điền. Nhóm tự thống nhất cách tách khai báo dùng chung, không chép struct thành nhiều bản khác nhau. Khi file đã có thì sửa file đó, không thêm hậu tố `final`, `v2`, `moi_nhat` để giữ nhiều bản song song. Git lưu lịch sử thay đổi.

Các loại tài liệu/dữ liệu khác:

- `docs/`: phân công, hướng dẫn và ghi chú kỹ thuật dùng chung.
- `data/samples/`: dữ liệu mẫu giả lập, chỉ thêm sau khi chốt định dạng; kèm mô tả dữ liệu và kết quả cần kiểm tra.
- `data/runtime/`: bản sao dùng để chạy thử trên máy mỗi người; Git bỏ qua thư mục này.
- File `.exe`, `.o`, `.obj` và thư mục build không đưa lên làm mã nguồn.

Hai thư mục dữ liệu chưa được tạo trong bản khởi tạo. Khi có định dạng, người phụ trách thêm file dữ liệu đúng chỗ; Git không lưu thư mục rỗng.

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

- [GitHub Desktop](https://docs.github.com/en/desktop): công cụ giao diện để làm việc với GitHub.
- [Clone repo](https://docs.github.com/en/desktop/adding-and-cloning-repositories).
- [Tạo nhánh và lưu thay đổi](https://docs.github.com/en/get-started/start-your-journey/writing-and-storing-your-code).
- [Xem thay đổi và commit](https://docs.github.com/en/desktop/making-changes-in-a-branch/committing-and-reviewing-changes-to-your-project-in-github-desktop).
- [Đồng bộ nhánh](https://docs.github.com/en/desktop/contributing-and-collaborating-using-github-desktop/syncing-your-branch).
- [Tạo pull request](https://docs.github.com/en/desktop/working-with-your-remote-repository-on-github-or-github-enterprise/creating-an-issue-or-pull-request-from-github-desktop).

Hướng dẫn nhóm cập nhật 27/09/2026. Tên/vị trí nút có thể khác nhẹ theo phiên bản Desktop; luôn kiểm tra tên repo, nhánh và danh sách file trước khi gửi thay đổi.
