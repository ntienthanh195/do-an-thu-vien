#include "00_KhaiBaoChung.h"

namespace
{
bool giaoDienPhim = false;
const ThuVien *thuVienTuLuu = nullptr;
const string *tepTuLuu = nullptr;
bool chuaLuu = false;
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
            CloseHandle(handle);
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
struct PhienTuLuu
{
    PhienTuLuu(const ThuVien &tv, const string &path)
    {
        thuVienTuLuu = &tv;
        tepTuLuu = &path;
        chuaLuu = false;
    }
    ~PhienTuLuu()
    {
        thuVienTuLuu = nullptr;
        tepTuLuu = nullptr;
        chuaLuu = false;
    }
};
inline bool NapPhien(ThuVien &tv, string &path, const string &next, KhoaTepPhien &khoa, string &loi)
{
    string moi =
        DuongDanUTF8(DuongDanDayDu(next)); // Moi cap phat/path/lock phai xong truoc DocFile.
    const bool cung = khoa.CungTep(moi);
    KhoaTepPhien khoaMoi;
    if (!cung && !khoaMoi.Mo(moi, loi))
        return false;
    if (!DocFile(tv, moi, loi))
        return false;
    path.swap(moi); // C++11 string cung allocator: swap khong cap phat.
    if (!cung)
        khoa.HoanDoi(khoaMoi);
    chuaLuu = false;
    return true;
}

#ifdef _WIN32
// Chi trang thai trinh bay: khong so huu hay thay bon cau truc nghiep vu.
const ThuVien *duLieuUI = nullptr;
const string *duongDanUI = nullptr;
NgayThang ngayUI;
int mucUI = 0;
string tieuDeUI = "Tong quan";
const WORD NEN = 0x0E, MO = 0x07, NHAN = 0x0A, THANH = 0x1E, CHON = 0x3E, O_NHAP = 0x5E;
const WORD VIEN = 0x02, NUT_CHINH = 0x60, O_DANG_NHAP = 0x4E;
// Bang mau chi thuoc phien ung dung, khong sua profile Windows Terminal.
const COLORREF bangMauUI[] = {
    RGB(17, 21, 28),    RGB(25, 31, 40),    RGB(52, 64, 80),    RGB(37, 63, 59),
    RGB(33, 48, 44),    RGB(29, 37, 48),    RGB(139, 207, 176), RGB(168, 178, 192),
    RGB(104, 119, 139), RGB(232, 196, 135), RGB(128, 201, 169), RGB(196, 205, 217),
    RGB(229, 155, 149), RGB(176, 164, 201), RGB(225, 231, 239), RGB(242, 245, 249)};
bool xuatRGB = false;
const wchar_t *dieuHuong[] = {L"Tổng quan",       L"Quản lý độc giả", L"Danh sách độc giả",
                              L"Kho sách",        L"Theo thể loại",   L"Tìm kiếm sách",
                              L"Mượn sách",       L"Trả / báo mất",   L"Sách đang mượn",
                              L"Độc giả quá hạn", L"Top 10 đầu sách", L"Mở dữ liệu",
                              L"Lưu dữ liệu",     L"Thoát phiên"};
const wchar_t *moTa[] = {L"Theo dõi thư viện và mở nhanh các nghiệp vụ.",
                         L"Thêm, hiệu chỉnh, khóa hoặc xóa thẻ độc giả.",
                         L"Xem theo mã thẻ hoặc theo tên và họ.",
                         L"Quản lý đầu sách và từng bản sách vật lý.",
                         L"Duyệt đầu sách được nhóm theo thể loại.",
                         L"Tìm theo tên và xem trạng thái từng cuốn.",
                         L"Kiểm tra thẻ, hạn mức và tình trạng cuốn sách.",
                         L"Nhận trả sách hoặc ghi nhận một cuốn bị mất.",
                         L"Tra các cuốn độc giả hiện đang giữ.",
                         L"Xem độc giả đang giữ sách vượt hạn 7 ngày.",
                         L"Thống kê số lượt mượn theo từng đầu sách.",
                         L"Mở file khác sau khi xác nhận thay dữ liệu.",
                         L"Ghi dữ liệu hiện hành vào file của phiên này.",
                         L"Thoát; dữ liệu đã tự lưu vẫn được giữ. Lỗi lưu cần xử lý trước."};
string TuUTF16(const wstring &s)
{
    if (s.empty())
        return "";
    int n = WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, s.data(), static_cast<int>(s.size()),
                                nullptr, 0, nullptr, nullptr);
    if (!n)
        throw LoiThuVien("Ky tu UTF-16 khong hop le");
    string r(static_cast<size_t>(n), '\0');
    WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, s.data(), static_cast<int>(s.size()), &r[0],
                        n, nullptr, nullptr);
    return r;
}
wstring SangUTF16(const string &s)
{
    if (s.empty())
        return L"";
    int n = MultiByteToWideChar(CP_UTF8, 0, s.data(), static_cast<int>(s.size()), nullptr, 0);
    wstring r(static_cast<size_t>(n), L' ');
    if (n)
        MultiByteToWideChar(CP_UTF8, 0, s.data(), static_cast<int>(s.size()), &r[0], n);
    return r;
}
wstring GhepDauHienThi(const wstring &s)
{
    if (s.empty())
        return s;
    int n = FoldStringW(MAP_PRECOMPOSED, s.data(), static_cast<int>(s.size()), nullptr, 0);
    if (!n)
        return s;
    wstring result(static_cast<size_t>(n), L' ');
    if (!FoldStringW(MAP_PRECOMPOSED, s.data(), static_cast<int>(s.size()), &result[0], n))
        return s;
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
        if (s == raw[i])
            return pretty[i];
    if (s == u8"Phai (Nam/Nữ)")
        return L"Giới tính (Nam / Nữ)";
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
            throw LoiThuVien("Khong ve duoc console");
        offset += written;
    }
}
wstring LenhMau(WORD attr)
{
    COLORREF fg = bangMauUI[attr & 15], bg = bangMauUI[(attr >> 4) & 15];
    return L"\x1b[38;2;" + to_wstring(GetRValue(fg)) + L";" + to_wstring(GetGValue(fg)) + L";" +
           to_wstring(GetBValue(fg)) + L"m\x1b[48;2;" + to_wstring(GetRValue(bg)) + L";" +
           to_wstring(GetGValue(bg)) + L";" + to_wstring(GetBValue(bg)) + L"m";
}
struct PhienGiaoDien
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD oldMode = 0;
    bool active = false, hadMode = false, hadPalette = false, fontChanged = false;
    CONSOLE_SCREEN_BUFFER_INFOEX oldPalette{};
    CONSOLE_FONT_INFOEX oldFont{};
    explicit PhienGiaoDien(bool enabled, bool adjustFont = true)
    {
        if (!enabled)
            return;
        active = true;
        oldPalette.cbSize = sizeof(oldPalette);
        oldFont.cbSize = sizeof(oldFont);
        hadPalette = GetConsoleScreenBufferInfoEx(out, &oldPalette) != 0;
        if (hadPalette)
        {
            auto theme = oldPalette;
            for (int i = 0; i < 16; ++i)
                theme.ColorTable[i] = bangMauUI[i];
            SetConsoleScreenBufferInfoEx(out, &theme);
            SetConsoleWindowInfo(out, TRUE, &oldPalette.srWindow);
        }
        wchar_t terminalSession[2]{};
        if (adjustFont && !GetEnvironmentVariableW(L"WT_SESSION", terminalSession, 2) &&
            GetCurrentConsoleFontEx(out, FALSE, &oldFont))
        {
            auto font = oldFont;
            font.dwFontSize = {0, 20};
            font.FontFamily = FF_MODERN;
            font.FontWeight = FW_NORMAL;
            const wchar_t face[] = L"Consolas";
            for (size_t i = 0; i < sizeof(face) / sizeof(face[0]); ++i)
                font.FaceName[i] = face[i];
            fontChanged = SetCurrentConsoleFontEx(out, FALSE, &font) != 0;
        }
        hadMode = GetConsoleMode(out, &oldMode) != 0;
        xuatRGB = hadMode && SetConsoleMode(out, oldMode | ENABLE_PROCESSED_OUTPUT |
                                                     ENABLE_VIRTUAL_TERMINAL_PROCESSING) != 0;
        if (xuatRGB)
            GhiConsole(L"\x1b[?1049h\x1b[?7l\x1b[2J\x1b[H");
    }
    ~PhienGiaoDien()
    {
        if (!active)
            return;
        if (xuatRGB)
        {
            try
            {
                GhiConsole(L"\x1b[0m\x1b[?7h\x1b[?25h\x1b[?1049l");
            }
            catch (...)
            {
            }
        }
        xuatRGB = false;
        if (fontChanged)
            SetCurrentConsoleFontEx(out, FALSE, &oldFont);
        if (hadPalette)
        {
            CONSOLE_SCREEN_BUFFER_INFOEX current{};
            current.cbSize = sizeof(current);
            if (GetConsoleScreenBufferInfoEx(out, &current))
            {
                SMALL_RECT rect = current.srWindow;
                for (int i = 0; i < 16; ++i)
                    current.ColorTable[i] = oldPalette.ColorTable[i];
                SetConsoleScreenBufferInfoEx(out, &current);
                SetConsoleWindowInfo(out, TRUE, &rect);
            }
        }
        if (hadMode)
            SetConsoleMode(out, oldMode);
    }
};
struct Phim
{
    WORD ma = 0;
    wchar_t chu = 0;
    bool shift = false, ctrl = false, click = false, resize = false;
    int x = 0, y = 0;
};
Phim DocPhimConsole()
{
    static DWORD nutTruoc = 0;
    static Phim phimLap;
    static WORD conLai = 0;
    if (conLai)
    {
        --conLai;
        return phimLap;
    }
    while (true)
    {
        INPUT_RECORD r{};
        DWORD n = 0;
        if (!ReadConsoleInputW(GetStdHandle(STD_INPUT_HANDLE), &r, 1, &n))
            throw LoiThuVien("Khong doc duoc console");
        Phim p;
        if (r.EventType == WINDOW_BUFFER_SIZE_EVENT)
        {
            p.resize = true;
            return p;
        }
        if (r.EventType == KEY_EVENT && r.Event.KeyEvent.bKeyDown)
        {
            const auto &k = r.Event.KeyEvent;
            p.ma = k.wVirtualKeyCode;
            p.chu = k.uChar.UnicodeChar;
            p.shift = (k.dwControlKeyState & SHIFT_PRESSED) != 0;
            p.ctrl = (k.dwControlKeyState & (LEFT_CTRL_PRESSED | RIGHT_CTRL_PRESSED)) != 0;
            phimLap = p;
            conLai = k.wRepeatCount > 1 ? static_cast<WORD>(k.wRepeatCount - 1) : 0;
            return p;
        }
        if (r.EventType == MOUSE_EVENT)
        {
            const auto &m = r.Event.MouseEvent;
            bool down = (m.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) != 0 &&
                        (nutTruoc & FROM_LEFT_1ST_BUTTON_PRESSED) == 0;
            nutTruoc = m.dwButtonState;
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
    int w = 80, h = 24;
    SMALL_RECT rect{};
    ConTroTam<CHAR_INFO[]> cells;
    KhungUI()
    {
        CONSOLE_SCREEN_BUFFER_INFO s{};
        if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &s))
        {
            rect = s.srWindow;
            w = rect.Right - rect.Left + 1;
            h = rect.Bottom - rect.Top + 1;
        }
        else
            rect = {0, 0, 79, 23};
        cells.reset(new CHAR_INFO[static_cast<size_t>(w) * static_cast<size_t>(h)]);
        fill(0, 0, w, h, NEN);
    }
    void put(int x, int y, wchar_t c, WORD a)
    {
        if (x < 0 || x >= w || y < 0 || y >= h)
            return;
        auto &cell =
            cells[static_cast<size_t>(y) * static_cast<size_t>(w) + static_cast<size_t>(x)];
        cell.Char.UnicodeChar = c;
        cell.Attributes = a;
    }
    void fill(int x, int y, int width, int height, WORD a)
    {
        for (int j = 0; j < height; ++j)
            for (int i = 0; i < width; ++i)
                put(x + i, y + j, L' ', a);
    }
    void text(int x, int y, const wstring &s, int width, WORD a = NEN)
    {
        if (width < 1)
            return;
        wstring visible = GhepDauHienThi(s);
        int n = static_cast<int>(visible.size());
        bool cut = n > width;
        for (int i = 0; i < width && i < n; ++i)
        {
            wchar_t c = visible[static_cast<size_t>(i)];
            if (c < L' ')
                c = L' ';
            if (c >= 0xD800 && c <= 0xDBFF && (i + 1 >= width || (cut && i + 1 == width - 1)))
            {
                put(x + i, y, L'…', a);
                break;
            }
            put(x + i, y, cut && i == width - 1 ? L'…' : c, a);
        }
    }
    void box(int x, int y, int width, int height, const wstring &title = L"", WORD a = VIEN)
    {
        if (width < 2 || height < 2)
            return;
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
            text(x + 2, y, L" " + title + L" ", width - 4, MO);
    }
    void button(int x, int y, int width, const wstring &s, bool active = false)
    {
        WORD color = active ? NUT_CHINH : O_NHAP;
        fill(x, y, width, 1, color);
        text(x + 2, y, s, width - 4, color);
    }
    bool small() const
    {
        return w < 80 || h < 24;
    }
    void show(int cx = -1, int cy = -1)
    {
        if (xuatRGB)
        {
            // Dinh vi tung dong, tat wrap: hang cuoi/cot cuoi khong day khung len.
            wstring output = L"\x1b[?25l\x1b[?7l";
            WORD last = 0xFFFF;
            for (int y = 0; y < h; ++y)
            {
                output += L"\x1b[" + to_wstring(y + 1) + L";1H";
                for (int x = 0; x < w; ++x)
                {
                    const auto &cell = cells[static_cast<size_t>(y) * static_cast<size_t>(w) +
                                             static_cast<size_t>(x)];
                    if (cell.Attributes != last)
                    {
                        output += LenhMau(cell.Attributes);
                        last = cell.Attributes;
                    }
                    output += cell.Char.UnicodeChar;
                }
            }
            if (cx >= 0)
                output += L"\x1b[" + to_wstring(cy + 1) + L";" + to_wstring(cx + 1) +
                          L"H\x1b[6 q\x1b[?25h";
            else
                output += L"\x1b[H";
            GhiConsole(output);
            return;
        }
        CONSOLE_CURSOR_INFO ci{20, cx >= 0 ? TRUE : FALSE};
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ci);
        COORD size{static_cast<SHORT>(w), static_cast<SHORT>(h)}, zero{0, 0};
        auto area = rect;
        WriteConsoleOutputW(GetStdHandle(STD_OUTPUT_HANDLE), cells.get(), size, zero, &area);
        if (cx >= 0)
            SetConsoleCursorPosition(
                GetStdHandle(STD_OUTPUT_HANDLE),
                COORD{static_cast<SHORT>(rect.Left + cx), static_cast<SHORT>(rect.Top + cy)});
    }
};
void NenUngDung(KhungUI &f, const wstring &title, const wstring &help)
{
    f.fill(0, 0, 23, f.h - 2, THANH);
    f.text(3, 1, L"THƯ VIỆN", 18, 0x1A);
    f.text(26, 1, title, f.w - 45, NEN);
    f.text(f.w - 15, 1, SangUTF16(ChuoiNgay(ngayUI)), 12, MO);
    for (int x = 26; x < f.w - 3; ++x)
        f.put(x, 2, L'─', VIEN);
    f.text(3, 3, L"KHÔNG GIAN LÀM VIỆC", 19, 0x17);
    for (int i = 0; i < 14 && i + 4 < f.h - 3; ++i)
    {
        WORD a = i == mucUI ? CHON : THANH;
        f.fill(1, i + 4, 21, 1, a);
        f.text(3, i + 4, dieuHuong[i], 18, a);
        if (i == mucUI)
            f.put(1, i + 4, L'│', 0x3A);
    }
    f.fill(0, f.h - 2, f.w, 2, NEN);
    f.text(2, f.h - 2, help, f.w - 4, MO);
    f.text(2, f.h - 1, L"File: " + (duongDanUI ? SangUTF16(*duongDanUI) : L""), f.w - 4, 0x08);
    if (f.small())
    {
        f.fill(0, 3, f.w, f.h - 5, NEN);
        f.text(1, 4, L"Phóng lớn terminal lên ít nhất 80 cột × 24 dòng.", f.w - 2, NHAN);
        f.text(1, 6, L"Dữ liệu nhập vẫn được giữ. Esc: quay lại.", f.w - 2, NEN);
    }
}
int XNoiDung()
{
    return 26;
}
void DongBang(KhungUI &f, int x, int y, int width, const wstring &line, WORD color)
{
    // Cac dong nhom/ngu canh giu nguyen. Dong co | chia o; Enter xem du noi dung.
    int n = 1;
    for (wchar_t c : line)
        if (c == L'|')
            ++n;
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
            ++k;
        else
            fields[k] += c;
    }
    int pos = x;
    for (int i = 0; i < n; ++i)
    {
        int cw = width / n + (i == n - 1 ? width % n : 0);
        f.text(pos, y, fields[i], cw - 1, color);
        if (i < n - 1)
            f.put(pos + cw - 1, y, L'│', MO);
        pos += cw;
    }
}
void XemChiTiet(const wstring &text, const wstring &title)
{
    size_t start = 0;
    while (true)
    {
        KhungUI f;
        NenUngDung(f, title, L"↑/↓: cuộn   Esc / Enter: đóng");
        if (!f.small())
        {
            int x = XNoiDung(), width = f.w - x - 3, rows = f.h - 9;
            f.box(x, 4, width, rows + 2, L"Nội dung đầy đủ");
            int inner = width - 4;
            if (start > text.size())
                start = 0;
            for (int i = 0; i < rows; ++i)
            {
                size_t p = start + static_cast<size_t>(i * inner);
                if (p >= text.size())
                    break;
                f.text(x + 2, 5 + i, text.substr(p, static_cast<size_t>(inner)), inner);
            }
        }
        f.show();
        Phim p = DocPhimConsole();
        if (p.ma == VK_ESCAPE || p.ma == VK_RETURN)
            return;
        int step = f.w - XNoiDung() - 7;
        if (step < 1)
            step = 1;
        if (p.ma == VK_DOWN && start + static_cast<size_t>(step) < text.size())
            start += static_cast<size_t>(step);
        if (p.ma == VK_UP)
            start = start >= static_cast<size_t>(step) ? start - static_cast<size_t>(step) : 0;
    }
}
struct SoLieu
{
    int dau = 0, cuon = 0, san = 0, doc = 0, muon = 0;
};
SoLieu TongQuan()
{
    SoLieu s;
    if (!duLieuUI)
        return s;
    s.dau = duLieuUI->dsDauSach.soLuong;
    s.doc = DemDocGia(duLieuUI->cayDocGia);
    for (int i = 0; i < s.dau; ++i)
        for (const CuonSach *p = duLieuUI->dsDauSach.ds[i]->dms; p; p = p->next)
        {
            ++s.cuon;
            if (p->trangThai == SACH_CHO_MUON)
                ++s.san;
            if (p->trangThai == SACH_DANG_MUON)
                ++s.muon;
        }
    return s;
}
int TrangChinh()
{
    SoLieu s = TongQuan();
    int focus = 0;
    while (true)
    {
        KhungUI f;
        NenUngDung(f, dieuHuong[mucUI],
                   L"↑/↓: chọn mục   Enter: mở   F1: tổng quan   F5: lưu   Esc/0: lưu và thoát");
        int x = XNoiDung(), width = f.w - x - 3;
        if (!f.small())
        {
            f.text(x, 4, mucUI ? moTa[mucUI] : L"Chào bạn, thư viện hôm nay có gì?", width, NHAN);
            const wchar_t *names[] = {L"Đầu sách", L"Cuốn sách", L"Độc giả", L"Đang giữ"};
            int nums[] = {s.dau, s.cuon, s.doc, s.muon};
            int tile = width / 4;
            for (int i = 0; i < 4; ++i)
            {
                int left = x + i * tile;
                f.fill(left, 6, tile - 2, 4, THANH);
                f.text(left + 2, 7, to_wstring(nums[i]), tile - 5, 0x1A);
                f.text(left + 1, 8, names[i], tile - 3, 0x17);
            }
            f.text(x, 11, mucUI ? L"THAO TÁC" : L"TRUY CẬP NHANH", width, MO);
            if (!mucUI)
            {
                int bw = (width - 4) / 3;
                f.button(x, 13, bw, L"Mượn sách", focus == 0);
                f.button(x + bw + 2, 13, bw, L"Trả sách", focus == 1);
                f.button(x + 2 * (bw + 2), 13, bw, L"Tìm sách", focus == 2);
            }
            else
                f.button(x, 13, width < 34 ? width : 34, L"Mở " + wstring(dieuHuong[mucUI]), true);
            f.box(x, 16, width, f.h - 19, L"Danh mục đầu sách");
            int room = f.h - 22;
            if (room > 0)
            {
                f.fill(x + 1, 17, width - 2, 1, THANH);
                f.text(x + 2, 17, L"ISBN", 17, 0x17);
                f.text(x + 20, 17, L"Tên sách", width - 31, 0x17);
                f.text(x + width - 9, 17, L"Cuốn", 6, 0x17);
                for (int i = 0; duLieuUI && i < s.dau && i < room - 1; ++i)
                {
                    const DauSach *d = duLieuUI->dsDauSach.ds[i];
                    int y = 18 + i;
                    WORD row = i % 2 ? THANH : NEN;
                    f.fill(x + 1, y, width - 2, 1, row);
                    f.text(x + 2, y, SangUTF16(d->ISBN), 17, static_cast<WORD>((row & 0xF0) | 7));
                    f.text(x + 20, y, SangUTF16(d->tenSach), width - 31, row);
                    f.text(x + width - 8, y, to_wstring(DemCuonSach(d->dms)), 5,
                           static_cast<WORD>((row & 0xF0) | 10));
                }
                if (s.dau == 0)
                    f.text(x + 2, 18, L"Chưa có đầu sách. Mở Kho sách để thêm.", width - 4, MO);
            }
        }
        f.show();
        Phim p = DocPhimConsole();
        if (p.ma == VK_ESCAPE || p.chu == L'0')
            return 0;
        if (p.ma == VK_F5)
            return 12;
        if (p.ma == VK_F1)
        {
            mucUI = 0;
            continue;
        }
        if (f.small())
            continue;
        if (p.ma == VK_UP)
            mucUI = (mucUI + 13) % 14;
        if (p.ma == VK_DOWN)
            mucUI = (mucUI + 1) % 14;
        if (p.ma == VK_TAB || p.ma == VK_RIGHT)
            focus = (focus + 1) % 3;
        if (p.ma == VK_LEFT)
            focus = (focus + 2) % 3;
        if (p.click)
        {
            if (p.x < 23 && p.y >= 4 && p.y < 18)
            {
                mucUI = p.y - 4;
                continue;
            }
            if (p.y == 13 && p.x >= x && p.x < x + width)
            {
                if (mucUI)
                {
                    if (p.x < x + (width < 34 ? width : 34))
                        return mucUI;
                }
                else
                {
                    int bw = (width - 4) / 3;
                    int index = (p.x - x) / (bw + 2);
                    if (index < 3 && (p.x - x) % (bw + 2) < bw)
                    {
                        focus = index;
                        const int quick[] = {6, 7, 5};
                        mucUI = quick[focus];
                        return mucUI;
                    }
                }
            }
        }
        if (p.ma == VK_RETURN)
        {
            if (mucUI)
                return mucUI;
            const int quick[] = {6, 7, 5};
            mucUI = quick[focus];
            return mucUI;
        }
        if (p.chu >= L'1' && p.chu <= L'9')
        {
            mucUI = static_cast<int>(p.chu - L'0');
            return mucUI;
        }
    }
}
size_t LuiKyTu(const wstring &s, size_t p)
{
    if (!p)
        return 0;
    --p;
    if (p && s[p] >= 0xDC00 && s[p] <= 0xDFFF && s[p - 1] >= 0xD800 && s[p - 1] <= 0xDBFF)
        --p;
    return p;
}
size_t TienKyTu(const wstring &s, size_t p)
{
    if (p >= s.size())
        return s.size();
    if (s[p] >= 0xD800 && s[p] <= 0xDBFF && p + 1 < s.size() && s[p + 1] >= 0xDC00 &&
        s[p + 1] <= 0xDFFF)
        ++p;
    return p + 1;
}
bool BieuMau(const string &title, const char *const *labels, string *values, int count)
{
    if (count < 1 || count > 12)
        throw LoiThuVien("Bieu mau chi ho tro 1..12 o");
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
        KhungUI f;
        NenUngDung(f, NhanHienThi(title),
                   L"Tab: đổi ô   Enter: tiếp   Ctrl+Enter: xác nhận   Esc: hủy");
        int x = XNoiDung(), width = f.w - x - 3, capacity = (f.h - 11) / 3;
        if (capacity < 1)
            capacity = 1;
        if (width > 66)
            width = 66;
        int shown = count < capacity ? count : capacity, buttonY = 7 + shown * 3;
        if (buttonY > f.h - 5)
            buttonY = f.h - 5;
        if (active < count)
        {
            if (active < first)
                first = active;
            if (active >= first + capacity)
                first = active - capacity + 1;
        }
        int cx = -1, cy = -1;
        if (!f.small())
        {
            f.text(x, 4, L"Nhập thông tin và chọn Xác nhận để lưu.", width, MO);
            for (int i = first; i < count && i < first + capacity; ++i)
            {
                int y = 6 + (i - first) * 3;
                f.text(x, y, NhanHienThi(labels[i]), width, active == i ? NHAN : MO);
                WORD fieldColor = active == i ? O_DANG_NHAP : O_NHAP;
                f.fill(x, y + 1, width, 1, fieldColor);
                f.put(x, y + 1, L'│',
                      static_cast<WORD>((fieldColor & 0xF0) | (active == i ? 10 : 8)));
                size_t start = cursors[i] > static_cast<size_t>(width - 4)
                                   ? cursors[i] - static_cast<size_t>(width - 4)
                                   : 0;
                if (start && fields[i][start] >= 0xDC00 && fields[i][start] <= 0xDFFF)
                    --start;
                f.text(x + 2, y + 1, fields[i].substr(start), width - 4, fieldColor);
                if (active == i)
                {
                    cx = x + 2 +
                         static_cast<int>(
                             GhepDauHienThi(fields[i].substr(start, cursors[i] - start)).size());
                    if (cx > x + width - 2)
                        cx = x + width - 2;
                    cy = y + 1;
                }
            }
            f.button(x, buttonY, 20, L"Xác nhận", active == count);
            f.button(x + 22, buttonY, 14, L"Hủy", active == count + 1);
            f.text(x, buttonY + 2,
                   L"Ô " + to_wstring(active < count ? active + 1 : count) + L" / " +
                       to_wstring(count) + L"  ·  Chưa xác nhận",
                   width, MO);
        }
        f.show(cx, cy);
        Phim p = DocPhimConsole();
        if (p.ma == VK_ESCAPE)
            return false;
        if (f.small())
            continue;
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
                        return false;
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
                    if (fields[i] == L"/huy")
                        return false;
                string converted[12];
                for (int i = 0; i < count; ++i)
                    converted[i] = TuUTF16(fields[i]);
                for (int i = 0; i < count; ++i)
                    values[i] = converted[i];
                return true;
            }
            if (active == count + 1)
                return false;
            ++active;
            continue;
        }
        if (active >= count)
        {
            if (p.ma == VK_LEFT || p.ma == VK_RIGHT)
                active = active == count ? count + 1 : count;
            continue;
        }
        auto &val = fields[active];
        auto &cursor = cursors[active];
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
            val.erase(prev, cursor - prev);
            cursor = prev;
            continue;
        }
        if (p.ma == VK_DELETE && cursor < val.size())
        {
            val.erase(cursor, TienKyTu(val, cursor) - cursor);
            continue;
        }
        if (p.chu >= 32 && !p.ctrl && val.size() < 4096)
        {
            val.insert(cursor, 1, p.chu);
            ++cursor;
        }
    }
}
#endif
} // namespace
bool DangDungGiaoDienHeThong()
{
    return giaoDienPhim;
}
bool NhapBieuMau(const string &title, const char *const *labels, string *values, int count)
{
#ifdef _WIN32
    if (giaoDienPhim)
        return BieuMau(title, labels, values, count);
#endif
    (void)title;
    for (int i = 0; i < count; ++i)
        if (!NhapDong(labels[i], values[i]))
            return false;
    return true;
}
bool NhapDong(const string &prompt, string &s)
{
#ifdef _WIN32
    if (giaoDienPhim)
    {
        const char *labels[] = {prompt.c_str()};
        string value;
        bool ok = BieuMau(tieuDeUI, labels, &value, 1);
        if (ok)
            s = value;
        return ok && s != "/huy";
    }
#endif
    cout << prompt << " (/huy de quay lai): " << flush;
    if (!getline(cin, s))
        return false;
    if (!s.empty() && s.back() == '\r')
        s.pop_back();
    return s != "/huy" && s != string(1, '\x1b');
}
bool NhapSo(const string &prompt, int &n, int lo, int hi)
{
    string s;
    while (NhapDong(prompt, s))
    {
        if (DocSoNguyen(ChuanHoaChuoi(s), n, lo, hi))
            return true;
        if (giaoDienPhim)
            ThongBao("LOI: nhap so nguyen trong [" + to_string(lo) + ", " + to_string(hi) + "].");
        else
            cout << "LOI: nhap so nguyen trong [" << lo << ", " << hi << "].\n";
    }
    return false;
}
int ChonMenu(const string &title, const char *const *labels, int count)
{
#ifdef _WIN32
    if (giaoDienPhim)
    {
        if (count == 13 && duLieuUI)
        {
            int r = TrangChinh();
            tieuDeUI = TuUTF16(dieuHuong[mucUI]);
            return r;
        }
        int selected = 0;
        tieuDeUI = title;
        while (true)
        {
            KhungUI f;
            NenUngDung(f, NhanHienThi(title),
                       L"↑/↓: chọn thao tác   Enter / nhấp chuột: mở   Esc/0: quay lại");
            int x = XNoiDung(), width = f.w - x - 3;
            if (!f.small())
            {
                f.text(x, 5, L"Bạn muốn thực hiện thao tác nào?", width, NHAN);
                for (int i = 0; i < count; ++i)
                {
                    f.button(x, 8 + i * 3, width, NhanHienThi(labels[i]), i == selected);
                    f.text(x + 2, 9 + i * 3, L"Enter để mở", width - 4, MO);
                }
            }
            f.show();
            Phim p = DocPhimConsole();
            if (p.ma == VK_ESCAPE || p.chu == L'0')
                return 0;
            if (f.small())
                continue;
            if (p.ma == VK_UP)
                selected = (selected + count - 1) % count;
            if (p.ma == VK_DOWN)
                selected = (selected + 1) % count;
            if (p.ma == VK_RETURN)
            {
                tieuDeUI = labels[selected];
                return selected + 1;
            }
            if (p.chu >= L'1' && p.chu <= L'9' && p.chu - L'1' < count)
            {
                int r = static_cast<int>(p.chu - L'0');
                tieuDeUI = labels[r - 1];
                return r;
            }
            if (p.click && p.x >= x && p.x < x + width && p.y >= 8 && (p.y - 8) % 3 == 0 &&
                (p.y - 8) / 3 < count)
            {
                selected = (p.y - 8) / 3;
                tieuDeUI = labels[selected];
                return selected + 1;
            }
        }
    }
#endif
    cout << '\n' << title << '\n';
    for (int i = 0; i < count; ++i)
        cout << i + 1 << ". " << labels[i] << '\n';
    cout << "0. Quay lai / luu va thoat\n";
    int choice = 0;
    return NhapSo("Chon", choice, 0, count) ? choice : 0;
}
void ThongBao(const string &s)
{
#ifdef _WIN32
    if (giaoDienPhim)
    {
        XemChiTiet(SangUTF16(s), L"Thông báo");
        return;
    }
#endif
    cout << s << '\n' << flush;
}
void HienThiPhanTrang(const string &text)
{
    if (!giaoDienPhim)
    {
        cout << text << flush;
        return;
    }
#ifdef _WIN32
    wstring all = SangUTF16(text);
    size_t total = 1;
    for (wchar_t c : all)
        if (c == L'\n')
            ++total;
    ConTroTam<size_t[]> starts(new size_t[total + 1]);
    size_t n = 1;
    starts[0] = 0;
    for (size_t i = 0; i < all.size(); ++i)
        if (all[i] == L'\n' && i + 1 < all.size())
            starts[n++] = i + 1;
    starts[n] = all.size();
    size_t selected = 0, page = 0;
    while (true)
    {
        KhungUI f;
        NenUngDung(f, SangUTF16(tieuDeUI),
                   L"↑/↓: chọn dòng   PgUp/PgDn: đổi trang   Enter: xem đầy đủ   Esc: quay lại");
        int x = XNoiDung(), width = f.w - x - 3, rows = f.h - 11;
        if (rows < 1)
            rows = 1;
        size_t step = static_cast<size_t>(rows);
        page = selected / step;
        if (!f.small())
        {
            f.text(x, 4, L"KẾT QUẢ   ·   " + to_wstring(n) + L" dòng", width, NHAN);
            f.box(x, 6, width, rows + 2);
            for (int i = 0; i < rows; ++i)
            {
                size_t index = page * step + static_cast<size_t>(i);
                if (index >= n)
                    break;
                WORD color = index == selected ? CHON : (index % 2 ? THANH : NEN);
                f.fill(x + 1, 7 + i, width - 2, 1, color);
                auto line = all.substr(starts[index], starts[index + 1] - starts[index]);
                while (!line.empty() && (line.back() == L'\n' || line.back() == L'\r'))
                    line.pop_back();
                DongBang(f, x + 2, 7 + i, width - 4, line, color);
            }
            f.button(x, f.h - 3, 12, L"‹ Trước");
            f.text(x + 14, f.h - 3,
                   L"Trang " + to_wstring(page + 1) + L" / " + to_wstring((n + step - 1) / step),
                   width - 29, MO);
            f.button(x + width - 13, f.h - 3, 13, L"Sau ›");
        }
        f.show();
        Phim p = DocPhimConsole();
        if (p.ma == VK_ESCAPE)
            return;
        if (f.small())
            continue;
        if (p.ma == VK_UP && selected)
            --selected;
        if (p.ma == VK_DOWN && selected + 1 < n)
            ++selected;
        if (p.ma == VK_HOME)
            selected = 0;
        if (p.ma == VK_END)
            selected = n - 1;
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
                    selected = i;
            }
        }
        if (next)
            selected = selected + step < n ? selected + step : n - 1;
        if (prev)
            selected = selected >= step ? selected - step : 0;
        if (p.ma == VK_RETURN)
            XemChiTiet(all.substr(starts[selected], starts[selected + 1] - starts[selected]),
                       L"Chi tiết dòng " + to_wstring(selected + 1));
    }
