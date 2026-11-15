#include "00_KhaiBaoChung.h"

/* ============================================================
   f. MUON SACH
   Nhap ma the, chuong trinh liet ke cac sach doc gia dang muon.
   Khong cho muon khi: the bi khoa, dang giu du 3 cuon, hoac dang giu sach qua han.
   ============================================================ */

// Thuc hien mot luot muon. Thanh cong thi them nut vao lich su va doi trang thai cuon sach.
bool MuonSach(DanhSachDauSach &ds, NutDocGia &docgia, const string &maSach, NgayThang ngayMuon,
              string &loi)
{
    if (docgia.thongTin.trangThaiThe != THE_HOAT_DONG)
    {
        loi = "The doc gia dang bi khoa, khong duoc muon sach.";
        return false;
    }
    if (Dem_so_sach_dang_muon(docgia) >= MAX_SACH_MUON)
    {
        loi = "Doc gia dang muon du 3 cuon, phai tra bot moi duoc muon tiep.";
        return false;
    }
    if (CoSachQuaHan7Ngay(docgia, ngayMuon))
    {
        loi = "Doc gia dang giu sach qua han, phai tra truoc khi muon tiep.";
        return false;
    }

    DauSach *dauSach = nullptr;
    CuonSach *cuon = TimCuonSachToanCuc(ds, maSach, dauSach);
    if (cuon == nullptr)
    {
        loi = "Khong tim thay ma sach " + maSach + ".";
        return false;
    }
    if (cuon->trangThai == SACH_DANG_MUON)
    {
        loi = "Cuon sach nay da co doc gia muon.";
        return false;
    }
    if (cuon->trangThai == SACH_THANH_LY)
    {
        loi = "Cuon sach nay da thanh ly.";
        return false;
    }

    MuonTra luot;
    luot.maSach = maSach;
    luot.ngayMuon = ngayMuon;
    luot.trangThai = MUON_DANG_MUON;
    them_lich_su(docgia, luot);

    cuon->trangThai = SACH_DANG_MUON;
    return true;
}

// In bang cac sach doc gia dang muon, bat dau tu dong y. Dong thu dongChon duoc to sang
// (truyen -1 neu khong can to sang). Tra ve so cuon dang muon.
int InSachDangMuon(const DanhSachDauSach &ds, NutDocGia &docgia, int x, int y, int dongChon)
{
    SetColor(MAU_VANG_SANG, MAU_DEN);
    InCot(x, y, "STT", 5);
    InCot(x + 5, y, "MA SACH", 22);
    InCot(x + 27, y, "TEN SACH", 42);
    InCot(x + 69, y, "NGAY MUON", 13);
    InCot(x + 82, y, "TINH TRANG", 24);
    SetColor(MAU_TRANG, MAU_DEN);
    XoaVung(x, y + 1, 106, MAX_SACH_MUON + 1);

    NgayThang homNay = HomNay();
    int dem = 0;
    MuonTra *p = docgia.thongTin.dsMuonTra;
    while (p != nullptr)
    {
        if (p->trangThai == MUON_DANG_MUON)
        {
            DauSach *dauSach = nullptr;
            TimCuonSachToanCuc(ds, p->maSach, dauSach);
            int quaHan = SoNgayQuaHan(p->ngayMuon, homNay);

            if (dem == dongChon)
                SetColor(MAU_DEN, MAU_NGOC_SANG);
            else if (quaHan > 0)
                SetColor(MAU_DO_SANG, MAU_DEN);
            else
                SetColor(MAU_TRANG, MAU_DEN);

            ++dem;
            InCot(x, y + dem, SoThanhChuoi(dem), 5);
            InCot(x + 5, y + dem, p->maSach, 22);
            if (dauSach != nullptr)
                InCot(x + 27, y + dem, dauSach->tenSach, 42);
            else
                InCot(x + 27, y + dem, "(khong ro dau sach)", 42);
            InCot(x + 69, y + dem, ChuoiNgay(p->ngayMuon), 13);
            if (quaHan > 0)
                InCot(x + 82, y + dem, "Qua han " + SoThanhChuoi(quaHan) + " ngay", 24);
            else
                InCot(x + 82, y + dem, "Trong han", 24);
        }
        p = p->next;
    }
    SetColor(MAU_TRANG, MAU_DEN);
    if (dem == 0)
        InTai(x, y + 1, "(doc gia khong giu cuon nao)");
    return dem;
}

void ManHinhMuonSach(DanhSachDauSach &ds, CayDocGia &cay)
{
    while (true)
    {
        VeManHinh("f. MUON SACH", "Enter: xac nhan    Esc: quay lai");
        NutDocGia *docgia = NhapMaTheTimDocGia(cay, 4, 5);
        if (docgia == nullptr)
            return;
        InThongTinDocGia(4, 7, *docgia);
        InTai(4, 11, "Cac sach dang muon:");

        // muon lien tiep cho cung mot doc gia toi khi nhan Esc
        string maSach = "";
        NgayThang ngayMuon = HomNay();
        while (true)
        {
            InSachDangMuon(ds, *docgia, 4, 12, -1);
            InTai(4, 18, "Ma sach muon (ISBN#N):");
            InTai(4, 20, "Ngay muon (dd/mm/yyyy):");
            maSach = "";
            if (!NhapChuoi(28, 18, 20, false, maSach))
                break;
            if (!NhapNgay(28, 20, ngayMuon))
                break;

            string loi;
            if (MuonSach(ds, *docgia, ChuanHoaChuoiSach(maSach), ngayMuon, loi))
            {
                LuuSauThayDoi(ds, cay);
                InSachDangMuon(ds, *docgia, 4, 12, -1);
                ThongBao("Da cho muon cuon " + maSach + ".", false);
            }
            else
                ThongBao(loi, true);
        }
    }
}
