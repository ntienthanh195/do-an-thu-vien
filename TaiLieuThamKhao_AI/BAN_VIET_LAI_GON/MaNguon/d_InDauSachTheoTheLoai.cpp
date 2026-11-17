#include "0.0_KhaiBaoChung.h"

/* ============================================================
   d. IN DAU SACH THEO TUNG THE LOAI, trong moi the loai thi ten sach tang dan.

   Mang goc da tang dan theo ten sach va khong duoc doi thu tu. Vi vay chep cac con tro
   sang mot mang tam roi sap mang tam theo the loai bang sap xep chen (insertion sort).
   Sap xep chen la thuat toan on dinh: hai dau sach cung the loai giu nguyen thu tu cu,
   tuc la van tang dan theo ten sach, nen khong can so sanh ten lan nua.

   HAM LAY TU FILE KHAC:
     1.3_DanhMucSach_DSLKDon.cpp: DemCuonSach
   ============================================================ */

/* ===================== XU LY ===================== */

// @TT [d] Sap mang tam theo the loai: Insertion Sort (on dinh nen cung the loai van tang theo ten) - O(n^2)
static void SapXepTheoTheLoai(DauSach *a[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        DauSach *x = a[i];
        int j = i - 1;
        while (j >= 0 && SoSanhChuoi(a[j]->theLoai, x->theLoai) > 0)
        {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = x;
    }
}

/* ===================== GIAO DIEN ===================== */

void ManHinhInDauSachTheoTheLoai(const DanhSachDauSach &ds)
{
    int n = ds.soLuong;
    DauSach **a = new DauSach *[n + 1]; // mang tam, chi giu con tro
    for (int i = 0; i < n; ++i)
        a[i] = ds.ds[i];
    SapXepTheoTheLoai(a, n);

    VeManHinh(4, "Đầu sách theo thể loại", "←/→: chuyển trang    Esc: quay lại");
    SetColor(MAU_VANG_SANG, MAU_DEN);
    InCot(2, 5, "THỂ LOẠI", 16);
    InCot(18, 5, "TÊN SÁCH", 30);
    InCot(48, 5, "ISBN", 15);
    InCot(63, 5, "TÁC GIẢ", 16);
    InCot(79, 5, "NĂM", 6);
    InCot(85, 5, "TRANG", 6);
    InCot(91, 5, "CUỐN", 5);
    SetColor(MAU_TRANG, MAU_DEN);

    int trang = 0;
    while (true)
    {
        XoaVung(0, 7, RONG_MH, SO_DONG_TRANG);
        for (int i = trang * SO_DONG_TRANG; i < n && i < (trang + 1) * SO_DONG_TRANG; ++i)
        {
            int y = 7 + i - trang * SO_DONG_TRANG;
            // chi in ten the loai o dong dau cua moi nhom (va dong dau moi trang)
            if (i == trang * SO_DONG_TRANG || SoSanhChuoi(a[i]->theLoai, a[i - 1]->theLoai) != 0)
            {
                SetColor(MAU_NGOC_SANG, MAU_DEN);
                InCot(2, y, a[i]->theLoai, 16);
                SetColor(MAU_TRANG, MAU_DEN);
            }
            InCot(18, y, a[i]->tenSach, 30);
            InCot(48, y, a[i]->ISBN, 15);
            InCot(63, y, a[i]->tacGia, 16);
            InCot(79, y, SoThanhChuoi(a[i]->namXuatBan), 6);
            InCot(85, y, SoThanhChuoi(a[i]->soTrang), 6);
            InCot(91, y, SoThanhChuoi(DemCuonSach(a[i]->dms)), 5);
        }
        if (n == 0)
            InTai(2, 7, "Thư viện chưa có đầu sách nào.");
        InSoTrang(trang, n);

        int phim = DocPhim();
        while (phim != PHIM_ESC && !XuLyPhimTrang(phim, trang, n))
            phim = DocPhim();
        if (phim == PHIM_ESC)
            break;
    }
    delete[] a;
}
