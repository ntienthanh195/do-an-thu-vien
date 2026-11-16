#include "00_KhaiBaoChung.h"

void TimDauSachTheoTen(const ThuVien &tv, const string &ten, ostream &out) {
    // Tu duy 1: Chan ngay truong hop thu vien chua co du lieu de thong bao ro rang.
    if (tv.dsDauSach.soLuong <= 0) {
        out << "Thu vien hien chua co dau sach nao.\n";
        return;
    }

    // Tu duy 2: Chuan hoa chuoi tim kiem (cat khoang trang dau/cuoi, gom nhieu khoang trang giua thanh 1)
    // giong het cach ThemDauSach da chuan hoa tenSach, giup so sanh khong bi lech vi go du dau cach.
    string tenClean;
    bool dangCoSpace = true;
    for (int i = 0; i < (int)ten.size(); ++i) {
        if (ten[i] == ' ' || ten[i] == '\t') {
            if (!dangCoSpace) {
                tenClean += ' ';
                dangCoSpace = true;
            }
        } else {
            tenClean += ten[i];
            dangCoSpace = false;
        }
    }
    if (!tenClean.empty() && tenClean[tenClean.size() - 1] == ' ') {
        string trimmed;
        for (int i = 0; i < (int)tenClean.size() - 1; ++i) trimmed += tenClean[i];
        tenClean = trimmed;
    }

    if (tenClean.empty()) {
        out << "Loi: Ten sach can tim khong duoc de trong.\n";
        return;
    }

    // Tu duy 3 (Tang 1 - Nhanh nhat O(log N)): Mang ds.ds da sap tang dan theo tenSach,
    // nen ta dung Binary Search de tim khop chinh xac tenSach (khong phan biet hoa/thuong ASCII).
    int lo = 0, hi = tv.dsDauSach.soLuong - 1, midMatch = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (tv.dsDauSach.ds[mid] == nullptr) break;
        const string &tenMid = tv.dsDauSach.ds[mid]->tenSach;

        int i = 0, cmp = 0;
        while (i < (int)tenMid.size() && i < (int)tenClean.size()) {
            char ca = (tenMid[i] >= 'A' && tenMid[i] <= 'Z') ? (char)(tenMid[i] + 32) : tenMid[i];
            char cb = (tenClean[i] >= 'A' && tenClean[i] <= 'Z') ? (char)(tenClean[i] + 32) : tenClean[i];
            if (ca != cb) {
                cmp = (unsigned char)ca < (unsigned char)cb ? -1 : 1;
                break;
            }
            ++i;
        }
        if (cmp == 0 && tenMid.size() != tenClean.size()) {
            cmp = (tenMid.size() < tenClean.size()) ? -1 : 1;
        }

        if (cmp == 0) {
            midMatch = mid;
            break;
        }
        if (cmp < 0) lo = mid + 1;
        else hi = mid - 1;
    }

    // Tu duy 4: Neu Binary Search tim thay 1 vi tri khop chinh xac, mo rong sang trai va phai
    // de gom TAT CA cac dau sach trung ten nhung khac ISBN (chung luon nam lien ke nhau).
    // Neu khong co khop chinh xac, chuyen sang quet toan mang tim theo tu khoa con.
    int duyetTu = 0, duyetDen = tv.dsDauSach.soLuong - 1;
    bool chiKiemTraChinhXac = false;

    if (midMatch != -1) {
        chiKiemTraChinhXac = true;
        duyetTu = midMatch;
        duyetDen = midMatch;

        while (duyetTu > 0 && tv.dsDauSach.ds[duyetTu - 1] != nullptr) {
            const string &t = tv.dsDauSach.ds[duyetTu - 1]->tenSach;
            if (t.size() != tenClean.size()) break;
            bool khop = true;
            for (int i = 0; i < (int)t.size(); ++i) {
                char ca = (t[i] >= 'A' && t[i] <= 'Z') ? (char)(t[i] + 32) : t[i];
                char cb = (tenClean[i] >= 'A' && tenClean[i] <= 'Z') ? (char)(tenClean[i] + 32) : tenClean[i];
                if (ca != cb) {
                    khop = false;
                    break;
                }
            }
            if (!khop) break; // Dieu kien dung: tenSach khac nhau
            --duyetTu;
        }

        while (duyetDen + 1 < tv.dsDauSach.soLuong && tv.dsDauSach.ds[duyetDen + 1] != nullptr) {
            const string &t = tv.dsDauSach.ds[duyetDen + 1]->tenSach;
            if (t.size() != tenClean.size()) break;
            bool khop = true;
            for (int i = 0; i < (int)t.size(); ++i) {
                char ca = (t[i] >= 'A' && t[i] <= 'Z') ? (char)(t[i] + 32) : t[i];
                char cb = (tenClean[i] >= 'A' && tenClean[i] <= 'Z') ? (char)(tenClean[i] + 32) : tenClean[i];
                if (ca != cb) {
                    khop = false;
                    break;
                }
            }
            if (!khop) break; // Dieu kien dung: tenSach khac nhau
            ++duyetDen;
        }
    }

    // Tu duy 5: Gop chung 1 vong lap xuat du lieu cho ca 2 nhanh (chinh xac va tu khoa con)
    // de tranh lap lai doan code in thong tin dau sach & danh muc cuon sach.
    int demKetQua = 0;
    for (int idx = duyetTu; idx <= duyetDen; ++idx) {
        const DauSach *d = tv.dsDauSach.ds[idx];
        if (d == nullptr) continue;

        if (!chiKiemTraChinhXac) {
            // Tim chuoi con thu cong khong phan biet hoa/thuong ASCII (khong dung string::find).
            bool chuaTuKhoa = false;
            if (tenClean.size() <= d->tenSach.size()) {
                int gioiHan = (int)d->tenSach.size() - (int)tenClean.size();
                for (int start = 0; start <= gioiHan; ++start) {
                    bool khop = true;
                    for (int j = 0; j < (int)tenClean.size(); ++j) {
                        char ca = d->tenSach[start + j];
                        char cb = tenClean[j];
                        if (ca >= 'A' && ca <= 'Z') ca = (char)(ca + 32);
                        if (cb >= 'A' && cb <= 'Z') cb = (char)(cb + 32);
                        if (ca != cb) {
                            khop = false;
                            break;
                        }
                    }
                    if (khop) {
                        chuaTuKhoa = true;
                        break;
                    }
                }
            }
            if (!chuaTuKhoa) continue;
        }

        if (demKetQua == 0) {
            if (chiKiemTraChinhXac) {
                out << "KET QUA TIM SACH CHINH XAC CHO \"" << tenClean << "\":\n";
            } else {
                out << "KET QUA TIM SACH THEO TU KHOA \"" << tenClean << "\":\n";
            }
        }
        ++demKetQua;

        // In day du cac truong bat buoc theo yeu cau de bai e.
        out << "------------------------------------------------------------\n";
        out << "[" << demKetQua << "] Ten sach     : " << d->tenSach << "\n";
        out << "    Ma ISBN      : " << d->ISBN << "\n";
        out << "    Tac gia      : " << d->tacGia << "\n";
        out << "    Nam xuat ban : " << d->namXuatBan << "\n";
        out << "    The loai     : " << d->theLoai << "\n";
        out << "    So trang     : " << d->soTrang << "\n";
        out << "    Cac ma sach trong thu vien:\n";

        if (d->dms == nullptr) {
            out << "      (Chua co cuon sach nao thuoc dau sach nay)\n";
        } else {
            for (const CuonSach *cs = d->dms; cs != nullptr; cs = cs->next) {
                const char *nhanTrangThai = "Khong xac dinh";
                if (cs->trangThai == SACH_CHO_MUON) nhanTrangThai = "Cho muon duoc";
                else if (cs->trangThai == SACH_DANG_MUON) nhanTrangThai = "Da co doc gia muon";
                else if (cs->trangThai == SACH_THANH_LY) nhanTrangThai = "Da thanh ly";

                out << "      - Ma sach: " << cs->maSach
                    << " | Trang thai: " << nhanTrangThai
                    << " | Vi tri: " << cs->viTri << "\n";
            }
        }
    }

    if (demKetQua == 0) {
        out << "Khong tim thay dau sach nao phu hop voi ten \"" << tenClean << "\".\n";
    } else {
        out << "------------------------------------------------------------\n";
        out << "Tong cong tim thay: " << demKetQua << " dau sach.\n";
    }
}

