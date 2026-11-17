#include "00_KhaiBaoChung.h"

/* ============================================================
   a. QUAN LY THE DOC GIA: them / xoa / hieu chinh (cac man hinh)
   Thao tac tren cay (tim, them, xoa, xoay AVL, cap ma the) nam o 10_DocGia_CayAVL.cpp:
     tim_cay, them_cay, XoaDocGia, HieuChinhDocGia, MaTheLonNhat, SinhMaTheTiepTheo.

   HAM LAY TU FILE KHAC:
     10_DocGia_CayAVL.cpp: HieuChinhDocGia, MaTheLonNhat, SinhMaTheTiepTheo, XoaDocGia, them_cay, tim_cay
   ============================================================ */

/* ===================== GIAO DIEN ===================== */

void InThongTinDocGia(int x, int y, const NutDocGia &docgia)
{
    const DocGia &dg = docgia.thongTin;
    InCot(x, y, "Họ tên    : " + dg.ho + " " + dg.ten, 60);
    InCot(x, y + 1, "Phái      : " + dg.phai, 60);
    InTai(x, y + 2, "Trạng thái: "); // hai lenh cout ben duoi in tiep ngay sau con tro
    if (dg.trangThaiThe == THE_HOAT_DONG)
    {
        SetColor(MAU_XANH_LA_SANG, MAU_DEN);
        cout << "Đang hoạt động";
    }
    else
    {
        SetColor(MAU_DO_SANG, MAU_DEN);
        cout << "Bị khóa       ";
    }
    SetColor(MAU_TRANG, MAU_DEN);
}

// Nhap ma the tai (x, y) cho toi khi tim thay doc gia. Tra ve nullptr neu nhan Esc.
NutDocGia *NhapMaTheTimDocGia(CayDocGia &caydocgia, int x, int y)
{
    InTai(x, y, "Mã thẻ độc giả :");
    int maThe = 0;
    while (true)
    {
        if (!NhapSo(x + 18, y, 6, maThe))
            return nullptr;
        NutDocGia *p = tim_cay(caydocgia, maThe);
        if (p != nullptr)
            return p;
        ThongBao("Không có độc giả mang mã thẻ " + SoThanhChuoi(maThe) + ".", true);
    }
}

// Nhap ho, ten, phai vao dg. Tra ve false neu nhan Esc.
static bool NhapHoTenPhai(int y, DocGia &dg)
{
    InTai(4, y, "Họ và tên lót  :");
    InTai(4, y + 2, "Tên            :");
    InTai(4, y + 4, "Phái (Nam/Nu)  :");
    while (true)
    {
        if (!NhapChuoi(22, y, 30, false, dg.ho)) return false;
        if (!NhapChuoi(22, y + 2, 15, false, dg.ten)) return false;
        if (!NhapChuoi(22, y + 4, 3, false, dg.phai)) return false;

        dg.ho = ChuanHoaTen(dg.ho);
        dg.ten = ChuanHoaTen(dg.ten);
        dg.phai = ChuanHoaTen(dg.phai);

        if (!HopLeVanBan(dg.ho) || !HopLeVanBan(dg.ten))
            ThongBao("Họ và tên không được rỗng, không chứa ký tự '|'.", true);
        else if (!HopLePhai(dg.phai))
            ThongBao("Phái chỉ nhận Nam hoặc Nu.", true);
        else
            return true;
    }
}

static void ManHinhThemDocGia(DanhSachDauSach &ds, CayDocGia &cay)
{
    while (true)
    {
        VeManHinh(1, "Thêm thẻ độc giả", "Enter: sang ô tiếp theo    Esc: quay lại");
        DocGia dg;
        if (!NhapHoTenPhai(5, dg))
            return;

        // ma moi = ma lon nhat dang co + 1 nen khong trung voi ma nao trong cay
        int maTheDaCap = MaTheLonNhat(cay);
        dg.maThe = SinhMaTheTiepTheo(maTheDaCap);
        dg.trangThaiThe = THE_HOAT_DONG;
        them_cay(cay, dg);
        LuuSauThayDoi(ds, cay);
        ThongBao("Đã thêm độc giả " + dg.ho + " " + dg.ten + ". Mã thẻ được cấp: " +
                     SoThanhChuoi(dg.maThe), false);
    }
}

static void ManHinhHieuChinhDocGia(DanhSachDauSach &ds, CayDocGia &cay)
{
    string mucTrangThai[2] = {"Khóa thẻ", "Đang hoạt động"};
    while (true)
    {
        VeManHinh(1, "Hiệu chỉnh thẻ độc giả", "Enter: sang ô tiếp theo    Esc: quay lại");
        NutDocGia *p = NhapMaTheTimDocGia(cay, 4, 5);
        if (p == nullptr)
            return;

        DocGia dg = p->thongTin; // ban sao de sua, chi ghi vao cay khi nhap xong
        if (!NhapHoTenPhai(7, dg))
            continue;

        InTai(4, 13, "Trạng thái thẻ :");
        int chon = ChonMenu(22, 13, 20, mucTrangThai, 2);
        if (chon == -1)
            continue;

        HieuChinhDocGia(cay, dg.maThe, dg.ho, dg.ten, dg.phai, chon);
        LuuSauThayDoi(ds, cay);
        ThongBao("Đã cập nhật thẻ " + SoThanhChuoi(dg.maThe) + ".", false);
    }
}

static void ManHinhXoaDocGia(DanhSachDauSach &ds, CayDocGia &cay)
{
    while (true)
    {
        VeManHinh(1, "Xóa thẻ độc giả", "Enter: tìm độc giả    Esc: quay lại");
        NutDocGia *p = NhapMaTheTimDocGia(cay, 4, 5);
        if (p == nullptr)
            return;

        int maThe = p->thongTin.maThe;
        InThongTinDocGia(4, 7, *p);
        if (!XacNhan("Xóa thẻ độc giả " + SoThanhChuoi(maThe) + "?"))
            continue;

        string loi;
        if (XoaDocGia(cay, maThe, loi))
        {
            LuuSauThayDoi(ds, cay);
            ThongBao("Đã xóa thẻ " + SoThanhChuoi(maThe) + ".", false);
        }
        else
            ThongBao(loi, true);
    }
}

void ManHinhQuanLyDocGia(DanhSachDauSach &ds, CayDocGia &cay)
{
    string muc[3] = {"1. Thêm thẻ độc giả", "2. Hiệu chỉnh thẻ độc giả", "3. Xóa thẻ độc giả"};
    while (true)
    {
        VeManHinh(1, "Quản lý thẻ độc giả", "↑/↓: chọn    Enter: vào    Esc: quay lại");
        int chon = ChonMenu(4, 5, 34, muc, 3);
        if (chon == -1)
            return;
        if (chon == 0)
            ManHinhThemDocGia(ds, cay);
        else if (chon == 1)
            ManHinhHieuChinhDocGia(ds, cay);
        else
            ManHinhXoaDocGia(ds, cay);
    }
}
