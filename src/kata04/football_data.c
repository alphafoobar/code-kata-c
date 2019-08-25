#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "football_data.h"

#include "../string/tokenizer.h"
#include "../string/strings.h"

FootballData *new_football_data(char *name, int points_for, int points_against) {
    FootballData *data = (FootballData *) malloc(sizeof(FootballData));
    data->name = name;
    data->points_for = points_for;
    data->points_against = points_against;
    return data;
}

int points_difference(FootballData *data) {
    return abs(data->points_for - data->points_against);
}

FootballData *new_football_data_from_string(char *data) {
    size_t number_of_tokens = 0;
    char **tokens = tokenize_string(data, " ", &number_of_tokens);
    if (number_of_tokens < 10) {
        free_array_of_strings(tokens, number_of_tokens);
        return NULL;
    }

    char *name = strdup(tokens[1]); // dup string to allow token to be managed.
    int points_for = an_int(tokens[6]);
    int points_against = an_int(tokens[8]);

    free_array_of_strings(tokens, number_of_tokens);

    return new_football_data(name, points_for, points_against);
}

void free_football_data(FootballData *data) {
    if (data) {
        free((void *) data->name);
    }
    free(data);
}
