#include "assert.hpp"
#define genAssertDebug(condition, message) DEBUG_ASSERT(condition)
#define genAssert(condition, message) ASSERT(condition)
#define genCriticalAssert(condition, message) VERIFY(condition)