#include "00_KhaiBaoChung.h"

/* ============================================================
   c. NHAP DAU SACH, DANH MA SACH TU DONG, THEM CUON, THANH LY

   Danh sach dau sach la mang con tro, luon tang dan theo ten sach.
   Khi them: tim vi tri chen bang tim kiem nhi phan, doi cac con tro phia sau
   sang phai mot o roi dat con tro moi vao.

   Danh muc sach: danh sach lien ket don, moi dau sach giu mot danh sach rieng (con tro dms).
   Ma sach tu dong co dang ISBN#N (N = 1, 2, 3...). De yeu cau "danh ma sach tu dong sao cho
   tim thong tin sach theo ma sach nhanh nhat": nho ma sach chua san ISBN nen khi tim mot cuon,
   chuong trinh tach ISBN ra, tim dung dau sach roi chi duyet danh muc cua dau sach do,
   khong phai duyet danh muc cua tat ca dau sach.

   CAU KHAC GOI HAM O DAY:
     DemCuonSach (d, e)
     TachISBNTuMaSach (j)
     TimCuonSachToanCuc (f, g, i)
     TimViTriDauSachTheoISBN (j)
   ============================================================ */

/* ===================== XU LY: DANH SACH DAU SACH (MANG CON TRO) ===================== */

// [THAI]
bool HopLeDauSach(const DauSach &d, string &loi)
{
    if (d.ISBN.size() != 13)
    {
        loi = "ISBN phải gồm đúng 13 chữ số.";
        return false;
    }
    for (int i = 0; i < 13; ++i)
    {
        if (d.ISBN[i] < '0' || d.ISBN[i] > '9')
        {
            loi = "ISBN phải gồm đúng 13 chữ số.";
            return false;
        }
    }
    if (!HopLeVanBan(d.tenSach))
    {
        loi = "Tên sách không hợp lệ.";
        return false;
    }
    if (d.soTrang < 1)
    {
        loi = "Số trang phải lớn hơn 0.";
        return false;
    }
    if (!HopLeVanBan(d.tacGia))
    {
        loi = "Tên tác giả không hợp lệ.";
        return false;
    }
    // Chi kiem nam > 0. Dieu kien "khong vuot qua nam hien tai" nam o man hinh nhap,
    // vi ham nay con duoc goi khi doc file: neu dong ho may bi dat lui nam thi
    // khong duoc coi file hop le la file hong.
    if (d.namXuatBan < 1)
    {
        loi = "Năm xuất bản phải lớn hơn 0.";
        return false;
    }
    if (!HopLeVanBan(d.theLoai))
    {
        loi = "Thể loại không hợp lệ.";
        return false;
    }
    return true;
}

