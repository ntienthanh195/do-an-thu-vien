#include "0.0_KhaiBaoChung.h"

/* ============================================================
   b. IN DANH SACH DOC GIA theo ten + ho tang dan, hoac theo ma the tang dan.

   - Theo ma the: duyet cay theo thu tu giua (LNR) la co san thu tu tang dan.
   - Theo ten + ho: cay chi sap theo ma the, nen lay dia chi cac nut ra mot mang tam
     roi sap mang tam bang Quick Sort. Cay khong bi thay doi.

   HAM LAY TU FILE KHAC:
     1.1_DocGia_CayAVL.cpp: DemDocGia, LayDanhSachDocGia
     1.4_MuonTra_DSLKDon.cpp: Dem_so_sach_dang_muon
   ============================================================ */

/* ===================== XU LY ===================== */

// So sanh hai doc gia theo ten, neu trung ten thi theo ho.
static int SoSanhTenHo(const NutDocGia *a, const NutDocGia *b)
{
    int kq = SoSanhChuoi(a->thongTin.ten, b->thongTin.ten);
    if (kq != 0)
        return kq;
    return SoSanhChuoi(a->thongTin.ho, b->thongTin.ho);
}

// Quick Sort tren mang con tro, lay phan tu giua lam chot.
// @TT [b] In theo ten + ho: Quick Sort tren mang con tro (chot la phan tu giua) - O(n log n) trung binh
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

/* ===================== GIAO DIEN ===================== */

void ManHinhInDanhSachDocGia(CayDocGia &cay)
{
    string muc[2] = {"1. Theo tên + họ tăng dần", "2. Theo mã thẻ tăng dần"};
    while (true)
    {
        VeManHinh(2, "Danh sách độc giả", "↑/↓: chọn    Enter: xem    Esc: quay lại");
        int kieu = ChonMenu(4, 5, 34, muc, 2);
        if (kieu == -1)
            return;

        int n = DemDocGia(cay);
        NutDocGia **a = new NutDocGia *[n + 1]; // mang tam, chi giu con tro
        // @TT [b] Lay doc gia ra mang tam bang duyet LNR (da tang theo ma the), cay khong bi doi
        LayDanhSachDocGia(cay, a, n);
        if (kieu == 0)
            SapXepTheoTenHo(a, 0, n - 1);

        if (kieu == 0)
            VeManHinh(2, "Danh sách độc giả theo tên + họ", "←/→: chuyển trang    Esc: quay lại");
        else
            VeManHinh(2, "Danh sách độc giả theo mã thẻ", "←/→: chuyển trang    Esc: quay lại");
        SetColor(MAU_VANG_SANG, MAU_DEN);
        InCot(2, 5, "STT", 6);
        InCot(8, 5, "MÃ THẺ", 10);
        InCot(18, 5, "HỌ", 28);
        InCot(46, 5, "TÊN", 16);
        InCot(62, 5, "PHÁI", 7);
        InCot(69, 5, "TRẠNG THÁI", 14);
        InCot(83, 5, "ĐANG MƯỢN", 10);
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
                InCot(18, y, dg.ho, 28);
                InCot(46, y, dg.ten, 16);
                InCot(62, y, dg.phai, 7);
                if (dg.trangThaiThe == THE_HOAT_DONG)
                    InCot(69, y, "Hoạt động", 14);
                else
                {
                    SetColor(MAU_DO_SANG, MAU_DEN);
                    InCot(69, y, "Bị khóa", 14);
                    SetColor(MAU_TRANG, MAU_DEN);
                }
                InCot(83, y, SoThanhChuoi(Dem_so_sach_dang_muon(*a[i])), 10);
            }
            if (n == 0)
                InTai(2, 7, "Chưa có độc giả nào.");
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
