#pragma once
// Chi bon header thu vien. Ho tro nho tu cai de giu giao dien/nghiep vu cu.
#include <iostream>
#include <string>
#include <fstream>
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
// Gia tri Win32; SDK MinGW cu chua dat ten cho co nay.
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif
#ifndef _WIN32
#error Ban giao dien nay danh cho Windows.
#endif

constexpr int SO_NGUYEN_LON_NHAT=2147483647;
static_assert(sizeof(int)==4,"Ban Windows nay can int 32 bit");
class LoiThuVien {
    std::string noiDung;
public:
    explicit LoiThuVien(const std::string& s):noiDung(s) {}
    const char* what() const {return noiDung.c_str();}
};

// So huu tam duy nhat. Khong thay mang/DSLK/BST luu du lieu nghiep vu.
// Cac wrapper nay khong cho sao chep, tu giai phong khi return/throw.
template<class T> class ConTroTam {
    T* p;
    ConTroTam(const ConTroTam&)=delete;
    ConTroTam& operator=(const ConTroTam&)=delete;
public:
    explicit ConTroTam(T* value=nullptr):p(value) {}
    ~ConTroTam(){delete p;}
    T* get() const {return p;}
    T* operator->() const {return p;}
    T& operator*() const {return *p;}
    T* release(){T* old=p;p=nullptr;return old;}
    void reset(T* value=nullptr){if(p!=value){delete p;p=value;}}
};
template<class T> class ConTroTam<T[]> {
    T* p;
    ConTroTam(const ConTroTam&)=delete;
    ConTroTam& operator=(const ConTroTam&)=delete;
public:
    explicit ConTroTam(T* value=nullptr):p(value) {}
    ~ConTroTam(){delete[] p;}
    T* get() const {return p;}
    T& operator[](std::size_t i) const {return p[i];}
    T* release(){T* old=p;p=nullptr;return old;}
    void reset(T* value=nullptr){if(p!=value){delete[] p;p=value;}}
};

// Gom cac dong xuat vao string de GUI phan trang, khong can <sstream>.
class BoDemChuoi:public std::streambuf {
    std::string duLieu;
protected:
    int_type overflow(int_type ch) override {
        if(!traits_type::eq_int_type(ch,traits_type::eof())) duLieu+=traits_type::to_char_type(ch);
        return traits_type::not_eof(ch);
    }
    std::streamsize xsputn(const char* s,std::streamsize n) override {
        if(n>0) duLieu.append(s,static_cast<std::size_t>(n));
        return n;
    }
public:
    const std::string& str() const {return duLieu;}
};
class LuongChuoi:public std::ostream {
    BoDemChuoi boDem;
public:
    LuongChuoi():std::ostream(nullptr){rdbuf(&boDem);exceptions(std::ios::badbit|std::ios::failbit);}
    const std::string& str() const {return boDem.str();}
};

