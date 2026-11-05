#include "00_KhaiBaoChung.h"

// [DEMO - CODEX] Phan bo sung cho ban trinh thay.
struct KetQuaQuaHan
{
    const DocGia *docGia = nullptr;
    int soNgay = 0;
    int soCuon = 0;
};

bool KetQuaQuaHanTruoc(KetQuaQuaHan a, KetQuaQuaHan b)
{

    if (a.soNgay != b.soNgay)
    {
        return a.soNgay > b.soNgay;
    }
    return a.docGia->maThe < b.docGia->maThe;
}
void TronKetQuaQuaHan(KetQuaQuaHan *a, KetQuaQuaHan *tam, int trai, int giua, int phai)
{
    int i = trai, j = giua + 1, k = trai;
    while (i <= giua && j <= phai)
    {
        if (KetQuaQuaHanTruoc(a[j], a[i]))
        {
            tam[k] = a[j];
            j++;
        }
        else
        {
            tam[k] = a[i];
            i++;
        }
        k++;
    }
    while (i <= giua)
    {
        tam[k] = a[i];
        i++;
        k++;
    }
    while (j <= phai)
    {
        tam[k] = a[j];
        j++;
        k++;
    }
    for (int viTri = trai; viTri <= phai; viTri++)
    {
        a[viTri] = tam[viTri];
    }
}
void ChiaKetQuaQuaHan(KetQuaQuaHan *a, KetQuaQuaHan *tam, int trai, int phai)
{
    if (trai >= phai)
    {
        return;
    }
    int giua = trai + (phai - trai) / 2;
    ChiaKetQuaQuaHan(a, tam, trai, giua);
    ChiaKetQuaQuaHan(a, tam, giua + 1, phai);
    TronKetQuaQuaHan(a, tam, trai, giua, phai);
}
void SapXepKetQuaQuaHan(KetQuaQuaHan *a, int soLuong)
{
    if (soLuong < 2)
    {
        return;
    }
    KetQuaQuaHan *tam = new KetQuaQuaHan[soLuong];
    try
    {
        ChiaKetQuaQuaHan(a, tam, 0, soLuong - 1);
        delete[] tam;
    }
    catch (...)
    {
        delete[] tam;
        throw;
    }
}

void InDocGiaQuaHan(const ThuVien &tv, const NgayThang &ngay, ostream &out)
{
    if (!NgayHopLe(ngay))
    {
        out << "Ngay thong ke khong hop le.\n";
        return;
    }
    int soDocGia = DemDocGia(tv.cayDocGia);
    const NutDocGia **ds = nullptr;
    KetQuaQuaHan *ketQua = nullptr;
    try
    {
        ds = new const NutDocGia *[soDocGia];
        ketQua = new KetQuaQuaHan[soDocGia];
        LayDanhSachDocGia(tv.cayDocGia, ds, soDocGia);
        int soKetQua = 0;
        for (int i = 0; i < soDocGia; i++)
        {
            KetQuaQuaHan dong;
            dong.docGia = &ds[i]->thongTin;
            const MuonTra *p = dong.docGia->dsMuonTra;
            while (p != nullptr)
            {
                if (p->trangThai == MUON_DANG_MUON)
                {
                    int quaHan = SoNgayQuaHan(p->ngayMuon, ngay);
                    if (quaHan > 0)
                    {
                        dong.soCuon++;
                        if (quaHan > dong.soNgay)
                        {
                            dong.soNgay = quaHan;
                        }
                    }
                }
                p = p->next;
            }
            if (dong.soCuon > 0)
            {
                ketQua[soKetQua] = dong;
                soKetQua++;
            }
        }
        SapXepKetQuaQuaHan(ketQua, soKetQua);
        out << "DOC GIA QUA HAN - ngay " << ChuoiNgay(ngay) << '\n';
        out << "Xep theo so ngay qua han (tinh tu moc 7 ngay) lon nhat trong cac cuon dang muon; hoa thi ma the tang.\n";
        for (int i = 0; i < soKetQua; i++)
        {
            out << ketQua[i].docGia->maThe << " | " << ketQua[i].docGia->ho << ' '
                << ketQua[i].docGia->ten << " | Qua han: " << ketQua[i].soNgay << " ngay | "
                << ketQua[i].soCuon << " cuon qua han\n";
        }
        if (soKetQua == 0)
        {
            out << "Khong co doc gia qua han.\n";
        }
        delete[] ds;
        delete[] ketQua;
    }
    catch (...)
    {
        delete[] ds;
        delete[] ketQua;
        throw;
    }
}
