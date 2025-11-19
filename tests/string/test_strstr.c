#include "minunit.h"
// Include your needes headers here
#include "mlib_string.h"
// Add your test function with MU_TEST(name)
MU_TEST (test_strstr_const_good) {
    const char* haystack = "Hello World, I am Erik";
    const char* needle = "World";

    const char* ptr = mlib_strstr (haystack, needle);
    mu_assert (ptr == &haystack[6], "Should be Adress of 7th Char in haystack");
}

MU_TEST (test_strstr_const_empty_neelde) {
    const char* haystack = "Hello World, I am Erik";
    const char* needle = "";

    const char* ptr = mlib_strstr (haystack, needle);
    mu_assert (ptr == haystack, "Should be Adress of haystack");
}

MU_TEST (test_strstr_const_bad_neelde_too_long) {
    const char* haystack = "Hello World, I am Erik";
    const char* needle = "Hello World, I am Erik and also I am a Programmer";

    const char* ptr = mlib_strstr (haystack, needle);
    mu_assert (ptr == nullptr, "Should be nullptr");
}

MU_TEST (test_strstr_const_bad_neelde_not_found) {
    const char* haystack = "Hello World, I am Erik";
    const char* needle = "Yolo";

    const char* ptr = mlib_strstr (haystack, needle);
    mu_assert (ptr == nullptr, "Should be nullptr");
}

MU_TEST_SUITE (test_strstr) {
    // Add the tests to run here with MU_RUN_TEST(name)
    MU_RUN_TEST (test_strstr_const_good);
    MU_RUN_TEST (test_strstr_const_empty_neelde);
    MU_RUN_TEST (test_strstr_const_bad_neelde_too_long);
    MU_RUN_TEST (test_strstr_const_bad_neelde_not_found);
}

int main (__attribute__ ((unused)) int argc, __attribute__ ((unused)) char** argv) {
    MU_RUN_SUITE (test_strstr);
    MU_REPORT ();
    return MU_EXIT_CODE;
}
