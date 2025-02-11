#include "../lavadaja_lib/lavadaja.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int err_flag = 0;
  int sign1 = s21_decimal_get_sign(value_1);
  int sign2 = s21_decimal_get_sign(value_2);
  if (result == NULL) {
    return 2;
  }
  for (int i = 0; i < 4; i++) result->bits[i] = 0;

  if (sign1 + sign2 == 0 || sign1 + sign2 == 2) {
    if (sign1 + sign2 == 2) {
      if (s21_is_less(value_1, value_2))
        s21_sub_helper(value_1, value_2, result, 1);
      else
        s21_sub_helper(value_2, value_1, result, 0);
    } else if (sign1 + sign2 == 0) {
      if (s21_is_less(value_1, value_2)) {
        s21_sub_helper(value_2, value_1, result, 1);
      } else
        s21_sub_helper(value_1, value_2, result, 0);
    }
  } else if (sign1)
    s21_add_helper(value_1, value_2, result, 1, &err_flag);
  else if (sign2)
    s21_add_helper(value_1, value_2, result, 0, &err_flag);
  if (err_flag == 1 && sign2 == 0 && sign1 == 1) err_flag = 2;
  return err_flag;
}
