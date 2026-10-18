# Kiểm chứng runtime mới — 17/10/2026

Đã build bản sao nguồn nguyên trạng bằng g++ (Rev3, Built by MSYS2 project) 16.2.0. Tám `.cpp`, C++17, `-O2 -Wall -Wextra -pedantic`, Windows liên kết `-lshell32`; exit0, không có chẩn đoán compiler. SHA-256 exe thử: `cd303a5cd23199204c34d3aaeaa87407f6bde7ecaad5e628941f320e837676be`. Không đưa exe/runtime vào gói tài liệu.

**25 ca đều đạt các assertion đã viết.** Các fixture là dữ liệu tổng hợp trong thư mục kiểm thử tách riêng. Script kiểm tra trạng thái lưu/byte/thông báo theo ca, dùng timeout; không dùng log cũ làm kết quả chạy mới. [Log và metadata](kiem_chung_runtime.json), [script 24 ca CLI](kiem_chung_cli.py), [script ca khóa tệp Windows](kiem_luu_bi_khoa.py).

Đây là CLI `--plain` và `--check`, có một ca Windows từ chối thay tệp đang bị khóa; chưa kiểm trực tiếp TUI/chuột/IME/font, lỗi cấp phát, các lỗi I/O khác, mất điện, hai tiến trình cùng ghi hoặc tải hàng triệu bản ghi. Không có điểm/hồ sơ học tập nào được tạo. PASS là của ca, không phải chứng nhận toàn bộ325 câu.

<a id="sequential_same_copy"></a>
## sequential_same_copy

Hai người tuần tự xin cùng cuốn: người1 thành công, người2 bị chặn; kiểm trạng thái/lịch sử sau lưu.

**Kết quả:** PASS · **Đường chạy:** CLI --plain + saved-state/byte assertions.

