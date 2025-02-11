#include "../s21_string.h"

// Выполняет поиск первого вхождения символа c в строке, на которую указывает
// аргумент str.
char *s21_strchr(const char *str, int c) {
  char *result = s21_NULL;
  while (*str) {
    if (*str == c) {
      result = (char *)str;
      break;
    }
    str++;
  }
  if (*str == c) result = (char *)str;  // для случая, когда c == '\0'
  return result;
}