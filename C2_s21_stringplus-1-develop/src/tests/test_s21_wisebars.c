#include "s21_tests.h"

START_TEST(test_memchr) {
  char src1_def[15] = "123456789";
  char src1_s21[15] = "123456789";
  ck_assert_str_eq(memchr(src1_def, '4', 10), s21_memchr(src1_s21, '4', 10));

  char str1[10] = "Hei";
  ck_assert_mem_eq(s21_memchr(str1, 'e', 5), memchr(str1, 'e', 5), 5);

  char str2[14] = "kekLoleepops";
  ck_assert_mem_eq(s21_memchr(str2, 'l', 0), memchr(str2, 'l', 0), 0);
}
END_TEST

START_TEST(test_memcmp) {
  char src1[15] = "12345678901";
  char dst1[15] = "12345678901";
  ck_assert_msg(memcmp(src1, dst1, 15) == 0 && s21_memcmp(src1, dst1, 15) == 0,
                "no");

  char src2[15] = "12345678901";
  char dst2[15] = "tertertet";
  ck_assert_int_eq(memcmp(src2, dst2, 15), s21_memcmp(src2, dst2, 15));

  char src3[15] = "12345678901";
  char dst3[15] = "werwe";
  ck_assert_msg(memcmp(src3, dst3, 15) <= 0 && s21_memcmp(src3, dst3, 15) <= 0,
                "No");

  char src4[15] = "erteterteqwe";
  char dst4[15] = "erteterte";
  ck_assert_msg(memcmp(src4, dst4, 15) >= 0 && s21_memcmp(src4, dst4, 15) >= 0,
                "No");
}
END_TEST

START_TEST(test_memcpy) {
  char str1_def[60], str1_s21[60], str1_text[] = "123456";
  memcpy(str1_def, str1_text, 7);
  s21_memcpy(str1_s21, str1_text, 7);
  ck_assert_str_eq(str1_def, str1_s21);

  char str2_def[] = "aaaaaaaaaaaaaaaaaaaaaaaaa";
  char str2_s21[] = "aaaaaaaaaaaaaaaaaaaaaaaaa";
  char str2_text[] = "Hello, I am from Africa.";
  memcpy(str2_def, str2_text, 10);
  s21_memcpy(str2_s21, str2_text, 10);
  ck_assert_str_eq(str2_def, str2_s21);
}
END_TEST

START_TEST(test_memmove) {
  char dest1_def[] = "abcd";
  char dest1_s21[] = "abcd";
  char src1[] = "****";
  ck_assert_str_eq(memmove(dest1_def, src1, 4),
                   s21_memmove(dest1_s21, src1, 4));

  char dest2_def[] = "123456789";
  char dest2_s21[] = "123456789";
  char src2[] = "******";
  ck_assert_str_eq(memmove(dest2_def, src2, 6), "******789");
  ck_assert_str_eq(s21_memmove(dest2_s21, src2, 6), "******789");

  char dest3_def[] = "1234567890";
  char dest3_s21[] = "1234567890";
  ck_assert_str_eq(memmove(&dest3_def[4], &dest3_def[3], 3),
                   s21_memmove(&dest3_s21[4], &dest3_s21[3], 3));
}
END_TEST

START_TEST(test_memset) {
  unsigned char src1[15] = "1234567890";
  unsigned char src2[15] = "1234567890";
  ck_assert_str_eq(memset(src1, '1', 10), s21_memset(src2, '1', 10));

  unsigned char src3[25] = "gergeebdjnyjtykxhdurnr";
  unsigned char src4[25] = "gergeebdjnyjtykxhdurnr";
  ck_assert_str_eq(memset(src3, '1', 20), s21_memset(src4, '1', 20));
}
END_TEST

START_TEST(test_strchr) {
  char str1[11] = "23456789";
  char *chr1_base;
  char *chr1_s21;
  int c1 = '4';

  chr1_base = strchr(str1, c1);
  chr1_s21 = s21_strchr(str1, c1);
  ck_assert_str_eq(chr1_base, chr1_s21);

  char str2[11] = "23456789";
  char *chr2_base;
  char *chr2_s21;
  int c2 = '1';

  chr2_base = strchr(str2, c2);
  chr2_s21 = s21_strchr(str2, c2);
  ck_assert(chr2_base == chr2_s21);

  char str3[] = "Hello world";
  int c3 = '\0';
  ck_assert_str_eq(s21_strchr(str3, c3), strchr(str3, c3));

  char str4[] = "";
  int c4 = '\0';
  ck_assert_str_eq(s21_strchr(str4, c4), strchr(str4, c4));
}
END_TEST

