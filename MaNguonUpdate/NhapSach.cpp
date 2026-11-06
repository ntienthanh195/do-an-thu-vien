#include "00_KhaiBaoChung.h"

// [THAI] Phan code Thai cung cap o commit 5c03ecf; giu logic hien co.
bool HopLeTenSach(const string &s){
    if(s.empty() || s.size() > 150) return false;
    if(LaChuoiRong(s)) return false;
    bool CoKyTuHopLe = false;
    for(char c : s){
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
            CoKyTuHopLe = true;
        }
        else if(c == ' ' || c == ':' || c == '-' || c == ',' || c == '.' ||
                c == '(' || c == ')' || c == '\'' || c == '"'){}
        else return false;
    }
    return CoKyTuHopLe;
}

// [THAI] Chuyen tu be7fa70, chuc nang c.
bool HopLeDauSach(const DauSach &d, string &loi){
    // KIEM TRA ISBN
    string ch_ISBN = ChuanHoaISBN(d.ISBN);
    if(static_cast<int>(ch_ISBN.size()) != 13){
        loi = "ISBN chi bao gom 13 so!\n";
        return false;
    }
    for(char c : ch_ISBN){
        if(c < '0' || c > '9'){
            loi = "ISBN chi bao gom 13 so!\n";
            return false;
        }
    }
    // KIEM TRA SO TRANG
    if(d.soTrang < 1){
        loi = "So trang phai lon hon 0!\n";
        return false;
    }
    // NAM XUAT BAN
    if(d.namXuatBan <1 || d.namXuatBan > NAM_HIEN_TAI){
        loi = "Nam xuat ban phai la so duong va khong vuot qua nam hien tai!\n";
        return false;
    }
    // THE LOAI
    if(!HopLeVanBan(d.theLoai)){
        loi = "The loai khong hop le!\n";
        return false;
    }
    // KIEM TRA TAC GIA
    if(!HopLeVanBan(d.tacGia)){
        loi = "Ten tac gia khong hop le!\n";
        return false;
    }
    // KIEM TRA TEN SACH
    if(!HopLeVanBan(d.tenSach)){
        loi = "Ten sach khong hop le!\n";
        return false;
    }
    loi.clear();
    return true;
}

const DauSach *TimDauSachTheoISBN(const DanhSachDauSach &ds, const string &isbn){
    string isbn_chuanhoa = ChuanHoaISBN(isbn);
    if(isbn_chuanhoa.size() == 0) return nullptr;
    for(int i = 0; i < ds.soLuong; ++i){
        if(ds.ds[i] != nullptr && ds.ds[i]->ISBN == isbn_chuanhoa) return ds.ds[i];
    }
    return nullptr;
}

int TimViTriChenTheoTen(const DanhSachDauSach& ds, const DauSach& d) {
    int l = 0;
    int r = ds.soLuong;
    while (l < r) {
        int m = (l + r) / 2;
        // loi thu vien
        if (ds.ds[m] == nullptr) return -1;
        if (SoSanhChuoi(ds.ds[m]->tenSach, d.tenSach) < 0)
            l = m + 1;                      // ds[m] < d  -> chen SAU m
        else
            r = m;                          // ds[m] >= d -> chen TAI hoac TRUOC m
    }
    return l;
}

bool ThemDauSach(ThuVien &tv, const DauSach &d, string &loi){
    // that bai
    // KIEM TRA SO LUONG DAU SACH
    if(tv.dsDauSach.soLuong >= MAX_DAU_SACH){
        loi = "Danh sach dau sach da day!\n";
        return false;
    }
    // KIEM TRA CON TRO DMS CUA DAU SACH MOI
    else if (d.dms != nullptr) {
    loi = "Dau sach moi khong duoc co san danh muc cuon!\n";
    return false;
    }
    // KIEM TRA CAC LOI HOP LE DAU SACH
    else if(!HopLeDauSach(d, loi)) return false;
    // KIEM TRA TRUNG ISBN
    else if(TimDauSachTheoISBN(tv.dsDauSach, d.ISBN) != nullptr){
        loi = "ISBN da ton tai, khong the them trung!\n";
        return false;
    }
    int vitriChen = TimViTriChenTheoTen(tv.dsDauSach, d);
    // KIEM TRA CON TRO NULL O TRONG DANH SACH DAU SACH
    if(vitriChen == -1){
        loi = "Danh sach dau sach bi hong!\n";
        return false;
    }
    // thanh cong
    for(int i = tv.dsDauSach.soLuong; i > vitriChen; --i){
        tv.dsDauSach.ds[i] = tv.dsDauSach.ds[i-1];
    }
    // chuẩn hóa ISBN, TEN SACH, TAC GIA, THE LOAI O HAM ManHinhNhapDauSach
    tv.dsDauSach.ds[vitriChen] = new DauSach(d);
    ++tv.dsDauSach.soLuong;
    loi.clear();
    return true;
}
