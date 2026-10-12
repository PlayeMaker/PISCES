@echo off
setlocal enabledelayedexpansion

REM ==================== Configuration ====================
REM Usage: %~nx0 [ALL] [HIGH_D] [HIGH_P] [LOW_D] [LOW_P] ...
REM Multiple args are supported, e.g.: %~nx0 HIGH_D HIGH_P
set "CONFIGS="
set "HAS_ALL=0"
set "ARG_COUNT=0"

:parse_loop
if "%~1"=="" goto :parse_done
if /i "%~1"=="ALL" (
    set "HAS_ALL=1"
) else if /i "%~1"=="HIGH_D" (
    set "CONFIGS=!CONFIGS! HIGH_D"
    set /a ARG_COUNT+=1
) else if /i "%~1"=="HIGH_P" (
    set "CONFIGS=!CONFIGS! HIGH_P"
    set /a ARG_COUNT+=1
) else if /i "%~1"=="LOW_D" (
    set "CONFIGS=!CONFIGS! LOW_D"
    set /a ARG_COUNT+=1
) else if /i "%~1"=="LOW_P" (
    set "CONFIGS=!CONFIGS! LOW_P"
    set /a ARG_COUNT+=1
) else (
    echo [ERROR] Unknown argument: %~1. Usage: %~nx0 [ALL^|HIGH_D^|HIGH_P^|LOW_D^|LOW_P] ...
    exit /b 1
)
shift
goto :parse_loop
:parse_done

REM If ALL is present or no args, build all four configs
if "!HAS_ALL!"=="1" set "CONFIGS=HIGH_D HIGH_P LOW_D LOW_P"
if "!CONFIGS!"=="" set "CONFIGS=HIGH_D HIGH_P LOW_D LOW_P"

REM Trim leading space
for /f "tokens=*" %%a in ("!CONFIGS!") do set "CONFIGS=%%a"

REM Unified folder name: ProjectName_APP1.6x[1,2,3,4]_BOOT1.4x_YYMMDDHHmm
REM   Numbers reflect built configs: HIGH_D=1, HIGH_P=2, LOW_D=3, LOW_P=4
set "APP_SUFFIX_NUMS="
for %%c in (!CONFIGS!) do (
    if /i "%%c"=="HIGH_D" ( if "!APP_SUFFIX_NUMS!"=="" (set "APP_SUFFIX_NUMS=1") else (set "APP_SUFFIX_NUMS=!APP_SUFFIX_NUMS!,1") )
    if /i "%%c"=="HIGH_P" ( if "!APP_SUFFIX_NUMS!"=="" (set "APP_SUFFIX_NUMS=2") else (set "APP_SUFFIX_NUMS=!APP_SUFFIX_NUMS!,2") )
    if /i "%%c"=="LOW_D"  ( if "!APP_SUFFIX_NUMS!"=="" (set "APP_SUFFIX_NUMS=3") else (set "APP_SUFFIX_NUMS=!APP_SUFFIX_NUMS!,3") )
    if /i "%%c"=="LOW_P"  ( if "!APP_SUFFIX_NUMS!"=="" (set "APP_SUFFIX_NUMS=4") else (set "APP_SUFFIX_NUMS=!APP_SUFFIX_NUMS!,4") )
)
if not "!APP_SUFFIX_NUMS!"=="" set "APP_SUFFIX=(!APP_SUFFIX_NUMS!)"

set "NAME_SOURCE=HIGH_D"
REM =======================================================

REM Determine script directory: try %~dp0 first, fallback to relative path
set "SCRIPT_DIR=%~dp0"
if not exist "%SCRIPT_DIR%%NAME_SOURCE%\merge_config.json" (
    set "SCRIPT_DIR=%CD%\Tools\build_script\"
)
cd /d "%SCRIPT_DIR%"
REM Put System32 first so certutil/find are the Windows ones (avoid GNU tools from Git Bash PATH)
set "PATH=%SystemRoot%\System32;%PATH%"

REM ==================== Read unified folder name ====================
set "CONFIG_JSON=%SCRIPT_DIR%%NAME_SOURCE%\merge_config.json"
if not exist "%CONFIG_JSON%" (
    echo [ERROR] Config file not found: %CONFIG_JSON%
    exit /b 1
)
for /f "tokens=1,* delims==" %%a in ('powershell -NoProfile -Command "$j = Get-Content -Raw '%CONFIG_JSON%' | ConvertFrom-Json; $j.PSObject.Properties | ForEach-Object { '{0}={1}' -f $_.Name, $_.Value }"') do (
    set "CFG_%%a=%%b"
)
for %%v in (ProjectName AppVersion BootVersion) do (
    if "!CFG_%%v!"=="" (
        echo [ERROR] Missing or empty config item in %CONFIG_JSON%: %%v
        exit /b 1
    )
)
set "APP_VX=%CFG_AppVersion:~0,-1%x%APP_SUFFIX%"
set "BOOT_VX=%CFG_BootVersion:~0,-1%x"
for /f %%a in ('powershell -NoProfile -Command "(Get-Date).ToString('yyMMddHHmm')"') do set "TIMESTAMP=%%a"
set "UNIFIED_DIR=%CFG_ProjectName%_APP%APP_VX%_BOOT%BOOT_VX%_%TIMESTAMP%"

