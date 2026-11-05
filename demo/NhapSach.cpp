#include "00_KhaiBaoChung.h"

// [THAI] Phan code Thai cung cap o commit 5c03ecf; cac dieu chinh demo co nhan ben duoi.
bool HopLeTenSach(const string &s){
    // [DEMO - CODEX] Ho tro ten tieng Viet va C++ trong du lieu mau.
    if(!KiemTraVanBanHeThong(s) || s.size() > 150) return false;
    if(LaChuoiRong(s)) return false;
    bool CoKyTuHopLe = false;
    for(char c : s){
        if(static_cast<unsigned char>(c) >= 128 || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
            CoKyTuHopLe = true;
        }      
        else if(c == '+' || c == ' ' || c == ':' || c == '-' || c == ',' || c == '.' ||
                c == '(' || c == ')' || c == '\'' || c == '"'){}
        else return false;
    }
    return CoKyTuHopLe;
}

bool HopLeDauSach(const DauSach &d, string &loi){
    // KIEM TRA ISBN 
    // quy uoc isbn ca thu vien la isbn-13
    string ch_ISBN = ChuanHoaChuoiSach(d.ISBN);
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
    if(!LaNamHopLe(d.namXuatBan)){
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

// [DEMO - CODEX] Dieu chinh tu ham cua Thai de ghep voi du lieu demo.
const DauSach *TimDauSachTheoISBN(const DanhSachDauSach &ds, const string &isbn){
    string isbn_chuanhoa = ChuanHoaChuoiSach(isbn);
    if(isbn_chuanhoa.size() == 0) return nullptr;
    for(int i = 0; i < ds.soLuong; ++i){
        if(ds.ds[i] != nullptr && ds.ds[i]->ISBN == isbn_chuanhoa) return ds.ds[i];
    }
    return nullptr;
}

// [DEMO - CODEX] Dieu chinh tu ham cua Thai de ghep voi du lieu demo.
int TimViTriChenTheoTen(const DanhSachDauSach& ds, const DauSach& d) {
    int l = 0;
    int r = ds.soLuong;                     
    while (l < r) {
        int m = (l + r) / 2;
        // loi thu vien
        if (ds.ds[m] == nullptr) return -1;
        int ten = SoSanhChuoi(ds.ds[m]->tenSach, d.tenSach);
        if (ten < 0 || (ten == 0 && ds.ds[m]->ISBN < ChuanHoaChuoiSach(d.ISBN)))
            l = m + 1;                      // ds[m] < d  -> chen SAU m
        else
            r = m;                          // ds[m] >= d -> chen TAI hoac TRUOC m
    }
    return l;                               
}

// [DEMO - CODEX] Dieu chinh tu ham cua Thai de ghep voi du lieu demo.
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
    DauSach duLieu = d;
    duLieu.ISBN = ChuanHoaChuoiSach(d.ISBN);
    DauSach *moi = new DauSach(duLieu);
    for(int i = tv.dsDauSach.soLuong; i > vitriChen; --i){
        tv.dsDauSach.ds[i] = tv.dsDauSach.ds[i-1];
    }
    // [DEMO - CODEX] ISBN duoc chuan hoa truoc khi chen.
    tv.dsDauSach.ds[vitriChen] = moi;
    ++tv.dsDauSach.soLuong;
    loi.clear();
    return true;
}

// [DEMO - CODEX] Phan bo sung cho ban trinh thay.
DauSach *TimDauSachTheoISBN(DanhSachDauSach &ds, const string &isbn)
{
    string chuan = ChuanHoaChuoiSach(isbn);
    for (int i = 0; i < ds.soLuong; i++)
    {
        if (ds.ds[i]->ISBN == chuan)
        {
            return ds.ds[i];
        }
    }
    return nullptr;
}
void HuyDanhSachDauSach(DanhSachDauSach &ds)
{
    for (int i = 0; i < ds.soLuong; i++)
    {
        if (ds.ds[i] != nullptr)
        {
            HuyDanhMucCuonSach(ds.ds[i]->dms);
        }
        delete ds.ds[i];
        ds.ds[i] = nullptr;
    }
    ds.soLuong = 0;
}
void ManHinhNhapDauSach(GiaoDien &gd, ThuVien &tv)
{
    const char *labels[] = {"Them dau sach moi", "Them cuon cho dau sach da co"};
    int choice = ChonMenu(gd, "NHAP SACH", labels, 2);
    if (choice < 1)
    {
        return;
    }
    string isbn, loi;
    if (DangDungGiaoDienHeThong(gd))
    {
        if (choice == 1)
        {
            const char *fields[] = {"ISBN",    "Ten sach",     "So trang",
                                    "Tac gia", "Nam xuat ban", "The loai"};
            string values[6];
            values[4] = ChuoiSo(HomNay().nam);
            while (NhapBieuMau(gd, "THEM DAU SACH", fields, values, 6))
            {
                DauSach d;
                d.ISBN = values[0];
                d.tenSach = values[1];
                d.tacGia = values[3];
                d.theLoai = values[5];
                if (!DocSoNguyen(values[2], d.soTrang, 1, 2147483647))
                {
                    ThongBao(gd, "So trang phai la so nguyen duong.");
                    continue;
                }
                if (!DocSoNguyen(values[4], d.namXuatBan, 1, HomNay().nam))
                {
                    ThongBao(gd, "Nam xuat ban phai tu 1 den nam hien tai.");
                    continue;
                }
                if (!ThemDauSach(tv, d, loi))
                {
                    ThongBao(gd, "LOI: " + loi);
                    continue;
                }
                LuuSauThayDoi(gd, tv);
                ThongBao(gd, "Da them dau sach " + ChuanHoaChuoiSach(d.ISBN) +
                         ". Chon Them cuon de nhap cac ban sach.");
                return;
            }
        }
        else
        {
            const char *fields[] = {"ISBN dau sach", "Vi tri cuon sach"};
            string values[2];
            while (NhapBieuMau(gd, "THEM CUON SACH", fields, values, 2))
            {
                string ma;
                if (!ThemCuonSach(tv, values[0], values[1], ma, loi))
                {
                    ThongBao(gd, "LOI: " + loi);
                    continue;
                }
                LuuSauThayDoi(gd, tv);
                ThongBao(gd, "Da cap ma cuon: " + ma);
                return;
            }
        }
        return;
    }
    if (choice == 1)
    {
        DauSach d;
        if (!NhapDong(gd, "ISBN: ", d.ISBN) || !NhapDong(gd, "Ten sach: ", d.tenSach) ||
            !NhapSo(gd, "So trang: ", d.soTrang, 1, 2147483647) || !NhapDong(gd, "Tac gia: ", d.tacGia) ||
            !NhapSo(gd, "Nam xuat ban: ", d.namXuatBan, 1, HomNay().nam) ||
            !NhapDong(gd, "The loai: ", d.theLoai))
        {
            return;
        }
        if (!ThemDauSach(tv, d, loi))
        {
            ThongBao(gd, loi);
            return;
        }
        LuuSauThayDoi(gd, tv);
        isbn = ChuanHoaChuoiSach(d.ISBN);
        ThongBao(gd, "Da them dau sach. Nhap so cuon muon them; 0 de ket thuc.");
    }
    else
    {
        if (!NhapDong(gd, "ISBN dau sach: ", isbn))
        {
            return;
        }
        isbn = ChuanHoaChuoiSach(isbn);
        if (!TimDauSachTheoISBN(tv.dsDauSach, isbn))
        {
            ThongBao(gd, "Khong tim thay ISBN.");
            return;
        }
    }
    int n;
    if (!NhapSo(gd, "So cuon can them: ", n, 0, MAX_BAN_GHI))
    {
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        string viTri, ma;
        if (!NhapDong(gd, "Vi tri cuon " + ChuoiSo(i + 1) + ": ", viTri))
        {
            ThongBao(gd, "Da dung nhap. Dau sach va nhung cuon da them duoc giu lai.");
            return;
        }
        if (!ThemCuonSach(tv, isbn, viTri, ma, loi))
        {
            ThongBao(gd, loi);
            return;
        }
        LuuSauThayDoi(gd, tv);
        ThongBao(gd, "Da cap ma cuon: " + ma);
    }
}
