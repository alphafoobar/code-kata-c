#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <string.h>

#include "../now.h"
#include "string/list.h"

#include <cmocka.h>

static void test_plus_string() {
    StringsList *const data = new_strings_list();

    plus_string(data, strdup("test-1"));
    plus_string(data, strdup("test-2"));
    assert_int_equal(data->lines_count, 2);
    free_strings_list(data);
}

static void test_plus_string_already_exists() {
    StringsList *const data = new_strings_list();

    plus_string(data, strdup("test"));
    plus_string(data, strdup("test"));
    assert_int_equal(data->lines_count, 1);
    free_strings_list(data);
}

int main() {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(test_plus_string),
            cmocka_unit_test(test_plus_string_already_exists)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
