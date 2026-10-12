@echo off
REM Delete generated hex/bin/elf/map files from the four config folders

cd /d "%~dp0"

set "CONFIGS=HIGH_D HIGH_P LOW_D LOW_P"

for %%d in (%CONFIGS%) do (
    if exist "%%d" (
        echo [INFO] Cleaning %%d ...
        for %%e in (hex bin elf map) do (
            del /q /f "%%d\*.%%e" >nul 2>&1
        )
    ) else (
        echo [WARN] Folder not found: %%d
    )
)

echo.
echo [INFO] Clean done.
