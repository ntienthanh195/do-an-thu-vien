#include "00_KhaiBaoChung.h"

/* ============================================================
   h. LIET KE MA SACH, TEN SACH MA DOC GIA CO SO THE X DANG MUON
   Duyet danh sach muon tra cua doc gia, chi lay cac luot co trang thai "dang muon".
   Ten sach lay tu dau sach chua cuon do (tim qua ISBN nam trong ma sach).
   ============================================================ */

void ManHinhSachDangMuon(const DanhSachDauSach &ds, CayDocGia &cay)
{
    while (true)
    {
        VeManHinh("h. SACH DANG MUON CUA MOT DOC GIA", "Enter: xem    Esc: quay lai");
        NutDocGia *docgia = NhapMaTheTimDocGia(cay, 4, 5);
        if (docgia == nullptr)
            return;

        InThongTinDocGia(4, 7, *docgia);
        InTai(4, 11, "Cac sach dang muon:");
        int soCuon = InSachDangMuon(ds, *docgia, 4, 12, -1);
        ThongBao("Doc gia dang muon " + SoThanhChuoi(soCuon) + " cuon.", false);
    }
}
