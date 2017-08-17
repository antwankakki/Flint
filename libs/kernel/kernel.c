#include "kernel.h"
#include "kernel_util.c"

int kernelInit(Drone* drone)
{
    ENTRY_POINT;
    drone->handle.populateDrone = populateDrone;
    if (!drone->handle.populateDrone(drone))
    {
        debugPrint(FATAL, __DEBUG__ || __RELEASE__, "Failed to populate drone");
        EXIT_POINT_WITH_RETURN(FALSE);
    }
    EXIT_POINT_WITH_RETURN(TRUE);
}
