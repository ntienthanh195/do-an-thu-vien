#include "00_KhaiBaoChung.h"

// [DEMO - CODEX] Phan bo sung cho ban trinh thay.
wstring DuongDanUTF16(const string &s)
{
    if (s.empty())
    {
        return L"";
    }
    if (s.size() > static_cast<size_t>(INT_MAX))
    {
        throw LoiThuVien("Duong dan qua dai");
    }
    int n = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, s.data(), static_cast<int>(s.size()),
                                nullptr, 0);
    if (!n)
    {
        throw LoiThuVien("Duong dan khong phai UTF-8 hop le");
    }
    wstring out(static_cast<size_t>(n), L'\0');
    if (!MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, s.data(), static_cast<int>(s.size()),
                             &out[0], n))
    {
        throw LoiThuVien("Khong doi duoc duong dan UTF-16");
    }
    for (wchar_t c : out)
    {
        if (c == 0)
        {
            throw LoiThuVien("Duong dan chua NUL");
        }
    }
    return out;
}
string DuongDanUTF8(const wstring &s)
{
    if (s.empty())
    {
        return "";
    }
    int n = WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, s.data(), static_cast<int>(s.size()),
                                nullptr, 0, nullptr, nullptr);
    if (!n)
    {
        throw LoiThuVien("Duong dan UTF-16 khong hop le");
    }
    string out(static_cast<size_t>(n), '\0');
    if (!WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, s.data(), static_cast<int>(s.size()),
                             &out[0], n, nullptr, nullptr))
    {
        throw LoiThuVien("Khong doi duoc duong dan UTF-8");
    }
    return out;
}
wstring DuongDanDayDu(const string &path)
{
    if (path.empty())
    {
        throw LoiThuVien("Duong dan rong");
    }
    wstring input = DuongDanUTF16(path);
    DWORD size = GetFullPathNameW(input.c_str(), 0, nullptr, nullptr);
    if (!size)
    {
        throw LoiThuVien("Khong xac dinh duoc duong dan day du");
    }
    wstring buffer(size, L'\0');
    DWORD used = GetFullPathNameW(input.c_str(), size, &buffer[0], nullptr);
    if (!used || used >= size)
    {
        throw LoiThuVien("Duong dan thay doi / qua dai");
    }
    buffer.resize(used);
    return buffer;
}
wstring ThuMucCha(const wstring &path)
{
    for (size_t i = path.size(); i > 0; --i)
    {
        if (path[i - 1] == L'\\' || path[i - 1] == L'/')
        {
            return CatChuoi(path, 0, i);
        }
    }
    return L"";
}
bool FileTonTai(const string &path)
{
    DWORD a = GetFileAttributesW(DuongDanUTF16(path).c_str());
    if (a != INVALID_FILE_ATTRIBUTES)
    {
        return true;
    }
    DWORD e = GetLastError();
    if (e == ERROR_FILE_NOT_FOUND || e == ERROR_PATH_NOT_FOUND)
    {
        return false;
    }
    throw LoiThuVien("Khong kiem tra duoc duong dan (Windows " + ChuoiSo(e) + ")");
}
void TaoThuMuc(wstring path)
{
    if (path.empty())
    {
        return;
    }
    DWORD a = GetFileAttributesW(path.c_str());
    if (a != INVALID_FILE_ATTRIBUTES)
    {
        if (a & FILE_ATTRIBUTE_DIRECTORY)
        {
            return;
        }
        throw LoiThuVien("Vi tri thu muc dang la mot file");
    }
    while (!path.empty() && (path.back() == L'\\' || path.back() == L'/'))
    {
        path.pop_back();
    }
    wstring parent = ThuMucCha(path);
    if (parent.empty() || parent == path)
    {
        throw LoiThuVien("Khong truy cap duoc thu muc goc");
    }
    TaoThuMuc(parent);
    if (!CreateDirectoryW(path.c_str(), nullptr))
    {
        a = GetFileAttributesW(path.c_str());
        if (a == INVALID_FILE_ATTRIBUTES || !(a & FILE_ATTRIBUTE_DIRECTORY))
        {
            throw LoiThuVien("Khong tao duoc thu muc (Windows " + ChuoiSo(GetLastError()) + ")");
        }
    }
}

// Tach doi so UTF-16 cua Windows, giu quote/backslash, khong can shellapi.h.
// out can command.size()+1 o; argv[0] co quy tac rieng cho ten executable.
int DocDoiSoWindows(const wstring &command, string *out)
{
    size_t i = 0;
    int count = 0;
    while (i < command.size() && (command[i] == L' ' || command[i] == L'\t'))
    {
        ++i;
    }
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
        {
            break;
        }
        exe += c;
        ++i;
    }
    out[count++] = DuongDanUTF8(exe);
    while (i < command.size())
    {
        while (i < command.size() && (command[i] == L' ' || command[i] == L'\t'))
        {
            ++i;
        }
        if (i == command.size())
        {
            break;
        }
        wstring value;
        quoted = false;
        while (i < command.size())
        {
            if (!quoted && (command[i] == L' ' || command[i] == L'\t'))
            {
                break;
            }
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
                {
                    break;
                }
                value += command[i++];
            }
        }
        out[count++] = DuongDanUTF8(value);
    }
    return count;
}



