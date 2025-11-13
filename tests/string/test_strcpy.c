#include "minunit.h"
// Include your needes headers here
#include "mlib_string.h"
#include <stdio.h>

// Add your test function with MU_TEST(name)
MU_TEST(test_strcpy_good) {
    char* src = "hello";
    char dest[6];
    
    mlib_strcpy(dest, src);
    mu_assert_string_eq(src, dest);
}

MU_TEST(test_strcpy_good_ret_val) {
    char* src = "hello";
    char dest[6];
    
    char* cdest = mlib_strcpy(dest, src);
    mu_assert_string_eq(src, cdest);
}

MU_TEST(test_strcpy_ret_val_copy) {
    char* src = "hello";
    char dest[6];
    
    char* cdest = mlib_strcpy(dest, src);
    mu_assert(dest == cdest, "Pointers should have the same value");
}

MU_TEST(test_strcpy_override) {
    char src[] = "hello";
    char dest[] = "olleh";

    mlib_strcpy(dest, src);

    mu_assert_string_eq(src, dest);
}

MU_TEST(test_strncpy_good) {
    char* src = "hello";
    char dest[6];

    mlib_strncpy(dest, src, 6);
    mu_assert_string_eq(src, dest);
}

MU_TEST(test_strncpy_good_retval) {
    char* src = "hello";
    char dest[6];

    char* cdest = mlib_strncpy(dest, src, 6);
    mu_assert_string_eq(src, cdest);
}

MU_TEST(test_strncpy_ret_val_copy) {
    char* src = "hello";
    char dest[6];
    
    char* cdest = mlib_strncpy(dest, src, 6);
    mu_assert(dest == cdest, "Pointers should have the same value");
}

MU_TEST(test_strncpy_count_less_than_src) {
    char* src = "Hello World!";
    char dest[6];

    mlib_strncpy(dest, src, 6);
    mu_assert(dest[5] != '\0', "Null-Terminating Character is not added if count is less than sort");
    for(int i = 0; i <= 5; i++) {
        mu_assert(dest[i] == src[i], "Otherwise should match");
    }

}

MU_TEST(test_strncpy_src_less_than_count) {
    char* src = "Hello";
    char dest[10];

    mlib_strncpy(dest, src, 10);
    //printf("%s", dest);
    for(int i = 0; i < 10; i++) {
        if(i<5) {
            mu_assert(src[i] == dest[i], "Chars up to count should match");
        } else {
            mu_assert(dest[i] == '\0', "Rest should be Null-Terminating Character");
        }
    }
}

MU_TEST_SUITE(test_strcpy) {
    // Add the tests to run here with MU_RUN_TEST(name)
    MU_RUN_TEST(test_strcpy_good);
    MU_RUN_TEST(test_strcpy_override);
    MU_RUN_TEST(test_strcpy_good_ret_val);
    MU_RUN_TEST(test_strcpy_ret_val_copy);

    MU_RUN_TEST(test_strncpy_good);
    MU_RUN_TEST(test_strncpy_good_retval);
    MU_RUN_TEST(test_strncpy_ret_val_copy);
    MU_RUN_TEST(test_strncpy_count_less_than_src);
    MU_RUN_TEST(test_strncpy_src_less_than_count);
}

int main(__attribute__ ((unused))int argc, __attribute__ ((unused))char** argv) {
MU_RUN_SUITE(test_strcpy);
MU_REPORT();
return MU_EXIT_CODE;
}
