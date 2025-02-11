#include "../s21_string.h"

void *insert(const char *src, const char *str, s21_size_t start_index) {
  char *new_str = s21_NULL;
  if (src != s21_NULL && str != s21_NULL) {
    s21_size_t len_src = s21_strlen(src);
    s21_size_t len_str = s21_strlen(str);
    if (start_index <= len_src) {
      new_str = (char *)malloc((len_src + len_str + 1) * sizeof(char));
      if (new_str) {
        s21_memcpy(
            new_str, src,
            start_index);  // Копируем часть исходной строки до start_index
        s21_memcpy(new_str + start_index, str,
                   len_str);  // Копируем вставляемую строку
        s21_memcpy(new_str + start_index + len_str, src + start_index,
                   len_src - start_index);  // Копируем оставшуюся часть
                                            // исходной строки после start_index
        new_str[len_src + len_str] = '\0';
      }
    }
  }
  return new_str;
}