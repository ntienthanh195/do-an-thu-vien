#include "00_KhaiBaoChung.h"

bool KhoangTrang(unsigned char c){
    return c == ' ' || c == '\t' || c == '\r' || c == '\n';
}
bool LaChuoiRong(const string &s){
    for(const char c : s){
        if(!KhoangTrang(c)) return false;
    }
    return true;
}
string ChuanHoaChuoi(const string &s){
    string kq = "";
    bool gap = false; // gap ky tu khac khoang trang
    for(const char c : s){
        if(!KhoangTrang(c)){
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
// string KhoaSoSanh(const string &s)
// {
//     string r = ChuanHoaChuoi(s);
//     for (char &c : r)
//         if (c >= 'A' && c <= 'Z')
//             c = static_cast<char>(c - 'A' + 'a');
//     return r;
// }
// int SoSanhChuoi(const string &a, const string &b)
// {
//     const string x = KhoaSoSanh(a), y = KhoaSoSanh(b);
//     return x < y ? -1 : (x > y ? 1 : 0); // a < b : -1, a > b : 1, a == b : 0
// }
int SoSanhChuoi(const string &a, const string &b){
    // a < b : -1, a > b : 1; a = b : 0
    string x = ChuanHoaChuoi(a);
    string y = ChuanHoaChuoi(b);
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
bool ChuaChuoi(const string &s, const string &part){
    if(part.size() == 0) return true;
    if(s.size() < part.size()) return false;
    // Dau bang xay ra khi vi tri cuoi cung cua s dung voi part 
    // ( vi du : s = "abc", part = "c" thi i = 2 = s.size() - part.size())
    for(size_t i = 0; i <= s.size() - part.size(); ++i){
        bool check = true;
        for(size_t j = 0; j < part.size(); ++j){
            char x = s[i+j], y = part[j];
            if (x >= 'A' && x <= 'Z') x = (char)(x + 32);
            if (y >= 'A' && y <= 'Z') y = (char)(y + 32);
            if(x != y){
                check = false;
                break;
            }
        }
        if(check) return true;
    }
    return false;
}
// bool HopLeVanBan(const string &s)
// {
//     return KiemTraVanBanHeThong(s);
// }
bool HopLeVanBan(const string &s)
{   
    const size_t MAX_VAN_BAN = 100;
    if(s.size() > MAX_VAN_BAN){
        return false;
    }
    if(LaChuoiRong(s)) return false;
    for(const unsigned char c : s){
        if (c == '|')  return false;   // delimiter file
        else if (c == '\\') return false;   // escape char
        else if (c < 32)    return false;   // control char (tab, newline...)
        else if (c == 127)  return false;   // DEL
        else if (c >= 128)  return false;   // khong phai ASCII in duoc
    }
    return true;
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
bool NgayHopLe(const NgayThang &d) {
    if (d.nam <= 0) return false;
    if (d.thang < 1 || d.thang > 12) return false;
    if (d.ngay < 1) return false;
    // Nam khong nhuan
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // Nam nhuan thang 2 co 29 ngay
    if (NamNhuan(d.nam)) {
        daysInMonth[2] = 29;
    }
    if (d.ngay > daysInMonth[d.thang]) return false;
    return true;
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
