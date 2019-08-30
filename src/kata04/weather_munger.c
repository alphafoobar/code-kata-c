#include <stdlib.h>

#include "weather_munger.h"
#include "../file/read_file.h" // #to_data(string filename)

WeatherMunger *read_weather_file(const char *filename) {
    int count = 0;
    StringsList *file_data = to_data_dofree(filename);

    WeatherMunger *munger = (WeatherMunger *) malloc(sizeof(WeatherMunger));
    WeatherData **data = (WeatherData **) malloc(file_data->lines_count * sizeof(WeatherData *));
    munger->data = data;

    for (size_t i = 0; i < file_data->lines_count; i++) {
        WeatherData *weather_data = new_weather_data_from_string(file_data->lines[i]);
        if (weather_data != NULL) {
            data[count++] = weather_data;
        }
    }

    munger->count = count;
    return munger;
}

WeatherData *smallest_difference_temperature(WeatherMunger *munger) {
    WeatherData *smallest_data = NULL;
    for (size_t i = 0; i < munger->count; i++) {
        WeatherData *data = munger->data[i];
        if (smallest_data == NULL || temperature_difference(data) < temperature_difference(smallest_data)) {
            smallest_data = data;
        }
    }
    return smallest_data;
}

void free_weather_munger(WeatherMunger *munger) {
    if (munger) {
        free((void *) munger->data);
    }
    free(munger);
}