void ManHinhTimSach(const ThuVien &tv) {
    // Tu duy UI 1: Chan som neu thu vien dang rong de khong bat thu thu nhap vo ich.
    if (tv.dsDauSach.soLuong <= 0) {
        ThongBao("Thu vien hien chua co dau sach nao de tim kiem.");
        return;
    }

    while (true) {
        string tuKhoa;
        if (!NhapDong("Nhap ten sach can tim (/huy hoac Esc de quay lai): ", tuKhoa)) break;

        // Kiem tra nhanh chuoi chi toan khoang trang ngay o tang UI de thong bao gon bang ThongBao.
        bool coKyTu = false;
        for (int i = 0; i < (int)tuKhoa.size(); ++i) {
            if (tuKhoa[i] != ' ' && tuKhoa[i] != '\t') {
                coKyTu = true;
                break;
            }
        }
        if (!coKyTu) {
            ThongBao("Vui long nhap ten sach hoac tu khoa can tim!");
            continue;
        }

        // Tu duy UI 2: Khong duoc dung <sstream>, nen ta tao bo dem streambuf cuc bo
        // thuan <iostream> + <string> de hung dau ra tu Tang Logic va day vao HienThiPhanTrang.
        struct BoDemChuoi : public std::streambuf {
            string noiDung;
        protected:
            int_type overflow(int_type ch) {
                if (ch != traits_type::eof()) {
                    noiDung += traits_type::to_char_type(ch);
                    return ch;
                }
                return traits_type::not_eof(ch);
            }
            std::streamsize xsputn(const char *s, std::streamsize n) {
                for (std::streamsize i = 0; i < n; ++i) noiDung += s[i];
                return n;
            }
        } buf;

        std::ostream out(&buf);
        TimDauSachTheoTen(tv, tuKhoa, out);
        HienThiPhanTrang(buf.noiDung);
    }
}