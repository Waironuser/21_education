#include "../s21_string.h"

// Копирует до n символов из строки, на которую указывает src, в dest.
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t j = 0;
  for (s21_size_t i = 0; i < n; i++) {
    *dest = *src;
    dest++;
    src++;
    j++;
  }
  return dest - j;
}