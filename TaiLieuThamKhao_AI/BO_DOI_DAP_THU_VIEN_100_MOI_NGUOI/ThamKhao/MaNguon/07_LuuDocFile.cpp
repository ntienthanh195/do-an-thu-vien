#include "00_KhaiBaoChung.h"
#include <fstream>
#include <memory>
#include <climits>
#include <filesystem>
#include <chrono>
#include <system_error>
#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#endif

namespace {
// Cac mang nay chi la view tam de kiem tra, khong thay bon cau truc luu tru.
template<class T, class Less> void SapXepHeap(T* a, int n, Less less) {
    auto vun = [&](int root, int count) {
        while (root < count/2) {
            int child=root*2+1;
            if (child+1<count && less(a[child],a[child+1])) ++child;
            if (!less(a[root],a[child])) break;
            T tmp=a[root]; a[root]=a[child]; a[child]=tmp; root=child;
        }
    };
    for (int i=n/2-1;i>=0;--i) vun(i,n);
    for (int end=n-1;end>0;--end) {
        T tmp=a[0]; a[0]=a[end]; a[end]=tmp; vun(0,end);
    }
}
bool SachTruoc(const DauSach* a, const DauSach* b) {
    const int c=SoSanhChuoi(a->tenSach,b->tenSach);
    return c<0 || (c==0 && a->ISBN<b->ISBN);
}
bool UTF8HopLe(const string& s) {
    for (std::size_t i=0;i<s.size();) {
        const unsigned char c=static_cast<unsigned char>(s[i++]);
        if (c<0x80) { if (c==0) return false; continue; }
        unsigned int cp=0, min=0; int left=0;
        if (c>=0xC2 && c<=0xDF) { cp=c&31; left=1; min=0x80; }
        else if (c>=0xE0 && c<=0xEF) { cp=c&15; left=2; min=0x800; }
        else if (c>=0xF0 && c<=0xF4) { cp=c&7; left=3; min=0x10000; }
        else return false;
        while (left--) {
            if (i==s.size()) return false;
            const unsigned char d=static_cast<unsigned char>(s[i++]);
            if ((d&0xC0)!=0x80) return false;
            cp=(cp<<6)|(d&63);
        }
        if (cp<min || cp>0x10FFFF || (cp>=0xD800 && cp<=0xDFFF)) return false;
    }
    return true;
}
bool VanBanFile(const string& s) { return HopLeVanBan(s) && UTF8HopLe(s); }
bool MaSinhDungDauSach(const string& ma,const string& isbn) {
    std::size_t hash=string::npos;
    for(std::size_t i=0;i<ma.size();++i) if(ma[i]=='#') hash=i;
    if(hash==string::npos) return true;
    if(hash==0 || hash+1==ma.size() || ma[hash+1]=='0') return false;
    int so=0;
    return ma.substr(0,hash)==isbn && DocSoNguyen(ma.substr(hash+1),so,1,INT_MAX);
}
struct BoDoc {
    std::ifstream in; int dong=0; string& loi;
    BoDoc(const string& path,string& err):in(std::filesystem::u8path(path),std::ios::binary),loi(err) {}
    bool Sai(const string& why) { loi="Dong "+std::to_string(dong)+": "+why; return false; }
    bool Dong(string& s) {
        s.clear(); ++dong; char ch=0; bool any=false;
        while (in.get(ch)) {
            any=true;
            if (ch=='\n') break;
            if (s.size()>=65536) return Sai("ban ghi vuot 65536 byte.");
            s+=ch;
        }
        if (in.bad()) return Sai("loi I/O khi doc.");
        if (!any) return Sai("file ket thuc som.");
        if (!s.empty() && s.back()=='\r') s.pop_back();
        if (dong==1 && s.size()>=3 && s.compare(0,3,"\xEF\xBB\xBF")==0) s.erase(0,3);
        if (!UTF8HopLe(s)) return Sai("du lieu khong phai UTF-8 hop le.");
        return true;
    }
    bool So(int& x,int lo,int hi) {
        string s; return Dong(s) && (DocSoNguyen(s,x,lo,hi) || Sai("so nguyen/so dem khong hop le."));
    }
    bool Truong(string* a,int n) {
        string s; return Dong(s) && (TachTruong(s,a,n) || Sai("sai so truong hoac co truong rong."));
    }
};
struct Khung { const NutDocGia* p; long long lo,hi; };
struct Luot { const MuonTra* p; int maThe; int sach; };
struct MocMuon { int maThe,ngay,loai; }; // 0 ket thuc, 1 muon-tra cung ngay, 2 bat dau
int TimChiSo(const CuonSach* const* a,int n,const string& ma) {
    int lo=0,hi=n;
    while(lo<hi) { int mid=lo+(hi-lo)/2; if(a[mid]->maSach<ma) lo=mid+1; else hi=mid; }
    return lo<n && a[lo]->maSach==ma ? lo : -1;
}
NutDocGia* DungBST(NutDocGia** nodes,int lo,int hi) {
    if(lo>=hi) return nullptr;
    int mid=lo+(hi-lo)/2; NutDocGia* p=nodes[mid];
    p->left=DungBST(nodes,lo,mid);p->right=DungBST(nodes,mid+1,hi);return p;
}
bool KiemTraNoiBo(const ThuVien& tv,string& loi) {
    auto sai=[&](const string& s) { loi=s; return false; };
    if(tv.maTheLonNhatDaCap<0) return sai("Moc ma the am.");
    const int nd=tv.dsDauSach.soLuong;
    if(nd<0 || nd>MAX_DAU_SACH) return sai("So dau sach vuot gioi han.");
    std::unique_ptr<const DauSach*[]> dau(new const DauSach*[nd]);
    std::unique_ptr<const CuonSach*[]> cuon(new const CuonSach*[MAX_BAN_GHI]);
    int nc=0;
    for(int i=0;i<nd;++i) {
        const DauSach* d=tv.dsDauSach.ds[i];
        if(!d) return sai("Con tro dau sach rong.");
        string err;
        if(!HopLeDauSach(*d,err)) return sai("Dau sach "+d->ISBN+": "+err);
        if(!VanBanFile(d->ISBN)||!VanBanFile(d->tenSach)||!VanBanFile(d->tacGia)||!VanBanFile(d->theLoai))
            return sai("Dau sach co van ban/UTF-8 khong hop le.");
        // UI chuan hoa ma truoc khi tra. Tu choi ma khac dang chuan trong file,
        // khong tu sua ma vi co the lam trung dinh danh/doi lien ket lich su.
        if(d->ISBN!=ChuanHoaChuoi(d->ISBN)) return sai("ISBN chua chuan hoa khoang trang: "+d->ISBN);
        if(i>0 && SachTruoc(d,tv.dsDauSach.ds[i-1])) return sai("Mang dau sach chua tang theo ten/ISBN.");
        dau[i]=d;
        for(const CuonSach* c=d->dms;c;c=c->next) {
            if(nc==MAX_BAN_GHI) return sai("Tong cuon vuot gioi han hoac danh sach bi vong.");
            if(!VanBanFile(c->maSach)||!VanBanFile(c->viTri)||!HopLeTrangThaiSach(c->trangThai))
                return sai("Cuon sach co ma, vi tri hoac trang thai sai.");
            if(c->maSach!=ChuanHoaChuoi(c->maSach)) return sai("Ma cuon chua chuan hoa khoang trang: "+c->maSach);
            if(!MaSinhDungDauSach(c->maSach,d->ISBN)) return sai("Ma cuon ISBN#so khong thuoc dung dau sach: "+c->maSach);
            cuon[nc++]=c;
        }
    }
    SapXepHeap(dau.get(),nd,[](const DauSach* a,const DauSach* b){return a->ISBN<b->ISBN;});
    for(int i=1;i<nd;++i) if(dau[i-1]->ISBN==dau[i]->ISBN) return sai("Trung ISBN: "+dau[i]->ISBN);
    SapXepHeap(cuon.get(),nc,[](const CuonSach* a,const CuonSach* b){return a->maSach<b->maSach;});
    for(int i=1;i<nc;++i) if(cuon[i-1]->maSach==cuon[i]->maSach) return sai("Trung ma cuon: "+cuon[i]->maSach);
    std::unique_ptr<Khung[]> stack(new Khung[MAX_DOC_GIA]);
    std::unique_ptr<Luot[]> lich(new Luot[MAX_BAN_GHI]);
    std::unique_ptr<int[]> active(new int[nc]{});
    int top=0,ng=0,nh=0;
    if(tv.cayDocGia.root) stack[top++]={tv.cayDocGia.root,0,static_cast<long long>(INT_MAX)+1};
    const NgayThang now=HomNay();
    while(top) {
        Khung f=stack[--top]; const DocGia& g=f.p->thongTin;
        if(++ng>MAX_DOC_GIA || g.maThe<=f.lo || g.maThe>=f.hi) return sai("BST sai thu tu/trung ma/vuot gioi han.");
        if(g.maThe>tv.maTheLonNhatDaCap) return sai("Ma the "+std::to_string(g.maThe)+" vuot moc da cap.");
        if(!VanBanFile(g.ho)||!VanBanFile(g.ten)||!HopLePhai(g.phai)||!HopLeTrangThaiThe(g.trangThaiThe))
            return sai("Doc gia "+std::to_string(g.maThe)+" co truong khong hop le.");
        int dang=0;
        for(const MuonTra* h=g.dsMuonTra;h;h=h->next) {
            if(nh==MAX_BAN_GHI) return sai("Tong lich su vuot gioi han hoac danh sach bi vong.");
            if(!VanBanFile(h->maSach)||!HopLeTrangThaiMuonTra(h->trangThai)||!NgayHopLe(h->ngayMuon)
               || KhoangCachNgay(h->ngayMuon,now)<0) return sai("Lich su doc gia "+std::to_string(g.maThe)+" co ngay muon/trang thai sai.");
            if(h->maSach!=ChuanHoaChuoi(h->maSach)) return sai("Ma cuon trong lich su chua chuan hoa khoang trang: "+h->maSach);
            int index=TimChiSo(cuon.get(),nc,h->maSach);
            if(index<0) return sai("Lich su tham chieu cuon khong ton tai: "+h->maSach);
            if(h->trangThai==MUON_DANG_MUON) {
                if(!NgayRong(h->ngayTra)) return sai("Luot dang muon phai co ngay tra 0/0/0: "+h->maSach);
                if(++dang>3 || ++active[index]>1) return sai("Vuot 3 cuon hoac trung luot dang muon: "+h->maSach);
            } else {
                if(!NgayHopLe(h->ngayTra)||KhoangCachNgay(h->ngayMuon,h->ngayTra)<0||KhoangCachNgay(h->ngayTra,now)<0)
                    return sai("Ngay tra/bao mat sai: "+h->maSach);
                if(h->trangThai==MUON_LAM_MAT && (cuon[index]->trangThai!=SACH_THANH_LY || g.trangThaiThe!=THE_BI_KHOA))
                    return sai("Luot mat phai gan cuon thanh ly va the khoa: "+h->maSach);
            }
            lich[nh++]={h,g.maThe,index};
        }
        if(f.p->right) {
            if(top==MAX_DOC_GIA) return sai("Cay vuot gioi han.");
            stack[top++]={f.p->right,g.maThe,f.hi};
        }
        if(f.p->left) {
            if(top==MAX_DOC_GIA) return sai("Cay vuot gioi han.");
            stack[top++]={f.p->left,f.lo,g.maThe};
        }
    }
    for(int i=0;i<nc;++i) if((cuon[i]->trangThai==SACH_DANG_MUON)!=(active[i]==1))
        return sai("Trang thai cuon khong khop lich su dang muon: "+cuon[i]->maSach);
    // Sap theo cuon, ngay bat dau, ngay ket thuc: cung ngay tra-roi-muon lai hop le.
    SapXepHeap(lich.get(),nh,[](const Luot& a,const Luot& b){
        if(a.sach!=b.sach) return a.sach<b.sach;
        const int am=SoThuTuNgay(a.p->ngayMuon),bm=SoThuTuNgay(b.p->ngayMuon);
        if(am!=bm) return am<bm;
        const int ae=a.p->trangThai==MUON_DANG_MUON?INT_MAX:SoThuTuNgay(a.p->ngayTra);
        const int be=b.p->trangThai==MUON_DANG_MUON?INT_MAX:SoThuTuNgay(b.p->ngayTra);
        if(ae!=be) return ae<be;
        if(a.p->trangThai!=b.p->trangThai) return a.p->trangThai<b.p->trangThai;
        return a.maThe<b.maThe;
    });
    for(int i=1;i<nh;++i) if(lich[i-1].sach==lich[i].sach) {
        const MuonTra& a=*lich[i-1].p; const MuonTra& b=*lich[i].p;
        if(a.trangThai!=MUON_DA_TRA || KhoangCachNgay(a.ngayTra,b.ngayMuon)<0)
            return sai("Lich su giao nhau hoac muon lai sau bao mat: "+a.maSach);
    }
    // V1 chi co NGAY, khong co gio: chon thu tu hop le co the xay ra trong ngay.
    // Tra luot tu ngay truoc -> cac luot muon-tra trong ngay -> luot giu qua ngay.
    // Moi luot cung ngay van can mot cho trong, nhung co the thuc hien lan luot.
    std::unique_ptr<MocMuon[]> moc(new MocMuon[static_cast<std::size_t>(nh)*2]);
    int nm=0;
    for(int i=0;i<nh;++i) {
        const MuonTra& h=*lich[i].p;int start=SoThuTuNgay(h.ngayMuon),ma=lich[i].maThe;
        if(h.trangThai==MUON_DANG_MUON) moc[nm++]={ma,start,2};
        else {
            int end=SoThuTuNgay(h.ngayTra);
            if(start==end) moc[nm++]={ma,start,1};
            else {moc[nm++]={ma,start,2};moc[nm++]={ma,end,0};}
        }
    }
    SapXepHeap(moc.get(),nm,[](const MocMuon& a,const MocMuon& b){
        if(a.maThe!=b.maThe) return a.maThe<b.maThe;
        if(a.ngay!=b.ngay) return a.ngay<b.ngay;
        return a.loai<b.loai;
    });
    int reader=0,held=0;
    for(int i=0;i<nm;++i) {
        if(moc[i].maThe!=reader) {reader=moc[i].maThe;held=0;}
        if(moc[i].loai==0) --held;
        else if(moc[i].loai==2) ++held;
        if(held<0 || held>3 || (moc[i].loai==1 && held==3))
            return sai("Lich su doc gia "+std::to_string(reader)+" vuot 3 cuon cung luc.");
    }
    loi.clear(); return true;
}
bool DocNoiBo(ThuVien& tv,const string& path,string& loi) {
    BoDoc r(path,loi); if(!r.in) { loi="Khong mo duoc file: "+path; return false; }
    ThuVien tmp; int nd=0,nc=0,nh=0;
    if(!r.So(tmp.maTheLonNhatDaCap,0,INT_MAX)||!r.So(nd,0,MAX_DAU_SACH)) return false;
    for(int i=0;i<nd;++i) {
        string a[7]; if(!r.Truong(a,7)) return false;
        std::unique_ptr<DauSach> d(new DauSach); int count=0;
        d->ISBN=a[0]; d->tenSach=a[1]; d->tacGia=a[3]; d->theLoai=a[5];
        if(!DocSoNguyen(a[2],d->soTrang,1,INT_MAX)||!DocSoNguyen(a[4],d->namXuatBan,1,9999)
           ||!DocSoNguyen(a[6],count,0,MAX_BAN_GHI-nc)) return r.Sai("so trang/nam/so cuon sai.");
        tmp.dsDauSach.ds[tmp.dsDauSach.soLuong++]=d.release();
        CuonSach** tail=&tmp.dsDauSach.ds[i]->dms;
        for(int j=0;j<count;++j) {
            string c[3]; if(!r.Truong(c,3)) return false;
            std::unique_ptr<CuonSach> p(new CuonSach); p->maSach=c[0]; p->viTri=c[2];
            if(!DocSoNguyen(c[1],p->trangThai,0,2)) return r.Sai("trang thai cuon sai.");
            *tail=p.release(); tail=&(*tail)->next; ++nc;
        }
    }
    SapXepHeap(tmp.dsDauSach.ds,nd,SachTruoc);
    int ng=0; if(!r.So(ng,0,MAX_DOC_GIA)) return false;
    std::unique_ptr<NutDocGia*[]> nodes(new NutDocGia*[ng]);
    NutDocGia* truoc=nullptr;
    for(int i=0;i<ng;++i) {
        string a[6]; if(!r.Truong(a,6)) return false;
        DocGia g; int count=0; g.ho=a[1];g.ten=a[2];g.phai=a[3];
        if(!DocSoNguyen(a[0],g.maThe,1,INT_MAX)||!DocSoNguyen(a[4],g.trangThaiThe,0,1)
           ||!DocSoNguyen(a[5],count,0,MAX_BAN_GHI-nh)) return r.Sai("ma the/trang thai/so lich su sai.");
        // Noi tam thanh nhanh phai de ThuVien so huu ngay ca khi doc loi.
        std::unique_ptr<NutDocGia> owned(new NutDocGia);owned->thongTin=g;
        NutDocGia* node=owned.release();nodes[i]=node;
        if(truoc) truoc->right=node;else tmp.cayDocGia.root=node;
        truoc=node;MuonTra** tail=&node->thongTin.dsMuonTra;
        for(int j=0;j<count;++j) {
            string h[4]; if(!r.Truong(h,4)) return false;
            std::unique_ptr<MuonTra> p(new MuonTra); p->maSach=h[0];
            if(!DocNgay(h[1],p->ngayMuon)||!DocNgay(h[2],p->ngayTra)||!DocSoNguyen(h[3],p->trangThai,0,2))
                return r.Sai("ngay/trang thai lich su sai.");
            *tail=p.release();tail=&(*tail)->next;++nh;
        }
    }
    SapXepHeap(nodes.get(),ng,[](const NutDocGia* a,const NutDocGia* b){return a->thongTin.maThe<b->thongTin.maThe;});
    for(int i=1;i<ng;++i) if(nodes[i-1]->thongTin.maThe==nodes[i]->thongTin.maThe)
        return r.Sai("trung ma the "+std::to_string(nodes[i]->thongTin.maThe)+".");
    // Can bang khi nap de file theo ma tang khong tao cay suy bien.
    tmp.cayDocGia.root=DungBST(nodes.get(),0,ng);
    if(r.in.peek()!=std::char_traits<char>::eof()) { ++r.dong; return r.Sai("du lieu du cuoi file."); }
    if(r.in.bad()) return r.Sai("loi I/O cuoi file.");
    if(!KiemTraNoiBo(tmp,loi)) { loi="Sau dong "+std::to_string(r.dong)+" (kiem tra lien ket): "+loi; return false; }
    HoanDoiThuVien(tv,tmp); loi.clear(); return true;
}
void Ghi(std::ostream& out,const ThuVien& tv) {
    out<<tv.maTheLonNhatDaCap<<'\n'<<tv.dsDauSach.soLuong<<'\n';
    for(int i=0;i<tv.dsDauSach.soLuong;++i) {
        const DauSach& d=*tv.dsDauSach.ds[i];
        out<<d.ISBN<<'|'<<d.tenSach<<'|'<<d.soTrang<<'|'<<d.tacGia<<'|'<<d.namXuatBan<<'|'<<d.theLoai<<'|'<<DemCuonSach(d.dms)<<'\n';
        for(const CuonSach* c=d.dms;c;c=c->next) out<<c->maSach<<'|'<<c->trangThai<<'|'<<c->viTri<<'\n';
    }
    const int n=DemDocGia(tv.cayDocGia); out<<n<<'\n';
    std::unique_ptr<const NutDocGia*[]> ds(new const NutDocGia*[n]);
    LayDanhSachDocGia(tv.cayDocGia,ds.get(),n);
    for(int i=0;i<n;++i) {
        const DocGia& g=ds[i]->thongTin;
        out<<g.maThe<<'|'<<g.ho<<'|'<<g.ten<<'|'<<g.phai<<'|'<<g.trangThaiThe<<'|'<<DemLichSu(g.dsMuonTra)<<'\n';
        for(const MuonTra* h=g.dsMuonTra;h;h=h->next)
            out<<h->maSach<<'|'<<ChuoiNgay(h->ngayMuon)<<'|'<<ChuoiNgay(h->ngayTra)<<'|'<<h->trangThai<<'\n';
    }
}
bool LuuNoiBo(const ThuVien& tv,const string& path,string& loi) {
    if(!KiemTraNoiBo(tv,loi)) { loi="Khong luu du lieu sai: "+loi;return false; }
    const std::filesystem::path dest=std::filesystem::u8path(path);
    if(dest.empty()||dest.filename().empty()) { loi="Duong dan file rong.";return false; }
    // Tao thu muc tam rieng cung thu muc dich: create_directory la thao tac giu cho.
    // Khong trung file tam cua lan chay khac, cung volume de rename/replace.
    std::filesystem::path dir;
    const auto stamp=std::chrono::high_resolution_clock::now().time_since_epoch().count();
    bool made=false;
    for(int i=0;i<100;++i) {
        dir=dest.parent_path()/std::filesystem::u8path(".thu-vien-save-"+std::to_string(stamp)+"-"+std::to_string(i));
        std::error_code ec;
        if(std::filesystem::create_directory(dir,ec)) { made=true;break; }
        if(ec && ec!=std::errc::file_exists) { loi="Khong tao duoc file tam: "+ec.message();return false; }
    }
    if(!made) { loi="Khong giu duoc ten file tam.";return false; }
    const auto temp=dir/"data.txt";
    struct DonTam {
        std::filesystem::path file,dir;
        ~DonTam(){std::error_code ec;std::filesystem::remove(file,ec);std::filesystem::remove(dir,ec);}
    } cleanup{temp,dir};
    {
        std::ofstream out(temp,std::ios::binary|std::ios::trunc);
        if(!out) { loi="Khong mo duoc file tam de ghi.";return false; }
        Ghi(out,tv);out.flush();
        if(!out) { loi="Ghi/flush file tam that bai; file cu duoc giu.";return false; }
        out.close();
        if(out.fail()) { loi="Dong file tam that bai; file cu duoc giu.";return false; }
    }
    // Doc lai file vua ghi de bat loi serialization truoc khi thay the ban cu.
    ThuVien check;
    if(!DocNoiBo(check,temp.u8string(),loi)) { loi="File tam khong doc lai duoc: "+loi;return false; }
#ifdef _WIN32
    if(!MoveFileExW(temp.c_str(),dest.c_str(),MOVEFILE_REPLACE_EXISTING|MOVEFILE_WRITE_THROUGH)) {
        loi="Thay the file that bai (Windows "+std::to_string(GetLastError())+"); file cu duoc giu.";return false;
    }
#else
    std::error_code ec; std::filesystem::rename(temp,dest,ec);
    if(ec) { loi="Thay the file that bai: "+ec.message()+"; file cu duoc giu.";return false; }
#endif
    loi.clear();return true;
}
} // namespace

