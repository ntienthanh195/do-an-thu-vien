# Chương VI — Sắp xếp và tìm kiếm

[Về hướng dẫn](README.md) · [Đáp án riêng](07_DapAn.md)

**Nguồn phạm vi:** Chương VI, mục I–V: các tình huống về Bubble, Insertion, Selection, Quick, Heap, Merge; tìm tuần tự và nhị phân, khóa sắp xếp và chi phí đầu ra.

Tự trả lời bằng lời trước khi mở đáp án. Với câu chọn phương án, nêu điều kiện và đánh đổi; với câu truy vết, nêu trạng thái hoặc thứ tự cụ thể. Mỗi câu là một tình huống có các ý liên quan; phải bảo vệ kết luận bằng phản ví dụ, trạng thái hoặc lập luận chi phí theo đúng yêu cầu.

<a id="lt6-01"></a>

## LT6-01

Bốn bản ghi độc giả theo thứ tự ban đầu: (mã 40,họ Trần,tên An), (10,Lê,Bình), (30,Lê,An), (20,Lê,An). Cần tăng theo tên rồi họ, và giữ thứ tự ban đầu giữa các bản ghi bằng cả tên lẫn họ. So hai cách: sắp ổn định theo họ rồi ổn định theo tên; hoặc sắp theo tên–họ–mã bằng một thuật toán bất kỳ. Giả sử Lê đứng trước Trần, An trước Bình. Hãy tính hai thứ tự mã và giải thích vì sao kết quả nhìn “có thứ tự hơn” chưa chắc đúng hợp đồng.

