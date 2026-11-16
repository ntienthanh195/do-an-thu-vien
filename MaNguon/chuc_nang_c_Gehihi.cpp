#include "00_KhaiBaoChung.h"
// ============================================================================
// PHAN 1: QUAN LY DAU SACH (02_DauSach.cpp)
// ============================================================================

bool HopLeDauSach(const DauSach &d, string &loi) {
    // Tu duy: Loc bo dau '-' va khoang trang de kiem tra dung 13 chu so cua ISBN-13
    string isbnSo = "";
    for (int i = 0; i < (int)d.ISBN.size(); ++i) {
        char c = d.ISBN[i];
        if (c != '-' && !KhoangTrang((unsigned char)c)) {
            if (c < '0' || c > '9') {
                loi = "ISBN chi duoc chua 13 chu so (0-9)!";
                return false;
            }
            isbnSo += c;
        }
    }
    if ((int)isbnSo.size() != 13) {
        loi = "ISBN phai gom dung 13 chu so!";
        return false;
    }

    // Tu duy: Chan cac truong so hoc nam ngoai mien gia tri thuc te
    if (d.soTrang < 1) {
        loi = "So trang phai lon hon 0!";
        return false;
    }
    if (d.namXuatBan < 1 || d.namXuatBan > NAM_HIEN_TAI) {
        loi = "Nam xuat ban khong hop le!";
        return false;
    }

    // Tu duy: Kiem tra tinh hop le van ban va cam dau '#' trong ten sach de bao ve maSach
    if (!HopLeVanBan(d.tenSach) || !HopLeVanBan(d.tacGia) || !HopLeVanBan(d.theLoai)) {
        loi = "Ten sach, tac gia hoac the loai khong hop le!";
        return false;
    }
    for (int i = 0; i < (int)d.tenSach.size(); ++i) {
        if (d.tenSach[i] == '#') {
            loi = "Ten sach khong duoc chua ky tu '#'!";
            return false;
        }
    }

    loi.clear();
    return true;
}

bool HopLeCuonSach(const CuonSach &s, string &loi) {
    // Tu duy: Ma sach khong duoc rong va chi chua ky tu ASCII in duoc, khong chua '|'
    if (LaChuoiRong(s.maSach)) {
        loi = "Ma sach khong duoc de trong!";
        return false;
    }
    for (int i = 0; i < (int)s.maSach.size(); ++i) {
        unsigned char c = (unsigned char)s.maSach[i];
        if (c == '|' || c == '\\' || c < 32 || c >= 127) {
            loi = "Ma sach chua ky tu khong hop le!";
            return false;
        }
    }

    // Tu duy: Trang thai phai thuoc tap {0: cho muon, 1: dang muon, 2: thanh ly}
    if (!HopLeTrangThaiSach(s.trangThai)) {
        loi = "Trang thai cuon sach khong hop le!";
        return false;
    }

    // Tu duy: Vi tri phai dung dinh dang Khu-Ke-Tang (VD: A-03-02, Khu A..Z, Ke/Tang 01..99)
    string vt = ChuanHoaChuoi(s.viTri);
    if ((int)vt.size() != 7 || vt[1] != '-' || vt[4] != '-') {
        loi = "Vi tri phai theo dinh dang Khu-Ke-Tang (VD: A-03-02)!";
        return false;
    }
    if (vt[0] < 'A' || vt[0] > 'Z') {
        loi = "Khu phai la chu cai in hoa tu A den Z!";
        return false;
    }
    if (vt[2] < '0' || vt[2] > '9' || vt[3] < '0' || vt[3] > '9' || (vt[2] == '0' && vt[3] == '0')) {
        loi = "Ke sach phai nam trong khoang 01 den 99!";
        return false;
    }
    if (vt[5] < '0' || vt[5] > '9' || vt[6] < '0' || vt[6] > '9' || (vt[5] == '0' && vt[6] == '0')) {
        loi = "Tang sach phai nam trong khoang 01 den 99!";
        return false;
    }

    loi.clear();
    return true;
}

