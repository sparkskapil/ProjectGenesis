include "commondirs.lua"

IncludeDirs = {}
IncludeDirs["sdl2"] = "%{ExternFolder}/sdl2/include"
IncludeDirs["spdlog"] = "%{ExternFolder}/spdlog/include"
IncludeDirs["libassert"] = "%{ExternFolder}/libassert/include"
IncludeDirs["glm"] = "%{ExternFolder}/glm"
IncludeDirs["VulkanSDK"]= "%{VulkanSDK}/Include"

LibraryDirs = {}
LibraryDirs["sdl2"] = "%{ExternFolder}/sdl2/lib/x64"
LibraryDirs["libassert"] = "%{ExternFolder}/libassert/%{cfg.buildcfg}"
LibraryDirs["VulkanSDK"] = "%{VulkanSDK}/Lib"

Library = {}
Library["sdl2"] = "SDL2.lib"
Library["libassert"] = "assert.lib; dbghelp.lib"
Library["Vulkan"] = "vulkan-1.lib"
Library["VulkanUtils"] = "VkLayer_utils.lib"

Defines = {}
Defines["sdl2"] = "SDL_MAIN_HANDLED"

PostBuildEvent = {}
PostBuildEvent["sdl2"] = "{COPY} %{LibraryDirs.sdl2}/SDL2.dll %{cfg.targetdir}" 