inline std::wstring DuongDanUTF16(const std::string& s) {
    if(s.empty()) return L"";
    if(s.size()>static_cast<std::size_t>(SO_NGUYEN_LON_NHAT)) throw LoiThuVien("Duong dan qua dai");
    int n=MultiByteToWideChar(CP_UTF8,MB_ERR_INVALID_CHARS,s.data(),static_cast<int>(s.size()),nullptr,0);
    if(!n) throw LoiThuVien("Duong dan khong phai UTF-8 hop le");
    std::wstring out(static_cast<std::size_t>(n),L'\0');
    if(!MultiByteToWideChar(CP_UTF8,MB_ERR_INVALID_CHARS,s.data(),static_cast<int>(s.size()),&out[0],n))
        throw LoiThuVien("Khong doi duoc duong dan UTF-16");
    for(wchar_t c:out) if(c==0) throw LoiThuVien("Duong dan chua NUL");
    return out;
}
inline std::string DuongDanUTF8(const std::wstring& s) {
    if(s.empty()) return "";
    int n=WideCharToMultiByte(CP_UTF8,WC_ERR_INVALID_CHARS,s.data(),static_cast<int>(s.size()),nullptr,0,nullptr,nullptr);
    if(!n) throw LoiThuVien("Duong dan UTF-16 khong hop le");
    std::string out(static_cast<std::size_t>(n),'\0');
    if(!WideCharToMultiByte(CP_UTF8,WC_ERR_INVALID_CHARS,s.data(),static_cast<int>(s.size()),&out[0],n,nullptr,nullptr))
        throw LoiThuVien("Khong doi duoc duong dan UTF-8");
    return out;
}
inline std::wstring DuongDanDayDu(const std::string& path) {
    if(path.empty()) throw LoiThuVien("Duong dan rong");
    std::wstring input=DuongDanUTF16(path);
    DWORD size=GetFullPathNameW(input.c_str(),0,nullptr,nullptr);
    if(!size) throw LoiThuVien("Khong xac dinh duoc duong dan day du");
    ConTroTam<wchar_t[]> buffer(new wchar_t[size]);
    DWORD used=GetFullPathNameW(input.c_str(),size,buffer.get(),nullptr);
    if(!used || used>=size) throw LoiThuVien("Duong dan thay doi / qua dai");
    return std::wstring(buffer.get(),used);
}
inline std::wstring ThuMucCha(const std::wstring& path) {
    for(std::size_t i=path.size();i>0;--i)
        if(path[i-1]==L'\\'||path[i-1]==L'/') return path.substr(0,i);
    return L"";
}
inline bool FileTonTai(const std::string& path) {
    DWORD a=GetFileAttributesW(DuongDanUTF16(path).c_str());
    if(a!=INVALID_FILE_ATTRIBUTES) return true;
    DWORD e=GetLastError();
    if(e==ERROR_FILE_NOT_FOUND||e==ERROR_PATH_NOT_FOUND) return false;
    throw LoiThuVien("Khong kiem tra duoc duong dan (Windows "+std::to_string(e)+")");
}
inline void TaoThuMuc(std::wstring path) {
    if(path.empty()) return;
    DWORD a=GetFileAttributesW(path.c_str());
    if(a!=INVALID_FILE_ATTRIBUTES) {
        if(a&FILE_ATTRIBUTE_DIRECTORY) return;
        throw LoiThuVien("Vi tri thu muc dang la mot file");
    }
    while(!path.empty() && (path.back()==L'\\'||path.back()==L'/')) path.pop_back();
    std::wstring parent=ThuMucCha(path);
    if(parent.empty() || parent==path) throw LoiThuVien("Khong truy cap duoc thu muc goc");
    TaoThuMuc(parent);
    if(!CreateDirectoryW(path.c_str(),nullptr)) {
        a=GetFileAttributesW(path.c_str());
        if(a==INVALID_FILE_ATTRIBUTES || !(a&FILE_ATTRIBUTE_DIRECTORY))
            throw LoiThuVien("Khong tao duoc thu muc (Windows "+std::to_string(GetLastError())+")");
    }
}

// Tach doi so UTF-16 cua Windows, giu quote/backslash, khong can shellapi.h.
// out can command.size()+1 o; argv[0] co quy tac rieng cho ten executable.
inline int DocDoiSoWindows(const std::wstring& command,std::string* out) {
    std::size_t i=0;int count=0;
    while(i<command.size() && (command[i]==L' '||command[i]==L'\t')) ++i;
    std::wstring exe;bool quoted=false;
    while(i<command.size()) {
        wchar_t c=command[i];
        if(c==L'"') {quoted=!quoted;++i;continue;}
        if(!quoted && (c==L' '||c==L'\t')) break;
        exe+=c;++i;
    }
    out[count++]=DuongDanUTF8(exe);
    while(i<command.size()) {
        while(i<command.size() && (command[i]==L' '||command[i]==L'\t')) ++i;
        if(i==command.size()) break;
        std::wstring value;quoted=false;
        while(i<command.size()) {
            if(!quoted && (command[i]==L' '||command[i]==L'\t')) break;
            std::size_t slashes=0;
            while(i<command.size() && command[i]==L'\\') {++slashes;++i;}
            if(i<command.size() && command[i]==L'"') {
                value.append(slashes/2,L'\\');
                if(slashes%2) {value+=L'"';++i;}
                else if(quoted && i+1<command.size() && command[i+1]==L'"') {value+=L'"';i+=2;}
                else {quoted=!quoted;++i;}
            } else {
                value.append(slashes,L'\\');
                if(i==command.size() || (!quoted && (command[i]==L' '||command[i]==L'\t'))) break;
                value+=command[i++];
            }
        }
        out[count++]=DuongDanUTF8(value);
    }
    return count;
}