#endif
}

void LuuSauThayDoi(const ThuVien &tv)
{
    if (thuVienTuLuu != &tv || !tepTuLuu)
        return;
    chuaLuu = true;
    string loi;
    if (!LuuFile(tv, *tepTuLuu, loi))
        throw LoiThuVien("Da cap nhat RAM nhung CHUA LUU: " + loi +
                         ". Hay bam Luu (F5); khong dong cua so.");
    chuaLuu = false;
}

#ifndef THUVIEN_TEST
namespace
{
struct ConsoleScope
{
#ifdef _WIN32
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
            SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), oldMode);
        if (hadCursor)
            SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &oldCursor);
        SetConsoleCP(oldIn);
        SetConsoleOutputCP(oldOut);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
#endif
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
int ChayUngDung(int argc, char **argv)
{
    string path = "DuLieu/runtime/ThuVien.txt", check;
    NgayThang ngay = HomNay();
    bool plain = false;
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
                path = val;
            else if (arg == "--check")
                check = val;
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
#ifdef _WIN32
    DWORD inputMode = 0, outputMode = 0;
    giaoDienPhim = !plain && GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &inputMode) &&
                   GetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), &outputMode);
#else
    (void)plain;
    giaoDienPhim = false; // giao dien nhap so portable
#endif
    ThuVien tv;
    string loi;
