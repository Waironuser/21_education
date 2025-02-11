#include "../s21_string.h"

// Вычисляет длину начального сегмента str1, который полностью состоит из
// символов, не входящих в str2.
s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t result = 0;
  s21_size_t len1 = s21_strlen(str1);
  s21_size_t len2 = s21_strlen(str2);
  int found = 0;
  for (s21_size_t i = 0; i < len1 && !found; i++) {
    for (s21_size_t j = 0; j < len2; j++) {
      if (str2[j] == str1[i]) {
        result = i;
        found = 1;
        break;
      }
    }
    if (!found) result = i + 1;
  }
  return result;
}