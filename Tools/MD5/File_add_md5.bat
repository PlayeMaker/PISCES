@echo off
REM 说明：在文件尾部添加格式化字符串，包括时间、GIT哈希前8位、MD5前七位，以及输出同名完整MD5值；
REM 20260206 V0.01 初版发布
REM 20260810 V0.02 SVN版本号改为GIT哈希（前8位）
REM ========== 参数校验 ==========
(set _=)>nul 2>&1 & @chcp 65001 >nul 2>&1

if "%~1"=="" (
    echo =======================
    echo ++ 请添加文件
	echo =======================
	exit /b 1
)

::检查文件是否存在
if not exist "%~1" (
    echo 错误: 文件 "%~1" 不存在
    exit /b 2
)

:: 获取传入的源文件路径
set "source_file=%~1"
set "source_filename=%~n1"
set "source_file_ext=%~x1"


:: 直接用PowerShell生成YYMMDD时间戳，纯英文逻辑，规避所有中文和编码问题
for /f %%a in ('powershell -Command "(Get-Date).ToString('yyMMdd')"') do set "timestamp=%%a"
::echo Timestamp(YYMMDD): %timestamp%

:: 获取GIT提交哈希（取前8位，失败则使用默认值）
set "git_hash=GIT00000000"

for /f %%a in ('git rev-parse --short^=8 HEAD 2^>nul') do (
    set "git_hash=GIT%%a"
)

:: 计算文件的MD5值
for /f "tokens=1 delims= " %%H in ('certutil -hashfile "%source_file%" MD5 ^| find /v ":" ^| find /v "MD5"') do set "MD5_HASH=%%H"
::echo MD5-HASH: %MD5_HASH%

:: 构建新文件名（处理可能为空的参数）
set "newfilename=%source_filename%_%timestamp%_%git_hash%_MD5%MD5_HASH:~0,7%%source_file_ext%

copy "%source_file%" "%newfilename%" >nul
if %errorlevel% equ %0% (    
	echo 生成文件失败 errcode %errorlevel%
    exit /b 3
)
::echo 成功生成文件: %newfilename%
    
:: 生成同名MD5记录文件
echo %MD5_HASH% > "%newfilename%.md5"
if errorlevel 1 (
	echo 生成MD5记录文件失败,errcode %errorlevel%
	exit /b 4	
)

::成功返回0
exit /b 0


