#include <stdarg.h>
#include <stddef.h>
// setjmp required
#include <setjmp.h>

#include "kata05/bloom_filter.h"

#include <cmocka.h>

static void test_initialize() {
    BloomFilter it;
    bloom_filter_init(&it);

    assert_false(it.test(&it, "Hello"));
}

static void test_one() {
    BloomFilter it;
    bloom_filter_init(&it);
    it.add_word(&it, "one");

    assert_true(it.test(&it, "one"));
}

static void test_dictionary() {
    BloomFilter it = bloom_filter_init_from_file("resources/wordlist.txt");

    assert_true(it.test(&it, "Hello"));
}

static void test_missing_word() {
    BloomFilter it = bloom_filter_init_from_file("resources/wordlist.txt");

    assert_false(it.test(&it, "F@@@@"));
}

static void test_tricky_word() {
    BloomFilter it = bloom_filter_init_from_file("resources/wordlist.txt");

    assert_false(it.test(&it, "beefburger's'"));
}

int main() {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(test_initialize),
            cmocka_unit_test(test_dictionary),
            cmocka_unit_test(test_one),
            cmocka_unit_test(test_missing_word),
            cmocka_unit_test(test_tricky_word),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
