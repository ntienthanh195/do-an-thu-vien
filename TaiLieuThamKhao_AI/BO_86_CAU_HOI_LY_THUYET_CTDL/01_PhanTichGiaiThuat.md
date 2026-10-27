# Chương I — Phân tích và đánh giá giải thuật

[Về hướng dẫn](README.md) · [Đáp án riêng](07_DapAn.md)

**Nguồn phạm vi:** Chương I, mục I–V; phần Giới thiệu môn học về lựa chọn cách tổ chức dữ liệu.

Tự trả lời bằng lời trước khi mở đáp án. Với câu chọn phương án, nêu điều kiện và đánh đổi; với câu truy vết, nêu trạng thái hoặc thứ tự cụ thể. Mỗi câu là một tình huống có các ý liên quan; phải bảo vệ kết luận bằng phản ví dụ, trạng thái hoặc lập luận chi phí theo đúng yêu cầu.

<a id="lt1-01"></a>

## LT1-01

Ban đầu có n₀≥1 bản ghi chưa sắp. Sau đó có q lần tra cứu mã và u lần chèn thành công, xen kẽ, không có xóa; đặt N=n₀+u là số bản ghi lớn nhất. Phương án A giữ mảng chưa sắp, chèn cuối và tìm tuần tự. Phương án B sắp theo mã một lần rồi luôn giữ mảng tăng theo mã, tìm nhị phân và chèn đúng vị trí. Mảng đủ sức chứa, so khóa và di chuyển một bản ghi tốn O(1), chưa tính kiểm tra trùng. Hãy lập chặn trên trường hợp xấu cho tổng công việc của hai phương án, tính cả chuẩn bị. Chỉ ra khi nào B đáng dùng và khi nào kết luận “tìm nhị phân nhanh hơn nên chọn B” thất bại.

