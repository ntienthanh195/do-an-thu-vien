# Chương V — Cây, BST và AVL

[Về hướng dẫn](README.md) · [Đáp án riêng](07_DapAn.md)

**Nguồn phạm vi:** Chương V, mục I–III: khái niệm và biểu diễn cây, cây nhị phân, phép duyệt, BST, AVL.

Tự trả lời bằng lời trước khi mở đáp án. Với câu chọn phương án, nêu điều kiện và đánh đổi; với câu truy vết, nêu trạng thái hoặc thứ tự cụ thể. Mỗi câu là một tình huống có các ý liên quan; phải bảo vệ kết luận bằng phản ví dụ, trạng thái hoặc lập luận chi phí theo đúng yêu cầu.

<a id="lt5-04"></a>

## LT5-04

Biểu diễn cây nhị phân bằng vị trí mảng: gốc ở 0, con trái 2i+1, con phải 2i+2. Với n nút xếp thành một chuỗi chỉ có con phải, hãy suy ra chỉ số nút cuối và số ô cần để giữ cách đánh số này. So với cây hoàn chỉnh n nút, vì sao câu “mảng chỉ cần n ô và luôn ít bộ nhớ hơn con trỏ” sai? Nếu n=20, khoảng trống đã lớn tới đâu?

[Đối chiếu đáp án](07_DapAn.md#lt5-04)

<a id="lt5-06"></a>

## LT5-06

So sánh hai cây có cùng số nút gần n: một cây nhị phân hoàn hảo và một cây là chuỗi lệch. Với DFS đệ quy thông thường và BFS dùng Queue, mỗi nút làm O(1) việc, hãy đánh giá thời gian và đỉnh bộ nhớ phụ trên từng cây. Một bạn muốn đổi DFS sang BFS chỉ vì sợ stack sâu: điều gì được giải quyết và rủi ro bộ nhớ nào có thể xuất hiện ở hình dạng khác?

[Đối chiếu đáp án](07_DapAn.md#lt5-06)

<a id="lt5-07"></a>

## LT5-07

Bộ kiểm BST chỉ so mỗi nút với hai con trực tiếp; tất cả phép so đều đúng. Hãy tạo cây ba nút khiến bộ kiểm vẫn chấp nhận sai. Sau đó đổi chính sách thành khóa trùng chỉ được nằm bên phải: mọi khóa cây trái < gốc, mọi khóa cây phải ≥ gốc. Kiểm dãy LNR không giảm có đủ xác nhận chính sách mới không? Hãy cho phản ví dụ hoặc chứng minh.

[Đối chiếu đáp án](07_DapAn.md#lt5-07)

<a id="lt5-08"></a>

## LT5-08

Cây BST thường đang có hình dạng tốt. Nhóm lưu các bản ghi theo LNR, rồi nạp lại bằng cách chèn lần lượt theo đúng thứ tự file. Khóa không trùng và file có n bản ghi tăng dần. Vì sao dữ liệu vẫn đủ, thứ tự LNR vẫn đúng nhưng hiệu năng có thể hỏng? Tính tổng chi phí dựng lại bằng cách đó và nêu một hướng dựng khác giữ BST mà không tự bổ sung cơ chế AVL vào cấu trúc.

[Đối chiếu đáp án](07_DapAn.md#lt5-08)

<a id="lt5-10"></a>

## LT5-10

Nút mã 40 thuộc An, sở hữu lịch sử A; nút kế tiếp mã 45 thuộc Bình, sở hữu lịch sử B. Khi xóa An bằng cách dùng nút kế tiếp, nhóm chỉ chép maThe=45 vào nút An rồi xóa nút Bình cùng lịch sử B. Cây còn thỏa thứ tự mã và tìm mã 40 trả không có. Hãy chỉ ra dữ liệu nào sai, trạng thái danh tính–lịch sử đúng phải là gì và vì sao một kiểm tra BST đơn thuần không bắt được lỗi này.

[Đối chiếu đáp án](07_DapAn.md#lt5-10)

<a id="lt5-11"></a>

## LT5-11

Một BST theo mã thẻ được dùng để tìm tên An. Người viết so An với tên ở nút hiện tại rồi chỉ đi trái hoặc phải như tìm theo mã; vài bộ dữ liệu mẫu đều đúng. Hãy tạo cây ba nút làm cách đó bỏ sót An. Nếu truy vấn đổi thành liệt kê các mã trong [a,b], khi nào được loại cây con, và vì sao kết luận “mọi phép lọc đều phải duyệt toàn cây” cũng quá mạnh?

[Đối chiếu đáp án](07_DapAn.md#lt5-11)

<a id="lt5-14"></a>

## LT5-14

Cây cần sửa cân bằng có gốc 30, trái 10, phải 40; nút 10 có trái 5, phải 20; nút 20 có trái 15, phải 25. Các cây con của 30 đều là AVL, h(rỗng)=0. Hãy xác định cách phục hồi AVL tại 30, vẽ cây cuối và chỉ rõ số phận của hai cây con 15,25. Bảo vệ kết quả bằng cả thứ tự LNR lẫn chiều cao, đồng thời giải thích vì sao chỉ kiểm hai giá trị ở gốc phép quay chưa đủ.

[Đối chiếu đáp án](07_DapAn.md#lt5-14)

<a id="lt5-15"></a>

## LT5-15

AVL ban đầu có gốc 4; trái 2 với hai con 1,3; phải 6 là lá. Xóa 6, rồi xét cân bằng tại 4 với h(rỗng)=0. Một bạn chỉ biết quy tắc chọn quay từ hướng chèn và lúng túng khi hệ số cân bằng của nút 2 bằng 0. Hãy đưa cây sau cân bằng, so chiều cao trước xóa với sau cân bằng và giải thích ý nghĩa của việc chiều cao có hoặc không giảm đối với tổ tiên của cây con này.

[Đối chiếu đáp án](07_DapAn.md#lt5-15)

<a id="lt5-17"></a>

## LT5-17

Với cây nhị phân có các nhãn phân biệt, hai dãy NLR=A,B,D,E,C và LNR=D,B,E,A,C xác định cây nào? Hãy giải thích vì sao cách tách theo gốc cho phép xác định duy nhất. Nếu chỉ có NLR=A,B và LRN=B,A thì có duy nhất không? Nếu nhãn được phép trùng, điều kiện nào của lập luận dùng NLR và LNR bị mất?

[Đối chiếu đáp án](07_DapAn.md#lt5-17)

<a id="lt5-18"></a>

## LT5-18

*Suy luận nâng cao từ kiến thức đang ôn; không gán là yêu cầu nguyên văn của giáo trình.*

Cần tìm độc giả có mã đứng thứ k theo thứ tự tăng trong BST, không có sẵn số nút mỗi cây con. Một bạn nói “cây có chiều cao logarit nên tìm hạng k cũng O(log R)”. Hãy chỉ ra thông tin còn thiếu. Nếu chỉ để so sánh thiết kế, cho phép lưu kích thước cây con thì có thể chọn nhánh thế nào, và những thao tác nào phải duy trì thông tin đó?

[Đối chiếu đáp án](07_DapAn.md#lt5-18)

<a id="lt5-19"></a>

## LT5-19

Muốn liệt kê toàn bộ mã tăng dần, một cách tìm nút nhỏ nhất rồi liên tục tìm nút kế tiếp bằng cách khởi động lại từ gốc; một cách khác dùng một lần duyệt LNR với trạng thái chờ. Hãy phân tích tổng chi phí có thể đạt của cách thứ nhất trên cây lệch và cây cân bằng, rồi giải thích vì sao duyệt một lần có thể tuyến tính. Khi một nút không có cây con phải, vì sao nút kế tiếp không đơn giản là nút cha bất kỳ?

[Đối chiếu đáp án](07_DapAn.md#lt5-19)

<a id="lt5-20"></a>

## LT5-20

BST có gốc 20, trái 10, phải 30 với trái 25 và phải 40. Trước khi xóa các mã 20 và 25, nhóm chụp hai con trỏ tới hai nút đó. Hàm xóa nút hai con dùng cách chép toàn bộ bản ghi kế tiếp vào nút bị xóa rồi giải phóng nút kế tiếp. Sau khi xóa 20, có còn được dùng con trỏ đã chụp tới 25 để xóa lần tiếp không? So với chụp các mã cần xóa và tìm lại từng mã, hãy phân biệt hai hợp đồng.

[Đối chiếu đáp án](07_DapAn.md#lt5-20)

<a id="lt5-21"></a>

## LT5-21

Một cây là chuỗi trái bốn nút. Trường height của mọi nút đều bị ghi thành 1. Bộ kiểm AVL chỉ lấy height lưu trong hai nút con để kiểm độ chênh không quá một, không kiểm chính height của nút hiện tại. Vì sao tất cả các kiểm tra cục bộ ấy có thể qua dù cây không là AVL? Hãy nêu cách kiểm độc lập vừa xác nhận hình dạng vừa xác nhận metadata, và so với việc tính lại chiều cao toàn cây con ở từng nút.

[Đối chiếu đáp án](07_DapAn.md#lt5-21)

<a id="lt5-22"></a>

## LT5-22

Một BST cho khóa trùng nhưng bắt buộc mọi khóa bằng gốc chỉ nằm bên phải. Ba nút cùng khóa 2 được chèn thành chuỗi phải; nhóm muốn cân bằng bằng quay trái như AVL thông thường. Hãy vẽ cây sau quay và chỉ ra xung đột giữa bất biến trùng một phía và cân bằng. Với rất nhiều khóa đều bằng nhau, hai yêu cầu này có thể cùng giữ nếu vẫn lưu mỗi phần tử thành một nút riêng với đúng phép so khóa gốc không?

[Đối chiếu đáp án](07_DapAn.md#lt5-22)

<a id="lt5-24"></a>

## LT5-24

*Suy luận nâng cao từ kiến thức đang ôn; không gán là yêu cầu nguyên văn của giáo trình.*

Dùng h(rỗng)=0, h(lá)=1. Gọi N(h) là số nút ít nhất của một AVL cao h. Hãy tự suy ra quan hệ giữa N(h), N(h−1), N(h−2), tính đủ để trả lời một AVL có 20 nút có thể cao 7 không, rồi giải thích vì sao điều kiện AVL dẫn tới chiều cao O(log R). Không được chỉ viện dẫn kết luận đã học thuộc.

[Đối chiếu đáp án](07_DapAn.md#lt5-24)

<a id="lt5-25"></a>

## LT5-25

Một BST thường có R khóa phân biệt, ban đầu cao O(log R). Cần xóa một lô m mã phân biệt đang tồn tại, 0≤m≤R, đã cho theo thứ tự tăng nghiêm ngặt; không có chèn xen vào. So cách tìm rồi xóa từng mã với cách duyệt cây một lượt, bỏ các mã thuộc lô và dựng lại BST từ những nút còn lại. Hãy phân tích chi phí, chọn theo m và chỉ ra dữ liệu tạm của phương án dựng lại.

<details>
<summary>Câu hỏi tiếp — mở sau khi trả lời câu chính</summary>

Bên ngoài có thể giữ con trỏ tới các nút sẽ sống sau lô xóa. Muốn giữ địa chỉ các nút ấy, phương án dựng lại phải làm gì? Việc giữ địa chỉ có đồng nghĩa một phép duyệt đang dở vẫn tiếp tục được như cũ không?

</details>

[Đối chiếu đáp án](07_DapAn.md#lt5-25)

<a id="lt5-26"></a>

## LT5-26

Xét lựa chọn cấu trúc ngoài phạm vi thay đổi bản nộp: mảng con trỏ đã tăng theo mã, BST thường và AVL. Chế độ A có dữ liệu gần như cố định, nhiều truy vấn mã chính xác và liệt kê khoảng mã, cập nhật được gom theo lô. Chế độ B nhận chèn/xóa trực tuyến với thứ tự khóa bất kỳ, có thể tăng dần, và cần chặn xấu nhất cho từng thao tác theo khóa. Hãy chọn có điều kiện cho từng chế độ, giải thích vì sao cùng lời quảng cáo “tìm O(log R)” chưa đủ quyết định.

<details>
<summary>Câu hỏi tiếp — mở sau khi trả lời câu chính</summary>

Mỗi đối tượng được cấp riêng và cần giữ địa chỉ khi còn sống. Mảng con trỏ có bị loại chỉ vì phải dịch ô khi chèn không? Còn điều gì cần cân nhắc nếu chuyển lựa chọn này sang đề Thư viện?

</details>

[Đối chiếu đáp án](07_DapAn.md#lt5-26)

<a id="lt5-27"></a>

## LT5-27

Hai BST có khóa phân biệt trong từng cây nhưng hình dạng có thể khác nhau. Cần kiểm chúng chứa cùng các bản ghi theo mã và nội dung, không cần giống hình dạng. Không được sửa cây hoặc tạo mảng chứa toàn bộ bản ghi; được dùng O(h_1+h_2) bộ nhớ phụ theo hai chiều cao. Hãy đề xuất cách so sánh, điều kiện kết luận khác nhau và phân tích chi phí.

<details>
<summary>Câu hỏi tiếp — mở sau khi trả lời câu chính</summary>

Vì sao so đệ quy các nút ở cùng vị trí có thể từ chối sai? Nếu hai dãy mã giống hệt nhưng dữ liệu lịch sử của một mã khác nhau, phép so phải làm thêm gì và cận thời gian cần diễn đạt thế nào?

</details>

[Đối chiếu đáp án](07_DapAn.md#lt5-27)
