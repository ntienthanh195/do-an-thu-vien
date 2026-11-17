#include "00_KhaiBaoChung.h"

/* ============================================================
   c. NHAP DAU SACH, THEM CUON, THANH LY (cac man hinh)
   Thao tac tren mang dau sach nam o 11_DauSach_MangConTro.cpp:
     ThemDauSach (tim nhi phan vi tri chen + doi con tro), TimDauSachTheoISBN.
   Danh ma sach tu dong nam o 12_DanhMucSach_DSLKDon.cpp: SinhMaSachTuDong, ThemCuonSach.
   ============================================================ */

/* ===================== GIAO DIEN ===================== */

// Nhap so cuon va vi tri, roi them cac cuon vao dau sach d. Tra ve so cuon da them.
static int NhapCacCuonSach(DauSach &d, int y)
{
    InTai(4, y, "Số cuốn thêm   :");
    InTai(4, y + 2, "Vị trí A-01-01 :");

    int soCuon = 0;
    string viTri = "";
    while (true)
    {
        if (!NhapSo(22, y, 3, soCuon))
            return 0;
        if (!NhapChuoi(22, y + 2, 7, false, viTri))
            return 0;
        if (viTri.size() > 0 && viTri[0] >= 'a' && viTri[0] <= 'z')
            viTri[0] = (char)(viTri[0] - 32);
        if (soCuon < 1)
            ThongBao("Số cuốn phải lớn hơn 0.", true);
        else if (!HopLeViTri(viTri))
            ThongBao("Vị trí phải có dạng Khu-Kệ-Tầng, ví dụ A-01-01.", true);
        else
            break;
    }
    for (int i = 0; i < soCuon; ++i)
        ThemCuonSach(d, viTri, SACH_CHO_MUON);
    return soCuon;
}

// [THAI] Nhap dau sach moi. Moi o duoc kiem tra ngay sau khi nhap, sai thi nhap lai o do.
static void ManHinhThemDauSach(DanhSachDauSach &ds, CayDocGia &cay)
{
    while (true)
    {
        VeManHinh(3, "Nhập đầu sách mới", "Enter: sang ô tiếp theo    Esc: hủy và quay lại");
        InTai(4, 5, "ISBN (13 số)   :");
        InTai(4, 7, "Tên sách       :");
        InTai(4, 9, "Số trang       :");
        InTai(4, 11, "Tác giả        :");
        InTai(4, 13, "Năm xuất bản   :");
        InTai(4, 15, "Thể loại       :");

        DauSach d;
        string loi;

        // --- 1. ISBN: dung 13 chu so va chua co trong thu vien ---
        while (true)
        {
            if (!NhapChuoi(22, 5, 17, false, d.ISBN)) return;
            d.ISBN = ChuanHoaISBN(d.ISBN);

            bool hopLe = (d.ISBN.size() == 13);
            for (int i = 0; hopLe && i < 13; ++i)
            {
                if (d.ISBN[i] < '0' || d.ISBN[i] > '9')
                    hopLe = false;
            }
            if (!hopLe)
                ThongBao("ISBN phải gồm đúng 13 chữ số (0-9).", true);
            else if (TimDauSachTheoISBN(ds, d.ISBN) != nullptr)
                ThongBao("ISBN này đã tồn tại. Vui lòng nhập lại.", true);
            else
                break;
        }

        // --- 2. Ten sach ---
        while (true)
        {
            if (!NhapChuoi(22, 7, 60, false, d.tenSach)) return;
            d.tenSach = ChuanHoaChuoiSach(d.tenSach);
            if (HopLeVanBan(d.tenSach))
                break;
            ThongBao("Tên sách không được để trống, không chứa ký tự '|'.", true);
        }

        // --- 3. So trang ---
        while (true)
        {
            if (!NhapSo(22, 9, 6, d.soTrang)) return;
            if (d.soTrang >= 1 && d.soTrang <= 100000)
                break;
            ThongBao("Số trang phải từ 1 đến 100000.", true);
        }

        // --- 4. Tac gia ---
        while (true)
        {
            if (!NhapChuoi(22, 11, 40, false, d.tacGia)) return;
            d.tacGia = ChuanHoaChuoiSach(d.tacGia);
            if (HopLeVanBan(d.tacGia))
                break;
            ThongBao("Tác giả không được để trống, không chứa ký tự '|'.", true);
        }

        // --- 5. Nam xuat ban ---
        while (true)
        {
            if (!NhapSo(22, 13, 4, d.namXuatBan)) return;
            if (d.namXuatBan >= 1 && d.namXuatBan <= HomNay().nam)
                break;
            ThongBao("Năm xuất bản phải từ 1 đến năm hiện tại.", true);
        }

        // --- 6. The loai ---
        while (true)
        {
            if (!NhapChuoi(22, 15, 30, false, d.theLoai)) return;
            d.theLoai = ChuanHoaChuoiSach(d.theLoai);
            if (HopLeVanBan(d.theLoai))
                break;
            ThongBao("Thể loại không được để trống, không chứa ký tự '|'.", true);
        }

        // --- Thuc hien them ---
        if (!ThemDauSach(ds, d, loi))
        {
            ThongBao("Thêm thất bại: " + loi, true);
            continue;
        }

        // danh ma sach tu dong cho cac cuon cua dau sach vua them
        DauSach *moi = TimDauSachTheoISBN(ds, d.ISBN);
        int soCuon = NhapCacCuonSach(*moi, 17);
        LuuSauThayDoi(ds, cay);
        if (soCuon == 0)
            ThongBao("Đã thêm đầu sách \"" + moi->tenSach + "\", chưa có cuốn nào.", false);
        else
            ThongBao("Đã thêm đầu sách \"" + moi->tenSach + "\" với " + SoThanhChuoi(soCuon) +
                         " cuốn. Mã cuốn đầu: " + moi->ISBN + "#1", false);
    }
}

