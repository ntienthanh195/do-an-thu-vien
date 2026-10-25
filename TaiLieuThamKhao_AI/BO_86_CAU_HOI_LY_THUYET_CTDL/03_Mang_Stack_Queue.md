# Chương III — Danh sách tuyến tính, Stack và Queue

[Về hướng dẫn](README.md) · [Đáp án riêng](07_DapAn.md)

**Nguồn phạm vi:** Chương III, mục I–IV: biểu diễn danh sách đặc bằng mảng, phép toán, Stack và Queue.

Tự trả lời bằng lời trước khi mở đáp án. Với câu chọn phương án, nêu điều kiện và đánh đổi; với câu truy vết, nêu trạng thái hoặc thứ tự cụ thể. Mỗi câu là một tình huống có các ý liên quan; phải bảo vệ kết luận bằng phản ví dụ, trạng thái hoặc lập luận chi phí theo đúng yêu cầu.

<a id="lt3-03"></a>

## LT3-03

Một mảng động chứa các con trỏ tới đối tượng đầu sách cấp phát riêng. Khi tăng sức chứa, chương trình cấp mảng ô con trỏ mới, sao chép các địa chỉ rồi giải phóng mảng ô cũ; các đối tượng đầu sách không được di chuyển hay xóa. Bên ngoài đang giữ ba thứ: chỉ số của một đầu sách, con trỏ tới đối tượng đó, và con trỏ tới ô chứa nó trong mảng cũ. Những thứ nào còn dùng được ngay sau tăng sức chứa? Nếu tiếp tục chèn đầu sách mới vào đầu mảng thì câu trả lời đổi ra sao?

