@ECHO OFF
@cls
del *.obj *.pdb *.ilk *.exe

@echo COMPILER
cl /nologo /O2 /EHs /MD /GR- -D_CRT_SECURE_NO_WARNINGS -I ..\include -I ..\deps\sdl2\include -I ..\deps\imgui\ -I ..\deps\sdl2_image\include -I ..\deps\math_lib\include\ -I ..\deps\chipmunk\include /c ..\src\main.cc
cl /nologo /O2 /EHs /MD /GR- -D_CRT_SECURE_NO_WARNINGS -I ..\include -I ..\deps\sdl2\include -I ..\deps\imgui\ -I ..\deps\sdl2_image\include -I ..\deps\math_lib\include\ -I ..\deps\chipmunk\include /c ..\src\game_manager.cc
cl /nologo /O2 /EHs /MD /GR- -D_CRT_SECURE_NO_WARNINGS -I ..\include -I ..\deps\sdl2\include -I ..\deps\imgui\ -I ..\deps\sdl2_image\include -I ..\deps\math_lib\include\ -I ..\deps\chipmunk\include /c ..\src\game_controller.cc
cl /nologo /O2 /EHs /MD /GR- -D_CRT_SECURE_NO_WARNINGS -I ..\include -I ..\deps\sdl2\include -I ..\deps\imgui\ -I ..\deps\sdl2_image\include -I ..\deps\math_lib\include\ -I ..\deps\chipmunk\include /c ..\src\window_controller.cc
cl /nologo /O2 /EHs /MD /GR- -D_CRT_SECURE_NO_WARNINGS -I ..\include -I ..\deps\sdl2\include -I ..\deps\imgui\ -I ..\deps\sdl2_image\include -I ..\deps\math_lib\include\ -I ..\deps\chipmunk\include /c ..\src\entity.cc
cl /nologo /O2 /EHs /MD /GR- -D_CRT_SECURE_NO_WARNINGS -I ..\include -I ..\deps\sdl2\include -I ..\deps\imgui\ -I ..\deps\sdl2_image\include -I ..\deps\math_lib\include\ -I ..\deps\chipmunk\include /c ..\src\path.cc
cl /nologo /O2 /EHs /MD /GR- -D_CRT_SECURE_NO_WARNINGS -I ..\include -I ..\deps\sdl2\include -I ..\deps\imgui\ -I ..\deps\sdl2_image\include -I ..\deps\math_lib\include\ -I ..\deps\chipmunk\include /c ..\src\sprite.cc
cl /nologo /O2 /EHs /MD /GR- -D_CRT_SECURE_NO_WARNINGS -I ..\include -I ..\deps\sdl2\include -I ..\deps\imgui\ -I ..\deps\sdl2_image\include -I ..\deps\math_lib\include\ -I ..\deps\chipmunk\include /c ..\src\texture.cc
cl /nologo /O2 /EHs /MD /GR- -D_CRT_SECURE_NO_WARNINGS -I ..\include -I ..\deps\sdl2\include -I ..\deps\imgui\ -I ..\deps\sdl2_image\include -I ..\deps\math_lib\include\ -I ..\deps\chipmunk\include /c ..\src\collider2D.cc
cl /nologo /O2 /EHs /MD /GR- -D_CRT_SECURE_NO_WARNINGS -I ..\include -I ..\deps\sdl2\include -I ..\deps\imgui\ -I ..\deps\sdl2_image\include -I ..\deps\math_lib\include\ -I ..\deps\chipmunk\include /c ..\src\particle.cc
cl /nologo /O2 /EHs /MD /GR- -D_CRT_SECURE_NO_WARNINGS -I ..\include -I ..\deps\sdl2\include -I ..\deps\imgui\ -I ..\deps\sdl2_image\include -I ..\deps\math_lib\include\ -I ..\deps\chipmunk\include /c ..\src\emitter.cc
cl /nologo /O2 /EHs /MD /GR- -D_CRT_SECURE_NO_WARNINGS -I ..\include -I ..\deps\sdl2\include -I ..\deps\imgui\ -I ..\deps\sdl2_image\include -I ..\deps\math_lib\include\ -I ..\deps\chipmunk\include /c ..\src\emitter_pool.cc
cl /nologo /O2 /EHs /MD /GR- -D_CRT_SECURE_NO_WARNINGS -I ..\include -I ..\deps\sdl2\include -I ..\deps\imgui\ -I ..\deps\sdl2_image\include -I ..\deps\math_lib\include\ -I ..\deps\chipmunk\include /c ..\src\imgui_controller.cc

@echo LINKER
cl /nologo /O2 /EHs /MD /GR- /Fe:..\bin\main.exe *.obj /link /SUBSYSTEM:CONSOLE ..\deps\sdl2\lib\x86\SDL2.lib ..\deps\sdl2\lib\x86\SDL2main.lib ..\deps\imgui\lib\imgui_d.lib ..\deps\math_lib\lib\math_d.lib ..\deps\sdl2_image\lib\x86\SDL2_image.lib ..\deps\chipmunk\lib\chipmunk.lib opengl32.lib shell32.lib user32.lib gdi32.lib
