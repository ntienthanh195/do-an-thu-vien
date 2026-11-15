#include "00_KhaiBaoChung.h"

// Dem tong so cuon sach cua ca thu vien de hien o man hinh chinh.
static int DemTatCaCuonSach(const DanhSachDauSach &ds)
{
    int tong = 0;
    for (int i = 0; i < ds.soLuong; ++i)
        tong += DemCuonSach(ds.ds[i]->dms);
    return tong;
}

void MenuChinh(DanhSachDauSach &ds, CayDocGia &cay)
{
    const int SO_MUC = 11;
    string muc[SO_MUC] = {
        "a. Quan ly the doc gia (them / xoa / hieu chinh)",
        "b. In danh sach doc gia",
        "c. Nhap dau sach, cuon sach",
        "d. In dau sach theo the loai",
        "e. Tim sach theo ten",
        "f. Muon sach",
        "g. Tra sach",
        "h. Sach dang muon cua mot doc gia",
        "i. Doc gia muon sach qua han",
        "j. 10 sach duoc muon nhieu nhat",
        "   Thoat chuong trinh"};

    while (true)
    {
        VeManHinh("MENU CHINH", "Len/Xuong: chon chuc nang    Enter: vao    Esc: thoat");
        VeKhung(30, 5, 60, SO_MUC + 4);
        SetColor(MAU_XAM, MAU_DEN);
        InTai(32, 21, "Dau sach: " + SoThanhChuoi(ds.soLuong) +
                          "     Cuon sach: " + SoThanhChuoi(DemTatCaCuonSach(ds)) +
                          "     Doc gia: " + SoThanhChuoi(DemDocGia(cay)));
        SetColor(MAU_TRANG, MAU_DEN);

        int chon = ChonMenu(33, 7, 54, muc, SO_MUC);
        if (chon == -1 || chon == SO_MUC - 1)
        {
            if (XacNhan("Thoat chuong trinh?"))
                return;
            continue;
        }

        switch (chon)
        {
        case 0: ManHinhQuanLyDocGia(ds, cay); break;
        case 1: ManHinhInDanhSachDocGia(cay); break;
        case 2: ManHinhNhapSach(ds, cay); break;
        case 3: ManHinhInDauSachTheoTheLoai(ds); break;
        case 4: ManHinhTimSach(ds); break;
        case 5: ManHinhMuonSach(ds, cay); break;
        case 6: ManHinhTraSach(ds, cay); break;
        case 7: ManHinhSachDangMuon(ds, cay); break;
        case 8: ManHinhDocGiaQuaHan(ds, cay); break;
        case 9: ManHinhTop10Sach(ds, cay); break;
        }
    }
}