int TimViTriChenTheoTen(const DanhSachDauSach &ds, const DauSach &d) {
    // Tu duy: Binary Search tim can duoi (lower_bound) de giu mang luon tang dan theo tenSach
    if (ds.soLuong < 0 || ds.soLuong > MAX_DAU_SACH) return -1;
    int l = 0, r = ds.soLuong;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (ds.ds[m] == nullptr) return -1;
        if (SoSanhChuoi(ds.ds[m]->tenSach, d.tenSach) < 0) l = m + 1;
        else r = m;
    }
    return l;
}

const DauSach *TimDauSachTheoISBN(const DanhSachDauSach &ds, const string &isbn) {
    // Tu duy: Chuan hoa ISBN dau vao ve 13 so roi quet mang con tro (vi mang sap xep theo ten)
    string isbnChuan = "";
    for (int i = 0; i < (int)isbn.size(); ++i) {
        char c = isbn[i];
        if (c != '-' && !KhoangTrang((unsigned char)c)) isbnChuan += c;
    }
    if ((int)isbnChuan.size() != 13) return nullptr;

    for (int i = 0; i < ds.soLuong; ++i) {
        if (ds.ds[i] != nullptr && ds.ds[i]->ISBN == isbnChuan) return ds.ds[i];
    }
    return nullptr;
}

DauSach *TimDauSachTheoISBN(DanhSachDauSach &ds, const string &isbn) {
    // Tu duy: Tai su dung ban const bang const_cast an toan, tranh lap lai ma nguon
    const DanhSachDauSach &cds = ds;
    return const_cast<DauSach *>(TimDauSachTheoISBN(cds, isbn));
}

bool ThemDauSach(ThuVien &tv, const DauSach &d, string &loi) {
    // Tu duy: Kiem tra suc chua, tinh nguyen ven va tinh hop le truoc khi cap phat dong
    if (tv.dsDauSach.soLuong >= MAX_DAU_SACH) {
        loi = "Danh sach dau sach da dat gioi han toi da!";
        return false;
    }
    if (d.dms != nullptr) {
        loi = "Dau sach moi khong duoc gan san danh muc cuon sach!";
        return false;
    }
    if (!HopLeDauSach(d, loi)) return false;

    // Tu duy: Tao ban sao da chuan hoa sach se de luu tru dong nhat trong bo nho
    DauSach banSao = d;
    banSao.ISBN = "";
    for (int i = 0; i < (int)d.ISBN.size(); ++i) {
        char c = d.ISBN[i];
        if (c != '-' && !KhoangTrang((unsigned char)c)) banSao.ISBN += c;
    }
    banSao.tenSach = ChuanHoaChuoi(d.tenSach);
    banSao.tacGia = ChuanHoaChuoi(d.tacGia);
    banSao.theLoai = ChuanHoaChuoi(d.theLoai);
    banSao.dms = nullptr;

    if (TimDauSachTheoISBN(tv.dsDauSach, banSao.ISBN) != nullptr) {
        loi = "Ma ISBN da ton tai trong thu vien!";
        return false;
    }

    int viTri = TimViTriChenTheoTen(tv.dsDauSach, banSao);
    if (viTri < 0) {
        loi = "Cau truc danh sach dau sach bi hong!";
        return false;
    }

    // Tu duy: Dich chuyen con tro tu cuoi lui ve viTri de khong ghi de dia chi cu
    DauSach *moi = new DauSach(banSao);
    for (int i = tv.dsDauSach.soLuong; i > viTri; --i) {
        tv.dsDauSach.ds[i] = tv.dsDauSach.ds[i - 1];
    }
    tv.dsDauSach.ds[viTri] = moi;
    ++tv.dsDauSach.soLuong;

    loi.clear();
    return true;
}

// ============================================================================
// PHAN 2: QUAN LY CUON SACH & SINH MA TU DONG (03_CuonSach.cpp)
// ============================================================================

