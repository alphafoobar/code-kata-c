#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdlib.h>

#include "string/tokenizer.h"

#include <cmocka.h>

static void test_tokenize_string() {
    size_t number_of_tokens = -1;
    char **tokens = tokenize_string("    1. Arsenal         38    26   9   3    79  -  36    87", " ",
                                    &number_of_tokens);
    assert_int_equal(10, number_of_tokens);
    assert_string_equal("Arsenal", tokens[1]);
    assert_string_equal("87", tokens[9]);

    for (int i = 0; i < number_of_tokens; i++) {
        free(tokens[i]);
    }
    free(tokens);
}

int main(int argc, char *argv[]) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(test_tokenize_string),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}