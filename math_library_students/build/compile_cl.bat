@ECHO OFF

del *.obj *.pdb *.ilk *.exe
@cls

cl /nologo /Zi /GR- /EHs /W3 /MDd /D_CRT_SECURE_NO_WARNINGS -I ..\math_library\include -I ..\unit_test\include /c ..\math_library\src\*.cc ..\unit_test\src\*.cc
cl /nologo /Zi /GR- /EHs /W3 /MDd /D_CRT_SECURE_NO_WARNINGS /Fe:unit_test_d.exe *.obj