const CuonSach *TimCuonSachTrongDauSach(const DauSach &d, const string &ma) {
    // Tu duy: Duyet danh sach lien ket don dms cua mot dau sach cu the
    string maChuan = ChuanHoaChuoi(ma);
    if (maChuan.empty()) return nullptr;

    const CuonSach *p = d.dms;
    int dem = 0;
    while (p != nullptr) {
        if (++dem > MAX_BAN_GHI) return nullptr;
        if (p->maSach == maChuan) return p;
        p = p->next;
    }
    return nullptr;
}

CuonSach *TimCuonSachTrongDauSach(DauSach &d, const string &ma) {
    const DauSach &cd = d;
    return const_cast<CuonSach *>(TimCuonSachTrongDauSach(cd, ma));
}

bool SinhMaSachTuDong(const ThuVien &tv, const DauSach &d, string &ma, string &loi) {
    // Tu duy: Dam bao dau sach hop le va da nam trong thu vien truoc khi cap ma
    if (!HopLeDauSach(d, loi)) return false;
    if (TimDauSachTheoISBN(tv.dsDauSach, d.ISBN) == nullptr) {
        loi = "Dau sach chua ton tai trong thu vien!";
        return false;
    }

    string tenChuan = ChuanHoaChuoi(d.tenSach);
    string isbnChuan = "";
    for (int i = 0; i < (int)d.ISBN.size(); ++i) {
        char c = d.ISBN[i];
        if (c != '-' && !KhoangTrang((unsigned char)c)) isbnChuan += c;
    }

    // Tu duy: Tim chi so N lon nhat trong dms (khong dung dem node vi node co the bi xoa)
    int maxN = 0;
    int demNode = 0;
    const CuonSach *p = d.dms;
    while (p != nullptr) {
        if (++demNode > MAX_BAN_GHI) {
            loi = "Danh muc cuon sach vuot gioi han hoac bi hong!";
            return false;
        }
        int posHash = -1;
        for (int i = (int)p->maSach.size() - 1; i >= 0; --i) {
            if (p->maSach[i] == '#') {
                posHash = i;
                break;
            }
        }
        if (posHash != -1 && posHash + 1 < (int)p->maSach.size()) {
            int val = 0;
            bool okSo = true;
            for (int i = posHash + 1; i < (int)p->maSach.size(); ++i) {
                char c = p->maSach[i];
                if (c < '0' || c > '9' || val > (SO_NGUYEN_LON_NHAT - (c - '0')) / 10) {
                    okSo = false;
                    break;
                }
                val = val * 10 + (c - '0');
            }
            if (okSo && val > maxN) maxN = val;
        }
        p = p->next;
    }

    if (maxN >= SO_NGUYEN_LON_NHAT) {
        loi = "Da dat gioi han chi so ma sach toi da!";
        return false;
    }

    // Tu duy: Chuyen nextN sang chuoi thu cong va ghep theo quy uoc tenSach#ISBN#N
    int nextN = maxN + 1;
    string chuoiN = "";
    int tmp = nextN;
    while (tmp > 0) {
        chuoiN = (char)('0' + (tmp % 10)) + chuoiN;
        tmp /= 10;
    }

    ma = tenChuan + "#" + isbnChuan + "#" + chuoiN;
    if (TimCuonSachTrongDauSach(d, ma) != nullptr) {
        loi = "Phat hien xung dot trung ma sach!";
        return false;
    }

    loi.clear();
    return true;
}

