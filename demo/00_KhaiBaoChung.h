#pragma once

#include <climits>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>
using namespace std;


// So dau sach toi da
const int MAX_DAU_SACH = 10000;

// Trang thai cuon sach
const int SACH_CHO_MUON  = 0; // cho muon duoc
const int SACH_DANG_MUON = 1; // dang duoc muon
const int SACH_THANH_LY  = 2; // da thanh ly

// Trang thai muon tra
const int MUON_DANG_MUON = 0; // dang muon
const int MUON_DA_TRA    = 1; // da tra
const int MUON_LAM_MAT   = 2; // lam mat

// Trang thai the doc gia
const int THE_BI_KHOA    = 0; // the bi khoa
const int THE_HOAT_DONG  = 1; // the dang hoat dong

const int MAX_DOC_GIA = 100000;
const int MAX_BAN_GHI = 200000;

/*NGAY THANG*/

struct NgayThang
{
    NgayThang() = default;
    NgayThang(int d, int m, int y) : ngay(d), thang(m), nam(y) {}
    int ngay = 0;
    int thang = 0;
    int nam = 0;
};

/*CUON SACH*/
// Moi cuon sach la mot nut trong danh sach lien ket don

struct CuonSach
{
    string maSach;                         // ma cuon sach, duy nhat
    int trangThai = SACH_CHO_MUON;        // 0: cho muon, 1: dang muon, 2: thanh ly
    string viTri;                          // vi tri de sach
    CuonSach* next = nullptr;              // con tro toi cuon sach ke tiep
};

/*DAU SACH*/
// Mot dau sach co the co nhieu cuon sach

struct DauSach
{
    string ISBN;
    string tenSach;
    int soTrang = 0;
    string tacGia;
    int namXuatBan = 0;
    string theLoai;

    CuonSach* dms = nullptr;               // danh muc cac cuon sach thuoc dau sach nay
};

/*DANH SACH DAU SACH*/
// De yeu cau: danh sach tuyen tinh la mang con tro
// Danh sach phai luon tang dan theo ten sach
// Thu tu nay se duoc duy tri trong ham them/sap xep

struct DanhSachDauSach
{
    DauSach* ds[MAX_DAU_SACH];          // mang con tro chua cac dau sach
    int soLuong;                           // so dau sach dang co

    // Khoi tao danh sach rong
    DanhSachDauSach()
    {
        soLuong = 0;

        for (int i = 0; i < MAX_DAU_SACH; ++i)
        {
            ds[i] = nullptr;
        }
    }
};

/*MUON TRA*/
// Moi lan muon/tra la mot nut trong danh sach lien ket don

struct MuonTra
{
    string maSach;                         // ma cuon sach duoc muon
    NgayThang ngayMuon;                    // ngay muon
    NgayThang ngayTra;                     // 0/0/0 nghia la chua tra
    int trangThai = MUON_DANG_MUON;       // 0: dang muon, 1: da tra, 2: lam mat
    MuonTra* next = nullptr;               // con tro toi lan muon ke tiep
};

/*DOC GIA*/

struct DocGia
{
    int maThe = 0;                         // ma the doc gia, so nguyen tu dong
    string ho;
    string ten;
    string phai;                           // chi nhan "Nam" hoac "Nu"
    int trangThaiThe = THE_HOAT_DONG;     // 0: khoa, 1: hoat dong

    MuonTra* dsMuonTra = nullptr;          // danh sach cac lan muon tra cua doc gia
};

/*NUT CAY DOC GIA*/
// De yeu cau: cay nhi phan tim kiem theo ma the

struct NutDocGia
{
    DocGia thongTin;                       // thong tin doc gia
    NutDocGia* left = nullptr;             // cay con trai
    NutDocGia* right = nullptr;            // cay con phai
    int height = 1; // [THANH] Chieu cao cua nut la trong cay AVL.
};

/*CAY DOC GIA*/

struct CayDocGia
{
    NutDocGia* root = nullptr;             // goc cay, nullptr nghia la cay rong
};

/*QUAN LY CHUNG*/
// Dung trong main de tranh bien toan cuc

struct ThuVien
{
    DanhSachDauSach dsDauSach;
    CayDocGia cayDocGia;
    int maTheLonNhatDaCap = 0;

    // ThuVien so huu cac node: khong sao chep nguyen kho bang phep gan.
    ThuVien() = default;
    ~ThuVien();
    ThuVien(const ThuVien &) = delete;
    ThuVien &operator=(const ThuVien &) = delete;
};

