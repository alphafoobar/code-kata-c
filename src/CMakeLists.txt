
add_executable(code_kata
        file/read_file.c
        string/strings.c
        string/tokenizer.c
        kata02/kata02-binary-search.c
        kata04/football_data.c
        main.c)

target_link_libraries(code_kata m)