bool ThemCuonSach(ThuVien &tv, const string &isbn, const string &viTri, string &ma, string &loi) {
    // Tu duy: Xac dinh dau sach chu quan theo ISBN, sinh ma tu dong roi kiem tra vi tri
    DauSach *ds = TimDauSachTheoISBN(tv.dsDauSach, isbn);
    if (ds == nullptr) {
        loi = "Khong tim thay dau sach co ISBN tuong ung!";
        return false;
    }

    string maSinh;
    if (!SinhMaSachTuDong(tv, *ds, maSinh, loi)) return false;

    // Chuan hoa chu cai dau cua vi tri thanh in hoa (vd: a-03-02 -> A-03-02)
    string vtChuan = ChuanHoaChuoi(viTri);
    if (!vtChuan.empty() && vtChuan[0] >= 'a' && vtChuan[0] <= 'z') {
        vtChuan[0] = (char)(vtChuan[0] - 32);
    }

    CuonSach mau;
    mau.maSach = maSinh;
    mau.trangThai = SACH_CHO_MUON;
    mau.viTri = vtChuan;
    mau.next = nullptr;
    if (!HopLeCuonSach(mau, loi)) return false;

    // Tu duy: Cap phat node moi va noi vao cuoi dms de giu dung thu tu sinh ma #1 -> #2 -> #3
    CuonSach *node = new CuonSach(mau);
    if (ds->dms == nullptr) {
        ds->dms = node;
    } else {
        CuonSach *tail = ds->dms;
        int dem = 0;
        while (tail->next != nullptr) {
            if (++dem > MAX_BAN_GHI) {
                delete node;
                loi = "Danh muc cuon sach bi hong con tro!";
                return false;
            }
            tail = tail->next;
        }
        tail->next = node;
    }

    ma = maSinh;
    loi.clear();
    return true;
}

const CuonSach *TimCuonSachToanCuc(const ThuVien &tv, const string &ma, const DauSach **owner) {
    // Tu duy: Khoi tao owner = nullptr de dam bao an toan khi tim that bai
    if (owner != nullptr) *owner = nullptr;
    string maChuan = ChuanHoaChuoi(ma);
    if (maChuan.empty() || tv.dsDauSach.soLuong <= 0) return nullptr;

    // Tu duy: Quet nguoc tim 2 dau '#' cuoi cung de tach tenSach, ISBN va N
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

    // Tu duy: Neu la ma cu khong co 2 dau '#' (vd S001), chuyen sang quet tuan tu du phong
    if (hash1 <= 0 || hash2 <= hash1 + 1 || hash2 + 1 >= (int)maChuan.size()) {
        for (int i = 0; i < tv.dsDauSach.soLuong; ++i) {
            if (tv.dsDauSach.ds[i] == nullptr) continue;
            const CuonSach *cs = TimCuonSachTrongDauSach(*tv.dsDauSach.ds[i], maChuan);
            if (cs != nullptr) {
                if (owner != nullptr) *owner = tv.dsDauSach.ds[i];
                return cs;
            }
        }
        return nullptr;
    }

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

    // Tu duy: Binary Search theo tenSach tren mang dau sach da sap xep O(log M)
    int l = 0, r = tv.dsDauSach.soLuong - 1, mid = -1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (tv.dsDauSach.ds[m] == nullptr) return nullptr;
        int cmp = SoSanhChuoi(tv.dsDauSach.ds[m]->tenSach, tenTach);
        if (cmp == 0) {
            mid = m;
            break;
        }
        if (cmp < 0) l = m + 1;
        else r = m - 1;
    }
    if (mid == -1) return nullptr;

    // Tu duy: Quet lan can sang trai va phai trong cum dau sach trung ten de khop dung ISBN
    for (int i = mid; i >= 0; --i) {
        const DauSach *ds = tv.dsDauSach.ds[i];
        if (ds == nullptr || SoSanhChuoi(ds->tenSach, tenTach) != 0) break;
        if (ds->ISBN == isbnTach) {
            const CuonSach *cs = TimCuonSachTrongDauSach(*ds, maChuan);
            if (cs != nullptr) {
                if (owner != nullptr) *owner = ds;
                return cs;
            }
        }
    }
    for (int i = mid + 1; i < tv.dsDauSach.soLuong; ++i) {
        const DauSach *ds = tv.dsDauSach.ds[i];
        if (ds == nullptr || SoSanhChuoi(ds->tenSach, tenTach) != 0) break;
        if (ds->ISBN == isbnTach) {
            const CuonSach *cs = TimCuonSachTrongDauSach(*ds, maChuan);
            if (cs != nullptr) {
                if (owner != nullptr) *owner = ds;
                return cs;
            }
        }
    }
    return nullptr;
}

