#include "00_KhaiBaoChung.h"

// [DEMO - CODEX] Phan bo sung cho ban trinh thay.
// Doc/ghi v1 bang fstream va cac ham thuong. Kho dang dung chi doi khi kho tam hop le.
bool BaoLoiFile(string &loi, const string &noiDung)
{
    loi = noiDung;
    return false;
}
bool DocDongFile(ifstream &file, string &dong, int &soDong, string &loi)
{
    dong.clear();
    soDong++;
    char kyTu;
    bool daDoc = false;
    while (file.get(kyTu))
    {
        daDoc = true;
        if (kyTu == '\n')
        {
            break;
        }
        if (dong.size() >= 65536)
        {
            return BaoLoiFile(loi, "Dong qua dai.");
        }
        if (kyTu == 0)
        {
            return BaoLoiFile(loi, "Dong chua ky tu NUL.");
        }
        dong += kyTu;
    }
    if (file.bad())
    {
        return BaoLoiFile(loi, "Loi doc file.");
    }
    if (!daDoc)
    {
        return BaoLoiFile(loi, "File ket thuc som o dong " + ChuoiSo(soDong));
    }
    if (!dong.empty() && dong[dong.size() - 1] == '\r')
    {
        dong.pop_back();
    }
    if (soDong == 1 && dong.size() >= 3 && dong[0] == char(0xEF) && dong[1] == char(0xBB) &&
        dong[2] == char(0xBF))
    {
        dong = CatChuoi(dong, 3, string::npos);
    }
    if (!dong.empty() && MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, dong.data(),
                                             int(dong.size()), nullptr, 0) == 0)
    {
        return BaoLoiFile(loi, "Du lieu khong phai UTF-8.");
    }
    return true;
}
bool DocSoFile(ifstream &file, int &so, int lonNhat, int &soDong, string &loi)
{
    string dong;
    if (!DocDongFile(file, dong, soDong, loi))
    {
        return false;
    }
    if (!DocSoNguyen(dong, so, 0, lonNhat))
    {
        return BaoLoiFile(loi, "So dem khong hop le o dong " + ChuoiSo(soDong));
    }
    return true;
}
bool DocTruongFile(ifstream &file, string *truong, int soTruong, int &soDong, string &loi)
{
    string dong;
    if (!DocDongFile(file, dong, soDong, loi))
    {
        return false;
    }
    if (!TachTruong(dong, truong, soTruong))
    {
        return BaoLoiFile(loi, "Sai so truong o dong " + ChuoiSo(soDong));
    }
    return true;
}

