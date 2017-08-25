#ifndef _KERNEL_
#define _KERNEL_

#include <flint/utils/debug.h>
#include <flint/kernel/defines.h>

namespace flint
{
namespace kernel
{

enum class Status
{
  MISSING = 1,
  BROKEN,
  FAILED,
  PRESENT,
  RUNNING,
  IDLE,
  READY,
  DOWN
};

const char *statusMap(Status status);

enum class BatteryType
{
  LiPo = 1
};

enum class CameraType
{
  STANDARD = 1,
  WIDE_ANGLE,
  SHORT_TELEPHOTO,
  MEDIUM_TELEPHOTO,
  SUPER_TELEPHOTO
};

class Battery
{
public:
  Battery();
  ~Battery();

  int loadCharge();
  unsigned int getId();
  Status getStatus();
  BatteryType getType();
  float getCharge();

private:
  unsigned int id;
  Status status;
  BatteryType type;
  float charge;
};

class Rotor
{
public:
  Rotor();
  ~Rotor();

  int getThrust();
  int setThrust(float thrust);
  Status getStatus();
  unsigned int getId();

private:
  unsigned int id;
  Status status;
  int thrust;
};

class Camera
{
public:
  Camera();
  ~Camera();

  int capture();
  int startLiveStream();
  int endLiveStream();

  CameraType getType();
  float getTilt();
  Status getStatus();
  unsigned int getId();

  void setTilt(float val);

private:
  unsigned int id;
  Status status;
  CameraType type;
  float tilt;
};

class Drone
{
public:
  Drone();
  ~Drone();

  int powerUp();
  int powerDown();
  int gracefulPowerDown();
  int reboot();
  int setDroneSpeed(float speed);
  int setDroneHeight(float height);
  int setDroneDirection(int direction);
  int setDroneTilt(float tilt);

  unsigned int getId();
  kernel::Status getStatus();
  float getSpeed();
  float getHeight();
  int getDirection();
  float getTilt();

  size_t getBatteryCount();
  size_t getRotorCount();
  size_t getCameraCount();

  Battery *getBattery(size_t index);
  Camera *getCamera(size_t index);
  Rotor *getRotor(size_t index);

private:
  unsigned int id;
  Status status;
  float speed;
  float height;
  int direction;
  float tilt;

  size_t battery_count;
  Battery *batteries;

  size_t rotor_count;
  Rotor *rotors;

  size_t camera_count;
  Camera *cameras;
};
}
}
#endif
