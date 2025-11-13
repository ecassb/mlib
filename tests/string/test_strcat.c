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

MU_TEST(test_strncat_good) {
    char dest[12];
    fill_char_array(dest);

    char* src = " World";
    mlib_strncat(dest, src, 6);
    mu_assert_string_eq("Hello World", dest);
}

MU_TEST(test_strncat_good_ret_val) {
    char dest[12];
    fill_char_array(dest);

    char* src = " World";
    char* cdest = mlib_strncat(dest, src, 6);
    mu_assert_string_eq("Hello World", cdest);
}

MU_TEST(test_strncat_good_ret_val_same_value) {
    char dest[12];
    fill_char_array(dest);
 
    char* src = " World";
    char* cdest = mlib_strncat(dest, src, 6);
    mu_assert(cdest == dest, "Pointer of return value should have same value as Input");
}

MU_TEST(test_strncat_early_terminating_char) {
    char dest[12];
    fill_char_array(dest);

    char* src = " Wor\0ld";
    char* cdest = mlib_strncat(dest, src, 7);
    mu_assert_string_eq("Hello Wor", cdest);
}

MU_TEST(test_strncat_early_count_reached) {
    char dest[12];
    fill_char_array(dest);

    char* src = " World";
    char* cdest = mlib_strncat(dest, src, 3);
    mu_assert_string_eq("Hello Wo", cdest);
}

MU_TEST(test_strncat_zero_count) {
    char dest[12];
    fill_char_array(dest);

    char* src = " World";
    char* cdest = mlib_strncat(dest, src, 0);
    mu_assert_string_eq("Hello", cdest);
}


MU_TEST_SUITE(test_strcat) {
    // Add the tests to run here with MU_RUN_TEST(name)
    MU_RUN_TEST(test_strcat_good);
    MU_RUN_TEST(test_strcat_good_ret_val);
    MU_RUN_TEST(test_strcat_good_ret_val_same_address);

    MU_RUN_TEST(test_strncat_good);
    MU_RUN_TEST(test_strncat_good_ret_val);
    MU_RUN_TEST(test_strncat_good_ret_val_same_value);
    MU_RUN_TEST(test_strncat_early_terminating_char);
    MU_RUN_TEST(test_strncat_early_count_reached);
    MU_RUN_TEST(test_strncat_zero_count);
}

int main(__attribute__ ((unused))int argc, __attribute__ ((unused))char** argv) {
MU_RUN_SUITE(test_strcat);
MU_REPORT();
return MU_EXIT_CODE;
}
