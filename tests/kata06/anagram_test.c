#include <stdarg.h>
#include <stddef.h>
// setjmp required
#include <setjmp.h>
#include <string.h>

#include "kata06/anagram.h"

#include <cmocka.h>
#include <search.h>

static void test_anagrams() {
    StringsList *const actual = anagrams_dofree(strdup("test-word-that-isn't-there"));
    assert_null(actual);
    free_strings_list(actual);
}

static void test_anagrams_load_word() {
    StringsList *const actual = anagrams_dofree(strdup("word"));

    assert_non_null(actual);
    assert_int_equal(actual->lines_count, 3);
    free_strings_list(actual);
}

static void test_anagrams_load_paste() {
    StringsList *const actual = anagrams_dofree(strdup("paste"));

    assert_non_null(actual);
    // Should only be 12 versions of paste.
    assert_int_equal(actual->lines_count, 12);
    free_strings_list(actual);
}

int main() {
    // Since this is a little intense and it's static anyway, just doing this once.
    hcreate(500000);
    load_anagrams("resources/wordlist.txt");

    const struct CMUnitTest tests[] = {
            cmocka_unit_test(test_anagrams),
            cmocka_unit_test(test_anagrams_load_word),
            cmocka_unit_test(test_anagrams_load_paste),
    };
    const int result = cmocka_run_group_tests(tests, NULL, NULL);
    hdestroy();
    return result;
}
