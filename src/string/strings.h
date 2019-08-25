#ifndef CODE_KATA_C_STRINGS_H
#define CODE_KATA_C_STRINGS_H

#include <stdlib.h>
#include <stdbool.h>

char *to_lower(char *s);

char *sorted_lowercase_string(char *s);

size_t latin1_hash_code(char *s);

bool is_number(char *s);

int an_int(char *s);

char *strip_trailing_asterisk(const char *s);

#endif //CODE_KATA_C_STRINGS_H
