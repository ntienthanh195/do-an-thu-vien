#include "00_KhaiBaoChung.h"

// [DEMO - CODEX] Phan bo sung cho ban trinh thay.
void InThongTinDauSach(const DauSach &sach, ostream &out, bool inCuon)
{
    out << "ISBN: " << sach.ISBN << " | " << sach.tenSach << " | " << sach.tacGia << " | "
        << sach.namXuatBan << " | " << sach.soTrang << " trang | " << sach.theLoai << '\n';
    if (!inCuon)
    {
        return;
    }
    const CuonSach *p = sach.dms;
    if (p == nullptr)
    {
        out << "  Chua co cuon sach.\n";
    }
    while (p != nullptr)
    {
        out << "  " << p->maSach << " | ";
        if (p->trangThai == SACH_CHO_MUON)
        {
            out << "Cho muon";
        }
        else if (p->trangThai == SACH_DANG_MUON)
        {
            out << "Dang muon";
        }
        else
        {
            out << "Da thanh ly";
        }
        out << " | Vi tri: " << p->viTri << '\n';
        p = p->next;
    }
}
void TimDauSachTheoTen(const ThuVien &tv, const string &ten, ostream &out)
{
    if (LaChuoiRong(ten))
    {
        out << "Tu khoa tim kiem khong duoc rong.\n";
        return;
    }
    int soKetQua = 0;
    for (int i = 0; i < tv.dsDauSach.soLuong; i++)
    {
        if (ChuaChuoi(tv.dsDauSach.ds[i]->tenSach, ten))
        {
            InThongTinDauSach(*tv.dsDauSach.ds[i], out, true);
            soKetQua++;
        }
    }
    out << "Tim thay " << soKetQua << " dau sach.\n";
}
void InDanhSachDauSach(const ThuVien &tv, ostream &out)
{
    if (tv.dsDauSach.soLuong == 0)
    {
        out << "Danh sach dau sach rong.\n";
    }
    for (int i = 0; i < tv.dsDauSach.soLuong; i++)
    {
        InThongTinDauSach(*tv.dsDauSach.ds[i], out, false);
    }
}
void ManHinhTimSach(const ThuVien &tv)
{
    string ten;
    if (!NhapDong("Ten/phan ten sach can tim: ", ten))
    {
        return;
    }
    ostringstream out;
    out.exceptions(ios::badbit | ios::failbit);
    TimDauSachTheoTen(tv, ten, out);
    HienThiPhanTrang(out.str());
}
