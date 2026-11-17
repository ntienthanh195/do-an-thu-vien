#include "00_KhaiBaoChung.h"

/* ============================================================
   10. CAU TRUC DU LIEU: CAY DOC GIA (cay nhi phan tim kiem, giu can bang theo AVL)
   File nay chi chua cac thao tac tren cay. Man hinh them/xoa/hieu chinh nam o a_QuanLyDocGia.cpp.

   Danh sach the doc gia la cay nhi phan tim kiem, khoa la ma the.

   Ma the do chuong trinh cap tang dan (ma lon nhat + 1). Voi cay nhi phan tim kiem thuong,
   khoa tang dan lam nut moi luon nam ben phai, cay lech thanh danh sach lien ket va tim kiem
   mat O(n). Vi vay cay duoc giu can bang theo AVL: moi nut co them truong height (chieu cao
   cua nut) de tinh he so can bang = cao trai - cao phai trong O(1). Sau moi lan them/xoa,
   neu he so vuot qua 1 hoac nho hon -1 thi xoay trai / xoay phai de can bang lai.
   Nho do tim, them, xoa luon la O(log n).
   ============================================================ */

// [THANH] Phan code Thanh cung cap/phu trach.
// @TT [a,f,g,h] Tim doc gia theo ma the: tim kiem tren cay nhi phan tim kiem bang vong lap - O(log n) vi cay AVL can bang
NutDocGia* tim_cay(CayDocGia &caydocgia, int x)
{
    NutDocGia* p = caydocgia;

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
// @TT [a] Xoay trai: con phai len lam goc, cap nhat height goc cu roi goc moi - O(1)
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

// @TT [a] Xoay phai: con trai len lam goc, cap nhat height goc cu roi goc moi - O(1)
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

// @TT [a] Them doc gia: chen de quy nhu BST, tren duong quay lui cap nhat height,
//         he so can bang > 1 / < -1 thi xoay (LL, LR, RR, RL) - O(log n)
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
        // trung ma the: khong them, giu nguyen cay
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

// [THANH] Them mot doc gia vao cay AVL. Tra ve false neu ma the da co.
bool them_cay(CayDocGia &caydocgia, const DocGia &docGiaMoi)
{
    if (tim_cay(caydocgia, docGiaMoi.maThe) != nullptr)
        return false;
    caydocgia = ThemDocGiaAVL(caydocgia, docGiaMoi);
    return true;
}

// @TT [a] Can bang lai mot nut sau khi xoa: tinh he so can bang, chon xoay don hay xoay kep
//         theo chieu cao hai cay con cua nut con
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

// @TT [a] Tach nut nho nhat (trai cung) cua cay con phai, dung khi xoa nut co 2 con
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

// @TT [a] Xoa doc gia: xoa nut BST 3 truong hop (la / 1 con / 2 con -> thay bang nut nho nhat
//         cua cay con phai), can bang lai tren duong quay lui - O(log n)
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

// [THANH] Chi xoa the chua tung muon sach, de khong mat lich su muon tra
// (lich su con dung cho thong ke top 10 va kiem tra qua han).
// @TT [a] Dieu kien xoa the: chi xoa the chua co lich su muon tra
bool XoaDocGia(CayDocGia &caydocgia, int mathe, string &loi)
{
    NutDocGia* p = tim_cay(caydocgia, mathe);

    if (p == nullptr)
    {
        loi = "Không tìm thấy độc giả.";
        return false;
    }
    else if (p->thongTin.dsMuonTra != nullptr)
    {
        loi = "Thẻ đã có lịch sử mượn trả, không thể xóa (có thể khóa thẻ).";
        return false;
    }

    caydocgia = XoaNutAVL(caydocgia, mathe);
    return true;
}

// [THANH]
bool HieuChinhDocGia(CayDocGia &caydocgia, int mathe, string Ho, string Ten, string Phai,
                     int trangthaiThe)
{
    NutDocGia *p = tim_cay(caydocgia, mathe);
    if (p == nullptr)
        return false;

    p->thongTin.ho = Ho;
    p->thongTin.ten = Ten;
    p->thongTin.phai = Phai;
    p->thongTin.trangThaiThe = trangthaiThe;
    return true;
}

// Ma the lon nhat dang co = nut ngoai cung ben phai cua cay. Cay rong tra ve 0.
// @TT [a] Cap ma the moi = ma lon nhat + 1; ma lon nhat la nut phai cung cua cay - O(log n)
int MaTheLonNhat(CayDocGia caydocgia)
{
    if (caydocgia == nullptr)
        return 0;
    while (caydocgia->right != nullptr)
        caydocgia = caydocgia->right;
    return caydocgia->thongTin.maThe;
}

// [THANH] Cap ma the tiep theo tu moc ma da cap.
int SinhMaTheTiepTheo(int &maTheDaCap)
{
    maTheDaCap = maTheDaCap + 1;
    return maTheDaCap;
}

// [THANH] Huy cay theo thu tu sau (LRN): huy hai cay con truoc roi moi huy nut goc.
// @TT Huy cay doc gia: duyet sau (LRN), huy ca DSLK muon tra cua tung nut
void Huydocgia(NutDocGia *&nutdocgia)
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

// [THANH]
void HuyCayDocGia(CayDocGia &caydocgia)
{
    Huydocgia(caydocgia);
}

/* ===================== DUYET CAY RA MANG TAM (dung cho b, i, j, Tong quan) ===================== */

// [THAI] Duyet giua (trai - nut - phai) de dem so nut.
// @TT [b,i,j] Dem so doc gia: duyet giua LNR - O(n)
static void DuyetGiuaDem(const NutDocGia *p, int &dem)
{
    if (p == nullptr) return;
    DuyetGiuaDem(p->left, dem);
    ++dem;
    DuyetGiuaDem(p->right, dem);
}

// [THAI] Duyet giua, ghi con tro nut vao out[] theo thu tu ma the tang dan.
// Dung khi idx >= capacity de khong ghi vuot mang.
// @TT [b,i,j] Do con tro cac nut ra mang tam: duyet giua LNR nen mang tang dan theo ma the - O(n)
static void DuyetGiuaThuThap(NutDocGia *p, NutDocGia **out, int capacity, int &idx)
{
    if (p == nullptr || idx >= capacity) return;
    DuyetGiuaThuThap(p->left, out, capacity, idx);
    if (idx < capacity)
    {
        out[idx] = p;
        ++idx;
    }
    DuyetGiuaThuThap(p->right, out, capacity, idx);
}

// [THAI] Dem toan bo doc gia trong cay. Cay rong tra ve 0.
int DemDocGia(CayDocGia tree)
{
    int dem = 0;
    DuyetGiuaDem(tree, dem);
    return dem;
}

// [THAI] Thu thap con tro cac nut vao out[] theo ma the tang dan.
// Tra ve so con tro da ghi (toi da la capacity).
int LayDanhSachDocGia(CayDocGia tree, NutDocGia **out, int capacity)
{
    if (out == nullptr || capacity <= 0) return 0;
    int idx = 0;
    DuyetGiuaThuThap(tree, out, capacity, idx);
    return idx;
}
