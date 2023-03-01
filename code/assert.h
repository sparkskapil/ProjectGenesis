#pragma once
#include "assert.hpp"
#include "Logger/logger.h"

#define genAssertDebug(condition, message) if(!(condition))log_warn(message); DEBUG_ASSERT(condition);
#define genAssert(condition, message) if(!(condition))log_error(message); ASSERT(condition);
#define genCriticalAssert(condition, message) if(!(condition))log_fatal(message); VERIFY(condition);