CuonSach *TimCuonSachToanCuc(ThuVien &tv, const string &ma, DauSach **owner) {
    const DauSach *constOwner = nullptr;
    const ThuVien &ctv = tv;
    const CuonSach *res = TimCuonSachToanCuc(ctv, ma, owner != nullptr ? &constOwner : nullptr);
    if (owner != nullptr) *owner = const_cast<DauSach *>(constOwner);
    return const_cast<CuonSach *>(res);
}

// ============================================================================
// PHAN 3: GIAO DIEN NHAP DAU SACH & BAN SAO (02_DauSach.cpp - Tang UI)
// ============================================================================

void ManHinhNhapDauSach(ThuVien &tv) {
    if (tv.dsDauSach.soLuong >= MAX_DAU_SACH) {
        ThongBao("Danh sach dau sach da day, khong the them moi!");
        return;
    }

    const char *nhan[6] = {
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

    // Tu duy: Vong lap bieu mau giu lai du lieu cu khi nhap sai de thu thu sua nhanh
    while (true) {
        if (!NhapBieuMau("NHAP THONG TIN DAU SACH", nhan, giaTri, 6)) return;

        d = DauSach();
        d.ISBN = ChuanHoaChuoi(giaTri[0]);
        d.tenSach = ChuanHoaChuoi(giaTri[1]);
        d.tacGia = ChuanHoaChuoi(giaTri[3]);
        d.theLoai = ChuanHoaChuoi(giaTri[5]);

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

        // Tu duy: Neu trung ISBN, cho phep nhap them ban sao vao dau sach san co
        const DauSach *daCo = TimDauSachTheoISBN(tv.dsDauSach, d.ISBN);
        if (daCo != nullptr) {
            const char *menuTrung[2] = {
                "Nhap them ban sao cho dau sach nay",
                "Quay lai sua bieu mau"
            };
            if (ChonMenu("ISBN DA TON TAI: " + daCo->tenSach, menuTrung, 2) == 0) {
                laDauSachMoi = false;
                break;
            }
            continue;
        }

        if (!ThemDauSach(tv, d, loi)) {
            ThongBao(loi);
            continue;
        }
        break;
    }

    // Tu duy: Nhap so luong ban sao va tu dong cap maSach = tenSach#ISBN#N cho tung cuon
    int soCuon = 0;
    if (!NhapSo("Nhap so luong ban sao nhap kho (0 de bo qua): ", soCuon, 0, 1000) || soCuon == 0) {
        if (laDauSachMoi) ThongBao("Da luu dau sach moi (0 ban sao).");
        return;
    }

    int daThem = 0;
    string dsMa = "";
    for (int k = 1; k <= soCuon; ++k) {
        string stt = "";
        int tmp = k;
        while (tmp > 0) {
            stt = (char)('0' + (tmp % 10)) + stt;
            tmp /= 10;
        }

        while (true) {
            string viTri;
            if (!NhapDong("Vi tri cuon #" + stt + " (VD: A-03-02, /huy de dung): ", viTri)) {
                k = soCuon + 1;
                break;
            }
            string maMoi, loiCuon;
            if (ThemCuonSach(tv, d.ISBN, viTri, maMoi, loiCuon)) {
                ++daThem;
                if (daThem <= 6) {
                    if (!dsMa.empty()) dsMa += " | ";
                    dsMa += maMoi;
                } else if (daThem == 7) {
                    dsMa += " | ...";
                }
                break;
            }
            ThongBao(loiCuon);
        }
    }

    if (daThem > 0) ThongBao("Thanh cong! Ma sach da cap: " + dsMa);
    else if (laDauSachMoi) ThongBao("Da luu dau sach moi, chua them ban sao nao.");
}