[Đối chiếu đáp án](07_DapAn.md#lt6-01)

<a id="lt6-03"></a>

## LT6-03

Dãy 2,3,…,n,1 chỉ có một phần tử lệch vị trí. So Insertion Sort chèn vào tiền tố với Bubble Sort quét từ trái sang phải, đưa phần tử lớn về cuối; Bubble có cờ dừng và thu ngắn đuôi đã cố định. Hãy đếm theo bậc số dịch/đổi chỗ và số so sánh, giải thích vì sao nhận xét “gần tăng nên cả hai tuyến tính” sai. Nếu đổi thành n,1,2,…,n−1, hành vi Bubble thay đổi ra sao?

[Đối chiếu đáp án](07_DapAn.md#lt6-03)

<a id="lt6-05"></a>

## LT6-05

Selection Sort thông thường tìm phần tử nhỏ nhất ở phần chưa sắp rồi đổi chỗ xa. Với 2a,2b,1, a và b chỉ đánh dấu thứ tự của hai khóa bằng nhau, hãy chứng minh có thể mất ổn định. Nếu thay đổi chỗ bằng cách rút phần tử nhỏ nhất đầu tiên rồi dịch đoạn trước nó để chèn vào đầu vùng chưa sắp, điều gì được cải thiện và chi phí di chuyển xấu nhất thay đổi thế nào? Có còn dùng lý do “Selection ít di chuyển” để chọn biến thể này không?

[Đối chiếu đáp án](07_DapAn.md#lt6-05)

<a id="lt6-06"></a>

## LT6-06

Quick Sort chọn phần tử giữa theo chỉ số làm pivot. Hãy cho một mảng có ít nhất năm khóa phân biệt khiến pivot đó là khóa nhỏ nhất, rồi giải thích vì sao chọn chỉ số giữa không bảo đảm chia cân bằng. Nếu một phiên bản chỉ gọi đệ quy vào phần nhỏ hơn và xử lý phần lớn hơn bằng vòng lặp, hãy bảo vệ cận stack O(log n) và cho biết thời gian xấu nhất có nhờ vậy thành O(n log n) không.

[Đối chiếu đáp án](07_DapAn.md#lt6-06)

<a id="lt6-08"></a>

## LT6-08

Xét phân hoạch đoạn chỉ số đóng [l,r], r>l, chọn và giữ cố định giá trị pivot ở chỉ số giữa. Ban đầu i=l,j=r. Mỗi lượt khi i≤j: quét i sang phải, rồi quét j sang trái; mọi bước quét đều kiểm i≤j trước khi đọc ô. Nếu sau hai lượt quét vẫn i≤j thì đổi A[i],A[j], sau đó tăng i và giảm j. Cách A quét qua khóa <pivot ở trái và >pivot ở phải; cách B thay hai dấu ấy bằng ≤ và ≥. Sau khi i>j, Quick Sort gọi lại [l,j] và [i,r] nếu đoạn tương ứng có ít nhất hai phần tử. Hãy đánh giá riêng từng cách về: phân hoạch có dừng, giữ quan hệ khóa hai phía, và bảo đảm các lời gọi con nhỏ hơn bài toán cha. Tự dựng phản ví dụ nếu một bảo đảm thất bại.

<details>
<summary>Câu hỏi tiếp — mở sau khi trả lời câu chính</summary>

Trên n khóa đều bằng pivot, hãy so hành vi của hai cách và phân tích thời gian Quick Sort của cách tiếp tục được. Từ đó có được kết luận cách ấy luôn chia cân bằng trên mọi dữ liệu không?

</details>

[Đối chiếu đáp án](07_DapAn.md#lt6-08)

<a id="lt6-10"></a>

## LT6-10

Cần xây max-heap từ mảng 1,2,3,4,5,6,7. Thủ tục điều chỉnh xuống chọn con lớn hơn và tiếp tục xuống cho tới đúng vị trí, nhưng chỉ có bảo đảm khi hai cây con đã là heap. Một bạn gọi nó theo thứ tự nút trong từ gốc xuống dưới, mỗi nút đúng một lần. Hãy truy vết để tìm quan hệ heap cuối cùng còn sai, rồi giải thích vì sao làm từ dưới lên đúng tiền điều kiện và vì sao tổng xây heap có thể O(n), dù một lần điều chỉnh có thể O(log n).

[Đối chiếu đáp án](07_DapAn.md#lt6-10)

<a id="lt6-11"></a>

## LT6-11

Ở một bước Heap Sort tăng dần, mảng được chia thành tiền tố đang xử lý và hậu tố đã chốt. Bộ kiểm chỉ xác nhận tiền tố là max-heap và hậu tố đã tăng. Hai điều đó có đủ bảo đảm sau khi sắp xong tiền tố, toàn mảng sẽ đúng không? Tự dựng một trạng thái vượt qua kiểm tra nhưng không thể hoàn tất đúng nếu chỉ tiếp tục xử lý tiền tố; bổ sung bất biến còn thiếu.

<details>
<summary>Câu hỏi tiếp — mở sau khi trả lời câu chính</summary>

Nếu cần Heap Sort giảm dần, hãy nêu loại heap và quan hệ giữa hai vùng. Việc đổi các dấu so phải bảo vệ cả thứ tự lẫn bảo toàn bản ghi như thế nào?

</details>

[Đối chiếu đáp án](07_DapAn.md#lt6-11)

<a id="lt6-12"></a>

## LT6-12

Một Merge Sort từ dưới lên đã qua kiểm thử hàm trộn hai đoạn với vùng đệm riêng. Tuy nhiên ở lượt độ dài s=4 trên n=11 phần tử, các đoạn đầu vào dài 4,4,3 đều tăng, mọi lần gọi hàm trộn đều cho kết quả đúng, nhưng mảng sau cả lượt không còn là hoán vị đầu vào. Hãy đề xuất một lỗi điều phối có thể gây triệu chứng này, tự dựng dữ liệu 11 phần tử và truy vết đủ để phân biệt lỗi điều phối với lỗi trong hàm trộn.

<details>
<summary>Câu hỏi tiếp — mở sau khi trả lời câu chính</summary>

Nêu bất biến của toàn lượt và nhóm kích thước kiểm thử giúp phát hiện lỗi dù các mẫu n là lũy thừa hai đều qua. Có thể kết luận chính xác lỗi của chương trình thật chỉ từ triệu chứng trên không?

</details>

[Đối chiếu đáp án](07_DapAn.md#lt6-12)

<a id="lt6-14"></a>

## LT6-14

Cần sắp n bản ghi tổng quát bằng so sánh: ổn định theo khóa đã có, thời gian xấu nhất O(n log n), chỉ O(1) bộ nhớ phụ và không có sẵn chỉ số thứ tự ban đầu trong bản ghi. Trong sáu cách cài thông thường đã học — Bubble, Insertion, Selection đổi chỗ, Quick đệ quy, Heap lặp, Merge mảng có đệm — cách nào đáp ứng đủ? Một đề xuất “Heap Sort rồi thêm vị trí hiện tại làm khóa phụ cho ổn định” có giải quyết được không? Hãy trả lời đúng phạm vi, không tuyên bố bất khả thi cho mọi thuật toán có thể tồn tại.

[Đối chiếu đáp án](07_DapAn.md#lt6-14)

<a id="lt6-17"></a>

## LT6-17

Cho mảng tăng không giảm có n phần tử, có thể rỗng hoặc chứa khóa trùng. Cần trả chỉ số đầu tiên có A[i]≥x; nếu không có thì trả n. Không dùng hàm thư viện: hãy thiết kế tìm kiếm nhị phân bằng lời, tự chọn đoạn đóng hoặc nửa mở. Phát biểu rõ phần đã loại, nơi đáp án còn có thể nằm và đại lượng giảm sau mỗi bước; giải thích vì sao không trả nhầm một vị trí bằng x ở giữa nhóm trùng. Ngoài chứng minh kết thúc, phải bảo vệ cận số vòng lặp theo cách chọn điểm xét.

<details>
<summary>Câu hỏi tiếp — mở sau khi trả lời câu chính</summary>

Tự chọn các test phân biệt lỗi bỏ sót đáp án ở biên, không kết thúc và trả sai vị trí đầu. Nếu đổi yêu cầu thành vị trí đầu có A[i]>x, phần xử lý khóa bằng x thay đổi thế nào?

</details>

[Đối chiếu đáp án](07_DapAn.md#lt6-17)

<a id="lt6-18"></a>

## LT6-18

Tên sách được sắp theo đúng thứ tự từ điển của các chuỗi chữ thường, không có bước chuẩn hóa khác. So ba truy vấn: bằng “an”, bắt đầu bằng “an”, chứa “an” ở bất kỳ vị trí. Với dãy an, ana, ban, car, xan, hãy chỉ nhóm kết quả và quyết định truy vấn nào có cơ sở tạo một khoảng liên tục để dùng tìm biên nhị phân. Sau đó nêu chi phí trả k kết quả và điều gì phải xét lại nếu khi tìm bỏ dấu/đổi hoa thường nhưng khi sắp thì không.

[Đối chiếu đáp án](07_DapAn.md#lt6-18)

<a id="lt6-21"></a>

## LT6-21

Thu nhỏ bài top 10 thành top 3 để phân tích: bảy đầu sách A…G có số lượt lần lượt 9,8,7,7,7,3,1. So hai hợp đồng: đúng ba đầu sách, khi hòa lấy mã tăng; hoặc lấy mọi đầu sách có lượt không thấp hơn mức của hạng ba. Hãy nêu hai kết quả và đánh giá đề xuất dùng heap giữ đúng ba ứng viên cho cả hai. Khi quay lại D đầu sách và H lượt lịch sử, những chi phí nào vẫn phải tính ngoài việc giữ heap?

[Đối chiếu đáp án](07_DapAn.md#lt6-21)

<a id="lt6-23"></a>

## LT6-23

Muốn sắp bản ghi tăng theo tên, nếu trùng tên mới xét năm. Một comparator trả “A đứng trước B” khi tên A nhỏ hơn tên B HOẶC năm A nhỏ hơn năm B. Hãy tự tạo cặp bản ghi chứng minh vấn đề của quan hệ này và nêu vì sao đổi thuật toán sắp xếp không sửa được hợp đồng so sánh.

<details>
<summary>Câu hỏi tiếp — mở sau khi trả lời câu chính</summary>

Thay HOẶC bằng VÀ có thực hiện đúng ưu tiên tên rồi năm không? Dùng dữ liệu cụ thể để trả lời và nêu quy tắc so phù hợp, kể cả hai bản ghi bằng cả tên lẫn năm.

</details>

[Đối chiếu đáp án](07_DapAn.md#lt6-23)

<a id="lt6-24"></a>

## LT6-24

Quick Sort chọn pivot ngẫu nhiên. Một phiên bản phân thành phần < pivot và phần ≥ pivot, đặt riêng một bản ghi pivot, rồi gọi tiếp hai phần còn lại; phiên bản khác gom toàn bộ phần = pivot và chỉ gọi tiếp các phần <,>. Trên n khóa đều bằng nhau, hãy phân tích độ sâu và công việc của hai cách. Ngẫu nhiên hóa pivot có cứu phiên bản đầu khỏi trường hợp này không?

[Đối chiếu đáp án](07_DapAn.md#lt6-24)

<a id="lt6-25"></a>

## LT6-25

Một hàm trộn xuôi hai dãy tăng đã được chứng minh đúng khi đầu ra tách biệt với hai vùng đầu vào. Nay bên gọi đặt hai dãy ở hai đoạn liền nhau trong một mảng và truyền đầu mảng ấy làm đầu ra, giữ nguyên thuật toán. Có đủ bảo đảm tổng sức chứa bằng tổng hai độ dài không? Tự tạo phản ví dụ và chỉ ra tiền điều kiện nào của chứng minh cũ không còn đúng.

<details>
<summary>Câu hỏi tiếp — mở sau khi trả lời câu chính</summary>

Một bạn sửa bằng cách đọc từ hai cuối và ghi ngược từ cuối chính mảng có đúng n+m ô, vẫn không có đệm. Cách sửa ấy có luôn an toàn không? Phân biệt mô hình này với trường hợp dãy thứ nhất có chỗ dư cuối và dãy thứ hai nằm ở vùng riêng.

</details>

[Đối chiếu đáp án](07_DapAn.md#lt6-25)

<a id="lt6-26"></a>

## LT6-26

Mảng có n khóa phân biệt đã tăng. Có q truy vấn chỉ hỏi tồn tại/không tồn tại và các khóa truy vấn cũng đã tăng, cho phép trả kết quả theo thứ tự đó. So tìm nhị phân độc lập q lần với dùng một vị trí chỉ tiến qua mảng khi xét các truy vấn. Hãy bảo vệ chi phí tổng của cách thứ hai, so khi q gần n với khi q=1, và giải thích nghĩa vụ bổ sung nếu ban đầu cần giữ thứ tự truy vấn tùy ý.

[Đối chiếu đáp án](07_DapAn.md#lt6-26)

<a id="lt6-27"></a>

## LT6-27

Dãy n khóa phân biệt đang giảm hoàn toàn. Gọi một nghịch thế là cặp vị trí i<j nhưng khóa ở i lớn hơn khóa ở j. Vì sao mọi phương pháp chỉ đổi chỗ hai phần tử kề nhau cần ít nhất n(n−1)/2 lần đổi để sắp tăng? Kết luận đó có mâu thuẫn với Heap Sort O(n log n) không? Hãy nói rõ mô hình thao tác đang bị giới hạn.

[Đối chiếu đáp án](07_DapAn.md#lt6-27)

<a id="lt6-28"></a>

## LT6-28

Kho chia thành nhiều phần không trùng đầu sách; mỗi đầu sách đã có số lượt mượn cuối cùng, và mọi phần dùng cùng thứ tự so đầy đủ để phá hòa. Muốn lấy đúng top k toàn kho, có đủ lấy top k mỗi phần rồi chọn lại từ hợp không? Hãy chứng minh hoặc cho phản ví dụ. Nếu thay vào đó chia các lượt lịch sử theo tháng, một đầu sách có thể xuất hiện ở nhiều tháng và số lượt phải cộng lại, lập luận cũ còn đúng không?

[Đối chiếu đáp án](07_DapAn.md#lt6-28)

<a id="lt6-29"></a>

## LT6-29

Một max-heap có thể tìm cực đại ở gốc. Nhóm suy ra tìm một khóa bất kỳ cũng O(log n) bằng cách “đi một nhánh như BST”. Hãy bác bỏ suy luận bằng quan hệ thứ tự mà heap thực sự bảo đảm. Sau đó xét heap có mọi nút trong mang khóa 2, còn mỗi lá có thể là 0 hoặc 1, và cần xác nhận không có khóa 1: vì sao trong mô hình không có chỉ mục phụ có thể phải đọc số lá tuyến tính?

[Đối chiếu đáp án](07_DapAn.md#lt6-29)

<a id="lt6-30"></a>

## LT6-30

Đầu vào gồm các khóa nguyên phân biệt, không rỗng. Bộ kiểm một thuật toán sắp xếp chỉ xác nhận đầu ra tăng nghiêm ngặt, cùng số phần tử, cùng tổng, cùng min và max. Hãy tìm số phần tử nhỏ nhất cho phép một đầu ra sai vẫn qua toàn bộ kiểm tra, tự đưa cặp đầu vào–đầu ra và chứng minh tính tối thiểu.

<details>
<summary>Câu hỏi tiếp — mở sau khi trả lời câu chính</summary>

Nếu mỗi bản ghi có mã riêng, khóa sắp là tên được phép trùng, cần kiểm thêm những gì để phát hiện mất, nhân đôi hoặc ghép sai dữ liệu? Tách yêu cầu bảo toàn dữ liệu khỏi yêu cầu ổn định.

</details>

[Đối chiếu đáp án](07_DapAn.md#lt6-30)

<a id="lt6-31"></a>

## LT6-31

Mảng A có n≥1 khóa đang tăng không giảm. Một lô gồm k vị trí phân biệt và giá trị mới, 0≤k≤n; các vị trí đã được cho theo thứ tự tăng nghiêm ngặt. Chỉ khi trạng thái cuối vẫn tăng mới áp dụng cả lô, nếu không phải giữ nguyên A. Chỉ xét xử lý tuần tự, phép gán không thất bại; truy cập ô A và phần tử của danh sách thay đổi tốn O(1). Không quét lại cả n ô: hãy tự tìm phản ví dụ cho cách kiểm từng giá trị mới với hàng xóm cũ, rồi thiết kế tập các cặp kề cần kiểm trong trạng thái dự kiến cuối. Chứng minh tập đó đủ và phân tích chi phí theo k.

<details>
<summary>Câu hỏi tiếp — mở sau khi trả lời câu chính</summary>

Làm thế nào đọc giá trị dự kiến của một hàng xóm cũng bị đổi mà không tạo bản sao n ô? Vì sao kiểm tuần tự rồi ghi ngay có thể vi phạm hợp đồng khi một thay đổi sau bị từ chối? Nếu các vị trí vẫn phân biệt nhưng chưa được sắp, cần tính thêm công việc nào cho phương án của bạn?

</details>

[Đối chiếu đáp án](07_DapAn.md#lt6-31)

<a id="lt6-32"></a>

## LT6-32

Có K đoạn không rỗng, mỗi đoạn đã tăng không giảm theo cùng khóa; tổng N bản ghi. Truy cập đầu/cuối mỗi đoạn tốn O(1). Nhóm muốn sắp thứ tự các đoạn theo khóa nhỏ nhất rồi ghép nguyên đoạn để tránh trộn từng bản ghi. Hãy tự đánh giá đề xuất này, suy ra điều kiện cần và đủ để một thứ tự ghép đã chọn cho kết quả tăng, rồi đề xuất cách tận dụng trường hợp ghép được mà vẫn xử lý đúng các trường hợp còn lại.

<details>
<summary>Câu hỏi tiếp — mở sau khi trả lời câu chính</summary>

Các đoạn ban đầu là các khúc liên tiếp của cùng một dãy, bản ghi có mã nhận diện và khóa có thể trùng. Nếu yêu cầu ổn định theo dãy ban đầu, điều kiện về giá trị ở ranh giới đã đủ chưa? Nêu cách giữ ổn định khi phải trộn.

</details>

[Đối chiếu đáp án](07_DapAn.md#lt6-32)
