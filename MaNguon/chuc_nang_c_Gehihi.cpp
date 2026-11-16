#include "00_KhaiBaoChung.h"

// ============================================================================
// PHAN 02: QUAN LY DAU SACH (02_DauSach.cpp)
// ============================================================================

bool HopLeDauSach(const DauSach &d, string &loi) {
    // Tu duy 1: Kiem tra ISBN-13 truoc vi day la khoa dinh danh duy nhat cua dau sach.
    if (d.ISBN.size() != 13) {
        loi = "ISBN phai gom dung 13 chu so (0-9).";
        return false;
    }
    for (int i = 0; i < (int)d.ISBN.size(); ++i) {
        if (d.ISBN[i] < '0' || d.ISBN[i] > '9') {
            loi = "ISBN chi duoc chua ky tu so tu 0 den 9.";
            return false;
        }
    }

    // Tu duy 2: Kiem tra cac truong chuoi (tenSach, tacGia, theLoai):
    // Phai co it nhat 1 ky tu khac khoang trang, va KHONG chua '#' (ky tu tach maSach) hoac '|'.
    const string *truongChuoi[3] = {&d.tenSach, &d.tacGia, &d.theLoai};
    const char *tenTruong[3] = {"Ten sach", "Tac gia", "The loai"};
    for (int k = 0; k < 3; ++k) {
        const string &s = *truongChuoi[k];
        bool coKyTu = false;
        for (int i = 0; i < (int)s.size(); ++i) {
            unsigned char c = (unsigned char)s[i];
            if (c < 32 || c == 127) {
                loi = string(tenTruong[k]) + " chua ky tu dieu khien khong hop le.";
                return false;
            }
            if (s[i] == '#' || s[i] == '|') {
                loi = string(tenTruong[k]) + " khong duoc chua ky tu '#' hoac '|'.";
                return false;
            }
            if (s[i] != ' ' && s[i] != '\t') coKyTu = true;
        }
        if (!coKyTu) {
            loi = string(tenTruong[k]) + " khong duoc de trong.";
            return false;
        }
    }

    // Tu duy 3: Kiem tra mien gia tri so hoc cho so trang va nam xuat ban.
    if (d.soTrang <= 0) {
        loi = "So trang phai lon hon 0.";
        return false;
    }
    if (d.namXuatBan < 1000 || d.namXuatBan > NAM_HIEN_TAI) {
        loi = "Nam xuat ban phai nam trong khoang 1000 den nam hien tai.";
        return false;
    }

    loi = "";
    return true;
}

bool HopLeCuonSach(const CuonSach &s, string &loi) {
    // Tu duy 1: Ma sach khong duoc rong va khong chua ky tu pha vo cau truc luu tru.
    bool coKyTu = false;
    for (int i = 0; i < (int)s.maSach.size(); ++i) {
        unsigned char c = (unsigned char)s.maSach[i];
        if (c < 32 || c == 127 || s.maSach[i] == '|') {
            loi = "Ma sach chua ky tu khong hop le.";
            return false;
        }
        if (s.maSach[i] != ' ' && s.maSach[i] != '\t') coKyTu = true;
    }
    if (!coKyTu) {
        loi = "Ma sach khong duoc de trong.";
        return false;
    }

    // Tu duy 2: Trang thai phai nam trong tap hang so cho phep (0, 1, 2).
    if (s.trangThai != SACH_CHO_MUON && s.trangThai != SACH_DANG_MUON &&
        s.trangThai != SACH_THANH_LY) {
        loi = "Trang thai cuon sach khong hop le.";
        return false;
    }

    // Tu duy 3: Vi tri bat buoc dung khuon K-KK-TT (7 ky tu, vd A-03-02).
    // Khu: A..Z; Ke: 01..99; Tang: 01..99 (khong chap nhan 00).
    if (s.viTri.size() != 7 || s.viTri[0] < 'A' || s.viTri[0] > 'Z' ||
        s.viTri[1] != '-' || s.viTri[4] != '-') {
        loi = "Vi tri phai dung dinh dang Khu-Ke-Tang (vd: A-03-02).";
        return false;
    }
    for (int idx = 2; idx <= 6; ++idx) {
        if (idx == 4) continue;
        if (s.viTri[idx] < '0' || s.viTri[idx] > '9') {
            loi = "Ke va tang trong vi tri phai la 2 chu so (01-99).";
            return false;
        }
    }
    if ((s.viTri[2] == '0' && s.viTri[3] == '0') || (s.viTri[5] == '0' && s.viTri[6] == '0')) {
        loi = "So ke va so tang phai tu 01 den 99.";
        return false;
    }

    loi = "";
    return true;
}

