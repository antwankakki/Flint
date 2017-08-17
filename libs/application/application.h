#ifndef _APPLICATION_
#define _APPLICATION_

#include "../debug/debug.h"
#include "../kernel/kernel.cpp"
#include "../network/network.cpp"

struct _Application;
typedef struct _ApplicationHandle {
    Status status;
    int (*populateApplication)(_Application* application);
    int (*showInventory)(const _Application* application);
} ApplicationHandle;

typedef struct _Application {
    int id;
    Status status;
    Drone drone;
    Network network;
    ApplicationHandle handle;
} Application;

#endif
