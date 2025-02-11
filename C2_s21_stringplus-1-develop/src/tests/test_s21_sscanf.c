#include "s21_tests.h"

START_TEST(sscanf_hard) {
  const char *input = "2345 dasfasdf 123.419 255 01236 c 0.123e-10 0x1A";
  int i1, i2;
  char str1[100], str2[100];
  float f1, f2;
  unsigned int ui1, ui2;
  int oct1, oct2;
  char ch1, ch2;
  float e1, e2;
  int hex1, hex2;
  int orig_res = sscanf(input, "%d %s %f %u %o %c %e %x", &i1, str1, &f1, &ui1,
                        &oct1, &ch1, &e1, &hex1);
  int my_res = s21_sscanf(input, "%d %s %f %u %o %c %e %x", &i2, str2, &f2,
                          &ui2, &oct2, &ch2, &e2, &hex2);
  ck_assert_int_eq(orig_res, my_res);
  ck_assert_int_eq(i1, i2);
  ck_assert_str_eq(str1, str2);
  ck_assert_float_eq(f1, f2);
  ck_assert_uint_eq(ui1, ui2);
  ck_assert_int_eq(oct1, oct2);
  ck_assert_int_eq(ch1, ch2);
  ck_assert_float_eq(e1, e2);
  ck_assert_int_eq(hex1, hex2);
}
END_TEST

START_TEST(sscanf_with_very_big_persent) {
  const char *input = "2345 dasfasdf 123.419 255 01236 c 0.123e+10 0x1A";
  int i1, i2;
  char str1[100], str2[100];
  float f1, f2;
  unsigned int ui1, ui2;
  int oct1, oct2;
  char ch1, ch2;
  float e1, e2;
  int hex1, hex2;
  int orig_res = sscanf(input, "%50d %s %f %u %o %c %e %x", &i1, str1, &f1,
                        &ui1, &oct1, &ch1, &e1, &hex1);
  int my_res = s21_sscanf(input, "%50d %s %f %u %o %c %e %x", &i2, str2, &f2,
                          &ui2, &oct2, &ch2, &e2, &hex2);
  ck_assert_int_eq(orig_res, my_res);
  ck_assert_int_eq(i1, i2);
  ck_assert_str_eq(str1, str2);
  ck_assert_float_eq(f1, f2);
  ck_assert_uint_eq(ui1, ui2);
  ck_assert_int_eq(oct1, oct2);
  ck_assert_int_eq(ch1, ch2);
  ck_assert_float_eq(e1, e2);
  ck_assert_int_eq(hex1, hex2);
}
END_TEST

START_TEST(sscanf_float_double_ldouble) {
  const char *input = "10.5 123.419 -2780.97";
  float f1, f2;
  double d1, d2;
  long double ld1, ld2;
  int orig_res = sscanf(input, "%f %lf %Lf", &f1, &d1, &ld1);
  int my_res = s21_sscanf(input, "%f %lf %Lf", &f2, &d2, &ld2);
  ck_assert_int_eq(orig_res, my_res);
  ck_assert_float_eq(f1, f2);
  ck_assert_double_eq(d1, d2);
  ck_assert_ldouble_eq(ld1, ld2);
}
END_TEST

START_TEST(sscanf_short_long_int) {
  const char *input = "123 87647654";
  short s1, s2;
  long l1, l2;
  int orig_res = sscanf(input, "%hd %ld", &s1, &l1);
  int my_res = s21_sscanf(input, "%hd %ld", &s2, &l2);
  ck_assert_int_eq(orig_res, my_res);
  ck_assert_int_eq(s1, s2);
  ck_assert_int_eq(l1, l2);
}
END_TEST

START_TEST(sscanf_i_specifier) {
  const char *input = "7646 2134 05345 5b 0X5b";
  int i1, i2;
  int oct1, oct2;
  int oct3, oct4;
  int hex1, hex2;
  int hex3, hex4;
  int orig_res =
      sscanf(input, "%i %i %i %i %i", &i1, &oct1, &oct3, &hex1, &hex3);
  int my_res =
      s21_sscanf(input, "%i %i %i %i %i", &i2, &oct2, &oct4, &hex2, &hex4);
  ck_assert_int_eq(orig_res, my_res);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(oct1, oct2);
  ck_assert_int_eq(oct3, oct4);
  ck_assert_int_eq(hex1, hex2);
  ck_assert_int_eq(hex3, hex4);
}
END_TEST

