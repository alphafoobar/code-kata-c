#ifndef KATA_READ_FILE_H
#define KATA_READ_FILE_H

#include <stdio.h>

#include "../string/list.h"

StringsList *to_data(const char *filename);

void read_file_into_list(FILE *file, StringsList *list);

#endif //KATA_READ_FILE_H
