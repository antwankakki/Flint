#ifndef _NETWORK_
#define _NETWORK_

#include "../debug/debug.h"

#define ACKNOWLEDGMENT_SET     0xABCDEF
#define DEFAULT_COMMAND_LENGTH (size_t)10

typedef struct {
  int action;
  int params[7];
} Action;

typedef struct {
  int acknowledgment; // ACKNOWLEDGMENT_SET
  int device_id;
  Action action;
} Command;

struct _Network;
typedef struct _NetworkHandle {
    Status status;
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
