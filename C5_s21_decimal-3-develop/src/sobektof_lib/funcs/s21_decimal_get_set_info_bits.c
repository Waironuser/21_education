#include "../sobektof.h"

// Получаем степень decimal
int s21_decimal_get_power(s21_decimal src) {
  int value = src.bits[INFO];
  value = (value & 0x00FF0000) >> 16;
  return value;
}

// Перезаписываем степень
void s21_decimal_set_power(s21_decimal *dst, int power) {
  if (power >= 0 && power <= 28) {
    dst->bits[INFO] &= ~(0xFF << 16);
    dst->bits[INFO] |= (power & 0xFF) << 16;
  }
}

// Первые 0 - 15 битоы из bits[3] в виде одного инта. Должен всегда быть 0
int s21_decimal_get_unused_lower(s21_decimal src) {
  int value = src.bits[INFO];
  value = (value & 0x0000FFFF);
  return value;
}

// Битоы 24 - 30 из bits[3] в виде одного инта. Должен всегда быть 0
int s21_decimal_get_unused_higher(s21_decimal src) {
  int value = src.bits[INFO];
  value = (value & 0x7F000000) >> 24;
  return value;
}

// Получаем знак (+/-) decimal
int s21_decimal_get_sign(s21_decimal src) {
  int value = src.bits[INFO];
  value = (value & 0x80000000) >> 31;
  return value;
}

// Переписываем знак (+/-) decimal
void s21_decimal_set_sign(s21_decimal *dst, int sign) {
  if (sign == 0 || sign == 1) {
    dst->bits[INFO] &= 0x7FFFFFFF;
    if (sign == 1) {
      dst->bits[INFO] |= 1 << 31;
    }
  }
}

// Проверяем на ноль
int s21_decimal_equals_zero(s21_decimal src) {
  int result = 0;
  if (src.bits[LOW] == 0 && src.bits[MIDDLE] == 0 && src.bits[HIGH] == 0) {
    result = 1;
  }
  return result;
}

// Все функции на получение информации из bits[3], но в одной красивой функции
int s21_decimal_get_info(s21_decimal src, int info_type) {
  int value;
  switch (info_type) {
    case UNUSED_LOWER:
      value = s21_decimal_get_unused_lower(src);
      break;
    case POWER:
      value = s21_decimal_get_power(src);
      break;
    case UNUSED_HIGHER:
      value = s21_decimal_get_unused_higher(src);
      break;
    case SIGN:
      value = s21_decimal_get_sign(src);
      break;
  }
  return value;
}

// Проверка decimal на валидность
int s21_is_correct_decimal(s21_decimal src) {
  int is_correct = 1;
  if (s21_decimal_get_info(src, UNUSED_LOWER) != 0) {
    is_correct = 0;
  }
  int power = s21_decimal_get_info(src, POWER);
  if (power > 28 || power < 0) {
    is_correct = 0;
  }
  if (s21_decimal_get_info(src, UNUSED_HIGHER) != 0) {
    is_correct = 0;
  }
  return is_correct;
}
