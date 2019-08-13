#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdlib.h>

#include "string/strings.h"

#include <cmocka.h>

static void test_hello_hash_code() {
    int result = latin1_hash_code("Hello");
    assert_int_equal(69609650, result);
}

static void test_make_hello_lower() {
    char *result = to_lower("Hello");
    assert_string_equal("hello", result);
}

static void test_make_pyramid_lower() {
    char *result = to_lower("thisIsit");
    assert_string_equal("thisisit", result);
}

static void test_an_int_is_87() {
    int result = an_int("87");
    assert_int_equal(87, result);
}

static void test_a_not_int_is_0() {
    int result = an_int("87.");
    assert_int_equal(0, result);
}

static void test_an_int_with_an_asterix_is_87() {
    int result = an_int("87*");
    assert_int_equal(87, result);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(test_an_int_is_87),
            cmocka_unit_test(test_a_not_int_is_0),
            cmocka_unit_test(test_an_int_with_an_asterix_is_87),
            cmocka_unit_test(test_make_hello_lower),
            cmocka_unit_test(test_make_pyramid_lower),
            cmocka_unit_test(test_hello_hash_code),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
