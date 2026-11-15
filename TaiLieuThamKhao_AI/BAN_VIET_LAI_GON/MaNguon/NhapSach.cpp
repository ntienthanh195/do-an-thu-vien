#include "00_KhaiBaoChung.h"

/* ============================================================
   c. NHAP DAU SACH
   Danh sach dau sach la mang con tro, luon tang dan theo ten sach.
   Khi them: tim vi tri chen bang tim kiem nhi phan, doi cac con tro phia sau
   sang phai mot o roi dat con tro moi vao.
   ============================================================ */

// [THAI]
bool HopLeDauSach(const DauSach &d, string &loi)
{
    if (d.ISBN.size() != 13)
    {
        loi = "ISBN phai gom dung 13 chu so.";
        return false;
    }
    for (int i = 0; i < 13; ++i)
    {
        if (d.ISBN[i] < '0' || d.ISBN[i] > '9')
        {
            loi = "ISBN phai gom dung 13 chu so.";
            return false;
        }
    }
    if (!HopLeVanBan(d.tenSach))
    {
        loi = "Ten sach khong hop le.";
        return false;
    }
    if (d.soTrang < 1)
    {
        loi = "So trang phai lon hon 0.";
        return false;
    }
    if (!HopLeVanBan(d.tacGia))
    {
        loi = "Ten tac gia khong hop le.";
        return false;
    }
    if (d.namXuatBan < 1 || d.namXuatBan > HomNay().nam)
    {
        loi = "Nam xuat ban phai lon hon 0 va khong vuot qua nam hien tai.";
        return false;
    }
    if (!HopLeVanBan(d.theLoai))
    {
        loi = "The loai khong hop le.";
        return false;
    }
    return true;
}

// Mang sap theo ten sach chu khong theo ISBN nen phai tim tuyen tinh.
// Tra ve chi so trong mang, -1 neu khong co.
int TimViTriDauSachTheoISBN(const DanhSachDauSach &ds, const string &isbn)
{
    for (int i = 0; i < ds.soLuong; ++i)
    {
        if (ds.ds[i]->ISBN == isbn)
            return i;
    }
    return -1;
}

// [THAI]
DauSach *TimDauSachTheoISBN(const DanhSachDauSach &ds, const string &isbn)
{
    int viTri = TimViTriDauSachTheoISBN(ds, isbn);
    if (viTri == -1)
        return nullptr;
    return ds.ds[viTri];
}

// [THAI] Tim kiem nhi phan: vi tri dau tien co ten sach >= ten sach moi.
int TimViTriChenTheoTen(const DanhSachDauSach &ds, const DauSach &d)
{
    int l = 0;
    int r = ds.soLuong;
    while (l < r)
    {
        int m = (l + r) / 2;
        if (SoSanhChuoi(ds.ds[m]->tenSach, d.tenSach) < 0)
            l = m + 1; // ds[m] < d  -> chen sau m
        else
            r = m;     // ds[m] >= d -> chen tai m hoac truoc m
    }
    return l;
}

// [THAI] Them mot dau sach va giu mang tang dan theo ten sach.
bool ThemDauSach(DanhSachDauSach &ds, const DauSach &d, string &loi)
{
    if (ds.soLuong >= MAX_DAU_SACH)
    {
        loi = "Danh sach dau sach da day.";
        return false;
    }
    if (!HopLeDauSach(d, loi))
        return false;
    if (TimDauSachTheoISBN(ds, d.ISBN) != nullptr)
    {
        loi = "ISBN da ton tai, khong the them trung.";
        return false;
    }

    int viTriChen = TimViTriChenTheoTen(ds, d);
    for (int i = ds.soLuong; i > viTriChen; --i)
        ds.ds[i] = ds.ds[i - 1];

    ds.ds[viTriChen] = new DauSach;
    *ds.ds[viTriChen] = d;
    ds.ds[viTriChen]->dms = nullptr;
    ++ds.soLuong;
    return true;
}

// Giai phong tat ca dau sach va danh muc cuon sach cua chung.
void HuyDanhSachDauSach(DanhSachDauSach &ds)
{
    for (int i = 0; i < ds.soLuong; ++i)
    {
        CuonSach *p = ds.ds[i]->dms;
        while (p != nullptr)
        {
            CuonSach *xoa = p;
            p = p->next;
            delete xoa;
        }
        delete ds.ds[i];
    }
    ds.soLuong = 0;
}

/* ===================== MAN HINH ===================== */

