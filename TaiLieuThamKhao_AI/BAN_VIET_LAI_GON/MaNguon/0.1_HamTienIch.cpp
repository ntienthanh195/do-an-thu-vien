#include "0.0_KhaiBaoChung.h"
#include <ctime>

/* ===================== XU LY CHUOI ===================== */

// [THAI]
bool KhoangTrang(unsigned char c)
{
    return c == ' ' || c == '\t' || c == '\r' || c == '\n';
}

// [THAI]
bool LaChuoiRong(const string &s)
{
    for (int i = 0; i < (int)s.size(); ++i)
    {
        if (!KhoangTrang(s[i]))
            return false;
    }
    return true;
}

// [THAI] Bo khoang trang thua o dau, cuoi va giua cac tu; giu nguyen hoa/thuong.
string ChuanHoaChuoiSach(const string &s)
{
    string kq = "";
    bool gap = false; // da gap ky tu khac khoang trang
    for (int i = 0; i < (int)s.size(); ++i)
    {
        char c = s[i];
        if (!KhoangTrang(c))
        {
            gap = true;
            kq += c;
        }
        else if (gap)
        {
            gap = false;
            kq += ' ';
        }
    }
    // truong hop "hello world " con thua mot khoang trang o cuoi
    if (kq.size() != 0 && kq[kq.size() - 1] == ' ')
        kq.erase(kq.size() - 1, 1);
    return kq;
}

// [THAI] Chuan hoa roi doi het sang chu thuong, dung de so sanh khong phan biet hoa/thuong.
string ChuanHoaChuoi(string s)
{
    s = ChuanHoaChuoiSach(s);
    for (int i = 0; i < (int)s.size(); ++i)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = (char)(s[i] + 32);
    }
    return s;
}

// Chuan hoa ho ten: bo khoang trang thua, viet hoa chu dau moi tu.
// Vi du: "  nguyen   VAN " -> "Nguyen Van"
string ChuanHoaTen(const string &s)
{
    string kq = ChuanHoaChuoi(s);
    for (int i = 0; i < (int)kq.size(); ++i)
    {
        if ((i == 0 || kq[i - 1] == ' ') && kq[i] >= 'a' && kq[i] <= 'z')
            kq[i] = (char)(kq[i] - 32);
    }
    return kq;
}

// [THAI] So sanh khong phan biet hoa/thuong. a < b: -1, a > b: 1, bang nhau: 0
// @TT [b,c,d] So sanh 2 chuoi khong phan biet hoa/thuong, dung cho sap xep va tim nhi phan theo ten
int SoSanhChuoi(const string &a, const string &b)
{
    string x = ChuanHoaChuoi(a);
    string y = ChuanHoaChuoi(b);
    for (int i = 0; i < (int)x.size() && i < (int)y.size(); ++i)
    {
        if (x[i] < y[i]) return -1;
        if (x[i] > y[i]) return 1;
    }
    if (x.size() < y.size()) return -1;
    if (x.size() > y.size()) return 1;
    return 0;
}

// [THAI] Kiem tra chuoi s co chua chuoi part khong (khong phan biet hoa/thuong).
// @TT [e] Tim chuoi con khong phan biet hoa/thuong: thu tung vi tri bat dau, so tung ky tu - O(n*m)
bool ChuaChuoi(const string &s, const string &part)
{
    if (part.size() == 0) return true;
    if (s.size() < part.size()) return false;
    for (int i = 0; i <= (int)(s.size() - part.size()); ++i)
    {
        bool khop = true;
        for (int j = 0; j < (int)part.size(); ++j)
        {
            char x = s[i + j], y = part[j];
            if (x >= 'A' && x <= 'Z') x = (char)(x + 32);
            if (y >= 'A' && y <= 'Z') y = (char)(y + 32);
            if (x != y)
            {
                khop = false;
                break;
            }
        }
        if (khop) return true;
    }
    return false;
}

// [THAI] Van ban luu duoc vao file: khong rong, khong chua dau '|' (dau ngan cach trong file).
bool HopLeVanBan(const string &s)
{
    if (s.size() > 100 || LaChuoiRong(s))
        return false;
    for (int i = 0; i < (int)s.size(); ++i)
    {
        unsigned char c = s[i];
        if (c == '|' || c < 32 || c >= 127)
            return false;
    }
    return true;
}

// [THAI] De: Phai chi nhan 'Nam' hoac 'Nu'.
bool HopLePhai(const string &phai)
{
    string chuan = ChuanHoaChuoi(phai);
    return chuan == "nam" || chuan == "nu";
}

// [THAI] Bo dau '-' va khoang trang trong ISBN. Vi du: 978-604-0-00000-1 -> 9786040000001
string ChuanHoaISBN(const string &isbn)
{
    string res = "";
    for (int i = 0; i < (int)isbn.size(); ++i)
    {
        if (isbn[i] != '-' && !KhoangTrang(isbn[i]))
            res += isbn[i];
    }
    return res;
}

