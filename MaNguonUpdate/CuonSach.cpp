#include "00_KhaiBaoChung.h"

// [THAI] Phan code Thai cung cap o commit 5c03ecf; giu logic hien co.
bool HopLeCuonSach(const CuonSach &s, string &loi){
    // KIEM TRA MA SACH 
    string ch_maSach = ChuanHoaChuoiSach(s.maSach);
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
    string ch_viTri = ChuanHoaChuoiSach(s.viTri);
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

// [THAI] Chuyen tu be7fa70, chuc nang c.
const CuonSach *TimCuonSachTrongDauSach(const DauSach &d, const string &ma){
    if(LaChuoiRong(ma)) return nullptr;
    const CuonSach *p = d.dms;
    while(p != nullptr){
        if(p->maSach == ma) return p;
        p = p->next;
    }
    return nullptr;
}

const CuonSach *TimCuonSachToanCuc(const ThuVien &tv, const string &ma, const DauSach **owner){
    if(LaChuoiRong(ma)) return nullptr;
    // 1. Tach 13 so dau tien lam ISBN
    string ISBN_trong_Ma = "";
    for(const char c : ma){
        if(ISBN_trong_Ma.size() < 13){
            if(c >= '0' && c <= '9'){
                ISBN_trong_Ma += c;
            }
            else if(!KhoangTrang(c)){ // Neu gap ky tu la (gach ngang, #...)
                return nullptr;       // -> Sai quy uoc
            }
        }
    }
    if(ISBN_trong_Ma.size() < 13) return nullptr;
    // 2. Tim dau sach theo ISBN
    const string ch_ma = ChuanHoaChuoiSach(ma);
    for(int i = 0; i < tv.dsDauSach.soLuong; ++i){
        if(tv.dsDauSach.ds[i] == nullptr) continue; // Chong crash

        if(tv.dsDauSach.ds[i]->ISBN == ISBN_trong_Ma){
            // can biet ca dau sach chua cuon sach
            if(owner != nullptr){
                *owner = tv.dsDauSach.ds[i];
            }

            return TimCuonSachTrongDauSach(*(tv.dsDauSach.ds[i]), ch_ma);
        }
    }
    return nullptr;
}

bool SinhMaSachTuDong(const ThuVien &tv, const DauSach &d, string &ma, string &loi){
    ma = "";
    if(!HopLeDauSach(d, loi)) return false;
    const CuonSach *p = d.dms;
    // 1. Neu chua co cuon nao
    if(p == nullptr){
        ma = d.ISBN + "#1";
        return true;
    }
    // 2. Sach thanh ly/mat chi doi trang thai, khong xoa node.
    // => Node cuoi DSLK luon la cuon moi nhat (co ma N lon nhat).
    while(p->next != nullptr){
        p = p->next;
    }
    // 3. Tim dau '#' trong ma sach cu
    int viTriThang = -1;
    for(int i = 0; i < (int)p->maSach.size(); ++i){
        if(p->maSach[i] == '#'){
            viTriThang = i;
            break;
        }
    }
    if(viTriThang == -1){
        loi = "Loi: Ma sach cu thieu ky tu '#'.\n";
        return false;
    }
    // 4. Trich xuat chuoi so N va kiem tra tinh hop le
    string so_cu = "";
    for(int i = viTriThang + 1; i < (int)p->maSach.size(); ++i){
        char c = p->maSach[i];
        if(c >= '0' && c <= '9'){
            so_cu += c;
        }else{
            loi = "Loi: Ma sach cu chua ky tu khong hop le sau '#'.\n";
            return false;
        }
    }
    if(so_cu.empty()){
        loi = "Loi: Ma sach cu thieu phan so N.\n";
        return false;
    }
    // 5. Cong 1 vao chuoi so (thuat toan cong co nho)
    string so_moi = "";
    int co_nho = 1; // Ban dau cong 1
    for(int i = (int)so_cu.size() - 1; i >= 0; --i){
        int giatri = (so_cu[i] - '0') + co_nho;
        if(giatri >= 10){
            giatri -= 10;
            co_nho = 1;
        }
        else{
            co_nho = 0;
        }
        so_moi += (char)(giatri + '0');
    }
    if(co_nho == 1){
        so_moi += '1'; // Truong hop 9 + 1 = 10
    }

    // 6. Ghep ma sach moi (nho dao nguoc chuoi so_moi)
    ma = d.ISBN + "#";
    for(int i = (int)so_moi.size() - 1; i >= 0; --i){
        ma += so_moi[i];
    }
    return true;
}

// [THAI] Chuyen tu be7fa70, chuc nang j.
// B2 : THAO TAC DANH MUC SACH
// Dem so cuon sach trong danh sach lien ket don.
// Khong thay doi con tro next cua bat ky node nao.
int DemCuonSach(const CuonSach *head) {
    int dem = 0;
    const CuonSach *p = head;
    while (p != nullptr) {
        ++dem;
        p = p->next;
    }
    return dem;
}
