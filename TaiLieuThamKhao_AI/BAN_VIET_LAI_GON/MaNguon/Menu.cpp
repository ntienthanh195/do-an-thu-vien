#include "00_KhaiBaoChung.h"

/* ============================================================
   MAN HINH CHINH
   Thanh menu ben trai liet ke cac chuc nang, vung noi dung ben phai hien trang "Tong quan":
   bon o so lieu va bang danh muc dau sach. Nguoi dung di chuyen tren thanh menu bang
   Len/Xuong, Enter de mo chuc nang; khi chuc nang ket thuc (Esc) thi quay ve day.
   Cac so lieu deu duoc dem lai moi lan ve, khong luu thanh bien.
   ============================================================ */

// Dem so cuon sach cua ca thu vien co trang thai trangThai.
// Truyen -1 de dem tat ca cac cuon.
static int DemCuonTheoTrangThai(const DanhSachDauSach &ds, int trangThai)
{
    int tong = 0;
    for (int i = 0; i < ds.soLuong; ++i)
    {
        for (CuonSach *p = ds.ds[i]->dms; p != nullptr; p = p->next)
        {
            if (trangThai == -1 || p->trangThai == trangThai)
                ++tong;
        }
    }
    return tong;
}

// Ve mot o so lieu: mot o chu nhat nen sang hon, con so o tren, ten so lieu o duoi.
static void VeOSoLieu(int x, int y, int so, const string &ten)
{
    SetColor(MAU_TRANG, MAU_NEN_O);
    XoaVung(x, y, 21, 4);
    SetColor(MAU_NGOC_SANG, MAU_NEN_O);
    InTai(x + 2, y + 1, SoThanhChuoi(so));
    SetColor(MAU_TRANG, MAU_NEN_O);
    InTai(x + 2, y + 2, ten);
    SetColor(MAU_TRANG, MAU_DEN);
}

// Trang "Tong quan": loi chao, bon o so lieu va 10 dau sach dau tien theo ten.
static void VeTongQuan(const DanhSachDauSach &ds, CayDocGia cay)
{
    const int SO_DONG_BANG = 10;

    SetColor(MAU_NGOC_SANG, MAU_DEN);
    InTai(2, 4, "Chào bạn, thư viện hôm nay có gì?");

    VeOSoLieu(2, 6, ds.soLuong, "Đầu sách");
    VeOSoLieu(25, 6, DemCuonTheoTrangThai(ds, -1), "Cuốn sách");
    VeOSoLieu(48, 6, DemDocGia(cay), "Độc giả");
    VeOSoLieu(71, 6, DemCuonTheoTrangThai(ds, SACH_DANG_MUON), "Đang được mượn");

    // khung bang danh muc, ten bang nam tren canh tren cua khung
    SetColor(MAU_XAM, MAU_DEN);
    VeKhung(2, 11, 90, SO_DONG_BANG + 4);
    InTai(4, 11, " Danh mục đầu sách ");
    InCot(4, 12, "ISBN", 16);
    InCot(20, 12, "Tên sách", 38);
    InCot(58, 12, "Thể loại", 14);
    InCot(72, 12, "Cuốn", 8);
    InCot(80, 12, "Trên kệ", 10);

    for (int i = 0; i < ds.soLuong && i < SO_DONG_BANG; ++i)
    {
        const DauSach &d = *ds.ds[i];
        int conTrenKe = 0;
        for (CuonSach *p = d.dms; p != nullptr; p = p->next)
        {
            if (p->trangThai == SACH_CHO_MUON)
                ++conTrenKe;
        }
        // dong chan, dong le co nen khac nhau cho de do theo hang
        int nen = MAU_DEN;
        if (i % 2 == 0)
            nen = MAU_NEN_O;
        SetColor(MAU_TRANG, nen);
        InCot(4, 13 + i, d.ISBN, 16);
        SetColor(MAU_TRANG_SANG, nen);
        InCot(20, 13 + i, d.tenSach, 38);
        SetColor(MAU_TRANG, nen);
        InCot(58, 13 + i, d.theLoai, 14);
        SetColor(MAU_NGOC_SANG, nen);
        InCot(72, 13 + i, SoThanhChuoi(DemCuonSach(d.dms)), 8);
        InCot(80, 13 + i, SoThanhChuoi(conTrenKe), 10);
    }

    SetColor(MAU_XAM, MAU_DEN);
    if (ds.soLuong == 0)
        InTai(4, 13, "Thư viện chưa có đầu sách nào. Chọn \"Nhập sách\" để bắt đầu.");
    else if (ds.soLuong > SO_DONG_BANG)
        InTai(4, 13 + SO_DONG_BANG, "... và " + SoThanhChuoi(ds.soLuong - SO_DONG_BANG) +
                                        " đầu sách khác (xem mục \"Theo thể loại\").");
    SetColor(MAU_TRANG, MAU_DEN);
}

void MenuChinh(DanhSachDauSach &ds, CayDocGia &cay)
{
    int chon = 0; // muc dang duoc to sang tren thanh menu, giu lai khi quay ve tu mot chuc nang

    while (true)
    {
        VeManHinh(chon, "Tổng quan", "↑/↓: chọn chức năng    Enter: mở    Esc: thoát");
        VeTongQuan(ds, cay);

        // Di chuyen tren thanh menu cho toi khi nhan Enter hoac Esc
        VeMucMenu(chon, true, true);
        while (true)
        {
            int phim = DocPhim();
            int cu = chon;
            if (phim == PHIM_LEN)
                chon = (chon + SO_MUC_MENU - 1) % SO_MUC_MENU;
            else if (phim == PHIM_XUONG)
                chon = (chon + 1) % SO_MUC_MENU;
            if (chon != cu)
            {
                // chi ve lai muc vua roi di va muc vua toi
                VeMucMenu(cu, false, false);
                VeMucMenu(chon, true, true);
            }
            else if (phim == PHIM_ENTER)
                break;
            else if (phim == PHIM_ESC)
            {
                chon = SO_MUC_MENU - 1; // Esc o man hinh chinh coi nhu chon "Thoat"
                break;
            }
        }

        // Thu tu cac case phai khop thu tu ten muc trong VeMenuTrai (GiaoDien.cpp)
        switch (chon)
        {
        case 0: break; // Tong quan: chi ve lai
        case 1: ManHinhQuanLyDocGia(ds, cay); break;
        case 2: ManHinhInDanhSachDocGia(cay); break;
        case 3: ManHinhNhapSach(ds, cay); break;
        case 4: ManHinhInDauSachTheoTheLoai(ds); break;
        case 5: ManHinhTimSach(ds); break;
        case 6: ManHinhMuonSach(ds, cay); break;
        case 7: ManHinhTraSach(ds, cay); break;
        case 8: ManHinhSachDangMuon(ds, cay); break;
        case 9: ManHinhDocGiaQuaHan(ds, cay); break;
        case 10: ManHinhTop10Sach(ds, cay); break;
        default:
            if (XacNhan("Thoát chương trình?"))
                return;
            chon = 0;
            break;
        }
    }
}
