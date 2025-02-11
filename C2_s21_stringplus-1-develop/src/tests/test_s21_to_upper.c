#include "s21_tests.h"

START_TEST(to_upper_base) {
  const char *str = "Hello, world!";
  char *result = to_upper(str);
  ck_assert_str_eq(result, "HELLO, WORLD!");
  free(result);
}
END_TEST

START_TEST(to_upper_uppercase_str) {
  const char *str = "HELLO, WORLD!";
  char *result = to_upper(str);
  ck_assert_str_eq(result, "HELLO, WORLD!");
  free(result);
}
END_TEST

START_TEST(to_upper_different_symbols) {
  const char *str = "1234!@#$";
  char *result = to_upper(str);
  ck_assert_str_eq(result, "1234!@#$");
  free(result);
}
END_TEST

START_TEST(to_upper_empty_str) {
  const char *str = "";
  char *result = to_upper(str);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(to_upper_mixed_symbols) {
  const char *str = "HeLLo, WoRLd!";
  char *result = to_upper(str);
  ck_assert_str_eq(result, "HELLO, WORLD!");
  free(result);
}
END_TEST

START_TEST(to_upper_null_str) {
  const char *str = s21_NULL;
  char *result = to_upper(str);
  ck_assert_ptr_eq(result, s21_NULL);
}
END_TEST

Suite *suite_to_upper(void) {
  Suite *s = suite_create("suite_to_upper");
  TCase *tc_core = tcase_create("tcase_to_upper");
  tcase_add_test(tc_core, to_upper_base);
  tcase_add_test(tc_core, to_upper_uppercase_str);
  tcase_add_test(tc_core, to_upper_different_symbols);
  tcase_add_test(tc_core, to_upper_empty_str);
  tcase_add_test(tc_core, to_upper_mixed_symbols);
  tcase_add_test(tc_core, to_upper_null_str);
  suite_add_tcase(s, tc_core);
  return s;
}