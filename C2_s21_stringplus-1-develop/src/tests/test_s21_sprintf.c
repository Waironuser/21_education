#include "s21_tests.h"

START_TEST(sprintf_1_c) {
  char str1[100];
  char str2[100];
  char *format = "%c format_c %c format_c %c format_c %c format_c %c";
  int a = 6;
  int b = 7;
  int c = 8;
  int d = 55;
  int e = 94;
  ck_assert_int_eq(sprintf(str1, format, a, b, c, d, e),
                   s21_sprintf(str2, format, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_c) {
  char str1[100];
  char str2[100];
  char *format = "%c format_c %c format_c %c format_c %c format_c %c";
  int a = -5;
  int b = -7;
  int c = -15;
  int d = -55;
  int e = -94;
  ck_assert_int_eq(sprintf(str1, format, a, b, c, d, e),
                   s21_sprintf(str2, format, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_c) {
  char str1[100];
  char str2[100];
  char *format = "%c format_c %c format_c %c format_c %c format_c %c";
  int a = 40;
  int b = 55;
  int c = 1855;
  int d = 245;
  int e = 142;
  ck_assert_int_eq(sprintf(str1, format, a, b, c, d, e),
                   s21_sprintf(str2, format, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_c) {
  char str1[100];
  char str2[100];
  char *format = "%c format_c %c format_c %c format_c %c format_c %c";
  int a = 40;
  int b = 55;
  int c = 1855;
  int d = 245;
  int e = 142;
  ck_assert_int_eq(sprintf(str1, format, a, b, c, d, e),
                   s21_sprintf(str2, format, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_c) {
  char str1[100];
  char str2[100];
  char *format = "%c format_c %c format_c %c format_c %c format_c %c";
  char a = 0;
  ck_assert_int_eq(sprintf(str1, format, a, a, a, a, a),
                   s21_sprintf(str2, format, a, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_c) {
  char str1[100];
  char str2[100];
  char *format = "%05c format_c % 5c format_c %lc format_c";
  int a = 45;
  unsigned long int b = 45;
  ck_assert_int_eq(sprintf(str1, format, a, a, b),
                   s21_sprintf(str2, format, a, a, b));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_c) {
  char str1[100];
  char str2[100];
  char *format = "%-010c format_c % -10c format_c %-lc";
  int a = 98;
  unsigned long int b = 98;
  ck_assert_int_eq(sprintf(str1, format, a, a, b),
                   s21_sprintf(str2, format, a, a, b));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_c) {
  char str1[100];
  char str2[100];
  char *format =
      "%+010.5c format_c % +10.5c format_c %-10lc format_c %-10lc format_c "
      "%+10lc";
  char a = 12;
  unsigned long int b = 12;
  unsigned long int c = 12;
  ck_assert_int_eq(sprintf(str1, format, a, a, b, c, c),
                   s21_sprintf(str2, format, a, a, b, c, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_c) {
  char str1[100];
  char str2[100];
  char *format =
      "%6.4c format_c %-6.4c format_c %4.10lc format_c %-4.10lc format_c %-0lc";
  int a = 30;
  unsigned long int b = 30;
  unsigned long int c = 30;
  ck_assert_int_eq(sprintf(str1, format, a, a, b, c, c),
                   s21_sprintf(str2, format, a, a, b, c, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_c) {
  char str1[100];
  char str2[100];
  char *format =
      "%10c format_c %-6.4c format_c %10.10lc format_c %-4.10lc format_c %-0lc";
  int a = 30;
  unsigned long int b = 30;
  unsigned long int c = 30;
  ck_assert_int_eq(sprintf(str1, format, a, a, b, c, c),
                   s21_sprintf(str2, format, a, a, b, c, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

////////////////////-----sprintf_cpec_d-----///////////////////

START_TEST(sprintf_1_signed) {
  char str1[100] = "";
  char str2[100] = "";
  char *format = "format d %d format d";
  int val = -54;
  ck_assert_int_eq(sprintf(str1, format, val), s21_sprintf(str2, format, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_signed) {
  char str1[100];
  char str2[100];
  char *format = "%d format d %d format d %d";
  int val = 784;
  int val2 = -154;
  int val3 = 598;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
                   s21_sprintf(str2, format, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_signed) {
  char str1[100];
  char str2[100];
  char *format = "%d format d %d format d %d";
  int val = 875;
  int val2 = 87;
  int val3 = 63;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
                   s21_sprintf(str2, format, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_signed) {
  char str1[100];
  char str2[100];
  char *format = "%ld format d %ld format d %hd GOD %hd";
  long int val = 72;
  long val2 = 732578278272;
  short int val3 = 36;
  short val4 = -287;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
                   s21_sprintf(str2, format, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_signed) {
  char str1[100];
  char str2[100];
  char *format = "%3d format d %5d format d %10d";
  int val = -6752;
  int val2 = -6987;
  int val3 = -57;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
                   s21_sprintf(str2, format, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_signed) {
  char str1[200];
  char str2[200];
  char *format = "%6.5d format d %.23d format d %3.d format d %.d %.6d";
  int val = -58875;
  int val2 = -58;
  int val3 = -75;
  int val4 = -69;
  int val5 = -7;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4, val5),
                   s21_sprintf(str2, format, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_signed) {
  char str1[200];
  char str2[200];
  char *format = "%-10.5d format d %-.8d format d %-7d format d %-.d";
  int val = -86;
  int val2 = -58;
  int val3 = -78;
  int val4 = -85;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
                   s21_sprintf(str2, format, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_signed) {
  char str1[200];
  char str2[200];
  char *format = "%0d format d %0.d format d %0.0d format d %0d GOD %.d";
  int val = -8;
  int val2 = -58;
  int val3 = -7;
  int val4 = -58;
  int val5 = -75;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4, val5),
                   s21_sprintf(str2, format, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_signed) {
  char str1[200];
  char str2[200];
  char *format = "%+d format d %+3.d format d %+5.7d format d %+10d";
  int val = -69;
  int val2 = -785;
  int val3 = -6;
  int val4 = -785;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
                   s21_sprintf(str2, format, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_signed) {
  char str1[200];
  char str2[200];
  char *format = "%-d format d %+3.d format d %+5.7d format d %10d";
  int val = -69;
  int val2 = -785;
  int val3 = -6;
  int val4 = -785;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
                   s21_sprintf(str2, format, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

////////////////////-----sprintf_cpec_g-----///////////////////

START_TEST(sprintf_1_g) {
  char str1[200];
  char str2[200];
  char *format = "%g format g %.g format g %3g format g %2.g format g %4.20g!";
  double num = 41.464;
  ck_assert_int_eq(sprintf(str1, format, num, num, num, num, num),
                   s21_sprintf(str2, format, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// START_TEST(sprintf_2_g) {
//   char str1[200];
//   char str2[200];
//   char *format = "%g format g %.g format g %2g format g %2.g format g
//   %2.50g!"; double num = -1478.59595; ck_assert_int_eq(sprintf(str1, format,
//   num, num, num, num, num),
//                    s21_sprintf(str2, format, num, num, num, num, num));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

START_TEST(sprintf_3_g) {
  char str1[200];
  char str2[200];
  char *format = "%14.21g format g\n%.8g format g\n";
  double num = 78.46255;
  double num1 = 155.87874;
  ck_assert_int_eq(sprintf(str1, format, num, num1),
                   s21_sprintf(str2, format, num, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_g) {
  char str1[200];
  char str2[200];
  char *format = "%.2g format g\n%.5g format g\n";
  double num = 784.466881;
  double num1 = 744.745;
  ck_assert_int_eq(sprintf(str1, format, num, num1),
                   s21_sprintf(str2, format, num, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_g) {
  char str1[200];
  char str2[200];
  char *format = "%g format g %.g format g %4g format g %4.g format g %#5.10g!";
  double num = 2.48465684468;
  ck_assert_int_eq(sprintf(str1, format, num, num, num, num, num),
                   s21_sprintf(str2, format, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_g) {
  char str1[200];
  char str2[200];
  char *format = "%g format g %.g format g %4g format g %4.g format g %#5.10g!";
  double num = -0.0000756589367;
  ck_assert_int_eq(sprintf(str1, format, num, num, num, num, num),
                   s21_sprintf(str2, format, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_g) {
  char str1[200];
  char str2[200];
  char *format = "%g format g %.g format g %4g format g %4.g format g %5.10g!";
  double num = 573429.56589367;
  ck_assert_int_eq(sprintf(str1, format, num, num, num, num, num),
                   s21_sprintf(str2, format, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_g) {
  char str1[200];
  char str2[200];
  char *format =
      "%g format g %.0g format g %2.2g format g %4.g format g %6.10g!";
  double num = -486.7984846544;
  ck_assert_int_eq(sprintf(str1, format, num, num, num, num, num),
                   s21_sprintf(str2, format, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_g) {
  char str1[200];
  char str2[200];
  char *format = "format g: %15.1g\nformat g: %16.2g\nformat g: %18.3g!";
  double num = -4788744.798556484684;
  ck_assert_int_eq(sprintf(str1, format, num, num, num),
                   s21_sprintf(str2, format, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
///////////////////-----sprintf_cpec_e-----///////////////////

START_TEST(sprintf_1_e) {
  char str1[100];
  char str2[100];
  char *format = "%e format e %5e format e %5.e";
  double num = -5656856565.;
  ck_assert_int_eq(sprintf(str1, format, num, num, num),
                   s21_sprintf(str2, format, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_e) {
  char str1[100];
  char str2[100];
  char *format = "%e\n%.e\n%4e\n%4.e\n%5.10e!";
  double num = -8998848488.;
  ck_assert_int_eq(sprintf(str1, format, num, num, num, num, num),
                   s21_sprintf(str2, format, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_e) {
  char str1[100];
  char str2[100];
  char *format = "%#e\n%#.e\n%#5.e\n%#.0e\n%#0.0e!";
  double num = -6115454568.;
  ck_assert_int_eq(sprintf(str1, format, num, num, num, num, num),
                   s21_sprintf(str2, format, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_e) {
  char str1[300];
  char str2[300];
  char *format = "format e: %020e\n format e: %020.e!";
  double num = -9879849846484.;
  ck_assert_int_eq(sprintf(str1, format, num, num),
                   s21_sprintf(str2, format, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_e) {
  char str1[300];
  char str2[300];
  char *format = "format e: %010e\n format e: %010.e!";
  double num = -488948459548589.;
  ck_assert_int_eq(sprintf(str1, format, num, num),
                   s21_sprintf(str2, format, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_e) {
  char str1[300];
  char str2[300];
  char *format = "format e: %0.0e!";
  double num = -79844848484848.;
  ck_assert_int_eq(sprintf(str1, format, num), s21_sprintf(str2, format, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_e) {
  char str1[300];
  char str2[300];
  char *format = "format e: %020e\nformat e: %020.e!";
  double num = -4655645484787887888888887878874848484848488484858585858959.;
  ck_assert_int_eq(sprintf(str1, format, num, num),
                   s21_sprintf(str2, format, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_e) {
  char str1[300];
  char str2[300];
  char *format = "format e: %010e\n format e: %010.e\nformat e: %0.0e!";
  double num = -744848484845853444444444477777.;
  ck_assert_int_eq(sprintf(str1, format, num, num, num),
                   s21_sprintf(str2, format, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_e) {
  char str1[300];
  char str2[300];
  char *format = "format e: %020e format e: %020.5e!";
  double num = -78787888888888888999999999555.;
  ck_assert_int_eq(sprintf(str1, format, num, num),
                   s21_sprintf(str2, format, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_e) {
  char str1[300];
  char str2[300];
  char *format = "format e: %0+10.7e format e: %- 10.7e";
  double num = -78787888888888888999999999555.;
  ck_assert_int_eq(sprintf(str1, format, num, num),
                   s21_sprintf(str2, format, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_e) {
  char str1[300];
  char str2[300];
  char *format = "format e: %0+1.7e format e: %- 5.7e";
  double num = -78787888888888888999999999555.;
  ck_assert_int_eq(sprintf(str1, format, num, num),
                   s21_sprintf(str2, format, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_e) {
  char str1[300];
  char str2[300];
  char *format = "format e: %0+20.5e format e: %- 020.5e!";
  double num = -78787888888888888999999999555.;
  ck_assert_int_eq(sprintf(str1, format, num, num),
                   s21_sprintf(str2, format, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_e) {
  char str1[300];
  char str2[300];
  char *format = "format e: %-0+20.5e format e: % 020.5e!";
  double num = -8999999555.415214521;
  ck_assert_int_eq(sprintf(str1, format, num, num),
                   s21_sprintf(str2, format, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

///////////////////-----sprintf_cpec_f-----///////////////////

START_TEST(sprintf_1_f) {
  char str1[200];
  char str2[200];
  char *format = "%f format f %.f format f %4f format f %4.f format f %5.10f!";
  double num = 8785.464651564541;
  ck_assert_int_eq(sprintf(str1, format, num, num, num, num, num),
                   s21_sprintf(str2, format, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_f) {
  char str1[200];
  char str2[200];
  char *format = "%f format f %.f format f %3f format f %4.f format f %5.10f!";
  double num = -87.4668948948498;
  ck_assert_int_eq(sprintf(str1, format, num, num, num, num, num),
                   s21_sprintf(str2, format, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_f) {
  char str1[400];
  char str2[400];
  char *format = "%Lf\n%.Lf!";
  long double num_long = -45454.388282828;
  ck_assert_int_eq(sprintf(str1, format, num_long, num_long),
                   s21_sprintf(str2, format, num_long, num_long));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_f) {
  char str1[400];
  char str2[400];
  char *format = "%20.10f\n%20.15f\n%-20.5f!";
  double num = -654.485;
  ck_assert_int_eq(sprintf(str1, format, num, num, num),
                   s21_sprintf(str2, format, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_f) {
  char str1[400];
  char str2[400];
  char *format = "%Lf\n%.Lf\n%+-#Lf\n%+#.Lf\n%-#.Lf!";
  long double num = 7895.589598;
  ck_assert_int_eq(sprintf(str1, format, num, num, num, num, num),
                   s21_sprintf(str2, format, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_f) {
  char str1[400];
  char str2[400];
  char *format = "format f: %5f\nformat f: %6.1f\nformat f: %8.2f!";
  double num = 545.65856;
  ck_assert_int_eq(sprintf(str1, format, num, num, num),
                   s21_sprintf(str2, format, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_f) {
  char str1[400];
  char str2[400];
  char *format = "format f: %10.5f\nformat f: %12.4f!";
  double num = 98956.5959;
  ck_assert_int_eq(sprintf(str1, format, num, num),
                   s21_sprintf(str2, format, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_f) {
  char str1[400];
  char str2[400];
  char *format = "format f: %15.1f\nformat f: %16.2f\nformat f: %18.3f!";
  double num = -5958656.396959;
  ck_assert_int_eq(sprintf(str1, format, num, num, num),
                   s21_sprintf(str2, format, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_f) {
  char str1[400];
  char str2[400];
  char *format = "format f: %10.4f\nformat f: %25.5f!";
  double num = -989598.154854;
  ck_assert_int_eq(sprintf(str1, format, num, num),
                   s21_sprintf(str2, format, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_f) {
  char str1[400];
  char str2[400];
  char *format = "format f: %f\nformat f: %f!";
  float num = 1.15485744;
  ck_assert_int_eq(sprintf(str1, format, num, num),
                   s21_sprintf(str2, format, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_f) {
  char str1[400];
  char str2[400];
  char *format = "format f: %f\nformat f: %f!";
  float num = 2.1544004;
  ck_assert_int_eq(sprintf(str1, format, num, num),
                   s21_sprintf(str2, format, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_f) {
  char str1[400];
  char str2[400];
  char *format = "format f: %*f\nformat f: %*.*f";
  int width1 = 5;
  int width2 = 7;
  int accuracy = 5;
  double num1 = -989598.154854, num2 = 38748383;
  ck_assert_int_eq(
      sprintf(str1, format, width1, num1, width2, accuracy, num2),
      s21_sprintf(str2, format, width1, num1, width2, accuracy, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

////////////////////-----sprintf_cpec_x-----///////////////////

START_TEST(sprintf_1_hex) {
  char str1[100] = "";
  char str2[100] = "";
  char *format = "format x %x format x";
  int val = 0x54;
  ck_assert_int_eq(sprintf(str1, format, val), s21_sprintf(str2, format, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_hex) {
  char str1[100];
  char str2[100];
  char *format = "%x format x %x format x %x";
  int val = 0x784;
  int val2 = 0xab5f;
  int val3 = 0x3a5f1;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
                   s21_sprintf(str2, format, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_hex) {
  char str1[100];
  char str2[100];
  char *format = "%x format x %x format x %x";
  int val = 0x3a5f;
  int val2 = 0x71982;
  int val3 = 0x93a9;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
                   s21_sprintf(str2, format, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_hex) {
  char str1[100];
  char str2[100];
  char *format = "%lx format x %lx format x %hx GOD %hx";
  long int val = 56565848428;
  long val2 = 8748448485;
  unsigned short int val3 = 2959;
  unsigned short val4 = 989;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
                   s21_sprintf(str2, format, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_hex) {
  char str1[100];
  char str2[100];
  char *format = "%3x format x %5x format x %10x";
  int val = 4841;
  int val2 = 595;
  int val3 = 895499;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
                   s21_sprintf(str2, format, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_hex) {
  char str1[200];
  char str2[200];
  char *format = "%6.5x format x %.23x format x %3.x format x %.x";
  int val = 11265;
  int val2 = 5959;
  int val3 = 575;
  int val4 = 58757;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
                   s21_sprintf(str2, format, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_hex) {
  char str1[200];
  char str2[200];
  char *format = "%-10.5x format x %-.8x format x %-7x format x %-.x";
  int val = 587;
  int val2 = 757;
  int val3 = 747;
  int val4 = 29358589;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
                   s21_sprintf(str2, format, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_hex) {
  char str1[200];
  char str2[200];
  char *format = "%0x format x %0.x format x %0.0x format x %0x GOD %.x";
  int val = 747;
  int val2 = 58;
  int val3 = 747;
  int val4 = 47;
  int val5 = 58;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4, val5),
                   s21_sprintf(str2, format, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_hex) {
  char str1[200];
  char str2[200];
  char *format = "%+x format x %+3.x format x %+5.7x format x %+10x";
  int val = 47417;
  int val2 = 588;
  int val3 = 747;
  int val4 = 588;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
                   s21_sprintf(str2, format, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_hex) {
  char str1[200];
  char str2[200];
  char *format = "%+x format x %+3.x format x %+5.7x format x %+10x";
  int val = 0xabc;
  int val2 = 0xfab;
  int val3 = 0xabc;
  int val4 = 0xfab;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
                   s21_sprintf(str2, format, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

////////////////////-----sprintf_cpec_X-----////////////////

START_TEST(sprintf_1_HEX) {
  char str1[100] = "";
  char str2[100] = "";
  char *format = "format X %X format X";
  int val = 0X124;
  ck_assert_int_eq(sprintf(str1, format, val), s21_sprintf(str2, format, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_HEX) {
  char str1[100];
  char str2[100];
  char *format = "%X format X %X format X %X";
  int val = 0Xa85;
  int val2 = 0X4aff;
  int val3 = 0X356f45;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
                   s21_sprintf(str2, format, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_HEX) {
  char str1[100];
  char str2[100];
  char *format = "%X format X %X format X %X";
  int val = 0X78fd;
  int val2 = 0Xabcd;
  int val3 = 0Xabcd;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
                   s21_sprintf(str2, format, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_HEX) {
  char str1[100];
  char str2[100];
  char *format = "%lX format X %lX format X %hX GOD %hX";
  unsigned long int val = 948949848949848;
  unsigned long int val2 = 5959595;
  unsigned short int val3 = 878;
  unsigned short val4 = 45;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
                   s21_sprintf(str2, format, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_HEX) {
  char str1[100];
  char str2[100];
  char *format = "%3X format X %5X format X %10X";
  int val = 8899798;
  int val2 = 654884848;
  int val3 = 895929595;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
                   s21_sprintf(str2, format, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_HEX) {
  char str1[200];
  char str2[200];
  char *format = "%6.5X format X %.23X format X %3.X format X %.X";
  int val = 122215;
  int val2 = 98998;
  int val3 = 8998;
  int val4 = 7788;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
                   s21_sprintf(str2, format, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_HEX) {
  char str1[200];
  char str2[200];
  char *format = "%-10.5X format X %-.8X format X %-7X format X %-.X";
  int val = 2872;
  int val2 = 47887;
  int val3 = 585;
  int val4 = 29757839;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
                   s21_sprintf(str2, format, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_HEX) {
  char str1[200];
  char str2[200];
  char *format = "%0X format X %0.X format X %0.0X format X %0X GOD %.X";
  int val = 2828;
  int val2 = 28727;
  int val3 = 77887;
  int val4 = 44455;
  int val5 = 78798783;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4, val5),
                   s21_sprintf(str2, format, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_HEX) {
  char str1[200];
  char str2[200];
  char *format = "%+X format X %+3.X format X %+5.7X format X %+10X";
  int val = 78;
  int val2 = 85585;
  int val3 = 788;
  int val4 = 454;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
                   s21_sprintf(str2, format, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_HEX) {
  char str1[200];
  char str2[200];
  char *format = "%+X format X %+3.X format X %+5.7X format X %+10X";
  int val = 0Xabc;
  int val2 = 0xfab;
  int val3 = 0xfab;
  int val4 = 0xfab;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
                   s21_sprintf(str2, format, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

////////////////////-----sprintf_cpec_i-----////////////////

START_TEST(sprintf_1_signed_i) {
  char str1[100] = "";
  char str2[100] = "";
  char *format = "format i %d format i";
  int val = -1727722;
  ck_assert_int_eq(sprintf(str1, format, val), s21_sprintf(str2, format, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_signed_i) {
  char str1[100];
  char str2[100];
  char *format = "%d format i %d format i %d";
  int val = 01123;
  int val2 = -07217;
  int val3 = 077242764;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
                   s21_sprintf(str2, format, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_signed_i) {
  char str1[100];
  char str2[100];
  char *format = "%i format i %i format i %i";
  int val = 112121;
  int val2 = 1313;
  int val3 = 1211541;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
                   s21_sprintf(str2, format, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// START_TEST(sprintf_4_signed_i) {
//   char str1[100];
//   char str2[100];
//   char *format = "%li format i %li format i %hi GOD %hi";
//   long int val = 121313213211;
//   signed long val2 = -13121;
//   short int val3 = -798;
//   short int val4 = 46546;
//   ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
//                    s21_sprintf(str2, format, val, val2, val3, val4));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

START_TEST(sprintf_5_signed_i) {
  char str1[100];
  char str2[100];
  char *format = "%3i format i %5i format i %10i";
  int val = -12123;
  int val2 = -464658;
  int val3 = -7987897;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
                   s21_sprintf(str2, format, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_signed_i) {
  char str1[200];
  char str2[200];
  char *format = "%6.5i format i %.23i format i %3.i format i %.i";
  int val = -15468;
  int val2 = -1564848;
  int val3 = -145;
  int val4 = -55656;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
                   s21_sprintf(str2, format, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_signed_i) {
  char str1[200];
  char str2[200];
  char *format = "%-10.5i format i %-.8i format i %-7i format i %-.i";
  int val = -46445;
  int val2 = -78798;
  int val3 = -13215;
  int val4 = -8978;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
                   s21_sprintf(str2, format, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_signed_i) {
  char str1[200];
  char str2[200];
  char *format = "%0i format i %0.i format i %0.0i format i %0i GOD %.i";
  int val = -123134;
  int val2 = -7987;
  int val3 = -98784;
  int val4 = -155;
  int val5 = -0000155;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4, val5),
                   s21_sprintf(str2, format, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_signed_i) {
  char str1[200];
  char str2[200];
  char *format = "%+i format i %+3.i format i %+5.7i format i %+10i";
  int val = -54564;
  int val2 = -4774;
  int val3 = -858;
  int val4 = -7587;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
                   s21_sprintf(str2, format, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

////////////////////-----sprintf_cpec_n-----////////////////

START_TEST(sprintf_1_n) {
  char str1[100] = "";
  char str2[100] = "";
  char *format = "format n %n format n";
  int valn1 = 0, valn2 = 0;
  ck_assert_int_eq(sprintf(str1, format, &valn1),
                   s21_sprintf(str2, format, &valn2));
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(valn1, valn2);
}
END_TEST

START_TEST(sprintf_2_n) {
  char str1[100];
  char str2[100];
  char *format = "format n %o %n format n %o%n";
  int val = 524;
  int val2 = 2524;
  int valn1 = 0, valn2 = 0, valn3 = 0, valn4 = 0;
  ck_assert_int_eq(sprintf(str1, format, val, &valn1, val2, &valn3),
                   s21_sprintf(str2, format, val, &valn2, val2, &valn4));
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(valn1, valn2);
  ck_assert_int_eq(valn3, valn4);
}
END_TEST

////////////////////-----sprintf_cpec_o-----////////////////

START_TEST(sprintf_1_octal) {
  char str1[100] = "";
  char str2[100] = "";
  char *format = "format o %o format o";
  int val = 224;
  ck_assert_int_eq(sprintf(str1, format, val), s21_sprintf(str2, format, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_octal) {
  char str1[100];
  char str2[100];
  char *format = "%o format o %o format o %o";
  int val = 42;
  int val2 = 572;
  int val3 = 07277425464;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
                   s21_sprintf(str2, format, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_octal) {
  char str1[100];
  char str2[100];
  char *format = "%o format o %o format o %o";
  int val = 72;
  int val2 = 274;
  int val3 = 727;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
                   s21_sprintf(str2, format, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_octal) {
  char str1[100];
  char str2[100];
  char *format = "%lo format o %lo format o %ho GOD %ho";
  long int val = 272727272;
  unsigned long int val2 = 757;
  unsigned short int val3 = 872;
  unsigned short val4 = 752;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
                   s21_sprintf(str2, format, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_octal) {
  char str1[100];
  char str2[100];
  char *format = "%3o format o %5o format o %10o";
  int val = 5875;
  int val2 = 785;
  int val3 = 7578;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
                   s21_sprintf(str2, format, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_octal) {
  char str1[200];
  char str2[200];
  char *format = "%6.5o format o %.23o format o %3.o format o %.o";
  int val = 785;
  int val2 = 78;
  int val3 = 87;
  int val4 = 785;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
                   s21_sprintf(str2, format, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_octal) {
  char str1[200];
  char str2[200];
  char *format = "%-10.5o format o %-.8o format o %-7o format o %-.o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
                   s21_sprintf(str2, format, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_octal) {
  char str1[200];
  char str2[200];
  char *format = "%0o format o %0.o format o %0.0o format o %0o GOD %.o";
  int val = 42;
  int val2 = 782;
  int val3 = 382;
  int val4 = 29727839;
  int val5 = 782;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4, val5),
                   s21_sprintf(str2, format, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_octal) {
  char str1[200];
  char str2[200];
  char *format = "%+o format o %+3.o format o %+5.7o format o %+10o";
  int val = 7825;
  int val2 = 387;
  int val3 = 788;
  int val4 = 782;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
                   s21_sprintf(str2, format, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

////////////////////-----sprintf_percent-----////////////////

START_TEST(sprintf_1_percent) {
  char str1[100] = "";
  char str2[100] = "";
  char *format = "%%format per %o format per";
  int val = 452;
  ck_assert_int_eq(sprintf(str1, format, val), s21_sprintf(str2, format, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_percent) {
  char str1[100];
  char str2[100];
  char *format = "format per %o per%%%%per %o";
  int val = 53;
  int val2 = 5254;
  ck_assert_int_eq(sprintf(str1, format, val, val2),
                   s21_sprintf(str2, format, val, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_percent) {
  char str1[100];
  char str2[100];
  char *format = "%o per%%per %o format per %o";
  int val = 452;
  int val2 = 42;
  int val3 = 36;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
                   s21_sprintf(str2, format, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

////////////////////-----sprintf_cpec_p-----////////////////

START_TEST(sprintf_1_pointer) {
  char str1[100] = "";
  char str2[100] = "";
  char *format = "format p %p format p";
  char *val = "25";
  ck_assert_int_eq(sprintf(str1, format, val), s21_sprintf(str2, format, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_pointer) {
  char str1[100];
  char str2[100];
  char *format = "%p format p %p format p %p";
  char *val = "42";
  char *val2 = "45245";
  char *val3 = "0p31224523";
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
                   s21_sprintf(str2, format, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_pointer) {
  char str1[100];
  char str2[100];
  char *format = "%p format p %p format p %p";
  char *val = "425";
  char *val2 = "452";
  char *val3 = "452";
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
                   s21_sprintf(str2, format, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_pointer) {
  char str1[100];
  char str2[100];
  char *format = "%p format p %p format p %p  %p";
  long int *val = (void *)3088675747373646;
  long long int *val2 = (void *)33030030303;
  unsigned short int *val3 = (void *)22600;
  unsigned char *val4 = (void *)120;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
                   s21_sprintf(str2, format, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_pointer) {
  char str1[100];
  char str2[100];
  char *format = "%3p format p %5p format p %12p";
  char *val = "17174";
  char *val2 = "2572";
  char *val3 = "36838";
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
                   s21_sprintf(str2, format, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_pointer) {
  char str1[200];
  char str2[200];
  char *format = "%6.5p format p %.23p format p %3.p format p %.p";
  char *val = "72178";
  char *val2 = "8725";
  char *val3 = "857";
  char *val4 = "7858";
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
                   s21_sprintf(str2, format, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_pointer) {
  char str1[200];
  char str2[200];
  char *format = "%-10.5p format p %-.4p format p %-16p format p %-.5p";
  char *val = "3015";
  char *val2 = "712";
  char *val3 = "99";
  char *val4 = "2939";
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
                   s21_sprintf(str2, format, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_pointer) {
  char str1[200];
  char str2[200];
  char *format = "%0p format p %0.p format p %0.0p format p %0p  %.p";
  char *val = "78578";
  char *val2 = "278287";
  char *val3 = "785";
  char *val4 = "78528";
  char *val5 = "24";
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4, val5),
                   s21_sprintf(str2, format, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_pointer) {
  char str1[200];
  char str2[200];
  char *format = "%+p format p %+3.p format p %+5.7p format p %+10p";
  char *val = "785";
  char *val2 = "785";
  char *val3 = "99785";
  char *val4 = "757";
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
                   s21_sprintf(str2, format, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

////////////////////-----sprintf_cpec_s-----////////////////

START_TEST(sprintf_1_string) {
  char str1[100] = "";
  char str2[100] = "";
  char *format = "format s %s format s";
  char *val = "ck_assert_pstr_eq(str1, str2);";
  ck_assert_int_eq(sprintf(str1, format, val), s21_sprintf(str2, format, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_string) {
  char str1[200];
  char str2[200];
  char *format = "%s %s %s";
  char *val = " in this language i";
  char *val2 = "equence of actions";
  char *val3 = " described in this langua";
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
                   s21_sprintf(str2, format, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_string) {
  char str1[100];
  char str2[100];
  char *format = "%s %s %s";
  char *val = "you said to the ";
  char *val2 = "you said to the thoughtful";
  char *val3 = "you said to the ";
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
                   s21_sprintf(str2, format, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_string) {
  char str1[200];
  char str2[200];
  char *format = "%3s s %5s s %10s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore";
  char *val3 = "PPAP";
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
                   s21_sprintf(str2, format, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_string) {
  char str1[200];
  char str2[200];
  char *format = "%6.5s s %.23s  s %3.s s %.s";
  char *val =
      "After a few seconds, Turing came to a logical conclusion to entrust the "
      "job to you";
  char *val2 = " logical conclusion to entrust the job to you";
  char *val3 = " the job to you";
  char *val4 = " good";
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
                   s21_sprintf(str2, format, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_string) {
  char str1[200];
  char str2[200];
  char *format = "%-10.5s  s %-.8s  s %-7s  s %-.s";
  char *val =
      "In this project you will develop your own implementation of the "
      "string.h";
  char *val2 = " your own implementation of the string.hy";
  char *val3 = " of the string.h";
  char *val4 = "In this project you will develop you";
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
                   s21_sprintf(str2, format, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_string) {
  char str1[200];
  char str2[200];
  char *format = "%0s  s %0.s  s %0.0s  s %0s  %.s";
  char *val =
      "In this project you will develop your own implementation of the "
      "string.h";
  char *val2 = "i don't care anymore, really";
  char *val3 =
      "InIn this project you will develop your own implementatmplementation of "
      "the string.h";
  char *val4 =
      "vIn this project you will develop your own implementation of the "
      "string.h";
  char *val5 = "v!";
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4, val5),
                   s21_sprintf(str2, format, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_string) {
  char str1[200];
  char str2[200];
  char *format = "%+s  s %+3.s  s %5.7s  s %10s";
  char *val =
      "The C programming language has a set of functions implementing "
      "operations on strings";
  char *val2 = " a set of functions implementing operations on strings";
  char *val3 =
      " language has a set of functions implementing operations on strings";
  char *val4 = " operations on strings";
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
                   s21_sprintf(str2, format, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

////////////////////-----sprintf_cpec_u-----////////////////

START_TEST(sprintf_1_unsigned) {
  char str1[100] = "";
  char str2[100] = "";
  char *format = "format u %u format u";
  unsigned int val = 012;
  ck_assert_int_eq(sprintf(str1, format, val), s21_sprintf(str2, format, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_unsigned) {
  char str1[100];
  char str2[100];
  char *format = "%u format u %u format u %u";
  unsigned int val = 5857;
  unsigned int val2 = 05000;
  unsigned int val3 = 07464;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
                   s21_sprintf(str2, format, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_unsigned) {
  char str1[100];
  char str2[100];
  char *format = "%u format u %u format u %u";
  unsigned int val = 785;
  unsigned int val2 = 75587;
  unsigned int val3 = 7587;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
                   s21_sprintf(str2, format, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_unsigned) {
  char str1[100];
  char str2[100];
  char *format = "%lu format u %lu format u %hu GOD %hu";
  long unsigned int val = 96969;
  long unsigned val2 = 5885;
  unsigned short val3 = 8657;
  unsigned short val4 = 699;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
                   s21_sprintf(str2, format, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_unsigned) {
  char str1[100];
  char str2[100];
  char *format = "%3u format u %5u format u %10u";
  unsigned int val = 58757;
  unsigned int val2 = 69685;
  unsigned int val3 = 785857;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3),
                   s21_sprintf(str2, format, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_unsigned) {
  char str1[200];
  char str2[200];
  char *format = "%6.5u format u %.23u format u %3.u format u %.u";
  unsigned int val = 69858;
  unsigned int val2 = 78578;
  unsigned int val3 = 69875;
  unsigned int val4 = 9867;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
                   s21_sprintf(str2, format, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_unsigned) {
  char str1[200];
  char str2[200];
  char *format = "%-10.5u format u %-.8u format u %-7u format u %-.u";
  unsigned int val = 698685;
  unsigned int val2 = 7578;
  unsigned int val3 = 687985;
  unsigned int val4 = 987;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
                   s21_sprintf(str2, format, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_unsigned) {
  char str1[200];
  char str2[200];
  char *format = "%0u format u %0.u format u %0.0u format u %0u qwe %.u";
  unsigned int val = 5785;
  unsigned int val2 = 6987;
  unsigned int val3 = 6978;
  unsigned int val4 = 6978;
  unsigned int val5 = 96878;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4, val5),
                   s21_sprintf(str2, format, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_unsigned) {
  char str1[200];
  char str2[200];
  char *format = "%+u format u %+3.u format u %+5.7u format u %+10u";
  unsigned int val = 697;
  unsigned int val2 = 9678;
  unsigned int val3 = 6987;
  unsigned int val4 = 785878;
  ck_assert_int_eq(sprintf(str1, format, val, val2, val3, val4),
                   s21_sprintf(str2, format, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *suiteSprintf(void) {
  Suite *s = suite_create("suite_sprintf");

  // Добавление тестов в набор
  TCase *tc_cpec_c = tcase_create("cpec_c");
  tcase_add_test(tc_cpec_c, sprintf_1_c);
  tcase_add_test(tc_cpec_c, sprintf_2_c);
  tcase_add_test(tc_cpec_c, sprintf_3_c);
  tcase_add_test(tc_cpec_c, sprintf_4_c);
  tcase_add_test(tc_cpec_c, sprintf_5_c);
  tcase_add_test(tc_cpec_c, sprintf_6_c);
  tcase_add_test(tc_cpec_c, sprintf_7_c);
  tcase_add_test(tc_cpec_c, sprintf_8_c);
  tcase_add_test(tc_cpec_c, sprintf_9_c);
  tcase_add_test(tc_cpec_c, sprintf_10_c);
  suite_add_tcase(s, tc_cpec_c);

  // Добавление тестов в набор
  TCase *tc_cpec_d = tcase_create("cpec_d");
  tcase_add_test(tc_cpec_d, sprintf_1_signed);
  tcase_add_test(tc_cpec_d, sprintf_2_signed);
  tcase_add_test(tc_cpec_d, sprintf_3_signed);
  tcase_add_test(tc_cpec_d, sprintf_4_signed);
  tcase_add_test(tc_cpec_d, sprintf_5_signed);
  tcase_add_test(tc_cpec_d, sprintf_6_signed);
  tcase_add_test(tc_cpec_d, sprintf_7_signed);
  tcase_add_test(tc_cpec_d, sprintf_8_signed);
  tcase_add_test(tc_cpec_d, sprintf_9_signed);
  tcase_add_test(tc_cpec_d, sprintf_10_signed);
  suite_add_tcase(s, tc_cpec_d);

  // Добавление тестов в набор
  TCase *tc_cpec_g = tcase_create("cpec_g");
  tcase_add_test(tc_cpec_g, sprintf_1_g);
  tcase_add_test(tc_cpec_g, sprintf_3_g);
  tcase_add_test(tc_cpec_g, sprintf_4_g);
  tcase_add_test(tc_cpec_g, sprintf_5_g);
  tcase_add_test(tc_cpec_g, sprintf_6_g);
  tcase_add_test(tc_cpec_g, sprintf_7_g);
  tcase_add_test(tc_cpec_g, sprintf_8_g);
  tcase_add_test(tc_cpec_g, sprintf_9_g);
  suite_add_tcase(s, tc_cpec_g);

  // Добавление тестов в набор
  TCase *tc_cpec_e = tcase_create("cpec_e");
  tcase_add_test(tc_cpec_e, sprintf_1_e);
  tcase_add_test(tc_cpec_e, sprintf_2_e);
  tcase_add_test(tc_cpec_e, sprintf_3_e);
  tcase_add_test(tc_cpec_e, sprintf_4_e);
  tcase_add_test(tc_cpec_e, sprintf_5_e);
  tcase_add_test(tc_cpec_e, sprintf_6_e);
  tcase_add_test(tc_cpec_e, sprintf_7_e);
  tcase_add_test(tc_cpec_e, sprintf_8_e);
  tcase_add_test(tc_cpec_e, sprintf_9_e);
  tcase_add_test(tc_cpec_e, sprintf_10_e);
  tcase_add_test(tc_cpec_e, sprintf_11_e);
  tcase_add_test(tc_cpec_e, sprintf_12_e);
  tcase_add_test(tc_cpec_e, sprintf_13_e);
  suite_add_tcase(s, tc_cpec_e);

  // Добавление тестов в набор
  TCase *tc_cpec_f = tcase_create("cpec_f");
  tcase_add_test(tc_cpec_f, sprintf_1_f);
  tcase_add_test(tc_cpec_f, sprintf_2_f);
  tcase_add_test(tc_cpec_f, sprintf_3_f);
  tcase_add_test(tc_cpec_f, sprintf_4_f);
  tcase_add_test(tc_cpec_f, sprintf_5_f);
  tcase_add_test(tc_cpec_f, sprintf_6_f);
  tcase_add_test(tc_cpec_f, sprintf_7_f);
  tcase_add_test(tc_cpec_f, sprintf_8_f);
  tcase_add_test(tc_cpec_f, sprintf_9_f);
  tcase_add_test(tc_cpec_f, sprintf_10_f);
  tcase_add_test(tc_cpec_f, sprintf_11_f);
  tcase_add_test(tc_cpec_f, sprintf_12_f);
  suite_add_tcase(s, tc_cpec_f);

  // Добавление тестов в набор
  TCase *tc_cpec_x = tcase_create("cpec_x");
  tcase_add_test(tc_cpec_x, sprintf_1_hex);
  tcase_add_test(tc_cpec_x, sprintf_2_hex);
  tcase_add_test(tc_cpec_x, sprintf_3_hex);
  tcase_add_test(tc_cpec_x, sprintf_4_hex);
  tcase_add_test(tc_cpec_x, sprintf_5_hex);
  tcase_add_test(tc_cpec_x, sprintf_6_hex);
  tcase_add_test(tc_cpec_x, sprintf_7_hex);
  tcase_add_test(tc_cpec_x, sprintf_8_hex);
  tcase_add_test(tc_cpec_x, sprintf_9_hex);
  tcase_add_test(tc_cpec_x, sprintf_10_hex);
  suite_add_tcase(s, tc_cpec_x);

  // Добавление тестов в набор
  TCase *tc_cpec_X = tcase_create("cpec_X");
  tcase_add_test(tc_cpec_X, sprintf_1_HEX);
  tcase_add_test(tc_cpec_X, sprintf_2_HEX);
  tcase_add_test(tc_cpec_X, sprintf_3_HEX);
  tcase_add_test(tc_cpec_X, sprintf_4_HEX);
  tcase_add_test(tc_cpec_X, sprintf_5_HEX);
  tcase_add_test(tc_cpec_X, sprintf_6_HEX);
  tcase_add_test(tc_cpec_X, sprintf_7_HEX);
  tcase_add_test(tc_cpec_X, sprintf_8_HEX);
  tcase_add_test(tc_cpec_X, sprintf_9_HEX);
  tcase_add_test(tc_cpec_X, sprintf_10_HEX);
  suite_add_tcase(s, tc_cpec_X);

  // Добавление тестов в набор
  TCase *tc_cpec_i = tcase_create("cpec_i");
  tcase_add_test(tc_cpec_i, sprintf_1_signed_i);
  tcase_add_test(tc_cpec_i, sprintf_2_signed_i);
  tcase_add_test(tc_cpec_i, sprintf_3_signed_i);
  //   tcase_add_test(tc_cpec_i, sprintf_4_signed_i);
  tcase_add_test(tc_cpec_i, sprintf_5_signed_i);
  tcase_add_test(tc_cpec_i, sprintf_6_signed_i);
  tcase_add_test(tc_cpec_i, sprintf_7_signed_i);
  tcase_add_test(tc_cpec_i, sprintf_8_signed_i);
  tcase_add_test(tc_cpec_i, sprintf_9_signed_i);
  suite_add_tcase(s, tc_cpec_i);

  // Добавление тестов в набор
  TCase *tc_cpec_n = tcase_create("cpec_n");
  tcase_add_test(tc_cpec_n, sprintf_1_n);
  tcase_add_test(tc_cpec_n, sprintf_2_n);
  suite_add_tcase(s, tc_cpec_n);

  // Добавление тестов в набор
  TCase *tc_cpec_o = tcase_create("cpec_o");
  tcase_add_test(tc_cpec_o, sprintf_1_octal);
  tcase_add_test(tc_cpec_o, sprintf_2_octal);
  tcase_add_test(tc_cpec_o, sprintf_3_octal);
  tcase_add_test(tc_cpec_o, sprintf_4_octal);
  tcase_add_test(tc_cpec_o, sprintf_5_octal);
  tcase_add_test(tc_cpec_o, sprintf_6_octal);
  tcase_add_test(tc_cpec_o, sprintf_7_octal);
  tcase_add_test(tc_cpec_o, sprintf_8_octal);
  tcase_add_test(tc_cpec_o, sprintf_9_octal);
  suite_add_tcase(s, tc_cpec_o);

  // Добавление тестов в набор
  TCase *tc_percent = tcase_create("percent");
  tcase_add_test(tc_percent, sprintf_1_percent);
  tcase_add_test(tc_percent, sprintf_2_percent);
  tcase_add_test(tc_percent, sprintf_3_percent);
  suite_add_tcase(s, tc_percent);

  // Добавление тестов в набор
  TCase *tc_cpec_p = tcase_create("cpec_p");
  tcase_add_test(tc_cpec_p, sprintf_1_pointer);
  tcase_add_test(tc_cpec_p, sprintf_2_pointer);
  tcase_add_test(tc_cpec_p, sprintf_3_pointer);
  tcase_add_test(tc_cpec_p, sprintf_4_pointer);
  tcase_add_test(tc_cpec_p, sprintf_5_pointer);
  tcase_add_test(tc_cpec_p, sprintf_6_pointer);
  tcase_add_test(tc_cpec_p, sprintf_7_pointer);
  tcase_add_test(tc_cpec_p, sprintf_8_pointer);
  tcase_add_test(tc_cpec_p, sprintf_9_pointer);
  suite_add_tcase(s, tc_cpec_p);

  // Добавление тестов в набор
  TCase *tc_cpec_s = tcase_create("cpec_s");
  tcase_add_test(tc_cpec_s, sprintf_1_string);
  tcase_add_test(tc_cpec_s, sprintf_2_string);
  tcase_add_test(tc_cpec_s, sprintf_3_string);
  tcase_add_test(tc_cpec_s, sprintf_5_string);
  tcase_add_test(tc_cpec_s, sprintf_6_string);
  tcase_add_test(tc_cpec_s, sprintf_7_string);
  tcase_add_test(tc_cpec_s, sprintf_8_string);
  tcase_add_test(tc_cpec_s, sprintf_9_string);
  suite_add_tcase(s, tc_cpec_s);

  // Добавление тестов в набор
  TCase *tc_cpec_u = tcase_create("cpec_u");
  tcase_add_test(tc_cpec_u, sprintf_1_unsigned);
  tcase_add_test(tc_cpec_u, sprintf_2_unsigned);
  tcase_add_test(tc_cpec_u, sprintf_3_unsigned);
  tcase_add_test(tc_cpec_u, sprintf_4_unsigned);
  tcase_add_test(tc_cpec_u, sprintf_5_unsigned);
  tcase_add_test(tc_cpec_u, sprintf_6_unsigned);
  tcase_add_test(tc_cpec_u, sprintf_7_unsigned);
  tcase_add_test(tc_cpec_u, sprintf_8_unsigned);
  tcase_add_test(tc_cpec_u, sprintf_9_unsigned);
  suite_add_tcase(s, tc_cpec_u);

  return s;
}