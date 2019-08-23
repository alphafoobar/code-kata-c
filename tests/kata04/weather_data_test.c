#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>

#include "kata04/weather_data.h"

#include <cmocka.h>

static void test_handles_asterix() {
    WeatherData *data = new_weather_data_from_string(
            "  26  97*   64    81          70.4       0.00 H       050  5.1 200  12  4.0 107 45 1014.9");
    assert_int_equal(33, temperature_difference(data));
    free_weather_data(data);
}

static void test_handles_normal_data() {
    WeatherData *data = new_weather_data_from_string(
            "   5  90    66    78          68.3       0.00 TFH     220  8.3 260  12  6.9  84 55 1014.4");
    assert_int_equal(24, temperature_difference(data));
    free_weather_data(data);
}

static void test_skips_title() {
    WeatherData *data = new_weather_data_from_string(
            "  Dy MxT   MnT   AvT   HDDay  AvDP 1HrP TPcpn WxType PDir AvSp Dir MxS SkyC MxR MnR AvSLP");
    assert_null(data);
    free_weather_data(data);
}

static void test_skips_invalid_data() {
    WeatherData *data = new_weather_data_from_string(
            "  mo  82.9  60.5  71.7    16  58.8       0.00              6.9          5.3");
    assert_null(data);
    free_weather_data(data);
}

static void test_skips_data() {
    WeatherData *data = new_weather_data_from_string("  ");
    assert_null(data);
    free_weather_data(data);
}

int main() {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(test_handles_asterix),
            cmocka_unit_test(test_handles_normal_data),
            cmocka_unit_test(test_skips_title),
            cmocka_unit_test(test_skips_invalid_data),
            cmocka_unit_test(test_skips_data),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}

