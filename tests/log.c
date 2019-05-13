#include <stdio.h> // For printf.
#include <time.h> // For strftime.
#include "now.h" // For now.
#include "kata-test.h"

void ok_test_log(const TestInfo test_info, const char *message) {
    char time_str[26];
    strftime(time_str, 26, "%Y-%m-%d %H:%M:%S", now());
    printf("[%s] OK! %s:%d (%s) %s\n", time_str, test_info.file, test_info.line, test_info.description, message);
}

void print_test_log(const TestInfo test_info, const char *message) {
    char time_str[26];
    strftime(time_str, 26, "%Y-%m-%d %H:%M:%S", now());
    printf("[%s] %s:%d (%s) %s\n", time_str, test_info.file, test_info.line, test_info.description, message);
}