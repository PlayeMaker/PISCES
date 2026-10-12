@echo off
setlocal enabledelayedexpansion

REM ==================== Configuration ====================
REM Leave empty to use hexview from PATH, or set full path, e.g.:
REM set "HEXVIEW=D:\Tools\HexView\hexview.exe"
set "HEXVIEW=hexview.exe"
REM HexView occasionally fails to initialize in batch mode; retry up to this many times
set "MAXTRY=3"
REM /G in every HexView call suppresses the disclaimer dialog (required for non-interactive CI runs)

set "OUTPUT_HEX=PISCES.hex"
set "PATCH_HEX=_patch.hex"
set "ERRLOG=hexview_err.log"
REM JSON config for the versioned output filename, format:
REM ProjectName_Config_AppVersion_BootVersion_Date_GITxxxx_MD5xxxxxxx_ChipName_BURN.hex
set "CONFIG_JSON=%~dp0merge_config.json"
REM ---- Patch data written to fixed addresses (merged last, always wins) ----
REM Each entry: full 8-hex-digit address + hex data string (1-16 bytes, even length)
set "PATCH_COUNT=3"
set "PATCH_ADDR_1=0200FC10"
set "PATCH_DATA_1=55555555"
set "PATCH_ADDR_2=0200F600"
set "PATCH_DATA_2=55555555"
set "PATCH_ADDR_3=0200FA18"
set "PATCH_DATA_3=A5A5A5A5"

REM ---- BL + SApp merge (output: FBL_SApp_merged.hex) ----
set "SAPP_FBL=AZ260123_FBL.hex"
set "SAPP_APP=AZ260123_SApp.hex"
set "SAPP_BIN=_fbl_mod.bin"
set "SAPP_HEX=_fbl_mod.hex"
set "SAPP_PATCH=_sapp_patch.hex"
set "SAPP_OUT=FBL_SApp_merged.hex"
REM Patch values written to fixed addresses (merged last, always win)
REM Constraint: both records must be 4 bytes and in segment 0x0002
REM (the base record :020000040002F8 in Step 2 is fixed accordingly)
set "SAPP_ADDR_1=0002D000"
set "SAPP_DATA_1=00030000"
set "SAPP_ADDR_2=0002D004"
REM SAPP_DATA_2 is set in Step 2 to the BIN file size (big-endian)
REM =======================================================

cd /d "%~dp0"
REM Put System32 first so certutil/find are the Windows ones (avoid GNU tools from Git Bash PATH)
set "PATH=%SystemRoot%\System32;%PATH%"

echo [INFO] Checking build scripts...
for %%b in (build_app.bat build_boot.bat build_bootM.bat build_sAPP.bat build_flashDriver.bat) do (
    if not exist "%%b" (
        echo [ERROR] Build script not found: %%b
        exit /b 1
    )
)

REM ==================== Build all projects ====================
for %%b in (build_app.bat build_boot.bat build_bootM.bat build_sAPP.bat build_flashDriver.bat) do (
    echo.
    echo [INFO] ========== Running %%b ==========
    call "%%b"
    if errorlevel 1 (
        echo [ERROR] %%b failed, abort merge.
        exit /b 1
    )
)

echo.
echo [INFO] Checking input hex files...
for %%f in (AZ260123_FBL.hex YTM32B1MD2X.hex AZ260123_FBLM.hex AZ260123_SApp.hex AZ260123_flashdriver.hex) do (
    if not exist "%%f" (
        echo [ERROR] Input file not found: %%f
        exit /b 1
    )
)

REM ==================== Part 1: merge BL + SApp ====================
REM  Step 1: FBL gaps filled with 0xFF, start 0x4000 -> 0x30000
REM  Step 2: record data length, CRC-32 written by HexView /CS9
REM  Step 3: merge, fill all gaps with 0xFF, and patch:
REM    0x0002D000-0x0002D003 = 0x00030000      (big-endian)
REM    0x0002D004-0x0002D007 = data length    (big-endian)
REM    0x0002D010-0x0002D013 = CRC-32         (big-endian, by /CS9)
echo.
echo [INFO] ========== Merging BL + SApp ==========

