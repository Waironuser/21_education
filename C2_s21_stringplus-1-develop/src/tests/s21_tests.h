#ifndef S21_TESTS_H
#define S21_TESTS_H

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

void runTestcase(Suite *testcase);
void runTests(void);

Suite *suiteSprintf_char(void);
Suite *suiteSprintf_string(void);
Suite *suiteSprintf_int(void);
Suite *suiteSprintf_int_u(void);
Suite *suiteSprintf_float(void);

Suite *suiteSprintf(void);
Suite *suite_sscanf(void);

Suite *make_strchr_suite(void);
Suite *make_strcspn_suite(void);
Suite *make_strcspn_suite(void);
Suite *make_strncat_suite(void);
Suite *make_strncmp_suite(void);
Suite *make_strncpy_suite(void);
Suite *make_strpbrk_suite(void);
Suite *make_strrchr_suite(void);
Suite *make_strstr_suite(void);
Suite *make_strerror_suite(void);

Suite *suite_create_tests(void);

Suite *suite_to_upper(void);
Suite *suite_to_lower(void);
Suite *suite_insert(void);
Suite *suite_trim(void);

Suite *suite_atoi(void);

#endif