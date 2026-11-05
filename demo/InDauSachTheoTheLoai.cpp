#include "00_KhaiBaoChung.h"

// [DEMO - CODEX] Phan bo sung cho ban trinh thay.
static bool DauSachDungTruoc(const DauSach &a, const DauSach &b)
{
    int ten = SoSanhChuoi(a.tenSach, b.tenSach);
    if (ten != 0) return ten < 0;
    return a.ISBN < b.ISBN;
}

void InDauSachTheoTheLoai(const ThuVien &tv, ostream &out)
{
    int soLuong = tv.dsDauSach.soLuong;
    if (soLuong == 0)
    {
        out << "Danh sach dau sach rong.\n";
        return;
    }
    const DauSach **tam = new const DauSach *[soLuong];
    try
    {
        for (int i = 0; i < soLuong; i++)
        {
            tam[i] = tv.dsDauSach.ds[i];
        }
        // Sap xep chen: don tung con tro de chen dau sach dang xet.
        for (int i = 1; i < soLuong; i++)
        {
            const DauSach *dangChen = tam[i];
            int j = i - 1;
            while (j >= 0)
            {
                int soSanh = SoSanhChuoi(tam[j]->theLoai, dangChen->theLoai);
                if (soSanh < 0)
                {
                    break;
                }
                if (soSanh == 0 && !DauSachDungTruoc(*dangChen, *tam[j]))
                {
                    break;
                }
                tam[j + 1] = tam[j];
                j--;
            }
            tam[j + 1] = dangChen;
        }
        for (int i = 0; i < soLuong; i++)
        {
            if (i == 0 || SoSanhChuoi(tam[i - 1]->theLoai, tam[i]->theLoai) != 0)
            {
                out << "\nTHE LOAI: " << tam[i]->theLoai << '\n';
            }
            InThongTinDauSach(*tam[i], out, false);
        }
        delete[] tam;
    }
    catch (...)
    {
        delete[] tam;
        throw;
    }
}
