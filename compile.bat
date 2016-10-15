@echo off
:loop
cls
set loop=N
set result=0
set /p compileOption=Enter compile flag: 
if [%compileOption%] == [] set compileOption=all
echo Compiling with flag %compileOption%...
mingw32-make %compileOption%
echo Compilation Complete!
set /p loop=Compile Again [Y/N]?
if %loop% == Y set result=1
if %loop% == y set result=1
if %result% == 1 GOTO loop