#include <iostream>
#include "logger.h"
#include "channel.h"
#include "msvcdebugdriver.h"

Logger Logger::ms_Instance;

Logger::Logger()
{
    m_Channel = std::make_unique<Channel>();
    m_Channel->AttachDriver(std::make_shared<MsvcDebugDriver>());
#if defined(NDEBUG)
    m_Level = LogLevel::Error;
#else 
    m_Level = LogLevel::Debug;
#endif
}

Logger::~Logger()
{
}

void Logger::Log(LogLevel level, const std::wstring& message, const wchar_t* function, const wchar_t* file, uint32_t line)
{
    if (level > m_Level)
    {
        return;
    }
    LogEntry entry = { function, file, line, message, level, std::chrono::system_clock::now() };
    m_Channel->Submit(entry);
}