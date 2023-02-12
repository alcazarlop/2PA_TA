@ECHO OFF

del *.obj *.pdb *.ilk *.exe
@cls

cl /nologo /Zi /GR- /EHs /W3 /MDd /D_CRT_SECURE_NO_WARNINGS -I ..\deps\math_lib\include -I ..\deps\math_lib\unit_test\include /c ..\deps\math_lib\unit_test\src\*.cc
cl /nologo /Zi /GR- /EHs /W3 /MDd /D_CRT_SECURE_NO_WARNINGS /Fe:..\bin\unit_test_d.exe *.obj

