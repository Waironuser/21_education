#include "s21_tests.h"

START_TEST(test_s21_strerror_1) {
  int str_1 = 18;
  ck_assert_str_eq(s21_strerror(str_1), "Invalid cross-device link");
}
END_TEST

START_TEST(test_s21_strerror_2) {
  int str_1 = 33;
  ck_assert_str_eq(s21_strerror(str_1), "Numerical argument out of domain");
}
END_TEST

START_TEST(test_s21_strerror_3) {
  int str_1 = 75;
  ck_assert_str_eq(s21_strerror(str_1),
                   "Value too large for defined data type");
}
END_TEST

START_TEST(test_s21_strerror_4) {
  int str_1 = -1;
  ck_assert_str_eq(s21_strerror(str_1), "Unknown error -1");
}
END_TEST

START_TEST(test_s21_strerror_5) {
  int str_1 = 150;
  ck_assert_str_eq(s21_strerror(str_1), "Unknown error 150");
}
END_TEST

Suite *make_strerror_suite(void) {
  Suite *s = suite_create("strerror");
  TCase *tc_strings = tcase_create("strings");
  suite_add_tcase(s, tc_strings);
  tcase_add_test(tc_strings, test_s21_strerror_1);
  tcase_add_test(tc_strings, test_s21_strerror_2);
  tcase_add_test(tc_strings, test_s21_strerror_3);
  tcase_add_test(tc_strings, test_s21_strerror_4);
  tcase_add_test(tc_strings, test_s21_strerror_5);
  return s;
}