struct Phim
{
    WORD ma = 0;
    wchar_t chu = 0;
    bool shift = false, ctrl = false, click = false, resize = false;
    int x = 0, y = 0;
};
struct MauGiaoDien
{
    WORD NEN, MO, NHAN, THANH, CHON, O_NHAP, VIEN, NUT_CHINH, O_DANG_NHAP;
    DWORD cheDoMauConsole;
    COLORREF bangMauUI[16];
};

struct GiaoDien
{
    const ThuVien &thuVien;
    string &duongDan;
    NgayThang &ngay;
    const MauGiaoDien &mau;
    const wchar_t *const *dieuHuong;
    const wchar_t *const *moTa;
    bool giaoDienPhim = false, xuatRGB = false, chuaLuu = false;
    int mucUI = 0;
    string tieuDeUI = "Tong quan";
    DWORD nutTruoc = 0;
    Phim phimLap;
    WORD conLai = 0;

    GiaoDien(const ThuVien &tv, string &tep, NgayThang &ngayPhien, const MauGiaoDien &bangMau,
             const wchar_t *const *cacMuc, const wchar_t *const *moTaMuc)
        : thuVien(tv), duongDan(tep), ngay(ngayPhien), mau(bangMau),
          dieuHuong(cacMuc), moTa(moTaMuc) {}
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
bool ChuaChuoi(const string &s, const string &part);

bool DocSoNguyen(const string &s, int &value, int lo, int hi);
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
void ManHinhNhapDauSach(GiaoDien &gd, ThuVien &tv);
void ManHinhTimSach(GiaoDien &gd, const ThuVien &tv);

// 03: danh muc cuon; ISBN#so cho ma moi, S001... cu van tra duoc.
CuonSach *TimCuonSachTrongDauSach(DauSach &d, const string &ma);
const CuonSach *TimCuonSachTrongDauSach(const DauSach &d, const string &ma);
CuonSach *TimCuonSachToanCuc(ThuVien &tv, const string &ma, DauSach **owner);
const CuonSach *TimCuonSachToanCuc(const ThuVien &tv, const string &ma,
                                   const DauSach **owner);
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
int ChonMaTheDocGia(GiaoDien &gd, const CayDocGia &cay, const string &tieuDe);
bool KiemTraDocGiaMuon(ThuVien &tv, int maThe, const NgayThang &ngay, string &loi);
bool ChonCuonDeMuon(GiaoDien &gd, const ThuVien &tv, int maThe,
                    const string &thongBao, bool choMuon,
                    const string &lyDoDung, string &maCuon);
void ManHinhDocGia(GiaoDien &gd, ThuVien &tv);

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
void ManHinhMuonTra(GiaoDien &gd, ThuVien &tv, const NgayThang &ngay, bool tra);
int ChonCuonDeTra(GiaoDien &gd, const ThuVien &tv, int maThe,
                  const string &thongBao, string &maCuon);

// 07: dung du lieu tam, xac minh toan ven roi moi hoan doi; save temp + replace.
bool KiemTraToanVen(const ThuVien &tv, string &loi);
bool DocFile(ThuVien &tv, const string &path, string &loi);
bool LuuFile(const ThuVien &tv, const string &path, string &loi);
void HuyThuVien(ThuVien &tv);
void HoanDoiThuVien(ThuVien &a, ThuVien &b);

// 08: helper UI dung chung. /huy hoac Esc de huy nhap; EOF thoat an toan.
bool DangDungGiaoDienHeThong(GiaoDien &gd);
bool NhapBieuMau(GiaoDien &gd, const string &title, const char *const *labels, string *values, int count);
bool NhapBieuMauLienTiep(GiaoDien &gd, const string &title, const char *const *labels,
                        string *values, int count, const string &thongBao);
bool NhapDong(GiaoDien &gd, const string &prompt, string &s);
bool NhapSo(GiaoDien &gd, const string &prompt, int &n, int lo, int hi);
int ChonMenu(GiaoDien &gd, const string &title, const char *const *labels, int count);
void ThongBao(GiaoDien &gd, const string &s);
void HienThiPhanTrang(GiaoDien &gd, const string &text);

// Chi cac man hinh goi sau commit; API nghiep vu khong tu ghi file.
void LuuSauThayDoi(GiaoDien &gd, const ThuVien &tv);

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
Chuoi CatChuoi(const Chuoi &s, size_t viTri, size_t soKyTu)
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
int ChonChucNang(GiaoDien &gd, const NgayThang &ngay, const string &path);
void ChayChucNang(GiaoDien &gd, int choice, ThuVien &tv, const NgayThang &ngay);
int KhoiDongUngDung(GiaoDien &gd, ThuVien &tv);
int SoNgayQuaHan(const NgayThang &ngayMuon, const NgayThang &ngayXet);
