#ifndef KHAI_BAO_CHUNG_H
#define KHAI_BAO_CHUNG_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/* ===================== HANG SO ===================== */

const int MAX_DAU_SACH  = 10000; // suc chua cua mang con tro dau sach
const int MAX_SACH_MUON = 3;     // de: moi doc gia muon toi da 3 cuon
const int HAN_MUON      = 7;     // de: qua han 7 ngay (khoang cach ngay >= 7 la qua han)

// Trang thai cuon sach (theo de)
const int SACH_CHO_MUON  = 0;
const int SACH_DANG_MUON = 1;
const int SACH_THANH_LY  = 2;

// Trang thai muon tra (theo de)
const int MUON_DANG_MUON = 0;
const int MUON_DA_TRA    = 1;
const int MUON_LAM_MAT   = 2;

// Trang thai the doc gia (theo de)
const int THE_BI_KHOA   = 0;
const int THE_HOAT_DONG = 1;

// Ten file du lieu
const char FILE_DU_LIEU[] = "DuLieu/ThuVien.txt";
// Ban sao du lieu, ghi lai moi lan mo chuong trinh va doc file thanh cong
const char FILE_SAO_LUU[] = "DuLieu/ThuVien_BanTruoc.txt";

/* ============ CAU TRUC DU LIEU (DUNG THEO DE) ============ */

// Kieu ngay cho hai truong NgayMuon, NgayTra cua de
struct NgayThang
{
    int ngay = 0;
    int thang = 0;
    int nam = 0;
};

// Danh muc sach: danh sach lien ket don (Ma sach, trang thai, vi tri)
struct CuonSach
{
    string maSach;                 // dang ISBN#N, duy nhat
    int trangThai = SACH_CHO_MUON;
    string viTri;
    CuonSach *next = nullptr;
};

// Dau sach (ISBN, Ten sach, So trang, Tac gia, nam xuat ban, the loai, con tro dms)
struct DauSach
{
    string ISBN;
    string tenSach;
    int soTrang = 0;
    string tacGia;
    int namXuatBan = 0;
    string theLoai;
    CuonSach *dms = nullptr;
};

// Danh sach dau sach: danh sach tuyen tinh la mang con tro, tang dan theo ten sach
struct DanhSachDauSach
{
    DauSach *ds[MAX_DAU_SACH];
    int soLuong = 0;
};

// Danh sach MUONTRA: danh sach lien ket don (MASACH, NgayMuon, NgayTra, trang thai)
struct MuonTra
{
    string maSach;
    NgayThang ngayMuon;
    NgayThang ngayTra;             // 0/0/0 nghia la chua tra
    int trangThai = MUON_DANG_MUON;
    MuonTra *next = nullptr;
};

// The doc gia (MATHE, Ho, Ten, Phai, trang thai the, con tro)
struct DocGia
{
    int maThe = 0;
    string ho;
    string ten;
    string phai;                   // "Nam" hoac "Nu"
    int trangThaiThe = THE_HOAT_DONG;
    MuonTra *dsMuonTra = nullptr;
};

// Nut cua cay nhi phan tim kiem, khoa la ma the
struct NutDocGia
{
    DocGia thongTin;
    NutDocGia *left = nullptr;
    NutDocGia *right = nullptr;
    int height = 1; // [THANH] chieu cao cua nut, dung de can bang cay theo AVL (truong them ngoai de)
};

// Cay doc gia chi la con tro toi nut goc, khong phai struct moi
typedef NutDocGia *CayDocGia;

/* ===================== MA PHIM, MA MAU ===================== */

// Phim thuong: _getch() tra ve ma ASCII.
// Phim mui ten: _getch() tra ve 0 hoac 224 roi moi tra ve ma phim,
// ham DocPhim cong them 256 de khong trung voi ky tu thuong.
const int PHIM_ENTER = 13;
const int PHIM_ESC   = 27;
const int PHIM_XOA   = 8;
const int PHIM_LEN   = 256 + 72;
const int PHIM_XUONG = 256 + 80;
const int PHIM_TRAI  = 256 + 75;
const int PHIM_PHAI  = 256 + 77;

