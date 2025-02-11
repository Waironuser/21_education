#include "s21_tests.h"

#define SIZE 100

START_TEST(simple_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %f";
  float dataOutput = 5.5;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(simple_big_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %f";
  float dataOutput = 355.3456789;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(plus_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %+f";
  float dataOutput = 5.5;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(plus_big_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %+f";
  float dataOutput = 355.3456789;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(minus_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %-f";
  float dataOutput = 5.5;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(minus_big_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %-f";
  float dataOutput = 355.3456789;
  ;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(plus2_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %+2f";
  float dataOutput = 5.5;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(plus2_big_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %+2f";
  float dataOutput = 355.3456789;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(plus_zero_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %+f";
  float dataOutput = 0;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(plus2_zero_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %+2f";
  float dataOutput = 0;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(minus_zero_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %-f";
  float dataOutput = 0;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(minus2_zero_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %-2f";
  float dataOutput = 0;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(minus2_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %-2f";
  float dataOutput = 355.3456789;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(minus2_min_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %-2f";
  float dataOutput = -355.3456789;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(test2_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %2f";
  float dataOutput = 5.5;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(plus4_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %+4f";
  float dataOutput = 5.5;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(test2_big_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %8f";
  float dataOutput = 355.3456789;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(plus4_big_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %+8f";
  float dataOutput = 355.3456789;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(minus4_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %-4f";
  float dataOutput = 5.5;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(minus8_big_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %-8f";
  float dataOutput = 355.3456789;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(minus_big_min_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %-8f";
  float dataOutput = -355.3456789;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(test8_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %8f";
  float dataOutput = 5.5;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(test8_big_min_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %8f";
  float dataOutput = -355.3456789;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(space_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World % f";
  float dataOutput = 5.5;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(space_minus_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World % f";
  float dataOutput = -5.5;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(precision_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %.f";
  float dataOutput = 777.5;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(precision_float_2) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %.f";
  float dataOutput = 777.45;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(precision_big_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %.f";
  float dataOutput = 777.3456789;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(precision4_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %.4f";
  float dataOutput = 5.5;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(precision4_big_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %.4f";
  float dataOutput = 355.3456789;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(big_precision_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %.8f";
  float dataOutput = 5.5;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(big_precision_big_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %.8f";
  float dataOutput = 355.345678967;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(zero_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %0f";
  float dataOutput = 5.5;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(zero_big_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %0f";
  float dataOutput = 355.3456789;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(zero_precision_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %.0f";
  float dataOutput = 777.3456789;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(h_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %hf";
  float dataOutput = 5.5;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(l_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %lf";
  float dataOutput = 355.3456789;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(h_big_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %hf";
  float dataOutput = 355.3456789;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(l_small_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %lf";
  float dataOutput = 5.5;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

START_TEST(long_width_float) {
  char expected[SIZE];
  char actual[SIZE];

  char *format = "Hello World %-20f";
  float dataOutput = 5.456;

  int expectedInt = sprintf(expected, format, dataOutput);
  int actualInt = s21_sprintf(actual, format, dataOutput);

  ck_assert_str_eq(expected, actual);
  ck_assert_int_eq(expectedInt, actualInt);
}
END_TEST

Suite *suiteSprintf_float(void) {
  Suite *s = suite_create("suite_sprintf_float");
  TCase *tc = tcase_create("tc_sprintf_float");

  tcase_add_test(tc, simple_float);
  tcase_add_test(tc, simple_big_float);
  tcase_add_test(tc, plus_float);
  tcase_add_test(tc, plus_big_float);
  tcase_add_test(tc, minus_float);
  tcase_add_test(tc, minus_big_float);
  tcase_add_test(tc, plus2_float);
  tcase_add_test(tc, plus2_big_float);
  tcase_add_test(tc, plus_zero_float);
  tcase_add_test(tc, plus2_zero_float);
  tcase_add_test(tc, minus_zero_float);
  tcase_add_test(tc, minus2_zero_float);
  tcase_add_test(tc, minus2_float);
  tcase_add_test(tc, minus2_min_float);
  tcase_add_test(tc, test2_float);
  tcase_add_test(tc, plus4_float);
  tcase_add_test(tc, test2_big_float);
  tcase_add_test(tc, plus4_big_float);
  tcase_add_test(tc, minus4_float);
  tcase_add_test(tc, minus8_big_float);
  tcase_add_test(tc, minus_big_min_float);
  tcase_add_test(tc, test8_float);
  tcase_add_test(tc, test8_big_min_float);
  tcase_add_test(tc, space_float);
  tcase_add_test(tc, space_minus_float);
  tcase_add_test(tc, precision_float);
  tcase_add_test(tc, precision_float_2);
  tcase_add_test(tc, precision_big_float);
  tcase_add_test(tc, precision4_float);
  tcase_add_test(tc, precision4_big_float);
  tcase_add_test(tc, big_precision_float);
  tcase_add_test(tc, big_precision_big_float);
  tcase_add_test(tc, zero_float);
  tcase_add_test(tc, zero_big_float);
  tcase_add_test(tc, zero_precision_float);
  tcase_add_test(tc, h_float);
  tcase_add_test(tc, l_float);
  tcase_add_test(tc, h_big_float);
  tcase_add_test(tc, l_small_float);
  tcase_add_test(tc, long_width_float);

  suite_add_tcase(s, tc);
  return s;
}