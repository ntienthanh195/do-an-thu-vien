#include "00_KhaiBaoChung.h"

bool KhoangTrang(unsigned char c){
    return c == ' ' || c == '\t' || c == '\r' || c == '\n';
}

bool LaChuoiRong(const string &s){
    for(const char c : s){
        if(!KhoangTrang(c)) return false;
    }
    return true;
}

string ChuanHoaChuoi(const string &s){
    string kq = "";
    bool gap = false; // gap ky tu khac khoang trang
    for(const char c : s){
        if(!KhoangTrang(c)){
            if(gap == false){
                gap = true;
            }
            kq += c;

        }
        else{
            if(gap == true){
                gap = false;
                kq += ' ';
            }
        }
    }
    // truong hop dac biet : "hello world "
    if(kq.size() != 0 && kq[kq.size()-1] == ' '){
        kq.pop_back();
    }
    return kq;
}

int SoSanhChuoi(const string &a, const string &b){
    // a < b : -1, a > b : 1; a = b : 0
    string x = ChuanHoaChuoi(a);
    string y = ChuanHoaChuoi(b);
    if (x.empty() && y.empty()) return 0;
    if (x.empty()) return -1;
    if (y.empty()) return 1;
    for (int i = 0; i < (int)x.size() && i < (int)y.size(); ++i){
        char x1 = x[i], y1 = y[i];
        if (x1 >= 'A' && x1 <= 'Z') x1 = (char)(x1 + 32);
        if (y1 >= 'A' && y1 <= 'Z') y1 = (char)(y1 + 32);
        if (x1 < y1) return -1;
        if (x1 > y1) return 1;
    }
    return x.size() < y.size() ? -1 : (x.size() > y.size() ? 1 : 0);
}

bool HopLeVanBan(const string &s)
{   
    const size_t MAX_VAN_BAN = 100;
    if(s.size() > MAX_VAN_BAN){
        return false;
    }
    if(LaChuoiRong(s)) return false;
    for(const unsigned char c : s){
        if (c == '|')  return false;   // delimiter file
        else if (c == '\\') return false;   // escape char
        else if (c < 32)    return false;   // control char (tab, newline...)
        else if (c == 127)  return false;   // DEL
        else if (c >= 128)  return false;   // khong phai ASCII in duoc
    }
    return true;
}

string ChuanHoaISBN(const string &isbn){
    string res = "";
    for(char c : isbn){
        // ISBN0-13 thuong co dang vi du : 978-3-16-148410-0 hoac 978 3 16 148410 0
        if( c != '-' && !KhoangTrang(c)){
            res += c;
        }
    }
    return res;
}

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

const CuonSach *TimCuonSachTrongDauSach(const DauSach &d, const string &ma){
    if(LaChuoiRong(ma)) return nullptr;
    const CuonSach *p = d.dms;
    while(p != nullptr){
        if(p->maSach == ma) return p;
        p = p->next;
    }
    return nullptr;
}

bool SinhMaSachTuDong(const ThuVien &tv, const DauSach &d, string &ma, string &loi) {
    // Buoc 1: Xac thuc dau sach hop le va da ton tai trong thu vien truoc khi cap ma
    if (!HopLeDauSach(d, loi)) return false;
    if (TimDauSachTheoISBN(tv.dsDauSach, d.ISBN) == nullptr) {
        loi = "Dau sach chua ton tai trong thu vien!";
        return false;
    }

    // Buoc 2: Chuan hoa ten sach & ISBN; chan dau '#' trong ten de bao toan dinh dang tenSach#ISBN#N
    string tenChuan = ChuanHoaChuoi(d.tenSach);
    for (int i = 0; i < (int)tenChuan.size(); ++i) {
        if (tenChuan[i] == '#') {
            loi = "Ten sach khong duoc chua ky tu '#'!";
            return false;
        }
    }
    string isbnChuan = ChuanHoaISBN(d.ISBN);

    // Buoc 3: Duyet dms tim chi so N lon nhat (khong dung dem node vi node co the bi xoa)
    int maxN = 0;
    int demNode = 0;
    const CuonSach *p = d.dms;
    while (p != nullptr) {
        // Chan vong lap vo han neu danh sach lien ket bi hong con tro
        if (++demNode > MAX_BAN_GHI) {
            loi = "Danh muc cuon sach bi hong hoac vuot gioi han!";
            return false;
        }

        // Quet nguoc tu cuoi chuoi maSach de tim vi tri dau '#' cuoi cung
        int posHash = -1;
        for (int i = (int)p->maSach.size() - 1; i >= 0; --i) {
            if (p->maSach[i] == '#') {
                posHash = i;
                break;
            }
        }

        // Ep kieu thu cong chuoi chu so sau dau '#' cuoi cung sang so nguyen
        if (posHash != -1 && posHash + 1 < (int)p->maSach.size()) {
            int val = 0;
            bool hopLeSo = true;
            for (int i = posHash + 1; i < (int)p->maSach.size(); ++i) {
                char c = p->maSach[i];
                if (c < '0' || c > '9') {
                    hopLeSo = false;
                    break;
                }
                int digit = c - '0';
                // Kiem tra tran so nguyen 32-bit
                if (val > (SO_NGUYEN_LON_NHAT - digit) / 10) {
                    hopLeSo = false;
                    break;
                }
                val = val * 10 + digit;
            }
            if (hopLeSo && val > maxN) maxN = val;
        }
        p = p->next;
    }

    // Buoc 4: Sinh chi so N ke tiep va chuyen sang chuoi thu cong (khong dung to_string)
    if (maxN >= SO_NGUYEN_LON_NHAT) {
        loi = "Da dat gioi han so luong ma sach toi da!";
        return false;
    }
    int nextN = maxN + 1;
    string chuoiN = "";
    int temp = nextN;
    while (temp > 0) {
        char digitChar = (char)('0' + (temp % 10));
        chuoiN = digitChar + chuoiN;
        temp /= 10;
    }

    // Buoc 5: Ghep chuoi dinh danh hoan chinh va doi chieu chong trung lan cuoi
    ma = tenChuan + "#" + isbnChuan + "#" + chuoiN;
    if (TimCuonSachTrongDauSach(d, ma) != nullptr) {
        loi = "Ma sach sinh ra bi trung lap!";
        return false;
    }

    loi.clear();
    return true;
}

