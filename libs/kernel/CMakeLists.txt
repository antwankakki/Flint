message("|__Building flint kernel")

project(flint_kernel CXX)

set(FLINT_KERNEL_SRC
        src/kernel.cpp)

set(FLINT_KERNEL_HDR
        include/flint/kernel/defines.h
        include/flint/kernel/kernel.h        
   )

include_directories(include)

add_library(flint_kernel ${FLINT_KERNEL_SRC} ${FLINT_KERNEL_HDR})
target_link_libraries(flint_kernel boost_optional)
target_include_directories(flint_kernel INTERFACE include/)