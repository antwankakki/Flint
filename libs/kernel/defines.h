#ifndef __DEFINES__
#define __DEFINES__

#define UNUSED(x) \
  debugPrint(INFO, __DEBUG__, "Unused parameter (%s) found in %s", #x, __FUNCTION__); \
  (void)x;

#define SAFE_FREE(x) \
  if (x) \
  { \
    debugPrint(INFO, __DEBUG__ || __RELEASE__, "Safely freeing %s", #x); \
    free(x); \
    x = NULL; \
  } \
  else \
  { \
    debugPrint(INFO, __DEBUG__ || __RELEASE__, "%s has been freed already", #x); \
  };

#endif
