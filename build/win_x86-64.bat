@echo off

SET COMPILER_PATH=clang
SET APP_NAME="application.exe"
SET LIB_DIR="../lib"
SET MAIN_PATH="../main.c"

%COMPILER_PATH% -I%LIB_DIR% %LIB_DIR%/*.c %MAIN_PATH% -o %APP_NAME%

echo(
echo Compilation end
echo(

pause

%APP_NAME%

echo(
pause
