#include "s21_tests.h"

START_TEST(trim_backspaces) {
  const char *src = "  Hello, world!  ";
  const char *trim_chars = " ";
  char *result = trim(src, trim_chars);
  ck_assert_str_eq(result, "Hello, world!");
  free(result);
}
END_TEST

START_TEST(trim_multiple_chars) {
  const char *src = "xxHello, world!yy";
  const char *trim_chars = "xy";
  char *result = trim(src, trim_chars);
  ck_assert_str_eq(result, "Hello, world!");
  free(result);
}
END_TEST

START_TEST(trim_null_trim_chars) {
  const char *src = " \tHello, world! \t";
  char *result = trim(src, s21_NULL);
  ck_assert_str_eq(result, "Hello, world!");
  free(result);
}
END_TEST

START_TEST(trim_only_trim_chars) {
  const char *src = "xxxx";
  const char *trim_chars = "x";
  char *result = trim(src, trim_chars);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(trim_empty_src) {
  const char *src = "";
  const char *trim_chars =
      "1234567890qwertyuiop[]asdfghjkl;'zxcvbnm,./!@#$^&*(*)_+";
  char *result = trim(src, trim_chars);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(trim_null_src) {
  const char *src = s21_NULL;
  const char *trim_chars = "x";
  char *result = trim(src, trim_chars);
  ck_assert_ptr_eq(result, s21_NULL);
}
END_TEST

Suite *suite_trim(void) {
  Suite *s = suite_create("suite_trim");
  TCase *tc_core = tcase_create("tcase_trim");
  tcase_add_test(tc_core, trim_backspaces);
  tcase_add_test(tc_core, trim_multiple_chars);
  tcase_add_test(tc_core, trim_null_trim_chars);
  tcase_add_test(tc_core, trim_only_trim_chars);
  tcase_add_test(tc_core, trim_empty_src);
  tcase_add_test(tc_core, trim_null_src);
  suite_add_tcase(s, tc_core);
  return s;
}