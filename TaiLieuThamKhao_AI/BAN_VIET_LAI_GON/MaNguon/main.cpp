#include "00_KhaiBaoChung.h"
#include <cstdlib>

int main()
{
    system("mode con: cols=120 lines=30"); // co dinh kich thuoc cua so console

    // Hai kho du lieu cua ca chuong trinh, truyen tham chieu cho cac ham, khong dung bien toan cuc.
    DanhSachDauSach *dsDauSach = new DanhSachDauSach; // mang 10000 con tro nen cap phat dong
    CayDocGia cayDocGia = nullptr;

    if (!DocFile(*dsDauSach, cayDocGia, FILE_DU_LIEU))
    {
        VeManHinh("LOI DOC FILE", "");
        ThongBao("File du lieu sai dinh dang. Chuong trinh bat dau voi thu vien rong.", true);
    }

    MenuChinh(*dsDauSach, cayDocGia);

    LuuFile(*dsDauSach, cayDocGia, FILE_DU_LIEU);
    HuyDanhSachDauSach(*dsDauSach);
    HuyCayDocGia(cayDocGia);
    delete dsDauSach;
    XoaManHinh();
    return 0;
}
