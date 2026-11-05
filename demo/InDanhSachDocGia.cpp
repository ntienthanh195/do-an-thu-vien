#include "00_KhaiBaoChung.h"

// [DEMO - CODEX] Phan bo sung cho ban trinh thay.
void InThongTinDocGia(const DocGia &docGia, ostream &out)
{
    out << docGia.maThe << " | " << docGia.ho << " | " << docGia.ten << " | " << docGia.phai
        << " | ";
    if (docGia.trangThaiThe == THE_HOAT_DONG)
    {
        out << "Hoat dong";
    }
    else
    {
        out << "Khoa";
    }
    out << '\n';
}

bool DocGiaTheoTenHoTruoc(const NutDocGia *a, const NutDocGia *b)
{

    int ten = SoSanhChuoi(a->thongTin.ten, b->thongTin.ten);
    if (ten != 0)
    {
        return ten < 0;
    }
    int ho = SoSanhChuoi(a->thongTin.ho, b->thongTin.ho);
    if (ho != 0)
    {
        return ho < 0;
    }
    return a->thongTin.maThe < b->thongTin.maThe;
}
void TronDocGiaTheoTenHo(const NutDocGia **a, const NutDocGia **tam, int trai, int giua, int phai)
{
    int i = trai, j = giua + 1, k = trai;
    while (i <= giua && j <= phai)
    {
        if (DocGiaTheoTenHoTruoc(a[j], a[i]))
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
void ChiaDocGiaTheoTenHo(const NutDocGia **a, const NutDocGia **tam, int trai, int phai)
{
    if (trai >= phai)
    {
        return;
    }
    int giua = trai + (phai - trai) / 2;
    ChiaDocGiaTheoTenHo(a, tam, trai, giua);
    ChiaDocGiaTheoTenHo(a, tam, giua + 1, phai);
    TronDocGiaTheoTenHo(a, tam, trai, giua, phai);
}
void SapXepDocGiaTheoTenHo(const NutDocGia **a, int soLuong)
{
    if (soLuong < 2)
    {
        return;
    }
    const NutDocGia **tam = new const NutDocGia *[soLuong];
    try
    {
        ChiaDocGiaTheoTenHo(a, tam, 0, soLuong - 1);
        delete[] tam;
    }
    catch (...)
    {
        delete[] tam;
        throw;
    }
}

void InDocGiaTheoMa(const ThuVien &tv, ostream &out)
{
    int soLuong = DemDocGia(tv.cayDocGia);
    const NutDocGia **ds = new const NutDocGia *[soLuong];
    try
    {
        LayDanhSachDocGia(tv.cayDocGia, ds, soLuong);
        out << "MA THE | HO | TEN | PHAI | THE\n";
        for (int i = 0; i < soLuong; i++)
        {
            InThongTinDocGia(ds[i]->thongTin, out);
        }
        if (soLuong == 0)
        {
            out << "Danh sach rong.\n";
        }
        delete[] ds;
    }
    catch (...)
    {
        delete[] ds;
        throw;
    }
}
void InDocGiaTheoTenHo(const ThuVien &tv, ostream &out)
{
    int soLuong = DemDocGia(tv.cayDocGia);
    const NutDocGia **ds = new const NutDocGia *[soLuong];
    try
    {
        LayDanhSachDocGia(tv.cayDocGia, ds, soLuong);
        SapXepDocGiaTheoTenHo(ds, soLuong);
        out << "MA THE | HO | TEN | PHAI | THE (TEN + HO)\n";
        for (int i = 0; i < soLuong; i++)
        {
            InThongTinDocGia(ds[i]->thongTin, out);
        }
        if (soLuong == 0)
        {
            out << "Danh sach rong.\n";
        }
        delete[] ds;
    }
    catch (...)
    {
        delete[] ds;
        throw;
    }
}
