#ifndef KATA04_FOOTBALL_MUNGER_H
#define KATA04_FOOTBALL_MUNGER_H

#include "football_data.h"

typedef struct football_munger {
    FootballData **data;
    int count;
} FootballMunger;

FootballMunger *read_football_file(const char *filename);

FootballData *smallest_difference_score(FootballMunger *munger);

void free_football_munger(FootballMunger *munger);

#endif //KATA04_FOOTBALL_MUNGER_H
