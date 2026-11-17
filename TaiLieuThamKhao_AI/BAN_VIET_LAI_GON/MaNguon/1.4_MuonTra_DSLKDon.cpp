#include "0.0_KhaiBaoChung.h"

/* ============================================================
   13. CAU TRUC DU LIEU: DANH SACH MUON TRA (danh sach lien ket don), moi doc gia giu mot danh sach rieng.
   Moi lan muon them mot nut vao cuoi danh sach. Khi tra khong xoa nut ma chi doi
   trang thai va ghi ngay tra, nen danh sach cung la lich su muon cua doc gia.
   ============================================================ */

// [THANH] Them mot luot muon vao cuoi danh sach.
// @TT [f] Them luot muon vao cuoi DSLK don muon tra
void them_lich_su(NutDocGia &q, MuonTra muontra)
{
    MuonTra *muontraa = new MuonTra;
    *muontraa = muontra;
    muontraa->next = nullptr;

    MuonTra *p = q.thongTin.dsMuonTra;
    while (p != nullptr && p->next != nullptr)
    {
        p = p->next;
    }
    if (p == nullptr)
        q.thongTin.dsMuonTra = muontraa;
    else
        p->next = muontraa;
}

// [THANH]
// @TT [f] Dem so sach dang muon (de chan muon qua 3 cuon): duyet DSLK, dem trang thai 0
int Dem_so_sach_dang_muon(NutDocGia &q)
{
    int sachdangmuon = 0;
    MuonTra *p = q.thongTin.dsMuonTra;
    while (p != nullptr)
    {
        if (p->trangThai == MUON_DANG_MUON)
            sachdangmuon++;
        p = p->next;
    }
    return sachdangmuon;
}

// [THANH] Tim luot dang muon (chua tra) cua mot ma sach.
// @TT [g] Tim luot dang muon cua mot ma sach: duyet tuyen tinh DSLK muon tra
MuonTra *TimMuonDangMuonTheoMa(NutDocGia &q, string maSach)
{
    MuonTra *p = q.thongTin.dsMuonTra;
    while (p != nullptr)
    {
        if (p->maSach == maSach && p->trangThai == MUON_DANG_MUON)
            return p;
        p = p->next;
    }
    return nullptr;
}

// [THANH] Doc gia co dang giu cuon nao qua han tinh den ngay ngayktra khong.
// Giu moc >= 7 cua nhom: muon ngay 01 thi den ngay 07 van trong han, ngay 08 la qua han.
// @TT [f] Kiem tra doc gia dang giu sach qua han: khoang cach ngay >= 7
bool CoSachQuaHan7Ngay(const NutDocGia &docgia, NgayThang ngayktra)
{
    MuonTra *q = docgia.thongTin.dsMuonTra;
    while (q != nullptr)
    {
        if (q->trangThai == MUON_DANG_MUON)
        {
            long long k = KhoangCachNgay(q->ngayMuon, ngayktra);
            if (k >= HAN_MUON)
                return true;
        }
        q = q->next;
    }
    return false;
}

// So ngay qua han cua mot luot muon tinh den ngayXet, cung moc voi ham tren.
// Vi du muon ngay 01: ngay 07 tra ve 0 (chua qua han), ngay 08 tra ve 1, ngay 09 tra ve 2.
// @TT [f,g,h,i] So ngay qua han = khoang cach ngay - 7 + 1 (0 neu chua qua han)
int SoNgayQuaHan(NgayThang ngayMuon, NgayThang ngayXet)
{
    long long k = KhoangCachNgay(ngayMuon, ngayXet);
    if (k < HAN_MUON)
        return 0;
    return (int)(k - HAN_MUON + 1);
}

// [THANH] Ket thuc mot luot dang muon: ghi ngay tra va trang thai moi
// (MUON_DA_TRA hoac MUON_LAM_MAT). Chi sua lich su, chua sua trang thai cuon sach.
// @TT [g] Tra sach: khong xoa nut, chi doi trang thai + ghi ngay tra (giu lich su cho top 10)
bool CapNhatLuotTra(const NutDocGia &docgia, string masach, NgayThang ngaytrasach, int trangThaiMoi)
{
    MuonTra *q = docgia.thongTin.dsMuonTra;
    while (q != nullptr && (q->maSach != masach || q->trangThai != MUON_DANG_MUON))
    {
        q = q->next;
    }
    if (q == nullptr)
        return false;

    q->ngayTra = ngaytrasach;
    q->trangThai = trangThaiMoi;
    return true;
}

// [THANH]
void HuyDanhSachMuonTra(NutDocGia &docgia)
{
    MuonTra *q = docgia.thongTin.dsMuonTra;
    while (q != nullptr)
    {
        MuonTra *p = q;
        q = q->next;
        delete p;
    }
    docgia.thongTin.dsMuonTra = nullptr;
}
