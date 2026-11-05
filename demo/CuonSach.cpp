#include "00_KhaiBaoChung.h"

// [THAI] Phan code Thai cung cap o commit 5c03ecf; cac dieu chinh demo co nhan ben duoi.
bool HopLeCuonSach(const CuonSach &s, string &loi){
    // [DEMO - CODEX] Kiem tra ma moi va vi tri theo quy uoc cua Thai.
    if (s.maSach.size() < 15 || s.maSach[13] != '#')
    {
        loi = "Ma sach phai dung ISBN#N.";
        return false;
    }
    for (size_t i = 0; i < s.maSach.size(); ++i)
        if (i != 13 && (s.maSach[i] < '0' || s.maSach[i] > '9'))
        {
            loi = "ISBN va so thu tu chi gom chu so.";
            return false;
        }
    int thuTu;
    if (!DocSoNguyen(CatChuoi(s.maSach, 14, string::npos), thuTu, 1, INT_MAX) || !HopLeTrangThaiSach(s.trangThai))
    {
        loi = "So thu tu hoac trang thai cuon sai.";
        return false;
    }
    const string &v = s.viTri;
    int ke, tang;
    if (v.size() != 7 || !((v[0] >= 'A' && v[0] <= 'Z') || (v[0] >= 'a' && v[0] <= 'z')) ||
        v[1] != '-' || v[4] != '-' || !DocSoNguyen(CatChuoi(v, 2, 2), ke, 1, 99) ||
        !DocSoNguyen(CatChuoi(v, 5, 2), tang, 1, 99))
    {
        loi = "Vi tri phai co dang A-01-01 (ke va tang tu 01 den 99).";
        return false;
    }
    loi.clear();
    return true;
}

