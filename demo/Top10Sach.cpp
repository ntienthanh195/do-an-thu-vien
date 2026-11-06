#include "00_KhaiBaoChung.h"

// [DEMO - CODEX] Phan bo sung cho ban trinh thay.
// [DEMO - CODEX] Sap xep mang vi tri; du lieu nam trong cac mang truyen vao.
bool CuonThongKeTruoc(int a, int b, const CuonSach *const *cuon)
{
    return cuon[a]->maSach < cuon[b]->maSach;
}
void TronCuonThongKe(int *thuTu, int *tam, int trai, int giua, int phai, const CuonSach *const *cuon)
{
    int i = trai, j = giua + 1, k = trai;
    while (i <= giua && j <= phai)
    {
        if (CuonThongKeTruoc(thuTu[j], thuTu[i], cuon))
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
void ChiaCuonThongKe(int *thuTu, int *tam, int trai, int phai, const CuonSach *const *cuon)
{
    if (trai >= phai)
    {
        return;
    }
    int giua = trai + (phai - trai) / 2;
    ChiaCuonThongKe(thuTu, tam, trai, giua, cuon);
    ChiaCuonThongKe(thuTu, tam, giua + 1, phai, cuon);
    TronCuonThongKe(thuTu, tam, trai, giua, phai, cuon);
}
void SapXepCuonThongKe(int *thuTu, int soLuong, const CuonSach *const *cuon)
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
        ChiaCuonThongKe(thuTu, tam, 0, soLuong - 1, cuon);
        delete[] tam;
    }
    catch (...)
    {
        delete[] tam;
        throw;
    }
}

int TimDauSachTrongChiMuc(const CuonSach *const *cuon, const int *viTriDauSach,
                              const int *thuTu, int soCuon, const string &ma)
{
    int trai = 0, phai = soCuon - 1;
    while (trai <= phai)
    {
        int giua = trai + (phai - trai) / 2;
        if (cuon[thuTu[giua]]->maSach == ma)
        {
            return viTriDauSach[thuTu[giua]];
        }
        if (cuon[thuTu[giua]]->maSach < ma)
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
    const CuonSach **cuon = nullptr;
    int *viTriDauSach = nullptr;
    int *thuTu = nullptr;
    try
    {
        soLuot = new int[soDauSach]{};
        docGia = new const NutDocGia *[soDocGia];
        cuon = new const CuonSach *[soCuon];
        viTriDauSach = new int[soCuon];
        thuTu = new int[soCuon];
        int viTri = 0;
        for (int i = 0; i < soDauSach; i++)
        {
            const CuonSach *p = tv.dsDauSach.ds[i]->dms;
            while (p != nullptr)
            {
                cuon[viTri] = p;
                viTriDauSach[viTri] = i;
                viTri++;
                p = p->next;
            }
        }
        SapXepCuonThongKe(thuTu, soCuon, cuon);
        LayDanhSachDocGia(tv.cayDocGia, docGia, soDocGia);
        for (int i = 0; i < soDocGia; i++)
        {
            const MuonTra *p = docGia[i]->thongTin.dsMuonTra;
            while (p != nullptr)
            {
                int dauSach = TimDauSachTrongChiMuc(cuon, viTriDauSach, thuTu, soCuon, p->maSach);
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
        delete[] cuon;
        delete[] viTriDauSach;
        delete[] thuTu;
    }
    catch (...)
    {
        delete[] soLuot;
        delete[] docGia;
        delete[] cuon;
        delete[] viTriDauSach;
        delete[] thuTu;
        throw;
    }
}
