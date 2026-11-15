@echo off
rem Bien dich bang g++ (MinGW) roi chay. Can co g++ trong PATH.
g++ -std=c++11 -Wall MaNguon\*.cpp -o ThuVien.exe
if errorlevel 1 (
  echo Bien dich that bai.
  pause
  exit /b 1
)
ThuVien.exe
