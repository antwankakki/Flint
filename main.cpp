#include "libs/application/application.c"

int main() {
    ENTRY_POINT;
    
    Application application;
    if (!applicationInit(&application))
    {
        debugPrint(FATAL, __DEBUG__ || __RELEASE__, "Failed to populate application");
        EXIT_POINT_WITH_RETURN(FALSE);
    }
    
    // Test
    application.handle.showInventory(&application);
    
    EXIT_POINT_WITH_RETURN(0);
}
