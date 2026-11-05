#include "00_KhaiBaoChung.h"

// [DEMO - CODEX] Phan bo sung cho ban trinh thay.
int ChonChucNang(const NgayThang &ngay, const string &path)
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
    return ChonMenu("THU VIEN | " + ChuoiNgay(ngay) + "\nDu lieu: " + path, labels, 13);
}

void ChayChucNang(int choice, ThuVien &tv, const NgayThang &ngay)
{
    ostringstream out;
    out.exceptions(ios::badbit | ios::failbit);
    if (choice == 1)
    {
        ManHinhDocGia(tv);
    }
    else if (choice == 2)
    {
        const char *views[] = {"Theo ma the", "Theo ten + ho"};
        int v = ChonMenu("b - DOC GIA", views, 2);
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
            HienThiPhanTrang(out.str());
        }
    }
    else if (choice == 3)
    {
        ManHinhNhapDauSach(tv);
    }
    else if (choice == 4)
    {
        InDauSachTheoTheLoai(tv, out);
        HienThiPhanTrang(out.str());
    }
    else if (choice == 5)
    {
        ManHinhTimSach(tv);
    }
    else if (choice == 6 || choice == 7)
    {
        ManHinhMuonTra(tv, ngay, choice == 7);
    }
    else if (choice == 8)
    {
        int ma;
        if (NhapSo("Ma the", ma, 1, SO_NGUYEN_LON_NHAT))
        {
            LietKeSachDangMuon(tv, ma, out);
            HienThiPhanTrang(out.str());
        }
    }
    else if (choice == 9)
    {
        InDocGiaQuaHan(tv, ngay, out);
        HienThiPhanTrang(out.str());
    }
    else if (choice == 10)
    {
        InTop10SachDuocMuonNhieuNhat(tv, out);
        HienThiPhanTrang(out.str());
    }
}
