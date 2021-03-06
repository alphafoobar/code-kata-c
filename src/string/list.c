#include <string.h>
#include <stdio.h>

#include "list.h"

void plus_string(StringsList *list, char *string) {
    if (contains_string(list, string)) {
        printf("List already contains string='%s'\n", string);
        return;
    }
    list->lines[list->lines_count] = strndup(string, MAX_STRING_LEN);
    if (++list->lines_count >= list->max_lines) {
        resize_list(list, list->max_lines * 2);
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
        list->lines[i] = NULL;
    }
}

StringsList *new_strings_list_dofree() {
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
            if (list->lines[i] != NULL) {
                free(list->lines[i]);
            }
        }
        free(list->lines);
        free(list);
    }
}
