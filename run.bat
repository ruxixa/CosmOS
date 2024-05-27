@echo off
qemu-system-i386 --version >nul 2>&1
if %ERRORLEVEL% equ 0 (
    qemu-system-i386 -kernel build/kernel
) else (
    echo QEMU not found
)
pause
