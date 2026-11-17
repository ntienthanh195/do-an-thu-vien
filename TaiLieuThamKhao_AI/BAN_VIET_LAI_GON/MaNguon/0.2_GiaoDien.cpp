#include "0.0_KhaiBaoChung.h"
#include <conio.h>
#include <cstdio>
#include <cstdlib>
#include <windows.h>

/* ============================================================
   GIAO DIEN CONSOLE TU VIET
   Chi dua tren cac thao tac co ban:
     - gotoxy   : dua con tro toi cot x, dong y (ma ANSI ESC[dong;cotH)
     - SetColor : doi mau chu va mau nen
     - _getch   : doc mot phim, khong can nhan Enter
   Moi thu con lai (thanh menu ben trai, o so lieu, khung, o nhap, bang) deu tu viet tu cac thao tac nay.

   Mau: console chi co san 16 mau co dinh, khong co tong xanh den / xanh bac ha cua giao dien nay.
   Vi vay SetColor khong goi SetConsoleTextAttribute ma in ra "ma mau ANSI":
       ESC [ 38;2;R;G;B m   doi mau chu thanh mau (R, G, B)
       ESC [ 48;2;R;G;B m   doi mau nen
   Day chi la mot chuoi ky tu in bang cout; console doc duoc chuoi nay sau khi KhoiTaoManHinh bat che do do.

   Chu tieng Viet co dau: console duoc chuyen sang bang ma UTF-8 (65001). Trong UTF-8 mot chu co dau
   chiem 2-3 byte nhung chi chiem 1 o tren man hinh, nen khi can le cot phai dem so KY TU chu khong
   dem so BYTE (xem InDuCot).
   ============================================================ */

// Bang mau: dong thu i la mau (do, xanh la, xanh duong) cua ma mau i.
static const int BANG_MAU[16][3] = {
    {15, 22, 32},    // 0  MAU_DEN: nen chinh
    {21, 30, 43},    // 1  MAU_NEN_MENU
    {32, 76, 65},    // 2  MAU_NEN_CHON
    {26, 36, 50},    // 3  MAU_NEN_O
    {127, 138, 153}, // 4  (khong dung)
    {127, 138, 153}, // 5  (khong dung)
    {127, 138, 153}, // 6  (khong dung)
    {214, 221, 230}, // 7  MAU_TRANG
    {125, 137, 153}, // 8  MAU_XAM
    {127, 138, 153}, // 9  (khong dung)
    {152, 211, 142}, // 10 MAU_XANH_LA_SANG
    {143, 212, 180}, // 11 MAU_NGOC_SANG
    {236, 118, 128}, // 12 MAU_DO_SANG
    {127, 138, 153}, // 13 (khong dung)
    {229, 196, 133}, // 14 MAU_VANG_SANG
    {243, 246, 250}  // 15 MAU_TRANG_SANG
};

// Goi mot lan khi mo chuong trinh.
void KhoiTaoManHinh()
{
    system("mode con: cols=120 lines=30"); // co dinh kich thuoc cua so console
    SetConsoleOutputCP(65001);             // in duoc tieng Viet co dau (UTF-8)

    // bat che do cho phep console hieu ma mau ANSI (bit 4 cua che do xuat)
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD cheDo = 0;
    GetConsoleMode(h, &cheDo);
    SetConsoleMode(h, cheDo | 4);

    // Cho cout gom chu vao mot vung dem lon thay vi day ra man hinh tung chut mot.
    // Ca man hinh duoc ve xong trong vung dem roi moi hien ra mot lan (luc DocPhim goi flush),
    // nen khi chuyen man hinh khong thay canh xoa roi ve lai tung phan (nhap nhay).
    setvbuf(stdout, nullptr, _IOFBF, 262144);

    XoaManHinh();
    HienConTro(false); // con tro chi hien khi dang o trong o nhap
}

// Hien hoac an con tro nhap nhay cua console (ma ANSI ESC[?25h / ESC[?25l).
// Neu de con tro luon hien thi moi lan ve lai man hinh se thay no chay loan xa theo cac lenh gotoxy.
void HienConTro(bool hien)
{
    if (hien)
        cout << "\x1b[?25h";
    else
        cout << "\x1b[?25l";
}

// Dua con tro toi cot x, dong y (goc tren trai la 0,0).
// Dung ma ANSI ESC[dong;cotH (dong, cot dem tu 1) thay cho SetConsoleCursorPosition:
// lenh doi vi tri di chung mot dong chay voi chu va ma mau trong vung dem cua cout,
// nen thu tu luon dung ma khong phai day vung dem ra man hinh truoc moi lan doi vi tri.
void gotoxy(int x, int y)
{
    cout << "\x1b[" << (y + 1) << ';' << (x + 1) << 'H';
}

