#include <flint/application/application.h>

/**
 * @brief Main entry of the program
 * @param argc the number of arguments passed to program
 * @param argv the actual arguments
 * @return
 */
int main()
{
    ENTRY_POINT;
    flint::application::Application application;
    application.showInventory();
    EXIT_POINT_WITH_RETURN(0);
}