namespace
{
struct KhoaTepPhien
{
    HANDLE handle = INVALID_HANDLE_VALUE;
    string tep;
    KhoaTepPhien() = default;
    KhoaTepPhien(const KhoaTepPhien &) = delete;
    KhoaTepPhien &operator=(const KhoaTepPhien &) = delete;
    ~KhoaTepPhien()
    {
        if (handle != INVALID_HANDLE_VALUE)
        {
            CloseHandle(handle);
        }
    }
    bool CungTep(const string &path) const
    {
        const wstring a = DuongDanUTF16(tep), b = DuongDanUTF16(path);
        return CompareStringOrdinal(a.c_str(), -1, b.c_str(), -1, TRUE) == CSTR_EQUAL;
    }
    bool Mo(const string &path, string &loi)
    {
        string ten = path;
        const wstring lock = DuongDanUTF16(path + ".thuvien.lock");
        HANDLE h = CreateFileW(lock.c_str(), GENERIC_READ | GENERIC_WRITE, 0, nullptr, OPEN_ALWAYS,
                               FILE_ATTRIBUTE_NORMAL | FILE_FLAG_DELETE_ON_CLOSE, nullptr);
        if (h == INVALID_HANDLE_VALUE)
        {
            loi = "Khong mo duoc khoa phien: file dang duoc mo o phien khac hoac thu muc khong cho "
                  "ghi.";
            return false;
        }
        tep.swap(ten);
        handle = h;
        return true;
    }
    void HoanDoi(KhoaTepPhien &other) noexcept
    {
        tep.swap(other.tep);
        HANDLE h = handle;
        handle = other.handle;
        other.handle = h;
    }
};
inline bool NapPhien(GiaoDien &gd, ThuVien &tv, string &path, const string &next, KhoaTepPhien &khoa, string &loi)
{
    string moi =
        DuongDanUTF8(DuongDanDayDu(next)); // Moi cap phat/path/lock phai xong truoc DocFile.
    const bool cung = khoa.CungTep(moi);
    KhoaTepPhien khoaMoi;
    if (!cung && !khoaMoi.Mo(moi, loi))
    {
        return false;
    }
    if (!DocFile(tv, moi, loi))
    {
        return false;
    }
    path.swap(moi); // C++11 string cung allocator: swap khong cap phat.
    if (!cung)
    {
        khoa.HoanDoi(khoaMoi);
    }
    gd.chuaLuu = false;
    return true;
}

string TuUTF16(const wstring &s)
{
    if (s.empty())
    {
        return "";
    }
    int n = WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, s.data(), static_cast<int>(s.size()),
                                nullptr, 0, nullptr, nullptr);
    if (!n)
    {
        throw LoiThuVien("Ky tu UTF-16 khong hop le");
    }
    string r(static_cast<size_t>(n), '\0');
    WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, s.data(), static_cast<int>(s.size()), &r[0],
                        n, nullptr, nullptr);
    return r;
}
wstring SangUTF16(const string &s)
{
    if (s.empty())
    {
        return L"";
    }
    int n = MultiByteToWideChar(CP_UTF8, 0, s.data(), static_cast<int>(s.size()), nullptr, 0);
    wstring r(static_cast<size_t>(n), L' ');
    if (n)
    {
        MultiByteToWideChar(CP_UTF8, 0, s.data(), static_cast<int>(s.size()), &r[0], n);
    }
    return r;
}
wstring GhepDauHienThi(const wstring &s)
{
    if (s.empty())
    {
        return s;
    }
    int n = FoldStringW(MAP_PRECOMPOSED, s.data(), static_cast<int>(s.size()), nullptr, 0);
    if (!n)
    {
        return s;
    }
    wstring result(static_cast<size_t>(n), L' ');
    if (!FoldStringW(MAP_PRECOMPOSED, s.data(), static_cast<int>(s.size()), &result[0], n))
    {
        return s;
    }
    return result; // Chi ghep dau de ve; khong thay byte cua ma dinh danh/du lieu.
}
wstring NhanHienThi(const string &s)
{
    const char *raw[] = {"Ho",
                         "Ten",
                         "Ten sach",
                         "So trang",
                         "Tac gia",
                         "Nam xuat ban",
                         "The loai",
                         "ISBN dau sach",
                         "Vi tri cuon sach",
                         "Ma cuon sach",
                         "Ma the doc gia",
                         "Trang thai the (0 khoa, 1 hoat dong)",
                         "THEM DOC GIA",
                         "THEM DAU SACH",
                         "THEM CUON SACH",
                         "Them doc gia",
                         "Sua / khoa / mo the",
                         "Xoa doc gia chua co lich su",
                         "Them dau sach moi",
                         "Them cuon cho dau sach da co",
                         "Theo ma the",
                         "Theo ten + ho",
                         "Tra sach"};
    const wchar_t *pretty[] = {L"Họ và tên đệm",
                               L"Tên",
                               L"Tên sách",
                               L"Số trang",
                               L"Tác giả",
                               L"Năm xuất bản",
                               L"Thể loại",
                               L"ISBN đầu sách",
                               L"Vị trí cuốn sách",
                               L"Mã cuốn sách",
                               L"Mã thẻ độc giả",
                               L"Trạng thái thẻ (0 khóa, 1 hoạt động)",
                               L"Thêm độc giả",
                               L"Thêm đầu sách",
                               L"Thêm cuốn sách",
                               L"Thêm độc giả",
                               L"Sửa thông tin / khóa thẻ",
                               L"Xóa độc giả chưa có lịch sử",
                               L"Thêm đầu sách mới",
                               L"Thêm cuốn vào đầu sách",
                               L"Theo mã thẻ",
                               L"Theo tên và họ",
                               L"Trả sách"};
    for (size_t i = 0; i < sizeof(raw) / sizeof(raw[0]); ++i)
    {
        if (s == raw[i])
        {
            return pretty[i];
        }
    }
    if (s == u8"Phai (Nam/Nữ)")
    {
        return L"Giới tính (Nam / Nữ)";
    }
    return SangUTF16(s);
}
void GhiConsole(const wstring &s)
{
    size_t offset = 0;
    while (offset < s.size())
    {
        DWORD written = 0;
        if (!WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), s.data() + offset,
                           static_cast<DWORD>(s.size() - offset), &written, nullptr) ||
            !written)
        {
            throw LoiThuVien("Khong ve duoc console");
        }
        offset += written;
    }
}
wstring LenhMau(const MauGiaoDien &mau, WORD attr)
{
    COLORREF fg = mau.bangMauUI[attr & 15], bg = mau.bangMauUI[(attr >> 4) & 15];
    return L"\x1b[38;2;" + ChuoiSoRong(GetRValue(fg)) + L";" + ChuoiSoRong(GetGValue(fg)) + L";" +
           ChuoiSoRong(GetBValue(fg)) + L"m\x1b[48;2;" + ChuoiSoRong(GetRValue(bg)) + L";" +
           ChuoiSoRong(GetGValue(bg)) + L";" + ChuoiSoRong(GetBValue(bg)) + L"m";
}
struct PhienGiaoDien
{
    GiaoDien &gd;
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD oldMode = 0;
    bool active = false, hadMode = false, hadPalette = false, fontChanged = false;
    CONSOLE_SCREEN_BUFFER_INFOEX oldPalette{};
    CONSOLE_FONT_INFOEX oldFont{};
    PhienGiaoDien(GiaoDien &giaoDien, bool enabled, bool adjustFont) : gd(giaoDien)
    {
        if (!enabled)
        {
            return;
        }
        active = true;
        oldPalette.cbSize = sizeof(oldPalette);
        oldFont.cbSize = sizeof(oldFont);
        hadPalette = GetConsoleScreenBufferInfoEx(out, &oldPalette) != 0;
        if (hadPalette)
        {
            CONSOLE_SCREEN_BUFFER_INFOEX theme = oldPalette;
            for (int i = 0; i < 16; ++i)
            {
                theme.ColorTable[i] = gd.mau.bangMauUI[i];
            }
            SetConsoleScreenBufferInfoEx(out, &theme);
            SetConsoleWindowInfo(out, TRUE, &oldPalette.srWindow);
        }
        wchar_t terminalSession[2]{};
        if (adjustFont && !GetEnvironmentVariableW(L"WT_SESSION", terminalSession, 2) &&
            GetCurrentConsoleFontEx(out, FALSE, &oldFont))
        {
            CONSOLE_FONT_INFOEX font = oldFont;
            font.dwFontSize = {0, 20};
            font.FontFamily = FF_MODERN;
            font.FontWeight = FW_NORMAL;
            const wchar_t face[] = L"Consolas";
            for (size_t i = 0; i < sizeof(face) / sizeof(face[0]); ++i)
            {
                font.FaceName[i] = face[i];
            }
            fontChanged = SetCurrentConsoleFontEx(out, FALSE, &font) != 0;
        }
        hadMode = GetConsoleMode(out, &oldMode) != 0;
        gd.xuatRGB = hadMode &&
                  SetConsoleMode(out, oldMode | ENABLE_PROCESSED_OUTPUT | gd.mau.cheDoMauConsole) != 0;
        if (gd.xuatRGB)
        {
            GhiConsole(L"\x1b[?1049h\x1b[?7l\x1b[2J\x1b[H");
        }
    }
    ~PhienGiaoDien()
    {
        if (!active)
        {
            return;
        }
        if (gd.xuatRGB)
        {
            try
            {
                GhiConsole(L"\x1b[0m\x1b[?7h\x1b[?25h\x1b[?1049l");
            }
            catch (...)
            {
            }
        }
        gd.xuatRGB = false;
        if (fontChanged)
        {
            SetCurrentConsoleFontEx(out, FALSE, &oldFont);
        }
        if (hadPalette)
        {
            CONSOLE_SCREEN_BUFFER_INFOEX current{};
            current.cbSize = sizeof(current);
            if (GetConsoleScreenBufferInfoEx(out, &current))
            {
                SMALL_RECT rect = current.srWindow;
                for (int i = 0; i < 16; ++i)
                {
                    current.ColorTable[i] = oldPalette.ColorTable[i];
                }
                SetConsoleScreenBufferInfoEx(out, &current);
                SetConsoleWindowInfo(out, TRUE, &rect);
            }
        }
        if (hadMode)
        {
            SetConsoleMode(out, oldMode);
        }
    }
};
Phim DocPhimConsole(GiaoDien &gd)
{
    if (gd.conLai)
    {
        --gd.conLai;
        return gd.phimLap;
    }
    while (true)
    {
        INPUT_RECORD r{};
        DWORD n = 0;
        if (!ReadConsoleInputW(GetStdHandle(STD_INPUT_HANDLE), &r, 1, &n))
        {
            throw LoiThuVien("Khong doc duoc console");
        }
        Phim p;
        if (r.EventType == WINDOW_BUFFER_SIZE_EVENT)
        {
            p.resize = true;
            return p;
        }
        if (r.EventType == KEY_EVENT && r.Event.KeyEvent.bKeyDown)
        {
            const KEY_EVENT_RECORD &k = r.Event.KeyEvent;
            p.ma = k.wVirtualKeyCode;
            p.chu = k.uChar.UnicodeChar;
            p.shift = (k.dwControlKeyState & SHIFT_PRESSED) != 0;
            p.ctrl = (k.dwControlKeyState & (LEFT_CTRL_PRESSED | RIGHT_CTRL_PRESSED)) != 0;
            gd.phimLap = p;
            gd.conLai = k.wRepeatCount > 1 ? static_cast<WORD>(k.wRepeatCount - 1) : 0;
            return p;
        }
        if (r.EventType == MOUSE_EVENT)
        {
            const MOUSE_EVENT_RECORD &m = r.Event.MouseEvent;
            bool down = (m.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) != 0 &&
                        (gd.nutTruoc & FROM_LEFT_1ST_BUTTON_PRESSED) == 0;
            gd.nutTruoc = m.dwButtonState;
            if (down && m.dwEventFlags == 0)
            {
                CONSOLE_SCREEN_BUFFER_INFO s{};
                GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &s);
                p.click = true;
                p.x = m.dwMousePosition.X - s.srWindow.Left;
                p.y = m.dwMousePosition.Y - s.srWindow.Top;
                return p;
            }
        }
    }
}
struct KhungUI
{
    const GiaoDien &gd;
    int w = 80, h = 24;
    SMALL_RECT rect{};
    CHAR_INFO *cells = nullptr;
    // Moi khung so huu mot mang pixel ky tu, khong sao chep quyen so huu.
    KhungUI(const KhungUI &) = delete;
    KhungUI &operator=(const KhungUI &) = delete;
    ~KhungUI()
    {
        delete[] cells;
    }
    explicit KhungUI(const GiaoDien &giaoDien) : gd(giaoDien)
    {
        CONSOLE_SCREEN_BUFFER_INFO s{};
        if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &s))
        {
            rect = s.srWindow;
            w = rect.Right - rect.Left + 1;
            h = rect.Bottom - rect.Top + 1;
        }
        else
        {
            rect = {0, 0, 79, 23};
        }
        cells = new CHAR_INFO[static_cast<size_t>(w) * static_cast<size_t>(h)];
        fill(0, 0, w, h, gd.mau.NEN);
    }
    void put(int x, int y, wchar_t c, WORD a)
    {
        if (x < 0 || x >= w || y < 0 || y >= h)
        {
            return;
        }
        CHAR_INFO &cell =
            cells[static_cast<size_t>(y) * static_cast<size_t>(w) + static_cast<size_t>(x)];
        cell.Char.UnicodeChar = c;
        cell.Attributes = a;
    }
    void fill(int x, int y, int width, int height, WORD a)
    {
        for (int j = 0; j < height; ++j)
        {
            for (int i = 0; i < width; ++i)
            {
                put(x + i, y + j, L' ', a);
            }
        }
    }
    void text(int x, int y, const wstring &s, int width, WORD a)
    {
        if (width < 1)
        {
            return;
        }
        wstring visible = GhepDauHienThi(s);
        int n = static_cast<int>(visible.size());
        bool cut = n > width;
        for (int i = 0; i < width && i < n; ++i)
        {
            wchar_t c = visible[static_cast<size_t>(i)];
            if (c < L' ')
            {
                c = L' ';
            }
            if (c >= 0xD800 && c <= 0xDBFF && (i + 1 >= width || (cut && i + 1 == width - 1)))
            {
                put(x + i, y, L'…', a);
                break;
            }
            put(x + i, y, cut && i == width - 1 ? L'…' : c, a);
        }
    }
    void box(int x, int y, int width, int height, const wstring &title, WORD a)
    {
        if (width < 2 || height < 2)
        {
            return;
        }
        for (int i = 1; i < width - 1; ++i)
        {
            put(x + i, y, L'─', a);
            put(x + i, y + height - 1, L'─', a);
        }
        for (int j = 1; j < height - 1; ++j)
        {
            put(x, y + j, L'│', a);
            put(x + width - 1, y + j, L'│', a);
        }
        put(x, y, L'┌', a);
        put(x + width - 1, y, L'┐', a);
        put(x, y + height - 1, L'└', a);
        put(x + width - 1, y + height - 1, L'┘', a);
        if (!title.empty())
        {
            text(x + 2, y, L" " + title + L" ", width - 4, gd.mau.MO);
        }
    }
    void button(int x, int y, int width, const wstring &s, bool active)
    {
        WORD color = active ? gd.mau.NUT_CHINH : gd.mau.O_NHAP;
        fill(x, y, width, 1, color);
        text(x + 2, y, s, width - 4, color);
    }
    bool small() const
    {
        return w < 80 || h < 24;
    }
    void show(int cx, int cy)
    {
        if (gd.xuatRGB)
        {
            // Dinh vi tung dong, tat wrap: hang cuoi/cot cuoi khong day khung len.
            wstring output = L"\x1b[?25l\x1b[?7l";
            WORD last = 0xFFFF;
            for (int y = 0; y < h; ++y)
            {
                output += L"\x1b[" + ChuoiSoRong(y + 1) + L";1H";
                for (int x = 0; x < w; ++x)
                {
                    const CHAR_INFO &cell = cells[static_cast<size_t>(y) * static_cast<size_t>(w) +
                                                  static_cast<size_t>(x)];
                    if (cell.Attributes != last)
                    {
                        output += LenhMau(gd.mau, cell.Attributes);
                        last = cell.Attributes;
                    }
                    output += cell.Char.UnicodeChar;
                }
            }
            if (cx >= 0)
            {
                output += L"\x1b[" + ChuoiSoRong(cy + 1) + L";" + ChuoiSoRong(cx + 1) +
                          L"H\x1b[6 q\x1b[?25h";
            }
            else
            {
                output += L"\x1b[H";
            }
            GhiConsole(output);
            return;
        }
        CONSOLE_CURSOR_INFO ci{20, cx >= 0 ? TRUE : FALSE};
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ci);
        COORD size{static_cast<SHORT>(w), static_cast<SHORT>(h)}, zero{0, 0};
        SMALL_RECT area = rect;
        WriteConsoleOutputW(GetStdHandle(STD_OUTPUT_HANDLE), cells, size, zero, &area);
        if (cx >= 0)
        {
            SetConsoleCursorPosition(
                GetStdHandle(STD_OUTPUT_HANDLE),
                COORD{static_cast<SHORT>(rect.Left + cx), static_cast<SHORT>(rect.Top + cy)});
        }
    }
};
void NenUngDung(GiaoDien &gd, KhungUI &f, const wstring &title, const wstring &help)
{
    f.fill(0, 0, 23, f.h - 2, gd.mau.THANH);
    f.text(3, 1, L"THƯ VIỆN", 18, 0x1A);
    f.text(26, 1, title, f.w - 45, gd.mau.NEN);
    f.text(f.w - 15, 1, SangUTF16(ChuoiNgay(gd.ngay)), 12, gd.mau.MO);
    for (int x = 26; x < f.w - 3; ++x)
    {
        f.put(x, 2, L'─', gd.mau.VIEN);
    }
    f.text(3, 3, L"KHÔNG GIAN LÀM VIỆC", 19, 0x17);
    for (int i = 0; i < 14 && i + 4 < f.h - 3; ++i)
    {
        WORD a = i == gd.mucUI ? gd.mau.CHON : gd.mau.THANH;
        f.fill(1, i + 4, 21, 1, a);
        f.text(3, i + 4, gd.dieuHuong[i], 18, a);
        if (i == gd.mucUI)
        {
            f.put(1, i + 4, L'│', 0x3A);
        }
    }
    f.fill(0, f.h - 2, f.w, 2, gd.mau.NEN);
    f.text(2, f.h - 2, help, f.w - 4, gd.mau.MO);
    f.text(2, f.h - 1, L"File: " + SangUTF16(gd.duongDan), f.w - 4, 0x08);
    if (f.small())
    {
        f.fill(0, 3, f.w, f.h - 5, gd.mau.NEN);
        f.text(1, 4, L"Phóng lớn terminal lên ít nhất 80 cột × 24 dòng.", f.w - 2, gd.mau.NHAN);
        f.text(1, 6, L"Dữ liệu nhập vẫn được giữ. Esc: quay lại.", f.w - 2, gd.mau.NEN);
    }
}
int XNoiDung()
{
    return 26;
}
void DongBang(GiaoDien &gd, KhungUI &f, int x, int y, int width, const wstring &line, WORD color)
{
    // Cac dong nhom/ngu canh giu nguyen. Dong co | chia o; Enter xem du noi dung.
    int n = 1;
    for (wchar_t c : line)
    {
        if (c == L'|')
        {
            ++n;
        }
    }
    if (n < 2 || n > 8)
    {
        f.text(x, y, line, width, color);
        return;
    }
    wstring fields[8];
    int k = 0;
    for (wchar_t c : line)
    {
        if (c == L'|')
        {
            ++k;
        }
        else
        {
            fields[k] += c;
        }
    }
    int pos = x;
    for (int i = 0; i < n; ++i)
    {
        int cw = width / n + (i == n - 1 ? width % n : 0);
        f.text(pos, y, fields[i], cw - 1, color);
        if (i < n - 1)
        {
            f.put(pos + cw - 1, y, L'│', gd.mau.MO);
        }
        pos += cw;
    }
}
void XemChiTiet(GiaoDien &gd, const wstring &text, const wstring &title)
{
    size_t start = 0;
    while (true)
    {
        KhungUI f(gd);
        NenUngDung(gd, f, title, L"↑/↓: cuộn   Esc / Enter: đóng");
        if (!f.small())
        {
            int x = XNoiDung(), width = f.w - x - 3, rows = f.h - 9;
            f.box(x, 4, width, rows + 2, L"Nội dung đầy đủ", gd.mau.VIEN);
            int inner = width - 4;
            if (start > text.size())
            {
                start = 0;
            }
            for (int i = 0; i < rows; ++i)
            {
                size_t p = start + static_cast<size_t>(i * inner);
                if (p >= text.size())
                {
                    break;
                }
                f.text(x + 2, 5 + i, CatChuoi(text, p, static_cast<size_t>(inner)), inner, gd.mau.NEN);
            }
        }
        f.show(-1, -1);
        Phim p = DocPhimConsole(gd);
        if (p.ma == VK_ESCAPE || p.ma == VK_RETURN)
        {
            return;
        }
        int step = f.w - XNoiDung() - 7;
        if (step < 1)
        {
            step = 1;
        }
        if (p.ma == VK_DOWN && start + static_cast<size_t>(step) < text.size())
        {
            start += static_cast<size_t>(step);
        }
        if (p.ma == VK_UP)
        {
            start = start >= static_cast<size_t>(step) ? start - static_cast<size_t>(step) : 0;
        }
    }
}
struct SoLieu
{
    int dau = 0, cuon = 0, san = 0, doc = 0, muon = 0;
};
SoLieu TongQuan(GiaoDien &gd)
{
    SoLieu s;
    s.dau = gd.thuVien.dsDauSach.soLuong;
    s.doc = DemDocGia(gd.thuVien.cayDocGia);
    for (int i = 0; i < s.dau; ++i)
    {
        for (const CuonSach *p = gd.thuVien.dsDauSach.ds[i]->dms; p; p = p->next)
        {
            ++s.cuon;
            if (p->trangThai == SACH_CHO_MUON)
            {
                ++s.san;
            }
            if (p->trangThai == SACH_DANG_MUON)
            {
                ++s.muon;
            }
        }
    }
    return s;
}
int TrangChinh(GiaoDien &gd)
{
    SoLieu s = TongQuan(gd);
    int focus = 0;
    while (true)
    {
        KhungUI f(gd);
        NenUngDung(gd, f, gd.dieuHuong[gd.mucUI],
                   L"↑/↓: chọn mục   Enter: mở   F1: tổng quan   F5: lưu   Esc/0: lưu và thoát");
        int x = XNoiDung(), width = f.w - x - 3;
        if (!f.small())
        {
            f.text(x, 4, gd.mucUI ? gd.moTa[gd.mucUI] : L"Chào bạn, thư viện hôm nay có gì?", width, gd.mau.NHAN);
            const wchar_t *names[] = {L"Đầu sách", L"Cuốn sách", L"Độc giả", L"Đang giữ"};
            int nums[] = {s.dau, s.cuon, s.doc, s.muon};
            int tile = width / 4;
            for (int i = 0; i < 4; ++i)
            {
                int left = x + i * tile;
                f.fill(left, 6, tile - 2, 4, gd.mau.THANH);
                f.text(left + 2, 7, ChuoiSoRong(nums[i]), tile - 5, 0x1A);
                f.text(left + 1, 8, names[i], tile - 3, 0x17);
            }
            f.text(x, 11, gd.mucUI ? L"THAO TÁC" : L"TRUY CẬP NHANH", width, gd.mau.MO);
            if (!gd.mucUI)
            {
                int bw = (width - 4) / 3;
                f.button(x, 13, bw, L"Mượn sách", focus == 0);
                f.button(x + bw + 2, 13, bw, L"Trả sách", focus == 1);
                f.button(x + 2 * (bw + 2), 13, bw, L"Tìm sách", focus == 2);
            }
            else
            {
                f.button(x, 13, width < 34 ? width : 34, L"Mở " + wstring(gd.dieuHuong[gd.mucUI]), true);
            }
            f.box(x, 16, width, f.h - 19, L"Danh mục đầu sách", gd.mau.VIEN);
            int room = f.h - 22;
            if (room > 0)
            {
                f.fill(x + 1, 17, width - 2, 1, gd.mau.THANH);
                f.text(x + 2, 17, L"ISBN", 17, 0x17);
                f.text(x + 20, 17, L"Tên sách", width - 31, 0x17);
                f.text(x + width - 9, 17, L"Cuốn", 6, 0x17);
                for (int i = 0; i < s.dau && i < room - 1; ++i)
                {
                    const DauSach *d = gd.thuVien.dsDauSach.ds[i];
                    int y = 18 + i;
                    WORD row = i % 2 ? gd.mau.THANH : gd.mau.NEN;
                    f.fill(x + 1, y, width - 2, 1, row);
                    f.text(x + 2, y, SangUTF16(d->ISBN), 17, static_cast<WORD>((row & 0xF0) | 7));
                    f.text(x + 20, y, SangUTF16(d->tenSach), width - 31, row);
                    f.text(x + width - 8, y, ChuoiSoRong(DemCuonSach(d->dms)), 5,
                           static_cast<WORD>((row & 0xF0) | 10));
                }
                if (s.dau == 0)
                {
                    f.text(x + 2, 18, L"Chưa có đầu sách. Mở Kho sách để thêm.", width - 4, gd.mau.MO);
                }
            }
        }
        f.show(-1, -1);
        Phim p = DocPhimConsole(gd);
        if (p.ma == VK_ESCAPE || p.chu == L'0')
        {
            return 0;
        }
        if (p.ma == VK_F5)
        {
            return 12;
        }
        if (p.ma == VK_F1)
        {
            gd.mucUI = 0;
            continue;
        }
        if (f.small())
        {
            continue;
        }
        if (p.ma == VK_UP)
        {
            gd.mucUI = (gd.mucUI + 13) % 14;
        }
        if (p.ma == VK_DOWN)
        {
            gd.mucUI = (gd.mucUI + 1) % 14;
        }
        if (p.ma == VK_TAB || p.ma == VK_RIGHT)
        {
            focus = (focus + 1) % 3;
        }
        if (p.ma == VK_LEFT)
        {
            focus = (focus + 2) % 3;
        }
        if (p.click)
        {
            if (p.x < 23 && p.y >= 4 && p.y < 18)
            {
                gd.mucUI = p.y - 4;
                continue;
            }
            if (p.y == 13 && p.x >= x && p.x < x + width)
            {
                if (gd.mucUI)
                {
                    if (p.x < x + (width < 34 ? width : 34))
                    {
                        return gd.mucUI;
                    }
                }
                else
                {
                    int bw = (width - 4) / 3;
                    int index = (p.x - x) / (bw + 2);
                    if (index < 3 && (p.x - x) % (bw + 2) < bw)
                    {
                        focus = index;
                        const int quick[] = {6, 7, 5};
                        gd.mucUI = quick[focus];
                        return gd.mucUI;
                    }
                }
            }
        }
        if (p.ma == VK_RETURN)
        {
            if (gd.mucUI)
            {
                return gd.mucUI;
            }
            const int quick[] = {6, 7, 5};
            gd.mucUI = quick[focus];
            return gd.mucUI;
        }
        if (p.chu >= L'1' && p.chu <= L'9')
        {
            gd.mucUI = static_cast<int>(p.chu - L'0');
            return gd.mucUI;
        }
    }
}
size_t LuiKyTu(const wstring &s, size_t p)
{
    if (!p)
    {
        return 0;
    }
    --p;
    if (p && s[p] >= 0xDC00 && s[p] <= 0xDFFF && s[p - 1] >= 0xD800 && s[p - 1] <= 0xDBFF)
    {
        --p;
    }
    return p;
}
size_t TienKyTu(const wstring &s, size_t p)
{
    if (p >= s.size())
    {
        return s.size();
    }
    if (s[p] >= 0xD800 && s[p] <= 0xDBFF && p + 1 < s.size() && s[p + 1] >= 0xDC00 &&
        s[p + 1] <= 0xDFFF)
    {
        ++p;
    }
    return p + 1;
}
bool BieuMau(GiaoDien &gd, const string &title, const char *const *labels, string *values, int count,
             const string &thongBao, bool lienTiep)
{
    if (count < 1 || count > 12)
    {
        throw LoiThuVien("Bieu mau chi ho tro 1..12 o");
    }
    wstring fields[12];
    size_t cursors[12]{};
    for (int i = 0; i < count; ++i)
    {
        fields[i] = SangUTF16(values[i]);
        cursors[i] = fields[i].size();
    }
    int active = 0, first = 0;
    while (true)
    {
        KhungUI f(gd);
        NenUngDung(gd, f, NhanHienThi(title),
                   lienTiep ? L"" : L"Tab: đổi ô   Enter: tiếp   Ctrl+Enter: xác nhận   Esc: hủy");
        int x = XNoiDung(), width = f.w - x - 3, capacity = (f.h - 11) / 3;
        if (capacity < 1)
        {
            capacity = 1;
        }
        if (width > 66)
        {
            width = 66;
        }
        int shown = count < capacity ? count : capacity, buttonY = 7 + shown * 3;
        if (buttonY > f.h - 5)
        {
            buttonY = f.h - 5;
        }
        if (active < count)
        {
            if (active < first)
            {
                first = active;
            }
            if (active >= first + capacity)
            {
                first = active - capacity + 1;
            }
        }
        int cx = -1, cy = -1;
        if (!f.small())
        {
            if (lienTiep)
            {
                f.text(x, 4, SangUTF16(thongBao), width, gd.mau.NHAN);
                f.text(x, 5, L"Nhap tiep; Tab/Enter den nut Luu, Esc: ket thuc.", width, gd.mau.MO);
            }
            else
            {
                f.text(x, 4, L"Nhập thông tin và chọn Xác nhận để lưu.", width, gd.mau.MO);
            }
            for (int i = first; i < count && i < first + capacity; ++i)
            {
                int y = 6 + (i - first) * 3;
                f.text(x, y, NhanHienThi(labels[i]), width, active == i ? gd.mau.NHAN : gd.mau.MO);
                WORD fieldColor = active == i ? gd.mau.O_DANG_NHAP : gd.mau.O_NHAP;
                f.fill(x, y + 1, width, 1, fieldColor);
                f.put(x, y + 1, L'│',
                      static_cast<WORD>((fieldColor & 0xF0) | (active == i ? 10 : 8)));
                size_t start = cursors[i] > static_cast<size_t>(width - 4)
                                   ? cursors[i] - static_cast<size_t>(width - 4)
                                   : 0;
                if (start && fields[i][start] >= 0xDC00 && fields[i][start] <= 0xDFFF)
                {
                    --start;
                }
                f.text(x + 2, y + 1, CatChuoi(fields[i], start, string::npos), width - 4, fieldColor);
                if (active == i)
                {
                    cx = x + 2 +
                         static_cast<int>(
                             GhepDauHienThi(CatChuoi(fields[i], start, cursors[i] - start)).size());
                    if (cx > x + width - 2)
                    {
                        cx = x + width - 2;
                    }
                    cy = y + 1;
                }
            }
            f.button(x, buttonY, 20, lienTiep ? L"Luu va nhap tiep" : L"Xác nhận", active == count);
            f.button(x + 22, buttonY, 14, lienTiep ? L"Ket thuc" : L"Hủy", active == count + 1);
            f.text(x, buttonY + 2,
                   L"Ô " + ChuoiSoRong(active < count ? active + 1 : count) + L" / " +
                       ChuoiSoRong(count) + L"  ·  Chưa xác nhận",
                   width, gd.mau.MO);
        }
        f.show(cx, cy);
        Phim p = DocPhimConsole(gd);
        if (p.ma == VK_ESCAPE)
        {
            return false;
        }
        if (f.small())
        {
            continue;
        }
        if (p.click)
        {
            if (p.x >= x && p.x < x + width)
            {
                int row = (p.y - 7) / 3;
                if (p.y >= 7 && (p.y - 7) % 3 == 0 && row >= 0 && first + row < count &&
                    row < capacity)
                {
                    active = first + row;
                    cursors[active] = fields[active].size();
                    continue;
                }
                if (p.y == buttonY)
                {
                    if (p.x < x + 20)
                    {
                        active = count;
                        p.ma = VK_RETURN;
                    }
                    else if (p.x >= x + 22 && p.x < x + 36)
                    {
                        return false;
                    }
                }
            }
        }
        if (p.ma == VK_TAB)
        {
            active = (active + (p.shift ? count + 1 : 1)) % (count + 2);
            continue;
        }
        if (p.ma == VK_UP)
        {
            active = (active + count + 1) % (count + 2);
            continue;
        }
        if (p.ma == VK_DOWN)
        {
            active = (active + 1) % (count + 2);
            continue;
        }
        if (p.ma == VK_RETURN)
        {
            if (p.ctrl || active == count)
            {
                for (int i = 0; i < count; ++i)
                {
                    if (fields[i] == L"/huy")
                    {
                        return false;
                    }
                }
                string converted[12];
                for (int i = 0; i < count; ++i)
                {
                    converted[i] = TuUTF16(fields[i]);
                }
                for (int i = 0; i < count; ++i)
                {
                    values[i] = converted[i];
                }
                return true;
            }
            if (active == count + 1)
            {
                return false;
            }
            ++active;
            continue;
        }
        if (active >= count)
        {
            if (p.ma == VK_LEFT || p.ma == VK_RIGHT)
            {
                active = active == count ? count + 1 : count;
            }
            continue;
        }
        wstring &val = fields[active];
        size_t &cursor = cursors[active];
        if (p.ctrl && p.ma == 'A')
        {
            val.clear();
            cursor = 0;
            continue;
        }
        if (p.ma == VK_LEFT)
        {
            cursor = LuiKyTu(val, cursor);
            continue;
        }
        if (p.ma == VK_RIGHT)
        {
            cursor = TienKyTu(val, cursor);
            continue;
        }
        if (p.ma == VK_HOME)
        {
            cursor = 0;
            continue;
        }
        if (p.ma == VK_END)
        {
            cursor = val.size();
            continue;
        }
        if (p.ma == VK_BACK && cursor)
        {
            size_t prev = LuiKyTu(val, cursor);
            val = CatChuoi(val, 0, prev) + CatChuoi(val, cursor, string::npos);
            cursor = prev;
            continue;
        }
        if (p.ma == VK_DELETE && cursor < val.size())
        {
            val = CatChuoi(val, 0, cursor) + CatChuoi(val, TienKyTu(val, cursor), string::npos);
            continue;
        }
        if (p.chu >= 32 && !p.ctrl && val.size() < 4096)
        {
            val = CatChuoi(val, 0, cursor) + p.chu + CatChuoi(val, cursor, string::npos);
            ++cursor;
        }
    }
}
// [DEMO - CODEX] Tu khoa chi de tim kiem; ho ten tren the van giu nguyen.
wstring TenDeTim(const wstring &ten)
{
    wstring ketQua;
    bool cach = false;
    for (size_t i = 0; i < ten.size(); ++i)
    {
        wchar_t c = ten[i];
        if (c >= 0x0300 && c <= 0x036F) continue;
        if (c == L' ' || c == L'\t')
        {
            cach = !ketQua.empty();
            continue;
        }
        if (c >= L'A' && c <= L'Z') c += L'a' - L'A';
        if (c > 127)
        {
            const wchar_t *nhom[] = {L"àáảãạăằắẳẵặâầấẩẫậÀÁẢÃẠĂẰẮẲẴẶÂẦẤẨẪẬ",
                                     L"èéẻẽẹêềếểễệÈÉẺẼẸÊỀẾỂỄỆ", L"ìíỉĩịÌÍỈĨỊ",
                                     L"òóỏõọôồốổỗộơờớởỡợÒÓỎÕỌÔỒỐỔỖỘƠỜỚỞỠỢ",
                                     L"ùúủũụưừứửữựÙÚỦŨỤƯỪỨỬỮỰ", L"ỳýỷỹỵỲÝỶỸỴ", L"đĐ"};
            const wchar_t chu[] = L"aeiouyd";
            for (int k = 0; k < 7 && c > 127; ++k)
                for (int j = 0; nhom[k][j]; ++j)
                    if (c == nhom[k][j]) { c = chu[k]; break; }
        }
        if (cach) ketQua += L' ';
        ketQua += c;
        cach = false;
    }
    return ketQua;
}

