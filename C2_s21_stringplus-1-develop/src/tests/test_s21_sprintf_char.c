#include "s21_tests.h"

#define SIZE 100

START_TEST(c_flag_minus_l) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "%-lc";
  wchar_t dataOutput = L'c';

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(c_flag_plus_l) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "%+lc";
  wchar_t dataOutput = L'c';

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(c_flag_space_l) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "% lc";
  wchar_t dataOutput = L'c';

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(c_flag_minus_h) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "%-hc";
  char dataOutput = 'c';

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(c_flag_plus_h) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "%+hc";
  char dataOutput = 'c';

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(c_flag_space_h) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "% hc";
  char dataOutput = 'c';

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(c_flag_minus_l_width_50) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "%-50lc";
  wchar_t dataOutput = L'c';

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(c_flag_plus_l_width_50) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "%+50lc";
  wchar_t dataOutput = L'c';

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(c_flag_space_l_width_50) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "% 50lc";
  wchar_t dataOutput = L'c';

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(c_flag_minus_h_width_50) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "%-50hc";
  char dataOutput = 'c';

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(c_flag_plus_h_width_50) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "%+50hc";
  char dataOutput = 'c';

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(c_flag_space_h_width_50) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "% 50hc";
  char dataOutput = 'c';

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(c_specifier) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "%c";
  char dataOutput = 'c';

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(c_flag_minus) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "%-c";
  char dataOutput = 'c';

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

Suite *suiteSprintf_char(void) {
  Suite *s = suite_create("suite_sprintf_char");
  TCase *tc = tcase_create("tc_sprintf_char");

  tcase_add_test(tc, c_specifier);
  tcase_add_test(tc, c_flag_minus);
  tcase_add_test(tc, c_flag_minus_l);
  tcase_add_test(tc, c_flag_plus_l);
  tcase_add_test(tc, c_flag_space_l);
  tcase_add_test(tc, c_flag_minus_h);
  tcase_add_test(tc, c_flag_plus_h);
  tcase_add_test(tc, c_flag_space_h);
  tcase_add_test(tc, c_flag_minus_l_width_50);
  tcase_add_test(tc, c_flag_plus_l_width_50);
  tcase_add_test(tc, c_flag_space_l_width_50);
  tcase_add_test(tc, c_flag_minus_h_width_50);
  tcase_add_test(tc, c_flag_plus_h_width_50);
  tcase_add_test(tc, c_flag_space_h_width_50);

  suite_add_tcase(s, tc);
  return s;
}
