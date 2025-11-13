#include "minunit.h"
// Include your needes headers here
#include "mlib_string.h"

void fill_char_array(char* s) {
    s[0] = 'H';
    s[1] = 'e';
    s[2] = 'l';
    s[3] = 'l';
    s[4] = 'o';
    s[5] = '\0';
}

// Add your test function with MU_TEST(name)
MU_TEST(test_strcat_good) {
    char dest[12];
    fill_char_array(dest);

    char* src = " World";
    mlib_strcat(dest, src);
    mu_assert_string_eq("Hello World", dest);
}

MU_TEST(test_strcat_good_ret_val) {
    char dest[12];
    fill_char_array(dest);
    char* src = " World";

    char* cdest = mlib_strcat(dest, src);
    mu_assert_string_eq("Hello World", cdest);
}

MU_TEST(test_strcat_good_ret_val_same_address) {
    char dest[12];
    fill_char_array(dest);
    char* src = " World";

    char* cdest = mlib_strcat(dest, src);
    mu_assert(cdest == dest, "Return value should have same adress");
}

MU_TEST_SUITE(test_strcat) {
    // Add the tests to run here with MU_RUN_TEST(name)
    MU_RUN_TEST(test_strcat_good);
    MU_RUN_TEST(test_strcat_good_ret_val);
    MU_RUN_TEST(test_strcat_good_ret_val_same_address);
}

int main(__attribute__ ((unused))int argc, __attribute__ ((unused))char** argv) {
MU_RUN_SUITE(test_strcat);
MU_REPORT();
return MU_EXIT_CODE;
}
