#ifndef _APPLICATION_
#define _APPLICATION_

#include "../debug/debug.h"
#include "../kernel/kernel.c"
#include "../network/network.c"

/// Defines
#define APPLICATION_STATUS_DOWN  1
#define APPLICATION_STATUS_IDLE  2
#define APPLICATION_STATUS_READY 3

/// EOF Defines

struct _Application;
typedef struct _ApplicationHandle {
    int status;
    int (*populateApplication)(_Application* application);
    int (*showInventory)(const _Application* application);
} ApplicationHandle;

typedef struct _Application {
    int id;
    int status;
    Drone drone;
    Network network;
    ApplicationHandle handle;
} Application;

#endif