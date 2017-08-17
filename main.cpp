#include "libs/application/application.c"

typedef struct {
  int a;
  int b;
} A;

int main() {
    ENTRY_POINT;

    Application application;
    if (!applicationInit(&application))
    {
        debugPrint(FATAL, __DEBUG__ || __RELEASE__, "Failed to populate application");
        EXIT_POINT_WITH_RETURN(FALSE);
    }

    // Test
    //application.handle.showInventory(&application);

    A* a = {0};

    a = (A*)calloc(1, sizeof(A));

    SAFE_FREE(a);
    SAFE_FREE(a);

    EXIT_POINT_WITH_RETURN(0);
}