// Ma mau cua chuong trinh. Moi ma ung voi mot mau RGB trong BANG_MAU (GiaoDien.cpp),
// ham SetColor(mauChu, mauNen) doi ma mau thanh mau that tren man hinh.
const int MAU_DEN          = 0;  // nen chinh cua vung noi dung (xanh den)
const int MAU_NEN_MENU     = 1;  // nen thanh menu ben trai
const int MAU_NEN_CHON     = 2;  // nen cua muc menu dang chon
const int MAU_NEN_O        = 3;  // nen o so lieu, dong xen ke cua bang
const int MAU_TRANG        = 7;  // chu thuong
const int MAU_XAM          = 8;  // chu mo: nhan, huong dan phim
const int MAU_XANH_LA_SANG = 10; // thanh cong, trang thai tot
const int MAU_NGOC_SANG    = 11; // mau nhan chinh (xanh bac ha)
const int MAU_DO_SANG      = 12; // loi, qua han, bi khoa
const int MAU_VANG_SANG    = 14; // tieu de cot, canh bao
const int MAU_TRANG_SANG   = 15; // chu noi bat

// Bo cuc man hinh: cua so console 120 cot x 30 dong, chia lam hai vung.
//   - Thanh menu ben trai, rong RONG_MENU cot, luon hien cac chuc nang (nhu thanh dieu huong cua web).
//   - Vung noi dung ben phai, rong RONG_MH cot. Moi ham in noi dung (InTai, InCot, XoaVung, VeKhung)
//     tinh toa do x tu mep trai cua vung noi dung, nen cac man hinh khong can biet thanh menu rong bao nhieu.
const int RONG_MENU      = 24;
const int RONG_MH        = 96;
const int SO_MUC_MENU    = 12; // Tong quan, 10 chuc nang a..j, Thoat
const int DONG_THONG_BAO = 26;
const int DONG_HUONG_DAN = 28;
const int SO_DONG_TRANG  = 15; // so dong du lieu tren mot trang bang

/* ===================== 01_HamTienIch.cpp ===================== */

bool KhoangTrang(unsigned char c);
bool LaChuoiRong(const string &s);
string ChuanHoaChuoi(string s);
string ChuanHoaChuoiSach(const string &s);
string ChuanHoaTen(const string &s);
int SoSanhChuoi(const string &a, const string &b);
bool ChuaChuoi(const string &s, const string &part);
bool HopLeVanBan(const string &s);
bool HopLePhai(const string &phai);
string ChuanHoaISBN(const string &isbn);
string SoThanhChuoi(int so);
bool ChuoiThanhSo(const string &s, int &so);
int TachTruong(const string &dong, char ngan, string truong[], int toiDa);

bool NamNhuan(int nam);
int SoNgayTrongThang(int thang, int nam);
bool NgayHopLe(const NgayThang &ngay);
long long Doirangay(NgayThang sngay);
long long KhoangCachNgay(NgayThang ngayt1, NgayThang ngayt2);
NgayThang HomNay();
string ChuoiNgay(const NgayThang &d);
bool DocNgay(const string &s, NgayThang &d);

/* ===================== GiaoDien.cpp ===================== */

void KhoiTaoManHinh();
void gotoxy(int x, int y);
void SetColor(int mauChu, int mauNen);
void XoaManHinh();
int DocPhim();
void InTai(int x, int y, const string &s);
void InCot(int x, int y, const string &s, int rong);
void InDuCot(const string &s, int rong);
void XoaVung(int x, int y, int rong, int cao);
void VeKhung(int x, int y, int rong, int cao);
void HienConTro(bool hien);
void VeMucMenu(int i, bool duocChon, bool dangDieuKhien);
void VeMenuTrai(int mucChon, bool dangDieuKhien);
void VeManHinh(int mucMenu, const string &tieuDe, const string &huongDan);
void ThongBao(const string &s, bool laLoi);
bool XacNhan(const string &cauHoi);
int ChonMenu(int x, int y, int rong, const string muc[], int soMuc);
bool NhapChuoi(int x, int y, int doDai, bool chiNhapSo, string &s);
bool NhapSo(int x, int y, int doDai, int &so);
bool NhapNgay(int x, int y, NgayThang &ngay);
bool XuLyPhimTrang(int phim, int &trang, int tongSoDong);
void InSoTrang(int trang, int tongSoDong);
string TenTrangThaiSach(int trangThai);

/* ===================== NhapSach.cpp, CuonSach.cpp (c) ===================== */

