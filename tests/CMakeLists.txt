
include_directories("${PROJECT_SOURCE_DIR}/src")

add_cmocka_test(test_kata02_binary_search
        SOURCES
        ${PROJECT_SOURCE_DIR}/tests/now.c
        ${PROJECT_SOURCE_DIR}/tests/kata02/kata02-binary-search_test.c
        ${PROJECT_SOURCE_DIR}/src/kata02/kata02-binary-search.c
        LINK_LIBRARIES cmocka_lib
        LINK_OPTIONS --coverage)

add_cmocka_test(test_read_file
        SOURCES
        ${PROJECT_SOURCE_DIR}/tests/now.c
        ${PROJECT_SOURCE_DIR}/tests/file/read_file_test.c
        ${PROJECT_SOURCE_DIR}/src/file/read_file.c
        LINK_LIBRARIES cmocka_lib
        LINK_OPTIONS --coverage)

add_cmocka_test(test_tokenizer
        SOURCES
        ${PROJECT_SOURCE_DIR}/tests/string/tokenizer_test.c
        ${PROJECT_SOURCE_DIR}/src/string/tokenizer.c
        LINK_LIBRARIES cmocka_lib
        LINK_OPTIONS --coverage)

add_cmocka_test(test_strings
        SOURCES
        ${PROJECT_SOURCE_DIR}/tests/string/strings_test.c
        ${PROJECT_SOURCE_DIR}/src/string/strings.c
        LINK_LIBRARIES cmocka_lib m
        LINK_OPTIONS --coverage)

add_cmocka_test(test_kata04_data_football
        SOURCES
        ${PROJECT_SOURCE_DIR}/tests/kata04/football_data_test.c
        ${PROJECT_SOURCE_DIR}/src/kata04/football_data.c
        ${PROJECT_SOURCE_DIR}/src/string/tokenizer.c
        ${PROJECT_SOURCE_DIR}/src/string/strings.c
        LINK_LIBRARIES cmocka_lib
        LINK_OPTIONS --coverage)

add_cmocka_test(test_kata04_data_weather
        SOURCES
        ${PROJECT_SOURCE_DIR}/tests/kata04/weather_data_test.c
        ${PROJECT_SOURCE_DIR}/src/kata04/weather_data.c
        ${PROJECT_SOURCE_DIR}/src/string/tokenizer.c
        ${PROJECT_SOURCE_DIR}/src/string/strings.c
        LINK_LIBRARIES cmocka_lib
        LINK_OPTIONS --coverage)

add_cmocka_test(test_kata04_data_munger_football
        SOURCES
        ${PROJECT_SOURCE_DIR}/tests/kata04/football_munger_test.c
        ${PROJECT_SOURCE_DIR}/src/kata04/football_munger.c
        ${PROJECT_SOURCE_DIR}/src/kata04/football_data.c
        ${PROJECT_SOURCE_DIR}/src/string/tokenizer.c
        ${PROJECT_SOURCE_DIR}/src/string/strings.c
        ${PROJECT_SOURCE_DIR}/src/file/read_file.c
        LINK_LIBRARIES cmocka_lib
        LINK_OPTIONS --coverage)

add_cmocka_test(test_kata04_data_munger_weather
        SOURCES
        ${PROJECT_SOURCE_DIR}/tests/kata04/weather_munger_test.c
        ${PROJECT_SOURCE_DIR}/src/kata04/weather_munger.c
        ${PROJECT_SOURCE_DIR}/src/kata04/weather_data.c
        ${PROJECT_SOURCE_DIR}/src/string/tokenizer.c
        ${PROJECT_SOURCE_DIR}/src/string/strings.c
        ${PROJECT_SOURCE_DIR}/src/file/read_file.c
        LINK_LIBRARIES cmocka_lib
        LINK_OPTIONS --coverage)

add_cmocka_test(test_kata05_bloom_filter
        SOURCES
        ${PROJECT_SOURCE_DIR}/tests/kata05/bloom_filter_test.c
        ${PROJECT_SOURCE_DIR}/src/kata05/bloom_filter.c
        ${PROJECT_SOURCE_DIR}/src/string/tokenizer.c
        ${PROJECT_SOURCE_DIR}/src/string/strings.c
        ${PROJECT_SOURCE_DIR}/src/file/read_file.c
        LINK_LIBRARIES cmocka_lib
        LINK_OPTIONS --coverage)

add_cmocka_test(test_kata06_anagram
        SOURCES
        ${PROJECT_SOURCE_DIR}/tests/kata06/anagram_test.c
        ${PROJECT_SOURCE_DIR}/src/kata06/anagram.c
        ${PROJECT_SOURCE_DIR}/src/string/tokenizer.c
        ${PROJECT_SOURCE_DIR}/src/string/strings.c
        ${PROJECT_SOURCE_DIR}/src/file/read_file.c
        LINK_LIBRARIES cmocka_lib
        LINK_OPTIONS --coverage)

add_library(cmocka_lib SHARED IMPORTED)
if (APPLE)
    set_target_properties(cmocka_lib PROPERTIES IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/build-dependencies/install/cmocka-1.1.5/lib/libcmocka.dylib)
else ()
    set_target_properties(cmocka_lib PROPERTIES IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/build-dependencies/install/cmocka-1.1.5/lib/libcmocka.so)
endif ()

include_directories(${PROJECT_SOURCE_DIR}/build-dependencies/install/cmocka-1.1.5/include)

file(COPY resources DESTINATION .)