int LocTheDocGia(const NutDocGia *const *danhSach, int soDocGia, const wstring &nhap,
                 const NutDocGia **ketQua)
{
    wstring tuKhoa = TenDeTim(nhap);
    int maNhap = 0;
    bool laMa = !tuKhoa.empty();
    for (size_t i = 0; i < tuKhoa.size(); ++i)
        if (tuKhoa[i] < L'0' || tuKhoa[i] > L'9') laMa = false;
    if (laMa) DocSoNguyen(TuUTF16(tuKhoa), maNhap, 1, INT_MAX);
    int dem = 0;
    for (int i = 0; i < soDocGia; ++i)
    {
        const DocGia &d = danhSach[i]->thongTin;
        bool khop = tuKhoa.empty() || (laMa && maNhap == d.maThe);
        if (!khop && !laMa)
        {
            wstring ten = TenDeTim(SangUTF16(d.ho + " " + d.ten));
            for (size_t viTri = 0; viTri + tuKhoa.size() <= ten.size(); ++viTri)
            {
                size_t j = 0;
                while (j < tuKhoa.size() && ten[viTri + j] == tuKhoa[j]) ++j;
                if (j == tuKhoa.size()) { khop = true; break; }
            }
        }
        if (khop) ketQua[dem++] = danhSach[i];
    }
    return dem;
}

