cmake_minimum_required(VERSION 3.0)

message("|__ Building boost/program_options...")

project(boost_program_options CXX)

file(GLOB_RECURSE BOOST_PROGRAM_OPTIONS_HDR "include/*.hpp")
file(GLOB_RECURSE BOOST_PROGRAM_OPTIONS_SRC "src/*.cpp")

list(LENGTH BOOST_PROGRAM_OPTIONS_HDR BOOST_PROGRAM_OPTIONS_HDR_CNT)
list(LENGTH BOOST_PROGRAM_OPTIONS_SRC BOOST_PROGRAM_OPTIONS_SRC_CNT)

message("|\t Found ${BOOST_PROGRAM_OPTIONS_HDR_CNT} header files and ${BOOST_PROGRAM_OPTIONS_SRC_CNT} source files.")

include_directories(${BOOST_PROGRAM_OPTIONS_HDR})

add_library(boost_program_options ${BOOST_PROGRAM_OPTIONS_SRC}
        ${BOOST_PROGRAM_OPTIONS_HDR})
target_include_directories(boost_program_options INTERFACE include/)
