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
    InTai(4, 7, "Kết quả " + SoThanhChuoi(thuTu + 1) + "/" + SoThanhChuoi(tongSo));
    SetColor(MAU_TRANG, MAU_DEN);
    InCot(4, 9, "ISBN         : " + d.ISBN, 45);
    InCot(4, 10, "Tên sách     : " + d.tenSach, 45);
    InCot(4, 11, "Tác giả      : " + d.tacGia, 45);
    InCot(4, 12, "Năm xuất bản : " + SoThanhChuoi(d.namXuatBan), 45);
    InCot(4, 13, "Thể loại     : " + d.theLoai, 45);
    InCot(4, 14, "Số trang     : " + SoThanhChuoi(d.soTrang), 45);

    SetColor(MAU_VANG_SANG, MAU_DEN);
    InCot(50, 9, "MÃ SÁCH", 18);
    InCot(68, 9, "VỊ TRÍ", 9);
    InCot(77, 9, "TRẠNG THÁI", 18);
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
        InCot(50, y, p->maSach, 18);
        InCot(68, y, p->viTri, 9);
        InCot(77, y, TenTrangThaiSach(p->trangThai), 18);
        ++y;
        p = p->next;
    }
    SetColor(MAU_TRANG, MAU_DEN);
    if (d.dms == nullptr)
        InTai(50, 10, "(chưa có cuốn nào)");
    InSoTrang(trang, DemCuonSach(d.dms));
}

void ManHinhTimSach(const DanhSachDauSach &ds)
{
    int *viTri = new int[ds.soLuong + 1]; // mang tam: chi so cac dau sach khop tu khoa
    string tuKhoa = "";

    while (true)
    {
        VeManHinh(5, "Tìm sách theo tên", "Enter: tìm    Esc: quay lại");
        InTai(4, 5, "Tên sách cần tìm:");
        if (!NhapChuoi(22, 5, 40, false, tuKhoa))
            break;
        tuKhoa = ChuanHoaChuoiSach(tuKhoa);
        if (tuKhoa.size() == 0)
        {
            ThongBao("Từ khóa không được rỗng.", true);
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
            ThongBao("Không có đầu sách nào có tên chứa \"" + tuKhoa + "\".", true);
            continue;
        }

        SetColor(MAU_XAM, MAU_DEN);
        InCot(2, DONG_HUONG_DAN,
              "↑/↓: đầu sách khác    ←/→: trang mã sách    Esc: tìm tên khác", RONG_MH - 4);
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
