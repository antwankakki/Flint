#include <flint/utils/debug.h>

void debugPrint(LogType log_type, int flag, const char *format, ...)
{
    if (flag)
    {
        switch (log_type)
        {
        case LogType::FATAL:
            printf("FATAL: ");
            break;
        case LogType::ERROR:
            printf("ERROR: ");
            break;
        case LogType::WARN:
            printf("WARN: ");
            break;
        case LogType::PASS:
            printf("PASS: ");
            break;
        case LogType::INFO:
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