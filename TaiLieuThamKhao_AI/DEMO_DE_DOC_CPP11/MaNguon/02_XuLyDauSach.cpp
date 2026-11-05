#include "00_KhaiBaoChung.h"

// Khoa phu ISBN lam ket qua on dinh khi hai dau sach cung ten.
int SoSanhDauSach(const DauSach &a, const DauSach &b)
{
    int c = SoSanhChuoi(a.tenSach, b.tenSach);
    if (c != 0)
        return c;
    return a.ISBN < b.ISBN ? -1 : (a.ISBN > b.ISBN ? 1 : 0);
}
void InMotDauSach(const DauSach &d, ostream &out, bool chiTiet)
{
    out << "ISBN: " << d.ISBN << " | " << d.tenSach << " | " << d.tacGia << " | " << d.namXuatBan
        << " | " << d.soTrang << " trang | " << d.theLoai << '\n';
    if (!chiTiet)
        return;
    if (!d.dms)
        out << "  Chua co cuon sach.\n";
    for (const CuonSach *p = d.dms; p; p = p->next)
    {
        const char *tt = p->trangThai == SACH_CHO_MUON    ? "Cho muon"
                         : p->trangThai == SACH_DANG_MUON ? "Dang muon"
                                                          : "Da thanh ly";
        out << "  " << p->maSach << " | " << tt << " | Vi tri: " << p->viTri << '\n';
    }
}
// da sua 
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
// da sua
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
// da sua
const DauSach *TimDauSachTheoISBN(const DanhSachDauSach &ds, const string &isbn){
    string isbn_chuanhoa = ChuanHoaISBN(isbn);
    if(isbn_chuanhoa.size() == 0) return nullptr;
    for(int i = 0; i < ds.soLuong; ++i){
        if(ds.ds[i] != nullptr && ds.ds[i]->ISBN == isbn_chuanhoa) return ds.ds[i];
    }
    return nullptr;
}
// da sua
// TRUONG HOP TRUNG ISBN SE KIEM TRA TRUOC TRONG ThemDauSach ROI MOI GOI TimViTriChenTheoTen
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
// da sua
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
// da sua
void TimDauSachTheoTen(const ThuVien &tv, const string &ten, ostream &out){
    if(LaChuoiRong(ten)){
        out << "Tu khoa tim kiem khong duoc rong.\n";
        return;
    }
    string ch_ten = ChuanHoaChuoi(ten);

    for (int i = 0; i < 60; ++i) out << '=';
    out << "\n TIM KIEM SACH THEO TEN\n";
    for (int i = 0; i < 60; ++i) out << '=';
    out << "\n Tu khoa: " << ch_ten << "\n\n";

    bool timThay = false; // Chi dung de check co ket qua hay khong

    for(int i = 0; i < tv.dsDauSach.soLuong; ++i){
        const DauSach *d = tv.dsDauSach.ds[i];
        if(d != nullptr && ChuaChuoi(d->tenSach, ch_ten)){
            timThay = true;
            
            out << " [" << (i + 1) << "] Ten sach    : " << d->tenSach << '\n';
            out << "     Tac gia     : " << d->tacGia << '\n';
            out << "     The loai    : " << d->theLoai << '\n';
            out << "     Nam xuat ban: " << d->namXuatBan << '\n';
            out << "     ISBN        : " << d->ISBN << '\n';

            if(d->dms == nullptr){
                out << "     Cac cuon    : (chua co cuon nao)\n";
            }
            else{
                const CuonSach *p = d->dms;
                while(p != nullptr){
                    out << "       - " << p->maSach << "  |  ";
                    if(p->trangThai == SACH_CHO_MUON){
                        out << "Cho muon duoc\n";
                    }
                    else if(p->trangThai == SACH_DANG_MUON){
                        out << "Da co nguoi muon\n";
                    }
                    else if(p->trangThai == SACH_THANH_LY){
                        out << "Da thanh ly\n";
                    }
                    else{
                        out << "Trang thai khong xac dinh\n";
                    }
                    p = p->next;
                }
            }
            out << '\n';
        }
    }

    if(!timThay){
        out << " Khong tim thay dau sach nao khop voi tu khoa: " << ch_ten << '\n';
    }
    
    for (int i = 0; i < 60; ++i) out << '=';
    out << '\n';
}

void InDanhSachDauSach(const ThuVien &tv, ostream &out)
{
    if (tv.dsDauSach.soLuong == 0)
        out << "Danh sach dau sach rong.\n";
    for (int i = 0; i < tv.dsDauSach.soLuong; ++i)
        InMotDauSach(*tv.dsDauSach.ds[i], out, false);
}

void InDauSachTheoTheLoai(const ThuVien &tv, ostream &out)
{
    const DauSach **view = NULL;
    try
    {

        int n = tv.dsDauSach.soLuong;
        if (!n)
        {
            out << "Danh sach dau sach rong.\n";
            delete[] view;
            return;
        }
        // View muon con tro, khong so huu DauSach. Sap xen O(D^2), bo nho O(D).
        // Mang goc van tang theo ten sau khi ham ket thuc.
        view = new const DauSach *[n];
        for (int i = 0; i < n; ++i)
        {
            const DauSach *key = tv.dsDauSach.ds[i];
            int j = i;
            while (j > 0)
            {
                int c = SoSanhChuoi(view[j - 1]->theLoai, key->theLoai);
                if (c < 0 || (c == 0 && SoSanhDauSach(*view[j - 1], *key) <= 0))
                    break;
                view[j] = view[j - 1];
                --j;
            }
            view[j] = key;
        }
        for (int i = 0; i < n; ++i)
        {
            if (i == 0 || SoSanhChuoi(view[i - 1]->theLoai, view[i]->theLoai) != 0)
                out << "\nTHE LOAI: " << view[i]->theLoai << '\n';
            InMotDauSach(*view[i], out, false);
        }

        delete[] view;
    }
    catch (...)
    {
        delete[] view;
        throw; // Bao loi cho menu; mang tam da duoc giai phong.
    }
}

void HuyDanhSachDauSach(DanhSachDauSach &ds)
{
    for (int i = 0; i < ds.soLuong; ++i)
    {
        if (ds.ds[i])
            HuyDanhMucCuonSach(ds.ds[i]->dms);
        delete ds.ds[i];
        ds.ds[i] = nullptr;
    }
    ds.soLuong = 0;
}
// da sua
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

void ManHinhTimSach(const ThuVien &tv)
{
    string ten;
    if (!NhapDong("Ten/phan ten sach can tim: ", ten))
        return;
    LuongChuoi out;
    TimDauSachTheoTen(tv, ten, out);
    HienThiPhanTrang(out.str());
}
