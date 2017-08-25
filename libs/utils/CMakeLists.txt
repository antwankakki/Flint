message("|__Building flint utils")

project(flint_utils CXX)

set(FLINT_UTILS_HDR
        include/flint/utils/debug.h
   )

set(FLINT_UTILS_SRC
   src/debug.cpp
)

include_directories(include)
add_library(flint_utils ${FLINT_UTILS_HDR} ${FLINT_UTILS_SRC})
target_include_directories(boost_optional INTERFACE include/)