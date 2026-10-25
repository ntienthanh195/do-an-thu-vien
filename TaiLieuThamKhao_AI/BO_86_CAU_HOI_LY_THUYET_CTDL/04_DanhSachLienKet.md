# Chương IV — Danh sách liên kết

[Về hướng dẫn](README.md) · [Đáp án riêng](07_DapAn.md)

**Nguồn phạm vi:** Chương IV, mục I–VI: đơn, có thứ tự, vòng, kép, Stack và Queue trên danh sách liên kết.

Tự trả lời bằng lời trước khi mở đáp án. Với câu chọn phương án, nêu điều kiện và đánh đổi; với câu truy vết, nêu trạng thái hoặc thứ tự cụ thể. Mỗi câu là một tình huống có các ý liên quan; phải bảo vệ kết luận bằng phản ví dụ, trạng thái hoặc lập luận chi phí theo đúng yêu cầu.

<a id="lt4-03"></a>

## LT4-03

Danh sách đơn A→B→C; chỉ có con trỏ p tới A, không có nút trước. Có con trỏ ngoài q tới đúng đối tượng B và q phải tiếp tục chỉ B sau khi xóa A. Một mẹo đề xuất sao chép nội dung B vào A rồi hủy nút B để đạt O(1). Cách đó có đáp ứng hợp đồng không? Nếu chỉ nhìn dãy giá trị in ra thì có thể bỏ sót điều gì? Hãy xét thêm trường hợp p là nút cuối.

