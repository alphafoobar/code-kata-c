#include <stdio.h> // for printf & sprintf.
#include <stdlib.h> // for malloc.
#include <string.h> // for strcmp.
#include <stdbool.h> // for boolean type.
#include <math.h> // for log10.

#include "kata-test.h"
#include "log.h"

TestInfo create_test_info(const char *file, const char *function, const char *description, int line) {
    TestInfo info = {file, function, description, line};
    return info;
}

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

int expect_eq(const TestInfo test_info, int expected, int actual) {
    const bool is_ok = expected == actual;
    char *string = is_ok ? "OK" : build_failure_message(expected, actual);

    print_test_log(test_info, string);

    if (is_ok) {
        return 0;
    }

    // Time to tidy!
    free(string);
    return 1;
}
