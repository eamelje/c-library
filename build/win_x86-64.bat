@echo off

SET ECHO_NEWLINE=echo.

SET COMPILER_PATH=clang
SET APP_PATH="bin\win_x86-64.exe"
SET LIB_DIR="..\lib"
SET MAIN_PATH="..\main.c"

:_COMPILE

%COMPILER_PATH% -I%LIB_DIR% %LIB_DIR%\*.c %MAIN_PATH% -o %APP_PATH%

%ECHO_NEWLINE%
echo Compilation end
%ECHO_NEWLINE%

%APP_PATH%

%ECHO_NEWLINE%
pause
goto _COMPILE