REM ==================== Run build_all_and_merge in each config folder ====================
for %%d in (%CONFIGS%) do (
    if not exist "%%d\build_all_and_merge.bat" (
        echo [ERROR] build_all_and_merge.bat not found in %%d
        exit /b 1
    )
    echo.
    echo [INFO] ============================================
    echo [INFO]   Merging config: %%d
    echo [INFO] ============================================
    cmd /c "%%d\build_all_and_merge.bat"
    if errorlevel 1 (
        echo [ERROR] %%d merge failed, abort.
        exit /b 1
    )
)

REM ==================== Collect outputs into unified folder ====================
echo.
echo [INFO] Collecting outputs into %UNIFIED_DIR%\

REM Create top-level category directories
for %%c in (Burn Debug Doc Sig) do (
    if not exist "!UNIFIED_DIR!\%%c" mkdir "!UNIFIED_DIR!\%%c"
    if !errorlevel! neq 0 (
        echo [ERROR] Failed to create folder !UNIFIED_DIR!\%%c
        exit /b 1
    )
)

REM Create MCM subdirectories under Burn, Debug, Sig for selected configs (Doc has no subs)
for %%d in (%CONFIGS%) do (
    set "MCM_NAME="
    if /i "%%d"=="HIGH_D" set "MCM_NAME=MCM_D_H"
    if /i "%%d"=="HIGH_P" set "MCM_NAME=MCM_P_H"
    if /i "%%d"=="LOW_D" set "MCM_NAME=MCM_D_L"
    if /i "%%d"=="LOW_P" set "MCM_NAME=MCM_P_L"
    for %%c in (Burn Debug Sig) do (
        if not exist "!UNIFIED_DIR!\%%c\!MCM_NAME!" mkdir "!UNIFIED_DIR!\%%c\!MCM_NAME!"
    )
)

REM Copy Doc files: non-xlsx unconditionally, xlsx only for selected configs
echo [INFO] Copying Doc files to !UNIFIED_DIR!\Doc\
if exist "%SCRIPT_DIR%Doc" (
    for %%f in ("%SCRIPT_DIR%Doc\*") do (
        set "SKIP=0"
        for %%p in (HIGH_D HIGH_P LOW_D LOW_P) do (
            echo %%~nxf | findstr /i "PISCES_%%p" >nul && set "SKIP=1"
        )
        if "!SKIP!"=="0" copy /y "%%f" "!UNIFIED_DIR!\Doc\" >nul
    )
    for %%d in (%CONFIGS%) do (
        for %%f in ("%SCRIPT_DIR%Doc\PISCES_%%d*.xlsx") do (
            copy /y "%%f" "!UNIFIED_DIR!\Doc\" >nul
            echo [INFO]   %%~nxf
        )
    )
)

for %%d in (%CONFIGS%) do (
    REM Map config name to MCM name
    set "MCM_NAME="
    if /i "%%d"=="HIGH_D" set "MCM_NAME=MCM_D_H"
    if /i "%%d"=="HIGH_P" set "MCM_NAME=MCM_P_H"
    if /i "%%d"=="LOW_D" set "MCM_NAME=MCM_D_L"
    if /i "%%d"=="LOW_P" set "MCM_NAME=MCM_P_L"

    REM Pick the newest *_BURN folder in the config dir
    set "GEN_DIR="
    for /f "delims=" %%g in ('dir /b /ad /o-d "%%d\*_BURN" 2^>nul') do (
        if not defined GEN_DIR set "GEN_DIR=%%g"
    )
    if not defined GEN_DIR (
        echo [ERROR] No *_BURN output folder found in %%d
        exit /b 1
    )

    REM Sig: move APP/BOOT/DRIVER hex files to Sig\MCM_NAME\
    for %%f in ("%%d\!GEN_DIR!\* APP.hex" "%%d\!GEN_DIR!\* BOOT.hex" "%%d\!GEN_DIR!\* DRIVER.hex") do (
        if exist "%%f" move /y "%%f" "!UNIFIED_DIR!\Sig\!MCM_NAME!\" >nul
    )

    REM Burn: move only the merged hex + md5 to Burn\MCM_NAME\
    echo [INFO] %%d -^> Burn\!MCM_NAME!\
    move /y "%%d\!GEN_DIR!\!GEN_DIR!.hex" "!UNIFIED_DIR!\Burn\!MCM_NAME!\" >nul
    if exist "%%d\!GEN_DIR!\!GEN_DIR!.hex.md5" move /y "%%d\!GEN_DIR!\!GEN_DIR!.hex.md5" "!UNIFIED_DIR!\Burn\!MCM_NAME!\" >nul
    rmdir /s /q "%%d\!GEN_DIR!" 2>nul

    REM Debug: copy .elf and .map files
    if exist "%%d\*.elf" copy "%%d\*.elf" "!UNIFIED_DIR!\Debug\!MCM_NAME!\" >nul
    if exist "%%d\*.map" copy "%%d\*.map" "!UNIFIED_DIR!\Debug\!MCM_NAME!\" >nul
)

REM ==================== Clean remaining build artifacts ====================
echo.
echo [INFO] Cleaning remaining build artifacts from config folders ...
call "%SCRIPT_DIR%\clean.bat"
if errorlevel 1 (
    echo [WARN] Clean script returned error, continuing anyway...
)

echo.
echo ========================================
echo   Merged configs: %CONFIGS%
echo   Output folder: %UNIFIED_DIR%\
echo     Burn\  - merged hex + md5
echo     Debug\ - .elf / .map files
echo     Doc\   - documentation
echo     Sig\   - app/boot/driver hex files
echo ========================================
endlocal