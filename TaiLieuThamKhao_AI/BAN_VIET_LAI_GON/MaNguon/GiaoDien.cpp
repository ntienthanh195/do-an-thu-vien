#include "00_KhaiBaoChung.h"
#include <conio.h>
#include <cstdlib>
#include <windows.h>

/* ============================================================
   Phan giao dien chi dung 4 thao tac co ban cua console:
     - gotoxy   : dua con tro toi cot x, dong y
     - SetColor : doi mau chu va mau nen
     - system("cls") : xoa man hinh
     - _getch   : doc mot phim, khong can nhan Enter
   Moi thu con lai (khung, menu, o nhap, bang) deu tu viet tu 4 thao tac nay.
   ============================================================ */

// Dua con tro toi cot x, dong y (goc tren trai la 0,0).
void gotoxy(int x, int y)
{
    COORD viTri;
    viTri.X = (short)x;
    viTri.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), viTri);
}

// Mau console = mauNen * 16 + mauChu, moi mau la mot so tu 0 den 15.
void SetColor(int mauChu, int mauNen)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)(mauNen * 16 + mauChu));
}

void XoaManHinh()
{
    SetColor(MAU_TRANG, MAU_DEN);
    system("cls");
}

// Doc mot phim. Phim mui ten gui 2 ma lien tiep (0 hoac 224, roi ma phim),
// nen cong 256 vao ma thu hai de phan biet voi ky tu thuong.
int DocPhim()
{
    int c = _getch();
    if (c == 0 || c == 224)
        return 256 + _getch();
    return c;
}

void InTai(int x, int y, const string &s)
{
    gotoxy(x, y);
    cout << s;
}

// In chuoi vao mot cot rong dung "rong" ky tu: chuoi dai thi cat, ngan thi them khoang trang.
void InCot(int x, int y, const string &s, int rong)
{
    gotoxy(x, y);
    for (int i = 0; i < rong; ++i)
    {
        if (i < (int)s.size() && i < rong - 1)
            cout << s[i];
        else
            cout << ' ';
    }
}

void XoaVung(int x, int y, int rong, int cao)
{
    for (int i = 0; i < cao; ++i)
    {
        gotoxy(x, y + i);
        for (int j = 0; j < rong; ++j)
            cout << ' ';
    }
}

void VeKhung(int x, int y, int rong, int cao)
{
    for (int i = 0; i < rong; ++i)
    {
        gotoxy(x + i, y);
        cout << '-';
        gotoxy(x + i, y + cao - 1);
        cout << '-';
    }
    for (int i = 0; i < cao; ++i)
    {
        gotoxy(x, y + i);
        cout << '|';
        gotoxy(x + rong - 1, y + i);
        cout << '|';
    }
    InTai(x, y, "+");
    InTai(x + rong - 1, y, "+");
    InTai(x, y + cao - 1, "+");
    InTai(x + rong - 1, y + cao - 1, "+");
}

// Xoa man hinh, ve thanh tieu de o tren va dong huong dan phim o duoi.
void VeManHinh(const string &tieuDe, const string &huongDan)
{
    XoaManHinh();

    SetColor(MAU_TRANG_SANG, MAU_XANH_DUONG);
    XoaVung(0, 0, RONG_MH, 3);
    InTai(2, 1, "QUAN LY THU VIEN");
    InTai((RONG_MH - (int)tieuDe.size()) / 2, 1, tieuDe);
    InTai(RONG_MH - 20, 1, "Ngay: " + ChuoiNgay(HomNay()));

    SetColor(MAU_XAM, MAU_DEN);
    InTai(2, DONG_HUONG_DAN, huongDan);
    SetColor(MAU_TRANG, MAU_DEN);
}

// In mot thong bao o dong thong bao roi cho nguoi dung nhan phim.
void ThongBao(const string &s, bool laLoi)
{
    XoaVung(0, DONG_THONG_BAO, RONG_MH, 1);
    if (laLoi)
        SetColor(MAU_DO_SANG, MAU_DEN);
    else
        SetColor(MAU_XANH_LA_SANG, MAU_DEN);
    InTai(2, DONG_THONG_BAO, s + "  [nhan phim bat ky]");
    SetColor(MAU_TRANG, MAU_DEN);
    DocPhim();
    XoaVung(0, DONG_THONG_BAO, RONG_MH, 1);
}

// Hoi co/khong. Nhan C la dong y; K hoac Esc la khong.
bool XacNhan(const string &cauHoi)
{
    XoaVung(0, DONG_THONG_BAO, RONG_MH, 1);
    SetColor(MAU_VANG_SANG, MAU_DEN);
    InTai(2, DONG_THONG_BAO, cauHoi + "  [C: co / K: khong]");
    SetColor(MAU_TRANG, MAU_DEN);

    bool dongY = false;
    while (true)
    {
        int phim = DocPhim();
        if (phim == 'c' || phim == 'C')
        {
            dongY = true;
            break;
        }
        if (phim == 'k' || phim == 'K' || phim == PHIM_ESC)
            break;
    }
    XoaVung(0, DONG_THONG_BAO, RONG_MH, 1);
    return dongY;
}

