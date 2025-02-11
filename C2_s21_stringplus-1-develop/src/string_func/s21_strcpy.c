#include "../s21_string.h"

// Копирует строку, на которую указывает src, в буфер, на который указывает
// dest.
char *s21_strcpy(char *dest, const char *src) {
  int i;  // Объявление переменной i для использования в цикле

  // Цикл копирования символов из src в dest, пока не достигнут нулевой символ
  // ('\0')
  for (i = 0; src[i]; i++)
    dest[i] = src[i];  // Копирование текущего символа из src в dest

  dest[i] = 0;  // Добавление нулевого символа ('\0') в конец строки dest

  return dest;  // Возвращение указателя на строку dest
}
