#include "00_KhaiBaoChung.h"

/* ============================================================
   DOC / GHI FILE VAN BAN. Moi dong la mot ban ghi, cac truong cach nhau boi dau '|'.

     <so dau sach>
     ISBN|ten sach|so trang|tac gia|nam xuat ban|the loai|<so cuon>
     ma sach|trang thai|vi tri                      (lap lai <so cuon> dong)
     ...
     <so doc gia>
     ma the|ho|ten|phai|trang thai the|<so luot muon>
     ma sach|ngay muon|ngay tra|trang thai          (lap lai <so luot muon> dong)
     ...

   Doc gia duoc ghi theo thu tu duyet truoc (NLR: nut goc truoc, roi cay con trai, cay con phai).
   Khi doc lai, tung doc gia duoc them vao cay bang them_cay nen cay tu can bang theo AVL,
   truong height khong can luu vao file.
   ============================================================ */

static int DemLuotMuon(const MuonTra *p)
{
    int dem = 0;
    while (p != nullptr)
    {
        ++dem;
        p = p->next;
    }
    return dem;
}

// Ghi cay doc gia theo thu tu duyet truoc (NLR).
static void GhiDocGia(ofstream &f, NutDocGia *p)
{
    if (p == nullptr)
        return;

    const DocGia &dg = p->thongTin;
    f << dg.maThe << '|' << dg.ho << '|' << dg.ten << '|' << dg.phai << '|' << dg.trangThaiThe
      << '|' << DemLuotMuon(dg.dsMuonTra) << '\n';
    for (MuonTra *m = dg.dsMuonTra; m != nullptr; m = m->next)
    {
        f << m->maSach << '|' << ChuoiNgay(m->ngayMuon) << '|' << ChuoiNgay(m->ngayTra) << '|'
          << m->trangThai << '\n';
    }

    GhiDocGia(f, p->left);
    GhiDocGia(f, p->right);
}

bool LuuFile(const DanhSachDauSach &ds, CayDocGia cay, const char tenFile[])
{
    ofstream f(tenFile);
    if (!f.is_open())
        return false;

    f << ds.soLuong << '\n';
    for (int i = 0; i < ds.soLuong; ++i)
    {
        const DauSach &d = *ds.ds[i];
        f << d.ISBN << '|' << d.tenSach << '|' << d.soTrang << '|' << d.tacGia << '|'
          << d.namXuatBan << '|' << d.theLoai << '|' << DemCuonSach(d.dms) << '\n';
        for (CuonSach *c = d.dms; c != nullptr; c = c->next)
            f << c->maSach << '|' << c->trangThai << '|' << c->viTri << '\n';
    }

    f << DemDocGia(cay) << '\n';
    GhiDocGia(f, cay);

    f.close();
    return true;
}

// Doc phan dau sach. Tra ve false neu file sai dinh dang.
static bool DocPhanSach(ifstream &f, DanhSachDauSach &ds)
{
    string dong, truong[7], loi;
    int soDauSach = 0;

    if (!getline(f, dong) || TachTruong(dong, '|', truong, 7) != 1 ||
        !ChuoiThanhSo(truong[0], soDauSach))
        return false;

    for (int i = 0; i < soDauSach; ++i)
    {
        DauSach d;
        int soCuon = 0;
        if (!getline(f, dong) || TachTruong(dong, '|', truong, 7) != 7)
            return false;
        d.ISBN = truong[0];
        d.tenSach = truong[1];
        d.tacGia = truong[3];
        d.theLoai = truong[5];
        if (!ChuoiThanhSo(truong[2], d.soTrang) || !ChuoiThanhSo(truong[4], d.namXuatBan) ||
            !ChuoiThanhSo(truong[6], soCuon))
            return false;
        if (!ThemDauSach(ds, d, loi))
            return false;

        // ThemDauSach chen theo ten nen phai tim lai dia chi dau sach vua them
        DauSach *moi = TimDauSachTheoISBN(ds, d.ISBN);
        for (int j = 0; j < soCuon; ++j)
        {
            int trangThai = 0;
            if (!getline(f, dong) || TachTruong(dong, '|', truong, 7) != 3)
                return false;
            if (!ChuoiThanhSo(truong[1], trangThai) || trangThai > SACH_THANH_LY)
                return false;
            if (TachISBNTuMaSach(truong[0]) != d.ISBN)
                return false; // ma sach phai co dang ISBN#N cua chinh dau sach nay
            ThemCuonSachCoMa(*moi, truong[0], truong[2], trangThai);
        }
    }
    return true;
}

// Doc phan doc gia va lich su muon tra. Tra ve false neu file sai dinh dang.
static bool DocPhanDocGia(ifstream &f, CayDocGia &cay)
{
    string dong, truong[6];
    int soDocGia = 0;

    if (!getline(f, dong) || TachTruong(dong, '|', truong, 6) != 1 ||
        !ChuoiThanhSo(truong[0], soDocGia))
        return false;

    for (int i = 0; i < soDocGia; ++i)
    {
        DocGia dg;
        int soLuot = 0;
        if (!getline(f, dong) || TachTruong(dong, '|', truong, 6) != 6)
            return false;
        dg.ho = truong[1];
        dg.ten = truong[2];
        dg.phai = truong[3];
        if (!ChuoiThanhSo(truong[0], dg.maThe) || !ChuoiThanhSo(truong[4], dg.trangThaiThe) ||
            !ChuoiThanhSo(truong[5], soLuot))
            return false;
        if (!HopLePhai(dg.phai) || dg.trangThaiThe > THE_HOAT_DONG)
            return false;
        if (!them_cay(cay, dg))
            return false; // trung ma the

        NutDocGia *nut = tim_cay(cay, dg.maThe);
        for (int j = 0; j < soLuot; ++j)
        {
            MuonTra luot;
            if (!getline(f, dong) || TachTruong(dong, '|', truong, 6) != 4)
                return false;
            luot.maSach = truong[0];
            if (!DocNgay(truong[1], luot.ngayMuon) || !DocNgay(truong[2], luot.ngayTra) ||
                !ChuoiThanhSo(truong[3], luot.trangThai) || luot.trangThai > MUON_LAM_MAT)
                return false;
            them_lich_su(*nut, luot);
        }
    }
    return true;
}

// Doc toan bo du lieu. Chua co file thi coi nhu thu vien rong va tra ve true.
// File sai dinh dang thi huy phan da doc va tra ve false.
bool DocFile(DanhSachDauSach &ds, CayDocGia &cay, const char tenFile[])
{
    ifstream f(tenFile);
    if (!f.is_open())
        return true;

    bool thanhCong = DocPhanSach(f, ds) && DocPhanDocGia(f, cay);
    f.close();

    if (!thanhCong)
    {
        HuyDanhSachDauSach(ds);
        HuyCayDocGia(cay);
    }
    return thanhCong;
}

// Goi sau moi thao tac lam thay doi du lieu de khong mat du lieu khi tat chuong trinh dot ngot.
void LuuSauThayDoi(const DanhSachDauSach &ds, CayDocGia cay)
{
    if (!LuuFile(ds, cay, FILE_DU_LIEU))
        ThongBao("Không ghi được file dữ liệu, kiểm tra thư mục DuLieu.", true);
}
