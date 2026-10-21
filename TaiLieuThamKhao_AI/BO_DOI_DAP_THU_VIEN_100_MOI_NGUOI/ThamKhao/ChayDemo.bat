@echo off
setlocal
pushd "%~dp0"
if errorlevel 1 (
    echo ERROR: Cannot open the extracted project folder.
    pause
    exit /b 1
)
powershell.exe -NoLogo -NoProfile -ExecutionPolicy Bypass -File "%~dp0ChayDemo.ps1" %*
set "demo_exit=%ERRORLEVEL%"
popd
if not "%demo_exit%"=="0" (
    echo.
    echo Demo failed. Read the error above and README.md.
)
echo.
echo Press any key to close this launcher.
pause >nul
exit /b %demo_exit%

