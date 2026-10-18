#include "00_KhaiBaoChung.h"
#include <memory>
#include <ostream>
#include <sstream>
#include <exception>

namespace {
// Khoa phu ISBN lam ket qua on dinh khi hai dau sach cung ten.
int SoSanhDauSach(const DauSach& a, const DauSach& b) {
    int c=SoSanhChuoi(a.tenSach,b.tenSach);
    if(c!=0) return c;
    return a.ISBN<b.ISBN ? -1 : (a.ISBN>b.ISBN ? 1 : 0);
}
void InMotDauSach(const DauSach& d, std::ostream& out, bool chiTiet) {
    out<<"ISBN: "<<d.ISBN<<" | "<<d.tenSach<<" | "<<d.tacGia
       <<" | "<<d.namXuatBan<<" | "<<d.soTrang<<" trang | "<<d.theLoai<<'\n';
    if(!chiTiet) return;
    if(!d.dms) out<<"  Chua co cuon sach.\n";
    for(const CuonSach* p=d.dms;p;p=p->next) {
        const char* tt=p->trangThai==SACH_CHO_MUON ? "Cho muon" :
                       p->trangThai==SACH_DANG_MUON ? "Dang muon" : "Da thanh ly";
        out<<"  "<<p->maSach<<" | "<<tt<<" | Vi tri: "<<p->viTri<<'\n';
    }
}
}

bool HopLeDauSach(const DauSach& d, string& loi) {
    if(!HopLeVanBan(d.ISBN) || !HopLeVanBan(d.tenSach) ||
       !HopLeVanBan(d.tacGia) || !HopLeVanBan(d.theLoai)) {
        loi="ISBN, ten sach, tac gia va the loai phai la van ban khong rong, khong ky tu dieu khien/|.";
        return false;
    }
    // ISBN la ma dinh danh nhom; khong ap checksum ISBN-10/13 khi de chua yeu cau.
    // Dau # danh rieng cho ma cuon ISBN#so; khong duoc nam trong ISBN.
    for(char ch:d.ISBN) if(ch=='#') { loi="ISBN khong duoc chua # (phan tach ma cuon)."; return false; }
    if(d.soTrang<=0) { loi="So trang phai lon hon 0."; return false; }
    if(d.namXuatBan<1 || d.namXuatBan>HomNay().nam) {
        loi="Nam xuat ban phai tu 1 den nam hien tai."; return false;
    }
    loi.clear(); return true;
}

int TimViTriChenTheoTen(const DanhSachDauSach& ds, const DauSach& d) {
    // Lower bound tu cai. O(log D) so sanh; chen van phai don O(D) con tro.
    int left=0,right=ds.soLuong;
    while(left<right) {
        int mid=left+(right-left)/2;
        if(SoSanhDauSach(*ds.ds[mid],d)<0) left=mid+1;
        else right=mid;
    }
    return left;
}

const DauSach* TimDauSachTheoISBN(const DanhSachDauSach& ds,const string& isbn) {
    // Mang sap theo TEN, khong duoc tim nhi phan theo ISBN.
    for(int i=0;i<ds.soLuong;++i) if(ds.ds[i]->ISBN==isbn) return ds.ds[i];
    return nullptr;
}
DauSach* TimDauSachTheoISBN(DanhSachDauSach& ds,const string& isbn) {
    for(int i=0;i<ds.soLuong;++i) if(ds.ds[i]->ISBN==isbn) return ds.ds[i];
    return nullptr;
}

bool ThemDauSach(ThuVien& tv,const DauSach& d,string& loi) {
    try {
        if(tv.dsDauSach.soLuong>=MAX_DAU_SACH) { loi="Mang dau sach da day."; return false; }
        if(d.dms) { loi="ThemDauSach chi nhan thong tin dau sach; them tung cuon bang ThemCuonSach."; return false; }
        // Chan ky tu dieu khien o du lieu GOC; chuan hoa khong duoc che dau loi nhap.
        if(!HopLeDauSach(d,loi)) return false;
        std::unique_ptr<DauSach> moi(new DauSach);
        moi->ISBN=ChuanHoaChuoi(d.ISBN); moi->tenSach=ChuanHoaChuoi(d.tenSach);
        moi->tacGia=ChuanHoaChuoi(d.tacGia); moi->theLoai=ChuanHoaChuoi(d.theLoai);
        moi->soTrang=d.soTrang; moi->namXuatBan=d.namXuatBan;
        if(!HopLeDauSach(*moi,loi)) return false;
        if(TimDauSachTheoISBN(tv.dsDauSach,moi->ISBN)) { loi="ISBN da ton tai."; return false; }
        int pos=TimViTriChenTheoTen(tv.dsDauSach,*moi);
        // Moi phep gan string/cap phat da xong. Commit chi di chuyen con tro.
        for(int i=tv.dsDauSach.soLuong;i>pos;--i) tv.dsDauSach.ds[i]=tv.dsDauSach.ds[i-1];
        tv.dsDauSach.ds[pos]=moi.release(); ++tv.dsDauSach.soLuong;
        loi.clear(); return true;
    } catch(const std::exception&) { loi="Khong du bo nho de them dau sach; du lieu khong doi."; return false; }
}

