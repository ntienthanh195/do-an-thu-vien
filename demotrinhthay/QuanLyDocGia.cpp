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
// Them va xoa tren cay AVL theo ma the.
static NutDocGia* XoayTrai(NutDocGia* root)
{
    NutDocGia* rootMoi = root->right;

    root->right = rootMoi->left;
    rootMoi->left = root;

    // Cap nhat chieu cao goc cu truoc
    if (root->left == nullptr && root->right == nullptr)
    {
        root->height = 1;
    }
    else if (root->left == nullptr)
    {
        root->height = root->right->height + 1;
    }
    else if (root->right == nullptr)
    {
        root->height = root->left->height + 1;
    }
    else if (root->left->height >= root->right->height)
    {
        root->height = root->left->height + 1;
    }
    else
    {
        root->height = root->right->height + 1;
    }

    // Sau do cap nhat chieu cao goc moi
    if (rootMoi->left == nullptr && rootMoi->right == nullptr)
    {
        rootMoi->height = 1;
    }
    else if (rootMoi->left == nullptr)
    {
        rootMoi->height = rootMoi->right->height + 1;
    }
    else if (rootMoi->right == nullptr)
    {
        rootMoi->height = rootMoi->left->height + 1;
    }
    else if (rootMoi->left->height >= rootMoi->right->height)
    {
        rootMoi->height = rootMoi->left->height + 1;
    }
    else
    {
        rootMoi->height = rootMoi->right->height + 1;
    }

    return rootMoi;
}

static NutDocGia* XoayPhai(NutDocGia* root)
{
    NutDocGia* rootMoi = root->left;

    root->left = rootMoi->right;
    rootMoi->right = root;

    // Cap nhat chieu cao goc cu truoc
    if (root->left == nullptr && root->right == nullptr)
    {
        root->height = 1;
    }
    else if (root->left == nullptr)
    {
        root->height = root->right->height + 1;
    }
    else if (root->right == nullptr)
    {
        root->height = root->left->height + 1;
    }
    else if (root->left->height >= root->right->height)
    {
        root->height = root->left->height + 1;
    }
    else
    {
        root->height = root->right->height + 1;
    }

    // Sau do cap nhat chieu cao goc moi
    if (rootMoi->left == nullptr && rootMoi->right == nullptr)
    {
        rootMoi->height = 1;
    }
    else if (rootMoi->left == nullptr)
    {
        rootMoi->height = rootMoi->right->height + 1;
    }
    else if (rootMoi->right == nullptr)
    {
        rootMoi->height = rootMoi->left->height + 1;
    }
    else if (rootMoi->left->height >= rootMoi->right->height)
    {
        rootMoi->height = rootMoi->left->height + 1;
    }
    else
    {
        rootMoi->height = rootMoi->right->height + 1;
    }

    return rootMoi;
}

static NutDocGia* ThemDocGiaAVL(NutDocGia* root, const DocGia &docgiamoi)
{
    if (root == nullptr)
    {
        NutDocGia* p = new NutDocGia;
        p->thongTin = docgiamoi;
        return p;
    }

    if (docgiamoi.maThe < root->thongTin.maThe)
    {
        root->left = ThemDocGiaAVL(root->left, docgiamoi);
    }
    else if (docgiamoi.maThe > root->thongTin.maThe)
    {
        root->right = ThemDocGiaAVL(root->right, docgiamoi);
    }
    else
    {
        cout << "Da co san";
        return root;
    }

    if (root->left == nullptr && root->right == nullptr)
    {
        root->height = 1;
    }
    else if (root->left == nullptr)
    {
        root->height = root->right->height + 1;
    }
    else if (root->right == nullptr)
    {
        root->height = root->left->height + 1;
    }
    else if (root->left->height >= root->right->height)
    {
        root->height = root->left->height + 1;
    }
    else
    {
        root->height = root->right->height + 1;
    }


    int caoTrai = 0;
    int caoPhai = 0;

if (root->left != nullptr)
{
    caoTrai = root->left->height;
}

if (root->right != nullptr)
{
    caoPhai = root->right->height;
}

    int heSoCanBang = caoTrai - caoPhai;


    if (heSoCanBang > 1)
    {
        if (docgiamoi.maThe > root->left->thongTin.maThe)
        {
        root->left = XoayTrai(root->left);
        }

        return XoayPhai(root);
    }



    if (heSoCanBang < -1)
{
    if (docgiamoi.maThe < root->right->thongTin.maThe)
    {

        root->right = XoayPhai(root->right);
    }

    return XoayTrai(root);
}

return root;

}