int TimViTriChenTheoTen(const DanhSachDauSach &ds, const DauSach &d) {
    // Tu duy: Mang ds.ds da luon tang dan theo tenSach -> dung Binary Search de tim vi tri chen O(log N).
    // Voi hai dau sach trung tenSach (khong phan biet hoa/thuong ASCII), xep tiep theo ISBN de co thu tu xac dinh.
    int lo = 0, hi = ds.soLuong - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        const string &a = ds.ds[mid]->tenSach;
        const string &b = d.tenSach;

        int i = 0, cmp = 0;
        while (i < (int)a.size() && i < (int)b.size()) {
            char ca = (a[i] >= 'A' && a[i] <= 'Z') ? (char)(a[i] + 32) : a[i];
            char cb = (b[i] >= 'A' && b[i] <= 'Z') ? (char)(b[i] + 32) : b[i];
            if (ca != cb) {
                cmp = (unsigned char)ca < (unsigned char)cb ? -1 : 1;
                break;
            }
            ++i;
        }
        if (cmp == 0 && a.size() != b.size()) {
            cmp = (a.size() < b.size()) ? -1 : 1;
        }
        if (cmp == 0) {
            // Trung tenSach -> phan dinh vi tri bang ISBN de giu thu tu on dinh.
            if (ds.ds[mid]->ISBN != d.ISBN) {
                cmp = (ds.ds[mid]->ISBN < d.ISBN) ? -1 : 1;
            }
        }

        if (cmp < 0) lo = mid + 1;
        else hi = mid - 1;
    }
    return lo;
}

const DauSach *TimDauSachTheoISBN(const DanhSachDauSach &ds, const string &isbn) {
    // Tu duy: Mang con tro duoc sap theo tenSach chu khong sap theo ISBN,
    // nen tim theo ISBN bat buoc duyet tuyen tinh tren mang con tro O(N).
    // Cat khoang trang hai dau cua chuoi isbn truyen vao truoc khi doi chieu.
    int L = 0, R = (int)isbn.size() - 1;
    while (L <= R && (isbn[L] == ' ' || isbn[L] == '\t')) ++L;
    while (R >= L && (isbn[R] == ' ' || isbn[R] == '\t')) --R;
    string isbnSach;
    for (int i = L; i <= R; ++i) isbnSach += isbn[i];

    if (isbnSach.size() != 13) return nullptr;
    for (int i = 0; i < ds.soLuong; ++i) {
        if (ds.ds[i] != nullptr && ds.ds[i]->ISBN == isbnSach) return ds.ds[i];
    }
    return nullptr;
}

DauSach *TimDauSachTheoISBN(DanhSachDauSach &ds, const string &isbn) {
    // Tai su dung ban const bang const_cast an toan vi tham so goc ds la non-const.
    return const_cast<DauSach *>(TimDauSachTheoISBN(static_cast<const DanhSachDauSach &>(ds), isbn));
}

