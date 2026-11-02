#include "00_KhaiBaoChung.h"

// Khong dung find/rfind: tu xac dinh dau # cuoi cung de tach ma.
bool TachMaMoi(const string &ma, string &isbn, int &so)
{
    string::size_type pos = string::npos;
    for (string::size_type i = 0; i < ma.size(); ++i)
        if (ma[i] == '#')
            pos = i;
    if (pos == string::npos || pos == 0 || pos + 1 == ma.size())
        return false;
    isbn = ma.substr(0, pos);
    string suffix = ma.substr(pos + 1);
    // Ma tu sinh la so duong o dang chuan, khong dau +, khong so 0 dau.
    if (suffix[0] == '0')
        return false;
    for (char c : suffix)
        if (c < '0' || c > '9')
            return false;
    return DocSoNguyen(suffix, so, 1, SO_NGUYEN_LON_NHAT);
}
CuonSach *TimCuonSachTrongDauSach(DauSach &d, const string &ma)
{
    for (CuonSach *p = d.dms; p; p = p->next)
        if (p->maSach == ma)
            return p;
    return nullptr;
}
const CuonSach *TimCuonSachTrongDauSach(const DauSach &d, const string &ma){
    if(LaChuoiRong(ma)) return nullptr;
    const CuonSach *p = d.dms;
    while(p != nullptr){
        if(p->maSach == ma) return p;
        p = p->next;
    }
    return nullptr;
}
const CuonSach *TimCuonSachToanCuc(const ThuVien &tv, const string &ma, const DauSach **owner){
    if(LaChuoiRong(ma)) return nullptr;
    // 1. Tach 13 so dau tien lam ISBN
    string ISBN_trong_Ma = "";
    for(const char c : ma){
        if(ISBN_trong_Ma.size() < 13){
            if(c >= '0' && c <= '9'){
                ISBN_trong_Ma += c;
            }
            else if(!KhoangTrang(c)){ // Neu gap ky tu la (gach ngang, #...)
                return nullptr;       // -> Sai quy uoc
            }
        }
    }
    if(ISBN_trong_Ma.size() < 13) return nullptr;
    // 2. Tim dau sach theo ISBN
    const string ch_ma = ChuanHoaChuoi(ma);
    for(int i = 0; i < tv.dsDauSach.soLuong; ++i){
        if(tv.dsDauSach.ds[i] == nullptr) continue; // Chong crash
        
        if(tv.dsDauSach.ds[i]->ISBN == ISBN_trong_Ma){
            // can biet ca dau sach chua cuon sach
            if(owner != nullptr){
                *owner = tv.dsDauSach.ds[i];
            }
            
            return TimCuonSachTrongDauSach(*(tv.dsDauSach.ds[i]), ch_ma);
        }
    }
    return nullptr;
}
CuonSach *TimCuonSachToanCuc(ThuVien &tv, const string &ma, DauSach **owner)
{
    // const_cast an toan o wrapper nay: doi tuong dau vao thuc su la ThuVien mutable.
    const DauSach *d = nullptr;
    const CuonSach *p = TimCuonSachToanCuc(static_cast<const ThuVien &>(tv), ma, &d);
    if (owner)
        *owner = const_cast<DauSach *>(d);
    return const_cast<CuonSach *>(p);
}

bool SinhMaSachTuDong(const ThuVien &tv, const DauSach &d, string &ma, string &loi)
{
    // Lay max, KHONG lay so nut+1: ma cu/file nhap co the co khoang trong.
    // Quet toan cuc de tranh trung ngay ca khi ma o sai chu so huu trong bo nho.
    int maxSo = 0;
    for (int i = 0; i < tv.dsDauSach.soLuong; ++i)
        for (const CuonSach *p = tv.dsDauSach.ds[i]->dms; p; p = p->next)
        {
            string isbn;
            int so = 0;
            if (TachMaMoi(p->maSach, isbn, so) && isbn == d.ISBN && so > maxSo)
                maxSo = so;
        }
    if (maxSo == SO_NGUYEN_LON_NHAT)
    {
        loi = "Da het mien so thu tu ma cuon.";
        return false;
    }
    string ketQua = d.ISBN + "#" + to_string(maxSo + 1);
    // ISBN hop le co the da du 512 byte: ma cuon them #N van phai luu/doc duoc.
    if (!HopLeVanBan(ketQua))
    {
        loi = "Ma cuon sinh ra vuot gioi han 512 byte; ISBN qua dai.";
        return false;
    }
    ma = ketQua;
    loi.clear();
    return true;
}
bool ThemCuonSach(ThuVien &tv, const string &isbn, const string &viTri, string &ma, string &loi)
{
    try
    {
        // Kiem tra truoc khi rut gon khoang trang: khong bien tab/newline thanh du lieu hop le.
        if (!HopLeVanBan(isbn) || !HopLeVanBan(viTri))
        {
            loi = "ISBN/vi tri phai khong rong, toi da 512 byte, khong ky tu dieu khien/|.";
            return false;
        }
        DauSach *d = TimDauSachTheoISBN(tv.dsDauSach, ChuanHoaChuoi(isbn));
        if (!d)
        {
            loi = "Khong tim thay dau sach theo ISBN.";
            return false;
        }
        string pos = ChuanHoaChuoi(viTri);
        if (!HopLeVanBan(pos))
        {
            loi = "Vi tri phai khong rong, khong ky tu dieu khien/|.";
            return false;
        }
        int tong = 0;
        for (int i = 0; i < tv.dsDauSach.soLuong; ++i)
            for (const CuonSach *p = tv.dsDauSach.ds[i]->dms; p; p = p->next)
                if (++tong >= MAX_BAN_GHI)
                {
                    loi = "Da dat gioi han so cuon cua ban tham khao.";
                    return false;
                }
        string maMoi;
        if (!SinhMaSachTuDong(tv, *d, maMoi, loi))
            return false;
        CuonSach thongTin;
        thongTin.maSach = maMoi;
        thongTin.viTri = pos;
        CuonSach *moi = new CuonSach(thongTin);
        // Doi chuoi khong cap phat: chi tra ma moi khi da tao duoc node.
        ma.swap(maMoi);
        if (d->dms == NULL)
        {
            d->dms = moi;
        }
        else
        {
            CuonSach *cuoi = d->dms;
            while (cuoi->next != NULL)
                cuoi = cuoi->next;
            cuoi->next = moi;
        }
        loi.clear();
        return true;
    }
    catch (...)
    {
        loi = "Khong du bo nho de them cuon; du lieu khong doi.";
        return false;
    }
}

void HuyDanhMucCuonSach(CuonSach *&head)
{
    while (head)
    {
        CuonSach *next = head->next;
        delete head;
        head = next;
    }
}
int DemCuonSach(const CuonSach *head)
{
    int n = 0;
    for (const CuonSach *p = head; p; p = p->next)
        ++n;
    return n;
}
