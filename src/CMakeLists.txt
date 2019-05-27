
add_executable(code_kata
        file/read_file.c
        kata02/kata02-binary-search.c
        main.c)

target_link_libraries(code_kata m)