bool ThemDauSach(ThuVien &tv, const DauSach &d, string &loi) {
    // Tu duy 1: Chan ngay tu dau neu mang dau sach da day (tranh cap phat vo ich).
    if (tv.dsDauSach.soLuong >= MAX_DAU_SACH) {
        loi = "Danh sach dau sach da dat gioi han toi da.";
        return false;
    }

    // Tu duy 2: Chuan hoa du lieu vao mot ban sao cuc bo (bo khoang trang thua hai dau va giua cac tu),
    // dong thoi ep dms = nullptr de bao dam DauSach moi khong ke thua con tro ngoai.
    DauSach moi = d;
    moi.dms = nullptr;
    string *canChuan[4] = {&moi.ISBN, &moi.tenSach, &moi.tacGia, &moi.theLoai};
    for (int k = 0; k < 4; ++k) {
        const string &src = *canChuan[k];
        string out;
        bool dangCoSpace = true; // true ngay tu dau giup tu dong cat khoang trang dau chuoi
        for (int i = 0; i < (int)src.size(); ++i) {
            if (src[i] == ' ' || src[i] == '\t') {
                if (!dangCoSpace && k != 0) { // ISBN (k==0) khong chen khoang trang ben trong
                    out += ' ';
                    dangCoSpace = true;
                }
            } else {
                out += src[i];
                dangCoSpace = false;
            }
        }
        if (!out.empty() && out[out.size() - 1] == ' ') {
            string trimmed;
            for (int i = 0; i < (int)out.size() - 1; ++i) trimmed += out[i];
            out = trimmed;
        }
        *canChuan[k] = out;
    }

    // Tu duy 3: Kiem tra hop le va kiem tra trung ISBN truoc khi cap phat dong.
    if (!HopLeDauSach(moi, loi)) return false;
    if (TimDauSachTheoISBN(tv.dsDauSach, moi.ISBN) != nullptr) {
        loi = "ISBN da ton tai trong thu vien.";
        return false;
    }

    // Tu duy 4: Tim vi tri chen bang Binary Search roi moi cap phat va dich phai mang.
    int pos = TimViTriChenTheoTen(tv.dsDauSach, moi);
    DauSach *node = nullptr;
    try {
        node = new DauSach(moi);
    } catch (...) {
        loi = "Khong du bo nho de tao dau sach moi.";
        return false;
    }

    for (int i = tv.dsDauSach.soLuong; i > pos; --i) {
        tv.dsDauSach.ds[i] = tv.dsDauSach.ds[i - 1];
    }
    tv.dsDauSach.ds[pos] = node;
    tv.dsDauSach.soLuong++;

    loi = "";
    return true;
}

void HuyDanhSachDauSach(DanhSachDauSach &ds) {
    // Tu duy: Giai phong DSLK cuon sach ben trong tung dau sach truoc khi delete dau sach.
    for (int i = 0; i < ds.soLuong; ++i) {
        if (ds.ds[i] != nullptr) {
            HuyDanhMucCuonSach(ds.ds[i]->dms);
            delete ds.ds[i];
            ds.ds[i] = nullptr;
        }
    }
    ds.soLuong = 0;
}