START_TEST(sscanf_width_int) {
  const char *input = "876476";
  int i1, i2;
  int orig_res = sscanf(input, "%3d", &i1);
  int my_res = s21_sscanf(input, "%3d", &i2);
  ck_assert_int_eq(orig_res, my_res);
  ck_assert_int_eq(i1, i2);
}
END_TEST

START_TEST(sscanf_width_string) {
  const char *input = "fugydsjgikfoilldsp435439telgfg";
  char str1[100];
  char str2[100];
  int orig_res = sscanf(input, "%8s", str1);
  int my_res = s21_sscanf(input, "%8s", str2);
  ck_assert_int_eq(orig_res, my_res);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sscanf_spec_E_X_g_G) {
  const char *input = "0.123e+10 0x5555 4.19e-2 4.19e+2";
  float E1, E2, g1, g2, G1, G2;
  int X1, X2;
  int orig_res = sscanf(input, "%E %X %g %G", &E1, &X1, &g1, &G1);
  int my_res = s21_sscanf(input, "%E %X %g %G", &E2, &X2, &g2, &G2);
  ck_assert_int_eq(orig_res, my_res);
  ck_assert_float_eq(E1, E2);
  ck_assert_int_eq(X1, X2);
  ck_assert_float_eq(g1, g2);
  ck_assert_float_eq(G1, G2);
}
END_TEST

START_TEST(sscanf_supress) {
  const char *input = "10 123.419 -2780.97";
  double d1, d2;
  long double ld1, ld2;
  int orig_res = sscanf(input, "%*d %lf %Lf", &d1, &ld1);
  int my_res = s21_sscanf(input, "%*d %lf %Lf", &d2, &ld2);
  ck_assert_int_eq(orig_res, my_res);
  ck_assert_double_eq(d1, d2);
  ck_assert_ldouble_eq(ld1, ld2);
}
END_TEST

START_TEST(sscanf_pointer) {
  const char *input = "0x7ffee0418b0";
  void *p1, *p2;
  int orig_res = sscanf(input, "%p", &p1);
  int my_res = s21_sscanf(input, "%p", &p2);
  ck_assert_int_eq(orig_res, my_res);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_EOF) {
  const char *input = "";
  int i1, i2;
  char str1[100], str2[100];
  float f1, f2;
  unsigned int ui1, ui2;
  int oct1, oct2;
  char ch1, ch2;
  float e1, e2;
  int hex1, hex2;
  int orig_res = sscanf(input, "%d %s %f %u %o %c %e %x", &i1, str1, &f1, &ui1,
                        &oct1, &ch1, &e1, &hex1);
  int my_res = s21_sscanf(input, "%d %s %f %u %o %c %e %x", &i2, str2, &f2,
                          &ui2, &oct2, &ch2, &e2, &hex2);
  ck_assert_int_eq(orig_res, my_res);
}
END_TEST

START_TEST(sscanf_EOF_with_spaces) {
  const char *input = "              ";
  int i1, i2;
  char str1[100], str2[100];
  float f1, f2;
  unsigned int ui1, ui2;
  int oct1, oct2;
  char ch1, ch2;
  float e1, e2;
  int hex1, hex2;
  int orig_res = sscanf(input, "%d %s %f %u %o %c %e %x", &i1, str1, &f1, &ui1,
                        &oct1, &ch1, &e1, &hex1);
  int my_res = s21_sscanf(input, "%d %s %f %u %o %c %e %x", &i2, str2, &f2,
                          &ui2, &oct2, &ch2, &e2, &hex2);
  ck_assert_int_eq(orig_res, my_res);
}
END_TEST

Suite *suite_sscanf(void) {
  Suite *s = suite_create("suite_sscanf");
  TCase *tc_core = tcase_create("tcase_sscanf");
  tcase_add_test(tc_core, sscanf_hard);
  tcase_add_test(tc_core, sscanf_with_very_big_persent);
  tcase_add_test(tc_core, sscanf_float_double_ldouble);
  tcase_add_test(tc_core, sscanf_short_long_int);
  tcase_add_test(tc_core, sscanf_i_specifier);
  tcase_add_test(tc_core, sscanf_width_int);
  tcase_add_test(tc_core, sscanf_width_string);
  tcase_add_test(tc_core, sscanf_spec_E_X_g_G);
  tcase_add_test(tc_core, sscanf_supress);
  tcase_add_test(tc_core, sscanf_pointer);
  tcase_add_test(tc_core, sscanf_EOF);
  tcase_add_test(tc_core, sscanf_EOF_with_spaces);
  suite_add_tcase(s, tc_core);
  return s;
}