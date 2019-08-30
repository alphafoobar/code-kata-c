#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#include "strings.h"

char *null_terminate(char *s, const size_t new_length);

size_t new_string_length(const char *s, size_t length);

long str_to_long_with_error_handling(const char *s);

/*
 * Latin1 hash algorithm from JDK. New string created, called must manage memory for both input
 * and output strings.
 */
char *to_lower_dofree(const char *s) {
    char *r = malloc((strlen(s) + 1) * sizeof(char));
    size_t i = 0;
    for (; s[i]; i++) {
        r[i] = (char) tolower(s[i]);
    }
    r[i] = '\0';
    return r;
}

int ascending(void const *a, void const *b) {
    return (*(char *) a - *(char *) b);
}

char *sorted_lowercase_string_dofree(char *s) {
    char *lower = to_lower_dofree(s);
    const size_t length = strlen(s);
    size_t i = 0, j = 0;

    for (; i < length; i++) {
        if (isalnum(lower[i])) {
            lower[j++] = lower[i];
        }
    }
    lower[j] = '\0';
    qsort(lower, j, sizeof(char), ascending);
    return lower;
}

char *trim(char *s) {
    const size_t length = strlen(s);

    for (size_t i = 0; i < length; i++) {
        if (s[i] == '\n' || isblank(s[i])) {
            s[i] = '\0';
            return s;
        }
    }
    return s;
}

bool is_number(const char *s) {
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
 * 
 * Returns a new string pointer, result must be freed.
 */
char *strip_trailing_asterisk_dofree(const char *s) {
    char *duplicate = strdup(s);
    const size_t length = strlen(duplicate);
    const size_t new_length = new_string_length(duplicate, length);
    return null_terminate(duplicate, new_length);
}

size_t new_string_length(const char *s, const size_t length) {
    const size_t new_length = length - 1;
    if (new_length > 0 &&
        (s[new_length] == '*' || s[new_length] == '\n' || s[new_length] == '\r')) {
        return new_length;
    }
    return length;
}

char *null_terminate(char *s, const size_t new_length) {
    if (s != NULL && new_length > 0) {
        s[new_length] = '\0';
    }
    return s;
}

size_t latin1_hash_code(const char *const s) {
    const size_t length = strlen(s);

    size_t h = 0;
    for (size_t i = 0; i < length; i++) {
        const unsigned char unsigned_char = s[i];
        h = 31u * h + (unsigned_char & 0xffu);
    }
    return h;
}

long to_long(const char *s) {
    char *free_me = strip_trailing_asterisk_dofree(s);
    const long i = str_to_long_with_error_handling(free_me);
    free(free_me);
    return i;
}

long str_to_long_with_error_handling(const char *s) {
    if (is_number(s)) {
        char *end_pointer;
        const long result = strtol(s, &end_pointer, 10);
        /* If the result is 0, test for an error */
        if (result == 0) {
            /* If a conversion error occurred, display a message and exit */
            if (errno == EINVAL) {
                printf("Conversion error occurred: %d, s='%s'\n", errno, s);
            }

            /* If the value provided was out of range, display a warning message */
            if (errno == ERANGE) {
                printf("The value provided was out of range: s='%s'\n", s);
            }
        }
        return result;
    }
    return 0;
}