void them_cay(CayDocGia &caydocgia, const DocGia &docGiaMoi)
{
    caydocgia.root = ThemDocGiaAVL(caydocgia.root, docGiaMoi);
}

static NutDocGia* CanBangLai(NutDocGia* root)
{
    if (root == nullptr)
        return nullptr;

    int caoTrai = 0;
    int caoPhai = 0;

    if (root->left != nullptr)
        caoTrai = root->left->height;

    if (root->right != nullptr)
        caoPhai = root->right->height;

    if (caoTrai >= caoPhai)
        root->height = caoTrai + 1;
    else
        root->height = caoPhai + 1;

    int heSoCanBang = caoTrai - caoPhai;

    if (heSoCanBang > 1)
    {
        NutDocGia* conTrai = root->left;
        int caoTraiCuaCon = 0;
        int caoPhaiCuaCon = 0;

        if (conTrai->left != nullptr)
            caoTraiCuaCon = conTrai->left->height;

        if (conTrai->right != nullptr)
            caoPhaiCuaCon = conTrai->right->height;

        if (caoPhaiCuaCon > caoTraiCuaCon)
            root->left = XoayTrai(conTrai);

        return XoayPhai(root);
    }

    if (heSoCanBang < -1)
    {
        NutDocGia* conPhai = root->right;
        int caoTraiCuaCon = 0;
        int caoPhaiCuaCon = 0;

        if (conPhai->left != nullptr)
            caoTraiCuaCon = conPhai->left->height;

        if (conPhai->right != nullptr)
            caoPhaiCuaCon = conPhai->right->height;

        if (caoTraiCuaCon > caoPhaiCuaCon)
            root->right = XoayPhai(conPhai);

        return XoayTrai(root);
    }

    return root;
}

static NutDocGia* TachNutNhoNhat(NutDocGia* root, NutDocGia* &nutNhoNhat)
{
    if (root == nullptr)
    {
        nutNhoNhat = nullptr;
        return nullptr;
    }

    if (root->left == nullptr)
    {
        nutNhoNhat = root;

        NutDocGia* conPhai = root->right;
        nutNhoNhat->right = nullptr;

        return conPhai;
    }

    root->left = TachNutNhoNhat(root->left, nutNhoNhat);
    return CanBangLai(root);
}

static NutDocGia* XoaNutAVL(NutDocGia* root, int mathe)
{
    if (root == nullptr)
        return nullptr;

    if (mathe < root->thongTin.maThe)
    {
        root->left = XoaNutAVL(root->left, mathe);
    }
    else if (mathe > root->thongTin.maThe)
    {
        root->right = XoaNutAVL(root->right, mathe);
    }
    else
    {
        NutDocGia* p = root;

        // Nút lá
        if (p->left == nullptr && p->right == nullptr)
        {
            delete p;
            return nullptr;
        }

        // Chỉ có con trái
        if (p->right == nullptr)
        {
            NutDocGia* con = p->left;
            delete p;
            return con;
        }

        // Chỉ có con phải
        if (p->left == nullptr)
        {
            NutDocGia* con = p->right;
            delete p;
            return con;
        }

        // Có đủ hai con
        NutDocGia* nutThayThe = nullptr;
        NutDocGia* nhanhPhaiConLai =
            TachNutNhoNhat(p->right, nutThayThe);

        nutThayThe->left = p->left;
        nutThayThe->right = nhanhPhaiConLai;

        root = nutThayThe;
        delete p;
    }

    return CanBangLai(root);
}

void XoaDocGia(CayDocGia &caydocgia, int mathe)
{
    NutDocGia* p = tim_cay(caydocgia, mathe);

    if (p == nullptr)
    {
        cout << "\nKhong tim thay doc gia";
    }
    else if (p->thongTin.dsMuonTra != nullptr)
    {
        cout << "\nThe da co lich su muon tra, khong the xoa";
    }
    else
    {
        caydocgia.root = XoaNutAVL(caydocgia.root, mathe);
    }
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

// [THANH] Hieu chinh thong tin the va cap ma the tiep theo.
bool HieuChinhDocGia(CayDocGia &caydocgia, int mathe,
                    string Ho, string Ten, string Phai,
                    int trangthaiThe)
{
    NutDocGia* p = tim_cay(caydocgia, mathe);

    if (p == nullptr)
    {
        return false;
    }

    p->thongTin.ho = Ho;
    p->thongTin.ten = Ten;
    p->thongTin.phai = Phai;
    p->thongTin.trangThaiThe = trangthaiThe;

    return true;
}

int SinhMaTheTiepTheo(int &maTheDaCap)
{
    maTheDaCap = maTheDaCap + 1;
    return maTheDaCap;
}
