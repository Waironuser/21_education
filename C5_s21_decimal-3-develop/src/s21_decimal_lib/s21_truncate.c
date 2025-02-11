#include "../lavadaja_lib/lavadaja.h"
#include "../sobektof_lib/sobektof.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int errno = 0;

  int power = s21_decimal_get_power(value);
  int sign = s21_decimal_get_sign(value);
  *result = value;
  s21_decimal_set_power(result, 0);
  s21_decimal_set_sign(result, 0);
  while (power > 0) {
    s21_decimal divisor = {{10, 0, 0, 0}};
    s21_decimal new_result = {{0, 0, 0, 0}};
    s21_decimal remainder = {{0, 0, 0, 0}};
    s21_div_no_remainder(*result, divisor, &new_result, &remainder);
    *result = new_result;
    power--;
  }
  s21_decimal_set_sign(result, sign);

  return errno;
}
