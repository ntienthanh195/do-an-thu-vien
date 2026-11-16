#include "00_KhaiBaoChung.h"

void TimDauSachTheoTen(const ThuVien &tv, const string &ten, ostream &out) {
    // Chan som dieu kien bien khi chuoi tim kiem rong hoac thu vien chua co sach
    string tenChuan = ChuanHoaChuoi(ten);
    if (LaChuoiRong(tenChuan)) {
        out << "Ten sach can tim khong duoc de trong!\n";
        return;
    }
    if (tv.dsDauSach.soLuong <= 0) {
        out << "Thu vien hien chua co dau sach nao!\n";
        return;
    }

    // Buoc 1 - Binary Search theo tenSach tren mang con tro da sap xep O(log M)
    int l = 0, r = tv.dsDauSach.soLuong - 1, mid = -1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (tv.dsDauSach.ds[m] == nullptr) {
            out << "Loi cau truc: Phat hien con tro dau sach bi rong!\n";
            return;
        }
        int cmp = SoSanhChuoi(tv.dsDauSach.ds[m]->tenSach, tenChuan);
        if (cmp == 0) {
            mid = m;
            break;
        }
        if (cmp < 0) l = m + 1;
        else r = m - 1;
    }

    // Neu tim thay khop chinh xac, mo rong sang trai va phai de gom nhom trung ten
    if (mid != -1) {
        int trai = mid;
        while (trai - 1 >= 0 && tv.dsDauSach.ds[trai - 1] != nullptr &&
               SoSanhChuoi(tv.dsDauSach.ds[trai - 1]->tenSach, tenChuan) == 0) {
            --trai;
        }
        int phai = mid;
        while (phai + 1 < tv.dsDauSach.soLuong && tv.dsDauSach.ds[phai + 1] != nullptr &&
               SoSanhChuoi(tv.dsDauSach.ds[phai + 1]->tenSach, tenChuan) == 0) {
            ++phai;
        }

        out << "Tim thay " << (phai - trai + 1) << " dau sach khop ten \"" << tenChuan << "\":\n";
        out << "====================================================================\n";
        for (int i = trai; i <= phai; ++i) {
            const DauSach *ds = tv.dsDauSach.ds[i];
            out << "[" << (i - trai + 1) << "] Ten sach    : " << ds->tenSach << "\n";
            out << "    Ma ISBN     : " << ds->ISBN << "\n";
            out << "    Tac gia     : " << ds->tacGia << "\n";
            out << "    Nam xuat ban: " << ds->namXuatBan << "\n";
            out << "    The loai    : " << ds->theLoai << "\n";
            out << "    Danh muc ma sach trong thu vien:\n";

            // Tu duy: Duyet danh sach lien ket don dms de in tung maSach va trang thai
            const CuonSach *cs = ds->dms;
            if (cs == nullptr) {
                out << "      (Chua co ban sao vat ly nao trong thu vien)\n";
            } else {
                int demCuon = 0;
                while (cs != nullptr) {
                    if (++demCuon > MAX_BAN_GHI) {
                        out << "      [Canh bao: Danh muc cuon sach vuot gioi han hoac hong con tro]\n";
                        break;
                    }
                    string tenTrangThai = "Khong xac dinh";
                    if (cs->trangThai == SACH_CHO_MUON) tenTrangThai = "Cho muon duoc";
                    else if (cs->trangThai == SACH_DANG_MUON) tenTrangThai = "Da co doc gia muon";
                    else if (cs->trangThai == SACH_THANH_LY) tenTrangThai = "Sach da thanh ly";

                    out << "      - Ma sach: " << cs->maSach
                        << " | Trang thai: " << tenTrangThai;
                    if (!LaChuoiRong(cs->viTri)) out << " | Vi tri: " << cs->viTri;
                    out << "\n";
                    cs = cs->next;
                }
            }
            out << "--------------------------------------------------------------------\n";
        }
        return;
    }

    // Buoc 2 - Du phong tim gan dung (chuoi con khong phan biet hoa/thuong)
    // Mang da sap xep tang dan theo tenSach nen ket qua quet tuan tu tu dong dung thu tu
    string khoaThuong = "";
    for (int i = 0; i < (int)tenChuan.size(); ++i) {
        char c = tenChuan[i];
        if (c >= 'A' && c <= 'Z') c = (char)(c + 32);
        khoaThuong += c;
    }

    int soKetQua = 0;
    for (int i = 0; i < tv.dsDauSach.soLuong; ++i) {
        const DauSach *ds = tv.dsDauSach.ds[i];
        if (ds == nullptr) continue;

        string tenDsChuan = ChuanHoaChuoi(ds->tenSach);
        string tenDsThuong = "";
        for (int j = 0; j < (int)tenDsChuan.size(); ++j) {
            char c = tenDsChuan[j];
            if (c >= 'A' && c <= 'Z') c = (char)(c + 32);
            tenDsThuong += c;
        }

        // Kiem tra thu cong khoaThuong co la chuoi con lien tiep cua tenDsThuong
        bool khopCon = false;
        int n = (int)tenDsThuong.size();
        int m = (int)khoaThuong.size();
        if (m <= n) {
            for (int pos = 0; pos <= n - m; ++pos) {
                bool giong = true;
                for (int k = 0; k < m; ++k) {
                    if (tenDsThuong[pos + k] != khoaThuong[k]) {
                        giong = false;
                        break;
                    }
                }
                if (giong) {
                    khopCon = true;
                    break;
                }
            }
        }

        if (khopCon) {
            ++soKetQua;
            if (soKetQua == 1) {
                out << "Khong co ten khop tuyet doi. Cac dau sach gan dung voi \"" << tenChuan << "\":\n";
                out << "====================================================================\n";
            }
            out << "[" << soKetQua << "] Ten sach    : " << ds->tenSach << "\n";
            out << "    Ma ISBN     : " << ds->ISBN << "\n";
            out << "    Tac gia     : " << ds->tacGia << "\n";
            out << "    Nam xuat ban: " << ds->namXuatBan << "\n";
            out << "    The loai    : " << ds->theLoai << "\n";
            out << "    Danh muc ma sach trong thu vien:\n";

            const CuonSach *cs = ds->dms;
            if (cs == nullptr) {
                out << "      (Chua co ban sao vat ly nao trong thu vien)\n";
            } else {
                int demCuon = 0;
                while (cs != nullptr) {
                    if (++demCuon > MAX_BAN_GHI) {
                        out << "      [Canh bao: Danh muc cuon sach vuot gioi han hoac hong con tro]\n";
                        break;
                    }
                    string tenTrangThai = "Khong xac dinh";
                    if (cs->trangThai == SACH_CHO_MUON) tenTrangThai = "Cho muon duoc";
                    else if (cs->trangThai == SACH_DANG_MUON) tenTrangThai = "Da co doc gia muon";
                    else if (cs->trangThai == SACH_THANH_LY) tenTrangThai = "Sach da thanh ly";

                    out << "      - Ma sach: " << cs->maSach
                        << " | Trang thai: " << tenTrangThai;
                    if (!LaChuoiRong(cs->viTri)) out << " | Vi tri: " << cs->viTri;
                    out << "\n";
                    cs = cs->next;
                }
            }
            out << "--------------------------------------------------------------------\n";
        }
    }

    if (soKetQua == 0) {
        out << "Khong tim thay dau sach nao phu hop voi ten \"" << tenChuan << "\"!\n";
    }
}

void ManHinhTimSach(const ThuVien &tv) {
    // Chan som neu thu vien rong de tranh thao tac nhap vo ich
    if (tv.dsDauSach.soLuong <= 0) {
        ThongBao("Thu vien hien chua co dau sach nao de tim kiem!");
        return;
    }

    // Bo dem streambuf cuc bo giup gom output tu ostream ma khong can <sstream>
    struct BoDemChuoi : public std::streambuf {
        string duLieu;
    protected:
        int_type overflow(int_type ch) override {
            if (ch != traits_type::eof()) duLieu += (char)ch;
            return ch;
        }
    };

    while (true) {
        string tenCanTim;
        if (!NhapDong("TIM SACH THEO TEN - Nhap ten sach (/huy hoac Esc de thoat): ", tenCanTim)) {
            return;
        }
        if (LaChuoiRong(tenCanTim)) {
            ThongBao("Vui long nhap ten sach can tim!");
            continue;
        }

        BoDemChuoi boDem;
        ostream out(&boDem);
        TimDauSachTheoTen(tv, tenCanTim, out);
        HienThiPhanTrang(boDem.duLieu);
    }
}