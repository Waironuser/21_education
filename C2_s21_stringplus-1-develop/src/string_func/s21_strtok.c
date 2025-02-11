#include "../s21_string.h"

int s21_delim(char ch, const char *delim) {
  int result = 0;
  while (*delim) {
    if (ch == *delim) {
      result = 1;
      break;
    }
    delim++;
  }
  return result;
}

char *s21_strtok(char *str, const char *delim) {
  static char *p;
  char *result = s21_NULL;
  if (str == s21_NULL) {
    str = p;
  }
  if (str != s21_NULL) {
    while (s21_delim(*str, delim)) {
      str++;
    }
    if (*str != '\0') {
      result = str;
      while (*str && !s21_delim(*str, delim)) {
        str++;
      }
      if (*str) {
        *str = '\0';
        p = str + 1;
      } else {
        p = str;
      }
    }
  }
  return result;
}
