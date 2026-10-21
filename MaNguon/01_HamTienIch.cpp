// Nhóm hàm chung
bool LaChuoiRong(const string& s){
    bool laKhoangTrang[256] = { false };
        laKhoangTrang[9]  = true; // '\t' : Tab ngang
        laKhoangTrang[10] = true; // '\n' : Xuống dòng (Line feed)
        laKhoangTrang[11] = true; // '\v' : Tab dọc
        laKhoangTrang[12] = true; // '\f' : Sang trang (Form feed)
        laKhoangTrang[13] = true; // '\r' : Về đầu dòng (Carriage return)
        laKhoangTrang[32] = true; // ' '  : Dấu cách (Space)
    for(size_t i = 0; i < s.size(); ++i){
        if(!laKhoangTrang[static_cast<unsigned char>(s[i])]){
            return false;
        }
    }
    return true;
}

// cần trao đổi thêm lại với thầy năm hợp lệ của cuốn sách bắt đầu và kết thúc 
bool LaNamHopLe(int nam){
    return nam >= 1 && nam <= NAM_HIEN_TAI;
}

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

bool HopLePhai(const string& phai){
    string chuan = ChuanHoaChuoi(phai);
    return chuan == "nam" || chuan == "nu" || chuan == "nữ";
}

bool HopLeTrangThaiSach(int trangThai){
    return trangThai == SACH_CHO_MUON || trangThai == SACH_DANG_MUON || trangThai == SACH_THANH_LY;
}

bool HopLeTrangThaiMuonTra(int trangThai){
    return trangThai == MUON_DANG_MUON || trangThai == MUON_DA_TRA || trangThai == MUON_LAM_MAT;
}

bool HopLeTrangThaiThe(int trangThai){
    return trangThai == THE_HOAT_DONG || trangThai == THE_BI_KHOA;
}