// Doi so nguyen khong am thanh chuoi. Vi du: 305 -> "305"
string SoThanhChuoi(int so)
{
    if (so == 0) return "0";
    string kq = "";
    while (so > 0)
    {
        kq = (char)('0' + so % 10) + kq;
        so /= 10;
    }
    return kq;
}

// Doi chuoi chu so thanh so nguyen. Tra ve false neu chuoi rong, qua dai hoac co ky tu khac so.
bool ChuoiThanhSo(const string &s, int &so)
{
    if (s.size() == 0 || s.size() > 9)
        return false;
    so = 0;
    for (int i = 0; i < (int)s.size(); ++i)
    {
        if (s[i] < '0' || s[i] > '9')
            return false;
        so = so * 10 + (s[i] - '0');
    }
    return true;
}

// Tach mot dong thanh cac truong theo ky tu ngan. Tra ve so truong tach duoc.
// Vi du: "S1|0|A-01-01" voi ngan = '|' -> truong[0]="S1", truong[1]="0", truong[2]="A-01-01"
int TachTruong(const string &dong, char ngan, string truong[], int toiDa)
{
    int dem = 0;
    string tam = "";
    for (int i = 0; i < (int)dong.size(); ++i)
    {
        if (dong[i] == '\r')
            continue; // file Windows co the con '\r' o cuoi dong
        if (dong[i] == ngan)
        {
            if (dem < toiDa)
                truong[dem] = tam;
            ++dem;
            tam = "";
        }
        else
            tam += dong[i];
    }
    if (dem < toiDa)
        truong[dem] = tam;
    ++dem;
    return dem;
}

/* ===================== NGAY THANG ===================== */

// [THANH]
bool NamNhuan(int nam)
{
    return nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0);
}

// [THANH]
int SoNgayTrongThang(int thang, int nam)
{
    if (thang < 1 || thang > 12 || nam <= 0)
        return 0;

    switch (thang)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        if (NamNhuan(nam))
            return 29;
        return 28;
    }
    return 0;
}

// [THANH]
bool NgayHopLe(const NgayThang &ngay)
{
    int soNgay = SoNgayTrongThang(ngay.thang, ngay.nam);
    return soNgay > 0 && ngay.ngay >= 1 && ngay.ngay <= soNgay;
}

// [THANH] Doi mot ngay thanh so ngay tinh tu 01/01/0001.
// @TT Doi ngay ra so ngay tinh tu 01/01/0001 (cong 365/366 tung nam, so ngay tung thang)
long long Doirangay(NgayThang sngay)
{
    long long soNgay = 0;
    for (int i = 1; i < sngay.nam; i++)
    {
        if (NamNhuan(i))
            soNgay += 366;
        else
            soNgay += 365;
    }
    for (int i = 1; i < sngay.thang; i++)
    {
        soNgay += SoNgayTrongThang(i, sngay.nam);
    }
    soNgay = soNgay + sngay.ngay - 1;
    return soNgay;
}

// [THANH] So ngay tu ngayt1 den ngayt2 (am neu ngayt2 truoc ngayt1).
// @TT [f,g,h,i] Khoang cach 2 ngay = Doirangay(ngay 2) - Doirangay(ngay 1)
long long KhoangCachNgay(NgayThang ngayt1, NgayThang ngayt2)
{
    long long i = Doirangay(ngayt1);
    long long j = Doirangay(ngayt2);
    return j - i;
}

// Lay ngay hien tai cua may tinh.
NgayThang HomNay()
{
    time_t t = time(0);
    tm *bayGio = localtime(&t);
    NgayThang d;
    d.ngay = bayGio->tm_mday;
    d.thang = bayGio->tm_mon + 1;
    d.nam = bayGio->tm_year + 1900;
    return d;
}

// Vi du: 5/9/2026 -> "05/09/2026". Ngay rong (chua tra) -> "0/0/0"
string ChuoiNgay(const NgayThang &d)
{
    if (d.ngay == 0 && d.thang == 0 && d.nam == 0)
        return "0/0/0";
    string kq = "";
    if (d.ngay < 10) kq += '0';
    kq += SoThanhChuoi(d.ngay) + "/";
    if (d.thang < 10) kq += '0';
    kq += SoThanhChuoi(d.thang) + "/" + SoThanhChuoi(d.nam);
    return kq;
}

// Doc chuoi dang dd/mm/yyyy. Tra ve false neu sai dinh dang hoac ngay khong ton tai.
// Rieng "0/0/0" duoc chap nhan, nghia la chua co ngay tra.
bool DocNgay(const string &s, NgayThang &d)
{
    string truong[3];
    if (TachTruong(s, '/', truong, 3) != 3)
        return false;
    if (!ChuoiThanhSo(truong[0], d.ngay) || !ChuoiThanhSo(truong[1], d.thang) ||
        !ChuoiThanhSo(truong[2], d.nam))
        return false;
    if (d.ngay == 0 && d.thang == 0 && d.nam == 0)
        return true;
    return NgayHopLe(d);
}