void TimDauSachTheoTen(const ThuVien& tv,const string& ten,std::ostream& out) {
    string khoa=ChuanHoaChuoi(ten);
    if(LaChuoiRong(khoa)) { out<<"Tu khoa tim kiem khong duoc rong.\n"; return; }
    int n=0;
    for(int i=0;i<tv.dsDauSach.soLuong;++i) if(ChuaChuoi(tv.dsDauSach.ds[i]->tenSach,khoa)) {
        InMotDauSach(*tv.dsDauSach.ds[i],out,true); ++n;
    }
    out<<"Tim thay "<<n<<" dau sach.\n";
}
void InDanhSachDauSach(const ThuVien& tv,std::ostream& out) {
    if(tv.dsDauSach.soLuong==0) out<<"Danh sach dau sach rong.\n";
    for(int i=0;i<tv.dsDauSach.soLuong;++i) InMotDauSach(*tv.dsDauSach.ds[i],out,false);
}

void InDauSachTheoTheLoai(const ThuVien& tv,std::ostream& out) {
    int n=tv.dsDauSach.soLuong;
    if(!n) { out<<"Danh sach dau sach rong.\n"; return; }
    // View muon con tro, khong so huu DauSach. Sap xen O(D^2), bo nho O(D).
    // Mang goc van tang theo ten sau khi ham ket thuc.
    std::unique_ptr<const DauSach*[]> view(new const DauSach*[n]);
    for(int i=0;i<n;++i) {
        const DauSach* key=tv.dsDauSach.ds[i]; int j=i;
        while(j>0) {
            int c=SoSanhChuoi(view[j-1]->theLoai,key->theLoai);
            if(c<0 || (c==0 && SoSanhDauSach(*view[j-1],*key)<=0)) break;
            view[j]=view[j-1]; --j;
        }
        view[j]=key;
    }
    for(int i=0;i<n;++i) {
        if(i==0 || SoSanhChuoi(view[i-1]->theLoai,view[i]->theLoai)!=0)
            out<<"\nTHE LOAI: "<<view[i]->theLoai<<'\n';
        InMotDauSach(*view[i],out,false);
    }
}

void HuyDanhSachDauSach(DanhSachDauSach& ds) {
    for(int i=0;i<ds.soLuong;++i) {
        if(ds.ds[i]) HuyDanhMucCuonSach(ds.ds[i]->dms);
        delete ds.ds[i]; ds.ds[i]=nullptr;
    }
    ds.soLuong=0;
}

void ManHinhNhapDauSach(ThuVien& tv) {
    const char* labels[]={"Them dau sach moi", "Them cuon cho dau sach da co"};
    int choice=ChonMenu("NHAP SACH",labels,2);
    if(choice<1) return;
    string isbn,loi;
    if(DangDungGiaoDienHeThong()) {
        if(choice==1) {
            const char* fields[]={"ISBN", "Ten sach", "So trang", "Tac gia", "Nam xuat ban", "The loai"};
            string values[6]; values[4]=std::to_string(HomNay().nam);
            while(NhapBieuMau("THEM DAU SACH",fields,values,6)) {
                DauSach d;d.ISBN=values[0];d.tenSach=values[1];d.tacGia=values[3];d.theLoai=values[5];
                if(!DocSoNguyen(values[2],d.soTrang,1,2147483647)) {ThongBao("So trang phai la so nguyen duong.");continue;}
                if(!DocSoNguyen(values[4],d.namXuatBan,1,HomNay().nam)) {ThongBao("Nam xuat ban phai tu 1 den nam hien tai.");continue;}
                if(!ThemDauSach(tv,d,loi)) {ThongBao("LOI: "+loi);continue;}
                ThongBao("Da them dau sach "+ChuanHoaChuoi(d.ISBN)+". Chon Them cuon de nhap cac ban sach.");return;
            }
        } else {
            const char* fields[]={"ISBN dau sach", "Vi tri cuon sach"};string values[2];
            while(NhapBieuMau("THEM CUON SACH",fields,values,2)) {
                string ma;
                if(!ThemCuonSach(tv,values[0],values[1],ma,loi)) {ThongBao("LOI: "+loi);continue;}
                ThongBao("Da cap ma cuon: "+ma);return;
            }
        }
        return;
    }
    if(choice==1) {
        DauSach d;
        if(!NhapDong("ISBN: ",d.ISBN) || !NhapDong("Ten sach: ",d.tenSach) ||
           !NhapSo("So trang: ",d.soTrang,1,2147483647) || !NhapDong("Tac gia: ",d.tacGia) ||
           !NhapSo("Nam xuat ban: ",d.namXuatBan,1,HomNay().nam) || !NhapDong("The loai: ",d.theLoai)) return;
        if(!ThemDauSach(tv,d,loi)) { ThongBao(loi); return; }
        isbn=ChuanHoaChuoi(d.ISBN);
        ThongBao("Da them dau sach. Nhap so cuon muon them; 0 de ket thuc.");
    } else {
        if(!NhapDong("ISBN dau sach: ",isbn)) return;
        isbn=ChuanHoaChuoi(isbn);
        if(!TimDauSachTheoISBN(tv.dsDauSach,isbn)) { ThongBao("Khong tim thay ISBN."); return; }
    }
    int n;
    if(!NhapSo("So cuon can them: ",n,0,MAX_BAN_GHI)) return;
    for(int i=0;i<n;++i) {
        string viTri,ma;
        if(!NhapDong("Vi tri cuon "+std::to_string(i+1)+": ",viTri)) {
            ThongBao("Da dung nhap. Dau sach va nhung cuon da them duoc giu lai."); return;
        }
        if(!ThemCuonSach(tv,isbn,viTri,ma,loi)) { ThongBao(loi); return; }
        ThongBao("Da cap ma cuon: "+ma);
    }
}

void ManHinhTimSach(const ThuVien& tv) {
    string ten;
    if(!NhapDong("Ten/phan ten sach can tim: ",ten)) return;
    std::ostringstream out; TimDauSachTheoTen(tv,ten,out); HienThiPhanTrang(out.str());
}
