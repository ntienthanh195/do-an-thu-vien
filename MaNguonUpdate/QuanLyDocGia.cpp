#include "00_KhaiBaoChung.h"
#include <iostream>

// [THANH] Chuyen tu ban Thanh gui ngay 01/11/2026, giu nguyen logic.

// [THANH] Phan code Thanh cung cap/phu trach.
NutDocGia* tim_cay(CayDocGia &caydocgia, int x)
{
    NutDocGia* p = caydocgia.root;

    while (p != nullptr)
    {
        if (x < p->thongTin.maThe)
            p = p->left;
        else if (x > p->thongTin.maThe)
            p = p->right;
        else if (x == p->thongTin.maThe)
            return p;
    }

    return nullptr;
}

// [THANH] Phan code Thanh cung cap/phu trach.
void them_cay(CayDocGia &caydocgia, const DocGia &docGiaMoi)
{
    NutDocGia* cha = nullptr;
    NutDocGia* p = caydocgia.root;

    while (p != nullptr)
    {
        cha = p;

        if (docGiaMoi.maThe < p->thongTin.maThe)
            p = p->left;
        else if (docGiaMoi.maThe > p->thongTin.maThe)
            p = p->right;
        else if (docGiaMoi.maThe == p->thongTin.maThe)
        {
            cout << "Da co san";
            return;
        }
    }

    p = new NutDocGia;
    p->thongTin = docGiaMoi;

    if (cha == nullptr)
        caydocgia.root = p;
    else if (docGiaMoi.maThe < cha->thongTin.maThe)
        cha->left = p;
    else
        cha->right = p;
}

// [THANH] Phan code Thanh cung cap/phu trach.
// Nguon: mau AI ho tro trong chat hoc, duoc Thanh dua vao ban ban giao.
void Huydocgia(NutDocGia* &nutdocgia)
{
    if (nutdocgia != nullptr)
    {
        
        Huydocgia(nutdocgia->left);
        Huydocgia(nutdocgia->right);

        
        HuyDanhSachMuonTra(*nutdocgia);

        
        delete nutdocgia;
        nutdocgia = nullptr;
    }
}

// [THANH] Phan code Thanh cung cap/phu trach.
// Nguon: mau AI ho tro trong chat hoc, duoc Thanh dua vao ban ban giao.
void HuyCayDocGia(CayDocGia &caydocgia)
{
    Huydocgia(caydocgia.root);
}
