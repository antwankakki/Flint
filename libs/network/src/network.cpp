#include <flint/network/network.h>
#include <string.h>

namespace flint
{
namespace network
{

int Network::readBytes(int *data_array, size_t data_array_length)
{
    ENTRY_POINT;
    UNUSED(data_array_length);
    memset(data_array, 0, data_array_length * sizeof(int));
    debugPrint(LogType::INFO, __DEBUG__ || __RELEASE__, "Reading %d byte(s)", data_array_length);
    EXIT_POINT_WITH_RETURN(true);
}

int Network::writeBytes(int *data_array, size_t data_array_length)
{
    ENTRY_POINT;
    UNUSED(data_array_length);
    UNUSED(data_array);
    debugPrint(LogType::INFO, __DEBUG__ || __RELEASE__, "Writing %d byte(s)", data_array_length);
    EXIT_POINT_WITH_RETURN(true);
}

Network::Network()
{
    ENTRY_POINT;
    EXIT_POINT;
}

Network::~Network()
{
}
}
}