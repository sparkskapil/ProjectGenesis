include "commondirs.lua"

IncludeDirs = {}
IncludeDirs["sdl2"] = "%{ExternFolder}/sdl2/include"
IncludeDirs["spdlog"] = "%{ExternFolder}/spdlog/include"

LibraryDirs = {}
LibraryDirs["sdl2"] = "%{ExternFolder}/sdl2/lib/x64"

Library = {}
Library["sdl2"] = "SDL2.lib"

Defines = {}
Defines["sdl2"] = "SDL_MAIN_HANDLED"

PostBuildEvent = {}
PostBuildEvent["sdl2"] = "{COPY} %{LibraryDirs.sdl2}/SDL2.dll %{cfg.targetdir}" 