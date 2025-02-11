#include "s21_tests.h"

#define SIZE 100

START_TEST(simple_int_u) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %u";
  int dataOutput = 5;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(simple_big_int_u) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %u";
  int dataOutput = 355;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(plus_int_u) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %+u";
  int dataOutput = 5;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(minus_int_u) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %-u";
  int dataOutput = 5;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(plus2_int_u) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %+2u";
  int dataOutput = 355;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(plus_zero_int_u) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %+u";
  int dataOutput = 0;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(plus_zero_2_int_u) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %+2u";
  int dataOutput = 0;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(minus_zero_int_u) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %-u";
  int dataOutput = 0;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(minus_zero_2_int_u) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %-2u";
  int dataOutput = 0;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(minus2_int_u) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %-2u";
  int dataOutput = 355;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(minus2_min_int_u) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %-2u";
  int dataOutput = -355;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(test2_int_u) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %2u";
  int dataOutput = 355;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(plus4_int_u) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %+4u";
  int dataOutput = 355;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(minus4_int_u) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %-4u";
  int dataOutput = 355;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(minus_more_int_u) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %-7u";
  int dataOutput = 355;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(minus4_min_int_u) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %-4u";
  int dataOutput = -355;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(test4_int_u) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %4u";
  int dataOutput = 355;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(test_more_4_int_u) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %u";
  int dataOutput = 35555;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(space_int_u) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World % u";
  int dataOutput = 35;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(space_minus_int_u) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World % u";
  int dataOutput = -35;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(precision_int_u) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %.u";
  int dataOutput = 35;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(precision_more4_int_u) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %.4u";
  int dataOutput = 35555;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(precision4_int_u) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %.4u";
  int dataOutput = 35;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(zero_int_u) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %0u";
  int dataOutput = 35;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(zero_precision_int_u) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %.0u";
  int dataOutput = 35;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(h_int_u) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %hu";
  int dataOutput = 35;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(l_int_u) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %lu";
  int dataOutput = 35;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

Suite *suiteSprintf_int_u(void) {
  Suite *s = suite_create("suite_sprintf_int_u");
  TCase *tc = tcase_create("tc_sprintf_int_u");

  tcase_add_test(tc, simple_int_u);
  tcase_add_test(tc, simple_big_int_u);
  tcase_add_test(tc, plus_int_u);
  tcase_add_test(tc, minus_int_u);
  tcase_add_test(tc, plus2_int_u);
  tcase_add_test(tc, plus_zero_int_u);
  tcase_add_test(tc, plus_zero_2_int_u);
  tcase_add_test(tc, minus_zero_int_u);
  tcase_add_test(tc, minus_zero_2_int_u);
  tcase_add_test(tc, minus2_int_u);
  tcase_add_test(tc, minus2_min_int_u);
  tcase_add_test(tc, test2_int_u);
  tcase_add_test(tc, plus4_int_u);
  tcase_add_test(tc, minus4_int_u);
  tcase_add_test(tc, minus_more_int_u);
  tcase_add_test(tc, minus4_min_int_u);
  tcase_add_test(tc, test4_int_u);
  tcase_add_test(tc, test_more_4_int_u);
  tcase_add_test(tc, space_int_u);
  tcase_add_test(tc, space_minus_int_u);
  tcase_add_test(tc, precision_int_u);
  tcase_add_test(tc, precision_more4_int_u);
  tcase_add_test(tc, precision4_int_u);
  tcase_add_test(tc, zero_int_u);
  tcase_add_test(tc, zero_precision_int_u);
  tcase_add_test(tc, h_int_u);
  tcase_add_test(tc, l_int_u);

  suite_add_tcase(s, tc);
  return s;
}