int ChonTheTrenManHinh(GiaoDien &gd, const NutDocGia *const *danhSach, int soDocGia,
                       const NutDocGia **ketQua, const string &tieuDe)
{
    wstring nhap;
    int chon = 0, soKhop = 0;
    bool canLoc = true;
    while (true)
    {
        if (canLoc)
        {
            soKhop = LocTheDocGia(danhSach, soDocGia, nhap, ketQua);
            chon = 0;
            canLoc = false;
        }
        KhungUI f(gd);
        NenUngDung(gd, f, SangUTF16(tieuDe),
                   L"Len/xuong: chon   Enter hoac bam dong: mo the   Esc: huy");
        int x = XNoiDung(), rong = f.w - x - 3;
        int soDong = f.h - 12;
        if (soDong < 1) soDong = 1;
        int dau = chon / soDong * soDong;
        int conTro = -1;
        if (!f.small())
        {
            f.text(x, 4, L"Tim theo ma the hoac mot phan ho ten", rong, gd.mau.NHAN);
            f.fill(x, 5, rong, 1, gd.mau.CHON);
            wstring hien = GhepDauHienThi(nhap);
            int boQua = static_cast<int>(hien.size()) - rong + 3;
            if (boQua > 0) hien = CatChuoi(hien, boQua, hien.size() - boQua);
            f.text(x + 1, 5, hien, rong - 2, gd.mau.CHON);
            f.text(x, 6, L"Bam dong de chon; hoac Len/Xuong, Enter.", rong, gd.mau.MO);
            conTro = x + 1 + static_cast<int>(hien.size());
            f.text(x, 7, L"Ma the", 11, gd.mau.MO);
            f.text(x + 12, 7, L"Ho va ten", rong - 25, gd.mau.MO);
            f.text(x + rong - 12, 7, L"Trang thai", 12, gd.mau.MO);
            for (int i = dau; i < soKhop && i < dau + soDong; ++i)
            {
                int y = 8 + i - dau;
                const DocGia &d = ketQua[i]->thongTin;
                WORD mau = i == chon ? gd.mau.CHON : gd.mau.NEN;
                f.fill(x, y, rong, 1, mau);
                f.text(x, y, ChuoiSoRong(d.maThe), 11, mau);
                f.text(x + 12, y, SangUTF16(d.ho + " " + d.ten), rong - 25, mau);
                f.text(x + rong - 12, y, d.trangThaiThe == THE_HOAT_DONG ? L"Hoat dong" : L"Bi khoa", 12, mau);
            }
            if (!soKhop) f.text(x, 8, L"Khong co doc gia phu hop.", rong, gd.mau.MO);
            f.text(x, f.h - 4, ChuoiSoRong(soKhop) + L" ket qua", 16, gd.mau.MO);
            f.button(x + rong - 18, f.h - 4, 18, L"Chon doc gia", false);
            f.button(x, f.h - 3, 12, L"Truoc", false);
            f.button(x + 14, f.h - 3, 12, L"Sau", false);
            f.button(x + rong - 8, f.h - 3, 8, L"Huy", false);
        }
        f.show(conTro, 5);
        Phim p = DocPhimConsole(gd);
        if (p.ma == VK_ESCAPE) return 0;
        if (f.small()) continue;
        bool truoc = p.ma == VK_PRIOR, sau = p.ma == VK_NEXT;
        if (p.click && p.x >= x && p.x < x + rong)
        {
            if (p.y == f.h - 4 && p.x >= x + rong - 18 && soKhop)
                return ketQua[chon]->thongTin.maThe;
            if (p.y >= 8 && p.y < 8 + soDong && dau + p.y - 8 < soKhop)
                return ketQua[dau + p.y - 8]->thongTin.maThe;
            if (p.y == f.h - 3)
            {
                if (p.x >= x + rong - 8) return 0;
                truoc = p.x < x + 12;
                sau = p.x >= x + 14 && p.x < x + 26;
            }
        }
        if (p.ma == VK_RETURN && soKhop) return ketQua[chon]->thongTin.maThe;
        if (p.ma == VK_UP && chon > 0) --chon;
        if (p.ma == VK_DOWN && chon + 1 < soKhop) ++chon;
        if (truoc) chon = chon >= soDong ? chon - soDong : 0;
        if (sau && soKhop) chon = chon + soDong < soKhop ? chon + soDong : soKhop - 1;
        if (p.ma == VK_BACK && !nhap.empty())
        {
            nhap.pop_back();
            canLoc = true;
        }
        else if (!p.ctrl && p.chu >= L' ' && nhap.size() < 256)
        {
            nhap += p.chu;
            canLoc = true;
        }
    }
}

