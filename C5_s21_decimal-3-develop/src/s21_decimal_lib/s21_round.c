#include "../lavadaja_lib/lavadaja.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int i = s21_decimal_get_power(value);
  int s = s21_decimal_get_sign(value);
  *result = value;
  s21_decimal_set_power(result, 0);
  s21_decimal_set_sign(result, 0);

  while (i > 0) {
    s21_decimal divisor = {{10, 0, 0, 0}};
    s21_decimal remainder = {{0, 0, 0, 0}};
    s21_decimal new_result = {{0, 0, 0, 0}};
    s21_div_no_remainder(*result, divisor, &new_result, &remainder);

    int round_up = 0;
    if (remainder.bits[LOW] > 5) {
      round_up = 1;
    } else if (remainder.bits[LOW] == 5) {
      if (new_result.bits[LOW] & 1) {
        round_up = 1;
      }
    }

    *result = new_result;
    if (round_up) {
      s21_decimal one = {{1, 0, 0, 0}};
      s21_add(*result, one, &new_result);
      *result = new_result;
    }

    i--;
  }

  s21_decimal_set_sign(result, s);

  return 0;
}
