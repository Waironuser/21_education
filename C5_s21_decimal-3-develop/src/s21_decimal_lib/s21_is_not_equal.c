#include "../lavadaja_lib/lavadaja.h"

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  s21_decimal num1 = {{0, 0, 0, 0}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  int result = TRUE;

  s21_normalize(value_1, value_2, &num1, &num2);
  if (s21_decimal_equals_zero(num1) && s21_decimal_equals_zero(num2))
    result = FALSE;
  else if (s21_decimal_get_sign(num1) != s21_decimal_get_sign(num2))
    result = TRUE;
  else
    result = s21_mantissa_compare(num1, num2) == EQUAL ? FALSE : TRUE;
  return result;
}