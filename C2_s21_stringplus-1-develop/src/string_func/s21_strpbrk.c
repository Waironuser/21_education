#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = s21_NULL;
  for (int stop = 0; *str1 != '\0' && !stop; ++str1) {
    for (const char *currStr2 = str2; *currStr2 != '\0'; ++currStr2) {
      if (*str1 == *currStr2) {
        result = (char *)str1;
        stop = 1;
        break;
      }
    }
  }
  return result;
}