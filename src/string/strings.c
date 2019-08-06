#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "strings.h"

char *modify_string(char *s, size_t new_length);

size_t new_string_length(const char *s, size_t length);

bool is_number(char *s) {
    const size_t length = strlen(s);
    for (int i = 0; i < length; i++) {
        if (!isdigit(s[i])) {
            return false;
        }
    }
    return true;
}

/*
 * This function has a side effect on s, if the last character is an '*', it is replaced with the NULL character '\0'.
 */
char *strip_trailing_asterisk(const char *s) {
    char *duplicate = strdup(s);
    const size_t length = strlen(duplicate);
    const size_t new_length = new_string_length(duplicate, length);
    return modify_string(duplicate, new_length);
}

size_t new_string_length(const char *s, const size_t length) {
    const size_t new_length = length - 1;
    if (new_length > 0 && s[new_length] == '*') {
        return new_length;
    }
    return length;
}

char *modify_string(char *s, const size_t new_length) {
    if (new_length > 0 && s[new_length] == '*') {
        s[new_length] = '\0';
    }
    return s;
}

int an_int(char *s) {
    s = strip_trailing_asterisk(s);
    if (is_number(s)) {
        return atoi(s);
    }
    return 0;
}