REM ---- Step 1a: shift FBL +0x2C000, fill 0xFF, export BIN to get length ----
set "TRY=0"
:S1A
set /a TRY+=1
"%HEXVIEW%" /s /G /E:%ERRLOG% /MO:"%SAPP_FBL%;0x2C000" /AF:0xFF /FA /XB -o "%SAPP_BIN%"
if not errorlevel 1 goto S1A_OK
if !TRY! LSS %MAXTRY% (ping -n 2 127.0.0.1 >nul & goto S1A)
echo [ERROR] HexView failed after retries, errorlevel %errorlevel%, see %ERRLOG%
exit /b %errorlevel%
:S1A_OK

REM ---- Step 1b: same, plus CRC-32 (method 9) placed at 0x2D010, export HEX ----
set "TRY=0"
:S1B
set /a TRY+=1
"%HEXVIEW%" /s /G /E:%ERRLOG% /MO:"%SAPP_FBL%;0x2C000" /AF:0xFF /FA /CS9:@0x2D010 /XI -o "%SAPP_HEX%"
if not errorlevel 1 goto S1B_OK
if !TRY! LSS %MAXTRY% (ping -n 2 127.0.0.1 >nul & goto S1B)
echo [ERROR] HexView failed after retries, errorlevel %errorlevel%, see %ERRLOG%
exit /b %errorlevel%
:S1B_OK

REM ---- Step 2: build SApp patch hex; SAPP_DATA_2 = size of the BIN file ----
for %%F in ("%SAPP_BIN%") do set LEN=%%~zF
set /a "b3=(LEN>>24)&255, b2=(LEN>>16)&255, b1=(LEN>>8)&255, b0=LEN&255"
set /a "c3=0x%SAPP_DATA_1:~0,2%, c2=0x%SAPP_DATA_1:~2,2%, c1=0x%SAPP_DATA_1:~4,2%, c0=0x%SAPP_DATA_1:~6,2%"
set /a "chk1=(256-((0x04+0x%SAPP_ADDR_1:~4,2%+0x%SAPP_ADDR_1:~6,2%+c3+c2+c1+c0)%%256))%%256"
set /a "chk2=(256-((0x04+0x%SAPP_ADDR_2:~4,2%+0x%SAPP_ADDR_2:~6,2%+b3+b2+b1+b0)%%256))%%256"
set "H=0123456789ABCDEF"
set "P1HEX="
set "P2HEX="
for %%v in (%c3% %c2% %c1% %c0% %chk1%) do (
    set /a "hi=%%v>>4, lo=%%v&15"
    for %%i in (!hi!) do for %%j in (!lo!) do set "P1HEX=!P1HEX!!H:~%%i,1!!H:~%%j,1!"
)
for %%v in (%b3% %b2% %b1% %b0% %chk2%) do (
    set /a "hi=%%v>>4, lo=%%v&15"
    for %%i in (!hi!) do for %%j in (!lo!) do set "P2HEX=!P2HEX!!H:~%%i,1!!H:~%%j,1!"
)
> %SAPP_PATCH% echo :020000040002F8
>> %SAPP_PATCH% echo :04%SAPP_ADDR_1:~4,4%00!P1HEX!
>> %SAPP_PATCH% echo :04%SAPP_ADDR_2:~4,4%00!P2HEX!
>> %SAPP_PATCH% echo :00000001FF

REM ---- Step 3: merge app + modified FBL + patch, fill gaps with 0xFF ----
set "TRY=0"
:S3
set /a TRY+=1
"%HEXVIEW%" /s /G /E:%ERRLOG% "%SAPP_APP%" /MO:"%SAPP_HEX%+%SAPP_PATCH%" /AF:0xFF /FA /XI -o "%SAPP_OUT%"
if not errorlevel 1 goto S3_OK
if !TRY! LSS %MAXTRY% (ping -n 2 127.0.0.1 >nul & goto S3)
echo [ERROR] HexView failed after retries, errorlevel %errorlevel%, see %ERRLOG%
exit /b %errorlevel%
:S3_OK

del "%SAPP_BIN%" "%SAPP_HEX%" "%SAPP_PATCH%" _fbl_mod.prm
echo [INFO] SApp merge done: %SAPP_OUT%  (length=0x!P2HEX:~0,8!)

REM ==================== Part 2: merge BLM + BL + APP ====================
echo.
echo [INFO] ========== Merging BLM + BL + APP ==========

