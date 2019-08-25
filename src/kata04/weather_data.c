#include <stdio.h>
#include <stdlib.h>

#include "weather_data.h"

#include "../string/tokenizer.h"
#include "../string/strings.h"

WeatherData *new_weather_data(int day, int min, int max) {
    WeatherData *data = (WeatherData *) malloc(sizeof(WeatherData));
    data->day = day;
    data->min = min;
    data->max = max;
    return data;
}

int temperature_difference(WeatherData *data) {
    return abs(data->max - data->min);
}

WeatherData *new_weather_data_from_string(char *data) {
    size_t number_of_tokens = 0;
    char **tokens = tokenize_string(data, " ", &number_of_tokens);
    if (number_of_tokens < 4) {
        free_array_of_strings(tokens, number_of_tokens);
        return NULL;
    }

    int day = an_int(tokens[0]);
    int max = an_int(tokens[1]);
    int min = an_int(tokens[2]);

    free_array_of_strings(tokens, number_of_tokens);

    // Day starts at 1. Anything less is invalid data.
    if (day < 1) {
        return NULL;
    }

    return new_weather_data(day, min, max);
}

void free_weather_data(WeatherData *data) {
    free(data);
}
