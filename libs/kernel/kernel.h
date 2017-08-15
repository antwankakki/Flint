#ifndef _KERNEL_
#define _KERNEL_

#include "../debug/debug.h"

/// Defines
#define DRONE_STATUS_NOT_PRESENT     1
#define DRONE_STATUS_IDLE            2
#define DRONE_STATUS_RUNNING         3
#define DRONE_STATUS_STANDBY         4

#define ROTOR_STATUS_NOT_PRESENT     1
#define ROTOR_STATUS_IDLE            2
#define ROTOR_STATUS_RUNNING         3
#define ROTOR_STATUS_STANDBY         4

#define CAMERA_STATUS_NOT_PRESENT     1
#define CAMERA_STATUS_IDLE            2
#define CAMERA_STATUS_RUNNING         3
#define CAMERA_STATUS_STANDBY         4
//TODO: add directions

/// EOF Defines

struct _Battery;
typedef struct _BatteryHandle {
    unsigned int status;
    int (*populateBattery)(_Battery* battery);
    int (*loadCharge)(_Battery* battery);
} BatteryHandle;

typedef struct _Battery {
    unsigned int id;
    int status;
    int type;
    float charge;
} Battery;

struct _Rotor;
typedef struct _RotorHandle {
    int status;
    int (*populateRotor)(_Rotor* rotor);
    int (*populateThrust)(_Rotor* rotor);
    int (*setThrust)(_Rotor* rotor, float thrust);
} RotorHandle;

typedef struct _Rotor {
    unsigned int id;
    int status;
    int thrust;
    RotorHandle handle;
} Rotor;

struct _Camera;
typedef struct _CameraHandle {
    int status;
    int (*capture)(_Camera* camera);
    // TODO: add more fields
} CameraHandle;

typedef struct _Camera {
    unsigned int id;
    int status;
    int type;
    // TODO: Add more fields
    CameraHandle handle;
} Camera;

struct _Drone;
typedef struct _DroneHandle {
    int status;
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
    int status;
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