REM ---- Generate patch hex file (Intel HEX) from PATCH_x config above ----
set "CURBASE="
type nul > "%PATCH_HEX%"
for /l %%n in (1,1,%PATCH_COUNT%) do (
    call :GENPATCH "!PATCH_ADDR_%%n!" "!PATCH_DATA_%%n!" || exit /b 1
)
>> "%PATCH_HEX%" echo :00000001FF

REM ---- /MO = opaque merge: later files overwrite existing data. ----
REM ---- Patch file is merged last, so the fixed values always win. ----
set "TRY=0"
:MERGE
set /a TRY+=1
"%HEXVIEW%" /s /G /E:%ERRLOG% AZ260123_FBL.hex /MO:"YTM32B1MD2X.hex+AZ260123_FBLM.hex+%PATCH_HEX%" /XI -o "%OUTPUT_HEX%"
if not errorlevel 1 goto MERGE_OK
if !TRY! LSS %MAXTRY% (ping -n 2 127.0.0.1 >nul & goto MERGE)
echo [ERROR] HexView failed after retries, errorlevel %errorlevel%, see %ERRLOG%
exit /b %errorlevel%
:MERGE_OK

del "%PATCH_HEX%"

REM ==================== Read JSON config ====================
echo [INFO] Reading config: %CONFIG_JSON%
if not exist "%CONFIG_JSON%" (
    echo [ERROR] Config file not found: %CONFIG_JSON%
    exit /b 1
)
for /f "tokens=1,* delims==" %%a in ('powershell -NoProfile -Command "$j = Get-Content -Raw '%CONFIG_JSON%' | ConvertFrom-Json; $j.PSObject.Properties | ForEach-Object { '{0}={1}' -f $_.Name, $_.Value }"') do (
    set "CFG_%%a=%%b"
)
for %%v in (ProjectName Config AppVersion BootVersion ChipName AppSoftVersion BootSoftVersion FlashDriverSoftVersion) do (
    if "!CFG_%%v!"=="" (
        echo [ERROR] Missing or empty config item: %%v
        exit /b 1
    )
)

REM ==================== Auto values: date / git hash / MD5 ====================
for /f %%a in ('powershell -NoProfile -Command "(Get-Date).ToString('yyMMdd')"') do set "TIMESTAMP=%%a"

set "GIT_TAG=GIT00000000"
for /f %%a in ('git rev-parse --short^=8 HEAD 2^>nul') do set "GIT_TAG=GIT%%a"

set "MD5_HASH="
for /f "tokens=1 delims= " %%H in ('certutil -hashfile "%OUTPUT_HEX%" MD5 ^| find /v ":" ^| find /v "MD5"') do set "MD5_HASH=%%H"
if not defined MD5_HASH (
    echo [ERROR] MD5 calculation failed for %OUTPUT_HEX%
    exit /b 1
)

REM ==================== Generate versioned output ====================
set "NEW_NAME=%CFG_ProjectName%_%CFG_Config%_APP%CFG_AppVersion%_BOOT%CFG_BootVersion%_%TIMESTAMP%_%GIT_TAG%_MD5%MD5_HASH:~0,7%_%CFG_ChipName%_BURN"
REM Deliverable names based on AppSoftVersion / BootSoftVersion / FlashDriverSoftVersion
set "APP_NAME=%CFG_AppSoftVersion% APP"
set "BOOT_NAME=%CFG_BootSoftVersion% BOOT"
set "DRIVER_NAME=%CFG_FlashDriverSoftVersion% DRIVER"
set "OUT_DIR=%NEW_NAME%"

if not exist "%OUT_DIR%" mkdir "%OUT_DIR%"
if %errorlevel% neq 0 (
    echo [ERROR] Failed to create folder %OUT_DIR%
    exit /b 1
)

copy "%OUTPUT_HEX%" "%OUT_DIR%\%NEW_NAME%.hex" >nul
if %errorlevel% neq 0 (
    echo [ERROR] Failed to generate %OUT_DIR%\%NEW_NAME%.hex
    exit /b 1
)

echo %MD5_HASH%> "%OUT_DIR%\%NEW_NAME%.hex.md5"
if %errorlevel% neq 0 (
    echo [ERROR] Failed to generate %OUT_DIR%\%NEW_NAME%.hex.md5
    exit /b 1
)

