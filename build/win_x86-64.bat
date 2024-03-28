@echo off

SET ECHO_NEWLINE=echo.

SET COMPILER_PATH=clang
SET APP_PATH="bin\win_x86-64.exe"
SET LIB_DIR="..\lib"
SET MAIN_PATH="..\main.c"
SET SOURCE_FILES=%LIB_DIR%\*.c

:_COMPILE

%COMPILER_PATH% -I%LIB_DIR% %SOURCE_FILES% %MAIN_PATH% -o %APP_PATH%

%ECHO_NEWLINE%
echo Compilation end
%ECHO_NEWLINE%

%APP_PATH%

%ECHO_NEWLINE%
echo press any key to recompile
pause
cls
goto _COMPILE