[Đối chiếu đáp án](07_DapAn.md#lt3-03)

<a id="lt3-04"></a>

## LT3-04

Mảng tăng dần còn đủ chỗ. Nhóm thay bước tìm vị trí chèn tuyến tính bằng tìm nhị phân và kết luận xây n phần tử từ rỗng chỉ tốn O(n log n). Hãy chọn một thứ tự đưa khóa vào khiến kết luận sai, đếm số phần tử phải dịch trong cả chuỗi và nêu khi nào gom dữ liệu rồi sắp một lần là phương án hợp lệ. Đề yêu cầu mảng luôn tăng sau mỗi lần thêm thành công.

[Đối chiếu đáp án](07_DapAn.md#lt3-04)

<a id="lt3-05"></a>

## LT3-05

Mảng con trỏ đầu sách đang tăng theo tên An, Bình, Cường. Một báo cáo đã chụp thứ tự các con trỏ đó. Đối tượng Bình được sửa tên thành Z và mảng nguồn được đưa lại về đúng thứ tự; không có đối tượng nào bị xóa. Báo cáo cũ còn con trỏ hợp lệ không, còn tăng theo tên không, và có còn là ảnh dữ liệu ở lúc lập báo cáo không? Hãy chỉ ra ba yêu cầu khác nhau mà nhóm phải phân biệt khi nói “giữ bản báo cáo cũ”.

[Đối chiếu đáp án](07_DapAn.md#lt3-05)

<a id="lt3-08"></a>

## LT3-08

Queue vòng M ô dùng front là vị trí lấy tiếp, rear là vị trí thêm tiếp, count là số phần tử. Sau mỗi thao tác, bộ kiểm chỉ xác nhận 0≤count≤M, rear≡front+count (mod M) và tập đa trị các phần tử còn lại đúng. Các kiểm tra ấy đã đủ chứng minh FIFO chưa? Hãy tự dựng hai trạng thái vượt qua chúng nhưng có hành vi lấy tiếp khác nhau, rồi nêu thông tin kiểm chứng còn thiếu.

<details>
<summary>Câu hỏi tiếp — mở sau khi trả lời câu chính</summary>

Queue có M=5, front=4, rear=2, count=3; thứ tự logic A,B,C nằm ở các ô 4,0,1. Tăng sức chứa lên 8. Nếu giữ nguyên ô vật lý và các chỉ số rồi chỉ đổi phép modulo, điều gì sai? Đề xuất trạng thái mới đúng và nói rõ quyền thay đổi chỉ số khi đổi mảng.

</details>

[Đối chiếu đáp án](07_DapAn.md#lt3-08)

<a id="lt3-09"></a>

## LT3-09

Các phần tử 1,2,3,4,5 phải được push theo đúng thứ tự vào một Stack; được xen pop tùy lúc nhưng không được lấy giữa Stack hoặc dùng nơi chứa phụ. Có thể nhận thứ tự pop 3,1,2,5,4 không? Hãy chỉ đúng thời điểm bất khả thi, không chỉ trả lời “không”. Nếu sửa thành 3,2,1,5,4 thì hãy bảo vệ bằng một chuỗi thao tác và rút ra cách kiểm một hoán vị bất kỳ của 1…n trong O(n) thao tác Stack. Vì sao cách kiểm ấy không bỏ sót một cách xen push/pop khác có thể thành công?

[Đối chiếu đáp án](07_DapAn.md#lt3-09)

<a id="lt3-10"></a>

## LT3-10

*Suy luận nâng cao từ kiến thức đang ôn; không gán là yêu cầu nguyên văn của giáo trình.*

Một Queue được cài bằng hai Stack. Thêm phần tử vào Stack vào; khi lấy, nếu Stack ra rỗng thì chuyển hết phần tử từ Stack vào sang Stack ra rồi mới pop, còn Stack ra chưa rỗng thì pop trực tiếp. Hãy chứng minh FIFO qua một chuỗi có thêm xen giữa các lần lấy. Với m thao tác từ trạng thái rỗng, mỗi push/pop Stack O(1), hãy phân biệt chi phí xấu của một lần lấy với tổng chi phí cả chuỗi; không được dùng chữ “trung bình” mà không giải thích.

[Đối chiếu đáp án](07_DapAn.md#lt3-10)

<a id="lt3-13"></a>

## LT3-13

Cài Stack bằng hai Queue chỉ có thêm cuối/lấy đầu. Cách A khi push chuyển các phần tử cũ để phần tử mới đứng đầu Queue chính; cách B push thẳng cuối và khi pop mới chuyển hết trừ phần tử cuối sang Queue phụ. Hãy giải thích cách mỗi phương án giữ LIFO, so chi phí push/pop và tính cả chuỗi n push rồi n pop. Có thể kết luận cách A nhanh hơn chỉ vì pop O(1) không?

[Đối chiếu đáp án](07_DapAn.md#lt3-13)

<a id="lt3-14"></a>

## LT3-14

Thiết kế một Stack hỗ trợ push, pop và getMin; mỗi thao tác phải O(1) trong trường hợp xấu, kể cả khi có nhiều giá trị bằng nhau và các thao tác xen kẽ bất kỳ. Không được quét lại Stack sau pop. Các vùng lưu trữ đã đủ sức chứa, truy cập một ô/so một giá trị tốn O(1); pop và getMin trên Stack rỗng phải báo không có phần tử. Hãy tự chọn thông tin phụ, phát biểu bất biến và giải thích vì sao nó đủ để khôi phục min sau mọi lần pop, rồi phân tích bộ nhớ phụ.

<details>
<summary>Câu hỏi tiếp — mở sau khi trả lời câu chính</summary>

Một đề xuất tiết kiệm bộ nhớ chỉ lưu các lần xuất hiện min mới nhỏ hơn nghiêm ngặt; khi pop giá trị bằng min hiện tại thì bỏ mốc đó. Không lưu số lần min trùng. Tự dựng chuỗi ngắn bác bỏ đề xuất, rồi nêu một cách nén các min bằng nhau mà vẫn đúng. So lượng bộ nhớ phụ trên dãy toàn bằng với dãy giảm nghiêm ngặt.

</details>

[Đối chiếu đáp án](07_DapAn.md#lt3-14)

<a id="lt3-15"></a>

## LT3-15

Hai Stack chia sẻ mảng M ô, mỗi Stack chiếm một đoạn liên tục; phần tử đang sống không được di chuyển, không có liên kết riêng trong mỗi ô, chỉ được dùng O(1) biến chỉ số. Hãy thiết kế cách dùng được toàn bộ sức chứa: nếu tổng số phần tử nhỏ hơn M thì lần push vào bất kỳ Stack nào cũng thành công. Chứng minh điều kiện đầy và thời gian push/pop.

<details>
<summary>Câu hỏi tiếp — mở sau khi trả lời câu chính</summary>

Nếu tăng thành ba Stack và vẫn giữ mọi ràng buộc trên, một cách bố trí mỗi Stack thành một đoạn liên tục có luôn tận dụng được ô trống cho Stack được chọn không? Dựng một trạng thái cùng yêu cầu push làm rõ giới hạn; đừng suy rộng thành bất khả thi với mọi cách biểu diễn.

</details>

[Đối chiếu đáp án](07_DapAn.md#lt3-15)

<a id="lt3-16"></a>

## LT3-16

Mảng n bản ghi cần loại mọi bản ghi không thỏa điều kiện, giữ thứ tự tương đối của các bản ghi còn lại; điều kiện chỉ phụ thuộc nội dung bản ghi gốc. Cách A gặp một bản ghi cần bỏ thì xóa bằng dịch toàn bộ đuôi. Hãy dựng dữ liệu làm tổng công việc bậc hai, rồi nêu một bất biến cho cách nén tại chỗ chỉ tuyến tính. Khi lọc xong, những chỉ số cũ của bên ngoài có còn chỉ đúng bản ghi không?

[Đối chiếu đáp án](07_DapAn.md#lt3-16)

<a id="lt3-17"></a>

## LT3-17

Mảng chứa n>0 bản ghi ở đúng tiền tố 0…n−1, còn thứ tự giữa các bản ghi không có ý nghĩa. Đã biết chỉ số i cần xóa; di chuyển một bản ghi tốn O(1). Hãy đề xuất cách xóa O(1) vẫn giữ phần còn lại thành một tiền tố đặc, và nêu thông tin nào của các bản ghi còn sống có thể thay đổi.

<details>
<summary>Câu hỏi tiếp — mở sau khi trả lời câu chính</summary>

Bổ sung yêu cầu mọi bản ghi còn sống phải giữ nguyên chỉ số cũ, vẫn không được để lỗ trong tiền tố. Hai yêu cầu này có luôn cùng thỏa khi xóa ở giữa không? Dùng trường hợp nhỏ để bảo vệ kết luận và nêu một yêu cầu phải nới.

</details>

[Đối chiếu đáp án](07_DapAn.md#lt3-17)

<a id="lt3-18"></a>

## LT3-18

Nhóm muốn dùng chỉ số ô mảng làm mã bền vững cho đầu sách: xóa ô 3 thì lần thêm sau dùng lại mã 3. Một lịch sử cũ chỉ lưu mã đó. Hãy dựng chuỗi khiến lịch sử vẫn tra được một bản ghi nhưng lại chỉ nhầm đầu sách, kể cả khi không có lỗi truy cập bộ nhớ. Muốn dùng một vị trí lưu trữ làm định danh thì phải bổ sung hoặc thay đổi điều kiện gì, và ràng buộc của đề Thư viện cần được giữ ra sao?

[Đối chiếu đáp án](07_DapAn.md#lt3-18)

<a id="lt3-19"></a>

## LT3-19

Khi đổi biểu thức trung tố sang hậu tố, một quy tắc luôn đẩy toán tử đang chờ ra nếu ưu tiên của nó lớn hơn toán tử mới; quy tắc khác dùng lớn hơn hoặc bằng. Phép trừ kết hợp trái, lũy thừa ký hiệu ^ kết hợp phải theo toán học; ngoặc phải được tôn trọng. Có một trong hai quy tắc dùng nguyên xi đúng cho cả hai loại toán tử không? Tự tạo các biểu thức phân biệt và suy ra điều kiện xử lý khi hai ưu tiên bằng nhau.

<details>
<summary>Câu hỏi tiếp — mở sau khi trả lời câu chính</summary>

Vì sao chọn ví dụ 2^2^2 chưa đủ để kiểm tính kết hợp bằng kết quả số? Nêu một ví dụ khác thật sự phát hiện sai và nói rõ vai trò của ngoặc mở trong Stack toán tử.

</details>

[Đối chiếu đáp án](07_DapAn.md#lt3-19)

<a id="lt3-20"></a>

## LT3-20

Chuỗi chỉ gồm hai loại ngoặc () và []. Một bộ kiểm giữ hai bộ đếm riêng: ngoặc mở tăng bộ đếm tương ứng, ngoặc đóng giảm; từ chối nếu bộ đếm nào âm ở bất kỳ tiền tố nào, chấp nhận nếu cuối cùng cả hai bằng 0. Bộ kiểm có đủ xác nhận ngoặc lồng đúng không? Nếu không, hãy tìm phản ví dụ ngắn nhất và giải thích vì sao không thể ngắn hơn.

<details>
<summary>Câu hỏi tiếp — mở sau khi trả lời câu chính</summary>

Đề xuất lượng thông tin cần giữ để kiểm đúng thứ tự lồng; phát biểu bất biến và chi phí theo độ dài n, độ sâu lồng lớn nhất d. So với trường hợp chỉ có một loại ngoặc.

</details>

[Đối chiếu đáp án](07_DapAn.md#lt3-20)

<a id="lt3-21"></a>

## LT3-21

Một Queue chỉ công khai thêm cuối và lấy đầu; phần tử không có chỉ mục ngoài. Người dùng muốn hủy phần tử mang mã x ở giữa, giữ thứ tự mọi phần tử còn lại, và hứa O(1) thời gian cho mọi x. Hãy bác hoặc bảo vệ lời hứa theo đúng giao diện này. Nếu chuyển sang danh sách đơn có head/tail thì riêng việc có tail đã đủ chưa? Vì sao thêm khả năng hủy không còn là chỉ dùng FIFO thuần túy?

[Đối chiếu đáp án](07_DapAn.md#lt3-21)

<a id="lt3-22"></a>

## LT3-22

Mảng A có n≥1 phần tử tăng không giảm ở đầu và còn m≥1 ô trống phía sau; mảng B có m phần tử cũng tăng không giảm. Cần đưa toàn bộ vào A, giữ A trước B khi hai bản ghi bằng khóa và giữ thứ tự tương đối trong từng nguồn khi khóa bằng. So cách chèn lần lượt B từ trái sang phải bằng dịch đuôi, mỗi lần chèn sau các bản ghi cùng khóa đã có, với cách trộn từ cuối về đầu. Hãy tính chi phí theo n,m, rồi phân biệt chặn trên theo tổng N=n+m với điều kiện đạt bậc hai theo N. Bảo vệ việc không ghi đè dữ liệu A chưa đọc và quyết định lấy nguồn nào trước khi hai khóa bằng nhau ở bước đi từ cuối. Giả sử A và B không dùng chung vùng nhớ, mỗi lần so/chuyển bản ghi tốn O(1).

[Đối chiếu đáp án](07_DapAn.md#lt3-22)
