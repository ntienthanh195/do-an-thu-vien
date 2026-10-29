#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <stdexcept>
using namespace std;

/*HẰNG SỐ*/
const int NAM_HIEN_TAI = 2026;
// Số đầu sách tối đa. Đề chưa quy định, đây là đề xuất của nhóm.
const int MAX_DAU_SACH = 10000;
// Trạng thái cuốn sách
const int SACH_CHO_MUON  = 0; // cho mượn được
const int SACH_DANG_MUON = 1; // đang được mượn
const int SACH_THANH_LY  = 2; // đã thanh lý

// Trạng thái mượn trả
const int MUON_DANG_MUON = 0; // đang mượn
const int MUON_DA_TRA    = 1; // đã trả
const int MUON_LAM_MAT   = 2; // làm mất

// Trạng thái thẻ độc giả
const int THE_BI_KHOA    = 0; // thẻ bị khóa
const int THE_HOAT_DONG  = 1; // thẻ đang hoạt động

/*NGÀY THÁNG*/ 

struct NgayThang
{
    int ngay = 0;
    int thang = 0;
    int nam = 0;
};

/*CUỐN SÁCH*/
// Mỗi cuốn sách là một nút trong danh sách liên kết đơn

struct CuonSach
{
    string maSach;                         // mã cuốn sách, duy nhất
    int trangThai = SACH_CHO_MUON;        // 0: cho mượn, 1: đang mượn, 2: thanh lý
    string viTri;                          // vị trí để sách
    CuonSach* next = nullptr;              // con trỏ tới cuốn sách kế tiếp
};

/*ĐẦU SÁCH*/
// Một đầu sách có thể có nhiều cuốn sách

struct DauSach
{
    string ISBN;
    string tenSach;
    int soTrang = 0;
    string tacGia;
    int namXuatBan = 0;
    string theLoai;

    CuonSach* dms = nullptr;               // danh mục các cuốn sách thuộc đầu sách này
};


/*DANH SÁCH ĐẦU SÁCH*/
// Đề yêu cầu: danh sách tuyến tính là mảng con trỏ
// Danh sách phải luôn tăng dần theo tên sách
// Thứ tự này sẽ được duy trì trong hàm thêm/sắp xếp

struct DanhSachDauSach
{
    DauSach* ds[MAX_DAU_SACH];          // mảng con trỏ chứa các đầu sách
    int soLuong;                           // số đầu sách đang có

    // Khởi tạo danh sách rỗng
    DanhSachDauSach()
    {
        soLuong = 0;

        for (int i = 0; i < MAX_DAU_SACH; ++i)
        {
            ds[i] = nullptr;
        }
    }
};


/*MƯỢN TRẢ*/
// Mỗi lần mượn/trả là một nút trong danh sách liên kết đơn

struct MuonTra
{
    string maSach;                         // mã cuốn sách được mượn
    NgayThang ngayMuon;                    // ngày mượn
    NgayThang ngayTra;                     // 0/0/0 nghĩa là chưa trả
    int trangThai = MUON_DANG_MUON;       // 0: đang mượn, 1: đã trả, 2: làm mất
    MuonTra* next = nullptr;               // con trỏ tới lần mượn kế tiếp
};


/*ĐỘC GIẢ*/

struct DocGia
{
    int maThe = 0;                         // mã thẻ độc giả, số nguyên tự động
    string ho;
    string ten;
    string phai;                           // chỉ nhận "Nam" hoặc "Nữ"
    int trangThaiThe = THE_HOAT_DONG;     // 0: khóa, 1: hoạt động

    MuonTra* dsMuonTra = nullptr;          // danh sách các lần mượn trả của độc giả
};


/*NÚT CÂY ĐỘC GIẢ*/
// Đề yêu cầu: cây nhị phân tìm kiếm theo mã thẻ

struct NutDocGia
{
    DocGia thongTin;                       // thông tin độc giả
    NutDocGia* left = nullptr;             // cây con trái
    NutDocGia* right = nullptr;            // cây con phải
};

/*CÂY ĐỘC GIẢ*/

struct CayDocGia
{
    NutDocGia* root = nullptr;             // gốc cây, nullptr nghĩa là cây rỗng
};


/*QUẢN LÝ CHUNG*/
// Dùng trong main để tránh biến toàn cục

struct ThuVien
{
    DanhSachDauSach dsDauSach;
    CayDocGia cayDocGia;
};