**Câu liên quan:** [TV01](../01_CAU_HOI.md#TV01).

<a id="locked_full_overdue_precedence"></a>
## locked_full_overdue_precedence

Thẻ khóa, đủ3, có quá hạn: kiểm thông báo khóa xuất hiện trước và không thêm lượt.

**Kết quả:** PASS · **Đường chạy:** CLI --plain + saved-state/byte assertions.

**Câu liên quan:** [TV51](../01_CAU_HOI.md#TV51).

<a id="full_before_overdue"></a>
## full_before_overdue

Thẻ hoạt động, đủ3 và quá hạn: kiểm báo đủ3 trước, dữ liệu không thêm.

**Kết quả:** PASS · **Đường chạy:** CLI --plain + saved-state/byte assertions.

**Câu liên quan:** [TV51](../01_CAU_HOI.md#TV51).

<a id="seven_eight_15"></a>
## seven_eight_15

08→15/10 đúng7 ngày: mượn thêm được.

**Kết quả:** PASS · **Đường chạy:** CLI --plain + saved-state/byte assertions.

**Câu liên quan:** [TV04](../01_CAU_HOI.md#TV04).

<a id="seven_eight_16"></a>
## seven_eight_16

08→16/10 đúng8 ngày: mượn thêm bị từ chối.

**Kết quả:** PASS · **Đường chạy:** CLI --plain + saved-state/byte assertions.

**Câu liên quan:** [TV04](../01_CAU_HOI.md#TV04).

<a id="return_then_other_borrow_old_return"></a>
## return_then_other_borrow_old_return

A trả, B mượn lại, A trả lặp không được đóng phiếu củaB.

**Kết quả:** PASS · **Đường chạy:** CLI --plain + saved-state/byte assertions.

**Câu liên quan:** [TV05](../01_CAU_HOI.md#TV05).

<a id="lost_then_return_other"></a>
## lost_then_return_other

Mất một cuốn khóa thẻ; còn được trả cuốn khác, không tự mở lại.

**Kết quả:** PASS · **Đường chạy:** CLI --plain + saved-state/byte assertions.

**Câu liên quan:** [TV06](../01_CAU_HOI.md#TV06), [TH247](../01_CAU_HOI.md#TH247).

<a id="two_identical_day_loans"></a>
## two_identical_day_loans

Hai lần mượn–trả cùng ngày tạo hai node dù trường giống nhau, top tính2.

**Kết quả:** PASS · **Đường chạy:** CLI --plain + saved-state/byte assertions.

**Câu liên quan:** [TH241](../01_CAU_HOI.md#TH241).

<a id="lost_no_reopen"></a>
## lost_no_reopen

Lịch sử mất ngăn mở lại thẻ theo giả định hiện tại.

**Kết quả:** PASS · **Đường chạy:** CLI --plain + saved-state/byte assertions.

**Câu liên quan:** [TV48](../01_CAU_HOI.md#TV48).

<a id="book_and_copies_retry"></a>
## book_and_copies_retry

Thêm lại ISBN bị chặn; thêm cuốn là thao tác riêng có thể tạo cuốn mới.

**Kết quả:** PASS · **Đường chạy:** CLI --plain + saved-state/byte assertions.

**Câu liên quan:** [TH226](../01_CAU_HOI.md#TH226).

<a id="new_legacy_distinct"></a>
## new_legacy_distinct

S001 vàA#1 là hai mã; thêm tiếp cấpA#2.

**Kết quả:** PASS · **Đường chạy:** CLI --plain + saved-state/byte assertions.

**Câu liên quan:** [TH252](../01_CAU_HOI.md#TH252).

<a id="top_twelve_ties"></a>
## top_twelve_ties

12 đầu cùng tên/cùng lượt, top đúng10 theo ISBN.

**Kết quả:** PASS · **Đường chạy:** CLI --plain + saved-state/byte assertions.

**Câu liên quan:** [TH14](../01_CAU_HOI.md#TH14), [TH74](../01_CAU_HOI.md#TH74).

<a id="overdue_partial_return"></a>
## overdue_partial_return

Trả cuốn quá hạn nặng nhất đổi xếp hạng, vẫn bị chặn mượn nếu còn quá hạn.

**Kết quả:** PASS · **Đường chạy:** CLI --plain + saved-state/byte assertions.

**Câu liên quan:** [TH61](../01_CAU_HOI.md#TH61).

<a id="reader_ties_and_readonly"></a>
## reader_ties_and_readonly

Tên hòa so họ rồi mã; báo cáo theo tên giữ byte file cũ khi không lưu.

**Kết quả:** PASS · **Đường chạy:** CLI --plain + saved-state/byte assertions.

**Câu liên quan:** [TN05](../01_CAU_HOI.md#TN05).

<a id="partial_book_cancel"></a>
## partial_book_cancel

Hủy giữa nhập cuốn giữ đầu và cuốn đã commit, không tạo phần còn lại.

**Kết quả:** PASS · **Đường chạy:** CLI --plain + saved-state/byte assertions.

**Câu liên quan:** [TH15](../01_CAU_HOI.md#TH15).

<a id="eof_unsaved"></a>
## eof_unsaved

EOF sau thao tác RAM không tự lưu; file giữ nguyên.

**Kết quả:** PASS · **Đường chạy:** CLI --plain + saved-state/byte assertions.

**Câu liên quan:** [TN56](../01_CAU_HOI.md#TN56).

<a id="delete_keep_highwater"></a>
## delete_keep_highwater

Xóa mã lớn nhất không làm mốc giảm; cấp tiếp dùng mốc+1.

**Kết quả:** PASS · **Đường chạy:** CLI --plain + saved-state/byte assertions.

**Câu liên quan:** [TV08](../01_CAU_HOI.md#TV08).

<a id="leap_seven"></a>
## leap_seven

25/02/2024→03/03/2024 là7 ngày: nhận mượn.

**Kết quả:** PASS · **Đường chạy:** CLI --plain + saved-state/byte assertions.

**Câu liên quan:** [TV04](../01_CAU_HOI.md#TV04), [TV73](../01_CAU_HOI.md#TV73).

<a id="leap_eight"></a>
## leap_eight

25/02/2024→04/03/2024 là8 ngày: chặn mượn.

**Kết quả:** PASS · **Đường chạy:** CLI --plain + saved-state/byte assertions.

**Câu liên quan:** [TV04](../01_CAU_HOI.md#TV04), [TV73](../01_CAU_HOI.md#TV73).

<a id="four_overlap"></a>
## four_overlap

Bốn khoảng giữ chồng nhau bị --check từ chối dù đều đã trả.

**Kết quả:** PASS · **Đường chạy:** --check expected accept/reject.

**Câu liên quan:** [TV11](../01_CAU_HOI.md#TV11).

<a id="four_same_day"></a>
## four_same_day

Bốn lượt mượn–trả cùng ngày có thứ tự khả thi được --check nhận.

**Kết quả:** PASS · **Đường chạy:** --check expected accept/reject.

**Câu liên quan:** [TV11](../01_CAU_HOI.md#TV11).

<a id="load_failure_keeps_ram"></a>
## load_failure_keeps_ram

File đứt trong danh mục bị từ chối; RAM đã thêm người trước đó còn để lưu.

**Kết quả:** PASS · **Đường chạy:** truncated file, CLI load failure then save RAM.

**Câu liên quan:** [GH03](../01_CAU_HOI.md#GH03), [TH209](../01_CAU_HOI.md#TH209).

<a id="load_success_switches_destination"></a>
## load_success_switches_destination

NAP thành công thay RAM/đích lưu; file gốc không bị ghi trong lần lưu sau.

**Kết quả:** PASS · **Đường chạy:** CLI load then save destination.

**Câu liên quan:** [TN73](../01_CAU_HOI.md#TN73).

<a id="startup_invalid_no_overwrite"></a>
## startup_invalid_no_overwrite

File tồn tại nhưng mâu thuẫn trạng thái bị chặn trước menu, exit2, byte không đổi.

**Kết quả:** PASS · **Đường chạy:** startup failure code2 and original file bytes.

**Câu liên quan:** [TN75](../01_CAU_HOI.md#TN75), [GH04](../01_CAU_HOI.md#GH04).

<a id="save_locked_keeps_ram_file"></a>
## save_locked_keeps_ram_file

Khóa tệp đích bằng handle Windows không cho chia sẻ ghi/xóa. Sau khi thêm độc giả21, chọn lưu/thoát bị từ chối thay tệp; vẫn trở lại menu và báo cáo được độc giả21 trong RAM. THOAT kết thúc không lưu, byte tệp cũ giữ nguyên và thư mục lưu tạm được dọn. Đây là một lỗi thay tệp cụ thể, không đại diện mọi lỗi I/O.

**Kết quả:** PASS · **Đường chạy:** Windows CreateFileW read share without delete/write; CLI save exit denied then report RAM and exit without saving.

**Câu liên quan:** [GH05](../01_CAU_HOI.md#GH05), [TN100](../01_CAU_HOI.md#TN100).

