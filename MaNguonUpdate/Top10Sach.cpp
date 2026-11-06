#include "00_KhaiBaoChung.h"

// [THAI] Chuyen tu be7fa70, chuc nang j: cac ham ho tro da co trong ban Thai gui.
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
