# Đồng bộ bộ vấn đáp với C++11

Ngày 21/10/2026. Cả 325 câu hỏi và đáp án đối chiếu chín file demo C++11 tại commit `b44964652043d8f4790a23952d4e3a8694ce1cdf`. Mã đi kèm khớp snapshot này. Sau đợt đồng bộ ban đầu, rà soát toàn bộ và sửa cổng từ chối đường dẫn dòng lệnh rỗng; cập nhật TN238 và toàn bộ liên kết snapshot.

- Giữ đủ 100 câu Thái, 100 câu Thành, 100 câu Tấn, 25 câu chung; giữ ID, thứ tự, câu phụ và các mốc ID gộp.
- 35 câu chỉnh nội dung: quyền sở hữu ConTroTam, LuongChuoi và lifetime/copy/reset, LoiThuVien/catch, giới hạn số, ngày máy/định dạng, nhận diện console, đối số Unicode, build, lưu file Windows và view chuỗi tự cài theo C++11.
- Toàn bộ mốc nguồn được dò lại bằng diff và tên symbol trên dòng đích; bổ sung liên kết lớp hỗ trợ nơi đáp án sử dụng. Tên file mở mã đi kèm; liên kết symbol/số dòng ghim snapshot C++11 để không trượt khi main đổi tiếp.
- Nguồn biên soạn JSON được cập nhật trước rồi xuất Markdown bằng exporter. Bản gửi nhóm giữ gọn; JSON, script và kết quả kiểm tra được lưu ở workspace biên soạn C++11 riêng, không ghi đè bộ lịch sử.

Các điểm cần chú ý khi ôn: LuongChuoi::str() trả const string&, không copy chuỗi tại lời gọi phân trang; không có setter str(""). LuongChuoi bật exceptions nhưng cout mặc định không tự bật. ConTroTam chỉ cài phần sở hữu cần dùng, không phải toàn bộ API smart pointer. TepDoc/TepGhi dùng Win32 HANDLE để giữ đường dẫn Unicode; bản demo dành cho Windows.

Phạm vi kiểm chứng: đối chiếu thay đổi mã C++17→C++11 và hợp đồng API liên quan, kiểm số câu/ID/nhóm, JSON–Markdown, mốc dòng/tên symbol, liên kết, nguồn không đổi, CRC và byte thành viên ZIP. Đây là đồng bộ theo thay đổi phiên bản, không phải chứng nhận lại mọi lập luận ngoài phạm vi chuyển đổi hay thực thi toàn bộ 325 tình huống/câu phụ. Các đề xuất sửa trên bản sao vẫn là đề xuất.

785 kiểm tra ứng dụng C++11 đã có từ đợt chuyển đổi, xem [phạm vi của đợt đó](KIEM_CHUNG_CPP11.md); không tính lại là kiểm thử mới của lần sửa tài liệu. Các ca 17–18/10 là lịch sử bản cũ. Không tạo bằng chứng nhóm tự viết, hiểu hoặc hoàn thành môn; G01–G12 vẫn cần xác nhận theo [yêu cầu và giả định](01_YEU_CAU_VA_GIA_DINH.md).

## Rà soát toàn bộ sau đồng bộ — 21/10/2026

Đã đọc lại đủ 325 câu chính, đáp án, câu phụ, cách kiểm chứng, sai lầm và danh sách hàm dẫn nguồn; phân biệt hành vi hiện tại với sửa trên bản sao/mở rộng. Không phát hiện câu bị mất, lặp ID, lệch nhóm hoặc còn mô tả API C++17 cũ như API hiện hành. Giữ 100/100/100/25 câu, thứ tự và các mốc ID gộp.

Kiểm lại 845 mốc symbol/dòng trên mỗi tài liệu (1.690 liên kết ghim nguồn), liên kết hỏi–đáp, JSON→Markdown và byte thành viên của cả hai ZIP. Các liên kết đều trỏ snapshot mới; ba dòng thêm trong main đã được tính vào mốc dòng phía sau.

Đã chạy lại 679 assertion nghiệp vụ, 43 assertion giao diện Win32 và 33 assertion lớp hỗ trợ; build C++11 đạt. Sau sửa đường dẫn rỗng, chạy lại 30 kiểm tra CLI a–j và thêm 26 assertion đối số: tổng 811 kiểm tra tự động trong đợt này. Bộ kiểm này không tương đương thực thi toàn bộ 325 tình huống/câu phụ, không kiểm tay IME/chuột vật lý trên máy thành viên. Các giới hạn đã nêu như TN82 (ngoại lệ sau khi nạp RAM) vẫn là giới hạn được mô tả, không phải chức năng đã sửa.
