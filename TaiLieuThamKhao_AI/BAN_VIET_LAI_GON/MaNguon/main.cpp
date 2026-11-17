#include "0.0_KhaiBaoChung.h"
#include <cstdlib>

int main()
{
    KhoiTaoManHinh(); // kich thuoc cua so, bang ma UTF-8, che do mau

    // Hai kho du lieu cua ca chuong trinh, truyen tham chieu cho cac ham, khong dung bien toan cuc.
    DanhSachDauSach *dsDauSach = new DanhSachDauSach; // mang 10000 con tro nen cap phat dong
    CayDocGia cayDocGia = nullptr;

    if (!DocFile(*dsDauSach, cayDocGia, FILE_DU_LIEU))
    {
        VeManHinh(0, "Lỗi đọc file", "");
        ThongBao("File hỏng: chép ThuVien_BanTruoc.txt đè lên ThuVien.txt rồi mở lại.", true);
        // Dung tai day va KHONG luu: neu chay tiep voi thu vien rong thi lan luu
        // dau tien se ghi de, lam mat luon phan du lieu con cuu duoc trong file.
        delete dsDauSach;
        XoaManHinh();
        return 1;
    }
    // Doc duoc file thi ghi mot ban sao, de khi file chinh hong con ban nay thay the.
    // Thu vien rong (chua co file, hoac chay nham thu muc) thi khong ghi,
    // de khong de mot ban sao rong len ban sao dang co du lieu.
    if (dsDauSach->soLuong > 0 || cayDocGia != nullptr)
        LuuFile(*dsDauSach, cayDocGia, FILE_SAO_LUU);

    MenuChinh(*dsDauSach, cayDocGia);

    LuuFile(*dsDauSach, cayDocGia, FILE_DU_LIEU);
    HuyDanhSachDauSach(*dsDauSach);
    HuyCayDocGia(cayDocGia);
    delete dsDauSach;
    XoaManHinh();
    HienConTro(true); // tra lai con tro cho cua so console
    return 0;
}
