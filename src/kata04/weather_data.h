#ifndef KATA04_WEATHER_DATA_H
#define KATA04_WEATHER_DATA_H

typedef struct weather_data {
    int day;
    int min;
    int max;
} WeatherData;

int temperature_difference(WeatherData *data);

WeatherData *new_weather_data_from_string(char *data);

WeatherData *new_weather_data(int day, int min, int max);

void free_weather_data(WeatherData *data);

#endif //KATA04_WEATHER_DATA_H
