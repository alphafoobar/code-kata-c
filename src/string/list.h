#ifndef CODE_KATA_C_LIST_H
#define CODE_KATA_C_LIST_H

#include <stdlib.h>
#include <stdbool.h>

#ifndef MAX_STRING_LEN
#define MAX_STRING_LEN  128 // Should probably match MAX_FILENAME_LEN in read_file.c
#endif // MAX_STRING_LEN

typedef struct strings_list {
    size_t lines_count;
    size_t max_lines;
    char **lines;
} StringsList;

StringsList *new_strings_list_dofree();

void resize_list(StringsList *list, size_t new_max_size);

bool contains_string(StringsList *list, char *string);

void plus_string(StringsList *list, char *string);

void free_strings_list(StringsList *list);

#endif //CODE_KATA_C_LIST_H
