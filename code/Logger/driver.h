#pragma once
#include "loggerinclude.h"

class IDriver
{
public:
    virtual ~IDriver() = default;
    virtual void Submit(LogEntry&) = 0;
};