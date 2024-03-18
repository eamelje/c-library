@echo off

SET COMPILER_PATH=clang
SET APP_PATH="bin\win64.exe"
SET LIB_DIR="..\lib"
SET MAIN_PATH="..\main.c"

%COMPILER_PATH% -I%LIB_DIR% %LIB_DIR%\*.c %MAIN_PATH% -o %APP_PATH%

echo(
echo Compilation end
echo(

%APP_PATH%

echo(
pause
