#ifndef KATA_READ_FILE_H
#define KATA_READ_FILE_H

typedef struct strings_list {
    int lines_count;
    int max_lines;
    char **lines;
} StringsList;

StringsList *to_data(const char *filename);

void free_strings_list(StringsList *list);

#endif //KATA_READ_FILE_H
