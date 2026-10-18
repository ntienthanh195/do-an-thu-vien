#include "00_KhaiBaoChung.h"
#include <memory>
#include <ostream>
#include <sstream>
#include <exception>

namespace {
// Cac mang trong file nay la view/bo dem tam, khong thay bon cau truc nghiep vu.
using ViewDocGia=std::unique_ptr<const NutDocGia*[]>;
int TaoViewDocGia(const ThuVien& tv,ViewDocGia& view) {
    int n=DemDocGia(tv.cayDocGia);
    if(n<0 || n>MAX_DOC_GIA) return -1;
    view.reset(new const NutDocGia*[n]);
    return LayDanhSachDocGia(tv.cayDocGia,view.get(),n)==n ? n : -1;
}

bool KiemTraNgayGiaoDich(const NgayThang& ngay,string& loi) {
    if(!NgayHopLe(ngay)) { loi="Ngay giao dich khong hop le."; return false; }
    if(KhoangCachNgay(HomNay(),ngay)>0) { loi="Khong ghi giao dich trong tuong lai."; return false; }
    return true;
}

// Ban tham khao ghi giao dich tuan tu. Khong chen lui ngay qua su kien gan nhat
// cua doc gia HOAC cua cuon sach. Cung ngay van cho tra roi muon lai.
bool KiemTraDongThoiGian(const ThuVien& tv,const DocGia& dg,const string& ma,
                        const NgayThang& ngay,int& dangMuonCuon,int& tongLichSu,string& loi) {
    ViewDocGia view; int n=TaoViewDocGia(tv,view);
    if(n<0) { loi="Cay doc gia vuot gioi han/khong doc duoc."; return false; }
    int moc=0; dangMuonCuon=0; tongLichSu=0;
    for(int i=0;i<n;++i) {
        const DocGia& x=view[i]->thongTin;
        for(const MuonTra* p=x.dsMuonTra;p;p=p->next) {
            if(tongLichSu>=MAX_BAN_GHI) { loi="Lich su vuot gioi han cua ban tham khao."; return false; }
            ++tongLichSu;
            if(p->maSach==ma && p->trangThai==MUON_DANG_MUON) ++dangMuonCuon;
            if(x.maThe!=dg.maThe && p->maSach!=ma) continue;
            if(!NgayHopLe(p->ngayMuon) || !HopLeTrangThaiMuonTra(p->trangThai) ||
               (p->trangThai!=MUON_DANG_MUON && !NgayHopLe(p->ngayTra))) {
                loi="Lich su lien quan co ngay/trang thai khong hop le."; return false;
            }
            int k=SoThuTuNgay(p->ngayMuon);
            if(k>moc) moc=k;
            if(p->trangThai!=MUON_DANG_MUON) {
                k=SoThuTuNgay(p->ngayTra); if(k>moc) moc=k;
            }
        }
    }
    if(SoThuTuNgay(ngay)<moc) {
        loi="Khong duoc ghi lui ngay qua giao dich gan nhat cua doc gia/cuon sach."; return false;
    }
    return true;
}

bool KetThucMuon(ThuVien& tv,int maThe,const string& maSach,const NgayThang& ngay,bool mat,string& loi) {
    try {
        if(!KiemTraNgayGiaoDich(ngay,loi)) return false;
        NutDocGia* node=TimDocGia(tv.cayDocGia,maThe);
        if(!node) { loi="Khong tim thay doc gia."; return false; }
        CuonSach* cuon=TimCuonSachToanCuc(tv,maSach);
        if(!cuon) { loi="Khong tim thay cuon sach."; return false; }
        MuonTra* phieu=TimMuonDangMuonTheoMa(node->thongTin,maSach);
        if(!phieu) { loi="Doc gia khong dang muon cuon nay (hoac da xu ly tra/mat)."; return false; }
        if(cuon->trangThai!=SACH_DANG_MUON) { loi="Trang thai cuon va lich su khong khop; khong cap nhat."; return false; }
        int dangMuon=0,tong=0;
        if(!KiemTraDongThoiGian(tv,node->thongTin,maSach,ngay,dangMuon,tong,loi)) return false;
        if(dangMuon!=1) { loi="Cuon sach khong co dung mot phieu muon dang mo; khong cap nhat."; return false; }
        // Thẻ bi khoa VAN duoc tra/bao mat. Commit khong cap phat, khong gan string.
        phieu->ngayTra=ngay;
        phieu->trangThai=mat ? MUON_LAM_MAT : MUON_DA_TRA;
        cuon->trangThai=mat ? SACH_THANH_LY : SACH_CHO_MUON;
        if(mat) node->thongTin.trangThaiThe=THE_BI_KHOA;
        loi.clear(); return true;
    } catch(const std::exception&) { loi="Khong du bo nho kiem tra giao dich; du lieu khong doi."; return false; }
}

// Heap sort tu cai: comparator(a,b)=true neu a phai nam TRUOC b trong ket qua.
// Heap giu phan tu phai nam cuoi o goc; rut goc ve cuoi moi vong.
template<class T,class SoSanh>
void VunDong(T* a,int n,int root,SoSanh truoc) {
    while(root<n/2) {
        int child=root*2+1;
        if(child+1<n && truoc(a[child],a[child+1])) ++child;
        if(!truoc(a[root],a[child])) break;
        T tmp=a[root]; a[root]=a[child]; a[child]=tmp; root=child;
    }
}
template<class T,class SoSanh>
void SapXepHeap(T* a,int n,SoSanh truoc) {
    for(int i=n/2;i>0;--i) VunDong(a,n,i-1,truoc);
    for(int end=n-1;end>0;--end) {
        T tmp=a[0]; a[0]=a[end]; a[end]=tmp;
        VunDong(a,end,0,truoc);
    }
}
struct DongQuaHan { const DocGia* dg=nullptr; int soNgay=0; int soCuon=0; };
struct ChiMucCuon { const CuonSach* cuon=nullptr; int dauSach=0; };

int TimChuSoHuu(const ChiMucCuon* a,int n,const string& ma) {
    int left=0,right=n-1;
    while(left<=right) {
        int mid=left+(right-left)/2;
        if(a[mid].cuon->maSach==ma) return a[mid].dauSach;
        if(a[mid].cuon->maSach<ma) left=mid+1; else right=mid-1;
    }
    return -1;
}
bool DauSachXepTruoc(const ThuVien& tv,const int* dem,int a,int b) {
    if(dem[a]!=dem[b]) return dem[a]>dem[b];
    int c=SoSanhChuoi(tv.dsDauSach.ds[a]->tenSach,tv.dsDauSach.ds[b]->tenSach);
    return c!=0 ? c<0 : tv.dsDauSach.ds[a]->ISBN<tv.dsDauSach.ds[b]->ISBN;
}
}

