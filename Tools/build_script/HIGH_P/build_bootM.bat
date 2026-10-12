@echo off
setlocal enabledelayedexpansion

REM ==================== Configuration ====================
set "ARM_TOOLCHAIN=D:\GNU Arm Embedded Toolchain\10 2021.10"
set "MAKE_PATH=D:\GNU Arm Embedded Toolchain\10 2021.10\bin"
set "BUILD_CONFIG=..\..\..\BootM\Debug"
REM =======================================================

set "PROJECT_ROOT=%~dp0"
set "BUILD_DIR=%PROJECT_ROOT%%BUILD_CONFIG%"

echo [INFO] Setting up environment...

REM Check ARM GCC
if not exist "%ARM_TOOLCHAIN%\bin\arm-none-eabi-gcc.exe" (
    echo [ERROR] ARM GCC not found. Check ARM_TOOLCHAIN: %ARM_TOOLCHAIN%
    exit /b 1
)
set "PATH=%ARM_TOOLCHAIN%\bin;%PATH%"

REM Check make
where make >nul 2>&1
if %errorlevel% neq 0 (
    if defined MAKE_PATH (
        if exist "%MAKE_PATH%\make.exe" (
            set "PATH=%MAKE_PATH%;%PATH%"
        ) else (
            echo [ERROR] make not found in MAKE_PATH: %MAKE_PATH%
            exit /b 1
        )
    ) else (
        echo [ERROR] make not found in PATH. Install make or set MAKE_PATH.
        exit /b 1
    )
)

REM Enter build directory
if not exist "%BUILD_DIR%\Makefile" (
    echo [ERROR] Makefile not found in %BUILD_DIR%
    exit /b 1
)

cd /d "%BUILD_DIR%"
echo [INFO] Starting build (config: %BUILD_CONFIG%)

REM ==================== Clean step ====================
echo [INFO] Cleaning...
make clean
if %errorlevel% neq 0 (
    echo [WARNING] 'make clean' reported errors, continuing anyway...
)
REM =====================================================

echo [INFO] Running make all...
make -j%NUMBER_OF_PROCESSORS% all
if %errorlevel% neq 0 (
    echo [ERROR] Build failed.
    exit /b 1
)
echo [SUCCESS] Build completed.

REM Find ELF and generate hex/bin
set "ELF_FILE="
for %%f in (*.elf) do (
    set "ELF_FILE=%%f"
    goto FOUND_ELF
)
:FOUND_ELF
if "%ELF_FILE%"=="" (
    echo [WARNING] No .elf file found, skip firmware generation.
    goto DONE
)

echo [INFO] Output ELF: %ELF_FILE%
for %%A in ("%ELF_FILE%") do set "BASE_NAME=%%~nA"

arm-none-eabi-objcopy -O ihex --gap-fill 0xFF "%ELF_FILE%" "%BASE_NAME%.hex"
if %errorlevel% equ 0 (
    echo [INFO] Generated %BASE_NAME%.hex
) else (
    echo [ERROR] HEX generation failed.
)

arm-none-eabi-objcopy -O binary --gap-fill 0xFF "%ELF_FILE%" "%BASE_NAME%.bin"
if %errorlevel% equ 0 (
    echo [INFO] Generated %BASE_NAME%.bin
) else (
    echo [ERROR] BIN generation failed.
)

arm-none-eabi-size "%ELF_FILE%"

:DONE
REM ==================== Copy output files to project root ====================
echo [INFO] Copying output files to project root directory (%PROJECT_ROOT%)...

REM Copy hex files
if exist "*.hex" (
    xcopy /Y "*.hex" "%PROJECT_ROOT%" >nul
    echo [INFO] Copied .hex files to %PROJECT_ROOT%
) else (
    echo [INFO] No .hex files found to copy.
)

REM Copy bin files
if exist "*.bin" (
    xcopy /Y "*.bin" "%PROJECT_ROOT%" >nul
    echo [INFO] Copied .bin files to %PROJECT_ROOT%
) else (
    echo [INFO] No .bin files found to copy.
)

REM Copy map files
if exist "*.map" (
    xcopy /Y "*.map" "%PROJECT_ROOT%" >nul
    echo [INFO] Copied .map files to %PROJECT_ROOT%
) else (
    echo [INFO] No .map files found to copy.
)

REM Copy elf files
if exist "*.elf" (
    xcopy /Y "*.elf" "%PROJECT_ROOT%" >nul
    echo [INFO] Copied .elf files to %PROJECT_ROOT%
) else (
    echo [INFO] No .elf files found to copy.
)
echo ========================================================================
REM ========================================================================

echo.
echo ========================================
echo   Build finished. Output: %BUILD_DIR%
echo ========================================
endlocal
