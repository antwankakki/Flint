message("|__Building flint application")

project(flint_application CXX)

set(FLINT_APPLICATION_SRC
        src/application.cpp)

set(FLINT_APPLICATION_HDR
        include/flint/application/application.h
   )

include_directories(include)

add_library(flint_application ${FLINT_APPLICATION_SRC} ${FLINT_APPLICATION_HDR})
target_link_libraries(flint_application flint_kernel flint_network flint_utils boost_optional)
target_include_directories(flint_application INTERFACE include/)