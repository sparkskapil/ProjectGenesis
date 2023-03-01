#pragma once
#include "loggerinclude.h"

class IPolicy
{
public:
    virtual ~IPolicy() = default;
    virtual bool Evaluate(LogEntry&) = 0;
};