void ManHinhNhapDauSach(ThuVien &tv) {
    // Tu duy UI: Tach luong chon giua (1) tao dau sach moi + tao ban sao hang loat,
    // va (2) nhap them ban sao cho dau sach da co. Moi thao tac logic goi qua ham Tang Logic.
    const char *menuLabels[3] = {
        "1. Nhap dau sach moi (tu dong danh ma cuon sach)",
        "2. Nhap them cuon sach cho dau sach da co (theo ISBN)",
        "0. Quay lai"
    };

    while (true) {
        int chon = ChonMenu("CHUC NANG C - NHAP DAU SACH & DANH MA SACH", menuLabels, 3);
        if (chon < 0 || chon == 2) break;

        if (chon == 0) {
            const char *formLabels[6] = {
                "ISBN-13 (13 chu so 0-9)",
                "Ten sach (khong chua # hoac |)",
                "So trang (> 0)",
                "Tac gia",
                "Nam xuat ban (1000..2026)",
                "The loai"
            };
            string values[6];
            bool daThemDauSach = false;
            string isbnDaLuu;

            while (true) {
                if (!NhapBieuMau("THEM DAU SACH MOI", formLabels, values, 6)) break;

                // Tu duy chuyen chuoi sang so thu cong (khong dung stoi):
                int soTrang = 0, namXB = 0;
                bool okTrang = true, okNam = true;

                const string &sTrang = values[2];
                int l1 = 0, r1 = (int)sTrang.size() - 1;
                while (l1 <= r1 && (sTrang[l1] == ' ' || sTrang[l1] == '\t')) ++l1;
                while (r1 >= l1 && (sTrang[r1] == ' ' || sTrang[r1] == '\t')) --r1;
                if (l1 > r1) okTrang = false;
                for (int i = l1; i <= r1 && okTrang; ++i) {
                    if (sTrang[i] < '0' || sTrang[i] > '9') okTrang = false;
                    else {
                        int digit = sTrang[i] - '0';
                        if (soTrang > (SO_NGUYEN_LON_NHAT - digit) / 10) okTrang = false;
                        else soTrang = soTrang * 10 + digit;
                    }
                }
                if (!okTrang || soTrang <= 0) {
                    ThongBao("Loi: So trang phai la so nguyen duong hop le.");
                    continue;
                }

                const string &sNam = values[4];
                int l2 = 0, r2 = (int)sNam.size() - 1;
                while (l2 <= r2 && (sNam[l2] == ' ' || sNam[l2] == '\t')) ++l2;
                while (r2 >= l2 && (sNam[r2] == ' ' || sNam[r2] == '\t')) --r2;
                if (l2 > r2) okNam = false;
                for (int i = l2; i <= r2 && okNam; ++i) {
                    if (sNam[i] < '0' || sNam[i] > '9') okNam = false;
                    else {
                        int digit = sNam[i] - '0';
                        if (namXB > (SO_NGUYEN_LON_NHAT - digit) / 10) okNam = false;
                        else namXB = namXB * 10 + digit;
                    }
                }
                if (!okNam) {
                    ThongBao("Loi: Nam xuat ban phai la so nguyen hop le.");
                    continue;
                }

                DauSach d;
                d.ISBN = values[0];
                d.tenSach = values[1];
                d.soTrang = soTrang;
                d.tacGia = values[3];
                d.namXuatBan = namXB;
                d.theLoai = values[5];
                d.dms = nullptr;

                string loi;
                if (!ThemDauSach(tv, d, loi)) {
                    ThongBao("Loi: " + loi);
                    continue;
                }

                // Cat trang dau/cuoi ISBN de dung tim kiem them ban sao ngay lap tuc.
                int li = 0, ri = (int)d.ISBN.size() - 1;
                while (li <= ri && (d.ISBN[li] == ' ' || d.ISBN[li] == '\t')) ++li;
                while (ri >= li && (d.ISBN[ri] == ' ' || d.ISBN[ri] == '\t')) --ri;
                for (int i = li; i <= ri; ++i) isbnDaLuu += d.ISBN[i];
                daThemDauSach = true;
                break;
            }

            if (daThemDauSach) {
                ThongBao("Da luu dau sach moi! ISBN: " + isbnDaLuu);
                int soBanSao = 0;
                if (NhapSo("Nhap so cuon sach muon tao tu dong ngay (0 de bo qua): ",
                           soBanSao, 0, 1000) && soBanSao > 0) {
                    for (int k = 1; k <= soBanSao; ++k) {
                        // Chuyen k thanh chuoi thu cong (khong dung to_string).
                        string sThuTu, rev;
                        int x = k;
                        while (x > 0) {
                            rev += (char)('0' + (x % 10));
                            x /= 10;
                        }
                        for (int idx = (int)rev.size() - 1; idx >= 0; --idx) sThuTu += rev[idx];

                        string viTri, maMoi, loi;
                        if (!NhapDong("Vi tri cuon " + sThuTu + " (Khu-Ke-Tang, vd A-03-02): ", viTri)) {
                            ThongBao("Da dung them cac cuon con lai.");
                            break;
                        }
                        if (!ThemCuonSach(tv, isbnDaLuu, viTri, maMoi, loi)) {
                            ThongBao("Loi: " + loi);
                            --k; // Cho phep nhap lai dung cuon dang loi vi tri
                        } else {
                            ThongBao("Tao thanh cong ma sach: " + maMoi);
                        }
                    }
                }
            }
        } else if (chon == 1) {
            string isbn;
            if (!NhapDong("Nhap ISBN-13 cua dau sach da co: ", isbn)) continue;
            DauSach *ds = TimDauSachTheoISBN(tv.dsDauSach, isbn);
            if (ds == nullptr) {
                ThongBao("Khong tim thay dau sach co ISBN nay!");
                continue;
            }

            int soBanSao = 0;
            if (!NhapSo("Dau sach \"" + ds->tenSach + "\" - Nhap so cuon can them: ",
                        soBanSao, 1, 1000)) {
                continue;
            }
            for (int k = 1; k <= soBanSao; ++k) {
                string sThuTu, rev;
                int x = k;
                while (x > 0) {
                    rev += (char)('0' + (x % 10));
                    x /= 10;
                }
                for (int idx = (int)rev.size() - 1; idx >= 0; --idx) sThuTu += rev[idx];

                string viTri, maMoi, loi;
                if (!NhapDong("Vi tri cuon " + sThuTu + " (Khu-Ke-Tang, vd A-03-02): ", viTri)) {
                    ThongBao("Da dung them cac cuon con lai.");
                    break;
                }
                if (!ThemCuonSach(tv, ds->ISBN, viTri, maMoi, loi)) {
                    ThongBao("Loi: " + loi);
                    --k;
                } else {
                    ThongBao("Tao thanh cong ma sach: " + maMoi);
                }
            }
        }
    }
}

