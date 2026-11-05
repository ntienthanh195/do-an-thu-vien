#include "00_KhaiBaoChung.h"

// [DEMO - CODEX] Phan bo sung cho ban trinh thay.
int ChonChucNang(GiaoDien &gd, const NgayThang &ngay, const string &path)
{
    const char *labels[] = {"a - Them / xoa / sua doc gia",
                            "b - Liet ke doc gia",
                            "c - Nhap dau sach / them cuon",
                            "d - Dau sach theo the loai",
                            "e - Tim theo ten sach",
                            "f - Muon sach",
                            "g - Tra / bao mat sach",
                            "h - Sach doc gia dang muon",
                            "i - Doc gia qua han",
                            "j - Top 10 dau sach",
                            "Nap file khac",
                            "Luu du lieu",
                            "Thoat (khong thu luu lai)"};
    return ChonMenu(gd, "THU VIEN | " + ChuoiNgay(ngay) + "\nDu lieu: " + path, labels, 13);
}

void ChayChucNang(GiaoDien &gd, int choice, ThuVien &tv, const NgayThang &ngay)
{
    ostringstream out;
    out.exceptions(ios::badbit | ios::failbit);
    if (choice == 1)
    {
        ManHinhDocGia(gd, tv);
    }
    else if (choice == 2)
    {
        const char *views[] = {"Theo ma the", "Theo ten + ho"};
        int v = ChonMenu(gd, "b - DOC GIA", views, 2);
        if (v == 1)
        {
            InDocGiaTheoMa(tv, out);
        }
        else if (v == 2)
        {
            InDocGiaTheoTenHo(tv, out);
        }
        if (v)
        {
            HienThiPhanTrang(gd, out.str());
        }
    }
    else if (choice == 3)
    {
        ManHinhNhapDauSach(gd, tv);
    }
    else if (choice == 4)
    {
        InDauSachTheoTheLoai(tv, out);
        HienThiPhanTrang(gd, out.str());
    }
    else if (choice == 5)
    {
        ManHinhTimSach(gd, tv);
    }
    else if (choice == 6 || choice == 7)
    {
        ManHinhMuonTra(gd, tv, ngay, choice == 7);
    }
    else if (choice == 8)
    {
        int ma;
        if (NhapSo(gd, "Ma the", ma, 1, INT_MAX))
        {
            LietKeSachDangMuon(tv, ma, out);
            HienThiPhanTrang(gd, out.str());
        }
    }
    else if (choice == 9)
    {
        InDocGiaQuaHan(tv, ngay, out);
        HienThiPhanTrang(gd, out.str());
    }
    else if (choice == 10)
    {
        InTop10SachDuocMuonNhieuNhat(tv, out);
        HienThiPhanTrang(gd, out.str());
    }
}
