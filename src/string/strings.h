#ifndef CODE_KATA_C_STRINGS_H
#define CODE_KATA_C_STRINGS_H

#include <stdlib.h>
#include <stdbool.h>

char *to_lower_dofree(const char *s);

char *sorted_lowercase_string_dofree(char *s);

size_t latin1_hash_code(const char *s);

bool is_number(const char *s);

long to_long(const char *s);

char *strip_trailing_asterisk_dofree(const char *s);

char *trim(char *s);

#endif //CODE_KATA_C_STRINGS_H
