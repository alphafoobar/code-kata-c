#include <stdarg.h>
#include <stddef.h>
// setjmp required
#include <setjmp.h>

#include "kata04/weather_munger.h"

#include <cmocka.h>

static void test_read_smallest_difference_temperature() {
    WeatherMunger *munger = read_weather_file("resources/weather.dat");
    assert_int_equal(14, smallest_difference_temperature(munger)->day);
    free_weather_munger(munger);
}

static void test_munger_count() {
    WeatherMunger *munger = read_weather_file("resources/weather.dat");
    assert_int_equal(30, munger->count);
    free_weather_munger(munger);
}

static void test_munger_day() {
    WeatherMunger *munger = read_weather_file("resources/weather.dat");
    assert_int_equal(2, munger->data[1]->day);
    free_weather_munger(munger);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(test_read_smallest_difference_temperature),
            cmocka_unit_test(test_munger_day),
            cmocka_unit_test(test_munger_count)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
