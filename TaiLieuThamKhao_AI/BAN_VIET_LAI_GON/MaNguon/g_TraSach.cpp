#include "00_KhaiBaoChung.h"

/* ============================================================
   g. TRA SACH
   Tra sach: luot muon chuyen sang "da tra" va ghi ngay tra, cuon sach chuyen ve "cho muon duoc".
   Bao mat : luot muon chuyen sang "lam mat", cuon sach khong con trong thu vien nen chuyen
             sang "da thanh ly", va the doc gia bi khoa (quy uoc cua nhom, can hoi lai thay).
   ============================================================ */

/* ===================== XU LY ===================== */

// @TT [g] Tra sach / bao mat: tim luot dang muon, kiem tra ngay tra, doi trang thai luot + cuon;
//         bao mat thi cuon -> thanh ly va khoa the
bool TraSach(DanhSachDauSach &ds, NutDocGia &docgia, const string &maSach, NgayThang ngayTra,
             bool lamMat, string &loi)
{
    MuonTra *luot = TimMuonDangMuonTheoMa(docgia, maSach);
    if (luot == nullptr)
    {
        loi = "Độc giả không đang mượn cuốn sách này.";
        return false;
    }
    NgayThang homNay = HomNay();
    if (KhoangCachNgay(ngayTra, homNay) < 0)
    {
        loi = "Ngày trả không được sau ngày hôm nay (" + ChuoiNgay(homNay) + ").";
        return false;
    }
    if (KhoangCachNgay(luot->ngayMuon, ngayTra) < 0)
    {
        loi = "Ngày trả không được trước ngày mượn (" + ChuoiNgay(luot->ngayMuon) + ").";
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
/* ===================== GIAO DIEN ===================== */

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
        VeManHinh(7, "Trả sách / báo mất", "↑/↓: chọn cuốn    Enter: trả sách    M: báo mất sách    Esc: quay lại");
        NutDocGia *docgia = NhapMaTheTimDocGia(cay, 4, 5);
        if (docgia == nullptr)
            return;
        InTai(4, 11, "Chọn cuốn sách cần trả:");

        int chon = 0;
        NgayThang ngayTra = HomNay();
        while (true)
        {
            InThongTinDocGia(4, 7, *docgia);
            int soCuon = InSachDangMuon(ds, *docgia, 4, 12, chon);
            if (soCuon == 0)
            {
                ThongBao("Độc giả không còn giữ cuốn sách nào.", false);
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
                    InTai(4, 18, "Ngày báo mất (dd/mm/yyyy):");
                else
                    InTai(4, 18, "Ngày trả     (dd/mm/yyyy):");
                bool tiepTuc = NhapNgay(31, 18, ngayTra);
                if (tiepTuc && lamMat)
                    tiepTuc = XacNhan("Báo mất cuốn " + maSach + "? Thẻ độc giả sẽ bị khóa.");

                string loi;
                if (!tiepTuc)
                    ;
                else if (TraSach(ds, *docgia, maSach, ngayTra, lamMat, loi))
                {
                    LuuSauThayDoi(ds, cay);
                    if (lamMat)
                        ThongBao("Đã ghi nhận mất cuốn " + maSach + " và khóa thẻ.", false);
                    else
                        ThongBao("Đã trả cuốn " + maSach + ".", false);
                    chon = 0;
                }
                else
                    ThongBao(loi, true);
                XoaVung(0, 18, RONG_MH, 1);
            }
        }
    }
}
