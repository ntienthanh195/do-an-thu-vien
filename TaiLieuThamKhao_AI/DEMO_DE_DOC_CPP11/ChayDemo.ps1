param([switch]$Plain)
$ErrorActionPreference = 'Stop'
Push-Location $PSScriptRoot
try {
    if (-not (Test-Path -LiteralPath 'build/ThuVien.exe')) { & ./Build.ps1 }
    New-Item -ItemType Directory -Force -Path 'DuLieu/runtime' | Out-Null
    # Moi lan mo la ban sao rieng, khong ghi de mau hoac phien demo cu.
    $demoFile = 'DuLieu/runtime/demo-' + (Get-Date -Format 'yyyyMMdd-HHmmss-ffff') + '.txt'
    Copy-Item -LiteralPath 'DuLieu/DuLieuMau.txt' -Destination $demoFile
    $appArgs = @('--data', $demoFile, '--date', '16/10/2026')
    if ($Plain) { $appArgs += '--plain' }
    & ./build/ThuVien.exe @appArgs
    if ($LASTEXITCODE -ne 0) { throw "Chuong trinh thoat voi ma $LASTEXITCODE" }
} finally { Pop-Location }
