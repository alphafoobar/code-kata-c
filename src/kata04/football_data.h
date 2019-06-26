#ifndef KATA04_FOOTBALL_DATA_H
#define KATA04_FOOTBALL_DATA_H

typedef struct football_data {
    char *name;
    int points_for;
    int points_against;
} FootballData;

int points_difference(FootballData *data);

FootballData *new_football_data_from_string(char *data);

FootballData *new_football_data(char *name, int points_for, int points_against);

void free_football_data(FootballData *data);

#endif //KATA04_FOOTBALL_DATA_H
