/*c.Nhập thông tin đầu sách và đánh mã sách tự động 
sao cho tìm thông tin sách theo mã sách nhanh nhất.*/
#include "00_KhaiBaoChung.h"

bool HopLeVanBan_THAI(const string &s)
{   
    string t = ChuanHoaChuoi(s);
    if(t.empty()) return false;
    for(const char& c : t){
        if((c < 'a' || c > 'z') && (c < 'A' || c > 'Z')){
            if(c != ' ') return false;
        }
    }
    return true;
}

bool HopLeTenSach_THAI(const string &s){
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
// Giai đoạn 1 — Nhánh thêm đầu sách
bool HopLeDauSach(const DauSach &d, string &loi){
    // KIEM TRA ISBN
    if(d.ISBN.size() != 10 && d.ISBN.size() != 13){
        loi = "ISBN khong hop le!\n";
        return false;
    }
    for(const char& c : d.ISBN){
        if(c < '0' || c > '9'){
            loi = "ISBN khong hop le!\n";
            return false;
        }
    }
    // KIEM TRA TAC GIA
    if(!HopLeVanBan_THAI(d.tacGia)){
        loi = "Tac gia khong hop le!\n";
        return false;
    }
    // KIEM TRA SO TRANG 
    if(d.soTrang <= 0){
        loi = "So trang khong hop le!\n";
        return false;
    }
    // NAM XUAT BAN 
    if(d.namXuatBan <= 0 || d.namXuatBan > 2026){
        loi = "Nam xuat ban khong hop le!\n";
        return false;
    }
    // THE LOAI 
    if(!HopLeVanBan_THAI(d.theLoai)){
        loi = "The loai khong hop le!\n";
        return false;
    }
    // KIEM TRA TEN SACH    
    if(!HopLeTenSach_THAI(d.tenSach)){
        loi = "Ten sach khong hop le!\n";
        return false;
    }

    return true;
}
