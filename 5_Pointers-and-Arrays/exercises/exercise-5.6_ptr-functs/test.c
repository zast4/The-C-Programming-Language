/* Rewrite appropriate programs from earlier chapters and exercises 
 * with pointers instead of array indexing. 
 * Good possibilities include getline (Chapters 1 and 4), atoi, itoa, and their variants (Chapters 2, 3, and 4), 
 * reverse (Chapter 3), and strindex and getop (Chapter 4). 
 */

#include <check.h>
#include <stdlib.h>

#include "5.6_ptr-funcs.h"

// atoi
START_TEST(test_atoi_1) {
    int a = atoi_v2("123");
    int b = atoi("123");

    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_atoi_2) {
    int a = atoi_v2("-123");
    int b = atoi("-123");

    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_atoi_3) {
    int a = atoi_v2("0");
    int b = atoi("0");

    ck_assert_int_eq(a, b);
}
END_TEST

// getop
START_TEST(test_getop_1) {
    char s1[4];
    char s2[] = "a";

    getop(s1);

    ck_assert_str_eq(s1, s2);
}
END_TEST

// itoa
START_TEST(test_itoa_1) {
    int a = 123;
    char s1[4];
    char s2[] = "123";

    itoa_v2(a, s1);

    ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(test_itoa_2) {
    int a = -123;
    char s1[5];
    char s2[] = "-123";

    itoa_v2(a, s1);

    ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(test_itoa_3) {
    int a = 0;
    char s1[4];
    char s2[] = "0";

    itoa_v2(a, s1);

    ck_assert_str_eq(s1, s2);
}
END_TEST

// strindex
START_TEST(test_strind_1) {
    char *s1 = "This is a line";
    char *s2 = "is";

    int res1 = strindex(s1, s2);
    int res2 = 2;

    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_strind_2) {
    char *s1 = "";
    char *s2 = "is";

    int res1 = strindex(s1, s2);
    int res2 = -1;

    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_strind_3) {
    char *s1 = "This is a line";
    char *s2 = "";

    int res1 = strindex(s1, s2);
    int res2 = -1;

    ck_assert_int_eq(res1, res2);
}
END_TEST


// getline
// START_TEST(test_getline_1) {
//     size_t bufsize = 1000;
//     char *s1 = (char *) malloc(bufsize * sizeof(char));
//     char *s2 = (char *) malloc(bufsize * sizeof(char));
//     get_line(s1, bufsize);
//     getline(&s2, &bufsize, stdin);

//     ck_assert_str_eq(s1, s2);

//     free(s1);
//     free(s2);
// }
// END_TEST

int main() {
    Suite *s1 = suite_create("test: ");
    TCase *tc1_1 = tcase_create("5.6_ptr-funcs.h");
    SRunner *sr = srunner_create(s1);
    int result;
    suite_add_tcase(s1, tc1_1);

    // atoi
    tcase_add_test(tc1_1, test_atoi_1);
    tcase_add_test(tc1_1, test_atoi_2);
    tcase_add_test(tc1_1, test_atoi_3);

    // itoa
    tcase_add_test(tc1_1, test_itoa_1);
    tcase_add_test(tc1_1, test_itoa_2);
    tcase_add_test(tc1_1, test_itoa_3);

    // strindex
    tcase_add_test(tc1_1, test_strind_1);
    tcase_add_test(tc1_1, test_strind_2);
    tcase_add_test(tc1_1, test_strind_3);
    

    // getline
    // tcase_add_test(tc1_1, test_getline_1);

    // getop
    // tcase_add_test(tc1_1, test_getop_1);


    srunner_set_fork_status(sr, CK_NOFORK);

    srunner_run_all(sr, CK_ENV);
    result = srunner_ntests_failed(sr);
    srunner_free(sr);
    return result == 0 ? 0 : 1;
}