#pragma once
#include <stdint.h>
#include <chrono>
#include <string>

enum class LogLevel
{
    None,
    Fatal,
    Error,
    Warn,
    Info,
    Debug,
    Verbose
};

inline const wchar_t* GetLevelName(LogLevel level)
{
    switch (level)
    {
    case LogLevel::Fatal:   return L"Fatal";
    case LogLevel::Error:   return L"Error";
    case LogLevel::Warn:    return L"Warn";
    case LogLevel::Info:    return L"Info";
    case LogLevel::Debug:   return L"Debug";
    case LogLevel::Verbose: return L"Verbose";
    default: return L"Unknown";
    }
}

struct LogEntry
{
    const wchar_t* Function;
    const wchar_t* File;
    uint32_t Line;
    std::wstring Message;
    LogLevel Level;
    std::chrono::time_point<std::chrono::system_clock> Timestamp;
};

class IChannel;
class IPolicy;
class IDriver;