// [DEMO - CODEX] Chi loc cac cuon cho muon, dung hai mang con tro tam.
int LocCuonChoMuon(const ThuVien &tv, const wstring &nhap,
                   const CuonSach **cuon, const DauSach **dau)
{
    string tuKhoa = TuUTF16(TenDeTim(nhap));
    int soLuong = 0;
    for (int i = 0; i < tv.dsDauSach.soLuong; ++i)
    {
        const DauSach *d = tv.dsDauSach.ds[i];
        bool khopTen = tuKhoa.empty() || ChuaChuoi(TuUTF16(TenDeTim(SangUTF16(d->tenSach))), tuKhoa);
        for (const CuonSach *p = d->dms; p != nullptr; p = p->next)
        {
            if (p->trangThai == SACH_CHO_MUON &&
                (khopTen || ChuaChuoi(p->maSach, tuKhoa)))
            {
                cuon[soLuong] = p;
                dau[soLuong] = d;
                ++soLuong;
            }
        }
    }
    return soLuong;
}

bool ChonCuonTrenManHinh(GiaoDien &gd, const ThuVien &tv, const DocGia &docGia,
                         const CuonSach **cuon,
                         const DauSach **dau, const string &thongBao, bool choMuon,
                         const string &lyDoDung, string &maCuon)
{
    wstring nhap;
    int soKhop = 0, chon = 0, soDangGiu = 0;
    for (const MuonTra *p = docGia.dsMuonTra; p != nullptr; p = p->next)
    {
        if (p->trangThai == MUON_DANG_MUON) ++soDangGiu;
    }
    bool canLoc = true;
    bool daChonDong = false;
    while (true)
    {
        if (canLoc && choMuon)
        {
            soKhop = LocCuonChoMuon(tv, nhap, cuon, dau);
            chon = 0;
            daChonDong = false;
            canLoc = false;
        }
        KhungUI f(gd);
        NenUngDung(gd, f, L"MUON SACH", L"");
        int x = XNoiDung(), rong = f.w - x - 3;
        int soDong = f.h - 21;
        if (soDong < 1) soDong = 1;
        int dauTrang = chon / soDong * soDong;
        bool nhieuTrang = soKhop > soDong;
        int nutY = f.h - 5;
        int conTro = -1;
        if (!f.small())
        {
            f.text(x, 3, L"The " + ChuoiSoRong(docGia.maThe) + L" | " +
                   SangUTF16(docGia.ho + " " + docGia.ten), rong, gd.mau.NHAN);
            f.text(x, 4, L"Dang giu " + ChuoiSoRong(soDangGiu) +
                   L"/3 (Ma cuon | Ten sach | Ngay muon)", rong, gd.mau.MO);
            int dong = 5;
            for (const MuonTra *p = docGia.dsMuonTra; p != nullptr; p = p->next)
            {
                if (p->trangThai == MUON_DANG_MUON && dong < 8)
                {
                    const DauSach *d = nullptr;
                    TimCuonSachToanCuc(tv, p->maSach, &d);
                    string ten = d == nullptr ? "[Lien ket loi]" : d->tenSach;
                    f.text(x, dong, SangUTF16(p->maSach), 16, gd.mau.NEN);
                    f.text(x + 17, dong, SangUTF16(ten), rong - 29, gd.mau.NEN);
                    f.text(x + rong - 10, dong, SangUTF16(ChuoiNgay(p->ngayMuon)), 10, gd.mau.NEN);
                    ++dong;
                }
            }
            if (dong == 5) f.text(x, 5, L"Chua giu cuon nao.", rong, gd.mau.NEN);
            f.text(x, 9, SangUTF16(thongBao), rong, gd.mau.NHAN);
            if (!choMuon)
            {
                f.text(x, 10, SangUTF16(lyDoDung), rong, gd.mau.NHAN);
                f.button(x, 12, 16, L"Ket thuc", true);
                f.text(x, 14, L"Bam Ket thuc, Enter hoac Esc de ve menu.", rong, gd.mau.MO);
            }
            else
            {
                f.text(x, 10, L"Nhap ma sach can muon (hoac ten sach)", rong, gd.mau.NHAN);
                f.fill(x, 11, rong, 1, gd.mau.CHON);
                wstring hien = GhepDauHienThi(nhap);
                int boQua = static_cast<int>(hien.size()) - rong + 3;
                if (boQua > 0) hien = CatChuoi(hien, boQua, hien.size() - boQua);
                f.text(x + 1, 11, hien, rong - 2, gd.mau.CHON);
                conTro = x + 1 + static_cast<int>(hien.size());
                f.text(x, 12, L"Len/Xuong: chon | Enter: muon | Esc: ket thuc", rong, gd.mau.MO);
                f.text(x, 14, L"Ma cuon", 16, gd.mau.MO);
                f.text(x + 17, 14, L"Ten sach", rong - 17, gd.mau.MO);
                for (int i = dauTrang; i < soKhop && i < dauTrang + soDong; ++i)
                {
                    int y = 15 + i - dauTrang;
                    WORD mau = i == chon ? gd.mau.CHON : gd.mau.NEN;
                    f.fill(x, y, rong, 1, mau);
                    f.text(x, y, SangUTF16(cuon[i]->maSach), 16, mau);
                    f.text(x + 17, y, SangUTF16(dau[i]->tenSach), rong - 17, mau);
                }
                if (soKhop)
                {
                    f.text(x, f.h - 6, SangUTF16(cuon[chon]->maSach + " | Vi tri: " +
                           cuon[chon]->viTri), rong, gd.mau.NHAN);
                    f.button(x, nutY, 20, L"Muon cuon nay", false);
                }
                else
                {
                    f.text(x, 15, L"Khong co cuon cho muon phu hop.", rong, gd.mau.MO);
                }
                f.button(x + rong - 14, nutY, 14, L"Ket thuc", false);
                if (nhieuTrang)
                {
                    int soTrang = (soKhop + soDong - 1) / soDong;
                    f.button(x, nutY + 1, 10, L"Truoc", false);
                    f.text(x + 11, nutY + 1, L"Trang " + ChuoiSoRong(dauTrang / soDong + 1) +
                           L"/" + ChuoiSoRong(soTrang), rong - 22, gd.mau.MO);
                    f.button(x + rong - 10, nutY + 1, 10, L"Sau", false);
                }
            }
        }
        f.show(conTro, 11);
        Phim p = DocPhimConsole(gd);
        if (p.ma == VK_ESCAPE) return false;
        if (f.small()) continue;
        if (!choMuon)
        {
            if (p.ma == VK_RETURN ||
                (p.click && p.y == 12 && p.x >= x && p.x < x + 16)) return false;
            continue;
        }
        bool truoc = p.ma == VK_PRIOR, sau = p.ma == VK_NEXT;
        // Enter tren o trong sau lan muon truoc chi giu nguyen man hinh.
        bool tiep = p.ma == VK_RETURN && (daChonDong || !TenDeTim(nhap).empty());
        if (p.click && p.x >= x && p.x < x + rong)
        {
            if (p.y >= 15 && p.y < 15 + soDong && dauTrang + p.y - 15 < soKhop)
            {
                chon = dauTrang + p.y - 15;
                daChonDong = true;
            }
            if (p.y == nutY)
            {
                if (p.x >= x + rong - 14) return false;
                tiep = p.x < x + 20;
            }
            if (nhieuTrang && p.y == nutY + 1)
            {
                truoc = p.x < x + 10;
                sau = p.x >= x + rong - 10;
            }
        }
        if (tiep && soKhop)
        {
            maCuon = cuon[chon]->maSach;
            return true;
        }
        if (soKhop && (p.ma == VK_UP || p.ma == VK_DOWN || truoc || sau)) daChonDong = true;
        if (p.ma == VK_UP && chon > 0) --chon;
        if (p.ma == VK_DOWN && chon + 1 < soKhop) ++chon;
        if (truoc) chon = chon >= soDong ? chon - soDong : 0;
        if (sau && soKhop) chon = chon + soDong < soKhop ? chon + soDong : soKhop - 1;
        if (p.ma == VK_BACK && !nhap.empty())
        {
            nhap.pop_back();
            canLoc = true;
        }
        else if (!p.ctrl && p.chu >= L' ' && nhap.size() < 256)
        {
            nhap += p.chu;
            canLoc = true;
        }
    }
}
// [DEMO - CODEX] Loc cac luot dang muon cua dung doc gia.
int LocCuonDangGiu(const ThuVien &tv, const DocGia &docGia, const wstring &nhap,
                   const MuonTra **ketQua)
{
    string tuKhoa = TuUTF16(TenDeTim(nhap));
    int soLuong = 0;
    for (const MuonTra *p = docGia.dsMuonTra; p != nullptr; p = p->next)
    {
        if (p->trangThai != MUON_DANG_MUON) continue;
        const DauSach *dau = nullptr;
        TimCuonSachToanCuc(tv, p->maSach, &dau);
        bool khop = tuKhoa.empty() || ChuaChuoi(p->maSach, tuKhoa);
        if (!khop && dau != nullptr)
        {
            khop = ChuaChuoi(TuUTF16(TenDeTim(SangUTF16(dau->tenSach))), tuKhoa);
        }
        if (khop) ketQua[soLuong++] = p;
    }
    return soLuong;
}

