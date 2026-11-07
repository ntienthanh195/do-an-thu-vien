#include "00_KhaiBaoChung.h"

// [DEMO - CODEX] Phan bo sung cho ban trinh thay.
bool KiemTraNgayThaoTac(const NgayThang &ngay, string &loi)
{
    if (!NgayHopLe(ngay))
    {
        loi = "Ngay giao dich khong hop le.";
        return false;
    }
    if (KhoangCachNgay(HomNay(), ngay) > 0)
    {
        loi = "Khong ghi ngay tuong lai.";
        return false;
    }
    return true;
}
bool KiemTraLichSuGiaoDich(const ThuVien &tv, int maThe, const string &maCuon,
                           const NgayThang &ngay, int &soDangMuon, int &tongLuot, string &loi)
{
    int soDocGia = DemDocGia(tv.cayDocGia);
    const NutDocGia **ds = new const NutDocGia *[soDocGia];
    try
    {
        LayDanhSachDocGia(tv.cayDocGia, ds, soDocGia);
        soDangMuon = 0;
        tongLuot = 0;
        int mocNgay = 0;
        bool hopLe = true;
        for (int i = 0; i < soDocGia && hopLe; i++)
        {
            const MuonTra *p = ds[i]->thongTin.dsMuonTra;
            while (p != nullptr && hopLe)
            {
                tongLuot++;
                if (tongLuot > MAX_BAN_GHI)
                {
                    loi = "Lich su vuot gioi han.";
                    hopLe = false;
                    break;
                }
                if (p->maSach == maCuon && p->trangThai == MUON_DANG_MUON)
                {
                    soDangMuon++;
                }
                if (ds[i]->thongTin.maThe == maThe || p->maSach == maCuon)
                {
                    if (!NgayHopLe(p->ngayMuon) || !HopLeTrangThaiMuonTra(p->trangThai))
                    {
                        loi = "Lich su lien quan khong hop le.";
                        hopLe = false;
                        break;
                    }
                    int ngayMuon = SoThuTuNgay(p->ngayMuon);
                    if (ngayMuon > mocNgay)
                    {
                        mocNgay = ngayMuon;
                    }
                    if (p->trangThai != MUON_DANG_MUON)
                    {
                        if (!NgayHopLe(p->ngayTra))
                        {
                            loi = "Ngay tra khong hop le.";
                            hopLe = false;
                            break;
                        }
                        int ngayTra = SoThuTuNgay(p->ngayTra);
                        if (ngayTra > mocNgay)
                        {
                            mocNgay = ngayTra;
                        }
                    }
                }
                p = p->next;
            }
        }
        delete[] ds;
        ds = nullptr;
        if (!hopLe)
        {
            return false;
        }
        if (SoThuTuNgay(ngay) < mocNgay)
        {
            loi = "Khong duoc ghi lui ngay qua lich su lien quan.";
            return false;
        }
        return true;
    }
    catch (...)
    {
        delete[] ds;
        throw;
    }
}
bool KiemTraDocGiaMuon(ThuVien &tv, int maThe, const NgayThang &ngay, string &loi)
{
    if (!KiemTraNgayThaoTac(ngay, loi))
    {
        return false;
    }
    NutDocGia *docGia = TimDocGia(tv.cayDocGia, maThe);
    if (docGia == nullptr)
    {
        loi = "Khong tim thay doc gia.";
        return false;
    }
    if (docGia->thongTin.trangThaiThe != THE_HOAT_DONG)
    {
        loi = "The dang bi khoa.";
        return false;
    }
    if (Dem_so_sach_dang_muon(*docGia) >= 3)
    {
        loi = "Doc gia da muon toi da 3 cuon.";
        return false;
    }
    if (CoSachQuaHan7Ngay(*docGia, ngay))
    {
        loi = "Doc gia dang co sach qua han.";
        return false;
    }
    loi.clear();
    return true;
}
bool MuonSach(ThuVien &tv, int maThe, const string &maCuon, const NgayThang &ngay, string &loi)
{
    if (!KiemTraDocGiaMuon(tv, maThe, ngay, loi))
    {
        return false;
    }
    NutDocGia *docGia = TimDocGia(tv.cayDocGia, maThe);
    CuonSach *cuon = TimCuonSachToanCuc(tv, maCuon, nullptr);
    if (cuon == nullptr)
    {
        loi = "Khong tim thay cuon sach.";
        return false;
    }
    if (cuon->trangThai != SACH_CHO_MUON)
    {
        loi = "Cuon sach khong cho muon duoc.";
        return false;
    }
    int soDangMuon = 0, tongLuot = 0;
    if (!KiemTraLichSuGiaoDich(tv, maThe, maCuon, ngay, soDangMuon, tongLuot, loi))
    {
        return false;
    }
    if (soDangMuon != 0 || tongLuot >= MAX_BAN_GHI)
    {
        loi = "Lich su khong cho phep them luot muon.";
        return false;
    }
    MuonTra duLieu;
    duLieu.maSach = maCuon;
    duLieu.ngayMuon = ngay;
    them_lich_su(*docGia, duLieu);
    cuon->trangThai = SACH_DANG_MUON;
    loi.clear();
    return true;
}
void ManHinhMuonTra(GiaoDien &gd, ThuVien &tv, const NgayThang &ngay, bool tra)
{
    if (!tra && DangDungGiaoDienHeThong(gd))
    {
        int maThe = ChonMaTheDocGia(gd, tv.cayDocGia, "MUON SACH - CHON DOC GIA");
        if (maThe == 0)
        {
            return;
        }
        string loi;
        if (!KiemTraDocGiaMuon(tv, maThe, ngay, loi))
        {
            ThongBao(gd, "THE " + ChuoiSo(maThe) + ": " + loi);
            return;
        }
        string thongBao;
        while (true)
        {
            bool choMuon = KiemTraDocGiaMuon(tv, maThe, ngay, loi);
            string maCuon;
            if (!ChonCuonDeMuon(gd, tv, maThe, thongBao, choMuon, loi, maCuon))
            {
                break;
            }
            if (!MuonSach(tv, maThe, maCuon, ngay, loi))
            {
                thongBao = "Chua muon: " + loi;
                continue;
            }
            // Chi hien thanh cong sau khi luu xong; loi luu thoat qua ngoai le.
            LuuSauThayDoi(gd, tv);
            thongBao = "Da luu luot muon cuon " + maCuon + ".";
        }
        return;
    }
    if (DangDungGiaoDienHeThong(gd))
    {
        int maThe = ChonMaTheDocGia(gd, tv.cayDocGia, "TRA SACH - CHON DOC GIA");
        if (maThe == 0) return;
        string thongBao;
        while (true)
        {
            string maCuon, loi;
            int thaoTac = ChonCuonDeTra(gd, tv, maThe, thongBao, maCuon);
            if (thaoTac == 0) break;
            bool thanhCong;
            if (thaoTac == 1)
            {
                thanhCong = TraSach(tv, maThe, maCuon, ngay, loi);
            }
            else
            {
                thanhCong = DanhDauMatSach(tv, maThe, maCuon, ngay, loi);
            }
            if (!thanhCong)
            {
                thongBao = "LOI: " + loi;
                continue;
            }
            LuuSauThayDoi(gd, tv);
            if (thaoTac == 1) thongBao = "Da luu tra cuon " + maCuon + ".";
            else thongBao = "Da bao mat " + maCuon + "; the da khoa.";
        }
        return;
    }
    int maThe;
    if (!NhapSo(gd, "Ma the doc gia: ", maThe, 1, 2147483647))
    {
        return;
    }
    if (!TimDocGia(tv.cayDocGia, maThe))
    {
        ThongBao(gd, "Khong tim thay doc gia.");
        return;
    }
    ostringstream out;
    out.exceptions(ios::badbit | ios::failbit);
    LietKeSachDangMuon(tv, maThe, out);
    HienThiPhanTrang(gd, out.str());
    int action = 1;
    if (tra)
    {
        const char *labels[] = {"Tra sach", "Bao mat sach (khoa the, rut cuon khoi kho)"};
        action = ChonMenu(gd, "TRA / BAO MAT", labels, 2);
        if (action < 1)
        {
            return;
        }
    }
    string ma, loi;
    if (!NhapDong(gd, "Ma cuon sach: ", ma))
    {
        return;
    }
    ma = ChuanHoaChuoiSach(ma);
    bool ok;
    if (!tra)
    {
        ok = MuonSach(tv, maThe, ma, ngay, loi);
    }
    else if (action == 1)
    {
        ok = TraSach(tv, maThe, ma, ngay, loi);
    }
    else
    {
        ok = DanhDauMatSach(tv, maThe, ma, ngay, loi);
    }
    if (ok)
    {
        LuuSauThayDoi(gd, tv);
    }
    ThongBao(gd, ok ? "Giao dich thanh cong, ngay " + ChuoiNgay(ngay) + "." : loi);
}
