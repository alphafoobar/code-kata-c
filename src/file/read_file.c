#include "read_file.h"

StringsList *to_data(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    StringsList *list = new_strings_list();
    read_file_into_list(file, list);

    fclose(file);
    return list;
}

void read_file_into_list(FILE *file, StringsList *list) {
    for (int i = 0; fgets(list->lines[i], MAX_STRING_LEN, file); i++) {
        if (++list->lines_count >= list->max_lines) {
            resize_list(list, list->max_lines * 2);
        }
    }
}