int ChonLuotTraTrenManHinh(GiaoDien &gd, const ThuVien &tv, const DocGia &docGia,
                           const string &thongBao, const MuonTra **ketQua, string &maCuon)
{
    wstring nhap;
    int soDangGiu = 0, soKhop = 0, chon = 0;
    int nut = 0; // 0: o nhap, 1: tra, 2: bao mat, 3: ket thuc.
    for (const MuonTra *p = docGia.dsMuonTra; p != nullptr; p = p->next)
    {
        if (p->trangThai == MUON_DANG_MUON) ++soDangGiu;
    }
    bool canLoc = true, daChonDong = false;
    while (true)
    {
        if (canLoc)
        {
            soKhop = LocCuonDangGiu(tv, docGia, nhap, ketQua);
            chon = 0;
            daChonDong = false;
            canLoc = false;
        }
        KhungUI f(gd);
        NenUngDung(gd, f, L"TRA SACH / BAO MAT", L"");
        int x = XNoiDung(), rong = f.w - x - 3;
        int soDong = f.h - 17;
        if (soDong < 1) soDong = 1;
        int dauTrang = chon / soDong * soDong;
        int nutY = f.h - 6;
        bool nhieuTrang = soKhop > soDong;
        int conTro = -1;
        if (!f.small())
        {
            f.text(x, 3, L"The " + ChuoiSoRong(docGia.maThe) + L" | " +
                   SangUTF16(docGia.ho + " " + docGia.ten), rong, gd.mau.NHAN);
            f.text(x, 4, SangUTF16(thongBao), rong, gd.mau.NHAN);
            f.text(x, 5, L"Dang giu " + ChuoiSoRong(soDangGiu) + L" cuon", rong, gd.mau.MO);
            if (soDangGiu == 0)
            {
                f.text(x, 7, L"Doc gia khong con sach dang muon.", rong, gd.mau.NHAN);
                f.button(x, 9, 16, L"Ket thuc", true);
                f.text(x, 11, L"Bam Ket thuc, Enter hoac Esc de ve menu.", rong, gd.mau.MO);
            }
            else
            {
                f.text(x, 6, L"Nhap ma cuon can tra (hoac ten sach)", rong, gd.mau.NHAN);
                f.fill(x, 7, rong, 1, gd.mau.CHON);
                wstring hien = GhepDauHienThi(nhap);
                int boQua = static_cast<int>(hien.size()) - rong + 3;
                if (boQua > 0) hien = CatChuoi(hien, boQua, hien.size() - boQua);
                f.text(x + 1, 7, hien, rong - 2, gd.mau.CHON);
                if (nut == 0) conTro = x + 1 + static_cast<int>(hien.size());
                f.text(x, 8, L"Len/Xuong: dong | Tab: nut | Enter: chon | Esc: ra", rong, gd.mau.MO);
                f.text(x, 9, L"Ma cuon", 16, gd.mau.MO);
                f.text(x + 17, 9, L"Ten sach", rong - 29, gd.mau.MO);
                f.text(x + rong - 10, 9, L"Ngay muon", 10, gd.mau.MO);
                for (int i = dauTrang; i < soKhop && i < dauTrang + soDong; ++i)
                {
                    const MuonTra *p = ketQua[i];
                    const DauSach *dau = nullptr;
                    TimCuonSachToanCuc(tv, p->maSach, &dau);
                    string ten = dau == nullptr ? "[Lien ket loi]" : dau->tenSach;
                    int y = 10 + i - dauTrang;
                    WORD mau = i == chon ? gd.mau.CHON : gd.mau.NEN;
                    f.fill(x, y, rong, 1, mau);
                    f.text(x, y, SangUTF16(p->maSach), 16, mau);
                    f.text(x + 17, y, SangUTF16(ten), rong - 29, mau);
                    f.text(x + rong - 10, y, SangUTF16(ChuoiNgay(p->ngayMuon)), 10, mau);
                }
                if (soKhop)
                {
                    f.text(x, nutY - 1, L"Da chon: " + SangUTF16(ketQua[chon]->maSach), rong, gd.mau.NHAN);
                    f.button(x, nutY, 20, L"Tra cuon nay", nut == 1);
                    f.button(x + 21, nutY, 12, L"Bao mat", nut == 2);
                }
                else
                {
                    f.text(x, 10, L"Khong co cuon dang giu phu hop.", rong, gd.mau.MO);
                }
                f.button(x + rong - 14, nutY, 14, L"Ket thuc", nut == 3);
                f.text(x, nutY + 1, L"Bao mat se khoa the va thanh ly cuon.", rong, gd.mau.MO);
                if (nhieuTrang)
                {
                    f.button(x, nutY + 2, 10, L"Truoc", false);
                    f.text(x + 11, nutY + 2, L"Trang " + ChuoiSoRong(dauTrang / soDong + 1) +
                           L"/" + ChuoiSoRong((soKhop + soDong - 1) / soDong), rong - 22, gd.mau.MO);
                    f.button(x + rong - 10, nutY + 2, 10, L"Sau", false);
                }
            }
        }
        f.show(conTro, 7);
        Phim p = DocPhimConsole(gd);
        if (p.ma == VK_ESCAPE) return 0;
        if (f.small()) continue;
        if (soDangGiu == 0)
        {
            if (p.ma == VK_RETURN || (p.click && p.y == 9 && p.x >= x && p.x < x + 16)) return 0;
            continue;
        }
        if (p.ma == VK_TAB)
        {
            nut = (nut + (p.shift ? 3 : 1)) % 4;
            continue;
        }
        int thaoTac = 0;
        if (p.ma == VK_RETURN)
        {
            if (nut == 3) return 0;
            if (nut == 1 || nut == 2) thaoTac = nut;
            else if (daChonDong || !TenDeTim(nhap).empty()) thaoTac = 1;
        }
        bool truoc = p.ma == VK_PRIOR, sau = p.ma == VK_NEXT;
        if (p.click && p.x >= x && p.x < x + rong)
        {
            if (p.y >= 10 && p.y < 10 + soDong && dauTrang + p.y - 10 < soKhop)
            {
                chon = dauTrang + p.y - 10;
                daChonDong = true;
                nut = 0;
            }
            if (p.y == 7) nut = 0;
            if (p.y == nutY)
            {
                if (p.x >= x + rong - 14) return 0;
                if (p.x < x + 20) thaoTac = 1;
                else if (p.x >= x + 21 && p.x < x + 33) thaoTac = 2;
            }
            if (nhieuTrang && p.y == nutY + 2)
            {
                truoc = p.x < x + 10;
                sau = p.x >= x + rong - 10;
            }
        }
        if (thaoTac && soKhop)
        {
            maCuon = ketQua[chon]->maSach;
            if (thaoTac == 2)
            {
                const char *xacNhan[] = {"Xac nhan bao mat (khoa the)", "Quay lai danh sach"};
                if (ChonMenu(gd, "BAO MAT CUON " + maCuon, xacNhan, 2) != 1) continue;
            }
            return thaoTac;
        }
        if (soKhop && (p.ma == VK_UP || p.ma == VK_DOWN || truoc || sau))
        {
            daChonDong = true;
            nut = 0;
        }
        if (p.ma == VK_UP && chon > 0) --chon;
        if (p.ma == VK_DOWN && chon + 1 < soKhop) ++chon;
        if (truoc) chon = chon >= soDong ? chon - soDong : 0;
        if (sau && soKhop) chon = chon + soDong < soKhop ? chon + soDong : soKhop - 1;
        if (p.ma == VK_BACK && !nhap.empty())
        {
            nhap.pop_back();
            canLoc = true;
            nut = 0;
        }
        else if (!p.ctrl && p.chu >= L' ' && nhap.size() < 256)
        {
            nhap += p.chu;
            canLoc = true;
            nut = 0;
        }
    }
}
int ChonTheDangVanBan(GiaoDien &gd, const NutDocGia *const *danhSach, int soDocGia,
                      const NutDocGia **ketQua)
{
    string nhap;
    while (NhapDong(gd, "Ma the hoac ho ten", nhap))
    {
        int soKhop = LocTheDocGia(danhSach, soDocGia, SangUTF16(nhap), ketQua);
        if (soKhop == 0)
        {
            cout << "Khong co doc gia phu hop.\n";
            continue;
        }
        int ma = 0;
        if (soKhop == 1 && DocSoNguyen(ChuanHoaChuoiSach(nhap), ma, 1, INT_MAX) &&
            ketQua[0]->thongTin.maThe == ma) return ma;
        for (int i = 0; i < soKhop; ++i)
        {
            const DocGia &d = ketQua[i]->thongTin;
            cout << d.maThe << " | " << d.ho << " " << d.ten << '\n';
        }
        if (!NhapSo(gd, "Chon ma the trong ket qua", ma, 1, INT_MAX)) return 0;
        for (int i = 0; i < soKhop; ++i)
            if (ketQua[i]->thongTin.maThe == ma) return ma;
        cout << "Ma the nam ngoai ket qua. Hay tim lai.\n";
    }
    return 0;
}
} // namespace
int ChonMaTheDocGia(GiaoDien &gd, const CayDocGia &cay, const string &tieuDe)
{
    int soDocGia = DemDocGia(cay);
    if (soDocGia == 0)
    {
        ThongBao(gd, "Chua co doc gia.");
        return 0;
    }
    const NutDocGia **danhSach = new const NutDocGia *[soDocGia];
    const NutDocGia **ketQua = nullptr;
    int ma = 0;
    try
    {
        LayDanhSachDocGia(cay, danhSach, soDocGia);
        ketQua = new const NutDocGia *[soDocGia];
        if (gd.giaoDienPhim) ma = ChonTheTrenManHinh(gd, danhSach, soDocGia, ketQua, tieuDe);
        else ma = ChonTheDangVanBan(gd, danhSach, soDocGia, ketQua);
    }
    catch (...)
    {
        delete[] ketQua;
        delete[] danhSach;
        throw;
    }
    delete[] ketQua;
    delete[] danhSach;
    return ma;
}
bool ChonCuonDeMuon(GiaoDien &gd, const ThuVien &tv, int maThe,
                    const string &thongBao, bool choMuon,
                    const string &lyDoDung, string &maCuon)
{
    const NutDocGia *docGia = TimDocGia(tv.cayDocGia, maThe);
    if (docGia == nullptr) return false;
    int sucChua = 0;
    for (int i = 0; i < tv.dsDauSach.soLuong; ++i)
    {
        sucChua += DemCuonSach(tv.dsDauSach.ds[i]->dms);
    }
    const CuonSach **cuon = new const CuonSach *[sucChua];
    const DauSach **dau = nullptr;
    bool daChon = false;
    try
    {
        dau = new const DauSach *[sucChua];
        daChon = ChonCuonTrenManHinh(gd, tv, docGia->thongTin, cuon, dau,
                                    thongBao, choMuon, lyDoDung, maCuon);
    }
    catch (...)
    {
        delete[] dau;
        delete[] cuon;
        throw;
    }
    delete[] dau;
    delete[] cuon;
    return daChon;
}
int ChonCuonDeTra(GiaoDien &gd, const ThuVien &tv, int maThe,
                  const string &thongBao, string &maCuon)
{
    const NutDocGia *docGia = TimDocGia(tv.cayDocGia, maThe);
    if (docGia == nullptr) return 0;
    int sucChua = DemLichSu(docGia->thongTin.dsMuonTra);
    const MuonTra **ketQua = new const MuonTra *[sucChua];
    int thaoTac = 0;
    try
    {
        thaoTac = ChonLuotTraTrenManHinh(gd, tv, docGia->thongTin, thongBao, ketQua, maCuon);
    }
    catch (...)
    {
        delete[] ketQua;
        throw;
    }
    delete[] ketQua;
    return thaoTac;
}
bool DangDungGiaoDienHeThong(GiaoDien &gd)
{
    return gd.giaoDienPhim;
}
bool NhapBieuMau(GiaoDien &gd, const string &title, const char *const *labels, string *values, int count)
{
    if (gd.giaoDienPhim)
    {
        return BieuMau(gd, title, labels, values, count, "", false);
    }
    (void)title;
    for (int i = 0; i < count; ++i)
    {
        if (!NhapDong(gd, labels[i], values[i]))
        {
            return false;
        }
    }
    return true;
}
bool NhapBieuMauLienTiep(GiaoDien &gd, const string &title, const char *const *labels,
                        string *values, int count, const string &thongBao)
{
    if (gd.giaoDienPhim)
    {
        return BieuMau(gd, title, labels, values, count, thongBao, true);
    }
    return NhapBieuMau(gd, title, labels, values, count);
}
bool NhapDong(GiaoDien &gd, const string &prompt, string &s)
{
    if (gd.giaoDienPhim)
    {
        const char *labels[] = {prompt.c_str()};
        string value;
        bool ok = BieuMau(gd, gd.tieuDeUI, labels, &value, 1, "", false);
        if (ok)
        {
            s = value;
        }
        return ok && s != "/huy";
    }
    cout << prompt << " (/huy de quay lai): " << flush;
    if (!getline(cin, s))
    {
        return false;
    }
    if (!s.empty() && s.back() == '\r')
    {
        s.pop_back();
    }
    return s != "/huy" && s != string(1, '\x1b');
}
bool NhapSo(GiaoDien &gd, const string &prompt, int &n, int lo, int hi)
{
    string s;
    while (NhapDong(gd, prompt, s))
    {
        if (DocSoNguyen(ChuanHoaChuoiSach(s), n, lo, hi))
        {
            return true;
        }
        if (gd.giaoDienPhim)
        {
            ThongBao(gd, "LOI: nhap so nguyen trong [" + ChuoiSo(lo) + ", " + ChuoiSo(hi) + "].");
        }
        else
        {
            cout << "LOI: nhap so nguyen trong [" << lo << ", " << hi << "].\n";
        }
    }
    return false;
}
int ChonMenu(GiaoDien &gd, const string &title, const char *const *labels, int count)
{
    if (gd.giaoDienPhim)
    {
        if (count == 13)
        {
            int r = TrangChinh(gd);
            gd.tieuDeUI = TuUTF16(gd.dieuHuong[gd.mucUI]);
            return r;
        }
        int selected = 0;
        gd.tieuDeUI = title;
        while (true)
        {
            KhungUI f(gd);
            NenUngDung(gd, f, NhanHienThi(title),
                       L"↑/↓: chọn thao tác   Enter / nhấp chuột: mở   Esc/0: quay lại");
            int x = XNoiDung(), width = f.w - x - 3;
            if (!f.small())
            {
                f.text(x, 5, L"Bạn muốn thực hiện thao tác nào?", width, gd.mau.NHAN);
                for (int i = 0; i < count; ++i)
                {
                    f.button(x, 8 + i * 3, width, NhanHienThi(labels[i]), i == selected);
                    f.text(x + 2, 9 + i * 3, L"Enter để mở", width - 4, gd.mau.MO);
                }
            }
            f.show(-1, -1);
            Phim p = DocPhimConsole(gd);
            if (p.ma == VK_ESCAPE || p.chu == L'0')
            {
                return 0;
            }
            if (f.small())
            {
                continue;
            }
            if (p.ma == VK_UP)
            {
                selected = (selected + count - 1) % count;
            }
            if (p.ma == VK_DOWN)
            {
                selected = (selected + 1) % count;
            }
            if (p.ma == VK_RETURN)
            {
                gd.tieuDeUI = labels[selected];
                return selected + 1;
            }
            if (p.chu >= L'1' && p.chu <= L'9' && p.chu - L'1' < count)
            {
                int r = static_cast<int>(p.chu - L'0');
                gd.tieuDeUI = labels[r - 1];
                return r;
            }
            if (p.click && p.x >= x && p.x < x + width && p.y >= 8 && (p.y - 8) % 3 == 0 &&
                (p.y - 8) / 3 < count)
            {
                selected = (p.y - 8) / 3;
                gd.tieuDeUI = labels[selected];
                return selected + 1;
            }
        }
    }
    cout << '\n' << title << '\n';
    for (int i = 0; i < count; ++i)
    {
        cout << i + 1 << ". " << labels[i] << '\n';
    }
    cout << "0. Quay lai / luu va thoat\n";
    int choice = 0;
    return NhapSo(gd, "Chon", choice, 0, count) ? choice : 0;
}
void ThongBao(GiaoDien &gd, const string &s)
{
    if (gd.giaoDienPhim)
    {
        XemChiTiet(gd, SangUTF16(s), L"Thông báo");
        return;
    }
    cout << s << '\n' << flush;
}
void HienThiPhanTrangVoiMangTam(GiaoDien &gd, const string &text, size_t *&starts)
{
    if (!gd.giaoDienPhim)
    {
        cout << text << flush;
        return;
    }
    wstring all = SangUTF16(text);
    size_t total = 1;
    for (wchar_t c : all)
    {
        if (c == L'\n')
        {
            ++total;
        }
    }
    starts = new size_t[total + 1];
    size_t n = 1;
    starts[0] = 0;
    for (size_t i = 0; i < all.size(); ++i)
    {
        if (all[i] == L'\n' && i + 1 < all.size())
        {
            starts[n++] = i + 1;
        }
    }
    starts[n] = all.size();
    size_t selected = 0, page = 0;
    while (true)
    {
        KhungUI f(gd);
        NenUngDung(gd, f, SangUTF16(gd.tieuDeUI),
                   L"↑/↓: chọn dòng   PgUp/PgDn: đổi trang   Enter: xem đầy đủ   Esc: quay lại");
        int x = XNoiDung(), width = f.w - x - 3, rows = f.h - 11;
        if (rows < 1)
        {
            rows = 1;
        }
        size_t step = static_cast<size_t>(rows);
        page = selected / step;
        if (!f.small())
        {
            f.text(x, 4, L"KẾT QUẢ   ·   " + ChuoiSoRong(n) + L" dòng", width, gd.mau.NHAN);
            f.box(x, 6, width, rows + 2, L"", gd.mau.VIEN);
            for (int i = 0; i < rows; ++i)
            {
                size_t index = page * step + static_cast<size_t>(i);
                if (index >= n)
                {
                    break;
                }
                WORD color = index == selected ? gd.mau.CHON : (index % 2 ? gd.mau.THANH : gd.mau.NEN);
                f.fill(x + 1, 7 + i, width - 2, 1, color);
                wstring line = CatChuoi(all, starts[index], starts[index + 1] - starts[index]);
                while (!line.empty() && (line.back() == L'\n' || line.back() == L'\r'))
                {
                    line.pop_back();
                }
                DongBang(gd, f, x + 2, 7 + i, width - 4, line, color);
            }
            f.button(x, f.h - 3, 12, L"‹ Trước", false);
            f.text(x + 14, f.h - 3,
                   L"Trang " + ChuoiSoRong(page + 1) + L" / " + ChuoiSoRong((n + step - 1) / step),
                   width - 29, gd.mau.MO);
            f.button(x + width - 13, f.h - 3, 13, L"Sau ›", false);
        }
        f.show(-1, -1);
        Phim p = DocPhimConsole(gd);
        if (p.ma == VK_ESCAPE)
        {
            return;
        }
        if (f.small())
        {
            continue;
        }
        if (p.ma == VK_UP && selected)
        {
            --selected;
        }
        if (p.ma == VK_DOWN && selected + 1 < n)
        {
            ++selected;
        }
        if (p.ma == VK_HOME)
        {
            selected = 0;
        }
        if (p.ma == VK_END)
        {
            selected = n - 1;
        }
        bool next = p.ma == VK_NEXT, prev = p.ma == VK_PRIOR;
        if (p.click)
        {
            if (p.y == f.h - 3)
            {
                prev = p.x >= x && p.x < x + 12;
                next = p.x >= x + width - 13 && p.x < x + width;
            }
            if (p.x >= x && p.x < x + width && p.y >= 7 && p.y < 7 + rows)
            {
                size_t i = page * step + static_cast<size_t>(p.y - 7);
                if (i < n)
                {
                    selected = i;
                }
            }
        }
        if (next)
        {
            selected = selected + step < n ? selected + step : n - 1;
        }
        if (prev)
        {
            selected = selected >= step ? selected - step : 0;
        }
        if (p.ma == VK_RETURN)
        {
            XemChiTiet(gd, CatChuoi(all, starts[selected], starts[selected + 1] - starts[selected]),
                       L"Chi tiết dòng " + ChuoiSoRong(selected + 1));
        }
    }
}
void HienThiPhanTrang(GiaoDien &gd, const string &text)
{
    size_t *starts = nullptr;
    try
    {
        HienThiPhanTrangVoiMangTam(gd, text, starts);
        delete[] starts;
    }
    catch (...)
    {
        delete[] starts;
        throw;
    }
}

