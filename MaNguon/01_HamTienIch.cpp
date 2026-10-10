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