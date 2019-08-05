cmake_minimum_required(VERSION 3.12)
project(c)
set(CMAKE_C_STANDARD 11)

add_subdirectory(src)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/build-dependencies/cmocka-1.1.5/cmake/Modules")

option(ENABLE_TESTS "Perform unit tests after build" ON)
include(AddCMockaTest)
enable_testing()

set(CMAKE_C_FLAGS "-Wall -Werror -Wpedantic -std=c11")

add_subdirectory(tests)
