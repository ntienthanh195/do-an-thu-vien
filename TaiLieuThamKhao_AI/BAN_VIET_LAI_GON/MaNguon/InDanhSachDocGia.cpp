#include "00_KhaiBaoChung.h"

/* ============================================================
   b. IN DANH SACH DOC GIA theo ten + ho tang dan, hoac theo ma the tang dan.

   - Theo ma the: duyet cay theo thu tu giua (LNR) la co san thu tu tang dan.
   - Theo ten + ho: cay chi sap theo ma the, nen lay dia chi cac nut ra mot mang tam
     roi sap mang tam bang Quick Sort. Cay khong bi thay doi.
   ============================================================ */

// So sanh hai doc gia theo ten, neu trung ten thi theo ho.
static int SoSanhTenHo(const NutDocGia *a, const NutDocGia *b)
{
    int kq = SoSanhChuoi(a->thongTin.ten, b->thongTin.ten);
    if (kq != 0)
        return kq;
    return SoSanhChuoi(a->thongTin.ho, b->thongTin.ho);
}

// Quick Sort tren mang con tro, lay phan tu giua lam chot.
static void SapXepTheoTenHo(NutDocGia *a[], int trai, int phai)
{
    if (trai >= phai)
        return;
    NutDocGia *chot = a[(trai + phai) / 2];
    int i = trai, j = phai;
    while (i <= j)
    {
        while (SoSanhTenHo(a[i], chot) < 0) ++i;
        while (SoSanhTenHo(a[j], chot) > 0) --j;
        if (i <= j)
        {
            NutDocGia *tam = a[i];
            a[i] = a[j];
            a[j] = tam;
            ++i;
            --j;
        }
    }
    SapXepTheoTenHo(a, trai, j);
    SapXepTheoTenHo(a, i, phai);
}

void ManHinhInDanhSachDocGia(CayDocGia &cay)
{
    string muc[2] = {"1. Theo ten + ho tang dan", "2. Theo ma the tang dan"};
    while (true)
    {
        VeManHinh("b. IN DANH SACH DOC GIA", "Len/Xuong: chon    Enter: xem    Esc: quay lai");
        int kieu = ChonMenu(4, 5, 34, muc, 2);
        if (kieu == -1)
            return;

        int n = DemDocGia(cay);
        NutDocGia **a = new NutDocGia *[n + 1]; // mang tam, chi giu con tro
        LayDanhSachDocGia(cay, a, n);
        if (kieu == 0)
            SapXepTheoTenHo(a, 0, n - 1);

        if (kieu == 0)
            VeManHinh("b. DANH SACH DOC GIA THEO TEN + HO", "Trai/Phai: chuyen trang    Esc: quay lai");
        else
            VeManHinh("b. DANH SACH DOC GIA THEO MA THE", "Trai/Phai: chuyen trang    Esc: quay lai");
        SetColor(MAU_VANG_SANG, MAU_DEN);
        InCot(2, 5, "STT", 6);
        InCot(8, 5, "MA THE", 10);
        InCot(18, 5, "HO", 32);
        InCot(50, 5, "TEN", 18);
        InCot(68, 5, "PHAI", 8);
        InCot(76, 5, "TRANG THAI THE", 18);
        InCot(94, 5, "DANG MUON", 10);
        SetColor(MAU_TRANG, MAU_DEN);

        int trang = 0;
        while (true)
        {
            XoaVung(0, 7, RONG_MH, SO_DONG_TRANG);
            for (int i = trang * SO_DONG_TRANG; i < n && i < (trang + 1) * SO_DONG_TRANG; ++i)
            {
                int y = 7 + i - trang * SO_DONG_TRANG;
                const DocGia &dg = a[i]->thongTin;
                InCot(2, y, SoThanhChuoi(i + 1), 6);
                InCot(8, y, SoThanhChuoi(dg.maThe), 10);
                InCot(18, y, dg.ho, 32);
                InCot(50, y, dg.ten, 18);
                InCot(68, y, dg.phai, 8);
                if (dg.trangThaiThe == THE_HOAT_DONG)
                    InCot(76, y, "Hoat dong", 18);
                else
                {
                    SetColor(MAU_DO_SANG, MAU_DEN);
                    InCot(76, y, "Bi khoa", 18);
                    SetColor(MAU_TRANG, MAU_DEN);
                }
                InCot(94, y, SoThanhChuoi(Dem_so_sach_dang_muon(*a[i])), 10);
            }
            if (n == 0)
                InTai(2, 7, "Chua co doc gia nao.");
            InSoTrang(trang, n);

            int phim = DocPhim();
            while (phim != PHIM_ESC && !XuLyPhimTrang(phim, trang, n))
                phim = DocPhim();
            if (phim == PHIM_ESC)
                break;
        }
        delete[] a;
    }
}
