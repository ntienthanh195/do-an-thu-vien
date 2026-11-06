#include "00_KhaiBaoChung.h"

// [DEMO - CODEX] Phan bo sung cho ban trinh thay.
// [DEMO - CODEX] Sap xep mang vi tri; du lieu nam trong cac mang truyen vao.
bool QuaHanTruoc(int a, int b, const DocGia *const *docGia, const int *soNgay)
{
    if (soNgay[a] != soNgay[b])
    {
        return soNgay[a] > soNgay[b];
    }
    return docGia[a]->maThe < docGia[b]->maThe;
}
void TronQuaHan(int *thuTu, int *tam, int trai, int giua, int phai, const DocGia *const *docGia, const int *soNgay)
{
    int i = trai, j = giua + 1, k = trai;
    while (i <= giua && j <= phai)
    {
        if (QuaHanTruoc(thuTu[j], thuTu[i], docGia, soNgay))
        {
            tam[k] = thuTu[j];
            j++;
        }
        else
        {
            tam[k] = thuTu[i];
            i++;
        }
        k++;
    }
    while (i <= giua)
    {
        tam[k] = thuTu[i];
        i++;
        k++;
    }
    while (j <= phai)
    {
        tam[k] = thuTu[j];
        j++;
        k++;
    }
    for (int viTri = trai; viTri <= phai; viTri++)
    {
        thuTu[viTri] = tam[viTri];
    }
}
void ChiaQuaHan(int *thuTu, int *tam, int trai, int phai, const DocGia *const *docGia, const int *soNgay)
{
    if (trai >= phai)
    {
        return;
    }
    int giua = trai + (phai - trai) / 2;
    ChiaQuaHan(thuTu, tam, trai, giua, docGia, soNgay);
    ChiaQuaHan(thuTu, tam, giua + 1, phai, docGia, soNgay);
    TronQuaHan(thuTu, tam, trai, giua, phai, docGia, soNgay);
}
void SapXepQuaHan(int *thuTu, int soLuong, const DocGia *const *docGia, const int *soNgay)
{
    for (int i = 0; i < soLuong; i++)
    {
        thuTu[i] = i;
    }
    if (soLuong < 2)
    {
        return;
    }
    int *tam = new int[soLuong];
    try
    {
        ChiaQuaHan(thuTu, tam, 0, soLuong - 1, docGia, soNgay);
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
    const DocGia **docGia = nullptr;
    int *soNgay = nullptr, *soCuon = nullptr, *thuTu = nullptr;
    try
    {
        ds = new const NutDocGia *[soDocGia];
        docGia = new const DocGia *[soDocGia];
        soNgay = new int[soDocGia];
        soCuon = new int[soDocGia];
        thuTu = new int[soDocGia];
        LayDanhSachDocGia(tv.cayDocGia, ds, soDocGia);
        int soKetQua = 0;
        for (int i = 0; i < soDocGia; i++)
        {
            const DocGia *nguoiDoc = &ds[i]->thongTin;
            int ngayQuaHan = 0, cuonQuaHan = 0;
            const MuonTra *p = nguoiDoc->dsMuonTra;
            while (p != nullptr)
            {
                if (p->trangThai == MUON_DANG_MUON)
                {
                    int quaHan = SoNgayQuaHan(p->ngayMuon, ngay);
                    if (quaHan > 0)
                    {
                        cuonQuaHan++;
                        if (quaHan > ngayQuaHan)
                        {
                            ngayQuaHan = quaHan;
                        }
                    }
                }
                p = p->next;
            }
            if (cuonQuaHan > 0)
            {
                docGia[soKetQua] = nguoiDoc;
                soNgay[soKetQua] = ngayQuaHan;
                soCuon[soKetQua] = cuonQuaHan;
                soKetQua++;
            }
        }
        SapXepQuaHan(thuTu, soKetQua, docGia, soNgay);
        out << "DOC GIA QUA HAN - ngay " << ChuoiNgay(ngay) << '\n';
        out << "Xep theo so ngay qua han (tinh tu moc 7 ngay) lon nhat trong cac cuon dang muon; hoa thi ma the tang.\n";
        for (int i = 0; i < soKetQua; i++)
        {
            out << docGia[thuTu[i]]->maThe << " | " << docGia[thuTu[i]]->ho << ' '
                << docGia[thuTu[i]]->ten << " | Qua han: " << soNgay[thuTu[i]] << " ngay | "
                << soCuon[thuTu[i]] << " cuon qua han\n";
        }
        if (soKetQua == 0)
        {
            out << "Khong co doc gia qua han.\n";
        }
        delete[] ds;
        delete[] docGia;
        delete[] soNgay;
        delete[] soCuon;
        delete[] thuTu;
    }
    catch (...)
    {
        delete[] ds;
        delete[] docGia;
        delete[] soNgay;
        delete[] soCuon;
        delete[] thuTu;
        throw;
    }
}
