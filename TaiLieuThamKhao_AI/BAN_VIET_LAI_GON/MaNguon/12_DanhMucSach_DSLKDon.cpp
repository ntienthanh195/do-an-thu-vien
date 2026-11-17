#include "00_KhaiBaoChung.h"

/* ============================================================
   12. CAU TRUC DU LIEU: DANH MUC SACH (danh sach lien ket don), moi dau sach giu mot danh sach rieng (con tro dms).

   Ma sach tu dong co dang ISBN#N (N = 1, 2, 3...). De yeu cau "danh ma sach tu dong sao cho
   tim thong tin sach theo ma sach nhanh nhat": nho ma sach chua san ISBN nen khi tim mot cuon,
   chuong trinh tach ISBN ra, tim dung dau sach roi chi duyet danh muc cua dau sach do,
   khong phai duyet danh muc cua tat ca dau sach.
   ============================================================ */

// [THAI] Vi tri co dang Khu-Ke-Tang, vi du A-01-01.
bool HopLeViTri(const string &viTri)
{
    if (viTri.size() != 7)
        return false;
    if (viTri[0] < 'A' || viTri[0] > 'Z')
        return false;
    if (viTri[1] != '-' || viTri[4] != '-')
        return false;
    for (int i = 2; i < 7; ++i)
    {
        if (i == 4) continue;
        if (viTri[i] < '0' || viTri[i] > '9')
            return false;
    }
    return true;
}

// Lay phan ISBN dung truoc dau '#'. Tra ve chuoi rong neu ma khong co dau '#'.
string TachISBNTuMaSach(const string &ma)
{
    string isbn = "";
    for (int i = 0; i < (int)ma.size(); ++i)
    {
        if (ma[i] == '#')
            return isbn;
        isbn += ma[i];
    }
    return "";
}

// [THAI] Tim mot cuon trong danh muc cua mot dau sach.
CuonSach *TimCuonSachTrongDauSach(const DauSach &d, const string &ma)
{
    CuonSach *p = d.dms;
    while (p != nullptr)
    {
        if (p->maSach == ma)
            return p;
        p = p->next;
    }
    return nullptr;
}

// [THAI] Tim mot cuon theo ma sach trong ca thu vien.
// dauSach nhan ve dau sach chua cuon do (de lay ten sach).
// @TT [f,g,h,i] Tim cuon theo ma sach: tach ISBN truoc dau #, tim dau sach, roi chi duyet
//         DSLK danh muc cua dau sach do (khong duyet danh muc cua moi dau sach)
CuonSach *TimCuonSachToanCuc(const DanhSachDauSach &ds, const string &ma, DauSach *&dauSach)
{
    dauSach = TimDauSachTheoISBN(ds, TachISBNTuMaSach(ma));
    if (dauSach == nullptr)
        return nullptr;
    return TimCuonSachTrongDauSach(*dauSach, ma);
}

// [THAI] Ma moi = ISBN#(N + 1), voi N la so thu tu cua cuon cuoi danh muc.
// Cuon thanh ly/lam mat chi doi trang thai, khong xoa nut, nen nut cuoi luon co N lon nhat.
// @TT [c] Danh ma sach tu dong ISBN#N: N = so thu tu cuon cuoi danh muc + 1
string SinhMaSachTuDong(const DauSach &d)
{
    int soCuoi = 0;
    CuonSach *p = d.dms;
    while (p != nullptr && p->next != nullptr)
        p = p->next;

    if (p != nullptr)
    {
        string phanSo = "";
        bool quaDauThang = false;
        for (int i = 0; i < (int)p->maSach.size(); ++i)
        {
            if (quaDauThang)
                phanSo += p->maSach[i];
            else if (p->maSach[i] == '#')
                quaDauThang = true;
        }
        ChuoiThanhSo(phanSo, soCuoi);
    }
    return d.ISBN + "#" + SoThanhChuoi(soCuoi + 1);
}

// Them mot cuon co san ma vao cuoi danh muc (dung khi doc file).
// @TT [c] Them cuon vao cuoi DSLK don danh muc sach
void ThemCuonSachCoMa(DauSach &d, const string &ma, const string &viTri, int trangThai)
{
    CuonSach *moi = new CuonSach;
    moi->maSach = ma;
    moi->viTri = viTri;
    moi->trangThai = trangThai;

    if (d.dms == nullptr)
    {
        d.dms = moi;
        return;
    }
    CuonSach *p = d.dms;
    while (p->next != nullptr)
        p = p->next;
    p->next = moi;
}

// Them mot cuon moi, ma sach do chuong trinh tu cap.
void ThemCuonSach(DauSach &d, const string &viTri, int trangThai)
{
    ThemCuonSachCoMa(d, SinhMaSachTuDong(d), viTri, trangThai);
}

// [THAI]
int DemCuonSach(const CuonSach *head)
{
    int dem = 0;
    while (head != nullptr)
    {
        ++dem;
        head = head->next;
    }
    return dem;
}
