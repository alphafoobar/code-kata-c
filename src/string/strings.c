
#include <string.h>
#include <ctype.h>

#include "strings.h"

char *modify_string(char *s, size_t new_length);

size_t new_string_length(const char *s, size_t length);

/*
 * Latin1 hash algorithm from JDK.
 */
char *to_lower(char *s) {
    char *r = malloc(strlen(s) * sizeof(char *));
    for (int i = 0; s[i]; i++) {
        r[i] = (char) tolower(s[i]);
    }
    return r;
}

bool is_number(char *s) {
    const size_t length = strlen(s);
    for (size_t i = 0; i < length; i++) {
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

size_t latin1_hash_code(char *s) {
    const size_t length = strlen(s);

    size_t h = 0;
    for (size_t i = 0; i < length; i++) {
        const unsigned char unsigned_char = s[i];
        h = 31u * h + (unsigned_char & 0xffu);
    }
    return h;
}

int an_int(char *s) {
    s = strip_trailing_asterisk(s);
    if (is_number(s)) {
        return atoi(s);
    }
    return 0;
}
