@echo off
echo Generating Projects
SET "WORKSPACE_ROOT=%cd%"
SET PREMAKE_EXE=%WORKSPACE_ROOT%\tools\premake\premake5.exe

"%PREMAKE_EXE%" vs2019 --file=genesis/genesis.lua