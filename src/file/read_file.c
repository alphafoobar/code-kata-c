#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "read_file.h"

#define  MAX_LEN  128

void resize_list(StringsList *list, size_t new_max_size);

void read_file(FILE *file, StringsList *list);

bool contains_string(StringsList *list, char *string);

StringsList *to_data(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    StringsList *list = new_strings_list();
    read_file(file, list);

    fclose(file);
    return list;
}

void read_file(FILE *file, StringsList *list) {
    for (int i = 0; fgets(list->lines[i], MAX_LEN, file); i++) {
        if (++list->lines_count >= list->max_lines) {
            resize_list(list, list->max_lines * 2);
        }
    }
}

void plus_string(StringsList *list, char *string) {
    list->lines[list->lines_count] = string;
    if (++list->lines_count >= list->max_lines) {
        resize_list(list, list->max_lines * 2);
    }
}

void plus_string_if_unique(StringsList *list, char *string) {
    if (contains_string(list, string)) {
        printf("Lit already contains string=%s\n", string);
        return;
    }

}

bool contains_string(StringsList *list, char *string) {
    for (size_t i = 0; i < list->lines_count; i++) {
        if (strcmp(list->lines[i], string) == 0) {
            return true;
        }
    }
    return false;
}

void resize_list(StringsList *list, size_t new_max_size) {
    list->max_lines = new_max_size;
    list->lines = (char **) realloc(list->lines, new_max_size * sizeof(char *));
    for (size_t i = list->lines_count; i < new_max_size; i++) {
        list->lines[i] = (char *) malloc(MAX_LEN * sizeof(char));
    }
}

StringsList *new_strings_list() {
    StringsList *list = (StringsList *) malloc(sizeof(StringsList));
    list->lines = NULL;
    list->lines_count = 0;
    list->max_lines = 10;
    resize_list(list, list->max_lines);
    return list;
}

void free_strings_list(StringsList *list) {
    if (list != NULL) {
        for (size_t i = 0; i < list->lines_count; i++) {
            free(list->lines[i]);
        }
        free(list->lines);
        free(list);
    }
}
