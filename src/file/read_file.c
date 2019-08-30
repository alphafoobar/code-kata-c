#include <string.h>

#include "read_file.h"

StringsList *to_data_dofree(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    StringsList *list = new_strings_list_dofree();
    read_file_into_list(file, list);
    fclose(file);
    return list;
}

void read_file_into_list(FILE *file, StringsList *list) {
    char temp[MAX_STRING_LEN];
    for (int i = 0; fgets(temp, MAX_STRING_LEN, file); i++) {
        list->lines[i] = strdup(temp);
        if (++list->lines_count >= list->max_lines) {
            resize_list(list, list->max_lines * 2);
        }
    }
}