[Đối chiếu đáp án](07_DapAn.md#lt1-01)

<a id="lt1-03"></a>

## LT1-03

Một báo cáo đánh giá ghi “A là O(n²), B cũng O(n²), nên tốc độ tăng như nhau; A đã chạy nhanh hơn ở n=1.000 nên luôn tốt hơn”. Hãy bác bỏ cả hai suy luận bằng các hàm chi phí cụ thể, rồi nêu thông tin tối thiểu cần bổ sung để so sánh có căn cứ.

[Đối chiếu đáp án](07_DapAn.md#lt1-03)

<a id="lt1-04"></a>

## LT1-04

Tìm tuần tự trong n≥2 bản ghi. Với xác suất p(n), mã không tồn tại nên cần n lần so; các truy vấn còn lại trúng ngay bản ghi đầu. Chỉ biết 0<p(n)≤1, mỗi lần so tốn O(1). Hãy suy ra điều kiện cần và đủ theo bậc tăng của p(n) để số phép so kỳ vọng là Θ(1), rồi để là Θ(log n). Tự chọn một p(n) cho từng trường hợp, và giải thích vì sao độ phức tạp xấu nhất vẫn có thể tuyến tính dù kỳ vọng nhỏ.

<details>
<summary>Câu hỏi tiếp — mở sau khi trả lời câu chính</summary>

Bỏ giả thiết trúng ngay đầu: vị trí trúng trung bình của các truy vấn thành công là μ(n), với 1≤μ(n)≤n và p(n)<1. Nếu chỉ biết p(n)=1/n thì có đủ kết luận kỳ vọng hằng số không? Tự dựng hai phân phối cùng xác suất thất bại nhưng khác bậc kỳ vọng.

</details>

[Đối chiếu đáp án](07_DapAn.md#lt1-04)

<a id="lt1-05"></a>

## LT1-05

Có R độc giả, độc giả i có H_i lượt lịch sử, tổng H=ΣH_i. Cách A duyệt từng độc giả và duyệt đúng lịch sử của người đó một lần. Cách B cũng duyệt R độc giả nhưng ở mỗi người lại duyệt toàn bộ H lượt để lọc theo mã. Mỗi phép xét O(1), bỏ qua xuất dữ liệu. Một bạn ghi cả hai là O(RH) vì đều có hai vòng lặp. Hãy chỉ ra cận chặt, kể cả trường hợp nhiều người không có lịch sử.

[Đối chiếu đáp án](07_DapAn.md#lt1-05)

<a id="lt1-09"></a>

## LT1-09

Các truy vấn được định tuyến tới danh mục đầu sách i, nhưng không bảo đảm cuốn cần tìm tồn tại trong danh mục đó. Danh sách có C_i cuốn; H_i truy vấn nhắm vào đầu i và đều không tìm thấy nên phải quét hết. Biết C=ΣC_i, H=ΣH_i; xét riêng số lần so mã cuốn, mỗi lần O(1). Hãy lập chi phí theo từng nhóm. Chỉ biết C,H có đủ suy ra một cận chặt dùng chung cho mọi cách phân bố không?

<details>
<summary>Câu hỏi tiếp — mở sau khi trả lời câu chính</summary>

Giữ đúng hai đầu sách không rỗng và cùng tổng C,H. Tự xây hai cách phân bố làm số lần so chênh nhau theo bậc tăng; phân biệt chặn trên với chi phí thực sự.

</details>

[Đối chiếu đáp án](07_DapAn.md#lt1-09)

<a id="lt1-10"></a>

## LT1-10

BST độc giả được tổ chức theo mã thẻ, chưa có chỉ mục tên. Yêu cầu trả về k người đầu theo tên rồi họ trong số những người thỏa một điều kiện lịch sử; không được bỏ sót người có tên nhỏ hơn. Một đề xuất chỉ duyệt đến khi gặp đủ k người rồi dừng và quảng cáo O(log R+k). Hãy tìm phản ví dụ, chỉ ra công việc nào không thể tự loại bỏ và phân biệt chi phí chuẩn bị với chi phí xuất trang.

[Đối chiếu đáp án](07_DapAn.md#lt1-10)

<a id="lt1-11"></a>

## LT1-11

Một phép tìm tên dùng O(log D) lần so chuỗi trong mảng D đầu sách đã sắp. Mọi tên dài tối đa L ký tự và nhiều tên chung một tiền tố dài. Có thể quảng cáo thời gian O(log D) độc lập với L không? Nếu chuẩn hóa sẵn mọi tên để giảm công việc khi tìm, hãy tách chi phí chuẩn bị, bộ nhớ, chi phí một truy vấn và nghĩa vụ khi tên bị sửa.

[Đối chiếu đáp án](07_DapAn.md#lt1-11)

<a id="lt1-12"></a>

## LT1-12

*Suy luận nâng cao từ kiến thức đang ôn; không gán là yêu cầu nguyên văn của giáo trình.*

Một thuật toán chỉ được so sánh từng cặp khóa phân biệt, mỗi phép so cho hai kết quả thứ tự, và phải sắp đúng mọi hoán vị n phần tử. Người viết hứa tối đa 5n phép so cho mọi n. Hãy mô hình hóa các chuỗi kết quả so bằng cây quyết định và giải thích vì sao lời hứa không thể đúng khi n đủ lớn. Kết luận có áp dụng ngay cho thuật toán dùng trực tiếp giá trị khóa để đặt vào các ô đã biết không?

[Đối chiếu đáp án](07_DapAn.md#lt1-12)

<a id="lt1-14"></a>

## LT1-14

Để trả nhanh số lượt đang mượn, một thiết kế giữ thêm biến đếm bên cạnh danh sách lịch sử. Sau mượn thành công phải thêm một lượt mở; sau trả thành công phải đóng một lượt mở; thao tác thất bại phải giữ nguyên dữ liệu. Một bạn tăng/giảm biến đếm ngay khi nhận yêu cầu, rồi mới kiểm điều kiện. Hãy dựng chuỗi làm số đếm sai, phát biểu bất biến và so tổng chi phí của q lần hỏi với u lần cập nhật so với đếm lại từ lịch sử mỗi lần.

[Đối chiếu đáp án](07_DapAn.md#lt1-14)

<a id="lt1-15"></a>

## LT1-15

Một báo cáo thử nghiệm ghi: “A chạy trước, B chạy sau, cùng một biến mảng n phần tử; thời gian B bằng 60% A”. Không lưu bản đầu vào trước mỗi lần chạy; đồng hồ bao cả phần chuẩn bị và xuất kết quả. Tác giả kết luận B nên thay A. Bạn chỉ được bổ sung tối đa ba nhóm phép đo có đối chứng. Hãy thiết kế các nhóm đo để phân biệt lợi thế thuật toán với ảnh hưởng của dữ liệu đầu vào, thứ tự chạy và công việc ngoài thuật toán; nêu kết quả nào sẽ làm bạn bác bỏ kết luận ban đầu.

<details>
<summary>Câu hỏi tiếp — mở sau khi trả lời câu chính</summary>

Mỗi nhóm đo có thể lặp nhiều lần. Nêu dữ liệu phải lưu, tiêu chí đúng phải kiểm và giới hạn của kết luận ngay cả khi B thắng ở mọi mẫu đã đo.

</details>

[Đối chiếu đáp án](07_DapAn.md#lt1-15)

<a id="lt1-16"></a>

## LT1-16

*Suy luận nâng cao từ kiến thức đang ôn; không gán là yêu cầu nguyên văn của giáo trình.*

Một mảng động tăng từ rỗng bằng các lần thêm cuối. Cách A mỗi khi hết chỗ chỉ cấp đúng thêm một ô; cách B tăng gấp đôi sức chứa, bắt đầu từ một ô. Giả sử chuyển một phần tử O(1), không có xóa, bỏ qua chi phí hệ thống cấp phát. Với n lần thêm, hãy đánh giá tổng số phần tử bị chuyển và độ trễ xấu nhất của một lần. Khi tăng sức chứa, vì sao bộ nhớ đỉnh có thể lớn hơn sức chứa mảng mới?

[Đối chiếu đáp án](07_DapAn.md#lt1-16)

<a id="lt1-17"></a>

## LT1-17

Vòng ngoài có n lượt, mỗi lượt làm Θ(1) việc riêng. Chỉ số j bắt đầu từ 0, không bị đặt lại và tổng cộng tăng đúng s lần, s≤n. Phiên bản A: mỗi lần tăng j và mỗi lần kiểm điều kiện trong vòng trong tốn Θ(1). Phiên bản B: lần tăng tới giá trị j phải quét đúng j ô; mọi phần còn lại, kể cả kiểm điều kiện, vẫn Θ(1). Hãy tìm cận chặt theo n,s cho cả hai. Khi nào B vẫn có tổng chi phí tuyến tính theo n?

<details>
<summary>Câu hỏi tiếp — mở sau khi trả lời câu chính</summary>

Nếu sau mỗi lượt ngoài được đặt j về 0, phần nào trong chứng minh không còn dùng được? Phải đếm lại đại lượng nào?

</details>

[Đối chiếu đáp án](07_DapAn.md#lt1-17)

<a id="lt1-18"></a>

## LT1-18

Trong một phép đo giả định của chương trình xử lý tuần tự, nhập/xuất chiếm 60%, tìm kiếm 30%, sắp xếp 10% tổng thời gian. Ba phần không chồng lấp. Hai đề xuất độc lập: làm riêng phần sắp nhanh gấp 10, hoặc làm riêng phần tìm nhanh gấp 2; các phần còn lại giữ nguyên với cùng khối lượng công việc. Hãy chọn đề xuất giảm tổng thời gian nhiều hơn, tính mức tăng tốc toàn chương trình và kiểm lời hứa “chỉ cần tối ưu sắp đủ tốt là toàn chương trình nhanh gấp đôi”.

<details>
<summary>Câu hỏi tiếp — mở sau khi trả lời câu chính</summary>

Giả sử chỉ số truy vấn đổi khiến thời gian tìm kiếm trước tối ưu nhân t>0 lần, còn lượng nhập/xuất và sắp vẫn như cũ. Suy ra ngưỡng t làm lựa chọn giữa hai đề xuất đảo chiều. Những giả thiết nào cần đo lại trước khi dùng ngưỡng đó cho chương trình thật?

</details>

[Đối chiếu đáp án](07_DapAn.md#lt1-18)

<a id="lt1-19"></a>

## LT1-19

Một BST có 50.000 bản ghi, mỗi bản ghi đúng 64 byte, địa chỉ cố định trong suốt lúc lập báo cáo. Cần báo cáo theo tên mà không sửa cây. Bộ nhớ phụ tối đa 1 MiB=1.048.576 byte; một con trỏ 8 byte; dành cố định 32 KiB cho mọi biến/bộ đệm khác. Mọi vùng lớn được cấp đúng số ô nêu trong mô hình. Hãy chọn giữa sao chép toàn bộ bản ghi và lập một mảng tham chiếu, có tính bộ nhớ đỉnh khi duyệt cây có thể lệch hoàn toàn.

<details>
<summary>Câu hỏi tiếp — mở sau khi trả lời câu chính</summary>

Nếu dùng Merge Sort cần thêm mảng đệm bằng kích thước mảng tham chiếu, có nhất thiết vượt trần không? Phân tích thời điểm tồn tại các vùng nhớ và so với sắp tham chiếu bằng Heap Sort lặp; nêu điều kiện về ổn định và vòng đời đối tượng.

</details>

[Đối chiếu đáp án](07_DapAn.md#lt1-19)
