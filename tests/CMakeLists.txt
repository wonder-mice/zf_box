cmake_minimum_required(VERSION 3.2)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall -Wextra -Werror -pedantic-errors -save-temps")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -Werror -pedantic-errors -save-temps")

add_executable(test_c test.c test.h)
target_link_libraries(test_c zf_box)
add_executable(test_cpp test.cpp test.h)
target_link_libraries(test_cpp zf_box)