// File Unicode: MinGW cu khong co constructor fstream(wchar_t*).
// Dung HANDLE Win32 lam nguon/dich cua stream C++11, khong doi dinh dang v1.
class BoDemDocTep:public std::streambuf {
    HANDLE file;
    char buffer[8192];
    bool loi;
    BoDemDocTep(const BoDemDocTep&)=delete;
    BoDemDocTep& operator=(const BoDemDocTep&)=delete;
protected:
    int_type underflow() override {
        if(gptr()<egptr()) return traits_type::to_int_type(*gptr());
        DWORD n=0;
        if(file==INVALID_HANDLE_VALUE || !ReadFile(file,buffer,sizeof(buffer),&n,nullptr)) {
            loi=true;return traits_type::eof();
        }
        if(!n) return traits_type::eof();
        setg(buffer,buffer,buffer+n);
        return traits_type::to_int_type(*gptr());
    }
public:
    explicit BoDemDocTep(const std::string& path):file(INVALID_HANDLE_VALUE),loi(false) {
        const std::wstring wide=DuongDanUTF16(path);
        file=CreateFileW(wide.c_str(),GENERIC_READ,FILE_SHARE_READ,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,nullptr);
        setg(buffer,buffer,buffer);
    }
    ~BoDemDocTep(){if(file!=INVALID_HANDLE_VALUE) CloseHandle(file);}
    bool moDuoc() const {return file!=INVALID_HANDLE_VALUE;}
    bool biLoi() const {return loi;}
};
class TepDoc:public std::istream {
    BoDemDocTep boDem;
public:
    explicit TepDoc(const std::string& path):std::istream(nullptr),boDem(path) {
        rdbuf(&boDem);if(!boDem.moDuoc()) setstate(std::ios::failbit);
    }
    bool bad() const {return std::istream::bad() || boDem.biLoi();}
};
class BoDemGhiTep:public std::streambuf {
    HANDLE file;
    char buffer[8192];
    bool loi;
    BoDemGhiTep(const BoDemGhiTep&)=delete;
    BoDemGhiTep& operator=(const BoDemGhiTep&)=delete;
    bool dayBoDem() {
        if(file==INVALID_HANDLE_VALUE || loi) return false;
        DWORD count=static_cast<DWORD>(pptr()-pbase()),done=0;
        while(done<count) {
            DWORD n=0;
            if(!WriteFile(file,buffer+done,count-done,&n,nullptr) || !n) {loi=true;return false;}
            done+=n;
        }
        setp(buffer,buffer+sizeof(buffer));return true;
    }
protected:
    int_type overflow(int_type ch) override {
        if(!dayBoDem()) return traits_type::eof();
        if(!traits_type::eq_int_type(ch,traits_type::eof())) {*pptr()=traits_type::to_char_type(ch);pbump(1);}
        return traits_type::not_eof(ch);
    }
    int sync() override {
        if(!dayBoDem() || !FlushFileBuffers(file)) {loi=true;return -1;}
        return 0;
    }
public:
    explicit BoDemGhiTep(const std::wstring& path):file(INVALID_HANDLE_VALUE),loi(false) {
        file=CreateFileW(path.c_str(),GENERIC_WRITE,0,nullptr,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,nullptr);
        setp(buffer,buffer+sizeof(buffer));
    }
    ~BoDemGhiTep(){dong();}
    bool moDuoc() const {return file!=INVALID_HANDLE_VALUE;}
    bool dong() {
        if(file==INVALID_HANDLE_VALUE) return !loi;
        bool ok=sync()==0;
        if(!CloseHandle(file)) ok=false;
        file=INVALID_HANDLE_VALUE;loi=!ok;return ok;
    }
};
class TepGhi:public std::ostream {
    BoDemGhiTep boDem;
public:
    explicit TepGhi(const std::wstring& path):std::ostream(nullptr),boDem(path) {
        rdbuf(&boDem);if(!boDem.moDuoc()) setstate(std::ios::failbit);
    }
    void close(){if(!boDem.dong()) setstate(std::ios::failbit);}
};


