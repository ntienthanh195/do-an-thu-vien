# Bộ 86 câu hỏi lý thuyết CTDL — bổ sung bộ 325 câu tình huống

**86 câu vấn đáp cần suy luận theo Chương I, III, IV, V và VI của CTDLFULL_UNICODE.docx**, kèm đáp án riêng. Bản này đã loại các câu khởi động chỉ hỏi định nghĩa hoặc nhắc lại thao tác. Các câu còn lại yêu cầu dựng phản ví dụ, truy vết có điều kiện, bảo vệ bất biến, phân tích chi phí cả chuỗi hoặc chọn phương án dưới các ràng buộc cụ thể.

**Phân biệt hai bộ:** bộ **86 câu lý thuyết CTDL** này tập trung vào lựa chọn cấu trúc, bất biến, phản ví dụ và phân tích giải thuật; bộ **325 câu tình huống đồ án Thư viện** tập trung vào nghiệp vụ và code tham khảo, chia theo thành viên. Hai bộ bổ sung cho nhau; 27 phần hỏi tiếp của bộ lý thuyết không cộng vào 86 câu chính và không thuộc bộ 325.

Mức khó là mục tiêu biên soạn, không phải mức đã đo trên từng thành viên. Hiểu định nghĩa là kiến thức cần dùng trong lập luận, không còn là một lượt hỏi riêng.

**Đã bỏ riêng Chương II — Đệ quy và lần ngược theo yêu cầu ngày 25/10/2026.** Bộ còn 86 câu chính và 86 đáp án có tiêu chí đối chiếu; 27 câu có phần hỏi tiếp riêng, không cộng vào số câu chính. Giữ nguyên mã câu ở năm chương còn lại, kể cả các câu dùng đệ quy khi phân tích cây hoặc thuật toán sắp xếp. Đã hiệu chỉnh ba điểm kỹ thuật ở LT1-01, LT3-22, LT6-17; nâng yêu cầu lập luận của LT1-04, LT3-14, LT4-21, LT6-08, LT6-31; làm rõ giả thiết biểu diễn và mã xóa ở LT4-24, LT5-25. Câu hỏi tiếp được mở sau câu chính để kiểm điều kiện áp dụng.

## Mở file nào

- [Chương I — Phân tích và đánh giá giải thuật](01_PhanTichGiaiThuat.md) — 14 câu.
- [Chương III — Danh sách tuyến tính, Stack và Queue](03_Mang_Stack_Queue.md) — 16 câu.
- [Chương IV — Danh sách liên kết](04_DanhSachLienKet.md) — 16 câu.
- [Chương V — Cây, BST và AVL](05_Cay_BST_AVL.md) — 18 câu.
- [Chương VI — Sắp xếp và tìm kiếm](06_SapXep_TimKiem.md) — 22 câu.
- [Đáp án gợi ý cho toàn bộ câu hỏi](07_DapAn.md).

Mở thư mục bằng VS Code, chọn file rồi dùng **Ctrl+Shift+V** để đọc Markdown. Trên GitHub có thể mở trực tiếp. Các liên kết câu hỏi–đáp án dùng được trong thư mục giải nén; không cần có mã nguồn demo bên cạnh.

## Cách nhóm dùng bộ này

1. Mỗi người đọc tình huống và tự đưa kết luận cùng căn cứ trước khi xem đáp án. Nếu thiếu khái niệm nền, tra lại đúng mục giáo trình rồi quay về tình huống; không cần đi qua một vòng câu định nghĩa trong bộ này.
2. Người hỏi chỉ đọc câu chính, không mở đáp án hoặc “Tránh nhầm” trước. Với các câu có mục thu gọn **Câu hỏi tiếp**, mở sau khi đã nghe lập luận ban đầu để kiểm tra thêm một điều kiện; không tính mục này thành câu riêng.
3. Mở đáp án và mục **Cần thể hiện khi trả lời** để đối chiếu điều kiện, phản ví dụ/bất biến và phân tích chi phí cụ thể. Chấp nhận cách đúng khác, không yêu cầu thuộc câu chữ hoặc gán điểm từ số ý đã nhắc.
4. Khi lập luận đã đủ thì khép câu; nếu cần ôn lại, đổi một giả thiết có ý nghĩa ở lượt sau. Sau đó nối sang tình huống liên quan trong bộ 325 hoặc đọc phần code nhóm đã thực sự viết.

Gợi ý liên hệ theo phân công: Thái chú ý mảng đầu sách, danh sách cuốn, tìm kiếm và thống kê; Thành chú ý BST, lịch sử và chi phí các bước mượn–trả; Tấn chú ý duyệt, lọc, thứ tự báo cáo và bộ nhớ tạm. Đây là điểm nối để ôn chéo, không miễn các chương còn lại cho ai.

## Phạm vi và nguồn

