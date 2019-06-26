#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>

#include "kata04/football_data.h"

#include <cmocka.h>

static void test_read_team_name() {
    FootballData *data = new_football_data_from_string("    1. Arsenal         38    26   9   3    79  -  36    87");
    assert_string_equal("Arsenal", data->name);
    free_football_data(data);
}

static void test_read_normal_data() {
    FootballData *data = new_football_data_from_string("    1. Arsenal         38    26   9   3    79  -  36    87");
    assert_int_equal(43, points_difference(data));
    free_football_data(data);
}

static void test_read_title_row() {
    FootballData *data = new_football_data_from_string("       Team            P     W    L   D    F      A     Pts");
    assert_null(data);
    free_football_data(data);
}

static void test_read_skip_empty_row() {
    FootballData *data = new_football_data_from_string("   -------------------------------------------------------");
    assert_null(data);
    free_football_data(data);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(test_read_team_name),
            cmocka_unit_test(test_read_normal_data),
            cmocka_unit_test(test_read_title_row),
            cmocka_unit_test(test_read_skip_empty_row),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}