// Doi mau chu va mau nen theo ma mau trong BANG_MAU.
void SetColor(int mauChu, int mauNen)
{
    cout << "\x1b[38;2;" << BANG_MAU[mauChu][0] << ';' << BANG_MAU[mauChu][1] << ';' << BANG_MAU[mauChu][2]
         << ";48;2;" << BANG_MAU[mauNen][0] << ';' << BANG_MAU[mauNen][1] << ';' << BANG_MAU[mauNen][2] << 'm';
}

// Xoa ca man hinh bang mau nen chinh. ESC[2J: xoa man hinh, ESC[H: dua con tro ve goc.
// (system("cls") se xoa bang mau den mac dinh cua console chu khong phai mau nen cua chuong trinh.)
// Chi goi luc mo va luc thoat chuong trinh; khi chuyen man hinh thi VeManHinh ve de len, khong xoa trang.
void XoaManHinh()
{
    SetColor(MAU_TRANG, MAU_DEN);
    cout << "\x1b[2J\x1b[H";
}

// Doc mot phim. Phim mui ten gui 2 ma lien tiep (0 hoac 224, roi ma phim),
// nen cong 256 vao ma thu hai de phan biet voi ky tu thuong.
int DocPhim()
{
    cout.flush(); // moi thu da ve nam trong vung dem: day ra man hinh mot lan truoc khi cho phim
    int c = _getch();
    if (c == 0 || c == 224)
        return 256 + _getch();
    return c;
}

// Cac ham in noi dung duoi day nhan x tinh tu mep trai cua vung noi dung,
// nen cong them RONG_MENU de khong de len thanh menu ben trai.
void InTai(int x, int y, const string &s)
{
    gotoxy(RONG_MENU + x, y);
    cout << s;
}

// In chuoi s tai vi tri con tro hien tai, chiem dung "rong" o: chuoi dai thi cat, ngan thi them khoang trang.
// Luon chua lai o cuoi cung lam khoang cach voi cot ke ben.
// Dem theo ky tu: byte co dang 10xxxxxx la byte noi tiep cua mot chu co dau, in ra nhung khong tinh them o.
void InDuCot(const string &s, int rong)
{
    int soO = 0;
    int i = 0;
    while (i < (int)s.size() && soO < rong - 1)
    {
        cout << s[i];
        ++i;
        while (i < (int)s.size() && ((unsigned char)s[i] & 0xC0) == 0x80)
        {
            cout << s[i];
            ++i;
        }
        ++soO;
    }
    for (; soO < rong; ++soO)
        cout << ' ';
}

// In chuoi vao mot cot rong dung "rong" o tai (x, y) cua vung noi dung.
void InCot(int x, int y, const string &s, int rong)
{
    gotoxy(RONG_MENU + x, y);
    InDuCot(s, rong);
}

void XoaVung(int x, int y, int rong, int cao)
{
    for (int i = 0; i < cao; ++i)
    {
        gotoxy(RONG_MENU + x, y + i);
        for (int j = 0; j < rong; ++j)
            cout << ' ';
    }
}

// Ve khung chu nhat bang cac ky tu ke khung.
void VeKhung(int x, int y, int rong, int cao)
{
    for (int i = 1; i < rong - 1; ++i)
    {
        InTai(x + i, y, "─");
        InTai(x + i, y + cao - 1, "─");
    }
    for (int i = 1; i < cao - 1; ++i)
    {
        InTai(x, y + i, "│");
        InTai(x + rong - 1, y + i, "│");
    }
    InTai(x, y, "┌");
    InTai(x + rong - 1, y, "┐");
    InTai(x, y + cao - 1, "└");
    InTai(x + rong - 1, y + cao - 1, "┘");
}

// Ve mot muc cua thanh menu ben trai (muc thu i, tinh tu 0).
//   - duocChon = false                      : muc binh thuong.
//   - duocChon = true,  dangDieuKhien = true : nguoi dung dang di chuyen tren thanh menu, to nen va co vach sang dau dong.
//   - duocChon = true,  dangDieuKhien = false: dang lam viec trong vung noi dung, chi to nen de biet dang o muc nao.
// Tach rieng ham nay de khi nhan Len/Xuong chi ve lai dung 2 muc (muc cu va muc moi),
// khong ve lai ca thanh menu, nho do man hinh khong bi nhap nhay.
// Ham dung gotoxy truc tiep vi no ve o ngoai vung noi dung.
void VeMucMenu(int i, bool duocChon, bool dangDieuKhien)
{
    const string muc[SO_MUC_MENU] = {
        "Tổng quan",
        "Quản lý độc giả",
        "Danh sách độc giả",
        "Nhập sách",
        "Theo thể loại",
        "Tìm kiếm sách",
        "Mượn sách",
        "Trả / báo mất",
        "Sách đang mượn",
        "Độc giả quá hạn",
        "Top 10 đầu sách",
        "Thoát"};

    gotoxy(1, 4 + i);
    if (!duocChon)
    {
        SetColor(MAU_TRANG, MAU_NEN_MENU);
        cout << "  ";
    }
    else if (dangDieuKhien)
    {
        SetColor(MAU_NGOC_SANG, MAU_NEN_CHON);
        cout << "▌ ";
        SetColor(MAU_TRANG_SANG, MAU_NEN_CHON);
    }
    else
    {
        SetColor(MAU_NGOC_SANG, MAU_NEN_CHON);
        cout << "  ";
    }
    InDuCot(muc[i], RONG_MENU - 4);
    SetColor(MAU_TRANG, MAU_DEN);
}

