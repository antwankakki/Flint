#include <flint/application/application.h>

namespace flint
{
namespace application
{

int Application::showInventory()
{
    ENTRY_POINT;
    printf("Application:\n");
    printf("  ID: %d\n", id);
    printf("  Status: %s\n", statusMap(status));
    printf("  Drone:\n");
    printf("    ID: %d\n", drone.getId());
    printf("    Status: %s\n", statusMap(drone.getStatus()));
    printf("    Speed: %.3f\n", drone.getSpeed());
    printf("    Height: %.3f\n", drone.getHeight());
    printf("    Direction: %d\n", drone.getDirection());
    printf("    Tilt: %.3f\n", drone.getTilt());
    printf("    Batteries:\n");
    printf("      Battery Count: %zu\n", drone.getBatteryCount());
    for (size_t i = 0; i < drone.getBatteryCount(); i++)
    {
        printf("      Battery #%zu:\n", i);
        printf("        ID: %d\n", drone.getBattery(i)->getId());
        printf("        Status: %s\n", statusMap(drone.getBattery(i)->getStatus()));
        printf("        Type: %d\n", drone.getBattery(i)->getType());
        printf("        Current Charge: %.2f\n", drone.getBattery(i)->getCharge());
    }
    printf("    Rotors:\n");
    printf("      Rotor Count: %zu\n", drone.getRotorCount());
    for (size_t i = 0; i < drone.getRotorCount(); i++)
    {
        printf("      Rotor #%zu:\n", i);
        printf("        ID: %d\n", drone.getRotor(i)->getId());
        printf("        Status: %s\n", statusMap(drone.getRotor(i)->getStatus()));
    }
    printf("    Cameras:\n");
    printf("      Camera Count: %zu\n", drone.getCameraCount());
    for (size_t i = 0; i < drone.getCameraCount(); i++)
    {
        printf("    Camera #%zu:\n", i);
        printf("      ID: %d\n", drone.getCamera(i)->getId());
        printf("      Status: %d\n", drone.getCamera(i)->getStatus());
        printf("      Type: %d\n", drone.getCamera(i)->getType());
        printf("      Tilt: %.3f\n", drone.getCamera(i)->getTilt());
    }
    EXIT_POINT_WITH_RETURN(true);
}

Application::Application()
{
}

Application::~Application()
{
}

///
// Actual entry point to the firmware
///
int Application::start()
{
    ENTRY_POINT;
    debugPrint(LogType::INFO, true, "Starting application");
    network::Command command;
    while (network.readBytes((int *)&command, network::DEFAULT_COMMAND_LENGTH))
    {
        if (command.acknowledgment == network::ACKNOWLEDGMENT_SET)
        {
            // TODO: process command
        }
        else
        {
            debugPrint(LogType::INFO, true, "Recieved invalid command (acknowledgment not set properly)");
        }
    }
    startAutoPilot();
    EXIT_POINT_WITH_RETURN(true);
}

int Application::startAutoPilot()
{
    ENTRY_POINT;
    EXIT_POINT_WITH_RETURN(true);
}
}
}