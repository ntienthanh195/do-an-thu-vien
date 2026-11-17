#include "00_KhaiBaoChung.h"

/* ============================================================
   j. 10 SACH CO SO LUOT MUON NHIEU NHAT

   De khong co truong "so luot muon" trong dau sach, nen so luot duoc dem lai moi lan xem:
   Buoc 1: mang tam luotMuon[i] = so luot muon cua dau sach thu i (ban dau bang 0).
   Buoc 2: duyet moi doc gia, moi luot muon trong lich su: tach ISBN tu ma sach,
           tim vi tri dau sach roi tang luotMuon[vi tri] len 1.
           Tinh ca luot dang muon, da tra va lam mat vi deu la mot lan muon.
   Buoc 3: mang tam thuTu[] giu chi so dau sach. Sap xep chon nhung chi chay 10 vong,
           moi vong dua dau sach nhieu luot nhat con lai len dau.
   ============================================================ */

void ManHinhTop10Sach(const DanhSachDauSach &ds, CayDocGia &cay)
{
    int n = ds.soLuong;

    // @TT [j] Buoc 1: mang tam luotMuon[] = 0, thuTu[] = chi so dau sach
    // Buoc 1
    int *luotMuon = new int[n + 1];
    int *thuTu = new int[n + 1];
    for (int i = 0; i < n; ++i)
    {
        luotMuon[i] = 0;
        thuTu[i] = i;
    }

    // @TT [j] Buoc 2: duyet moi doc gia, moi luot muon -> tach ISBN -> tim dau sach -> tang luotMuon
    // Buoc 2
    int soDocGia = DemDocGia(cay);
    NutDocGia **tatCa = new NutDocGia *[soDocGia + 1];
    LayDanhSachDocGia(cay, tatCa, soDocGia);
    for (int i = 0; i < soDocGia; ++i)
    {
        for (MuonTra *p = tatCa[i]->thongTin.dsMuonTra; p != nullptr; p = p->next)
        {
            int viTri = TimViTriDauSachTheoISBN(ds, TachISBNTuMaSach(p->maSach));
            if (viTri != -1)
                ++luotMuon[viTri];
        }
    }

    // @TT [j] Buoc 3: Selection Sort chi chay 10 vong (moi vong dua dau sach nhieu luot nhat len) - O(10*n)
    // Buoc 3
    int soDong = n;
    if (soDong > 10)
        soDong = 10;
    for (int i = 0; i < soDong; ++i)
    {
        int lonNhat = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (luotMuon[thuTu[j]] > luotMuon[thuTu[lonNhat]])
                lonNhat = j;
        }
        int tam = thuTu[i];
        thuTu[i] = thuTu[lonNhat];
        thuTu[lonNhat] = tam;
    }

    VeManHinh(10, "10 sách có số lượt mượn nhiều nhất", "Esc: quay lại");
    SetColor(MAU_VANG_SANG, MAU_DEN);
    InCot(2, 5, "HẠNG", 6);
    InCot(8, 5, "TÊN SÁCH", 34);
    InCot(42, 5, "ISBN", 15);
    InCot(57, 5, "TÁC GIẢ", 20);
    InCot(77, 5, "THỂ LOẠI", 13);
    InCot(90, 5, "LƯỢT", 6);
    SetColor(MAU_TRANG, MAU_DEN);

    int dong = 0;
    for (int i = 0; i < soDong; ++i)
    {
        const DauSach &d = *ds.ds[thuTu[i]];
        if (luotMuon[thuTu[i]] == 0)
            break; // dau sach chua ai muon thi khong xep hang
        InCot(2, 7 + dong, SoThanhChuoi(dong + 1), 6);
        InCot(8, 7 + dong, d.tenSach, 34);
        InCot(42, 7 + dong, d.ISBN, 15);
        InCot(57, 7 + dong, d.tacGia, 20);
        InCot(77, 7 + dong, d.theLoai, 13);
        SetColor(MAU_XANH_LA_SANG, MAU_DEN);
        InCot(90, 7 + dong, SoThanhChuoi(luotMuon[thuTu[i]]), 6);
        SetColor(MAU_TRANG, MAU_DEN);
        ++dong;
    }
    if (dong == 0)
        InTai(2, 7, "Chưa có lượt mượn nào.");

    while (DocPhim() != PHIM_ESC)
        ;

    delete[] luotMuon;
    delete[] thuTu;
    delete[] tatCa;
}