START_TEST(test_strcat) {
  char app1[10] = "end";
  char dest1[10] = "start";
  ck_assert_str_eq(strcat(dest1, app1), s21_strcat(dest1, app1));

  char app2[10] = "end";
  char dest2[10] = "";
  ck_assert_str_eq(strcat(dest2, app2), s21_strcat(dest2, app2));

  char app3[10] = "";
  char dest3[10] = "start";
  ck_assert_str_eq(strcat(dest3, app3), s21_strcat(dest3, app3));

  char app4[10] = " ";
  char dest4[10] = "   ";
  ck_assert_str_eq(s21_strcat(dest4, app4), strcat(dest4, app4));

  char app5[10] = "\0";
  char dest5[10] = "\n\0";
  ck_assert_str_eq(s21_strcat(dest5, app5), strcat(dest5, app5));
}
END_TEST

// START_TEST(test_strcmp) {
//   char str1[10] = "abc";
//   char str2[10] = "abc";
//   ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));

//   char str3[] = "abc";
//   char str4[] = "cba";
//   int sr_s21 = s21_strcmp(str3, str4);
//   int sr_base = strcmp(str3, str4);
//   ck_assert_float_eq(sr_s21, sr_base);

//   char str5[10] = "\0";
//   char str6[10] = "\0";
//   ck_assert_int_eq(strcmp(str5, str6), s21_strcmp(str5, str6));

//   char str7[10] = " ";
//   char str8[10] = " ";
//   ck_assert_int_eq(strcmp(str7, str8), s21_strcmp(str7, str8));
// }
// END_TEST

START_TEST(test_strcpy) {
  char str1[30] = "First row\0second row";
  char dest1[40] = "";
  ck_assert_str_eq(strcpy(dest1, str1), s21_strcpy(dest1, str1));

  char str2[30] = "First row\nsecond row";
  char dest2[40] = "";
  ck_assert_str_eq(strcpy(dest2, str2), s21_strcpy(dest2, str2));

  char str3[30] = "\0First row second row";
  char dest3[40] = "";
  ck_assert_str_eq(strcpy(dest3, str3), s21_strcpy(dest3, str3));
}
END_TEST

START_TEST(test_strcspn) {
  char str[] = "ahbchghghghygfd";
  ck_assert_int_eq(strcspn(str, "abc"), s21_strcspn(str, "abc"));
  ck_assert_int_eq(strcspn(str, "cab"), s21_strcspn(str, "cab"));
  ck_assert_int_eq(strcspn(str, "1"), s21_strcspn(str, "1"));
  ck_assert_int_eq(strcspn(str, "hy"), s21_strcspn(str, "hy"));
}
END_TEST

START_TEST(test_strncat) {
  char app1[10] = "end";
  char dest1[10] = "start";
  ck_assert_str_eq(strncat(dest1, app1, 4), s21_strncat(dest1, app1, 4));

  char app2[10] = "end";
  char dest2[10] = "";
  ck_assert_str_eq(strncat(dest2, app2, 3), s21_strncat(dest2, app2, 3));

  char app3[10] = "";
  char dest3[10] = "start";
  ck_assert_str_eq(strncat(dest3, app3, 2), s21_strncat(dest3, app3, 2));

  char app4[10] = " ";
  char dest4[10] = "   ";
  ck_assert_str_eq(s21_strncat(dest4, app4, 1), strncat(dest4, app4, 1));

  char app5[10] = "\0";
  char dest5[10] = "\n\0";
  ck_assert_str_eq(s21_strncat(dest5, app5, 1), strncat(dest5, app5, 1));
}
END_TEST

START_TEST(test_strncmp) {
  char str1[10] = "abc";
  char str2[10] = "abc";
  ck_assert_int_eq(strncmp(str1, str2, 3), s21_strncmp(str1, str2, 3));

  char str3[10] = "abc";
  char str4[10] = "cba";
  ck_assert_int_eq(strncmp(str3, str4, 2), s21_strncmp(str3, str4, 2));

  char str5[10] = "\0";
  char str6[10] = "\0";
  ck_assert_int_eq(strncmp(str5, str6, 3), s21_strncmp(str5, str6, 3));

  char str7[10] = " ";
  char str8[10] = " ";
  ck_assert_int_eq(strncmp(str7, str8, 1), s21_strncmp(str7, str8, 1));
}
END_TEST

START_TEST(test_strncpy) {
  char str1[30] = "First row\0second row";
  char dest1[40] = "";
  ck_assert_str_eq(strncpy(dest1, str1, 15), s21_strncpy(dest1, str1, 15));

  char str2[30] = "First row\nsecond row";
  char dest2[40] = "";
  ck_assert_str_eq(strncpy(dest2, str2, 35), s21_strncpy(dest2, str2, 35));

  char str3[30] = "\0First row second row";
  char dest3[40] = "";
  ck_assert_str_eq(strncpy(dest3, str3, 5), s21_strncpy(dest3, str3, 5));
}
END_TEST

START_TEST(test_strlen) {
  char *str1 = "\0";
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
  char *str2 = " ";
  ck_assert_int_eq(s21_strlen(str2), strlen(str2));
  char *str3 = "four";
  ck_assert_int_eq(s21_strlen(str3), strlen(str3));
}
END_TEST

