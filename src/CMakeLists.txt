
add_executable(code_kata
        main.c
        file/read_file.c
        file/read_file.h
        string/list.c
        string/list.h
        string/strings.c
        string/strings.h
        string/tokenizer.c
        string/tokenizer.h
        kata02/kata02-binary-search.c
        kata04/football_data.c
        kata04/football_data.h
        kata04/weather_data.c
        kata04/weather_data.h
        kata04/football_munger.c
        kata04/football_munger.h
        kata04/weather_munger.c
        kata04/weather_munger.h
        kata05/bloom_filter.c
        kata05/bloom_filter.h
        kata06/anagram.c
        kata06/anagram.h)

target_link_libraries(code_kata m)
