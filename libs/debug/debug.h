#ifndef _DEBUG_
#define _DEBUG_

#include <stdio.h> // vprintf
#include <stdarg.h> // va_list, va_start, va_end
#include <stdlib.h>

// Booleans
#define TRUE  (0 == 0)
#define FALSE (0 == 1)

#ifdef DEBUG
    #define __DEBUG__ TRUE
    #define __RELEASE__ FALSE
#endif
#ifdef RELEASE
    #define __DEBUG__ FALSE
    #define __RELEASE__ TRUE
#endif
#ifndef DEBUG
  #ifndef RELEASE
    // if compiled with neither -DDEBUG nor -DRELEASE
    #define __DEBUG__ FALSE
    #define __RELEASE__ FALSE
  #endif
#endif

// Log Types
typedef enum {
    FATAL = 0,
    ERROR,
    WARN,
    PASS,
    INFO
} LogType;

void debugPrint(LogType log_type, int flag, const char * format, ...)
{
    if (flag)
    {
        switch (log_type)
        {
            case FATAL:
                printf("FATAL: ");
                break;
            case ERROR:
                printf("ERROR: ");
                break;
            case WARN:
                printf("WARN: ");
                break;
            case PASS:
                printf("PASS: ");
                break;
            case INFO:
                printf("INFO: ");
                break;
            default:
                printf("UNKNOWN: ");
        }
        va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);
        printf("\n");
    }
}

#define ENTRY_POINT debugPrint(INFO, __DEBUG__ || __RELEASE__, "Entered %s (%s:%d)", __FUNCTION__, __FILE__, __LINE__);
#define EXIT_POINT debugPrint(INFO, __DEBUG__ || __RELEASE__, "Exited %s (%s:%d)", __FUNCTION__, __FILE__, __LINE__);
#define EXIT_POINT_WITH_RETURN(x) \
  EXIT_POINT; \
  return x;

#endif
