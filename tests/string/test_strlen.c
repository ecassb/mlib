#include "minunit.h"
#include "mlib_string.h"

MU_TEST(test_strlen_ok) {
    mu_assert_int_eq(5, mlib_strlen("hello"));
}

MU_TEST(test_strlen_empty_string) {
    mu_assert_int_eq(0, mlib_strlen(""));
}

MU_TEST_SUITE(string_test) {
    MU_RUN_TEST(test_strlen_ok);
    MU_RUN_TEST(test_strlen_empty_string);
}

int main(__attribute__ ((unused))int argc, __attribute__ ((unused))char** argv) {
    MU_RUN_SUITE(string_test);
	MU_REPORT();
	return MU_EXIT_CODE;
}
