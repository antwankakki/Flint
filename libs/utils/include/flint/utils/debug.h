#ifndef _DEBUG_
#define _DEBUG_

#include <stdio.h>  // vprintf
#include <stdarg.h> // va_list, va_start, va_end
#include <stdlib.h>

#ifdef DEBUG
#define __DEBUG__ true
#define __RELEASE__ false
#endif
#ifdef RELEASE
#define __DEBUG__ false
#define __RELEASE__ true
#endif
#ifndef DEBUG
#ifndef RELEASE
// If compiled with neither -DDEBUG nor -DRELEASE
#define __DEBUG__ false
#define __RELEASE__ false
#endif
#endif

// Log Types
enum class LogType
{
    FATAL = 0,
    ERROR,
    WARN,
    PASS,
    INFO
};

void debugPrint(LogType log_type, int flag, const char *format, ...);

#define ENTRY_POINT debugPrint(LogType::INFO, __DEBUG__ || __RELEASE__, "Entered %s (%s:%d)", __FUNCTION__, __FILE__, __LINE__);
#define EXIT_POINT debugPrint(LogType::INFO, __DEBUG__ || __RELEASE__, "Exited %s (%s:%d)", __FUNCTION__, __FILE__, __LINE__);
#define EXIT_POINT_WITH_RETURN(x) \
    EXIT_POINT;                   \
    return x;

#endif