const CuonSach *TimCuonSachToanCuc(const ThuVien &tv, const string &ma, const DauSach **owner) {
    // Buoc 1: Khoi tao an toan con tro owner va kiem tra dieu kien bien dau vao
    if (owner != nullptr) *owner = nullptr;
    string maChuan = ChuanHoaChuoi(ma);
    if (maChuan.empty() || tv.dsDauSach.soLuong <= 0) return nullptr;

    // Buoc 2: Quet nguoc tu cuoi chuoi maSach de tim 2 dau '#' phan tach (tenSach#ISBN#N)
    int hash2 = -1, hash1 = -1;
    for (int i = (int)maChuan.size() - 1; i >= 0; --i) {
        if (maChuan[i] == '#') {
            if (hash2 == -1) hash2 = i;
            else {
                hash1 = i;
                break;
            }
        }
    }

    // Chan ma sai dinh dang (khong du 2 dau '#' hoac bi khuyet tenSach / ISBN / N)
    if (hash1 <= 0 || hash2 <= hash1 + 1 || hash2 + 1 >= (int)maChuan.size()) {
        return nullptr;
    }

    // Buoc 3: Tach thu cong tenSach, ISBN (loai bo '-' va khoang trang) va kiem tra phan so N
    string tenTach = "";
    for (int i = 0; i < hash1; ++i) tenTach += maChuan[i];

    string isbnTach = "";
    for (int i = hash1 + 1; i < hash2; ++i) {
        char c = maChuan[i];
        if (c != '-' && !KhoangTrang((unsigned char)c)) isbnTach += c;
    }
    if ((int)isbnTach.size() != 13) return nullptr;

    for (int i = hash2 + 1; i < (int)maChuan.size(); ++i) {
        if (maChuan[i] < '0' || maChuan[i] > '9') return nullptr;
    }

    // Buoc 4: Binary Search tren mang con tro dau sach da sap xep tang dan theo tenSach
    int l = 0, r = tv.dsDauSach.soLuong - 1, midTimThay = -1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (tv.dsDauSach.ds[m] == nullptr) return nullptr;
        int cmp = SoSanhChuoi(tv.dsDauSach.ds[m]->tenSach, tenTach);
        if (cmp == 0) {
            midTimThay = m;
            break;
        }
        if (cmp < 0) l = m + 1;
        else r = m - 1;
    }
    if (midTimThay == -1) return nullptr;

    // Buoc 5: Quet lan can sang trai (gom ca midTimThay) va sang phai trong nhom trung tenSach
    for (int i = midTimThay; i >= 0; --i) {
        const DauSach *dsHienTai = tv.dsDauSach.ds[i];
        if (dsHienTai == nullptr || SoSanhChuoi(dsHienTai->tenSach, tenTach) != 0) break;
        if (dsHienTai->ISBN == isbnTach) {
            const CuonSach *cs = TimCuonSachTrongDauSach(*dsHienTai, maChuan);
            if (cs != nullptr) {
                if (owner != nullptr) *owner = dsHienTai;
                return cs;
            }
        }
    }
    for (int i = midTimThay + 1; i < tv.dsDauSach.soLuong; ++i) {
        const DauSach *dsHienTai = tv.dsDauSach.ds[i];
        if (dsHienTai == nullptr || SoSanhChuoi(dsHienTai->tenSach, tenTach) != 0) break;
        if (dsHienTai->ISBN == isbnTach) {
            const CuonSach *cs = TimCuonSachTrongDauSach(*dsHienTai, maChuan);
            if (cs != nullptr) {
                if (owner != nullptr) *owner = dsHienTai;
                return cs;
            }
        }
    }

    return nullptr;
}

