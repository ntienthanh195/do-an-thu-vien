#include "00_KhaiBaoChung.h"

/* ============================================================
   11. CAU TRUC DU LIEU: DANH SACH DAU SACH (danh sach tuyen tinh = mang con tro)
   File nay chi chua cac thao tac tren mang. Man hinh nhap sach nam o c_NhapSach.cpp.

   Danh sach dau sach la mang con tro, luon tang dan theo ten sach.
   Khi them: tim vi tri chen bang tim kiem nhi phan, doi cac con tro phia sau
   sang phai mot o roi dat con tro moi vao.
   ============================================================ */

// [THAI]
bool HopLeDauSach(const DauSach &d, string &loi)
{
    if (d.ISBN.size() != 13)
    {
        loi = "ISBN phải gồm đúng 13 chữ số.";
        return false;
    }
    for (int i = 0; i < 13; ++i)
    {
        if (d.ISBN[i] < '0' || d.ISBN[i] > '9')
        {
            loi = "ISBN phải gồm đúng 13 chữ số.";
            return false;
        }
    }
    if (!HopLeVanBan(d.tenSach))
    {
        loi = "Tên sách không hợp lệ.";
        return false;
    }
    if (d.soTrang < 1)
    {
        loi = "Số trang phải lớn hơn 0.";
        return false;
    }
    if (!HopLeVanBan(d.tacGia))
    {
        loi = "Tên tác giả không hợp lệ.";
        return false;
    }
    // Chi kiem nam > 0. Dieu kien "khong vuot qua nam hien tai" nam o man hinh nhap,
    // vi ham nay con duoc goi khi doc file: neu dong ho may bi dat lui nam thi
    // khong duoc coi file hop le la file hong.
    if (d.namXuatBan < 1)
    {
        loi = "Năm xuất bản phải lớn hơn 0.";
        return false;
    }
    if (!HopLeVanBan(d.theLoai))
    {
        loi = "Thể loại không hợp lệ.";
        return false;
    }
    return true;
}

// Mang sap theo ten sach chu khong theo ISBN nen phai tim tuyen tinh.
// Tra ve chi so trong mang, -1 neu khong co.
// @TT [c,e,f,g,h,i,j] Tim dau sach theo ISBN: tim tuyen tinh vi mang sap theo ten, khong theo ISBN - O(n)
int TimViTriDauSachTheoISBN(const DanhSachDauSach &ds, const string &isbn)
{
    for (int i = 0; i < ds.soLuong; ++i)
    {
        if (ds.ds[i]->ISBN == isbn)
            return i;
    }
    return -1;
}

// [THAI]
DauSach *TimDauSachTheoISBN(const DanhSachDauSach &ds, const string &isbn)
{
    int viTri = TimViTriDauSachTheoISBN(ds, isbn);
    if (viTri == -1)
        return nullptr;
    return ds.ds[viTri];
}

// [THAI] Tim kiem nhi phan: vi tri dau tien co ten sach >= ten sach moi.
// @TT [c] Tim vi tri chen theo ten sach: tim kiem nhi phan (vi tri dau tien >= ten moi) - O(log n)
int TimViTriChenTheoTen(const DanhSachDauSach &ds, const DauSach &d)
{
    int l = 0;
    int r = ds.soLuong;
    while (l < r)
    {
        int m = (l + r) / 2;
        if (SoSanhChuoi(ds.ds[m]->tenSach, d.tenSach) < 0)
            l = m + 1; // ds[m] < d  -> chen sau m
        else
            r = m;     // ds[m] >= d -> chen tai m hoac truoc m
    }
    return l;
}

// [THAI] Them mot dau sach va giu mang tang dan theo ten sach.
// @TT [c] Them dau sach giu mang tang theo ten: tim vi tri bang nhi phan, doi con tro sang phai 1 o - O(n)
bool ThemDauSach(DanhSachDauSach &ds, const DauSach &d, string &loi)
{
    if (ds.soLuong >= MAX_DAU_SACH)
    {
        loi = "Danh sách đầu sách đã đầy.";
        return false;
    }
    if (!HopLeDauSach(d, loi))
        return false;
    if (TimDauSachTheoISBN(ds, d.ISBN) != nullptr)
    {
        loi = "ISBN đã tồn tại, không thể thêm trùng.";
        return false;
    }

    int viTriChen = TimViTriChenTheoTen(ds, d);
    for (int i = ds.soLuong; i > viTriChen; --i)
        ds.ds[i] = ds.ds[i - 1];

    ds.ds[viTriChen] = new DauSach;
    *ds.ds[viTriChen] = d;
    ds.ds[viTriChen]->dms = nullptr;
    ++ds.soLuong;
    return true;
}

// Giai phong tat ca dau sach va danh muc cuon sach cua chung.
void HuyDanhSachDauSach(DanhSachDauSach &ds)
{
    for (int i = 0; i < ds.soLuong; ++i)
    {
        CuonSach *p = ds.ds[i]->dms;
        while (p != nullptr)
        {
            CuonSach *xoa = p;
            p = p->next;
            delete xoa;
        }
        delete ds.ds[i];
    }
    ds.soLuong = 0;
}
