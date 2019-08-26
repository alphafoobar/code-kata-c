#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <string.h>

#include "../now.h"
#include "string/list.h"

#include <cmocka.h>

static void test_plus_string() {
    StringsList *const data = new_strings_list();

    plus_string(data, strdup("test"));
    assert_int_equal(data->lines_count, 1);
    free_strings_list(data);
}

int main() {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(test_plus_string),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
