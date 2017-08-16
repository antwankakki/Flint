#ifndef __DEFINES__
#define __DEFINES__

#define UNUSED(x) debugPrint(INFO, __DEBUG__, "Unused parameter (%s) found in %s", #x, __FUNCTION__); (void)x;

#endif
