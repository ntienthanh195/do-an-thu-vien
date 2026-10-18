#include "00_KhaiBaoChung.h"
#include <ctime>
#include <iomanip>
#include <sstream>
#include <stdexcept>

namespace {
bool KhoangTrang(unsigned char c) { return c==' ' || c=='\t' || c=='\r' || c=='\n'; }
}
bool LaChuoiRong(const string& s) {
    for (unsigned char c:s) if (!KhoangTrang(c)) return false;
    return true;
}
string ChuanHoaChuoi(const string& s) {
    string r; bool gap=false;
    for (unsigned char c:s) {
        if (KhoangTrang(c)) { if (!r.empty()) gap=true; }
        else { if (gap) r+=' '; r+=static_cast<char>(c); gap=false; }
    }
    return r;
}
string KhoaSoSanh(const string& s) {
    string r=ChuanHoaChuoi(s);
    for (char& c:r) if (c>='A' && c<='Z') c=static_cast<char>(c-'A'+'a');
    return r;
}
int SoSanhChuoi(const string& a,const string& b) {
    const string x=KhoaSoSanh(a), y=KhoaSoSanh(b);
    return x<y ? -1 : (x>y ? 1 : 0);
}
bool ChuaChuoi(const string& s,const string& part) {
    const string a=KhoaSoSanh(s), b=KhoaSoSanh(part);
    if (b.empty()) return false;
    if (b.size()>a.size()) return false;
    for (std::size_t i=0;i<=a.size()-b.size();++i) {
        std::size_t j=0;
        while (j<b.size() && a[i+j]==b[j]) ++j;
        if (j==b.size()) return true;
    }
    return false;
}
bool HopLeVanBan(const string& s) {
    if (LaChuoiRong(s) || s.size()>512) return false;
    // Kiem tra UTF-8 that, khong chi chap nhan byte bat ky.
    for (std::size_t i=0;i<s.size();) {
        unsigned char c=static_cast<unsigned char>(s[i]);
        if (c<128) { if (c<32 || c==127 || c=='|') return false; ++i; continue; }
        int n=0; unsigned int cp=0;
        if (c>=0xC2 && c<=0xDF) { n=2; cp=c&31U; }
        else if (c>=0xE0 && c<=0xEF) { n=3; cp=c&15U; }
        else if (c>=0xF0 && c<=0xF4) { n=4; cp=c&7U; }
        else return false;
        if (i+static_cast<std::size_t>(n)>s.size()) return false;
        for (int k=1;k<n;++k) {
            unsigned char b=static_cast<unsigned char>(s[i+static_cast<std::size_t>(k)]);
            if ((b&0xC0U)!=0x80U) return false;
            cp=(cp<<6U)|(b&63U);
        }
        if ((n==3 && cp<0x800) || (n==4 && cp<0x10000) || cp>0x10FFFF ||
            (cp>=0xD800 && cp<=0xDFFF) || cp==0xFEFF || (cp>=0x80 && cp<=0x9F)) return false;
        i+=static_cast<std::size_t>(n);
    }
    return true;
}
bool DocSoNguyen(const string& s,int& value,int lo,int hi) {
    if (s.empty() || lo<0 || hi<lo) return false;
    int n=0;
    for (char c:s) {
        if (c<'0'||c>'9') return false;
        int d=c-'0';
        if (n>hi/10 || (n==hi/10 && d>hi%10)) return false;
        n=n*10+d;
    }
    if (n<lo) return false;
    value=n; return true;
}
bool TachTruong(const string& line,string* out,int count) {
    if (count<=0) return false;
    int k=0; string value;
    for (char c:line) {
        if (c=='|') { if (k>=count-1 || value.empty()) return false; out[k++]=value; value.clear(); }
        else value+=c;
    }
    if (k!=count-1 || value.empty()) return false;
    out[k]=value; return true;
}
bool NamNhuan(int y) { return y%400==0 || (y%4==0 && y%100!=0); }
bool NgayRong(const NgayThang& d) { return d.ngay==0 && d.thang==0 && d.nam==0; }
bool NgayHopLe(const NgayThang& d) {
    static const int ngayThang[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if (d.nam<1 || d.nam>9999 || d.thang<1 || d.thang>12) return false;
    int max=ngayThang[d.thang-1]+(d.thang==2 && NamNhuan(d.nam) ? 1:0);
    return d.ngay>=1 && d.ngay<=max;
}
bool DocNgay(const string& s,NgayThang& d) {
    int part[3]{}; int k=0; string v;
    for (char c:s) {
        if (c=='/') { if(k>=2 || !DocSoNguyen(v,part[k],0,9999)) return false; ++k; v.clear(); }
        else v+=c;
    }
    if (k!=2 || !DocSoNguyen(v,part[2],0,9999)) return false;
    NgayThang x{part[0],part[1],part[2]};
    if (!NgayHopLe(x) && !(s=="0/0/0")) return false;
    d=x; return true;
}
string ChuoiNgay(const NgayThang& d) {
    if (NgayRong(d)) return "0/0/0";
    std::ostringstream out;
    out<<std::setfill('0')<<std::setw(2)<<d.ngay<<'/'<<std::setw(2)<<d.thang<<'/'<<std::setw(4)<<d.nam;
    return out.str();
}
int SoThuTuNgay(const NgayThang& d) {
    if (!NgayHopLe(d)) throw std::invalid_argument("Khong tinh ngay khong hop le / 0/0/0");
    static const int truocThang[]={0,31,59,90,120,151,181,212,243,273,304,334};
    int y=d.nam-1;
    return 365*y+y/4-y/100+y/400+truocThang[d.thang-1]+d.ngay+(d.thang>2 && NamNhuan(d.nam)?1:0);
}
int KhoangCachNgay(const NgayThang& a,const NgayThang& b) { return SoThuTuNgay(b)-SoThuTuNgay(a); }
NgayThang HomNay() {
    std::time_t t=std::time(nullptr); std::tm* p=std::localtime(&t);
    if (!p) throw std::runtime_error("Khong doc duoc dong ho he thong");
    return NgayThang{p->tm_mday,p->tm_mon+1,p->tm_year+1900};
}
bool QuaHan7Ngay(const NgayThang& a,const NgayThang& b) {
    return NgayHopLe(a) && NgayHopLe(b) && KhoangCachNgay(a,b)>7;
}
bool HopLePhai(const string& s) { return s=="Nam" || s==u8"Nữ"; }
bool HopLeTrangThaiThe(int x) { return x==0 || x==1; }
bool HopLeTrangThaiSach(int x) { return x>=0 && x<=2; }
bool HopLeTrangThaiMuonTra(int x) { return x>=0 && x<=2; }
