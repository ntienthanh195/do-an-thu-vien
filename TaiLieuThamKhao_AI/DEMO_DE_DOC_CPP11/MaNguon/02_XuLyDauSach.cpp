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
void TimDauSachTheoTen(const ThuVien &tv, const string &ten, ostream &out){
    if(LaChuoiRong(ten)) return;
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

void ManHinhNhapDauSach(ThuVien &tv)
{
    const char *labels[] = {"Them dau sach moi", "Them cuon cho dau sach da co"};
    int choice = ChonMenu("NHAP SACH", labels, 2);
    if (choice < 1)
        return;
    string isbn, loi;
    if (DangDungGiaoDienHeThong())
    {
        if (choice == 1)
        {
            const char *fields[] = {"ISBN",    "Ten sach",     "So trang",
                                    "Tac gia", "Nam xuat ban", "The loai"};
            string values[6];
            values[4] = to_string(HomNay().nam);
            while (NhapBieuMau("THEM DAU SACH", fields, values, 6))
            {
                DauSach d;
                d.ISBN = values[0];
                d.tenSach = values[1];
                d.tacGia = values[3];
                d.theLoai = values[5];
                if (!DocSoNguyen(values[2], d.soTrang, 1, 2147483647))
                {
                    ThongBao("So trang phai la so nguyen duong.");
                    continue;
                }
                if (!DocSoNguyen(values[4], d.namXuatBan, 1, HomNay().nam))
                {
                    ThongBao("Nam xuat ban phai tu 1 den nam hien tai.");
                    continue;
                }
                if (!ThemDauSach(tv, d, loi))
                {
                    ThongBao("LOI: " + loi);
                    continue;
                }
                LuuSauThayDoi(tv);
                ThongBao("Da them dau sach " + ChuanHoaChuoi(d.ISBN) +
                         ". Chon Them cuon de nhap cac ban sach.");
                return;
            }
        }
        else
        {
            const char *fields[] = {"ISBN dau sach", "Vi tri cuon sach"};
            string values[2];
            while (NhapBieuMau("THEM CUON SACH", fields, values, 2))
            {
                string ma;
                if (!ThemCuonSach(tv, values[0], values[1], ma, loi))
                {
                    ThongBao("LOI: " + loi);
                    continue;
                }
                LuuSauThayDoi(tv);
                ThongBao("Da cap ma cuon: " + ma);
                return;
            }
        }
        return;
    }
    if (choice == 1)
    {
        DauSach d;
        if (!NhapDong("ISBN: ", d.ISBN) || !NhapDong("Ten sach: ", d.tenSach) ||
            !NhapSo("So trang: ", d.soTrang, 1, 2147483647) || !NhapDong("Tac gia: ", d.tacGia) ||
            !NhapSo("Nam xuat ban: ", d.namXuatBan, 1, HomNay().nam) ||
            !NhapDong("The loai: ", d.theLoai))
            return;
        if (!ThemDauSach(tv, d, loi))
        {
            ThongBao(loi);
            return;
        }
        LuuSauThayDoi(tv);
        isbn = ChuanHoaChuoi(d.ISBN);
        ThongBao("Da them dau sach. Nhap so cuon muon them; 0 de ket thuc.");
    }
    else
    {
        if (!NhapDong("ISBN dau sach: ", isbn))
            return;
        isbn = ChuanHoaChuoi(isbn);
        if (!TimDauSachTheoISBN(tv.dsDauSach, isbn))
        {
            ThongBao("Khong tim thay ISBN.");
            return;
        }
    }
    int n;
    if (!NhapSo("So cuon can them: ", n, 0, MAX_BAN_GHI))
        return;
    for (int i = 0; i < n; ++i)
    {
        string viTri, ma;
        if (!NhapDong("Vi tri cuon " + to_string(i + 1) + ": ", viTri))
        {
            ThongBao("Da dung nhap. Dau sach va nhung cuon da them duoc giu lai.");
            return;
        }
        if (!ThemCuonSach(tv, isbn, viTri, ma, loi))
        {
            ThongBao(loi);
            return;
        }
        LuuSauThayDoi(tv);
        ThongBao("Da cap ma cuon: " + ma);
    }
}
void ManHinhNhapDauSach(ThuVien &tv){
    
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