// [DEMO - CODEX] Phan bo sung cho ban trinh thay.
bool TachMaCuonTuSinh(const string &ma, string &isbn, int &soThuTu)
{
    size_t viTri = ma.size();
    for (size_t i = 0; i < ma.size(); i++)
    {
        if (ma[i] == '#')
        {
            viTri = i;
        }
    }
    if (viTri == 0 || viTri == ma.size() || viTri + 1 == ma.size())
    {
        return false;
    }
    if (ma[viTri + 1] == '0')
    {
        return false;
    }
    isbn = CatChuoi(ma, 0, viTri);
    return DocSoNguyen(CatChuoi(ma, viTri + 1, string::npos), soThuTu, 1, INT_MAX);
}
bool MaCoDauThang(const string &ma)
{
    for (size_t i = 0; i < ma.size(); i++)
    {
        if (ma[i] == '#')
        {
            return true;
        }
    }
    return false;
}
CuonSach *TimCuonSachTrongDauSach(DauSach &sach, const string &ma)
{
    CuonSach *p = sach.dms;
    while (p != nullptr)
    {
        if (p->maSach == ma)
        {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}
const CuonSach *TimCuonSachTrongDauSach(const DauSach &sach, const string &ma)
{
    const CuonSach *p = sach.dms;
    while (p != nullptr)
    {
        if (p->maSach == ma)
        {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}
CuonSach *TimCuonSachToanCuc(ThuVien &tv, const string &ma, DauSach **chuSoHuu)
{
    if (chuSoHuu != nullptr)
    {
        *chuSoHuu = nullptr;
    }
    string isbn;
    int so = 0;
    bool maMoi = MaCoDauThang(ma);
    if (maMoi && !TachMaCuonTuSinh(ma, isbn, so))
    {
        return nullptr;
    }
    for (int i = 0; i < tv.dsDauSach.soLuong; i++)
    {
        DauSach *dauSach = tv.dsDauSach.ds[i];
        if (!maMoi || dauSach->ISBN == isbn)
        {
            CuonSach *cuon = TimCuonSachTrongDauSach(*dauSach, ma);
            if (cuon != nullptr)
            {
                if (chuSoHuu != nullptr)
                {
                    *chuSoHuu = dauSach;
                }
                return cuon;
            }
        }
    }
    return nullptr;
}
const CuonSach *TimCuonSachToanCuc(const ThuVien &tv, const string &ma, const DauSach **chuSoHuu)
{
    if (chuSoHuu != nullptr)
    {
        *chuSoHuu = nullptr;
    }
    string isbn;
    int so = 0;
    bool maMoi = MaCoDauThang(ma);
    if (maMoi && !TachMaCuonTuSinh(ma, isbn, so))
    {
        return nullptr;
    }
    for (int i = 0; i < tv.dsDauSach.soLuong; i++)
    {
        const DauSach *dauSach = tv.dsDauSach.ds[i];
        if (!maMoi || dauSach->ISBN == isbn)
        {
            const CuonSach *cuon = TimCuonSachTrongDauSach(*dauSach, ma);
            if (cuon != nullptr)
            {
                if (chuSoHuu != nullptr)
                {
                    *chuSoHuu = dauSach;
                }
                return cuon;
            }
        }
    }
    return nullptr;
}
bool SinhMaSachTuDong(const ThuVien &tv, const DauSach &sach, string &ma, string &loi)
{
    int lonNhat = 0;
    for (int i = 0; i < tv.dsDauSach.soLuong; i++)
    {
        const CuonSach *p = tv.dsDauSach.ds[i]->dms;
        while (p != nullptr)
        {
            string isbn;
            int so = 0;
            if (TachMaCuonTuSinh(p->maSach, isbn, so) && isbn == sach.ISBN && so > lonNhat)
            {
                lonNhat = so;
            }
            p = p->next;
        }
    }
    if (lonNhat == INT_MAX)
    {
        loi = "Het mien ma cuon.";
        return false;
    }
    string maMoi = sach.ISBN + "#" + ChuoiSo(lonNhat + 1);
    if (!KiemTraVanBanHeThong(maMoi))
    {
        loi = "Ma cuon qua dai.";
        return false;
    }
    ma = maMoi;
    loi.clear();
    return true;
}
bool ThemCuonSach(ThuVien &tv, const string &isbn, const string &viTri, string &ma, string &loi)
{
    if (!KiemTraVanBanHeThong(isbn) || !KiemTraVanBanHeThong(viTri))
    {
        loi = "ISBN/vi tri khong hop le.";
        return false;
    }
    DauSach *sach = TimDauSachTheoISBN(tv.dsDauSach, ChuanHoaChuoiSach(isbn));
    if (sach == nullptr)
    {
        loi = "Khong tim thay ISBN.";
        return false;
    }
    int tong = 0;
    for (int i = 0; i < tv.dsDauSach.soLuong; i++)
    {
        tong += DemCuonSach(tv.dsDauSach.ds[i]->dms);
    }
    if (tong >= MAX_BAN_GHI)
    {
        loi = "Dat gioi han so cuon.";
        return false;
    }
    CuonSach thongTin;
    if (!SinhMaSachTuDong(tv, *sach, thongTin.maSach, loi))
    {
        return false;
    }
    thongTin.viTri = ChuanHoaChuoiSach(viTri);
    if (!HopLeCuonSach(thongTin, loi)) return false;
    CuonSach *moi = new CuonSach(thongTin);
    try
    {
        ma = thongTin.maSach;
    }
    catch (...)
    {
        delete moi;
        throw;
    }
    CuonSach *cuoi = sach->dms;
    if (cuoi == nullptr)
    {
        sach->dms = moi;
    }
    else
    {
        while (cuoi->next != nullptr)
        {
            cuoi = cuoi->next;
        }
        cuoi->next = moi;
    }
    loi.clear();
    return true;
}
void HuyDanhMucCuonSach(CuonSach *&dau)
{
    while (dau != nullptr)
    {
        CuonSach *xoa = dau;
        dau = dau->next;
        delete xoa;
    }
}
int DemCuonSach(const CuonSach *dau)
{
    int soCuon = 0;
    const CuonSach *p = dau;
    while (p != nullptr)
    {
        soCuon++;
        p = p->next;
    }
    return soCuon;
}
