#include "00_KhaiBaoChung.h"

// [DEMO - CODEX] Phan bo sung cho ban trinh thay.
struct CuonVaDauSach
{
    const CuonSach *cuon = nullptr;
    int viTriDauSach = 0;
};

bool CuonThongKeTruoc(CuonVaDauSach a, CuonVaDauSach b)
{
    return a.cuon->maSach < b.cuon->maSach;
}
void TronCuonThongKe(CuonVaDauSach *a, CuonVaDauSach *tam, int trai, int giua, int phai)
{
    int i = trai, j = giua + 1, k = trai;
    while (i <= giua && j <= phai)
    {
        if (CuonThongKeTruoc(a[j], a[i]))
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
void ChiaCuonThongKe(CuonVaDauSach *a, CuonVaDauSach *tam, int trai, int phai)
{
    if (trai >= phai)
    {
        return;
    }
    int giua = trai + (phai - trai) / 2;
    ChiaCuonThongKe(a, tam, trai, giua);
    ChiaCuonThongKe(a, tam, giua + 1, phai);
    TronCuonThongKe(a, tam, trai, giua, phai);
}
void SapXepCuonThongKe(CuonVaDauSach *a, int soLuong)
{
    if (soLuong < 2)
    {
        return;
    }
    CuonVaDauSach *tam = new CuonVaDauSach[soLuong];
    try
    {
        ChiaCuonThongKe(a, tam, 0, soLuong - 1);
        delete[] tam;
    }
    catch (...)
    {
        delete[] tam;
        throw;
    }
}

int TimDauSachTrongChiMuc(const CuonVaDauSach *ds, int soCuon, const string &ma)
{
    int trai = 0, phai = soCuon - 1;
    while (trai <= phai)
    {
        int giua = trai + (phai - trai) / 2;
        if (ds[giua].cuon->maSach == ma)
        {
            return ds[giua].viTriDauSach;
        }
        if (ds[giua].cuon->maSach < ma)
        {
            trai = giua + 1;
        }
        else
        {
            phai = giua - 1;
        }
    }
    return -1;
}
bool XepHangTruoc(const ThuVien &tv, const int *soLuot, int a, int b)
{
    if (soLuot[a] != soLuot[b])
    {
        return soLuot[a] > soLuot[b];
    }
    int ten = SoSanhChuoi(tv.dsDauSach.ds[a]->tenSach, tv.dsDauSach.ds[b]->tenSach);
    if (ten != 0)
    {
        return ten < 0;
    }
    return tv.dsDauSach.ds[a]->ISBN < tv.dsDauSach.ds[b]->ISBN;
}
void InTop10SachDuocMuonNhieuNhat(const ThuVien &tv, ostream &out)
{
    int soDauSach = tv.dsDauSach.soLuong;
    int soCuon = 0;
    for (int i = 0; i < soDauSach; i++)
    {
        soCuon += DemCuonSach(tv.dsDauSach.ds[i]->dms);
    }
    int soDocGia = DemDocGia(tv.cayDocGia);
    int *soLuot = nullptr;
    const NutDocGia **docGia = nullptr;
    CuonVaDauSach *chiMuc = nullptr;
    try
    {
        soLuot = new int[soDauSach]{};
        docGia = new const NutDocGia *[soDocGia];
        chiMuc = new CuonVaDauSach[soCuon];
        int viTri = 0;
        for (int i = 0; i < soDauSach; i++)
        {
            const CuonSach *p = tv.dsDauSach.ds[i]->dms;
            while (p != nullptr)
            {
                chiMuc[viTri].cuon = p;
                chiMuc[viTri].viTriDauSach = i;
                viTri++;
                p = p->next;
            }
        }
        SapXepCuonThongKe(chiMuc, soCuon);
        LayDanhSachDocGia(tv.cayDocGia, docGia, soDocGia);
        for (int i = 0; i < soDocGia; i++)
        {
            const MuonTra *p = docGia[i]->thongTin.dsMuonTra;
            while (p != nullptr)
            {
                int dauSach = TimDauSachTrongChiMuc(chiMuc, soCuon, p->maSach);
                if (dauSach < 0)
                {
                    throw LoiThuVien("Lich su tham chieu cuon khong ton tai.");
                }
                soLuot[dauSach]++;
                p = p->next;
            }
        }
        int top[10], soHang = 0;
        for (int i = 0; i < soDauSach; i++)
        {
            if (soLuot[i] == 0)
            {
                continue;
            }
            int chen = 0;
            while (chen < soHang && !XepHangTruoc(tv, soLuot, i, top[chen]))
            {
                chen++;
            }
            if (chen == 10)
            {
                continue;
            }
            if (soHang < 10)
            {
                soHang++;
            }
            for (int j = soHang - 1; j > chen; j--)
            {
                top[j] = top[j - 1];
            }
            top[chen] = i;
        }
        out << "TOP TOI DA 10 DAU SACH THEO LUOT MUON\n";
        out << "Moi lan muon tinh 1, gom dang muon/da tra/mat. Hoa: ten tang, roi ISBN tang.\n";
        for (int i = 0; i < soHang; i++)
        {
            out << i + 1 << " | " << tv.dsDauSach.ds[top[i]]->ISBN << " | "
                << tv.dsDauSach.ds[top[i]]->tenSach << " | " << soLuot[top[i]] << " luot\n";
        }
        if (soHang == 0)
        {
            out << "Chua co luot muon nao.\n";
        }
        delete[] soLuot;
        delete[] docGia;
        delete[] chiMuc;
    }
    catch (...)
    {
        delete[] soLuot;
        delete[] docGia;
        delete[] chiMuc;
        throw;
    }
}
