#include "../s21_string.h"

void *to_upper(const char *str) {
  char *new_str = s21_NULL;
  if (str != s21_NULL) {
    s21_size_t len = s21_strlen(str);
    new_str = (char *)malloc((len + 1) * sizeof(char));
    if (new_str) {
      for (s21_size_t i = 0; i < len; i++) {
        if (str[i] >= 97 && str[i] <= 122) {
          new_str[i] = str[i] - 32;
        } else {
          new_str[i] = str[i];
        }
      }
      new_str[len] = '\0';
    }
  }
  return new_str;
}