#ifndef __DEFINES__
#define __DEFINES__

// The compiler has checks enabled to spint out warnings when variables/objects
// are declared and not used and has switches enabled to treat warnings at errors.
// If you've declared a variable or an object that you're not yet ready to utilize,
// pass it to UNUSED() which will let the compiler know that you're aware of this
// warning and would like to silence it.
#define UNUSED(x) \
  debugPrint(INFO, __DEBUG__ || __RELEASE__, "Unused parameter (%s) found at %s:%d", #x, __FUNCTION__, __LINE__); \
  (void)x;

// Double freeing leads to segmentation faluts. This can be extremely dangerous
// especially when the drone is in flight mode as it will very likely run out of
// control and crash or fly into space.
// <b>Always</b> avoid using free() directly, and use SAFE_FREE() instead. This
// rule will be enforced and will lead to <b>pull request rejection</b> when violated.
#define SAFE_FREE(x) \
  if (x) \
  { \
    debugPrint(INFO, __DEBUG__ || __RELEASE__, "Safely freeing %s", #x); \
    free(x); \
    x = NULL; \
  } \
  else \
  { \
    debugPrint(INFO, __DEBUG__ || __RELEASE__, "%s is a free pointer", #x); \
  };

#endif
