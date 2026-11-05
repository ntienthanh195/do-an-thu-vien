#include "00_KhaiBaoChung.h"

// B1 : XU LY NGAY THANG
// Helper: Kiem tra nam nhuan
static bool LaNamNhuan(int nam) {
    return (nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0);
}

// Helper: Tra ve so ngay cua mot thang cu the
static int SoNgayTrongThang(int thang, int nam) {
    if (thang == 4 || thang == 6 || thang == 9 || thang == 11) {
        return 30;
    }
    if (thang == 2) {
        return LaNamNhuan(nam) ? 29 : 28;
    }
    return 31;
}

// Kiem tra tinh hop le cua mot ngay thang
bool NgayHopLe(const NgayThang &d) {
    if (d.nam <= 0) return false;
    if (d.thang < 1 || d.thang > 12) return false;
    if (d.ngay < 1 || d.ngay > SoNgayTrongThang(d.thang, d.nam)) return false;
    return true;
}

// Chuyen ngay thang thanh so thu tu (tinh tu 01/01/0001)
int SoThuTuNgay(const NgayThang &d) {
    int nam = d.nam - 1;
    // Tinh tong so ngay cua cac nam truoc do
    int ngay = nam * 365 + nam / 4 - nam / 100 + nam / 400;

    // Tinh tong so ngay cua cac thang truoc do trong nam hien tai
    for (int i = 1; i < d.thang; ++i) {
        ngay += SoNgayTrongThang(i, d.nam);
    }

    // Cong them ngay hien tai
    ngay += d.ngay;
    return ngay;
}

// Tinh khoang cach giua 2 ngay (b - a)
int KhoangCachNgay(const NgayThang &a, const NgayThang &b) {
    return SoThuTuNgay(b) - SoThuTuNgay(a);
}

// Kiem tra xem sach da qua han 7 ngay chua
bool QuaHan7Ngay(const NgayThang &ngayMuon, const NgayThang &now) {
    if (!NgayHopLe(ngayMuon) || !NgayHopLe(now)) {
        return false; // Ngay khong hop le thi coi nhu khong the xu ly qua han
    }
    int khoangCach = KhoangCachNgay(ngayMuon, now);
    return khoangCach > 7;
}

// B2 : DUYET BST
// Helper: Dem so nut trong cay
static int DemNut(const NutDocGia *node) {
    if (node == nullptr) return 0;
    return 1 + DemNut(node->left) + DemNut(node->right);
}

// Helper: Duyet In-order (Left - Root - Right) va ghi vao mang
static void DuyetLNR(const NutDocGia *node, const NutDocGia **out, int capacity, int &count) {
    if (node == nullptr || count >= capacity) return;
    
    DuyetLNR(node->left, out, capacity, count);
    
    if (count < capacity) {
        out[count] = node;
        ++count;
    }
    
    DuyetLNR(node->right, out, capacity, count);
}

// Dem tong so doc gia trong cay
int DemDocGia(const CayDocGia &tree) {
    return DemNut(tree.root);
}

// Lay danh sach con tro doc gia vao mang out
int LayDanhSachDocGia(const CayDocGia &tree, const NutDocGia **out, int capacity) {
    int count = 0;
    if (capacity > 0 && out != nullptr) {
        DuyetLNR(tree.root, out, capacity, count);
    }
    return count;
}

// B3 : KIEM TRA QUA HAN 
// Tinh so ngay qua han lon nhat cua doc gia (neu co)
// Tra ve 0 neu khong co sach nao qua han hoac danh sach rong
int SoNgayQuaHanLonNhat(const DocGia &dg, const NgayThang &now) {
    if (!NgayHopLe(now)) return 0;
    
    int maxQuaHan = 0;
    const MuonTra *p = dg.dsMuonTra;
    
    while (p != nullptr) {
        // Chi xet nhung sach dang muon (chua tra, chua mat)
        if (p->trangThai == MUON_DANG_MUON) {
            if (NgayHopLe(p->ngayMuon)) {
                int khoangCach = KhoangCachNgay(p->ngayMuon, now);
                
                // Mượn quá 7 ngày mới tính là quá hạn
                if (khoangCach > 7) {
                    int soNgayQuaHan = khoangCach - 7;
                    if (soNgayQuaHan > maxQuaHan) {
                        maxQuaHan = soNgayQuaHan;
                    }
                }
            }
        }
        p = p->next;
    }
    
    return maxQuaHan;
}

