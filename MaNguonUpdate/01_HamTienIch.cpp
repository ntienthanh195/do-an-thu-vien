#include "00_KhaiBaoChung.h"
#include <cctype>

// [THAI] Chuyen tu be7fa70, chuc nang c/e.
bool KhoangTrang(unsigned char c){
    return c == ' ' || c == '\t' || c == '\r' || c == '\n';
}

bool LaChuoiRong(const string &s){
    for(const char c : s){
        if(!KhoangTrang(c)) return false;
    }
    return true;
}

// cần trao đổi thêm lại với thầy năm hợp lệ của cuốn sách bắt đầu và kết thúc
// [THAI] Phan code Thai cung cap; dung chung cho nhom.
bool LaNamHopLe(int nam){
    return nam >= 1 && nam <= NAM_HIEN_TAI;
}

// [THAI] Phan code Thai cung cap; dung chung cho nhom.
string ChuanHoaChuoi(string s){
    // Xóa khoảng trắng thừa đầu/cuối
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end = s.find_last_not_of(" \t\r\n");
    if (start == string::npos) return "";
    s = s.substr(start, end - start + 1);
    // Chuyển về chữ thường
    for(char& c : s){
        c = tolower(static_cast<unsigned char> (c));
    }
    return s;
}

// [THAI] Phan code Thai cung cap; dung chung cho nhom.
bool HopLePhai(const string& phai){
    string chuan = ChuanHoaChuoi(phai);
    return chuan == "nam" || chuan == "nu" || chuan == "nữ";
}

// [THAI] Phan code Thai cung cap; dung chung cho nhom.
bool HopLeTrangThaiSach(int trangThai){
    return trangThai == SACH_CHO_MUON || trangThai == SACH_DANG_MUON || trangThai == SACH_THANH_LY;
}

// [THAI] Phan code Thai cung cap; dung chung cho nhom.
bool HopLeTrangThaiMuonTra(int trangThai){
    return trangThai == MUON_DANG_MUON || trangThai == MUON_DA_TRA || trangThai == MUON_LAM_MAT;
}

// [THAI] Phan code Thai cung cap; dung chung cho nhom.
bool HopLeTrangThaiThe(int trangThai){
    return trangThai == THE_HOAT_DONG || trangThai == THE_BI_KHOA;
}

// [THAI] Chuyen tu be7fa70, chuc nang c/e.
string ChuanHoaChuoiSach(const string &s){
    string kq = "";
    bool gap = false; // gap ky tu khac khoang trang
    for(const char c : s){
        if(!KhoangTrang(c)){
            if(gap == false){
                gap = true;
            }
            kq += c;

        }
        else{
            if(gap == true){
                gap = false;
                kq += ' ';
            }
        }
    }
    // truong hop dac biet : "hello world "
    if(kq.size() != 0 && kq[kq.size()-1] == ' '){
        kq.pop_back();
    }
    return kq;
}

int SoSanhChuoi(const string &a, const string &b){
    // a < b : -1, a > b : 1; a = b : 0
    string x = ChuanHoaChuoiSach(a);
    string y = ChuanHoaChuoiSach(b);
    if (x.empty() && y.empty()) return 0;
    if (x.empty()) return -1;
    if (y.empty()) return 1;
    for (int i = 0; i < (int)x.size() && i < (int)y.size(); ++i){
        char x1 = x[i], y1 = y[i];
        if (x1 >= 'A' && x1 <= 'Z') x1 = (char)(x1 + 32);
        if (y1 >= 'A' && y1 <= 'Z') y1 = (char)(y1 + 32);
        if (x1 < y1) return -1;
        if (x1 > y1) return 1;
    }
    return x.size() < y.size() ? -1 : (x.size() > y.size() ? 1 : 0);
}

bool HopLeVanBan(const string &s)
{
    const size_t MAX_VAN_BAN = 100;
    if(s.size() > MAX_VAN_BAN){
        return false;
    }
    if(LaChuoiRong(s)) return false;
    for(const unsigned char c : s){
        if (c == '|')  return false;   // delimiter file
        else if (c == '\\') return false;   // escape char
        else if (c < 32)    return false;   // control char (tab, newline...)
        else if (c == 127)  return false;   // DEL
        else if (c >= 128)  return false;   // khong phai ASCII in duoc
    }
    return true;
}

string ChuanHoaISBN(const string &isbn){
    string res = "";
    for(char c : isbn){
        // ISBN0-13 thuong co dang vi du : 978-3-16-148410-0 hoac 978 3 16 148410 0
        if( c != '-' && !KhoangTrang(c)){
            res += c;
        }
    }
    return res;
}

// [THANH] Nhom ham ngay thang tu ban Thanh gui ngay 01/11/2026.

// [THANH] Phan code Thanh cung cap/phu trach.
bool NamNhuan(int nam)
{
    return nam % 400 == 0 ||
           (nam % 4 == 0 && nam % 100 != 0);
}

// [THANH] Phan code Thanh cung cap/phu trach.
int SoNgayTrongThang(int thang, int nam)
{
    if (thang < 1 || thang > 12 || nam <= 0)
        return 0;

    switch (thang)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;

        case 4:
        case 6:
        case 9:
        case 11:
            return 30;

        case 2:
            if (NamNhuan(nam))
                return 29;
            return 28;
    }

    return 0;
}

// [THANH] Phan code Thanh cung cap/phu trach.
bool NgayHopLe(const NgayThang &ngay)
{
    int soNgay = SoNgayTrongThang(ngay.thang, ngay.nam);

    return soNgay > 0 &&
           ngay.ngay >= 1 &&
           ngay.ngay <= soNgay;
}

// [THANH] Phan code Thanh cung cap/phu trach.
long long Doirangay(NgayThang sngay)
{
	long long soNgay=0;
	for(int i=1;i<sngay.nam;i++)
	{
		if(NamNhuan(i))
		{
			soNgay+= 366;
		}
		else
		{
			soNgay+= 365;
		}
	}


	for(int i=1;i<sngay.thang;i++)
	{
		soNgay+=SoNgayTrongThang(i,sngay.nam);
	}
	soNgay = soNgay + sngay.ngay-1;
	return soNgay;
}

// [THANH] Phan code Thanh cung cap/phu trach.
long long KhoangCachNgay(NgayThang ngayt1, NgayThang ngayt2)
{
    long long i=Doirangay(ngayt1);
	long long j=Doirangay(ngayt2);
	return j-i;
}
