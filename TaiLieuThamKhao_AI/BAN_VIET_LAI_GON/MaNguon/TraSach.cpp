#include "00_KhaiBaoChung.h"

/* ============================================================
   g. TRA SACH
   Tra sach: luot muon chuyen sang "da tra" va ghi ngay tra, cuon sach chuyen ve "cho muon duoc".
   Bao mat : luot muon chuyen sang "lam mat", cuon sach khong con trong thu vien nen chuyen
             sang "da thanh ly", va the doc gia bi khoa (quy uoc cua nhom, can hoi lai thay).
   ============================================================ */

bool TraSach(DanhSachDauSach &ds, NutDocGia &docgia, const string &maSach, NgayThang ngayTra,
             bool lamMat, string &loi)
{
    MuonTra *luot = TimMuonDangMuonTheoMa(docgia, maSach);
    if (luot == nullptr)
    {
        loi = "Doc gia khong dang muon cuon sach nay.";
        return false;
    }
    if (KhoangCachNgay(luot->ngayMuon, ngayTra) < 0)
    {
        loi = "Ngay tra khong duoc truoc ngay muon (" + ChuoiNgay(luot->ngayMuon) + ").";
        return false;
    }

    DauSach *dauSach = nullptr;
    CuonSach *cuon = TimCuonSachToanCuc(ds, maSach, dauSach);

    if (lamMat)
    {
        CapNhatLuotTra(docgia, maSach, ngayTra, MUON_LAM_MAT);
        if (cuon != nullptr)
            cuon->trangThai = SACH_THANH_LY;
        docgia.thongTin.trangThaiThe = THE_BI_KHOA;
    }
    else
    {
        CapNhatLuotTra(docgia, maSach, ngayTra, MUON_DA_TRA);
        if (cuon != nullptr)
            cuon->trangThai = SACH_CHO_MUON;
    }
    return true;
}

// Lay ma sach cua luot dang muon thu "thuTu" (tinh tu 0) trong lich su cua doc gia.
static string MaSachDangMuonThu(NutDocGia &docgia, int thuTu)
{
    int dem = 0;
    MuonTra *p = docgia.thongTin.dsMuonTra;
    while (p != nullptr)
    {
        if (p->trangThai == MUON_DANG_MUON)
        {
            if (dem == thuTu)
                return p->maSach;
            ++dem;
        }
        p = p->next;
    }
    return "";
}

void ManHinhTraSach(DanhSachDauSach &ds, CayDocGia &cay)
{
    while (true)
    {
        VeManHinh("g. TRA SACH", "Len/Xuong: chon cuon    Enter: tra sach    M: bao mat sach    Esc: quay lai");
        NutDocGia *docgia = NhapMaTheTimDocGia(cay, 4, 5);
        if (docgia == nullptr)
            return;
        InTai(4, 11, "Chon cuon sach can tra:");

        int chon = 0;
        NgayThang ngayTra = HomNay();
        while (true)
        {
            InThongTinDocGia(4, 7, *docgia);
            int soCuon = InSachDangMuon(ds, *docgia, 4, 12, chon);
            if (soCuon == 0)
            {
                ThongBao("Doc gia khong con giu cuon sach nao.", false);
                break;
            }

            int phim = DocPhim();
            if (phim == PHIM_ESC)
                break;
            if (phim == PHIM_LEN && chon > 0)
                --chon;
            else if (phim == PHIM_XUONG && chon + 1 < soCuon)
                ++chon;
            else if (phim == PHIM_ENTER || phim == 'm' || phim == 'M')
            {
                bool lamMat = (phim != PHIM_ENTER);
                string maSach = MaSachDangMuonThu(*docgia, chon);

                if (lamMat)
                    InTai(4, 18, "Ngay bao mat (dd/mm/yyyy):");
                else
                    InTai(4, 18, "Ngay tra     (dd/mm/yyyy):");
                bool tiepTuc = NhapNgay(31, 18, ngayTra);
                if (tiepTuc && lamMat)
                    tiepTuc = XacNhan("Bao mat cuon " + maSach + "? The doc gia se bi khoa.");

                string loi;
                if (!tiepTuc)
                    ;
                else if (TraSach(ds, *docgia, maSach, ngayTra, lamMat, loi))
                {
                    LuuSauThayDoi(ds, cay);
                    if (lamMat)
                        ThongBao("Da ghi nhan mat cuon " + maSach + " va khoa the.", false);
                    else
                        ThongBao("Da tra cuon " + maSach + ".", false);
                    chon = 0;
                }
                else
                    ThongBao(loi, true);
                XoaVung(0, 18, RONG_MH, 1);
            }
        }
    }
}
