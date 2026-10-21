#pragma once
// Phan ky thuat giu giao dien va doc/ghi hien tai. Khong phai cau truc CTDL.
// Nhom doc cac file 00-06 truoc; khong can sua phan nay khi them nghiep vu.

class LoiThuVien
{
    string noiDung;

  public:
    explicit LoiThuVien(const string &s) : noiDung(s)
    {
    }
    const char *what() const
    {
        return noiDung.c_str();
    }
};

// So huu tam duy nhat. Khong thay mang/DSLK/BST luu du lieu nghiep vu.
// Cac wrapper nay khong cho sao chep, tu giai phong khi return/throw.
template <class T> class ConTroTam
{
    T *p;
    ConTroTam(const ConTroTam &) = delete;
    ConTroTam &operator=(const ConTroTam &) = delete;

  public:
    explicit ConTroTam(T *value = nullptr) : p(value)
    {
    }
    ~ConTroTam()
    {
        delete p;
    }
    T *get() const
    {
        return p;
    }
    T *operator->() const
    {
        return p;
    }
    T &operator*() const
    {
        return *p;
    }
    T *release()
    {
        T *old = p;
        p = nullptr;
        return old;
    }
    void reset(T *value = nullptr)
    {
        if (p != value)
        {
            delete p;
            p = value;
        }
    }
};
template <class T> class ConTroTam<T[]>
{
    T *p;
    ConTroTam(const ConTroTam &) = delete;
    ConTroTam &operator=(const ConTroTam &) = delete;

  public:
    explicit ConTroTam(T *value = nullptr) : p(value)
    {
    }
    ~ConTroTam()
    {
        delete[] p;
    }
    T *get() const
    {
        return p;
    }
    T &operator[](size_t i) const
    {
        return p[i];
    }
    T *release()
    {
        T *old = p;
        p = nullptr;
        return old;
    }
    void reset(T *value = nullptr)
    {
        if (p != value)
        {
            delete[] p;
            p = value;
        }
    }
};

// Gom cac dong xuat vao string de GUI phan trang, khong can <sstream>.
class BoDemChuoi : public streambuf
{
    string duLieu;

  protected:
    int_type overflow(int_type ch) override
    {
        if (!traits_type::eq_int_type(ch, traits_type::eof()))
            duLieu += traits_type::to_char_type(ch);
        return traits_type::not_eof(ch);
    }
    streamsize xsputn(const char *s, streamsize n) override
    {
        if (n > 0)
            duLieu.append(s, static_cast<size_t>(n));
        return n;
    }

  public:
    const string &str() const
    {
        return duLieu;
    }
};
class LuongChuoi : public ostream
{
    BoDemChuoi boDem;

  public:
    LuongChuoi() : ostream(nullptr)
    {
        rdbuf(&boDem);
        exceptions(ios::badbit | ios::failbit);
    }
    const string &str() const
    {
        return boDem.str();
    }
};

inline wstring DuongDanUTF16(const string &s)
{
    if (s.empty())
        return L"";
    if (s.size() > static_cast<size_t>(SO_NGUYEN_LON_NHAT))
        throw LoiThuVien("Duong dan qua dai");
    int n = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, s.data(), static_cast<int>(s.size()),
                                nullptr, 0);
    if (!n)
        throw LoiThuVien("Duong dan khong phai UTF-8 hop le");
    wstring out(static_cast<size_t>(n), L'\0');
    if (!MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, s.data(), static_cast<int>(s.size()),
                             &out[0], n))
        throw LoiThuVien("Khong doi duoc duong dan UTF-16");
    for (wchar_t c : out)
        if (c == 0)
            throw LoiThuVien("Duong dan chua NUL");
    return out;
}
inline string DuongDanUTF8(const wstring &s)
{
    if (s.empty())
        return "";
    int n = WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, s.data(), static_cast<int>(s.size()),
                                nullptr, 0, nullptr, nullptr);
    if (!n)
        throw LoiThuVien("Duong dan UTF-16 khong hop le");
    string out(static_cast<size_t>(n), '\0');
    if (!WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, s.data(), static_cast<int>(s.size()),
                             &out[0], n, nullptr, nullptr))
        throw LoiThuVien("Khong doi duoc duong dan UTF-8");
    return out;
}
inline wstring DuongDanDayDu(const string &path)
{
    if (path.empty())
        throw LoiThuVien("Duong dan rong");
    wstring input = DuongDanUTF16(path);
    DWORD size = GetFullPathNameW(input.c_str(), 0, nullptr, nullptr);
    if (!size)
        throw LoiThuVien("Khong xac dinh duoc duong dan day du");
    ConTroTam<wchar_t[]> buffer(new wchar_t[size]);
    DWORD used = GetFullPathNameW(input.c_str(), size, buffer.get(), nullptr);
    if (!used || used >= size)
        throw LoiThuVien("Duong dan thay doi / qua dai");
    return wstring(buffer.get(), used);
}
inline wstring ThuMucCha(const wstring &path)
{
    for (size_t i = path.size(); i > 0; --i)
        if (path[i - 1] == L'\\' || path[i - 1] == L'/')
            return path.substr(0, i);
    return L"";
}
inline bool FileTonTai(const string &path)
{
    DWORD a = GetFileAttributesW(DuongDanUTF16(path).c_str());
    if (a != INVALID_FILE_ATTRIBUTES)
        return true;
    DWORD e = GetLastError();
    if (e == ERROR_FILE_NOT_FOUND || e == ERROR_PATH_NOT_FOUND)
        return false;
    throw LoiThuVien("Khong kiem tra duoc duong dan (Windows " + to_string(e) + ")");
}
inline void TaoThuMuc(wstring path)
{
    if (path.empty())
        return;
    DWORD a = GetFileAttributesW(path.c_str());
    if (a != INVALID_FILE_ATTRIBUTES)
    {
        if (a & FILE_ATTRIBUTE_DIRECTORY)
            return;
        throw LoiThuVien("Vi tri thu muc dang la mot file");
    }
    while (!path.empty() && (path.back() == L'\\' || path.back() == L'/'))
        path.pop_back();
    wstring parent = ThuMucCha(path);
    if (parent.empty() || parent == path)
        throw LoiThuVien("Khong truy cap duoc thu muc goc");
    TaoThuMuc(parent);
    if (!CreateDirectoryW(path.c_str(), nullptr))
    {
        a = GetFileAttributesW(path.c_str());
        if (a == INVALID_FILE_ATTRIBUTES || !(a & FILE_ATTRIBUTE_DIRECTORY))
            throw LoiThuVien("Khong tao duoc thu muc (Windows " + to_string(GetLastError()) + ")");
    }
}

