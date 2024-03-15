@echo off

SET COMPILER_PATH=clang
SET APP_NAME="apptest1234.exe"

%COMPILER_PATH% ^
-I../lib ^
../lib/*.c ^
../main.c ^
-o %APP_NAME%

echo(
echo Compilation end
echo(

%APP_NAME%

echo(
pause

