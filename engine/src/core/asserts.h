#pragma once

#include "defines.h"

// Disable assertions be commenting out this line
#define KASSERTIONS_ENABLED

#ifdef KASSERTIONS_ENABLED
#if _MSC_VER
#include <intrin.h>
#define debug_break() __debugbreak()
#else
#define debug_break() __builtin_trap()
#endif

KAPI void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line);

#define KASSERT(expr)                                                           \
    {                                                                           \
        if (expr)                                                               \
        {                                                                       \
        }                                                                       \
        else                                                                    \
        {                                                                       \
            report_assertion_failure(#expr, "", __FILE__, __LINE__);            \
            debug_break();                                                      \
        }                                                                       \
    }  

#define KASSERT_MSG(expr, message)                                              \
    {                                                                           \
        if (expr)                                                               \
        {                                                                       \
        }                                                                       \
        else                                                                    \
        {                                                                       \
            report_assertion_failure(#expr, message, __FILE__, __LINE__);       \
            debug_break();                                                      \
        }                                                                       \
    }                                                                           \

#ifdef _DEBUG
#define KASSERT_DEBUG(expr)                                                     \
    {                                                                           \
        if (expr)                                                               \
        {                                                                       \
        }                                                                       \
        else                                                                    \
        {                                                                       \
            report_assertion_failure(#expr, message, __FILE__, __LINE__);       \
            debug_break();                                                      \
        }                                                                       \
    }                                                                           
#else
#define KASSERT_DEBUG(expr) // Do nothing
#endif

#else
#define KASSERT(expr) // Do nothing
#define KASSERT_MSG(expr, message) // Do nothing
#define KASSERT_DEBUG(expr) // Do nothing

#endif