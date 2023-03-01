#pragma once
#include "loggerinclude.h"

class Logger
{
public:
    virtual ~Logger();
    static Logger& Instance() { return ms_Instance; }
    
    void SetLevel(LogLevel level) { m_Level = level; }
    LogLevel GetLevel() const { return m_Level; }
    virtual void Log(LogLevel level, const std::wstring& message, const wchar_t* function, const wchar_t* file, uint32_t line);

protected:
    Logger();

private:
    static Logger ms_Instance;
    LogLevel m_Level;
    std::unique_ptr<IChannel> m_Channel;
};

#define genLogger Logger::Instance()    
#define log_fatal(message)      genLogger.Log(LogLevel::Fatal,      message, __FUNCTIONW__, __FILEW__, __LINE__)
#define log_error(message)      genLogger.Log(LogLevel::Error,      message, __FUNCTIONW__, __FILEW__, __LINE__)
#define log_warn(message)       genLogger.Log(LogLevel::Warn,       message, __FUNCTIONW__, __FILEW__, __LINE__)
#define log_info(message)       genLogger.Log(LogLevel::Info,       message, __FUNCTIONW__, __FILEW__, __LINE__)
#define log_debug(message)      genLogger.Log(LogLevel::Debug,      message, __FUNCTIONW__, __FILEW__, __LINE__)
#define log_verbose(message)    genLogger.Log(LogLevel::Verbose,    message, __FUNCTIONW__, __FILEW__, __LINE__)