static void ManHinhThemCuonSach(DanhSachDauSach &ds, CayDocGia &cay)
{
    VeManHinh(3, "Thêm cuốn sách cho đầu sách đã có", "Enter: sang ô tiếp theo    Esc: quay lại");
    InTai(4, 5, "ISBN (13 số)   :");

    string isbn = "";
    DauSach *d = nullptr;
    while (d == nullptr)
    {
        if (!NhapChuoi(22, 5, 17, false, isbn))
            return;
        d = TimDauSachTheoISBN(ds, ChuanHoaISBN(isbn));
        if (d == nullptr)
            ThongBao("Không có đầu sách nào mang ISBN này.", true);
    }

    InTai(4, 7, "Tên sách       : " + d->tenSach);
    InTai(4, 9, "Số cuốn hiện có: " + SoThanhChuoi(DemCuonSach(d->dms)));

    int soCuon = NhapCacCuonSach(*d, 11);
    if (soCuon > 0)
    {
        LuuSauThayDoi(ds, cay);
        ThongBao("Đã thêm " + SoThanhChuoi(soCuon) + " cuốn. Mã cuốn mới nhất: " +
                     d->ISBN + "#" + SoThanhChuoi(DemCuonSach(d->dms)), false);
    }
}

static void ManHinhThanhLySach(DanhSachDauSach &ds, CayDocGia &cay)
{
    VeManHinh(3, "Thanh lý cuốn sách", "Enter: xác nhận mã sách    Esc: quay lại");
    InTai(4, 5, "Mã sách (ISBN#N):");

    string ma = "";
    while (true)
    {
        if (!NhapChuoi(22, 5, 20, false, ma))
            return;
        DauSach *d = nullptr;
        CuonSach *cuon = TimCuonSachToanCuc(ds, ma, d);
        if (cuon == nullptr)
            ThongBao("Không tìm thấy mã sách này.", true);
        else if (cuon->trangThai == SACH_DANG_MUON)
            ThongBao("Sách đang có độc giả mượn, không thanh lý được.", true);
        else if (cuon->trangThai == SACH_THANH_LY)
            ThongBao("Cuốn sách này đã thanh lý từ trước.", true);
        else if (XacNhan("Thanh lý cuốn " + ma + " của \"" + d->tenSach + "\"?"))
        {
            cuon->trangThai = SACH_THANH_LY;
            LuuSauThayDoi(ds, cay);
            ThongBao("Đã thanh lý cuốn sách.", false);
        }
    }
}

void ManHinhNhapSach(DanhSachDauSach &ds, CayDocGia &cay)
{
    string muc[3] = {"1. Nhập đầu sách mới", "2. Thêm cuốn sách cho đầu sách đã có",
                     "3. Thanh lý cuốn sách"};
    while (true)
    {
        VeManHinh(3, "Nhập sách", "↑/↓: chọn    Enter: vào    Esc: quay lại");
        int chon = ChonMenu(4, 5, 44, muc, 3);
        if (chon == -1)
            return;
        if (chon == 0)
            ManHinhThemDauSach(ds, cay);
        else if (chon == 1)
            ManHinhThemCuonSach(ds, cay);
        else
            ManHinhThanhLySach(ds, cay);
    }
}
