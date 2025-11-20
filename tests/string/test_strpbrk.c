#include "minunit.h"
// Include your needes headers here
#include "mlib_string.h"
// Add your test function with MU_TEST(name)
MU_TEST (test_strpbrk_good) {
    char* haystack = "Hello World";
    char* charset = "ew";

    mu_assert (&haystack[1] == mlib_strpbrk (haystack, charset), "Should match");
}

MU_TEST (test_strpbrk_good_switched) {
    char* haystack = "Hello World";
    char* charset = "we";

    mu_check (&haystack[1] == mlib_strpbrk (haystack, charset));
}

MU_TEST (test_strpbrk_empty_charset) {
    char* haystack = "Hello World";
    char* charset = "";

    mu_check (nullptr == mlib_strpbrk (haystack, charset));
}

MU_TEST (test_strpbrk_empty_string) {
    char* haystack = "";
    char* charset = "ew";

    mu_check (nullptr == mlib_strpbrk (haystack, charset));
}

MU_TEST (test_strpbrk_chars_not_in_haystack) {
    char* haystack = "Cool";
    char* charset = "ew";

    mu_check (nullptr == mlib_strpbrk (haystack, charset));
}

MU_TEST_SUITE (test_strpbrk) {
    // Add the tests to run here with MU_RUN_TEST(name)
    MU_RUN_TEST (test_strpbrk_good);
    MU_RUN_TEST (test_strpbrk_good_switched);
    MU_RUN_TEST (test_strpbrk_empty_charset);
    MU_RUN_TEST (test_strpbrk_empty_string);
    MU_RUN_TEST (test_strpbrk_chars_not_in_haystack);
}

int main (__attribute__ ((unused)) int argc, __attribute__ ((unused)) char** argv) {
    MU_RUN_SUITE (test_strpbrk);
    MU_REPORT ();
    return MU_EXIT_CODE;
}
