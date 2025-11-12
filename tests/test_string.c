#include "minunit.h"
#include "string.h"

MU_TEST(test_strlen_ok) {
    mu_assert_int_eq(5, strlen("hello"));
}

MU_TEST_SUITE(string_test) {
    MU_RUN_TEST(test_strlen_ok);
}

int main(__attribute__ ((unused))int argc, __attribute__ ((unused))char** argv) {
    MU_RUN_SUITE(string_test);
	MU_REPORT();
	return MU_EXIT_CODE;
}
