#pragma once
#include "assert.hpp"
#include "Logger/logger.h"

#define genAssertDebug(condition, message) if(!(condition))log_warn(message); DEBUG_ASSERT(condition);
#define genAssert(condition, message) if(!(condition))log_error(message); ASSERT(condition);
#define genAssertCritical(condition, message) if(!(condition))log_fatal(message); VERIFY(condition);

#define genFailedDebug(message) genAssertDebug(false, message);
#define genFailed(message) genAssert(false, message);
#define genFailedCritical(message) genAssertCritical(false, message);