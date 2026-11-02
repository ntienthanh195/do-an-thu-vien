/*c.Nhập thông tin đầu sách và đánh mã sách tự động sao cho tìm thông tin sách theo mã sách nhanh nhất.*/
// Step 1 – Xử lý chuỗi
// Hàm: LaChuoiRong, ChuanHoaChuoi, SoSanhChuoi
// Step 2 – Kiểm tra dữ liệu
// Hàm: HopLeVanBan, ChuanHoaISBN, HopLeDauSach, ChuaChuoi , void TimDauSachTheoTen






/*e. Tìm thông tin sách dựa vào tên sách : in ra các thông tin mã ISBN, tên sách, tác giả, năm xuất bản, thể loại, các mã sách , trạng thái mã sách trong thư viện.*/
// SoSanhChuoi -> TimDauSachTheoTen







































#include "00_KhaiBaoChung.h"

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
