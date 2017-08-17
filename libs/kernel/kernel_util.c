const char* statusMap(Status status)
{
  switch (status)
  {
    case MISSING:
        return "Missing";
    case BROKEN:
        return "Broken";
    case FAILED:
      return "Failed";
    case PRESENT:
      return "Present";
    case RUNNING:
      return "Running";
    case IDLE:
      return "Idle";
    case READY:
      return "Ready";
    case DOWN:
      return "DOWN";
    default:
      return "Unknown";
  }
}

int powerUp(Drone* drone)
{
    ENTRY_POINT;
    UNUSED(drone);
    debugPrint(INFO, __DEBUG__ || __RELEASE__, "Powering up the drone");
    EXIT_POINT_WITH_RETURN(TRUE);
}

int powerDown(Drone* drone)
{
    ENTRY_POINT;
    UNUSED(drone);
    debugPrint(INFO, __DEBUG__ || __RELEASE__, "Powering down the drone");
    EXIT_POINT_WITH_RETURN(TRUE);
}

int gracefulPowerDown(Drone* drone)
{
    ENTRY_POINT;
    UNUSED(drone);
    debugPrint(INFO, __DEBUG__ || __RELEASE__, "Gracefully powering down the drone");
    EXIT_POINT_WITH_RETURN(TRUE);
}

int reboot(Drone* drone)
{
    ENTRY_POINT;
    UNUSED(drone);
    debugPrint(INFO, __DEBUG__ || __RELEASE__, "Rebooting the drone");
    EXIT_POINT_WITH_RETURN(TRUE);
}

int setDroneSpeed(Drone* drone, float speed)
{
    ENTRY_POINT;
    UNUSED(drone);
    debugPrint(INFO, __DEBUG__ || __RELEASE__, "Setting drone speed to %.3f", speed);
    EXIT_POINT_WITH_RETURN(TRUE);
}

int setDroneHeight(Drone* drone, float height)
{
    ENTRY_POINT;
    UNUSED(drone);
    debugPrint(INFO, __DEBUG__ || __RELEASE__, "Setting drone height to %.3f", height);
    EXIT_POINT_WITH_RETURN(TRUE);
}

int setDroneDirection(Drone *drone, int direction)
{
    ENTRY_POINT;
    UNUSED(drone);
    printf("Setting drone direction to %d", direction);
    EXIT_POINT_WITH_RETURN(TRUE);
}

int setDroneTilt(Drone* drone, float tilt)
{
    ENTRY_POINT;
    UNUSED(drone);
    debugPrint(INFO, __DEBUG__ || __RELEASE__, "Setting drone tilt to %.3f", tilt);
    EXIT_POINT_WITH_RETURN(TRUE);
}

int populateDroneHandle(Drone* drone)
{
    ENTRY_POINT;
    drone->id = 1;
    drone->status = PRESENT;
    drone->handle.powerUp = powerUp;
    drone->handle.powerDown = powerDown;
    drone->handle.gracefulPowerDown = gracefulPowerDown;
    drone->handle.reboot = reboot;
    drone->handle.setDroneSpeed = setDroneSpeed;
    drone->handle.setDroneHeight = setDroneHeight;
    drone->handle.setDroneDirection = setDroneDirection;
    drone->handle.setDroneTilt = setDroneTilt;
    EXIT_POINT_WITH_RETURN(TRUE);
}

int populateDrone(Drone* drone)
{
    ENTRY_POINT;
    if (!populateDroneHandle(drone))
    {
        debugPrint(FATAL, __DEBUG__ || __RELEASE__, "Failed to populate drone handle");
        EXIT_POINT_WITH_RETURN(FALSE);
    }
    // TODO: finish
    EXIT_POINT_WITH_RETURN(TRUE);
}
