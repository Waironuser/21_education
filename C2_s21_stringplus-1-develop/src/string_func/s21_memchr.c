#include "../s21_string.h"
// Выполняет поиск первого вхождения символа c
// в первых n байтах строки, на которую указывает аргумент str.
void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *result = (unsigned char *)str;
  void *ch = s21_NULL;
  for (s21_size_t i = 0; i < n; i++) {
    if (*result == (unsigned char)c) {
      ch = result;
      break;
    }
    result++;
  }
  return ch;
}