// Nhap so cuon va vi tri, roi them cac cuon vao dau sach d. Tra ve so cuon da them.
static int NhapCacCuonSach(DauSach &d, int y)
{
    InTai(4, y, "So cuon them   :");
    InTai(4, y + 2, "Vi tri A-01-01 :");

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
            ThongBao("So cuon phai lon hon 0.", true);
        else if (!HopLeViTri(viTri))
            ThongBao("Vi tri phai co dang Khu-Ke-Tang, vi du A-01-01.", true);
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
        VeManHinh("c. NHAP DAU SACH MOI", "Enter: sang o tiep theo    Esc: huy va quay lai");
        InTai(4, 5, "ISBN (13 so)   :");
        InTai(4, 7, "Ten sach       :");
        InTai(4, 9, "So trang       :");
        InTai(4, 11, "Tac gia        :");
        InTai(4, 13, "Nam xuat ban   :");
        InTai(4, 15, "The loai       :");

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
                ThongBao("ISBN phai gom dung 13 chu so (0-9).", true);
            else if (TimDauSachTheoISBN(ds, d.ISBN) != nullptr)
                ThongBao("ISBN nay da ton tai. Vui long nhap lai.", true);
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
            ThongBao("Ten sach khong duoc de trong, khong chua ky tu '|'.", true);
        }

        // --- 3. So trang ---
        while (true)
        {
            if (!NhapSo(22, 9, 6, d.soTrang)) return;
            if (d.soTrang >= 1 && d.soTrang <= 100000)
                break;
            ThongBao("So trang phai tu 1 den 100000.", true);
        }

        // --- 4. Tac gia ---
        while (true)
        {
            if (!NhapChuoi(22, 11, 40, false, d.tacGia)) return;
            d.tacGia = ChuanHoaChuoiSach(d.tacGia);
            if (HopLeVanBan(d.tacGia))
                break;
            ThongBao("Tac gia khong duoc de trong, khong chua ky tu '|'.", true);
        }

        // --- 5. Nam xuat ban ---
        while (true)
        {
            if (!NhapSo(22, 13, 4, d.namXuatBan)) return;
            if (d.namXuatBan >= 1 && d.namXuatBan <= HomNay().nam)
                break;
            ThongBao("Nam xuat ban phai tu 1 den nam hien tai.", true);
        }

        // --- 6. The loai ---
        while (true)
        {
            if (!NhapChuoi(22, 15, 30, false, d.theLoai)) return;
            d.theLoai = ChuanHoaChuoiSach(d.theLoai);
            if (HopLeVanBan(d.theLoai))
                break;
            ThongBao("The loai khong duoc de trong, khong chua ky tu '|'.", true);
        }

        // --- Thuc hien them ---
        if (!ThemDauSach(ds, d, loi))
        {
            ThongBao("Them that bai: " + loi, true);
            continue;
        }

        // danh ma sach tu dong cho cac cuon cua dau sach vua them
        DauSach *moi = TimDauSachTheoISBN(ds, d.ISBN);
        int soCuon = NhapCacCuonSach(*moi, 17);
        LuuSauThayDoi(ds, cay);
        if (soCuon == 0)
            ThongBao("Da them dau sach \"" + moi->tenSach + "\", chua co cuon nao.", false);
        else
            ThongBao("Da them dau sach \"" + moi->tenSach + "\" voi " + SoThanhChuoi(soCuon) +
                         " cuon. Ma cuon dau: " + moi->ISBN + "#1", false);
    }
}

static void ManHinhThemCuonSach(DanhSachDauSach &ds, CayDocGia &cay)
{
    VeManHinh("c. THEM CUON SACH CHO DAU SACH DA CO", "Enter: sang o tiep theo    Esc: quay lai");
    InTai(4, 5, "ISBN (13 so)   :");

    string isbn = "";
    DauSach *d = nullptr;
    while (d == nullptr)
    {
        if (!NhapChuoi(22, 5, 17, false, isbn))
            return;
        d = TimDauSachTheoISBN(ds, ChuanHoaISBN(isbn));
        if (d == nullptr)
            ThongBao("Khong co dau sach nao mang ISBN nay.", true);
    }

    InTai(4, 7, "Ten sach       : " + d->tenSach);
    InTai(4, 9, "So cuon hien co: " + SoThanhChuoi(DemCuonSach(d->dms)));

    int soCuon = NhapCacCuonSach(*d, 11);
    if (soCuon > 0)
    {
        LuuSauThayDoi(ds, cay);
        ThongBao("Da them " + SoThanhChuoi(soCuon) + " cuon. Ma cuon moi nhat: " +
                     d->ISBN + "#" + SoThanhChuoi(DemCuonSach(d->dms)), false);
    }
}

static void ManHinhThanhLySach(DanhSachDauSach &ds, CayDocGia &cay)
{
    VeManHinh("c. THANH LY CUON SACH", "Enter: xac nhan ma sach    Esc: quay lai");
    InTai(4, 5, "Ma sach (ISBN#N):");

    string ma = "";
    while (true)
    {
        if (!NhapChuoi(22, 5, 20, false, ma))
            return;
        DauSach *d = nullptr;
        CuonSach *cuon = TimCuonSachToanCuc(ds, ma, d);
        if (cuon == nullptr)
            ThongBao("Khong tim thay ma sach nay.", true);
        else if (cuon->trangThai == SACH_DANG_MUON)
            ThongBao("Sach dang co doc gia muon, khong thanh ly duoc.", true);
        else if (cuon->trangThai == SACH_THANH_LY)
            ThongBao("Cuon sach nay da thanh ly tu truoc.", true);
        else if (XacNhan("Thanh ly cuon " + ma + " cua \"" + d->tenSach + "\"?"))
        {
            cuon->trangThai = SACH_THANH_LY;
            LuuSauThayDoi(ds, cay);
            ThongBao("Da thanh ly cuon sach.", false);
        }
    }
}

void ManHinhNhapSach(DanhSachDauSach &ds, CayDocGia &cay)
{
    string muc[3] = {"1. Nhap dau sach moi", "2. Them cuon sach cho dau sach da co",
                     "3. Thanh ly cuon sach"};
    while (true)
    {
        VeManHinh("c. NHAP SACH", "Len/Xuong: chon    Enter: vao    Esc: quay lai");
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