// ============================================================================
// PHAN 03: DANH MUC CUON SACH & TIM KIEM NHANH (03_CuonSach.cpp)
// ============================================================================

const CuonSach *TimCuonSachTrongDauSach(const DauSach &d, const string &ma) {
    // Tu duy: Cat khoang trang hai dau cua ma tim kiem, sau do so sanh khong phan biet hoa/thuong ASCII
    // de thu thu go "lap trinh c#978...#1" van tim dung "Lap Trinh C#978...#1".
    int L = 0, R = (int)ma.size() - 1;
    while (L <= R && (ma[L] == ' ' || ma[L] == '\t')) ++L;
    while (R >= L && (ma[R] == ' ' || ma[R] == '\t')) --R;
    string maSachTim;
    for (int i = L; i <= R; ++i) maSachTim += ma[i];
    if (maSachTim.empty()) return nullptr;

    for (const CuonSach *p = d.dms; p != nullptr; p = p->next) {
        if (p->maSach.size() != maSachTim.size()) continue;
        bool khop = true;
        for (int i = 0; i < (int)maSachTim.size(); ++i) {
            char ca = p->maSach[i];
            char cb = maSachTim[i];
            if (ca >= 'A' && ca <= 'Z') ca = (char)(ca + 32);
            if (cb >= 'A' && cb <= 'Z') cb = (char)(cb + 32);
            if (ca != cb) {
                khop = false;
                break;
            }
        }
        if (khop) return p;
    }
    return nullptr;
}

CuonSach *TimCuonSachTrongDauSach(DauSach &d, const string &ma) {
    return const_cast<CuonSach *>(TimCuonSachTrongDauSach(static_cast<const DauSach &>(d), ma));
}

