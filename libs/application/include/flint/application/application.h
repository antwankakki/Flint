#ifndef _APPLICATION_
#define _APPLICATION_

#include <flint/utils/debug.h>
#include <flint/kernel/kernel.h>
#include <flint/network/network.h>

namespace flint
{
namespace application
{

class Application
{
public:
  Application();
  ~Application();

  int showInventory();
  int start();
  int startAutoPilot();

private:
  int id;
  kernel::Status status;
  kernel::Drone drone;
  network::Network network;
};
}
}

#endif
