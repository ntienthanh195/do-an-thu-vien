#include "00_KhaiBaoChung.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iomanip>
// Harness tổng hợp, không phải mã sản phẩm hoặc bài người học tự làm.
void ck(bool b,const char* m){if(!b)throw std::runtime_error(m);}
int reader(ThuVien& t,const string& name="An") {int m=0;string e;ck(ThemDocGia(t,"Ho",name,"Nam",m,e),"reader");return m;}
DauSach* book(ThuVien& t,const string& id,const string& name="Ten",int year=2010) {
    DauSach d;d.ISBN=id;d.tenSach=name;d.soTrang=100;d.tacGia="TG";d.namXuatBan=year;d.theLoai="Loai";
    string e;ck(ThemDauSach(t,d,e),"book");return TimDauSachTheoISBN(t.dsDauSach,id);
}
string copy(ThuVien& t,const string& id){string m,e;ck(ThemCuonSach(t,id,"Ke",m,e),"copy");return m;}
MuonTra* history(ThuVien& t,int id,const string& code,int s,int e,int state=1){
    MuonTra* p=new MuonTra;p->maSach=code;p->ngayMuon={s,10,2020};p->ngayTra=state==0?NgayThang{}:NgayThang{e,10,2020};p->trangThai=state;
    MuonTra** q=&TimDocGia(t.cayDocGia,id)->thongTin.dsMuonTra;while(*q)q=&(*q)->next;*q=p;return p;
}
bool valid(ThuVien& t){string e;return KiemTraToanVen(t,e);}
string top(ThuVien& t){std::ostringstream o;InTop10SachDuocMuonNhieuNhat(t,o);return o.str();}
std::vector<string> topids(const string& text){std::vector<string> r;std::istringstream in(text);string l;while(std::getline(in,l)){auto p=l.find(" | ");if(p==string::npos)continue;auto q=l.find(" | ",p+3);r.push_back(l.substr(p+3,q-p-3));}return r;}
int main(int argc,char** argv){try{
 ck(argc==2,"case argument");string mode=argv[1],e;
 ThuVien t;
 if(mode=="own_cycle"){
   int a=reader(t);book(t,"X");string x=copy(t,"X");
   auto p=history(t,a,x,1,1);auto q=history(t,a,x,2,2);q->next=p;
   std::cout<<"BEFORE_MUON copy="<<TimCuonSachToanCuc(t,x)->trangThai<<std::endl;
   MuonSach(t,a,x,{3,10,2020},e); // process isolation + timeout; never normal teardown of a cycle
   q->next=nullptr;ck(false,"cycle unexpectedly returned");
 } else if(mode=="foreign_cycle"){
   int a=reader(t),b=reader(t,"Binh");book(t,"X");book(t,"Y");string x=copy(t,"X"),y=copy(t,"Y");
   auto p=history(t,b,y,1,1);auto q=history(t,b,y,2,2);q->next=p;
   bool ok=MuonSach(t,a,x,{3,10,2020},e);q->next=nullptr;
   ck(!ok,"foreign cycle accepted");ck(e.find("gioi han")!=string::npos,"expected bounded timeline error");
   ck(TimCuonSachToanCuc(t,x)->trangThai==0,"copy changed");ck(!TimDocGia(t.cayDocGia,a)->thongTin.dsMuonTra,"new history");
 } else if(mode=="sort_permutation"){
   for(auto it:std::vector<std::pair<int,string>>{{10,"C"},{20,"B"},{30,"A"}}){DocGia d;d.maThe=it.first;d.ho="Ho";d.ten=it.second;d.phai="Nam";ck(ChenDocGiaCoMa(t.cayDocGia,d,e),"insert");}
   t.maTheLonNhatDaCap=30;ck(valid(t),"sort fixture");std::ostringstream o;InDocGiaTheoTenHo(t,o);
   std::vector<int> actual;std::istringstream in(o.str());string l;while(std::getline(in,l))if(!l.empty()&&l[0]>='0'&&l[0]<='9')actual.push_back(std::stoi(l));
   ck(actual==std::vector<int>({30,20,10}),"sort order/permutation");
   std::vector<int> wrong{30,20,20};auto cmp=[&](int a,int b){return TimDocGia(t.cayDocGia,a)->thongTin.ten<TimDocGia(t.cayDocGia,b)->thongTin.ten;};
   ck(std::is_sorted(wrong.begin(),wrong.end(),cmp),"counterexample not sorted");std::sort(wrong.begin(),wrong.end());ck(wrong!=std::vector<int>({10,20,30}),"counterexample permutation");
 } else if(mode=="top_late"||mode=="top_ties"){
   int a=reader(t);for(int i=0;i<12;++i){std::ostringstream id;id<<'B'<<std::setw(2)<<std::setfill('0')<<i;book(t,id.str(),id.str());string code=copy(t,id.str());int n=mode=="top_late"&&i>=10?(i==10?100:50):1;for(int j=0;j<n;++j)history(t,a,code,1,1);}
   ck(valid(t),"top fixture");auto r=topids(top(t));std::vector<string> exp;
   if(mode=="top_late")exp={"B10","B11","B00","B01","B02","B03","B04","B05","B06","B07"};else exp={"B00","B01","B02","B03","B04","B05","B06","B07","B08","B09"};
   ck(r==exp,"top mismatch");
 } else if(mode=="code509"||mode=="code510"){
   int len=mode=="code509"?509:510;string id(len,'A');auto d=book(t,id);d->dms=new CuonSach;d->dms->maSach=id+"#9";d->dms->viTri="Ke";
   ck(valid(t),"long id initial fixture");string out="UNCHANGED";bool ok=ThemCuonSach(t,id,"Ke",out,e);ck(ok==(len==509),"length boundary");
   ck(DemCuonSach(d->dms)==(len==509?2:1),"count boundary");ck(out==(len==509?id+"#10":"UNCHANGED"),"output boundary");ck(valid(t),"length post-state");
 } else if(mode=="publication_date"){
   ck(HomNay().nam>=2026,"requires date >=2026");book(t,"P","Publication",2025);string c=copy(t,"P");int a=reader(t);
   ck(MuonSach(t,a,c,{1,10,2020},e),"publication loan");ck(valid(t),"publication validator");
 } else if(mode=="sweep_valid"||mode=="sweep_four"){
   int a=reader(t);int count=mode=="sweep_four"?4:1;for(int i=0;i<count;++i){string id="S"+std::to_string(i);book(t,id,id);string c=copy(t,id);history(t,a,c,i==3?5:1,i==3?6:10);}
   bool ok=valid(t);
#ifdef DAY_RESET_MUTANT
   ck(!ok,"mutant sweep unexpectedly accepted");
#else
   ck(ok==(mode=="sweep_valid"),"original sweep oracle");
#endif
 } else if(mode=="bst_bounds"){
   auto node=[](int id){auto p=new NutDocGia;p->thongTin.maThe=id;p->thongTin.ho="Ho";p->thongTin.ten="Ten";p->thongTin.phai="Nam";return p;};
   auto r=node(40),l=node(20),z=node(50);r->left=l;l->right=z;t.cayDocGia.root=r;t.maTheLonNhatDaCap=50;
   ck(!TimDocGia(t.cayDocGia,50),"search should miss invalid subtree");const NutDocGia* rows[3];ck(LayDanhSachDocGia(t.cayDocGia,rows,3)==3,"walk count");ck(rows[0]==l&&rows[1]==z&&rows[2]==r,"walk order");ck(!valid(t),"bad global range accepted");
   z->thongTin.maThe=30;ck(valid(t),"valid global range rejected");z->thongTin.maThe=40;ck(!valid(t),"duplicate ancestor accepted");
 } else if(mode=="partial_batch"){
   book(t,"B");string c=copy(t,"B"),out="old";ck(!ThemCuonSach(t,"B","bad|location",out,e),"bad position accepted");
   ck(out=="old"&&DemCuonSach(TimDauSachTheoISBN(t.dsDauSach,"B")->dms)==1,"partial batch changed");ck(valid(t),"batch post-state");
 } else if(mode=="four_open"){
   int a=reader(t);for(int i=0;i<4;++i){string id="F"+std::to_string(i);book(t,id,id);string c=copy(t,id);history(t,a,c,1,0,0);TimCuonSachToanCuc(t,c)->trangThai=1;}
   ck(!valid(t),"four open accepted");
 } else if(mode=="top_missing"){
   int a=reader(t);book(t,"B");string c=copy(t,"B");history(t,a,"MISSING",1,1);string s=top(t);ck(s.find("Loi toan ven")!=string::npos,"missing not reported");ck(s.find("TOP TOI DA")==string::npos,"partial header");ck(!valid(t),"missing history accepted");
 } else ck(false,"unknown mode");
 std::cout<<"PASS "<<mode<<'\n';return 0;
}catch(const std::exception& e){std::cerr<<"FAIL "<<e.what()<<'\n';return 1;}}
