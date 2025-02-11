#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = s21_NULL;
  if (*needle == '\0') {
    result = (char *)haystack;
  } else {
    s21_size_t needle_len = s21_strlen(needle);
    while (*haystack) {
      if (s21_strncmp(haystack, needle, needle_len) == 0) {
        result = (char *)haystack;
        break;
      }
      haystack++;
    }
  }
  return result;
}
