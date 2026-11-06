#pragma once

#include <iosfwd>
#include <string>
using namespace std;

/*HẰNG SỐ*/
// Năm hiện tại
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
    int height = 1; // [THANH] Chieu cao cua nut la trong cay AVL.
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


// Khai bao cac ham da co noi dung trong MaNguonUpdate.
bool LaChuoiRong(const string& s);
bool LaNamHopLe(int nam);
string ChuanHoaChuoi(string s);
bool HopLePhai(const string& phai);
bool HopLeTrangThaiSach(int trangThai);
bool HopLeTrangThaiMuonTra(int trangThai);
bool HopLeTrangThaiThe(int trangThai);

// ChuanHoaChuoiSach gop khoang trang va giu hoa/thuong theo ban Thai.
string ChuanHoaChuoiSach(const string& s);
int SoSanhChuoi(const string& a, const string& b);
bool HopLeVanBan(const string& s);
string ChuanHoaISBN(const string& isbn);

bool HopLeTenSach(const string& s);
bool HopLeDauSach(const DauSach& d, string& loi);
const DauSach* TimDauSachTheoISBN(const DanhSachDauSach& ds, const string& isbn);
int TimViTriChenTheoTen(const DanhSachDauSach& ds, const DauSach& d);
bool ThemDauSach(ThuVien& tv, const DauSach& d, string& loi);
bool HopLeCuonSach(const CuonSach& s, string& loi);

// [THANH] Khai bao 15 ham tu ban Thanh gui ngay 01/11/2026.
NutDocGia* tim_cay(CayDocGia &caydocgia, int x);
void them_cay(CayDocGia &caydocgia, const DocGia &docGiaMoi);
void Huydocgia(NutDocGia* &nutdocgia);
void HuyCayDocGia(CayDocGia &caydocgia);
void them_lich_su(NutDocGia &q, MuonTra muontra);
int Dem_so_sach_dang_muon(NutDocGia &q);
MuonTra* TimMuonDangMuonTheoMa(NutDocGia &q,string maSach);
bool CoSachQuaHan7Ngay(const NutDocGia &docgia, NgayThang ngayktra);
bool CapNhatLuotTra(const NutDocGia &docgia,string masach, NgayThang ngaytrasach );
void HuyDanhSachMuonTra(NutDocGia &docgia);
bool NamNhuan(int nam);
int SoNgayTrongThang(int thang, int nam);
bool NgayHopLe(const NgayThang &ngay);
long long Doirangay(NgayThang sngay);
long long KhoangCachNgay(NgayThang ngayt1, NgayThang ngayt2);

// [THANH] Quan ly the doc gia.
bool HieuChinhDocGia(CayDocGia &caydocgia, int mathe, string Ho, string Ten, string Phai, int trangthaiThe);
int SinhMaTheTiepTheo(int &maTheDaCap);
void XoaDocGia(CayDocGia &caydocgia, int mathe);

// [THAI] Cac ham tu chuc nang c, e va phan ho tro j (be7fa70).
bool KhoangTrang(unsigned char c);
void ManHinhNhapDauSach(ThuVien &tv);
const CuonSach *TimCuonSachTrongDauSach(const DauSach &d, const string &ma);
const CuonSach *TimCuonSachToanCuc(const ThuVien &tv, const string &ma, const DauSach **owner);
bool SinhMaSachTuDong(const ThuVien &tv, const DauSach &d, string &ma, string &loi);
bool ChuaChuoi(const string &s, const string &part);
void TimDauSachTheoTen(const ThuVien &tv, const string &ten, ostream &out);
int DemCuonSach(const CuonSach *head);
int DemDocGia(const CayDocGia &tree);
int LayDanhSachDocGia(const CayDocGia &tree, const NutDocGia **out, int capacity);
