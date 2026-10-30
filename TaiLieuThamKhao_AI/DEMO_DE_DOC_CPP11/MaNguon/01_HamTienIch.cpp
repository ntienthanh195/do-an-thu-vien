#include "00_KhaiBaoChung.h"

namespace
{
bool KhoangTrang(unsigned char c)
{
    return c == ' ' || c == '\t' || c == '\r' || c == '\n';
}
} // namespace
bool LaChuoiRong(const string &s)
{
    for (unsigned char c : s)
        if (!KhoangTrang(c))
            return false;
    return true;
}
string ChuanHoaChuoi(const string &s)
{
    string r;
    bool gap = false;
    for (unsigned char c : s)
    {
        if (KhoangTrang(c))
        {
            if (!r.empty())
                gap = true;
        }
        else
        {
            if (gap) r += ' ';
            r += static_cast<char>(c);
            gap = false;
        }
    }
    return r;
}
string KhoaSoSanh(const string &s)
{
    string r = ChuanHoaChuoi(s);
    for (char &c : r)
        if (c >= 'A' && c <= 'Z')
            c = static_cast<char>(c - 'A' + 'a');
    return r;
}
int SoSanhChuoi(const string &a, const string &b)
{
    const string x = KhoaSoSanh(a), y = KhoaSoSanh(b);
    return x < y ? -1 : (x > y ? 1 : 0); // a < b : -1, a > b : 1, a == b : 0
}
bool ChuaChuoi(const string &s, const string &part)
{
    const string a = KhoaSoSanh(s), b = KhoaSoSanh(part);
    if (b.empty())
        return false;
    if (b.size() > a.size())
        return false;
    for (size_t i = 0; i <= a.size() - b.size(); ++i)
    {
        size_t j = 0;
        while (j < b.size() && a[i + j] == b[j])
            ++j;
        if (j == b.size())
            return true;
    }
    return false;
}
bool HopLeVanBan(const string &s)
{
    return KiemTraVanBanHeThong(s);
}
bool DocSoNguyen(const string &s, int &value, int lo, int hi)
{
    if (s.empty() || lo < 0 || hi < lo)
        return false;
    int n = 0;
    for (char c : s)
    {
        if (c < '0' || c > '9')
            return false;
        int d = c - '0';
        if (n > hi / 10 || (n == hi / 10 && d > hi % 10))
            return false;
        n = n * 10 + d;
    }
    if (n < lo)
        return false;
    value = n;
    return true;
}
bool TachTruong(const string &line, string *out, int count)
{
    if (count <= 0)
        return false;
    int k = 0;
    string value;
    for (char c : line)
    {
        if (c == '|')
        {
            if (k >= count - 1 || value.empty())
                return false;
            out[k++] = value;
            value.clear();
        }
        else
            value += c;
    }
    if (k != count - 1 || value.empty())
        return false;
    out[k] = value;
    return true;
}
bool NamNhuan(int y)
{
    return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}
bool NgayRong(const NgayThang &d)
{
    return d.ngay == 0 && d.thang == 0 && d.nam == 0;
}
bool NgayHopLe(const NgayThang &d)
{
    static const int ngayThang[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (d.nam < 1 || d.nam > 9999 || d.thang < 1 || d.thang > 12)
        return false;
    int max = ngayThang[d.thang - 1] + (d.thang == 2 && NamNhuan(d.nam) ? 1 : 0);
    return d.ngay >= 1 && d.ngay <= max;
}
bool DocNgay(const string &s, NgayThang &d)
{
    int part[3]{};
    int k = 0;
    string v;
    for (char c : s)
    {
        if (c == '/')
        {
            if (k >= 2 || !DocSoNguyen(v, part[k], 0, 9999))
                return false;
            ++k;
            v.clear();
        }
        else
            v += c;
    }
    if (k != 2 || !DocSoNguyen(v, part[2], 0, 9999))
        return false;
    NgayThang x{part[0], part[1], part[2]};
    if (!NgayHopLe(x) && !(s == "0/0/0"))
        return false;
    d = x;
    return true;
}
string ChuoiNgay(const NgayThang &d)
{
    if (NgayRong(d))
        return "0/0/0";
    string ngay = to_string(d.ngay), thang = to_string(d.thang), nam = to_string(d.nam);
    while (ngay.size() < 2)
        ngay = "0" + ngay;
    while (thang.size() < 2)
        thang = "0" + thang;
    while (nam.size() < 4)
        nam = "0" + nam;
    return ngay + "/" + thang + "/" + nam;
}
int SoThuTuNgay(const NgayThang &d)
{
    if (!NgayHopLe(d))
        throw LoiThuVien("Khong tinh ngay khong hop le / 0/0/0");
    static const int truocThang[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    int y = d.nam - 1;
    return 365 * y + y / 4 - y / 100 + y / 400 + truocThang[d.thang - 1] + d.ngay +
           (d.thang > 2 && NamNhuan(d.nam) ? 1 : 0);
}
int KhoangCachNgay(const NgayThang &a, const NgayThang &b)
{
    return SoThuTuNgay(b) - SoThuTuNgay(a);
}
NgayThang HomNay()
{
    SYSTEMTIME now;
    GetLocalTime(&now);
    return NgayThang(now.wDay, now.wMonth, now.wYear);
}
bool QuaHan7Ngay(const NgayThang &a, const NgayThang &b)
{
    return NgayHopLe(a) && NgayHopLe(b) && KhoangCachNgay(a, b) > 7;
}
bool HopLePhai(const string &s)
{
    return s == "Nam" || s == u8"Nữ";
}
bool HopLeTrangThaiThe(int x)
{
    return x == 0 || x == 1;
}
bool HopLeTrangThaiSach(int x)
{
    return x >= 0 && x <= 2;
}
bool HopLeTrangThaiMuonTra(int x)
{
    return x >= 0 && x <= 2;
}
