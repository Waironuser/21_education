#include "../lavadaja_lib/lavadaja.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  s21_decimal num1 = {{0, 0, 0, 0}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  s21_normalize(value_1, value_2, &num1, &num2);
  int result = FALSE;
  int sign1 = s21_decimal_get_sign(num1);
  int sign2 = s21_decimal_get_sign(num2);

  if (s21_decimal_equals_zero(num1) && s21_decimal_equals_zero(num2)) {
    result = FALSE;
  } else if (sign1 > sign2)
    result = TRUE;
  else if (sign1 < sign2)
    result = FALSE;
  else {
    result = s21_mantissa_compare(num1, num2) == LESS ? TRUE : FALSE;
  }
  if (sign1 == sign2 && sign1 == 1) result = result == TRUE ? FALSE : TRUE;
  return result;
}