bool ISBNKiemTraTruoc(const DauSach *a, const DauSach *b)
{
    return a->ISBN < b->ISBN;
}
void TronISBNKiemTra(const DauSach **a, const DauSach **tam, int trai, int giua, int phai)
{
    int i = trai, j = giua + 1, k = trai;
    while (i <= giua && j <= phai)
    {
        if (ISBNKiemTraTruoc(a[j], a[i]))
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
void ChiaISBNKiemTra(const DauSach **a, const DauSach **tam, int trai, int phai)
{
    if (trai >= phai)
    {
        return;
    }
    int giua = trai + (phai - trai) / 2;
    ChiaISBNKiemTra(a, tam, trai, giua);
    ChiaISBNKiemTra(a, tam, giua + 1, phai);
    TronISBNKiemTra(a, tam, trai, giua, phai);
}
void SapXepISBNKiemTra(const DauSach **a, int soLuong)
{
    if (soLuong < 2)
    {
        return;
    }
    const DauSach **tam = new const DauSach *[soLuong];
    try
    {
        ChiaISBNKiemTra(a, tam, 0, soLuong - 1);
        delete[] tam;
    }
    catch (...)
    {
        delete[] tam;
        throw;
    }
}

bool MaCuonKiemTraTruoc(const CuonSach *a, const CuonSach *b)
{
    return a->maSach < b->maSach;
}
void TronMaCuonKiemTra(const CuonSach **a, const CuonSach **tam, int trai, int giua, int phai)
{
    int i = trai, j = giua + 1, k = trai;
    while (i <= giua && j <= phai)
    {
        if (MaCuonKiemTraTruoc(a[j], a[i]))
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
void ChiaMaCuonKiemTra(const CuonSach **a, const CuonSach **tam, int trai, int phai)
{
    if (trai >= phai)
    {
        return;
    }
    int giua = trai + (phai - trai) / 2;
    ChiaMaCuonKiemTra(a, tam, trai, giua);
    ChiaMaCuonKiemTra(a, tam, giua + 1, phai);
    TronMaCuonKiemTra(a, tam, trai, giua, phai);
}
void SapXepMaCuonKiemTra(const CuonSach **a, int soLuong)
{
    if (soLuong < 2)
    {
        return;
    }
    const CuonSach **tam = new const CuonSach *[soLuong];
    try
    {
        ChiaMaCuonKiemTra(a, tam, 0, soLuong - 1);
        delete[] tam;
    }
    catch (...)
    {
        delete[] tam;
        throw;
    }
}

// [DEMO - CODEX] Sap xep mang vi tri; du lieu nam trong cac mang truyen vao.
bool LuotTheoCuonTruoc(int a, int b, const int *viTriCuon, const int *ngayMuon, const int *ngayKetThuc,
    const int *trangThaiLuot, const int *maTheLuot)
{
    if (viTriCuon[a] != viTriCuon[b])
    {
        return viTriCuon[a] < viTriCuon[b];
    }
    if (ngayMuon[a] != ngayMuon[b])
    {
        return ngayMuon[a] < ngayMuon[b];
    }
    if (ngayKetThuc[a] != ngayKetThuc[b])
    {
        return ngayKetThuc[a] < ngayKetThuc[b];
    }
    if (trangThaiLuot[a] != trangThaiLuot[b])
    {
        return trangThaiLuot[a] < trangThaiLuot[b];
    }
    return maTheLuot[a] < maTheLuot[b];
}
void TronLuotTheoCuon(int *thuTu, int *tam, int trai, int giua, int phai, const int *viTriCuon,
    const int *ngayMuon, const int *ngayKetThuc, const int *trangThaiLuot, const int *maTheLuot)
{
    int i = trai, j = giua + 1, k = trai;
    while (i <= giua && j <= phai)
    {
        if (LuotTheoCuonTruoc(thuTu[j], thuTu[i], viTriCuon, ngayMuon, ngayKetThuc, trangThaiLuot, maTheLuot))
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
void ChiaLuotTheoCuon(int *thuTu, int *tam, int trai, int phai, const int *viTriCuon, const int *ngayMuon,
    const int *ngayKetThuc, const int *trangThaiLuot, const int *maTheLuot)
{
    if (trai >= phai)
    {
        return;
    }
    int giua = trai + (phai - trai) / 2;
    ChiaLuotTheoCuon(thuTu, tam, trai, giua, viTriCuon, ngayMuon, ngayKetThuc, trangThaiLuot, maTheLuot);
    ChiaLuotTheoCuon(thuTu, tam, giua + 1, phai, viTriCuon, ngayMuon, ngayKetThuc, trangThaiLuot, maTheLuot);
    TronLuotTheoCuon(thuTu, tam, trai, giua, phai, viTriCuon, ngayMuon, ngayKetThuc, trangThaiLuot, maTheLuot);
}
void SapXepLuotTheoCuon(int *thuTu, int soLuong, const int *viTriCuon, const int *ngayMuon,
    const int *ngayKetThuc, const int *trangThaiLuot, const int *maTheLuot)
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
        ChiaLuotTheoCuon(thuTu, tam, 0, soLuong - 1, viTriCuon, ngayMuon, ngayKetThuc, trangThaiLuot, maTheLuot);
        delete[] tam;
    }
    catch (...)
    {
        delete[] tam;
        throw;
    }
}

// [DEMO - CODEX] Sap xep mang vi tri; du lieu nam trong cac mang truyen vao.
bool MocTheoDocGiaTruoc(int a, int b, const int *maTheMoc, const int *ngayMoc, const int *loaiMoc)
{
    if (maTheMoc[a] != maTheMoc[b])
    {
        return maTheMoc[a] < maTheMoc[b];
    }
    if (ngayMoc[a] != ngayMoc[b])
    {
        return ngayMoc[a] < ngayMoc[b];
    }
    return loaiMoc[a] < loaiMoc[b];
}
void TronMocTheoDocGia(int *thuTu, int *tam, int trai, int giua, int phai, const int *maTheMoc,
    const int *ngayMoc, const int *loaiMoc)
{
    int i = trai, j = giua + 1, k = trai;
    while (i <= giua && j <= phai)
    {
        if (MocTheoDocGiaTruoc(thuTu[j], thuTu[i], maTheMoc, ngayMoc, loaiMoc))
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
void ChiaMocTheoDocGia(int *thuTu, int *tam, int trai, int phai, const int *maTheMoc, const int *ngayMoc,
    const int *loaiMoc)
{
    if (trai >= phai)
    {
        return;
    }
    int giua = trai + (phai - trai) / 2;
    ChiaMocTheoDocGia(thuTu, tam, trai, giua, maTheMoc, ngayMoc, loaiMoc);
    ChiaMocTheoDocGia(thuTu, tam, giua + 1, phai, maTheMoc, ngayMoc, loaiMoc);
    TronMocTheoDocGia(thuTu, tam, trai, giua, phai, maTheMoc, ngayMoc, loaiMoc);
}
void SapXepMocTheoDocGia(int *thuTu, int soLuong, const int *maTheMoc, const int *ngayMoc, const int *loaiMoc)
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
        ChiaMocTheoDocGia(thuTu, tam, 0, soLuong - 1, maTheMoc, ngayMoc, loaiMoc);
        delete[] tam;
    }
    catch (...)
    {
        delete[] tam;
        throw;
    }
}

bool TenSachFileTruoc(DauSach *a, DauSach *b)
{

    int ten = SoSanhChuoi(a->tenSach, b->tenSach);
    if (ten != 0)
    {
        return ten < 0;
    }
    return a->ISBN < b->ISBN;
}
void TronTenSachFile(DauSach **a, DauSach **tam, int trai, int giua, int phai)
{
    int i = trai, j = giua + 1, k = trai;
    while (i <= giua && j <= phai)
    {
        if (TenSachFileTruoc(a[j], a[i]))
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
void ChiaTenSachFile(DauSach **a, DauSach **tam, int trai, int phai)
{
    if (trai >= phai)
    {
        return;
    }
    int giua = trai + (phai - trai) / 2;
    ChiaTenSachFile(a, tam, trai, giua);
    ChiaTenSachFile(a, tam, giua + 1, phai);
    TronTenSachFile(a, tam, trai, giua, phai);
}
void SapXepTenSachFile(DauSach **a, int soLuong)
{
    if (soLuong < 2)
    {
        return;
    }
    DauSach **tam = new DauSach *[soLuong];
    try
    {
        ChiaTenSachFile(a, tam, 0, soLuong - 1);
        delete[] tam;
    }
    catch (...)
    {
        delete[] tam;
        throw;
    }
}

bool MaTheFileTruoc(NutDocGia *a, NutDocGia *b)
{
    return a->thongTin.maThe < b->thongTin.maThe;
}
void TronMaTheFile(NutDocGia **a, NutDocGia **tam, int trai, int giua, int phai)
{
    int i = trai, j = giua + 1, k = trai;
    while (i <= giua && j <= phai)
    {
        if (MaTheFileTruoc(a[j], a[i]))
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
void ChiaMaTheFile(NutDocGia **a, NutDocGia **tam, int trai, int phai)
{
    if (trai >= phai)
    {
        return;
    }
    int giua = trai + (phai - trai) / 2;
    ChiaMaTheFile(a, tam, trai, giua);
    ChiaMaTheFile(a, tam, giua + 1, phai);
    TronMaTheFile(a, tam, trai, giua, phai);
}
void SapXepMaTheFile(NutDocGia **a, int soLuong)
{
    if (soLuong < 2)
    {
        return;
    }
    NutDocGia **tam = new NutDocGia *[soLuong];
    try
    {
        ChiaMaTheFile(a, tam, 0, soLuong - 1);
        delete[] tam;
    }
    catch (...)
    {
        delete[] tam;
        throw;
    }
}

int TimCuonTrongMangKiemTra(const CuonSach *const *ds, int soCuon, const string &ma)
{
    int trai = 0, phai = soCuon - 1;
    while (trai <= phai)
    {
        int giua = trai + (phai - trai) / 2;
        if (ds[giua]->maSach == ma)
        {
            return giua;
        }
        if (ds[giua]->maSach < ma)
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
bool MaCuonDungChuSoHuu(const string &ma, const string &isbn)
{
    size_t dauThang = ma.size();
    for (size_t i = 0; i < ma.size(); i++)
    {
        if (ma[i] == '#')
        {
            dauThang = i;
        }
    }
    if (dauThang == ma.size())
    {
        return true;
    }
    if (dauThang == 0 || dauThang + 1 == ma.size() || ma[dauThang + 1] == '0')
    {
        return false;
    }
    int so = 0;
    return CatChuoi(ma, 0, dauThang) == isbn &&
           DocSoNguyen(CatChuoi(ma, dauThang + 1, string::npos), so, 1, INT_MAX);
}
bool KiemTraCacDanhSach(const ThuVien &tv, const DauSach **dauSach,
                           const CuonSach **cuonSach,
                           const NutDocGia **docGiaTrongCay,
                           int *viTriCuon,
                           int *ngayMuon,
                           int *ngayKetThuc,
                           int *trangThaiLuot,
                           int *maTheLuot,
                           int *thuTuLuot,
                           int *maTheMoc,
                           int *ngayMoc,
                           int *loaiMoc,
                           int *thuTuMoc,
                           int *soDangMuon, string &loi)
{
    int soDauSach = tv.dsDauSach.soLuong;
    if (soDauSach < 0 || soDauSach > MAX_DAU_SACH || tv.maTheLonNhatDaCap < 0)
    {
        return BaoLoiFile(loi, "So dau sach/moc ma the khong hop le.");
    }
    int soCuon = 0;
    for (int i = 0; i < soDauSach; i++)
    {
        const DauSach *sach = tv.dsDauSach.ds[i];
        if (sach == nullptr)
        {
            return BaoLoiFile(loi, "Con tro dau sach rong.");
        }
        if (!HopLeDauSach(*sach, loi))
        {
            return false;
        }
        if (sach->ISBN != ChuanHoaChuoiSach(sach->ISBN))
        {
            return BaoLoiFile(loi, "ISBN chua chuan hoa khoang trang");
        }
        if (i > 0 && TenSachFileTruoc(tv.dsDauSach.ds[i], tv.dsDauSach.ds[i - 1]))
        {
            return BaoLoiFile(loi, "Mang dau sach chua theo ten.");
        }
        dauSach[i] = sach;
        const CuonSach *p = sach->dms;
        while (p != nullptr)
        {
            if (soCuon == MAX_BAN_GHI)
            {
                return BaoLoiFile(loi, "Qua nhieu cuon hoac danh sach bi vong.");
            }
            if (!KiemTraVanBanHeThong(p->maSach) || !KiemTraVanBanHeThong(p->viTri) ||
                !HopLeTrangThaiSach(p->trangThai))
            {
                return BaoLoiFile(loi, "Cuon sach khong hop le.");
            }
            if (p->maSach != ChuanHoaChuoiSach(p->maSach))
            {
                return BaoLoiFile(loi, "Ma cuon chua chuan hoa khoang trang");
            }
            if (!MaCuonDungChuSoHuu(p->maSach, sach->ISBN))
            {
                return BaoLoiFile(loi, "Ma cuon khong thuoc dau sach.");
            }
            cuonSach[soCuon] = p;
            soCuon++;
            p = p->next;
        }
    }
    SapXepISBNKiemTra(dauSach, soDauSach);
    for (int i = 1; i < soDauSach; i++)
    {
        if (dauSach[i - 1]->ISBN == dauSach[i]->ISBN)
        {
            return BaoLoiFile(loi, "Trung ISBN.");
        }
    }
    SapXepMaCuonKiemTra(cuonSach, soCuon);
    for (int i = 1; i < soCuon; i++)
    {
        if (cuonSach[i - 1]->maSach == cuonSach[i]->maSach)
        {
            return BaoLoiFile(loi, "Trung ma cuon.");
        }
    }

    int soDocGia = LayDanhSachDocGia(tv.cayDocGia, docGiaTrongCay, MAX_DOC_GIA);
    int soLuot = 0, soMoc = 0;
    int homNay = SoThuTuNgay(HomNay());
    for (int i = 0; i < soDocGia; i++)
    {
        const DocGia &docGia = docGiaTrongCay[i]->thongTin;
        if (docGia.maThe <= 0 || docGia.maThe > tv.maTheLonNhatDaCap)
        {
            return BaoLoiFile(loi, "Ma the vuot moc da cap.");
        }
        if (i > 0 && docGiaTrongCay[i - 1]->thongTin.maThe >= docGia.maThe)
        {
            return BaoLoiFile(loi, "BST sai thu tu hoac trung ma the.");
        }
        if (!HopLeVanBan(docGia.ho) || !HopLeVanBan(docGia.ten) || !HopLePhai(docGia.phai) ||
            !HopLeTrangThaiThe(docGia.trangThaiThe))
        {
            return BaoLoiFile(loi, "Thong tin doc gia khong hop le.");
        }
        const MuonTra *p = docGia.dsMuonTra;
        int dangGiu = 0;
        while (p != nullptr)
        {
            if (soLuot == MAX_BAN_GHI)
            {
                return BaoLoiFile(loi, "Qua nhieu luot muon hoac danh sach bi vong.");
            }
            if (!KiemTraVanBanHeThong(p->maSach) || !HopLeTrangThaiMuonTra(p->trangThai) ||
                !NgayHopLe(p->ngayMuon))
            {
                return BaoLoiFile(loi, "Luot muon khong hop le.");
            }
            if (p->maSach != ChuanHoaChuoiSach(p->maSach))
            {
                return BaoLoiFile(loi, "Ma cuon trong lich su chua chuan hoa khoang trang");
            }
            int cuon = TimCuonTrongMangKiemTra(cuonSach, soCuon, p->maSach);
            if (cuon < 0)
            {
                return BaoLoiFile(loi, "Lich su tham chieu cuon khong ton tai.");
            }
            int batDau = SoThuTuNgay(p->ngayMuon);
            if (batDau > homNay)
            {
                return BaoLoiFile(loi, "Ngay muon trong tuong lai.");
            }
            int ketThuc = INT_MAX;
            if (p->trangThai == MUON_DANG_MUON)
            {
                if (!NgayRong(p->ngayTra))
                {
                    return BaoLoiFile(loi, "Dang muon phai co ngay tra rong.");
                }
                dangGiu++;
                soDangMuon[cuon]++;
                if (dangGiu > 3 || soDangMuon[cuon] > 1)
                {
                    return BaoLoiFile(loi, "Vuot ba cuon hoac trung luot dang muon.");
                }
            }
            else
            {
                if (!NgayHopLe(p->ngayTra))
                {
                    return BaoLoiFile(loi, "Ngay tra khong hop le.");
                }
                ketThuc = SoThuTuNgay(p->ngayTra);
                if (ketThuc < batDau || ketThuc > homNay)
                {
                    return BaoLoiFile(loi, "Ngay tra sai thu tu.");
                }
                if (p->trangThai == MUON_LAM_MAT &&
                    (docGia.trangThaiThe != THE_BI_KHOA ||
                     cuonSach[cuon]->trangThai != SACH_THANH_LY))
                {
                    return BaoLoiFile(loi, "Luot mat phai gan the khoa va cuon thanh ly.");
                }
            }
            viTriCuon[soLuot] = cuon;
            maTheLuot[soLuot] = docGia.maThe;
            ngayMuon[soLuot] = batDau;
            ngayKetThuc[soLuot] = ketThuc;
            trangThaiLuot[soLuot] = p->trangThai;
            soLuot++;

            maTheMoc[soMoc] = docGia.maThe;
            ngayMoc[soMoc] = batDau;
            loaiMoc[soMoc] = 2;
            if (batDau == ketThuc)
            {
                loaiMoc[soMoc] = 1;
            }
            soMoc++;
            if (ketThuc != INT_MAX && ketThuc != batDau)
            {
                maTheMoc[soMoc] = docGia.maThe;
                ngayMoc[soMoc] = ketThuc;
                loaiMoc[soMoc] = 0;
                soMoc++;
            }
            p = p->next;
        }
    }
    for (int i = 0; i < soCuon; i++)
    {
        if ((cuonSach[i]->trangThai == SACH_DANG_MUON) != (soDangMuon[i] == 1))
        {
            return BaoLoiFile(loi, "Trang thai cuon khong khop lich su.");
        }
    }
    SapXepLuotTheoCuon(thuTuLuot, soLuot, viTriCuon, ngayMuon, ngayKetThuc, trangThaiLuot, maTheLuot);
    for (int i = 1; i < soLuot; i++)
    {
        if (viTriCuon[thuTuLuot[i - 1]] == viTriCuon[thuTuLuot[i]])
        {
            if (trangThaiLuot[thuTuLuot[i - 1]] != MUON_DA_TRA ||
                ngayKetThuc[thuTuLuot[i - 1]] > ngayMuon[thuTuLuot[i]])
            {
                return BaoLoiFile(loi, "Lich su chong lan hoac muon lai sau bao mat.");
            }
        }
    }
    SapXepMocTheoDocGia(thuTuMoc, soMoc, maTheMoc, ngayMoc, loaiMoc);
    int maDangXet = 0, soDangGiu = 0;
    for (int i = 0; i < soMoc; i++)
    {
        if (maTheMoc[thuTuMoc[i]] != maDangXet)
        {
            maDangXet = maTheMoc[thuTuMoc[i]];
            soDangGiu = 0;
        }
        if (loaiMoc[thuTuMoc[i]] == 0)
        {
            soDangGiu--;
        }
        else if (loaiMoc[thuTuMoc[i]] == 2)
        {
            soDangGiu++;
        }
        else if (soDangGiu == 3)
        {
            return BaoLoiFile(loi, "Luot muon-tra cung ngay vuot ba cuon.");
        }
        if (soDangGiu < 0 || soDangGiu > 3)
        {
            return BaoLoiFile(loi, "Lich su tung vuot ba cuon cung luc.");
        }
    }
    loi.clear();
    return true;
}
// [DEMO - CODEX] Moi mang giu mot loai du lieu kiem tra, cung chi so la cung ban ghi.
bool KiemTraToanVen(const ThuVien &tv, string &loi)
{
    const DauSach **dauSach = nullptr;
    const CuonSach **cuonSach = nullptr;
    const NutDocGia **docGiaTrongCay = nullptr;
    int *viTriCuon = nullptr;
    int *ngayMuon = nullptr;
    int *ngayKetThuc = nullptr;
    int *trangThaiLuot = nullptr;
    int *maTheLuot = nullptr;
    int *thuTuLuot = nullptr;
    int *maTheMoc = nullptr;
    int *ngayMoc = nullptr;
    int *loaiMoc = nullptr;
    int *thuTuMoc = nullptr;
    int *soDangMuon = nullptr;
    bool dung = false;
    try
    {
        dauSach = new const DauSach *[MAX_DAU_SACH];
        cuonSach = new const CuonSach *[MAX_BAN_GHI];
        docGiaTrongCay = new const NutDocGia *[MAX_DOC_GIA];
        viTriCuon = new int[MAX_BAN_GHI];
        ngayMuon = new int[MAX_BAN_GHI];
        ngayKetThuc = new int[MAX_BAN_GHI];
        trangThaiLuot = new int[MAX_BAN_GHI];
        maTheLuot = new int[MAX_BAN_GHI];
        thuTuLuot = new int[MAX_BAN_GHI];
        maTheMoc = new int[MAX_BAN_GHI * 2];
        ngayMoc = new int[MAX_BAN_GHI * 2];
        loaiMoc = new int[MAX_BAN_GHI * 2];
        thuTuMoc = new int[MAX_BAN_GHI * 2];
        soDangMuon = new int[MAX_BAN_GHI]{};
        dung = KiemTraCacDanhSach(tv, dauSach, cuonSach, docGiaTrongCay, viTriCuon, ngayMuon, ngayKetThuc,
            trangThaiLuot, maTheLuot, thuTuLuot, maTheMoc, ngayMoc, loaiMoc, thuTuMoc, soDangMuon, loi);
    }
    catch (...)
    {
        delete[] dauSach;
        delete[] cuonSach;
        delete[] docGiaTrongCay;
        delete[] viTriCuon;
        delete[] ngayMuon;
        delete[] ngayKetThuc;
        delete[] trangThaiLuot;
        delete[] maTheLuot;
        delete[] thuTuLuot;
        delete[] maTheMoc;
        delete[] ngayMoc;
        delete[] loaiMoc;
        delete[] thuTuMoc;
        delete[] soDangMuon;
        loi = "Khong du bo nho hoac loi khi kiem tra du lieu.";
        return false;
    }
    delete[] dauSach;
    delete[] cuonSach;
    delete[] docGiaTrongCay;
    delete[] viTriCuon;
    delete[] ngayMuon;
    delete[] ngayKetThuc;
    delete[] trangThaiLuot;
    delete[] maTheLuot;
    delete[] thuTuLuot;
    delete[] maTheMoc;
    delete[] ngayMoc;
    delete[] loaiMoc;
    delete[] thuTuMoc;
    delete[] soDangMuon;
    return dung;
}
NutDocGia *DungCayTuMang(NutDocGia **ds, int trai, int phai)
{
    if (trai > phai)
    {
        return nullptr;
    }
    int giua = trai + (phai - trai) / 2;
    NutDocGia *p = ds[giua];
    p->left = DungCayTuMang(ds, trai, giua - 1);
    p->right = DungCayTuMang(ds, giua + 1, phai);
    int traiCao = p->left ? p->left->height : 0;
    int phaiCao = p->right ? p->right->height : 0;
    p->height = 1 + (traiCao > phaiCao ? traiCao : phaiCao);
    return p;
}
bool DocSachTuFile(ifstream &file, ThuVien &tam, int &soDong, string &loi)
{
    int soDauSach = 0, tongCuon = 0;
    if (!DocSoFile(file, soDauSach, MAX_DAU_SACH, soDong, loi))
    {
        return false;
    }
    for (int i = 0; i < soDauSach; i++)
    {
        string truong[7];
        if (!DocTruongFile(file, truong, 7, soDong, loi))
        {
            return false;
        }
        DauSach sach;
        sach.ISBN = truong[0];
        sach.tenSach = truong[1];
        sach.tacGia = truong[3];
        sach.theLoai = truong[5];
        int soCuon = 0;
        if (!DocSoNguyen(truong[2], sach.soTrang, 1, INT_MAX) ||
            !DocSoNguyen(truong[4], sach.namXuatBan, 1, 9999) ||
            !DocSoNguyen(truong[6], soCuon, 0, MAX_BAN_GHI - tongCuon))
        {
            return BaoLoiFile(loi, "So lieu dau sach khong hop le.");
        }
        DauSach *moi = new DauSach(sach);
        tam.dsDauSach.ds[tam.dsDauSach.soLuong] = moi;
        tam.dsDauSach.soLuong++;
        CuonSach *cuoi = nullptr;
        for (int j = 0; j < soCuon; j++)
        {
            string cuon[3];
            if (!DocTruongFile(file, cuon, 3, soDong, loi))
            {
                return false;
            }
            CuonSach duLieu;
            duLieu.maSach = cuon[0];
            duLieu.viTri = cuon[2];
            if (!DocSoNguyen(cuon[1], duLieu.trangThai, SACH_CHO_MUON, SACH_THANH_LY))
            {
                return BaoLoiFile(loi, "Trang thai cuon sai.");
            }
            CuonSach *p = new CuonSach(duLieu);
            if (cuoi == nullptr)
            {
                moi->dms = p;
            }
            else
            {
                cuoi->next = p;
            }
            cuoi = p;
            tongCuon++;
        }
    }
    SapXepTenSachFile(tam.dsDauSach.ds, tam.dsDauSach.soLuong);
    return true;
}
bool DocCacNutDocGia(ifstream &file, ThuVien &tam, NutDocGia **ds, int soDocGia, int &soDong,
                     string &loi, int &daDoc)
{
    int tongLuot = 0;
    for (int i = 0; i < soDocGia; i++)
    {
        string truong[6];
        if (!DocTruongFile(file, truong, 6, soDong, loi))
        {
            return false;
        }
        DocGia docGia;
        docGia.ho = truong[1];
        docGia.ten = truong[2];
        docGia.phai = truong[3];
        int soLuot = 0;
        if (!DocSoNguyen(truong[0], docGia.maThe, 1, INT_MAX) ||
            !DocSoNguyen(truong[4], docGia.trangThaiThe, THE_BI_KHOA, THE_HOAT_DONG) ||
            !DocSoNguyen(truong[5], soLuot, 0, MAX_BAN_GHI - tongLuot))
        {
            return BaoLoiFile(loi, "So lieu doc gia sai.");
        }
        NutDocGia *p = new NutDocGia;
        ds[i] = p;
        ++daDoc;
        p->thongTin = docGia;
        MuonTra *cuoi = nullptr;
        for (int j = 0; j < soLuot; j++)
        {
            string luot[4];
            if (!DocTruongFile(file, luot, 4, soDong, loi))
            {
                return false;
            }
            MuonTra lichSu;
            lichSu.maSach = luot[0];
            if (!DocNgay(luot[1], lichSu.ngayMuon) || !DocNgay(luot[2], lichSu.ngayTra) ||
                !DocSoNguyen(luot[3], lichSu.trangThai, MUON_DANG_MUON, MUON_LAM_MAT))
            {
                return BaoLoiFile(loi, "Ngay/trang thai luot muon sai.");
            }
            MuonTra *moi = new MuonTra(lichSu);
            if (cuoi == nullptr)
            {
                p->thongTin.dsMuonTra = moi;
            }
            else
            {
                cuoi->next = moi;
            }
            cuoi = moi;
            tongLuot++;
        }
    }
    SapXepMaTheFile(ds, soDocGia);
    for (int i = 1; i < soDocGia; i++)
    {
        if (ds[i - 1]->thongTin.maThe == ds[i]->thongTin.maThe)
        {
            return BaoLoiFile(loi, "Trung ma the.");
        }
    }
    tam.cayDocGia.root = DungCayTuMang(ds, 0, soDocGia - 1);
    daDoc = 0;
    return true;
}
void HuyCacNutChuaGhep(NutDocGia **ds, int daDoc)
{
    for (int i = 0; i < daDoc; i++)
    {
        HuyDanhSachMuonTra(*ds[i]);
        delete ds[i];
        ds[i] = nullptr;
    }
}
bool DocDocGiaTuFile(ifstream &file, ThuVien &tam, NutDocGia **ds, int soDocGia,
                     int &soDong, string &loi)
{
    int daDoc = 0;
    try
    {
        bool dung = DocCacNutDocGia(file, tam, ds, soDocGia, soDong, loi, daDoc);
        HuyCacNutChuaGhep(ds, daDoc);
        return dung;
    }
    catch (...)
    {
        HuyCacNutChuaGhep(ds, daDoc);
        throw;
    }
}
bool DocFile(ThuVien &tv, const string &path, string &loi)
{
    NutDocGia **ds = nullptr;
    try
    {
        ifstream file(DuongDanUTF16(path).c_str(), ios::binary);
        if (!file)
        {
            return BaoLoiFile(loi, "Khong mo duoc file: " + path);
        }
        ThuVien tam;
        int soDong = 0, soDocGia = 0;
        if (!DocSoFile(file, tam.maTheLonNhatDaCap, INT_MAX, soDong, loi))
        {
            return false;
        }
        if (!DocSachTuFile(file, tam, soDong, loi))
        {
            return false;
        }
        if (!DocSoFile(file, soDocGia, MAX_DOC_GIA, soDong, loi))
        {
            return false;
        }
        ds = new NutDocGia *[soDocGia];
        bool docDu = DocDocGiaTuFile(file, tam, ds, soDocGia, soDong, loi);
        delete[] ds;
        ds = nullptr;
        if (!docDu)
        {
            return false;
        }
        char du;
        if (file.get(du))
        {
            return BaoLoiFile(loi, "Du lieu du cuoi file.");
        }
        if (file.bad())
        {
            return BaoLoiFile(loi, "Loi doc cuoi file.");
        }
        if (!KiemTraToanVen(tam, loi))
        {
            return false;
        }
        HoanDoiThuVien(tv, tam);
        loi.clear();
        return true;
    }
    catch (...)
    {
        delete[] ds;
        loi = "Doc file that bai; giu nguyen du lieu cu.";
        return false;
    }
}
void GhiDuLieuFile(ostream &file, const ThuVien &tv)
{
    file << tv.maTheLonNhatDaCap << '\n' << tv.dsDauSach.soLuong << '\n';
    for (int i = 0; i < tv.dsDauSach.soLuong; i++)
    {
        const DauSach &sach = *tv.dsDauSach.ds[i];
        file << sach.ISBN << '|' << sach.tenSach << '|' << sach.soTrang << '|' << sach.tacGia << '|'
             << sach.namXuatBan << '|' << sach.theLoai << '|' << DemCuonSach(sach.dms) << '\n';
        const CuonSach *p = sach.dms;
        while (p != nullptr)
        {
            file << p->maSach << '|' << p->trangThai << '|' << p->viTri << '\n';
            p = p->next;
        }
    }
    int soDocGia = DemDocGia(tv.cayDocGia);
    const NutDocGia **ds = new const NutDocGia *[soDocGia];
    try
    {
        LayDanhSachDocGia(tv.cayDocGia, ds, soDocGia);
        file << soDocGia << '\n';
        for (int i = 0; i < soDocGia; i++)
        {
            const DocGia &docGia = ds[i]->thongTin;
            file << docGia.maThe << '|' << docGia.ho << '|' << docGia.ten << '|' << docGia.phai
                 << '|' << docGia.trangThaiThe << '|' << DemLichSu(docGia.dsMuonTra) << '\n';
            const MuonTra *p = docGia.dsMuonTra;
            while (p != nullptr)
            {
                file << p->maSach << '|' << ChuoiNgay(p->ngayMuon) << '|' << ChuoiNgay(p->ngayTra)
                     << '|' << p->trangThai << '\n';
                p = p->next;
            }
        }
        delete[] ds;
    }
    catch (...)
    {
        delete[] ds;
        throw;
    }
}
bool GhiVaThayFile(const ThuVien &tv, const wstring &fileTam, const wstring &dich, string &loi)
{
    {
        ofstream file(fileTam.c_str(), ios::binary | ios::trunc);
        if (!file)
        {
            return BaoLoiFile(loi, "Khong mo duoc file tam.");
        }
        GhiDuLieuFile(file, tv);
        file.flush();
        if (!file)
        {
            return BaoLoiFile(loi, "Ghi file tam that bai.");
        }
        file.close();
        if (file.fail())
        {
            return BaoLoiFile(loi, "Dong file tam that bai.");
        }
    }
    // Dong stream truoc khi mo lai, dong bo du lieu he thong roi moi thay file cu.
    HANDLE tep = CreateFileW(fileTam.c_str(), GENERIC_WRITE, 0, nullptr, OPEN_EXISTING,
                             FILE_ATTRIBUTE_NORMAL, nullptr);
    if (tep == INVALID_HANDLE_VALUE)
    {
        return BaoLoiFile(loi, "Khong dong bo duoc file tam.");
    }
    bool dongBo = FlushFileBuffers(tep) != 0;
    bool dongTep = CloseHandle(tep) != 0;
    if (!dongBo || !dongTep)
    {
        return BaoLoiFile(loi, "Dong bo file tam that bai.");
    }
    ThuVien kiemTra;
    if (!DocFile(kiemTra, DuongDanUTF8(fileTam), loi))
    {
        return false;
    }
    if (!MoveFileExW(fileTam.c_str(), dich.c_str(),
                     MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH))
    {
        return BaoLoiFile(loi, "Khong thay duoc file dich; file cu duoc giu.");
    }
    loi.clear();
    return true;
}
bool LuuFile(const ThuVien &tv, const string &path, string &loi)
{
    wstring thuMucTam, fileTam;
    bool daTao = false;
    try
    {
        if (!KiemTraToanVen(tv, loi))
        {
            return false;
        }
        wstring dich = DuongDanDayDu(path);
        wstring cha = ThuMucCha(dich);
        for (int i = 0; i < 100; i++)
        {
            thuMucTam = cha + L".thu-vien-save-" + ChuoiSoRong(GetCurrentProcessId()) + L"-" +
                        ChuoiSoRong(GetTickCount()) + L"-" + ChuoiSoRong(i);
            if (CreateDirectoryW(thuMucTam.c_str(), nullptr))
            {
                daTao = true;
                break;
            }
            if (GetLastError() != ERROR_ALREADY_EXISTS)
            {
                break;
            }
        }
        if (!daTao)
        {
            return BaoLoiFile(loi, "Khong tao duoc thu muc tam.");
        }
        fileTam = thuMucTam + L"/data.txt";
        bool thanhCong = GhiVaThayFile(tv, fileTam, dich, loi);
        DeleteFileW(fileTam.c_str());
        RemoveDirectoryW(thuMucTam.c_str());
        return thanhCong;
    }
    catch (...)
    {
        if (!fileTam.empty())
        {
            DeleteFileW(fileTam.c_str());
        }
        if (daTao)
        {
            RemoveDirectoryW(thuMucTam.c_str());
        }
        loi = "Luu file that bai; file cu duoc giu.";
        return false;
    }
}
ThuVien::~ThuVien()
{
    HuyThuVien(*this);
}
void HuyThuVien(ThuVien &tv)
{
    HuyCayDocGia(tv.cayDocGia);
    HuyDanhSachDauSach(tv.dsDauSach);
    tv.maTheLonNhatDaCap = 0;
}
void HoanDoiThuVien(ThuVien &a, ThuVien &b)
{
    for (int i = 0; i < MAX_DAU_SACH; i++)
    {
        DauSach *tam = a.dsDauSach.ds[i];
        a.dsDauSach.ds[i] = b.dsDauSach.ds[i];
        b.dsDauSach.ds[i] = tam;
    }
    int soLuong = a.dsDauSach.soLuong;
    a.dsDauSach.soLuong = b.dsDauSach.soLuong;
    b.dsDauSach.soLuong = soLuong;
    NutDocGia *goc = a.cayDocGia.root;
    a.cayDocGia.root = b.cayDocGia.root;
    b.cayDocGia.root = goc;
    int ma = a.maTheLonNhatDaCap;
    a.maTheLonNhatDaCap = b.maTheLonNhatDaCap;
    b.maTheLonNhatDaCap = ma;
}