// Ban tham khao AI. Bon cau truc va ten truong giu theo header cua nhom.
using std::string;
constexpr int MAX_DAU_SACH = 10000;
constexpr int MAX_DOC_GIA = 100000; // gioi han tai nguyen cua ban tham khao
constexpr int MAX_BAN_GHI = 200000;
constexpr int SACH_CHO_MUON=0, SACH_DANG_MUON=1, SACH_THANH_LY=2;
constexpr int MUON_DANG_MUON=0, MUON_DA_TRA=1, MUON_LAM_MAT=2;
constexpr int THE_BI_KHOA=0, THE_HOAT_DONG=1;
struct NgayThang {
    int ngay, thang, nam;
    NgayThang(int d=0,int m=0,int y=0):ngay(d),thang(m),nam(y) {}
};
struct CuonSach { string maSach; int trangThai=SACH_CHO_MUON; string viTri; CuonSach* next=nullptr; };
struct DauSach {
    string ISBN, tenSach; int soTrang=0; string tacGia; int namXuatBan=0;
    string theLoai; CuonSach* dms=nullptr;
};
struct DanhSachDauSach { DauSach* ds[MAX_DAU_SACH]{}; int soLuong=0; };
struct MuonTra {
    string maSach; NgayThang ngayMuon, ngayTra; int trangThai=MUON_DANG_MUON;
    MuonTra* next=nullptr;
};
struct DocGia {
    int maThe=0; string ho, ten, phai; int trangThaiThe=THE_HOAT_DONG;
    MuonTra* dsMuonTra=nullptr;
};
struct NutDocGia { DocGia thongTin; NutDocGia* left=nullptr; NutDocGia* right=nullptr; };
struct CayDocGia { NutDocGia* root=nullptr; };
struct ThuVien {
    DanhSachDauSach dsDauSach; CayDocGia cayDocGia;
    int maTheLonNhatDaCap=0; // metadata v1: khong tai su dung ma da xoa
    ThuVien()=default;
    ~ThuVien();
    ThuVien(const ThuVien&)=delete;
    ThuVien& operator=(const ThuVien&)=delete;
};

// 01: chuoi, ngay, nhap chuan; khong tinh thong ke nghiep vu o day.
bool LaChuoiRong(const string& s);
string ChuanHoaChuoi(const string& s);
string KhoaSoSanh(const string& s); // ha ASCII; giu nguyen byte UTF-8 co dau
int SoSanhChuoi(const string& a, const string& b);
bool ChuaChuoi(const string& s, const string& part);
bool HopLeVanBan(const string& s);
bool DocSoNguyen(const string& s, int& value, int lo=0, int hi=2147483647);
bool TachTruong(const string& line, string* out, int count);
bool NamNhuan(int year);
bool NgayHopLe(const NgayThang& d);
bool NgayRong(const NgayThang& d);
bool DocNgay(const string& s, NgayThang& d);
string ChuoiNgay(const NgayThang& d);
int SoThuTuNgay(const NgayThang& d); // chi goi voi ngay hop le
int KhoangCachNgay(const NgayThang& a, const NgayThang& b); // b-a
NgayThang HomNay();
bool QuaHan7Ngay(const NgayThang& ngayMuon, const NgayThang& now);
bool HopLePhai(const string& s);
bool HopLeTrangThaiThe(int x);
bool HopLeTrangThaiSach(int x);
bool HopLeTrangThaiMuonTra(int x);

// 02: mang con tro dau sach. Ket qua tim kiem la con tro muon, khong delete.
bool HopLeDauSach(const DauSach& d, string& loi);
int TimViTriChenTheoTen(const DanhSachDauSach& ds, const DauSach& d);
DauSach* TimDauSachTheoISBN(DanhSachDauSach& ds, const string& isbn);
const DauSach* TimDauSachTheoISBN(const DanhSachDauSach& ds, const string& isbn);
bool ThemDauSach(ThuVien& tv, const DauSach& d, string& loi);
void TimDauSachTheoTen(const ThuVien& tv, const string& ten, std::ostream& out);
void InDanhSachDauSach(const ThuVien& tv, std::ostream& out);
void InDauSachTheoTheLoai(const ThuVien& tv, std::ostream& out);
void HuyDanhSachDauSach(DanhSachDauSach& ds);
void ManHinhNhapDauSach(ThuVien& tv);
void ManHinhTimSach(const ThuVien& tv);

