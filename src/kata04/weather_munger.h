#ifndef KATA04_WEATHER_MUNGER_H
#define KATA04_WEATHER_MUNGER_H

#include "weather_data.h"

typedef struct weather_munger {
    WeatherData **data;
    int count;
} WeatherMunger;

WeatherMunger *read_weather_file(const char *filename);

WeatherData *smallest_difference_temperature(WeatherMunger *munger);

void free_weather_munger(WeatherMunger *munger);

#endif //KATA04_WEATHER_MUNGER_H
