#include "00_KhaiBaoChung.h"

int DemLichSu(const MuonTra* p) { int n=0; for (;p;p=p->next) ++n; return n; }
int DemSoSachDangMuon(const DocGia& d) {
    int n=0; for (const MuonTra* p=d.dsMuonTra;p;p=p->next) if(p->trangThai==MUON_DANG_MUON) ++n;
    return n;
}
bool CoSachQuaHan7Ngay(const DocGia& d,const NgayThang& now) {
    for (const MuonTra* p=d.dsMuonTra;p;p=p->next)
        if(p->trangThai==MUON_DANG_MUON && QuaHan7Ngay(p->ngayMuon,now)) return true;
    return false;
}
MuonTra* TimMuonDangMuonTheoMa(DocGia& d,const string& ma) {
    for(MuonTra* p=d.dsMuonTra;p;p=p->next) if(p->maSach==ma && p->trangThai==MUON_DANG_MUON) return p;
    return nullptr;
}
void HuyDanhSachMuonTra(MuonTra*& head) {
    while(head) { MuonTra* p=head; head=head->next; delete p; }
}
void LietKeSachDangMuon(const ThuVien& tv,int ma,std::ostream& out) {
    const NutDocGia* dg=TimDocGia(tv.cayDocGia,ma);
    if(!dg) { out<<"Khong tim thay doc gia.\n"; return; }
    out<<"DANG MUON | The "<<ma<<" | "<<dg->thongTin.ho<<' '<<dg->thongTin.ten<<'\n';
    int n=0;
    for(const MuonTra* p=dg->thongTin.dsMuonTra;p;p=p->next) {
        if(p->trangThai!=MUON_DANG_MUON) continue;
        const DauSach* owner=nullptr;
        TimCuonSachToanCuc(tv,p->maSach,&owner);
        out<<p->maSach<<" | "<<(owner?owner->tenSach:"[LIEN KET LOI]")<<" | "<<ChuoiNgay(p->ngayMuon)<<'\n'; ++n;
    }
    if(!n) out<<"Khong co sach dang muon.\n";
}
