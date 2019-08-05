#include <stdio.h>
#include <stdlib.h>
#include "read_file.h"

#define  MAX_LEN  128

StringsList *new_strings_list();

void resize_list(StringsList *stringsList, int new_max_size);

char *get_line(FILE *file, char *line);

void read_file(FILE *file, StringsList *list);

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
    for (int i = 0; get_line(file, list->lines[i]); i++) {
        if (i >= list->max_lines) {
            resize_list(list, list->max_lines * 2);
        }
        list->lines_count++;
    }
}

char *get_line(FILE *file, char *line) {
    line = (char *) malloc(MAX_LEN * sizeof(char));
    return fgets(line, MAX_LEN, file);
}

void resize_list(StringsList *stringsList, int new_max_size) {
    stringsList->max_lines = new_max_size;
    stringsList->lines = (char **) realloc(stringsList->lines, new_max_size * sizeof *stringsList->lines);
}

StringsList *new_strings_list() {
    StringsList *list = malloc(sizeof(StringsList));
    list->lines = NULL;
    list->lines_count = 0;
    list->max_lines = 10;
    resize_list(list, list->max_lines);
    return list;
}

void free_strings_list(StringsList *list) {
    if (list != NULL) {
        free(list->lines);
        free(list);
    }
}