copy "YTM32B1MD2X.hex" "%OUT_DIR%\%APP_NAME%.hex" >nul
if %errorlevel% neq 0 (
    echo [ERROR] Failed to copy YTM32B1MD2X.hex to %OUT_DIR%
    exit /b 1
)

copy "%SAPP_OUT%" "%OUT_DIR%\%BOOT_NAME%.hex" >nul
if %errorlevel% neq 0 (
    echo [ERROR] Failed to copy %SAPP_OUT% to %OUT_DIR%
    exit /b 1
)

copy "AZ260123_flashdriver.hex" "%OUT_DIR%\%DRIVER_NAME%.hex" >nul
if %errorlevel% neq 0 (
    echo [ERROR] Failed to copy AZ260123_flashdriver.hex to %OUT_DIR%
    exit /b 1
)

echo.
echo ========================================
echo   Merge finished.
echo   Output: %OUTPUT_HEX%
echo   Versioned: %OUT_DIR%\%NEW_NAME%.hex
echo   App hex:   %OUT_DIR%\%APP_NAME%.hex
echo   Boot hex:  %OUT_DIR%\%BOOT_NAME%.hex
echo   Driver:    %OUT_DIR%\%DRIVER_NAME%.hex
echo ========================================
endlocal
exit /b 0

REM ==================== Subroutines ====================
:GENPATCH
REM Build one Intel HEX data record. %1 = 8-hex-digit address, %2 = hex data string
set "P_ADDR=%~1"
set "P_DATA=%~2"
set "P_LEN=0"
:GP_LEN
if not "!P_DATA:~%P_LEN%,1!"=="" (set /a P_LEN+=1 & goto GP_LEN)
set /a "P_N=P_LEN/2"
set /a "P_ODD=P_LEN%%2"
if %P_N%==0 (echo [ERROR] Empty patch data for address %P_ADDR%& exit /b 1)
if %P_ODD% NEQ 0 (echo [ERROR] Odd hex data length for address %P_ADDR%& exit /b 1)
if %P_N% GTR 16 (echo [ERROR] Patch data longer than 16 bytes at %P_ADDR%, split into multiple entries& exit /b 1)
if not "%P_ADDR:~8,1%"=="" (echo [ERROR] Bad patch address '%P_ADDR%', need exactly 8 hex digits& exit /b 1)
if "%P_ADDR:~7,1%"=="" (echo [ERROR] Bad patch address '%P_ADDR%', need exactly 8 hex digits& exit /b 1)
REM Extended linear address record, emitted once per 64K segment
set "P_BASE=%P_ADDR:~0,4%"
set "P_OFFS=%P_ADDR:~4,4%"
if /i not "%P_BASE%"=="%CURBASE%" (
    set "CURBASE=%P_BASE%"
    set /a "P_CK=(0x100-((6+0x%P_BASE:~0,2%+0x%P_BASE:~2,2%)%%0x100))%%0x100"
    call :TOHEX !P_CK! P_CKS
    >> "%PATCH_HEX%" echo :02000004%P_BASE%!P_CKS!
)
REM Data record checksum: two's complement of (len + addr hi + addr lo + type + data)
set /a "P_SUM=(%P_N%+0x%P_OFFS:~0,2%+0x%P_OFFS:~2,2%)%%0x100"
set "P_IDX=0"
:GP_SUM
if %P_IDX% LSS %P_LEN% (
    set /a "P_SUM=(P_SUM+0x!P_DATA:~%P_IDX%,2!)%%0x100"
    set /a P_IDX+=2
    goto GP_SUM
)
set /a "P_CK=(0x100-P_SUM)%%0x100"
call :TOHEX %P_CK% P_CKS
call :TOHEX %P_N% P_NS
>> "%PATCH_HEX%" echo :%P_NS%%P_OFFS%00%P_DATA%%P_CKS%
exit /b 0

:TOHEX
REM %1 = decimal 0-255, sets %2 to 2-digit uppercase hex
set "T_H=0123456789ABCDEF"
set /a "T_HI=%1>>4, T_LO=%1&15"
set "%~2=!T_H:~%T_HI%,1!!T_H:~%T_LO%,1!"
exit /b 0
