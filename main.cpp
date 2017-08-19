#include "libs/application/application.cpp"

typedef struct {
    int a;
} A;

int main() {
    ENTRY_POINT;
    Application application;
    if (!applicationInit(&application))
    {
        debugPrint(FATAL, TRUE, "Failed to populate application");
        EXIT_POINT_WITH_RETURN(1);
    }

    // test
    application.handle.showInventory(&application);

    if (!application.handle.start(&application))
    {
      debugPrint(FATAL, TRUE, "Unable to start application");
      EXIT_POINT_WITH_RETURN(1);
    }
    EXIT_POINT_WITH_RETURN(0);
}
