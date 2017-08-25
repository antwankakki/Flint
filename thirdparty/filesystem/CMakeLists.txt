cmake_minimum_required(VERSION 3.0)

message("|__ Building boost/filesystem...")

project(boost_filesystem CXX)

file(GLOB_RECURSE BOOST_FILESYSTEM_HDR "include/*.hpp")
file(GLOB_RECURSE BOOST_FILESYSTEM_SRC "src/*.cpp")

list(LENGTH BOOST_FILESYSTEM_HDR BOOST_FILESYSTEM_HDR_CNT)
list(LENGTH BOOST_FILESYSTEM_SRC BOOST_FILESYSTEM_SRC_CNT)

message("|\t Found ${BOOST_FILESYSTEM_HDR_CNT} header files and ${BOOST_FILESYSTEM_SRC_CNT} source files.")

include_directories(${BOOST_FILESYSTEM_HDR})

add_library(boost_filesystem ${BOOST_FILESYSTEM_SRC} ${BOOST_FILESYSTEM_HDR})
target_include_directories(boost_filesystem INTERFACE include/)