bool MuonSach(ThuVien& tv,int maThe,const string& maSach,const NgayThang& ngay,string& loi) {
    try {
        if(!KiemTraNgayGiaoDich(ngay,loi)) return false;
        NutDocGia* node=TimDocGia(tv.cayDocGia,maThe);
        if(!node) { loi="Khong tim thay doc gia."; return false; }
        DocGia& dg=node->thongTin;
        if(dg.trangThaiThe!=THE_HOAT_DONG) { loi="The doc gia dang bi khoa."; return false; }
        if(DemSoSachDangMuon(dg)>=3) { loi="Doc gia da muon toi da 3 cuon cung luc."; return false; }
        if(CoSachQuaHan7Ngay(dg,ngay)) { loi="Doc gia dang giu sach qua 7 ngay; phai xu ly sach qua han truoc."; return false; }
        CuonSach* cuon=TimCuonSachToanCuc(tv,maSach);
        if(!cuon) { loi="Khong tim thay ma cuon sach."; return false; }
        if(cuon->trangThai!=SACH_CHO_MUON) { loi="Cuon sach dang duoc muon hoac da thanh ly."; return false; }
        int dangMuon=0,tong=0;
        if(!KiemTraDongThoiGian(tv,dg,maSach,ngay,dangMuon,tong,loi)) return false;
        if(dangMuon!=0) { loi="Cuon sach da co phieu dang muon; trang thai du lieu khong khop."; return false; }
        if(tong>=MAX_BAN_GHI) { loi="Da dat gioi han so ban ghi lich su."; return false; }
        std::unique_ptr<MuonTra> moi(new MuonTra);
        moi->maSach=maSach; moi->ngayMuon=ngay;
        MuonTra** tail=&dg.dsMuonTra;
        while(*tail) tail=&(*tail)->next;
        // Moi thong tin da hop le va node da cap phat. Hai thay doi commit lien nhau.
        *tail=moi.release(); cuon->trangThai=SACH_DANG_MUON;
        loi.clear(); return true;
    } catch(const std::exception&) { loi="Khong du bo nho de muon sach; du lieu khong doi."; return false; }
}
bool TraSach(ThuVien& tv,int maThe,const string& maSach,const NgayThang& ngay,string& loi) {
    return KetThucMuon(tv,maThe,maSach,ngay,false,loi);
}
bool DanhDauMatSach(ThuVien& tv,int maThe,const string& maSach,const NgayThang& ngay,string& loi) {
    // Gia dinh can hoi thay: ngayTra la ngay BAO MAT, khong gia vo sach da tra.
    // Cuon trang thai 2 = rut kho; the khoa. Khong them truong phi phat/ngay bao mat.
    return KetThucMuon(tv,maThe,maSach,ngay,true,loi);
}

