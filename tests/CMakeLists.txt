
include_directories("${PROJECT_SOURCE_DIR}/src")

add_cmocka_test(test_kata02_binary_search
        SOURCES
        ${CMAKE_SOURCE_DIR}/tests/kata-test.c
        ${CMAKE_SOURCE_DIR}/tests/log.c
        ${CMAKE_SOURCE_DIR}/tests/now.c
        ${CMAKE_SOURCE_DIR}/tests/kata02/kata02-binary-search_test.c
        ${CMAKE_SOURCE_DIR}/src/kata02/kata02-binary-search.c)

add_library(cmocka_lib SHARED IMPORTED)
if (APPLE)
    set_target_properties(cmocka_lib PROPERTIES IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/build-dependencies/install/cmocka-1.1.5/lib/libcmocka.dylib)
else ()
    set_target_properties(cmocka_lib PROPERTIES IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/build-dependencies/install/cmocka-1.1.5/lib/libcmocka.so)
endif ()

include_directories(${PROJECT_SOURCE_DIR}/build-dependencies/install/cmocka-1.1.5/include)

target_link_libraries(test_kata02_binary_search cmocka_lib)