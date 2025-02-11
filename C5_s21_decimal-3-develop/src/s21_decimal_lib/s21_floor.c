#include "../lavadaja_lib/lavadaja.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int errno = 0;

  int power = s21_decimal_get_power(value);
  int sign = s21_decimal_get_sign(value);
  *result = value;
  s21_decimal_set_power(result, 0);
  s21_decimal_set_sign(result, 0);
  while (power > 0) {
    s21_decimal divisor = {{10, 0, 0, 0}};
    s21_decimal remainder = {{0, 0, 0, 0}};
    s21_decimal new_result = {{0, 0, 0, 0}};
    s21_div_no_remainder(*result, divisor, &new_result, &remainder);
    *result = new_result;
    power--;
  }
  if (sign && !s21_is_equal(*result, value)) {
    s21_decimal one = {{1, 0, 0, 0}};
    s21_decimal new_result = {{0, 0, 0, 0}};
    s21_add(*result, one, &new_result);
    *result = new_result;
  }
  s21_decimal_set_sign(result, sign);

  return errno;
}
