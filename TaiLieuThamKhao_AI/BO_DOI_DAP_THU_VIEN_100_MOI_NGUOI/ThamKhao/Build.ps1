param([string]$Compiler = '')
$ErrorActionPreference = 'Stop'
if (-not $Compiler) {
    $found = Get-Command g++ -ErrorAction SilentlyContinue
    if ($found) { $Compiler = $found.Source }
    elseif (Test-Path -LiteralPath 'C:\msys64\ucrt64\bin\g++.exe') { $Compiler = 'C:\msys64\ucrt64\bin\g++.exe' }
    else { throw 'Can cai GCC/MinGW co C++11, hoac truyen -Compiler duong-dan-g++.exe' }
}
$oldPath = $env:PATH
$env:PATH = (Split-Path -Parent $Compiler) + [IO.Path]::PathSeparator + $oldPath
Push-Location $PSScriptRoot
try {
    New-Item -ItemType Directory -Force -Path build | Out-Null
    $sources = @(
        'MaNguon/01_HamTienIch.cpp', 'MaNguon/02_XuLyDauSach.cpp',
        'MaNguon/03_XuLyCuonSach.cpp', 'MaNguon/04_XuLyDocGia.cpp',
        'MaNguon/05_XuLyMuonTra.cpp', 'MaNguon/06_NghiepVuTongHop.cpp',
        'MaNguon/07_LuuDocFile.cpp', 'MaNguon/08_ChuongTrinhChinh.cpp'
    )
    $flags = @('-std=c++11', '-O2', '-Wall', '-Wextra', '-Wpedantic', '-Wconversion', '-Wshadow', '-Werror', '-static', '-static-libgcc', '-static-libstdc++')
    & $Compiler @flags @sources  -o build/ThuVien.exe
    if ($LASTEXITCODE -ne 0) { throw "Build that bai: exit $LASTEXITCODE" }
    Write-Output 'BUILD OK: build/ThuVien.exe (9 file nguon, 1 main)'
} finally {
    Pop-Location
    $env:PATH = $oldPath
}
