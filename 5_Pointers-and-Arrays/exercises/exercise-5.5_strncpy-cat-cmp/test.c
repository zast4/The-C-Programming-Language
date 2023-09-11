/**
 *
 * Exercise: 5.5
 *
 * Write versions of the library functions strncpy, strncat, and
 * strncmp, which operate on at most the first n characters of their argument
 * strings.
 *
 **/

#include "5.5_strn.h"

#include <check.h>
#include <stdlib.h>


// strncat
START_TEST(test_srtncat_1) {
    char *s1 = malloc(sizeof(char) * 8);
    char *s2 = malloc(sizeof(char) * 8);
    s1[0] = '\0';
    s2[0] = '\0';

    char s3[] = "def";
    int n = 3;

    strn_cat(s1, s3, n);
    strncat(s2, s3, n);

    ck_assert_str_eq(s1, s3);

    free(s1);
    free(s2);
    //printf("%s", s1);
}
END_TEST

// strncpy
START_TEST(test_srtncpy_1) {
    char *s1 = malloc(sizeof(char) * 8);
    char *s2 = malloc(sizeof(char) * 8);
    s1[0] = '\0';
    s2[0] = '\0';

    char s3[] = "def";
    int n = 3;

    strn_cpy(s1, s3, n);
    strncpy(s2, s3, n);

    ck_assert_str_eq(s1, s3);

    free(s1);
    free(s2);
    //printf("%s", s1);
}
END_TEST

int main() {
    Suite *s1 = suite_create("test: ");
    TCase *tc1_1 = tcase_create("5.5_strn.h");
    SRunner *sr = srunner_create(s1);
    int result;
    suite_add_tcase(s1, tc1_1);

    // strncat
    tcase_add_test(tc1_1, test_srtncat_1);

    // strncpy
    tcase_add_test(tc1_1, test_srtncpy_1);

    srunner_set_fork_status(sr, CK_NOFORK);

    srunner_run_all(sr, CK_ENV);
    result = srunner_ntests_failed(sr);
    srunner_free(sr);
    return result == 0 ? 0 : 1;
}