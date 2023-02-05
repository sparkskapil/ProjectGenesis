include "commondirs.lua"
include "extern.lua"

workspace "framework"
	configurations { "Debug", "Release" }
	platforms { "Win64" }
	location "%{ProjectGenFolder}"

filter { "platforms:Win64" }
	system "Windows"
	architecture "x86_64"

project "genesis"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	targetdir "%{OutputFolder}/%{cfg.buildcfg}-%{cfg.platform}"
	location "%{ProjectGenFolder}/%{prj.name}"

	files 
	{ 
		"%{CodeFolder}/**.h", 
		"%{CodeFolder}/**.cpp" 
	}
	
	includedirs
	{
		"%{IncludeDirs.sdl2}",
		"%{IncludeDirs.spdlog}",
	}

	libdirs
	{
		"%{LibraryDirs.sdl2}"
	}

	defines
	{
		"%{Defines.sdl2}"
	}
	
	links
	{
		"%{Library.sdl2}",
	}

	postbuildcommands
	{
		"%{PostBuildEvent.sdl2}"
	}

	
	filter "system:windows"
		systemversion "latest"
	
	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"