// Kiem tra doc gia co sach qua han 7 ngay khong
bool CoSachQuaHan7Ngay(const DocGia &dg, const NgayThang &now) {
    return SoNgayQuaHanLonNhat(dg, now) > 0;
}

// B4 : HOAN THIEN HEAPSORT
// Helper: Kiem tra a co dung truoc b trong mang ket qua khong
static bool LaLonHon(const NutDocGia *a, const NutDocGia *b, const NgayThang &now) {
    int qa = SoNgayQuaHanLonNhat(a->thongTin, now);
    int qb = SoNgayQuaHanLonNhat(b->thongTin, now);
    
    if (qa != qb) {
        return qa > qb; // Qua han giam dan
    }
    // Neu qua han bang nhau, uu tien ma the tang dan
    return a->thongTin.maThe < b->thongTin.maThe;
}

// Helper: Hoan vi 2 con tro
static void HoanVi(const NutDocGia **a, const NutDocGia **b) {
    const NutDocGia *temp = *a;
    *a = *b;
    *b = temp;
}

// Helper: Vun dong tai nut i (Max-Heap theo tieu chi LaLonHon)
static void VunDong(const NutDocGia **ds, int n, int i, const NgayThang &now) {
    int lonNhat = i;
    int trai = 2 * i + 1;
    int phai = 2 * i + 2;

    if (trai < n && LaLonHon(ds[trai], ds[lonNhat], now)) {
        lonNhat = trai;
    }
    if (phai < n && LaLonHon(ds[phai], ds[lonNhat], now)) {
        lonNhat = phai;
    }
    if (lonNhat != i) {
        HoanVi(&ds[i], &ds[lonNhat]);
        VunDong(ds, n, lonNhat, now);
    }
}

// Ham chinh: Sap xep mang con tro doc gia qua han
void HeapSortDocGiaQuaHan(const NutDocGia **ds, int n, const NgayThang &now) {
    if (ds == nullptr || n <= 1) return;

    // 1. Xay dung Max-Heap
    for (int i = n / 2 - 1; i >= 0; --i) {
        VunDong(ds, n, i, now);
    }

    // 2. Sap xep
    for (int i = n - 1; i > 0; --i) {
        HoanVi(&ds[0], &ds[i]);
        VunDong(ds, i, 0, now);
    }
}

// B5 : TICH HOP HAM THONG KE CHINH 
void InDocGiaQuaHan(const ThuVien &tv, const NgayThang &ngay, ostream &out) {
    int tongDocGia = DemDocGia(tv.cayDocGia);
    if (tongDocGia == 0) {
        out << "Thu vien chua co doc gia nao.\n";
        return;
    }

    // Cap phat mang tam de chua con tro doc gia
    const NutDocGia **mangTam = new const NutDocGia*[tongDocGia];
    
    // Lay danh sach doc gia vao mang tam
    int soLuongThucTe = LayDanhSachDocGia(tv.cayDocGia, mangTam, tongDocGia);
    if (soLuongThucTe == 0) {
        delete[] mangTam;
        out << "Khong the lay danh sach doc gia.\n";
        return;
    }

    // Sap xep mang theo so ngay qua han giam dan
    HeapSortDocGiaQuaHan(mangTam, soLuongThucTe, ngay);

    out << "--- DANH SACH DOC GIA QUA HAN ---\n";
    int demQuaHan = 0;
    
    // Duyet mang da sap xep va in ra nhung nguoi qua han
    for (int i = 0; i < soLuongThucTe; ++i) {
        const NutDocGia *nut = mangTam[i];
        int soNgayQuaHan = SoNgayQuaHanLonNhat(nut->thongTin, ngay);
        
        if (soNgayQuaHan > 0) {
            ++demQuaHan;
            out << demQuaHan << ". Ma the: " << nut->thongTin.maThe
                << " | Ho ten: " << nut->thongTin.ho << " " << nut->thongTin.ten
                << " | Qua han: " << soNgayQuaHan << " ngay\n";
        } else {
            // Vi mang da sap xep giam dan, nhung nguoi con lai se khong qua han
            break;
        }
    }

    if (demQuaHan == 0) {
        out << "Khong co doc gia nao qua han.\n";
    }

    // Giai phong bo nho
    delete[] mangTam;
}