const CuonSach *TimCuonSachToanCuc(const ThuVien &tv, const string &ma, const DauSach **owner) {
    if (owner != nullptr) *owner = nullptr;

    // Tu duy 1: Cat khoang trang ngoai cua ma truy van.
    int L = 0, R = (int)ma.size() - 1;
    while (L <= R && (ma[L] == ' ' || ma[L] == '\t')) ++L;
    while (R >= L && (ma[R] == ' ' || ma[R] == '\t')) --R;
    string maClean;
    for (int i = L; i <= R; ++i) maClean += ma[i];
    if (maClean.empty()) return nullptr;

    // Tu duy 2: Quy uoc maSach = tenSach#ISBN#N.
    // Quet nguoc tu phai sang trai tim 2 dau '#' cuoi cung de tach tenSach va ISBN chinh xac:
    // [0..pos1-1] la tenSach, [pos1+1..pos2-1] la ISBN, [pos2+1..end] la N.
    int pos2 = -1, pos1 = -1;
    for (int i = (int)maClean.size() - 1; i >= 0; --i) {
        if (maClean[i] == '#') {
            if (pos2 == -1) pos2 = i;
            else {
                pos1 = i;
                break;
            }
        }
    }

    // Tu duy 3 (Nhanh nhat): Neu dung dinh dang tenSach#ISBN#N:
    // - Dung Binary Search tim tenSach tren mang con tro dau sach (O(log N)).
    // - Neu tai vi tri mid khop tenSach nhung khac ISBN, quet lan can sang trai roi sang phai,
    //   dung ngay lap tuc khi tenSach khong con khop.
    // - Tim duoc DauSach dich thi nhay thang vao DSLK dms de tim dung node CuonSach.
    if (pos1 > 0 && pos2 > pos1 + 1 && pos2 + 1 < (int)maClean.size()) {
        string tenPart, isbnPart;
        for (int i = 0; i < pos1; ++i) tenPart += maClean[i];
        for (int i = pos1 + 1; i < pos2; ++i) isbnPart += maClean[i];

        int lo = 0, hi = tv.dsDauSach.soLuong - 1, midMatch = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            const string &tenMid = tv.dsDauSach.ds[mid]->tenSach;

            int i = 0, cmp = 0;
            while (i < (int)tenMid.size() && i < (int)tenPart.size()) {
                char ca = (tenMid[i] >= 'A' && tenMid[i] <= 'Z') ? (char)(tenMid[i] + 32) : tenMid[i];
                char cb = (tenPart[i] >= 'A' && tenPart[i] <= 'Z') ? (char)(tenPart[i] + 32) : tenPart[i];
                if (ca != cb) {
                    cmp = (unsigned char)ca < (unsigned char)cb ? -1 : 1;
                    break;
                }
                ++i;
            }
            if (cmp == 0 && tenMid.size() != tenPart.size()) {
                cmp = (tenMid.size() < tenPart.size()) ? -1 : 1;
            }

            if (cmp == 0) {
                midMatch = mid;
                break;
            }
            if (cmp < 0) lo = mid + 1;
            else hi = mid - 1;
        }

        if (midMatch == -1) return nullptr;

        const DauSach *target = nullptr;
        if (tv.dsDauSach.ds[midMatch]->ISBN == isbnPart) {
            target = tv.dsDauSach.ds[midMatch];
        } else {
            // Quet sang trai trong pham vi cac dau sach co cung tenSach.
            for (int k = midMatch - 1; k >= 0; --k) {
                const string &t = tv.dsDauSach.ds[k]->tenSach;
                if (t.size() != tenPart.size()) break;
                bool cungTen = true;
                for (int i = 0; i < (int)t.size(); ++i) {
                    char ca = (t[i] >= 'A' && t[i] <= 'Z') ? (char)(t[i] + 32) : t[i];
                    char cb = (tenPart[i] >= 'A' && tenPart[i] <= 'Z') ? (char)(tenPart[i] + 32) : tenPart[i];
                    if (ca != cb) {
                        cungTen = false;
                        break;
                    }
                }
                if (!cungTen) break; // Dieu kien dung: tenSach khac nhau
                if (tv.dsDauSach.ds[k]->ISBN == isbnPart) {
                    target = tv.dsDauSach.ds[k];
                    break;
                }
            }

            // Neu ben trai chua thay, quet sang phai trong pham vi cung tenSach.
            if (target == nullptr) {
                for (int k = midMatch + 1; k < tv.dsDauSach.soLuong; ++k) {
                    const string &t = tv.dsDauSach.ds[k]->tenSach;
                    if (t.size() != tenPart.size()) break;
                    bool cungTen = true;
                    for (int i = 0; i < (int)t.size(); ++i) {
                        char ca = (t[i] >= 'A' && t[i] <= 'Z') ? (char)(t[i] + 32) : t[i];
                        char cb = (tenPart[i] >= 'A' && tenPart[i] <= 'Z') ? (char)(tenPart[i] + 32) : tenPart[i];
                        if (ca != cb) {
                            cungTen = false;
                            break;
                        }
                    }
                    if (!cungTen) break; // Dieu kien dung: tenSach khac nhau
                    if (tv.dsDauSach.ds[k]->ISBN == isbnPart) {
                        target = tv.dsDauSach.ds[k];
                        break;
                    }
                }
            }
        }

        if (target == nullptr) return nullptr;
        const CuonSach *cs = TimCuonSachTrongDauSach(*target, maClean);
        if (cs != nullptr && owner != nullptr) *owner = target;
        return cs;
    }

    // Tu duy 4 (Du phong): Ho tro dinh dang ma cu (ISBN#so hoac S001) neu co tu file cu.
    if (pos2 > 0 && pos1 == -1) {
        string isbnCu;
        for (int i = 0; i < pos2; ++i) isbnCu += maClean[i];
        const DauSach *target = TimDauSachTheoISBN(tv.dsDauSach, isbnCu);
        if (target != nullptr) {
            const CuonSach *cs = TimCuonSachTrongDauSach(*target, maClean);
            if (cs != nullptr && owner != nullptr) *owner = target;
            return cs;
        }
    }

    for (int i = 0; i < tv.dsDauSach.soLuong; ++i) {
        if (tv.dsDauSach.ds[i] != nullptr) {
            const CuonSach *cs = TimCuonSachTrongDauSach(*tv.dsDauSach.ds[i], maClean);
            if (cs != nullptr) {
                if (owner != nullptr) *owner = tv.dsDauSach.ds[i];
                return cs;
            }
        }
    }
    return nullptr;
}

