#include "00_KhaiBaoChung.h"

/* ============================================================
   h. LIET KE MA SACH, TEN SACH MA DOC GIA CO SO THE X DANG MUON
   Duyet danh sach muon tra cua doc gia, chi lay cac luot co trang thai "dang muon".
   Ten sach lay tu dau sach chua cuon do (tim qua ISBN nam trong ma sach).
   ============================================================ */

// @TT [h] Tim doc gia bang tim_cay (10_), liet ke bang InSachDangMuon (f_MuonSach.cpp)
void ManHinhSachDangMuon(const DanhSachDauSach &ds, CayDocGia &cay)
{
    while (true)
    {
        VeManHinh(8, "Sách đang mượn của một độc giả", "Enter: xem    Esc: quay lại");
        NutDocGia *docgia = NhapMaTheTimDocGia(cay, 4, 5);
        if (docgia == nullptr)
            return;

        InThongTinDocGia(4, 7, *docgia);
        InTai(4, 11, "Các sách đang mượn:");
        int soCuon = InSachDangMuon(ds, *docgia, 4, 12, -1);
        ThongBao("Độc giả đang mượn " + SoThanhChuoi(soCuon) + " cuốn.", false);
    }
}
