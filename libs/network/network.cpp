#include "network.h"
#include "network_util.cpp"

int networkInit(Network* network)
{
    ENTRY_POINT;
    network->handle.populateNetwork = populateNetwork;
    if (!network->handle.populateNetwork(network))
    {
        debugPrint(FATAL, __DEBUG__ || __RELEASE__, "Failed to populate network");
        EXIT_POINT_WITH_RETURN(FALSE);
    }
    EXIT_POINT_WITH_RETURN(TRUE);
}
