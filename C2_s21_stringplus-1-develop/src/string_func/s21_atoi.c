#include "s21_sprintf.h"

// Макрос для проверки является ли символ цифрой
#define is_digit(c) ((c) >= '0' && (c) <= '9')

// Основная функция atoi без использования сторонних библиотек
int s21_atoi(const char *str) {
  int result = 0;
  int sign = 1;

  // Пропускаем начальные пробелы
  while (*str == ' ') {
    str++;
  }

  // Определяем знак числа
  sign = determine_sign(&str);

  // Преобразование строки в число
  while (is_digit(*str)) {
    result = result * 10 + (*str - '0');
    str++;
  }

  // Учитываем знак числа
  return sign * result;
}