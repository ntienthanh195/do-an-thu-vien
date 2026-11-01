/*c.Nhập thông tin đầu sách và đánh mã sách tự động sao cho tìm thông tin sách theo mã sách nhanh nhất.*/
// Step 1 – Xử lý chuỗi
// Hàm: LaChuoiRong, ChuanHoaChuoi, SoSanhChuoi
// Step 2 – Kiểm tra dữ liệu
// Hàm: HopLeVanBan, ChuanHoaISBN, HopLeDauSach















































#include "00_KhaiBaoChung.h"
// Giai đoạn 1 — Nhánh thêm đầu sách

// HopLeDauSach
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
bool HopLeDauSach(const DauSach &d, string &loi){
    // KIEM TRA ISBN 
    // quy uoc isbn ca thu vien la isbn-13
    string ch_ISBN = ChuanHoaChuoi(d.ISBN);
    if((int)ch_ISBN.size() != 13){
        loi = "ISBN phai co dung 13 ky tu so!\n";
        return false;
    }
    for(char c : ch_ISBN){
        if(c < '0' || c > '9'){
            loi = "ISBN chi duoc chua so!\n";
            return false;
        }
    }
    // KIEM TRA TAC GIA
    if(!HopLeVanBan(d.tacGia)){
        loi = "Tac gia khong hop le!\n";
        return false;
    }
    // KIEM TRA SO TRANG 
    if(d.soTrang <= 0){
        loi = "So trang phai lon hon 0!\n";
        return false;
    }
    // NAM XUAT BAN 
    if(d.namXuatBan <= 0 || d.namXuatBan > 2026){
        loi = "Nam xuat ban phai tu 1 den nam hien tai!\n";
        return false;
    }
    // THE LOAI 
    if(!HopLeVanBan(d.theLoai)){
        loi = "The loai khong hop le!\n";
        return false;
    }
    // KIEM TRA TEN SACH    
    if(!HopLeTenSach(d.tenSach)){
        loi = "Ten sach khong hop le!\n";
        return false;
    }
    loi.clear();
    return true;
}

// TimDauSachTheoISBN
const DauSach *TimDauSachTheoISBN(const DanhSachDauSach &ds, const string &isbn){
    string isbn_chuanhoa = ChuanHoaISBN(isbn);
    if(isbn_chuanhoa.size() == 0) return nullptr;
    for(int i = 0; i < ds.soLuong; ++i){
        if(ds.ds[i] != nullptr && ds.ds[i]->ISBN == isbn_chuanhoa) return ds.ds[i];
    }
    return nullptr;
}
// cach 2 nhanh hon : nhung phai biet co duoc luu mang khoa isbn o file khaibaochung.h khong

// TimViTriChenTheoTen
// Khong kiem tra trung ISBN ;o day caller (ThemDauSach) phai goi
// TimDauSachTheoISBN truoc de chan trung. (ISBN trung bao ham ca ISBN + TENSACH trung)
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

// ThemDauSach
bool ThemDauSach(ThuVien &tv, const DauSach &d, string &loi){
    // that bai
    if(tv.dsDauSach.soLuong >= MAX_DAU_SACH){
        loi = "Danh sach dau sach da day!\n";
        return false;
    }
    else if (d.dms != nullptr) {
    loi = "Dau sach moi khong duoc co san danh muc cuon!\n";
    return false;
    }
    else if(!HopLeDauSach(d, loi)) return false;
    else if(TimDauSachTheoISBN(tv.dsDauSach, d.ISBN) != nullptr){
        loi = "ISBN da ton tai, khong the them trung!\n";
        return false;
    }
    int vitriChen = TimViTriChenTheoTen(tv.dsDauSach, d);
    if(vitriChen == -1){
        loi = "Loi thu vien!\n";
        return false;
    }
    // thanh cong (chen dau sach vao vi tri thu i)
    for(int i = tv.dsDauSach.soLuong; i > vitriChen; --i){
        tv.dsDauSach.ds[i] = tv.dsDauSach.ds[i-1];
    }
    // co can chuan hoa dau / chu hoa / thuong cho ten sach , tac gia, the loai
    tv.dsDauSach.ds[vitriChen] = new DauSach(d);
    ++tv.dsDauSach.soLuong;
    loi.clear();
    return true;
}

// // HopLeCuonSach
bool HopLeCuonSach(const CuonSach &s, string &loi){
    // KIEM TRA MA SACH 
    string ch_maSach = ChuanHoaChuoi(s.maSach);
    if((int)s.maSach.size() < 15 || s.maSach[13] != '#'){
        loi = "Ma sach phai dung dinh dang ISBN#N!\n";
        return false;
    }
    for(int i = 0; s.maSach[i] != '#'; ++i){
        if(s.maSach[i] < '0' || s.maSach[i] > '9'){
            loi = "Ma sach phai dung dinh dang ISBN#N!\n";
            return false;
        }
    }
    for(int i = 14; i < s.maSach.size(); ++i){
        if(s.maSach[i] < '0' && s.maSach[i] > '9'){
            loi = "Ma sach phai dung dinh dang ISBN#N!\n";
            return false;
        }
    }
    // KIEM TRA TRANG THAI
    if(s.trangThai != SACH_CHO_MUON && s.trangThai != SACH_DANG_MUON && s.trangThai != SACH_THANH_LY){
        loi = "Tran thai sach khong hop le!\n";
        return false;
    }
    // KIEM TRA VI TRI 
    string ch_viTri = ChuanHoaChuoi(s.viTri);
    if(s.viTri.size() != 7){
        loi = "Do dai vi tri sach phai co dung 7 ky tu theo dinh dang Khu-Ke-Tang ( vi du : A-01-01 )!\n";
        return false;
    }
    for(int i = 0; i < s.viTri.size(); ++i){
        if(i == 0 && ((s.viTri[i] < 'A' && s.viTri[i] > 'Z') && (s.viTri[i] < 'a' && s.viTri[i] > 'z'))){
            loi = "Dinh dang vi tri sach Khu-Ke-Tang, trong do Khu [A...Z], Ke [01...99], Tang [01...99] \n";
            return false;
        }
    }
    loi.clear();
    return true;
}
