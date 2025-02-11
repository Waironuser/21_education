#include "../cherlyma_lib/cherlyma.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  dec_to_null(result);
  int flag = 0;
  int sign = 0;
  int corr = 1;
  if (!correct(value_1) || !correct(value_2)) corr = 0;
  if (!s21_zero(value_2) && corr) {
    if (get_sign(value_1) != get_sign(value_2)) {
      sign = 1;
    }
    int scale = get_scale(value_1) - get_scale(value_2);
    set_scale(&value_1, 0);
    set_scale(&value_2, 0);
    s21_decimal integer = {{0, 0, 0, 0}};
    s21_decimal remainder = {{0, 0, 0, 0}};
    del(value_1, value_2, &integer, &remainder);
    s21_add(*result, integer, result);
    while (!s21_zero(remainder) && scale < 30) {
      if (!first_unzero_bit(*result) && scale < 30) {
        mul_to_10(&remainder);
        del(remainder, value_2, &integer, &remainder);
        flag = mul_to_10(result);
        plus(*result, integer, result);
        scale++;
      } else
        dec_to_null(&remainder);
    }
    if (scale < 0) {
      while (scale) {
        mul_to_10(result);
        scale++;
      }
    }
    if (first_unzero_bit(*result) && !scale) {
      if (get_sign(*result))
        flag = 2;
      else
        flag = 1;
    }
    while (scale > 28) {
      round_float(result);
      scale--;
    }
    set_scale(result, scale);
  } else {
    if (!corr)
      flag = 4;
    else
      flag = 3;
  }
  if (first_unzero_bit(*result) && get_scale(*result)) {
    round_float(result);
  }
  set_sign(result, sign);
  if (flag) {
    dec_to_null(result);
  }
  return flag;
}