// Ve ca thanh menu ben trai: nen, ten chuong trinh va 12 muc. Chi goi khi ve lai ca man hinh.
void VeMenuTrai(int mucChon, bool dangDieuKhien)
{
    SetColor(MAU_TRANG, MAU_NEN_MENU);
    for (int y = 0; y < 30; ++y)
    {
        gotoxy(0, y);
        InDuCot("", RONG_MENU);
    }

    SetColor(MAU_NGOC_SANG, MAU_NEN_MENU);
    gotoxy(3, 1);
    cout << "THƯ VIỆN";
    SetColor(MAU_XAM, MAU_NEN_MENU);
    gotoxy(3, 3);
    cout << "CHỨC NĂNG";

    for (int i = 0; i < SO_MUC_MENU; ++i)
        VeMucMenu(i, i == mucChon, dangDieuKhien);
}

// Ve khung chung cua moi man hinh: thanh menu ben trai (to muc mucMenu),
// tieu de va ngay o dau vung noi dung, dong huong dan phim o cuoi.
void VeManHinh(int mucMenu, const string &tieuDe, const string &huongDan)
{
    // Khong xoa trang ca man hinh: thanh menu duoc ve de len chinh no (nhin khong doi),
    // chi vung noi dung duoc lap lai bang mau nen roi ve noi dung moi.
    VeMenuTrai(mucMenu, false);
    SetColor(MAU_TRANG, MAU_DEN);
    XoaVung(0, 0, RONG_MH, 29);
    XoaVung(0, 29, RONG_MH - 1, 1); // chua lai o cuoi cung cua man hinh: in vao do console se cuon len mot dong

    SetColor(MAU_TRANG_SANG, MAU_DEN);
    InTai(2, 1, tieuDe);
    SetColor(MAU_XAM, MAU_DEN);
    InTai(RONG_MH - 13, 1, ChuoiNgay(HomNay()));
    for (int x = 2; x < RONG_MH - 3; ++x)
        InTai(x, 2, "─");

    InCot(2, DONG_HUONG_DAN, huongDan, RONG_MH - 4);
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
    InCot(2, DONG_THONG_BAO, s + "  [nhấn phím bất kỳ]", RONG_MH - 4);
    SetColor(MAU_TRANG, MAU_DEN);
    DocPhim();
    XoaVung(0, DONG_THONG_BAO, RONG_MH, 1);
}

// Hoi co/khong. Nhan C la dong y; K hoac Esc la khong.
bool XacNhan(const string &cauHoi)
{
    XoaVung(0, DONG_THONG_BAO, RONG_MH, 1);
    SetColor(MAU_VANG_SANG, MAU_DEN);
    InCot(2, DONG_THONG_BAO, cauHoi + "  [C: có / K: không]", RONG_MH - 4);
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
        SetColor(MAU_DEN, MAU_NGOC_SANG);
        InCot(x, y, tam, doDai + 1);
        gotoxy(RONG_MENU + x + (int)tam.size(), y);
        HienConTro(true);

        int phim = DocPhim();
        HienConTro(false);
        if (phim == PHIM_ENTER || phim == PHIM_ESC)
        {
            if (phim == PHIM_ENTER)
                s = tam;
            // tra o nhap ve mau thuong
            SetColor(MAU_TRANG_SANG, MAU_NEN_O);
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
        ThongBao("Ngày không hợp lệ, nhập theo dạng dd/mm/yyyy.", true);
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
                     "   Tổng số dòng: " + SoThanhChuoi(tongSoDong), 60);
    SetColor(MAU_TRANG, MAU_DEN);
}

string TenTrangThaiSach(int trangThai)
{
    if (trangThai == SACH_CHO_MUON) return "Cho mượn được";
    if (trangThai == SACH_DANG_MUON) return "Đã có người mượn";
    return "Đã thanh lý";
}
