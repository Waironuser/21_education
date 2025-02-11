#include "s21_tests.h"

START_TEST(test_basic_positive) {
  const char *str = "12345";
  int expected = 12345;
  int result = atoi(str);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_basic_negative) {
  const char *str = "-54321";
  int expected = -54321;
  int result = atoi(str);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_with_spaces) {
  const char *str = "   789  ";
  int expected = 789;
  int result = atoi(str);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_with_plus_sign) {
  const char *str = "+987";
  int expected = 987;
  int result = atoi(str);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_with_non_numeric) {
  const char *str = "123abc456";
  int expected = 123;
  int result = atoi(str);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_sign_plus) {
  const char *str = "+";
  int expected = 0;
  int result = atoi(str);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_sign_minus) {
  const char *str = "-";
  int expected = 0;
  int result = atoi(str);
  ck_assert_int_eq(result, expected);
}
END_TEST

Suite *suite_atoi(void) {
  Suite *s = suite_create("atoi_suite");
  TCase *tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_basic_positive);
  tcase_add_test(tc_core, test_basic_negative);
  tcase_add_test(tc_core, test_with_spaces);
  tcase_add_test(tc_core, test_with_plus_sign);
  tcase_add_test(tc_core, test_with_non_numeric);
  tcase_add_test(tc_core, test_sign_plus);
  tcase_add_test(tc_core, test_sign_minus);

  suite_add_tcase(s, tc_core);

  return s;
}