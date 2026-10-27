# Đáp án gợi ý ôn lý thuyết CTDL cho nhóm Thư viện

[Về hướng dẫn](README.md)

Các ý dưới đây là căn cứ kiểm tra lập luận, không phải bài nói phải thuộc nguyên văn. Trả lời đúng bằng cách khác vẫn hợp lệ. Phần liên hệ là phân tích yêu cầu/thiết kế hoặc tình huống giả định, không xác nhận mã nhóm đã cài.

Quy ước: n là số phần tử của cấu trúc đang xét; D đầu sách, C cuốn, R độc giả, H tổng lượt lịch sử, h chiều cao cây. Nếu không nêu khác, mỗi phép so khóa và thao tác trên bản ghi được coi là hằng số; với chuỗi, cấp phát và đầu ra phải tính thêm chi phí thực tế. Bộ nhớ phụ bao gồm ngăn xếp lời gọi.

## Chương I — Phân tích và đánh giá giải thuật

<a id="lt1-01"></a>

### LT1-01

**Câu hỏi:** Ban đầu có n₀≥1 bản ghi chưa sắp. Sau đó có q lần tra cứu mã và u lần chèn thành công, xen kẽ, không có xóa; đặt N=n₀+u là số bản ghi lớn nhất. Phương án A giữ mảng chưa sắp, chèn cuối và tìm tuần tự. Phương án B sắp theo mã một lần rồi luôn giữ mảng tăng theo mã, tìm nhị phân và chèn đúng vị trí. Mảng đủ sức chứa, so khóa và di chuyển một bản ghi tốn O(1), chưa tính kiểm tra trùng. Hãy lập chặn trên trường hợp xấu cho tổng công việc của hai phương án, tính cả chuẩn bị. Chỉ ra khi nào B đáng dùng và khi nào kết luận “tìm nhị phân nhanh hơn nên chọn B” thất bại.

**Ý cần nắm:** Phân biệt n₀ là kích thước ban đầu và N=n₀+u là cận kích thước trong toàn chuỗi. A có chặn O(qN+u) cho phần tra cứu/chèn. B có thể chuẩn bị bằng một phép sắp O(n₀ log(n₀+1)); các truy vấn sau đó có chặn O(q log(N+1)). Lần chèn thứ j phải dịch tối đa n₀+j−1 bản ghi, nên tổng dịch không quá un₀+u(u−1)/2. Nếu còn tìm vị trí chèn bằng nhị phân, tính thêm tối đa O(u log(N+1)); vì N≥1, cả phần chèn có thể gộp vào O(uN). Do đó B có chặn O(n₀ log(n₀+1)+q log(N+1)+uN). Logarit viết với +1 để biểu thức không mất chi phí hằng số ở kích thước một; không làm thay đổi bậc khi kích thước tăng. Nếu ít cập nhật và rất nhiều tra cứu, phần chuẩn bị có thể được bù bởi chi phí truy vấn thấp hơn; nếu nhiều chèn đầu/giữa, chi phí dịch có thể lấn át lợi ích. Muốn kết luận định lượng phải xét kích thước ở từng thời điểm, vị trí chèn và chi phí thực tế; so hai chặn trên không chứng minh phương án nào nhanh hơn trên mọi dữ liệu. Nếu tính cả đọc/nạp n₀ bản ghi ban đầu thì cộng Θ(n₀) cho cả hai; phần này nằm ngoài các thao tác đang so. Mảng đầu sách của đề Thư viện bắt buộc tăng theo tên, nên mô hình sắp theo mã ở đây chỉ dùng so sánh lý thuyết, không cho phép đổi khóa sắp trong bản nộp.

**Cần thể hiện khi trả lời:**

- Định nghĩa nhất quán n₀,N=n₀+u; tính riêng chuẩn bị, tra cứu, tìm vị trí và dịch khi chèn.
- Nêu chặn tổng cùng điều kiện áp dụng; không suy ưu thế thực tế chỉ từ hai Big-O.

**Tránh nhầm:** Không dùng cùng một ký hiệu cho kích thước ban đầu và cận sau chèn nếu chúng khác nhau. Tính cả chuẩn bị, tìm vị trí và dịch; hai chặn trên chưa chứng minh ưu thế thực tế.

