message("|__Building flint network")


project(flint_network CXX)

set(FLINT_NETWORK_SRC
        src/network.cpp)

set(FLINT_NETWORK_HDR
        include/flint/network/network.h
   )

include_directories(include)

add_library(flint_network ${FLINT_NETWORK_SRC} ${FLINT_NETWORK_HDR})
target_link_libraries(flint_network flint_kernel boost_optional)
target_include_directories(flint_network INTERFACE include/)