cmake_minimum_required(VERSION 3.12)
project(c)

set(CMAKE_C_STANDARD 11)

add_executable(code_kata src/kata02/kata02-binary-search.c tests/kata02/kata02-binary-search_test.c tests/now.c tests/log.c tests/kata-test.h tests/kata-test.c)
target_link_libraries(code_kata m)

include_directories(src)
