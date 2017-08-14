#include "libs/application/application.c"

int main() {
    ENTRY_POINT;
    
    Application application;
    if (!applicationInit(&application))
    {
        debugPrint(FATAL, TRUE, "Failed to populate application\n");
        EXIT_POINT_WITH_RETURN(FALSE);
    }
    
    // Test
    application.handle.showInventory(&application);
    
    EXIT_POINT_WITH_RETURN(0);
}
