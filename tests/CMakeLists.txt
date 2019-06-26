
include_directories("${PROJECT_SOURCE_DIR}/src")

add_cmocka_test(test_kata02_binary_search
        SOURCES
        ${CMAKE_SOURCE_DIR}/tests/now.c
        ${CMAKE_SOURCE_DIR}/tests/kata02/kata02-binary-search_test.c
        ${CMAKE_SOURCE_DIR}/src/kata02/kata02-binary-search.c)

add_cmocka_test(test_read_file
        SOURCES
        ${CMAKE_SOURCE_DIR}/tests/now.c
        ${CMAKE_SOURCE_DIR}/tests/file/read_file_test.c
        ${CMAKE_SOURCE_DIR}/src/file/read_file.c
        LINK_LIBRARIES cmocka_lib)

add_cmocka_test(test_tokenizer
        SOURCES
        ${CMAKE_SOURCE_DIR}/tests/strings/tokenizer_test.c
        ${CMAKE_SOURCE_DIR}/src/string/tokenizer.c
        LINK_LIBRARIES cmocka_lib)

add_cmocka_test(test_strings
        SOURCES
        ${CMAKE_SOURCE_DIR}/tests/strings/strings_test.c
        ${CMAKE_SOURCE_DIR}/src/string/strings.c
        LINK_LIBRARIES cmocka_lib)

add_cmocka_test(test_kata04_data_munger
        SOURCES
        ${PROJECT_SOURCE_DIR}/tests/kata04/football_data_test.c
        ${PROJECT_SOURCE_DIR}/src/kata04/football_data.c
        ${PROJECT_SOURCE_DIR}/src/string/tokenizer.c
        ${PROJECT_SOURCE_DIR}/src/string/strings.c
        LINK_LIBRARIES cmocka_lib)

add_library(cmocka_lib SHARED IMPORTED)
if (APPLE)
    set_target_properties(cmocka_lib PROPERTIES IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/build-dependencies/install/cmocka-1.1.5/lib/libcmocka.dylib)
else ()
    set_target_properties(cmocka_lib PROPERTIES IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/build-dependencies/install/cmocka-1.1.5/lib/libcmocka.so)
endif ()

include_directories(${PROJECT_SOURCE_DIR}/build-dependencies/install/cmocka-1.1.5/include)

target_link_libraries(test_kata02_binary_search cmocka_lib m)

file(COPY resources DESTINATION .)