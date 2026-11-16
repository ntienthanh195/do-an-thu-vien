#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
using namespace std;

const int SO_NGUYEN_LON_NHAT = 2147483647;
const int NAM_HIEN_TAI = 2026;
const int MAX_DAU_SACH = 10000;
const int MAX_DOC_GIA = 100000; 
const int MAX_BAN_GHI = 200000;
const int SACH_CHO_MUON = 0, SACH_DANG_MUON = 1, SACH_THANH_LY = 2;
const int MUON_DANG_MUON = 0, MUON_DA_TRA = 1, MUON_LAM_MAT = 2;
const int THE_BI_KHOA = 0, THE_HOAT_DONG = 1;
struct NgayThang
{
    int ngay, thang, nam;
    NgayThang(int d = 0, int m = 0, int y = 0)
    {
        ngay = d;
        thang = m;
        nam = y;
    }
};
// viTri = Khu-Ke-Tang ( trong do Khu trong khoang (A...Z), ke (01...99), tang (01...99) 
// vi du : A-03-02
struct CuonSach
{
    string maSach;  // maSach = tenSach#ISBN#N
    int trangThai = SACH_CHO_MUON;
    string viTri;
    CuonSach *next = nullptr;
};
// quy uoc : ISBN-13 = chuoi ky tu 13 chu so
struct DauSach
{
    string ISBN, tenSach;   // ISBN = ISBN-13 (chuoi ky tu 13 so tu 0-9)
    int soTrang = 0;
    string tacGia;
    int namXuatBan = 0;
    string theLoai;
    CuonSach *dms = nullptr;
};
struct DanhSachDauSach
{
    DauSach *ds[MAX_DAU_SACH]{};
    int soLuong = 0;
};
struct MuonTra
{
    string maSach;
    NgayThang ngayMuon, ngayTra;
    int trangThai = MUON_DANG_MUON;
    MuonTra *next = nullptr;
};
struct DocGia
{
    int maThe = 0;
    string ho, ten, phai;
    int trangThaiThe = THE_HOAT_DONG;
    MuonTra *dsMuonTra = nullptr;
};
struct NutDocGia
{
    DocGia thongTin;
    NutDocGia *left = nullptr;
    NutDocGia *right = nullptr;
};
struct CayDocGia
{
    NutDocGia *root = nullptr;
};
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

// 01: chuoi, ngay, nhap chuan; khong tinh thong ke nghiep vu o day.
bool KhoangTrang(unsigned char c);
bool LaChuoiRong(const string &s);
string ChuanHoaChuoi(const string &s);
string KhoaSoSanh(const string &s); // ha ASCII; giu nguyen byte UTF-8 co dau
int SoSanhChuoi(const string &a, const string &b);
bool ChuaChuoi(const string &s, const string &part);
bool HopLeVanBan(const string &s);
bool DocSoNguyen(const string &s, int &value, int lo = 0, int hi = 2147483647);
bool TachTruong(const string &line, string *out, int count);
bool NamNhuan(int year);
bool NgayHopLe(const NgayThang &d);
bool NgayRong(const NgayThang &d);
bool DocNgay(const string &s, NgayThang &d);
string ChuoiNgay(const NgayThang &d);
int SoThuTuNgay(const NgayThang &d);                        // chi goi voi ngay hop le
int KhoangCachNgay(const NgayThang &a, const NgayThang &b); // b-a
NgayThang HomNay();
bool QuaHan7Ngay(const NgayThang &ngayMuon, const NgayThang &now);
bool HopLePhai(const string &s);
bool HopLeTrangThaiThe(int x);
bool HopLeTrangThaiSach(int x);
bool HopLeTrangThaiMuonTra(int x);

// 02: mang con tro dau sach. Ket qua tim kiem la con tro muon, khong delete.
bool HopLeDauSach(const DauSach &d, string &loi);
bool HopLeCuonSach(const CuonSach &s, string &loi);
int TimViTriChenTheoTen(const DanhSachDauSach &ds, const DauSach &d);
DauSach *TimDauSachTheoISBN(DanhSachDauSach &ds, const string &isbn);
const DauSach *TimDauSachTheoISBN(const DanhSachDauSach &ds, const string &isbn);
bool ThemDauSach(ThuVien &tv, const DauSach &d, string &loi);
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

// 04: BST theo ma the; mang con tro tam chi la view, khong doi BST.
NutDocGia *TimDocGia(CayDocGia &tree, int ma);
const NutDocGia *TimDocGia(const CayDocGia &tree, int ma);
int DemDocGia(const CayDocGia &tree);
int LayDanhSachDocGia(const CayDocGia &tree, const NutDocGia **out, int capacity);
bool ChenDocGiaCoMa(CayDocGia &tree, const DocGia &dg, string &loi); // chi bo doc file
bool ThemDocGia(ThuVien &tv, const string &ho, const string &ten, const string &phai, int &ma,
                string &loi);
bool HieuChinhDocGia(ThuVien &tv, int ma, const string &ho, const string &ten, const string &phai,
                     int tt, string &loi);
bool XoaDocGia(ThuVien &tv, int ma, string &loi);
void HuyCayDocGia(CayDocGia &tree);
void InDocGiaTheoMa(const ThuVien &tv, ostream &out);
void InDocGiaTheoTenHo(const ThuVien &tv, ostream &out);
void ManHinhDocGia(ThuVien &tv);

// 05: lich su + phep doc; nghiep vu cap nhat dong bo nam o 06.
int DemLichSu(const MuonTra *p);
int DemSoSachDangMuon(const DocGia &dg);
bool CoSachQuaHan7Ngay(const DocGia &dg, const NgayThang &now);
MuonTra *TimMuonDangMuonTheoMa(DocGia &dg, const string &ma);
void HuyDanhSachMuonTra(MuonTra *&head);
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
