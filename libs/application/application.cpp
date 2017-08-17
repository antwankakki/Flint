#include <string.h> // needed for memset
#include "application.h"
#include "application_util.cpp"

int applicationInit(Application* application)
{
    ENTRY_POINT;
    memset(application, 0, sizeof(Application));
    application->handle.populateApplication = populateApplication;
    if (!application->handle.populateApplication(application))
    {
        debugPrint(FATAL, __DEBUG__ || __RELEASE__, "Failed to populate application");
        EXIT_POINT_WITH_RETURN(FALSE);
    }
    EXIT_POINT_WITH_RETURN(TRUE);
}
