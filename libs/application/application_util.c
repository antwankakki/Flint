char* applicationStatusMap(int status)
{
    switch (status)
    {
        case APPLICATION_STATUS_DOWN:
            return (char*)"Down";
        case APPLICATION_STATUS_IDLE:
            return (char*)"Idle";
        case APPLICATION_STATUS_READY:
            return (char*)"Ready";
        default:
            return (char*)"Unknown";
    }
}

int showInventory(const Application* application)
{
    ENTRY_POINT;
    printf("Application:\n");
    printf("  ID: %d\n", application->id);
    printf("  Status: %s\n", applicationStatusMap(application->status));
    printf("  Drone:\n");
    printf("    ID: %d\n", application->drone.id);
    printf("    Status: %s\n", kernelStatusMap(application->drone.status));
    printf("    Speed: %.3f\n", application->drone.speed);
    printf("    Height: %.3f\n", application->drone.height);
    printf("    Direction: %d\n", application->drone.direction);
    printf("    Tilt: %.3f\n", application->drone.tilt);
    printf("    Batteries:\n");
    printf("      Battery Count: %d\n", application->drone.battery_count);
    for (unsigned int i = 0; i < application->drone.battery_count; i++)
    {
        printf("      Battery #%d:\n", i);
        printf("        ID: %d\n", application->drone.batteries[i].id);
        printf("        Status: %s\n", kernelStatusMap(application->drone.batteries[i].status));
        printf("        Type: %d\n", application->drone.batteries[i].type);
        printf("        Current Charge: %.2f\n", application->drone.batteries[i].charge);
    }
    printf("    Rotors:\n");
    printf("      Rotor Count: %d\n", application->drone.rotor_count);
    for (unsigned int i = 0; i < application->drone.rotor_count; i++)
    {
      printf("      Rotor #%d:\n", i);
      printf("        ID: %d\n", application->drone.rotors[i].id);
      printf("        Status: %s\n", kernelStatusMap(application->drone.rotors[i].status));
    }
    printf("    Cameras:\n");
    printf("      Camera Count: %d\n", application->drone.camera_count);
    for (unsigned int i = 0; i < application->drone.camera_count; i++)
    {
      printf("    Camera #%d:\n", i);
      printf("      ID: %d\n", application->drone.cameras[i].id);
      printf("      Status: %d\n", application->drone.cameras[i].status);
      printf("      Type: %d\n", application->drone.cameras[i].type);
      printf("      Tilt: %.3f\n", application->drone.cameras[i].tilt);
    }
    EXIT_POINT_WITH_RETURN(TRUE);
}

int populateApplicationHandle(Application* application)
{
    ENTRY_POINT;
    application->handle.showInventory = showInventory;
    // TODO: add all handles
    EXIT_POINT_WITH_RETURN(TRUE);
}

int populateApplication(Application* application)
{
    ENTRY_POINT;
    application-> id = 1;

    if (kernelInit(&application->drone) && networkInit(&application->network) && populateApplicationHandle(application))
    {
        application->status = APPLICATION_STATUS_READY;
    }
    else
    {
        application->status = APPLICATION_STATUS_DOWN;
        EXIT_POINT_WITH_RETURN(FALSE);
    }
    EXIT_POINT_WITH_RETURN(TRUE);
}
