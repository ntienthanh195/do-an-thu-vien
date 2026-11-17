#include "00_KhaiBaoChung.h"

/* ============================================================
   i. DANH SACH DOC GIA MUON SACH QUA HAN, thoi gian qua han giam dan

   Buoc 1: duyet cay lay dia chi cac nut doc gia ra mang tam.
   Buoc 2: voi moi luot dang muon da qua han, ghi lai (doc gia, luot muon) vao hai mang
           tam song song dg[] va luot[].
   Buoc 3: sap hai mang do giam dan theo so ngay qua han bang sap xep chon (selection sort).
   Mot doc gia giu 2 cuon qua han se co 2 dong.

   HAM LAY TU FILE KHAC:
     10_DocGia_CayAVL.cpp: DemDocGia, LayDanhSachDocGia
     12_DanhMucSach_DSLKDon.cpp: TimCuonSachToanCuc
     13_MuonTra_DSLKDon.cpp: SoNgayQuaHan
   ============================================================ */

void ManHinhDocGiaQuaHan(const DanhSachDauSach &ds, CayDocGia &cay)
{
    NgayThang homNay = HomNay();

    // @TT [i] Buoc 1: duyet LNR do con tro doc gia ra mang tam
    // Buoc 1
    int soDocGia = DemDocGia(cay);
    NutDocGia **tatCa = new NutDocGia *[soDocGia + 1];
    LayDanhSachDocGia(cay, tatCa, soDocGia);

    // dem truoc so luot qua han de cap phat mang vua du
    int n = 0;
    for (int i = 0; i < soDocGia; ++i)
    {
        for (MuonTra *p = tatCa[i]->thongTin.dsMuonTra; p != nullptr; p = p->next)
        {
            if (p->trangThai == MUON_DANG_MUON && SoNgayQuaHan(p->ngayMuon, homNay) > 0)
                ++n;
        }
    }

    // @TT [i] Buoc 2: loc luot dang muon da qua han vao 2 mang song song dg[], luot[]
    // Buoc 2
    NutDocGia **dg = new NutDocGia *[n + 1];
    MuonTra **luot = new MuonTra *[n + 1];
    n = 0;
    for (int i = 0; i < soDocGia; ++i)
    {
        for (MuonTra *p = tatCa[i]->thongTin.dsMuonTra; p != nullptr; p = p->next)
        {
            if (p->trangThai == MUON_DANG_MUON && SoNgayQuaHan(p->ngayMuon, homNay) > 0)
            {
                dg[n] = tatCa[i];
                luot[n] = p;
                ++n;
            }
        }
    }

    // @TT [i] Buoc 3: Selection Sort giam dan theo so ngay qua han - O(k^2), k = so luot qua han
    // Buoc 3: ngay muon cang som thi qua han cang lau
    for (int i = 0; i < n - 1; ++i)
    {
        int lonNhat = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (SoNgayQuaHan(luot[j]->ngayMuon, homNay) > SoNgayQuaHan(luot[lonNhat]->ngayMuon, homNay))
                lonNhat = j;
        }
        NutDocGia *tamDG = dg[i];
        dg[i] = dg[lonNhat];
        dg[lonNhat] = tamDG;
        MuonTra *tamLuot = luot[i];
        luot[i] = luot[lonNhat];
        luot[lonNhat] = tamLuot;
    }

    VeManHinh(9, "Độc giả mượn sách quá hạn", "←/→: chuyển trang    Esc: quay lại");
    SetColor(MAU_VANG_SANG, MAU_DEN);
    InCot(2, 5, "STT", 4);
    InCot(6, 5, "MÃ THẺ", 7);
    InCot(13, 5, "HỌ TÊN", 22);
    InCot(35, 5, "MÃ SÁCH", 17);
    InCot(52, 5, "TÊN SÁCH", 22);
    InCot(74, 5, "NGÀY MƯỢN", 12);
    InCot(86, 5, "QUÁ HẠN", 10);
    SetColor(MAU_TRANG, MAU_DEN);

    int trang = 0;
    while (true)
    {
        XoaVung(0, 7, RONG_MH, SO_DONG_TRANG);
        for (int i = trang * SO_DONG_TRANG; i < n && i < (trang + 1) * SO_DONG_TRANG; ++i)
        {
            int y = 7 + i - trang * SO_DONG_TRANG;
            DauSach *dauSach = nullptr;
            TimCuonSachToanCuc(ds, luot[i]->maSach, dauSach);

            InCot(2, y, SoThanhChuoi(i + 1), 4);
            InCot(6, y, SoThanhChuoi(dg[i]->thongTin.maThe), 7);
            InCot(13, y, dg[i]->thongTin.ho + " " + dg[i]->thongTin.ten, 22);
            InCot(35, y, luot[i]->maSach, 17);
            if (dauSach != nullptr)
                InCot(52, y, dauSach->tenSach, 22);
            InCot(74, y, ChuoiNgay(luot[i]->ngayMuon), 12);
            SetColor(MAU_DO_SANG, MAU_DEN);
            InCot(86, y, SoThanhChuoi(SoNgayQuaHan(luot[i]->ngayMuon, homNay)) + " ngày", 10);
            SetColor(MAU_TRANG, MAU_DEN);
        }
        if (n == 0)
            InTai(2, 7, "Không có độc giả nào đang giữ sách quá hạn.");
        InSoTrang(trang, n);

        int phim = DocPhim();
        while (phim != PHIM_ESC && !XuLyPhimTrang(phim, trang, n))
            phim = DocPhim();
        if (phim == PHIM_ESC)
            break;
    }

    delete[] tatCa;
    delete[] dg;
    delete[] luot;
}
