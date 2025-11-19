#include "minunit.h"
// Include your needes headers here
#include "mlib_string.h"
// Add your test function with MU_TEST(name)
MU_TEST (test_strchr_const_good) {
    const char* word = "helle";

    const char* occurence = mlib_strchr (word, 'e');
    mu_assert (occurence == &word[1], "Should be adrerss of e");
}

MU_TEST (test_strchr_const_bad) {
    const char* word = "helle";

    const char* occurence = mlib_strchr (word, 'w');
    mu_assert (occurence == nullptr, "Should be nullpointer");
}

MU_TEST (test_strchr_good) {
    char* word = "helle";

    char* occurence = mlib_strchr (word, 'e');
    mu_assert (occurence == &word[1], "Should be address of e");
}

MU_TEST (test_strchr_bad) {
    char* word = "helle";

    char* occurence = mlib_strchr (word, 'w');
    mu_assert (occurence == nullptr, "Should be nullprt");
}

MU_TEST (test_strrchr_const_good) {
    const char* word = "helle";

    const char* occurence = mlib_strrchr (word, 'e');
    mu_assert (occurence == &word[4], "Should be adrerss of e");
}

MU_TEST (test_strrchr_const_bad) {
    const char* word = "helle";

    const char* occurence = mlib_strrchr (word, 'w');
    mu_assert (occurence == nullptr, "Should be nullpointer");
}

MU_TEST (test_strrchr_good) {
    char* word = "helle";

    char* occurence = mlib_strrchr (word, 'e');
    mu_assert (occurence == &word[4], "Should be address of e");
}

MU_TEST (test_strrchr_bad) {
    char* word = "helle";

    char* occurence = mlib_strrchr (word, 'w');
    mu_assert (occurence == nullptr, "Should be nullprt");
}

MU_TEST_SUITE (test_strchr) {
    // Add the tests to run here with MU_RUN_TEST(name)
    MU_RUN_TEST (test_strchr_const_good);
    MU_RUN_TEST (test_strchr_const_bad);
    MU_RUN_TEST (test_strchr_good);
    MU_RUN_TEST (test_strchr_bad);
    MU_RUN_TEST (test_strrchr_const_good);
    MU_RUN_TEST (test_strrchr_const_bad);
    MU_RUN_TEST (test_strrchr_good);
    MU_RUN_TEST (test_strrchr_bad);
}

int main (__attribute__ ((unused)) int argc, __attribute__ ((unused)) char** argv) {
    MU_RUN_SUITE (test_strchr);
    MU_REPORT ();
    return MU_EXIT_CODE;
}
