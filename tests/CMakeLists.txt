cmake_minimum_required(VERSION 3.2)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall -Wextra -Werror -pedantic-errors")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -Werror -pedantic-errors")

add_executable(test_c test.c)
target_link_libraries(test_c zf_box)
add_executable(test_cpp test.cpp)
target_link_libraries(test_cpp zf_box)
