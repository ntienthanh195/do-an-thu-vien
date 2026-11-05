#include "00_KhaiBaoChung.h"


// [THAI] Tien ich da co trong bo MaNguon cua nhom (commit 5c03ecf).
// [THAI] Phan code Thai cung cap; dung chung cho nhom.
bool LaChuoiRong(const string& s){
    bool laKhoangTrang[256] = { false };
        laKhoangTrang[9]  = true; // '\t' : Tab ngang
        laKhoangTrang[10] = true; // '\n' : Xuong dong (Line feed)
        laKhoangTrang[11] = true; // '\v' : Tab doc
        laKhoangTrang[12] = true; // '\f' : Sang trang (Form feed)
        laKhoangTrang[13] = true; // '\r' : Ve dau dong (Carriage return)
        laKhoangTrang[32] = true; // ' '  : Dau cach (Space)
    for(size_t i = 0; i < s.size(); ++i){
        if(!laKhoangTrang[static_cast<unsigned char>(s[i])]){
            return false;
        }
    }
    return true;
}

// can trao doi them lai voi thay nam hop le cua cuon sach bat dau va ket thuc
// [THAI] Phan code Thai cung cap; dung chung cho nhom.
bool LaNamHopLe(int nam){
    return nam >= 1 && nam <= HomNay().nam;
}

// [THAI] Phan code Thai cung cap; dung chung cho nhom.
string ChuanHoaChuoi(string s){
    // [DEMO - CODEX] Tu duyet ky tu khi chuan hoa.
    string kq = ChuanHoaChuoiSach(s);
    for (size_t i = 0; i < kq.size(); ++i)
        if (kq[i] >= 'A' && kq[i] <= 'Z') kq[i] += 'a' - 'A';
    return kq;
}

// [THAI] Phan code Thai cung cap; dung chung cho nhom.
bool HopLePhai(const string& phai){
    string chuan = ChuanHoaChuoi(phai);
    return chuan == "nam" || chuan == "nu" || chuan == "nữ";
}

// [THAI] Phan code Thai cung cap; dung chung cho nhom.
bool HopLeTrangThaiSach(int trangThai){
    return trangThai == SACH_CHO_MUON || trangThai == SACH_DANG_MUON || trangThai == SACH_THANH_LY;
}

// [THAI] Phan code Thai cung cap; dung chung cho nhom.
bool HopLeTrangThaiMuonTra(int trangThai){
    return trangThai == MUON_DANG_MUON || trangThai == MUON_DA_TRA || trangThai == MUON_LAM_MAT;
}

// [THAI] Phan code Thai cung cap; dung chung cho nhom.
bool HopLeTrangThaiThe(int trangThai){
    return trangThai == THE_HOAT_DONG || trangThai == THE_BI_KHOA;
}

// Tien ich sach tu ban Thai; ten rieng giu nguyen hanh vi cua ChuanHoaChuoi cu.
// [THAI] Phan code Thai cung cap; dung chung cho nhom.
string ChuanHoaChuoiSach(const string &s){
    string kq = "";
    bool gap = false; // gap ky tu khac khoang trang
    for(const char c : s){
        if(c  != ' ' && c  != '\n' && c  != '\t' && c  != '\r'){
            if(gap == false){
                gap = true;
            }
            kq += c;

        }
        else{
            if(gap == true){
                gap = false;
                kq += ' ';
            }
        }
    }
    // truong hop dac biet : "hello world "
    if(kq.size() != 0 && kq[kq.size()-1] == ' '){
        kq.pop_back();
    }
    return kq;
}

// [THAI] Phan code Thai cung cap; dung chung cho nhom.
int SoSanhChuoi(const string &a, const string &b){
    // a < b : -1, a > b : 1; a = b : 0
    string x = ChuanHoaChuoiSach(a);
    string y = ChuanHoaChuoiSach(b);
    if (x.empty() && y.empty()) return 0;
    if (x.empty()) return -1;
    if (y.empty()) return 1;
    for (int i = 0; i < (int)x.size() && i < (int)y.size(); ++i){
        char x1 = x[i], y1 = y[i];
        if (x1 >= 'A' && x1 <= 'Z') x1 = (char)(x1 + 32);
        if (y1 >= 'A' && y1 <= 'Z') y1 = (char)(y1 + 32);
        if (x1 < y1) return -1;
        if (x1 > y1) return 1;
    }
    return x.size() < y.size() ? -1 : (x.size() > y.size() ? 1 : 0);
}

