@echo off
rem Bien dich bang g++ (MinGW/MSYS2) roi chay chuong trinh.
cd /d "%~dp0"
if exist C:\msys64\ucrt64\bin\g++.exe set "PATH=C:\msys64\ucrt64\bin;%PATH%"
echo Dang bien dich...
g++ -std=c++11 -Wall -static MaNguon\*.cpp -o ThuVien.exe
if errorlevel 1 (
  echo Bien dich that bai.
  pause
  exit /b 1
)
ThuVien.exe