bool HopLeDauSach(const DauSach &d, string &loi);
int TimViTriDauSachTheoISBN(const DanhSachDauSach &ds, const string &isbn);
DauSach *TimDauSachTheoISBN(const DanhSachDauSach &ds, const string &isbn);
int TimViTriChenTheoTen(const DanhSachDauSach &ds, const DauSach &d);
bool ThemDauSach(DanhSachDauSach &ds, const DauSach &d, string &loi);
void HuyDanhSachDauSach(DanhSachDauSach &ds);
void ManHinhNhapSach(DanhSachDauSach &ds, CayDocGia &cay);

bool HopLeViTri(const string &viTri);
string TachISBNTuMaSach(const string &ma);
CuonSach *TimCuonSachTrongDauSach(const DauSach &d, const string &ma);
CuonSach *TimCuonSachToanCuc(const DanhSachDauSach &ds, const string &ma, DauSach *&dauSach);
string SinhMaSachTuDong(const DauSach &d);
void ThemCuonSach(DauSach &d, const string &viTri, int trangThai);
void ThemCuonSachCoMa(DauSach &d, const string &ma, const string &viTri, int trangThai);
int DemCuonSach(const CuonSach *head);

/* ===================== d, e ===================== */

void ManHinhInDauSachTheoTheLoai(const DanhSachDauSach &ds);
void ManHinhTimSach(const DanhSachDauSach &ds);

/* ===================== QuanLyDocGia.cpp (a), InDanhSachDocGia.cpp (b) ===================== */

NutDocGia *tim_cay(CayDocGia &caydocgia, int x);
bool them_cay(CayDocGia &caydocgia, const DocGia &docGiaMoi);
bool XoaDocGia(CayDocGia &caydocgia, int mathe, string &loi);
bool HieuChinhDocGia(CayDocGia &caydocgia, int mathe, string Ho, string Ten, string Phai,
                     int trangthaiThe);
int MaTheLonNhat(CayDocGia caydocgia);
int SinhMaTheTiepTheo(int &maTheDaCap);
void Huydocgia(NutDocGia *&nutdocgia);
void HuyCayDocGia(CayDocGia &caydocgia);
void InThongTinDocGia(int x, int y, const NutDocGia &docgia);
NutDocGia *NhapMaTheTimDocGia(CayDocGia &caydocgia, int x, int y);
void ManHinhQuanLyDocGia(DanhSachDauSach &ds, CayDocGia &cay);
void ManHinhInDanhSachDocGia(CayDocGia &cay);

/* ===================== Muon tra (f, g, h) ===================== */

void them_lich_su(NutDocGia &q, MuonTra muontra);
int Dem_so_sach_dang_muon(NutDocGia &q);
MuonTra *TimMuonDangMuonTheoMa(NutDocGia &q, string maSach);
bool CoSachQuaHan7Ngay(const NutDocGia &docgia, NgayThang ngayktra);
int SoNgayQuaHan(NgayThang ngayMuon, NgayThang ngayXet);
bool CapNhatLuotTra(const NutDocGia &docgia, string masach, NgayThang ngaytrasach, int trangThaiMoi);
void HuyDanhSachMuonTra(NutDocGia &docgia);

bool MuonSach(DanhSachDauSach &ds, NutDocGia &docgia, const string &maSach, NgayThang ngayMuon,
              string &loi);
bool TraSach(DanhSachDauSach &ds, NutDocGia &docgia, const string &maSach, NgayThang ngayTra,
             bool lamMat, string &loi);
int InSachDangMuon(const DanhSachDauSach &ds, NutDocGia &docgia, int x, int y, int dongChon);
void ManHinhMuonSach(DanhSachDauSach &ds, CayDocGia &cay);
void ManHinhTraSach(DanhSachDauSach &ds, CayDocGia &cay);
void ManHinhSachDangMuon(const DanhSachDauSach &ds, CayDocGia &cay);

/* ===================== Thong ke (i, j) ===================== */

void ManHinhDocGiaQuaHan(const DanhSachDauSach &ds, CayDocGia &cay);
int DemDocGia(CayDocGia tree);
int LayDanhSachDocGia(CayDocGia tree, NutDocGia **out, int capacity);
void ManHinhTop10Sach(const DanhSachDauSach &ds, CayDocGia &cay);

/* ===================== LuuDocFile.cpp, Menu.cpp ===================== */

bool DocFile(DanhSachDauSach &ds, CayDocGia &cay, const char tenFile[]);
bool LuuFile(const DanhSachDauSach &ds, CayDocGia cay, const char tenFile[]);
void LuuSauThayDoi(const DanhSachDauSach &ds, CayDocGia cay);
void MenuChinh(DanhSachDauSach &ds, CayDocGia &cay);

#endif