// [THAI] Phan code Thai cung cap; dung chung cho nhom.
// [DEMO - CODEX] Dieu chinh tu ham cua Thai de ghep voi du lieu demo.
bool HopLeVanBan(const string &s)
{   
    string t = ChuanHoaChuoiSach(s);
    if (!KiemTraVanBanHeThong(s)) return false; // [DEMO - CODEX] chap nhan ten UTF-8
    for(const char& c : t){
        if((c < 'a' || c > 'z') && (c < 'A' || c > 'Z')){
            if(c != ' ' && static_cast<unsigned char>(c) < 128) return false;
        }
    }
    return true;
}

// [THAI] Phan code Thai cung cap; dung chung cho nhom.
string ChuanHoaISBN(const string &isbn){
    string res = "";
    for(char c : isbn){
        if(c >= '0' && c <= '9'){
            res += c;
        }
    }
    return res;
}

// [THANH] Nhom ham ngay thang tu ban Thanh gui ngay 01/11/2026.

// [THANH] Phan code Thanh cung cap/phu trach.
bool NamNhuan(int nam)
{
    return nam % 400 == 0 ||
           (nam % 4 == 0 && nam % 100 != 0);
}

// [THANH] Phan code Thanh cung cap/phu trach.
int SoNgayTrongThang(int thang, int nam)
{
    if (thang < 1 || thang > 12 || nam <= 0)
        return 0;

    switch (thang)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;

        case 4:
        case 6:
        case 9:
        case 11:
            return 30;

        case 2:
            if (NamNhuan(nam))
                return 29;
            return 28;
    }

    return 0;
}

// [THANH] Phan code Thanh cung cap/phu trach.
bool NgayHopLe(const NgayThang &ngay)
{
    int soNgay = SoNgayTrongThang(ngay.thang, ngay.nam);

    return soNgay > 0 &&
           ngay.ngay >= 1 &&
           ngay.ngay <= soNgay;
}

// [THANH] Phan code Thanh cung cap/phu trach.
long long Doirangay(NgayThang sngay)
{
	long long soNgay=0;
	for(int i=1;i<sngay.nam;i++)
	{
		if(NamNhuan(i))
		{
			soNgay+= 366;
		}
		else
		{
			soNgay+= 365;
		}
	}
	

	for(int i=1;i<sngay.thang;i++)
	{
		soNgay+=SoNgayTrongThang(i,sngay.nam);
	}
	soNgay = soNgay + sngay.ngay-1;
	return soNgay;
}

// [THANH] Phan code Thanh cung cap/phu trach.
long long KhoangCachNgay(NgayThang ngayt1, NgayThang ngayt2)
{
    long long i=Doirangay(ngayt1);
	long long j=Doirangay(ngayt2);
	return j-i;
}

// [DEMO - CODEX] Phan bo sung cho ban trinh thay.
bool ChuaChuoi(const string &chuoi, const string &canTim)
{
    string a = ChuanHoaChuoi(chuoi);
    string b = ChuanHoaChuoi(canTim);
    if (b.empty() || b.size() > a.size())
    {
        return false;
    }
    for (size_t viTri = 0; viTri <= a.size() - b.size(); viTri++)
    {
        size_t j = 0;
        while (j < b.size() && a[viTri + j] == b[j])
        {
            j++;
        }
        if (j == b.size())
        {
            return true;
        }
    }
    return false;
}
bool DocSoNguyen(const string &chuoi, int &ketQua, int nhoNhat, int lonNhat)
{
    if (chuoi.empty() || nhoNhat < 0 || lonNhat < nhoNhat)
    {
        return false;
    }
    int so = 0;
    for (size_t i = 0; i < chuoi.size(); i++)
    {
        if (chuoi[i] < '0' || chuoi[i] > '9')
        {
            return false;
        }
        int chuSo = chuoi[i] - '0';
        if (so > lonNhat / 10)
        {
            return false;
        }
        if (so == lonNhat / 10 && chuSo > lonNhat % 10)
        {
            return false;
        }
        so = so * 10 + chuSo;
    }
    if (so < nhoNhat)
    {
        return false;
    }
    ketQua = so;
    return true;
}
static bool TachTheoKyTu(const string &dong, char dauTach, string *truong, int soTruong)
{
    if (soTruong <= 0) return false;
    int viTri = 0;
    truong[0].clear();
    for (char c : dong)
    {
        if (c == dauTach)
        {
            if (truong[viTri].empty() || viTri + 1 >= soTruong) return false;
            truong[++viTri].clear();
        }
        else
        {
            truong[viTri] += c;
        }
    }
    return viTri == soTruong - 1 && !truong[viTri].empty();
}

