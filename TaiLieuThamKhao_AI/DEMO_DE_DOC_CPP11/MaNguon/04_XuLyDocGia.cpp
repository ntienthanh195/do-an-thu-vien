#include "00_KhaiBaoChung.h"

const NutDocGia *TimDocGia(const CayDocGia &tree, int ma)
{
    const NutDocGia *p = tree.root;
    while (p && p->thongTin.maThe != ma)
        p = ma < p->thongTin.maThe ? p->left : p->right;
    return p;
}
NutDocGia *TimDocGia(CayDocGia &tree, int ma)
{
    NutDocGia *p = tree.root;
    while (p && p->thongTin.maThe != ma)
        p = ma < p->thongTin.maThe ? p->left : p->right;
    return p;
}
int LayDanhSachDocGia(const CayDocGia &tree, const NutDocGia **out, int capacity)
{
    const NutDocGia **stack = NULL;
    try
    {

        stack = new const NutDocGia *[MAX_DOC_GIA];
        int top = 0, n = 0;
        const NutDocGia *p = tree.root;
        while (p || top)
        {
            while (p)
            {
                if (top >= MAX_DOC_GIA)
                    throw LoiThuVien("Cay vuot gioi han tai nguyen");
                stack[top++] = p;
                p = p->left;
            }
            p = stack[--top];
            if (n >= MAX_DOC_GIA || (out && n >= capacity))
                throw LoiThuVien("Mang ket qua khong du cho");
            if (out)
                out[n] = p;
            ++n;
            p = p->right;
        }
        delete[] stack;
        return n;
    }
    catch (...)
    {
        delete[] stack;
        throw; // Bao loi cho menu; mang tam da duoc giai phong.
    }
}
int DemDocGia(const CayDocGia &tree)
{
    return LayDanhSachDocGia(tree, nullptr, 0);
}
namespace
{
bool HopLeDocGia(const string &ho, const string &ten, const string &phai, int tt, string &loi)
{
    if (!HopLeVanBan(ho) || !HopLeVanBan(ten))
    {
        loi = "Ho/ten phai la UTF-8, khong rong, khong |, toi da 512 byte.";
        return false;
    }
    if (!HopLePhai(phai))
    {
        loi = u8"Phai chi nhan Nam hoac Nữ.";
        return false;
    }
    if (!HopLeTrangThaiThe(tt))
    {
        loi = "Trang thai the chi nhan 0 hoac 1.";
        return false;
    }
    return true;
}
void InMotDocGia(const DocGia &d, ostream &out)
{
    out << d.maThe << " | " << d.ho << " | " << d.ten << " | " << d.phai << " | "
        << (d.trangThaiThe ? "Hoat dong" : "Khoa") << '\n';
}
bool TenHoTruoc(const NutDocGia *a, const NutDocGia *b)
{
    int c = SoSanhChuoi(a->thongTin.ten, b->thongTin.ten);
    if (c)
        return c < 0;
    c = SoSanhChuoi(a->thongTin.ho, b->thongTin.ho);
    return c ? c < 0 : a->thongTin.maThe < b->thongTin.maThe;
}
} // namespace
bool ChenDocGiaCoMa(CayDocGia &tree, const DocGia &d, string &loi)
{
    if (d.maThe <= 0 || d.dsMuonTra != NULL ||
        !HopLeDocGia(d.ho, d.ten, d.phai, d.trangThaiThe, loi))
    {
        if (loi.empty())
            loi = "Ma the phai duong; chen doc gia rong lich su truoc.";
        return false;
    }

    // Tim vi tri chen: cha la nut dung truoc p tren duong di.
    NutDocGia *cha = NULL;
    NutDocGia *p = tree.root;
    while (p != NULL)
    {
        if (p->thongTin.maThe == d.maThe)
        {
            loi = "Trung ma the.";
            return false;
        }
        cha = p;
        if (d.maThe < p->thongTin.maThe)
            p = p->left;
        else
            p = p->right;
    }

    // Chuan bi thong tin truoc; tao nut xong moi noi vao cay.
    NutDocGia thongTin;
    thongTin.thongTin = d;
    NutDocGia *moi = new NutDocGia(thongTin);
    if (cha == NULL)
        tree.root = moi;
    else if (d.maThe < cha->thongTin.maThe)
        cha->left = moi;
    else
        cha->right = moi;
    return true;
}
bool ThemDocGia(ThuVien &tv, const string &ho, const string &ten, const string &phai, int &ma,
                string &loi)
{
    loi.clear();
    if (!HopLeDocGia(ho, ten, phai, THE_HOAT_DONG, loi))
        return false;
    if (tv.maTheLonNhatDaCap == SO_NGUYEN_LON_NHAT)
    {
        loi = "Da het mien ma the int; khong quay vong.";
        return false;
    }
    if (DemDocGia(tv.cayDocGia) >= MAX_DOC_GIA)
    {
        loi = "Dat gioi han doc gia cua ban tham khao.";
        return false;
    }
    DocGia d;
    d.maThe = tv.maTheLonNhatDaCap + 1;
    d.ho = ChuanHoaChuoi(ho);
    d.ten = ChuanHoaChuoi(ten);
    d.phai = phai;
    if (!ChenDocGiaCoMa(tv.cayDocGia, d, loi))
        return false;
    tv.maTheLonNhatDaCap = d.maThe;
    ma = d.maThe;
    return true;
}
bool HieuChinhDocGia(ThuVien &tv, int ma, const string &ho, const string &ten, const string &phai,
                     int tt, string &loi)
{
    loi.clear();
    NutDocGia *p = TimDocGia(tv.cayDocGia, ma);
    if (!p)
    {
        loi = "Khong tim thay doc gia.";
        return false;
    }
    if (!HopLeDocGia(ho, ten, phai, tt, loi))
        return false;
    string h = ChuanHoaChuoi(ho), t = ChuanHoaChuoi(ten), f = phai;
    if (!HopLeDocGia(h, t, f, tt, loi))
        return false;
    if (tt == THE_HOAT_DONG)
        for (const MuonTra *q = p->thongTin.dsMuonTra; q; q = q->next)
            if (q->trangThai == MUON_LAM_MAT)
            {
                loi = "Chua ho tro xu ly xong mat sach; khong mo lai the co lich su mat.";
                return false;
            }
    // Sau khi cap phat chuoi thanh cong, swap khong cap phat: khong sua nua chung.
    p->thongTin.ho.swap(h);
    p->thongTin.ten.swap(t);
    p->thongTin.phai.swap(f);
    p->thongTin.trangThaiThe = tt;
    return true;
}
bool XoaDocGia(ThuVien &tv, int ma, string &loi)
{
    loi.clear();
    NutDocGia *cha = NULL;
    NutDocGia *p = tv.cayDocGia.root;
    while (p != NULL && p->thongTin.maThe != ma)
    {
        cha = p;
        if (ma < p->thongTin.maThe)
            p = p->left;
        else
            p = p->right;
    }
    if (p == NULL)
    {
        loi = "Khong tim thay doc gia.";
        return false;
    }
    if (p->thongTin.dsMuonTra != NULL)
    {
        loi = "Khong xoa doc gia co lich su; hay khoa the de giu thong ke.";
        return false;
    }

    NutDocGia *thayThe;
    if (p->left == NULL)
        thayThe = p->right;
    else if (p->right == NULL)
        thayThe = p->left;
    else
    {
        // Hai con: lay nut co ma nho nhat trong cay con phai.
        NutDocGia *chaKeTiep = p;
        NutDocGia *keTiep = p->right;
        while (keTiep->left != NULL)
        {
            chaKeTiep = keTiep;
            keTiep = keTiep->left;
        }
        if (chaKeTiep != p)
        {
            chaKeTiep->left = keTiep->right;
            keTiep->right = p->right;
        }
        keTiep->left = p->left;
        thayThe = keTiep;
        // Di chuyen ca nut, giu nguyen lich su thuoc doc gia ke tiep.
    }

    if (cha == NULL)
        tv.cayDocGia.root = thayThe;
    else if (cha->left == p)
        cha->left = thayThe;
    else
        cha->right = thayThe;
    delete p;
    return true;
}
void HuyCayDocGia(CayDocGia &tree)
{
    // Quay lien ket de huy lap: O(R), O(1) phu, khong tran stack voi cay lech.
    while (tree.root)
    {
        NutDocGia *p = tree.root;
        if (p->left)
        {
            NutDocGia *q = p->left;
            p->left = q->right;
            q->right = p;
            tree.root = q;
        }
        else
        {
            tree.root = p->right;
            HuyDanhSachMuonTra(p->thongTin.dsMuonTra);
            delete p;
        }
    }
}

