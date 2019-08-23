#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tokenizer.h"

/*
 * Returned tokens are the responsibility of the caller to free.
 * This code based on this stackoverflow answer in
 */
char **tokenize_string(const char *s, const char *delimiter, size_t *num_tokens) {
    char *duplicate = strdup(s);
    size_t tokens_alloc = 1;
    size_t tokens_used = 0;
    char **tokens = calloc(tokens_alloc, sizeof(char *));
    char *token;
    char *rest = duplicate;
    while ((token = strsep(&rest, delimiter)) != NULL) {
        if (tokens_used == tokens_alloc) {
            tokens_alloc *= 2;
            tokens = realloc(tokens, tokens_alloc * sizeof(char *));
        }

        // Don't store empty strings.
        if (token[0] != '\0') {
            tokens[tokens_used++] = strdup(token);
        }
    }
    if (tokens_used == 0) {
        free(tokens);
        tokens = NULL;
    } else {
        tokens = realloc(tokens, tokens_used * sizeof(char *));
    }
    *num_tokens = tokens_used;
    free(duplicate);
    return tokens;
}

void free_array_of_strings(char **tokens, size_t number_of_tokens) {
    for (size_t i = 0; i < number_of_tokens; i++) {
        free(tokens[i]);
    }
    free(tokens);
}
