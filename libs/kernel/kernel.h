#ifndef _KERNEL_
#define _KERNEL_

#include "../debug/debug.h"
#include "defines.h"

typedef enum {
  MISSING = 1,
  BROKEN,
  FAILED,
  PRESENT,
  RUNNING,
  IDLE
} Status;

typedef enum {
  LiPo = 1
} BatteryType;

typedef enum {
  // TODO: ADD
} CameraType;

struct _Battery;
typedef struct _BatteryHandle {
    Status status;
    int (*populateBattery)(_Battery* battery);
    int (*loadCharge)(_Battery* battery);
} BatteryHandle;

typedef struct _Battery {
    unsigned int id;
    Status status;
    BatteryType type;
    float charge;
} Battery;

struct _Rotor;
typedef struct _RotorHandle {
    Status status;
    int (*populateRotor)(_Rotor* rotor);
    int (*populateThrust)(_Rotor* rotor);
    int (*setThrust)(_Rotor* rotor, float thrust);
} RotorHandle;

typedef struct _Rotor {
    unsigned int id;
    Status status;
    int thrust;
    RotorHandle handle;
} Rotor;

struct _Camera;
typedef struct _CameraHandle {
    Status status;
    int (*capture)(_Camera* camera);
    // TODO: add more fields
} CameraHandle;

typedef struct _Camera {
    unsigned int id;
    Status status;
    CameraType type;
    // TODO: Add more fields
    CameraHandle handle;
} Camera;

struct _Drone;
typedef struct _DroneHandle {
    Status status;
    int (*populateDrone)(_Drone* drone);
    int (*powerUp)(_Drone* drone);
    int (*powerDown)(_Drone* drone);
    int (*gracefulPowerDown)(_Drone* drone);
    int (*reboot)(_Drone* drone);
    int (*setDroneSpeed)(_Drone* drone, float speed);
    int (*setDroneHeight)(_Drone* drone, float height);
    int (*setDroneDirection)(_Drone *drone, int direction);
    int (*setDroneTilt)(_Drone* drone, float tilt);
} DroneHandle;

typedef struct _Drone {
    unsigned int id;
    Status status;
    float speed;
    float height;
    int direction;
    float tilt;
    unsigned int battery_count;
    Battery* batteries;
    unsigned int rotor_count;
    Rotor* rotors;
    unsigned int camera_count;
    Camera* cameras;
    DroneHandle handle;
} Drone;

#endif
