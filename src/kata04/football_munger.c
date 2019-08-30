#include <stdlib.h>

#include "football_munger.h"
#include "../file/read_file.h" // #to_data(string filename)

FootballMunger *read_football_file(const char *filename) {
    int count = 0;
    StringsList *file_data = to_data_dofree(filename);

    FootballMunger *munger = (FootballMunger *) malloc(sizeof(FootballMunger));
    FootballData **data = (FootballData **) malloc(file_data->lines_count * sizeof(FootballData *));
    munger->data = data;

    for (size_t i = 0; i < file_data->lines_count; i++) {
        FootballData *football_data = new_football_data_from_string(file_data->lines[i]);
        if (football_data != NULL) {
            data[count++] = football_data;
        }
    }

    munger->count = count;
    return munger;
}

FootballData *smallest_difference_score(FootballMunger *munger) {
    FootballData *smallest_data = NULL;
    for (size_t i = 0; i < munger->count; i++) {
        FootballData *data = munger->data[i];
        if (smallest_data == NULL || points_difference(data) < points_difference(smallest_data)) {
            smallest_data = data;
        }
    }
    return smallest_data;
}

void free_football_munger(FootballMunger *munger) {
    if (munger) {
        free((void *) munger->data);
    }
    free(munger);
}
