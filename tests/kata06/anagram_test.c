#include <stdarg.h>
#include <stddef.h>
// setjmp required
#include <setjmp.h>
#include <string.h>

#include "kata06/anagram.h"

#include <cmocka.h>

static void test_anagrams() {
    StringsList *actual = anagrams(strdup("hello"));

    assert_int_equal(actual->lines_count, 1);
    free_strings_list(actual);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(test_anagrams),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
