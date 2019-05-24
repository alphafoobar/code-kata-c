//
// Tests for kata02 - Karate Chop!
//
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>

#include <string.h>

#include <stdio.h> // for printf & sprintf.
#include <time.h> // for string format time.
#include "kata02/kata02-binary-search.h"
#include "../now.h"
#include "../log.h"

#include <cmocka.h>

int empty_array[] = {};
int array_of_one[] = {1};

static void test_empty_array() {
    assert_int_equal(-1, chop(3, empty_array, 0, 0));
}

static void test_found_in_array_of_length_1() {
    assert_int_equal(0, chop(1, array_of_one, 0, 1));
}

static void test_not_found_array_of_length_1() {
    assert_int_equal(-1, chop(3, array_of_one, 0, 1));
}

static void test_array_of_length_3() {
    int array[] = {1, 3, 5};

    assert_int_equal(0, chop(1, array, 0, 3));
    assert_int_equal(1, chop(3, array, 0, 3));
    assert_int_equal(2, chop(5, array, 0, 3));
    assert_int_equal(-1, chop(0, array, 0, 3));
    assert_int_equal(-1, chop(2, array, 0, 3));
    assert_int_equal(-1, chop(4, array, 0, 3));
    assert_int_equal(-1, chop(6, array, 0, 3));
}

static void test_array_of_length_4() {
    int array[] = {1, 3, 5, 7};

    assert_int_equal(0, chop(1, array, 0, 4));
    assert_int_equal(1, chop(3, array, 0, 4));
    assert_int_equal(2, chop(5, array, 0, 4));
    assert_int_equal(3, chop(7, array, 0, 4));
    assert_int_equal(-1, chop(0, array, 0, 4));
    assert_int_equal(-1, chop(2, array, 0, 4));
    assert_int_equal(-1, chop(4, array, 0, 4));
    assert_int_equal(-1, chop(6, array, 0, 4));
    assert_int_equal(-1, chop(8, array, 0, 4));
}

int main(int argc, char *argv[]) {
    // Calculate the time taken by fun()
    clock_t t_0 = clock();
    char result[26];
    strftime(result, 26, "%Y-%m-%d %H:%M:%S", now());

    const struct CMUnitTest tests[] = {
            cmocka_unit_test(test_empty_array),
            cmocka_unit_test(test_found_in_array_of_length_1),
            cmocka_unit_test(test_not_found_array_of_length_1),
            cmocka_unit_test(test_array_of_length_3),
            cmocka_unit_test(test_array_of_length_4),
    };

    const int test_outcome = cmocka_run_group_tests(tests, NULL, NULL);

    double time_taken = ((double) clock() - t_0) / CLOCKS_PER_SEC; // in seconds
    printf("[%s] (test) Finished%s In %f seconds\n", result, test_outcome == 0 ? "." : " with errors!", time_taken);

    return test_outcome;
}