[Quay lại câu hỏi](01_PhanTichGiaiThuat.md#lt1-01)

<a id="lt1-03"></a>

### LT1-03

**Câu hỏi:** Một báo cáo đánh giá ghi “A là O(n²), B cũng O(n²), nên tốc độ tăng như nhau; A đã chạy nhanh hơn ở n=1.000 nên luôn tốt hơn”. Hãy bác bỏ cả hai suy luận bằng các hàm chi phí cụ thể, rồi nêu thông tin tối thiểu cần bổ sung để so sánh có căn cứ.

**Ý cần nắm:** Chọn A(n)=n và B(n)=n²: cả hai thuộc O(n²) nhưng cận chặt lần lượt Theta(n) và Theta(n²), nên cùng chặn trên không có nghĩa cùng tốc độ tăng. Để bác suy luận từ một điểm, chọn A(n)=n² và B(n)=2.000n: tại n=1.000, A nhỏ hơn; khi n>2.000 thì B nhỏ hơn. Cần thống nhất kích thước đầu vào, phép toán được tính, trường hợp hoặc phân phối đầu vào, chi phí chuẩn bị và bộ nhớ; đo thực tế phải giữ cùng phạm vi công việc và môi trường.

**Cần thể hiện khi trả lời:**

- Dùng hàm chi phí cụ thể bác cả suy luận cùng Big-O lẫn suy luận từ một kích thước.
- Phân biệt chặn trên, cận chặt và kết quả đo có phạm vi.

**Tránh nhầm:** Không sử dụng Big-O như dấu bằng giữa hai hàm hoặc lấy một phép đo làm kết luận cho mọi quy mô.

[Quay lại câu hỏi](01_PhanTichGiaiThuat.md#lt1-03)

<a id="lt1-04"></a>

### LT1-04

**Câu hỏi:** Tìm tuần tự trong n≥2 bản ghi. Với xác suất p(n), mã không tồn tại nên cần n lần so; các truy vấn còn lại trúng ngay bản ghi đầu. Chỉ biết 0<p(n)≤1, mỗi lần so tốn O(1). Hãy suy ra điều kiện cần và đủ theo bậc tăng của p(n) để số phép so kỳ vọng là Θ(1), rồi để là Θ(log n). Tự chọn một p(n) cho từng trường hợp, và giải thích vì sao độ phức tạp xấu nhất vẫn có thể tuyến tính dù kỳ vọng nhỏ.

**Câu hỏi tiếp:** Bỏ giả thiết trúng ngay đầu: vị trí trúng trung bình của các truy vấn thành công là μ(n), với 1≤μ(n)≤n và p(n)<1. Nếu chỉ biết p(n)=1/n thì có đủ kết luận kỳ vọng hằng số không? Tự dựng hai phân phối cùng xác suất thất bại nhưng khác bậc kỳ vọng.

**Ý cần nắm:** Trong mô hình đầu, E[C]=(1−p)×1+p×n=1+(n−1)p, nên E[C]=Θ(1+np). Vì p không âm, E[C]=Θ(1) khi và chỉ khi p(n)=O(1/n); ví dụ p=1/n cho 2−1/n. Với n tăng vô hạn, E[C]=Θ(log n) khi và chỉ khi p(n)=Θ(log n/n); có thể chọn p=log₂n/n cho n≥2. Chỉ p=O(log n/n) mới cho một chặn trên, chưa bảo đảm Θ(log n), vì nó còn cho phép p=1/n. Với mỗi n, p(n)>0 nên truy vấn vắng mã vẫn là một khả năng cần n lần so; kỳ vọng không phải cận cho mọi lần chạy. Khi vị trí trúng thay đổi, E[C]=(1−p)μ+pn. Cùng p=1/n: nếu mọi lần thành công trúng đầu thì E=2−1/n; nếu vị trí trúng phân bố đều từ 1 đến n thì μ=(n+1)/2 và E=(n²+2n−1)/(2n)=Θ(n). Vì vậy xác suất thất bại nhỏ không đủ nếu chưa biết công việc ở các lần thành công. Không cần giả thiết các truy vấn độc lập để tính kỳ vọng của một truy vấn theo phân phối đã cho.

**Cần thể hiện khi trả lời:**

- Tự lập E=1+(n−1)p, suy ra đúng hai điều kiện cần và đủ cùng ví dụ.
- Dùng E=(1−p)μ+pn để dựng hai phân phối cùng p nhưng khác bậc; tách kỳ vọng khỏi xấu nhất.

**Tránh nhầm:** Phân biệt O(log n) với Θ(log n), và phân biệt xác suất một sự kiện với chi phí có điều kiện khi sự kiện đó xảy ra.

[Quay lại câu hỏi](01_PhanTichGiaiThuat.md#lt1-04)

<a id="lt1-05"></a>

### LT1-05

**Câu hỏi:** Có R độc giả, độc giả i có H_i lượt lịch sử, tổng H=ΣH_i. Cách A duyệt từng độc giả và duyệt đúng lịch sử của người đó một lần. Cách B cũng duyệt R độc giả nhưng ở mỗi người lại duyệt toàn bộ H lượt để lọc theo mã. Mỗi phép xét O(1), bỏ qua xuất dữ liệu. Một bạn ghi cả hai là O(RH) vì đều có hai vòng lặp. Hãy chỉ ra cận chặt, kể cả trường hợp nhiều người không có lịch sử.

**Ý cần nắm:** A thực hiện R bước quản lý độc giả cộng đúng H bước lịch sử, nên Theta(R+H). Vòng trong không có H lượt ở mọi lần; phải cộng các H_i. B làm R lượt, mỗi lượt xét H phần tử, nên Theta(R+RH) nếu vẫn có công việc hằng số cho từng độc giả; khi H≥1 có thể viết Theta(RH). Thành phần R không được bỏ khi H=0. Bản ghi O(RH) cho A là chặn trên lỏng khi R,H≥1 và còn không xử lý đúng trường hợp H=0.

**Cần thể hiện khi trả lời:**

- Cộng R lượt thăm với tổng lịch sử ở A, so với quét H lặp R lần ở B.
- Xét độc giả không có lịch sử và tránh đếm mọi vòng lồng thành tích.

**Tránh nhầm:** Hai vòng lồng nhau chưa đủ quyết định phép nhân; cần xác định mỗi phần tử thực sự bị xét bao nhiêu lần.

[Quay lại câu hỏi](01_PhanTichGiaiThuat.md#lt1-05)

<a id="lt1-09"></a>

### LT1-09

**Câu hỏi:** Các truy vấn được định tuyến tới danh mục đầu sách i, nhưng không bảo đảm cuốn cần tìm tồn tại trong danh mục đó. Danh sách có C_i cuốn; H_i truy vấn nhắm vào đầu i và đều không tìm thấy nên phải quét hết. Biết C=ΣC_i, H=ΣH_i; xét riêng số lần so mã cuốn, mỗi lần O(1). Hãy lập chi phí theo từng nhóm. Chỉ biết C,H có đủ suy ra một cận chặt dùng chung cho mọi cách phân bố không?

**Câu hỏi tiếp:** Giữ đúng hai đầu sách không rỗng và cùng tổng C,H. Tự xây hai cách phân bố làm số lần so chênh nhau theo bậc tăng; phân biệt chặn trên với chi phí thực sự.

**Ý cần nắm:** Số lần so đúng bằng ΣH_i C_i. Luôn có chặn trên CH, nhưng không phải mọi phân bố đều đạt Θ(CH). Với C≥2, đặt C_1=1,C_2=C−1. Nếu cả H truy vấn nhắm đầu 1 thì có H lần so; nếu cả H truy vấn nhắm đầu 2 thì có H(C−1) lần so. Khi C tăng, hai chi phí khác bậc dù cùng C,H. Ví dụ cho phép H_i=0; nếu bắt mỗi đầu nhận truy vấn thì phải điều chỉnh ví dụ theo ràng buộc mới. Chi phí định tuyến hay xuất kết quả chưa nằm trong số lần so đang hỏi.

**Cần thể hiện khi trả lời:**

- Viết đúng tổng ΣH_i C_i và phạm vi chi phí.
- Dựng hai phân bố hợp lệ cùng C,H, tách O(CH) khỏi khẳng định Θ(CH).

**Tránh nhầm:** “Định tuyến tới danh mục i” không có nghĩa đã xác nhận cuốn thuộc danh mục đó. Không dùng việc truy vấn thất bại để suy ra dữ liệu mâu thuẫn.

[Quay lại câu hỏi](01_PhanTichGiaiThuat.md#lt1-09)

<a id="lt1-10"></a>

### LT1-10

**Câu hỏi:** BST độc giả được tổ chức theo mã thẻ, chưa có chỉ mục tên. Yêu cầu trả về k người đầu theo tên rồi họ trong số những người thỏa một điều kiện lịch sử; không được bỏ sót người có tên nhỏ hơn. Một đề xuất chỉ duyệt đến khi gặp đủ k người rồi dừng và quảng cáo O(log R+k). Hãy tìm phản ví dụ, chỉ ra công việc nào không thể tự loại bỏ và phân biệt chi phí chuẩn bị với chi phí xuất trang.

**Ý cần nắm:** Thứ tự gặp theo mã thẻ không bảo đảm thứ tự tên: người mã lớn ở nhánh chưa duyệt có thể tên An, đứng trước các tên đã thu được. Nếu không có thông tin tổng hợp hoặc thứ tự phù hợp để loại nhánh, nhìn chung phải xét mọi độc giả và dữ liệu lịch sử cần để xác định điều kiện. Có thể chỉ giữ k ứng viên tốt nhất trong quá trình xét, nhưng vẫn phải đọc phần nguồn có thể ảnh hưởng kết quả. Xuất k dòng cần ít nhất theo lượng đầu ra; phân trang không tự làm bước lọc/chọn toàn cục thành O(log R+k).

**Cần thể hiện khi trả lời:**

- Dựng ca dừng sau k người bỏ sót tên nhỏ hơn.
- Phân biệt duyệt/lọc/sắp chuẩn bị với chi phí xuất trang.

**Tránh nhầm:** Không dùng cận của tìm theo khóa BST cho một báo cáo theo khóa khác và có thêm điều kiện lọc.

[Quay lại câu hỏi](01_PhanTichGiaiThuat.md#lt1-10)

<a id="lt1-11"></a>

### LT1-11

**Câu hỏi:** Một phép tìm tên dùng O(log D) lần so chuỗi trong mảng D đầu sách đã sắp. Mọi tên dài tối đa L ký tự và nhiều tên chung một tiền tố dài. Có thể quảng cáo thời gian O(log D) độc lập với L không? Nếu chuẩn hóa sẵn mọi tên để giảm công việc khi tìm, hãy tách chi phí chuẩn bị, bộ nhớ, chi phí một truy vấn và nghĩa vụ khi tên bị sửa.

**Ý cần nắm:** O(log D) mới là số lần so; nếu một lần phải đọc tới L ký tự thì có cận O(L log D), ngoài việc đọc/chuẩn hóa từ khóa và xuất kết quả. Chuẩn hóa sẵn D tên có thể cần O(DL) thời gian và bộ nhớ theo tổng độ dài khóa, tùy phép chuẩn hóa. Nó tránh lặp lại bước chuẩn hóa tên ở mỗi truy vấn nhưng không tự làm so hai chuỗi dài thành O(1). Khi đổi tên phải cập nhật khóa đã chuẩn hóa và giữ đúng thứ tự mà tìm kiếm dựa vào; nếu không, tối ưu có thể trả sai.

**Cần thể hiện khi trả lời:**

- Tính chi phí ký tự trong các lần so, không coi mọi chuỗi là O(1).
- Nêu bộ nhớ và nghĩa vụ cập nhật dữ liệu chuẩn hóa.

**Tránh nhầm:** Nêu rõ đang đếm phép so hay thời gian theo ký tự; bộ nhớ khóa phụ và chi phí giữ nó đúng không được bỏ khỏi đánh giá.

[Quay lại câu hỏi](01_PhanTichGiaiThuat.md#lt1-11)

<a id="lt1-12"></a>

### LT1-12

**Câu hỏi:** Một thuật toán chỉ được so sánh từng cặp khóa phân biệt, mỗi phép so cho hai kết quả thứ tự, và phải sắp đúng mọi hoán vị n phần tử. Người viết hứa tối đa 5n phép so cho mọi n. Hãy mô hình hóa các chuỗi kết quả so bằng cây quyết định và giải thích vì sao lời hứa không thể đúng khi n đủ lớn. Kết luận có áp dụng ngay cho thuật toán dùng trực tiếp giá trị khóa để đặt vào các ô đã biết không?

**Ý cần nắm:** Có n! thứ tự đầu vào cần phân biệt theo danh tính phần tử. Cây quyết định nhị phân có chiều sâu tối đa c chỉ có tối đa 2^c lá, nên cần 2^c≥n!, hay c≥log₂(n!). Chỉ riêng khoảng n/2 thừa số cuối của n! đã cho tăng theo (n/2)^(n/2), nên chặn dưới là Omega(n log n), vượt 5n khi n đủ lớn. Lập luận này gắn với mô hình chỉ dùng so sánh; nếu khai thác miền giá trị đặc biệt để đánh địa chỉ trực tiếp thì phải phân tích mô hình và tài nguyên khác, không áp dụng máy móc cùng chặn dưới.

**Cần thể hiện khi trả lời:**

- Nối n! hoán vị với số lá và chiều cao cây quyết định.
- Giới hạn kết luận trong mô hình sắp bằng so sánh.

**Tránh nhầm:** Đây là giới hạn trong một mô hình đã nêu, không phải tuyên bố mọi phương pháp sắp xếp trên mọi loại khóa đều cần n log n thời gian.

[Quay lại câu hỏi](01_PhanTichGiaiThuat.md#lt1-12)

<a id="lt1-14"></a>

### LT1-14

**Câu hỏi:** Để trả nhanh số lượt đang mượn, một thiết kế giữ thêm biến đếm bên cạnh danh sách lịch sử. Sau mượn thành công phải thêm một lượt mở; sau trả thành công phải đóng một lượt mở; thao tác thất bại phải giữ nguyên dữ liệu. Một bạn tăng/giảm biến đếm ngay khi nhận yêu cầu, rồi mới kiểm điều kiện. Hãy dựng chuỗi làm số đếm sai, phát biểu bất biến và so tổng chi phí của q lần hỏi với u lần cập nhật so với đếm lại từ lịch sử mỗi lần.

**Ý cần nắm:** Đang có hai lượt mở, yêu cầu mượn cuốn không còn cho mượn bị từ chối nhưng biến đếm đã tăng thành ba; hoặc trả lại một lượt đã đóng làm đếm giảm sai. Bất biến là số lưu bằng đúng số nút lịch sử thỏa điều kiện đang mở, và phải giữ sau cả thành công lẫn thất bại. Đọc số lưu là O(1), nhưng mọi đường cập nhật/nạp dữ liệu phải duy trì hoặc dựng lại nó; chi phí nghiệp vụ khác vẫn còn. Nếu lịch sử tối đa dài H, đếm lại q lần có O(qH), còn duy trì biến đếm thêm O(u+q) công việc sau khâu khởi tạo, theo giả thiết cập nhật nhận biết được đúng thay đổi.

**Cần thể hiện khi trả lời:**

- Dựng chuỗi thành công/thất bại phá biến đếm và nêu bất biến với lịch sử.
- Tính lợi ích truy vấn cùng nghĩa vụ cập nhật nhất quán.

**Tránh nhầm:** Dữ liệu hỗ trợ đổi chi phí truy vấn thành nghĩa vụ giữ nhất quán; đây là phân tích thiết kế, không tự thêm trường vào bản nộp.

[Quay lại câu hỏi](01_PhanTichGiaiThuat.md#lt1-14)

<a id="lt1-15"></a>

### LT1-15

**Câu hỏi:** Một báo cáo thử nghiệm ghi: “A chạy trước, B chạy sau, cùng một biến mảng n phần tử; thời gian B bằng 60% A”. Không lưu bản đầu vào trước mỗi lần chạy; đồng hồ bao cả phần chuẩn bị và xuất kết quả. Tác giả kết luận B nên thay A. Bạn chỉ được bổ sung tối đa ba nhóm phép đo có đối chứng. Hãy thiết kế các nhóm đo để phân biệt lợi thế thuật toán với ảnh hưởng của dữ liệu đầu vào, thứ tự chạy và công việc ngoài thuật toán; nêu kết quả nào sẽ làm bạn bác bỏ kết luận ban đầu.

**Câu hỏi tiếp:** Mỗi nhóm đo có thể lặp nhiều lần. Nêu dữ liệu phải lưu, tiêu chí đúng phải kiểm và giới hạn của kết luận ngay cả khi B thắng ở mọi mẫu đã đo.

**Ý cần nắm:** Chưa đủ dữ kiện để chọn B. Một kế hoạch hợp lệ: (1) cho A và B nhận hai bản sao độc lập của cùng đầu vào, giữ bản gốc và đổi luân phiên thứ tự chạy; chỉ đo đoạn sắp, kiểm kết quả sau đo. Nếu chênh lệch đổi theo vị trí chạy, chưa thể gán hết cho thuật toán. (2) lặp cặp đo trên các họ dữ liệu đã xác định trước: ngẫu nhiên, tăng, giảm, nhiều khóa trùng, nhiều kích thước; giữ cùng dữ liệu trong từng cặp. Nếu B chỉ thắng trên mảng đã tăng còn thua trên họ phù hợp công việc thật, tỷ lệ 60% không khái quát được. (3) đo riêng chuẩn bị, sắp và xuất, rồi đo toàn quy trình với cùng điều kiện; nếu lợi thế chỉ nằm ở lượng xuất khác nhau hoặc biến mất khi tách phần ngoài sắp thì kết luận về riêng thuật toán không đứng vững. Lưu đầu vào hoặc hạt sinh, kích thước, thứ tự chạy, môi trường và phân bố thời gian qua các lần lặp. Kiểm thứ tự, bảo toàn bản ghi và độ ổn định nếu hợp đồng yêu cầu. Có thể tổ chức ba nhóm khác nếu kiểm soát được các yếu tố và có dự đoán phân biệt. Đo thực nghiệm trên mẫu không chứng minh cận xấu nhất, tính đúng trên mọi đầu vào hoặc ưu thế trên mọi máy.

**Cần thể hiện khi trả lời:**

- Mỗi nhóm đo có yếu tố kiểm soát và dự đoán phân biệt, không chỉ nói “chạy lại nhiều lần”.
- Kiểm đúng trước khi so nhanh, phân biệt thời gian sắp với cả quy trình và giới hạn ngoại suy.

**Tránh nhầm:** Không khẳng định A chắc chắn đã sắp đầu vào của B khi nhật ký không lưu trạng thái đó; đó là giả thuyết cần kiểm. Đổi thứ tự chạy một lần cũng chưa loại hết nhiễu.

[Quay lại câu hỏi](01_PhanTichGiaiThuat.md#lt1-15)

<a id="lt1-16"></a>

### LT1-16

**Câu hỏi:** Một mảng động tăng từ rỗng bằng các lần thêm cuối. Cách A mỗi khi hết chỗ chỉ cấp đúng thêm một ô; cách B tăng gấp đôi sức chứa, bắt đầu từ một ô. Giả sử chuyển một phần tử O(1), không có xóa, bỏ qua chi phí hệ thống cấp phát. Với n lần thêm, hãy đánh giá tổng số phần tử bị chuyển và độ trễ xấu nhất của một lần. Khi tăng sức chứa, vì sao bộ nhớ đỉnh có thể lớn hơn sức chứa mảng mới?

**Ý cần nắm:** A chuyển 1+2+…+(n−1) phần tử, tổng Theta(n²). B chuyển 1+2+4+… trước các lần tăng, tổng O(n), nên cả chuỗi có chi phí khấu hao O(1) cho một lần thêm trong mô hình này; riêng một lần vẫn có thể chuyển Theta(n) phần tử. Nếu phải giữ khối cũ trong lúc tạo khối mới và chuyển, tại lần tăng từ C lên 2C có thể đồng thời tồn tại 3C ô. Đây là chi phí bộ nhớ tại thời điểm chuyển, không chỉ 2C của trạng thái cuối.

**Cần thể hiện khi trả lời:**

- Tính tổng số lần chuyển cho tăng một ô và tăng gấp đôi.
- Tách chi phí cả chuỗi, độ trễ một lần và bộ nhớ đỉnh khi đổi vùng.

**Tránh nhầm:** Khấu hao hằng số không bảo đảm độ trễ hằng số hoặc thao tác cấp phát luôn thành công; mô hình này không thay mảng cố định của đề nhóm.

[Quay lại câu hỏi](01_PhanTichGiaiThuat.md#lt1-16)

<a id="lt1-17"></a>

### LT1-17

**Câu hỏi:** Vòng ngoài có n lượt, mỗi lượt làm Θ(1) việc riêng. Chỉ số j bắt đầu từ 0, không bị đặt lại và tổng cộng tăng đúng s lần, s≤n. Phiên bản A: mỗi lần tăng j và mỗi lần kiểm điều kiện trong vòng trong tốn Θ(1). Phiên bản B: lần tăng tới giá trị j phải quét đúng j ô; mọi phần còn lại, kể cả kiểm điều kiện, vẫn Θ(1). Hãy tìm cận chặt theo n,s cho cả hai. Khi nào B vẫn có tổng chi phí tuyến tính theo n?

**Câu hỏi tiếp:** Nếu sau mỗi lượt ngoài được đặt j về 0, phần nào trong chứng minh không còn dùng được? Phải đếm lại đại lượng nào?

**Ý cần nắm:** A có Θ(n+s)=Θ(n): có s bước thành công và nhiều nhất một lần kiểm thất bại cho mỗi lượt ngoài. B có Θ(n+Σ_{j=1}^s j)=Θ(n+s²). Do đó B vẫn Θ(n) khi s=O(√n), và có thể Θ(n²) nếu s=Θ(n). Nếu đặt lại j, tổng số lần tăng trên toàn chương trình không còn bị chặn bởi n; phải đếm số tăng thực tế qua các lượt và chi phí từng tăng. Với n lượt, mỗi lượt lại đi hết n ô, A trở thành Θ(n²); với công việc quét của B như trên ở mỗi lượt, có thể Θ(n³).

**Cần thể hiện khi trả lời:**

- Suy ra Θ(n+s) và Θ(n+s²), có tính các lần kiểm thất bại.
- Nêu điều kiện s=O(√n) và lý do đặt lại j làm mất cận tổng số lần tăng.

**Tránh nhầm:** Con trỏ đơn điệu chỉ chặn số lần tiến; không tự chặn công việc ẩn trong mỗi lần tiến hoặc kiểm điều kiện.

[Quay lại câu hỏi](01_PhanTichGiaiThuat.md#lt1-17)

<a id="lt1-18"></a>

### LT1-18

**Câu hỏi:** Trong một phép đo giả định của chương trình xử lý tuần tự, nhập/xuất chiếm 60%, tìm kiếm 30%, sắp xếp 10% tổng thời gian. Ba phần không chồng lấp. Hai đề xuất độc lập: làm riêng phần sắp nhanh gấp 10, hoặc làm riêng phần tìm nhanh gấp 2; các phần còn lại giữ nguyên với cùng khối lượng công việc. Hãy chọn đề xuất giảm tổng thời gian nhiều hơn, tính mức tăng tốc toàn chương trình và kiểm lời hứa “chỉ cần tối ưu sắp đủ tốt là toàn chương trình nhanh gấp đôi”.

**Câu hỏi tiếp:** Giả sử chỉ số truy vấn đổi khiến thời gian tìm kiếm trước tối ưu nhân t>0 lần, còn lượng nhập/xuất và sắp vẫn như cũ. Suy ra ngưỡng t làm lựa chọn giữa hai đề xuất đảo chiều. Những giả thiết nào cần đo lại trước khi dùng ngưỡng đó cho chương trình thật?

**Ý cần nắm:** Chuẩn hóa tổng cũ bằng 1. Tối ưu sắp cho thời gian 0,6+0,3+0,1/10=0,91, tăng tốc 1/0,91≈1,099 lần. Tối ưu tìm cho 0,6+0,3/2+0,1=0,85, tăng tốc ≈1,176 lần, tốt hơn trong mô hình này. Dù phần sắp giảm về 0, tổng vẫn ít nhất 0,9 nên mức tăng tốc không vượt 1/0,9≈1,111 lần; không đạt gấp đôi. Nếu tỷ trọng công việc đổi, phải đo lại thời gian và số lần thực hiện từng phần trên tải đại diện; tỷ lệ cũ không tự giữ nguyên. Big-O mô tả tăng trưởng theo biến kích thước dưới mô hình chi phí, không cung cấp tỷ trọng của từng phần trong phép đo này. Còn phải kiểm phần tối ưu có giữ đầu ra và chi phí bộ nhớ/chuẩn bị phù hợp hay không. Nếu riêng công việc tìm kiếm nhân t>0 lần còn hai phần kia giữ lượng việc cũ, thời gian gốc theo đơn vị ban đầu là 0,7+0,3t. Hai phương án lần lượt mất 0,61+0,3t và 0,7+0,15t; hiệu bằng 0,15t−0,09. Do đó tối ưu sắp lợi hơn khi t<0,6, tối ưu tìm lợi hơn khi t>0,6, hòa tại t=0,6. Không được tiếp tục dùng tỷ lệ 60%/30%/10% cho tổng thời gian mới mà chưa chuẩn hóa lại.

**Cần thể hiện khi trả lời:**

- Tính tổng mới, so hai mức tăng tốc và chứng minh trần khi chỉ tối ưu sắp.
- Tự lập biểu thức theo t, suy ra ngưỡng 0,6 và nêu giả thiết phải đo lại khi tải thay đổi.

**Tránh nhầm:** Các số là dữ liệu giả định để suy luận, không phải kết quả benchmark repo Thư viện. Phần trăm giảm thời gian không bằng phần trăm tăng tốc.

[Quay lại câu hỏi](01_PhanTichGiaiThuat.md#lt1-18)

<a id="lt1-19"></a>

### LT1-19

**Câu hỏi:** Một BST có 50.000 bản ghi, mỗi bản ghi đúng 64 byte, địa chỉ cố định trong suốt lúc lập báo cáo. Cần báo cáo theo tên mà không sửa cây. Bộ nhớ phụ tối đa 1 MiB=1.048.576 byte; một con trỏ 8 byte; dành cố định 32 KiB cho mọi biến/bộ đệm khác. Mọi vùng lớn được cấp đúng số ô nêu trong mô hình. Hãy chọn giữa sao chép toàn bộ bản ghi và lập một mảng tham chiếu, có tính bộ nhớ đỉnh khi duyệt cây có thể lệch hoàn toàn.

**Câu hỏi tiếp:** Nếu dùng Merge Sort cần thêm mảng đệm bằng kích thước mảng tham chiếu, có nhất thiết vượt trần không? Phân tích thời điểm tồn tại các vùng nhớ và so với sắp tham chiếu bằng Heap Sort lặp; nêu điều kiện về ổn định và vòng đời đối tượng.

**Ý cần nắm:** Sao chép bản ghi đã cần 50.000×64=3.200.000 byte, vượt trần. Mảng tham chiếu cần 400.000 byte. Có thể duyệt bằng Stack tường minh chứa tối đa 50.000 con trỏ, cũng 400.000 byte; cộng 32.768 byte là 832.768 byte, nằm trong trần. Kết thúc duyệt, giải phóng vùng Stack trước khi cấp đệm trộn thì hai mảng tham chiếu cộng phần cố định vẫn là 832.768 byte. Nếu giữ đồng thời mảng kết quả, Stack và đệm thì cần 1.232.768 byte, vượt trần. Đây là cận đỉnh theo các vùng cấp phát của thiết kế, không phải tổng mọi byte từng cấp. Heap Sort lặp trên mảng tham chiếu giảm bộ nhớ ở pha sắp nhưng cách thông thường không ổn định; Merge Sort ổn định có thể dùng nếu thứ tự ban đầu giữa khóa tên trùng cần giữ. Các tham chiếu không sở hữu đối tượng; bản ghi phải tồn tại và không đổi tên trong khi báo cáo dùng thứ tự đã sắp. Mô hình đã dành phần cố định cho chi phí khác, không được dùng các phép tính này để cam kết bộ nhớ thực của một runtime bất kỳ.

**Cần thể hiện khi trả lời:**

- Tính đúng ba mức 3.200.000; 832.768; 1.232.768 byte và chọn biểu diễn khả thi.
- Lập lịch giải phóng/cấp vùng nhớ, gắn lựa chọn sắp với ổn định và vòng đời tham chiếu.

**Tránh nhầm:** Độ cao BST thường có thể tuyến tính. Bộ nhớ đỉnh phụ thuộc vòng đời vùng cấp phát; chỉ xóa phần tử Stack mà không giải phóng sức chứa chưa làm giảm vùng đã giữ.

[Quay lại câu hỏi](01_PhanTichGiaiThuat.md#lt1-19)

## Chương III — Danh sách tuyến tính, Stack và Queue

<a id="lt3-03"></a>

### LT3-03

**Câu hỏi:** Một mảng động chứa các con trỏ tới đối tượng đầu sách cấp phát riêng. Khi tăng sức chứa, chương trình cấp mảng ô con trỏ mới, sao chép các địa chỉ rồi giải phóng mảng ô cũ; các đối tượng đầu sách không được di chuyển hay xóa. Bên ngoài đang giữ ba thứ: chỉ số của một đầu sách, con trỏ tới đối tượng đó, và con trỏ tới ô chứa nó trong mảng cũ. Những thứ nào còn dùng được ngay sau tăng sức chứa? Nếu tiếp tục chèn đầu sách mới vào đầu mảng thì câu trả lời đổi ra sao?

**Ý cần nắm:** Sau chỉ riêng tăng sức chứa và giữ nguyên thứ tự, chỉ số còn chỉ đúng phần tử và con trỏ đối tượng còn hợp lệ; con trỏ tới ô trong mảng cũ mất hiệu lực vì khối ô đã bị giải phóng. Sau chèn đầu mảng có dịch ô, chỉ số cũ có thể chỉ sang đầu sách khác, trong khi con trỏ tới đối tượng cũ vẫn hợp lệ theo giả thiết không xóa/di chuyển đối tượng. Cần phân biệt tính hợp lệ của địa chỉ, vị trí logic và danh tính đối tượng; sao chép con trỏ không tạo bản sao đối tượng.

**Cần thể hiện khi trả lời:**

- Phân biệt chỉ số, địa chỉ đối tượng và địa chỉ ô con trỏ sau cấp lại.
- Xét thêm tác động dịch ô khi chèn đầu.

**Tránh nhầm:** Đây là mô hình mảng động để so sánh; header nhóm đang dùng mảng con trỏ sức chứa cố định, chưa được tự đổi cấu trúc nộp.

[Quay lại câu hỏi](03_Mang_Stack_Queue.md#lt3-03)

<a id="lt3-04"></a>

### LT3-04

**Câu hỏi:** Mảng tăng dần còn đủ chỗ. Nhóm thay bước tìm vị trí chèn tuyến tính bằng tìm nhị phân và kết luận xây n phần tử từ rỗng chỉ tốn O(n log n). Hãy chọn một thứ tự đưa khóa vào khiến kết luận sai, đếm số phần tử phải dịch trong cả chuỗi và nêu khi nào gom dữ liệu rồi sắp một lần là phương án hợp lệ. Đề yêu cầu mảng luôn tăng sau mỗi lần thêm thành công.

**Ý cần nắm:** Đưa các khóa theo thứ tự giảm khiến mỗi khóa mới chèn đầu. Lần có i phần tử phải dịch i phần tử; tổng 0+1+…+(n−1)=n(n−1)/2, nên vẫn Theta(n²) thao tác dịch dù tổng chi phí tìm vị trí là O(n log n). Gom rồi sắp một lần chỉ hợp lệ nếu các trạng thái chưa sắp chưa được xem là các lần thêm đã hoàn tất, ví dụ một bước nhập hàng loạt có hợp đồng riêng. Với yêu cầu tăng sau từng lần thêm thành công, không được công bố thành công rồi trì hoãn việc sắp.

**Cần thể hiện khi trả lời:**

- Dựng thứ tự chèn giảm và tính tổng số lần dịch.
- Nêu khi nào sắp theo lô phù hợp yêu cầu luôn tăng sau lần thêm thành công.

**Tránh nhầm:** Giảm chi phí tìm vị trí không tự giảm chi phí duy trì biểu diễn.

[Quay lại câu hỏi](03_Mang_Stack_Queue.md#lt3-04)

<a id="lt3-05"></a>

### LT3-05

**Câu hỏi:** Mảng con trỏ đầu sách đang tăng theo tên An, Bình, Cường. Một báo cáo đã chụp thứ tự các con trỏ đó. Đối tượng Bình được sửa tên thành Z và mảng nguồn được đưa lại về đúng thứ tự; không có đối tượng nào bị xóa. Báo cáo cũ còn con trỏ hợp lệ không, còn tăng theo tên không, và có còn là ảnh dữ liệu ở lúc lập báo cáo không? Hãy chỉ ra ba yêu cầu khác nhau mà nhóm phải phân biệt khi nói “giữ bản báo cáo cũ”.

**Ý cần nắm:** Các con trỏ vẫn hợp lệ theo giả thiết; mảng nguồn mới là An,Cường,Z. Báo cáo cũ giữ thứ tự con trỏ An,Z,Cường nên không còn tăng theo tên hiện tại. Nó cũng không giữ nguyên chữ Bình của thời điểm tạo vì vẫn đọc cùng đối tượng đã bị sửa. Cần phân biệt giữ tham chiếu tới đối tượng hiện hành, giữ thứ tự hiển thị hợp lệ sau cập nhật, và giữ ảnh nội dung lịch sử. Yêu cầu cuối cần dữ liệu độc lập hoặc cơ chế phiên bản; chỉ sao chép mảng con trỏ không đủ.

**Cần thể hiện khi trả lời:**

- Phân biệt con trỏ hợp lệ, thứ tự hiện tại và nội dung chụp trước sửa.
- Đưa đúng thứ tự nguồn và báo cáo sau đổi Bình thành Z.

**Tránh nhầm:** Con trỏ hợp lệ không bảo đảm thứ tự báo cáo hoặc ý nghĩa snapshot còn đúng.

[Quay lại câu hỏi](03_Mang_Stack_Queue.md#lt3-05)

<a id="lt3-08"></a>

### LT3-08

**Câu hỏi:** Queue vòng M ô dùng front là vị trí lấy tiếp, rear là vị trí thêm tiếp, count là số phần tử. Sau mỗi thao tác, bộ kiểm chỉ xác nhận 0≤count≤M, rear≡front+count (mod M) và tập đa trị các phần tử còn lại đúng. Các kiểm tra ấy đã đủ chứng minh FIFO chưa? Hãy tự dựng hai trạng thái vượt qua chúng nhưng có hành vi lấy tiếp khác nhau, rồi nêu thông tin kiểm chứng còn thiếu.

**Câu hỏi tiếp:** Queue có M=5, front=4, rear=2, count=3; thứ tự logic A,B,C nằm ở các ô 4,0,1. Tăng sức chứa lên 8. Nếu giữ nguyên ô vật lý và các chỉ số rồi chỉ đổi phép modulo, điều gì sai? Đề xuất trạng thái mới đúng và nói rõ quyền thay đổi chỉ số khi đổi mảng.

**Ý cần nắm:** Chưa đủ: với M=5, front=0,rear=2,count=2, trạng thái ô 0,1 là A,B hoặc B,A đều qua các kiểm tra nhưng lấy tiếp khác nhau. Cần đối chiếu dãy theo thứ tự đưa vào/trả ra, chẳng hạn một mô hình Queue tham chiếu hoặc bất biến dãy logic còn chờ; phép thất bại phải giữ nguyên trạng thái theo hợp đồng. Ở ví dụ tăng sức chứa, dùng modulo 8 thì đi từ ô 4 ba bước sẽ đọc 4,5,6, không còn là A,B,C ở 4,0,1; rear=2 cũng không bằng (4+3) mod 8. Có thể sao chép theo thứ tự logic A,B,C vào 0,1,2, đặt front=0,rear=3,count=3. Chỉ số nội bộ được thay đổi nếu hợp đồng bên ngoài không hứa giữ địa chỉ ô; thứ tự FIFO và số phần tử phải giữ.

**Cần thể hiện khi trả lời:**

- Tạo phản ví dụ cùng metadata và cùng phần tử nhưng sai thứ tự.
- Bảo toàn dãy logic khi tăng sức chứa, phân biệt địa chỉ ô với phần tử trong Queue.

**Tránh nhầm:** Bất biến số học và bảo toàn tập phần tử chưa mô tả thứ tự. Mảng vòng phải được diễn giải theo đúng sức chứa đang dùng.

[Quay lại câu hỏi](03_Mang_Stack_Queue.md#lt3-08)

<a id="lt3-09"></a>

### LT3-09

**Câu hỏi:** Các phần tử 1,2,3,4,5 phải được push theo đúng thứ tự vào một Stack; được xen pop tùy lúc nhưng không được lấy giữa Stack hoặc dùng nơi chứa phụ. Có thể nhận thứ tự pop 3,1,2,5,4 không? Hãy chỉ đúng thời điểm bất khả thi, không chỉ trả lời “không”. Nếu sửa thành 3,2,1,5,4 thì hãy bảo vệ bằng một chuỗi thao tác và rút ra cách kiểm một hoán vị bất kỳ của 1…n trong O(n) thao tác Stack. Vì sao cách kiểm ấy không bỏ sót một cách xen push/pop khác có thể thành công?

**Ý cần nắm:** Muốn pop đầu là 3, phải push 1,2,3 rồi pop 3. Khi đó 2 nằm trên 1, nên không thể lấy 1 tiếp theo mà vẫn để 2 ra sau; push thêm chỉ đặt thêm vật cản ở trên. Thứ tự sửa là khả thi: push 1,2,3; pop 3,2,1; push 4,5; pop 5,4. Khi phần tử cần ra đã nằm dưới một phần tử chưa được phép ra, và chỉ còn được push/pop ở đỉnh, thứ tự yêu cầu không thể thực hiện. Truy vết trạng thái đỉnh là chứng cứ cho kết luận. Để kiểm một hoán vị, lần lượt xét phần tử đầu ra cần có: nếu nó chưa được push thì push dãy đầu vào tới nó, rồi yêu cầu nó nằm ở đỉnh để pop; nếu không ở đỉnh thì từ chối. Mỗi phần tử push/pop tối đa một lần, nên O(n). Việc push tới phần tử mong muốn là bắt buộc theo thứ tự đầu vào; một khi nó bị chặn bởi phần tử chưa được phép pop, push thêm không gỡ được vật cản. Vì vậy lựa chọn kiểm này không bỏ qua một lịch thao tác hợp lệ khác.

**Cần thể hiện khi trả lời:**

- Chỉ ra vật cản ở đỉnh và truy vết chuỗi hợp lệ.
- Chứng minh bộ kiểm O(n) không bỏ qua lịch push/pop khả thi khác.

**Tránh nhầm:** Không suy khả thi chỉ từ việc đầu ra chứa đủ đúng các giá trị; thứ tự bị ràng buộc bởi các phần tử đang chắn ở đỉnh.

[Quay lại câu hỏi](03_Mang_Stack_Queue.md#lt3-09)

<a id="lt3-10"></a>

### LT3-10

**Câu hỏi:** Một Queue được cài bằng hai Stack. Thêm phần tử vào Stack vào; khi lấy, nếu Stack ra rỗng thì chuyển hết phần tử từ Stack vào sang Stack ra rồi mới pop, còn Stack ra chưa rỗng thì pop trực tiếp. Hãy chứng minh FIFO qua một chuỗi có thêm xen giữa các lần lấy. Với m thao tác từ trạng thái rỗng, mỗi push/pop Stack O(1), hãy phân biệt chi phí xấu của một lần lấy với tổng chi phí cả chuỗi; không được dùng chữ “trung bình” mà không giải thích.

**Ý cần nắm:** Ví dụ thêm A,B,C rồi lấy A làm Stack ra còn B ở trên C; thêm D vào Stack vào, hai lần lấy kế vẫn trả B,C, sau đó mới chuyển D và lấy D. Phần tử mới không vượt các phần tử cũ vì chỉ chuyển khi Stack ra hết. Một lần lấy có thể chuyển Theta(t) phần tử, nên xấu nhất tuyến tính theo số đang chờ. Nhưng mỗi phần tử được push vào một lần, chuyển ra tối đa một lần và pop ra tối đa một lần; tổng số thao tác Stack là O(m). Chi phí bình quân trên chuỗi, gọi là khấu hao, là O(1) mỗi thao tác, không dựa vào giả thiết xác suất truy vấn.

**Cần thể hiện khi trả lời:**

- Bảo vệ FIFO với thêm xen giữa các lần lấy.
- Đếm số lần mỗi phần tử qua hai Stack, tách khấu hao khỏi kỳ vọng xác suất.

**Tránh nhầm:** Cận khấu hao không bảo đảm mọi lần lấy đều có độ trễ hằng số. Đây là bài suy luận từ Stack/Queue, không thêm hàng chờ vào nghiệp vụ Thư viện.

[Quay lại câu hỏi](03_Mang_Stack_Queue.md#lt3-10)

<a id="lt3-13"></a>

### LT3-13

**Câu hỏi:** Cài Stack bằng hai Queue chỉ có thêm cuối/lấy đầu. Cách A khi push chuyển các phần tử cũ để phần tử mới đứng đầu Queue chính; cách B push thẳng cuối và khi pop mới chuyển hết trừ phần tử cuối sang Queue phụ. Hãy giải thích cách mỗi phương án giữ LIFO, so chi phí push/pop và tính cả chuỗi n push rồi n pop. Có thể kết luận cách A nhanh hơn chỉ vì pop O(1) không?

**Ý cần nắm:** A có thể đưa phần tử mới vào Queue phụ rồi chuyển các phần tử cũ theo thứ tự sang sau nó, đổi vai trò hai Queue: phần tử mới luôn ở đầu để pop O(1), nhưng push khi đang có t phần tử tốn O(t+1). B push O(1); lúc pop phải chuyển t−1 phần tử để lấy phần tử cuối, nên pop O(t). Chuỗi n push rồi n pop tốn Theta(n²) với cả hai cách, nhưng chi phí dồn vào các thời điểm khác nhau. Lựa chọn còn phụ thuộc tần suất thao tác và yêu cầu độ trễ của từng loại.

**Cần thể hiện khi trả lời:**

- Giải thích LIFO và nơi trả chi phí ở từng cách.
- Tính cả chuỗi n push/n pop và liên hệ yêu cầu độ trễ.

**Tránh nhầm:** Một thao tác rẻ hơn có thể chỉ là dời công việc sang thao tác khác; phải cộng cả chuỗi và giữ đúng thứ tự.

[Quay lại câu hỏi](03_Mang_Stack_Queue.md#lt3-13)

<a id="lt3-14"></a>

### LT3-14

**Câu hỏi:** Thiết kế một Stack hỗ trợ push, pop và getMin; mỗi thao tác phải O(1) trong trường hợp xấu, kể cả khi có nhiều giá trị bằng nhau và các thao tác xen kẽ bất kỳ. Không được quét lại Stack sau pop. Các vùng lưu trữ đã đủ sức chứa, truy cập một ô/so một giá trị tốn O(1); pop và getMin trên Stack rỗng phải báo không có phần tử. Hãy tự chọn thông tin phụ, phát biểu bất biến và giải thích vì sao nó đủ để khôi phục min sau mọi lần pop, rồi phân tích bộ nhớ phụ.

**Câu hỏi tiếp:** Một đề xuất tiết kiệm bộ nhớ chỉ lưu các lần xuất hiện min mới nhỏ hơn nghiêm ngặt; khi pop giá trị bằng min hiện tại thì bỏ mốc đó. Không lưu số lần min trùng. Tự dựng chuỗi ngắn bác bỏ đề xuất, rồi nêu một cách nén các min bằng nhau mà vẫn đúng. So lượng bộ nhớ phụ trên dãy toàn bằng với dãy giảm nghiêm ngặt.

**Ý cần nắm:** Một cách là lưu ở mỗi mức giá trị nhỏ nhất của tiền tố tới mức đó. Push tạo mức mới với min của giá trị mới và min cũ; pop bỏ mức hiện tại, thông tin của mức trước đã có sẵn. Bất biến này đúng quy nạp theo từng thao tác, kể cả khóa trùng. getMin đọc thông tin ở đỉnh; các phép trên Stack rỗng không đọc ô và không thay trạng thái. Thời gian O(1) mỗi thao tác theo mô hình đã cho, bộ nhớ phụ O(n) với n phần tử đang có. Đề xuất chỉ giữ min mới nghiêm ngặt hỏng với push 2, push 2, pop: Stack còn một số 2 nhưng mốc min duy nhất đã bị bỏ. Có thể sửa bằng cách giữ cả các lần bằng nhau, hoặc nén thành các cặp (giá trị min, số lần xuất hiện của min đó kể từ khi mốc ấy được mở). Với cách nén, push nhỏ hơn min thì mở mốc mới có số lần 1; bằng min thì tăng số lần của mốc đỉnh; lớn hơn thì giữ metadata. Khi pop đúng min, giảm số lần và chỉ bỏ mốc khi số lần về 0; pop giá trị lớn hơn không đổi mốc. LIFO bảo đảm các giá trị nhỏ hơn được thêm về sau phải được lấy ra trước khi một mốc cũ cần dùng lại. Với n phần tử bằng nhau, cách nén giữ một cặp; với dãy giảm nghiêm ngặt, cần n mốc, nên bộ nhớ phụ xấu nhất vẫn O(n). Đây là cận của phương án, không phải chứng minh cận dưới cho mọi biểu diễn.

**Cần thể hiện khi trả lời:**

- Tự thiết kế thông tin phụ và chứng minh bất biến qua push/pop, kể cả rỗng và trùng.
- Tự dựng phản ví dụ, sửa cơ chế đếm min trùng và phân biệt bộ nhớ từng họ dữ liệu với cận xấu nhất.

**Tránh nhầm:** Số lần xuất hiện phải đi cùng đúng mốc min đang hoạt động. Một biến min hoặc một danh sách chỉ có các giá trị min phân biệt mà thiếu thông tin phục hồi không đủ.

[Quay lại câu hỏi](03_Mang_Stack_Queue.md#lt3-14)

<a id="lt3-15"></a>

### LT3-15

**Câu hỏi:** Hai Stack chia sẻ mảng M ô, mỗi Stack chiếm một đoạn liên tục; phần tử đang sống không được di chuyển, không có liên kết riêng trong mỗi ô, chỉ được dùng O(1) biến chỉ số. Hãy thiết kế cách dùng được toàn bộ sức chứa: nếu tổng số phần tử nhỏ hơn M thì lần push vào bất kỳ Stack nào cũng thành công. Chứng minh điều kiện đầy và thời gian push/pop.

**Câu hỏi tiếp:** Nếu tăng thành ba Stack và vẫn giữ mọi ràng buộc trên, một cách bố trí mỗi Stack thành một đoạn liên tục có luôn tận dụng được ô trống cho Stack được chọn không? Dựng một trạng thái cùng yêu cầu push làm rõ giới hạn; đừng suy rộng thành bất khả thi với mọi cách biểu diễn.

**Ý cần nắm:** Với hai Stack, đặt chúng ở hai đầu mảng và tăng vào khoảng trống chung; có thể dùng hai độ dài a,b với a+b≤M. Khi a+b<M, cả hai phía đều có một ô kề hướng tăng còn trống; push/pop chỉ sửa một ô và chỉ số nên O(1), không chuyển phần tử cũ. Khi đủ M ô thì mọi push phải từ chối. Với ba đoạn sống không rỗng, ví dụ M=8 có các đoạn [1,2],[3,4],[5,6] và hai ô 0,7 trống, Stack giữa không thể tăng mà vẫn liên tục và không chuyển phần tử cũ. Có thể lập luận tổng quát hơn khi M≥4: sau M−1 lần push được phân vào đủ cả ba Stack, chỉ còn một ô trống. Một ô chỉ kề tối đa hai đoạn sống, nên có ít nhất một Stack không thể nhận ô đó mà vẫn giữ đoạn liên tục. Nếu một cách bố trí đã từ chối trước khi đến trạng thái này thì nó cũng đã vi phạm yêu cầu tận dụng mọi ô trống. Phải nới điều kiện không di chuyển, cho phép một Stack có nhiều đoạn, hoặc dùng biểu diễn có liên kết và thông tin quản lý khác.

**Cần thể hiện khi trả lời:**

- Chứng minh hai Stack tăng từ hai đầu dùng được mọi ô trống.
- Nêu ca ba đoạn bị chặn và chỉ đúng ràng buộc cần nới, không tuyên bố bất khả thi tuyệt đối.

**Tránh nhầm:** Kết luận cho ba Stack phụ thuộc yêu cầu đoạn liên tục và không di chuyển; dùng liên kết trong từng ô hoặc cho phép dồn mảng là bài toán khác.

[Quay lại câu hỏi](03_Mang_Stack_Queue.md#lt3-15)

<a id="lt3-16"></a>

### LT3-16

**Câu hỏi:** Mảng n bản ghi cần loại mọi bản ghi không thỏa điều kiện, giữ thứ tự tương đối của các bản ghi còn lại; điều kiện chỉ phụ thuộc nội dung bản ghi gốc. Cách A gặp một bản ghi cần bỏ thì xóa bằng dịch toàn bộ đuôi. Hãy dựng dữ liệu làm tổng công việc bậc hai, rồi nêu một bất biến cho cách nén tại chỗ chỉ tuyến tính. Khi lọc xong, những chỉ số cũ của bên ngoài có còn chỉ đúng bản ghi không?

**Ý cần nắm:** Nếu hầu hết hoặc tất cả phần tử bị loại và mỗi lần đều dịch phần đuôi, số lần chuyển có thể là (n−1)+(n−2)+… nên Theta(n²). Có thể tách vị trí đang đọc khỏi độ dài phần giữ: tiền tố đã ghi chứa đúng các bản ghi đạt yêu cầu đã đọc, theo thứ tự cũ; vị trí ghi không vượt vị trí đọc nên không đè dữ liệu chưa xét. Mỗi bản ghi được xét một lần và chuyển tối đa một lần, cho O(n) với thao tác bản ghi hằng số. Số lượng logic phải được chốt đúng; các chỉ số cũ sau điểm bị loại có thể đổi ý nghĩa dù mảng vẫn ở cùng địa chỉ.

**Cần thể hiện khi trả lời:**

- Dựng ca dịch lặp bậc hai, nêu bất biến vùng đã giữ của cách nén.
- Bảo vệ không ghi đè dữ liệu chưa đọc và nêu tác động lên chỉ số cũ.

**Tránh nhầm:** Tại chỗ không có nghĩa là giữ nguyên vị trí từng bản ghi hoặc mọi tham chiếu bên ngoài.

[Quay lại câu hỏi](03_Mang_Stack_Queue.md#lt3-16)

<a id="lt3-17"></a>

### LT3-17

**Câu hỏi:** Mảng chứa n>0 bản ghi ở đúng tiền tố 0…n−1, còn thứ tự giữa các bản ghi không có ý nghĩa. Đã biết chỉ số i cần xóa; di chuyển một bản ghi tốn O(1). Hãy đề xuất cách xóa O(1) vẫn giữ phần còn lại thành một tiền tố đặc, và nêu thông tin nào của các bản ghi còn sống có thể thay đổi.

**Câu hỏi tiếp:** Bổ sung yêu cầu mọi bản ghi còn sống phải giữ nguyên chỉ số cũ, vẫn không được để lỗ trong tiền tố. Hai yêu cầu này có luôn cùng thỏa khi xóa ở giữa không? Dùng trường hợp nhỏ để bảo vệ kết luận và nêu một yêu cầu phải nới.

**Ý cần nắm:** Có thể đưa bản ghi cuối vào ô i rồi giảm n; nếu i đã là cuối thì chỉ giảm n. Số thao tác hằng số, nhưng bản ghi cuối đổi chỉ số, thứ tự bị thay đổi; nếu có ánh xạ chỉ số bên ngoài thì phải cập nhật đúng chi phí của ánh xạ đó. Với n=3, xóa i=1: tiền tố mới chỉ gồm 0,1; bản ghi cũ ở 2 không thể vừa giữ chỉ số 2 vừa nằm trong tiền tố mới. Vì thế phải cho phép đổi chỉ số, chấp nhận lỗ hoặc dùng một lớp định danh ổn định tách khỏi vị trí. Nếu mảng chứa đối tượng trực tiếp, di chuyển có thể ảnh hưởng con trỏ tới đối tượng; nếu chứa con trỏ thì đối tượng được cấp riêng có thể giữ địa chỉ.

**Cần thể hiện khi trả lời:**

- Tự tìm cách lấp chỗ trống bằng số thao tác hằng số và xét xóa cuối.
- Chứng minh xung đột giữa giữ mọi chỉ số và tiền tố đặc, phân biệt chỉ số với danh tính.

**Tránh nhầm:** O(1) ở đây giả định đã có chỉ số và bản ghi chuyển được với chi phí hằng số; không bao gồm tìm bản ghi hoặc một ánh xạ phụ chưa được tính.

[Quay lại câu hỏi](03_Mang_Stack_Queue.md#lt3-17)

<a id="lt3-18"></a>

### LT3-18

**Câu hỏi:** Nhóm muốn dùng chỉ số ô mảng làm mã bền vững cho đầu sách: xóa ô 3 thì lần thêm sau dùng lại mã 3. Một lịch sử cũ chỉ lưu mã đó. Hãy dựng chuỗi khiến lịch sử vẫn tra được một bản ghi nhưng lại chỉ nhầm đầu sách, kể cả khi không có lỗi truy cập bộ nhớ. Muốn dùng một vị trí lưu trữ làm định danh thì phải bổ sung hoặc thay đổi điều kiện gì, và ràng buộc của đề Thư viện cần được giữ ra sao?

**Ý cần nắm:** Đầu sách A từng ở ô 3 và có lịch sử trỏ mã 3; sau khi xóa A rồi đặt B vào ô đó, tra mã 3 trả B, làm lịch sử cũ đổi đối tượng. Đây là lỗi danh tính dù địa chỉ và chỉ số đều hợp lệ. Muốn định danh bền phải có cơ chế phân biệt các lần sử dụng vị trí, không tái dùng định danh còn được tham chiếu, hoặc cập nhật/mô hình hóa lịch sử theo hợp đồng được chấp nhận. Đề đã có ISBN và mã cuốn riêng; vị trí mảng không được tự thay thế ý nghĩa các mã này, cũng không tự sửa chính sách lịch sử để tiện tái dùng ô.

**Cần thể hiện khi trả lời:**

- Dựng chuỗi tái dùng vị trí làm lịch sử trỏ nhầm dù truy cập hợp lệ.
- Tách định danh bền khỏi vị trí, giữ ý nghĩa mã theo đề.

**Tránh nhầm:** Tra được một bản ghi không đồng nghĩa tra đúng đối tượng mà dữ liệu lịch sử đã nhắc tới.

[Quay lại câu hỏi](03_Mang_Stack_Queue.md#lt3-18)

<a id="lt3-19"></a>

### LT3-19

**Câu hỏi:** Khi đổi biểu thức trung tố sang hậu tố, một quy tắc luôn đẩy toán tử đang chờ ra nếu ưu tiên của nó lớn hơn toán tử mới; quy tắc khác dùng lớn hơn hoặc bằng. Phép trừ kết hợp trái, lũy thừa ký hiệu ^ kết hợp phải theo toán học; ngoặc phải được tôn trọng. Có một trong hai quy tắc dùng nguyên xi đúng cho cả hai loại toán tử không? Tự tạo các biểu thức phân biệt và suy ra điều kiện xử lý khi hai ưu tiên bằng nhau.

**Câu hỏi tiếp:** Vì sao chọn ví dụ 2^2^2 chưa đủ để kiểm tính kết hợp bằng kết quả số? Nêu một ví dụ khác thật sự phát hiện sai và nói rõ vai trò của ngoặc mở trong Stack toán tử.

**Ý cần nắm:** Không có quy tắc cố định > hoặc ≥ đúng cho cả hai. Với 8−3−2, đúng là (8−3)−2=3; nếu không đẩy phép trừ cũ khi ưu tiên bằng nhau thì thành 8−(3−2)=7. Với 2^3^2, đúng là 2^(3^2)=512; nếu đẩy ^ cũ ở dấu bằng thì thành (2^3)^2=64. Khi xét toán tử mới, đẩy toán tử ở đỉnh nếu nó có ưu tiên lớn hơn, hoặc cùng ưu tiên và toán tử mới kết hợp trái; phép ^ kết hợp phải cần giữ toán tử cùng ưu tiên chờ lại. Ngoặc mở là ranh giới, không đẩy toán tử qua đó; ngoặc đóng xử lý tới ngoặc mở tương ứng. 2^2^2 cho 16 theo cả hai cách đặt ngoặc nên có thể che lỗi dù cây biểu thức khác nhau.

**Cần thể hiện khi trả lời:**

- Dựng ví dụ phân biệt cho cả kết hợp trái và phải.
- Nêu quy tắc dấu bằng theo toán tử mới và nhận ra một test số có thể không phân biệt được lỗi.

**Tránh nhầm:** Ký hiệu ^ được định nghĩa là lũy thừa trong bài này, không phải toán tử XOR của C++. Hai cây phân tích khác nhau có thể tình cờ cho cùng giá trị.

[Quay lại câu hỏi](03_Mang_Stack_Queue.md#lt3-19)

<a id="lt3-20"></a>

### LT3-20

**Câu hỏi:** Chuỗi chỉ gồm hai loại ngoặc () và []. Một bộ kiểm giữ hai bộ đếm riêng: ngoặc mở tăng bộ đếm tương ứng, ngoặc đóng giảm; từ chối nếu bộ đếm nào âm ở bất kỳ tiền tố nào, chấp nhận nếu cuối cùng cả hai bằng 0. Bộ kiểm có đủ xác nhận ngoặc lồng đúng không? Nếu không, hãy tìm phản ví dụ ngắn nhất và giải thích vì sao không thể ngắn hơn.

**Câu hỏi tiếp:** Đề xuất lượng thông tin cần giữ để kiểm đúng thứ tự lồng; phát biểu bất biến và chi phí theo độ dài n, độ sâu lồng lớn nhất d. So với trường hợp chỉ có một loại ngoặc.

**Ý cần nắm:** Phản ví dụ ([)] dài 4: cả hai bộ đếm luôn không âm và kết thúc bằng 0, nhưng ) đóng sai loại đang mở gần nhất. Chuỗi được bộ đếm chấp nhận có độ dài chẵn; độ dài 0 hợp lệ, độ dài 2 muốn đủ số mở/đóng của từng loại và không âm thì chỉ có () hoặc [], đều hợp lệ. Vì thế 4 là ngắn nhất. Cần nhớ dãy loại ngoặc mở chưa đóng theo thứ tự; dùng Stack, gặp mở thì đưa loại vào, gặp đóng phải khớp đỉnh rồi lấy ra, cuối chuỗi Stack phải rỗng. Bất biến: Stack lưu đúng các ngoặc chưa khép từ ngoài vào trong của tiền tố đã xử lý. Thời gian O(n), bộ nhớ O(d) ô loại ngoặc. Với chỉ một loại, loại ở đỉnh đã biết nên bộ đếm độ sâu là đủ.

**Cần thể hiện khi trả lời:**

- Tự tạo phản ví dụ tối thiểu và bảo vệ tính tối thiểu.
- Mô tả thông tin thứ tự còn thiếu, bất biến Stack và chi phí.

**Tránh nhầm:** Hai số lượng đúng không xác định được thứ tự lồng. Cận bộ nhớ O(d) mô tả phương án Stack này; không cần suy diễn một định lý cận dưới cho mọi mô hình máy.

[Quay lại câu hỏi](03_Mang_Stack_Queue.md#lt3-20)

<a id="lt3-21"></a>

### LT3-21

**Câu hỏi:** Một Queue chỉ công khai thêm cuối và lấy đầu; phần tử không có chỉ mục ngoài. Người dùng muốn hủy phần tử mang mã x ở giữa, giữ thứ tự mọi phần tử còn lại, và hứa O(1) thời gian cho mọi x. Hãy bác hoặc bảo vệ lời hứa theo đúng giao diện này. Nếu chuyển sang danh sách đơn có head/tail thì riêng việc có tail đã đủ chưa? Vì sao thêm khả năng hủy không còn là chỉ dùng FIFO thuần túy?

**Ý cần nắm:** Với giao diện chỉ thấy đầu Queue, phần tử cần hủy có thể ở cuối hoặc không tồn tại; phải tiếp cận các phần tử trước để xác định, nên không có bảo đảm O(1) trong mô hình này. Có thể dùng thao tác quay vòng một số phần tử xác định để lọc và giữ thứ tự, nhưng công việc vẫn tuyến tính. Head/tail không cho ngay vị trí hay nút trước của x trong danh sách đơn; cần tìm hoặc duy trì thông tin phụ cùng nghĩa vụ cập nhật. Hủy theo mã là thao tác bổ sung ngoài giao diện FIFO cơ bản, nên phải thiết kế và phân tích hợp đồng mới.

**Cần thể hiện khi trả lời:**

- Bác cận O(1) theo đúng giao diện chỉ thấy đầu Queue.
- Tách tìm nút/nút trước khỏi thao tác nối, nêu API hủy là phần bổ sung.

**Tránh nhầm:** Không dùng tên Queue để bỏ qua chi phí tra cứu một phần tử không ở đầu.

[Quay lại câu hỏi](03_Mang_Stack_Queue.md#lt3-21)

<a id="lt3-22"></a>

### LT3-22

**Câu hỏi:** Mảng A có n≥1 phần tử tăng không giảm ở đầu và còn m≥1 ô trống phía sau; mảng B có m phần tử cũng tăng không giảm. Cần đưa toàn bộ vào A, giữ A trước B khi hai bản ghi bằng khóa và giữ thứ tự tương đối trong từng nguồn khi khóa bằng. So cách chèn lần lượt B từ trái sang phải bằng dịch đuôi, mỗi lần chèn sau các bản ghi cùng khóa đã có, với cách trộn từ cuối về đầu. Hãy tính chi phí theo n,m, rồi phân biệt chặn trên theo tổng N=n+m với điều kiện đạt bậc hai theo N. Bảo vệ việc không ghi đè dữ liệu A chưa đọc và quyết định lấy nguồn nào trước khi hai khóa bằng nhau ở bước đi từ cuối. Giả sử A và B không dùng chung vùng nhớ, mỗi lần so/chuyển bản ghi tốn O(1).

**Ý cần nắm:** Do B được chèn theo thứ tự tăng và sau các khóa bằng, các bản ghi B đã chèn không phải dịch lại khi chèn bản ghi B tiếp theo. Mỗi lần chỉ có thể dịch tối đa n bản ghi A gốc, nên tổng dịch không quá nm; đạt đúng nm khi mọi khóa B nhỏ hơn mọi khóa A. Với n,m≥1, chi phí dịch trong trường hợp xấu là Θ(nm); tìm vị trí và ghi phần tử mới phải tính thêm theo cách cài, không mặc định chỉ có dịch. Đặt N=n+m: nm≤N²/4 nên đây luôn là O(N²), nhưng để có Θ(N²) cần hai độ dài cùng bậc, tương đương n=Θ(N), m=Θ(N). Chỉ “n,m cùng tăng” chưa đủ: n=k,m=k² cho nm=k³ còn N²=Θ(k⁴). Nếu xét trường hợp xấu trên mọi cách chia một tổng N cố định, chọn hai độ dài gần N/2 đạt Θ(N²). Với trộn ngược, gọi a,b là số phần tử chưa đọc còn lại của A,B; vị trí ghi tiếp là a+b−1. Khi b>0, vị trí này lớn hơn a−1 nên không đè phần A chưa đọc; B nằm riêng. Chọn phần tử lớn hơn ở hai cuối, khi bằng nhau đặt bản ghi B vào vị trí sau trước, nhờ vậy A đứng trước B trong kết quả. Lấy từ cuối từng nguồn rồi ghi từ cuối cũng giữ thứ tự tương đối của khóa bằng trong chính nguồn đó. Khi B đã hết, phần A còn lại đã ở đúng chỗ; khi A hết, chép phần B còn lại. Tổng thời gian O(n+m), bộ nhớ phụ O(1) trong mô hình này.

**Cần thể hiện khi trả lời:**

- Tính số dịch theo n,m; phân biệt O(N²), Θ(N²) và điều kiện hai độ dài cùng bậc.
- Bảo vệ vùng ghi bằng a+b−1 so với a−1; xử lý khóa bằng để giữ A trước B và thứ tự từng nguồn.

**Tránh nhầm:** Giữ Θ(nm) khi hai độ dài là tham số độc lập. Không suy thành Θ((n+m)²) chỉ vì cả hai cùng tăng; trộn ngược còn phụ thuộc vùng trống, nguồn tách biệt và quy tắc hòa đúng.

[Quay lại câu hỏi](03_Mang_Stack_Queue.md#lt3-22)

## Chương IV — Danh sách liên kết

<a id="lt4-03"></a>

### LT4-03

**Câu hỏi:** Danh sách đơn A→B→C; chỉ có con trỏ p tới A, không có nút trước. Có con trỏ ngoài q tới đúng đối tượng B và q phải tiếp tục chỉ B sau khi xóa A. Một mẹo đề xuất sao chép nội dung B vào A rồi hủy nút B để đạt O(1). Cách đó có đáp ứng hợp đồng không? Nếu chỉ nhìn dãy giá trị in ra thì có thể bỏ sót điều gì? Hãy xét thêm trường hợp p là nút cuối.

**Ý cần nắm:** Dãy giá trị có thể trông như B,C, nhưng đối tượng B gốc bị hủy khiến q không còn hợp lệ; A gốc lại tồn tại với nội dung mới. Vì hợp đồng yêu cầu xóa đúng A và bảo toàn đối tượng B, mẹo đó không đáp ứng dù giá trị in có vẻ đúng. Nếu nội dung có tài nguyên sở hữu thì sao chép còn có thể gây chia sẻ hoặc hủy sai. Với nút cuối, không có nút sau để sao chép; chỉ có p không đủ nối lại nút trước trong danh sách đơn thông thường.

**Cần thể hiện khi trả lời:**

- Phân biệt xóa đối tượng A với thay giá trị rồi hủy B, theo dõi q.
- Xét nút cuối và tài nguyên sở hữu thay vì chỉ dãy in ra.

**Tránh nhầm:** Phân biệt xóa một giá trị khỏi dãy với xóa đúng đối tượng và giữ danh tính các nút còn lại.

[Quay lại câu hỏi](04_DanhSachLienKet.md#lt4-03)

<a id="lt4-04"></a>

### LT4-04

**Câu hỏi:** Hai danh sách đơn tách rời: L1=A→B→C→D, L2=X→Y; mỗi danh sách có head,tail và số lượng. Cần chuyển nguyên đoạn B→C từ L1 sang cuối L2, giữ địa chỉ mọi nút và không cấp nút mới. Hãy mô tả trạng thái cuối, các bất biến cần kiểm và lý do chỉ kiểm số lượng là chưa đủ. Nếu đoạn chuyển là toàn bộ L1 và L2 ban đầu rỗng, những đầu quản lý nào thay đổi?

**Ý cần nắm:** Trạng thái cuối thông thường: L1=A→D, head A,tail D,số lượng 2; L2=X→Y→B→C, head X,tail C,số lượng 4; next cuối mỗi danh sách là null. Tập nút toàn cục vẫn là sáu nút ban đầu, mỗi nút thuộc đúng một danh sách, không có vòng và không mất đường tới nút. Chỉ số lượng đúng vẫn có thể che chia sẻ nút hoặc mất một nút rồi đếm nhầm nút khác. Nếu chuyển toàn bộ nguồn sang đích rỗng, nguồn phải rỗng cả head/tail/count, đích nhận hai đầu và số lượng của đoạn; cần xét các con trỏ tham chiếu ngoài theo hợp đồng mới.

**Cần thể hiện khi trả lời:**

- Nêu đúng chuỗi nút, head/tail/count và quyền sở hữu sau chuyển đoạn.
- Xét nguồn hết/đích rỗng, kiểm không mất nút, chia sẻ hoặc tạo vòng.

**Tránh nhầm:** Đây là suy luận trạng thái và quyền sở hữu của phép chuyển; không chỉ xem các giá trị cuối có đúng thứ tự.

[Quay lại câu hỏi](04_DanhSachLienKet.md#lt4-04)

<a id="lt4-05"></a>

### LT4-05

**Câu hỏi:** Danh sách có head và tail chứa A,B,C,D; A,B,D cần bị loại, chỉ C được giữ. Một cách duyệt sau mỗi lần xóa lại tiến thêm một nút và cập nhật “nút trước” như thể nút vừa xóa còn tồn tại. Hãy chỉ ra hai kiểu lỗi có thể xảy ra, nêu trạng thái cuối đúng và phát biểu một bất biến đủ giúp duyệt/xóa cả các nút liên tiếp mà không bỏ sót. Trường hợp mọi nút đều bị loại phải thỏa điều gì?

**Ý cần nắm:** Có thể bỏ qua B sau khi xóa A vì tiến quá xa, hoặc giữ con trỏ trước tới nút đã hủy rồi truy cập nó ở lần nối sau. Cuối đúng chỉ còn C, head=tail=C và C không có nút kế. Một bất biến phù hợp: phần đã xét gồm đúng các nút được giữ, nút trước là nút được giữ cuối cùng hoặc không có, còn nút hiện tại là nút chưa xét đầu tiên. Xóa một nút không biến nó thành “nút trước”; cách lưu điểm tiếp tục phải tránh đọc lại vùng đã hủy. Nếu loại tất cả, cả head và tail phản ánh rỗng, số lượng bằng 0.

**Cần thể hiện khi trả lời:**

- Nhận diện bỏ sót nút liên tiếp và con trỏ tới vùng đã hủy.
- Nêu bất biến nút trước được giữ, xét chỉ còn C và loại hết.

**Tránh nhầm:** Tiến trình duyệt phải được lập luận theo các nút chưa xét, không theo số lần tăng một con trỏ.

[Quay lại câu hỏi](04_DanhSachLienKet.md#lt4-05)

<a id="lt4-07"></a>

### LT4-07

**Câu hỏi:** Tìm nhị phân trên danh sách đơn đã tăng: cách A mỗi lần tìm giữa bằng cách đi từ đầu của đoạn ứng viên hiện tại, cách B luôn đi từ head toàn danh sách tới chỉ số giữa toàn cục. Biết sẵn độ dài đoạn, đi một liên kết và so một khóa đều O(1). Với truy vấn lớn hơn mọi khóa, hãy đánh giá số lần so sánh và số bước đi liên kết của mỗi cách. Có cách nào trong hai cách bảo đảm thời gian O(log n) không?

**Ý cần nắm:** Cả hai giảm số ứng viên khoảng một nửa nên có O(log n) so sánh khóa. A đi khoảng n/2+n/4+… bước tìm giữa, tổng O(n), và trường hợp này Theta(n). B đi lại từ head tới các vị trí khoảng n/2,3n/4,7n/8,…; có Theta(log n) lượt mà hầu hết đi Theta(n) liên kết, nên Theta(n log n) bước. Không cách nào bảo đảm thời gian O(log n) trong mô hình này. Một phép tìm tuần tự đã là Theta(n) xấu nhất và còn đơn giản hơn; ít so sánh có thể có ý nghĩa riêng nếu so khóa rất đắt.

**Cần thể hiện khi trả lời:**

- Đếm riêng số so khóa và bước đi liên kết của hai cách tìm giữa.
- Bảo vệ cận tuyến tính so với n log n, không gán truy cập O(1) cho danh sách.

**Tránh nhầm:** Không đánh đồng số phép so sánh với thời gian truy cập nút; phải nêu rõ điểm xuất phát của mỗi lượt đi.

[Quay lại câu hỏi](04_DanhSachLienKet.md#lt4-07)

<a id="lt4-09"></a>

### LT4-09

**Câu hỏi:** Cần trộn hai danh sách tăng bằng cách nối lại các nút, không cấp nút mới, và kết quả phải là một danh sách tăng độc lập. Người gọi đồng thời yêu cầu hai danh sách nguồn vẫn giữ nguyên toàn bộ liên kết để tiếp tục dùng. Các yêu cầu này có tương thích nói chung không? Xét thêm đầu vào L1=1→4→7 và L2=2→4→7, trong đó hai nút 4 và 7 thực sự dùng chung địa chỉ, không phải bản sao. Điều kiện nào của phép trộn thông thường đã bị vi phạm?

**Ý cần nắm:** Với các nút liên kết đơn chỉ có một next, việc tạo kết quả xen kẽ bằng cách đổi next nhìn chung làm thay đổi ít nhất một nguồn. Muốn giữ nguồn nguyên vẹn và có kết quả độc lập phải cho phép bản sao nút, một biểu diễn tham chiếu riêng hoặc thay hợp đồng sở hữu. Đầu vào dùng chung đuôi còn vi phạm giả thiết hai tập nút nguồn tách rời; có thể đưa cùng nút vào kết quả hai lần, tạo vòng hoặc hủy lặp. Hai lượt xuất hiện giá trị 4 trong hai nguồn không tương đương có hai đối tượng 4 riêng biệt.

**Cần thể hiện khi trả lời:**

- Nêu xung đột một next khi vừa nối lại vừa muốn giữ nguyên hai nguồn.
- Phân biệt chung địa chỉ đuôi với chỉ trùng giá trị và nêu tiền điều kiện tách rời.

**Tránh nhầm:** Cận O(n+m) của trộn không chứng minh phép trộn đúng khi hợp đồng sở hữu hoặc tính tách rời của nguồn bị vi phạm.

[Quay lại câu hỏi](04_DanhSachLienKet.md#lt4-09)

<a id="lt4-10"></a>

### LT4-10

**Câu hỏi:** Danh sách vòng chỉ giữ tail; nếu không rỗng thì head được suy ra là nút sau tail. Ban đầu vòng A→B→C→A, tail=C. Một vòng duyệt nhớ head=A làm mốc kết thúc nhưng xóa và giải phóng A ngay lần đầu. Vì sao “cứ đi tới khi gặp lại địa chỉ A” không còn là lập luận đúng? Hãy nêu một cách xác định phạm vi duyệt an toàn bằng lời, rồi xử lý riêng việc xóa nút duy nhất.

**Ý cần nắm:** Sau khi A bị tháo khỏi vòng, các nút còn lại không còn đường đi về A nên điều kiện gặp lại mốc cũ có thể không bao giờ xảy ra; đọc A đã hủy cũng không hợp lệ. Có thể dựa trên số nút ban đầu nếu biết chính xác và mỗi lượt xử lý đúng một nút ban đầu, giữ điểm tiếp tục hợp lệ trước khi hủy; hoặc chọn một mốc còn sống với quy tắc cập nhật/dừng được chứng minh. Khi xóa nút duy nhất, tail phải trở thành rỗng, không còn head để suy từ tail; không đi tiếp qua liên kết tự trỏ của nút đã hủy.

**Cần thể hiện khi trả lời:**

- Chỉ ra mốc A đã bị loại không còn là căn cứ dừng.
- Nêu phạm vi duyệt an toàn và xử lý vòng một nút.

**Tránh nhầm:** Mốc dừng dùng địa chỉ chỉ có ý nghĩa khi mốc còn thuộc cấu trúc đang duyệt hoặc có quy tắc khác bảo đảm dừng.

[Quay lại câu hỏi](04_DanhSachLienKet.md#lt4-10)

<a id="lt4-15"></a>

### LT4-15

**Câu hỏi:** Danh sách đơn gồm các đối tượng A→B→C→D→E→F; cần đảo thứ tự đoạn B…E nhưng giữ nguyên địa chỉ và nội dung từng đối tượng. Bên ngoài có con trỏ tới C. Một bạn đổi nội dung B với E, C với D thay vì đổi liên kết, vì kết quả in tên giống yêu cầu. Hãy nêu chuỗi nút cuối đúng, phân tích điều gì bên ngoài sẽ quan sát khác và chỉ ra hai ranh giới của đoạn cần được nối đúng khi đảo bằng liên kết.

**Ý cần nắm:** Chuỗi đối tượng cuối phải là A→E→D→C→B→F; con trỏ ngoài vẫn tới đúng C với nguyên nội dung của C. Đổi dữ liệu tại địa chỉ C khiến con trỏ ấy quan sát nội dung D, trái với hợp đồng giữ danh tính đối tượng dù dãy tên in ra có thể giống. Khi đổi liên kết phải nối phần trước đoạn vào đầu mới E và đuôi mới B vào phần sau F, đồng thời giữ đường tới các nút đang chưa xử lý. Trường hợp đoạn chạm head hoặc tail cần cập nhật đúng đầu quản lý tương ứng; không được mặc định cả hai ranh giới đều có nút ngoài.

**Cần thể hiện khi trả lời:**

- Cho đúng chuỗi đối tượng sau đảo, bảo toàn nội dung ở địa chỉ C.
- Nêu hai ranh giới nối và các trường hợp chạm head/tail.

**Tránh nhầm:** Đảo thứ tự đối tượng và tráo nội dung giữa các đối tượng không tương đương khi có tham chiếu bên ngoài.

[Quay lại câu hỏi](04_DanhSachLienKet.md#lt4-15)

<a id="lt4-16"></a>

### LT4-16

**Câu hỏi:** Danh sách đi từ A→B→C→D→E→F rồi F nối về C. Hai con trỏ cùng bắt đầu ở A, mỗi lượt một con đi một liên kết, con kia đi hai. Hãy xác định lần gặp đầu sau khi bắt đầu di chuyển và cho biết đó có phải luôn là điểm vào vòng không. Sau khi gặp, đặt một con về A, con kia giữ ở chỗ gặp rồi cho cả hai đi từng bước: vì sao cách này xác định được điểm vào vòng?

**Ý cần nắm:** Các cặp sau bốn lượt là (B,C),(C,E),(D,C),(E,E), nên gặp ở E, không phải điểm vào C. Độ dài phần không vòng là μ=2, độ dài vòng λ=4. Nếu con chậm đã đi t bước khi gặp, con nhanh đi 2t, nên chênh t là bội của λ; vị trí gặp cách đầu vòng theo hướng đi một lượng tương đương t−μ. Đi thêm μ bước từ đó sẽ tới đầu vòng, đồng thời con đặt lại ở A cũng vừa đi hết đoạn không vòng. Tổng công việc O(μ+λ) và chỉ dùng số con trỏ hằng số; danh sách không vòng phải kiểm hết đường hợp lệ trước khi đi hai bước.

**Cần thể hiện khi trả lời:**

- Truy vết lần gặp E và chứng minh bước tìm điểm vào bằng độ dài vòng/tiền tố.
- Không đồng nhất chỗ gặp với đầu vòng; tính thời gian và bộ nhớ.

**Tránh nhầm:** Điểm gặp đầu không mặc định là điểm bắt đầu vòng; lập luận cần dùng khoảng cách trên vòng, không chỉ nhìn hình vẽ.

[Quay lại câu hỏi](04_DanhSachLienKet.md#lt4-16)

<a id="lt4-17"></a>

### LT4-17

**Câu hỏi:** Hai danh sách đơn không vòng có thể dùng chung một đoạn đuôi; nội dung các nút có thể trùng dù địa chỉ khác. Không được sửa liên kết hoặc đánh dấu vào nút. Biết độ dài hai danh sách là m và n, hãy tìm cách xác định nút chung đầu tiên trong O(m+n) thời gian và O(1) bộ nhớ phụ, đồng thời giải thích vì sao so giá trị hoặc cứ đi hai con trỏ từ hai head cùng tốc độ có thể sai.

**Ý cần nắm:** Cho con trỏ của danh sách dài hơn đi trước đúng phần chênh độ dài, rồi cho hai con cùng tiến và so địa chỉ. Khi đã cách cuối bằng nhau, nếu có chung đuôi thì hai con gặp đúng nút chung đầu; nếu không, cùng hết danh sách mà chưa gặp. Hai nút bằng giá trị chưa chắc cùng đối tượng. Đi từ hai head ngay với cùng tốc độ giữ nguyên khoảng lệch nếu các tiền tố dài khác nhau, nên có thể không cùng tới nút chung. Nếu chưa biết độ dài, đếm trước vẫn giữ tổng O(m+n) và bộ nhớ phụ hằng số.

**Cần thể hiện khi trả lời:**

- Căn chỉnh số bước còn tới cuối rồi so địa chỉ.
- Bảo vệ nút chung đầu, ca không chung và chi phí O(m+n), O(1).

**Tránh nhầm:** Giả thiết không vòng quan trọng vì cần độ dài hữu hạn và điểm kết thúc chung để căn chỉnh.

[Quay lại câu hỏi](04_DanhSachLienKet.md#lt4-17)

<a id="lt4-18"></a>

### LT4-18

**Câu hỏi:** Hai danh sách vòng đơn tách rời, mỗi danh sách chỉ giữ tail: vòng thứ nhất A→B→C→A, tail=C; vòng thứ hai D→E→D, tail=E. Cần nối thành một vòng theo thứ tự A,B,C,D,E mà không cấp nút. Hãy nêu quan hệ liên kết cuối và giải thích vì sao thao tác có thể O(1) khi đã có hai tail. Nếu hai tail thực ra thuộc cùng một vòng, tiền điều kiện nào mất đi và việc kiểm tiền điều kiện có còn tự O(1) không?

**Ý cần nắm:** Cuối cùng C nối D, E nối A và tail kết quả là E nếu giữ head A; các liên kết trong hai đoạn còn lại giữ nguyên. Có hai tail thì suy ra được hai head qua next, nên chỉ đổi số liên kết hằng số. Nếu hai tail nằm trong cùng vòng, đây không còn là nối hai tập nút tách rời; thay hai liên kết có thể tách vòng hoặc đổi thứ tự ngoài ý muốn. Không có thêm thông tin sở hữu thì xác nhận hai vòng tách rời có thể cần duyệt; không được bỏ chi phí kiểm tra rồi quảng cáo toàn bộ API luôn O(1).

**Cần thể hiện khi trả lời:**

- Nêu đúng hai liên kết đổi và tail kết quả.
- Tách chi phí nối khỏi xác minh hai vòng tách rời.

**Tránh nhầm:** Cận O(1) của cập nhật liên kết chỉ áp dụng sau khi tiền điều kiện về hai nguồn hợp lệ đã được bảo đảm.

[Quay lại câu hỏi](04_DanhSachLienKet.md#lt4-18)

<a id="lt4-20"></a>

### LT4-20

**Câu hỏi:** Mỗi nút danh sách ngoài sở hữu một danh sách con riêng. Một bản sao mới đã cấp nút ngoài mới và nối next mới, nhưng chỉ sao chép địa chỉ danh sách con của từng nút. Nhóm gọi đây là “sao chép sâu vì các nút ngoài khác địa chỉ”. Hãy đưa hai phép thử bằng lời có thể bác bỏ tính độc lập, nêu phạm vi tài nguyên cần xét và yêu cầu xử lý nếu sao chép thất bại giữa danh sách con thứ hai.

**Ý cần nắm:** Sửa một nút trong danh sách con của bản sao có thể làm nguồn thay đổi; hủy bản sao rồi đọc/hủy danh sách con nguồn có thể gặp con trỏ không hợp lệ hoặc giải phóng lặp nếu cả hai đều nhận quyền sở hữu. Phải xét toàn bộ vùng dữ liệu có thể sửa và tài nguyên mà hợp đồng yêu cầu sở hữu độc lập, không chỉ lớp nút ngoài. Nếu lỗi giữa chừng, cần thu hồi đúng phần đã tạo cho bản sao, không hủy tài nguyên nguồn đang bị chia sẻ ngoài ý muốn, và không công bố bản sao dở như một kết quả hoàn chỉnh.

**Cần thể hiện khi trả lời:**

- Dùng phép sửa và hủy để phân biệt sao lớp ngoài với sao độc lập mọi tài nguyên.
- Nêu thu hồi phần sao dở mà không hủy dữ liệu nguồn.

**Tránh nhầm:** Khác địa chỉ ở lớp ngoài không chứng minh các cấu trúc lồng bên trong đã độc lập.

[Quay lại câu hỏi](04_DanhSachLienKet.md#lt4-20)

<a id="lt4-21"></a>

### LT4-21

**Câu hỏi:** Hai danh sách kép vòng tách rời có lính canh S₁,S₂ và biến count chỉ đếm bản ghi. Ban đầu L₁ có A,B,C theo chiều next; L₂ rỗng. Thực hiện lần lượt: chuyển đoạn B…C từ L₁ vào ngay trước S₂; sau đó chuyển A từ L₁ vào ngay trước B của L₂. Không cấp/hủy nút, địa chỉ và nội dung bản ghi giữ nguyên. Hãy nêu cấu trúc cả hai chiều và count sau từng bước, rồi phát biểu bất biến để nguồn rỗng vẫn là cấu trúc hợp lệ. Đã biết hai đầu đoạn và điểm chèn, nhưng chưa biết số nút của một đoạn bất kỳ: lời hứa “toàn phép chuyển luôn O(1)” có đúng khi phải cập nhật count không?

**Câu hỏi tiếp:** Mở rộng thao tác sang chuyển đoạn trong cùng một danh sách. Hợp đồng yêu cầu không làm gì nếu điểm chèn p nằm trong đoạn; đầu/cuối đoạn được bảo đảm hợp lệ, nhưng chưa có thông tin p có thuộc đoạn hay không. Cần kiểm gì trước khi thay liên kết? Phân biệt chi phí kiểm điều kiện, cập nhật count và nối lại. Xét thêm trường hợp p là nút ngay sau đoạn.

**Ý cần nắm:** Sau bước một, chiều next là S₁→A→S₁ và S₂→B→C→S₂, count lần lượt 1,2; chiều prev là các chuỗi đảo tương ứng. Sau bước hai, S₁.next=S₁.prev=S₁, count₁=0; chiều next của L₂ là S₂→A→B→C→S₂, chiều prev là S₂→C→B→A→S₂, count₂=3. Mỗi nút thuộc đúng một vòng, next/prev phải đối ứng ở mọi cạnh, vòng đi qua đúng lính canh của danh sách đó, count không gồm lính canh; toàn bộ tập bản ghi và địa chỉ được bảo toàn. Cần giữ các hàng xóm ở ranh giới trước khi đổi liên kết, đặc biệt khi nguồn hết nút hoặc đích đang rỗng. Nối bỏ/chèn một đoạn có các đầu đã biết chỉ sửa số liên kết hằng số, nhưng nếu đoạn dài k chưa có sẵn số lượng thì có thể phải duyệt Θ(k) để cập nhật hai count. Nếu k đã biết đúng và các tiền điều kiện đã được bảo đảm thì phần cập nhật cấu trúc/count mới O(1). Với cùng danh sách, cần xác nhận p không nằm trong đoạn trước khi tháo; nếu nằm trong thì trả về không đổi theo hợp đồng. Không có thông tin phụ, phép kiểm này có thể Θ(k); count tổng không đổi. Nếu p chính là nút ngay sau đoạn thì thứ tự yêu cầu cũng đã có sẵn, có thể xử lý như không làm gì. Các trường hợp còn lại chỉ nối lại ranh giới sau khi điều kiện đã được xác nhận. Lính canh thuộc cấu trúc quản lý, không được chuyển như bản ghi.

**Cần thể hiện khi trả lời:**

- Theo dõi đúng hai chiều, count và quyền sở hữu qua cả hai lần chuyển, kể cả nguồn/đích rỗng.
- Tách chi phí xác định độ dài/kiểm điểm chèn khỏi số phép nối, xử lý đúng tự chuyển và trường hợp không làm gì.

**Tránh nhầm:** Ít phép gán con trỏ không chứng minh toàn thao tác O(1). Trường hợp nguồn–đích là cùng một vòng cần hợp đồng riêng, không dùng máy móc cách ghép hai tập nút tách rời.

[Quay lại câu hỏi](04_DanhSachLienKet.md#lt4-21)

<a id="lt4-22"></a>

### LT4-22

**Câu hỏi:** Có K danh sách đã tăng, mỗi danh sách dài s, các tập nút tách rời; K là lũy thừa hai và tổng H=Ks. Mỗi phép trộn tốn theo tổng độ dài hai nguồn trong trường hợp xấu. So cách trộn lần lượt một danh sách mới vào kết quả đang lớn dần với cách ghép từng cặp thành nhiều vòng. Hãy tính tổng công việc và giải thích vì sao mọi phép trộn riêng đều tuyến tính nhưng toàn quá trình có thể khác bậc theo K.

**Ý cần nắm:** Trộn dồn có các kích thước khoảng 2s,3s,…,Ks, tổng Theta(sK²)=Theta(HK) ở cận xấu. Ghép cân bằng có log₂K vòng; ở mỗi vòng, tổng số nút đi qua các phép trộn là H, nên Theta(H log K). Cả hai đều dùng phép trộn tuyến tính, nhưng cách kết hợp quyết định một nút bị đi qua bao nhiêu lần. Các kết luận giả định phép trộn có hợp đồng sở hữu phù hợp và không thêm một chi phí khác như sao chép lại toàn cấu trúc ngoài phần đã tính.

**Cần thể hiện khi trả lời:**

- Cộng kích thước các lần trộn dồn và tổng công việc từng vòng cân bằng.
- Giải thích số lần một nút bị xử lý phụ thuộc cách kết hợp, không chỉ hàm trộn.

**Tránh nhầm:** Không cộng chi phí của một bước tiêu biểu rồi quên số lần cùng dữ liệu tham gia các bước về sau.

[Quay lại câu hỏi](04_DanhSachLienKet.md#lt4-22)

<a id="lt4-23"></a>

### LT4-23

**Câu hỏi:** Một vòng duyệt danh sách trước khi xử lý nút hiện tại đã giữ con trỏ next, rồi gọi một thao tác được phép xóa bất kỳ nút nào trong danh sách. Người viết cho rằng giữ next là đủ tránh mọi lỗi khi tiếp tục. Hãy tạo trường hợp thao tác được gọi làm con trỏ đã giữ mất hiệu lực, rồi nêu một hợp đồng hạn chế hoặc cách tổ chức xử lý giúp lập luận an toàn. Chỉ xét thực hiện tuần tự trong một tiến trình.

**Ý cần nắm:** Nếu tại A đã giữ next=B, nhưng thao tác được gọi xóa B thì con trỏ đã giữ không còn hợp lệ; thao tác còn có thể xóa cả đoạn tiếp theo. Giữ next chỉ giúp khi thay đổi được giới hạn, chẳng hạn được xóa chính nút hiện tại nhưng không xóa các nút chưa duyệt khác. Cách khác là ghi nhận yêu cầu xóa rồi thực hiện sau pha duyệt, hoặc duyệt theo các định danh bền và tra lại theo một hợp đồng rõ. Chụp một mảng con trỏ cũng không tự an toàn nếu các đối tượng có thể bị xóa trước khi dùng các con trỏ đó.

**Cần thể hiện khi trả lời:**

- Dựng ca callback xóa chính nút next đã lưu.
- Nêu hợp đồng hạn chế sửa hoặc trì hoãn xóa có lập luận an toàn.

**Tránh nhầm:** Lỗi này không cần đa luồng; một lời gọi tuần tự có quyền sửa quá rộng cũng phá bất biến của bên đang duyệt.

[Quay lại câu hỏi](04_DanhSachLienKet.md#lt4-23)

<a id="lt4-24"></a>

### LT4-24

**Câu hỏi:** Một cấu trúc cần duyệt qua lại theo con trỏ hiện tại và xóa chính nút đó, kể cả nút cuối; bên gọi chỉ đưa con trỏ tới nút, không đưa nút trước. Mỗi thao tác phải O(1), địa chỉ và nội dung của mọi nút còn sống phải giữ nguyên. Hãy so danh sách đơn có head/tail, danh sách kép và mảng đặc lưu trực tiếp bản ghi trong một tiền tố liên tục (không phải mảng con trỏ, không có lớp định vị phụ) để chọn phương án đáp ứng; nói rõ thông tin nào tạo ra khác biệt.

**Câu hỏi tiếp:** Đổi hợp đồng: không cần bước lùi nữa, khi xóa bên gọi luôn đưa đúng nút trước còn hợp lệ hoặc xác nhận nút cần xóa là head. Khi ấy lựa chọn có thay đổi không? Liên hệ với danh sách đơn cuốn/lịch sử của đề Thư viện mà không tự thay cấu trúc bắt buộc.

**Ý cần nắm:** Danh sách kép có prev/next cho phép bước lùi và nối bỏ nút đã biết trong O(1), kể cả biên nếu quản lý head/tail đúng, không chuyển bản ghi của nút sống. Danh sách đơn không có đường tới nút trước: biết tail không cho biết nút trước tail; xóa tùy ý hoặc bước lùi có thể phải tìm từ head O(n). Mẹo chép dữ liệu nút sau không dùng được ở tail và vi phạm giữ nguyên nội dung/danh tính nút sống. Mảng đặc lưu trực tiếp bản ghi phải di chuyển ít nhất một bản ghi còn sống khi lấp chỗ xóa ở giữa, nên không đồng thời giữ các yêu cầu này. Khi caller cung cấp nút trước hợp lệ và không cần bước lùi, danh sách đơn cập nhật liên kết O(1), giảm một con trỏ mỗi nút; nhưng chi phí tìm/duy trì nút trước thuộc caller vẫn phải tính ở mức toàn thao tác. Đây là so sánh thiết kế giả định, không cấp quyền thay danh sách đơn trong đề.

**Cần thể hiện khi trả lời:**

- So đúng các biểu diễn đã nêu, trong đó mảng lưu trực tiếp bản ghi; xét đủ địa chỉ/nội dung, bước lùi và xóa tail.
- Giải thích vì sao đổi thông tin caller cung cấp có thể đổi lựa chọn, vẫn tính chi phí toàn thao tác.

**Tránh nhầm:** O(1) để nối bỏ nút khác với O(1) để tìm ra mọi thông tin cần nối. Con trỏ nút trước cũ có thể không còn hợp lệ sau cập nhật.

[Quay lại câu hỏi](04_DanhSachLienKet.md#lt4-24)

<a id="lt4-25"></a>

### LT4-25

**Câu hỏi:** n đối tượng tồn tại duy nhất, địa chỉ ổn định, mỗi đối tượng chỉ có một trường next; không được sửa cấu trúc bản ghi hay thứ tự danh sách nguồn. Cần giữ đồng thời hai cách duyệt theo hai khóa khác nhau, hai thứ tự có thể không trùng. Được cấp thêm tối đa 2n ô con trỏ. Hãy chọn cách biểu diễn hai cách duyệt, giải thích vì sao chỉ giữ hai con trỏ đầu trên cùng các next thường không đủ, và phân biệt bản nhìn theo thứ tự với bản sao dữ liệu.

**Câu hỏi tiếp:** Sau khi lập hai cách duyệt, một đối tượng bị xóa hoặc sửa khóa. Những nghĩa vụ nào phát sinh để lần duyệt tiếp không đọc dữ liệu đã giải phóng hoặc dùng thứ tự lỗi thời? Nêu giới hạn của ngân sách nếu muốn đóng băng cả nội dung cũ.

**Ý cần nắm:** Một trường next chỉ xác định một nút kế tiếp cho mỗi đối tượng; hai thứ tự đầy đủ không tương thích có thể đòi cùng một đối tượng trỏ tới hai nút khác nhau. Hai con trỏ đầu chỉ chọn điểm bắt đầu, không tạo được hai quan hệ kế tiếp độc lập trên cùng các trường next. Có thể tạo hai mảng không sở hữu, mỗi mảng n con trỏ, rồi sắp theo khóa tương ứng; đúng 2n ô, nguồn và địa chỉ đối tượng giữ nguyên. Có thể dùng Heap Sort lặp trên các mảng nếu không yêu cầu ổn định để không cần thêm vùng đệm tỷ lệ n. Hai mảng là hai bản nhìn vào cùng đối tượng, không chụp nội dung tại lúc lập. Trước khi giải phóng đối tượng phải loại các tham chiếu liên quan hoặc hủy/đánh dấu bản nhìn không được dùng; khi khóa đổi phải cập nhật thứ tự hoặc xây lại trước truy vấn phụ thuộc thứ tự. Muốn giữ nội dung cũ sau sửa/xóa cần bản sao dữ liệu hoặc một cơ chế giữ phiên bản/vòng đời riêng, chưa được bảo đảm chỉ bằng 2n ô con trỏ.

**Cần thể hiện khi trả lời:**

- Chứng minh giới hạn của một next và chọn hai mảng tham chiếu trong ngân sách.
- Nêu trách nhiệm cập nhật khi xóa/đổi khóa, không gọi con trỏ còn hợp lệ là ảnh chụp dữ liệu cũ.

**Tránh nhầm:** Hai thứ tự độc lập khác với hai bản sao độc lập. Phương án phụ trợ cho bài giả định không tự được đưa vào đề Thư viện.

[Quay lại câu hỏi](04_DanhSachLienKet.md#lt4-25)

## Chương V — Cây, BST và AVL

<a id="lt5-04"></a>

### LT5-04

**Câu hỏi:** Biểu diễn cây nhị phân bằng vị trí mảng: gốc ở 0, con trái 2i+1, con phải 2i+2. Với n nút xếp thành một chuỗi chỉ có con phải, hãy suy ra chỉ số nút cuối và số ô cần để giữ cách đánh số này. So với cây hoàn chỉnh n nút, vì sao câu “mảng chỉ cần n ô và luôn ít bộ nhớ hơn con trỏ” sai? Nếu n=20, khoảng trống đã lớn tới đâu?

**Ý cần nắm:** Ở độ sâu d, chỉ số của chuỗi phải là 2^(d+1)−2; với n nút, chỉ số cuối 2^n−2 và cần 2^n−1 ô nếu cấp liên tục tới đó. Với n=20, cần 1.048.575 ô nhưng chỉ dùng 20 vị trí; cây hoàn chỉnh n nút dùng các vị trí 0 tới n−1. Biểu diễn bằng con trỏ có số nút theo n nhưng tốn các trường liên kết/cấp phát. Lựa chọn phải dựa hình dạng và mô hình lưu trữ, không chỉ tên “mảng” hay “cây”.

**Cần thể hiện khi trả lời:**

- Suy ra chỉ số cuối 2^n−2 và số ô cho chuỗi phải.
- So hình dạng hoàn chỉnh với lệch, tính ví dụ n=20 và chi phí biểu diễn.

**Tránh nhầm:** Có thể dùng cách mã hóa khác để tránh lỗ, nhưng khi đó không còn được giữ nguyên toàn bộ giả thiết về vị trí và công thức truy cập này.

[Quay lại câu hỏi](05_Cay_BST_AVL.md#lt5-04)

<a id="lt5-06"></a>

### LT5-06

**Câu hỏi:** So sánh hai cây có cùng số nút gần n: một cây nhị phân hoàn hảo và một cây là chuỗi lệch. Với DFS đệ quy thông thường và BFS dùng Queue, mỗi nút làm O(1) việc, hãy đánh giá thời gian và đỉnh bộ nhớ phụ trên từng cây. Một bạn muốn đổi DFS sang BFS chỉ vì sợ stack sâu: điều gì được giải quyết và rủi ro bộ nhớ nào có thể xuất hiện ở hình dạng khác?

**Ý cần nắm:** Cả hai cách thăm toàn cây đều Theta(n) thời gian. Trên cây hoàn hảo, DFS đệ quy sâu Theta(log n), trong khi Queue BFS có thể chứa Theta(n) nút ở mức rộng. Trên chuỗi lệch, DFS đệ quy sâu Theta(n), còn Queue BFS chỉ cần số nút hằng số. Đổi sang BFS tránh stack lời gọi nhưng có thể cần nhiều bộ nhớ hàng đợi ở cây rộng; thứ tự xử lý cũng đổi, không dùng thay thế nếu hợp đồng yêu cầu một thứ tự DFS cụ thể.

**Cần thể hiện khi trả lời:**

- So đủ thời gian và bộ nhớ DFS/BFS trên cả cây rộng lẫn cây sâu.
- Gắn lựa chọn với hình dạng và thứ tự duyệt yêu cầu.

**Tránh nhầm:** Không coi BFS hoặc DFS luôn tiết kiệm bộ nhớ hơn; cận phụ thuộc hình dạng và cách cài đã nêu.

[Quay lại câu hỏi](05_Cay_BST_AVL.md#lt5-06)

<a id="lt5-07"></a>

### LT5-07

**Câu hỏi:** Bộ kiểm BST chỉ so mỗi nút với hai con trực tiếp; tất cả phép so đều đúng. Hãy tạo cây ba nút khiến bộ kiểm vẫn chấp nhận sai. Sau đó đổi chính sách thành khóa trùng chỉ được nằm bên phải: mọi khóa cây trái < gốc, mọi khóa cây phải ≥ gốc. Kiểm dãy LNR không giảm có đủ xác nhận chính sách mới không? Hãy cho phản ví dụ hoặc chứng minh.

**Ý cần nắm:** Gốc 20, con trái 10, và con phải của 10 là 25: từng cạnh phù hợp so sánh cục bộ nhưng 25 vi phạm miền nhỏ hơn 20 của cả cây trái. Với chính sách trùng chỉ bên phải, gốc 2 có con trái 2 cho LNR là 2,2 không giảm nhưng vẫn sai. Kiểm toàn cục cần truyền hoặc suy ra các cận khóa, đồng thời phân biệt cận chặt và không chặt đúng phía. LNR tăng nghiêm ngặt có thể kiểm chính sách không trùng, nhưng không tự kiểm được mọi chính sách phân bố khóa trùng.

**Cần thể hiện khi trả lời:**

- Dựng phản ví dụ quan hệ tổ tiên và phản ví dụ khóa trùng sai phía.
- Nêu cận chặt/không chặt phù hợp toàn cây.

**Tránh nhầm:** Cùng thứ tự giá trị khi duyệt chưa chắc cùng thỏa quy tắc vị trí của các khóa bằng nhau.

[Quay lại câu hỏi](05_Cay_BST_AVL.md#lt5-07)

<a id="lt5-08"></a>

### LT5-08

**Câu hỏi:** Cây BST thường đang có hình dạng tốt. Nhóm lưu các bản ghi theo LNR, rồi nạp lại bằng cách chèn lần lượt theo đúng thứ tự file. Khóa không trùng và file có n bản ghi tăng dần. Vì sao dữ liệu vẫn đủ, thứ tự LNR vẫn đúng nhưng hiệu năng có thể hỏng? Tính tổng chi phí dựng lại bằng cách đó và nêu một hướng dựng khác giữ BST mà không tự bổ sung cơ chế AVL vào cấu trúc.

**Ý cần nắm:** Chèn khóa tăng liên tiếp vào BST thường tạo chuỗi phải. Cây vẫn chứa đủ khóa và LNR vẫn tăng, nhưng chiều cao lên Theta(n); tổng tìm vị trí chèn là 0+1+…+(n−1), nên Theta(n²). Nếu đã có toàn bộ dữ liệu theo khóa trong một biểu diễn truy cập phù hợp, có thể dựng cây cân bằng ban đầu bằng cách chọn khóa giữa làm gốc từng miền, tạo mỗi nút một lần; phần dựng có thể O(n) và bộ nhớ phụ tùy biểu diễn/đệ quy. Đây là chọn hình dạng ban đầu, không bảo đảm cân bằng sau mọi cập nhật như AVL.

**Cần thể hiện khi trả lời:**

- Giải thích nạp bằng chèn tăng tạo chuỗi và tổng Θ(n²).
- Nêu hướng dựng BST có hình dạng tốt mà không tự đổi sang AVL.

**Tránh nhầm:** Tính đúng về tập dữ liệu và thứ tự không chứng minh hình dạng hoặc hiệu năng được giữ qua lưu–nạp.

[Quay lại câu hỏi](05_Cay_BST_AVL.md#lt5-08)

<a id="lt5-10"></a>

### LT5-10

**Câu hỏi:** Nút mã 40 thuộc An, sở hữu lịch sử A; nút kế tiếp mã 45 thuộc Bình, sở hữu lịch sử B. Khi xóa An bằng cách dùng nút kế tiếp, nhóm chỉ chép maThe=45 vào nút An rồi xóa nút Bình cùng lịch sử B. Cây còn thỏa thứ tự mã và tìm mã 40 trả không có. Hãy chỉ ra dữ liệu nào sai, trạng thái danh tính–lịch sử đúng phải là gì và vì sao một kiểm tra BST đơn thuần không bắt được lỗi này.

**Ý cần nắm:** Nút còn lại mang mã 45 nhưng vẫn có tên An và lịch sử A, trong khi Bình và lịch sử B bị xóa; đúng ra yêu cầu xóa An phải giữ Bình dưới mã 45 với đúng lịch sử B, nếu chính sách cho phép xóa An. Nếu lịch sử A được phép hủy thì chỉ hủy đúng phần đó; nếu chính sách cấm xóa người có lịch sử thì phải từ chối trước. Phép thay thế cần bảo toàn cả bản ghi và quyền sở hữu, bằng chuyển nút hoặc chuyển dữ liệu theo hợp đồng phù hợp. Kiểm BST chỉ thấy khóa và vị trí nên không kiểm quan hệ người–lịch sử.

**Cần thể hiện khi trả lời:**

- Theo dõi danh tính, mã và lịch sử khi chép thiếu bản ghi.
- Giải thích vì sao kiểm thứ tự BST và không còn mã 40 vẫn bỏ sót sai dữ liệu.

**Tránh nhầm:** Xóa đúng khóa chưa đủ chứng minh xóa đúng người và giữ đúng dữ liệu của người còn lại.

[Quay lại câu hỏi](05_Cay_BST_AVL.md#lt5-10)

<a id="lt5-11"></a>

### LT5-11

**Câu hỏi:** Một BST theo mã thẻ được dùng để tìm tên An. Người viết so An với tên ở nút hiện tại rồi chỉ đi trái hoặc phải như tìm theo mã; vài bộ dữ liệu mẫu đều đúng. Hãy tạo cây ba nút làm cách đó bỏ sót An. Nếu truy vấn đổi thành liệt kê các mã trong [a,b], khi nào được loại cây con, và vì sao kết luận “mọi phép lọc đều phải duyệt toàn cây” cũng quá mạnh?

**Ý cần nắm:** Ví dụ gốc mã 20 tên Bình, trái mã 10 tên Dũng, phải mã 30 tên An: so theo tên sẽ đi trái để tìm An và bỏ qua kết quả ở phải. Tên không có quan hệ thứ tự được BST bảo đảm. Với khoảng mã, nếu khóa hiện tại<a thì toàn cây trái cũng ngoài khoảng; nếu khóa hiện tại>b thì toàn cây phải cũng ngoài khoảng. Có thể chỉ đi vào các vùng khóa còn giao với [a,b], đạt O(h+k) cho cách duyệt khoảng chuẩn với k kết quả và khóa so hằng số. Việc loại nhánh hợp lệ phụ thuộc thuộc tính lọc có gắn với bất biến khóa hay không.

**Cần thể hiện khi trả lời:**

- Dựng cây bỏ sót tên khi cắt nhánh bằng thuộc tính khác khóa.
- Phát biểu điều kiện loại cây con hợp lệ với khoảng mã.

**Tránh nhầm:** Không suy khả năng loại nhánh từ một hình dạng mẫu vô tình sắp tên giống mã.

[Quay lại câu hỏi](05_Cay_BST_AVL.md#lt5-11)

<a id="lt5-14"></a>

### LT5-14

**Câu hỏi:** Cây cần sửa cân bằng có gốc 30, trái 10, phải 40; nút 10 có trái 5, phải 20; nút 20 có trái 15, phải 25. Các cây con của 30 đều là AVL, h(rỗng)=0. Hãy xác định cách phục hồi AVL tại 30, vẽ cây cuối và chỉ rõ số phận của hai cây con 15,25. Bảo vệ kết quả bằng cả thứ tự LNR lẫn chiều cao, đồng thời giải thích vì sao chỉ kiểm hai giá trị ở gốc phép quay chưa đủ.

**Ý cần nắm:** Nút 30 lệch trái, con trái 10 lệch phải, nên cần xử lý LR. Cây cuối có gốc 20; trái 10 với hai con 5,15; phải 30 với hai con 25,40. Chiều cao các lá là 1, hai nút 10 và 30 là 2, gốc 20 là 3; hệ số cân bằng của ba nút trong đều 0. LNR vẫn 5,10,15,20,25,30,40. Phải giữ 15 ở phía phải 10 và 25 ở phía trái 30, cùng nối đúng gốc cây con mới với bên ngoài nếu có; kiểm riêng khóa gốc không phát hiện mất hoặc gắn sai cây con giữa.

**Cần thể hiện khi trả lời:**

- Xác định và vẽ đúng phép quay kép, giữ cây con 15,25.
- Kiểm cả LNR lẫn chiều cao trên cây kết quả.

**Tránh nhầm:** Đáp án phải thể hiện các liên kết và chiều cao sau phép quay, không chỉ gọi đúng tên LR.

[Quay lại câu hỏi](05_Cay_BST_AVL.md#lt5-14)

<a id="lt5-15"></a>

### LT5-15

**Câu hỏi:** AVL ban đầu có gốc 4; trái 2 với hai con 1,3; phải 6 là lá. Xóa 6, rồi xét cân bằng tại 4 với h(rỗng)=0. Một bạn chỉ biết quy tắc chọn quay từ hướng chèn và lúng túng khi hệ số cân bằng của nút 2 bằng 0. Hãy đưa cây sau cân bằng, so chiều cao trước xóa với sau cân bằng và giải thích ý nghĩa của việc chiều cao có hoặc không giảm đối với tổ tiên của cây con này.

**Ý cần nắm:** Sau xóa, nút 4 lệch trái hai mức, nút 2 có hệ số 0. Quay phải đơn tại 4 cho gốc 2, trái 1, phải 4 với con trái 3. Chiều cao trước xóa là 3 và sau cân bằng vẫn 3; các độ lệch vẫn trong giới hạn AVL. Nếu cây này nằm dưới một tổ tiên đang hợp lệ, tổ tiên không nhận thay đổi chiều cao từ cây con này nên không cần lan giảm chiều cao thêm theo nhánh đó. Các trường hợp xóa khác có thể làm chiều cao giảm và buộc tiếp tục kiểm lên trên.

**Cần thể hiện khi trả lời:**

- Xử lý đúng con lệch bằng 0 trong xóa AVL.
- So chiều cao trước/sau và suy ra ảnh hưởng tới tổ tiên.

**Tránh nhầm:** Hệ số con bằng 0 là trường hợp hợp lệ khi xóa; không được chọn phép quay chỉ từ khóa đã xóa hoặc quy tắc chèn thuộc lòng.

[Quay lại câu hỏi](05_Cay_BST_AVL.md#lt5-15)

<a id="lt5-17"></a>

### LT5-17

**Câu hỏi:** Với cây nhị phân có các nhãn phân biệt, hai dãy NLR=A,B,D,E,C và LNR=D,B,E,A,C xác định cây nào? Hãy giải thích vì sao cách tách theo gốc cho phép xác định duy nhất. Nếu chỉ có NLR=A,B và LRN=B,A thì có duy nhất không? Nếu nhãn được phép trùng, điều kiện nào của lập luận dùng NLR và LNR bị mất?

**Ý cần nắm:** Gốc là A; trong LNR, phần D,B,E thuộc trái và C thuộc phải. Cây trái có gốc B với trái D và phải E; cây phải chỉ có C. Nhãn phân biệt giúp xác định đúng một vị trí của gốc trong LNR, từ đó xác định kích thước và các đoạn con tương ứng để lặp lại lập luận. Với NLR=A,B và LRN=B,A, B có thể là con trái hoặc con phải của A nên không duy nhất. Khi nhãn trùng, không tự xác định được lần xuất hiện nào trong LNR là gốc, và có thể có nhiều cây phù hợp.

**Cần thể hiện khi trả lời:**

- Dựng cây từ NLR/LNR và giải thích tách duy nhất khi nhãn phân biệt.
- Dựng trường hợp không duy nhất khi thiếu thông tin hoặc trùng nhãn.

**Tránh nhầm:** Không dùng một giá trị trùng như danh tính duy nhất của nút khi khôi phục cấu trúc.

[Quay lại câu hỏi](05_Cay_BST_AVL.md#lt5-17)

<a id="lt5-18"></a>

### LT5-18

**Câu hỏi:** Cần tìm độc giả có mã đứng thứ k theo thứ tự tăng trong BST, không có sẵn số nút mỗi cây con. Một bạn nói “cây có chiều cao logarit nên tìm hạng k cũng O(log R)”. Hãy chỉ ra thông tin còn thiếu. Nếu chỉ để so sánh thiết kế, cho phép lưu kích thước cây con thì có thể chọn nhánh thế nào, và những thao tác nào phải duy trì thông tin đó?

**Ý cần nắm:** Chiều cao thấp không cho biết cây trái chứa bao nhiêu người; dùng LNR dừng ở hạng k vẫn có thể xét Theta(R) nút khi k lớn. Nếu mỗi nút lưu chính xác số nút cây con, so k với số nút trái để đi trái, nhận gốc hoặc đổi hạng rồi đi phải, nên đi tối đa O(h) mức. Thêm, xóa và các phép đổi liên kết như quay đều phải cập nhật số lượng của các cây con liên quan; số liệu chiều cao không thay thế được số lượng nút. Đây là thông tin hỗ trợ mới trong phương án so sánh, không tự được đưa vào bản nộp theo đề.

**Cần thể hiện khi trả lời:**

- Chỉ ra thiếu kích thước cây con để định hướng hạng k.
- Nêu cách chọn nhánh và nghĩa vụ duy trì metadata qua cập nhật/quay.

**Tránh nhầm:** Cân bằng theo chiều cao không tự cung cấp thống kê thứ hạng.

[Quay lại câu hỏi](05_Cay_BST_AVL.md#lt5-18)

<a id="lt5-19"></a>

### LT5-19

**Câu hỏi:** Muốn liệt kê toàn bộ mã tăng dần, một cách tìm nút nhỏ nhất rồi liên tục tìm nút kế tiếp bằng cách khởi động lại từ gốc; một cách khác dùng một lần duyệt LNR với trạng thái chờ. Hãy phân tích tổng chi phí có thể đạt của cách thứ nhất trên cây lệch và cây cân bằng, rồi giải thích vì sao duyệt một lần có thể tuyến tính. Khi một nút không có cây con phải, vì sao nút kế tiếp không đơn giản là nút cha bất kỳ?

**Ý cần nắm:** Mỗi lần tìm kế tiếp từ gốc có thể tốn O(h), nên tổng O(Rh); trên chuỗi phải, đi lại tới các khóa kế tiếp cho tổng Theta(R²), trên cây cân bằng có thể là Theta(R log R). Một lần LNR xử lý mỗi nút và mỗi liên kết theo số lần hằng số, nên Theta(R), với bộ nhớ chờ tùy cách cài. Nếu không có cây phải, kế tiếp là tổ tiên gần nhất mà nút hiện tại nằm trong cây con trái của tổ tiên đó; các tổ tiên đạt tới từ phía con phải đều có khóa nhỏ hơn nút hiện tại. Có thể không có kế tiếp ở nút lớn nhất.

**Cần thể hiện khi trả lời:**

- Cộng công việc tìm kế tiếp từ gốc trên hình dạng xấu và cân bằng.
- Bảo vệ duyệt LNR một lần tuyến tính và quy tắc tổ tiên kế tiếp.

**Tránh nhầm:** Gọi nhiều lần một hàm đúng và nhanh riêng lẻ vẫn có thể lặp lại đường đi nhiều lần.

[Quay lại câu hỏi](05_Cay_BST_AVL.md#lt5-19)

<a id="lt5-20"></a>

### LT5-20

**Câu hỏi:** BST có gốc 20, trái 10, phải 30 với trái 25 và phải 40. Trước khi xóa các mã 20 và 25, nhóm chụp hai con trỏ tới hai nút đó. Hàm xóa nút hai con dùng cách chép toàn bộ bản ghi kế tiếp vào nút bị xóa rồi giải phóng nút kế tiếp. Sau khi xóa 20, có còn được dùng con trỏ đã chụp tới 25 để xóa lần tiếp không? So với chụp các mã cần xóa và tìm lại từng mã, hãy phân biệt hai hợp đồng.

**Ý cần nắm:** Nút 25 là kế tiếp của 20; theo cách xóa đã nêu, nó được giải phóng và bản ghi 25 chuyển vào địa chỉ gốc cũ. Con trỏ đã chụp tới nút 25 vì vậy không còn hợp lệ, dù mã 25 vẫn tồn tại. Chụp mã 20,25 rồi tra lại từng mã theo trạng thái hiện tại có thể thực hiện ý định xóa hai bản ghi đó nếu mã là định danh ổn định và không có thao tác tái dùng mã xen vào. Chụp con trỏ là cam kết theo đối tượng nút cụ thể; chụp khóa là cam kết theo bản ghi được định danh, nên không thể hoán đổi hai cách mà không xét thuật toán xóa.

**Cần thể hiện khi trả lời:**

- Theo dõi địa chỉ 25 bị giải phóng sau xóa 20 bằng chép bản ghi.
- Phân biệt chụp con trỏ với chụp mã rồi tìm lại.

**Tránh nhầm:** Một nút bị giải phóng không có nghĩa bản ghi mang khóa của nó đã biến mất khỏi cây.

[Quay lại câu hỏi](05_Cay_BST_AVL.md#lt5-20)

<a id="lt5-21"></a>

### LT5-21

**Câu hỏi:** Một cây là chuỗi trái bốn nút. Trường height của mọi nút đều bị ghi thành 1. Bộ kiểm AVL chỉ lấy height lưu trong hai nút con để kiểm độ chênh không quá một, không kiểm chính height của nút hiện tại. Vì sao tất cả các kiểm tra cục bộ ấy có thể qua dù cây không là AVL? Hãy nêu cách kiểm độc lập vừa xác nhận hình dạng vừa xác nhận metadata, và so với việc tính lại chiều cao toàn cây con ở từng nút.

**Ý cần nắm:** Mỗi nút có con trái được ghi height=1, con phải rỗng height=0, nên độ chênh đọc từ metadata chỉ là 1; kiểm tra không nhìn thấy chiều cao thực của chuỗi. Có thể duyệt hậu tự, lấy chiều cao thật trả về từ hai con, kiểm độ lệch và so height lưu với chiều cao tính được. Một lần như vậy xét mỗi nút số lần hằng số, O(R), với stack O(h). Nếu ở mỗi nút lại duyệt toàn cây con để tính chiều cao từ đầu, trên chuỗi có tổng R+(R−1)+… và tốn Theta(R²).

**Cần thể hiện khi trả lời:**

- Chỉ ra metadata height sai khiến kiểm cục bộ chấp nhận chuỗi lệch.
- Nêu kiểm độc lập từ dưới lên và so chi phí tính lặp chiều cao.

**Tránh nhầm:** Metadata đang cần kiểm không được dùng như bằng chứng độc lập cho chính tính đúng của nó.

[Quay lại câu hỏi](05_Cay_BST_AVL.md#lt5-21)

<a id="lt5-22"></a>

### LT5-22

**Câu hỏi:** Một BST cho khóa trùng nhưng bắt buộc mọi khóa bằng gốc chỉ nằm bên phải. Ba nút cùng khóa 2 được chèn thành chuỗi phải; nhóm muốn cân bằng bằng quay trái như AVL thông thường. Hãy vẽ cây sau quay và chỉ ra xung đột giữa bất biến trùng một phía và cân bằng. Với rất nhiều khóa đều bằng nhau, hai yêu cầu này có thể cùng giữ nếu vẫn lưu mỗi phần tử thành một nút riêng với đúng phép so khóa gốc không?

**Ý cần nắm:** Sau quay, nút giữa trở thành gốc 2 với một nút 2 bên trái, vi phạm điều kiện cây trái phải nhỏ hơn gốc. Nếu mọi khóa đều bằng nhau và mỗi phần tử là một nút theo chính phép so này, không nút nào được ở bên trái; cấu trúc buộc thành chuỗi phải nên không thể đồng thời là AVL khi đủ dài. Có thể đổi biểu diễn thành một nút cho mỗi khóa kèm số lần/danh sách giá trị, hoặc dùng khóa ghép có thành phần phân biệt; cả hai đều là thay đổi hợp đồng cần đánh giá. Mã thẻ trong đề vốn phải duy nhất, nên đây là tình huống lý thuyết về chính sách trùng.

**Cần thể hiện khi trả lời:**

- Vẽ kết quả quay ba khóa bằng nhau và chỉ ra khóa bằng sang trái.
- Nêu xung đột cấu trúc khi vẫn giữ mỗi khóa thành một nút với luật trùng một phía.

**Tránh nhầm:** Không cho rằng phép quay tự bảo toàn mọi chính sách khóa trùng chỉ vì nó bảo toàn thứ tự LNR không giảm.

[Quay lại câu hỏi](05_Cay_BST_AVL.md#lt5-22)

<a id="lt5-24"></a>

### LT5-24

**Câu hỏi:** Dùng h(rỗng)=0, h(lá)=1. Gọi N(h) là số nút ít nhất của một AVL cao h. Hãy tự suy ra quan hệ giữa N(h), N(h−1), N(h−2), tính đủ để trả lời một AVL có 20 nút có thể cao 7 không, rồi giải thích vì sao điều kiện AVL dẫn tới chiều cao O(log R). Không được chỉ viện dẫn kết luận đã học thuộc.

**Ý cần nắm:** Muốn cao h, một con phải cao h−1; để ít nút nhất mà vẫn cân bằng, con kia thấp nhất được là h−2. Vì thế N(h)=1+N(h−1)+N(h−2), với N(0)=0,N(1)=1. Dãy tiếp là 2,4,7,12,20,33 ở h=2…7; 20 nút không đủ cao 7, còn mức 6 là có thể. Vì N(h) tăng ít nhất theo một hàm mũ theo h, chẳng hạn từ quan hệ hai mức N(h)≥1+2N(h−2), chiều cao chỉ tăng theo logarit của số nút. Điều kiện này không bắt cây hoàn hảo hay hai phía có cùng số nút.

**Cần thể hiện khi trả lời:**

- Suy ra truy hồi số nút tối thiểu và kiểm h=7 với 20 nút.
- Giải thích tăng trưởng dẫn tới chiều cao logarit, không chỉ đọc thuộc cận.

**Tránh nhầm:** Phải thống nhất quy ước chiều cao trước khi dùng các số cụ thể; cận logarit cần một lập luận tăng số nút, không chỉ tên AVL.

[Quay lại câu hỏi](05_Cay_BST_AVL.md#lt5-24)

<a id="lt5-25"></a>

### LT5-25

**Câu hỏi:** Một BST thường có R khóa phân biệt, ban đầu cao O(log R). Cần xóa một lô m mã phân biệt đang tồn tại, 0≤m≤R, đã cho theo thứ tự tăng nghiêm ngặt; không có chèn xen vào. So cách tìm rồi xóa từng mã với cách duyệt cây một lượt, bỏ các mã thuộc lô và dựng lại BST từ những nút còn lại. Hãy phân tích chi phí, chọn theo m và chỉ ra dữ liệu tạm của phương án dựng lại.

**Câu hỏi tiếp:** Bên ngoài có thể giữ con trỏ tới các nút sẽ sống sau lô xóa. Muốn giữ địa chỉ các nút ấy, phương án dựng lại phải làm gì? Việc giữ địa chỉ có đồng nghĩa một phép duyệt đang dở vẫn tiếp tục được như cũ không?

**Ý cần nắm:** Với xóa BST thông thường bằng nút kế tiếp/trước và không có chèn, chiều cao không tăng, nên tìm/xóa m mã có cận O(m log R) từ chiều cao ban đầu; đây không phải bảo đảm tự cân bằng cho các cập nhật tương lai. Vì m mã xóa phân biệt và đều tồn tại, có đúng R−m nút sống sau lô. Phương án lô: LNR cho dãy mã tăng, đồng thời tiến qua danh sách m mã cần xóa; thu các nút sống thành mảng con trỏ theo mã, rồi chọn giữa để nối lại một BST có hình dạng cân bằng. Thời gian O(R+m)=O(R), gồm giải phóng m nút; vùng tạm O(R−m+log(R+1)) con trỏ/khung với duyệt trên cây ban đầu, ngoài danh sách mã đã cho. m nhỏ thường nghiêng về xóa riêng; m tỷ lệ R cho thấy lợi thế cận trên của xử lý lô, nhưng quyết định thực phải xét bộ nhớ và hằng số. Để giữ địa chỉ nút sống, cần nối lại chính các nút ấy, không cấp bản sao rồi hủy toàn bộ nút cũ; phải lưu trạng thái duyệt cần thiết trước khi hủy nút. Thay các liên kết làm trạng thái iterator/Stack duyệt cũ có thể lỗi thời dù địa chỉ còn hợp lệ. Ngoài ra, cách xóa riêng bằng chép bản ghi kế tiếp có thể hủy địa chỉ vốn thuộc một mã sống; nếu hợp đồng đòi ổn định địa chỉ thì cách xóa đó cũng phải xét lại.

**Cần thể hiện khi trả lời:**

- Dùng giả thiết m mã phân biệt để đếm R−m nút sống; so O(m log R) với O(R) và nêu bộ nhớ tạm.
- Phân biệt giữ khóa/bản ghi, giữ địa chỉ và giữ trạng thái duyệt; xét cả hai phương án theo hợp đồng con trỏ.

**Tránh nhầm:** Dựng lại một BST có hình dạng cân bằng không tự biến cấu trúc thành AVL. Chặn bộ nhớ phải tính cả stack, kể cả khi xóa hết nên mảng nút sống rỗng.

[Quay lại câu hỏi](05_Cay_BST_AVL.md#lt5-25)

<a id="lt5-26"></a>

### LT5-26

**Câu hỏi:** Xét lựa chọn cấu trúc ngoài phạm vi thay đổi bản nộp: mảng con trỏ đã tăng theo mã, BST thường và AVL. Chế độ A có dữ liệu gần như cố định, nhiều truy vấn mã chính xác và liệt kê khoảng mã, cập nhật được gom theo lô. Chế độ B nhận chèn/xóa trực tuyến với thứ tự khóa bất kỳ, có thể tăng dần, và cần chặn xấu nhất cho từng thao tác theo khóa. Hãy chọn có điều kiện cho từng chế độ, giải thích vì sao cùng lời quảng cáo “tìm O(log R)” chưa đủ quyết định.

**Câu hỏi tiếp:** Mỗi đối tượng được cấp riêng và cần giữ địa chỉ khi còn sống. Mảng con trỏ có bị loại chỉ vì phải dịch ô khi chèn không? Còn điều gì cần cân nhắc nếu chuyển lựa chọn này sang đề Thư viện?

**Ý cần nắm:** Ở A, mảng con trỏ tăng là ứng viên tốt: tìm nhị phân O(log R), liệt kê k mã trong khoảng O(log R+k), duyệt liên tiếp thuận tiện; chèn/xóa riêng có thể O(R) do dịch nhưng cập nhật lô có thể gom xử lý. Không khẳng định luôn nhanh nhất nếu chưa có tải và phép đo. BST thường tìm O(h), không có bảo đảm logarit trước chuỗi cập nhật bất kỳ; chèn các khóa tăng có thể tạo chuỗi. AVL giữ h=O(log R), đáp ứng chặn O(log R) cho tìm/chèn/xóa theo khóa ở B dưới mô hình mỗi bước/so khóa O(1), đổi lại phải giữ metadata và cân bằng. Liệt kê khoảng trên cây có thể O(h+k), nên AVL cũng đạt O(log R+k). Mảng con trỏ chỉ chuyển các ô địa chỉ, không buộc di chuyển đối tượng cấp riêng; vì vậy địa chỉ đối tượng có thể ổn định dù chỉ số đổi. Cần xét bộ nhớ, cách xóa/ownership, tần suất cập nhật và giới hạn độ trễ. Đề Thư viện bắt buộc BST độc giả và mảng đầu sách theo tên; so sánh lý thuyết không cho phép đổi khóa hay thay cấu trúc đó.

**Cần thể hiện khi trả lời:**

- Gắn lựa chọn với chế độ tải và cận xấu, có chi phí truy vấn khoảng/cập nhật.
- Phân biệt độ ổn định địa chỉ với vị trí trong mảng và giữ đúng ràng buộc đề.

**Tránh nhầm:** Cân bằng hình dạng ban đầu khác với duy trì cân bằng qua mọi cập nhật; địa chỉ ô con trỏ khác địa chỉ đối tượng.

[Quay lại câu hỏi](05_Cay_BST_AVL.md#lt5-26)

<a id="lt5-27"></a>

### LT5-27

**Câu hỏi:** Hai BST có khóa phân biệt trong từng cây nhưng hình dạng có thể khác nhau. Cần kiểm chúng chứa cùng các bản ghi theo mã và nội dung, không cần giống hình dạng. Không được sửa cây hoặc tạo mảng chứa toàn bộ bản ghi; được dùng O(h_1+h_2) bộ nhớ phụ theo hai chiều cao. Hãy đề xuất cách so sánh, điều kiện kết luận khác nhau và phân tích chi phí.

**Câu hỏi tiếp:** Vì sao so đệ quy các nút ở cùng vị trí có thể từ chối sai? Nếu hai dãy mã giống hệt nhưng dữ liệu lịch sử của một mã khác nhau, phép so phải làm thêm gì và cận thời gian cần diễn đạt thế nào?

**Ý cần nắm:** Dùng hai bộ duyệt LNR từng bước, mỗi bộ giữ Stack các nút đang chờ. Mỗi lần lấy bản ghi kế tiếp từ cả hai, so mã và nội dung theo hợp đồng; khác một bản ghi hoặc một bên hết trước thì kết luận khác, cùng hết sau mọi cặp bằng nhau thì bằng. Do khóa phân biệt, LNR đưa về cùng một thứ tự chuẩn theo mã, không phụ thuộc hình dạng. Mỗi nút được đưa vào/lấy khỏi Stack một lần, cận thời gian O(R_1+R_2+P), với P là tổng chi phí so nội dung thực sự đã xét; bộ nhớ O(h_1+h_2) cho hai Stack, cộng bộ nhớ mà phép so nội dung cần dùng nếu có. Nếu nội dung so được O(1), toàn bộ cận là O(R_1+R_2). Ví dụ một cây gốc 2 có con 1,3 và một cây chuỗi phải 1→2→3 chứa cùng mã nhưng so theo vị trí gốc sẽ thấy khác. Cùng mã chưa bảo đảm cùng người/lịch sử; phải so trường bắt buộc và dữ liệu liên quan theo định nghĩa bằng nhau, không chỉ so địa chỉ con trỏ lịch sử.

**Cần thể hiện khi trả lời:**

- Dùng hai luồng LNR đồng bộ và xử lý lệch độ dài, không sao chép cả cây.
- Tách bằng nhau về dữ liệu khỏi hình dạng, tính chi phí nội dung và chiều cao thực.

**Tránh nhầm:** Đây là bài so hai cây đã biết là BST; nếu tính BST chưa được xác nhận thì phải kiểm thêm. h_1,h_2 không tự là logarit với BST thường.

[Quay lại câu hỏi](05_Cay_BST_AVL.md#lt5-27)

## Chương VI — Sắp xếp và tìm kiếm

<a id="lt6-01"></a>

### LT6-01

**Câu hỏi:** Bốn bản ghi độc giả theo thứ tự ban đầu: (mã 40,họ Trần,tên An), (10,Lê,Bình), (30,Lê,An), (20,Lê,An). Cần tăng theo tên rồi họ, và giữ thứ tự ban đầu giữa các bản ghi bằng cả tên lẫn họ. So hai cách: sắp ổn định theo họ rồi ổn định theo tên; hoặc sắp theo tên–họ–mã bằng một thuật toán bất kỳ. Giả sử Lê đứng trước Trần, An trước Bình. Hãy tính hai thứ tự mã và giải thích vì sao kết quả nhìn “có thứ tự hơn” chưa chắc đúng hợp đồng.

**Ý cần nắm:** Hai lần sắp ổn định cho thứ tự 30,20,40,10: cặp Lê An giữ 30 trước 20 như ban đầu. So theo tên–họ–mã cho 20,30,40,10 và vi phạm yêu cầu giữ thứ tự ban đầu giữa bản ghi bằng tên,họ. Tính ổn định được xét theo khóa mà hợp đồng định nghĩa là bằng nhau; tự thêm mã đã đổi quan hệ tương đương và yêu cầu nghiệp vụ. Nếu hợp đồng đổi sang cần mã tăng khi hòa thì cách thứ hai mới phù hợp.

**Cần thể hiện khi trả lời:**

- Tính đúng hai thứ tự mã và phân biệt thứ tự phụ với ổn định.
- Giải thích thứ tự các lượt sắp ổn định theo độ ưu tiên trường.

**Tránh nhầm:** Một khóa phụ không được tự thêm chỉ vì làm kết quả xác định hơn.

[Quay lại câu hỏi](06_SapXep_TimKiem.md#lt6-01)

<a id="lt6-03"></a>

### LT6-03

**Câu hỏi:** Dãy 2,3,…,n,1 chỉ có một phần tử lệch vị trí. So Insertion Sort chèn vào tiền tố với Bubble Sort quét từ trái sang phải, đưa phần tử lớn về cuối; Bubble có cờ dừng và thu ngắn đuôi đã cố định. Hãy đếm theo bậc số dịch/đổi chỗ và số so sánh, giải thích vì sao nhận xét “gần tăng nên cả hai tuyến tính” sai. Nếu đổi thành n,1,2,…,n−1, hành vi Bubble thay đổi ra sao?

**Ý cần nắm:** Insertion thực hiện khoảng n−1 so sánh ngắn ở các tiền tố đã tăng và dịch n−1 phần tử ở bước cuối, nên tổng Theta(n). Bubble trái→phải chỉ đẩy số 1 về trái một vị trí mỗi lượt, cần Theta(n) lượt và Theta(n²) so sánh dù chỉ n−1 đổi chỗ. Với n ở đầu, một lượt đẩy n tới cuối, lượt tiếp kiểm phần còn lại không đổi nên dừng: Theta(n) so sánh. Hướng di chuyển của phần tử lệch quan trọng, không chỉ số phần tử lệch hoặc số nghịch thế.

**Cần thể hiện khi trả lời:**

- Đếm riêng so sánh và dịch/đổi của Insertion và Bubble theo hướng quét đã nêu.
- Xét cả phần tử nhỏ ở cuối lẫn phần tử lớn ở đầu.

**Tránh nhầm:** Tính thích nghi phải gắn với đúng phiên bản thuật toán và dạng lệch, không chỉ nhãn “gần có thứ tự”.

[Quay lại câu hỏi](06_SapXep_TimKiem.md#lt6-03)

<a id="lt6-05"></a>

### LT6-05

**Câu hỏi:** Selection Sort thông thường tìm phần tử nhỏ nhất ở phần chưa sắp rồi đổi chỗ xa. Với 2a,2b,1, a và b chỉ đánh dấu thứ tự của hai khóa bằng nhau, hãy chứng minh có thể mất ổn định. Nếu thay đổi chỗ bằng cách rút phần tử nhỏ nhất đầu tiên rồi dịch đoạn trước nó để chèn vào đầu vùng chưa sắp, điều gì được cải thiện và chi phí di chuyển xấu nhất thay đổi thế nào? Có còn dùng lý do “Selection ít di chuyển” để chọn biến thể này không?

**Ý cần nắm:** Đổi 1 với 2a cho 1,2b,2a nên mất thứ tự giữa hai khóa 2. Rút phần tử nhỏ nhất đầu tiên rồi dịch đoạn trước nó giữ thứ tự các phần tử còn lại; không đưa bản ghi bằng khóa vượt những bản ghi cùng khóa trước nó, nên có thể giữ ổn định. Tuy nhiên mỗi bước có thể dịch tuyến tính nhiều phần tử, tổng xấu nhất Theta(n²) lần di chuyển thay vì O(n) lần đổi chỗ của bản thông thường. Số so sánh vẫn Theta(n²). Phải đánh giá biến thể thực tế, không giữ nguyên ưu điểm cũ sau khi đổi cơ chế.

**Cần thể hiện khi trả lời:**

- Dựng sự đảo 2a,2b ở Selection đổi xa.
- Phân tích độ ổn định và số dịch của biến thể rút rồi chèn.

**Tránh nhầm:** Tính ổn định và số lần ghi bộ nhớ có thể đánh đổi; không gán tính chất của bản gốc cho biến thể.

[Quay lại câu hỏi](06_SapXep_TimKiem.md#lt6-05)

<a id="lt6-06"></a>

### LT6-06

**Câu hỏi:** Quick Sort chọn phần tử giữa theo chỉ số làm pivot. Hãy cho một mảng có ít nhất năm khóa phân biệt khiến pivot đó là khóa nhỏ nhất, rồi giải thích vì sao chọn chỉ số giữa không bảo đảm chia cân bằng. Nếu một phiên bản chỉ gọi đệ quy vào phần nhỏ hơn và xử lý phần lớn hơn bằng vòng lặp, hãy bảo vệ cận stack O(log n) và cho biết thời gian xấu nhất có nhờ vậy thành O(n log n) không.

**Ý cần nắm:** Ví dụ 4,3,1,2,5 có phần tử giữa bằng 1; phân hoạch theo giá trị có thể cho một phía rỗng và phía kia bốn phần tử. Chỉ số giữa không phải trung vị theo giá trị. Nếu chỉ gọi đệ quy phần nhỏ hơn, mỗi lần làm sâu stack xử lý không quá khoảng n/2 phần tử so với lần gọi cha; độ sâu O(log n), còn phần lớn được xử lý lặp ở mức hiện tại. Phân hoạch liên tục rất lệch vẫn có tổng n+(n−1)+… nên thời gian có thể Theta(n²); tối ưu stack không tự sửa tổng công việc.

**Cần thể hiện khi trả lời:**

- Tạo pivot giữa chỉ số nhưng cực trị theo khóa.
- Chứng minh stack theo nhánh nhỏ, tách nó khỏi cận thời gian xấu.

**Tránh nhầm:** Phải tách cân bằng dữ liệu, số lần so sánh và độ sâu lời gọi; ba đại lượng không đồng nhất.

[Quay lại câu hỏi](06_SapXep_TimKiem.md#lt6-06)

<a id="lt6-08"></a>

### LT6-08

**Câu hỏi:** Xét phân hoạch đoạn chỉ số đóng [l,r], r>l, chọn và giữ cố định giá trị pivot ở chỉ số giữa. Ban đầu i=l,j=r. Mỗi lượt khi i≤j: quét i sang phải, rồi quét j sang trái; mọi bước quét đều kiểm i≤j trước khi đọc ô. Nếu sau hai lượt quét vẫn i≤j thì đổi A[i],A[j], sau đó tăng i và giảm j. Cách A quét qua khóa <pivot ở trái và >pivot ở phải; cách B thay hai dấu ấy bằng ≤ và ≥. Sau khi i>j, Quick Sort gọi lại [l,j] và [i,r] nếu đoạn tương ứng có ít nhất hai phần tử. Hãy đánh giá riêng từng cách về: phân hoạch có dừng, giữ quan hệ khóa hai phía, và bảo đảm các lời gọi con nhỏ hơn bài toán cha. Tự dựng phản ví dụ nếu một bảo đảm thất bại.

**Câu hỏi tiếp:** Trên n khóa đều bằng pivot, hãy so hành vi của hai cách và phân tích thời gian Quick Sort của cách tiếp tục được. Từ đó có được kết luận cách ấy luôn chia cân bằng trên mọi dữ liệu không?

**Ý cần nắm:** Cả hai vòng phân hoạch đều dừng: chỉ số chỉ đi vào trong; nếu quét chưa làm i vượt j thì phép đổi luôn kèm tiến/lùi. Các vùng đã xử lý bên trái chứa khóa ≤pivot, bên phải chứa khóa ≥pivot; đổi hai phần tử dừng ở sai phía bảo toàn quan hệ này. Khi i>j, [l,j] có khóa ≤pivot và [i,r] có khóa ≥pivot; nếu còn một ô giữa hai miền thì nó bằng pivot. Nhưng quan hệ ấy chưa đủ bảo đảm Quick Sort kết thúc. Với B và [7,7,7], quét trái đi hết, i=r+1,j=r; lời gọi [l,j] chính là đoạn cha, nên đệ quy lặp lại không thu nhỏ. Với A, vì pivot là một giá trị trong đoạn và quét dùng dấu nghiêm ngặt, lượt đầu không thể quét chéo hết mà chưa xử lý vị trí gặp: có ít nhất một lần đổi, kể cả đổi một ô với chính nó. Sau đó i≥l+1,j≤r−1, các bước sau chỉ thu hẹp thêm, nên cả hai lời gọi con đều nhỏ hơn đoạn cha. Trên toàn khóa bằng, A liên tục đổi các cặp hai đầu và tiến cả hai chỉ số, chia thành hai phần gần bằng nhau. Một lượt phân hoạch Θ(n), toàn Quick Sort theo cách đệ quy này Θ(n log n) trên họ dữ liệu toàn bằng. B kết thúc một lượt phân hoạch nhưng cả Quick Sort không kết thúc trên họ đó. Cách A vẫn có thể chia lệch trên dữ liệu khác; pivot ở chỉ số giữa không bảo đảm là trung vị theo giá trị, nên không suy ra cận xấu nhất O(n log n) cho mọi đầu vào.

**Cần thể hiện khi trả lời:**

- Phân tích riêng dừng của vòng, bất biến phân hoạch và giảm kích thước lời gọi; tự tạo ca B gọi lại nguyên đoạn.
- Bảo vệ tiến triển của A từ pivot thuộc đoạn, tính đúng trường hợp toàn bằng và không suy rộng thành luôn cân bằng.

**Tránh nhầm:** Phải kiểm cả tiến triển bên trong vòng phân hoạch lẫn kích thước các lời gọi con. Giữ đúng quan hệ hai phía không tự bảo đảm đệ quy kết thúc hoặc chia cân bằng.

[Quay lại câu hỏi](06_SapXep_TimKiem.md#lt6-08)

<a id="lt6-10"></a>

### LT6-10

**Câu hỏi:** Cần xây max-heap từ mảng 1,2,3,4,5,6,7. Thủ tục điều chỉnh xuống chọn con lớn hơn và tiếp tục xuống cho tới đúng vị trí, nhưng chỉ có bảo đảm khi hai cây con đã là heap. Một bạn gọi nó theo thứ tự nút trong từ gốc xuống dưới, mỗi nút đúng một lần. Hãy truy vết để tìm quan hệ heap cuối cùng còn sai, rồi giải thích vì sao làm từ dưới lên đúng tiền điều kiện và vì sao tổng xây heap có thể O(n), dù một lần điều chỉnh có thể O(log n).

**Ý cần nắm:** Điều chỉnh gốc trước cho 3,2,7,4,5,6,1: số 3 ở gốc vẫn nhỏ hơn con 7 vì cây con ban đầu chưa là heap. Tiếp nút 1 cho 3,5,7,4,2,6,1, nút 2 không đổi; gốc vẫn sai. Làm từ nút trong thấp nhất lên bảo đảm các cây con đã được xử lý trước. Tổng công việc theo chiều cao các nút bị chặn bởi n×Σ_{j≥1}j/2^j=O(n), vì số nút có thể đi xa giảm nhanh; không phải mọi nút cùng đi log n mức.

**Cần thể hiện khi trả lời:**

- Truy vết lỗi khi điều chỉnh từ trên xuống trước khi cây con là heap.
- Bảo vệ thứ tự dưới lên và tổng xây heap tuyến tính.

**Tránh nhầm:** Một thủ tục đúng có tiền điều kiện không được áp dụng ở mọi thứ tự rồi mặc định toàn thuật toán đúng.

[Quay lại câu hỏi](06_SapXep_TimKiem.md#lt6-10)

<a id="lt6-11"></a>

### LT6-11

**Câu hỏi:** Ở một bước Heap Sort tăng dần, mảng được chia thành tiền tố đang xử lý và hậu tố đã chốt. Bộ kiểm chỉ xác nhận tiền tố là max-heap và hậu tố đã tăng. Hai điều đó có đủ bảo đảm sau khi sắp xong tiền tố, toàn mảng sẽ đúng không? Tự dựng một trạng thái vượt qua kiểm tra nhưng không thể hoàn tất đúng nếu chỉ tiếp tục xử lý tiền tố; bổ sung bất biến còn thiếu.

**Câu hỏi tiếp:** Nếu cần Heap Sort giảm dần, hãy nêu loại heap và quan hệ giữa hai vùng. Việc đổi các dấu so phải bảo vệ cả thứ tự lẫn bảo toàn bản ghi như thế nào?

**Ý cần nắm:** Chưa đủ. Chẳng hạn tiền tố [6,4,5] là max-heap, hậu tố [1,7,8] tăng, nhưng sắp tiền tố cho [4,5,6,1,7,8], vẫn sai. Cần mọi phần tử trong tiền tố không lớn hơn mọi phần tử ở hậu tố; hậu tố chứa đúng các phần tử lớn nhất đã chốt, đồng thời toàn mảng bảo toàn tập đa trị bản ghi ban đầu. Một bước đúng đưa cực đại của vùng heap tới cuối vùng đang xử lý, giảm vùng này rồi phục hồi heap, giữ quan hệ giữa hai vùng. Với giảm dần, dùng min-heap, đưa cực tiểu về cuối; hậu tố giảm và mọi phần tử của nó không lớn hơn mọi phần tử trong tiền tố. Đổi dấu so không được làm mất, nhân đôi hoặc tách khóa khỏi phần dữ liệu tương ứng.

**Cần thể hiện khi trả lời:**

- Tự tạo trạng thái mà hai kiểm tra cục bộ đều qua nhưng toàn cục sai.
- Phát biểu đủ bất biến hai vùng cho cả tăng và giảm, có bảo toàn bản ghi.

**Tránh nhầm:** Hai vùng đúng riêng chưa đủ cho toàn mảng; cần quan hệ ở ranh giới và bảo toàn dữ liệu.

[Quay lại câu hỏi](06_SapXep_TimKiem.md#lt6-11)

<a id="lt6-12"></a>

### LT6-12

**Câu hỏi:** Một Merge Sort từ dưới lên đã qua kiểm thử hàm trộn hai đoạn với vùng đệm riêng. Tuy nhiên ở lượt độ dài s=4 trên n=11 phần tử, các đoạn đầu vào dài 4,4,3 đều tăng, mọi lần gọi hàm trộn đều cho kết quả đúng, nhưng mảng sau cả lượt không còn là hoán vị đầu vào. Hãy đề xuất một lỗi điều phối có thể gây triệu chứng này, tự dựng dữ liệu 11 phần tử và truy vết đủ để phân biệt lỗi điều phối với lỗi trong hàm trộn.

**Câu hỏi tiếp:** Nêu bất biến của toàn lượt và nhóm kích thước kiểm thử giúp phát hiện lỗi dù các mẫu n là lũy thừa hai đều qua. Có thể kết luận chính xác lỗi của chương trình thật chỉ từ triệu chứng trên không?

**Ý cần nắm:** Một khả năng là vòng ngoài chỉ trộn các cặp đoạn đủ s và cuối lượt chép toàn bộ đệm về nguồn, nhưng bỏ quên đoạn dư. Ví dụ đầu vào [1,3,5,7 | 2,4,6,8 | 9,10,11], đệm ban đầu toàn −1: trộn hai đoạn đầu đúng thành 1…8, ba ô đệm cuối chưa được ghi. Chép cả 11 ô cho [1,2,3,4,5,6,7,8,−1,−1,−1], làm mất 9,10,11 dù lời gọi trộn đúng. Bất biến: mỗi phần tử đầu vào của lượt phải đi vào đúng một ô đầu ra, kể cả đoạn không có bạn trộn; các đoạn đầu ra tăng và có độ dài không quá 2s. Lượt tiếp theo s=8 cần xử lý cặp 8 và 3. Test quanh lũy thừa hai và quanh bội 2s, với khóa hoặc mã nhận diện phân biệt, giúp lộ đoạn lẻ và đoạn ngắn. Đây là một giả thuyết có diễn biến tái hiện; lỗi chỉ số/chép đè khác cũng có thể gây cùng triệu chứng, nên cần đọc hoặc ghi vết chương trình thật để kết luận.

**Cần thể hiện khi trả lời:**

- Tạo dữ liệu và trạng thái đệm cho một giả thuyết tái hiện được.
- Nêu bất biến bao phủ toàn lượt và test đoạn dư, phân biệt giả thuyết với chẩn đoán đã xác nhận.

**Tránh nhầm:** Qua kiểm thử hàm con không chứng minh vòng điều phối đúng; dựng một nguyên nhân hợp lý cũng chưa xác nhận đó là lỗi thật.

[Quay lại câu hỏi](06_SapXep_TimKiem.md#lt6-12)

<a id="lt6-14"></a>

### LT6-14

**Câu hỏi:** Cần sắp n bản ghi tổng quát bằng so sánh: ổn định theo khóa đã có, thời gian xấu nhất O(n log n), chỉ O(1) bộ nhớ phụ và không có sẵn chỉ số thứ tự ban đầu trong bản ghi. Trong sáu cách cài thông thường đã học — Bubble, Insertion, Selection đổi chỗ, Quick đệ quy, Heap lặp, Merge mảng có đệm — cách nào đáp ứng đủ? Một đề xuất “Heap Sort rồi thêm vị trí hiện tại làm khóa phụ cho ổn định” có giải quyết được không? Hãy trả lời đúng phạm vi, không tuyên bố bất khả thi cho mọi thuật toán có thể tồn tại.

**Ý cần nắm:** Không có một trong sáu bản cài nêu trên đáp ứng đồng thời: Bubble/Insertion ổn định và ít bộ nhớ nhưng xấu nhất bậc hai; Selection đổi chỗ không ổn định và bậc hai; Quick thường không ổn định, có stack và xấu nhất bậc hai; Heap lặp ít bộ nhớ và O(n log n) nhưng không ổn định; Merge mảng ổn định và O(n log n) nhưng dùng đệm O(n). Vị trí hiện tại đổi trong lúc sắp nên không thay được thứ tự ban đầu. Lưu chỉ số ban đầu cho từng bản ghi cần thêm thông tin theo n trong mô hình đã nêu. Cần thương lượng một điều kiện hoặc nghiên cứu biến thể khác ngoài sáu bản này; chưa có chứng minh bất khả thi tổng quát.

**Cần thể hiện khi trả lời:**

- Đối chiếu đủ ổn định, thời gian xấu và bộ nhớ của sáu cách cài được nêu.
- Không coi vị trí hiện tại là thứ tự gốc và không tuyên bố bất khả thi ngoài phạm vi.

**Tránh nhầm:** Đừng biến một yêu cầu không đạt trong các phương án đang xét thành định lý không thể có; cũng không giấu bộ nhớ đánh dấu thứ tự.

[Quay lại câu hỏi](06_SapXep_TimKiem.md#lt6-14)

<a id="lt6-17"></a>

### LT6-17

**Câu hỏi:** Cho mảng tăng không giảm có n phần tử, có thể rỗng hoặc chứa khóa trùng. Cần trả chỉ số đầu tiên có A[i]≥x; nếu không có thì trả n. Không dùng hàm thư viện: hãy thiết kế tìm kiếm nhị phân bằng lời, tự chọn đoạn đóng hoặc nửa mở. Phát biểu rõ phần đã loại, nơi đáp án còn có thể nằm và đại lượng giảm sau mỗi bước; giải thích vì sao không trả nhầm một vị trí bằng x ở giữa nhóm trùng. Ngoài chứng minh kết thúc, phải bảo vệ cận số vòng lặp theo cách chọn điểm xét.

**Câu hỏi tiếp:** Tự chọn các test phân biệt lỗi bỏ sót đáp án ở biên, không kết thúc và trả sai vị trí đầu. Nếu đổi yêu cầu thành vị trí đầu có A[i]>x, phần xử lý khóa bằng x thay đổi thế nào?

**Ý cần nắm:** Một cách dùng miền chưa phân loại [l,r), ban đầu [0,n). Bất biến: mọi i<l có A[i]<x; mọi i≥r trong mảng có A[i]≥x. Đáp án là biên chuyển tiếp thuộc [l,r], có thể bằng n. Khi l<r, chọn điểm giữa m=l+⌊(r−l)/2⌋. Nếu A[m]<x, tính tăng cho phép loại tới m, biên trái mới là m+1; ngược lại biên phải mới là m. Trường hợp sau chưa trả ngay khi gặp x, mà tiếp tục tìm phía trái; m đã thuộc vùng đạt điều kiện và có thể là biên cuối. Đặt L=r−l>0: nếu cập nhật r thì độ dài mới là ⌊L/2⌋; nếu cập nhật l thì độ dài mới là L−⌊L/2⌋−1≤⌊L/2⌋. Vì vậy miền giảm ít nhất khoảng một nửa mỗi vòng, không chỉ giảm một lượng dương; với n≥1 có tối đa ⌊log₂n⌋+1 vòng. Khi l=r, l là vị trí đầu đạt hoặc n. Mảng rỗng trả 0, không truy cập ô và không chạy vòng lặp. Tính cả khởi tạo/kết thúc, thời gian O(1+log(n+1)), bộ nhớ lặp O(1), giả sử so khóa O(1). Nếu chỉ chọn m tùy ý trong [l,r), kết quả vẫn có thể đúng và dừng nhưng chưa có cận logarit: chọn m=l với x lớn hơn mọi khóa sẽ cần n vòng. Test: [] với x bất kỳ→0; [2,2] với x=2→0 và x=3→2; [1,3] với x=2→1; thêm x nhỏ hơn phần tử đầu và mảng một ô. Với yêu cầu >x, vùng bên trái chứa khóa ≤x, bên phải chứa khóa >x, nên khóa bằng x bị loại về phía trái; giữ cách chọn giữa và cận thu hẹp như trên. Cách dùng đoạn đóng kèm biến ứng viên cũng hợp lệ nếu chứng minh đủ bất biến, tiến triển và giảm miền theo tỷ lệ cố định.

**Cần thể hiện khi trả lời:**

- Có bất biến đúng cho khóa trùng/rỗng và chứng minh độ dài còn lại tối đa ⌊L/2⌋ theo điểm giữa.
- Tách kết thúc khỏi cận logarit, tự chọn test có sức phân biệt và chỉnh đúng khi đổi ≥ thành >.

**Tránh nhầm:** Giảm nghiêm ngặt đủ để chứng minh kết thúc trên miền hữu hạn, chưa đủ suy ra thời gian logarit. Ứng viên có thể ở biên r dù r không thuộc miền chưa phân loại.

[Quay lại câu hỏi](06_SapXep_TimKiem.md#lt6-17)

<a id="lt6-18"></a>

### LT6-18

**Câu hỏi:** Tên sách được sắp theo đúng thứ tự từ điển của các chuỗi chữ thường, không có bước chuẩn hóa khác. So ba truy vấn: bằng “an”, bắt đầu bằng “an”, chứa “an” ở bất kỳ vị trí. Với dãy an, ana, ban, car, xan, hãy chỉ nhóm kết quả và quyết định truy vấn nào có cơ sở tạo một khoảng liên tục để dùng tìm biên nhị phân. Sau đó nêu chi phí trả k kết quả và điều gì phải xét lại nếu khi tìm bỏ dấu/đổi hoa thường nhưng khi sắp thì không.

**Ý cần nắm:** Bằng “an” cho phần tử đầu; tiền tố “an” cho an,ana; chứa “an” cho an,ana,ban,xan, bị ngắt bởi car. Các chuỗi bằng một khóa hoặc chung tiền tố tạo một khoảng theo chính thứ tự từ điển đã nêu; truy vấn chứa không có bảo đảm đó. Có thể tìm hai biên bằng cách so/kiểm tiền tố phù hợp rồi xuất k kết quả, O(log n+k) về thao tác nếu phép so được coi hằng số; chuỗi dài và lượng đầu ra có chi phí riêng. Chuẩn hóa khác nhau giữa sắp và tìm có thể phá tính đơn điệu cần để loại nửa miền, nên phải xác lập lại thứ tự tương ứng.

**Cần thể hiện khi trả lời:**

- Phân biệt bằng/prefix/substring về tính liên tục theo thứ tự đang sắp.
- Tính tìm biên cộng xuất k kết quả và kiểm thống nhất chuẩn hóa.

**Tránh nhầm:** Không suy mọi kiểu tìm tên đều dùng được cùng một tìm nhị phân chỉ vì mảng đã tăng theo tên.

[Quay lại câu hỏi](06_SapXep_TimKiem.md#lt6-18)

<a id="lt6-21"></a>

### LT6-21

**Câu hỏi:** Thu nhỏ bài top 10 thành top 3 để phân tích: bảy đầu sách A…G có số lượt lần lượt 9,8,7,7,7,3,1. So hai hợp đồng: đúng ba đầu sách, khi hòa lấy mã tăng; hoặc lấy mọi đầu sách có lượt không thấp hơn mức của hạng ba. Hãy nêu hai kết quả và đánh giá đề xuất dùng heap giữ đúng ba ứng viên cho cả hai. Khi quay lại D đầu sách và H lượt lịch sử, những chi phí nào vẫn phải tính ngoài việc giữ heap?

**Ý cần nắm:** Hợp đồng đúng ba trả A,B,C; hợp đồng bao gồm đồng hạng trả A,B,C,D,E. Heap chỉ giữ ba bản ghi có thể tìm được ngưỡng 7, nhưng không tự giữ đủ mọi đầu sách đồng hạng đã bị loại; cần cơ chế khác, chẳng hạn lượt quét tiếp nếu còn dữ liệu, hoặc chấp nhận bộ nhớ kết quả tăng. Với hợp đồng đúng k và tiêu chí hòa đầy đủ, giữ heap ứng viên có thể O(D log k), rồi sắp k kết quả; vẫn cần tính lượt mượn từ H bản ghi, ánh xạ về đầu sách, chuẩn bị và xuất dữ liệu. Nếu mọi đầu đồng hạng, đầu ra theo hợp đồng hai có thể dài D, không chỉ k.

**Cần thể hiện khi trả lời:**

- Cho đúng kết quả của top-k cố định và lấy hết hòa ở ngưỡng.
- Tính chi phí thống kê lịch sử/đầu sách trước bước giữ heap.

**Tránh nhầm:** Chưa thống nhất đồng hạng thì chưa thể kết luận một thuật toán top k đáp ứng yêu cầu; đây là giả định cần nhóm/thầy chốt.

[Quay lại câu hỏi](06_SapXep_TimKiem.md#lt6-21)

<a id="lt6-23"></a>

### LT6-23

**Câu hỏi:** Muốn sắp bản ghi tăng theo tên, nếu trùng tên mới xét năm. Một comparator trả “A đứng trước B” khi tên A nhỏ hơn tên B HOẶC năm A nhỏ hơn năm B. Hãy tự tạo cặp bản ghi chứng minh vấn đề của quan hệ này và nêu vì sao đổi thuật toán sắp xếp không sửa được hợp đồng so sánh.

**Câu hỏi tiếp:** Thay HOẶC bằng VÀ có thực hiện đúng ưu tiên tên rồi năm không? Dùng dữ liệu cụ thể để trả lời và nêu quy tắc so phù hợp, kể cả hai bản ghi bằng cả tên lẫn năm.

**Ý cần nắm:** Chọn A=(An,2025), B=(Bình,2020), giả sử An đứng trước Bình. A trước B theo tên, còn B trước A theo năm; comparator HOẶC trả đúng cả hai chiều, vi phạm tính bất đối xứng của quan hệ “đứng trước”. Thuật toán sắp không thể bảo đảm một thứ tự thỏa đồng thời hai đòi hỏi mâu thuẫn ấy. Đổi thành VÀ cho cả hai chiều sai trên cặp này, trong khi yêu cầu ưu tiên tên vẫn buộc A đứng trước B. Quy tắc đúng: tên nhỏ hơn thì đứng trước; chỉ khi tên bằng nhau mới dùng năm nhỏ hơn. Nếu bằng cả hai trường thì hai chiều đều sai, và nếu cần giữ thứ tự ban đầu giữa chúng phải dùng hợp đồng ổn định phù hợp. Quan hệ ưu thế theo nhiều tiêu chí là một mục tiêu khác thứ tự ưu tiên trường.

**Cần thể hiện khi trả lời:**

- Tự dựng cặp so mâu thuẫn hai chiều cho HOẶC.
- Bác bỏ VÀ đối với thứ tự ưu tiên trường và xử lý rõ khóa bằng nhau.

**Tránh nhầm:** Comparator là một phần đặc tả tính đúng. Không chữa một quan hệ sai bằng việc thử nhiều thuật toán rồi chọn kết quả trông hợp lý.

[Quay lại câu hỏi](06_SapXep_TimKiem.md#lt6-23)

<a id="lt6-24"></a>

### LT6-24

**Câu hỏi:** Quick Sort chọn pivot ngẫu nhiên. Một phiên bản phân thành phần < pivot và phần ≥ pivot, đặt riêng một bản ghi pivot, rồi gọi tiếp hai phần còn lại; phiên bản khác gom toàn bộ phần = pivot và chỉ gọi tiếp các phần <,>. Trên n khóa đều bằng nhau, hãy phân tích độ sâu và công việc của hai cách. Ngẫu nhiên hóa pivot có cứu phiên bản đầu khỏi trường hợp này không?

**Ý cần nắm:** Trong phiên bản đầu, bỏ riêng một bản ghi pivot vẫn để n−1 khóa bằng ở cùng một phía; các kích thước còn lại là n−1,n−2,…, nên có thể tốn Theta(n²) và sâu Theta(n) với cách đệ quy thông thường. Chọn pivot nào cũng cùng giá trị, nên ngẫu nhiên hóa không thay cách chia này. Phiên bản gom phần bằng chỉ cần một lượt phân hoạch tuyến tính, rồi hai phần phải đệ quy đều rỗng, nên Theta(n) công việc cho dữ liệu toàn bằng. Điều này không biến mọi dữ liệu của Quick Sort thành tuyến tính hoặc xóa mọi cận xấu khác.

**Cần thể hiện khi trả lời:**

- Phân tích khóa trùng cho phân hoạch hai phía và gom ba nhóm.
- Giải thích vì sao pivot ngẫu nhiên không cứu chuỗi loại một phần tử bằng nhau.

**Tránh nhầm:** Ngẫu nhiên hóa lựa chọn giá trị và xử lý khóa trùng là hai vấn đề khác nhau.

[Quay lại câu hỏi](06_SapXep_TimKiem.md#lt6-24)

<a id="lt6-25"></a>

### LT6-25

**Câu hỏi:** Một hàm trộn xuôi hai dãy tăng đã được chứng minh đúng khi đầu ra tách biệt với hai vùng đầu vào. Nay bên gọi đặt hai dãy ở hai đoạn liền nhau trong một mảng và truyền đầu mảng ấy làm đầu ra, giữ nguyên thuật toán. Có đủ bảo đảm tổng sức chứa bằng tổng hai độ dài không? Tự tạo phản ví dụ và chỉ ra tiền điều kiện nào của chứng minh cũ không còn đúng.

**Câu hỏi tiếp:** Một bạn sửa bằng cách đọc từ hai cuối và ghi ngược từ cuối chính mảng có đúng n+m ô, vẫn không có đệm. Cách sửa ấy có luôn an toàn không? Phân biệt mô hình này với trường hợp dãy thứ nhất có chỗ dư cuối và dãy thứ hai nằm ở vùng riêng.

**Ý cần nắm:** Không. Với [4,8 | 1,6], chọn 1 rồi ghi vào ô đầu làm mất 4 chưa đọc; còn đủ số ô không có nghĩa các lần ghi không đè dữ liệu nguồn. Chứng minh trộn có đệm dựa vào việc phần chưa đọc còn nguyên. Chỉ đổi hướng cũng không đủ: với [6,8 | 1,4], lấy cực đại 8 của đoạn trái ghi vào ô cuối sẽ đè 4 chưa đọc của đoạn phải. Ngược lại, mô hình A có chỗ trống ở cuối còn B tách biệt cho phép trộn ngược vì vị trí ghi được bảo vệ khỏi phần A chưa đọc và không ghi đè B. Có các cách trộn tại chỗ khác dùng dịch, xoay đoạn hoặc kỹ thuật phức tạp hơn, nhưng phải chứng minh và phân tích riêng; không suy ra bất khả thi từ hai phản ví dụ này.

**Cần thể hiện khi trả lời:**

- Truy vết đúng lần ghi đè đầu tiên cho cả hướng xuôi và ngược.
- Phân biệt hai đoạn cùng mảng với mô hình một đầu vào riêng và chỗ dư cuối.

**Tránh nhầm:** Tính đúng của hàm còn phụ thuộc quan hệ giữa các vùng bộ nhớ. Đổi hướng duyệt không tự khôi phục tiền điều kiện vùng đầu ra tách biệt.

[Quay lại câu hỏi](06_SapXep_TimKiem.md#lt6-25)

<a id="lt6-26"></a>

### LT6-26

**Câu hỏi:** Mảng có n khóa phân biệt đã tăng. Có q truy vấn chỉ hỏi tồn tại/không tồn tại và các khóa truy vấn cũng đã tăng, cho phép trả kết quả theo thứ tự đó. So tìm nhị phân độc lập q lần với dùng một vị trí chỉ tiến qua mảng khi xét các truy vấn. Hãy bảo vệ chi phí tổng của cách thứ hai, so khi q gần n với khi q=1, và giải thích nghĩa vụ bổ sung nếu ban đầu cần giữ thứ tự truy vấn tùy ý.

**Ý cần nắm:** Có thể giữ vị trí ở phần tử chưa bị loại: khi nó nhỏ hơn khóa truy vấn thì tiến, khi bằng/lớn hơn thì xác định kết quả. Vì các truy vấn tăng, không cần quay lại các phần tử đã vượt; tổng bước đi mảng không quá n, cộng q truy vấn cho O(n+q). Tìm nhị phân độc lập có O(q log n), có thể tốt hơn khi q rất nhỏ; với q cùng bậc n, cách đi chung có lợi về bậc. Nếu truy vấn ban đầu chưa sắp, phải cộng chi phí sắp, giữ vị trí gốc và khôi phục thứ tự kết quả; không được giả định các việc đó miễn phí.

**Cần thể hiện khi trả lời:**

- Chứng minh tổng bước của con trỏ đơn điệu trên mảng và dãy truy vấn.
- So q nhỏ/q gần n, tính nghĩa vụ giữ thứ tự truy vấn ban đầu.

**Tránh nhầm:** Một cách tốt cho nhiều truy vấn có thứ tự không nhất thiết tốt cho một truy vấn hoặc cho luồng phải trả ngay theo thứ tự đến.

[Quay lại câu hỏi](06_SapXep_TimKiem.md#lt6-26)

<a id="lt6-27"></a>

### LT6-27

**Câu hỏi:** Dãy n khóa phân biệt đang giảm hoàn toàn. Gọi một nghịch thế là cặp vị trí i<j nhưng khóa ở i lớn hơn khóa ở j. Vì sao mọi phương pháp chỉ đổi chỗ hai phần tử kề nhau cần ít nhất n(n−1)/2 lần đổi để sắp tăng? Kết luận đó có mâu thuẫn với Heap Sort O(n log n) không? Hãy nói rõ mô hình thao tác đang bị giới hạn.

**Ý cần nắm:** Dãy giảm có một nghịch thế cho mọi cặp, tổng n(n−1)/2. Đổi hai phần tử kề chỉ thay đổi quan hệ của đúng cặp đó, làm số nghịch thế tăng hoặc giảm một; muốn về 0 cần ít nhất bằng số nghịch thế ban đầu lần đổi. Heap Sort có thể đổi các vị trí xa nhau và tái tổ chức bằng quan hệ heap, nên không bị chặn dưới dành riêng cho đổi kề. Không được áp dụng cận số phép đổi kề cho mọi mô hình sắp xếp hoặc nhầm nó với cận số phép so sánh.

**Cần thể hiện khi trả lời:**

- Đếm nghịch thế và mức một phép đổi kề có thể giảm.
- Giới hạn cận dưới trong mô hình đổi kề, không mâu thuẫn Heap Sort.

**Tránh nhầm:** Một chặn dưới mạnh chỉ đúng trong các giả thiết đã dùng để chứng minh nó.

[Quay lại câu hỏi](06_SapXep_TimKiem.md#lt6-27)

<a id="lt6-28"></a>

### LT6-28

**Câu hỏi:** Kho chia thành nhiều phần không trùng đầu sách; mỗi đầu sách đã có số lượt mượn cuối cùng, và mọi phần dùng cùng thứ tự so đầy đủ để phá hòa. Muốn lấy đúng top k toàn kho, có đủ lấy top k mỗi phần rồi chọn lại từ hợp không? Hãy chứng minh hoặc cho phản ví dụ. Nếu thay vào đó chia các lượt lịch sử theo tháng, một đầu sách có thể xuất hiện ở nhiều tháng và số lượt phải cộng lại, lập luận cũ còn đúng không?

**Ý cần nắm:** Với các tập đầu sách tách rời và điểm cuối cùng đã biết, cách lấy hợp là đủ: một đầu sách bị loại khỏi top k của phần nó đã có ít nhất k đầu sách đứng trước nó theo cùng thứ tự toàn cục, nên không thể thuộc top k toàn kho. Khi chia lịch sử, điểm của cùng đầu sách còn phân tán nên lập luận không còn dùng được. Với k=1, A có 5 lượt ở mỗi tháng; tháng một B có 6, tháng hai C có 6, các điểm khác bằng 0. Top riêng là B và C, nhưng tổng A=10 đứng đầu và bị mất khỏi hợp. Phải tổng hợp đúng điểm trước hoặc dùng một quy trình khác có căn cứ.

**Cần thể hiện khi trả lời:**

- Chứng minh top-k cục bộ đủ khi các đối tượng tách rời và số liệu đã chốt.
- Dựng phản ví dụ khi phải cộng cùng đối tượng qua các tháng.

**Tránh nhầm:** Cần phân biệt chia tập đối tượng đã có điểm với chia những đóng góp tạo ra điểm của cùng đối tượng.

[Quay lại câu hỏi](06_SapXep_TimKiem.md#lt6-28)

<a id="lt6-29"></a>

### LT6-29

**Câu hỏi:** Một max-heap có thể tìm cực đại ở gốc. Nhóm suy ra tìm một khóa bất kỳ cũng O(log n) bằng cách “đi một nhánh như BST”. Hãy bác bỏ suy luận bằng quan hệ thứ tự mà heap thực sự bảo đảm. Sau đó xét heap có mọi nút trong mang khóa 2, còn mỗi lá có thể là 0 hoặc 1, và cần xác nhận không có khóa 1: vì sao trong mô hình không có chỉ mục phụ có thể phải đọc số lá tuyến tính?

**Ý cần nắm:** Max-heap chỉ bảo đảm cha không nhỏ hơn con; nó không phân chia miền khóa nhỏ/lớn giữa hai cây con để chọn bỏ một nhánh như BST. Trong họ heap đã nêu, mỗi lá độc lập có thể là 0 hoặc 1 mà vẫn không lớn hơn cha 2. Nếu còn một lá chưa xem, hai heap giống mọi vị trí đã xem nhưng khác 0/1 ở lá đó đòi hai câu trả lời khác nhau. Cây heap hoàn chỉnh có số lá Theta(n), nên xác nhận vắng 1 có cận xấu Omega(n), không phải O(log n).

**Cần thể hiện khi trả lời:**

- Phân biệt quan hệ heap với miền khóa của BST.
- Dùng các lá 0/1 độc lập để bảo vệ số vị trí phải đọc ở trường hợp xấu.

**Tránh nhầm:** Một cực trị đọc O(1) không có nghĩa cấu trúc hỗ trợ tìm mọi khóa hiệu quả như cây tìm kiếm.

[Quay lại câu hỏi](06_SapXep_TimKiem.md#lt6-29)

<a id="lt6-30"></a>

### LT6-30

**Câu hỏi:** Đầu vào gồm các khóa nguyên phân biệt, không rỗng. Bộ kiểm một thuật toán sắp xếp chỉ xác nhận đầu ra tăng nghiêm ngặt, cùng số phần tử, cùng tổng, cùng min và max. Hãy tìm số phần tử nhỏ nhất cho phép một đầu ra sai vẫn qua toàn bộ kiểm tra, tự đưa cặp đầu vào–đầu ra và chứng minh tính tối thiểu.

**Câu hỏi tiếp:** Nếu mỗi bản ghi có mã riêng, khóa sắp là tên được phép trùng, cần kiểm thêm những gì để phát hiện mất, nhân đôi hoặc ghép sai dữ liệu? Tách yêu cầu bảo toàn dữ liệu khỏi yêu cầu ổn định.

**Ý cần nắm:** Nhỏ nhất là 4: đầu vào [1,2,5,8], đầu ra [1,3,4,8] đều tăng nghiêm ngặt, có 4 phần tử, tổng 16, min 1, max 8, nhưng khác các khóa ở giữa. Với 1 phần tử, min xác định nó; với 2 phần tử, min và max xác định cả hai; với 3 phần tử, min, max và tổng xác định phần tử giữa. Vì đầu ra phải tăng nghiêm ngặt, không còn thứ tự khác che lỗi ở n≤3. Với bản ghi, cần kiểm đúng tập mã và đúng nội dung gắn với mỗi mã, hoặc so tập đa trị toàn bản ghi với đầu vào theo hợp đồng; chỉ bảo toàn khóa tên không bảo toàn danh tính/nội dung. Nếu yêu cầu ổn định, kiểm thêm thứ tự mã ban đầu trong từng nhóm bằng khóa, không coi ổn định là hệ quả của bảo toàn dữ liệu.

**Cần thể hiện khi trả lời:**

- Tìm được cặp 4 phần tử và chứng minh không thể với 1–3 phần tử.
- Tách thứ tự, bảo toàn bản ghi và ổn định thành các nghĩa vụ khác nhau.

**Tránh nhầm:** Các số tổng hợp có thể trùng dù dữ liệu khác. Một phép kiểm mạnh cho khóa đơn chưa chắc đủ khi khóa chỉ là một trường của bản ghi.

[Quay lại câu hỏi](06_SapXep_TimKiem.md#lt6-30)

<a id="lt6-31"></a>

### LT6-31

**Câu hỏi:** Mảng A có n≥1 khóa đang tăng không giảm. Một lô gồm k vị trí phân biệt và giá trị mới, 0≤k≤n; các vị trí đã được cho theo thứ tự tăng nghiêm ngặt. Chỉ khi trạng thái cuối vẫn tăng mới áp dụng cả lô, nếu không phải giữ nguyên A. Chỉ xét xử lý tuần tự, phép gán không thất bại; truy cập ô A và phần tử của danh sách thay đổi tốn O(1). Không quét lại cả n ô: hãy tự tìm phản ví dụ cho cách kiểm từng giá trị mới với hàng xóm cũ, rồi thiết kế tập các cặp kề cần kiểm trong trạng thái dự kiến cuối. Chứng minh tập đó đủ và phân tích chi phí theo k.

**Câu hỏi tiếp:** Làm thế nào đọc giá trị dự kiến của một hàng xóm cũng bị đổi mà không tạo bản sao n ô? Vì sao kiểm tuần tự rồi ghi ngay có thể vi phạm hợp đồng khi một thay đổi sau bị từ chối? Nếu các vị trí vẫn phân biệt nhưng chưa được sắp, cần tính thêm công việc nào cho phương án của bạn?

**Ý cần nắm:** Ví dụ A=[0,10,20,30], đổi vị trí 1 thành 18 và vị trí 2 thành 12: mỗi giá trị đều nằm giữa hai hàng xóm cũ, nhưng trạng thái cuối [0,18,12,30] sai. Với tập vị trí đổi S, chỉ cần kiểm các cạnh (i,i+1) mà i∈S hoặc i+1∈S, dùng giá trị sau tất cả thay đổi. Mọi cạnh khác giữ nguyên hai đầu nên vẫn đúng; mọi cạnh bị ảnh hưởng đã kiểm, vì vậy toàn mảng tăng khi và chỉ khi tất cả các cạnh được kiểm đều hợp lệ. Có tối đa min(2k,n−1) cạnh khác nhau. Duyệt danh sách thay đổi đã tăng theo chỉ số: với một vị trí t, hàng xóm t−1 hoặc t+1 nếu cũng đổi phải nằm ngay trước hoặc sau nó trong danh sách thay đổi; dùng giá trị mới ở đó, nếu không thì đọc A gốc. Bỏ qua hàng xóm ngoài mảng. Có thể kiểm một cạnh hai lần mà vẫn chỉ tối đa 2k lần so; không cần cấu trúc đánh dấu n ô. Thời gian kiểm O(k), bộ nhớ phụ O(1) ngoài danh sách k thay đổi đã cho; k=0 không có cạnh cần kiểm và chỉ cần công việc hằng số. Chưa ghi A trong pha kiểm. Nếu tất cả qua, ghi k thay đổi trong lượt thứ hai; nếu có cạnh sai thì từ chối và A nguyên vẹn. Ghi ngay khi kiểm có thể để lại một phần lô khi về sau phát hiện lỗi; muốn làm vậy phải có cơ chế hoàn tác, không được tự coi là đáp ứng hợp đồng. Nếu các vị trí chưa sắp, phương án này có thể sắp các cặp (vị trí,giá trị mới) trước với O(k log(k+1)), rồi kiểm/ghi O(k); phải tính thêm vùng sao nếu hợp đồng cấm sửa thứ tự danh sách thay đổi đầu vào. Không cần đa luồng để phát sinh vấn đề.

**Cần thể hiện khi trả lời:**

- Tự dựng phản ví dụ và chứng minh tập cạnh bị ảnh hưởng là đủ, có cận số cạnh.
- Đọc đúng giá trị dự kiến từ các thay đổi kề nhau, kiểm trước/ghi sau và tính cả chi phí khi đầu vào chưa sắp.

**Tránh nhầm:** Phải kiểm cạnh trong trạng thái cuối, không trộn giá trị mới của một đầu với giá trị cũ của đầu kia. Tính đúng thứ tự và tính toàn bộ-hoặc-không của lô là hai nghĩa vụ riêng.

[Quay lại câu hỏi](06_SapXep_TimKiem.md#lt6-31)

<a id="lt6-32"></a>

### LT6-32

**Câu hỏi:** Có K đoạn không rỗng, mỗi đoạn đã tăng không giảm theo cùng khóa; tổng N bản ghi. Truy cập đầu/cuối mỗi đoạn tốn O(1). Nhóm muốn sắp thứ tự các đoạn theo khóa nhỏ nhất rồi ghép nguyên đoạn để tránh trộn từng bản ghi. Hãy tự đánh giá đề xuất này, suy ra điều kiện cần và đủ để một thứ tự ghép đã chọn cho kết quả tăng, rồi đề xuất cách tận dụng trường hợp ghép được mà vẫn xử lý đúng các trường hợp còn lại.

**Câu hỏi tiếp:** Các đoạn ban đầu là các khúc liên tiếp của cùng một dãy, bản ghi có mã nhận diện và khóa có thể trùng. Nếu yêu cầu ổn định theo dãy ban đầu, điều kiện về giá trị ở ranh giới đã đủ chưa? Nêu cách giữ ổn định khi phải trộn.

**Ý cần nắm:** Sắp theo min không đủ: A=[1,100], B=[2,3] cho [1,100,2,3]. Với thứ tự các đoạn B_1…B_K đã chọn và từng đoạn đã tăng, điều kiện cần và đủ là last(B_i)≤first(B_{i+1}) ở mọi ranh giới; cần vì là hai phần tử kề, đủ do kết hợp với thứ tự nội bộ. Kiểm K−1 ranh giới tốn O(K); xuất bản ghép vẫn Θ(N), và nếu phải sắp thứ tự K đoạn thì tính thêm chi phí đó. Khi điều kiện không đạt, trộn đôi theo các vòng cân bằng có thể tạo kết quả O(N log K) thời gian với bộ đệm O(N); có thể giữ nguyên thứ tự các đoạn và dùng cách này trực tiếp. Với ổn định, mỗi đoạn còn phải giữ thứ tự gốc trong nhóm bằng khóa. Đổi thứ tự hai đoạn toàn khóa 1 vẫn qua kiểm giá trị nhưng đảo thứ tự mã ban đầu. Cách đơn giản là ghép nhanh chỉ khi thứ tự đoạn gốc đã qua kiểm ranh giới; nếu phải trộn, trộn ổn định các đoạn kề theo thứ tự gốc, khi khóa bằng thì lấy bên trái trước. Một thiết kế đổi thứ tự đoạn phải chứng minh riêng thứ tự gốc của các bản ghi bằng khóa, chẳng hạn dùng vị trí gốc làm thông tin phân xử.

**Cần thể hiện khi trả lời:**

- Suy ra điều kiện cần và đủ, có phản ví dụ cho sắp theo min.
- Tính cả kiểm/chuẩn bị/xuất và đề xuất đường trộn; xử lý riêng thứ tự gốc của các khóa bằng.

**Tránh nhầm:** O(K) chỉ là chi phí kiểm ranh giới khi thứ tự trong từng đoạn đã được bảo đảm. Khóa tăng không tự chứng minh ổn định.

[Quay lại câu hỏi](06_SapXep_TimKiem.md#lt6-32)
