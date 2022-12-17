@echo off
cls
premake5.exe vs2019
xcopy /y ".\dlls\" "..\bin\window_example\Win32_Debug\"
pause