- Nguồn chính: **CTDLFULL_UNICODE.docx**, do người dùng xác nhận ngày 25/10/2026. Phạm vi hiện tại: Chương I phân tích; III danh sách tuyến tính/Stack/Queue; IV liên kết; V cây/BST/AVL; VI sắp xếp/tìm kiếm. Chương II đã được rút khỏi bộ câu hỏi theo yêu cầu mới của người dùng; giáo trình gốc vẫn giữ nguyên.
- Không đưa Chương VII đồ thị hoặc phần sắp xếp ngoài thành yêu cầu của bộ này. Các câu kết hợp Stack/Queue, chi phí cả chuỗi, cây quyết định so sánh và quan hệ số nút AVL là bài suy luận từ kiến thức đang ôn; đề hoặc đáp án nêu đủ mô hình cần dùng, không gán chúng thành các mục nguyên văn của giáo trình.
- Nguồn liên hệ: [đề số 3](https://github.com/ntienthanh195/do-an-thu-vien/blob/d85bf167b70252693e32365e31696bf87493ac3b/TaiLieuThamKhao_AI/BO_DOI_DAP_THU_VIEN_100_MOI_NGUOI/ThamKhao/NGUYEN_VAN_DE_3_THU_VIEN.txt), [khai báo nhóm](https://github.com/ntienthanh195/do-an-thu-vien/blob/d85bf167b70252693e32365e31696bf87493ac3b/MaNguon/00_KhaiBaoChung.h) và [hướng dẫn bộ 325](https://github.com/ntienthanh195/do-an-thu-vien/blob/d85bf167b70252693e32365e31696bf87493ac3b/TaiLieuThamKhao_AI/README.md), cùng snapshot repo `d85bf16` đã đối chiếu với nhánh main ngày 25/10/2026. Liên kết nguồn GitHub cần Internet.
- Bốn cấu trúc đề yêu cầu: mảng con trỏ đầu sách luôn tăng theo tên; danh sách đơn cuốn; BST độc giả theo mã; danh sách đơn mượn trả của từng độc giả. Các phương án so sánh trong đáp án không tự cấp quyền thay cấu trúc, thêm trường nghiệp vụ hoặc thêm chức năng vào bản nộp.
- Bộ 325 hiện dẫn snapshot demo C++11 `1c4510c`; code nhóm nằm ở MaNguon tại gốc repo. Các câu mới ưu tiên lý thuyết và khai báo, không giả định chức năng của demo đã tồn tại trong code nhóm. Chưa rà mọi nhánh/PR hoặc xác minh toàn bộ đáp án 325 trong lần soạn này.

## Những điều phải nói kèm điều kiện

- Big-O là chặn trên tiệm cận; quy tắc bỏ hệ số chỉ là cách rút gọn biểu thức đã phân tích. Nêu rõ đại lượng n, trường hợp đang xét và chi phí một thao tác.
- Thêm/xóa liên kết O(1) là phần cập nhật khi đã có đủ vị trí/con trỏ; thao tác tìm rồi xóa có thể O(n).
- BST thường có chi phí theo chiều cao, có thể O(n); AVL mới duy trì chiều cao logarit bằng điều kiện cân bằng.
- Tìm nhị phân phải khớp khóa/thứ tự và tính chi phí truy cập. Mảng tăng theo tên không hỗ trợ ngay tìm nhị phân theo ISBN.
- Quick Sort có trung bình/kỳ vọng O(n log n) dưới giả thiết thích hợp, xấu nhất có thể O(n²). Không dùng diễn đạt mơ hồ trong phần phân tích cũ của giáo trình thay cho việc nêu giả thiết.
- Thuật ngữ cây đầy/hoàn chỉnh có thể khác giữa tài liệu; câu trả lời phải nói rõ hình dạng. Bộ này không sao chép các ví dụ mã C/C++ cũ làm mẫu triển khai.

## Đối chiếu mã câu với bản trước

<details>
<summary>Mở khi nhóm đang ghi chú bằng mã câu của bản trước</summary>

Các mã dưới đây đã được thay ở lần biên tập trước, không phải thay đổi mới của lần bỏ Chương II. Câu thay thế có mục tiêu mới, không phải đáp án mới cho mã cũ. Toàn bộ mã LT2 đã rút khỏi bộ hiện tại; các mã ở năm chương còn lại giữ nguyên để nhóm tiếp tục dùng ghi chú cũ.

- LT1-06: thay bằng [LT1-18](01_PhanTichGiaiThuat.md#lt1-18).
- LT1-13: thay bằng [LT1-19](01_PhanTichGiaiThuat.md#lt1-19); hướng lập luận cũ còn được ôn tại [LT6-29](06_SapXep_TimKiem.md#lt6-29).
- LT4-11: thay bằng [LT4-24](04_DanhSachLienKet.md#lt4-24); hướng lập luận cũ còn được ôn tại [LT4-21](04_DanhSachLienKet.md#lt4-21).
- LT4-19: thay bằng [LT4-25](04_DanhSachLienKet.md#lt4-25); hướng lập luận cũ còn được ôn tại [LT3-04](03_Mang_Stack_Queue.md#lt3-04).
- LT5-09: thay bằng [LT5-25](05_Cay_BST_AVL.md#lt5-25); hướng lập luận cũ còn được ôn tại [LT5-10](05_Cay_BST_AVL.md#lt5-10).
- LT5-16: thay bằng [LT5-26](05_Cay_BST_AVL.md#lt5-26); hướng lập luận cũ còn được ôn tại [LT5-11](05_Cay_BST_AVL.md#lt5-11).
- LT5-23: thay bằng [LT5-27](05_Cay_BST_AVL.md#lt5-27); hướng lập luận cũ còn được ôn tại [LT5-17](05_Cay_BST_AVL.md#lt5-17).

</details>

## Giới hạn sử dụng

Đây là bộ câu hỏi do AI biên soạn để nhóm ôn, không phải danh sách câu thầy chắc chắn hỏi và không phải xác nhận ai đã nắm kiến thức. Câu hỏi khó có thể học qua nhiều lượt. Việc tạo bộ tài liệu không ghi tiến độ, điểm, lần làm hay kết quả kiểm thử cho thành viên nào. Đáp án nêu nguyên lý và phân tích, không cung cấp mã giải quyết phần đồ án mà nhóm phải tự viết.
