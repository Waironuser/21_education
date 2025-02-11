#ifndef S21_DECIMAL_GET_SET_INFO_BITS_H
#define S21_DECIMAL_GET_SET_INFO_BITS_H

#include "../s21_decimal.h"

int s21_is_correct_decimal(s21_decimal src);
int s21_decimal_get_info(s21_decimal src, int info_type);
int s21_decimal_get_power(s21_decimal src);
int s21_decimal_get_unused_lower(s21_decimal src);
int s21_decimal_get_unused_higher(s21_decimal src);
int s21_decimal_get_sign(s21_decimal src);
int s21_decimal_equals_zero(s21_decimal src);

void s21_decimal_set_power(s21_decimal *src, int value);
void s21_decimal_set_sign(s21_decimal *dst, int sign);

#endif