ThuVien::~ThuVien() { HuyThuVien(*this); }
void HuyThuVien(ThuVien& tv) {
    HuyCayDocGia(tv.cayDocGia);HuyDanhSachDauSach(tv.dsDauSach);tv.maTheLonNhatDaCap=0;
}
void HoanDoiThuVien(ThuVien& a,ThuVien& b) {
    if(&a==&b) return;
    for(int i=0;i<MAX_DAU_SACH;++i) { DauSach* p=a.dsDauSach.ds[i];a.dsDauSach.ds[i]=b.dsDauSach.ds[i];b.dsDauSach.ds[i]=p; }
    int n=a.dsDauSach.soLuong;a.dsDauSach.soLuong=b.dsDauSach.soLuong;b.dsDauSach.soLuong=n;
    NutDocGia* p=a.cayDocGia.root;a.cayDocGia.root=b.cayDocGia.root;b.cayDocGia.root=p;
    n=a.maTheLonNhatDaCap;a.maTheLonNhatDaCap=b.maTheLonNhatDaCap;b.maTheLonNhatDaCap=n;
}
bool KiemTraToanVen(const ThuVien& tv,string& loi) {
    try { return KiemTraNoiBo(tv,loi); }
    catch(const std::exception& e) { loi=string("Kiem tra that bai: ")+e.what();return false; }
}
bool DocFile(ThuVien& tv,const string& path,string& loi) {
    try { return DocNoiBo(tv,path,loi); }
    catch(const std::exception& e) { loi=string("Doc file that bai; giu du lieu cu: ")+e.what();return false; }
}
bool LuuFile(const ThuVien& tv,const string& path,string& loi) {
    try { return LuuNoiBo(tv,path,loi); }
    catch(const std::exception& e) { loi=string("Luu file that bai: ")+e.what();return false; }
}
