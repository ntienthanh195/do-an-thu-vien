#include "00_KhaiBaoChung.h"

// Helper: Kiem tra nam nhuan
static bool LaNamNhuan(int nam) {
    return (nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0);
}

// Helper: Tra ve so ngay cua mot thang cu the
static int SoNgayTrongThang(int thang, int nam) {
    if (thang == 4 || thang == 6 || thang == 9 || thang == 11) {
        return 30;
    }
    if (thang == 2) {
        return LaNamNhuan(nam) ? 29 : 28;
    }
    return 31;
}

// Kiem tra tinh hop le cua mot ngay thang
bool NgayHopLe(const NgayThang &d) {
    if (d.nam <= 0) return false;
    if (d.thang < 1 || d.thang > 12) return false;
    if (d.ngay < 1 || d.ngay > SoNgayTrongThang(d.thang, d.nam)) return false;
    return true;
}

// Chuyen ngay thang thanh so thu tu (tinh tu 01/01/0001)
int SoThuTuNgay(const NgayThang &d) {
    int nam = d.nam - 1;
    // Tinh tong so ngay cua cac nam truoc do
    int ngay = nam * 365 + nam / 4 - nam / 100 + nam / 400;

    // Tinh tong so ngay cua cac thang truoc do trong nam hien tai
    for (int i = 1; i < d.thang; ++i) {
        ngay += SoNgayTrongThang(i, d.nam);
    }

    // Cong them ngay hien tai
    ngay += d.ngay;
    return ngay;
}

// Tinh khoang cach giua 2 ngay (b - a)
int KhoangCachNgay(const NgayThang &a, const NgayThang &b) {
    return SoThuTuNgay(b) - SoThuTuNgay(a);
}

// Kiem tra xem sach da qua han 7 ngay chua
bool QuaHan7Ngay(const NgayThang &ngayMuon, const NgayThang &now) {
    if (!NgayHopLe(ngayMuon) || !NgayHopLe(now)) {
        return false; // Ngay khong hop le thi coi nhu khong the xu ly qua han
    }
    int khoangCach = KhoangCachNgay(ngayMuon, now);
    return khoangCach > 7;
}
