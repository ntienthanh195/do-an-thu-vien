# Đồng bộ bộ vấn đáp với C++11

Ngày 21/10/2026. Cả 325 câu hỏi và đáp án đối chiếu chín file demo C++11 tại commit `c6c48b3dcde8204fa0509e5bc39d1ee263878456`. Mã đi kèm khớp snapshot này; mã ứng dụng không thay đổi trong đợt đồng bộ tài liệu.

- Giữ đủ 100 câu Thái, 100 câu Thành, 100 câu Tấn, 25 câu chung; giữ ID, thứ tự, câu phụ và các mốc ID gộp.
- 35 câu chỉnh nội dung: quyền sở hữu ConTroTam, LuongChuoi và lifetime/copy/reset, LoiThuVien/catch, giới hạn số, ngày máy/định dạng, nhận diện console, đối số Unicode, build, lưu file Windows và view chuỗi tự cài theo C++11.
- Toàn bộ mốc nguồn được dò lại bằng diff và tên symbol trên dòng đích; bổ sung liên kết lớp hỗ trợ nơi đáp án sử dụng. Tên file mở mã đi kèm; liên kết symbol/số dòng ghim snapshot C++11 để không trượt khi main đổi tiếp.
- Nguồn biên soạn JSON được cập nhật trước rồi xuất Markdown bằng exporter. Bản gửi nhóm giữ gọn; JSON, script và kết quả kiểm tra được lưu ở workspace biên soạn C++11 riêng, không ghi đè bộ lịch sử.

Các điểm cần chú ý khi ôn: LuongChuoi::str() trả const string&, không copy chuỗi tại lời gọi phân trang; không có setter str(""). LuongChuoi bật exceptions nhưng cout mặc định không tự bật. ConTroTam chỉ cài phần sở hữu cần dùng, không phải toàn bộ API smart pointer. TepDoc/TepGhi dùng Win32 HANDLE để giữ đường dẫn Unicode; bản demo dành cho Windows.

Phạm vi kiểm chứng: đối chiếu thay đổi mã C++17→C++11 và hợp đồng API liên quan, kiểm số câu/ID/nhóm, JSON–Markdown, mốc dòng/tên symbol, liên kết, nguồn không đổi, CRC và byte thành viên ZIP. Đây là đồng bộ theo thay đổi phiên bản, không phải chứng nhận lại mọi lập luận ngoài phạm vi chuyển đổi hay thực thi toàn bộ 325 tình huống/câu phụ. Các đề xuất sửa trên bản sao vẫn là đề xuất.

785 kiểm tra ứng dụng C++11 đã có từ đợt chuyển đổi, xem [phạm vi của đợt đó](KIEM_CHUNG_CPP11.md); không tính lại là kiểm thử mới của lần sửa tài liệu. Các ca 17–18/10 là lịch sử bản cũ. Không tạo bằng chứng nhóm tự viết, hiểu hoặc hoàn thành môn; G01–G12 vẫn cần xác nhận theo [yêu cầu và giả định](01_YEU_CAU_VA_GIA_DINH.md).
