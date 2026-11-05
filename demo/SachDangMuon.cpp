#include "00_KhaiBaoChung.h"

// [DEMO - CODEX] Phan bo sung cho ban trinh thay.
void LietKeSachDangMuon(const ThuVien &tv, int maThe, ostream &out)
{
    const NutDocGia *docGia = TimDocGia(tv.cayDocGia, maThe);
    if (docGia == nullptr)
    {
        out << "Khong tim thay doc gia.\n";
        return;
    }
    out << "DANG MUON | The " << maThe << " | " << docGia->thongTin.ho << ' '
        << docGia->thongTin.ten << '\n';
    const MuonTra *p = docGia->thongTin.dsMuonTra;
    int soSach = 0;
    while (p != nullptr)
    {
        if (p->trangThai == MUON_DANG_MUON)
        {
            const DauSach *dauSach = nullptr;
            TimCuonSachToanCuc(tv, p->maSach, &dauSach);
            out << p->maSach << " | ";
            if (dauSach != nullptr)
            {
                out << dauSach->tenSach;
            }
            else
            {
                out << "[LIEN KET LOI]";
            }
            out << " | " << ChuoiNgay(p->ngayMuon) << '\n';
            soSach++;
        }
        p = p->next;
    }
    if (soSach == 0)
    {
        out << "Khong co sach dang muon.\n";
    }
}
