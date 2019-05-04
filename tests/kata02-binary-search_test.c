//
// Tests for kata02 - Karate Chop!
//
#include <stdio.h> // for printf & sprintf.
#include <stdlib.h> // for malloc.
#include <string.h> // for strcmp.
#include <time.h> // for string format time.
#include <stdbool.h> // for boolean type.
#include <math.h> // for log10.
#include "kata02-binary-search.h"
#include "now.h"
#include "log.h"

int calc_chars(int number) {
    if (number < 10) {
        // Numbers may be negative.
        return 2;
    }
    return (int) log10(number) + 2;
}

char *build_failure_message(int expected, int actual) {
    char *failure_message = (char *) malloc(calc_chars(abs(expected)) + 25 + calc_chars(abs(actual)) * sizeof(char));
    sprintf(failure_message, "Wanted %d but received %d", expected, actual);
    return failure_message;
}

int expect_eq(char *title, int expected, int actual) {
    const bool is_ok = expected == actual;
    char *string = is_ok ? "OK" : build_failure_message(expected, actual);

    print_log(title, string);

    if (is_ok) {
        return 0;
    }

    // Time to tidy!
    free(string);
    return 1;
}

int test_empty_array() {
    int array[] = {};
    return expect_eq("empty array", -1, chop(3, array, 0, 0));
}

int test_array_of_length_1() {
    int array[] = {1};
    return expect_eq("not found in 1", -1, chop(3, array, 0, 1))
           + expect_eq("found in 1", 0, chop(1, array, 0, 1));
}

int test_array_of_length_3() {
    int array[] = {1, 3, 5};
    return expect_eq("find 1st of 3", 0, chop(1, array, 0, 3))
           + expect_eq("find 2nd of 3", 1, chop(3, array, 0, 3))
           + expect_eq("find 3rd of 3", 2, chop(5, array, 0, 3))
           + expect_eq("not found of 3", -1, chop(0, array, 0, 3))
           + expect_eq("not found of 3", -1, chop(2, array, 0, 3))
           + expect_eq("not found of 3", -1, chop(4, array, 0, 3))
           + expect_eq("not found of 3", -1, chop(6, array, 0, 3));
}

int test_array_of_length_4() {
    int array[] = {1, 3, 5, 7};
    return expect_eq("find 1st in 4", 0, chop(1, array, 0, 4))
           + expect_eq("find 2nd in 4", 1, chop(3, array, 0, 4))
           + expect_eq("find 3rd in 4", 2, chop(5, array, 0, 4))
           + expect_eq("find 4th in 4", 3, chop(7, array, 0, 4))
           + expect_eq("not found of 4", -1, chop(0, array, 0, 4))
           + expect_eq("not found of 4", -1, chop(2, array, 0, 4))
           + expect_eq("not found of 4", -1, chop(4, array, 0, 4))
           + expect_eq("not found of 4", -1, chop(6, array, 0, 4))
           + expect_eq("not found of 4", -1, chop(8, array, 0, 4));
}

int main() {
    // Calculate the time taken by fun()
    clock_t t_0 = clock();
    char result[26];
    strftime(result, 26, "%Y-%m-%d %H:%M:%S", now());
    int test_result = test_empty_array()
                      + test_array_of_length_1()
                      + test_array_of_length_3()
                      + test_array_of_length_4();

    double time_taken = ((double) clock() - t_0) / CLOCKS_PER_SEC; // in seconds
    printf("[%s] (test) Finished%s In %f seconds\n", result, test_result == 0 ? "." : " with errors!", time_taken);
    return test_result;
}
