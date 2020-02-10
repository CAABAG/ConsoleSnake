--premake5.lua

workspace("Console Snake")
	configurations { "Debug", "Release" }
	location "build"

project "Console Snake"
	kind "ConsoleApp"
	language "C++"
	location "build/Console Snake"
	targetdir "build/Console Snake/bin/%{cfg.buildcfg}"
	
	files { "src/**.h", "src/**.cpp" }
	
	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"
	
	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"