message("|__Building manual testers")

project(simple_tester CXX)
add_executable(simple_tester simple_tester.cpp)
target_link_libraries(simple_tester flint_application)