void LuuSauThayDoi(GiaoDien &gd, const ThuVien &tv)
{
    gd.chuaLuu = true;
    string loi;
    if (!LuuFile(tv, gd.duongDan, loi))
    {
        throw LoiThuVien("Da cap nhat RAM nhung CHUA LUU: " + loi +
                         ". Hay bam Luu (F5); khong dong cua so.");
    }
    gd.chuaLuu = false;
}

namespace
{
struct ConsoleScope
{
    UINT oldIn = GetConsoleCP(), oldOut = GetConsoleOutputCP();
    DWORD oldMode = 0;
    CONSOLE_CURSOR_INFO oldCursor{};
    bool hadMode = GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &oldMode) != 0;
    bool hadCursor = GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &oldCursor) != 0;
    ConsoleScope()
    {
        SetConsoleCP(CP_UTF8);
        SetConsoleOutputCP(CP_UTF8);
    }
    ~ConsoleScope()
    {
        if (hadMode)
        {
            SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), oldMode);
        }
        if (hadCursor)
        {
            SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &oldCursor);
        }
        SetConsoleCP(oldIn);
        SetConsoleOutputCP(oldOut);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
};
void HuongDan()
{
    cout << "ThuVien.exe [--data duong-dan] [--date dd/mm/yyyy] [--plain]\n"
         << "ThuVien.exe --check duong-dan\n"
         << "--date dung ngay mo phong qua khu cho demo, khong cho ngay tuong lai.\n"
         << "TUI: Tab/Enter chuyen o, Ctrl+Enter xac nhan, Esc huy. /huy huy khi xac nhan form.\n"
         << "--plain: /huy huy nhap. 0 luu va thoat. Tu luu sau thao tac thanh cong; EOF khong thu "
            "luu lai neu truoc do luu loi.\n";
}
int ChayUngDung(GiaoDien &gd, ThuVien &tv, int argc, char **argv)
{
    string &path = gd.duongDan;
    string check;
    NgayThang &ngay = gd.ngay;
    bool plain = false;
    bool dungDuLieuMacDinh = true;
    for (int i = 1; i < argc; ++i)
    {
        string arg = argv[i];
        if (arg == "--help")
        {
            HuongDan();
            return 0;
        }
        if (arg == "--plain")
        {
            plain = true;
            continue;
        }
        if ((arg == "--data" || arg == "--date" || arg == "--check") && i + 1 < argc)
        {
            string val = argv[++i];
            if ((arg == "--data" || arg == "--check") && val.empty())
            {
                cerr << "Duong dan " << arg << " khong duoc rong.\n";
                return 2;
            }
            if (arg == "--data")
            {
                path = val;
                dungDuLieuMacDinh = false;
            }
            else if (arg == "--check")
            {
                check = val;
            }
            else if (!DocNgay(val, ngay) || !NgayHopLe(ngay) || KhoangCachNgay(ngay, HomNay()) < 0)
            {
                cerr << "Ngay mo phong khong hop le / tuong lai.\n";
                return 2;
            }
        }
        else
        {
            HuongDan();
            return 2;
        }
    }
    DWORD inputMode = 0, outputMode = 0;
    gd.giaoDienPhim = !plain && GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &inputMode) &&
                   GetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), &outputMode);
    string loi;
    if (gd.giaoDienPhim)
    {
        DWORD mode = 0;
        GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &mode);
        SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE),
                       (mode | ENABLE_EXTENDED_FLAGS | ENABLE_MOUSE_INPUT | ENABLE_WINDOW_INPUT) &
                           ~(ENABLE_QUICK_EDIT_MODE | ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT));
    }
    if (!check.empty())
    {
        if (!DocFile(tv, check, loi))
        {
            cerr << "KHONG HOP LE: " << loi << '\n';
            return 2;
        }
        int copies = 0;
        for (int i = 0; i < tv.dsDauSach.soLuong; ++i)
        {
            copies += DemCuonSach(tv.dsDauSach.ds[i]->dms);
        }
        cout << "HOP LE | dau sach=" << tv.dsDauSach.soLuong << " | cuon=" << copies
             << " | doc gia=" << DemDocGia(tv.cayDocGia) << " | moc ma=" << tv.maTheLonNhatDaCap
             << '\n';
        return 0;
    }
    path = DuongDanUTF8(DuongDanDayDu(path));
    TaoThuMuc(ThuMucCha(DuongDanUTF16(path)));
    KhoaTepPhien khoa;
    if (!khoa.Mo(path, loi))
    {
        cerr << loi << '\n';
        return 2;
    }
    if (FileTonTai(path))
    {
        if (!DocFile(tv, path, loi))
        {
            cerr << "Khong nap/khong ghi de file loi: " << loi << '\n';
            return 2;
        }
    }
    else if (dungDuLieuMacDinh && FileTonTai("demo/DuLieu/DuLieuMau.txt"))
    {
        if (!DocFile(tv, "demo/DuLieu/DuLieuMau.txt", loi))
        {
            cerr << "Khong doc duoc du lieu mau: " << loi << '\n';
            return 2;
        }
    }
    else
    {
        TaoThuMuc(ThuMucCha(DuongDanDayDu(path)));
        cout << "Tao phien rong; file se duoc tao khi luu.\n";
    }
    cout << "THU gd.mau.VIEN - BAN DEMO CUA NHOM\nNgay giao dich: "
         << ChuoiNgay(ngay) << "\nDu lieu: " << path << '\n';
    PhienGiaoDien phienGiaoDien(gd, gd.giaoDienPhim, true);
    while (true)
    {
        int choice = ChonChucNang(gd, ngay, path);
        if (!cin)
        {
            cerr << "EOF: thoat; thao tac da tu luu van con. Neu da bao loi luu, RAM chua ghi se "
                    "mat.\n";
            return 0;
        }
        try
        {
            if (gd.chuaLuu &&
                (choice == 1 || choice == 3 || choice == 6 || choice == 7 || choice == 11))
            {
                ThongBao(gd,
                    "CHUA LUU: hay bam Luu (F5) thanh cong truoc khi sua tiep hoac nap file khac.");
                continue;
            }
            if (choice == 0 || choice == 12)
            {
                if (LuuFile(tv, path, loi))
                {
                    gd.chuaLuu = false;
                    ThongBao(gd, "OK: da luu " + path);
                    if (choice == 0)
                    {
                        return 0;
                    }
                }
                else
                {
                    ThongBao(gd, "LOI LUU (van giu du lieu trong RAM): " + loi);
                }
            }
            else if (choice >= 1 && choice <= 10)
            {
                ChayChucNang(gd, choice, tv, ngay);
            }
            else if (choice == 11)
            {
                string next, confirm;
                if (NhapDong(gd, "Duong dan file UTF-8", next) &&
                    NhapDong(gd, "Nhap NAP de thay du lieu RAM (hay luu truoc neu can)", confirm) &&
                    confirm == "NAP")
                {
                    if (NapPhien(gd, tv, path, next, khoa, loi))
                    {
                        ThongBao(gd, "OK: da nap du lieu.");
                    }
                    else
                    {
                        ThongBao(gd, "LOI: " + loi + "; du lieu RAM cu duoc giu nguyen.");
                    }
                }
            }
            else if (choice == 13)
            {
                string confirm;
                if (NhapDong(gd, "Nhap THOAT de thoat; du lieu da tu luu van giu, RAM chua luu (neu co "
                             "loi) se mat",
                             confirm) &&
                    confirm == "THOAT")
                {
                    return 0;
                }
            }
        }
        catch (const LoiThuVien &e)
        {
            ThongBao(gd, string("Khong hoan tat thao tac: ") + e.what());
        }
        catch (...)
        {
            ThongBao(gd, "Khong hoan tat thao tac: khong du bo nho / loi luong.");
        }
    }
}
} // namespace
int KhoiDongUngDung(GiaoDien &gd, ThuVien &tv)
{
    ConsoleScope console;
    string *utf8 = nullptr;
    char **ptrs = nullptr;
    try
    {
        // argv hep cua CRT co the la ANSI. Doc lenh UTF-16 de duong dan co dau dung.
        const wstring command = GetCommandLineW();
        utf8 = new string[command.size() + 1];
        int n = DocDoiSoWindows(command, utf8);
        ptrs = new char *[n];
        for (int i = 0; i < n; ++i)
        {
            ptrs[i] = &utf8[i][0];
        }
        int ketQua = ChayUngDung(gd, tv, n, ptrs);
        delete[] ptrs;
        delete[] utf8;
        return ketQua;
    }
    catch (const LoiThuVien &e)
    {
        delete[] ptrs;
        delete[] utf8;
        cerr << "LOI: " << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        delete[] ptrs;
        delete[] utf8;
        cerr << "LOI: khong du bo nho / loi luong.\n";
        return 1;
    }
}