// Menu doc: len/xuong de di chuyen thanh sang, Enter de chon, Esc de thoat.
// Tra ve vi tri muc duoc chon (tu 0), hoac -1 neu nhan Esc.
int ChonMenu(int x, int y, int rong, const string muc[], int soMuc)
{
    int chon = 0;
    while (true)
    {
        for (int i = 0; i < soMuc; ++i)
        {
            if (i == chon)
                SetColor(MAU_DEN, MAU_NGOC_SANG);
            else
                SetColor(MAU_TRANG, MAU_DEN);
            InCot(x, y + i, " " + muc[i], rong);
        }
        SetColor(MAU_TRANG, MAU_DEN);

        int phim = DocPhim();
        if (phim == PHIM_LEN)
            chon = (chon + soMuc - 1) % soMuc;
        else if (phim == PHIM_XUONG)
            chon = (chon + 1) % soMuc;
        else if (phim == PHIM_ENTER)
            return chon;
        else if (phim == PHIM_ESC)
            return -1;
    }
}

// O nhap mot dong tai (x, y), dai toi da doDai ky tu. Gia tri san co trong s duoc hien de sua.
// Enter: xong, tra ve true. Esc: huy, tra ve false va giu nguyen s.
bool NhapChuoi(int x, int y, int doDai, bool chiNhapSo, string &s)
{
    string tam = s;
    while (true)
    {
        // ve lai o nhap voi nen sang de biet dang nhap o dau
        SetColor(MAU_DEN, MAU_TRANG);
        InCot(x, y, tam, doDai + 1);
        gotoxy(x + (int)tam.size(), y);

        int phim = DocPhim();
        if (phim == PHIM_ENTER || phim == PHIM_ESC)
        {
            if (phim == PHIM_ENTER)
                s = tam;
            // tra o nhap ve mau thuong
            SetColor(MAU_TRANG_SANG, MAU_DEN);
            InCot(x, y, s, doDai + 1);
            SetColor(MAU_TRANG, MAU_DEN);
            return phim == PHIM_ENTER;
        }
        if (phim == PHIM_XOA)
        {
            if (tam.size() > 0)
                tam.erase(tam.size() - 1, 1);
        }
        else if (phim >= 32 && phim <= 126 && (int)tam.size() < doDai)
        {
            if (!chiNhapSo || (phim >= '0' && phim <= '9'))
                tam += (char)phim;
        }
    }
}

// Nhap so nguyen khong am. Bat nhap lai cho toi khi co so hoac nhan Esc.
bool NhapSo(int x, int y, int doDai, int &so)
{
    string tam = "";
    if (so > 0)
        tam = SoThanhChuoi(so);
    while (true)
    {
        if (!NhapChuoi(x, y, doDai, true, tam))
            return false;
        if (ChuoiThanhSo(tam, so))
            return true;
    }
}

// Nhap ngay dang dd/mm/yyyy, hien san gia tri dang co trong bien ngay.
bool NhapNgay(int x, int y, NgayThang &ngay)
{
    string tam = ChuoiNgay(ngay);
    while (true)
    {
        if (!NhapChuoi(x, y, 10, false, tam))
            return false;
        NgayThang d;
        if (DocNgay(tam, d) && NgayHopLe(d))
        {
            ngay = d;
            return true;
        }
        ThongBao("Ngay khong hop le, nhap theo dang dd/mm/yyyy.", true);
    }
}

// Chuyen trang cua bang bang phim trai/phai. Tra ve true neu trang thay doi.
bool XuLyPhimTrang(int phim, int &trang, int tongSoDong)
{
    int tongTrang = (tongSoDong + SO_DONG_TRANG - 1) / SO_DONG_TRANG;
    if (phim == PHIM_PHAI && trang + 1 < tongTrang)
    {
        ++trang;
        return true;
    }
    if (phim == PHIM_TRAI && trang > 0)
    {
        --trang;
        return true;
    }
    return false;
}

void InSoTrang(int trang, int tongSoDong)
{
    int tongTrang = (tongSoDong + SO_DONG_TRANG - 1) / SO_DONG_TRANG;
    if (tongTrang == 0)
        tongTrang = 1;
    SetColor(MAU_XAM, MAU_DEN);
    InCot(2, 24, "Trang " + SoThanhChuoi(trang + 1) + "/" + SoThanhChuoi(tongTrang) +
                     "   Tong so dong: " + SoThanhChuoi(tongSoDong), 60);
    SetColor(MAU_TRANG, MAU_DEN);
}

string TenTrangThaiSach(int trangThai)
{
    if (trangThai == SACH_CHO_MUON) return "Cho muon duoc";
    if (trangThai == SACH_DANG_MUON) return "Da co nguoi muon";
    return "Da thanh ly";
}
