#include "00_KhaiBaoChung.h"

// [DEMO - CODEX] Phan bo sung cho ban trinh thay.
bool XuLyKetThucLuotMuon(ThuVien &tv, int maThe, const string &maCuon, const NgayThang &ngay,
                         bool baoMat, string &loi)
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
    CuonSach *cuon = TimCuonSachToanCuc(tv, maCuon, nullptr);
    if (cuon == nullptr)
    {
        loi = "Khong tim thay cuon sach.";
        return false;
    }
    MuonTra *luot = TimMuonDangMuonTheoMa(*docGia, maCuon);
    if (luot == nullptr)
    {
        loi = "Doc gia khong dang muon cuon nay.";
        return false;
    }
    if (cuon->trangThai != SACH_DANG_MUON)
    {
        loi = "Trang thai cuon khong khop lich su.";
        return false;
    }
    int soDangMuon = 0, tongLuot = 0;
    if (!KiemTraLichSuGiaoDich(tv, maThe, maCuon, ngay, soDangMuon, tongLuot, loi))
    {
        return false;
    }
    if (soDangMuon != 1)
    {
        loi = "Cuon sach phai co dung mot luot dang muon.";
        return false;
    }
    if (baoMat)
    {
        luot->ngayTra = ngay;
        luot->trangThai = MUON_LAM_MAT;
        cuon->trangThai = SACH_THANH_LY;
        docGia->thongTin.trangThaiThe = THE_BI_KHOA;
    }
    else
    {
        CapNhatLuotTra(*docGia, maCuon, ngay);
        cuon->trangThai = SACH_CHO_MUON;
    }
    loi.clear();
    return true;
}
bool TraSach(ThuVien &tv, int maThe, const string &ma, const NgayThang &ngay, string &loi)
{
    return XuLyKetThucLuotMuon(tv, maThe, ma, ngay, false, loi);
}
bool DanhDauMatSach(ThuVien &tv, int maThe, const string &ma, const NgayThang &ngay, string &loi)
{
    return XuLyKetThucLuotMuon(tv, maThe, ma, ngay, true, loi);
}
