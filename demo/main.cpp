#include "00_KhaiBaoChung.h"

// [DEMO - CODEX] main so huu thu vien va trang thai giao dien.
int main()
{
    ThuVien tv;
    string duongDan = "demo/DuLieu/DuLieuMau.txt";
    NgayThang ngay = HomNay();

    const MauGiaoDien mau = {0x0E,
                             0x07,
                             0x0A,
                             0x1E,
                             0x3E,
                             0x5E,
                             0x02,
                             0x60,
                             0x4E,
                             0x0004,
                             {RGB(17, 21, 28), RGB(25, 31, 40), RGB(52, 64, 80), RGB(37, 63, 59),
                              RGB(33, 48, 44), RGB(29, 37, 48), RGB(139, 207, 176),
                              RGB(168, 178, 192), RGB(104, 119, 139), RGB(232, 196, 135),
                              RGB(128, 201, 169), RGB(196, 205, 217), RGB(229, 155, 149),
                              RGB(176, 164, 201), RGB(225, 231, 239), RGB(242, 245, 249)}};
    const wchar_t *const dieuHuong[] = {
        L"Tong quan",      L"Quan ly doc gia", L"Danh sach doc gia", L"Kho sach",
        L"Theo the loai",  L"Tim kiem sach",   L"Muon sach",         L"Tra / bao mat",
        L"Sach dang muon", L"Doc gia qua han", L"Top 10 dau sach",   L"Mo du lieu",
        L"Luu du lieu",    L"Thoat phien"};
    const wchar_t *const moTa[] = {
        L"Theo doi thu vien va mo nhanh cac nghiep vu.",
        L"Them, hieu chinh, khoa hoac xoa the doc gia.",
        L"Xem theo ma the hoac theo ten va ho.",
        L"Quan ly dau sach va tung ban sach vat ly.",
        L"Duyet dau sach duoc nhom theo the loai.",
        L"Tim theo ten va xem trang thai tung cuon.",
        L"Kiem tra the, han muc va tinh trang cuon sach.",
        L"Nhan tra sach hoac ghi nhan mot cuon bi mat.",
        L"Tra cac cuon doc gia hien dang giu.",
        L"Xem doc gia da giu sach tu 7 ngay tro len.",
        L"Thong ke so luot muon theo tung dau sach.",
        L"Mo file khac sau khi xac nhan thay du lieu.",
        L"Ghi du lieu hien hanh vao file cua phien nay.",
        L"Thoat; du lieu da tu luu van duoc giu. Loi luu can xu ly truoc."};
    GiaoDien gd(tv, duongDan, ngay, mau, dieuHuong, moTa);
    return KhoiDongUngDung(gd, tv);
}