CuonSach *TimCuonSachToanCuc(ThuVien &tv, const string &ma, DauSach **owner) {
    const DauSach *constOwner = nullptr;
    const CuonSach *found = TimCuonSachToanCuc(static_cast<const ThuVien &>(tv), ma, &constOwner);
    if (owner != nullptr) *owner = const_cast<DauSach *>(constOwner);
    return const_cast<CuonSach *>(found);
}

bool SinhMaSachTuDong(const ThuVien &tv, const DauSach &d, string &ma, string &loi) {
    // Tu duy 1: Bao dam tenSach va ISBN cua dau sach hop le va khong chua '#' truoc khi ghep ma.
    if (d.tenSach.empty() || d.ISBN.empty()) {
        loi = "Thieu ten sach hoac ISBN de sinh ma sach.";
        return false;
    }
    for (int i = 0; i < (int)d.tenSach.size(); ++i) {
        if (d.tenSach[i] == '#' || d.tenSach[i] == '|') {
            loi = "Ten sach chua ky tu cam khong the sinh ma.";
            return false;
        }
    }

    // Tu duy 2: Thay vi dung (soLuong + 1) de bi trung khi tung xoa/doc file co khoang trong,
    // quet toan bo danh muc cuon sach de tim gia tri N lon nhat hien co va tang len 1.
    int maxN = 0;
    const DauSach *dsTrongTV = TimDauSachTheoISBN(tv.dsDauSach, d.ISBN);
    const CuonSach *lists[2] = {d.dms, (dsTrongTV != nullptr && dsTrongTV != &d) ? dsTrongTV->dms : nullptr};

    for (int L = 0; L < 2; ++L) {
        for (const CuonSach *p = lists[L]; p != nullptr; p = p->next) {
            int lastHash = -1;
            for (int i = (int)p->maSach.size() - 1; i >= 0; --i) {
                if (p->maSach[i] == '#') {
                    lastHash = i;
                    break;
                }
            }
            if (lastHash >= 0 && lastHash + 1 < (int)p->maSach.size()) {
                int val = 0;
                bool toanSo = true;
                for (int i = lastHash + 1; i < (int)p->maSach.size(); ++i) {
                    if (p->maSach[i] < '0' || p->maSach[i] > '9') {
                        toanSo = false;
                        break;
                    }
                    int digit = p->maSach[i] - '0';
                    if (val > (SO_NGUYEN_LON_NHAT - 1 - digit) / 10) {
                        toanSo = false;
                        break;
                    }
                    val = val * 10 + digit;
                }
                if (toanSo && val > maxN) maxN = val;
            }
        }
    }

    // Tu duy 3: Ghep chuoi theo dung quy uoc tenSach#ISBN#N va kiem chung khong trung lap.
    int nextN = maxN + 1;
    while (true) {
        string strN, rev;
        int tmp = nextN;
        while (tmp > 0) {
            rev += (char)('0' + (tmp % 10));
            tmp /= 10;
        }
        for (int i = (int)rev.size() - 1; i >= 0; --i) strN += rev[i];

        string ungVien = d.tenSach + "#" + d.ISBN + "#" + strN;
        bool trung = (TimCuonSachTrongDauSach(d, ungVien) != nullptr);
        if (!trung && dsTrongTV != nullptr && dsTrongTV != &d) {
            trung = (TimCuonSachTrongDauSach(*dsTrongTV, ungVien) != nullptr);
        }
        if (!trung) {
            ma = ungVien;
            loi = "";
            return true;
        }
        if (nextN >= SO_NGUYEN_LON_NHAT) {
            loi = "Vuot qua gioi han so thu tu ma sach.";
            return false;
        }
        ++nextN;
    }
}

