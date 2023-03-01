#pragma once
#include "driver.h"

class MsvcDebugDriver : public IDriver
{
public:
	void Submit(LogEntry&) override;
	~MsvcDebugDriver() = default;
};