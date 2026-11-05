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
bool MuonSach(ThuVien &tv, int maThe, const string &maCuon, const NgayThang &ngay, string &loi)
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
    CuonSach *cuon = TimCuonSachToanCuc(tv, maCuon);
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
void ManHinhMuonTra(ThuVien &tv, const NgayThang &ngay, bool tra)
{
    if (DangDungGiaoDienHeThong())
    {
        const char *readerFields[] = {"Ma the doc gia"};
        string readerValues[1];
        int maThe = 0;
        while (true)
        {
            if (!NhapBieuMau(tra ? "TRA SACH - CHON DOC GIA" : "MUON SACH - CHON DOC GIA",
                             readerFields, readerValues, 1))
            {
                return;
            }
            if (!DocSoNguyen(readerValues[0], maThe, 1, 2147483647))
            {
                ThongBao("Ma the phai la so nguyen duong trong mien int.");
                continue;
            }
            if (!TimDocGia(tv.cayDocGia, maThe))
            {
                ThongBao("Khong tim thay doc gia. Kiem tra lai ma the.");
                continue;
            }
            break;
        }
        // Hien sach dang giu TRUOC khi nhap cuon, giu dung luong chuc nang f.
        ostringstream out;
        out.exceptions(ios::badbit | ios::failbit);
        LietKeSachDangMuon(tv, maThe, out);
        HienThiPhanTrang(out.str());
        int action = 1;
        if (tra)
        {
            const char *actions[] = {"Tra sach", "Bao mat sach (khoa the, rut cuon khoi kho)"};
            action = ChonMenu("TRA / BAO MAT - THE " + ChuoiSo(maThe), actions, 2);
            if (action < 1)
            {
                return;
            }
        }
        const char *copyFields[] = {"Ma cuon sach"};
        string copyValues[1], loi;
        string title;
        if (!tra)
        {
            title = "MUON SACH";
        }
        else if (action == 1)
        {
            title = "TRA SACH";
        }
        else
        {
            title = "BAO MAT SACH";
        }
        title = title + " - THE " + ChuoiSo(maThe);
        while (NhapBieuMau(title, copyFields, copyValues, 1))
        {
            string ma = ChuanHoaChuoiSach(copyValues[0]);
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
            if (!ok)
            {
                ThongBao("LOI: " + loi);
                continue;
            }
            LuuSauThayDoi(tv);
            ThongBao("Giao dich thanh cong, ngay " + ChuoiNgay(ngay) + ".");
            return;
        }
        return;
    }
    int maThe;
    if (!NhapSo("Ma the doc gia: ", maThe, 1, 2147483647))
    {
        return;
    }
    if (!TimDocGia(tv.cayDocGia, maThe))
    {
        ThongBao("Khong tim thay doc gia.");
        return;
    }
    ostringstream out;
    out.exceptions(ios::badbit | ios::failbit);
    LietKeSachDangMuon(tv, maThe, out);
    HienThiPhanTrang(out.str());
    int action = 1;
    if (tra)
    {
        const char *labels[] = {"Tra sach", "Bao mat sach (khoa the, rut cuon khoi kho)"};
        action = ChonMenu("TRA / BAO MAT", labels, 2);
        if (action < 1)
        {
            return;
        }
    }
    string ma, loi;
    if (!NhapDong("Ma cuon sach: ", ma))
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
        LuuSauThayDoi(tv);
    }
    ThongBao(ok ? "Giao dich thanh cong, ngay " + ChuoiNgay(ngay) + "." : loi);
}