[Đối chiếu đáp án](07_DapAn.md#lt4-03)

<a id="lt4-04"></a>

## LT4-04

Hai danh sách đơn tách rời: L1=A→B→C→D, L2=X→Y; mỗi danh sách có head,tail và số lượng. Cần chuyển nguyên đoạn B→C từ L1 sang cuối L2, giữ địa chỉ mọi nút và không cấp nút mới. Hãy mô tả trạng thái cuối, các bất biến cần kiểm và lý do chỉ kiểm số lượng là chưa đủ. Nếu đoạn chuyển là toàn bộ L1 và L2 ban đầu rỗng, những đầu quản lý nào thay đổi?

[Đối chiếu đáp án](07_DapAn.md#lt4-04)

<a id="lt4-05"></a>

## LT4-05

Danh sách có head và tail chứa A,B,C,D; A,B,D cần bị loại, chỉ C được giữ. Một cách duyệt sau mỗi lần xóa lại tiến thêm một nút và cập nhật “nút trước” như thể nút vừa xóa còn tồn tại. Hãy chỉ ra hai kiểu lỗi có thể xảy ra, nêu trạng thái cuối đúng và phát biểu một bất biến đủ giúp duyệt/xóa cả các nút liên tiếp mà không bỏ sót. Trường hợp mọi nút đều bị loại phải thỏa điều gì?

[Đối chiếu đáp án](07_DapAn.md#lt4-05)

<a id="lt4-07"></a>

## LT4-07

Tìm nhị phân trên danh sách đơn đã tăng: cách A mỗi lần tìm giữa bằng cách đi từ đầu của đoạn ứng viên hiện tại, cách B luôn đi từ head toàn danh sách tới chỉ số giữa toàn cục. Biết sẵn độ dài đoạn, đi một liên kết và so một khóa đều O(1). Với truy vấn lớn hơn mọi khóa, hãy đánh giá số lần so sánh và số bước đi liên kết của mỗi cách. Có cách nào trong hai cách bảo đảm thời gian O(log n) không?

[Đối chiếu đáp án](07_DapAn.md#lt4-07)

<a id="lt4-09"></a>

## LT4-09

Cần trộn hai danh sách tăng bằng cách nối lại các nút, không cấp nút mới, và kết quả phải là một danh sách tăng độc lập. Người gọi đồng thời yêu cầu hai danh sách nguồn vẫn giữ nguyên toàn bộ liên kết để tiếp tục dùng. Các yêu cầu này có tương thích nói chung không? Xét thêm đầu vào L1=1→4→7 và L2=2→4→7, trong đó hai nút 4 và 7 thực sự dùng chung địa chỉ, không phải bản sao. Điều kiện nào của phép trộn thông thường đã bị vi phạm?

[Đối chiếu đáp án](07_DapAn.md#lt4-09)

<a id="lt4-10"></a>

## LT4-10

Danh sách vòng chỉ giữ tail; nếu không rỗng thì head được suy ra là nút sau tail. Ban đầu vòng A→B→C→A, tail=C. Một vòng duyệt nhớ head=A làm mốc kết thúc nhưng xóa và giải phóng A ngay lần đầu. Vì sao “cứ đi tới khi gặp lại địa chỉ A” không còn là lập luận đúng? Hãy nêu một cách xác định phạm vi duyệt an toàn bằng lời, rồi xử lý riêng việc xóa nút duy nhất.

[Đối chiếu đáp án](07_DapAn.md#lt4-10)

<a id="lt4-15"></a>

## LT4-15

Danh sách đơn gồm các đối tượng A→B→C→D→E→F; cần đảo thứ tự đoạn B…E nhưng giữ nguyên địa chỉ và nội dung từng đối tượng. Bên ngoài có con trỏ tới C. Một bạn đổi nội dung B với E, C với D thay vì đổi liên kết, vì kết quả in tên giống yêu cầu. Hãy nêu chuỗi nút cuối đúng, phân tích điều gì bên ngoài sẽ quan sát khác và chỉ ra hai ranh giới của đoạn cần được nối đúng khi đảo bằng liên kết.

[Đối chiếu đáp án](07_DapAn.md#lt4-15)

<a id="lt4-16"></a>

## LT4-16

*Suy luận nâng cao từ kiến thức đang ôn; không gán là yêu cầu nguyên văn của giáo trình.*

Danh sách đi từ A→B→C→D→E→F rồi F nối về C. Hai con trỏ cùng bắt đầu ở A, mỗi lượt một con đi một liên kết, con kia đi hai. Hãy xác định lần gặp đầu sau khi bắt đầu di chuyển và cho biết đó có phải luôn là điểm vào vòng không. Sau khi gặp, đặt một con về A, con kia giữ ở chỗ gặp rồi cho cả hai đi từng bước: vì sao cách này xác định được điểm vào vòng?

[Đối chiếu đáp án](07_DapAn.md#lt4-16)

<a id="lt4-17"></a>

## LT4-17

*Suy luận nâng cao từ kiến thức đang ôn; không gán là yêu cầu nguyên văn của giáo trình.*

Hai danh sách đơn không vòng có thể dùng chung một đoạn đuôi; nội dung các nút có thể trùng dù địa chỉ khác. Không được sửa liên kết hoặc đánh dấu vào nút. Biết độ dài hai danh sách là m và n, hãy tìm cách xác định nút chung đầu tiên trong O(m+n) thời gian và O(1) bộ nhớ phụ, đồng thời giải thích vì sao so giá trị hoặc cứ đi hai con trỏ từ hai head cùng tốc độ có thể sai.

[Đối chiếu đáp án](07_DapAn.md#lt4-17)

<a id="lt4-18"></a>

## LT4-18

Hai danh sách vòng đơn tách rời, mỗi danh sách chỉ giữ tail: vòng thứ nhất A→B→C→A, tail=C; vòng thứ hai D→E→D, tail=E. Cần nối thành một vòng theo thứ tự A,B,C,D,E mà không cấp nút. Hãy nêu quan hệ liên kết cuối và giải thích vì sao thao tác có thể O(1) khi đã có hai tail. Nếu hai tail thực ra thuộc cùng một vòng, tiền điều kiện nào mất đi và việc kiểm tiền điều kiện có còn tự O(1) không?

[Đối chiếu đáp án](07_DapAn.md#lt4-18)

<a id="lt4-20"></a>

## LT4-20

Mỗi nút danh sách ngoài sở hữu một danh sách con riêng. Một bản sao mới đã cấp nút ngoài mới và nối next mới, nhưng chỉ sao chép địa chỉ danh sách con của từng nút. Nhóm gọi đây là “sao chép sâu vì các nút ngoài khác địa chỉ”. Hãy đưa hai phép thử bằng lời có thể bác bỏ tính độc lập, nêu phạm vi tài nguyên cần xét và yêu cầu xử lý nếu sao chép thất bại giữa danh sách con thứ hai.

[Đối chiếu đáp án](07_DapAn.md#lt4-20)

<a id="lt4-21"></a>

## LT4-21

Hai danh sách kép vòng tách rời có lính canh S₁,S₂ và biến count chỉ đếm bản ghi. Ban đầu L₁ có A,B,C theo chiều next; L₂ rỗng. Thực hiện lần lượt: chuyển đoạn B…C từ L₁ vào ngay trước S₂; sau đó chuyển A từ L₁ vào ngay trước B của L₂. Không cấp/hủy nút, địa chỉ và nội dung bản ghi giữ nguyên. Hãy nêu cấu trúc cả hai chiều và count sau từng bước, rồi phát biểu bất biến để nguồn rỗng vẫn là cấu trúc hợp lệ. Đã biết hai đầu đoạn và điểm chèn, nhưng chưa biết số nút của một đoạn bất kỳ: lời hứa “toàn phép chuyển luôn O(1)” có đúng khi phải cập nhật count không?

<details>
<summary>Câu hỏi tiếp — mở sau khi trả lời câu chính</summary>

Mở rộng thao tác sang chuyển đoạn trong cùng một danh sách. Hợp đồng yêu cầu không làm gì nếu điểm chèn p nằm trong đoạn; đầu/cuối đoạn được bảo đảm hợp lệ, nhưng chưa có thông tin p có thuộc đoạn hay không. Cần kiểm gì trước khi thay liên kết? Phân biệt chi phí kiểm điều kiện, cập nhật count và nối lại. Xét thêm trường hợp p là nút ngay sau đoạn.

</details>

[Đối chiếu đáp án](07_DapAn.md#lt4-21)

<a id="lt4-22"></a>

## LT4-22

Có K danh sách đã tăng, mỗi danh sách dài s, các tập nút tách rời; K là lũy thừa hai và tổng H=Ks. Mỗi phép trộn tốn theo tổng độ dài hai nguồn trong trường hợp xấu. So cách trộn lần lượt một danh sách mới vào kết quả đang lớn dần với cách ghép từng cặp thành nhiều vòng. Hãy tính tổng công việc và giải thích vì sao mọi phép trộn riêng đều tuyến tính nhưng toàn quá trình có thể khác bậc theo K.

[Đối chiếu đáp án](07_DapAn.md#lt4-22)

<a id="lt4-23"></a>

## LT4-23

Một vòng duyệt danh sách trước khi xử lý nút hiện tại đã giữ con trỏ next, rồi gọi một thao tác được phép xóa bất kỳ nút nào trong danh sách. Người viết cho rằng giữ next là đủ tránh mọi lỗi khi tiếp tục. Hãy tạo trường hợp thao tác được gọi làm con trỏ đã giữ mất hiệu lực, rồi nêu một hợp đồng hạn chế hoặc cách tổ chức xử lý giúp lập luận an toàn. Chỉ xét thực hiện tuần tự trong một tiến trình.

[Đối chiếu đáp án](07_DapAn.md#lt4-23)

<a id="lt4-24"></a>

## LT4-24

Một cấu trúc cần duyệt qua lại theo con trỏ hiện tại và xóa chính nút đó, kể cả nút cuối; bên gọi chỉ đưa con trỏ tới nút, không đưa nút trước. Mỗi thao tác phải O(1), địa chỉ và nội dung của mọi nút còn sống phải giữ nguyên. Hãy so danh sách đơn có head/tail, danh sách kép và mảng đặc lưu trực tiếp bản ghi trong một tiền tố liên tục (không phải mảng con trỏ, không có lớp định vị phụ) để chọn phương án đáp ứng; nói rõ thông tin nào tạo ra khác biệt.

<details>
<summary>Câu hỏi tiếp — mở sau khi trả lời câu chính</summary>

Đổi hợp đồng: không cần bước lùi nữa, khi xóa bên gọi luôn đưa đúng nút trước còn hợp lệ hoặc xác nhận nút cần xóa là head. Khi ấy lựa chọn có thay đổi không? Liên hệ với danh sách đơn cuốn/lịch sử của đề Thư viện mà không tự thay cấu trúc bắt buộc.

</details>

[Đối chiếu đáp án](07_DapAn.md#lt4-24)

<a id="lt4-25"></a>

## LT4-25

n đối tượng tồn tại duy nhất, địa chỉ ổn định, mỗi đối tượng chỉ có một trường next; không được sửa cấu trúc bản ghi hay thứ tự danh sách nguồn. Cần giữ đồng thời hai cách duyệt theo hai khóa khác nhau, hai thứ tự có thể không trùng. Được cấp thêm tối đa 2n ô con trỏ. Hãy chọn cách biểu diễn hai cách duyệt, giải thích vì sao chỉ giữ hai con trỏ đầu trên cùng các next thường không đủ, và phân biệt bản nhìn theo thứ tự với bản sao dữ liệu.

<details>
<summary>Câu hỏi tiếp — mở sau khi trả lời câu chính</summary>

Sau khi lập hai cách duyệt, một đối tượng bị xóa hoặc sửa khóa. Những nghĩa vụ nào phát sinh để lần duyệt tiếp không đọc dữ liệu đã giải phóng hoặc dùng thứ tự lỗi thời? Nêu giới hạn của ngân sách nếu muốn đóng băng cả nội dung cũ.

</details>

[Đối chiếu đáp án](07_DapAn.md#lt4-25)
