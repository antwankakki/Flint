#include <flint/kernel/kernel.h>

namespace flint
{
namespace kernel
{

const char *statusMap(Status status)
{
    switch (status)
    {
    case Status::MISSING:
        return "Missing";
    case Status::BROKEN:
        return "Broken";
    case Status::FAILED:
        return "Failed";
    case Status::PRESENT:
        return "Present";
    case Status::RUNNING:
        return "Running";
    case Status::IDLE:
        return "Idle";
    case Status::READY:
        return "Ready";
    case Status::DOWN:
        return "DOWN";
    default:
        return "Unknown";
    }
}

int Drone::powerUp()
{
    ENTRY_POINT;
    UNUSED(speed);
    debugPrint(LogType::INFO, __DEBUG__ || __RELEASE__, "Powering up the drone");
    EXIT_POINT_WITH_RETURN(true);
}

int Drone::powerDown()
{
    ENTRY_POINT;
    UNUSED(speed);
    debugPrint(LogType::INFO, __DEBUG__ || __RELEASE__, "Powering down the drone");
    EXIT_POINT_WITH_RETURN(true);
}

int Drone::gracefulPowerDown()
{
    ENTRY_POINT;
    UNUSED(speed);
    debugPrint(LogType::INFO, __DEBUG__ || __RELEASE__, "Gracefully powering down the drone");
    EXIT_POINT_WITH_RETURN(true);
}

int Drone::reboot()
{
    ENTRY_POINT;
    UNUSED(id);
    debugPrint(LogType::INFO, __DEBUG__ || __RELEASE__, "Rebooting the drone");
    EXIT_POINT_WITH_RETURN(true);
}

int Drone::setDroneSpeed(float speed)
{
    ENTRY_POINT;
    UNUSED(speed);
    debugPrint(LogType::INFO, __DEBUG__ || __RELEASE__, "Setting drone speed to %.3f", speed);
    EXIT_POINT_WITH_RETURN(true);
}

int Drone::setDroneHeight(float height)
{
    ENTRY_POINT;
    UNUSED(height);
    debugPrint(LogType::INFO, __DEBUG__ || __RELEASE__, "Setting drone height to %.3f", height);
    EXIT_POINT_WITH_RETURN(true);
}

int Drone::setDroneDirection(int direction)
{
    ENTRY_POINT;
    UNUSED(direction);
    printf("Setting drone direction to %d", direction);
    EXIT_POINT_WITH_RETURN(true);
}

int Drone::setDroneTilt(float tilt)
{
    ENTRY_POINT;
    UNUSED(tilt);
    debugPrint(LogType::INFO, __DEBUG__ || __RELEASE__, "Setting drone tilt to %.3f", tilt);
    EXIT_POINT_WITH_RETURN(true);
}

unsigned int Drone::getId()
{
    return id;
}

Status Drone::getStatus()
{
    return status;
}

float Drone::getSpeed()
{
    return speed;
}

float Drone::getHeight()
{
    return height;
}

int Drone::getDirection()
{
    return direction;
}

size_t Drone::getBatteryCount()
{
    return battery_count;
}

size_t Drone::getRotorCount()
{
    return rotor_count;
}

size_t Drone::getCameraCount()
{
    return camera_count;
}

Battery *Drone::getBattery(size_t index)
{
    if (index >= getBatteryCount())
        return nullptr;

    return &(batteries[index]);
}

Camera *Drone::getCamera(size_t index)
{
    if (index >= getCameraCount())
        return nullptr;

    return &(cameras[index]);
}

Rotor *Drone::getRotor(size_t index)
{
    if (index >= getRotorCount())
        return nullptr;

    return &(rotors[index]);
}

float Drone::getTilt()
{
    return tilt;
}

unsigned int Rotor::getId()
{
    return id;
}

Status Rotor::getStatus()
{
    return status;
}

unsigned int Camera::getId()
{
    return id;
}

Status Camera::getStatus()
{
    return status;
}

float Camera::getTilt()
{
    return tilt;
}

CameraType Camera::getType()
{
    return type;
}

unsigned int Battery::getId()
{
    return id;
}

Status Battery::getStatus()
{
    return status;
}

float Battery::getCharge()
{
    return charge;
}

BatteryType Battery::getType()
{
    return type;
}

Drone::Drone()
    : id(1), battery_count(0), rotor_count(0), camera_count(0)
{
    ENTRY_POINT;
    id = 1;
    status = Status::PRESENT;
    EXIT_POINT;
}

Drone::~Drone()
{
    ENTRY_POINT;
    EXIT_POINT;
}
}
}