// Mang sap theo ten sach chu khong theo ISBN nen phai tim tuyen tinh.
// Tra ve chi so trong mang, -1 neu khong co.
// @TT [c,e,f,g,h,i,j] Tim dau sach theo ISBN: tim tuyen tinh vi mang sap theo ten, khong theo ISBN - O(n)
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
// @TT [c] Tim vi tri chen theo ten sach: tim kiem nhi phan (vi tri dau tien >= ten moi) - O(log n)
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
// @TT [c] Them dau sach giu mang tang theo ten: tim vi tri bang nhi phan, doi con tro sang phai 1 o - O(n)
bool ThemDauSach(DanhSachDauSach &ds, const DauSach &d, string &loi)
{
    if (ds.soLuong >= MAX_DAU_SACH)
    {
        loi = "Danh sách đầu sách đã đầy.";
        return false;
    }
    if (!HopLeDauSach(d, loi))
        return false;
    if (TimDauSachTheoISBN(ds, d.ISBN) != nullptr)
    {
        loi = "ISBN đã tồn tại, không thể thêm trùng.";
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

/* ===================== XU LY: DANH MUC SACH (DSLK DON), MA SACH TU DONG ===================== */

// [THAI] Vi tri co dang Khu-Ke-Tang, vi du A-01-01.
bool HopLeViTri(const string &viTri)
{
    if (viTri.size() != 7)
        return false;
    if (viTri[0] < 'A' || viTri[0] > 'Z')
        return false;
    if (viTri[1] != '-' || viTri[4] != '-')
        return false;
    for (int i = 2; i < 7; ++i)
    {
        if (i == 4) continue;
        if (viTri[i] < '0' || viTri[i] > '9')
            return false;
    }
    return true;
}

// Lay phan ISBN dung truoc dau '#'. Tra ve chuoi rong neu ma khong co dau '#'.
string TachISBNTuMaSach(const string &ma)
{
    string isbn = "";
    for (int i = 0; i < (int)ma.size(); ++i)
    {
        if (ma[i] == '#')
            return isbn;
        isbn += ma[i];
    }
    return "";
}

// [THAI] Tim mot cuon trong danh muc cua mot dau sach.
CuonSach *TimCuonSachTrongDauSach(const DauSach &d, const string &ma)
{
    CuonSach *p = d.dms;
    while (p != nullptr)
    {
        if (p->maSach == ma)
            return p;
        p = p->next;
    }
    return nullptr;
}

// [THAI] Tim mot cuon theo ma sach trong ca thu vien.
// dauSach nhan ve dau sach chua cuon do (de lay ten sach).
// @TT [f,g,h,i] Tim cuon theo ma sach: tach ISBN truoc dau #, tim dau sach, roi chi duyet
//         DSLK danh muc cua dau sach do (khong duyet danh muc cua moi dau sach)
CuonSach *TimCuonSachToanCuc(const DanhSachDauSach &ds, const string &ma, DauSach *&dauSach)
{
    dauSach = TimDauSachTheoISBN(ds, TachISBNTuMaSach(ma));
    if (dauSach == nullptr)
        return nullptr;
    return TimCuonSachTrongDauSach(*dauSach, ma);
}

// [THAI] Ma moi = ISBN#(N + 1), voi N la so thu tu cua cuon cuoi danh muc.
// Cuon thanh ly/lam mat chi doi trang thai, khong xoa nut, nen nut cuoi luon co N lon nhat.
// @TT [c] Danh ma sach tu dong ISBN#N: N = so thu tu cuon cuoi danh muc + 1
string SinhMaSachTuDong(const DauSach &d)
{
    int soCuoi = 0;
    CuonSach *p = d.dms;
    while (p != nullptr && p->next != nullptr)
        p = p->next;

    if (p != nullptr)
    {
        string phanSo = "";
        bool quaDauThang = false;
        for (int i = 0; i < (int)p->maSach.size(); ++i)
        {
            if (quaDauThang)
                phanSo += p->maSach[i];
            else if (p->maSach[i] == '#')
                quaDauThang = true;
        }
        ChuoiThanhSo(phanSo, soCuoi);
    }
    return d.ISBN + "#" + SoThanhChuoi(soCuoi + 1);
}

// Them mot cuon co san ma vao cuoi danh muc (dung khi doc file).
// @TT [c] Them cuon vao cuoi DSLK don danh muc sach
void ThemCuonSachCoMa(DauSach &d, const string &ma, const string &viTri, int trangThai)
{
    CuonSach *moi = new CuonSach;
    moi->maSach = ma;
    moi->viTri = viTri;
    moi->trangThai = trangThai;

    if (d.dms == nullptr)
    {
        d.dms = moi;
        return;
    }
    CuonSach *p = d.dms;
    while (p->next != nullptr)
        p = p->next;
    p->next = moi;
}

// Them mot cuon moi, ma sach do chuong trinh tu cap.
void ThemCuonSach(DauSach &d, const string &viTri, int trangThai)
{
    ThemCuonSachCoMa(d, SinhMaSachTuDong(d), viTri, trangThai);
}

// [THAI]
int DemCuonSach(const CuonSach *head)
{
    int dem = 0;
    while (head != nullptr)
    {
        ++dem;
        head = head->next;
    }
    return dem;
}

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
