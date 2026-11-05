@echo off
setlocal
pushd "%~dp0.." || exit /b 1
if not exist build mkdir build
g++ -std=c++11 -O2 -Wall -Wextra -Wpedantic demotrinhthay/*.cpp -o build/ThuVien.exe
if errorlevel 1 goto loi
build\ThuVien.exe
if errorlevel 1 goto loi
popd
exit /b 0
:loi
echo Khong chay duoc demo. Kiem tra thong bao o tren va MinGW g++ trong PATH.
pause
popd
exit /b 1
