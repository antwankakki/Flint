#ifndef _NETWORK_
#define _NETWORK_

#include "../debug/debug.h"

struct _Network;
typedef struct _NetworkHandle {
    int status;
    void* instance;
    int (*populateNetwork)(_Network* network);
    int (*readBytes)(_Network* network, int* data_array, size_t data_array_length);
    int (*writeBytes)(_Network* network, int* data_array, size_t data_array_length);
} NetworkHandle;

typedef struct _Network {
    int id;
    Status status;
    int type;
    NetworkHandle handle;
} Network;

#endif
