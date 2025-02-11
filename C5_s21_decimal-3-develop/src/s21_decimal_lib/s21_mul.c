#include "../cherlyma_lib/cherlyma.h"

int s21_mul(s21_decimal num, s21_decimal num2, s21_decimal *res) {
  int result = 0;
  int over = 0;
  dec_to_null(res);
  if (correct(num) && correct(num2)) {
    if (!s21_zero(num) && !s21_zero(num2)) {
      if (s21_decimal_get_sign(num) != s21_decimal_get_sign(num2)) {
        s21_decimal_set_sign(res, 1);
      }
      over = multiplication(num, num2, res);
    }
    if (over && s21_decimal_get_sign(*res)) {
      result = 2;
    } else if (over && !s21_decimal_get_sign(*res)) {
      result = 1;
    }
    if (s21_zero(*res)) s21_decimal_set_sign(res, 0);
  } else
    result = 4;
  if (result) {
    dec_to_null(res);
    s21_decimal_set_sign(res, 0);
  }
  return result;
}
