-- premake5.lua
workspace "framework"
	configurations { "Debug", "Release" }
	platforms { "Win64" }
	location "../#projects"

filter { "platforms:Win64" }
	system "Windows"
	architecture "x86_64"

project "genesis"
	kind "ConsoleApp"
	language "C++"
	targetdir "../#build/%{cfg.buildcfg}-%{cfg.platform}"
	location "../#projects/genesis"

	files { "../code/**.h", "../code/**.cpp" }

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"