bool TachTruong(const string &dong, string *truong, int soTruong)
{
    return TachTheoKyTu(dong, '|', truong, soTruong);
}
bool NgayRong(const NgayThang &ngay)
{
    return ngay.ngay == 0 && ngay.thang == 0 && ngay.nam == 0;
}
bool DocNgay(const string &chuoi, NgayThang &ketQua)
{
    string truong[3];
    if (!TachTheoKyTu(chuoi, '/', truong, 3)) return false;
    NgayThang tam;
    if (!DocSoNguyen(truong[0], tam.ngay, 0, 31))
    {
        return false;
    }
    if (!DocSoNguyen(truong[1], tam.thang, 0, 12))
    {
        return false;
    }
    if (!DocSoNguyen(truong[2], tam.nam, 0, 9999))
    {
        return false;
    }
    if (!NgayHopLe(tam) && chuoi != "0/0/0")
    {
        return false;
    }
    ketQua = tam;
    return true;
}
string ChuoiNgay(const NgayThang &ngay)
{
    if (NgayRong(ngay))
    {
        return "0/0/0";
    }
    string d = ChuoiSo(ngay.ngay), m = ChuoiSo(ngay.thang), y = ChuoiSo(ngay.nam);
    while (d.size() < 2)
    {
        d = "0" + d;
    }
    while (m.size() < 2)
    {
        m = "0" + m;
    }
    while (y.size() < 4)
    {
        y = "0" + y;
    }
    return d + "/" + m + "/" + y;
}
int SoThuTuNgay(const NgayThang &ngay)
{
    if (!NgayHopLe(ngay))
    {
        throw LoiThuVien("Ngay khong hop le.");
    }
    int namTruoc = ngay.nam - 1;
    int soNgay = 365 * namTruoc + namTruoc / 4 - namTruoc / 100 + namTruoc / 400;
    for (int thang = 1; thang < ngay.thang; thang++)
    {
        soNgay += SoNgayTrongThang(thang, ngay.nam);
    }
    return soNgay + ngay.ngay;
}
NgayThang HomNay()
{
    SYSTEMTIME ngay;
    GetLocalTime(&ngay);
    return NgayThang(ngay.wDay, ngay.wMonth, ngay.wYear);
}
bool KiemTraVanBanHeThong(const string &s)
{

    if (LaChuoiRong(s) || s.size() > 512)
    {
        return false;
    }
    // Kiem tra UTF-8 that, khong chi chap nhan byte bat ky.
    for (size_t i = 0; i < s.size();)
    {
        unsigned char c = static_cast<unsigned char>(s[i]);
        if (c < 128)
        {
            if (c < 32 || c == 127 || c == '|')
            {
                return false;
            }
            ++i;
            continue;
        }
        int n = 0;
        unsigned int cp = 0;
        if (c >= 0xC2 && c <= 0xDF)
        {
            n = 2;
            cp = c & 31U;
        }
        else if (c >= 0xE0 && c <= 0xEF)
        {
            n = 3;
            cp = c & 15U;
        }
        else if (c >= 0xF0 && c <= 0xF4)
        {
            n = 4;
            cp = c & 7U;
        }
        else
        {
            return false;
        }
        if (i + static_cast<size_t>(n) > s.size())
        {
            return false;
        }
        for (int k = 1; k < n; ++k)
        {
            unsigned char b = static_cast<unsigned char>(s[i + static_cast<size_t>(k)]);
            if ((b & 0xC0U) != 0x80U)
            {
                return false;
            }
            cp = (cp << 6U) | (b & 63U);
        }
        if ((n == 3 && cp < 0x800) || (n == 4 && cp < 0x10000) || cp > 0x10FFFF ||
            (cp >= 0xD800 && cp <= 0xDFFF) || cp == 0xFEFF || (cp >= 0x80 && cp <= 0x9F))
        {
            return false;
        }
        i += static_cast<size_t>(n);
    }
    return true;
}

string ChuoiSo(long long so)
{
    bool am = so < 0;
    char nguoc[20];
    int n = 0;
    do
    {
        int du = static_cast<int>(so % 10);
        nguoc[n++] = static_cast<char>('0' + (du < 0 ? -du : du));
        so /= 10;
    } while (so != 0);
    string kq;
    if (am) kq += '-';
    while (n > 0) kq += nguoc[--n];
    return kq;
}
wstring ChuoiSoRong(long long so)
{
    string hep = ChuoiSo(so);
    wstring rong;
    for (char c : hep) rong += static_cast<wchar_t>(c);
    return rong;
}

// [DEMO - CODEX] Dung chung moc >= 7 cua nhom cho ca muon sach va bao cao.
int SoNgayQuaHan(const NgayThang &ngayMuon, const NgayThang &ngayXet)
{
    long long daGiu = KhoangCachNgay(ngayMuon, ngayXet);
    if (daGiu < 7) return 0;
    return static_cast<int>(daGiu - 7 + 1);
}
