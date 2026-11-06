#include "00_KhaiBaoChung.h"

bool KhoangTrang(unsigned char c){
    return c == ' ' || c == '\t' || c == '\r' || c == '\n';
}

bool LaChuoiRong(const string &s){
    for(const char c : s){
        if(!KhoangTrang(c)) return false;
    }
    return true;
}

string ChuanHoaChuoi(const string &s){
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
    string x = ChuanHoaChuoi(a);
    string y = ChuanHoaChuoi(b);
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

bool ChuaChuoi(const string &s, const string &part){
    if(part.size() == 0) return true;
    if(s.size() < part.size()) return false;
    // Dau bang xay ra khi vi tri cuoi cung cua s dung voi part 
    // ( vi du : s = "abc", part = "c" thi i = 2 = s.size() - part.size())
    for(size_t i = 0; i <= s.size() - part.size(); ++i){
        bool check = true;
        for(size_t j = 0; j < part.size(); ++j){
            char x = s[i+j], y = part[j];
            if (x >= 'A' && x <= 'Z') x = (char)(x + 32);
            if (y >= 'A' && y <= 'Z') y = (char)(y + 32);
            if(x != y){
                check = false;
                break;
            }
        }
        if(check) return true;
    }
    return false;
}

void TimDauSachTheoTen(const ThuVien &tv, const string &ten, ostream &out){
    if(LaChuoiRong(ten)){
        out << "Tu khoa tim kiem khong duoc rong.\n";
        return;
    }
    string ch_ten = ChuanHoaChuoi(ten);

    for (int i = 0; i < 60; ++i) out << '=';
    out << "\n TIM KIEM SACH THEO TEN\n";
    for (int i = 0; i < 60; ++i) out << '=';
    out << "\n Tu khoa: " << ch_ten << "\n\n";

    bool timThay = false; // Chi dung de check co ket qua hay khong

    for(int i = 0; i < tv.dsDauSach.soLuong; ++i){
        const DauSach *d = tv.dsDauSach.ds[i];
        if(d != nullptr && ChuaChuoi(d->tenSach, ch_ten)){
            timThay = true;
            
            out << " [" << (i + 1) << "] Ten sach    : " << d->tenSach << '\n';
            out << "     Tac gia     : " << d->tacGia << '\n';
            out << "     The loai    : " << d->theLoai << '\n';
            out << "     Nam xuat ban: " << d->namXuatBan << '\n';
            out << "     ISBN        : " << d->ISBN << '\n';

            if(d->dms == nullptr){
                out << "     Cac cuon    : (chua co cuon nao)\n";
            }
            else{
                const CuonSach *p = d->dms;
                while(p != nullptr){
                    out << "       - " << p->maSach << "  |  ";
                    if(p->trangThai == SACH_CHO_MUON){
                        out << "Cho muon duoc\n";
                    }
                    else if(p->trangThai == SACH_DANG_MUON){
                        out << "Da co nguoi muon\n";
                    }
                    else if(p->trangThai == SACH_THANH_LY){
                        out << "Da thanh ly\n";
                    }
                    else{
                        out << "Trang thai khong xac dinh\n";
                    }
                    p = p->next;
                }
            }
            out << '\n';
        }
    }

    if(!timThay){
        out << " Khong tim thay dau sach nao khop voi tu khoa: " << ch_ten << '\n';
    }
    
    for (int i = 0; i < 60; ++i) out << '=';
    out << '\n';
}
