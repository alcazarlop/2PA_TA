
@ECHO OFF
@cls
del *.obj *.pdb *.ilk *.exe

@echo COMPILER
cl /nologo /Zi /EHs /MDd /W4 -D_CRT_SECURE_NO_WARNINGS -I ..\include -I ..\deps\sdl2\include -I ..\deps\imgui\ -I ..\deps\sdl2_image\include -I ..\deps\math_lib\include\  /c ..\src\main.cc
cl /nologo /Zi /EHs /MDd /W4 -D_CRT_SECURE_NO_WARNINGS -I ..\include -I ..\deps\sdl2\include -I ..\deps\imgui\ -I ..\deps\sdl2_image\include -I ..\deps\math_lib\include\  /c ..\src\game_manager.cc
cl /nologo /Zi /EHs /MDd /W4 -D_CRT_SECURE_NO_WARNINGS -I ..\include -I ..\deps\sdl2\include -I ..\deps\imgui\ -I ..\deps\sdl2_image\include -I ..\deps\math_lib\include\  /c ..\src\game_controller.cc
cl /nologo /Zi /EHs /MDd /W4 -D_CRT_SECURE_NO_WARNINGS -I ..\include -I ..\deps\sdl2\include -I ..\deps\imgui\ -I ..\deps\sdl2_image\include -I ..\deps\math_lib\include\  /c ..\src\entity.cc
cl /nologo /Zi /EHs /MDd /W4 -D_CRT_SECURE_NO_WARNINGS -I ..\include -I ..\deps\sdl2\include -I ..\deps\imgui\ -I ..\deps\sdl2_image\include -I ..\deps\math_lib\include\  /c ..\src\path.cc
cl /nologo /Zi /EHs /MDd /W4 -D_CRT_SECURE_NO_WARNINGS -I ..\include -I ..\deps\sdl2\include -I ..\deps\imgui\ -I ..\deps\sdl2_image\include -I ..\deps\math_lib\include\  /c ..\src\sprite.cc
cl /nologo /Zi /EHs /MDd /W4 -D_CRT_SECURE_NO_WARNINGS -I ..\include -I ..\deps\sdl2\include -I ..\deps\imgui\ -I ..\deps\sdl2_image\include -I ..\deps\math_lib\include\  /c ..\src\texture.cc
cl /nologo /Zi /EHs /MDd /W4 -D_CRT_SECURE_NO_WARNINGS -I ..\include -I ..\deps\sdl2\include -I ..\deps\imgui\ -I ..\deps\sdl2_image\include -I ..\deps\math_lib\include\  /c ..\src\particle.cc
cl /nologo /Zi /EHs /MDd /W4 -D_CRT_SECURE_NO_WARNINGS -I ..\include -I ..\deps\sdl2\include -I ..\deps\imgui\ -I ..\deps\sdl2_image\include -I ..\deps\math_lib\include\  /c ..\src\emitter.cc
cl /nologo /Zi /EHs /MDd /W4 -D_CRT_SECURE_NO_WARNINGS -I ..\include -I ..\deps\sdl2\include -I ..\deps\imgui\ -I ..\deps\sdl2_image\include -I ..\deps\math_lib\include\  /c ..\src\emitter_pool.cc
cl /nologo /Zi /EHs /MDd /W4 -D_CRT_SECURE_NO_WARNINGS -I ..\include -I ..\deps\sdl2\include -I ..\deps\imgui\ -I ..\deps\sdl2_image\include -I ..\deps\math_lib\include\  /c ..\src\imgui_controller.cc
cl /nologo /Zi /EHs /MDd /W4 -D_CRT_SECURE_NO_WARNINGS -I ..\include -I ..\deps\sdl2\include -I ..\deps\imgui\ -I ..\deps\sdl2_image\include -I ..\deps\math_lib\include\  /c ..\src\cube.cc

@echo LINKER
cl /nologo /Zi /EHs /MDd /W4 /Fe:..\bin\main_d.exe *.obj /link /SUBSYSTEM:CONSOLE ..\deps\sdl2\lib\x86\SDL2.lib ..\deps\sdl2\lib\x86\SDL2main.lib ..\deps\imgui\lib\imgui_d.lib ..\deps\sdl2_image\lib\x86\SDL2_image.lib opengl32.lib shell32.lib user32.lib gdi32.lib
