#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <string.h>

#include "../now.h"
#include "file/read_file.h"

#include <cmocka.h>

static void test_unknown_file() {
    StringsList *const data = to_data("unknown file");
    assert_null(data);
    free_strings_list(data);
}

static void test_plus_string() {
    StringsList *const data = new_strings_list();

    plus_string(data, strdup("test"));
    assert_int_equal(data->lines_count, 1);
    free_strings_list(data);
}

static void test_weather_file() {
    StringsList *const data = to_data("resources/weather.dat");
    assert_true(data->lines_count > 0);
    free_strings_list(data);
}

static void test_read_first_lines() {
    StringsList *const data = to_data("resources/weather.dat");
    assert_string_equal("  Dy MxT   MnT   AvT   HDDay  AvDP 1HrP TPcpn WxType PDir AvSp Dir MxS SkyC MxR MnR AvSLP\n",
                        data->lines[0]);
    assert_string_equal("\n", data->lines[1]);
    assert_string_equal("  mo  82.9  60.5  71.7    16  58.8       0.00              6.9          5.3\n",
                        data->lines[32]);
    assert_string_equal("", data->lines[33]);
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
            cmocka_unit_test(test_plus_string),
            cmocka_unit_test(test_read_first_lines),
            cmocka_unit_test(test_football_file),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
