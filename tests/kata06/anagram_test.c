#include <stdarg.h>
#include <stddef.h>
// setjmp required
#include <setjmp.h>
#include <string.h>

#include "kata06/anagram.h"

#include <cmocka.h>
#include <search.h>

static void test_anagrams() {
    StringsList *actual = anagrams(strdup("hello"));
    assert_null(actual);
    free_strings_list(actual);
}

static void test_anagrams_load_word() {
    load_anagrams("resources/wordlist.txt");

    assert_non_null(anagrams("word"));
}

static void test_anagrams_load_paste() {
    load_anagrams("resources/wordlist.txt");

    StringsList *const list = anagrams("paste");
    // Should only be 10 versions of paste.
//    assert_int_equal(list->lines_count, 10);
    assert_non_null(list);
}

int main() {
    // Create dictionary in advance.
    hcreate(200000);

    const struct CMUnitTest tests[] = {
            cmocka_unit_test(test_anagrams),
            cmocka_unit_test(test_anagrams_load_word),
            cmocka_unit_test(test_anagrams_load_paste)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
