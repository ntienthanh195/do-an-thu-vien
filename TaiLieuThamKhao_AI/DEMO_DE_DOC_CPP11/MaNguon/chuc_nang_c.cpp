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
    const string ch_ma = ChuanHoaChuoi(ma);
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
// Cac ham helper giao dien
static void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
static void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
// Helper: Nhap chuoi voi giao dien, tu dong bat ESC va Backspace
static bool NhapChuoiUI(int x, int y, string &out, bool laISBN) {
    out = "";
    gotoxy(x, y);
    setColor(15); // Mau trang
    
    while (true) {
        int c = _getch();
        
        if (c == 27) { // Phim ESC
            return false;
        }
        if (c == 13) { // Phim Enter
            return true;
        }
        if (c == 8) { // Phim Backspace
            if (out.size() > 0) {
                out.erase(out.size() - 1); // Xoa ky tu cuoi
                std::cout << "\b \b";      // Xoa tren man hinh
            }
        } 
        else if (c >= 32 && c <= 126) {
            // Chi cho phep nhap ky tu in duoc (ASCII)
            out += (char)c;
            std::cout << (char)c;
        }
    }
}
// ham ho tro ManHinhNhapDauSach : gotoxy, setColor, NhapChuoiUI
void ManHinhNhapDauSach(ThuVien &tv) {
    while (true) {
        system("cls"); // Xoa man hinh cho sach
        setColor(11);  // Mau xanh lam (Cyan)
        std::cout << "======================================================\n";
        std::cout << "               THEM DAU SACH MOI                      \n";
        std::cout << "     (Nhan phim ESC bat ky luc nao de quay lai)       \n";
        std::cout << "======================================================\n\n";
        setColor(15); // Mau trang

        string isbn, tenSach, tacGia, theLoai;
        int soTrang = 0, namXuatBan = 0;

        // --- 1. NHAP ISBN ---
        while (true) {
            gotoxy(0, 6); std::cout << "Nhap ISBN (13 chu so):          "; 
            if (!NhapChuoiUI(23, 6, isbn, true)) return;
            
            isbn = ChuanHoaISBN(isbn);
            gotoxy(0, 7); std::cout << "                                                  "; // Xoa dong loi cu
            
            bool hopLe = true;
            if (isbn.size() != 13) hopLe = false;
            else {
                for (int i = 0; i < 13; ++i) {
                    if (isbn[i] < '0' || isbn[i] > '9') { hopLe = false; break; }
                }
            }
            
            if (!hopLe) {
                setColor(12); // Do
                gotoxy(0, 7); std::cout << "Loi: ISBN phai gom dung 13 chu so (0-9).";
                continue;
            }
            if (TimDauSachTheoISBN(tv.dsDauSach, isbn) != nullptr) {
                setColor(12);
                gotoxy(0, 7); std::cout << "Loi: ISBN nay da ton tai. Vui long nhap lai.";
                continue;
            }
            setColor(15);
            break;
        }

        // --- 2. NHAP TEN SACH ---
        while (true) {
            gotoxy(0, 9); std::cout << "Nhap ten sach:                  "; 
            if (!NhapChuoiUI(16, 9, tenSach, false)) return;
            
            tenSach = ChuanHoaChuoi(tenSach);
            gotoxy(0, 10); std::cout << "                                                  ";
            
            if (tenSach.empty()) {
                setColor(12);
                gotoxy(0, 10); std::cout << "Loi: Ten sach khong duoc de trong.";
                continue;
            }
            if (!HopLeVanBan(tenSach)) {
                setColor(12);
                gotoxy(0, 10); std::cout << "Loi: Ten sach chua ky tu khong hop le (co dau).";
                continue;
            }
            setColor(15);
            break;
        }

        // --- 3. NHAP SO TRANG (Nhap chuoi de kiem tra thay vi cin >>) ---
        while (true) {
            string sTrang;
            gotoxy(0, 12); std::cout << "Nhap so trang:                  ";
            if (!NhapChuoiUI(16, 12, sTrang, false)) return;
            
            gotoxy(0, 13); std::cout << "                                                  ";
            if (sTrang.empty()) {
                setColor(12); gotoxy(0, 13); std::cout << "Loi: So trang khong duoc de trong.";
                continue;
            }
            // Tu viet logic chuyen chuoi sang so
            bool hopLe = true;
            for (int i = 0; i < (int)sTrang.size(); ++i) {
                if (sTrang[i] < '0' || sTrang[i] > '9') { hopLe = false; break; }
            }
            if (!hopLe) {
                setColor(12); gotoxy(0, 13); std::cout << "Loi: So trang phai la chu so.";
                continue;
            }
            soTrang = 0;
            for (int i = 0; i < (int)sTrang.size(); ++i) {
                soTrang = soTrang * 10 + (sTrang[i] - '0');
            }
            if (soTrang < 1 || soTrang > 100000) {
                setColor(12); gotoxy(0, 13); std::cout << "Loi: So trang phai tu 1 den 100000.";
                continue;
            }
            setColor(15);
            break;
        }

        // --- 4. NHAP TAC GIA ---
        while (true) {
            gotoxy(0, 15); std::cout << "Nhap ten tac gia:               ";
            if (!NhapChuoiUI(18, 15, tacGia, false)) return;
            
            tacGia = ChuanHoaChuoi(tacGia);
            gotoxy(0, 16); std::cout << "                                                  ";
            
            if (tacGia.empty()) {
                setColor(12); gotoxy(0, 16); std::cout << "Loi: Tac gia khong duoc de trong.";
                continue;
            }
            if (!HopLeVanBan(tacGia)) {
                setColor(12); gotoxy(0, 16); std::cout << "Loi: Tac gia chua ky tu khong hop le (co dau).";
                continue;
            }
            setColor(15);
            break;
        }

        // --- 5. NHAP NAM XUAT BAN ---
        while (true) {
            string sNam;
            gotoxy(0, 18); std::cout << "Nhap nam xuat ban:              ";
            if (!NhapChuoiUI(19, 18, sNam, false)) return;
            
            gotoxy(0, 19); std::cout << "                                                  ";
            if (sNam.empty()) {
                setColor(12); gotoxy(0, 19); std::cout << "Loi: Nam XB khong duoc de trong.";
                continue;
            }
            bool hopLe = true;
            for (int i = 0; i < (int)sNam.size(); ++i) {
                if (sNam[i] < '0' || sNam[i] > '9') { hopLe = false; break; }
            }
            if (!hopLe) {
                setColor(12); gotoxy(0, 19); std::cout << "Loi: Nam XB phai la chu so.";
                continue;
            }
            namXuatBan = 0;
            for (int i = 0; i < (int)sNam.size(); ++i) {
                namXuatBan = namXuatBan * 10 + (sNam[i] - '0');
            }
            if (namXuatBan < 1 || namXuatBan > 2100) {
                setColor(12); gotoxy(0, 19); std::cout << "Loi: Nam XB phai tu 1 den 2100.";
                continue;
            }
            setColor(15);
            break;
        }

        // --- 6. NHAP THE LOAI ---
        while (true) {
            gotoxy(0, 21); std::cout << "Nhap the loai:                  ";
            if (!NhapChuoiUI(16, 21, theLoai, false)) return;
            
            theLoai = ChuanHoaChuoi(theLoai);
            gotoxy(0, 22); std::cout << "                                                  ";
            
            if (theLoai.empty()) {
                setColor(12); gotoxy(0, 22); std::cout << "Loi: The loai khong duoc de trong.";
                continue;
            }
            if (!HopLeVanBan(theLoai)) {
                setColor(12); gotoxy(0, 22); std::cout << "Loi: The loai chua ky tu khong hop le (co dau).";
                continue;
            }
            setColor(15);
            break;
        }

        // --- THUC HIEN THEM ---
        DauSach d;
        d.ISBN = isbn;
        d.tenSach = tenSach;
        d.soTrang = soTrang;
        d.tacGia = tacGia;
        d.namXuatBan = namXuatBan;
        d.theLoai = theLoai;

        string loi;
        gotoxy(0, 24);
        if (ThemDauSach(tv, d, loi)) {
            setColor(10); // Xanh la
            std::cout << "=> Them dau sach thanh cong!";
        } else {
            setColor(12);
            std::cout << "=> Them that bai: " << loi;
        }

        // Hoi nhap tiep
        setColor(15);
        gotoxy(0, 26); std::cout << "Nhan phim bat ky de nhap tiep (hoac ESC de thoat)...";
        int c = _getch();
        if (c == 27) return; // Thoat neu bam ESC
    }
}    


