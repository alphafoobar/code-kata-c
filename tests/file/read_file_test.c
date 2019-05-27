#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>

#include "../now.h"
#include "file/read_file.h"

#include <cmocka.h>

static void test_unknown_file() {
    StringsList *const data = to_data("unknown file");
    assert_null(data);
    free_strings_list(data);
}

static void test_weather_file() {
    StringsList *const data = to_data("resources/weather.dat");
    assert_true(data->lines_count > 0);
    free_strings_list(data);
}

static void test_football_file() {
    StringsList *const data = to_data("resources/football.dat");
    assert_true(data->lines_count > 0);
    free_strings_list(data);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(test_unknown_file),
            cmocka_unit_test(test_weather_file),
            cmocka_unit_test(test_football_file),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}