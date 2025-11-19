#include "minunit.h"
// Include your needes headers here
#include "mlib_string.h"

// Add your test function with MU_TEST(name)
MU_TEST (test_strcmp_good_equal) {
    char* s1 = "Hello";
    char* s2 = "Hello";

    mu_assert_int_eq (0, mlib_strcmp (s1, s2));
}

MU_TEST (test_strcmp_good_less) {
    char* less = "Hell";
    char* more = "Hello";

    mu_assert_int_eq (-1, mlib_strcmp (less, more));
}

MU_TEST (test_strcmp_good_more) {
    char* less = "Hell";
    char* more = "Hello";

    mu_assert_int_eq (1, mlib_strcmp (more, less));
}

MU_TEST (test_strcmp_good_equal_less) {
    char* less = "Hello";
    char* more = "Hellp";

    mu_assert_int_eq (-1, mlib_strcmp (less, more));
}

MU_TEST (test_strcmp_good_equal_more) {
    char* less = "Hello";
    char* more = "Hellp";

    mu_assert_int_eq (1, mlib_strcmp (more, less));
}

MU_TEST (test_strcmp_same_pointer) {
    char* s = "hello";

    mu_assert_int_eq (0, mlib_strcmp (s, s));
}

MU_TEST (test_strncmp_good_equal_less_count) {
    char* s1 = "hello";
    char* s2 = "hello";

    mu_assert_int_eq (0, mlib_strncmp (s1, s2, 8));
}

MU_TEST (test_strncmp_good_equal_more_count) {
    char* s1 = "hello";
    char* s2 = "hello";

    mu_assert_int_eq (0, mlib_strncmp (s1, s2, 4));
}

MU_TEST (test_strncmp_good_equal_count) {
    char* s1 = "hello";
    char* s2 = "hello";

    mu_assert_int_eq (0, mlib_strncmp (s1, s2, 6));
}

MU_TEST (test_strncmp_good_less_bigger_count) {
    char* less = "Hell";
    char* more = "Hello";

    mu_assert_int_eq (-1, mlib_strncmp (less, more, 5));
}

MU_TEST (test_strncmp_good_less_less_count) {
    char* less = "Hele";
    char* more = "Hello";

    mu_assert_int_eq (-1, mlib_strncmp (less, more, 4));
}

MU_TEST (test_strncmp_good_more_bigger_count) {
    char* less = "Hell";
    char* more = "Hello";

    mu_assert_int_eq (1, mlib_strncmp (more, less, 5));
}

MU_TEST (test_strncmp_good_more_less_count) {
    char* less = "Hell";
    char* more = "Helpo";

    mu_assert_int_eq (1, mlib_strncmp (more, less, 4));
}

MU_TEST (test_strncmp_count_zero) {
    char* s1 = "hello";
    char* s2 = "Hello";

    mu_assert_int_eq (0, mlib_strncmp (s1, s2, 0));
}

MU_TEST_SUITE (test_strcmp) {
    // Add the tests to run here with MU_RUN_TEST(name)
    MU_RUN_TEST (test_strcmp_good_equal);
    MU_RUN_TEST (test_strcmp_good_less);
    MU_RUN_TEST (test_strcmp_good_more);
    MU_RUN_TEST (test_strcmp_good_equal_less);
    MU_RUN_TEST (test_strcmp_good_equal_more);
    MU_RUN_TEST (test_strcmp_same_pointer);
    MU_RUN_TEST (test_strncmp_count_zero);
    MU_RUN_TEST (test_strncmp_good_equal_count);
    MU_RUN_TEST (test_strncmp_good_equal_less_count);
    MU_RUN_TEST (test_strncmp_good_equal_more_count);
    MU_RUN_TEST (test_strncmp_good_less_bigger_count);
    MU_RUN_TEST (test_strncmp_good_less_less_count);
    MU_RUN_TEST (test_strncmp_good_more_bigger_count);
    MU_RUN_TEST (test_strncmp_good_more_less_count);
}

int main (__attribute__ ((unused)) int argc, __attribute__ ((unused)) char** argv) {
    MU_RUN_SUITE (test_strcmp);
    MU_REPORT ();
    return MU_EXIT_CODE;
}
