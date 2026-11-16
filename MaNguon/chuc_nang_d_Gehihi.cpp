// Dat cac ham nay vao file: 02_DauSach.cpp (cung file voi cac ham Phan 02 da viet)
// Chi dung #include "00_KhaiBaoChung.h", khong dung STL (vector/map/algorithm/sstream).

#include "00_KhaiBaoChung.h"

void InDauSachTheoTheLoai(const ThuVien &tv, ostream &out) {
    // Tu duy 1: Dem so dau sach hop le (khac nullptr) truoc khi cap phat mang tam.
    // Neu thu vien rong thi ket thuc som, khong cap phat thua.
    int m = 0;
    for (int i = 0; i < tv.dsDauSach.soLuong; ++i) {
        if (tv.dsDauSach.ds[i] != nullptr) ++m;
    }
    if (m == 0) {
        out << "Thu vien hien chua co dau sach nao.\n";
        return;
    }

    // Tu duy 2: Khong duoc sua thu tu mang goc (const ThuVien &tv) va khong dung STL,
    // nen ta cap phat mang con tro tam + mang chi so order[] de sap xep gian tiep.
    // Chuan hoa keyTL (the loai) va keyTen (ten sach) 1 lan duy nhat giup MergeSort
    // so sanh truc tiep voi toc do cao va hoan toan nhat quan.
    const DauSach **dsArr = nullptr;
    string *keyTL = nullptr;
    string *keyTen = nullptr;
    int *order = nullptr;
    int *buf = nullptr;

    try {
        dsArr = new const DauSach*[m];
        keyTL = new string[m];
        keyTen = new string[m];
        order = new int[m];
        buf = new int[m];
    } catch (...) {
        delete[] dsArr;
        delete[] keyTL;
        delete[] keyTen;
        delete[] order;
        delete[] buf;
        out << "Loi: Khong du bo nho tam de thong ke sach theo the loai.\n";
        return;
    }

    int idx = 0;
    for (int i = 0; i < tv.dsDauSach.soLuong; ++i) {
        const DauSach *d = tv.dsDauSach.ds[i];
        if (d == nullptr) continue;

        dsArr[idx] = d;
        order[idx] = idx;

        // Tao khoa chuan hoa (bo space thua + ha ASCII hoa ve thuong) cho theLoai va tenSach.
        const string *nguon[2] = {&d->theLoai, &d->tenSach};
        string *dich[2] = {&keyTL[idx], &keyTen[idx]};
        for (int k = 0; k < 2; ++k) {
            const string &src = *nguon[k];
            string res;
            bool dangCoSpace = true;
            for (int j = 0; j < (int)src.size(); ++j) {
                char c = src[j];
                if (c == ' ' || c == '\t') {
                    if (!dangCoSpace) {
                        res += ' ';
                        dangCoSpace = true;
                    }
                } else {
                    if (c >= 'A' && c <= 'Z') c = (char)(c + 32);
                    res += c;
                    dangCoSpace = false;
                }
            }
            if (!res.empty() && res[res.size() - 1] == ' ') {
                string trimmed;
                for (int j = 0; j < (int)res.size() - 1; ++j) trimmed += res[j];
                res = trimmed;
            }
            *dich[k] = res;
        }
        ++idx;
    }

    // Tu duy 3: Dung MergeSort lap tu duoi len (khong de quy -> khong lo tran stack),
    // do phuc tap O(m log m) on dinh trong moi truong hop.
    // Tieu chi sap xep: (1) keyTL tang dan -> (2) keyTen tang dan -> (3) ISBN tang dan.
    for (int width = 1; width < m; width *= 2) {
        for (int left = 0; left < m; left += 2 * width) {
            int mid = left + width;
            if (mid > m) mid = m;
            int right = left + 2 * width;
            if (right > m) right = m;

            int p = left, q = mid, k = left;
            while (p < mid && q < right) {
                int ia = order[p];
                int ib = order[q];
                bool aTruoc = false;
                if (keyTL[ia] != keyTL[ib]) {
                    aTruoc = (keyTL[ia] < keyTL[ib]);
                } else if (keyTen[ia] != keyTen[ib]) {
                    aTruoc = (keyTen[ia] < keyTen[ib]);
                } else {
                    aTruoc = (dsArr[ia]->ISBN <= dsArr[ib]->ISBN);
                }

                if (aTruoc) buf[k++] = order[p++];
                else buf[k++] = order[q++];
            }
            while (p < mid) buf[k++] = order[p++];
            while (q < right) buf[k++] = order[q++];

            for (int t = left; t < right; ++t) order[t] = buf[t];
        }
    }

    // Tu duy 4: Sau khi da sap theo (theLoai, tenSach), cac dau sach cung the loai nam lien ke nhau.
    // Duyet 1 luot qua mang order[] de ngat nhom moi khi keyTL thay doi va xuat ket qua.
    out << "DANH SACH DAU SACH THEO TUNG THE LOAI (TEN SACH TANG DAN)\n";
    out << "============================================================\n";

    int soTheLoai = 0;
    int i = 0;
    while (i < m) {
        const string &nhomKey = keyTL[order[i]];
        const string &tenNhomHienThi = dsArr[order[i]]->theLoai;
        ++soTheLoai;

        out << "\nTHE LOAI [" << soTheLoai << "]: "
            << (nhomKey.empty() ? string("(Chua phan loai)") : tenNhomHienThi) << "\n";
        out << "------------------------------------------------------------\n";

        int sttTrongNhom = 0;
        while (i < m && keyTL[order[i]] == nhomKey) {
            const DauSach *d = dsArr[order[i]];
            ++sttTrongNhom;

            // Dem nhanh tong so ban sao va so cuon dang san sang cho muon trong DSLK dms.
            int tongBanSao = 0, sanSang = 0;
            for (const CuonSach *cs = d->dms; cs != nullptr; cs = cs->next) {
                ++tongBanSao;
                if (cs->trangThai == SACH_CHO_MUON) ++sanSang;
            }

            out << "  " << sttTrongNhom << ". Ten sach: " << d->tenSach
                << " | ISBN: " << d->ISBN
                << " | Tac gia: " << d->tacGia
                << " | Nam XB: " << d->namXuatBan
                << " | So trang: " << d->soTrang
                << " | Ban sao: " << sanSang << "/" << tongBanSao << " cho muon\n";
            ++i;
        }
        out << "  -> Tong trong the loai: " << sttTrongNhom << " dau sach.\n";
    }

    out << "============================================================\n";
    out << "Tong cong: " << soTheLoai << " the loai | " << m << " dau sach.\n";

    // Tu duy 5: Giai phong day du toan bo mang tam truoc khi thoat ham.
    delete[] dsArr;
    delete[] keyTL;
    delete[] keyTen;
    delete[] order;
    delete[] buf;
}