// Vun dong de sap theo ten + ho, khong thay doi khoa trong BST.
void VunDongDocGia(const NutDocGia **rows, int root, int size)
{
    while (root < size / 2)
    {
        int child = 2 * root + 1;
        if (child + 1 < size && TenHoTruoc(rows[child], rows[child + 1]))
            ++child;
        if (!TenHoTruoc(rows[root], rows[child]))
            break;
        const NutDocGia *tam = rows[root];
        rows[root] = rows[child];
        rows[child] = tam;
        root = child;
    }
}
void InDocGiaTheoMa(const ThuVien &tv, ostream &out)
{
    const NutDocGia **rows = NULL;
    try
    {

        int n = DemDocGia(tv.cayDocGia);
        rows = new const NutDocGia *[n];
        LayDanhSachDocGia(tv.cayDocGia, rows, n);
        out << "MA THE | HO | TEN | PHAI | THE\n";
        for (int i = 0; i < n; ++i)
            InMotDocGia(rows[i]->thongTin, out);
        if (!n)
            out << "Danh sach rong.\n";

        delete[] rows;
    }
    catch (...)
    {
        delete[] rows;
        throw; // Bao loi cho menu; mang tam da duoc giai phong.
    }
}
void InDocGiaTheoTenHo(const ThuVien &tv, ostream &out)
{
    const NutDocGia **rows = NULL;
    try
    {

        int n = DemDocGia(tv.cayDocGia);
        rows = new const NutDocGia *[n];
        LayDanhSachDocGia(tv.cayDocGia, rows, n);
        // Heap sort tu cai tren view: O(R log R), khong doi khoa BST.
        for (int i = n / 2; i > 0; --i)
            VunDongDocGia(rows, i - 1, n);
        for (int end = n - 1; end > 0; --end)
        {
            const NutDocGia *tmp = rows[0];
            rows[0] = rows[end];
            rows[end] = tmp;
            VunDongDocGia(rows, 0, end);
        }
        out << "MA THE | HO | TEN | PHAI | THE (TEN + HO)\n";
        for (int i = 0; i < n; ++i)
            InMotDocGia(rows[i]->thongTin, out);
        if (!n)
            out << "Danh sach rong.\n";

        delete[] rows;
    }
    catch (...)
    {
        delete[] rows;
        throw; // Bao loi cho menu; mang tam da duoc giai phong.
    }
}
void ManHinhDocGia(ThuVien &tv)
{
    const char *labels[] = {"Them doc gia", "Sua / khoa / mo the", "Xoa doc gia chua co lich su"};
    int chon = ChonMenu("a - QUAN LY DOC GIA", labels, 3);
    int ma = 0, tt = 1;
    string ho, ten, phai, loi;
    if (chon == 0)
        return;
    if (DangDungGiaoDienHeThong())
    {
        if (chon < 1)
            return;
        const NutDocGia *current = nullptr;
        if (chon == 2 || chon == 3)
        {
            const char *fields[] = {"Ma the doc gia"};
            string values[1];
            while (true)
            {
                if (!NhapBieuMau(chon == 2 ? "CHON DOC GIA CAN SUA" : "CHON DOC GIA CAN XOA",
                                 fields, values, 1))
                    return;
                if (!DocSoNguyen(values[0], ma, 1, SO_NGUYEN_LON_NHAT))
                {
                    ThongBao("Ma the phai la so nguyen duong trong mien int.");
                    continue;
                }
                current = TimDocGia(tv.cayDocGia, ma);
                if (!current)
                {
                    ThongBao("Khong tim thay doc gia. Kiem tra lai ma the.");
                    continue;
                }
                break;
            }
        }
        if (chon == 3)
        {
            bool ok = XoaDocGia(tv, ma, loi);
            if (ok)
                LuuSauThayDoi(tv);
            ThongBao(ok ? "OK: da xoa doc gia." : "LOI: " + loi);
            return;
        }
        const char *fields[] = {"Ho", "Ten", u8"Phai (Nam/Nữ)",
                                "Trang thai the (0 khoa, 1 hoat dong)"};
        string values[4];
        values[2] = "Nam";
        values[3] = "1";
        if (current)
        {
            const DocGia &d = current->thongTin;
            values[0] = d.ho;
            values[1] = d.ten;
            values[2] = d.phai;
            values[3] = to_string(d.trangThaiThe);
        }
        while (NhapBieuMau(chon == 1 ? "THEM DOC GIA" : "HIEU CHINH DOC GIA - THE " + to_string(ma),
                           fields, values, chon == 1 ? 3 : 4))
        {
            if (chon == 2 && !DocSoNguyen(values[3], tt, 0, 1))
            {
                ThongBao("Trang thai the chi nhan 0 (khoa) hoac 1 (hoat dong).");
                continue;
            }
            bool ok = chon == 1 ? ThemDocGia(tv, values[0], values[1], values[2], ma, loi)
                                : HieuChinhDocGia(tv, ma, values[0], values[1], values[2], tt, loi);
            if (!ok)
            {
                ThongBao("LOI: " + loi);
                continue;
            }
            LuuSauThayDoi(tv);
            ThongBao("OK: da luu doc gia, ma the " + to_string(ma));
            return;
        }
        return;
    }
    if (chon == 2 || chon == 3)
        if (!NhapSo("Ma the", ma, 1, SO_NGUYEN_LON_NHAT))
            return;
    if (chon == 3)
    {
        bool ok = XoaDocGia(tv, ma, loi);
        if (ok)
            LuuSauThayDoi(tv);
        ThongBao(ok ? "OK: da xoa doc gia." : "LOI: " + loi);
        return;
    }
    if (!NhapDong("Ho", ho) || !NhapDong("Ten", ten) || !NhapDong(u8"Phai (Nam/Nữ)", phai))
        return;
    bool ok = false;
    if (chon == 1)
        ok = ThemDocGia(tv, ho, ten, phai, ma, loi);
    else
    {
        if (!NhapSo("Trang thai the (0 khoa, 1 hoat dong)", tt, 0, 1))
            return;
        ok = HieuChinhDocGia(tv, ma, ho, ten, phai, tt, loi);
    }
    if (ok)
        LuuSauThayDoi(tv);
    ThongBao(ok ? "OK: ma the " + to_string(ma) : "LOI: " + loi);
}
