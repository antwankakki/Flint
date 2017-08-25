#ifndef _NETWORK_
#define _NETWORK_

#include <flint/utils/debug.h>
#include <flint/kernel/kernel.h>

namespace flint
{
namespace network
{

constexpr int ACKNOWLEDGMENT_SET = 0xABCDEF;
constexpr size_t DEFAULT_COMMAND_LENGTH = 10;

struct Action
{
  int action;
  int params[7];
};

struct Command
{
  int acknowledgment; // ACKNOWLEDGMENT_SET
  int device_id;
  Action action;
};

class Network
{
public:
  Network();
  ~Network();

  int readBytes(int *data_array, size_t data_array_length);
  int writeBytes(int *data_array, size_t data_array_length);

private:
  int id;
  kernel::Status status;
  int type;
};
}
}

#endif