void InDanhSachDauSach(const ThuVien &tv, ostream &out) {
    // Tu duy: Mang dsDauSach da luon duoc duy tri tang dan theo tenSach khi ThemDauSach,
    // nen chi can duyet tuan tu tu dau den cuoi va xuat thong tin tong quat.
    if (tv.dsDauSach.soLuong <= 0) {
        out << "Thu vien hien chua co dau sach nao.\n";
        return;
    }

    out << "DANH SACH TOAN BO DAU SACH (TANG DAN THEO TEN SACH)\n";
    out << "------------------------------------------------------------\n";

    int dem = 0;
    for (int i = 0; i < tv.dsDauSach.soLuong; ++i) {
        const DauSach *d = tv.dsDauSach.ds[i];
        if (d == nullptr) continue;
        ++dem;

        int tongBanSao = 0, sanSang = 0;
        for (const CuonSach *cs = d->dms; cs != nullptr; cs = cs->next) {
            ++tongBanSao;
            if (cs->trangThai == SACH_CHO_MUON) ++sanSang;
        }

        out << dem << ". " << d->tenSach
            << " | ISBN: " << d->ISBN
            << " | The loai: " << d->theLoai
            << " | Tac gia: " << d->tacGia
            << " | Nam XB: " << d->namXuatBan
            << " | Ban sao: " << sanSang << "/" << tongBanSao << "\n";
    }
    if (dem == 0) {
        out << "Thu vien hien chua co dau sach nao.\n";
    } else {
        out << "------------------------------------------------------------\n";
        out << "Tong cong: " << dem << " dau sach.\n";
    }
}