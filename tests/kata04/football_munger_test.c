#include <stdarg.h>
#include <stddef.h>
// setjmp required
#include <setjmp.h>

#include "kata04/football_munger.h"

#include <cmocka.h>

static void test_read_team_name() {
    FootballMunger *munger = read_football_file("resources/football.dat");
    assert_string_equal("Aston_Villa", smallest_difference_score(munger)->name);
    free_football_munger(munger);
}

static void test_munger_count() {
    FootballMunger *munger = read_football_file("resources/football.dat");
    assert_int_equal(20, munger->count);
    free_football_munger(munger);
}

static void test_munger_name() {
    FootballMunger *munger = read_football_file("resources/football.dat");
    assert_string_equal("Liverpool", munger->data[1]->name);
    free_football_munger(munger);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(test_read_team_name),
            cmocka_unit_test(test_munger_name),
            cmocka_unit_test(test_munger_count)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
