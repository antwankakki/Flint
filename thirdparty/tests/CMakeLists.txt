cmake_minimum_required(VERSION 3.0)

message("|__ Building boost/test...")

project(boost_test CXX)

file(GLOB_RECURSE BOOST_TEST_HDR "include/*.hpp")
file(GLOB_RECURSE BOOST_TEST_SRC "src/*.cpp")

list(LENGTH BOOST_TEST_HDR BOOST_TEST_HDR_CNT)
list(LENGTH BOOST_TEST_SRC BOOST_TEST_SRC_CNT)

message("\t Found ${BOOST_TEST_HDR_CNT} header files and ${BOOST_TEST_SRC_CNT} source files.")

include_directories(${BOOST_TEST_HDR})

add_library(boost_test ${BOOST_TEST_SRC} ${BOOST_TEST_HDR})
target_include_directories(boost_test INTERFACE include/)
