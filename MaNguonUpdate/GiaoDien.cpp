#include "00_KhaiBaoChung.h"
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <iostream>

// [THAI] Chuyen tu be7fa70, chuc nang c.
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

            tenSach = ChuanHoaChuoiSach(tenSach);
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

            tacGia = ChuanHoaChuoiSach(tacGia);
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

            theLoai = ChuanHoaChuoiSach(theLoai);
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
