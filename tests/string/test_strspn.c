#include "minunit.h"
// Include your needes headers here
#include "mlib_string.h"
// Add your test function with MU_TEST(name)

MU_TEST (test_strspn_good) {
    const char* word = "Hello World";
    const char* charset = "oWr";

    size_t length = mlib_strspn (word, charset);
    mu_assert_int_eq (3, length);
}

MU_TEST (test_strspn_chars_not_in_word) {
    const char* word = "Hello World";
    const char* charset = "jk";

    size_t length = mlib_strspn (word, charset);
    mu_assert_int_eq (0, length);
}

MU_TEST (test_strspn_two_spans_shorter_first) {
    const char* word = "World Hello";
    const char* charset = "l";

    size_t length = mlib_strspn (word, charset);
    mu_assert_int_eq (2, length);
}

MU_TEST (test_strspn_two_spans_shorter_last) {
    const char* word = "Hello World";
    const char* charset = "l";

    size_t length = mlib_strspn (word, charset);
    mu_assert_int_eq (2, length);
}

MU_TEST (test_strspn_two_spans_eq_length) {
    const char* word = "Hello Worlld";
    const char* charset = "l";

    size_t length = mlib_strspn (word, charset);
    mu_assert_int_eq (2, length);
}

MU_TEST (test_strcspn_good) {
    const char* word = "Hello World";
    const char* charset = "oWr";

    size_t length = mlib_strcspn (word, charset);
    mu_assert_int_eq (4, length);
}

MU_TEST (test_strcspn_chars_not_in_word) {
    const char* word = "Hello World";
    const char* charset = "jk";

    size_t length = mlib_strcspn (word, charset);
    mu_assert_int_eq (11, length);
}

MU_TEST (test_strcspn_all_chars_in_word) {
    const char* word = "World Hello";
    const char* charset = "WHor lde";

    size_t length = mlib_strcspn (word, charset);
    mu_assert_int_eq (0, length);
}

MU_TEST_SUITE (test_strspn) {
    // Add the tests to run here with MU_RUN_TEST(name)
    MU_RUN_TEST (test_strspn_good);
    MU_RUN_TEST (test_strspn_chars_not_in_word);
    MU_RUN_TEST (test_strspn_two_spans_eq_length);
    MU_RUN_TEST (test_strspn_two_spans_shorter_first);
    MU_RUN_TEST (test_strspn_two_spans_shorter_last);
    MU_RUN_TEST (test_strcspn_good);
    MU_RUN_TEST (test_strcspn_chars_not_in_word);
    MU_RUN_TEST (test_strcspn_all_chars_in_word);
}

int main (__attribute__ ((unused)) int argc, __attribute__ ((unused)) char** argv) {
    MU_RUN_SUITE (test_strspn);
    MU_REPORT ();
    return MU_EXIT_CODE;
}
