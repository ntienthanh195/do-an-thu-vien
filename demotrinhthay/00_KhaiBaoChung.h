#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>
using namespace std;

/*HẰNG SỐ*/
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
    NgayThang(int d = 0, int m = 0, int y = 0) : ngay(d), thang(m), nam(y) {}
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
    int maTheLonNhatDaCap = 0; // metadata v1: khong tai su dung ma da xoa
    // ThuVien so huu cac node: khong sao chep nguyen kho bang phep gan.
    ThuVien() = default;
    ~ThuVien();
    ThuVien(const ThuVien &) = delete;
    ThuVien &operator=(const ThuVien &) = delete;
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

// [DEMO - CODEX] Phan bo sung cho ban trinh thay.
const DWORD CHE_DO_MAU_CONSOLE = 0x0004;

const int SO_NGUYEN_LON_NHAT = 2147483647;
const int MAX_DOC_GIA = 100000; // gioi han tai nguyen cua ban demo
const int MAX_BAN_GHI = 200000;


bool ChuaChuoi(const string &s, const string &part);

bool DocSoNguyen(const string &s, int &value, int lo = 0, int hi = 2147483647);
bool TachTruong(const string &line, string *out, int count);

bool NgayRong(const NgayThang &d);
bool DocNgay(const string &s, NgayThang &d);
string ChuoiNgay(const NgayThang &d);
int SoThuTuNgay(const NgayThang &d);                        // chi goi voi ngay hop le

NgayThang HomNay();

// 02: mang con tro dau sach. Ket qua tim kiem la con tro muon, khong delete.

DauSach *TimDauSachTheoISBN(DanhSachDauSach &ds, const string &isbn);

void TimDauSachTheoTen(const ThuVien &tv, const string &ten, ostream &out);
void InDanhSachDauSach(const ThuVien &tv, ostream &out);
void InDauSachTheoTheLoai(const ThuVien &tv, ostream &out);
void HuyDanhSachDauSach(DanhSachDauSach &ds);
void ManHinhNhapDauSach(ThuVien &tv);
void ManHinhTimSach(const ThuVien &tv);

// 03: danh muc cuon; ISBN#so cho ma moi, S001... cu van tra duoc.
CuonSach *TimCuonSachTrongDauSach(DauSach &d, const string &ma);
const CuonSach *TimCuonSachTrongDauSach(const DauSach &d, const string &ma);
CuonSach *TimCuonSachToanCuc(ThuVien &tv, const string &ma, DauSach **owner = nullptr);
const CuonSach *TimCuonSachToanCuc(const ThuVien &tv, const string &ma,
                                   const DauSach **owner = nullptr);
bool SinhMaSachTuDong(const ThuVien &tv, const DauSach &d, string &ma, string &loi);
bool ThemCuonSach(ThuVien &tv, const string &isbn, const string &viTri, string &ma, string &loi);
void HuyDanhMucCuonSach(CuonSach *&head);
int DemCuonSach(const CuonSach *head);

// a, b: AVL theo ma the; mang con tro tam chi la view, khong doi BST.
NutDocGia *TimDocGia(CayDocGia &tree, int ma);
const NutDocGia *TimDocGia(const CayDocGia &tree, int ma);
int DemDocGia(const CayDocGia &tree);
int LayDanhSachDocGia(const CayDocGia &tree, const NutDocGia **out, int capacity);
bool ChenDocGiaCoMa(CayDocGia &tree, const DocGia &dg, string &loi); // them vao cay AVL
bool ThemDocGia(ThuVien &tv, const string &ho, const string &ten, const string &phai, int &ma,
                string &loi);
bool HieuChinhDocGia(ThuVien &tv, int ma, const string &ho, const string &ten, const string &phai,
                     int tt, string &loi);
bool XoaDocGia(ThuVien &tv, int ma, string &loi);

void InDocGiaTheoMa(const ThuVien &tv, ostream &out);
void InDocGiaTheoTenHo(const ThuVien &tv, ostream &out);
void ManHinhDocGia(ThuVien &tv);

// 05: lich su + phep doc; nghiep vu cap nhat dong bo nam o 06.
int DemLichSu(const MuonTra *p);

void LietKeSachDangMuon(const ThuVien &tv, int maThe, ostream &out);

// 06: giao dich muon/tra/mat va thong ke chi doc.
bool MuonSach(ThuVien &tv, int maThe, const string &maSach, const NgayThang &ngay, string &loi);
bool TraSach(ThuVien &tv, int maThe, const string &maSach, const NgayThang &ngay, string &loi);
bool DanhDauMatSach(ThuVien &tv, int maThe, const string &maSach, const NgayThang &ngay,
                    string &loi);
void InDocGiaQuaHan(const ThuVien &tv, const NgayThang &ngay, ostream &out);
void InTop10SachDuocMuonNhieuNhat(const ThuVien &tv, ostream &out);
void ManHinhMuonTra(ThuVien &tv, const NgayThang &ngay, bool tra);

// 07: dung du lieu tam, xac minh toan ven roi moi hoan doi; save temp + replace.
bool KiemTraToanVen(const ThuVien &tv, string &loi);
bool DocFile(ThuVien &tv, const string &path, string &loi);
bool LuuFile(const ThuVien &tv, const string &path, string &loi);
void HuyThuVien(ThuVien &tv);
void HoanDoiThuVien(ThuVien &a, ThuVien &b);

// 08: helper UI dung chung. /huy hoac Esc de huy nhap; EOF thoat an toan.
bool DangDungGiaoDienHeThong();
bool NhapBieuMau(const string &title, const char *const *labels, string *values, int count);
bool NhapDong(const string &prompt, string &s);
bool NhapSo(const string &prompt, int &n, int lo, int hi);
int ChonMenu(const string &title, const char *const *labels, int count);
void ThongBao(const string &s);
void HienThiPhanTrang(const string &text);

// Chi cac man hinh goi sau commit; API nghiep vu khong tu ghi file.
void LuuSauThayDoi(const ThuVien &tv);

class LoiThuVien
{
    string noiDung;

  public:
    explicit LoiThuVien(const string &s) : noiDung(s)
    {
    }
    const char *what() const
    {
        return noiDung.c_str();
    }
};

wstring DuongDanUTF16(const string &s);
string DuongDanUTF8(const wstring &s);
wstring DuongDanDayDu(const string &path);
wstring ThuMucCha(const wstring &path);
bool FileTonTai(const string &path);
void TaoThuMuc(wstring path);
int DocDoiSoWindows(const wstring &command, string *out);
bool KiemTraVanBanHeThong(const string &s);

string ChuoiSo(long long so);
wstring ChuoiSoRong(long long so);
template <class Chuoi>
Chuoi CatChuoi(const Chuoi &s, size_t viTri, size_t soKyTu = Chuoi::npos)
{
    Chuoi ketQua;
    for (size_t i = viTri; i < s.size() && i - viTri < soKyTu; ++i)
        ketQua += s[i];
    return ketQua;
}
bool KiemTraNgayThaoTac(const NgayThang &ngay, string &loi);
bool KiemTraLichSuGiaoDich(const ThuVien &tv, int maThe, const string &maCuon,
                           const NgayThang &ngay, int &soDangMuon, int &tongLuot, string &loi);
void InThongTinDauSach(const DauSach &sach, ostream &out, bool inCuon);
int ChonChucNang(const NgayThang &ngay, const string &path);
void ChayChucNang(int choice, ThuVien &tv, const NgayThang &ngay);
int KhoiDongUngDung();
int SoNgayQuaHan(const NgayThang &ngayMuon, const NgayThang &ngayXet);
