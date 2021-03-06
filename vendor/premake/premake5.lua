--premake5.lua

workspace("Console Snake")
	configurations { "Debug", "Release" }

project "Console Snake"
	kind "ConsoleApp"
	language "C++"
	targetdir "../../bin/%{cfg.buildcfg}"
	
	files { "../../src/**.h", "../../src/**.cpp" }
	
	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"
	
	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"