START_TEST(test_strpbrk) {
  char str1_base[] = "Ow no this is Adam";
  char str1_s21[] = "Ow no this is Adam";
  char key1[] = "o";
  char *brk1_s21, *brk1_base;

  brk1_s21 = s21_strpbrk(str1_s21, key1);
  brk1_base = strpbrk(str1_base, key1);
  ck_assert((brk1_s21 != s21_NULL) && (brk1_base != s21_NULL));
  while ((brk1_s21 != s21_NULL) && (brk1_base != s21_NULL)) {
    ck_assert_str_eq(brk1_s21, brk1_base);
    brk1_s21 = s21_strpbrk(brk1_s21 + 1, key1);
    brk1_base = strpbrk(brk1_base + 1, key1);
  }

  char str3_base[] = "Ow no this is Adam";
  char str3_s21[] = "Ow no this is Adam";
  char key3[] = "oia";
  char *brk3_s21, *brk3_base;

  brk3_s21 = s21_strpbrk(str3_s21, key3);
  brk3_base = strpbrk(str3_base, key3);
  ck_assert((brk3_s21 != s21_NULL) && (brk3_base != s21_NULL));
  while ((brk3_s21 != s21_NULL) && (brk3_base != s21_NULL)) {
    ck_assert_str_eq(brk3_s21, brk3_base);
    brk3_s21 = s21_strpbrk(brk3_s21 + 1, key3);
    brk3_base = strpbrk(brk3_base + 1, key3);
  }
}

START_TEST(test_strtok) {
  char str1_base[] = "devide the sentence - nice, cool.";
  char str1_s21[] = "devide the sentence - nice, cool.";
  char del1[] = " ,-";
  char *tok1_s21, *tok1_base;

  tok1_s21 = s21_strtok(str1_s21, del1);
  tok1_base = strtok(str1_base, del1);
  ck_assert((tok1_s21 != s21_NULL) && (tok1_base != s21_NULL));
  while ((tok1_s21 != s21_NULL) && (tok1_base != s21_NULL)) {
    ck_assert_str_eq(tok1_s21, tok1_base);
    tok1_s21 = s21_strtok(s21_NULL, del1);
    tok1_base = strtok(s21_NULL, del1);
  }

  char *str2_base = s21_NULL;
  char *str2_s21 = s21_NULL;
  char del2[] = "/";
  char *tok2_s21, *tok2_base;

  tok2_s21 = s21_strtok(str2_s21, del2);
  tok2_base = strtok(str2_base, del2);
  ck_assert_pstr_eq(tok2_s21, tok2_base);

  char str3_base[] = "devide the sentence - nice, cool.";
  char str3_s21[] = "devide the sentence - nice, cool.";
  char del3[] = " ";
  char *tok3_s21, *tok3_base;

  tok3_s21 = s21_strtok(str3_s21, del3);
  tok3_base = strtok(str3_base, del3);
  ck_assert((tok3_s21 != s21_NULL) && (tok3_base != s21_NULL));
  while ((tok3_s21 != s21_NULL) && (tok3_base != s21_NULL)) {
    ck_assert_str_eq(tok3_s21, tok3_base);
    tok3_s21 = s21_strtok(s21_NULL, del3);
    tok3_base = strtok(s21_NULL, del3);
  }
}

// Функция создания набора тестов.
Suite *suite_create_tests(void) {
  Suite *suite = suite_create("test s21_string");
  TCase *tc_core = tcase_create("core tests");

  tcase_add_test(tc_core, test_memchr);
  tcase_add_test(tc_core, test_memcmp);
  tcase_add_test(tc_core, test_memcpy);
  tcase_add_test(tc_core, test_memmove);
  tcase_add_test(tc_core, test_memset);
  tcase_add_test(tc_core, test_strchr);
  tcase_add_test(tc_core, test_strcat);
  // tcase_add_test(tc_core, test_strcmp);
  tcase_add_test(tc_core, test_strcpy);
  tcase_add_test(tc_core, test_strcspn);
  tcase_add_test(tc_core, test_strncat);
  tcase_add_test(tc_core, test_strncmp);
  tcase_add_test(tc_core, test_strncpy);
  tcase_add_test(tc_core, test_strlen);
  tcase_add_test(tc_core, test_strpbrk);
  tcase_add_test(tc_core, test_strtok);

  suite_add_tcase(suite, tc_core);

  return suite;
}

// int main(void) {
//   int failed = 0;
//   Suite *suite = suite_create_tests();
//   SRunner *runner = srunner_create(suite);

//   srunner_set_fork_status(runner, CK_NOFORK);
//   srunner_run_all(runner, CK_NORMAL);
//   // Получаем количество проваленных тестов.
//   failed = srunner_ntests_failed(runner);
//   srunner_free(runner);

//   return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
// }