void InDocGiaQuaHan(const ThuVien& tv,const NgayThang& ngay,std::ostream& out) {
    if(!NgayHopLe(ngay)) { out<<"Ngay thong ke khong hop le.\n"; return; }
    ViewDocGia view; int n=TaoViewDocGia(tv,view);
    if(n<0) { out<<"Khong tao duoc danh sach doc gia.\n"; return; }
    std::unique_ptr<DongQuaHan[]> rows(new DongQuaHan[n]); int k=0;
    for(int i=0;i<n;++i) {
        DongQuaHan row; row.dg=&view[i]->thongTin;
        for(const MuonTra* p=row.dg->dsMuonTra;p;p=p->next) if(p->trangThai==MUON_DANG_MUON) {
            int du=KhoangCachNgay(p->ngayMuon,ngay)-7;
            if(du>0) { ++row.soCuon; if(du>row.soNgay) row.soNgay=du; }
        }
        if(row.soCuon) rows[k++]=row;
    }
    SapXepHeap(rows.get(),k,[](const DongQuaHan& a,const DongQuaHan& b) {
        return a.soNgay!=b.soNgay ? a.soNgay>b.soNgay : a.dg->maThe<b.dg->maThe;
    });
    out<<"DOC GIA QUA HAN - ngay "<<ChuoiNgay(ngay)<<'\n';
    out<<"Xep theo so ngay VUOT 7 lon nhat trong cac cuon dang muon; hoa thi ma the tang.\n";
    for(int i=0;i<k;++i) out<<rows[i].dg->maThe<<" | "<<rows[i].dg->ho<<' '<<rows[i].dg->ten
        <<" | Qua han: "<<rows[i].soNgay<<" ngay | "<<rows[i].soCuon<<" cuon qua han\n";
    if(!k) out<<"Khong co doc gia qua han.\n";
    // O(R+H+RlogR), bo nho O(R), voi R doc gia, H ban ghi lich su.
}

void InTop10SachDuocMuonNhieuNhat(const ThuVien& tv,std::ostream& out) {
    int d=tv.dsDauSach.soLuong,c=0;
    for(int i=0;i<d;++i) c+=DemCuonSach(tv.dsDauSach.ds[i]->dms);
    std::unique_ptr<ChiMucCuon[]> index(new ChiMucCuon[c]);
    std::unique_ptr<int[]> dem(new int[d]{});
    int pos=0;
    for(int i=0;i<d;++i) for(const CuonSach* p=tv.dsDauSach.ds[i]->dms;p;p=p->next) {
        index[pos].cuon=p; index[pos].dauSach=i; ++pos;
    }
    SapXepHeap(index.get(),c,[](const ChiMucCuon& a,const ChiMucCuon& b) { return a.cuon->maSach<b.cuon->maSach; });
    ViewDocGia view; int n=TaoViewDocGia(tv,view);
    if(n<0) { out<<"Khong tao duoc danh sach doc gia.\n"; return; }
    for(int i=0;i<n;++i) for(const MuonTra* p=view[i]->thongTin.dsMuonTra;p;p=p->next) {
        int owner=TimChuSoHuu(index.get(),c,p->maSach);
        if(owner<0) { out<<"Loi toan ven: lich su tham chieu ma cuon khong ton tai: "<<p->maSach<<'\n'; return; }
        ++dem[owner]; // Moi nut la MOT luot muon: dang muon, da tra va mat deu tinh.
    }
    int top[10]{},k=0;
    for(int i=0;i<d;++i) if(dem[i]>0) {
        int j=0;
        while(j<k && !DauSachXepTruoc(tv,dem.get(),i,top[j])) ++j;
        if(j>=10) continue;
        int last=k<10 ? k : 9;
        for(int m=last;m>j;--m) top[m]=top[m-1];
        top[j]=i; if(k<10) ++k;
    }
    out<<"TOP TOI DA 10 DAU SACH THEO LUOT MUON\n";
    out<<"Moi lan muon tinh 1, gom dang muon/da tra/mat. Hoa: ten tang, roi ISBN tang.\n";
    for(int i=0;i<k;++i) out<<i+1<<" | "<<tv.dsDauSach.ds[top[i]]->ISBN<<" | "
        <<tv.dsDauSach.ds[top[i]]->tenSach<<" | "<<dem[top[i]]<<" luot\n";
    if(!k) out<<"Chua co luot muon nao.\n";
    // O(C log C + H log C + 10D + R); bo nho O(C+D+R). Khong co bo dem luu lau dai.
}

