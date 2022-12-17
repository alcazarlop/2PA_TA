workspace "ParticleSystem"
   language "C++"
   configurations { "Debug", "Release" }
   platforms{ "Win64", "Win32" }
   location "../build"

   filter { "platforms:Win64" }
       system "windows"
       architecture "x86_64"
   filter { "platforms:Win32" }
       system "windows"
       architecture "x86"

   flags{ "MultiProcessorCompile" }
   
  --Defines 
  defines{

     "_CRT_SECURE_NO_WARNINGS",
	 
  }
  filter { "platforms:Win64" }
  libdirs { "../deps/sdl2/lib/x64", "../deps/math_lib/lib", "../deps/chipmunk/lib", "../deps/sdl2_image/lib/x64" }

  filter { "platforms:Win32" }
  libdirs { "../deps/sdl2/lib/x86", "../deps/math_lib/lib", "../deps/chipmunk/lib", "../deps/sdl2_image/lib/x86" }
  --Source files for Windows Build
  filter { "platforms:Win32" }
  files{
     "../src/**.c*",
	 "../include/**.h*",
	 "../deps/imgui/include/**.h*",
	 "../deps/imgui/src/**.c*",
	 "../deps/sqlite3/include/**.h*",
	 "../deps/sqlite3/src/**.c*",
    "../deps/math_lib/include/**.h*",
    "../deps/math_lib/src/**.c*",
    "../deps/chipmunk/include/**.h*",
    "../deps/sdl2/include/**.h*",
    "../deps/sdl2_image/include/**.h*"
  }

  includedirs{
	 "../deps/sdl2/include/",
    "../deps/sdl2_image/include",
    "../deps/chipmunk/include",
	 "../deps/sqlite3/include/",
	 "../deps/imgui/include",
     "../include/",
     "../src/",
     "../deps/math_lib/include/"
  }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"

   projects = {

      "window_example"

   }
  
   for i, prj in ipairs(projects) do

	project (prj)
	kind "ConsoleApp"
		targetdir ("../bin/" .. prj .. "/%{cfg.platform}_%{cfg.buildcfg}")
		location ("../build/" .. prj)
		debugdir ("../bin/" .. prj .. "/%{cfg.platform}_%{cfg.buildcfg}")
		files{ "../src/**.c*" }
		links{ "SDL2", "math_d", "chipmunk", "SDL2_image", "SDL2main" }

   end
   
   
  

  