void ManHinhNhapDauSach(ThuVien &tv) {
    // Buoc 1: Chan som neu mang con tro dau sach da dat suc chua toi da
    if (tv.dsDauSach.soLuong >= MAX_DAU_SACH) {
        ThongBao("Danh sach dau sach da day, khong the them moi!");
        return;
    }

    const char *nhanBieuMau[6] = {
        "ISBN (13 chu so)",
        "Ten sach",
        "So trang",
        "Tac gia",
        "Nam xuat ban",
        "The loai"
    };
    string giaTri[6];
    DauSach d;
    bool laDauSachMoi = true;

    // Buoc 2: Vong lap nhap va xac thuc thong tin dau sach (giu lai giaTri khi sai de sua nhanh)
    while (true) {
        if (!NhapBieuMau("NHAP THONG TIN DAU SACH", nhanBieuMau, giaTri, 6)) {
            return; // Nguoi dung huy thao tac (Esc hoac /huy)
        }

        // Chuan hoa du lieu chuoi truoc khi kiem tra va luu tru
        d = DauSach();
        d.ISBN = ChuanHoaISBN(giaTri[0]);
        d.tenSach = ChuanHoaChuoi(giaTri[1]);
        d.tacGia = ChuanHoaChuoi(giaTri[3]);
        d.theLoai = ChuanHoaChuoi(giaTri[5]);

        // Chan ky tu '#' trong ten sach de tranh pha vo cau truc maSach = tenSach#ISBN#N
        bool chuaDauThang = false;
        for (int i = 0; i < (int)d.tenSach.size(); ++i) {
            if (d.tenSach[i] == '#') {
                chuaDauThang = true;
                break;
            }
        }
        if (chuaDauThang) {
            ThongBao("Ten sach khong duoc chua ky tu '#'!");
            continue;
        }

        // Ep kieu thu cong cac truong so nguyen bang helper cua Module 01
        if (!DocSoNguyen(ChuanHoaChuoi(giaTri[2]), d.soTrang, 1, SO_NGUYEN_LON_NHAT)) {
            ThongBao("So trang phai la so nguyen lon hon 0!");
            continue;
        }
        if (!DocSoNguyen(ChuanHoaChuoi(giaTri[4]), d.namXuatBan, 1, NAM_HIEN_TAI)) {
            ThongBao("Nam xuat ban khong hop le!");
            continue;
        }

        string loi;
        if (!HopLeDauSach(d, loi)) {
            ThongBao(loi);
            continue;
        }

        // Xu ly tinh huong trung ISBN: cho phep nhap them ban sao hoac sua lai bieu mau
        const DauSach *daCo = TimDauSachTheoISBN(tv.dsDauSach, d.ISBN);
        if (daCo != nullptr) {
            const char *tuyChon[2] = {
                "Nhap them ban sao cho dau sach da co",
                "Quay lai sua thong tin bieu mau"
            };
            int chon = ChonMenu("ISBN DA TON TAI: " + daCo->tenSach, tuyChon, 2);
            if (chon == 0) {
                laDauSachMoi = false;
                break;
            }
            continue;
        }

        // Chen dau sach moi vao mang con tro theo dung thu tu tang dan ten sach
        if (!ThemDauSach(tv, d, loi)) {
            ThongBao(loi);
            continue;
        }
        break;
    }

    // Buoc 3: Nhap so luong ban sao vat ly va tu dong sinh maSach = tenSach#ISBN#N
    int soCuonNhap = 0;
    if (!NhapSo("Nhap so luong cuon sach nhap kho (0 de bo qua): ", soCuonNhap, 0, 1000)) {
        if (laDauSachMoi) ThongBao("Da luu dau sach moi (chua nhap ban sao).");
        return;
    }
    if (soCuonNhap == 0) {
        if (laDauSachMoi) ThongBao("Da luu dau sach moi (0 ban sao).");
        return;
    }

    int daThem = 0;
    string tomTatMa = "";
    for (int k = 1; k <= soCuonNhap; ++k) {
        // Tao chuoi nhac nhap thu cong (khong dung to_string)
        string soThuTu = "";
        int tmp = k;
        while (tmp > 0) {
            soThuTu = (char)('0' + (tmp % 10)) + soThuTu;
            tmp /= 10;
        }

        while (true) {
            string viTri;
            if (!NhapDong("Vi tri cuon #" + soThuTu + " (VD: A-03-02, /huy de dung): ", viTri)) {
                k = soCuonNhap + 1; // Thoat ca vong lap ngoai
                break;
            }
            string maMoi, loiCuon;
            if (ThemCuonSach(tv, d.ISBN, ChuanHoaChuoi(viTri), maMoi, loiCuon)) {
                ++daThem;
                if (daThem <= 8) {
                    if (!tomTatMa.empty()) tomTatMa += " | ";
                    tomTatMa += maMoi;
                } else if (daThem == 9) {
                    tomTatMa += " | ...";
                }
                break;
            }
            ThongBao(loiCuon);
        }
    }

    // Buoc 4: Tong ket ket qua thao tac cho thu thu
    if (daThem > 0) {
        ThongBao("Hoan tat! Ma sach da cap: " + tomTatMa);
    } else if (laDauSachMoi) {
        ThongBao("Da luu dau sach moi, chua them duoc ban sao nao.");
    }
}
