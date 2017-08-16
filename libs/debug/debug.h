#ifndef _DEBUG_
#define _DEBUG_

#include <stdio.h> //vprintf
#include <stdarg.h> //va_list, va_start, va_end
#include <stdlib.h>

// Booleans
#define TRUE  (0 == 0)
#define FALSE (0 == 1)

// Log Types
//#define FATAL 0
//#define ERROR 1
//#define WARN  2
//#define PASS  3
//#define INFO  4
typedef enum {
    FATAL = 0,
    ERROR,
    WARN,
    PASS,
    INFO
} LogType;

#ifdef DEBUG
    #define __DEBUG__ TRUE
    #define __RELEASE__ FALSE
#endif
#ifdef RELEASE
    #define __DEBUG__ FALSE
    #define __RELEASE__ TRUE
#endif

#define ENTRY_POINT printf("Entered %s (%s: %d)\n", __FUNCTION__, __FILE__, __LINE__);
#define EXIT_POINT printf("Exited %s (%s: %d)\n", __FUNCTION__, __FILE__, __LINE__);
#define EXIT_POINT_WITH_RETURN(x) EXIT_POINT; return x;

void debugPrint(int log_type, int flag, const char * format, ...)
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

#endif
