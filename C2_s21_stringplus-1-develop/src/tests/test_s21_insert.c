#include "s21_tests.h"

START_TEST(insert_begin) {
  const char *src = "world!";
  const char *str = "Hello, ";
  s21_size_t start_index = 0;
  char *result = insert(src, str, start_index);
  ck_assert_str_eq(result, "Hello, world!");
  free(result);
}
END_TEST

START_TEST(insert_middle) {
  const char *src = "Hello, !";
  const char *str = "world";
  s21_size_t start_index = 7;
  char *result = insert(src, str, start_index);
  ck_assert_str_eq(result, "Hello, world!");
  free(result);
}
END_TEST

START_TEST(insert_end) {
  const char *src = "Hello";
  const char *str = ", world!";
  s21_size_t start_index = 5;
  char *result = insert(src, str, start_index);
  ck_assert_str_eq(result, "Hello, world!");
  free(result);
}
END_TEST

START_TEST(insert_empty_str) {
  const char *src = "Hello, world!";
  const char *str = "";
  s21_size_t start_index = 5;
  char *result = insert(src, str, start_index);
  ck_assert_str_eq(result, "Hello, world!");
  free(result);
}
END_TEST

START_TEST(insert_empty_src) {
  const char *src = "";
  const char *str = "Hello, world!";
  s21_size_t start_index = 0;
  char *result = insert(src, str, start_index);
  ck_assert_str_eq(result, "Hello, world!");
  free(result);
}
END_TEST

START_TEST(insert_negative_index) {
  const char *src = "Hello, world!";
  const char *str = "russian";
  s21_size_t start_index = -1;
  char *result = insert(src, str, start_index);
  ck_assert_ptr_eq(result, s21_NULL);
}
END_TEST

START_TEST(insert_null_src) {
  const char *src = s21_NULL;
  const char *str = "Hello";
  s21_size_t start_index = 0;
  char *result = insert(src, str, start_index);
  ck_assert_ptr_eq(result, s21_NULL);
}
END_TEST

START_TEST(insert_null_str) {
  const char *src = "Hello, world!";
  const char *str = s21_NULL;
  s21_size_t start_index = 5;
  char *result = insert(src, str, start_index);
  ck_assert_ptr_eq(result, s21_NULL);
}
END_TEST

Suite *suite_insert(void) {
  Suite *s = suite_create("suite_insert");
  TCase *tc_core = tcase_create("tcase_insert");
  tcase_add_test(tc_core, insert_begin);
  tcase_add_test(tc_core, insert_middle);
  tcase_add_test(tc_core, insert_end);
  tcase_add_test(tc_core, insert_empty_str);
  tcase_add_test(tc_core, insert_empty_src);
  tcase_add_test(tc_core, insert_negative_index);
  tcase_add_test(tc_core, insert_null_src);
  tcase_add_test(tc_core, insert_null_str);
  suite_add_tcase(s, tc_core);
  return s;
}