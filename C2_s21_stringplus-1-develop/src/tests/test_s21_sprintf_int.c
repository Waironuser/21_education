#include "s21_tests.h"

#define SIZE 100

START_TEST(simple_int) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %d";
  int dataOutput = 5;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(simple_big_int) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %d";
  int dataOutput = 355;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(plus_int) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %+d";
  int dataOutput = 5;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(minus_int) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %-d";
  int dataOutput = 5;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(plus2_int) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %+2d";
  int dataOutput = 355;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(plus_zero_int) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %+d";
  int dataOutput = 0;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(plus_zero_2_int) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %+2d";
  int dataOutput = 0;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(minus_zero_int) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %-d";
  int dataOutput = 0;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(minus_zero_2_int) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %-2d";
  int dataOutput = 0;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(minus2_int) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %-2d";
  int dataOutput = 355;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(minus2_min_int) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %-2d";
  int dataOutput = -355;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(test2_int) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %2d";
  int dataOutput = 355;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(plus4_int) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %+4d";
  int dataOutput = 355;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(minus4_int) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %-4d";
  int dataOutput = 355;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(minus_more_int) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %-7d";
  int dataOutput = 355;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(minus4_min_int) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %-4d";
  int dataOutput = -355;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(test4_int) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %4d";
  int dataOutput = 355;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(test_more_4_int) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %4d";
  int dataOutput = 35555;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(space_int) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World % d";
  int dataOutput = 35;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(space_minus_int) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World % d";
  int dataOutput = -35;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(precision_int) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %.d";
  int dataOutput = 35;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(precision_more4_int) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %.4d";
  int dataOutput = 35555;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(precision4_int) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %.4d";
  int dataOutput = 35;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(zero_int) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %0d";
  int dataOutput = 35;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(zero_precision_int) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %.0d";
  int dataOutput = 35;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(h_int) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %hd";
  int dataOutput = 35;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(l_int) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %ld";
  int dataOutput = 35;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

Suite *suiteSprintf_int(void) {
  Suite *s = suite_create("suite_sprintf_int");
  TCase *tc = tcase_create("tc_sprintf_int");

  tcase_add_test(tc, simple_int);
  tcase_add_test(tc, simple_big_int);
  tcase_add_test(tc, plus_int);
  tcase_add_test(tc, minus_int);
  tcase_add_test(tc, plus2_int);
  tcase_add_test(tc, plus_zero_int);
  tcase_add_test(tc, plus_zero_2_int);
  tcase_add_test(tc, minus_zero_int);
  tcase_add_test(tc, minus_zero_2_int);
  tcase_add_test(tc, minus2_int);
  tcase_add_test(tc, minus2_min_int);
  tcase_add_test(tc, test2_int);
  tcase_add_test(tc, plus4_int);
  tcase_add_test(tc, minus4_int);
  tcase_add_test(tc, minus_more_int);
  tcase_add_test(tc, minus4_min_int);
  tcase_add_test(tc, test4_int);
  tcase_add_test(tc, test_more_4_int);
  tcase_add_test(tc, space_int);
  tcase_add_test(tc, space_minus_int);
  tcase_add_test(tc, precision_int);
  tcase_add_test(tc, precision_more4_int);
  tcase_add_test(tc, precision4_int);
  tcase_add_test(tc, zero_int);
  tcase_add_test(tc, zero_precision_int);
  tcase_add_test(tc, h_int);
  tcase_add_test(tc, l_int);

  suite_add_tcase(s, tc);
  return s;
}