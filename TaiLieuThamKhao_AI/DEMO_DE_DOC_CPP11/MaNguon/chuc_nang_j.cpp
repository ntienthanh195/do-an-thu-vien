#include "00_KhaiBaoChung.h"

// B1 : TIEN ICH CHUOI
// So sanh 2 chuoi theo kieu alphabet, khong phan biet hoa thuong (ASCII).
// Tra ve: -1 neu a < b, 0 neu a == b, 1 neu a > b.
// Khong dung STL compare/strcmp, khong cap phat bo nho.
int SoSanhChuoi(const string &a, const string &b) {
    int n = (int)a.size();
    int m = (int)b.size();
    int i = 0;
    while (i < n && i < m) {
        char ca = a[i];
        char cb = b[i];
        // ha hoa A-Z, chi ASCII
        if (ca >= 'A' && ca <= 'Z') ca = (char)(ca + 32);
        if (cb >= 'A' && cb <= 'Z') cb = (char)(cb + 32);
        if (ca < cb) return -1;
        if (ca > cb) return 1;
        ++i;
    }
    if (n < m) return -1;
    if (n > m) return 1;
    return 0;
}

// B2 : THAO TAC DANH MUC SACH
// Dem so cuon sach trong danh sach lien ket don.
// Khong thay doi con tro next cua bat ky node nao.
int DemCuonSach(const CuonSach *head) {
    int dem = 0;
    const CuonSach *p = head;
    while (p != nullptr) {
        ++dem;
        p = p->next;
    }
    return dem;
}

// B3 : DUYET BST 
// Duyet in-order (trai - nut - phai) de dem so nut.
static void DuyetGiuaDem(const NutDocGia *p, int &dem) {
    if (p == nullptr) return;
    DuyetGiuaDem(p->left, dem);
    ++dem;
    DuyetGiuaDem(p->right, dem);
}

// Duyet in-order, ghi con tro nut vao out[] theo thu tu ma the tang dan.
// Dung khi idx >= capacity de khong ghi vuot va khong duyet thua.
static void DuyetGiuaThuThap(const NutDocGia *p, const NutDocGia **out,
                             int capacity, int &idx) {
    if (p == nullptr || idx >= capacity) return;
    DuyetGiuaThuThap(p->left, out, capacity, idx);
    if (idx < capacity) {
        out[idx] = p;
        ++idx;
    }
    DuyetGiuaThuThap(p->right, out, capacity, idx);
}

// Dem toan bo doc gia trong BST. Rong tra ve 0.
int DemDocGia(const CayDocGia &tree) {
    int dem = 0;
    DuyetGiuaDem(tree.root, dem);
    return dem;
}

// Thu thap con tro cac nut vao out[] theo ma the tang dan.
// Tra ve so con tro da ghi (toi da la capacity).
int LayDanhSachDocGia(const CayDocGia &tree, const NutDocGia **out, int capacity) {
    if (out == nullptr || capacity <= 0) return 0;
    int idx = 0;
    DuyetGiuaThuThap(tree.root, out, capacity, idx);
    return idx;
}

