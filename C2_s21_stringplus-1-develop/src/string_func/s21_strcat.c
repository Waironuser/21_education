#include "../s21_string.h"

// // Добавляет строку, на которую указывает src, в конец строки, на которую
// указывает dest
char *s21_strcat(char *dest, const char *src) {
  int len_dest = s21_strlen(dest);

  for (; *src != '\0'; src++, len_dest++) dest[len_dest] = *src;

  return dest;
}