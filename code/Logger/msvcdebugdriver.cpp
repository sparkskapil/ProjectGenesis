#include <format>
#include <chrono>
#include <Windows.h>
#include "msvcdebugdriver.h"

void MsvcDebugDriver::Submit(LogEntry& entry)
{
    auto output = std::format(L"@[LOG] [{}] [{{{}}}] {}\n  >> at {}\n     {}({})\n",
        GetLevelName(entry.Level),
        std::chrono::zoned_time{ std::chrono::current_zone(), entry.Timestamp},
        entry.Message,
        entry.Function,
        entry.File,
        entry.Line
    );
    OutputDebugStringW(output.c_str());
}
