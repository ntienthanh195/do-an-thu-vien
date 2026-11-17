#include "00_KhaiBaoChung.h"

/* ============================================================
   f. MUON SACH
   Nhap ma the, chuong trinh liet ke cac sach doc gia dang muon.
   Khong cho muon khi: the bi khoa, dang giu du 3 cuon, hoac dang giu sach qua han.

   HAM LAY TU FILE KHAC:
     12_DanhMucSach_DSLKDon.cpp: TimCuonSachToanCuc
     13_MuonTra_DSLKDon.cpp: CoSachQuaHan7Ngay, Dem_so_sach_dang_muon, SoNgayQuaHan, them_lich_su
     a_QuanLyDocGia.cpp: InThongTinDocGia, NhapMaTheTimDocGia
   ============================================================ */

/* ===================== XU LY ===================== */

// @TT [f] Muon sach: kiem tra lan luot ngay muon, the khoa, du 3 cuon, dang giu sach qua han,
//         ma sach co ton tai, cuon dang muon/thanh ly; dat thi them cuoi DSLK muon tra
// Thuc hien mot luot muon. Thanh cong thi them nut vao lich su va doi trang thai cuon sach.
bool MuonSach(DanhSachDauSach &ds, NutDocGia &docgia, const string &maSach, NgayThang ngayMuon,
              string &loi)
{
    // Ngay muon do thu thu nhap nen phai doi chieu voi ngay cua may:
    // khong nhan ngay o tuong lai (se khong tra duoc sach truoc ngay do).
    NgayThang homNay = HomNay();
    if (KhoangCachNgay(ngayMuon, homNay) < 0)
    {
        loi = "Ngày mượn không được sau ngày hôm nay (" + ChuoiNgay(homNay) + ").";
        return false;
    }
    if (docgia.thongTin.trangThaiThe != THE_HOAT_DONG)
    {
        loi = "Thẻ độc giả đang bị khóa, không được mượn sách.";
        return false;
    }
    if (Dem_so_sach_dang_muon(docgia) >= MAX_SACH_MUON)
    {
        loi = "Độc giả đang mượn đủ 3 cuốn, phải trả bớt mới được mượn tiếp.";
        return false;
    }
    // Xet qua han theo ngay hom nay, khong theo ngay muon vua nhap,
    // de khong the nhap lui ngay muon ma lach duoc dieu kien nay.
    if (CoSachQuaHan7Ngay(docgia, homNay))
    {
        loi = "Độc giả đang giữ sách quá hạn, phải trả trước khi mượn tiếp.";
        return false;
    }

    DauSach *dauSach = nullptr;
    CuonSach *cuon = TimCuonSachToanCuc(ds, maSach, dauSach);
    if (cuon == nullptr)
    {
        loi = "Không tìm thấy mã sách " + maSach + ".";
        return false;
    }
    if (cuon->trangThai == SACH_DANG_MUON)
    {
        loi = "Cuốn sách này đã có độc giả mượn.";
        return false;
    }
    if (cuon->trangThai == SACH_THANH_LY)
    {
        loi = "Cuốn sách này đã thanh lý.";
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

/* ===================== GIAO DIEN ===================== */

// @TT [f,g,h] Liet ke sach dang muon: duyet DSLK muon tra, chi lay luot co trang thai 0 (dang muon)
// In bang cac sach doc gia dang muon, bat dau tu dong y. Dong thu dongChon duoc to sang
// (truyen -1 neu khong can to sang). Tra ve so cuon dang muon.
int InSachDangMuon(const DanhSachDauSach &ds, NutDocGia &docgia, int x, int y, int dongChon)
{
    SetColor(MAU_VANG_SANG, MAU_DEN);
    InCot(x, y, "STT", 5);
    InCot(x + 5, y, "MÃ SÁCH", 18);
    InCot(x + 23, y, "TÊN SÁCH", 34);
    InCot(x + 57, y, "NGÀY MƯỢN", 12);
    InCot(x + 69, y, "TÌNH TRẠNG", 20);
    SetColor(MAU_TRANG, MAU_DEN);
    XoaVung(x, y + 1, 89, MAX_SACH_MUON + 1);

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
            InCot(x + 5, y + dem, p->maSach, 18);
            if (dauSach != nullptr)
                InCot(x + 23, y + dem, dauSach->tenSach, 34);
            else
                InCot(x + 23, y + dem, "(không rõ đầu sách)", 34);
            InCot(x + 57, y + dem, ChuoiNgay(p->ngayMuon), 12);
            if (quaHan > 0)
                InCot(x + 69, y + dem, "Quá hạn " + SoThanhChuoi(quaHan) + " ngày", 20);
            else
                InCot(x + 69, y + dem, "Trong hạn", 20);
        }
        p = p->next;
    }
    SetColor(MAU_TRANG, MAU_DEN);
    if (dem == 0)
        InTai(x, y + 1, "(độc giả không giữ cuốn nào)");
    return dem;
}

void ManHinhMuonSach(DanhSachDauSach &ds, CayDocGia &cay)
{
    while (true)
    {
        VeManHinh(6, "Mượn sách", "Enter: xác nhận    Esc: quay lại");
        NutDocGia *docgia = NhapMaTheTimDocGia(cay, 4, 5);
        if (docgia == nullptr)
            return;
        InThongTinDocGia(4, 7, *docgia);
        InTai(4, 11, "Các sách đang mượn:");

        // muon lien tiep cho cung mot doc gia toi khi nhan Esc
        string maSach = "";
        NgayThang ngayMuon = HomNay();
        while (true)
        {
            InSachDangMuon(ds, *docgia, 4, 12, -1);
            InTai(4, 18, "Mã sách mượn (ISBN#N):");
            InTai(4, 20, "Ngày mượn (dd/mm/yyyy):");
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
                ThongBao("Đã cho mượn cuốn " + maSach + ".", false);
            }
            else
                ThongBao(loi, true);
        }
    }
}
