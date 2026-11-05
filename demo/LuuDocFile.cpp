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

struct CuonKiemTra
{
    const CuonSach *cuon = nullptr;
    const DauSach *dauSach = nullptr;
};
struct LuotKiemTra
{
    int viTriCuon = 0;
    int maThe = 0;
    int ngayMuon = 0;
    int ngayKetThuc = 0;
    int trangThai; // Gan tu luot muon truoc khi sap xep.
};
struct MocKiemTra
{
    int maThe = 0;
    int ngay = 0;
    int loai = 0; // 0: tra tu ngay truoc; 1: muon-tra cung ngay; 2: muon giu sang ngay khac
};

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

bool MaCuonKiemTraTruoc(CuonKiemTra a, CuonKiemTra b)
{
    return a.cuon->maSach < b.cuon->maSach;
}
void TronMaCuonKiemTra(CuonKiemTra *a, CuonKiemTra *tam, int trai, int giua, int phai)
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
void ChiaMaCuonKiemTra(CuonKiemTra *a, CuonKiemTra *tam, int trai, int phai)
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
void SapXepMaCuonKiemTra(CuonKiemTra *a, int soLuong)
{
    if (soLuong < 2)
    {
        return;
    }
    CuonKiemTra *tam = new CuonKiemTra[soLuong];
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

bool LuotTheoCuonTruoc(LuotKiemTra a, LuotKiemTra b)
{

    if (a.viTriCuon != b.viTriCuon)
    {
        return a.viTriCuon < b.viTriCuon;
    }
    if (a.ngayMuon != b.ngayMuon)
    {
        return a.ngayMuon < b.ngayMuon;
    }
    if (a.ngayKetThuc != b.ngayKetThuc)
    {
        return a.ngayKetThuc < b.ngayKetThuc;
    }
    if (a.trangThai != b.trangThai)
    {
        return a.trangThai < b.trangThai;
    }
    return a.maThe < b.maThe;
}
void TronLuotTheoCuon(LuotKiemTra *a, LuotKiemTra *tam, int trai, int giua, int phai)
{
    int i = trai, j = giua + 1, k = trai;
    while (i <= giua && j <= phai)
    {
        if (LuotTheoCuonTruoc(a[j], a[i]))
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
void ChiaLuotTheoCuon(LuotKiemTra *a, LuotKiemTra *tam, int trai, int phai)
{
    if (trai >= phai)
    {
        return;
    }
    int giua = trai + (phai - trai) / 2;
    ChiaLuotTheoCuon(a, tam, trai, giua);
    ChiaLuotTheoCuon(a, tam, giua + 1, phai);
    TronLuotTheoCuon(a, tam, trai, giua, phai);
}
void SapXepLuotTheoCuon(LuotKiemTra *a, int soLuong)
{
    if (soLuong < 2)
    {
        return;
    }
    LuotKiemTra *tam = new LuotKiemTra[soLuong];
    try
    {
        ChiaLuotTheoCuon(a, tam, 0, soLuong - 1);
        delete[] tam;
    }
    catch (...)
    {
        delete[] tam;
        throw;
    }
}

bool MocTheoDocGiaTruoc(MocKiemTra a, MocKiemTra b)
{

    if (a.maThe != b.maThe)
    {
        return a.maThe < b.maThe;
    }
    if (a.ngay != b.ngay)
    {
        return a.ngay < b.ngay;
    }
    return a.loai < b.loai;
}
void TronMocTheoDocGia(MocKiemTra *a, MocKiemTra *tam, int trai, int giua, int phai)
{
    int i = trai, j = giua + 1, k = trai;
    while (i <= giua && j <= phai)
    {
        if (MocTheoDocGiaTruoc(a[j], a[i]))
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
void ChiaMocTheoDocGia(MocKiemTra *a, MocKiemTra *tam, int trai, int phai)
{
    if (trai >= phai)
    {
        return;
    }
    int giua = trai + (phai - trai) / 2;
    ChiaMocTheoDocGia(a, tam, trai, giua);
    ChiaMocTheoDocGia(a, tam, giua + 1, phai);
    TronMocTheoDocGia(a, tam, trai, giua, phai);
}
void SapXepMocTheoDocGia(MocKiemTra *a, int soLuong)
{
    if (soLuong < 2)
    {
        return;
    }
    MocKiemTra *tam = new MocKiemTra[soLuong];
    try
    {
        ChiaMocTheoDocGia(a, tam, 0, soLuong - 1);
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

// Bo mang tam chi giu dia chi va so lieu kiem tra, khong so huu cac nut cua thu vien.
struct MangKiemTra
{
    const DauSach **dauSach = nullptr;
    CuonKiemTra *cuon = nullptr;
    const NutDocGia **docGia = nullptr;
    LuotKiemTra *luot = nullptr;
    MocKiemTra *moc = nullptr;
    int *soDangMuon = nullptr;
};
void HuyMangKiemTra(MangKiemTra &tam)
{
    delete[] tam.dauSach;
    delete[] tam.cuon;
    delete[] tam.docGia;
    delete[] tam.luot;
    delete[] tam.moc;
    delete[] tam.soDangMuon;
    tam.dauSach = nullptr;
    tam.cuon = nullptr;
    tam.docGia = nullptr;
    tam.luot = nullptr;
    tam.moc = nullptr;
    tam.soDangMuon = nullptr;
}
int TimCuonTrongMangKiemTra(const CuonKiemTra *ds, int soCuon, const string &ma)
{
    int trai = 0, phai = soCuon - 1;
    while (trai <= phai)
    {
        int giua = trai + (phai - trai) / 2;
        if (ds[giua].cuon->maSach == ma)
        {
            return giua;
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
bool KiemTraCacDanhSach(const ThuVien &tv, MangKiemTra &tam, string &loi)
{
    int soDauSach = tv.dsDauSach.soLuong;
    if (soDauSach < 0 || soDauSach > MAX_DAU_SACH || tv.maTheLonNhatDaCap < 0)
    {
        return BaoLoiFile(loi, "So dau sach/moc ma the khong hop le.");
    }
    tam.dauSach = new const DauSach *[soDauSach];
    tam.cuon = new CuonKiemTra[MAX_BAN_GHI];
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
        tam.dauSach[i] = sach;
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
            tam.cuon[soCuon].cuon = p;
            tam.cuon[soCuon].dauSach = sach;
            soCuon++;
            p = p->next;
        }
    }
    SapXepISBNKiemTra(tam.dauSach, soDauSach);
    for (int i = 1; i < soDauSach; i++)
    {
        if (tam.dauSach[i - 1]->ISBN == tam.dauSach[i]->ISBN)
        {
            return BaoLoiFile(loi, "Trung ISBN.");
        }
    }
    SapXepMaCuonKiemTra(tam.cuon, soCuon);
    for (int i = 1; i < soCuon; i++)
    {
        if (tam.cuon[i - 1].cuon->maSach == tam.cuon[i].cuon->maSach)
        {
            return BaoLoiFile(loi, "Trung ma cuon.");
        }
    }

    tam.docGia = new const NutDocGia *[MAX_DOC_GIA];
    int soDocGia = LayDanhSachDocGia(tv.cayDocGia, tam.docGia, MAX_DOC_GIA);
    tam.luot = new LuotKiemTra[MAX_BAN_GHI];
    tam.moc = new MocKiemTra[MAX_BAN_GHI * 2];
    tam.soDangMuon = new int[soCuon]{};
    int soLuot = 0, soMoc = 0;
    int homNay = SoThuTuNgay(HomNay());
    for (int i = 0; i < soDocGia; i++)
    {
        const DocGia &docGia = tam.docGia[i]->thongTin;
        if (docGia.maThe <= 0 || docGia.maThe > tv.maTheLonNhatDaCap)
        {
            return BaoLoiFile(loi, "Ma the vuot moc da cap.");
        }
        if (i > 0 && tam.docGia[i - 1]->thongTin.maThe >= docGia.maThe)
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
            int cuon = TimCuonTrongMangKiemTra(tam.cuon, soCuon, p->maSach);
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
                tam.soDangMuon[cuon]++;
                if (dangGiu > 3 || tam.soDangMuon[cuon] > 1)
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
                     tam.cuon[cuon].cuon->trangThai != SACH_THANH_LY))
                {
                    return BaoLoiFile(loi, "Luot mat phai gan the khoa va cuon thanh ly.");
                }
            }
            tam.luot[soLuot].viTriCuon = cuon;
            tam.luot[soLuot].maThe = docGia.maThe;
            tam.luot[soLuot].ngayMuon = batDau;
            tam.luot[soLuot].ngayKetThuc = ketThuc;
            tam.luot[soLuot].trangThai = p->trangThai;
            soLuot++;

            tam.moc[soMoc].maThe = docGia.maThe;
            tam.moc[soMoc].ngay = batDau;
            tam.moc[soMoc].loai = 2;
            if (batDau == ketThuc)
            {
                tam.moc[soMoc].loai = 1;
            }
            soMoc++;
            if (ketThuc != INT_MAX && ketThuc != batDau)
            {
                tam.moc[soMoc].maThe = docGia.maThe;
                tam.moc[soMoc].ngay = ketThuc;
                tam.moc[soMoc].loai = 0;
                soMoc++;
            }
            p = p->next;
        }
    }
    for (int i = 0; i < soCuon; i++)
    {
        if ((tam.cuon[i].cuon->trangThai == SACH_DANG_MUON) != (tam.soDangMuon[i] == 1))
        {
            return BaoLoiFile(loi, "Trang thai cuon khong khop lich su.");
        }
    }
    SapXepLuotTheoCuon(tam.luot, soLuot);
    for (int i = 1; i < soLuot; i++)
    {
        if (tam.luot[i - 1].viTriCuon == tam.luot[i].viTriCuon)
        {
            if (tam.luot[i - 1].trangThai != MUON_DA_TRA ||
                tam.luot[i - 1].ngayKetThuc > tam.luot[i].ngayMuon)
            {
                return BaoLoiFile(loi, "Lich su chong lan hoac muon lai sau bao mat.");
            }
        }
    }
    SapXepMocTheoDocGia(tam.moc, soMoc);
    int maDangXet = 0, soDangGiu = 0;
    for (int i = 0; i < soMoc; i++)
    {
        if (tam.moc[i].maThe != maDangXet)
        {
            maDangXet = tam.moc[i].maThe;
            soDangGiu = 0;
        }
        if (tam.moc[i].loai == 0)
        {
            soDangGiu--;
        }
        else if (tam.moc[i].loai == 2)
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
bool KiemTraToanVen(const ThuVien &tv, string &loi)
{
    MangKiemTra tam;
    try
    {
        bool dung = KiemTraCacDanhSach(tv, tam, loi);
        HuyMangKiemTra(tam);
        return dung;
    }
    catch (...)
    {
        HuyMangKiemTra(tam);
        loi = "Khong du bo nho hoac loi khi kiem tra du lieu.";
        return false;
    }
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
bool DocDocGiaTuFile(ifstream &file, ThuVien &tam, NutDocGia **ds, int soDocGia, int &soDong,
                     string &loi)
{
    struct NutChoGhep
    {
        NutDocGia **ds;
        int daDoc;
        ~NutChoGhep()
        {
            for (int i = 0; i < daDoc; ++i)
            {
                HuyDanhSachMuonTra(*ds[i]);
                delete ds[i];
            }
        }
    } choGhep = {ds, 0};

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
        NutDocGia *p = new NutDocGia(docGia);
        ds[i] = p;
        ++choGhep.daDoc;
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
    choGhep.daDoc = 0;
    return true;
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