#ifdef _WIN32
    duLieuUI = &tv;
    duongDanUI = &path;
    ngayUI = ngay;
    if (giaoDienPhim)
    {
        DWORD mode = 0;
        GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &mode);
        SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE),
                       (mode | ENABLE_EXTENDED_FLAGS | ENABLE_MOUSE_INPUT | ENABLE_WINDOW_INPUT) &
                           ~(ENABLE_QUICK_EDIT_MODE | ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT));
    }
#endif
    if (!check.empty())
    {
        if (!DocFile(tv, check, loi))
        {
            cerr << "KHONG HOP LE: " << loi << '\n';
            return 2;
        }
        int copies = 0;
        for (int i = 0; i < tv.dsDauSach.soLuong; ++i)
            copies += DemCuonSach(tv.dsDauSach.ds[i]->dms);
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
    PhienTuLuu tuLuu(tv, path);
    if (FileTonTai(path))
    {
        if (!DocFile(tv, path, loi))
        {
            cerr << "Khong nap/khong ghi de file loi: " << loi << '\n';
            return 2;
        }
    }
    else
    {
        TaoThuMuc(ThuMucCha(DuongDanDayDu(path)));
        cout << "Tao phien rong; file se duoc tao khi luu.\n";
    }
    cout << "BAN THAM KHAO AI - khong phai bang chung nhom tu lam.\nNgay giao dich: "
         << ChuoiNgay(ngay) << "\nDu lieu: " << path << '\n';
#ifdef _WIN32
    PhienGiaoDien phienGiaoDien(giaoDienPhim);
#endif
    const char *labels[] = {"a - Them / xoa / sua doc gia",
                            "b - Liet ke doc gia",
                            "c - Nhap dau sach / them cuon",
                            "d - Dau sach theo the loai",
                            "e - Tim theo ten sach",
                            "f - Muon sach",
                            "g - Tra / bao mat sach",
                            "h - Sach doc gia dang muon",
                            "i - Doc gia qua han",
                            "j - Top 10 dau sach",
                            "Nap file khac",
                            "Luu du lieu",
                            "Thoat (khong thu luu lai)"};
    while (true)
    {
        int choice = ChonMenu("THU VIEN | " + ChuoiNgay(ngay) + "\nDu lieu: " + path, labels, 13);
        if (!cin)
        {
            cerr << "EOF: thoat; thao tac da tu luu van con. Neu da bao loi luu, RAM chua ghi se "
                    "mat.\n";
            return 0;
        }
        try
        {
            if (chuaLuu &&
                (choice == 1 || choice == 3 || choice == 6 || choice == 7 || choice == 11))
            {
                ThongBao(
                    "CHUA LUU: hay bam Luu (F5) thanh cong truoc khi sua tiep hoac nap file khac.");
                continue;
            }
            LuongChuoi out;
            if (choice == 0 || choice == 12)
            {
                if (LuuFile(tv, path, loi))
                {
                    chuaLuu = false;
                    ThongBao("OK: da luu " + path);
                    if (choice == 0)
                        return 0;
                }
                else
                    ThongBao("LOI LUU (van giu du lieu trong RAM): " + loi);
            }
            else if (choice == 1)
                ManHinhDocGia(tv);
            else if (choice == 2)
            {
                const char *views[] = {"Theo ma the", "Theo ten + ho"};
                int v = ChonMenu("b - DOC GIA", views, 2);
                if (v == 1)
                    InDocGiaTheoMa(tv, out);
                else if (v == 2)
                    InDocGiaTheoTenHo(tv, out);
                if (v)
                    HienThiPhanTrang(out.str());
            }
            else if (choice == 3)
                ManHinhNhapDauSach(tv);
            else if (choice == 4)
            {
                InDauSachTheoTheLoai(tv, out);
                HienThiPhanTrang(out.str());
            }
            else if (choice == 5)
                ManHinhTimSach(tv);
            else if (choice == 6 || choice == 7)
                ManHinhMuonTra(tv, ngay, choice == 7);
            else if (choice == 8)
            {
                int ma;
                if (NhapSo("Ma the", ma, 1, SO_NGUYEN_LON_NHAT))
                {
                    LietKeSachDangMuon(tv, ma, out);
                    HienThiPhanTrang(out.str());
                }
            }
            else if (choice == 9)
            {
                InDocGiaQuaHan(tv, ngay, out);
                HienThiPhanTrang(out.str());
            }
            else if (choice == 10)
            {
                InTop10SachDuocMuonNhieuNhat(tv, out);
                HienThiPhanTrang(out.str());
            }
            else if (choice == 11)
            {
                string next, confirm;
                if (NhapDong("Duong dan file UTF-8", next) &&
                    NhapDong("Nhap NAP de thay du lieu RAM (hay luu truoc neu can)", confirm) &&
                    confirm == "NAP")
                {
                    if (NapPhien(tv, path, next, khoa, loi))
                    {
                        ThongBao("OK: da nap du lieu.");
                    }
                    else
                        ThongBao("LOI: " + loi + "; du lieu RAM cu duoc giu nguyen.");
                }
            }
            else if (choice == 13)
            {
                string confirm;
                if (NhapDong("Nhap THOAT de thoat; du lieu da tu luu van giu, RAM chua luu (neu co "
                             "loi) se mat",
                             confirm) &&
                    confirm == "THOAT")
                    return 0;
            }
        }
        catch (const LoiThuVien &e)
        {
            ThongBao(string("Khong hoan tat thao tac: ") + e.what());
        }
        catch (...)
        {
            ThongBao("Khong hoan tat thao tac: khong du bo nho / loi luong.");
        }
    }
}
} // namespace
int main(int argc, char **argv)
{
    ConsoleScope console;
    try
    {
#ifdef _WIN32
        // argv hep cua CRT co the la ANSI. Doc lenh UTF-16 de duong dan co dau dung.
        const wstring command = GetCommandLineW();
        ConTroTam<string[]> utf8(new string[command.size() + 1]);
        int n = DocDoiSoWindows(command, utf8.get());
        ConTroTam<char *[]> ptrs(new char *[n]);
        for (int i = 0; i < n; ++i)
            ptrs[i] = &utf8[i][0];
        (void)argc;
        (void)argv;
        return ChayUngDung(n, ptrs.get());
#else
        return ChayUngDung(argc, argv);
#endif
    }
    catch (const LoiThuVien &e)
    {
        cerr << "LOI: " << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "LOI: khong du bo nho / loi luong.\n";
        return 1;
    }
}
#endif