// Tach doi so UTF-16 cua Windows, giu quote/backslash, khong can shellapi.h.
// out can command.size()+1 o; argv[0] co quy tac rieng cho ten executable.
inline int DocDoiSoWindows(const wstring &command, string *out)
{
    size_t i = 0;
    int count = 0;
    while (i < command.size() && (command[i] == L' ' || command[i] == L'\t'))
        ++i;
    wstring exe;
    bool quoted = false;
    while (i < command.size())
    {
        wchar_t c = command[i];
        if (c == L'"')
        {
            quoted = !quoted;
            ++i;
            continue;
        }
        if (!quoted && (c == L' ' || c == L'\t'))
            break;
        exe += c;
        ++i;
    }
    out[count++] = DuongDanUTF8(exe);
    while (i < command.size())
    {
        while (i < command.size() && (command[i] == L' ' || command[i] == L'\t'))
            ++i;
        if (i == command.size())
            break;
        wstring value;
        quoted = false;
        while (i < command.size())
        {
            if (!quoted && (command[i] == L' ' || command[i] == L'\t'))
                break;
            size_t slashes = 0;
            while (i < command.size() && command[i] == L'\\')
            {
                ++slashes;
                ++i;
            }
            if (i < command.size() && command[i] == L'"')
            {
                value.append(slashes / 2, L'\\');
                if (slashes % 2)
                {
                    value += L'"';
                    ++i;
                }
                else if (quoted && i + 1 < command.size() && command[i + 1] == L'"')
                {
                    value += L'"';
                    i += 2;
                }
                else
                {
                    quoted = !quoted;
                    ++i;
                }
            }
            else
            {
                value.append(slashes, L'\\');
                if (i == command.size() || (!quoted && (command[i] == L' ' || command[i] == L'\t')))
                    break;
                value += command[i++];
            }
        }
        out[count++] = DuongDanUTF8(value);
    }
    return count;
}

// File Unicode: MinGW cu khong co constructor fstream(wchar_t*).
// Dung HANDLE Win32 lam nguon/dich cua stream C++11, khong doi dinh dang v1.
class BoDemDocTep : public streambuf
{
    HANDLE file;
    char buffer[8192];
    bool loi;
    BoDemDocTep(const BoDemDocTep &) = delete;
    BoDemDocTep &operator=(const BoDemDocTep &) = delete;

  protected:
    int_type underflow() override
    {
        if (gptr() < egptr())
            return traits_type::to_int_type(*gptr());
        DWORD n = 0;
        if (file == INVALID_HANDLE_VALUE || !ReadFile(file, buffer, sizeof(buffer), &n, nullptr))
        {
            loi = true;
            return traits_type::eof();
        }
        if (!n)
            return traits_type::eof();
        setg(buffer, buffer, buffer + n);
        return traits_type::to_int_type(*gptr());
    }