void ManHinhMuonTra(ThuVien& tv,const NgayThang& ngay,bool tra) {
    if(DangDungGiaoDienHeThong()) {
        const char* readerFields[]={"Ma the doc gia"};string readerValues[1];int maThe=0;
        while(true) {
            if(!NhapBieuMau(tra?"TRA SACH - CHON DOC GIA":"MUON SACH - CHON DOC GIA",readerFields,readerValues,1)) return;
            if(!DocSoNguyen(readerValues[0],maThe,1,2147483647)) {ThongBao("Ma the phai la so nguyen duong trong mien int.");continue;}
            if(!TimDocGia(tv.cayDocGia,maThe)) {ThongBao("Khong tim thay doc gia. Kiem tra lai ma the.");continue;}
            break;
        }
        // Hien sach dang giu TRUOC khi nhap cuon, giu dung luong chuc nang f.
        std::ostringstream out;LietKeSachDangMuon(tv,maThe,out);HienThiPhanTrang(out.str());
        int action=1;
        if(tra) {
            const char* actions[]={"Tra sach", "Bao mat sach (khoa the, rut cuon khoi kho)"};
            action=ChonMenu("TRA / BAO MAT - THE "+std::to_string(maThe),actions,2);
            if(action<1) return;
        }
        const char* copyFields[]={"Ma cuon sach"};string copyValues[1],loi;
        string title=(tra?(action==1?"TRA SACH":"BAO MAT SACH"):"MUON SACH")+string(" - THE ")+std::to_string(maThe);
        while(NhapBieuMau(title,copyFields,copyValues,1)) {
            string ma=ChuanHoaChuoi(copyValues[0]);
            bool ok=tra ? (action==1 ? TraSach(tv,maThe,ma,ngay,loi) : DanhDauMatSach(tv,maThe,ma,ngay,loi))
                        : MuonSach(tv,maThe,ma,ngay,loi);
            if(!ok) {ThongBao("LOI: "+loi);continue;}
            ThongBao("Giao dich thanh cong, ngay "+ChuoiNgay(ngay)+".");return;
        }
        return;
    }
    int maThe;
    if(!NhapSo("Ma the doc gia: ",maThe,1,2147483647)) return;
    if(!TimDocGia(tv.cayDocGia,maThe)) { ThongBao("Khong tim thay doc gia."); return; }
    std::ostringstream out;
    LietKeSachDangMuon(tv,maThe,out); HienThiPhanTrang(out.str());
    int action=1;
    if(tra) {
        const char* labels[]={"Tra sach", "Bao mat sach (khoa the, rut cuon khoi kho)"};
        action=ChonMenu("TRA / BAO MAT",labels,2);
        if(action<1) return;
    }
    string ma,loi;
    if(!NhapDong("Ma cuon sach: ",ma)) return;
    ma=ChuanHoaChuoi(ma);
    bool ok=tra ? (action==1 ? TraSach(tv,maThe,ma,ngay,loi) : DanhDauMatSach(tv,maThe,ma,ngay,loi))
                : MuonSach(tv,maThe,ma,ngay,loi);
    ThongBao(ok ? "Giao dich thanh cong, ngay "+ChuoiNgay(ngay)+"." : loi);
}
