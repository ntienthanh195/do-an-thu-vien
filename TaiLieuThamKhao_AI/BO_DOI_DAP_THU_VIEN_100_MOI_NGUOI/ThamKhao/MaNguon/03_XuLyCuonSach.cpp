#include "00_KhaiBaoChung.h"
#include <memory>
#include <limits>
#include <exception>

namespace {
// Khong dung find/rfind: tu xac dinh dau # cuoi cung de tach ma.
bool TachMaMoi(const string& ma,string& isbn,int& so) {
    string::size_type pos=string::npos;
    for(string::size_type i=0;i<ma.size();++i) if(ma[i]=='#') pos=i;
    if(pos==string::npos || pos==0 || pos+1==ma.size()) return false;
    isbn=ma.substr(0,pos);
    string suffix=ma.substr(pos+1);
    // Ma tu sinh la so duong o dang chuan, khong dau +, khong so 0 dau.
    if(suffix[0]=='0') return false;
    for(char c:suffix) if(c<'0'||c>'9') return false;
    return DocSoNguyen(suffix,so,1,std::numeric_limits<int>::max());
}
}

CuonSach* TimCuonSachTrongDauSach(DauSach& d,const string& ma) {
    for(CuonSach* p=d.dms;p;p=p->next) if(p->maSach==ma) return p;
    return nullptr;
}
const CuonSach* TimCuonSachTrongDauSach(const DauSach& d,const string& ma) {
    for(const CuonSach* p=d.dms;p;p=p->next) if(p->maSach==ma) return p;
    return nullptr;
}

const CuonSach* TimCuonSachToanCuc(const ThuVien& tv,const string& ma,const DauSach** owner) {
    if(owner) *owner=nullptr;
    string isbn; int so=0;
    if(TachMaMoi(ma,isbn,so)) {
        const DauSach* d=TimDauSachTheoISBN(tv.dsDauSach,isbn);
        if(d) {
            const CuonSach* p=TimCuonSachTrongDauSach(*d,ma);
            if(p) { if(owner) *owner=d; return p; }
        }
        // Ma ISBN#N co y nghia chu so huu. Khong tra nham sang dau sach khac.
        return nullptr;
    }
    // Co # nhung khong dung dang ma moi thi khong coi la ma legacy.
    for(char ch:ma) if(ch=='#') return nullptr;
    // Ho tro ma cu nhom da co (S001...). Khong suy ISBN tu tien to ma cu.
    for(int i=0;i<tv.dsDauSach.soLuong;++i) {
        const CuonSach* p=TimCuonSachTrongDauSach(*tv.dsDauSach.ds[i],ma);
        if(p) { if(owner) *owner=tv.dsDauSach.ds[i]; return p; }
    }
    return nullptr;
}
CuonSach* TimCuonSachToanCuc(ThuVien& tv,const string& ma,DauSach** owner) {
    // const_cast an toan o wrapper nay: doi tuong dau vao thuc su la ThuVien mutable.
    const DauSach* d=nullptr;
    const CuonSach* p=TimCuonSachToanCuc(static_cast<const ThuVien&>(tv),ma,&d);
    if(owner) *owner=const_cast<DauSach*>(d);
    return const_cast<CuonSach*>(p);
}

bool SinhMaSachTuDong(const ThuVien& tv,const DauSach& d,string& ma,string& loi) {
    // Lay max, KHONG lay so nut+1: ma cu/file nhap co the co khoang trong.
    // Quet toan cuc de tranh trung ngay ca khi ma o sai chu so huu trong bo nho.
    int maxSo=0;
    for(int i=0;i<tv.dsDauSach.soLuong;++i) for(const CuonSach* p=tv.dsDauSach.ds[i]->dms;p;p=p->next) {
        string isbn; int so=0;
        if(TachMaMoi(p->maSach,isbn,so) && isbn==d.ISBN && so>maxSo) maxSo=so;
    }
    if(maxSo==std::numeric_limits<int>::max()) { loi="Da het mien so thu tu ma cuon."; return false; }
    string ketQua=d.ISBN+"#"+std::to_string(maxSo+1);
    // ISBN hop le co the da du 512 byte: ma cuon them #N van phai luu/doc duoc.
    if(!HopLeVanBan(ketQua)) { loi="Ma cuon sinh ra vuot gioi han 512 byte; ISBN qua dai."; return false; }
    ma=ketQua; loi.clear(); return true;
}

bool ThemCuonSach(ThuVien& tv,const string& isbn,const string& viTri,string& ma,string& loi) {
    try {
        // Kiem tra truoc khi rut gon khoang trang: khong bien tab/newline thanh du lieu hop le.
        if(!HopLeVanBan(isbn) || !HopLeVanBan(viTri)) {
            loi="ISBN/vi tri phai khong rong, toi da 512 byte, khong ky tu dieu khien/|."; return false;
        }
        DauSach* d=TimDauSachTheoISBN(tv.dsDauSach,ChuanHoaChuoi(isbn));
        if(!d) { loi="Khong tim thay dau sach theo ISBN."; return false; }
        string pos=ChuanHoaChuoi(viTri);
        if(!HopLeVanBan(pos)) { loi="Vi tri phai khong rong, khong ky tu dieu khien/|."; return false; }
        int tong=0;
        for(int i=0;i<tv.dsDauSach.soLuong;++i) for(const CuonSach* p=tv.dsDauSach.ds[i]->dms;p;p=p->next)
            if(++tong>=MAX_BAN_GHI) { loi="Da dat gioi han so cuon cua ban tham khao."; return false; }
        string maMoi;
        if(!SinhMaSachTuDong(tv,*d,maMoi,loi)) return false;
        std::unique_ptr<CuonSach> moi(new CuonSach);
        moi->maSach=maMoi; moi->viTri=pos;
        // Gan gia tri output truoc khi commit de loi cap phat string khong tao nua giao dich.
        ma=maMoi;
        CuonSach** tail=&d->dms;
        while(*tail) tail=&(*tail)->next;
        *tail=moi.release(); loi.clear(); return true;
    } catch(const std::exception&) { loi="Khong du bo nho de them cuon; du lieu khong doi."; return false; }
}

void HuyDanhMucCuonSach(CuonSach*& head) {
    while(head) { CuonSach* next=head->next; delete head; head=next; }
}
int DemCuonSach(const CuonSach* head) {
    int n=0; for(const CuonSach* p=head;p;p=p->next) ++n; return n;
}
