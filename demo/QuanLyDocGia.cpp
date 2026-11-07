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
        try
        {
            p->thongTin = docgiamoi;
        }
        catch (...)
        {
            delete p;
            throw;
        }
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

        // Nut la
        if (p->left == nullptr && p->right == nullptr)
        {
            delete p;
            return nullptr;
        }

        // Chi co con trai
        if (p->right == nullptr)
        {
            NutDocGia* con = p->left;
            delete p;
            return con;
        }

        // Chi co con phai
        if (p->left == nullptr)
        {
            NutDocGia* con = p->right;
            delete p;
            return con;
        }

        // Co du hai con
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

// [DEMO - CODEX] Phan bo sung cho ban trinh thay.
NutDocGia *TimDocGia(CayDocGia &cay, int ma)
{
    return tim_cay(cay, ma);
}
const NutDocGia *TimDocGia(const CayDocGia &cay, int ma)
{
    const NutDocGia *p = cay.root;
    while (p != nullptr)
    {
        if (ma < p->thongTin.maThe)
        {
            p = p->left;
        }
        else if (ma > p->thongTin.maThe)
        {
            p = p->right;
        }
        else
        {
            return p;
        }
    }
    return nullptr;
}
int LayDanhSachDocGia(const CayDocGia &cay, const NutDocGia **ketQua, int sucChua)
{
    // Ngan xep mang tu cai: tranh de quy sau khi cay bi lech.
    const NutDocGia **nganXep = new const NutDocGia *[MAX_DOC_GIA];
    int soNutCho = 0, soDocGia = 0;
    const NutDocGia *p = cay.root;
    try
    {
        while (p != nullptr || soNutCho > 0)
        {
            while (p != nullptr)
            {
                if (soNutCho == MAX_DOC_GIA)
                {
                    throw LoiThuVien("Cay vuot gioi han.");
                }
                nganXep[soNutCho] = p;
                soNutCho++;
                p = p->left;
            }
            soNutCho--;
            p = nganXep[soNutCho];
            if (soDocGia == MAX_DOC_GIA)
            {
                throw LoiThuVien("Cay vuot gioi han.");
            }
            if (ketQua != nullptr)
            {
                if (soDocGia >= sucChua)
                {
                    throw LoiThuVien("Mang ket qua khong du cho.");
                }
                ketQua[soDocGia] = p;
            }
            soDocGia++;
            p = p->right;
        }
        delete[] nganXep;
        return soDocGia;
    }
    catch (...)
    {
        delete[] nganXep;
        throw;
    }
}
int DemDocGia(const CayDocGia &cay)
{
    return LayDanhSachDocGia(cay, nullptr, 0);
}
bool ThongTinTheHopLe(const string &ho, const string &ten, const string &phai, int trangThai,
                      string &loi)
{
    if (!HopLeVanBan(ho) || !HopLeVanBan(ten))
    {
        loi = "Ho/ten khong hop le.";
        return false;
    }
    if (!HopLePhai(phai))
    {
        loi = "Phai chi nhan Nam hoac Nữ.";
        return false;
    }
    if (!HopLeTrangThaiThe(trangThai))
    {
        loi = "Trang thai the chi nhan 0 hoac 1.";
        return false;
    }
    return true;
}
bool ChenDocGiaCoMa(CayDocGia &cay, const DocGia &docGia, string &loi)
{
    if (docGia.maThe <= 0 || docGia.dsMuonTra != nullptr)
    {
        loi = "Ma the phai duong, doc gia moi chua co lich su.";
        return false;
    }
    if (!ThongTinTheHopLe(docGia.ho, docGia.ten, docGia.phai, docGia.trangThaiThe, loi))
    {
        return false;
    }
    if (tim_cay(cay, docGia.maThe))
    {
        loi = "Trung ma the.";
        return false;
    }
    them_cay(cay, docGia);
    loi.clear();
    return true;
}
bool ThemDocGia(ThuVien &tv, const string &ho, const string &ten, const string &phai, int &ma,
                string &loi)
{
    if (!ThongTinTheHopLe(ho, ten, phai, THE_HOAT_DONG, loi))
    {
        return false;
    }
    if (tv.maTheLonNhatDaCap == INT_MAX)
    {
        loi = "Het mien ma the.";
        return false;
    }
    if (DemDocGia(tv.cayDocGia) >= MAX_DOC_GIA)
    {
        loi = "Dat gioi han doc gia.";
        return false;
    }
    DocGia moi;
    int moc = tv.maTheLonNhatDaCap;
    moi.maThe = SinhMaTheTiepTheo(moc);
    moi.ho = ChuanHoaChuoiSach(ho);
    moi.ten = ChuanHoaChuoiSach(ten);
    moi.phai = phai;
    if (!ChenDocGiaCoMa(tv.cayDocGia, moi, loi))
    {
        return false;
    }
    tv.maTheLonNhatDaCap = moi.maThe;
    ma = moi.maThe;
    return true;
}
bool HieuChinhDocGia(ThuVien &tv, int ma, const string &ho, const string &ten, const string &phai,
                     int trangThai, string &loi)
{
    NutDocGia *p = TimDocGia(tv.cayDocGia, ma);
    if (p == nullptr)
    {
        loi = "Khong tim thay doc gia.";
        return false;
    }
    if (!ThongTinTheHopLe(ho, ten, phai, trangThai, loi))
    {
        return false;
    }
    const MuonTra *luot = p->thongTin.dsMuonTra;
    while (luot != nullptr)
    {
        if (trangThai == THE_HOAT_DONG && luot->trangThai == MUON_LAM_MAT)
        {
            loi = "Chua duoc mo the con lich su mat sach.";
            return false;
        }
        luot = luot->next;
    }
    loi.clear();
    return HieuChinhDocGia(tv.cayDocGia, ma, ChuanHoaChuoiSach(ho), ChuanHoaChuoiSach(ten), phai, trangThai);
}
bool XoaDocGia(ThuVien &tv, int ma, string &loi)
{
    NutDocGia *p = tim_cay(tv.cayDocGia, ma);
    if (p == nullptr)
    {
        loi = "Khong tim thay doc gia.";
        return false;
    }
    if (p->thongTin.dsMuonTra != nullptr)
    {
        loi = "Khong xoa doc gia co lich su; hay khoa the de giu thong ke.";
        return false;
    }
    XoaDocGia(tv.cayDocGia, ma);
    loi.clear();
    return true;
}
void ManHinhDocGia(GiaoDien &gd, ThuVien &tv)
{
    const char *labels[] = {"Them doc gia", "Sua / khoa / mo the", "Xoa doc gia chua co lich su"};
    int chon = ChonMenu(gd, "a - QUAN LY DOC GIA", labels, 3);
    int ma = 0, tt = THE_HOAT_DONG;
    string ho, ten, phai, loi;
    if (chon == 0)
    {
        return;
    }
    if (chon == 2)
    {
        ma = ChonMaTheDocGia(gd, tv.cayDocGia, "CHON DOC GIA CAN SUA");
        if (ma == 0) return;
    }
    if (DangDungGiaoDienHeThong(gd))
    {
        if (chon < 1)
        {
            return;
        }
        const NutDocGia *current = nullptr;
        if (chon == 2) current = TimDocGia(tv.cayDocGia, ma);
        if (chon == 3)
        {
            const char *fields[] = {"Ma the doc gia"};
            string values[1];
            while (true)
            {
                if (!NhapBieuMau(gd, "CHON DOC GIA CAN XOA",
                                 fields, values, 1))
                {
                    return;
                }
                if (!DocSoNguyen(values[0], ma, 1, INT_MAX))
                {
                    ThongBao(gd, "Ma the phai la so nguyen duong trong mien int.");
                    continue;
                }
                current = TimDocGia(tv.cayDocGia, ma);
                if (!current)
                {
                    ThongBao(gd, "Khong tim thay doc gia. Kiem tra lai ma the.");
                    continue;
                }
                break;
            }
        }
        if (chon == 3)
        {
            bool ok = XoaDocGia(tv, ma, loi);
            if (ok)
            {
                LuuSauThayDoi(gd, tv);
            }
            ThongBao(gd, ok ? "OK: da xoa doc gia." : "LOI: " + loi);
            return;
        }
        const char *fields[] = {"Ho", "Ten", u8"Phai (Nam/Nữ)",
                                "Trang thai the (0 khoa, 1 hoat dong)"};
        string values[4];
        values[2] = "Nam";
        values[3] = ChuoiSo(THE_HOAT_DONG);
        if (current)
        {
            const DocGia &d = current->thongTin;
            values[0] = d.ho;
            values[1] = d.ten;
            values[2] = d.phai;
            values[3] = ChuoiSo(d.trangThaiThe);
        }
        string thongBao;
        while (true)
        {
            bool daNhap;
            if (chon == 1)
            {
                daNhap = NhapBieuMauLienTiep(gd, "THEM DOC GIA", fields, values, 3, thongBao);
            }
            else
            {
                daNhap = NhapBieuMau(gd, "HIEU CHINH DOC GIA - THE " + ChuoiSo(ma), fields, values, 4);
            }
            if (!daNhap)
            {
                break;
            }
            if (chon == 2 && !DocSoNguyen(values[3], tt, THE_BI_KHOA, THE_HOAT_DONG))
            {
                ThongBao(gd, "Trang thai the chi nhan 0 (khoa) hoac 1 (hoat dong).");
                continue;
            }
            bool ok = chon == 1 ? ThemDocGia(tv, values[0], values[1], values[2], ma, loi)
                                : HieuChinhDocGia(tv, ma, values[0], values[1], values[2], tt, loi);
            if (!ok)
            {
                ThongBao(gd, "LOI: " + loi);
                continue;
            }
            LuuSauThayDoi(gd, tv);
            if (chon == 1)
            {
                thongBao = "Da luu the " + ChuoiSo(ma) + " - " + values[0] + " " + values[1];
                values[0].clear();
                values[1].clear();
                values[2] = "Nam";
                continue;
            }
            ThongBao(gd, "OK: da luu doc gia, ma the " + ChuoiSo(ma));
            return;
        }
        return;
    }
    if (chon == 3)
    {
        if (!NhapSo(gd, "Ma the", ma, 1, INT_MAX))
        {
            return;
        }
    }
    if (chon == 3)
    {
        bool ok = XoaDocGia(tv, ma, loi);
        if (ok)
        {
            LuuSauThayDoi(gd, tv);
        }
        ThongBao(gd, ok ? "OK: da xoa doc gia." : "LOI: " + loi);
        return;
    }
    if (!NhapDong(gd, "Ho", ho) || !NhapDong(gd, "Ten", ten) || !NhapDong(gd, u8"Phai (Nam/Nữ)", phai))
    {
        return;
    }
    bool ok = false;
    if (chon == 1)
    {
        ok = ThemDocGia(tv, ho, ten, phai, ma, loi);
    }
    else
    {
        if (!NhapSo(gd, "Trang thai the (0 khoa, 1 hoat dong)", tt, THE_BI_KHOA, THE_HOAT_DONG))
        {
            return;
        }
        ok = HieuChinhDocGia(tv, ma, ho, ten, phai, tt, loi);
    }
    if (ok)
    {
        LuuSauThayDoi(gd, tv);
    }
    ThongBao(gd, ok ? "OK: ma the " + ChuoiSo(ma) : "LOI: " + loi);
}
