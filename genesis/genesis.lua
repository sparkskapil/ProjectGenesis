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
	cppdialect "C++latest"
	targetdir "%{OutputFolder}/%{cfg.buildcfg}-%{cfg.platform}"
	location "%{ProjectGenFolder}/%{prj.name}"
	debugdir "%{OutputFolder}/%{cfg.buildcfg}-%{cfg.platform}"
	
	files 
	{ 
		"%{CodeFolder}/**.h", 
		"%{CodeFolder}/**.cpp" 
	}
	
	includedirs
	{
		"%{IncludeDirs.sdl2}",
		"%{IncludeDirs.spdlog}",
		"%{IncludeDirs.libassert}",
		"%{IncludeDirs.glm}",
		"%{IncludeDirs.VulkanSDK}",
	}

	libdirs
	{
		"%{LibraryDirs.sdl2}",
		"%{LibraryDirs.libassert}",
		"%{LibraryDirs.VulkanSDK}",
	}

	defines
	{
		"%{Defines.sdl2}",
	}
	
	links
	{
		"%{Library.sdl2}",
		"%{Library.libassert}",
		"%{Library.Vulkan}",
		"%{Library.VulkanUtils}",
	}

	postbuildcommands
	{
		"%{PostBuildEvent.sdl2}",
	}

	
	filter "system:windows"
		systemversion "latest"
	
	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"

	group "Logger"
		files {"%{CodeFolder}/Logger/*.h", "%{CodeFolder}/Logger/*.cpp"}