bool ThemCuonSach(ThuVien &tv, const string &isbn, const string &viTri, string &ma, string &loi) {
    ma = "";

    // Tu duy 1: Tim dau sach so huu theo ISBN truoc khi thao tac vi tri hay sinh ma.
    DauSach *ds = TimDauSachTheoISBN(tv.dsDauSach, isbn);
    if (ds == nullptr) {
        loi = "Khong tim thay dau sach co ISBN nay.";
        return false;
    }

    // Tu duy 2: Chuan hoa nhe viTri (cat khoang trang hai dau, viet hoa ky tu khu 'a'..'z' -> 'A'..'Z')
    // de than thien voi nguoi nhap ma van giu nghiem quy chuan A-03-02 trong HopLeCuonSach.
    int L = 0, R = (int)viTri.size() - 1;
    while (L <= R && (viTri[L] == ' ' || viTri[L] == '\t')) ++L;
    while (R >= L && (viTri[R] == ' ' || viTri[R] == '\t')) --R;
    string viTriClean;
    for (int i = L; i <= R; ++i) viTriClean += viTri[i];
    if (!viTriClean.empty() && viTriClean[0] >= 'a' && viTriClean[0] <= 'z') {
        viTriClean[0] = (char)(viTriClean[0] - 32);
    }

    // Tu duy 3: Sinh ma sach va kiem tra HopLeCuonSach truoc khi cap phat node DSLK.
    string maSinh;
    if (!SinhMaSachTuDong(tv, *ds, maSinh, loi)) return false;

    CuonSach mau;
    mau.maSach = maSinh;
    mau.trangThai = SACH_CHO_MUON;
    mau.viTri = viTriClean;
    mau.next = nullptr;
    if (!HopLeCuonSach(mau, loi)) return false;

    CuonSach *node = nullptr;
    try {
        node = new CuonSach(mau);
    } catch (...) {
        loi = "Khong du bo nho de tao cuon sach moi.";
        return false;
    }

    // Tu duy 4: Chen cuoi DSLK de giu thu tu ban sao #1, #2, #3... tu nhien khi hien thi.
    if (ds->dms == nullptr) {
        ds->dms = node;
    } else {
        CuonSach *tail = ds->dms;
        while (tail->next != nullptr) tail = tail->next;
        tail->next = node;
    }

    ma = maSinh;
    loi = "";
    return true;
}

void HuyDanhMucCuonSach(CuonSach *&head) {
    while (head != nullptr) {
        CuonSach *tiep = head->next;
        delete head;
        head = tiep;
    }
}

int DemCuonSach(const CuonSach *head) {
    int dem = 0;
    for (const CuonSach *p = head; p != nullptr; p = p->next) ++dem;
    return dem;
}