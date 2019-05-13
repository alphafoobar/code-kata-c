//
// Tests for kata02 - Karate Chop!
//
#include <stdio.h> // for printf & sprintf.
#include <time.h> // for string format time.
#include "kata02/kata02-binary-search.h"
#include "../kata-test.h"
#include "../now.h"
#include "../log.h"

int empty_array[] = {};
int array_of_one[] = {1};

int test_empty_array() {
    return expect_eq(DESC_TEST("empty array"), -1, chop(3, empty_array, 0, 0));
}

int test_found_in_array_of_length_1() {
    return expect_eq(DESC_TEST("found in 1"), 0, chop(1, array_of_one, 0, 1));
}

int test_not_found_array_of_length_1() {
    return expect_eq(DESC_TEST("not found in 1"), -1, chop(3, array_of_one, 0, 1));
}

int test_array_of_length_3() {
    int array[] = {1, 3, 5};
    return expect_eq(DESC_TEST("find 1st of 3"), 0, chop(1, array, 0, 3))
           + expect_eq(DESC_TEST("find 2nd of 3"), 1, chop(3, array, 0, 3))
           + expect_eq(DESC_TEST("find 3rd of 3"), 2, chop(5, array, 0, 3))
           + expect_eq(DESC_TEST("not found of 3"), -1, chop(0, array, 0, 3))
           + expect_eq(DESC_TEST("not found of 3"), -1, chop(2, array, 0, 3))
           + expect_eq(DESC_TEST("not found of 3"), -1, chop(4, array, 0, 3))
           + expect_eq(DESC_TEST("not found of 3"), -1, chop(6, array, 0, 3));
}

int test_array_of_length_4() {
    int array[] = {1, 3, 5, 7};
    return expect_eq(DESC_TEST("find 1st in 4"), 0, chop(1, array, 0, 4))
           + expect_eq(DESC_TEST("find 2nd in 4"), 1, chop(3, array, 0, 4))
           + expect_eq(DESC_TEST("find 3rd in 4"), 2, chop(5, array, 0, 4))
           + expect_eq(DESC_TEST("find 4th in 4"), 3, chop(7, array, 0, 4))
           + expect_eq(DESC_TEST("not found of 4"), -1, chop(0, array, 0, 4))
           + expect_eq(DESC_TEST("not found of 4"), -1, chop(2, array, 0, 4))
           + expect_eq(DESC_TEST("not found of 4"), -1, chop(4, array, 0, 4))
           + expect_eq(DESC_TEST("not found of 4"), -1, chop(6, array, 0, 4))
           + expect_eq(DESC_TEST("not found of 4"), -1, chop(8, array, 0, 4));
}

int main() {
    // Calculate the time taken by fun()
    clock_t t_0 = clock();
    char result[26];
    strftime(result, 26, "%Y-%m-%d %H:%M:%S", now());
    int test_result = test_empty_array()
                      + test_found_in_array_of_length_1()
                      + test_not_found_array_of_length_1()
                      + test_array_of_length_3()
                      + test_array_of_length_4();

    double time_taken = ((double) clock() - t_0) / CLOCKS_PER_SEC; // in seconds
    printf("[%s] (test) Finished%s In %f seconds\n", result, test_result == 0 ? "." : " with errors!", time_taken);
    return test_result;
}
