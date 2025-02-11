#include "../s21_string.h"

int leftTrim(const char *src, const char *trim_chars);
int rightTrim(const char *src, const char *trim_chars);

// функция для печати символов новой строки
void *trim(const char *src, const char *trim_chars) {
  char *new_str = s21_NULL;
  if (src != s21_NULL) {
    int start = leftTrim(
        src, trim_chars);  // определения позиции, откуда слева нужно печатать
    int end = rightTrim(
        src, trim_chars);  // определения позиции, до куда справа нужно печатать
    if (start <= end) {
      new_str = (char *)malloc((end - start + 2) * sizeof(char));
      if (new_str) {
        s21_size_t k = 0;
        for (int i = start; i <= end; i++) {
          new_str[k++] = src[i];
        }
        new_str[k] = '\0';
      }
    } else {
      new_str = (char *)malloc(1 * sizeof(char));
      if (new_str) {
        new_str[0] = '\0';
      }
    }
  }
  return new_str;
}

// функция для определения позиции, откуда слева нужно печатать
int leftTrim(const char *src, const char *trim_chars) {
  int start = 0;
  int src_len = s21_strlen(src);
  s21_size_t trim_chars_len;
  if (trim_chars != s21_NULL) {
    trim_chars_len = s21_strlen(trim_chars);
  } else {
    trim_chars_len = 0;
  }
  while (start < src_len) {
    int trim_status = 0;
    if (trim_chars_len != 0) {
      for (s21_size_t j = 0; j < trim_chars_len; j++) {
        if (src[start] == trim_chars[j]) {
          trim_status = 1;
          break;
        }
      }
    } else {
      if (src[start] == ' ' || src[start] == '\t') {
        trim_status = 1;
      }
    }
    if (!trim_status) {
      break;
    }
    start++;
  }
  return start;
}

// функция для определения позиции, до куда справа нужно печатать
int rightTrim(const char *src, const char *trim_chars) {
  int end = s21_strlen(src) - 1;
  s21_size_t trim_chars_len;
  if (trim_chars != s21_NULL) {
    trim_chars_len = s21_strlen(trim_chars);
  } else {
    trim_chars_len = 0;
  }
  while (end > 0) {
    int trim_status = 0;
    if (trim_chars_len != 0) {
      for (s21_size_t j = 0; j < trim_chars_len; j++) {
        if (src[end] == trim_chars[j]) {
          trim_status = 1;
          break;
        }
      }
    } else {
      if (src[end] == ' ' || src[end] == '\t') {
        trim_status = 1;
      }
    }
    if (!trim_status) {
      break;
    }
    end--;
  }
  return end;
}
