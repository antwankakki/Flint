cmake_minimum_required(VERSION 3.0)

message("|__ Building boost/optional...")

project(boost_optional CXX)

file(GLOB_RECURSE BOOST_OPTIONAL_HDR "include/*.hpp")

list(LENGTH BOOST_OPTIONAL_HDR BOOST_OPTIONAL_HDR_CNT)

message("|\t Found ${BOOST_OPTIONAL_HDR_CNT} header files")

include_directories(${BOOST_OPTIONAL_HDR})

add_library(boost_optional INTERFACE)
target_include_directories(boost_optional INTERFACE include/)
