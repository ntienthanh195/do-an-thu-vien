#include "00_KhaiBaoChung.h"

/* ============================================================
   e. TIM THONG TIN SACH THEO TEN SACH
   In ISBN, ten sach, tac gia, nam xuat ban, the loai, cac ma sach va trang thai tung ma sach.
   Tim theo kieu "ten sach co chua tu khoa", khong phan biet hoa/thuong.
   ============================================================ */

// In thong tin mot dau sach va mot trang cac cuon sach cua no.
static void InKetQuaTimSach(const DauSach &d, int thuTu, int tongSo, int trang)
{
    XoaVung(0, 7, RONG_MH, 18);
    SetColor(MAU_NGOC_SANG, MAU_DEN);
    InTai(4, 7, "Ket qua " + SoThanhChuoi(thuTu + 1) + "/" + SoThanhChuoi(tongSo));
    SetColor(MAU_TRANG, MAU_DEN);
    InTai(4, 9, "ISBN         : " + d.ISBN);
    InTai(4, 10, "Ten sach     : " + d.tenSach);
    InTai(4, 11, "Tac gia      : " + d.tacGia);
    InTai(4, 12, "Nam xuat ban : " + SoThanhChuoi(d.namXuatBan));
    InTai(4, 13, "The loai     : " + d.theLoai);
    InTai(4, 14, "So trang     : " + SoThanhChuoi(d.soTrang));

    SetColor(MAU_VANG_SANG, MAU_DEN);
    InCot(60, 9, "MA SACH", 22);
    InCot(82, 9, "VI TRI", 10);
    InCot(92, 9, "TRANG THAI", 20);
    SetColor(MAU_TRANG, MAU_DEN);

    // bo qua cac cuon cua nhung trang truoc
    CuonSach *p = d.dms;
    for (int i = 0; i < trang * SO_DONG_TRANG && p != nullptr; ++i)
        p = p->next;

    int y = 10;
    while (p != nullptr && y < 10 + SO_DONG_TRANG)
    {
        if (p->trangThai == SACH_CHO_MUON)
            SetColor(MAU_XANH_LA_SANG, MAU_DEN);
        else if (p->trangThai == SACH_DANG_MUON)
            SetColor(MAU_VANG_SANG, MAU_DEN);
        else
            SetColor(MAU_XAM, MAU_DEN);
        InCot(60, y, p->maSach, 22);
        InCot(82, y, p->viTri, 10);
        InCot(92, y, TenTrangThaiSach(p->trangThai), 20);
        ++y;
        p = p->next;
    }
    SetColor(MAU_TRANG, MAU_DEN);
    if (d.dms == nullptr)
        InTai(60, 10, "(chua co cuon nao)");
    InSoTrang(trang, DemCuonSach(d.dms));
}

void ManHinhTimSach(const DanhSachDauSach &ds)
{
    int *viTri = new int[ds.soLuong + 1]; // mang tam: chi so cac dau sach khop tu khoa
    string tuKhoa = "";

    while (true)
    {
        VeManHinh("e. TIM SACH THEO TEN", "Enter: tim    Esc: quay lai");
        InTai(4, 5, "Ten sach can tim:");
        if (!NhapChuoi(22, 5, 40, false, tuKhoa))
            break;
        tuKhoa = ChuanHoaChuoiSach(tuKhoa);
        if (tuKhoa.size() == 0)
        {
            ThongBao("Tu khoa khong duoc rong.", true);
            continue;
        }

        int soKetQua = 0;
        for (int i = 0; i < ds.soLuong; ++i)
        {
            if (ChuaChuoi(ds.ds[i]->tenSach, tuKhoa))
                viTri[soKetQua++] = i;
        }
        if (soKetQua == 0)
        {
            ThongBao("Khong co dau sach nao co ten chua \"" + tuKhoa + "\".", true);
            continue;
        }

        SetColor(MAU_XAM, MAU_DEN);
        InCot(2, DONG_HUONG_DAN,
              "Len/Xuong: dau sach khac    Trai/Phai: trang ma sach    Esc: tim ten khac", 100);
        SetColor(MAU_TRANG, MAU_DEN);

        int chon = 0, trang = 0;
        while (true)
        {
            const DauSach &d = *ds.ds[viTri[chon]];
            InKetQuaTimSach(d, chon, soKetQua, trang);
            int phim = DocPhim();
            if (phim == PHIM_ESC)
                break;
            if (phim == PHIM_XUONG && chon + 1 < soKetQua)
            {
                ++chon;
                trang = 0;
            }
            else if (phim == PHIM_LEN && chon > 0)
            {
                --chon;
                trang = 0;
            }
            else
                XuLyPhimTrang(phim, trang, DemCuonSach(d.dms));
        }
    }
    delete[] viTri;
}
