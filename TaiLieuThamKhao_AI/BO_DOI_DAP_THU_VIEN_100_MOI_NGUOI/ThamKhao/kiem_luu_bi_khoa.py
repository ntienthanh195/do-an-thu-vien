"""Một ca kiểm lưu thất bại do khóa tệp Windows; chỉ dùng dữ liệu tổng hợp."""
from pathlib import Path
import argparse, ctypes, hashlib, json, os, subprocess, tempfile
from ctypes import wintypes

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--exe', required=True)
parser.add_argument('--report', required=True, help='Tệp báo cáo mới, không ghi đè')
args = parser.parse_args()
exe, report = Path(args.exe).resolve(), Path(args.report).resolve()
assert os.name == 'nt', 'Ca này dùng handle tệp Windows'
assert exe.is_file() and not report.exists()
k = ctypes.WinDLL('kernel32', use_last_error=True)
k.CreateFileW.argtypes = [wintypes.LPCWSTR, wintypes.DWORD, wintypes.DWORD,
    ctypes.c_void_p, wintypes.DWORD, wintypes.DWORD, wintypes.HANDLE]
k.CreateFileW.restype = wintypes.HANDLE
k.CloseHandle.argtypes = [wintypes.HANDLE]
k.CloseHandle.restype = wintypes.BOOL

with tempfile.TemporaryDirectory(prefix='thu-vien-save-locked-') as temp:
    p = Path(temp) / 'data.txt'
    p.write_text('20\n0\n0\n', encoding='utf-8')
    before = p.read_bytes()
    h = k.CreateFileW(str(p), 0x80000000, 1, None, 3, 0, None)
    assert h != ctypes.c_void_p(-1).value, ctypes.get_last_error()
    try:
        run = subprocess.run([str(exe), '--plain', '--data', str(p), '--date', '16/10/2026'],
            input='1\n1\nNguyen\nMoi\nNam\n0\n2\n1\n13\nTHOAT\n'.encode(),
            capture_output=True, timeout=25)
    finally:
        k.CloseHandle(h)
    out = run.stdout.decode('utf-8').replace('\r\n', '\n')
    assert run.returncode == 0 and 'LOI LUU' in out and 'Thay the file that bai' in out, out
    assert '21 | Nguyen | Moi | Nam | Hoat dong' in out, out
    assert p.read_bytes() == before
    assert not list(p.parent.glob('.thu-vien-save-*'))
    result = dict(case='save_locked_keeps_ram_file', status='PASS', question_ids=['GH05', 'TN100'],
        stdout=out, stderr=run.stderr.decode('utf-8'), exe_sha256=hashlib.sha256(exe.read_bytes()).hexdigest(),
        old_file_sha256=hashlib.sha256(before).hexdigest(),
        assertions=['exit0 after explicit THOAT', 'replace failure reported',
            'new reader21 still in RAM report', 'original target bytes unchanged',
            'temporary save directory cleaned'])
with report.open('x', encoding='utf-8') as f:
    json.dump(result, f, ensure_ascii=False, indent=2)
    f.write('\n')
print('PASS save_locked_keeps_ram_file')
