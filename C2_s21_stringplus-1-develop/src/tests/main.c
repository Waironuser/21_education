#include "s21_tests.h"

int main(void) {
  runTests();

  return 0;
}

void runTestcase(Suite *testcase) {
  static int counterTestcase = 1;

  if (counterTestcase > 1) putchar('\n');
  printf("%s%d%s", "CURR TEST: ", counterTestcase, "\n");
  counterTestcase++;

  SRunner *sr = srunner_create(testcase);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  srunner_free(sr);
}

void runTests(void) {
  Suite *listCases[] = {suite_sscanf(),
                        suite_atoi(),
                        suiteSprintf(),
                        suiteSprintf_int(),
                        suiteSprintf_int_u(),
                        suiteSprintf_char(),
                        suiteSprintf_float(),
                        suiteSprintf_string(),
                        make_strchr_suite(),
                        make_strcspn_suite(),
                        make_strncat_suite(),
                        make_strncmp_suite(),
                        make_strncpy_suite(),
                        make_strpbrk_suite(),
                        make_strrchr_suite(),
                        make_strerror_suite(),
                        make_strstr_suite(),
                        suite_create_tests(),
                        suite_to_upper(),
                        suite_to_lower(),
                        suite_insert(),
                        suite_trim(),
                        NULL};
  for (Suite **currentTestcase = listCases; *currentTestcase != NULL;
       currentTestcase++) {
    runTestcase(*currentTestcase);
  }
}