#include "00_KhaiBaoChung.h"

// [THANH] Chuyen tu ban Thanh gui ngay 01/11/2026, giu nguyen logic.

// [THANH] Phan code Thanh cung cap/phu trach.
void them_lich_su(NutDocGia &q, MuonTra muontra)
{
	MuonTra* muontraa=new MuonTra;
	*muontraa= muontra;
	 muontraa->next = nullptr;  
	MuonTra* p=q.thongTin.dsMuonTra;
	while(p!=nullptr && p->next!=nullptr)
	{
		p=p->next;
	
	}
	if(p==nullptr)
	{
		p=muontraa;
		q.thongTin.dsMuonTra=p;
	}
	else 
	{
		p->next=muontraa;
	}
}

// [THANH] Phan code Thanh cung cap/phu trach.
int Dem_so_sach_dang_muon(NutDocGia &q)
{
	int sachdangmuon=0;
	MuonTra* p=q.thongTin.dsMuonTra;
	while(p!=nullptr)
	{
		if(p->trangThai==0)
		sachdangmuon++;
		p=p->next;
	}
	return sachdangmuon;
}

// [THANH] Phan code Thanh cung cap/phu trach.
MuonTra* TimMuonDangMuonTheoMa(NutDocGia &q,string maSach)
{
	
	MuonTra* p=q.thongTin.dsMuonTra;
	while(p!=nullptr)
	{
		if(p->maSach==maSach&&p->trangThai==0)
		{
			return p;
		}
		p=p->next;	
	}
	return nullptr;
	
}

// [THANH] Phan code Thanh cung cap/phu trach.
// Giu moc >= 7 nhu ban gui; can doi chieu quy uoc han muon khi ghep.
bool CoSachQuaHan7Ngay(const NutDocGia &docgia, NgayThang ngayktra)
{
	MuonTra* q = docgia.thongTin.dsMuonTra;
	while(q!=nullptr)
	{
		if(q->trangThai == 0 )
		{
			long long k=KhoangCachNgay(q->ngayMuon,ngayktra);
			if(k>=7) return true; 
		}
		q=q->next;
	}
	return false;
}

// [THANH] Phan code Thanh cung cap/phu trach.
// Chi cap nhat lich su; chua cap nhat trang thai cuon sach.
bool CapNhatLuotTra(const NutDocGia &docgia,string masach, NgayThang ngaytrasach )
{
	MuonTra* q = docgia.thongTin.dsMuonTra;
	while(q!=nullptr && (q->maSach!=masach || q->trangThai!=0 ))
	{	
		q=q->next;
	}
	if(q==nullptr)
	{
		return false;
	}
	q->ngayTra=ngaytrasach;
	q->trangThai=1;
	return true;
}

// [THANH] Phan code Thanh cung cap/phu trach.
void HuyDanhSachMuonTra(NutDocGia &docgia)
{
    MuonTra* q = docgia.thongTin.dsMuonTra;

    while (q != nullptr)
    {
        MuonTra* p = q;
        q = q->next;
        delete p;
    }

    docgia.thongTin.dsMuonTra = nullptr;
}