  public:
    explicit BoDemDocTep(const string &path) : file(INVALID_HANDLE_VALUE), loi(false)
    {
        const wstring wide = DuongDanUTF16(path);
        file = CreateFileW(wide.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING,
                           FILE_ATTRIBUTE_NORMAL, nullptr);
        setg(buffer, buffer, buffer);
    }
    ~BoDemDocTep()
    {
        if (file != INVALID_HANDLE_VALUE)
            CloseHandle(file);
    }
    bool moDuoc() const
    {
        return file != INVALID_HANDLE_VALUE;
    }
    bool biLoi() const
    {
        return loi;
    }
};
class TepDoc : public istream
{
    BoDemDocTep boDem;

  public:
    explicit TepDoc(const string &path) : istream(nullptr), boDem(path)
    {
        rdbuf(&boDem);
        if (!boDem.moDuoc())
            setstate(ios::failbit);
    }
    bool bad() const
    {
        return istream::bad() || boDem.biLoi();
    }
};
class BoDemGhiTep : public streambuf
{
    HANDLE file;
    char buffer[8192];
    bool loi;
    BoDemGhiTep(const BoDemGhiTep &) = delete;
    BoDemGhiTep &operator=(const BoDemGhiTep &) = delete;
    bool dayBoDem()
    {
        if (file == INVALID_HANDLE_VALUE || loi)
            return false;
        DWORD count = static_cast<DWORD>(pptr() - pbase()), done = 0;
        while (done < count)
        {
            DWORD n = 0;
            if (!WriteFile(file, buffer + done, count - done, &n, nullptr) || !n)
            {
                loi = true;
                return false;
            }
            done += n;
        }
        setp(buffer, buffer + sizeof(buffer));
        return true;
    }

  protected:
    int_type overflow(int_type ch) override
    {
        if (!dayBoDem())
            return traits_type::eof();
        if (!traits_type::eq_int_type(ch, traits_type::eof()))
        {
            *pptr() = traits_type::to_char_type(ch);
            pbump(1);
        }
        return traits_type::not_eof(ch);
    }
    int sync() override
    {
        if (!dayBoDem() || !FlushFileBuffers(file))
        {
            loi = true;
            return -1;
        }
        return 0;
    }

  public:
    explicit BoDemGhiTep(const wstring &path) : file(INVALID_HANDLE_VALUE), loi(false)
    {
        file = CreateFileW(path.c_str(), GENERIC_WRITE, 0, nullptr, CREATE_ALWAYS,
                           FILE_ATTRIBUTE_NORMAL, nullptr);
        setp(buffer, buffer + sizeof(buffer));
    }
    ~BoDemGhiTep()
    {
        dong();
    }
    bool moDuoc() const
    {
        return file != INVALID_HANDLE_VALUE;
    }
    bool dong()
    {
        if (file == INVALID_HANDLE_VALUE)
            return !loi;
        bool ok = sync() == 0;
        if (!CloseHandle(file))
            ok = false;
        file = INVALID_HANDLE_VALUE;
        loi = !ok;
        return ok;
    }
};
class TepGhi : public ostream
{
    BoDemGhiTep boDem;

  public:
    explicit TepGhi(const wstring &path) : ostream(nullptr), boDem(path)
    {
        rdbuf(&boDem);
        if (!boDem.moDuoc())
            setstate(ios::failbit);
    }
    void close()
    {
        if (!boDem.dong())
            setstate(ios::failbit);
    }
};

inline bool KiemTraVanBanHeThong(const string &s)
{

    if (LaChuoiRong(s) || s.size() > 512)
        return false;
    // Kiem tra UTF-8 that, khong chi chap nhan byte bat ky.
    for (size_t i = 0; i < s.size();)
    {
        unsigned char c = static_cast<unsigned char>(s[i]);
        if (c < 128)
        {
            if (c < 32 || c == 127 || c == '|')
                return false;
            ++i;
            continue;
        }
        int n = 0;
        unsigned int cp = 0;
        if (c >= 0xC2 && c <= 0xDF)
        {
            n = 2;
            cp = c & 31U;
        }
        else if (c >= 0xE0 && c <= 0xEF)
        {
            n = 3;
            cp = c & 15U;
        }
        else if (c >= 0xF0 && c <= 0xF4)
        {
            n = 4;
            cp = c & 7U;
        }
        else
            return false;
        if (i + static_cast<size_t>(n) > s.size())
            return false;
        for (int k = 1; k < n; ++k)
        {
            unsigned char b = static_cast<unsigned char>(s[i + static_cast<size_t>(k)]);
            if ((b & 0xC0U) != 0x80U)
                return false;
            cp = (cp << 6U) | (b & 63U);
        }
        if ((n == 3 && cp < 0x800) || (n == 4 && cp < 0x10000) || cp > 0x10FFFF ||
            (cp >= 0xD800 && cp <= 0xDFFF) || cp == 0xFEFF || (cp >= 0x80 && cp <= 0x9F))
            return false;
        i += static_cast<size_t>(n);
    }
    return true;
}