// 03: danh muc cuon; ISBN#so cho ma moi, S001... cu van tra duoc.
CuonSach* TimCuonSachTrongDauSach(DauSach& d, const string& ma);
const CuonSach* TimCuonSachTrongDauSach(const DauSach& d, const string& ma);
CuonSach* TimCuonSachToanCuc(ThuVien& tv, const string& ma, DauSach** owner=nullptr);
const CuonSach* TimCuonSachToanCuc(const ThuVien& tv, const string& ma, const DauSach** owner=nullptr);
bool SinhMaSachTuDong(const ThuVien& tv, const DauSach& d, string& ma, string& loi);
bool ThemCuonSach(ThuVien& tv, const string& isbn, const string& viTri, string& ma, string& loi);
void HuyDanhMucCuonSach(CuonSach*& head);
int DemCuonSach(const CuonSach* head);

// 04: BST theo ma the; mang con tro tam chi la view, khong doi BST.
NutDocGia* TimDocGia(CayDocGia& tree, int ma);
const NutDocGia* TimDocGia(const CayDocGia& tree, int ma);
int DemDocGia(const CayDocGia& tree);
int LayDanhSachDocGia(const CayDocGia& tree, const NutDocGia** out, int capacity);
bool ChenDocGiaCoMa(CayDocGia& tree, const DocGia& dg, string& loi); // chi bo doc file
bool ThemDocGia(ThuVien& tv, const string& ho, const string& ten, const string& phai, int& ma, string& loi);
bool HieuChinhDocGia(ThuVien& tv, int ma, const string& ho, const string& ten, const string& phai, int tt, string& loi);
bool XoaDocGia(ThuVien& tv, int ma, string& loi);
void HuyCayDocGia(CayDocGia& tree);
void InDocGiaTheoMa(const ThuVien& tv, std::ostream& out);
void InDocGiaTheoTenHo(const ThuVien& tv, std::ostream& out);
void ManHinhDocGia(ThuVien& tv);

// 05: lich su + phep doc; nghiep vu cap nhat dong bo nam o 06.
int DemLichSu(const MuonTra* p);
int DemSoSachDangMuon(const DocGia& dg);
bool CoSachQuaHan7Ngay(const DocGia& dg, const NgayThang& now);
MuonTra* TimMuonDangMuonTheoMa(DocGia& dg, const string& ma);
void HuyDanhSachMuonTra(MuonTra*& head);
void LietKeSachDangMuon(const ThuVien& tv, int maThe, std::ostream& out);

// 06: giao dich muon/tra/mat va thong ke chi doc.
bool MuonSach(ThuVien& tv, int maThe, const string& maSach, const NgayThang& ngay, string& loi);
bool TraSach(ThuVien& tv, int maThe, const string& maSach, const NgayThang& ngay, string& loi);
bool DanhDauMatSach(ThuVien& tv, int maThe, const string& maSach, const NgayThang& ngay, string& loi);
void InDocGiaQuaHan(const ThuVien& tv, const NgayThang& ngay, std::ostream& out);
void InTop10SachDuocMuonNhieuNhat(const ThuVien& tv, std::ostream& out);
void ManHinhMuonTra(ThuVien& tv, const NgayThang& ngay, bool tra);

// 07: dung du lieu tam, xac minh toan ven roi moi hoan doi; save temp + replace.
bool KiemTraToanVen(const ThuVien& tv, string& loi);
bool DocFile(ThuVien& tv, const string& path, string& loi);
bool LuuFile(const ThuVien& tv, const string& path, string& loi);
void HuyThuVien(ThuVien& tv);
void HoanDoiThuVien(ThuVien& a, ThuVien& b);

// 08: helper UI dung chung. /huy hoac Esc de huy nhap; EOF thoat an toan.
bool DangDungGiaoDienHeThong();
bool NhapBieuMau(const string& title, const char* const* labels, string* values, int count);
bool NhapDong(const string& prompt, string& s);
bool NhapSo(const string& prompt, int& n, int lo, int hi);
int ChonMenu(const string& title, const char* const* labels, int count);
void ThongBao(const string& s);
void HienThiPhanTrang(const string& text);

// Chi cac man hinh goi sau commit; API nghiep vu khong tu ghi file.
void LuuSauThayDoi(const ThuVien& tv);
