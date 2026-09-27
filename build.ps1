param([string]$Compiler = 'g++')

$ErrorActionPreference = 'Stop'
$projectDir = $PSScriptRoot
$outputDir = Join-Path $projectDir 'build'
New-Item -ItemType Directory -Force -Path $outputDir | Out-Null

# Liệt kê rõ file thực thi; bản khai báo .cpp gốc chỉ giữ để đối chiếu.
$sourceNames = @('main', 'DocGia', 'MuonTra', 'Sach', 'ThongKe', 'LietKe', 'Menu', 'GiaoDien', 'DuLieu')
$sourcePaths = @($sourceNames | ForEach-Object { Join-Path $projectDir "src/$_.cpp" })
$outputPath = Join-Path $outputDir 'thu-vien.exe'
& $Compiler '-std=c++17' '-Wall' '-Wextra' '-Wpedantic' @sourcePaths '-o' $outputPath
if ($LASTEXITCODE -ne 0) { throw "Build failed, exit code $LASTEXITCODE" }
Write-Host "Build OK: $outputPath"
Write-Host 'Build thành công không có nghĩa các hàm TODO đã được cài hoặc kiểm thử.'
