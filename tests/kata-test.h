#ifndef C_KATA_TEST_H
#define C_KATA_TEST_H

#ifndef DESC_TEST
#define DESC_TEST(desc) create_test_info(__FILE__, __func__, desc, __LINE__)
#endif// DESC_TEST

typedef struct TEST_INFO {
    const char *file;
    const char *function;
    const char *description;
    const int line;
} TestInfo;

TestInfo create_test_info(const char *file, const char *function, const char *description, int line);

int expect_eq(TestInfo test_info, int expected, int actual);

#endif //C_KATA_TEST_H
